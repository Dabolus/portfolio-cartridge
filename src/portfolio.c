#include "../res/fonts/font_early_game_boy.h"
#include "helpers/fade.h"
#include "helpers/sound.h"
#include "helpers/text.h"
#include "helpers/theme.h"
#include "helpers/utils.h"
#include "pages/about.h"
#include "pages/contacts.h"
#include "pages/handler.h"
#include "pages/home_header.h"
#include "pages/home_menu.h"
#include "pages/projects.h"
#include "pages/skills.h"
#include <gbdk/platform.h>

void handle_theme_switch(void) {
  sound_switch();
  theme_switch();
}

void main(void) {
  sound_init();
  theme_init();
  // Load font in the background data (2 colors -> 1 bit per pixel)
  set_bkg_1bpp_data(0, 50, font_early_game_boy);
  init_page(HOME_HEADER);
  SHOW_BKG;
  music_start();

  uint8_t current_loop_count = 0;

  while (1) {
    uint8_t keys = joypad();

    // Allow switching theme by pressing Select
    throttlekey(keys, J_SELECT, &handle_theme_switch);

    // Allow going back to the home header from any page
    // by pressing Start
    if (current_page != HOME_HEADER && (keys & J_START)) {
      set_page(HOME_HEADER);
      music_start();
      continue;
    }

    // Play back sound when pressing B while not on home header
    if (current_page != HOME_HEADER && (keys & J_B)) {
      sound_back();
    }

    switch (current_page) {
    case HOME_HEADER:
      home_header_loop(&current_loop_count, keys);
      break;
    case HOME_MENU: {
      home_menu_loop(&current_loop_count, keys);
      break;
    }
    case ABOUT:
      about_loop(&current_loop_count, keys);
      break;
    case CONTACTS:
      contacts_loop(&current_loop_count, keys);
      break;
    case PROJECTS:
      projects_loop(&current_loop_count, keys);
      break;
    case SKILLS:
      skills_loop(&current_loop_count, keys);
      break;
    }

    fastdelay(3);
    ++current_loop_count;
  }
}
