#pragma once
#ifndef PAGES_HOME_HEADER_H
#define PAGES_HOME_HEADER_H

#include <gbdk/platform.h>

extern const uint8_t typewritten_text_start_x;
extern const uint8_t typewritten_text_start_y;

extern void home_header_setup(void);

extern void home_header_loop(uint8_t *current_loop_count);

#endif
