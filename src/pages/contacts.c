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
  set_sprite_data(0, 4, google_developers_data);
  set_sprite_tiles(4, 28, 2, 2, google_developers_tiles);
  set_bkg_tiles(3, 4, ARRAY_LEN(gga), 1, gga);
  // GitHub
  set_sprite_data(4, 4, github_data);
  set_sprite_tiles(4, 44, 2, 2, github_tiles);
  set_bkg_tiles(3, 6, ARRAY_LEN(dabolus), 1, dabolus);
  // Twitter
  set_sprite_data(8, 4, twitter_data);
  set_sprite_tiles(4, 60, 2, 2, twitter_tiles);
  set_bkg_tiles(3, 8, ARRAY_LEN(dabolus), 1, dabolus);
  // Telegram
  set_sprite_data(12, 4, telegram_data);
  set_sprite_tiles(4, 76, 2, 2, telegram_tiles);
  set_bkg_tiles(3, 10, ARRAY_LEN(dabolus), 1, dabolus);
  // Polywork
  set_sprite_data(16, 4, polywork_data);
  set_sprite_tiles(4, 92, 2, 2, polywork_tiles);
  set_bkg_tiles(3, 12, ARRAY_LEN(dabolus), 1, dabolus);
  // LinkedIn
  set_sprite_data(20, 4, linkedin_data);
  set_sprite_tiles(4, 108, 2, 2, linkedin_tiles);
  set_bkg_tiles(3, 14, ARRAY_LEN(giorgio), 1, giorgio);
  set_bkg_tiles(3 + ARRAY_LEN(giorgio), 14, ARRAY_LEN(garasto), 1, garasto);
  // Facebook
  set_sprite_data(24, 4, facebook_data);
  set_sprite_tiles(4, 124, 2, 2, facebook_tiles);
  set_bkg_tiles(3, 16, ARRAY_LEN(giorgio), 1, giorgio);
  set_bkg_tile_xy(3 + ARRAY_LEN(giorgio), 16, 0x08);
  set_bkg_tiles(4 + ARRAY_LEN(giorgio), 16, ARRAY_LEN(garasto), 1, garasto);

  SHOW_SPRITES;
}

void contacts_loop(uint8_t *current_loop_count, uint8_t keys) {
  *current_loop_count = 0;

  if (keys & J_B) {
    set_page(HOME_MENU);
  }
}

void contacts_unload() {
  // Hide the sprite layer
  HIDE_SPRITES;
  // Hide all the socials tiles (we use last Facebook tile as limit as it is the
  // last social tile loaded)
  for (uint8_t i = 0; i <= facebook_tiles[3]; ++i) {
    hide_sprite(i);
  }
}

#endif
