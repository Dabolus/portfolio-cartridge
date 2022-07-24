#pragma once
#ifndef PAGES_CONTACTS_H
#define PAGES_CONTACTS_H

#include <gbdk/platform.h>

extern void contacts_setup(void);

extern void contacts_loop(uint8_t *current_loop_count, uint8_t keys);

#endif
