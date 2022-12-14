#ifndef HELPERS_SOUND_C
#define HELPERS_SOUND_C

#include "sound.h"
#include <gbdk/platform.h>

void sound_init() {
#ifdef NINTENDO
  // NOTE: these registers must be in this specific order!
  // 1000 0000 in binary: turns on sound
  NR52_REG = 0x80;
  // Sets the volume for both left and right channel to max
  NR50_REG = 0x77;
  // 1111 1111 in binary, selects which channels to use
  // We have 4 stereo channels, and each of them is stereo
  // (1 bit for L and 1 for R), so we are telling the GB to
  // enable every channel on both L and R
  NR51_REG = 0xFF;
#endif
}

void sound_start() {
#ifdef NINTENDO
  NR10_REG = 0x00;
  NR11_REG = 0xC2;
  NR12_REG = 0xF4;
  NR13_REG = 0xB0;
  NR14_REG = 0x86;
#endif
}

void sound_enter() {
#ifdef NINTENDO
  NR10_REG = 0x00;
  NR11_REG = 0x80;
  NR12_REG = 0x63;
  NR13_REG = 0x73;
  NR14_REG = 0x86;
#endif
}

void sound_switch() {
#ifdef NINTENDO
  NR41_REG = 0x00;
  NR42_REG = 0x37;
  NR43_REG = 0x70;
  NR44_REG = 0x80;
#endif
}

void sound_scroll(uint8_t len) {
#ifdef NINTENDO
  NR41_REG = 0x00;
  NR42_REG = 0x60 | len;
  NR43_REG = 0x10;
  NR44_REG = 0x80;
#endif
}

void sound_bounce() {
#ifdef NINTENDO
  NR10_REG = 0x77;
  NR11_REG = 0xC0;
  NR12_REG = 0x83;
  NR13_REG = 0x66;
  NR14_REG = 0x86;
#endif
}

void sound_back() {
#ifdef NINTENDO
  NR41_REG = 0x1F;
  NR42_REG = 0xF1;
  NR43_REG = 0x30;
  NR44_REG = 0xC0;
#endif
}

#endif
