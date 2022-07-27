#ifndef HELPERS_UTILS_C
#define HELPERS_UTILS_C

#include "utils.h"
#include <gbdk/platform.h>

void fastdelay(uint8_t num_loops) {
  for (uint8_t i = 0; i != num_loops; i++) {
    wait_vbl_done();
  }
}

void fillarea(uint8_t x, uint8_t y, uint8_t w, uint8_t h, unsigned char c) {
  for (uint8_t i = 0; i < w; ++i) {
    for (uint8_t j = 0; j < h; ++j) {
      set_bkg_tile_xy(x + i, y + j, c);
    }
  }
}

void cleararea(uint8_t x, uint8_t y, uint8_t w, uint8_t h) {
  fillarea(x, y, w, h, 0x00);
}

void clearscreen() {
  cleararea(0, 0, DEVICE_SCREEN_WIDTH, DEVICE_SCREEN_HEIGHT);
}

uint8_t previous_keys_state = 0x00;

void throttlekey(uint8_t keys, uint8_t key, void (*cb)(void)) {
  // If the key is pressed and was not pressed before, call the callback
  // and set the key as pressed in our internal state
  if (!(previous_keys_state & key) && (keys & key)) {
    cb();
    previous_keys_state |= key;
  }
  // If the key is no more pressed and was pressed before, set the key as
  // not pressed in our internal state
  if ((previous_keys_state & key) && !(keys & key)) {
    previous_keys_state &= ~key;
  }
}

struct ScrollerConfig scroller_config;
uint8_t scroller_current_row;

// It could be great to save the content in the config struct and automatically
// use it from within this function, but I couldn't find an easy and performant
// way to do that. :)
void scroller_draw(const unsigned char content[][20]) {
  for (uint8_t i = 0; i < scroller_config.height; ++i) {
    set_bkg_tiles(0, i + scroller_config.y, DEVICE_SCREEN_WIDTH, 1,
                  content[i + scroller_current_row]);
  }
}

void scroller_init(struct ScrollerConfig *config) {
  scroller_config = *config;
  scroller_current_row = 0;
}

void scroller_row_up() {
  if (scroller_current_row == 0) {
    return;
  }
  --scroller_current_row;
}

void scroller_row_down() {
  if (scroller_current_row ==
      scroller_config.content_total_rows - scroller_config.height) {
    return;
  }
  ++scroller_current_row;
}

void scroller_page_down() {
  scroller_current_row += scroller_config.height;
  if (scroller_current_row >
      scroller_config.content_total_rows - scroller_config.height) {
    scroller_current_row =
        scroller_config.content_total_rows - scroller_config.height;
  }
}

#endif
