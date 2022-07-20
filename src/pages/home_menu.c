#ifndef _PAGES_HOME_MENU_
#define _PAGES_HOME_MENU_

#include <gbdk/platform.h>

void home_menu_setup() {
  for (uint8_t i = 0; i < 20; ++i) {
    for (uint8_t j = 0; j < 18; ++j) {
      set_bkg_tile_xy(i, j, 0x00);
    }
  }
}

void home_menu_loop(uint8_t *current_loop_count) { current_loop_count = 0; }

#endif
