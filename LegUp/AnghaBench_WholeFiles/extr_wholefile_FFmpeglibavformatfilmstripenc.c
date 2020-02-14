#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_6__ ;
typedef  struct TYPE_16__   TYPE_5__ ;
typedef  struct TYPE_15__   TYPE_4__ ;
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
struct TYPE_17__ {TYPE_4__** streams; int /*<<< orphan*/ * pb; TYPE_3__* priv_data; } ;
struct TYPE_16__ {int /*<<< orphan*/  size; int /*<<< orphan*/  data; } ;
struct TYPE_13__ {int den; int num; } ;
struct TYPE_15__ {TYPE_2__ time_base; TYPE_1__* codecpar; } ;
struct TYPE_14__ {int /*<<< orphan*/  nb_frames; } ;
struct TYPE_12__ {scalar_t__ format; int width; int height; } ;
typedef  TYPE_3__ FilmstripMuxContext ;
typedef  TYPE_4__ AVStream ;
typedef  TYPE_5__ AVPacket ;
typedef  int /*<<< orphan*/  AVIOContext ;
typedef  TYPE_6__ AVFormatContext ;

/* Variables and functions */
 int AVERROR_INVALIDDATA ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 scalar_t__ AV_PIX_FMT_RGBA ; 
 int /*<<< orphan*/  RAND_TAG ; 
 int /*<<< orphan*/  av_log (TYPE_6__*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  avio_w8 (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  avio_wb16 (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  avio_wb32 (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  avio_write (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int write_header(AVFormatContext *s)
{
    if (s->streams[0]->codecpar->format != AV_PIX_FMT_RGBA) {
        av_log(s, AV_LOG_ERROR, "only AV_PIX_FMT_RGBA is supported\n");
        return AVERROR_INVALIDDATA;
    }
    return 0;
}

__attribute__((used)) static int write_packet(AVFormatContext *s, AVPacket *pkt)
{
    FilmstripMuxContext *film = s->priv_data;
    avio_write(s->pb, pkt->data, pkt->size);
    film->nb_frames++;
    return 0;
}

__attribute__((used)) static int write_trailer(AVFormatContext *s)
{
    FilmstripMuxContext *film = s->priv_data;
    AVIOContext *pb = s->pb;
    AVStream *st = s->streams[0];
    int i;

    avio_wb32(pb, RAND_TAG);
    avio_wb32(pb, film->nb_frames);
    avio_wb16(pb, 0);  // packing method
    avio_wb16(pb, 0);  // reserved
    avio_wb16(pb, st->codecpar->width);
    avio_wb16(pb, st->codecpar->height);
    avio_wb16(pb, 0);  // leading
    // TODO: should be avg_frame_rate
    avio_wb16(pb, st->time_base.den / st->time_base.num);
    for (i = 0; i < 16; i++)
        avio_w8(pb, 0x00);  // reserved

    return 0;
}

