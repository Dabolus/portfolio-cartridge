#pragma once
#ifndef HELPERS_SOUND_H
#define HELPERS_SOUND_H

#include <gbdk/platform.h>

extern void sound_init(void);

extern void sound_start(void);

extern void sound_enter(void);

extern void sound_scroll(uint8_t len);

extern void sound_bounce(void);

extern void sound_back(void);

#endif
