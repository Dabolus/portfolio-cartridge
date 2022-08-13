import path from 'path';
import { promises as fs } from 'fs';
import { load } from 'js-yaml';
import { LanguageSizeData, SkillData } from './model';

export const cachePath = path.join(__dirname, '..', '.cache');

export const readData = async <T = unknown>(fileName: string) => {
  const absolutePath = path.join(__dirname, '..', 'data', `${fileName}.yml`);
  const rawContent = await fs.readFile(absolutePath, 'utf8');
  return load(rawContent) as T;
};

export const chunk = <T extends string | unknown[]>(
  arr: T,
  size: number,
): T[] =>
  Array.from<void, T>(
    { length: Math.ceil(arr.length / size) },
    (_, i) => arr.slice(i * size, i * size + size) as T,
  );

export const numberToHex = (number: number) =>
  `0x${number.toString(16).toUpperCase().padStart(2, '0')}`;

export const binaryToHex = (binary: string) => numberToHex(parseInt(binary, 2));

export const autoWrapPhrase = (
  phrase: string,
  maxWidth: number,
  separator = ' ',
  printSeparator = false,
) => {
  const words = phrase.split(separator);
  const lines = [];
  let currentLine = words[0];

  for (let i = 1; i < words.length; i++) {
    const word = words[i];
    const width = (currentLine + separator + word).length;
    if (width < maxWidth) {
      currentLine += separator + word;
    } else {
      lines.push(currentLine + (printSeparator ? separator : ''));
      currentLine = word;
    }
  }
  lines.push(currentLine);

  return lines.join('\n');
};

export const autoWrapText = (text: string, maxWidth: number) => {
  const lines = text.split(/[\r\n]/);
  return lines
    .flatMap(line => autoWrapPhrase(line, maxWidth).split('\n'))
    .join('\n');
};

const charMap: Record<string, number | undefined> = {
  '!': 1,
  '"': 2,
  "'": 3,
  '(': 4,
  ')': 5,
  ',': 6,
  '-': 7,
  '.': 8,
  ':': 19,
  ';': 20,
  '?': 21,
  '▔': 50,
  '+': 51,
  '#': 52,
  '%': 53,
  '≈': 54,
};

export const textToHex = (text: string) =>
  Array.from(text.toLowerCase())
    .map(char => {
      const translated = char.codePointAt(0);
      if (!translated) {
        return 0;
      }
      if (char === '\n' || char === '\r') {
        return 254;
      }
      if (char >= '0' && char <= '9') {
        return translated - 39;
      }
      if (char >= 'a' && char <= 'z') {
        return translated - 75;
      }
      return charMap[char] || 0;
    })
    .map(numberToHex);

export const textPageToHex = (text: string) => {
  const rows = text.split(/[\r\n]/);
  return rows.map(row => textToHex(row.padEnd(20, ' ')));
};

export const prettifySize = (bytes: number) => {
  const measurementUnits = ['B', 'kB', 'MB', 'GB'];
  let finalVal = bytes;
  let unitIndex = 0;
  while (finalVal > 1024) {
    finalVal /= 1024;
    unitIndex++;
  }
  return `≈${Math.round(finalVal)}${measurementUnits[unitIndex]}`;
};

export interface ChartOutput {
  data: string[];
  tiles: string[][];
}

export interface ComputeLineChartOptions {
  maxWidth?: number;
  startingBarsData?: string[];
  mapOffset: number;
}

export const computeLineChart = (
  data: Record<string, SkillData>,
  { maxWidth = 20, startingBarsData = [], mapOffset }: ComputeLineChartOptions,
): ChartOutput => {
  const entries = Object.entries(data).filter(([, { score }]) => !!score);

  // Find the longest label name
  const longestName = entries.reduce(
    (longest, [name]) => Math.max(longest, name.length),
    0,
  );
  const availableSpaceInTiles = maxWidth - longestName - 1;
  const availableSpaceInPixels = availableSpaceInTiles * 8;

  const barsDataSet = new Set(startingBarsData);
  const bars = entries.map(([name, { score }]) => {
    const scoreInPixels = Math.round(score * availableSpaceInPixels);
    const neededTiles = Math.ceil(scoreInPixels / 8);
    const totalPixels = neededTiles * 8;
    const bitsArray = Array.from({ length: totalPixels }, (_, i) =>
      i <= scoreInPixels ? 1 : 0,
    ).join('');
    const bar = chunk(bitsArray, 8).map(binaryToHex);
    // Add all the tiles to the set
    bar.forEach(row => {
      // Each row corresponds to a single row of pixels, so we need to generate the full bar
      // (empty row + 6 equal rows for the bar + another empty row)
      const tile = Array.from({ length: 8 }, (_, i) =>
        i === 0 || i === 7 ? '0x00' : row,
      ).join(',');
      barsDataSet.add(tile);
    });
    return { name, bar };
  });
  const barsData = Array.from(barsDataSet);
  const barsTiles = bars.map(({ name, bar }) => {
    // Compute the name prefix, to which we need to add the bar tiles
    const prefix = textToHex(name.padEnd(longestName + 1, ' '));
    const barTiles = bar.map(byte =>
      numberToHex(
        mapOffset + barsData.findIndex(bytesStr => bytesStr.includes(byte)),
      ),
    );
    return Array.from(
      { length: maxWidth },
      (_, i) => prefix[i] ?? barTiles[i - prefix.length] ?? '0x00',
    );
  });
  return {
    // Each row corresponds to a single row of pixels, so we need to generate the full bar
    // (empty row + 6 equal rows for the bar + another empty row)
    data: barsData,
    tiles: barsTiles,
  };
};

export interface ComputeSizeChartOptions {
  maxWidth?: number;
}

export const computeSizeChart = (
  data: readonly LanguageSizeData[],
  totalSize: number,
  { maxWidth = 20 }: ComputeSizeChartOptions = {},
): ChartOutput => {
  const textRows = data.map(({ name, size }) => {
    const prettifiedSize = prettifySize(size);
    const textRow = `${name.padEnd(
      maxWidth - prettifiedSize.length,
      ' ',
    )}${prettifiedSize}`;
    return textToHex(textRow);
  });

  return {
    data: [],
    tiles: textRows,
  };
};
