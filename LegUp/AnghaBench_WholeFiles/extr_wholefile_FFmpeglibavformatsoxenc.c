#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_26__   TYPE_6__ ;
typedef  struct TYPE_25__   TYPE_5__ ;
typedef  struct TYPE_24__   TYPE_4__ ;
typedef  struct TYPE_23__   TYPE_3__ ;
typedef  struct TYPE_22__   TYPE_2__ ;
typedef  struct TYPE_21__   TYPE_1__ ;

/* Type definitions */
typedef  int int64_t ;
struct TYPE_26__ {scalar_t__ codec_id; size_t channels; int /*<<< orphan*/  sample_rate; } ;
struct TYPE_25__ {int /*<<< orphan*/  value; } ;
struct TYPE_24__ {TYPE_3__* pb; TYPE_1__** streams; TYPE_2__* priv_data; int /*<<< orphan*/  metadata; } ;
struct TYPE_23__ {int seekable; } ;
struct TYPE_22__ {size_t header_size; } ;
struct TYPE_21__ {TYPE_6__* codecpar; } ;
typedef  TYPE_2__ SoXContext ;
typedef  TYPE_3__ AVIOContext ;
typedef  TYPE_4__ AVFormatContext ;
typedef  TYPE_5__ AVDictionaryEntry ;
typedef  TYPE_6__ AVCodecParameters ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVIO_SEEKABLE_NORMAL ; 
 scalar_t__ AV_CODEC_ID_PCM_S32BE ; 
 scalar_t__ AV_CODEC_ID_PCM_S32LE ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  EINVAL ; 
 size_t FFALIGN (size_t,int) ; 
 int /*<<< orphan*/  SEEK_SET ; 
 size_t SOX_FIXED_HDR ; 
 TYPE_5__* av_dict_get (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int av_double2int (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  av_log (TYPE_4__*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  avio_flush (TYPE_3__*) ; 
 int /*<<< orphan*/  avio_seek (TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 int avio_tell (TYPE_3__*) ; 
 int /*<<< orphan*/  avio_wb32 (TYPE_3__*,size_t) ; 
 int /*<<< orphan*/  avio_wb64 (TYPE_3__*,int) ; 
 int /*<<< orphan*/  avio_wl32 (TYPE_3__*,size_t) ; 
 int /*<<< orphan*/  avio_wl64 (TYPE_3__*,int) ; 
 int /*<<< orphan*/  avio_write (TYPE_3__*,int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  ffio_fill (TYPE_3__*,int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  ffio_wfourcc (TYPE_3__*,char*) ; 
 size_t strlen (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int sox_write_header(AVFormatContext *s)
{
    SoXContext *sox = s->priv_data;
    AVIOContext *pb = s->pb;
    AVCodecParameters *par = s->streams[0]->codecpar;
    AVDictionaryEntry *comment;
    size_t comment_len = 0, comment_size;

    comment = av_dict_get(s->metadata, "comment", NULL, 0);
    if (comment)
        comment_len = strlen(comment->value);
    comment_size = FFALIGN(comment_len, 8);

    sox->header_size = SOX_FIXED_HDR + comment_size;

    if (par->codec_id == AV_CODEC_ID_PCM_S32LE) {
        ffio_wfourcc(pb, ".SoX");
        avio_wl32(pb, sox->header_size);
        avio_wl64(pb, 0); /* number of samples */
        avio_wl64(pb, av_double2int(par->sample_rate));
        avio_wl32(pb, par->channels);
        avio_wl32(pb, comment_size);
    } else if (par->codec_id == AV_CODEC_ID_PCM_S32BE) {
        ffio_wfourcc(pb, "XoS.");
        avio_wb32(pb, sox->header_size);
        avio_wb64(pb, 0); /* number of samples */
        avio_wb64(pb, av_double2int(par->sample_rate));
        avio_wb32(pb, par->channels);
        avio_wb32(pb, comment_size);
    } else {
        av_log(s, AV_LOG_ERROR, "invalid codec; use pcm_s32le or pcm_s32be\n");
        return AVERROR(EINVAL);
    }

    if (comment_len)
        avio_write(pb, comment->value, comment_len);

    ffio_fill(pb, 0, comment_size - comment_len);

    avio_flush(pb);

    return 0;
}

__attribute__((used)) static int sox_write_trailer(AVFormatContext *s)
{
    SoXContext *sox = s->priv_data;
    AVIOContext *pb = s->pb;
    AVCodecParameters *par = s->streams[0]->codecpar;

    if (s->pb->seekable & AVIO_SEEKABLE_NORMAL) {
        /* update number of samples */
        int64_t file_size = avio_tell(pb);
        int64_t num_samples = (file_size - sox->header_size - 4LL) >> 2LL;
        avio_seek(pb, 8, SEEK_SET);
        if (par->codec_id == AV_CODEC_ID_PCM_S32LE) {
            avio_wl64(pb, num_samples);
        } else
            avio_wb64(pb, num_samples);
        avio_seek(pb, file_size, SEEK_SET);

        avio_flush(pb);
    }

    return 0;
}

