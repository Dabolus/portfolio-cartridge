#ifndef PAGES_HANDLER_C
#define PAGES_HANDLER_C

#include "handler.h"
#include "../helpers/fade.h"
#include "../helpers/utils.h"
#include "about.h"
#include "contacts.h"
#include "home_header.h"
#include "home_menu.h"
#include "projects.h"
#include "skills.h"

enum Page current_page = HOME_HEADER;

void init_page(enum Page page) {
  switch (current_page) {
  case HOME_MENU:
    home_menu_unload();
    break;
  case CONTACTS:
    contacts_unload();
    break;
  }
  switch (page) {
  case HOME_HEADER:
    home_header_setup();
    break;
  case HOME_MENU:
    home_menu_setup();
    break;
  case ABOUT:
    about_setup();
    break;
  case CONTACTS:
    contacts_setup();
    break;
  case PROJECTS:
    projects_setup();
    break;
  case SKILLS:
    skills_setup();
    break;
  }
  current_page = page;
}

void set_page(enum Page page) {
  fadeout(16);
  clearscreen();
  init_page(page);
  fadein(16);
}

#endif
