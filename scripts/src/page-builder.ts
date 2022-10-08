import type { LanguageSizeData, Skill } from '@dabolus/portfolio-data';
import { computeLineChart, computeSizeChart, textPageToHex } from './utils';

export const screenWidth = 20;

export interface PageBuilderOptions {
  mapOffset?: number;
}

export interface Page {
  data: string[];
  tiles: string[][];
}

export class PageBuilder {
  #options: PageBuilderOptions;
  #data: string[] = [];
  #tiles: string[][] = [];

  constructor(options?: PageBuilderOptions) {
    this.#options = options;
  }

  addTitle(title: string): this {
    return this.addText(`${title}\n${'▔'.repeat(title.length)}`);
  }

  addText(text: string): this {
    const hex = textPageToHex(text);
    this.#tiles = [...this.#tiles, ...hex];
    return this;
  }

  addGutter(height = 1): this {
    const emptyRow = Array.from({ length: 20 }, () => '0x00');
    this.#tiles = [
      ...this.#tiles,
      ...Array.from({ length: height }, () => emptyRow),
    ];
    return this;
  }

  addLineChart(data: Record<string, Skill>): this {
    const { data: chartData, tiles: chartTiles } = computeLineChart(data, {
      mapOffset: this.#options?.mapOffset,
      startingBarsData: this.#data,
    });
    this.#data = [...this.#data, ...chartData];
    this.#tiles = [...this.#tiles, ...chartTiles];
    return this;
  }

  addSizeChart(data: readonly LanguageSizeData[], totalSize: number) {
    const { data: chartData, tiles: chartTiles } = computeSizeChart(
      data,
      totalSize,
    );
    this.#data = [...this.#data, ...chartData];
    this.#tiles = [...this.#tiles, ...chartTiles];
    return this;
  }

  build(): Page {
    return {
      data: this.#data.flatMap(line => line.split(',')),
      tiles: this.#tiles,
    };
  }
}
