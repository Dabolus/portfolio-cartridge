#ifndef PAGES_ABOUT_C
#define PAGES_ABOUT_C

#include "about.h"
#include "../../res/assets/phrases.h"
#include "../helpers/text.h"
#include "../helpers/utils.h"
#include "handler.h"
#include <gbdk/platform.h>

void handle_about_me_scroll_row_up() {
  scroller_row_up();
  scroller_draw(about_me_description);
}

void handle_about_me_scroll_row_down() {
  scroller_row_down();
  scroller_draw(about_me_description);
}

void handle_about_me_scroll_page_down() {
  scroller_page_down();
  scroller_draw(about_me_description);
}

void about_setup() {
  set_bkg_tiles(1, 1, ARRAY_LEN(about_me), 1, about_me);
  fillarea(0, PAGE_HEADER_HEIGHT - 1, DEVICE_SCREEN_WIDTH, 1, 0x32);
  struct ScrollerConfig scroller_config;
  scroller_config.y = PAGE_HEADER_HEIGHT;
  scroller_config.height = DEVICE_SCREEN_HEIGHT - PAGE_HEADER_HEIGHT;
  scroller_config.content_total_rows = ARRAY_LEN(about_me_description);
  scroller_init(&scroller_config);
  scroller_draw(about_me_description);
}

void about_loop(uint8_t *current_loop_count, uint8_t keys) {
  if (keys & J_B) {
    set_page(HOME_MENU);
  }

  // Allow scrolling by one row by pressing up or down
  void (*about_me_scroll_row_up_handler)(void);
  about_me_scroll_row_up_handler = &handle_about_me_scroll_row_up;
  throttlekey(keys, J_UP, about_me_scroll_row_up_handler);

  void (*about_me_scroll_row_down_handler)(void);
  about_me_scroll_row_down_handler = &handle_about_me_scroll_row_down;
  throttlekey(keys, J_DOWN, about_me_scroll_row_down_handler);

  // Allow scrolling by one page by pressing A
  void (*about_me_scroll_page_down_handler)(void);
  about_me_scroll_page_down_handler = &handle_about_me_scroll_page_down;
  throttlekey(keys, J_A, about_me_scroll_page_down_handler);
}

#endif
