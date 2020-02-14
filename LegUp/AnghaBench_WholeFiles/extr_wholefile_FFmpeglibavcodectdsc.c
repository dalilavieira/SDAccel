#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_30__   TYPE_4__ ;
typedef  struct TYPE_29__   TYPE_3__ ;
typedef  struct TYPE_28__   TYPE_2__ ;
typedef  struct TYPE_27__   TYPE_22__ ;
typedef  struct TYPE_26__   TYPE_1__ ;
typedef  struct TYPE_25__   TYPE_18__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int uLongf ;
struct TYPE_30__ {int width; scalar_t__ height; int err_recognition; TYPE_1__* priv_data; } ;
struct TYPE_29__ {int** data; int* linesize; int key_frame; int /*<<< orphan*/  pict_type; } ;
struct TYPE_28__ {int* data; int size; } ;
struct TYPE_27__ {int* linesize; int width; int height; scalar_t__* data; } ;
struct TYPE_26__ {int* cursor; int cursor_x; int cursor_hot_x; int cursor_y; int cursor_hot_y; int cursor_w; int cursor_h; int width; int height; int cursor_stride; int* tilebuffer; int deflatelen; int* deflatebuffer; TYPE_22__* refframe; int /*<<< orphan*/  gbc; TYPE_18__* jpgframe; int /*<<< orphan*/  jpeg_avctx; } ;
struct TYPE_25__ {scalar_t__ format; int /*<<< orphan*/ * linesize; int /*<<< orphan*/ * data; } ;
typedef  TYPE_1__ TDSCContext ;
typedef  TYPE_2__ AVPacket ;
typedef  TYPE_3__ AVFrame ;
typedef  TYPE_4__ AVCodecContext ;

/* Variables and functions */
 int /*<<< orphan*/  APPLY_ALPHA (int,int const,int) ; 
 int AVERROR_INVALIDDATA ; 
 int AVERROR_PATCHWELCOME ; 
 int AVERROR_UNKNOWN ; 
 int AV_EF_EXPLODE ; 
 int /*<<< orphan*/  AV_LOG_DEBUG ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_LOG_WARNING ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_I ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_P ; 
 scalar_t__ AV_PIX_FMT_YUVJ420P ; 
 int BITMAPINFOHEADER_SIZE ; 
