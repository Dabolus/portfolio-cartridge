#pragma once
#ifndef PAGES_PROJECTS_H
#define PAGES_PROJECTS_H

#include <gbdk/platform.h>

extern void projects_setup(void);

extern void projects_loop(uint8_t *current_loop_count, uint8_t keys);

extern void projects_unload(void);

#endif
