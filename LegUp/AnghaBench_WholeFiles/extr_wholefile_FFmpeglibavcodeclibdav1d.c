#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_57__   TYPE_9__ ;
typedef  struct TYPE_56__   TYPE_8__ ;
typedef  struct TYPE_55__   TYPE_7__ ;
typedef  struct TYPE_54__   TYPE_6__ ;
typedef  struct TYPE_53__   TYPE_5__ ;
typedef  struct TYPE_52__   TYPE_4__ ;
typedef  struct TYPE_51__   TYPE_3__ ;
typedef  struct TYPE_50__   TYPE_2__ ;
typedef  struct TYPE_49__   TYPE_1__ ;
typedef  struct TYPE_48__   TYPE_17__ ;
typedef  struct TYPE_47__   TYPE_16__ ;
typedef  struct TYPE_46__   TYPE_15__ ;
typedef  struct TYPE_45__   TYPE_14__ ;
typedef  struct TYPE_44__   TYPE_13__ ;
typedef  struct TYPE_43__   TYPE_12__ ;
typedef  struct TYPE_42__   TYPE_11__ ;
typedef  struct TYPE_41__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  va_list ;
typedef  int /*<<< orphan*/  uint8_t ;
typedef  enum AVPixelFormat { ____Placeholder_AVPixelFormat } AVPixelFormat ;
typedef  enum AVColorTransferCharacteristic { ____Placeholder_AVColorTransferCharacteristic } AVColorTransferCharacteristic ;
typedef  enum AVColorSpace { ____Placeholder_AVColorSpace } AVColorSpace ;
typedef  enum AVColorPrimaries { ____Placeholder_AVColorPrimaries } AVColorPrimaries ;
struct TYPE_49__ {int /*<<< orphan*/  duration; int /*<<< orphan*/  offset; int /*<<< orphan*/  timestamp; } ;
struct TYPE_42__ {TYPE_1__ m; int /*<<< orphan*/  sz; } ;
struct TYPE_57__ {int pool_size; int /*<<< orphan*/  c; TYPE_11__ data; int /*<<< orphan*/  pool; } ;
struct TYPE_56__ {int /*<<< orphan*/  max_frame_average_light_level; int /*<<< orphan*/  max_content_light_level; } ;
struct TYPE_55__ {int /*<<< orphan*/  min_luminance; int /*<<< orphan*/  max_luminance; int /*<<< orphan*/ * white_point; int /*<<< orphan*/ ** primaries; } ;
struct TYPE_54__ {int frame_type; } ;
struct TYPE_53__ {int /*<<< orphan*/  duration; int /*<<< orphan*/  size; int /*<<< orphan*/  offset; int /*<<< orphan*/  timestamp; } ;
struct TYPE_52__ {size_t hbd; int chr; scalar_t__ color_range; scalar_t__ trc; scalar_t__ pri; scalar_t__ mtrx; int /*<<< orphan*/  profile; } ;
struct TYPE_51__ {size_t layout; uintptr_t h; uintptr_t w; } ;
struct TYPE_50__ {scalar_t__ draining; } ;
struct TYPE_48__ {scalar_t__ data; } ;
struct TYPE_47__ {scalar_t__ width; scalar_t__ height; int colorspace; int color_primaries; int color_trc; int /*<<< orphan*/  color_range; int /*<<< orphan*/  chroma_sample_location; void* pix_fmt; int /*<<< orphan*/  profile; TYPE_2__* internal; TYPE_9__* priv_data; } ;
struct TYPE_46__ {int /*<<< orphan*/  MaxFALL; int /*<<< orphan*/  MaxCLL; } ;
struct TYPE_45__ {int* linesize; uintptr_t width; uintptr_t height; int colorspace; int color_primaries; int color_trc; int key_frame; int /*<<< orphan*/  pict_type; int /*<<< orphan*/  pkt_duration; int /*<<< orphan*/  pkt_size; int /*<<< orphan*/  pkt_pos; int /*<<< orphan*/  pkt_dts; int /*<<< orphan*/  best_effort_timestamp; int /*<<< orphan*/  pts; int /*<<< orphan*/  color_range; int /*<<< orphan*/  chroma_location; void* format; int /*<<< orphan*/ ** data; int /*<<< orphan*/ * buf; } ;
struct TYPE_44__ {int has_primaries; int has_luminance; void* min_luminance; void* max_luminance; void** white_point; void*** display_primaries; } ;
struct TYPE_43__ {int /*<<< orphan*/ * buf; int /*<<< orphan*/  duration; int /*<<< orphan*/  pos; int /*<<< orphan*/  pts; scalar_t__ size; int /*<<< orphan*/  data; int /*<<< orphan*/  member_0; } ;
struct TYPE_41__ {int* stride; TYPE_8__* content_light; TYPE_7__* mastering_display; TYPE_6__* frame_hdr; TYPE_5__ m; TYPE_4__* seq_hdr; TYPE_3__ p; int /*<<< orphan*/ ** data; TYPE_17__* allocator_data; int /*<<< orphan*/  member_0; } ;
typedef  TYPE_9__ Libdav1dContext ;
typedef  TYPE_10__ Dav1dPicture ;
typedef  TYPE_11__ Dav1dData ;
typedef  TYPE_12__ AVPacket ;
typedef  TYPE_13__ AVMasteringDisplayMetadata ;
typedef  TYPE_14__ AVFrame ;
typedef  TYPE_15__ AVContentLightMetadata ;
typedef  TYPE_16__ AVCodecContext ;
typedef  TYPE_17__ AVBufferRef ;