#define  CUR_FMT_BGRA 130 
#define  CUR_FMT_MONO 129 
#define  CUR_FMT_RGBA 128 
 int FFALIGN (int,int) ; 
 void* FFMIN (int,int) ; 
 int MKTAG (char,char,char,char) ; 
 int TDSB_HEADER_SIZE ; 
 int TDSF_HEADER_SIZE ; 
 int av_clip_uint8 (int) ; 
 int av_frame_copy (TYPE_3__*,TYPE_22__*) ; 
 int av_frame_get_buffer (TYPE_22__*,int) ; 
 int /*<<< orphan*/  av_frame_unref (TYPE_18__*) ; 
 int /*<<< orphan*/  av_image_copy_plane (scalar_t__,int,int*,int,int,int) ; 
 int /*<<< orphan*/  av_init_packet (TYPE_2__*) ; 
 int /*<<< orphan*/  av_log (TYPE_4__*,int /*<<< orphan*/ ,char*,...) ; 
 int av_reallocp (int**,int) ; 
 int avcodec_receive_frame (int /*<<< orphan*/ ,TYPE_18__*) ; 
 int avcodec_send_packet (int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  avpriv_request_sample (TYPE_4__*,char*,int) ; 
 int bytestream2_get_be32 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bytestream2_get_buffer (int /*<<< orphan*/ *,int*,int) ; 
 int bytestream2_get_bytes_left (int /*<<< orphan*/ *) ; 
 int bytestream2_get_le16 (int /*<<< orphan*/ *) ; 
 int bytestream2_get_le32 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bytestream2_init (int /*<<< orphan*/ *,int*,int) ; 
 int /*<<< orphan*/  bytestream2_skip (int /*<<< orphan*/ *,int) ; 
 int ff_get_buffer (TYPE_4__*,TYPE_3__*,int /*<<< orphan*/ ) ; 
 int ff_set_dimensions (TYPE_4__*,int,int) ; 
 int /*<<< orphan*/  tdsc_blit (scalar_t__,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int uncompress (int*,int*,int*,int) ; 

__attribute__((used)) static void tdsc_paint_cursor(AVCodecContext *avctx, uint8_t *dst, int stride)
{
    TDSCContext *ctx = avctx->priv_data;
    const uint8_t *cursor = ctx->cursor;
    int x = ctx->cursor_x - ctx->cursor_hot_x;
    int y = ctx->cursor_y - ctx->cursor_hot_y;
    int w = ctx->cursor_w;
    int h = ctx->cursor_h;
    int i, j;

    if (!ctx->cursor)
        return;

    if (x + w > ctx->width)
        w = ctx->width - x;
    if (y + h > ctx->height)
        h = ctx->height - y;
    if (x < 0) {
        w      +=  x;
        cursor += -x * 4;
    } else {
        dst    +=  x * 3;
    }
    if (y < 0) {
        h      +=  y;
        cursor += -y * ctx->cursor_stride;
    } else {
        dst    +=  y * stride;
    }
    if (w < 0 || h < 0)
        return;

    for (j = 0; j < h; j++) {
        for (i = 0; i < w; i++) {
            uint8_t alpha = cursor[i * 4];
            APPLY_ALPHA(dst[i * 3 + 0], cursor[i * 4 + 1], alpha);
            APPLY_ALPHA(dst[i * 3 + 1], cursor[i * 4 + 2], alpha);
            APPLY_ALPHA(dst[i * 3 + 2], cursor[i * 4 + 3], alpha);
        }
        dst    += stride;
        cursor += ctx->cursor_stride;
    }
}

__attribute__((used)) static int tdsc_load_cursor(AVCodecContext *avctx)
{
    TDSCContext *ctx  = avctx->priv_data;
    int i, j, k, ret, bits, cursor_fmt;
    uint8_t *dst;

    ctx->cursor_hot_x = bytestream2_get_le16(&ctx->gbc);
    ctx->cursor_hot_y = bytestream2_get_le16(&ctx->gbc);
    ctx->cursor_w     = bytestream2_get_le16(&ctx->gbc);
    ctx->cursor_h     = bytestream2_get_le16(&ctx->gbc);

    ctx->cursor_stride = FFALIGN(ctx->cursor_w, 32) * 4;
    cursor_fmt = bytestream2_get_le32(&ctx->gbc);

    if (ctx->cursor_x >= avctx->width || ctx->cursor_y >= avctx->height) {
        av_log(avctx, AV_LOG_ERROR,
               "Invalid cursor position (%d.%d outside %dx%d).\n",
               ctx->cursor_x, ctx->cursor_y, avctx->width, avctx->height);
        return AVERROR_INVALIDDATA;
    }
    if (ctx->cursor_w < 1 || ctx->cursor_w > 256 ||
        ctx->cursor_h < 1 || ctx->cursor_h > 256) {
        av_log(avctx, AV_LOG_ERROR,
               "Invalid cursor dimensions %dx%d.\n",
               ctx->cursor_w, ctx->cursor_h);
        return AVERROR_INVALIDDATA;
    }
    if (ctx->cursor_hot_x > ctx->cursor_w ||
        ctx->cursor_hot_y > ctx->cursor_h) {
        av_log(avctx, AV_LOG_WARNING, "Invalid hotspot position %d.%d.\n",
               ctx->cursor_hot_x, ctx->cursor_hot_y);
        ctx->cursor_hot_x = FFMIN(ctx->cursor_hot_x, ctx->cursor_w - 1);
        ctx->cursor_hot_y = FFMIN(ctx->cursor_hot_y, ctx->cursor_h - 1);
    }

    ret = av_reallocp(&ctx->cursor, ctx->cursor_stride * ctx->cursor_h);
    if (ret < 0) {
        av_log(avctx, AV_LOG_ERROR, "Cannot allocate cursor buffer.\n");
        return ret;
    }

    dst = ctx->cursor;
    /* here data is packed in BE */
    switch (cursor_fmt) {
    case CUR_FMT_MONO:
        for (j = 0; j < ctx->cursor_h; j++) {
            for (i = 0; i < ctx->cursor_w; i += 32) {
                bits = bytestream2_get_be32(&ctx->gbc);
                for (k = 0; k < 32; k++) {
                    dst[0] = !!(bits & 0x80000000);
                    dst   += 4;
                    bits <<= 1;
                }
            }
            dst += ctx->cursor_stride - ctx->cursor_w * 4;
        }

        dst = ctx->cursor;
        for (j = 0; j < ctx->cursor_h; j++) {
            for (i = 0; i < ctx->cursor_w; i += 32) {
                bits = bytestream2_get_be32(&ctx->gbc);
                for (k = 0; k < 32; k++) {
                    int mask_bit = !!(bits & 0x80000000);
                    switch (dst[0] * 2 + mask_bit) {
                    case 0:
                        dst[0] = 0xFF;
                        dst[1] = 0x00;
                        dst[2] = 0x00;
                        dst[3] = 0x00;
                        break;
                    case 1:
                        dst[0] = 0xFF;
                        dst[1] = 0xFF;
                        dst[2] = 0xFF;
                        dst[3] = 0xFF;
                        break;
                    default:
                        dst[0] = 0x00;
                        dst[1] = 0x00;
                        dst[2] = 0x00;
                        dst[3] = 0x00;
                    }
                    dst   += 4;
                    bits <<= 1;
                }
            }
            dst += ctx->cursor_stride - ctx->cursor_w * 4;
        }
        break;
    case CUR_FMT_BGRA:
    case CUR_FMT_RGBA:
        /* Skip monochrome version of the cursor */
        bytestream2_skip(&ctx->gbc,
                         ctx->cursor_h * (FFALIGN(ctx->cursor_w, 32) >> 3));
        if (cursor_fmt & 8) { // RGBA -> ABGR
            for (j = 0; j < ctx->cursor_h; j++) {
                for (i = 0; i < ctx->cursor_w; i++) {
                    int val = bytestream2_get_be32(&ctx->gbc);
                    *dst++ = val >> 24;
                    *dst++ = val >> 16;
                    *dst++ = val >>  8;
                    *dst++ = val >>  0;
                }
                dst += ctx->cursor_stride - ctx->cursor_w * 4;
            }
        } else { // BGRA -> ABGR
            for (j = 0; j < ctx->cursor_h; j++) {
                for (i = 0; i < ctx->cursor_w; i++) {
                    int val = bytestream2_get_be32(&ctx->gbc);
                    *dst++ = val >>  0;
                    *dst++ = val >> 24;
                    *dst++ = val >> 16;
                    *dst++ = val >>  8;
                }
                dst += ctx->cursor_stride - ctx->cursor_w * 4;
            }
        }
        break;
    default:
        avpriv_request_sample(avctx, "Cursor format %08x", cursor_fmt);
        return AVERROR_PATCHWELCOME;
    }

    return 0;
}

__attribute__((used)) static inline void tdsc_yuv2rgb(uint8_t *out, int Y, int U, int V)
{
    out[0] = av_clip_uint8(Y + (             91881 * V + 32768 >> 16));
    out[1] = av_clip_uint8(Y + (-22554 * U - 46802 * V + 32768 >> 16));
    out[2] = av_clip_uint8(Y + (116130 * U             + 32768 >> 16));
}

__attribute__((used)) static int tdsc_decode_jpeg_tile(AVCodecContext *avctx, int tile_size,
                                 int x, int y, int w, int h)
{
    TDSCContext *ctx = avctx->priv_data;
    AVPacket jpkt;
    int ret;

    /* Prepare a packet and send to the MJPEG decoder */
    av_init_packet(&jpkt);
    jpkt.data = ctx->tilebuffer;
    jpkt.size = tile_size;

    ret = avcodec_send_packet(ctx->jpeg_avctx, &jpkt);
    if (ret < 0) {
        av_log(avctx, AV_LOG_ERROR, "Error submitting a packet for decoding\n");
        return ret;
    }

    ret = avcodec_receive_frame(ctx->jpeg_avctx, ctx->jpgframe);
    if (ret < 0 || ctx->jpgframe->format != AV_PIX_FMT_YUVJ420P) {
        av_log(avctx, AV_LOG_ERROR,
               "JPEG decoding error (%d).\n", ret);

        /* Normally skip, error if explode */
        if (avctx->err_recognition & AV_EF_EXPLODE)
            return AVERROR_INVALIDDATA;
        else
            return 0;
    }

    /* Let's paint onto the buffer */
    tdsc_blit(ctx->refframe->data[0] + x * 3 + ctx->refframe->linesize[0] * y,
              ctx->refframe->linesize[0],
              ctx->jpgframe->data[0], ctx->jpgframe->linesize[0],
              ctx->jpgframe->data[1], ctx->jpgframe->data[2],
              ctx->jpgframe->linesize[1], w, h);

    av_frame_unref(ctx->jpgframe);

    return 0;
}

__attribute__((used)) static int tdsc_decode_tiles(AVCodecContext *avctx, int number_tiles)
{
    TDSCContext *ctx = avctx->priv_data;
    int i;

    /* Iterate over the number of tiles */
    for (i = 0; i < number_tiles; i++) {
        int tile_size;
        int tile_mode;
        int x, y, w, h;
        int ret;

        if (bytestream2_get_bytes_left(&ctx->gbc) < 4 ||
            bytestream2_get_le32(&ctx->gbc) != MKTAG('T','D','S','B') ||
            bytestream2_get_bytes_left(&ctx->gbc) < TDSB_HEADER_SIZE - 4) {
            av_log(avctx, AV_LOG_ERROR, "TDSB tag is too small.\n");
            return AVERROR_INVALIDDATA;
        }

        tile_size = bytestream2_get_le32(&ctx->gbc);
        if (bytestream2_get_bytes_left(&ctx->gbc) < tile_size)
            return AVERROR_INVALIDDATA;

        tile_mode = bytestream2_get_le32(&ctx->gbc);
        bytestream2_skip(&ctx->gbc, 4); // unknown
        x = bytestream2_get_le32(&ctx->gbc);
        y = bytestream2_get_le32(&ctx->gbc);
        w = bytestream2_get_le32(&ctx->gbc) - x;
        h = bytestream2_get_le32(&ctx->gbc) - y;

        if (x >= ctx->width || y >= ctx->height) {
            av_log(avctx, AV_LOG_ERROR,
                   "Invalid tile position (%d.%d outside %dx%d).\n",
                   x, y, ctx->width, ctx->height);
            return AVERROR_INVALIDDATA;
        }
        if (x + w > ctx->width || y + h > ctx->height) {
            av_log(avctx, AV_LOG_ERROR,
                   "Invalid tile size %dx%d\n", w, h);
            return AVERROR_INVALIDDATA;
        }

        ret = av_reallocp(&ctx->tilebuffer, tile_size);
        if (!ctx->tilebuffer)
            return ret;

        bytestream2_get_buffer(&ctx->gbc, ctx->tilebuffer, tile_size);

        if (tile_mode == MKTAG('G','E','P','J')) {
            /* Decode JPEG tile and copy it in the reference frame */
            ret = tdsc_decode_jpeg_tile(avctx, tile_size, x, y, w, h);
            if (ret < 0)
                return ret;
        } else if (tile_mode == MKTAG(' ','W','A','R')) {
            /* Just copy the buffer to output */
            av_image_copy_plane(ctx->refframe->data[0] + x * 3 +
                                ctx->refframe->linesize[0] * y,
                                ctx->refframe->linesize[0], ctx->tilebuffer,
                                w * 3, w * 3, h);
        } else {
            av_log(avctx, AV_LOG_ERROR, "Unknown tile type %08x.\n", tile_mode);
            return AVERROR_INVALIDDATA;
        }
        av_log(avctx, AV_LOG_DEBUG, "Tile %d, %dx%d (%d.%d)\n", i, w, h, x, y);
    }

    return 0;
}

__attribute__((used)) static int tdsc_parse_tdsf(AVCodecContext *avctx, int number_tiles)
{
    TDSCContext *ctx = avctx->priv_data;
    int ret, w, h, init_refframe = !ctx->refframe->data[0];

    /* BITMAPINFOHEADER
     * http://msdn.microsoft.com/en-us/library/windows/desktop/dd183376.aspx */
    if (bytestream2_get_le32(&ctx->gbc) != BITMAPINFOHEADER_SIZE)
        return AVERROR_INVALIDDATA;

    /* Store size, but wait for context reinit before updating avctx */
    w =  bytestream2_get_le32(&ctx->gbc);
    h = -bytestream2_get_le32(&ctx->gbc);

    if (bytestream2_get_le16(&ctx->gbc) != 1 ||  // 1 plane
        bytestream2_get_le16(&ctx->gbc) != 24)   // BGR24
        return AVERROR_INVALIDDATA;

    bytestream2_skip(&ctx->gbc, 24); // unused fields

    /* Update sizes */
    if (avctx->width != w || avctx->height != h) {
        av_log(avctx, AV_LOG_DEBUG, "Size update %dx%d -> %d%d.\n",
               avctx->width, avctx->height, ctx->width, ctx->height);
        ret = ff_set_dimensions(avctx, w, h);
        if (ret < 0)
            return ret;
        init_refframe = 1;
    }
    ctx->refframe->width  = ctx->width  = w;
    ctx->refframe->height = ctx->height = h;

    /* Allocate the reference frame if not already done or on size change */
    if (init_refframe) {
        ret = av_frame_get_buffer(ctx->refframe, 32);
        if (ret < 0)
            return ret;
    }

    /* Decode all tiles in a frame */
    return tdsc_decode_tiles(avctx, number_tiles);
}

__attribute__((used)) static int tdsc_parse_dtsm(AVCodecContext *avctx)
{
    TDSCContext *ctx = avctx->priv_data;
    int ret;
    int action = bytestream2_get_le32(&ctx->gbc);

    bytestream2_skip(&ctx->gbc, 4); // some kind of ID or version maybe?

    if (action == 2 || action == 3) {
        /* Load cursor coordinates */
        ctx->cursor_x = bytestream2_get_le32(&ctx->gbc);
        ctx->cursor_y = bytestream2_get_le32(&ctx->gbc);

        /* Load a full cursor sprite */
        if (action == 3) {
            ret = tdsc_load_cursor(avctx);
            /* Do not consider cursor errors fatal unless in explode mode */
            if (ret < 0 && (avctx->err_recognition & AV_EF_EXPLODE))
                return ret;
        }
    } else {
        avpriv_request_sample(avctx, "Cursor action %d", action);
    }

    return 0;
}

__attribute__((used)) static int tdsc_decode_frame(AVCodecContext *avctx, void *data,
                             int *got_frame, AVPacket *avpkt)
{
    TDSCContext *ctx = avctx->priv_data;
    AVFrame *frame = data;
    int ret, tag_header, keyframe = 0;
    uLongf dlen;

    /* Resize deflate buffer on resolution change */
    if (ctx->width != avctx->width || ctx->height != avctx->height) {
        ctx->deflatelen = avctx->width * avctx->height * (3 + 1);
        ret = av_reallocp(&ctx->deflatebuffer, ctx->deflatelen);
        if (ret < 0)
            return ret;
    }
    dlen = ctx->deflatelen;

    /* Frames are deflated, need to inflate them first */
    ret = uncompress(ctx->deflatebuffer, &dlen, avpkt->data, avpkt->size);
    if (ret) {
        av_log(avctx, AV_LOG_ERROR, "Deflate error %d.\n", ret);
        return AVERROR_UNKNOWN;
    }

    bytestream2_init(&ctx->gbc, ctx->deflatebuffer, dlen);

    /* Check for tag and for size info */
    if (bytestream2_get_bytes_left(&ctx->gbc) < 4 + 4) {
        av_log(avctx, AV_LOG_ERROR, "Frame is too small.\n");
        return AVERROR_INVALIDDATA;
    }

    /* Read tag */
    tag_header = bytestream2_get_le32(&ctx->gbc);

    if (tag_header == MKTAG('T','D','S','F')) {
        int number_tiles;
        if (bytestream2_get_bytes_left(&ctx->gbc) < TDSF_HEADER_SIZE) {
            av_log(avctx, AV_LOG_ERROR, "TDSF tag is too small.\n");
            return AVERROR_INVALIDDATA;
        }
        /* First 4 bytes here are the number of GEPJ/WAR tiles in this frame */
        number_tiles = bytestream2_get_le32(&ctx->gbc);

        bytestream2_skip(&ctx->gbc, 4); // internal timestamp maybe?
        keyframe = bytestream2_get_le32(&ctx->gbc) == 0x30;

        ret = tdsc_parse_tdsf(avctx, number_tiles);
        if (ret < 0)
            return ret;

        /* Check if there is anything else we are able to parse */
        if (bytestream2_get_bytes_left(&ctx->gbc) >= 4 + 4)
            tag_header = bytestream2_get_le32(&ctx->gbc);
    }

    /* This tag can be after a TDSF block or on its own frame */
    if (tag_header == MKTAG('D','T','S','M')) {
        /* First 4 bytes here are the total size in bytes for this frame */
        int tag_size = bytestream2_get_le32(&ctx->gbc);

        if (bytestream2_get_bytes_left(&ctx->gbc) < tag_size) {
            av_log(avctx, AV_LOG_ERROR, "DTSM tag is too small.\n");
            return AVERROR_INVALIDDATA;
        }

        ret = tdsc_parse_dtsm(avctx);
        if (ret < 0)
            return ret;
    }

    /* Get the output frame and copy the reference frame */
    ret = ff_get_buffer(avctx, frame, 0);
    if (ret < 0)
        return ret;

    ret = av_frame_copy(frame, ctx->refframe);
    if (ret < 0)
        return ret;

    /* Paint the cursor on the output frame */
    tdsc_paint_cursor(avctx, frame->data[0], frame->linesize[0]);

    /* Frame is ready to be output */
    if (keyframe) {
        frame->pict_type = AV_PICTURE_TYPE_I;
        frame->key_frame = 1;
    } else {
        frame->pict_type = AV_PICTURE_TYPE_P;
    }
    *got_frame = 1;

    return avpkt->size;
}

