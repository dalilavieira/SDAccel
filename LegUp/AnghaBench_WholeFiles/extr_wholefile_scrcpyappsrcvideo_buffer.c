#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {scalar_t__ started; } ;
struct video_buffer {int rendering_frame_consumed; int interrupted; int /*<<< orphan*/  rendering_frame_consumed_cond; int /*<<< orphan*/  mutex; int /*<<< orphan*/  const* rendering_frame; TYPE_1__ fps_counter; int /*<<< orphan*/  const* decoding_frame; } ;
typedef  int /*<<< orphan*/  const AVFrame ;

/* Variables and functions */
 int /*<<< orphan*/  SDL_DestroyCond (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SDL_DestroyMutex (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SDL_assert (int) ; 
 int /*<<< orphan*/  av_frame_free (int /*<<< orphan*/  const**) ; 
 int /*<<< orphan*/  cond_signal (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cond_wait (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fps_counter_add_rendered_frame (TYPE_1__*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ ) ; 

void
video_buffer_destroy(struct video_buffer *vb) {
#ifndef SKIP_FRAMES
    SDL_DestroyCond(vb->rendering_frame_consumed_cond);
#endif
    SDL_DestroyMutex(vb->mutex);
    av_frame_free(&vb->rendering_frame);
    av_frame_free(&vb->decoding_frame);
}

__attribute__((used)) static void
video_buffer_swap_frames(struct video_buffer *vb) {
    AVFrame *tmp = vb->decoding_frame;
    vb->decoding_frame = vb->rendering_frame;
    vb->rendering_frame = tmp;
}

void
video_buffer_offer_decoded_frame(struct video_buffer *vb,
                                 bool *previous_frame_skipped) {
    mutex_lock(vb->mutex);
#ifndef SKIP_FRAMES
    // if SKIP_FRAMES is disabled, then the decoder must wait for the current
    // frame to be consumed
    while (!vb->rendering_frame_consumed && !vb->interrupted) {
        cond_wait(vb->rendering_frame_consumed_cond, vb->mutex);
    }
#else
    if (vb->fps_counter.started && !vb->rendering_frame_consumed) {
        fps_counter_add_skipped_frame(&vb->fps_counter);
    }
#endif

    video_buffer_swap_frames(vb);

    *previous_frame_skipped = !vb->rendering_frame_consumed;
    vb->rendering_frame_consumed = false;

    mutex_unlock(vb->mutex);
}

const AVFrame *
video_buffer_consume_rendered_frame(struct video_buffer *vb) {
    SDL_assert(!vb->rendering_frame_consumed);
    vb->rendering_frame_consumed = true;
    if (vb->fps_counter.started) {
        fps_counter_add_rendered_frame(&vb->fps_counter);
    }
#ifndef SKIP_FRAMES
    // if SKIP_FRAMES is disabled, then notify the decoder the current frame is
    // consumed, so that it may push a new one
    cond_signal(vb->rendering_frame_consumed_cond);
#endif
    return vb->rendering_frame;
}

void
video_buffer_interrupt(struct video_buffer *vb) {
#ifdef SKIP_FRAMES
    (void) vb; // unused
#else
    mutex_lock(vb->mutex);
    vb->interrupted = true;
    mutex_unlock(vb->mutex);
    // wake up blocking wait
    cond_signal(vb->rendering_frame_consumed_cond);
#endif
}

