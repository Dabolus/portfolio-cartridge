#ifndef HELPERS_FADE_C
#define HELPERS_FADE_C

#include "fade.h"
#include "utils.h"
#include <gbdk/platform.h>

void fade_gb(uint8_t to, uint8_t duration, BOOLEAN reverse) {
#ifdef NINTENDO
  uint16_t start =
      reverse ? ((uint16_t)BGP_REG << 8) | to : ((uint16_t)to << 8) | BGP_REG;
  for (uint8_t i = 1; i != 5 && BGP_REG != to; ++i) {
    BGP_REG = start >> ((reverse ? 4 - i : i) << 1);
    fastdelay(duration / 4);
  }
#endif
}

void fade_gbc(palette_color_t from[4], palette_color_t to[4],
              uint8_t duration) {
  // TODO: implement this
}

uint8_t previous_gb_bg_palette;

/**
 * Fade out the current screen by changing the Game Boy palette to be darker
 * and darker (or brighter and brighter if theme is set to dark). Note that the
 * Game Boy color palette only has a total of 4 colors, so the total animation
 * frames will always be 4 and will change every `duration / 4` VBlank
 * interrupts.
 *
 * @param duration The total duration of the fade animation in VBlank
 * interrupts. This should be a multiple of 4.
 */
void fadeout(uint8_t duration) {
  if (DEVICE_SUPPORTS_COLOR) {
    // TODO: implement this
  } else {
#ifdef NINTENDO
    previous_gb_bg_palette = BGP_REG;
    // Fade to light if theme is light, otherwise fade to dark
    fade_gb(BGP_REG == 0xE4 ? 0xFF : 0x00, duration, FALSE);
#endif
  }
  // Don't use wait_vbl_done() until display is turned on again
  DISPLAY_OFF;
}

/**
 * Fade in the current screen by changing the Game Boy palette to be the
 * original one (before `fadeout` was called). Note that the Game Boy color
 * palette only has a total of 4 colors, so the total animation frames will
 * always be 4 and will change every `duration / 4` VBlank interrupts.
 *
 * @param duration The total duration of the fade animation in VBlank
 * interrupts. This should be a multiple of 4.
 */
void fadein(uint8_t duration) {
  // Make sure the display is turned on so that wait_vbl_done() can be used
  DISPLAY_ON;
  if (DEVICE_SUPPORTS_COLOR) {
    // TODO: implement this
  } else {
    fade_gb(previous_gb_bg_palette, duration, TRUE);
  }
}

#endif
