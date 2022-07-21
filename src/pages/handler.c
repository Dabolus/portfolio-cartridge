#ifndef _PAGES_HANDLER_
#define _PAGES_HANDLER_

#include "../helpers/fade.c"
#include "home_header.c"
#include "home_menu.c"

enum Page {
  HOME_HEADER,
  HOME_MENU,
};

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
