#pragma once
#ifndef HELPERS_UTILS_H
#define HELPERS_UTILS_H

#include <gbdk/platform.h>

extern void fastdelay(uint8_t num_loops);

extern void fillarea(uint8_t x, uint8_t y, uint8_t w, uint8_t h,
                     unsigned char c);

extern void cleararea(uint8_t x, uint8_t y, uint8_t w, uint8_t h);

extern void clearscreen(void);

extern void throttlekey(uint8_t keys, uint8_t key, void (*cb)(void));

extern struct ScrollerConfig {
  uint8_t y;
  uint8_t height;
  uint8_t content_total_rows;
  const unsigned char content[][20];
};

extern void scroller_draw(const unsigned char content[][20]);

extern void scroller_init(struct ScrollerConfig *config);

extern void scroller_row_up();

extern void scroller_row_down();

extern void scroller_page_down();

#endif
