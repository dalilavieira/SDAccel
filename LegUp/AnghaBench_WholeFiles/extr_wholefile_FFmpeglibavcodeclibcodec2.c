#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_4__ ;
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int uint16_t ;
typedef  int /*<<< orphan*/  int16_t ;
struct TYPE_17__ {int block_align; int frame_size; TYPE_1__* priv_data; } ;
struct TYPE_16__ {int nb_samples; scalar_t__* data; } ;
struct TYPE_15__ {int size; int* data; } ;
struct TYPE_14__ {int /*<<< orphan*/  codec; } ;
typedef  TYPE_1__ LibCodec2Context ;
typedef  TYPE_2__ AVPacket ;
typedef  TYPE_3__ AVFrame ;
typedef  TYPE_4__ AVCodecContext ;

/* Variables and functions */
 int /*<<< orphan*/  codec2_decode (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int*) ; 
 int /*<<< orphan*/  codec2_encode (int /*<<< orphan*/ ,int*,int /*<<< orphan*/ *) ; 
 int ff_alloc_packet2 (TYPE_4__*,TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 int ff_get_buffer (TYPE_4__*,TYPE_3__*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void avpriv_codec2_make_extradata(uint8_t *ptr, int mode) {
    //version 0.8 as of 2017-12-23 (r3386)
    ptr[0] = 0;     //major
    ptr[1] = 8;     //minor
    ptr[2] = mode;  //mode
    ptr[3] = 0;     //flags
}

__attribute__((used)) static inline uint16_t avpriv_codec2_version_from_extradata(uint8_t *ptr) {
    return (ptr[0] << 8) + ptr[1];
}

__attribute__((used)) static inline uint8_t avpriv_codec2_mode_from_extradata(uint8_t *ptr) {
    return ptr[2];
}

__attribute__((used)) static int libcodec2_decode(AVCodecContext *avctx, void *data,
                            int *got_frame_ptr, AVPacket *pkt)
{
    LibCodec2Context *c2 = avctx->priv_data;
    AVFrame *frame = data;
    int ret, nframes, i;
    uint8_t *input;
    int16_t *output;

    nframes           = pkt->size / avctx->block_align;
    frame->nb_samples = avctx->frame_size * nframes;

    ret = ff_get_buffer(avctx, frame, 0);
    if (ret < 0) {
        return ret;
    }

    input  = pkt->data;
    output = (int16_t *)frame->data[0];

    for (i = 0; i < nframes; i++) {
        codec2_decode(c2->codec, output, input);
        input  += avctx->block_align;
        output += avctx->frame_size;
    }

    *got_frame_ptr = nframes > 0;
    return nframes * avctx->block_align;
}

__attribute__((used)) static int libcodec2_encode(AVCodecContext *avctx, AVPacket *avpkt,
                            const AVFrame *frame, int *got_packet_ptr)
{
    LibCodec2Context *c2 = avctx->priv_data;
    int16_t *samples = (int16_t *)frame->data[0];

    int ret = ff_alloc_packet2(avctx, avpkt, avctx->block_align, 0);
    if (ret < 0) {
        return ret;
    }

    codec2_encode(c2->codec, avpkt->data, samples);
    *got_packet_ptr = 1;

    return 0;
}

