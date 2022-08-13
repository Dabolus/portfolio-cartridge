#ifndef PAGES_HOME_MENU_C
#define PAGES_HOME_MENU_C

#include "home_menu.h"
#include "../../res/assets/home_menu.h"
#include "../../res/assets/phrases.h"
#include "../helpers/text.h"
#include "../helpers/utils.h"
#include "handler.h"
#include <gbdk/platform.h>

enum MenuOption current_menu_option = MENU_OPTION_ABOUT;

struct MenuItem {
  enum MenuOption option;
  uint8_t x;
  uint8_t y;
  uint8_t text_width;
  const unsigned char *text_data;
  const unsigned char *icon_data;
};

struct MenuItem menu_items[4];

void update_menu_item_frame(struct MenuItem *menu_item, BOOLEAN selected) {
  if (selected) {
    drawframe(menu_item->x, menu_item->y, MENU_ITEM_WIDTH, MENU_ITEM_HEIGHT,
              0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 0x40, 0x41);
  } else {
    drawframe(menu_item->x, menu_item->y, MENU_ITEM_WIDTH, MENU_ITEM_HEIGHT,
              0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39);
  }
}

void update_menu_item_content(struct MenuItem *menu_item, BOOLEAN selected) {
  uint8_t text_x =
      menu_item->x + (MENU_ITEM_WIDTH / 2) - (menu_item->text_width / 2);
  if (selected) {
    set_bkg_1bpp_data(66, 16, menu_item->icon_data);

    // Clear the text area
    cleararea(text_x, menu_item->y + 4, menu_item->text_width, 1);
    // Draw the text one tile higher
    set_bkg_tiles(text_x, menu_item->y + 3, menu_item->text_width, 1,
                  menu_item->text_data);
    // Draw the icon
    set_bkg_tiles(menu_item->x + 3, menu_item->y + 4, 4, 4, home_menu_icon_map);
    fastdelay(1);
    // Clear the new text area
    cleararea(text_x, menu_item->y + 3, menu_item->text_width, 1);
    // Draw the text one tile higher for the last time
    set_bkg_tiles(text_x, menu_item->y + 2, menu_item->text_width, 1,
                  menu_item->text_data);
  } else {
    // Clear the icon area
    cleararea(menu_item->x + 3, menu_item->y + 4, 4, 4);
    // Clear the text area
    cleararea(text_x, menu_item->y + 2, menu_item->text_width, 1);
    // Draw the text one tile lower
    set_bkg_tiles(text_x, menu_item->y + 3, menu_item->text_width, 1,
                  menu_item->text_data);
    fastdelay(1);
    // Clear the new text area
    cleararea(text_x, menu_item->y + 3, menu_item->text_width, 1);
    // Draw the text at the center of the menu item
    set_bkg_tiles(text_x, menu_item->y + 4, menu_item->text_width, 1,
                  menu_item->text_data);
  }
}

void update_menu_item(struct MenuItem *menu_item, BOOLEAN selected) {
  update_menu_item_frame(menu_item, selected);
  update_menu_item_content(menu_item, selected);
}

void update_menu_option(uint8_t new_option) {
  update_menu_item(&menu_items[current_menu_option], FALSE);
  current_menu_option = new_option;
  update_menu_item(&menu_items[current_menu_option], TRUE);
}

void handle_menu_navigation_up() {
  update_menu_option((current_menu_option + MENU_COLUMNS) % MENU_ITEMS);
}
void handle_menu_navigation_right() {
  update_menu_option((current_menu_option + 1) % MENU_ITEMS);
}
void handle_menu_navigation_down() {
  update_menu_option((current_menu_option + MENU_ITEMS - MENU_COLUMNS) %
                     MENU_ITEMS);
}
void handle_menu_navigation_left() {
  update_menu_option((current_menu_option + MENU_ITEMS - 1) % MENU_ITEMS);
}

void home_menu_setup() {
  // Load the frame data
  set_bkg_data(50, 16, home_menu_frame_data);

  struct MenuItem menu_item_about;
  menu_item_about.option = MENU_OPTION_ABOUT;
  menu_item_about.x = 0;
  menu_item_about.y = 0;
  menu_item_about.text_width = ARRAY_LEN(about_me);
  menu_item_about.text_data = about_me;
  menu_item_about.icon_data = home_menu_about_icon_data;
  menu_items[MENU_OPTION_ABOUT] = menu_item_about;

  struct MenuItem menu_item_contacts;
  menu_item_contacts.option = MENU_OPTION_CONTACTS;
  menu_item_contacts.x = MENU_ITEM_WIDTH;
  menu_item_contacts.y = 0;
  menu_item_contacts.text_width = ARRAY_LEN(contacts);
  menu_item_contacts.text_data = contacts;
  menu_item_contacts.icon_data = home_menu_contacts_icon_data;
  menu_items[MENU_OPTION_CONTACTS] = menu_item_contacts;

  struct MenuItem menu_item_projects;
  menu_item_projects.option = MENU_OPTION_PROJECTS;
  menu_item_projects.x = 0;
  menu_item_projects.y = MENU_ITEM_HEIGHT;
  menu_item_projects.text_width = ARRAY_LEN(projects);
  menu_item_projects.text_data = projects;
  menu_item_projects.icon_data = home_menu_projects_icon_data;
  menu_items[MENU_OPTION_PROJECTS] = menu_item_projects;

  struct MenuItem menu_item_skills;
  menu_item_skills.option = MENU_OPTION_SKILLS;
  menu_item_skills.x = MENU_ITEM_WIDTH;
  menu_item_skills.y = MENU_ITEM_HEIGHT;
  menu_item_skills.text_width = ARRAY_LEN(skills);
  menu_item_skills.text_data = skills;
  menu_item_skills.icon_data = home_menu_skills_icon_data;
  menu_items[MENU_OPTION_SKILLS] = menu_item_skills;

  // About me
  update_menu_item(&menu_items[MENU_OPTION_ABOUT],
                   current_menu_option == MENU_OPTION_ABOUT);
  // Contacts
  update_menu_item(&menu_items[MENU_OPTION_CONTACTS],
                   current_menu_option == MENU_OPTION_CONTACTS);
  // Projects
  update_menu_item(&menu_items[MENU_OPTION_PROJECTS],
                   current_menu_option == MENU_OPTION_PROJECTS);
  // Skills
  update_menu_item(&menu_items[MENU_OPTION_SKILLS],
                   current_menu_option == MENU_OPTION_SKILLS);
}

void home_menu_loop(uint8_t *current_loop_count, uint8_t keys) {
  current_loop_count = 0;

  if (keys & J_B) {
    set_page(HOME_HEADER);
  }

  if (keys & J_A) {
    // Current menu option + the number of extra pages we have defined
    // before the menu pages (i.e. `HOME_HEADER` and `HOME_MENU`)
    set_page(current_menu_option + 2);
  }

  throttlekey(keys, J_UP, &handle_menu_navigation_up);
  throttlekey(keys, J_RIGHT, &handle_menu_navigation_right);
  throttlekey(keys, J_DOWN, &handle_menu_navigation_down);
  throttlekey(keys, J_LEFT, &handle_menu_navigation_left);
}

#endif
