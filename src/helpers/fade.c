#ifndef _HELPERS_FADE_
#define _HELPERS_FADE_

#include <gbdk/platform.h>
#include <stdint.h>

#include "utils.c"

static const uint16_t bg_palette[] = {RGB_WHITE, RGB_LIGHTGRAY, RGB_DARKGRAY,
                                      RGB_BLACK, RGB_BLACK,     RGB_BLACK,
                                      RGB_BLACK};

/**
 * Fade out the current screen by changing the Game Boy palette to be darker and
 * darker. Note that the Game Boy color palette only has a total of 4 colors, so
 * the total animation frames will always be 3 and will change every
 * `fade_duration / 3` VBlank interrupts.
 *
 * @param fade_duration The total duration of the fade animation in VBlank
 * interrupts. This should be a multiple of 3.
 */
void fadeout(uint8_t fade_duration) {
  for (uint8_t i = 1; i != 4; ++i) {
    // 0xFFE4 is 11'11 11'11 11'10 01'00
    // (i << 1) is i*2
    // Each iteration the number gets shifted by 2 bits to the right
    // Each two bit pair represents a color on DMG
    // BGP_REG is 8 bit and upper 8 bit will be discarded on cast
    // i=0 would be 11'10 01'00
    // i=1 is 11'11 10'01 etc.
    // The resulting color palette will be // 0xE4 -> 0xF9 -> 0xFE
    BGP_REG = (0xFFE4 >> (i << 1));
    // Sets palette #0 for Game Boy Color
    // bg_palette is just the start address of the array
    set_bkg_palette(0, 1, bg_palette + i);
    fastdelay(fade_duration / 3);
  };
  // Don't use wait_vbl_done() until display is turned on again
  DISPLAY_OFF;
}

/**
 * Fade in the current screen by changing the Game Boy palette to be brighter
 * and brighter. Note that the Game Boy color palette only has a total of 4
 * colors, so the total animation frames will always be 3 and will change every
 * `fade_duration / 3` VBlank interrupts.
 *
 * @param fade_duration The total duration of the fade animation in VBlank
 * interrupts. This should be a multiple of 3.
 */
void fadein(uint8_t fade_duration) {
  // Make sure the display is turned on so that wait_vbl_done() can be used
  DISPLAY_ON;

  // This is identical to what we do in fadeout(), except we start from the end
  // 0xFE -> 0xF9 -> 0xE4
  for (uint8_t i = 2; i != 255; --i) {
    BGP_REG = (0xFFE4 >> (i << 1));
    set_bkg_palette(0, 1, bg_palette + i);
    fastdelay(fade_duration / 3);
  };
}

#endif
