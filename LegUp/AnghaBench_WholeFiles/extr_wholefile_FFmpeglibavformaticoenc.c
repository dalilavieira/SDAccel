#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_34__   TYPE_8__ ;
typedef  struct TYPE_33__   TYPE_7__ ;
typedef  struct TYPE_32__   TYPE_6__ ;
typedef  struct TYPE_31__   TYPE_5__ ;
typedef  struct TYPE_30__   TYPE_4__ ;
typedef  struct TYPE_29__   TYPE_3__ ;
typedef  struct TYPE_28__   TYPE_2__ ;
typedef  struct TYPE_27__   TYPE_1__ ;

/* Type definitions */
struct TYPE_34__ {char* name; } ;
struct TYPE_33__ {scalar_t__ codec_id; scalar_t__ format; int width; int height; int bits_per_coded_sample; } ;
struct TYPE_32__ {int nb_streams; TYPE_1__** streams; TYPE_5__* pb; TYPE_2__* priv_data; } ;
struct TYPE_31__ {int seekable; } ;
struct TYPE_30__ {size_t stream_index; int size; scalar_t__ data; } ;
struct TYPE_29__ {int offset; int width; int height; int bits; int size; } ;
struct TYPE_28__ {int current_image; int nb_images; TYPE_3__* images; } ;
struct TYPE_27__ {TYPE_7__* codecpar; } ;
typedef  TYPE_2__ IcoMuxContext ;
typedef  TYPE_3__ IcoImage ;
typedef  TYPE_4__ AVPacket ;
typedef  TYPE_5__ AVIOContext ;
typedef  TYPE_6__ AVFormatContext ;
typedef  TYPE_7__ AVCodecParameters ;
typedef  TYPE_8__ AVCodecDescriptor ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVIO_SEEKABLE_NORMAL ; 
 scalar_t__ AV_CODEC_ID_BMP ; 
 scalar_t__ AV_CODEC_ID_PNG ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 scalar_t__ AV_PIX_FMT_BGR24 ; 
 scalar_t__ AV_PIX_FMT_BGRA ; 
 scalar_t__ AV_PIX_FMT_PAL8 ; 
 scalar_t__ AV_PIX_FMT_RGB32 ; 
 scalar_t__ AV_PIX_FMT_RGB555LE ; 
 scalar_t__ AV_PIX_FMT_RGBA ; 
 int AV_RL16 (scalar_t__) ; 
 int AV_RL32 (scalar_t__) ; 
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  EIO ; 
 int /*<<< orphan*/  ENOMEM ; 
 int /*<<< orphan*/  SEEK_SET ; 
 int /*<<< orphan*/  av_freep (TYPE_3__**) ; 
 int /*<<< orphan*/  av_log (TYPE_6__*,int /*<<< orphan*/ ,char*,...) ; 
 TYPE_3__* av_mallocz_array (int,int) ; 
 TYPE_8__* avcodec_descriptor_get (scalar_t__) ; 
 int /*<<< orphan*/  avio_flush (TYPE_5__*) ; 
 int /*<<< orphan*/  avio_seek (TYPE_5__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  avio_skip (TYPE_5__*,int) ; 
 int avio_tell (TYPE_5__*) ; 
 int /*<<< orphan*/  avio_w8 (TYPE_5__*,int) ; 
 int /*<<< orphan*/  avio_wl16 (TYPE_5__*,int) ; 
 int /*<<< orphan*/  avio_wl32 (TYPE_5__*,int) ; 
 int /*<<< orphan*/  avio_write (TYPE_5__*,scalar_t__,int) ; 

__attribute__((used)) static int ico_check_attributes(AVFormatContext *s, const AVCodecParameters *p)
{
    if (p->codec_id == AV_CODEC_ID_BMP) {
        if (p->format == AV_PIX_FMT_PAL8 && AV_PIX_FMT_RGB32 != AV_PIX_FMT_BGRA) {
            av_log(s, AV_LOG_ERROR, "Wrong endianness for bmp pixel format\n");
            return AVERROR(EINVAL);
        } else if (p->format != AV_PIX_FMT_PAL8 &&
                   p->format != AV_PIX_FMT_RGB555LE &&
                   p->format != AV_PIX_FMT_BGR24 &&
                   p->format != AV_PIX_FMT_BGRA) {
            av_log(s, AV_LOG_ERROR, "BMP must be 1bit, 4bit, 8bit, 16bit, 24bit, or 32bit\n");
            return AVERROR(EINVAL);
        }
    } else if (p->codec_id == AV_CODEC_ID_PNG) {
        if (p->format != AV_PIX_FMT_RGBA) {
            av_log(s, AV_LOG_ERROR, "PNG in ico requires pixel format to be rgba\n");
            return AVERROR(EINVAL);
        }
    } else {
        const AVCodecDescriptor *codesc = avcodec_descriptor_get(p->codec_id);
        av_log(s, AV_LOG_ERROR, "Unsupported codec %s\n", codesc ? codesc->name : "");
        return AVERROR(EINVAL);
    }

    if (p->width > 256 ||
        p->height > 256) {
        av_log(s, AV_LOG_ERROR, "Unsupported dimensions %dx%d (dimensions cannot exceed 256x256)\n", p->width, p->height);
        return AVERROR(EINVAL);
    }

    return 0;
}

__attribute__((used)) static int ico_write_header(AVFormatContext *s)
{
    IcoMuxContext *ico = s->priv_data;
    AVIOContext *pb = s->pb;
    int ret;
    int i;

    if (!(pb->seekable & AVIO_SEEKABLE_NORMAL)) {
        av_log(s, AV_LOG_ERROR, "Output is not seekable\n");
        return AVERROR(EINVAL);
    }

    ico->current_image = 0;
    ico->nb_images = s->nb_streams;

    avio_wl16(pb, 0); // reserved
    avio_wl16(pb, 1); // 1 == icon
    avio_skip(pb, 2); // skip the number of images

    for (i = 0; i < s->nb_streams; i++) {
        if (ret = ico_check_attributes(s, s->streams[i]->codecpar))
            return ret;

        // Fill in later when writing trailer...
        avio_skip(pb, 16);
    }

    ico->images = av_mallocz_array(ico->nb_images, sizeof(IcoMuxContext));
    if (!ico->images)
        return AVERROR(ENOMEM);

    avio_flush(pb);

    return 0;
}

__attribute__((used)) static int ico_write_packet(AVFormatContext *s, AVPacket *pkt)
{
    IcoMuxContext *ico = s->priv_data;
    IcoImage *image;
    AVIOContext *pb = s->pb;
    AVCodecParameters *par = s->streams[pkt->stream_index]->codecpar;
    int i;

    if (ico->current_image >= ico->nb_images) {
        av_log(s, AV_LOG_ERROR, "ICO already contains %d images\n", ico->current_image);
        return AVERROR(EIO);
    }

    image = &ico->images[ico->current_image++];

    image->offset = avio_tell(pb);
    image->width = (par->width == 256) ? 0 : par->width;
    image->height = (par->height == 256) ? 0 : par->height;

    if (par->codec_id == AV_CODEC_ID_PNG) {
        image->bits = par->bits_per_coded_sample;
        image->size = pkt->size;

        avio_write(pb, pkt->data, pkt->size);
    } else { // BMP
        if (AV_RL32(pkt->data + 14) != 40) { // must be BITMAPINFOHEADER
            av_log(s, AV_LOG_ERROR, "Invalid BMP\n");
            return AVERROR(EINVAL);
        }

        image->bits = AV_RL16(pkt->data + 28); // allows things like 1bit and 4bit images to be preserved
        image->size = pkt->size - 14 + par->height * (par->width + 7) / 8;

        avio_write(pb, pkt->data + 14, 8); // Skip the BITMAPFILEHEADER header
        avio_wl32(pb, AV_RL32(pkt->data + 22) * 2); // rewrite height as 2 * height
        avio_write(pb, pkt->data + 26, pkt->size - 26);

        for (i = 0; i < par->height * (par->width + 7) / 8; ++i)
            avio_w8(pb, 0x00); // Write bitmask (opaque)
    }

    return 0;
}

__attribute__((used)) static int ico_write_trailer(AVFormatContext *s)
{
    IcoMuxContext *ico = s->priv_data;
    AVIOContext *pb = s->pb;
    int i;

    avio_seek(pb, 4, SEEK_SET);

    avio_wl16(pb, ico->current_image);

    for (i = 0; i < ico->nb_images; i++) {
        avio_w8(pb, ico->images[i].width);
        avio_w8(pb, ico->images[i].height);

        if (s->streams[i]->codecpar->codec_id == AV_CODEC_ID_BMP &&
            s->streams[i]->codecpar->format == AV_PIX_FMT_PAL8) {
            avio_w8(pb, (ico->images[i].bits >= 8) ? 0 : 1 << ico->images[i].bits);
        } else {
            avio_w8(pb, 0);
        }

        avio_w8(pb, 0); // reserved
        avio_wl16(pb, 1); // color planes
        avio_wl16(pb, ico->images[i].bits);
        avio_wl32(pb, ico->images[i].size);
        avio_wl32(pb, ico->images[i].offset);
    }

    av_freep(&ico->images);

    return 0;
}

