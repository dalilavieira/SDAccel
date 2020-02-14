#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_8__ ;
typedef  struct TYPE_17__   TYPE_4__ ;
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
struct recorder {int format; TYPE_8__* ctx; int /*<<< orphan*/ * filename; } ;
typedef  enum recorder_format { ____Placeholder_recorder_format } recorder_format ;
struct TYPE_18__ {TYPE_2__** streams; int /*<<< orphan*/  pb; } ;
struct TYPE_17__ {int /*<<< orphan*/  name; } ;
struct TYPE_16__ {int size; int /*<<< orphan*/  data; } ;
struct TYPE_15__ {int /*<<< orphan*/  time_base; TYPE_1__* codec; } ;
struct TYPE_14__ {int extradata_size; int /*<<< orphan*/ * extradata; } ;
typedef  TYPE_2__ AVStream ;
typedef  TYPE_3__ AVPacket ;
typedef  TYPE_4__ AVOutputFormat ;

/* Variables and functions */
 int /*<<< orphan*/  LOGC (char*) ; 
 int /*<<< orphan*/  LOGE (char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  LOGI (char*,char const*,int /*<<< orphan*/ *) ; 
#define  RECORDER_FORMAT_MKV 129 
#define  RECORDER_FORMAT_MP4 128 
 int /*<<< orphan*/  SCRCPY_TIME_BASE ; 
 int /*<<< orphan*/  SDL_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * av_malloc (int) ; 
 TYPE_4__* av_oformat_next (TYPE_4__ const*) ; 
 int /*<<< orphan*/  av_packet_rescale_ts (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int av_write_trailer (TYPE_8__*) ; 
 int /*<<< orphan*/  avformat_free_context (TYPE_8__*) ; 
 int avformat_write_header (TYPE_8__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  avio_close (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  avio_closep (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,char const*) ; 

__attribute__((used)) static const AVOutputFormat *
find_muxer(const char *name) {
#ifdef SCRCPY_LAVF_HAS_NEW_MUXER_ITERATOR_API
    void *opaque = NULL;
#endif
    const AVOutputFormat *oformat = NULL;
    do {
#ifdef SCRCPY_LAVF_HAS_NEW_MUXER_ITERATOR_API
        oformat = av_muxer_iterate(&opaque);
#else
        oformat = av_oformat_next(oformat);
#endif
        // until null or with name "mp4"
    } while (oformat && strcmp(oformat->name, name));
    return oformat;
}

void
recorder_destroy(struct recorder *recorder) {
    SDL_free(recorder->filename);
}

__attribute__((used)) static const char *
recorder_get_format_name(enum recorder_format format) {
    switch (format) {
        case RECORDER_FORMAT_MP4: return "mp4";
        case RECORDER_FORMAT_MKV: return "matroska";
        default: return NULL;
    }
}

void
recorder_close(struct recorder *recorder) {
    int ret = av_write_trailer(recorder->ctx);
    if (ret < 0) {
        LOGE("Failed to write trailer to %s", recorder->filename);
    }
    avio_close(recorder->ctx->pb);
    avformat_free_context(recorder->ctx);

    const char *format_name = recorder_get_format_name(recorder->format);
    LOGI("Recording complete to %s file: %s", format_name, recorder->filename);
}

__attribute__((used)) static bool
recorder_write_header(struct recorder *recorder, const AVPacket *packet) {
    AVStream *ostream = recorder->ctx->streams[0];

    uint8_t *extradata = av_malloc(packet->size * sizeof(uint8_t));
    if (!extradata) {
        LOGC("Cannot allocate extradata");
        return false;
    }

    // copy the first packet to the extra data
    memcpy(extradata, packet->data, packet->size);

#ifdef SCRCPY_LAVF_HAS_NEW_CODEC_PARAMS_API
    ostream->codecpar->extradata = extradata;
    ostream->codecpar->extradata_size = packet->size;
#else
    ostream->codec->extradata = extradata;
    ostream->codec->extradata_size = packet->size;
#endif

    int ret = avformat_write_header(recorder->ctx, NULL);
    if (ret < 0) {
        LOGE("Failed to write header to %s", recorder->filename);
        SDL_free(extradata);
        avio_closep(&recorder->ctx->pb);
        avformat_free_context(recorder->ctx);
        return false;
    }

    return true;
}

__attribute__((used)) static void
recorder_rescale_packet(struct recorder *recorder, AVPacket *packet) {
    AVStream *ostream = recorder->ctx->streams[0];
    av_packet_rescale_ts(packet, SCRCPY_TIME_BASE, ostream->time_base);
}

