import { promises as fs } from 'fs';
import path from 'path';
import {
  skills,
  GitHubData,
  getGitHubCodeStats,
} from '@dabolus/portfolio-data';
import { cachePath, numberToHex } from './utils.js';
import { PageBuilder, screenWidth } from './page-builder.js';

export const generateSkills = async () => {
  let githubData: GitHubData | undefined = await fs
    .readFile(path.join(cachePath, 'github-skills.json'), 'utf8')
    .then(skills => JSON.parse(skills))
    .catch(() => undefined);

  if (!githubData) {
    githubData = await getGitHubCodeStats();
    await fs.mkdir(cachePath, { recursive: true });
    await fs.writeFile(
      path.join(cachePath, 'github-skills.json'),
      JSON.stringify(githubData),
      'utf8',
    );
  }

  const { data, tiles } = new PageBuilder({ mapOffset: 55 })
    .addTitle('Coding')
    .addText('Languages I feel\nmost confident with')
    .addGutter()
    .addLineChart(skills.coding)
    .addGutter()
    .addText('Languages I use\nthe most')
    .addGutter()
    .addSizeChart(githubData.languages, githubData.total)
    .addGutter()
    .addTitle('Music')
    .addLineChart(skills.music)
    // TODO: add soft skills
    .build();

  const skillsExtraCharsData = [
    // Plus
    0x00, 0x18, 0x18, 0x7e, 0x7e, 0x18, 0x18, 0x00,
    // Sharp
    0x00, 0x24, 0x7e, 0x24, 0x24, 0x7e, 0x24, 0x00,
    // Percent
    0x22, 0x54, 0x28, 0x08, 0x14, 0x2a, 0x44, 0x00,
    // Almost equal to
    0x00, 0x00, 0x32, 0x4c, 0x32, 0x4c, 0x00, 0x00,
  ];

  const allData = [...skillsExtraCharsData.map(numberToHex), ...data];

  const sourceFile = `#ifndef GENERATED_SKILLS_C
#define GENERATED_SKILLS_C

#include "generated_skills.h"
#include <gbdk/platform.h>

const unsigned char skills_data[${allData.length}] = {${allData.join(', ')}};

const unsigned char skills_tiles[${tiles.length}][${screenWidth}] = {${tiles
    .map(row => `{${row.join(', ')}}`)
    .join(',\n')}};

#endif
`;
  const headerFile = `#pragma once
#ifndef GENERATED_SKILLS_H
#define GENERATED_SKILLS_H

#include <gbdk/platform.h>

extern const uint8_t skills_tiles_rows;

extern const unsigned char skills_data[${allData.length}];

extern const unsigned char skills_tiles[${tiles.length}][${screenWidth}];

#endif
`;
  const outputPath = path.join(__dirname, '..', '..', 'res', 'generated');
  await fs.mkdir(outputPath, { recursive: true });
  await fs.writeFile(path.join(outputPath, 'generated_skills.c'), sourceFile);
  await fs.writeFile(path.join(outputPath, 'generated_skills.h'), headerFile);
};
