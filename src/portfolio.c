#include "font_early_game_boy.h"
#include "helpers/fade.c"
#include "helpers/text.c"
#include "helpers/utils.c"
#include "pages/handler.c"
#include <gbdk/platform.h>

void main() {
  // Load font in the background data (2 colors -> 1 bit per pixel)
  set_bkg_1bpp_data(0, 50, font_early_game_boy);
  init_page(HOME_HEADER);
  SHOW_BKG;

  uint8_t current_loop_count = 0;

  while (1) {
    uint8_t keys = joypad();

    if (!is_select_pressed && (keys & J_SELECT)) {
      // Reverse the palette bits
      BGP_REG = ~BGP_REG;
      is_select_pressed = TRUE;
    }

    if (is_select_pressed && !(keys & J_SELECT)) {
      is_select_pressed = FALSE;
    }

    if (keys & (J_START | J_A)) {
      set_page(HOME_MENU);
    }

    switch (current_page) {
    case HOME_HEADER:
      home_header_loop(&current_loop_count);
      break;
    case HOME_MENU: {
      home_menu_loop(&current_loop_count);
      break;
    }
    }

    fastdelay(3);
    ++current_loop_count;
  }
}
