#pragma once
#ifndef HELPERS_UTILS_H
#define HELPERS_UTILS_H

#include <gbdk/platform.h>

#define CENTER_X(x)                                                            \
  ((DEVICE_SCREEN_WIDTH - x) % 2 ? (DEVICE_SCREEN_WIDTH - x) / 2 + 1           \
                                 : (DEVICE_SCREEN_WIDTH - x) / 2)

extern void fastdelay(uint8_t num_loops);

extern void cleararea(uint8_t x, uint8_t y, uint8_t w, uint8_t h);

extern void clearscreen(void);

extern void drawframe(
    uint8_t x, uint8_t y, uint8_t w, uint8_t h, unsigned char top_border_tile,
    unsigned char top_right_corner_tile, unsigned char right_border_tile,
    unsigned char bottom_right_corner_tile, unsigned char bottom_border_tile,
    unsigned char bottom_left_corner_tile, unsigned char left_border_tile,
    unsigned char top_left_corner_tile);

extern void drawtext(uint8_t start_x, uint8_t start_y,
                     const unsigned char *text);

extern void throttlekey(uint8_t keys, uint8_t key, void (*cb)(void));

extern struct ScrollerConfig {
  uint8_t y;
  uint8_t height;
  uint8_t content_total_rows;
  const unsigned char content[][20];
};

extern void scroller_draw(const unsigned char content[][20]);

extern void scroller_init(struct ScrollerConfig *config);

extern void scroller_row_up(void);

extern void scroller_row_down(void);

extern void scroller_page_up(void);

extern void scroller_page_down(void);

extern void set_sprite_tiles(uint8_t x, uint8_t y, uint8_t w, uint8_t h,
                             const uint8_t *tiles);

extern uint8_t force_value_in_range(uint8_t value, uint8_t min, uint8_t max);

#endif
