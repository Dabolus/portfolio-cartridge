#include "assets/arrow.c"
#include "assets/home_header.c"
#include "assets/not.c"
#include "assets/phrases.c"
#include "font_early_game_boy.h"
#include "helpers/text.c"
#include <gbdk/platform.h>

void main() {
  // Load font in the background data (2 colors -> 1 bit per pixel)
  set_bkg_1bpp_data(0, 50, font_early_game_boy);
  // Load and draw hello message
  set_bkg_data(50, 39, home_header_data);
  set_bkg_tiles(0, 1, 20, 3, home_header_map);
  // Load and draw arrow
  set_bkg_data(89, 1, arrow_data);
  set_bkg_tiles(6, 13, 1, 1, arrow_tiles);
  // Load and draw "not" text
  set_bkg_data(90, 2, not_data);
  set_bkg_tiles(0, 16, 2, 1, not_tiles);
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

  SHOW_BKG;

  const uint8_t typewritten_text_start_x = 2;
  const uint8_t typewritten_text_start_y = 4;
  uint8_t current_text_x = 0;
  uint8_t current_text_y = 0;
  uint8_t current_text_index = 0;
  uint8_t current_text_id = 0;

  while (1) {
    // We reached the end of the phrase
    if (phrases[current_text_id][current_text_index] == 0xFF) {
      fastdelay(90);
      for (uint8_t i = 0; i < TYPEWRITTEN_TEXT_MAX_LENGTH; ++i) {
        for (uint8_t j = 0; j <= current_text_y; ++j) {
          set_bkg_tile_xy(typewritten_text_start_x + i,
                          typewritten_text_start_y + j, 0x00);
        }
      }
      ++current_text_id;
      if (current_text_id >= ARRAY_LEN(phrases)) {
        current_text_id = 0;
      }
      current_text_x = 0;
      current_text_y = 0;
      current_text_index = 0;
    }

    set_bkg_tile_xy(typewritten_text_start_x + current_text_x,
                    typewritten_text_start_y + current_text_y,
                    phrases[current_text_id][current_text_index]);
    // Skip all the spaces
    do {
      ++current_text_x;
      ++current_text_index;
    } while (phrases[current_text_id][current_text_index] == 0x00);
    // Skip all the newlines
    while (phrases[current_text_id][current_text_index] == 0xFE) {
      current_text_x = 0;
      ++current_text_y;
      ++current_text_index;
    }

    fastdelay(9);
  }
}
