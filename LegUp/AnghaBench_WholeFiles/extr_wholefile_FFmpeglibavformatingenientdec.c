#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_11__ {int /*<<< orphan*/  pb; } ;
struct TYPE_10__ {scalar_t__ stream_index; } ;
struct TYPE_9__ {char* buf; int buf_size; } ;
typedef  TYPE_1__ AVProbeData ;
typedef  TYPE_2__ AVPacket ;
typedef  TYPE_3__ AVFormatContext ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVPROBE_SCORE_MAX ; 
 int /*<<< orphan*/  AV_LOG_DEBUG ; 
 int AV_RB16 (char*) ; 
 scalar_t__ AV_RN32 (char*) ; 
 int /*<<< orphan*/  EIO ; 
 int MKTAG (char,char,char,char) ; 
 int av_get_packet (int /*<<< orphan*/ ,TYPE_2__*,int) ; 
 int /*<<< orphan*/  av_log (TYPE_3__*,int /*<<< orphan*/ ,char*,int,int,int,int,int) ; 
 int avio_rl16 (int /*<<< orphan*/ ) ; 
 int avio_rl32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  avio_skip (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int ingenient_probe(const AVProbeData *p)
{
    if (   AV_RN32(p->buf) != AV_RN32("MJPG")
        || p->buf_size < 50
        || AV_RB16(p->buf + 48) != 0xffd8)
        return 0;
    return AVPROBE_SCORE_MAX * 3 / 4;
}

__attribute__((used)) static int ingenient_read_packet(AVFormatContext *s, AVPacket *pkt)
{
    int ret, size, w, h, unk1, unk2;

    if (avio_rl32(s->pb) != MKTAG('M', 'J', 'P', 'G'))
        return AVERROR(EIO); // FIXME

    size = avio_rl32(s->pb);

    w = avio_rl16(s->pb);
    h = avio_rl16(s->pb);

    avio_skip(s->pb, 8); // zero + size (padded?)
    avio_skip(s->pb, 2);
    unk1 = avio_rl16(s->pb);
    unk2 = avio_rl16(s->pb);
    avio_skip(s->pb, 22); // ASCII timestamp

    av_log(s, AV_LOG_DEBUG, "Ingenient packet: size=%d, width=%d, height=%d, unk1=%d unk2=%d\n",
        size, w, h, unk1, unk2);

    ret = av_get_packet(s->pb, pkt, size);
    if (ret < 0)
        return ret;
    pkt->stream_index = 0;
    return ret;
}

