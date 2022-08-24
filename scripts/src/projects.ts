import { promises as fs } from 'fs';
import path from 'path';
import {
  autoWrapPhrase,
  autoWrapText,
  chunk,
  hexColorToRgb8,
  readData,
  textToHex,
} from './utils';
import { screenWidth } from './page-builder';
import type { ProjectData } from './model';

export const generateProjects = async () => {
  const projectsData = await readData<ProjectData[]>('projects');

  const sourceFile = `#ifndef GENERATED_PROJECTS_C
#define GENERATED_PROJECTS_C

#include "projects.h"
#include <gbdk/platform.h>

${projectsData
  .map(project => {
    const normalizedId = project.id.replace(/-/g, '_');
    const hexName = textToHex(
      autoWrapText(project.name, screenWidth - 5),
    ).concat('0xFF');
    const hexDescription = textToHex(
      autoWrapText(project.description, screenWidth - 2),
    ).concat('0xFF');
    const hexTags = textToHex(
      autoWrapPhrase(
        [...project.languages, ...project.frameworks]
          .map(val =>
            val
              .replace('JavaScript', 'JS')
              .replace('TypeScript', 'TS')
              .replace('#', 'Sharp'),
          )
          .join(','),
        screenWidth - 2,
        ',',
        true,
      ),
    ).concat('0xFF');
    const hexIcon = chunk(project.icon.pixelart.bitmap, 2).map(
      byte => `0x${byte}`,
    );
    const palette = Array.from({ length: 4 }, (_, i) => {
      const color = project.icon.pixelart.colors[3 - i];
      return color ? hexColorToRgb8(color) : '0';
    });

    return `const unsigned char ${normalizedId}_name_data[${
      hexName.length
    }] = {${hexName.join(', ')}};
const unsigned char ${normalizedId}_description_data[${
      hexDescription.length
    }] = {${hexDescription.join(', ')}};
const unsigned char ${normalizedId}_tags_data[${
      hexTags.length
    }] = {${hexTags.join(', ')}};
const unsigned char ${normalizedId}_icon_data[${
      hexIcon.length
    }] = {${hexIcon.join(', ')}};
const palette_color_t ${normalizedId}_icon_palette[${
      palette.length
    }] = {${palette.join(', ')}};`;
  })
  .join('\n\n')}

const unsigned char project_icon_tiles[4] = {0x00, 0x01, 0x02, 0x03};

void get_projects(struct Project* projects) {
${projectsData
  .map((project, index) => {
    const normalizedId = project.id.replace(/-/g, '_');

    return `  struct Project ${normalizedId};
  ${normalizedId}.name_data = ${normalizedId}_name_data;
  ${normalizedId}.description_data = ${normalizedId}_description_data;
  ${normalizedId}.tags_data = ${normalizedId}_tags_data;
  ${normalizedId}.icon_data = ${normalizedId}_icon_data;
  ${normalizedId}.icon_palette = ${normalizedId}_icon_palette;
  projects[${index}] = ${normalizedId};`;
  })
  .join('\n\n')}
}


#endif
`;
  const headerFile = `#pragma once
#ifndef GENERATED_PROJECTS_H
#define GENERATED_PROJECTS_H

#include <gbdk/platform.h>

#define TOTAL_PROJECTS ${projectsData.length}

extern struct Project {
  const unsigned char *name_data;
  const unsigned char *description_data;
  const unsigned char *tags_data;
  const unsigned char *icon_data;
  const palette_color_t *icon_palette;
};

extern const unsigned char project_icon_tiles[4];

extern void get_projects(struct Project* projects);

#endif
`;
  const outputPath = path.join(__dirname, '..', '..', 'res', 'generated');
  await fs.mkdir(outputPath, { recursive: true });
  await fs.writeFile(path.join(outputPath, 'projects.c'), sourceFile);
  await fs.writeFile(path.join(outputPath, 'projects.h'), headerFile);
};
