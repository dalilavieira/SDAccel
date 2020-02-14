#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_23__   TYPE_8__ ;
typedef  struct TYPE_22__   TYPE_7__ ;
typedef  struct TYPE_21__   TYPE_6__ ;
typedef  struct TYPE_20__   TYPE_5__ ;
typedef  struct TYPE_19__   TYPE_4__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
struct TYPE_23__ {scalar_t__ format; int /*<<< orphan*/  height; int /*<<< orphan*/  width; } ;
struct TYPE_22__ {int /*<<< orphan*/ * pb; TYPE_2__** streams; TYPE_3__* priv_data; } ;
struct TYPE_21__ {int size; scalar_t__ stream_index; scalar_t__* data; } ;
struct TYPE_20__ {int buf_size; float* buf; } ;
struct TYPE_19__ {TYPE_1__* codecpar; } ;
struct TYPE_18__ {scalar_t__ count; } ;
struct TYPE_17__ {TYPE_8__* codecpar; } ;
struct TYPE_16__ {void* height; void* width; scalar_t__ codec_tag; int /*<<< orphan*/  format; int /*<<< orphan*/  codec_id; int /*<<< orphan*/  codec_type; } ;
typedef  TYPE_3__ FrmContext ;
typedef  TYPE_4__ AVStream ;
typedef  TYPE_5__ AVProbeData ;
typedef  TYPE_6__ AVPacket ;
typedef  int /*<<< orphan*/  AVIOContext ;
typedef  TYPE_7__ AVFormatContext ;
typedef  TYPE_8__ AVCodecParameters ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_EOF ; 
 int AVERROR_INVALIDDATA ; 
 int /*<<< orphan*/  AVMEDIA_TYPE_VIDEO ; 
 int AVPROBE_SCORE_MAX ; 
 int /*<<< orphan*/  AV_CODEC_ID_RAWVIDEO ; 
 scalar_t__ AV_PIX_FMT_BGRA ; 
 scalar_t__ AV_RL16 (char*) ; 
 int /*<<< orphan*/  ENOMEM ; 
 int av_get_packet (int /*<<< orphan*/ *,TYPE_6__*,int) ; 
 int av_image_get_buffer_size (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 TYPE_4__* avformat_new_stream (TYPE_7__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  avio_r8 (int /*<<< orphan*/ *) ; 
 void* avio_rl16 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  avio_skip (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  avpriv_find_pix_fmt (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  frm_pix_fmt_tags ; 

__attribute__((used)) static int frm_read_probe(const AVProbeData *p)
{
    if (p->buf_size > 8 &&
        p->buf[0] == 'F' && p->buf[1] == 'R' && p->buf[2] == 'M' &&
        AV_RL16(&p->buf[4]) && AV_RL16(&p->buf[6]))
        return AVPROBE_SCORE_MAX / 4;
    return 0;
}

__attribute__((used)) static int frm_read_header(AVFormatContext *avctx)
{
    AVIOContext *pb = avctx->pb;
    AVStream *st = avformat_new_stream(avctx, 0);
    if (!st)
        return AVERROR(ENOMEM);

    st->codecpar->codec_type = AVMEDIA_TYPE_VIDEO;
    st->codecpar->codec_id   = AV_CODEC_ID_RAWVIDEO;
    avio_skip(pb, 3);

    st->codecpar->format    = avpriv_find_pix_fmt(frm_pix_fmt_tags, avio_r8(pb));
    if (!st->codecpar->format)
        return AVERROR_INVALIDDATA;

    st->codecpar->codec_tag  = 0;
    st->codecpar->width      = avio_rl16(pb);
    st->codecpar->height     = avio_rl16(pb);
    return 0;
}

__attribute__((used)) static int frm_read_packet(AVFormatContext *avctx, AVPacket *pkt)
{
    FrmContext *s = avctx->priv_data;
    AVCodecParameters *par = avctx->streams[0]->codecpar;
    int packet_size, ret;

    if (s->count)
        return AVERROR_EOF;

    packet_size = av_image_get_buffer_size(par->format, par->width, par->height, 1);
    if (packet_size < 0)
        return AVERROR_INVALIDDATA;

    ret = av_get_packet(avctx->pb, pkt, packet_size);
    if (ret < 0)
        return ret;

    if (par->format == AV_PIX_FMT_BGRA) {
        int i;
        for (i = 3; i + 1 <= pkt->size; i += 4)
            pkt->data[i] = 0xFF - pkt->data[i];
    }

    pkt->stream_index = 0;
    s->count++;

    return 0;
}

