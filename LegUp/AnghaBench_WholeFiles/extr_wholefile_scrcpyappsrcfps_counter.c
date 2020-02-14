#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int uint32_t ;
struct fps_counter {int started; int slice_start; scalar_t__ nr_rendered; } ;

/* Variables and functions */
 int /*<<< orphan*/  LOGI (char*,scalar_t__) ; 
 void* SDL_GetTicks () ; 

void
fps_counter_init(struct fps_counter *counter) {
    counter->started = false;
    // no need to initialize the other fields, they are meaningful only when
    // started is true
}

void
fps_counter_start(struct fps_counter *counter) {
    counter->started = true;
    counter->slice_start = SDL_GetTicks();
    counter->nr_rendered = 0;
#ifdef SKIP_FRAMES
    counter->nr_skipped = 0;
#endif
}

void
fps_counter_stop(struct fps_counter *counter) {
    counter->started = false;
}

__attribute__((used)) static void
display_fps(struct fps_counter *counter) {
#ifdef SKIP_FRAMES
    if (counter->nr_skipped) {
        LOGI("%d fps (+%d frames skipped)", counter->nr_rendered,
                                            counter->nr_skipped);
    } else {
#endif
    LOGI("%d fps", counter->nr_rendered);
#ifdef SKIP_FRAMES
    }
#endif
}

__attribute__((used)) static void
check_expired(struct fps_counter *counter) {
    uint32_t now = SDL_GetTicks();
    if (now - counter->slice_start >= 1000) {
        display_fps(counter);
        // add a multiple of one second
        uint32_t elapsed_slices = (now - counter->slice_start) / 1000;
        counter->slice_start += 1000 * elapsed_slices;
        counter->nr_rendered = 0;
#ifdef SKIP_FRAMES
        counter->nr_skipped = 0;
#endif
    }
}

void
fps_counter_add_rendered_frame(struct fps_counter *counter) {
    check_expired(counter);
    ++counter->nr_rendered;
}

