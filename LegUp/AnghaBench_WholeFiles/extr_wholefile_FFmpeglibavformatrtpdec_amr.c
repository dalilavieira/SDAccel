#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_26__   TYPE_5__ ;
typedef  struct TYPE_25__   TYPE_4__ ;
typedef  struct TYPE_24__   TYPE_3__ ;
typedef  struct TYPE_23__   TYPE_2__ ;
typedef  struct TYPE_22__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  uint16_t ;
struct TYPE_26__ {int /*<<< orphan*/ * streams; } ;
struct TYPE_25__ {int* data; int size; int /*<<< orphan*/  stream_index; } ;
struct TYPE_24__ {int /*<<< orphan*/  index; TYPE_1__* codecpar; } ;
struct TYPE_23__ {int channels; void* interleaving; void* crc; void* octet_align; } ;
struct TYPE_22__ {scalar_t__ codec_id; int channels; int /*<<< orphan*/  channel_layout; } ;
typedef  TYPE_2__ PayloadContext ;
typedef  TYPE_3__ AVStream ;
typedef  TYPE_4__ AVPacket ;
typedef  TYPE_5__ AVFormatContext ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_INVALIDDATA ; 
 int /*<<< orphan*/  AV_CH_LAYOUT_MONO ; 
 scalar_t__ AV_CODEC_ID_AMR_NB ; 
 scalar_t__ AV_CODEC_ID_AMR_WB ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_LOG_WARNING ; 
 int /*<<< orphan*/  ENOMEM ; 
 void* atoi (char const*) ; 
 int /*<<< orphan*/  av_log (TYPE_5__*,int /*<<< orphan*/ ,char*,...) ; 
 scalar_t__ av_new_packet (TYPE_4__*,int) ; 
 scalar_t__ av_strstart (char const*,char*,char const**) ; 
 int ff_parse_fmtp (TYPE_5__*,int /*<<< orphan*/ ,TYPE_2__*,char const*,int (*) (TYPE_5__*,TYPE_3__*,TYPE_2__*,char const*,char const*)) ; 
 int* frame_sizes_nb ; 
 int* frame_sizes_wb ; 
 int /*<<< orphan*/  memcpy (int*,int const*,int) ; 
 int /*<<< orphan*/  memset (int*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 

__attribute__((used)) static int amr_handle_packet(AVFormatContext *ctx, PayloadContext *data,
                             AVStream *st, AVPacket *pkt, uint32_t *timestamp,
                             const uint8_t *buf, int len, uint16_t seq,
                             int flags)
{
    const uint8_t *frame_sizes = NULL;
    int frames;
    int i;
    const uint8_t *speech_data;
    uint8_t *ptr;

    if (st->codecpar->codec_id == AV_CODEC_ID_AMR_NB) {
        frame_sizes = frame_sizes_nb;
    } else if (st->codecpar->codec_id == AV_CODEC_ID_AMR_WB) {
        frame_sizes = frame_sizes_wb;
    } else {
        av_log(ctx, AV_LOG_ERROR, "Bad codec ID\n");
        return AVERROR_INVALIDDATA;
    }

    if (st->codecpar->channels != 1) {
        av_log(ctx, AV_LOG_ERROR, "Only mono AMR is supported\n");
        return AVERROR_INVALIDDATA;
    }
    st->codecpar->channel_layout = AV_CH_LAYOUT_MONO;

    /* The AMR RTP packet consists of one header byte, followed
     * by one TOC byte for each AMR frame in the packet, followed
     * by the speech data for all the AMR frames.
     *
     * The header byte contains only a codec mode request, for
     * requesting what kind of AMR data the sender wants to
     * receive. Not used at the moment.
     */

    /* Count the number of frames in the packet. The highest bit
     * is set in a TOC byte if there are more frames following.
     */
    for (frames = 1; frames < len && (buf[frames] & 0x80); frames++) ;

    if (1 + frames >= len) {
        /* We hit the end of the packet while counting frames. */
        av_log(ctx, AV_LOG_ERROR, "No speech data found\n");
        return AVERROR_INVALIDDATA;
    }

    speech_data = buf + 1 + frames;

    /* Everything except the codec mode request byte should be output. */
    if (av_new_packet(pkt, len - 1)) {
        av_log(ctx, AV_LOG_ERROR, "Out of memory\n");
        return AVERROR(ENOMEM);
    }
    pkt->stream_index = st->index;
    ptr = pkt->data;

    for (i = 0; i < frames; i++) {
        uint8_t toc = buf[1 + i];
        int frame_size = frame_sizes[(toc >> 3) & 0x0f];

        if (speech_data + frame_size > buf + len) {
            /* Too little speech data */
            av_log(ctx, AV_LOG_WARNING, "Too little speech data in the RTP packet\n");
            /* Set the unwritten part of the packet to zero. */
            memset(ptr, 0, pkt->data + pkt->size - ptr);
            pkt->size = ptr - pkt->data;
            return 0;
        }

        /* Extract the AMR frame mode from the TOC byte */
        *ptr++ = toc & 0x7C;

        /* Copy the speech data */
        memcpy(ptr, speech_data, frame_size);
        speech_data += frame_size;
        ptr += frame_size;
    }

    if (speech_data < buf + len) {
        av_log(ctx, AV_LOG_WARNING, "Too much speech data in the RTP packet?\n");
        /* Set the unwritten part of the packet to zero. */
        memset(ptr, 0, pkt->data + pkt->size - ptr);
        pkt->size = ptr - pkt->data;
    }

    return 0;
}

__attribute__((used)) static int amr_parse_fmtp(AVFormatContext *s,
                          AVStream *stream, PayloadContext *data,
                          const char *attr, const char *value)
{
    /* Some AMR SDP configurations contain "octet-align", without
     * the trailing =1. Therefore, if the value is empty,
     * interpret it as "1".
     */
    if (!strcmp(value, "")) {
        av_log(s, AV_LOG_WARNING, "AMR fmtp attribute %s had "
                                  "nonstandard empty value\n", attr);
        value = "1";
    }
    if (!strcmp(attr, "octet-align"))
        data->octet_align = atoi(value);
    else if (!strcmp(attr, "crc"))
        data->crc = atoi(value);
    else if (!strcmp(attr, "interleaving"))
        data->interleaving = atoi(value);
    else if (!strcmp(attr, "channels"))
        data->channels = atoi(value);
    return 0;
}

__attribute__((used)) static int amr_parse_sdp_line(AVFormatContext *s, int st_index,
                              PayloadContext *data, const char *line)
{
    const char *p;
    int ret;

    if (st_index < 0)
        return 0;

    /* Parse an fmtp line this one:
     * a=fmtp:97 octet-align=1; interleaving=0
     * That is, a normal fmtp: line followed by semicolon & space
     * separated key/value pairs.
     */
    if (av_strstart(line, "fmtp:", &p)) {
        ret = ff_parse_fmtp(s, s->streams[st_index], data, p, amr_parse_fmtp);
        if (!data->octet_align || data->crc ||
            data->interleaving || data->channels != 1) {
            av_log(s, AV_LOG_ERROR, "Unsupported RTP/AMR configuration!\n");
            return -1;
        }
        return ret;
    }
    return 0;
}

