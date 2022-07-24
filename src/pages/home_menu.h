#pragma once
#ifndef PAGES_HOME_MENU_H
#define PAGES_HOME_MENU_H

#define MENU_COLUMNS 2
#define MENU_ROWS 2
#define MENU_ITEMS (MENU_COLUMNS * MENU_ROWS)
#define MENU_ITEM_WIDTH (DEVICE_SCREEN_WIDTH / MENU_COLUMNS)
#define MENU_ITEM_HEIGHT (DEVICE_SCREEN_HEIGHT / MENU_ROWS)

#include <gbdk/platform.h>

extern enum MenuOption {
  MENU_OPTION_ABOUT,
  MENU_OPTION_CONTACTS,
  MENU_OPTION_PROJECTS,
  MENU_OPTION_SKILLS,
};

extern void home_menu_setup(void);

extern void home_menu_loop(uint8_t *current_loop_count, uint8_t keys);

#endif
