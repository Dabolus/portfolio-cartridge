#ifndef _PAGES_HOME_MENU_
#define _PAGES_HOME_MENU_

#include "../assets/home_menu.c"
#include <gbdk/platform.h>

void home_menu_setup() {
  for (uint8_t i = 0; i < 20; ++i) {
    for (uint8_t j = 0; j < 18; ++j) {
      set_bkg_tile_xy(i, j, 0x00);
    }
  }
  set_bkg_data(50, 8, home_menu_frame_data);
  set_bkg_tiles(0, 0, 10, 9, home_menu_frame_map);
  set_bkg_tiles(10, 0, 10, 9, home_menu_frame_map);
  set_bkg_tiles(0, 9, 10, 9, home_menu_frame_map);
  set_bkg_tiles(10, 9, 10, 9, home_menu_frame_map);
}

void home_menu_loop(uint8_t *current_loop_count) { current_loop_count = 0; }

#endif