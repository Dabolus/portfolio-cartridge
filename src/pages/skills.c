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
  fill_bkg_rect(0, PAGE_HEADER_HEIGHT - 1, DEVICE_SCREEN_WIDTH, 1, 0x32);
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
  throttlekey(keys, J_UP, &handle_skills_scroll_row_up);
  throttlekey(keys, J_DOWN, &handle_skills_scroll_row_down);
  // Allow scrolling by one page by pressing A
  throttlekey(keys, J_A, &handle_skills_scroll_page_down);
}

#endif
