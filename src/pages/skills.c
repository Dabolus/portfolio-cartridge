#ifndef PAGES_SKILLS_C
#define PAGES_SKILLS_C

#include "../../res/assets/phrases.h"
#include "../helpers/text.h"
#include "../helpers/utils.h"
#include "handler.h"
#include <gbdk/platform.h>

void skills_setup() {
  set_bkg_tiles(1, 1, ARRAY_LEN(skills), 1, skills);
  fillarea(0, 3, DEVICE_SCREEN_WIDTH, 1, 0x33);
}

void skills_loop(uint8_t *current_loop_count, uint8_t keys) {
  if (keys & J_B) {
    set_page(HOME_MENU);
  }
}

#endif
