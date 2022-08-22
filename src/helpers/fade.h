#pragma once
#ifndef HELPERS_FADE_H
#define HELPERS_FADE_H

#include <gbdk/platform.h>

extern const palette_color_t rgb_theme_colors[4];

extern void fadeout(uint8_t duration);

extern void fadein(uint8_t duration);

#endif
