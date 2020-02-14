#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_27__   TYPE_7__ ;
typedef  struct TYPE_26__   TYPE_6__ ;
typedef  struct TYPE_25__   TYPE_5__ ;
typedef  struct TYPE_24__   TYPE_4__ ;
typedef  struct TYPE_23__   TYPE_3__ ;
typedef  struct TYPE_22__   TYPE_2__ ;
typedef  struct TYPE_21__   TYPE_1__ ;

/* Type definitions */
struct mp_log {int dummy; } ;
struct TYPE_23__ {scalar_t__ levels; scalar_t__ space; int /*<<< orphan*/  gamma; int /*<<< orphan*/  primaries; } ;
struct mp_image_params {int imgfmt; int w; int h; int p_w; int p_h; int /*<<< orphan*/  chroma_location; TYPE_3__ color; } ;
struct mp_image {int /*<<< orphan*/  fmt; struct mp_image_params params; int /*<<< orphan*/ * stride; int /*<<< orphan*/ * planes; int /*<<< orphan*/  imgfmt; int /*<<< orphan*/  h; int /*<<< orphan*/  w; } ;
struct image_writer_opts {scalar_t__ format; } ;
struct TYPE_21__ {int id; } ;
struct image_writer_ctx {int /*<<< orphan*/  member_2; struct image_writer_opts const* member_1; struct mp_log* member_0; TYPE_2__* opts; TYPE_1__ original_format; } ;
struct AVCodec {scalar_t__ id; int* pix_fmts; } ;
typedef  struct mp_image mp_image_t ;
typedef  enum AVPixelFormat { ____Placeholder_AVPixelFormat } AVPixelFormat ;
struct TYPE_27__ {int value; scalar_t__ name; } ;
struct TYPE_26__ {int pix_fmt; int /*<<< orphan*/  color_range; int /*<<< orphan*/  height; int /*<<< orphan*/  width; int /*<<< orphan*/  compression_level; int /*<<< orphan*/  time_base; } ;
struct TYPE_25__ {scalar_t__ format; int /*<<< orphan*/  color_trc; int /*<<< orphan*/  color_primaries; int /*<<< orphan*/  color_range; int /*<<< orphan*/  height; int /*<<< orphan*/  width; int /*<<< orphan*/ * linesize; int /*<<< orphan*/ * data; } ;
struct TYPE_24__ {int /*<<< orphan*/  size; int /*<<< orphan*/  data; int /*<<< orphan*/  member_0; } ;
struct TYPE_22__ {int high_bit_depth; int /*<<< orphan*/  format; scalar_t__ tag_csp; int /*<<< orphan*/  png_filter; int /*<<< orphan*/  png_compression; } ;
typedef  int /*<<< orphan*/  FILE ;
typedef  TYPE_4__ AVPacket ;
typedef  TYPE_5__ AVFrame ;
typedef  TYPE_6__ AVCodecContext ;

/* Variables and functions */
 scalar_t__ AV_CODEC_ID_PNG ; 
 int /*<<< orphan*/  AV_OPT_SEARCH_CHILDREN ; 
 scalar_t__ AV_PIX_FMT_NONE ; 
