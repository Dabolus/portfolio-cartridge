#ifndef PAGES_CONTACTS_C
#define PAGES_CONTACTS_C

#include "contacts.h"
#include "../../res/assets/phrases.h"
#include "../../res/assets/socials.h"
#include "../helpers/text.h"
#include "../helpers/utils.h"
#include "handler.h"
#include <gbdk/platform.h>

void contacts_setup(void) {
  set_bkg_tiles(1, 1, ARRAY_LEN(contacts), 1, contacts);
  fill_bkg_rect(0, 3, DEVICE_SCREEN_WIDTH, 1, 0x32);

  // QR code
  set_bkg_tiles(13, 5, ARRAY_LEN(email), 1, email);
  set_bkg_1bpp_data(51, 49, email_qr_data);
  set_bkg_tiles(12, 6, 7, 7, email_qr_tiles);

  // Socials
  // Google Developers
  set_sprite_data(0, 4, google_developers_data);
  for (uint8_t i = 0; i < 4; ++i) {
    set_sprite_prop(i, 1);
  }
  set_sprite_palette_entry(1, 2, google_developers_color);
  set_sprite_palette_entry(1, 3, RGB8(0, 0, 0));
  set_sprite_tiles(4, 28, 2, 2, google_developers_tiles);
  set_bkg_tiles(3, 4, ARRAY_LEN(gga), 1, gga);
  // GitHub
  set_sprite_data(4, 4, github_data);
  for (uint8_t i = 0; i < 4; ++i) {
    set_sprite_prop(i + 4, 1);
  }
  set_sprite_palette_entry(1, 1, github_color);
  set_sprite_palette_entry(1, 3, RGB8(0, 0, 0));
  set_sprite_tiles(4, 44, 2, 2, github_tiles);
  set_bkg_tiles(3, 6, ARRAY_LEN(dabolus), 1, dabolus);
  // Twitter/X
  set_sprite_data(8, 4, x_data);
  for (uint8_t i = 0; i < 4; ++i) {
    set_sprite_prop(i + 8, 2);
  }
  set_sprite_palette_entry(2, 2, x_color);
  set_sprite_palette_entry(2, 3, RGB8(0, 0, 0));
  set_sprite_tiles(4, 60, 2, 2, x_tiles);
  set_bkg_tiles(3, 8, ARRAY_LEN(dabolus), 1, dabolus);
  // Telegram
  set_sprite_data(12, 4, telegram_data);
  for (uint8_t i = 0; i < 4; ++i) {
    set_sprite_prop(i + 12, 2);
  }
  set_sprite_palette_entry(2, 1, telegram_color);
  set_sprite_palette_entry(2, 3, RGB8(0, 0, 0));
  set_sprite_tiles(4, 76, 2, 2, telegram_tiles);
  set_bkg_tiles(3, 10, ARRAY_LEN(dabolus), 1, dabolus);
  // Polywork
  set_sprite_data(16, 4, polywork_data);
  for (uint8_t i = 0; i < 4; ++i) {
    set_sprite_prop(i + 16, 3);
  }
  set_sprite_palette_entry(3, 2, polywork_color);
  set_sprite_palette_entry(3, 3, RGB8(0, 0, 0));
  set_sprite_tiles(4, 92, 2, 2, polywork_tiles);
  set_bkg_tiles(3, 12, ARRAY_LEN(dabolus), 1, dabolus);
  // LinkedIn
  set_sprite_data(20, 4, linkedin_data);
  for (uint8_t i = 0; i < 4; ++i) {
    set_sprite_prop(i + 20, 3);
  }
  set_sprite_palette_entry(3, 1, linkedin_color);
  set_sprite_palette_entry(3, 3, RGB8(0, 0, 0));
  set_sprite_tiles(4, 108, 2, 2, linkedin_tiles);
  set_bkg_tiles(3, 14, ARRAY_LEN(giorgio), 1, giorgio);
  set_bkg_tiles(3 + ARRAY_LEN(giorgio), 14, ARRAY_LEN(garasto), 1, garasto);
  // Facebook
  set_sprite_data(24, 4, facebook_data);
  for (uint8_t i = 0; i < 4; ++i) {
    set_sprite_prop(i + 24, 4);
  }
  set_sprite_palette_entry(4, 2, facebook_color);
  set_sprite_palette_entry(4, 3, RGB8(0, 0, 0));
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

void contacts_unload(void) {
  // Hide the sprite layer
  HIDE_SPRITES;
  // Hide all the socials tiles (we use last Facebook tile as limit as it is the
  // last social tile loaded)
  for (uint8_t i = 0; i <= facebook_tiles[3]; ++i) {
    hide_sprite(i);
  }
}

#endif
