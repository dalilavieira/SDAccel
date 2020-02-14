#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct libcelt_context {int discard; int /*<<< orphan*/  dec; } ;
typedef  int /*<<< orphan*/  int16_t ;
struct TYPE_13__ {int frame_size; int channels; struct libcelt_context* priv_data; } ;
struct TYPE_12__ {int nb_samples; scalar_t__* data; } ;
struct TYPE_11__ {int size; int /*<<< orphan*/  data; } ;
struct TYPE_10__ {int version_id; } ;
typedef  int /*<<< orphan*/  CELTMode ;
typedef  TYPE_1__ CELTHeader ;
typedef  TYPE_2__ AVPacket ;
typedef  TYPE_3__ AVFrame ;
typedef  TYPE_4__ AVCodecContext ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_INVALIDDATA ; 
#define  CELT_ALLOC_FAIL 132 
#define  CELT_BAD_ARG 131 
#define  CELT_CORRUPTED_DATA 130 
#define  CELT_INTERNAL_ERROR 129 
#define  CELT_UNIMPLEMENTED 128 
 int /*<<< orphan*/  EFAULT ; 
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  ENOMEM ; 
 int /*<<< orphan*/  ENOSYS ; 
 int celt_decode (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  celt_header_init (TYPE_1__*,int /*<<< orphan*/ *,int,int) ; 
 int ff_get_buffer (TYPE_4__*,TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memmove (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static int ff_celt_error_to_averror(int err)
{
    switch (err) {
        case CELT_BAD_ARG:          return AVERROR(EINVAL);
#ifdef CELT_BUFFER_TOO_SMALL
        case CELT_BUFFER_TOO_SMALL: return AVERROR(ENOBUFS);
#endif
        case CELT_INTERNAL_ERROR:   return AVERROR(EFAULT);
        case CELT_CORRUPTED_DATA:   return AVERROR_INVALIDDATA;
        case CELT_UNIMPLEMENTED:    return AVERROR(ENOSYS);
#ifdef ENOTRECOVERABLE
        case CELT_INVALID_STATE:    return AVERROR(ENOTRECOVERABLE);
#endif
        case CELT_ALLOC_FAIL:       return AVERROR(ENOMEM);
        default:                    return AVERROR(EINVAL);
    }
}

__attribute__((used)) static int ff_celt_bitstream_version_hack(CELTMode *mode)
{
    CELTHeader header = { .version_id = 0 };
    celt_header_init(&header, mode, 960, 2);
    return header.version_id;
}

__attribute__((used)) static int libcelt_dec_decode(AVCodecContext *c, void *data,
                              int *got_frame_ptr, AVPacket *pkt)
{
    struct libcelt_context *celt = c->priv_data;
    AVFrame *frame = data;
    int err;
    int16_t *pcm;

    frame->nb_samples = c->frame_size;
    if ((err = ff_get_buffer(c, frame, 0)) < 0)
        return err;
    pcm = (int16_t *)frame->data[0];
    err = celt_decode(celt->dec, pkt->data, pkt->size, pcm, c->frame_size);
    if (err < 0)
        return ff_celt_error_to_averror(err);
    if (celt->discard) {
        frame->nb_samples -= celt->discard;
        memmove(pcm, pcm + celt->discard * c->channels,
                frame->nb_samples * c->channels * sizeof(int16_t));
        celt->discard = 0;
    }
    *got_frame_ptr = 1;
    return pkt->size;
}

