#pragma once
#ifndef HELPERS_UTILS_H
#define HELPERS_UTILS_H

#include <gbdk/platform.h>

extern void fastdelay(uint8_t num_loops);

extern void cleararea(uint8_t x, uint8_t y, uint8_t w, uint8_t h);

extern void clearscreen(void);

extern void throttlekey(uint8_t keys, uint8_t key, void (*cb)(void));

#endif
