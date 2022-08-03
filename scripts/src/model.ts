export interface LanguageSizeData {
  readonly name: string;
  readonly size: number;
  readonly color: string;
}

export interface GitHubData {
  readonly total: number;
  readonly languages: readonly LanguageSizeData[];
}

export interface SkillData {
  readonly score: number;
  readonly color: string;
}

export interface SkillsData {
  readonly coding: Record<string, SkillData>;
  readonly music: Record<string, SkillData>;
  readonly soft: Record<string, SkillData>;
}
