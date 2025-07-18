#ifndef ASSETS_SOCIALS_C
#define ASSETS_SOCIALS_C

#include "socials.h"
#include <gbdk/platform.h>

const unsigned char email_qr_data[] = {
    0x00, 0x00, 0x00, 0x1F, 0x1F, 0x18, 0x18, 0x19, 0x00, 0x00, 0x00, 0xFF,
    0xFF, 0x01, 0x01, 0xF9, 0x00, 0x00, 0x00, 0x81, 0x81, 0x99, 0x99, 0x81,
    0x00, 0x00, 0x00, 0x86, 0x86, 0xE1, 0xE1, 0x80, 0x00, 0x00, 0x00, 0x61,
    0x61, 0xF9, 0xF9, 0x61, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x80, 0x80, 0x9F,
    0x00, 0x00, 0x00, 0xF8, 0xF8, 0x18, 0x18, 0x98, 0x19, 0x19, 0x19, 0x19,
    0x19, 0x18, 0x18, 0x1F, 0xF9, 0xF9, 0xF9, 0xF9, 0xF9, 0x01, 0x01, 0xFF,
    0x81, 0x80, 0x80, 0x81, 0x81, 0x99, 0x99, 0x99, 0x80, 0x19, 0x19, 0xF9,
    0xF9, 0x98, 0x98, 0x99, 0x61, 0x81, 0x81, 0x81, 0x81, 0x79, 0x79, 0x99,
    0x9F, 0x9F, 0x9F, 0x9F, 0x9F, 0x80, 0x80, 0xFF, 0x98, 0x98, 0x98, 0x98,
    0x98, 0x18, 0x18, 0xF8, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x06,
    0xFF, 0x00, 0x00, 0x1F, 0x1F, 0x98, 0x98, 0x01, 0x99, 0x1F, 0x1F, 0xE7,
    0xE7, 0x7F, 0x7F, 0x98, 0x99, 0x80, 0x80, 0x86, 0x86, 0xFE, 0xFE, 0x1F,
    0x99, 0x60, 0x60, 0x61, 0x61, 0x60, 0x60, 0xE7, 0xFF, 0x00, 0x00, 0xE0,
    0xE0, 0x18, 0x18, 0x81, 0xF8, 0x00, 0x00, 0x60, 0x60, 0x00, 0x00, 0x80,
    0x06, 0x06, 0x06, 0x01, 0x01, 0x19, 0x19, 0x01, 0x01, 0x1E, 0x1E, 0x87,
    0x87, 0xE0, 0xE0, 0xE1, 0x98, 0x61, 0x61, 0xF9, 0xF9, 0x66, 0x66, 0x98,
    0x1F, 0xF9, 0xF9, 0x99, 0x99, 0x7E, 0x7E, 0x60, 0xE7, 0xE0, 0xE0, 0x99,
    0x99, 0x01, 0x01, 0x61, 0x81, 0x1F, 0x1F, 0xE1, 0xE1, 0x9F, 0x9F, 0xFE,
    0x80, 0x98, 0x98, 0xF8, 0xF8, 0x80, 0x80, 0x00, 0x01, 0x00, 0x00, 0x1E,
    0x1E, 0x00, 0x00, 0x1F, 0xE1, 0x00, 0x00, 0x1F, 0x1F, 0x00, 0x00, 0xFF,
    0x98, 0x1F, 0x1F, 0xF8, 0xF8, 0x19, 0x19, 0x9F, 0x60, 0xF8, 0xF8, 0x79,
    0x79, 0xE6, 0xE6, 0xF8, 0x61, 0x7F, 0x7F, 0x9F, 0x9F, 0x18, 0x18, 0x79,
    0xFE, 0xF9, 0xF9, 0xF9, 0xF9, 0x1E, 0x1E, 0x9F, 0x00, 0x98, 0x98, 0xF8,
    0xF8, 0x00, 0x00, 0x80, 0x1F, 0x18, 0x18, 0x19, 0x19, 0x19, 0x19, 0x19,
    0xFF, 0x01, 0x01, 0xF9, 0xF9, 0xF9, 0xF9, 0xF9, 0x9F, 0x98, 0x98, 0x9E,
    0x9E, 0x81, 0x81, 0x81, 0xF8, 0x78, 0x78, 0x60, 0x60, 0xFF, 0xFF, 0x98,
    0x79, 0x18, 0x18, 0x7F, 0x7F, 0x9E, 0x9E, 0x06, 0x9F, 0x19, 0x19, 0xF9,
    0xF9, 0x66, 0x66, 0x01, 0x80, 0xF8, 0xF8, 0x80, 0x80, 0x18, 0x18, 0xE0,
    0x19, 0x18, 0x18, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0xF9, 0x01, 0x01, 0xFF,
    0xFF, 0x00, 0x00, 0x00, 0x81, 0x80, 0x80, 0x86, 0x86, 0x00, 0x00, 0x00,
    0x98, 0x07, 0x07, 0x66, 0x66, 0x00, 0x00, 0x00, 0x06, 0x9E, 0x9E, 0x07,
    0x07, 0x00, 0x00, 0x00, 0x01, 0x19, 0x19, 0x9F, 0x9F, 0x00, 0x00, 0x00,
    0xE0, 0xE0, 0xE0, 0xF8, 0xF8, 0x00, 0x00, 0x00};
