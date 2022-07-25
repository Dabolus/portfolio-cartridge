#ifndef PAGES_ABOUT_C
#define PAGES_ABOUT_C

#include "about.h"
#include "../../res/assets/phrases.h"
#include "../helpers/text.h"
#include "../helpers/utils.h"
#include "handler.h"
#include <gbdk/platform.h>

uint8_t about_me_current_row_index;

void draw_about_me_description_chunk() {
  for (uint8_t i = 0; i < DEVICE_SCREEN_HEIGHT - PAGE_HEADER_HEIGHT; ++i) {
    set_bkg_tiles(0, i + PAGE_HEADER_HEIGHT, DEVICE_SCREEN_WIDTH, 1,
                  about_me_description[i + about_me_current_row_index]);
  }
}

void handle_about_me_scroll_row_up() {
  if (about_me_current_row_index == 0) {
    return;
  }
  --about_me_current_row_index;
  draw_about_me_description_chunk();
}

void handle_about_me_scroll_row_down() {
  if (about_me_current_row_index == ARRAY_LEN(about_me_description) -
                                        DEVICE_SCREEN_HEIGHT +
                                        PAGE_HEADER_HEIGHT) {
    return;
  }
  ++about_me_current_row_index;
  draw_about_me_description_chunk();
}

void handle_about_me_scroll_page_down() {
  about_me_current_row_index += DEVICE_SCREEN_HEIGHT - PAGE_HEADER_HEIGHT;
  if (about_me_current_row_index > ARRAY_LEN(about_me_description) -
                                       DEVICE_SCREEN_HEIGHT +
                                       PAGE_HEADER_HEIGHT) {
    about_me_current_row_index = ARRAY_LEN(about_me_description) -
                                 DEVICE_SCREEN_HEIGHT + PAGE_HEADER_HEIGHT;
  }
  draw_about_me_description_chunk();
}

void about_setup() {
  set_bkg_tiles(1, 1, ARRAY_LEN(about_me), 1, about_me);
  fillarea(0, PAGE_HEADER_HEIGHT - 1, DEVICE_SCREEN_WIDTH, 1, 0x32);
  about_me_current_row_index = 0;
  draw_about_me_description_chunk();
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
