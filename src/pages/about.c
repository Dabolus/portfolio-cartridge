#ifndef PAGES_ABOUT_C
#define PAGES_ABOUT_C

#include "../../res/assets/phrases.h"
#include "../helpers/text.h"
#include "../helpers/utils.h"
#include "handler.h"
#include <gbdk/platform.h>

void about_setup() {
  set_bkg_tiles(1, 1, ARRAY_LEN(about_me), 1, about_me);
  fillarea(0, 3, DEVICE_SCREEN_WIDTH, 1, 0x33);
}

void about_loop(uint8_t *current_loop_count, uint8_t keys) {
  if (keys & J_B) {
    set_page(HOME_MENU);
  }
}

#endif
