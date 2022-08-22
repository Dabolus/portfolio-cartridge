#ifndef PAGES_CONTACTS_C
#define PAGES_CONTACTS_C

#include "contacts.h"
#include "../../res/assets/phrases.h"
#include "../../res/assets/socials.h"
#include "../helpers/text.h"
#include "../helpers/utils.h"
#include "handler.h"
#include <gbdk/platform.h>

void contacts_setup() {
  set_bkg_tiles(1, 1, ARRAY_LEN(contacts), 1, contacts);
  fill_bkg_rect(0, 3, DEVICE_SCREEN_WIDTH, 1, 0x32);

  // QR code
  set_bkg_tiles(13, 5, ARRAY_LEN(email), 1, email);
  set_bkg_1bpp_data(51, 49, email_qr_data);
  set_bkg_tiles(12, 6, 7, 7, email_qr_tiles);

  // Socials
  // Google Developers
  set_bkg_data(100, 4, google_developers_data);
  set_bkg_tiles(0, 4, 2, 2, google_developers_tiles);
  set_bkg_tiles(2, 5, ARRAY_LEN(gga), 1, gga);
  // GitHub
  set_bkg_data(104, 4, github_data);
  set_bkg_tiles(0, 6, 2, 2, github_tiles);
  set_bkg_tiles(2, 7, ARRAY_LEN(dabolus), 1, dabolus);
  // Twitter
  set_bkg_data(108, 4, twitter_data);
  set_bkg_tiles(0, 8, 2, 2, twitter_tiles);
  set_bkg_tiles(2, 9, ARRAY_LEN(dabolus), 1, dabolus);
  // Telegram
  set_bkg_data(112, 4, telegram_data);
  set_bkg_tiles(0, 10, 2, 2, telegram_tiles);
  set_bkg_tiles(2, 11, ARRAY_LEN(dabolus), 1, dabolus);
  // Polywork
  set_bkg_data(116, 4, polywork_data);
  set_bkg_tiles(0, 12, 2, 2, polywork_tiles);
  set_bkg_tiles(2, 13, ARRAY_LEN(dabolus), 1, dabolus);
  // LinkedIn
  set_bkg_data(120, 4, linkedin_data);
  set_bkg_tiles(0, 14, 2, 2, linkedin_tiles);
  set_bkg_tiles(2, 15, ARRAY_LEN(giorgio), 1, giorgio);
  set_bkg_tiles(2 + ARRAY_LEN(giorgio), 15, ARRAY_LEN(garasto), 1, garasto);
  // Facebook
  set_bkg_data(124, 4, facebook_data);
  set_bkg_tiles(0, 16, 2, 2, facebook_tiles);
  set_bkg_tiles(2, 17, ARRAY_LEN(giorgio), 1, giorgio);
  set_bkg_tile_xy(2 + ARRAY_LEN(giorgio), 17, 0x08);
  set_bkg_tiles(3 + ARRAY_LEN(giorgio), 17, ARRAY_LEN(garasto), 1, garasto);
}

void contacts_loop(uint8_t *current_loop_count, uint8_t keys) {
  *current_loop_count = 0;

  if (keys & J_B) {
    set_page(HOME_MENU);
  }
}

#endif