const unsigned char email_qr_tiles[] = {
    0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C,
    0x3D, 0x3E, 0x3F, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46,
    0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50,
    0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A,
    0x5B, 0x5C, 0x5D, 0x5E, 0x5F, 0x60, 0x61, 0x62, 0x63};

const unsigned char google_developers_data[] = {
    0x00, 0x00, 0x07, 0x07, 0x1C, 0x1F, 0x30, 0x3F, 0x20, 0x39, 0x60,
    0x71, 0x40, 0x47, 0x40, 0x7F, 0x00, 0x00, 0xE0, 0xE0, 0x38, 0xF8,
    0x0C, 0xFC, 0x04, 0x9C, 0x06, 0x8E, 0x02, 0xE2, 0x02, 0xF2, 0x40,
    0x4F, 0x40, 0x47, 0x60, 0x71, 0x20, 0x39, 0x30, 0x3F, 0x1C, 0x1F,
    0x07, 0x07, 0x00, 0x00, 0x02, 0xFE, 0x02, 0xE2, 0x06, 0x8E, 0x04,
    0x9C, 0x0C, 0xFC, 0x38, 0xF8, 0xE0, 0xE0, 0x00, 0x00};
const unsigned char google_developers_tiles[] = {0x00, 0x01, 0x02, 0x03};
const palette_color_t google_developers_color = RGB8(66, 133, 244);

const unsigned char github_data[] = {
    0x00, 0x00, 0x07, 0x07, 0x1F, 0x1C, 0x3F, 0x30, 0x37, 0x20, 0x70,
    0x60, 0x70, 0x40, 0x67, 0x40, 0x00, 0x00, 0xE0, 0xE0, 0xF8, 0x38,
    0xFC, 0x0C, 0xEC, 0x04, 0x0E, 0x06, 0x0E, 0x02, 0xE6, 0x02, 0x6D,
    0x40, 0x6D, 0x40, 0x67, 0x60, 0x30, 0x20, 0x3F, 0x30, 0x1F, 0x1C,
    0x07, 0x07, 0x00, 0x00, 0xB6, 0x02, 0xB6, 0x02, 0xE6, 0x06, 0x0C,
    0x04, 0xFC, 0x0C, 0xF8, 0x38, 0xE0, 0xE0, 0x00, 0x00};
const unsigned char github_tiles[] = {0x04, 0x05, 0x06, 0x07};
const palette_color_t github_color = RGB8(51, 51, 51);

const unsigned char x_data[] = {
    0x00, 0x00, 0x07, 0x07, 0x1C, 0x1F, 0x30, 0x3F, 0x20, 0x31, 0x60,
    0x76, 0x40, 0x7B, 0x40, 0x7D, 0x00, 0x00, 0xE0, 0xE0, 0x38, 0xF8,
    0x0C, 0xFC, 0x04, 0xEC, 0x06, 0xDE, 0x02, 0x3E, 0x02, 0x7E, 0x40,
    0x7E, 0x40, 0x7C, 0x60, 0x7B, 0x20, 0x37, 0x30, 0x3F, 0x1C, 0x1F,
    0x07, 0x07, 0x00, 0x00, 0x02, 0xBE, 0x02, 0xDE, 0x06, 0x6E, 0x04,
    0x8C, 0x0C, 0xFC, 0x38, 0xF8, 0xE0, 0xE0, 0x00, 0x00};
const unsigned char x_tiles[] = {0x08, 0x09, 0x0A, 0x0B};
const palette_color_t x_color = RGB8(0, 0, 0);

