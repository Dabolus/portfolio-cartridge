#ifndef PAGES_CONTACTS_C
#define PAGES_CONTACTS_C

#include "contacts.h"
#include "../../res/assets/phrases.h"
#include "../helpers/text.h"
#include "../helpers/utils.h"
#include "handler.h"
#include <gbdk/platform.h>

void contacts_setup() {
  set_bkg_tiles(1, 1, ARRAY_LEN(contacts), 1, contacts);
  fillarea(0, 3, DEVICE_SCREEN_WIDTH, 1, 0x32);
}

void contacts_loop(uint8_t *current_loop_count, uint8_t keys) {
  if (keys & J_B) {
    set_page(HOME_MENU);
  }
}

#endif
