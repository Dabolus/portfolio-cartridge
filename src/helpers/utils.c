#ifndef _HELPERS_UTILS_
#define _HELPERS_UTILS_

#include <gbdk/platform.h>
#include <stdint.h>

void fastdelay(uint8_t num_loops) {
  for (uint8_t i = 0; i != num_loops; i++) {
    wait_vbl_done();
  }
}

void clearscreen() {
  for (uint8_t i = 0; i < DEVICE_SCREEN_WIDTH; ++i) {
    for (uint8_t j = 0; j < DEVICE_SCREEN_HEIGHT; ++j) {
      set_bkg_tile_xy(i, j, 0x00);
    }
  }
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

#endif
