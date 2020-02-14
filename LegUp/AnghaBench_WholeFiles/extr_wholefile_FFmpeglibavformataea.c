#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_22__   TYPE_7__ ;
typedef  struct TYPE_21__   TYPE_6__ ;
typedef  struct TYPE_20__   TYPE_5__ ;
typedef  struct TYPE_19__   TYPE_4__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
struct TYPE_22__ {TYPE_3__** streams; int /*<<< orphan*/  pb; } ;
struct TYPE_21__ {scalar_t__ stream_index; } ;
struct TYPE_20__ {int buf_size; int* buf; } ;
struct TYPE_19__ {TYPE_1__* codecpar; } ;
struct TYPE_18__ {TYPE_2__* codecpar; } ;
struct TYPE_17__ {int /*<<< orphan*/  block_align; } ;
struct TYPE_16__ {int channels; int sample_rate; int bit_rate; int block_align; int /*<<< orphan*/  channel_layout; int /*<<< orphan*/  codec_id; int /*<<< orphan*/  codec_type; } ;
typedef  TYPE_4__ AVStream ;
typedef  TYPE_5__ AVProbeData ;
typedef  TYPE_6__ AVPacket ;
typedef  TYPE_7__ AVFormatContext ;

/* Variables and functions */
 int AT1_SU_SIZE ; 
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_INVALIDDATA ; 
 int /*<<< orphan*/  AVMEDIA_TYPE_AUDIO ; 
 int AVPROBE_SCORE_MAX ; 
 int /*<<< orphan*/  AV_CH_LAYOUT_MONO ; 
 int /*<<< orphan*/  AV_CH_LAYOUT_STEREO ; 
 int /*<<< orphan*/  AV_CODEC_ID_ATRAC1 ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int AV_RL32 (int*) ; 
 int /*<<< orphan*/  EIO ; 
 int /*<<< orphan*/  ENOMEM ; 
 int av_get_packet (int /*<<< orphan*/ ,TYPE_6__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  av_log (TYPE_7__*,int /*<<< orphan*/ ,char*,int) ; 
 TYPE_4__* avformat_new_stream (TYPE_7__*,int /*<<< orphan*/ *) ; 
 int avio_r8 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  avio_skip (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int aea_read_probe(const AVProbeData *p)
{
    if (p->buf_size <= 2048+212)
        return 0;

    /* Magic is '00 08 00 00' in little-endian*/
    if (AV_RL32(p->buf)==0x800) {
        int ch, i;
        ch = p->buf[264];

        if (ch != 1 && ch != 2)
            return 0;

        /* Check so that the redundant bsm bytes and info bytes are valid
         * the block size mode bytes have to be the same
         * the info bytes have to be the same
         */
        for (i = 2048; i + 211 < p->buf_size; i+= 212) {
            int bsm_s, bsm_e, inb_s, inb_e;
            bsm_s = p->buf[0];
            inb_s = p->buf[1];
            inb_e = p->buf[210];
            bsm_e = p->buf[211];

            if (bsm_s != bsm_e || inb_s != inb_e)
                return 0;
        }
        return AVPROBE_SCORE_MAX / 4 + 1;
    }
    return 0;
}

__attribute__((used)) static int aea_read_header(AVFormatContext *s)
{
    AVStream *st = avformat_new_stream(s, NULL);
    if (!st)
        return AVERROR(ENOMEM);

    /* Parse the amount of channels and skip to pos 2048(0x800) */
    avio_skip(s->pb, 264);
    st->codecpar->channels = avio_r8(s->pb);
    avio_skip(s->pb, 1783);


    st->codecpar->codec_type     = AVMEDIA_TYPE_AUDIO;
    st->codecpar->codec_id       = AV_CODEC_ID_ATRAC1;
    st->codecpar->sample_rate    = 44100;
    st->codecpar->bit_rate       = 292000;

    if (st->codecpar->channels != 1 && st->codecpar->channels != 2) {
        av_log(s, AV_LOG_ERROR, "Channels %d not supported!\n", st->codecpar->channels);
        return AVERROR_INVALIDDATA;
    }

    st->codecpar->channel_layout = (st->codecpar->channels == 1) ? AV_CH_LAYOUT_MONO : AV_CH_LAYOUT_STEREO;

    st->codecpar->block_align = AT1_SU_SIZE * st->codecpar->channels;
    return 0;
}

__attribute__((used)) static int aea_read_packet(AVFormatContext *s, AVPacket *pkt)
{
    int ret = av_get_packet(s->pb, pkt, s->streams[0]->codecpar->block_align);

    pkt->stream_index = 0;
    if (ret <= 0)
        return AVERROR(EIO);

    return ret;
}

