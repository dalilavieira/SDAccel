#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_4__ ;
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
struct TYPE_16__ {int /*<<< orphan*/  pb; TYPE_2__* priv_data; } ;
struct TYPE_15__ {TYPE_1__* codecpar; scalar_t__ start_time; } ;
struct TYPE_14__ {int /*<<< orphan*/  sample_rate; } ;
struct TYPE_13__ {int channels; int bits_per_coded_sample; void* frame_size; int /*<<< orphan*/  block_align; int /*<<< orphan*/  codec_id; int /*<<< orphan*/  sample_rate; int /*<<< orphan*/  format; int /*<<< orphan*/  codec_type; } ;
typedef  TYPE_2__ AptXDemuxerContext ;
typedef  TYPE_3__ AVStream ;
typedef  int /*<<< orphan*/  AVPacket ;
typedef  TYPE_4__ AVFormatContext ;

/* Variables and functions */
 int /*<<< orphan*/  APTX_BLOCK_SIZE ; 
 int /*<<< orphan*/  APTX_HD_BLOCK_SIZE ; 
 void* APTX_HD_PACKET_SIZE ; 
 void* APTX_PACKET_SIZE ; 
 int AVERROR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AVMEDIA_TYPE_AUDIO ; 
 int /*<<< orphan*/  AV_CODEC_ID_APTX ; 
 int /*<<< orphan*/  AV_CODEC_ID_APTX_HD ; 
 int /*<<< orphan*/  AV_SAMPLE_FMT_S32P ; 
 int /*<<< orphan*/  ENOMEM ; 
 int av_get_packet (int /*<<< orphan*/ ,int /*<<< orphan*/ *,void*) ; 
 TYPE_3__* avformat_new_stream (TYPE_4__*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static AVStream *aptx_read_header_common(AVFormatContext *s)
{
    AptXDemuxerContext *s1 = s->priv_data;
    AVStream *st = avformat_new_stream(s, NULL);
    if (!st)
        return NULL;
    st->codecpar->codec_type = AVMEDIA_TYPE_AUDIO;
    st->codecpar->format = AV_SAMPLE_FMT_S32P;
    st->codecpar->channels = 2;
    st->codecpar->sample_rate = s1->sample_rate;
    st->start_time = 0;
    return st;
}

__attribute__((used)) static int aptx_read_header(AVFormatContext *s)
{
    AVStream *st = aptx_read_header_common(s);
    if (!st)
        return AVERROR(ENOMEM);
    st->codecpar->codec_id = AV_CODEC_ID_APTX;
    st->codecpar->bits_per_coded_sample = 4;
    st->codecpar->block_align = APTX_BLOCK_SIZE;
    st->codecpar->frame_size = APTX_PACKET_SIZE;
    return 0;
}

__attribute__((used)) static int aptx_hd_read_header(AVFormatContext *s)
{
    AVStream *st = aptx_read_header_common(s);
    if (!st)
        return AVERROR(ENOMEM);
    st->codecpar->codec_id = AV_CODEC_ID_APTX_HD;
    st->codecpar->bits_per_coded_sample = 6;
    st->codecpar->block_align = APTX_HD_BLOCK_SIZE;
    st->codecpar->frame_size = APTX_HD_PACKET_SIZE;
    return 0;
}

__attribute__((used)) static int aptx_read_packet(AVFormatContext *s, AVPacket *pkt)
{
    return av_get_packet(s->pb, pkt, APTX_PACKET_SIZE);
}

__attribute__((used)) static int aptx_hd_read_packet(AVFormatContext *s, AVPacket *pkt)
{
    return av_get_packet(s->pb, pkt, APTX_HD_PACKET_SIZE);
}

