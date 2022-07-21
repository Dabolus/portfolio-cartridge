#ifndef _PAGES_HOME_MENU_
#define _PAGES_HOME_MENU_

#include "../assets/home_menu.c"
#include "../assets/phrases.c"
#include <gbdk/platform.h>

void home_menu_setup() {
  // Load the frame data
  set_bkg_data(50, 8, home_menu_frame_data);
  // Draw the 4 frames of the menu
  // About me
  set_bkg_tiles(0, 0, 10, 9, home_menu_frame_map);
  set_bkg_tiles(1, 2, 8, 1, about_me);
  // Contacts
  set_bkg_tiles(10, 0, 10, 9, home_menu_frame_map);
  set_bkg_tiles(11, 2, 8, 1, contacts);
  // Projects
  set_bkg_tiles(0, 9, 10, 9, home_menu_frame_map);
  set_bkg_tiles(1, 11, 8, 1, projects);
  // Skills
  set_bkg_tiles(10, 9, 10, 9, home_menu_frame_map);
  set_bkg_tiles(12, 11, 6, 1, skills);
}

void home_menu_loop(uint8_t *current_loop_count) { current_loop_count = 0; }

#endif
