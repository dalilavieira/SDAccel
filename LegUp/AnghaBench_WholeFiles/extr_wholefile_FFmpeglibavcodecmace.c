#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_6__ ;
typedef  struct TYPE_19__   TYPE_5__ ;
typedef  struct TYPE_18__   TYPE_4__ ;
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int int16_t ;
struct TYPE_20__ {int stride; int* tab2; int* tab1; } ;
struct TYPE_19__ {scalar_t__ codec_id; int channels; TYPE_1__* priv_data; } ;
struct TYPE_18__ {int nb_samples; scalar_t__ extended_data; } ;
struct TYPE_17__ {int* data; int size; } ;
struct TYPE_16__ {int index; int level; int previous; int factor; int prev2; } ;
struct TYPE_15__ {TYPE_2__* chd; } ;
typedef  TYPE_1__ MACEContext ;
typedef  TYPE_2__ ChannelData ;
typedef  TYPE_3__ AVPacket ;
typedef  TYPE_4__ AVFrame ;
typedef  TYPE_5__ AVCodecContext ;

/* Variables and functions */
 int AVERROR_INVALIDDATA ; 
 scalar_t__ AV_CODEC_ID_MACE3 ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int FFMIN (int,int) ; 
 int QT_8S_2_16S (int) ; 
 int /*<<< orphan*/  av_log (TYPE_5__*,int /*<<< orphan*/ ,char*,int) ; 
 int ff_get_buffer (TYPE_5__*,TYPE_4__*,int /*<<< orphan*/ ) ; 
 TYPE_6__* tabs ; 

__attribute__((used)) static inline int16_t mace_broken_clip_int16(int n)
{
    if (n > 32767)
        return 32767;
    else if (n < -32768)
        return -32767;
    else
        return n;
}

__attribute__((used)) static int16_t read_table(ChannelData *chd, uint8_t val, int tab_idx)
{
    int16_t current;

    if (val < tabs[tab_idx].stride)
        current = tabs[tab_idx].tab2[((chd->index & 0x7f0) >> 4) * tabs[tab_idx].stride + val];
    else
        current = - 1 - tabs[tab_idx].tab2[((chd->index & 0x7f0) >> 4)*tabs[tab_idx].stride + 2*tabs[tab_idx].stride-val-1];

    if (( chd->index += tabs[tab_idx].tab1[val]-(chd->index >> 5) ) < 0)
      chd->index = 0;

    return current;
}

__attribute__((used)) static void chomp3(ChannelData *chd, int16_t *output, uint8_t val, int tab_idx)
{

    int16_t current = read_table(chd, val, tab_idx);

    current = mace_broken_clip_int16(current + chd->level);

    chd->level = current - (current >> 3);
    *output = QT_8S_2_16S(current);
}

__attribute__((used)) static void chomp6(ChannelData *chd, int16_t *output, uint8_t val, int tab_idx)
{
    int16_t current = read_table(chd, val, tab_idx);

    if ((chd->previous ^ current) >= 0) {
        chd->factor = FFMIN(chd->factor + 506, 32767);
    } else {
        if (chd->factor - 314 < -32768)
            chd->factor = -32767;
        else
            chd->factor -= 314;
    }

    current = mace_broken_clip_int16(current + chd->level);

    chd->level = (current*chd->factor) >> 15;
    current >>= 1;

    output[0] = QT_8S_2_16S(chd->previous + chd->prev2 -
                            ((chd->prev2-current) >> 2));
    output[1] = QT_8S_2_16S(chd->previous + current +
                            ((chd->prev2-current) >> 2));
    chd->prev2 = chd->previous;
    chd->previous = current;
}

__attribute__((used)) static int mace_decode_frame(AVCodecContext *avctx, void *data,
                             int *got_frame_ptr, AVPacket *avpkt)
{
    AVFrame *frame     = data;
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    int16_t **samples;
    MACEContext *ctx = avctx->priv_data;
    int i, j, k, l, ret;
    int is_mace3 = (avctx->codec_id == AV_CODEC_ID_MACE3);

    if (buf_size % (avctx->channels << is_mace3)) {
        av_log(avctx, AV_LOG_ERROR, "buffer size %d is odd\n", buf_size);
        buf_size -= buf_size % (avctx->channels << is_mace3);
        if (!buf_size)
            return AVERROR_INVALIDDATA;
    }

    /* get output buffer */
    frame->nb_samples = 3 * (buf_size << (1 - is_mace3)) / avctx->channels;
    if ((ret = ff_get_buffer(avctx, frame, 0)) < 0)
        return ret;
    samples = (int16_t **)frame->extended_data;

    for(i = 0; i < avctx->channels; i++) {
        int16_t *output = samples[i];

        for (j=0; j < buf_size / (avctx->channels << is_mace3); j++)
            for (k=0; k < (1 << is_mace3); k++) {
                uint8_t pkt = buf[(i << is_mace3) +
                                  (j*avctx->channels << is_mace3) + k];

                uint8_t val[2][3] = {{pkt >> 5, (pkt >> 3) & 3, pkt & 7 },
                                     {pkt & 7 , (pkt >> 3) & 3, pkt >> 5}};

                for (l=0; l < 3; l++) {
                    if (is_mace3)
                        chomp3(&ctx->chd[i], output, val[1][l], l);
                    else
                        chomp6(&ctx->chd[i], output, val[0][l], l);

                    output += 1 << (1-is_mace3);
                }
            }
    }

    *got_frame_ptr = 1;

    return buf_size;
}

