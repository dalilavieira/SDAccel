#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct TYPE_12__ {int flags; int flags2; int thread_count; int active_thread_type; int thread_type; TYPE_1__* codec; } ;
struct TYPE_11__ {int capabilities; } ;
typedef  TYPE_2__ AVCodecContext ;

/* Variables and functions */
 int AV_CODEC_CAP_AUTO_THREADS ; 
 int AV_CODEC_CAP_FRAME_THREADS ; 
 int AV_CODEC_CAP_SLICE_THREADS ; 
 int AV_CODEC_FLAG2_CHUNKS ; 
 int AV_CODEC_FLAG_LOW_DELAY ; 
 int AV_CODEC_FLAG_TRUNCATED ; 
 int /*<<< orphan*/  AV_LOG_WARNING ; 
 int FF_THREAD_FRAME ; 
 int FF_THREAD_SLICE ; 
 int MAX_AUTO_THREADS ; 
 int /*<<< orphan*/  av_log (TYPE_2__*,int /*<<< orphan*/ ,char*,int,int) ; 
 int /*<<< orphan*/  ff_frame_thread_free (TYPE_2__*,int) ; 
 int ff_frame_thread_init (TYPE_2__*) ; 
 int /*<<< orphan*/  ff_slice_thread_free (TYPE_2__*) ; 
 int ff_slice_thread_init (TYPE_2__*) ; 

__attribute__((used)) static void validate_thread_parameters(AVCodecContext *avctx)
{
    int frame_threading_supported = (avctx->codec->capabilities & AV_CODEC_CAP_FRAME_THREADS)
                                && !(avctx->flags  & AV_CODEC_FLAG_TRUNCATED)
                                && !(avctx->flags  & AV_CODEC_FLAG_LOW_DELAY)
                                && !(avctx->flags2 & AV_CODEC_FLAG2_CHUNKS);
    if (avctx->thread_count == 1) {
        avctx->active_thread_type = 0;
    } else if (frame_threading_supported && (avctx->thread_type & FF_THREAD_FRAME)) {
        avctx->active_thread_type = FF_THREAD_FRAME;
    } else if (avctx->codec->capabilities & AV_CODEC_CAP_SLICE_THREADS &&
               avctx->thread_type & FF_THREAD_SLICE) {
        avctx->active_thread_type = FF_THREAD_SLICE;
    } else if (!(avctx->codec->capabilities & AV_CODEC_CAP_AUTO_THREADS)) {
        avctx->thread_count       = 1;
        avctx->active_thread_type = 0;
    }

    if (avctx->thread_count > MAX_AUTO_THREADS)
        av_log(avctx, AV_LOG_WARNING,
               "Application has requested %d threads. Using a thread count greater than %d is not recommended.\n",
               avctx->thread_count, MAX_AUTO_THREADS);
}

int ff_thread_init(AVCodecContext *avctx)
{
    validate_thread_parameters(avctx);

    if (avctx->active_thread_type&FF_THREAD_SLICE)
        return ff_slice_thread_init(avctx);
    else if (avctx->active_thread_type&FF_THREAD_FRAME)
        return ff_frame_thread_init(avctx);

    return 0;
}

void ff_thread_free(AVCodecContext *avctx)
{
    if (avctx->active_thread_type&FF_THREAD_FRAME)
        ff_frame_thread_free(avctx, avctx->thread_count);
    else
        ff_slice_thread_free(avctx);
}

