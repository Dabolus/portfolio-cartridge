#pragma once
#ifndef HELPERS_TEXT_H
#define HELPERS_TEXT_H

#define ARRAY_LEN(A) sizeof(A) / sizeof(A[0])
#define PRINT_TEXT(X, Y, T) set_bkg_tiles(X, Y, ARRAY_LEN(T), 1, T)
#define PRINT_CENTERED_TEXT(Y, T) PRINT_TEXT(CENTER_X(ARRAY_LEN(T)), Y, T)
#define TYPEWRITTEN_TEXT_MAX_LENGTH (DEVICE_SCREEN_WIDTH - 2)

#endif
