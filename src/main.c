#include "uv.h"

int main() {
  uv_loop_t *loop = uv_default_loop();

  uv_run(loop, UV_RUN_DEFAULT);
  printf("uvtest!\n");

  return 0;
}
