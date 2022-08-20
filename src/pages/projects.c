#ifndef PAGES_PROJECTS_C
#define PAGES_PROJECTS_C

#include "projects.h"
#include "../../res/assets/phrases.h"
#include "../../res/generated/projects.h"
#include "../helpers/text.h"
#include "../helpers/utils.h"
#include "handler.h"
#include <gbdk/platform.h>

struct Project projects_info[TOTAL_PROJECTS];
uint8_t current_project_index = 0;

void render_current_project() {
  // Icon
  set_bkg_1bpp_data(58, 4, projects_info[current_project_index].icon_data);
  set_bkg_tiles(1, 4, 2, 2, project_icon_tiles);
  // Name
  fill_bkg_rect(4, 4, 15, 2, 0x00);
  drawtext(4, 4, projects_info[current_project_index].name_data);
  // Description
  fill_bkg_rect(1, 8, 18, 9, 0x00);
  fill_bkg_rect(1, 6, 18, 1, 0x36);
  fill_bkg_rect(1, 14, 18, 1, 0x32);
  drawtext(1, 8, projects_info[current_project_index].description_data);
  // Tags
  drawtext(1, 15, projects_info[current_project_index].tags_data);
}

void handle_projects_navigation_prev() {
  current_project_index =
      (current_project_index + TOTAL_PROJECTS - 1) % TOTAL_PROJECTS;
  render_current_project();
}
void handle_projects_navigation_next() {
  current_project_index = (current_project_index + 1) % TOTAL_PROJECTS;
  render_current_project();
}

void projects_setup() {
  set_bkg_tiles(1, 1, ARRAY_LEN(projects), 1, projects);
  drawframe(0, 3, DEVICE_SCREEN_WIDTH, DEVICE_SCREEN_HEIGHT - 3, 0x32, 0x33,
            0x34, 0x35, 0x36, 0x37, 0x38, 0x39);
  get_projects(projects_info);
  render_current_project();
}

void projects_loop(uint8_t *current_loop_count, uint8_t keys) {
  if (keys & J_B) {
    set_page(HOME_MENU);
  }

  throttlekey(keys, J_UP, &handle_projects_navigation_prev);
  throttlekey(keys, J_RIGHT, &handle_projects_navigation_next);
  throttlekey(keys, J_DOWN, &handle_projects_navigation_next);
  throttlekey(keys, J_LEFT, &handle_projects_navigation_prev);
}

#endif
