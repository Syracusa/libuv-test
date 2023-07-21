#include <stdio.h>
#include "uv.h"

uint64_t app_start_time;
#define APP_TIME_MS() ((uv_hrtime() - app_start_time) / 1000000)

static void timer_callback(uv_timer_t *handle) {
    static const int iterations = 10;
    static int count = 0;
    printf("[%8ldms] Timer iterate => %d/%d\n", APP_TIME_MS(), count, iterations);
    if (++count == iterations) {
        printf("Out!\n");
        uv_timer_stop(handle);
    }
}

static void timer_test(uv_loop_t *loop) {
    uv_timer_t timer_req;

    uv_timer_init(loop, &timer_req);
    uv_timer_start(&timer_req, timer_callback, 0, 2000);
}

int main()
{
    app_start_time = uv_hrtime();
    uv_loop_t *loop = uv_default_loop();
    timer_test(loop);


    uv_run(loop, UV_RUN_DEFAULT);
    uv_loop_close(loop);
    return 0;
}