const unsigned char telegram_data[] = {
    0x00, 0x00, 0x07, 0x07, 0x1F, 0x1C, 0x3F, 0x30, 0x3F, 0x20, 0x7E,
    0x60, 0x78, 0x40, 0x70, 0x40, 0x00, 0x00, 0xE0, 0xE0, 0xF8, 0x38,
    0xCC, 0x0C, 0x8C, 0x04, 0x0E, 0x06, 0x4E, 0x02, 0x8E, 0x02, 0x61,
    0x40, 0x61, 0x60, 0x72, 0x60, 0x3A, 0x20, 0x38, 0x30, 0x1C, 0x1C,
    0x07, 0x07, 0x00, 0x00, 0x8E, 0x02, 0x0E, 0x02, 0x0E, 0x06, 0x0C,
    0x04, 0x0C, 0x0C, 0xF8, 0x38, 0xE0, 0xE0, 0x00, 0x00};
const unsigned char telegram_tiles[] = {0x0C, 0x0D, 0x0E, 0x0F};
const palette_color_t telegram_color = RGB8(0, 136, 204);

const unsigned char polywork_data[] = {
    0x00, 0x00, 0x07, 0x07, 0x1C, 0x1F, 0x30, 0x3F, 0x20, 0x38, 0x60,
    0x75, 0x40, 0x70, 0x40, 0x75, 0x00, 0x00, 0xE0, 0xE0, 0x38, 0xF8,
    0x0C, 0xFC, 0x04, 0x1C, 0x06, 0xAE, 0x02, 0x0E, 0x02, 0xAE, 0x40,
    0x75, 0x40, 0x70, 0x60, 0x75, 0x20, 0x38, 0x30, 0x3F, 0x1C, 0x1F,
    0x07, 0x07, 0x00, 0x00, 0x02, 0xAE, 0x02, 0x1E, 0x06, 0xBE, 0x04,
    0x7C, 0x0C, 0xFC, 0x38, 0xF8, 0xE0, 0xE0, 0x00, 0x00};
const unsigned char polywork_tiles[] = {0x10, 0x11, 0x12, 0x13};
const palette_color_t polywork_color = RGB8(84, 61, 224);

const unsigned char linkedin_data[] = {
    0x00, 0x00, 0x07, 0x07, 0x1F, 0x1C, 0x3F, 0x30, 0x33, 0x20, 0x73,
    0x60, 0x7F, 0x40, 0x72, 0x40, 0x00, 0x00, 0xE0, 0xE0, 0xF8, 0x38,
    0xFC, 0x0C, 0xFC, 0x04, 0xFE, 0x06, 0xFE, 0x02, 0x9E, 0x02, 0x72,
    0x40, 0x72, 0x40, 0x72, 0x60, 0x32, 0x20, 0x3F, 0x30, 0x1F, 0x1C,
    0x07, 0x07, 0x00, 0x00, 0x0E, 0x02, 0x4E, 0x02, 0x4E, 0x06, 0x4C,
    0x04, 0xFC, 0x0C, 0xF8, 0x38, 0xE0, 0xE0, 0x00, 0x00};
const unsigned char linkedin_tiles[] = {0x14, 0x15, 0x16, 0x17};
const palette_color_t linkedin_color = RGB8(0, 119, 181);

const unsigned char facebook_data[] = {
    0x00, 0x00, 0x07, 0x07, 0x1C, 0x1F, 0x30, 0x3F, 0x20, 0x3E, 0x60,
    0x7E, 0x40, 0x7C, 0x40, 0x7C, 0x00, 0x00, 0xE0, 0xE0, 0x38, 0xF8,
    0x0C, 0x3C, 0x04, 0x3C, 0x06, 0x7E, 0x02, 0x3E, 0x02, 0x3E, 0x40,
    0x7E, 0x40, 0x7E, 0x60, 0x7E, 0x20, 0x3E, 0x30, 0x3E, 0x1C, 0x1F,
    0x07, 0x07, 0x00, 0x00, 0x02, 0x7E, 0x02, 0x7E, 0x06, 0x7E, 0x04,
    0x7C, 0x0C, 0x7C, 0x38, 0xF8, 0xE0, 0xE0, 0x00, 0x00};
const unsigned char facebook_tiles[] = {0x18, 0x19, 0x1A, 0x1B};
const palette_color_t facebook_color = RGB8(59, 89, 152);

#endif
