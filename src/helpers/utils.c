#ifndef _HELPERS_UTILS_
#define _HELPERS_UTILS_

#include <stdint.h>

void fastdelay(uint8_t num_loops) {
  for (uint8_t i = 0; i != num_loops; i++) {
    wait_vbl_done();
  }
}

#endif
