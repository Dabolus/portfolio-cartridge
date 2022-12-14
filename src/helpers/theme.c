#ifndef HELPERS_THEME_C
#define HELPERS_THEME_C

#include "text.h"
#include <gbdk/platform.h>

BOOLEAN is_dark_theme = FALSE;

const palette_color_t rgb_theme_colors[4] = {
    RGB8(255, 255, 255),
    RGB8(72, 72, 72),
    RGB8(48, 48, 48),
    RGB8(32, 32, 32),
};

palette_color_t current_theme[4];

void set_theme(palette_color_t *theme) {
  for (uint8_t i = 0; i != 4; ++i) {
    set_bkg_palette_entry(0, i, theme[i]);
    set_sprite_palette_entry(0, i, theme[i]);
    current_theme[i] = theme[i];
  }
}

void theme_switch() {
  if (DEVICE_SUPPORTS_COLOR) {
    // Replace the colors in the default palette with the ones from the theme in
    // the proper order
    is_dark_theme = !is_dark_theme;
    palette_color_t new_palette[4];
    for (uint8_t i = 0; i < ARRAY_LEN(rgb_theme_colors); ++i) {
      const uint8_t color_index =
          is_dark_theme ? ARRAY_LEN(rgb_theme_colors) - i - 1 : i;
      new_palette[i] = rgb_theme_colors[color_index];
    }
    set_theme(new_palette);
  } else {
#ifdef NINTENDO
    // Reverse the background and sprites palettes bits (for Game Boy Classic)
    BGP_REG = ~BGP_REG;
    OBP0_REG = ~OBP0_REG;
#endif
  }
}

void theme_init() {
  if (DEVICE_SUPPORTS_COLOR) {
    // Set the palette to be from the lightest to the darkest color (aka light
    // theme)
    set_theme(rgb_theme_colors);
  } else {
#ifdef NINTENDO
    // Default Game Boy Classic theme (11 10 01 00)
    BGP_REG = 0xE4;
    OBP0_REG = 0xE4;
#endif
  }
}

#endif
