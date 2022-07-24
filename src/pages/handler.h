#pragma once
#ifndef PAGES_HANDLER_H
#define PAGES_HANDLER_H

extern enum Page {
  HOME_HEADER,
  HOME_MENU,
  ABOUT,
  CONTACTS,
  PROJECTS,
  SKILLS,
};

extern enum Page current_page;

extern void init_page(enum Page page);

extern void set_page(enum Page page);

#endif
