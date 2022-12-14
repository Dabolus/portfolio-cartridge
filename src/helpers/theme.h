#pragma once
#ifndef HELPERS_THEME_H
#define HELPERS_THEME_H

#include <gbdk/platform.h>

extern BOOLEAN is_dark_theme;

extern const palette_color_t rgb_theme_colors[4];

extern palette_color_t current_theme[4];

extern void theme_switch(void);

extern void theme_init(void);

#endif
