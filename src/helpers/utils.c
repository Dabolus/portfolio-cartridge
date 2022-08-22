#ifndef HELPERS_UTILS_C
#define HELPERS_UTILS_C

#include "utils.h"
#include <gbdk/platform.h>

void fastdelay(uint8_t num_loops) {
  for (uint8_t i = 0; i != num_loops; i++) {
    wait_vbl_done();
  }
}

void cleararea(uint8_t x, uint8_t y, uint8_t w, uint8_t h) {
  fill_bkg_rect(x, y, w, h, 0x00);
}

void clearscreen() {
  cleararea(0, 0, DEVICE_SCREEN_WIDTH, DEVICE_SCREEN_HEIGHT);
}

void drawframe(
    uint8_t x, uint8_t y, uint8_t w, uint8_t h, unsigned char top_border_tile,
    unsigned char top_right_corner_tile, unsigned char right_border_tile,
    unsigned char bottom_right_corner_tile, unsigned char bottom_border_tile,
    unsigned char bottom_left_corner_tile, unsigned char left_border_tile,
    unsigned char top_left_corner_tile) {
  fill_bkg_rect(x + 1, y, w - 2, 1, top_border_tile);
  set_bkg_tile_xy(x + w - 1, y, top_right_corner_tile);
  fill_bkg_rect(x + w - 1, y + 1, 1, h - 2, right_border_tile);
  set_bkg_tile_xy(x + w - 1, y + h - 1, bottom_right_corner_tile);
  fill_bkg_rect(x + 1, y + h - 1, w - 2, 1, bottom_border_tile);
  set_bkg_tile_xy(x, y + h - 1, bottom_left_corner_tile);
  fill_bkg_rect(x, y + 1, 1, h - 2, left_border_tile);
  set_bkg_tile_xy(x, y, top_left_corner_tile);
}

void drawtext(uint8_t start_x, uint8_t start_y, const unsigned char *text) {
  uint8_t current_text_x = 0;
  uint8_t current_text_y = 0;
  uint8_t current_text_index = 0;

  while (text[current_text_index] != 0xFF) {
    set_bkg_tile_xy(start_x + current_text_x, start_y + current_text_y,
                    text[current_text_index]);
    ++current_text_x;
    ++current_text_index;
    // Handle newlines
    if (text[current_text_index] == 0xFE) {
      current_text_x = 0;
      ++current_text_y;
      ++current_text_index;
    }
  };
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

void set_sprite_tiles(uint8_t x, uint8_t y, uint8_t w, uint8_t h,
                      const uint8_t *tiles) {
  for (uint8_t i = 0; i < h; ++i) {
    for (uint8_t j = 0; j < w; ++j) {
      const uint8_t sprite_tile = tiles[i * w + j];
      set_sprite_tile(sprite_tile, sprite_tile);
      move_sprite(sprite_tile, x + (j * 8) + 8, y + (i * 8) + 16);
    }
  }
}

#endif
