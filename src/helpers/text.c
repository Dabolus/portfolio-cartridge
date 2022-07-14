#ifndef _HELPERS_TEXT_
#define _HELPERS_TEXT_

#include "../font_early_game_boy.h"
#include <gbdk/platform.h>

#define ARRAY_LEN(A) sizeof(A) / sizeof(A[0])
#define PRINT_TEXT(X, Y, T) set_bkg_tiles(X, Y, ARRAY_LEN(T), 1, T)
#define TYPEWRITTEN_TEXT_MAX_LENGTH (DEVICE_SCREEN_WIDTH - 2)

#endif
