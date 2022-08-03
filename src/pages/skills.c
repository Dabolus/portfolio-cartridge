#ifndef PAGES_SKILLS_C
#define PAGES_SKILLS_C

#include "skills.h"
#include "../../res/assets/phrases.h"
#include "../../res/generated/skills.h"
#include "../helpers/text.h"
#include "../helpers/utils.h"
#include "handler.h"
#include <gbdk/platform.h>

void handle_skills_scroll_row_up() {
  scroller_row_up();
  scroller_draw(skills_tiles);
}

void handle_skills_scroll_row_down() {
  scroller_row_down();
  scroller_draw(skills_tiles);
}

void handle_skills_scroll_page_down() {
  scroller_page_down();
  scroller_draw(skills_tiles);
}

void skills_setup() {
  set_bkg_tiles(1, 1, ARRAY_LEN(skills), 1, skills);
  fillarea(0, PAGE_HEADER_HEIGHT - 1, DEVICE_SCREEN_WIDTH, 1, 0x32);
  set_bkg_1bpp_data(51, ARRAY_LEN(skills_data) / 8, skills_data);
  struct ScrollerConfig scroller_config;
  scroller_config.y = PAGE_HEADER_HEIGHT;
  scroller_config.height = DEVICE_SCREEN_HEIGHT - PAGE_HEADER_HEIGHT;
  scroller_config.content_total_rows = ARRAY_LEN(skills_tiles);
  scroller_init(&scroller_config);
  scroller_draw(skills_tiles);
}

void skills_loop(uint8_t *current_loop_count, uint8_t keys) {
  if (keys & J_B) {
    set_page(HOME_MENU);
  }

  // Allow scrolling by one row by pressing up or down
  void (*skills_scroll_row_up_handler)(void);
  skills_scroll_row_up_handler = &handle_skills_scroll_row_up;
  throttlekey(keys, J_UP, skills_scroll_row_up_handler);

  void (*skills_scroll_row_down_handler)(void);
  skills_scroll_row_down_handler = &handle_skills_scroll_row_down;
  throttlekey(keys, J_DOWN, skills_scroll_row_down_handler);

  // Allow scrolling by one page by pressing A
  void (*skills_scroll_page_down_handler)(void);
  skills_scroll_page_down_handler = &handle_skills_scroll_page_down;
  throttlekey(keys, J_A, skills_scroll_page_down_handler);
}

#endif
