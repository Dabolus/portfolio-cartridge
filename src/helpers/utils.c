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

#endif
