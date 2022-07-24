#include "../res/fonts/font_early_game_boy.h"
#include "helpers/fade.h"
#include "helpers/text.h"
#include "helpers/utils.h"
#include "pages/handler.h"
#include "pages/home_header.h"
#include "pages/home_menu.h"
#include <gbdk/platform.h>

void handle_theme_change() {
  // Reverse the palette bits
  BGP_REG = ~BGP_REG;
}

void main() {
  // Load font in the background data (2 colors -> 1 bit per pixel)
  set_bkg_1bpp_data(0, 50, font_early_game_boy);
  init_page(HOME_HEADER);
  SHOW_BKG;

  uint8_t current_loop_count = 0;

  while (1) {
    uint8_t keys = joypad();

    void (*theme_change_handler)(void);
    theme_change_handler = &handle_theme_change;
    throttlekey(keys, J_SELECT, theme_change_handler);

    switch (current_page) {
    case HOME_HEADER:
      home_header_loop(&current_loop_count);
      if (keys & (J_START | J_A)) {
        set_page(HOME_MENU);
      }
      break;
    case HOME_MENU: {
      home_menu_loop(&current_loop_count, keys);
      if (keys & J_B) {
        set_page(HOME_HEADER);
      }
      break;
    }
    }

    fastdelay(3);
    ++current_loop_count;
  }
}
