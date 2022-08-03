import { promises as fs } from 'fs';
import path from 'path';
import fetch from 'node-fetch';
import { cachePath, numberToHex, readData } from './utils.js';
import type { GitHubData, SkillData, SkillsData } from './model';
import { PageBuilder, screenWidth } from './page-builder.js';

// NOTE: this function is exactly the same as the one used in the main portfolio,
// and also other helpers used to parse the data are the same. It would be great
// to create a common library (being it either a different repo or just a monorepo
// with the 2 implementations + this shared ibrary) for this kind of stuff.
const getGithubData = async (
  codingSkillsData: Record<string, SkillData>,
): Promise<GitHubData> => {
  const request = await fetch('https://api.github.com/graphql', {
    method: 'POST',
    headers: {
      Authorization: `Bearer ${process.env.GH_TOKEN}`,
    },
    body: JSON.stringify({
      query: `
          query {
            viewer {
              repositories(first: 100) {
                nodes {
                  languages(first: 100) {
                    edges {
                      node {
                        name
                      }
                      size
                    }
                    totalSize
                  }
                }
              }
            }
          }
        `,
    }),
  });

  const response = (await request.json()) as any;

  const { total, languages } = response.data.viewer.repositories.nodes.reduce(
    (acc: any, repo: any) => ({
      ...acc,
      total: (acc.total || 0) + repo.languages.totalSize,
      languages: {
        ...acc.languages,
        ...repo.languages.edges.reduce(
          (languages: any, language: any) => ({
            ...languages,
            [language.node.name]: {
              ...acc.languages[language.node.name],
              color: language.node.color,
              size:
                ((acc.languages[language.node.name] || {}).size || 0) +
                language.size,
            },
          }),
          {},
        ),
      },
    }),
    { total: 0, languages: {} },
  );

  return {
    total,
    languages: Object.entries(languages).reduce(
      (languageArr: any, [name, { color, size }]: [string, any]) => {
        const index = languageArr.findIndex(
          (language: any) => language.size < size,
        );
        const newElemIndex = index < 0 ? languageArr.length : index;
        const firstSlice = languageArr.slice(0, newElemIndex);
        const secondSlice = languageArr.slice(newElemIndex);

        return [
          ...firstSlice,
          {
            name,
            size,
            color:
              color ||
              codingSkillsData[name]?.color ||
              'var(--theme-card-background)',
          },
          ...secondSlice,
        ];
      },
      [],
    ),
  };
};

export const generateSkills = async () => {
  const skillsData = await readData<SkillsData>('skills');

  let githubData: GitHubData | undefined = await fs
    .readFile(path.join(cachePath, 'github-skills.json'), 'utf8')
    .then(skills => JSON.parse(skills))
    .catch(() => undefined);

  if (!githubData) {
    githubData = await getGithubData(skillsData.coding);
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
    .addLineChart(skillsData.coding)
    .addGutter()
    .addText('Languages I use\nthe most')
    .addGutter()
    .addSizeChart(githubData.languages, githubData.total)
    .addGutter()
    .addTitle('Music')
    .addLineChart(skillsData.music)
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

#include "skills.h"
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
  await fs.writeFile(path.join(outputPath, 'skills.c'), sourceFile);
  await fs.writeFile(path.join(outputPath, 'skills.h'), headerFile);
};
