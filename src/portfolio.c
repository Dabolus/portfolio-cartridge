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

static const palette_color_t light_palette[] = {
    RGB8(250, 250, 250),
    RGB8(240, 240, 240),
    RGB8(220, 220, 220),
    RGB8(32, 32, 32),
};

static const palette_color_t dark_palette[] = {
    RGB8(33, 33, 33),
    RGB8(48, 48, 48),
    RGB8(73, 73, 73),
    RGB8(255, 255, 255),
};

BOOLEAN is_dark_theme = FALSE;

void handle_theme_change() {
  if (DEVICE_SUPPORTS_COLOR) {
    // Switch between the two color palettes (for Game Boy Color)
    is_dark_theme = !is_dark_theme;
    set_bkg_palette(0, 1, is_dark_theme ? dark_palette : light_palette);
  } else {
#ifdef NINTENDO
    // Reverse the palette bits (for Game Boy Classic)
    BGP_REG = ~BGP_REG;
#endif
  }
}

void main() {
  if (DEVICE_SUPPORTS_COLOR) {
    set_bkg_palette(0, 1, light_palette);
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
