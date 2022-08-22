#include "../res/fonts/font_early_game_boy.h"
#include "helpers/fade.h"
#include "helpers/text.h"
#include "helpers/utils.h"
#include "pages/about.h"
#include "pages/contacts.h"
#include "pages/handler.h"
#include "pages/home_header.h"
#include "pages/home_menu.h"
#include "pages/projects.h"
#include "pages/skills.h"
#include <gbdk/platform.h>

BOOLEAN is_dark_theme = FALSE;

void handle_theme_change() {
  if (DEVICE_SUPPORTS_COLOR) {
    // Replace the colors in the default palette with the ones from the theme in
    // the proper order
    is_dark_theme = !is_dark_theme;
    for (uint8_t i = 0; i < ARRAY_LEN(rgb_theme_colors); ++i) {
      const uint8_t color_index =
          is_dark_theme ? ARRAY_LEN(rgb_theme_colors) - i - 1 : i;
      set_bkg_palette_entry(0, i, rgb_theme_colors[color_index]);
      set_sprite_palette_entry(0, i, rgb_theme_colors[color_index]);
    }
  } else {
#ifdef NINTENDO
    // Reverse the background and sprites palettes bits (for Game Boy Classic)
    BGP_REG = ~BGP_REG;
    OBP0_REG = ~OBP0_REG;
#endif
  }
}

void main() {
  if (DEVICE_SUPPORTS_COLOR) {
    for (uint8_t i = 0; i < ARRAY_LEN(rgb_theme_colors); ++i) {
      set_bkg_palette_entry(0, i, rgb_theme_colors[i]);
      set_sprite_palette_entry(0, i, rgb_theme_colors[i]);
    }
  }
  // Load font in the background data (2 colors -> 1 bit per pixel)
  set_bkg_1bpp_data(0, 50, font_early_game_boy);
  init_page(HOME_HEADER);
  SHOW_BKG;

  uint8_t current_loop_count = 0;

  while (1) {
    uint8_t keys = joypad();

    // Allow switching theme by pressing Select
    throttlekey(keys, J_SELECT, &handle_theme_change);

    // Allow going back to the home header from any page
    // by pressing Start
    if (current_page != HOME_HEADER && (keys & J_START)) {
      set_page(HOME_HEADER);
      continue;
    }

    switch (current_page) {
    case HOME_HEADER:
      home_header_loop(&current_loop_count, keys);
      break;
    case HOME_MENU: {
      home_menu_loop(&current_loop_count, keys);
      break;
    }
    case ABOUT:
      about_loop(&current_loop_count, keys);
      break;
    case CONTACTS:
      contacts_loop(&current_loop_count, keys);
      break;
    case PROJECTS:
      projects_loop(&current_loop_count, keys);
      break;
    case SKILLS:
      skills_loop(&current_loop_count, keys);
      break;
    }

    fastdelay(3);
    ++current_loop_count;
  }
}