/* Variables and functions */
 int /*<<< orphan*/  AVCHROMA_LOC_LEFT ; 
 int /*<<< orphan*/  AVCHROMA_LOC_TOPLEFT ; 
 int /*<<< orphan*/  AVCOL_RANGE_JPEG ; 
 int /*<<< orphan*/  AVCOL_RANGE_MPEG ; 
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_EOF ; 
 int AVERROR_INVALIDDATA ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_I ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_P ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_SP ; 
#define  DAV1D_CHR_COLOCATED 133 
#define  DAV1D_CHR_VERTICAL 132 
#define  DAV1D_FRAME_TYPE_INTER 131 
#define  DAV1D_FRAME_TYPE_INTRA 130 
#define  DAV1D_FRAME_TYPE_KEY 129 
#define  DAV1D_FRAME_TYPE_SWITCH 128 
 int DAV1D_PICTURE_ALIGNMENT ; 
 int /*<<< orphan*/  EAGAIN ; 
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  ENOMEM ; 
 int FFALIGN (uintptr_t,int) ; 
 int /*<<< orphan*/  av_assert0 (int /*<<< orphan*/ ) ; 
 TYPE_17__* av_buffer_pool_get (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  av_buffer_pool_init (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  av_buffer_pool_uninit (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  av_buffer_ref (TYPE_17__*) ; 
 int /*<<< orphan*/  av_buffer_unref (TYPE_17__**) ; 
 TYPE_15__* av_content_light_metadata_create_side_data (TYPE_14__*) ; 
 int /*<<< orphan*/  av_frame_unref (TYPE_14__*) ; 
 int av_image_fill_arrays (int /*<<< orphan*/ **,int*,int /*<<< orphan*/ *,int,int,int,int) ; 
 int av_image_fill_pointers (int /*<<< orphan*/ **,int,int,int /*<<< orphan*/ *,int*) ; 
 void* av_make_q (int /*<<< orphan*/ ,int) ; 
 TYPE_13__* av_mastering_display_metadata_create_side_data (TYPE_14__*) ; 
 int /*<<< orphan*/  av_packet_unref (TYPE_12__*) ; 
 int /*<<< orphan*/  av_vlog (TYPE_16__*,int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dav1d_data_unref (TYPE_11__*) ; 
 int dav1d_data_wrap (TYPE_11__*,int /*<<< orphan*/ ,scalar_t__,void (*) (int /*<<< orphan*/  const*,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dav1d_flush (int /*<<< orphan*/ ) ; 
 int dav1d_get_picture (int /*<<< orphan*/ ,TYPE_10__*) ; 
 int /*<<< orphan*/  dav1d_picture_unref (TYPE_10__*) ; 
 int dav1d_send_data (int /*<<< orphan*/ ,TYPE_11__*) ; 
 int ff_decode_get_packet (TYPE_16__*,TYPE_12__*) ; 
 int ff_set_dimensions (TYPE_16__*,scalar_t__,scalar_t__) ; 
 void*** pix_fmt ; 

__attribute__((used)) static void libdav1d_log_callback(void *opaque, const char *fmt, va_list vl)
{
    AVCodecContext *c = opaque;

    av_vlog(c, AV_LOG_ERROR, fmt, vl);
}

__attribute__((used)) static int libdav1d_picture_allocator(Dav1dPicture *p, void *cookie)
{
    Libdav1dContext *dav1d = cookie;
    enum AVPixelFormat format = pix_fmt[p->p.layout][p->seq_hdr->hbd];
    int ret, linesize[4], h = FFALIGN(p->p.h, 128);
    uint8_t *aligned_ptr, *data[4];
    AVBufferRef *buf;

    ret = av_image_fill_arrays(data, linesize, NULL, format, FFALIGN(p->p.w, 128),
                               h, DAV1D_PICTURE_ALIGNMENT);
    if (ret < 0)
        return ret;

    if (ret != dav1d->pool_size) {
        av_buffer_pool_uninit(&dav1d->pool);
        // Use twice the amount of required padding bytes for aligned_ptr below.
        dav1d->pool = av_buffer_pool_init(ret + DAV1D_PICTURE_ALIGNMENT * 2, NULL);
        if (!dav1d->pool) {
            dav1d->pool_size = 0;
            return AVERROR(ENOMEM);
        }
        dav1d->pool_size = ret;
    }
    buf = av_buffer_pool_get(dav1d->pool);
    if (!buf)
        return AVERROR(ENOMEM);

    // libdav1d requires DAV1D_PICTURE_ALIGNMENT aligned buffers, which av_malloc()
    // doesn't guarantee for example when AVX is disabled at configure time.
    // Use the extra DAV1D_PICTURE_ALIGNMENT padding bytes in the buffer to align it
    // if required.
    aligned_ptr = (uint8_t *)FFALIGN((uintptr_t)buf->data, DAV1D_PICTURE_ALIGNMENT);
    ret = av_image_fill_pointers(data, format, h, aligned_ptr, linesize);
    if (ret < 0) {
        av_buffer_unref(&buf);
        return ret;
    }

    p->data[0] = data[0];
    p->data[1] = data[1];
    p->data[2] = data[2];
    p->stride[0] = linesize[0];
    p->stride[1] = linesize[1];
    p->allocator_data = buf;

    return 0;
}

__attribute__((used)) static void libdav1d_picture_release(Dav1dPicture *p, void *cookie)
{
    AVBufferRef *buf = p->allocator_data;

    av_buffer_unref(&buf);
}

__attribute__((used)) static void libdav1d_flush(AVCodecContext *c)
{
    Libdav1dContext *dav1d = c->priv_data;

    dav1d_data_unref(&dav1d->data);
    dav1d_flush(dav1d->c);
}

__attribute__((used)) static void libdav1d_data_free(const uint8_t *data, void *opaque) {
    AVBufferRef *buf = opaque;

    av_buffer_unref(&buf);
}

__attribute__((used)) static int libdav1d_receive_frame(AVCodecContext *c, AVFrame *frame)
{
    Libdav1dContext *dav1d = c->priv_data;
    Dav1dData *data = &dav1d->data;
    Dav1dPicture pic = { 0 }, *p = &pic;
    int res;

    if (!data->sz) {
        AVPacket pkt = { 0 };

        res = ff_decode_get_packet(c, &pkt);
        if (res < 0 && res != AVERROR_EOF)
            return res;

        if (pkt.size) {
            res = dav1d_data_wrap(data, pkt.data, pkt.size, libdav1d_data_free, pkt.buf);
            if (res < 0) {
                av_packet_unref(&pkt);
                return res;
            }

            data->m.timestamp = pkt.pts;
            data->m.offset = pkt.pos;
            data->m.duration = pkt.duration;

            pkt.buf = NULL;
            av_packet_unref(&pkt);
        }
    }

    res = dav1d_send_data(dav1d->c, data);
    if (res < 0) {
        if (res == AVERROR(EINVAL))
            res = AVERROR_INVALIDDATA;
        if (res != AVERROR(EAGAIN))
            return res;
    }

    res = dav1d_get_picture(dav1d->c, p);
    if (res < 0) {
        if (res == AVERROR(EINVAL))
            res = AVERROR_INVALIDDATA;
        else if (res == AVERROR(EAGAIN) && c->internal->draining)
            res = AVERROR_EOF;

        return res;
    }

    av_assert0(p->data[0] != NULL);

    // This requires the custom allocator above
    frame->buf[0] = av_buffer_ref(p->allocator_data);
    if (!frame->buf[0]) {
        dav1d_picture_unref(p);
        return AVERROR(ENOMEM);
    }

    frame->data[0] = p->data[0];
    frame->data[1] = p->data[1];
    frame->data[2] = p->data[2];
    frame->linesize[0] = p->stride[0];
    frame->linesize[1] = p->stride[1];
    frame->linesize[2] = p->stride[1];

    c->profile = p->seq_hdr->profile;
    frame->format = c->pix_fmt = pix_fmt[p->p.layout][p->seq_hdr->hbd];
    frame->width = p->p.w;
    frame->height = p->p.h;
    if (c->width != p->p.w || c->height != p->p.h) {
        res = ff_set_dimensions(c, p->p.w, p->p.h);
        if (res < 0)
            goto fail;
    }

    switch (p->seq_hdr->chr) {
    case DAV1D_CHR_VERTICAL:
        frame->chroma_location = c->chroma_sample_location = AVCHROMA_LOC_LEFT;
        break;
    case DAV1D_CHR_COLOCATED:
        frame->chroma_location = c->chroma_sample_location = AVCHROMA_LOC_TOPLEFT;
        break;
    }
    frame->colorspace = c->colorspace = (enum AVColorSpace) p->seq_hdr->mtrx;
    frame->color_primaries = c->color_primaries = (enum AVColorPrimaries) p->seq_hdr->pri;
    frame->color_trc = c->color_trc = (enum AVColorTransferCharacteristic) p->seq_hdr->trc;
    frame->color_range = c->color_range = p->seq_hdr->color_range ? AVCOL_RANGE_JPEG : AVCOL_RANGE_MPEG;

    // match timestamps and packet size
    frame->pts = frame->best_effort_timestamp = p->m.timestamp;
#if FF_API_PKT_PTS
FF_DISABLE_DEPRECATION_WARNINGS
    frame->pkt_pts = p->m.timestamp;
FF_ENABLE_DEPRECATION_WARNINGS
#endif
    frame->pkt_dts = p->m.timestamp;
    frame->pkt_pos = p->m.offset;
    frame->pkt_size = p->m.size;
    frame->pkt_duration = p->m.duration;
    frame->key_frame = p->frame_hdr->frame_type == DAV1D_FRAME_TYPE_KEY;

    switch (p->frame_hdr->frame_type) {
    case DAV1D_FRAME_TYPE_KEY:
    case DAV1D_FRAME_TYPE_INTRA:
        frame->pict_type = AV_PICTURE_TYPE_I;
        break;
    case DAV1D_FRAME_TYPE_INTER:
        frame->pict_type = AV_PICTURE_TYPE_P;
        break;
    case DAV1D_FRAME_TYPE_SWITCH:
        frame->pict_type = AV_PICTURE_TYPE_SP;
        break;
    default:
        res = AVERROR_INVALIDDATA;
        goto fail;
    }

    if (p->mastering_display) {
        AVMasteringDisplayMetadata *mastering = av_mastering_display_metadata_create_side_data(frame);
        if (!mastering) {
            res = AVERROR(ENOMEM);
            goto fail;
        }

        for (int i = 0; i < 3; i++) {
            mastering->display_primaries[i][0] = av_make_q(p->mastering_display->primaries[i][0], 1 << 16);
            mastering->display_primaries[i][1] = av_make_q(p->mastering_display->primaries[i][1], 1 << 16);
        }
        mastering->white_point[0] = av_make_q(p->mastering_display->white_point[0], 1 << 16);
        mastering->white_point[1] = av_make_q(p->mastering_display->white_point[1], 1 << 16);

        mastering->max_luminance = av_make_q(p->mastering_display->max_luminance, 1 << 8);
        mastering->min_luminance = av_make_q(p->mastering_display->min_luminance, 1 << 14);

        mastering->has_primaries = 1;
        mastering->has_luminance = 1;
    }
    if (p->content_light) {
        AVContentLightMetadata *light = av_content_light_metadata_create_side_data(frame);
        if (!light) {
            res = AVERROR(ENOMEM);
            goto fail;
        }
        light->MaxCLL = p->content_light->max_content_light_level;
        light->MaxFALL = p->content_light->max_frame_average_light_level;
    }

    res = 0;
fail:
    dav1d_picture_unref(p);
    if (res < 0)
        av_frame_unref(frame);
    return res;
}

