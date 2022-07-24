#ifndef ASSETS_ARROW_C
#define ASSETS_ARROW_C

#include "arrow.h"

// 01 01 00 00 00 00 00 00
// 01 11 01 01 00 00 00 00
// 01 11 11 11 01 01 00 00
// 01 11 11 11 11 11 01 01
// 01 11 11 11 11 11 01 01
// 01 11 11 11 01 01 00 00
// 01 11 01 01 00 00 00 00
// 01 01 00 00 00 00 00 00

const unsigned char arrow_data[] = {0xC0, 0x00, 0xF0, 0x40, 0xFC, 0x70,
                                    0xFF, 0x7C, 0xFF, 0x7C, 0xFC, 0x70,
                                    0xF0, 0x40, 0xC0, 0x00};

const unsigned char arrow_tiles[] = {0x59};

#endif
