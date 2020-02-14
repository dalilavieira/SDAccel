#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_22__   TYPE_6__ ;
typedef  struct TYPE_21__   TYPE_5__ ;
typedef  struct TYPE_20__   TYPE_4__ ;
typedef  struct TYPE_19__   TYPE_3__ ;
typedef  struct TYPE_18__   TYPE_2__ ;
typedef  struct TYPE_17__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint64_t ;
typedef  int /*<<< orphan*/  caddr_t ;
struct TYPE_18__ {scalar_t__ per_frame; int framerate; int standard; int /*<<< orphan*/  tuner_fd; int /*<<< orphan*/  video_fd; int /*<<< orphan*/  height; int /*<<< orphan*/  width; } ;
typedef  TYPE_2__ VideoData ;
struct TYPE_22__ {TYPE_2__* priv_data; int /*<<< orphan*/  url; } ;
struct TYPE_21__ {int /*<<< orphan*/  data; scalar_t__ pts; } ;
struct TYPE_20__ {scalar_t__ den; scalar_t__ num; } ;
struct TYPE_19__ {TYPE_4__ avg_frame_rate; TYPE_1__* codecpar; } ;
struct TYPE_17__ {int /*<<< orphan*/  height; int /*<<< orphan*/  width; int /*<<< orphan*/  codec_id; int /*<<< orphan*/  format; int /*<<< orphan*/  codec_type; } ;
typedef  TYPE_3__ AVStream ;
typedef  TYPE_4__ AVRational ;
typedef  TYPE_5__ AVPacket ;
typedef  TYPE_6__ AVFormatContext ;

/* Variables and functions */
 int AUDIO_MUTE ; 
 int AVERROR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AVMEDIA_TYPE_VIDEO ; 
 int /*<<< orphan*/  AV_CODEC_ID_RAWVIDEO ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_LOG_INFO ; 
 int /*<<< orphan*/  AV_PIX_FMT_YUV420P ; 
 int /*<<< orphan*/  BT848_SAUDIO ; 
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  EIO ; 
 int /*<<< orphan*/  ENOMEM ; 
 int /*<<< orphan*/  METEORCAPTUR ; 
 int METEOR_CAP_STOP_CONT ; 
#define  NTSC 130 
#define  PAL 129 
#define  SECAM 128 
 scalar_t__ av_gettime () ; 
 int /*<<< orphan*/  av_log (TYPE_6__*,int /*<<< orphan*/ ,char*,...) ; 
 scalar_t__ av_new_packet (TYPE_5__*,int) ; 
 int av_parse_video_rate (TYPE_4__*,int) ; 
 void* av_strdup (char*) ; 
 TYPE_3__* avformat_new_stream (TYPE_6__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  avpriv_set_pts_info (TYPE_3__*,int,int,int) ; 
 scalar_t__ bktr_init (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,double) ; 
 int /*<<< orphan*/  close (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ioctl (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 scalar_t__ last_frame_time ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,scalar_t__,int) ; 
 int /*<<< orphan*/  munmap (int /*<<< orphan*/ ,int) ; 
 scalar_t__ nsignals ; 
 int /*<<< orphan*/  usleep (scalar_t__) ; 
 scalar_t__ video_buf ; 
 int video_buf_size ; 

__attribute__((used)) static void catchsignal(int signal)
{
    nsignals++;
    return;
}

__attribute__((used)) static void bktr_getframe(uint64_t per_frame)
{
    uint64_t curtime;

    curtime = av_gettime();
    if (!last_frame_time
        || ((last_frame_time + per_frame) > curtime)) {
        if (!usleep(last_frame_time + per_frame + per_frame / 8 - curtime)) {
            if (!nsignals)
                av_log(NULL, AV_LOG_INFO,
                       "SLEPT NO signals - %d microseconds late\n",
                       (int)(av_gettime() - last_frame_time - per_frame));
        }
    }
    nsignals = 0;
    last_frame_time = curtime;
}

__attribute__((used)) static int grab_read_packet(AVFormatContext *s1, AVPacket *pkt)
{
    VideoData *s = s1->priv_data;

    if (av_new_packet(pkt, video_buf_size) < 0)
        return AVERROR(EIO);

    bktr_getframe(s->per_frame);

    pkt->pts = av_gettime();
    memcpy(pkt->data, video_buf, video_buf_size);

    return video_buf_size;
}

__attribute__((used)) static int grab_read_header(AVFormatContext *s1)
{
    VideoData *s = s1->priv_data;
    AVStream *st;
    AVRational framerate;
    int ret = 0;

    if (!s->framerate)
        switch (s->standard) {
        case PAL:   s->framerate = av_strdup("pal");  break;
        case NTSC:  s->framerate = av_strdup("ntsc"); break;
        case SECAM: s->framerate = av_strdup("25");   break;
        default:
            av_log(s1, AV_LOG_ERROR, "Unknown standard.\n");
            ret = AVERROR(EINVAL);
            goto out;
        }
    if ((ret = av_parse_video_rate(&framerate, s->framerate)) < 0) {
        av_log(s1, AV_LOG_ERROR, "Could not parse framerate '%s'.\n", s->framerate);
        goto out;
    }

    st = avformat_new_stream(s1, NULL);
    if (!st) {
        ret = AVERROR(ENOMEM);
        goto out;
    }
    avpriv_set_pts_info(st, 64, 1, 1000000); /* 64 bits pts in use */

    s->per_frame = ((uint64_t)1000000 * framerate.den) / framerate.num;

    st->codecpar->codec_type = AVMEDIA_TYPE_VIDEO;
    st->codecpar->format = AV_PIX_FMT_YUV420P;
    st->codecpar->codec_id = AV_CODEC_ID_RAWVIDEO;
    st->codecpar->width = s->width;
    st->codecpar->height = s->height;
    st->avg_frame_rate = framerate;

    if (bktr_init(s1->url, s->width, s->height, s->standard,
                  &s->video_fd, &s->tuner_fd, -1, 0.0) < 0) {
        ret = AVERROR(EIO);
        goto out;
    }

    nsignals = 0;
    last_frame_time = 0;

out:
    return ret;
}

__attribute__((used)) static int grab_read_close(AVFormatContext *s1)
{
    VideoData *s = s1->priv_data;
    int c;

    c = METEOR_CAP_STOP_CONT;
    ioctl(s->video_fd, METEORCAPTUR, &c);
    close(s->video_fd);

    c = AUDIO_MUTE;
    ioctl(s->tuner_fd, BT848_SAUDIO, &c);
    close(s->tuner_fd);

    munmap((caddr_t)video_buf, video_buf_size);

    return 0;
}

