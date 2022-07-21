#ifndef _PAGES_HOME_MENU_
#define _PAGES_HOME_MENU_

#include "../assets/home_menu.c"
#include "../assets/phrases.c"
#include <gbdk/platform.h>

#define MENU_COLUMNS 2
#define MENU_ROWS 2
#define MENU_ITEMS (MENU_COLUMNS * MENU_ROWS)

enum MenuOption {
  MENU_OPTION_ABOUT,
  MENU_OPTION_CONTACTS,
  MENU_OPTION_PROJECTS,
  MENU_OPTION_SKILLS,
};

enum MenuOption current_menu_option_index = MENU_OPTION_ABOUT;

uint8_t current_menu_option_index;

void draw_frame(uint8_t x, uint8_t y, uint8_t w, uint8_t h,
                const unsigned char *top_frame_map,
                const unsigned char *right_frame_map,
                const unsigned char *bottom_frame_map,
                const unsigned char *left_frame_map) {
  set_bkg_tiles(x, y, w, 1, top_frame_map);
  set_bkg_tiles(x + w - 1, y + 1, 1, h - 1, right_frame_map);
  set_bkg_tiles(x, y + h - 1, w - 1, 1, bottom_frame_map);
  set_bkg_tiles(x, y + 1, 1, h - 2, left_frame_map);
}

void update_menu_item_frame(uint8_t x, uint8_t y, BOOLEAN selected) {
  if (selected) {
    draw_frame(x, y, 10, 9, home_menu_selected_top_frame_map,
               home_menu_selected_right_frame_map,
               home_menu_selected_bottom_frame_map,
               home_menu_selected_left_frame_map);
  } else {
    draw_frame(x, y, 10, 9, home_menu_top_frame_map, home_menu_right_frame_map,
               home_menu_bottom_frame_map, home_menu_left_frame_map);
  }
}

void home_menu_setup() {
  current_menu_option_index = MENU_OPTION_ABOUT;
  // Load the frame data
  set_bkg_data(50, 16, home_menu_frame_data);

  // About me
  update_menu_item_frame(0, 0, current_menu_option_index == MENU_OPTION_ABOUT);
  set_bkg_tiles(1, 2, 8, 1, about_me);
  // Contacts
  update_menu_item_frame(10, 0,
                         current_menu_option_index == MENU_OPTION_CONTACTS);
  set_bkg_tiles(11, 2, 8, 1, contacts);
  // Projects
  update_menu_item_frame(0, 9,
                         current_menu_option_index == MENU_OPTION_PROJECTS);
  set_bkg_tiles(1, 11, 8, 1, projects);
  // Skills
  update_menu_item_frame(10, 9,
                         current_menu_option_index == MENU_OPTION_SKILLS);
  set_bkg_tiles(12, 11, 6, 1, skills);
}

void home_menu_loop(uint8_t *current_loop_count, uint8_t keys) {
  current_loop_count = 0;

  // Draw the 4 frames of the menu
  // About me
  update_menu_item_frame(0, 0, current_menu_option_index == MENU_OPTION_ABOUT);
  // Contacts
  update_menu_item_frame(10, 0,
                         current_menu_option_index == MENU_OPTION_CONTACTS);
  // Projects
  update_menu_item_frame(0, 9,
                         current_menu_option_index == MENU_OPTION_PROJECTS);
  // Skills
  update_menu_item_frame(10, 9,
                         current_menu_option_index == MENU_OPTION_SKILLS);

  if (keys & J_UP) {
    current_menu_option_index =
        (current_menu_option_index + MENU_COLUMNS) % MENU_ITEMS;
    waitpadup();
  }
  if (keys & J_RIGHT) {
    current_menu_option_index = (current_menu_option_index + 1) % MENU_ITEMS;
    waitpadup();
  }
  if (keys & J_DOWN) {
    current_menu_option_index =
        (current_menu_option_index + MENU_ITEMS - MENU_COLUMNS) % MENU_ITEMS;
    waitpadup();
  }
  if (keys & J_LEFT) {
    current_menu_option_index =
        (current_menu_option_index + MENU_ITEMS - 1) % MENU_ITEMS;
    waitpadup();
  }
}

#endif
