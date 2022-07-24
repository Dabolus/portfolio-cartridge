#ifndef PAGES_HANDLER_C
#define PAGES_HANDLER_C

#include "handler.h"
#include "../helpers/fade.h"
#include "../helpers/utils.h"
#include "home_header.h"
#include "home_menu.h"

enum Page current_page = HOME_HEADER;

void init_page(enum Page page) {
  current_page = page;
  switch (page) {
  case HOME_HEADER:
    home_header_setup();
    break;
  case HOME_MENU:
    home_menu_setup();
    break;
  }
}

void set_page(enum Page page) {
  fadeout(16);
  clearscreen();
  init_page(page);
  fadein(16);
}

#endif
