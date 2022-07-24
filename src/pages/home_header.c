#ifndef PAGES_HOME_HEADER_C
#define PAGES_HOME_HEADER_C

#include "home_header.h"
#include "../../res/assets/arrow.h"
#include "../../res/assets/google_g.h"
#include "../../res/assets/home_header.h"
#include "../../res/assets/not.h"
#include "../../res/assets/phrases.h"
#include "../helpers/text.h"
#include "handler.h"
#include <gbdk/platform.h>

const uint8_t typewritten_text_start_x = 2;
const uint8_t typewritten_text_start_y = 4;

uint8_t current_text_x;
uint8_t current_text_y;
uint8_t current_text_index;
uint8_t current_text_id;
BOOLEAN is_deleting;
BOOLEAN is_select_pressed;

void home_header_setup() {
  // Initialize state variables
  current_text_x = 0;
  current_text_y = 0;
  current_text_index = 0;
  current_text_id = 0;
  is_deleting = FALSE;
  is_select_pressed = FALSE;

  // Load and draw hello message
  set_bkg_data(50, 39, home_header_data);
  set_bkg_tiles(0, 1, 20, 3, home_header_map);
  // Load and draw arrow
  set_bkg_data(89, 1, arrow_data);
  set_bkg_tiles(6, 13, 1, 1, arrow_tiles);
  // Load and draw "not" text
  set_bkg_data(90, 2, not_data);
  set_bkg_tiles(0, 16, 2, 1, not_tiles);
  // Load Google G
  set_bkg_1bpp_data(92, 1, google_g_data);
  // Start
  PRINT_TEXT(8, 13, start);
  // Copyright
  PRINT_TEXT(4, 16, copyright);
  // License
  PRINT_TEXT(0, 17, license);
  // Typewritten text prefix and suffix
  PRINT_TEXT(0, 4, phrases_prefix);
  PRINT_TEXT(1, 8, phrases_suffix_1);
  PRINT_TEXT(1, 9, phrases_suffix_2);
  PRINT_TEXT(5, 10, phrases_suffix_3);
}

void home_header_loop(uint8_t *current_loop_count, uint8_t keys) {
  if (keys & (J_START | J_A)) {
    set_page(HOME_MENU);
  }

  // We reached the start of the phrase
  if (current_text_index == 0) {
    is_deleting = FALSE;
    *current_loop_count = 0;
  }
  // We reached the end of the phrase
  else if (phrases[current_text_id][current_text_index] == 0xFF) {
    is_deleting = TRUE;
    *current_loop_count = 0;
    --current_text_x;
    --current_text_index;
  }

  if (is_deleting) {
    if (*current_loop_count >= 30) {
      // Delete the character at the current position
      set_bkg_tile_xy(typewritten_text_start_x + current_text_x,
                      typewritten_text_start_y + current_text_y, 0x00);
      // Delete any spaces in the same loop
      do {
        --current_text_x;
        --current_text_index;
        set_bkg_tile_xy(typewritten_text_start_x + current_text_x,
                        typewritten_text_start_y + current_text_y, 0x00);
      } while (phrases[current_text_id][current_text_index] == 0x00);
      // Skip newlines
      if (phrases[current_text_id][current_text_index] == 0xFE) {
        // Detect the end of the next line and set our X to be at the end of
        // it
        current_text_x = 0;
        do {
          ++current_text_x;
        } while (
            phrases[current_text_id][current_text_index - current_text_x] !=
                0xFE &&
            phrases[current_text_id][current_text_index - current_text_x] !=
                0xFF &&
            current_text_index - current_text_x > 0);
        --current_text_y;
        --current_text_index;
      }

      if (current_text_index == 0) {
        ++current_text_id;
        if (current_text_id >= ARRAY_LEN(phrases)) {
          current_text_id = 0;
        }
        current_text_x = 0;
        current_text_y = 0;
      }
    }

  }
  // Only perform typewritten text animation every 3 loops
  else if (*current_loop_count % 3 == 0) {
    set_bkg_tile_xy(typewritten_text_start_x + current_text_x,
                    typewritten_text_start_y + current_text_y,
                    phrases[current_text_id][current_text_index]);
    // Skip spaces
    do {
      ++current_text_x;
      ++current_text_index;
    } while (phrases[current_text_id][current_text_index] == 0x00);
    // Skip newlines
    if (phrases[current_text_id][current_text_index] == 0xFE) {
      current_text_x = 0;
      ++current_text_y;
      ++current_text_index;
    }
  }
}

#endif
