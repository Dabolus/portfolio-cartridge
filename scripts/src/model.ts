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

export interface Icon {
  readonly svg?: string;
  readonly jpg?: string;
  readonly png?: string;
  readonly webp?: string;
  readonly jxl?: string;
  readonly pixelart: string;
  readonly placeholder: string;
}

export interface ProjectData {
  readonly id: string;
  readonly name: string;
  readonly description: string;
  readonly link: string;
  readonly source?: string;
  readonly languages: readonly string[];
  readonly frameworks: readonly string[];
  readonly icon: Icon;
}