#define  AV_PIX_FMT_YUV420P 130 
#define  AV_PIX_FMT_YUV422P 129 
#define  AV_PIX_FMT_YUV444P 128 
 int AV_PIX_FMT_YUVJ420P ; 
 int AV_PIX_FMT_YUVJ422P ; 
 int AV_PIX_FMT_YUVJ444P ; 
 int /*<<< orphan*/  AV_TIME_BASE_Q ; 
 int IMGFMT_RGB0 ; 
 int IMGFMT_RGB_DEPTH (int) ; 
 int /*<<< orphan*/  MP_CHROMA_CENTER ; 
 scalar_t__ MP_CSP_BT_601 ; 
 scalar_t__ MP_CSP_LEVELS_PC ; 
 scalar_t__ MP_CSP_RGB ; 
 int /*<<< orphan*/  MP_ERR (struct image_writer_ctx*,char*,...) ; 
 TYPE_5__* av_frame_alloc () ; 
 int /*<<< orphan*/  av_frame_free (TYPE_5__**) ; 
 int /*<<< orphan*/  av_init_packet (TYPE_4__*) ; 
 int /*<<< orphan*/  av_opt_set_int (TYPE_6__*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  av_packet_unref (TYPE_4__*) ; 
 TYPE_6__* avcodec_alloc_context3 (struct AVCodec*) ; 
 struct AVCodec* avcodec_find_encoder (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  avcodec_free_context (TYPE_6__**) ; 
 scalar_t__ avcodec_open2 (TYPE_6__*,struct AVCodec*,int /*<<< orphan*/ *) ; 
 int avcodec_receive_packet (TYPE_6__*,TYPE_4__*) ; 
 int avcodec_send_frame (TYPE_6__*,TYPE_5__*) ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (char const*,char*) ; 
 int /*<<< orphan*/  fwrite (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 struct image_writer_opts image_writer_opts_defaults ; 
 int imgfmt2pixfmt (int /*<<< orphan*/ ) ; 
 char const* m_opt_choice_str (TYPE_7__*,scalar_t__) ; 
 int /*<<< orphan*/  mp_csp_levels_to_avcol_range (scalar_t__) ; 
 int /*<<< orphan*/  mp_csp_prim_to_avcol_pri (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mp_csp_trc_to_avcol_trc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mp_err (struct mp_log*,char*,...) ; 
 struct mp_image* mp_image_alloc (int,int,int) ; 
 int /*<<< orphan*/  mp_image_copy_attributes (struct mp_image*,struct mp_image*) ; 
 struct mp_image* mp_image_new_ref (struct mp_image*) ; 
 scalar_t__ mp_image_params_equal (struct mp_image_params*,struct mp_image_params*) ; 
 int /*<<< orphan*/  mp_image_params_get_dsize (struct mp_image_params*,int*,int*) ; 
 int /*<<< orphan*/  mp_image_params_guess_csp (struct mp_image_params*) ; 
 scalar_t__ mp_image_swscale (struct mp_image*,struct mp_image*,int /*<<< orphan*/ ) ; 
 TYPE_7__* mp_image_writer_formats ; 
 int mp_imgfmt_select_best (int,int,int) ; 
 int /*<<< orphan*/  mp_imgfmt_to_name (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mp_sws_hq_flags ; 
 int pixfmt2imgfmt (int const) ; 
 scalar_t__ strcmp (scalar_t__,char const*) ; 
 int /*<<< orphan*/  talloc_free (struct mp_image*) ; 

__attribute__((used)) static enum AVPixelFormat replace_j_format(enum AVPixelFormat fmt)
{
    switch (fmt) {
    case AV_PIX_FMT_YUV420P: return AV_PIX_FMT_YUVJ420P;
    case AV_PIX_FMT_YUV422P: return AV_PIX_FMT_YUVJ422P;
    case AV_PIX_FMT_YUV444P: return AV_PIX_FMT_YUVJ444P;
    }
    return fmt;
}

__attribute__((used)) static bool write_lavc(struct image_writer_ctx *ctx, mp_image_t *image, FILE *fp)
{
    bool success = 0;
    AVFrame *pic = NULL;
    AVPacket pkt = {0};
    int got_output = 0;

    av_init_packet(&pkt);

    struct AVCodec *codec = avcodec_find_encoder(ctx->opts->format);
    AVCodecContext *avctx = NULL;
    if (!codec)
        goto print_open_fail;
    avctx = avcodec_alloc_context3(codec);
    if (!avctx)
        goto print_open_fail;

    avctx->time_base = AV_TIME_BASE_Q;
    avctx->width = image->w;
    avctx->height = image->h;
    avctx->color_range = mp_csp_levels_to_avcol_range(image->params.color.levels);
    avctx->pix_fmt = imgfmt2pixfmt(image->imgfmt);
    // Annoying deprecated garbage for the jpg encoder.
    if (image->params.color.levels == MP_CSP_LEVELS_PC)
        avctx->pix_fmt = replace_j_format(avctx->pix_fmt);
    if (avctx->pix_fmt == AV_PIX_FMT_NONE) {
        MP_ERR(ctx, "Image format %s not supported by lavc.\n",
               mp_imgfmt_to_name(image->imgfmt));
        goto error_exit;
    }
    if (codec->id == AV_CODEC_ID_PNG) {
        avctx->compression_level = ctx->opts->png_compression;
        av_opt_set_int(avctx, "pred", ctx->opts->png_filter,
                       AV_OPT_SEARCH_CHILDREN);
    }

    if (avcodec_open2(avctx, codec, NULL) < 0) {
     print_open_fail:
        MP_ERR(ctx, "Could not open libavcodec encoder for saving images\n");
        goto error_exit;
    }

    pic = av_frame_alloc();
    if (!pic)
        goto error_exit;
    for (int n = 0; n < 4; n++) {
        pic->data[n] = image->planes[n];
        pic->linesize[n] = image->stride[n];
    }
    pic->format = avctx->pix_fmt;
    pic->width = avctx->width;
    pic->height = avctx->height;
    pic->color_range = avctx->color_range;
    if (ctx->opts->tag_csp) {
        pic->color_primaries = mp_csp_prim_to_avcol_pri(image->params.color.primaries);
        pic->color_trc = mp_csp_trc_to_avcol_trc(image->params.color.gamma);
    }

    int ret = avcodec_send_frame(avctx, pic);
    if (ret < 0)
        goto error_exit;
    ret = avcodec_send_frame(avctx, NULL); // send EOF
    if (ret < 0)
        goto error_exit;
    ret = avcodec_receive_packet(avctx, &pkt);
    if (ret < 0)
        goto error_exit;
    got_output = 1;

    fwrite(pkt.data, pkt.size, 1, fp);

    success = !!got_output;
error_exit:
    avcodec_free_context(&avctx);
    av_frame_free(&pic);
    av_packet_unref(&pkt);
    return success;
}

__attribute__((used)) static int get_encoder_format(struct AVCodec *codec, int srcfmt, bool highdepth)
{
    const enum AVPixelFormat *pix_fmts = codec->pix_fmts;
    int current = 0;
    for (int n = 0; pix_fmts && pix_fmts[n] != AV_PIX_FMT_NONE; n++) {
        int fmt = pixfmt2imgfmt(pix_fmts[n]);
        if (!fmt)
            continue;
        // Ignore formats larger than 8 bit per pixel.
        if (!highdepth && IMGFMT_RGB_DEPTH(fmt) > 32)
            continue;
        current = current ? mp_imgfmt_select_best(current, fmt, srcfmt) : fmt;
    }
    return current;
}

__attribute__((used)) static int get_target_format(struct image_writer_ctx *ctx)
{
    struct AVCodec *codec = avcodec_find_encoder(ctx->opts->format);
    if (!codec)
        goto unknown;

    int srcfmt = ctx->original_format.id;

    int target = get_encoder_format(codec, srcfmt, ctx->opts->high_bit_depth);
    if (!target)
        target = get_encoder_format(codec, srcfmt, true);

    if (!target)
        goto unknown;

    return target;

unknown:
    return IMGFMT_RGB0;
}

const char *image_writer_file_ext(const struct image_writer_opts *opts)
{
    struct image_writer_opts defs = image_writer_opts_defaults;

    if (!opts)
        opts = &defs;

    return m_opt_choice_str(mp_image_writer_formats, opts->format);
}

bool image_writer_high_depth(const struct image_writer_opts *opts)
{
    return opts->format == AV_CODEC_ID_PNG;
}

int image_writer_format_from_ext(const char *ext)
{
    for (int n = 0; mp_image_writer_formats[n].name; n++) {
        if (ext && strcmp(mp_image_writer_formats[n].name, ext) == 0)
            return mp_image_writer_formats[n].value;
    }
    return 0;
}

struct mp_image *convert_image(struct mp_image *image, int destfmt,
                               struct mp_log *log)
{
    int d_w, d_h;
    mp_image_params_get_dsize(&image->params, &d_w, &d_h);

    struct mp_image_params p = {
        .imgfmt = destfmt,
        .w = d_w,
        .h = d_h,
        .p_w = 1,
        .p_h = 1,
    };
    mp_image_params_guess_csp(&p);

    // If RGB, just assume everything is correct.
    if (p.color.space != MP_CSP_RGB) {
        // Currently, assume what FFmpeg's jpg encoder needs.
        // Of course this works only for non-HDR (no HDR support in libswscale).
        p.color.levels = MP_CSP_LEVELS_PC;
        p.color.space = MP_CSP_BT_601;
        p.chroma_location = MP_CHROMA_CENTER;
        mp_image_params_guess_csp(&p);
    }

    if (mp_image_params_equal(&p, &image->params))
        return mp_image_new_ref(image);

    struct mp_image *dst = mp_image_alloc(p.imgfmt, p.w, p.h);
    if (!dst) {
        mp_err(log, "Out of memory.\n");
        return NULL;
    }
    mp_image_copy_attributes(dst, image);

    dst->params = p;

    if (mp_image_swscale(dst, image, mp_sws_hq_flags) < 0) {
        mp_err(log, "Error when converting image.\n");
        talloc_free(dst);
        return NULL;
    }

    return dst;
}

bool write_image(struct mp_image *image, const struct image_writer_opts *opts,
                const char *filename, struct mp_log *log)
{
    struct image_writer_opts defs = image_writer_opts_defaults;
    if (!opts)
        opts = &defs;

    struct image_writer_ctx ctx = { log, opts, image->fmt };
    bool (*write)(struct image_writer_ctx *, mp_image_t *, FILE *) = write_lavc;
    int destfmt = 0;

#if HAVE_JPEG
    if (opts->format == AV_CODEC_ID_MJPEG) {
        write = write_jpeg;
        destfmt = IMGFMT_RGB24;
    }
#endif

    if (!destfmt)
        destfmt = get_target_format(&ctx);

    struct mp_image *dst = convert_image(image, destfmt, log);
    if (!dst)
        return false;

    FILE *fp = fopen(filename, "wb");
    bool success = false;
    if (fp == NULL) {
        mp_err(log, "Error opening '%s' for writing!\n", filename);
    } else {
        success = write(&ctx, dst, fp);
        success = !fclose(fp) && success;
        if (!success)
            mp_err(log, "Error writing file '%s'!\n", filename);
    }

    talloc_free(dst);
    return success;
}

void dump_png(struct mp_image *image, const char *filename, struct mp_log *log)
{
    struct image_writer_opts opts = image_writer_opts_defaults;
    opts.format = AV_CODEC_ID_PNG;
    write_image(image, &opts, filename, log);
}

