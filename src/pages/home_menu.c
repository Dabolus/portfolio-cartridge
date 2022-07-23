#ifndef _PAGES_HOME_MENU_
#define _PAGES_HOME_MENU_

#include "../assets/home_menu.c"
#include "../assets/phrases.c"
#include <gbdk/platform.h>

#define MENU_COLUMNS 2
#define MENU_ROWS 2
#define MENU_ITEMS (MENU_COLUMNS * MENU_ROWS)
#define MENU_ITEM_WIDTH (DEVICE_SCREEN_WIDTH / MENU_COLUMNS)
#define MENU_ITEM_HEIGHT (DEVICE_SCREEN_HEIGHT / MENU_ROWS)

enum MenuOption {
  MENU_OPTION_ABOUT,
  MENU_OPTION_CONTACTS,
  MENU_OPTION_PROJECTS,
  MENU_OPTION_SKILLS,
};

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

void update_menu_item_frame(struct MenuItem *menu_item, BOOLEAN selected) {
  if (selected) {
    draw_frame(
        menu_item->x, menu_item->y, MENU_ITEM_WIDTH, MENU_ITEM_HEIGHT,
        home_menu_selected_top_frame_map, home_menu_selected_right_frame_map,
        home_menu_selected_bottom_frame_map, home_menu_selected_left_frame_map);
  } else {
    draw_frame(menu_item->x, menu_item->y, MENU_ITEM_WIDTH, MENU_ITEM_HEIGHT,
               home_menu_top_frame_map, home_menu_right_frame_map,
               home_menu_bottom_frame_map, home_menu_left_frame_map);
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
  current_menu_option = MENU_OPTION_ABOUT;
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

  void (*menu_navigation_up_handler)(void);
  menu_navigation_up_handler = &handle_menu_navigation_up;
  throttlekey(keys, J_UP, menu_navigation_up_handler);

  void (*menu_navigation_right_handler)(void);
  menu_navigation_right_handler = &handle_menu_navigation_right;
  throttlekey(keys, J_RIGHT, menu_navigation_right_handler);

  void (*menu_navigation_down_handler)(void);
  menu_navigation_down_handler = &handle_menu_navigation_down;
  throttlekey(keys, J_DOWN, menu_navigation_down_handler);

  void (*menu_navigation_left_handler)(void);
  menu_navigation_left_handler = &handle_menu_navigation_left;
  throttlekey(keys, J_LEFT, menu_navigation_left_handler);
}

#endif
