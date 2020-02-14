#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_47__   TYPE_9__ ;
typedef  struct TYPE_46__   TYPE_8__ ;
typedef  struct TYPE_45__   TYPE_7__ ;
typedef  struct TYPE_44__   TYPE_6__ ;
typedef  struct TYPE_43__   TYPE_5__ ;
typedef  struct TYPE_42__   TYPE_4__ ;
typedef  struct TYPE_41__   TYPE_3__ ;
typedef  struct TYPE_40__   TYPE_2__ ;
typedef  struct TYPE_39__   TYPE_1__ ;
typedef  struct TYPE_38__   TYPE_12__ ;
typedef  struct TYPE_37__   TYPE_10__ ;

/* Type definitions */
typedef  char uint8_t ;
typedef  unsigned int uint16_t ;
typedef  int /*<<< orphan*/  opj_stream_t ;
struct TYPE_41__ {int numcomps; int color_space; int x1; int x0; int y1; int y0; TYPE_1__* comps; } ;
typedef  TYPE_3__ opj_image_t ;
typedef  int /*<<< orphan*/  opj_codec_t ;
typedef  enum AVPixelFormat { ____Placeholder_AVPixelFormat } AVPixelFormat ;
struct TYPE_42__ {void* f; } ;
typedef  TYPE_4__ ThreadFrame ;
struct TYPE_47__ {int height; int width; char** data; int* linesize; int format; int key_frame; int /*<<< orphan*/  pict_type; } ;
struct TYPE_46__ {char* data; int size; } ;
struct TYPE_45__ {int nb_components; int log2_chroma_w; int log2_chroma_h; TYPE_2__* comp; } ;
struct TYPE_44__ {scalar_t__ pos; scalar_t__ size; int buffer; int member_1; char* member_2; int /*<<< orphan*/  member_0; } ;
struct TYPE_38__ {int /*<<< orphan*/  cp_reduce; int /*<<< orphan*/  cp_layer; } ;
struct TYPE_43__ {TYPE_12__ dec_params; int /*<<< orphan*/  lowqual; } ;
struct TYPE_40__ {int depth; int plane; int shift; int step; } ;
struct TYPE_39__ {int prec; int dx; int dy; int sgnd; int* data; int h; int w; } ;
struct TYPE_37__ {int pix_fmt; scalar_t__ bits_per_raw_sample; int /*<<< orphan*/  lowres; TYPE_5__* priv_data; } ;
typedef  int OPJ_SIZE_T ;
typedef  int OPJ_OFF_T ;
typedef  int /*<<< orphan*/  OPJ_BOOL ;
typedef  TYPE_5__ LibOpenJPEGContext ;
typedef  TYPE_6__ BufferReader ;
typedef  TYPE_7__ AVPixFmtDescriptor ;
typedef  TYPE_8__ AVPacket ;
typedef  TYPE_9__ AVFrame ;
typedef  TYPE_10__ AVCodecContext ;

/* Variables and functions */
 int AVERROR_EXTERNAL ; 
 int AVERROR_INVALIDDATA ; 
 int AVERROR_PATCHWELCOME ; 
 int AVERROR_UNKNOWN ; 
 int /*<<< orphan*/  AV_LOG_DEBUG ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_LOG_WARNING ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_I ; 
 int AV_PIX_FMT_GRAY16 ; 
 int AV_PIX_FMT_NONE ; 
 int AV_RB32 (char*) ; 
 int FFMAX (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FFMIN (int,int) ; 
 int FF_ARRAY_ELEMS (int*) ; 
 int JP2_SIG_TYPE ; 
 int JP2_SIG_VALUE ; 
#define  OPJ_CLRSPC_GRAY 130 
#define  OPJ_CLRSPC_SRGB 129 
#define  OPJ_CLRSPC_SYCC 128 
 int /*<<< orphan*/  OPJ_CODEC_J2K ; 
 int /*<<< orphan*/  OPJ_CODEC_JP2 ; 
 int /*<<< orphan*/  OPJ_FALSE ; 
 int /*<<< orphan*/  OPJ_STREAM_READ ; 
 int /*<<< orphan*/  OPJ_TRUE ; 
 int /*<<< orphan*/  av_log (TYPE_10__*,int /*<<< orphan*/ ,char*,...) ; 
 TYPE_7__* av_pix_fmt_desc_get (int) ; 
 int /*<<< orphan*/  avpriv_report_missing_feature (TYPE_10__*,char*,int) ; 
 int ff_set_dimensions (TYPE_10__*,int,int) ; 
 int ff_thread_get_buffer (TYPE_10__*,TYPE_4__*,int /*<<< orphan*/ ) ; 
 int* libopenjpeg_all_pix_fmts ; 
 int* libopenjpeg_gray_pix_fmts ; 
 int* libopenjpeg_rgb_pix_fmts ; 
 int* libopenjpeg_yuv_pix_fmts ; 
 int /*<<< orphan*/  memcpy (void*,int,int) ; 
 int /*<<< orphan*/ * opj_create_decompress (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  opj_decode (int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_3__*) ; 
 int /*<<< orphan*/  opj_destroy_codec (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  opj_image_destroy (TYPE_3__*) ; 
 int /*<<< orphan*/  opj_read_header (int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_3__**) ; 
 int /*<<< orphan*/  opj_set_error_handler (int /*<<< orphan*/ *,void (*) (char const*,void*),TYPE_10__*) ; 
 int /*<<< orphan*/  opj_set_info_handler (int /*<<< orphan*/ *,void (*) (char const*,void*),TYPE_10__*) ; 
 int /*<<< orphan*/  opj_set_warning_handler (int /*<<< orphan*/ *,void (*) (char const*,void*),TYPE_10__*) ; 
 int /*<<< orphan*/  opj_setup_decoder (int /*<<< orphan*/ *,TYPE_12__*) ; 
 int /*<<< orphan*/ * opj_stream_default_create (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  opj_stream_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  opj_stream_set_read_function (int /*<<< orphan*/ *,int (*) (void*,int,void*)) ; 
 int /*<<< orphan*/  opj_stream_set_seek_function (int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*)) ; 
 int /*<<< orphan*/  opj_stream_set_skip_function (int /*<<< orphan*/ *,int (*) (int,void*)) ; 
 int /*<<< orphan*/  opj_stream_set_user_data (int /*<<< orphan*/ *,TYPE_6__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  opj_stream_set_user_data_length (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static void error_callback(const char *msg, void *data)
{
    av_log(data, AV_LOG_ERROR, "%s", msg);
}

__attribute__((used)) static void warning_callback(const char *msg, void *data)
{
    av_log(data, AV_LOG_WARNING, "%s", msg);
}

__attribute__((used)) static void info_callback(const char *msg, void *data)
{
    av_log(data, AV_LOG_DEBUG, "%s", msg);
}

__attribute__((used)) static OPJ_SIZE_T stream_read(void *out_buffer, OPJ_SIZE_T nb_bytes, void *user_data)
{
    BufferReader *reader = user_data;
    int remaining;

    if (reader->pos == reader->size) {
        return (OPJ_SIZE_T)-1;
    }
    remaining = reader->size - reader->pos;
    if (nb_bytes > remaining) {
        nb_bytes = remaining;
    }
    memcpy(out_buffer, reader->buffer + reader->pos, nb_bytes);
    reader->pos += (int)nb_bytes;
    return nb_bytes;
}

__attribute__((used)) static OPJ_OFF_T stream_skip(OPJ_OFF_T nb_bytes, void *user_data)
{
    BufferReader *reader = user_data;
    if (nb_bytes < 0) {
        if (reader->pos == 0) {
            return (OPJ_SIZE_T)-1;
        }
        if (nb_bytes + reader->pos < 0) {
            nb_bytes = -reader->pos;
        }
    } else {
        int remaining;

        if (reader->pos == reader->size) {
            return (OPJ_SIZE_T)-1;
        }
        remaining = reader->size - reader->pos;
        if (nb_bytes > remaining) {
            nb_bytes = remaining;
        }
    }
    reader->pos += (int)nb_bytes;
    return nb_bytes;
}

__attribute__((used)) static OPJ_BOOL stream_seek(OPJ_OFF_T nb_bytes, void *user_data)
{
    BufferReader *reader = user_data;
    if (nb_bytes < 0 || nb_bytes > reader->size) {
        return OPJ_FALSE;
    }
    reader->pos = (int)nb_bytes;
    return OPJ_TRUE;
}

__attribute__((used)) static inline int libopenjpeg_matches_pix_fmt(const opj_image_t *image, enum AVPixelFormat pix_fmt)
{
    const AVPixFmtDescriptor *desc = av_pix_fmt_desc_get(pix_fmt);
    int match = 1;

    if (desc->nb_components != image->numcomps) {
        return 0;
    }

    switch (desc->nb_components) {
    case 4:
        match = match &&
                desc->comp[3].depth >= image->comps[3].prec &&
                1 == image->comps[3].dx &&
                1 == image->comps[3].dy;
    case 3:
        match = match &&
                desc->comp[2].depth >= image->comps[2].prec &&
                1 << desc->log2_chroma_w == image->comps[2].dx &&
                1 << desc->log2_chroma_h == image->comps[2].dy;
    case 2:
        match = match &&
                desc->comp[1].depth >= image->comps[1].prec &&
                1 << desc->log2_chroma_w == image->comps[1].dx &&
                1 << desc->log2_chroma_h == image->comps[1].dy;
    case 1:
        match = match &&
                desc->comp[0].depth >= image->comps[0].prec &&
                1 == image->comps[0].dx &&
                1 == image->comps[0].dy;
    default:
        break;
    }

    return match;
}

__attribute__((used)) static inline enum AVPixelFormat libopenjpeg_guess_pix_fmt(const opj_image_t *image) {
    int index;
    const enum AVPixelFormat *possible_fmts = NULL;
    int possible_fmts_nb = 0;

    switch (image->color_space) {
    case OPJ_CLRSPC_SRGB:
        possible_fmts    = libopenjpeg_rgb_pix_fmts;
        possible_fmts_nb = FF_ARRAY_ELEMS(libopenjpeg_rgb_pix_fmts);
        break;
    case OPJ_CLRSPC_GRAY:
        possible_fmts    = libopenjpeg_gray_pix_fmts;
        possible_fmts_nb = FF_ARRAY_ELEMS(libopenjpeg_gray_pix_fmts);
        break;
    case OPJ_CLRSPC_SYCC:
        possible_fmts    = libopenjpeg_yuv_pix_fmts;
        possible_fmts_nb = FF_ARRAY_ELEMS(libopenjpeg_yuv_pix_fmts);
        break;
    default:
        possible_fmts    = libopenjpeg_all_pix_fmts;
        possible_fmts_nb = FF_ARRAY_ELEMS(libopenjpeg_all_pix_fmts);
        break;
    }

    for (index = 0; index < possible_fmts_nb; ++index)
        if (libopenjpeg_matches_pix_fmt(image, possible_fmts[index])) {
            return possible_fmts[index];
        }

    return AV_PIX_FMT_NONE;
}

__attribute__((used)) static inline int libopenjpeg_ispacked(enum AVPixelFormat pix_fmt)
{
    const AVPixFmtDescriptor *desc = av_pix_fmt_desc_get(pix_fmt);
    int i, component_plane;

    if (pix_fmt == AV_PIX_FMT_GRAY16)
        return 0;

    component_plane = desc->comp[0].plane;
    for (i = 1; i < desc->nb_components; i++)
        if (component_plane != desc->comp[i].plane)
            return 0;
    return 1;
}

__attribute__((used)) static inline void libopenjpeg_copy_to_packed8(AVFrame *picture, opj_image_t *image) {
    uint8_t *img_ptr;
    int index, x, y, c;
    for (y = 0; y < picture->height; y++) {
        index   = y * picture->width;
        img_ptr = picture->data[0] + y * picture->linesize[0];
        for (x = 0; x < picture->width; x++, index++)
            for (c = 0; c < image->numcomps; c++)
                *img_ptr++ = 0x80 * image->comps[c].sgnd + image->comps[c].data[index];
    }
}

__attribute__((used)) static inline void libopenjpeg_copy_to_packed16(AVFrame *picture, opj_image_t *image) {
    uint16_t *img_ptr;
    const AVPixFmtDescriptor *desc = av_pix_fmt_desc_get(picture->format);
    int index, x, y, c;
    int adjust[4];
    for (x = 0; x < image->numcomps; x++)
        adjust[x] = FFMAX(FFMIN(desc->comp[x].depth - image->comps[x].prec, 8), 0) + desc->comp[x].shift;

    for (y = 0; y < picture->height; y++) {
        index   = y * picture->width;
        img_ptr = (uint16_t *) (picture->data[0] + y * picture->linesize[0]);
        for (x = 0; x < picture->width; x++, index++)
            for (c = 0; c < image->numcomps; c++)
                *img_ptr++ = (1 << image->comps[c].prec - 1) * image->comps[c].sgnd +
                             (unsigned)image->comps[c].data[index] << adjust[c];
    }
}

__attribute__((used)) static inline void libopenjpeg_copyto8(AVFrame *picture, opj_image_t *image) {
    int *comp_data;
    uint8_t *img_ptr;
    int index, x, y;

    for (index = 0; index < image->numcomps; index++) {
        comp_data = image->comps[index].data;
        for (y = 0; y < image->comps[index].h; y++) {
            img_ptr = picture->data[index] + y * picture->linesize[index];
            for (x = 0; x < image->comps[index].w; x++) {
                *img_ptr = 0x80 * image->comps[index].sgnd + *comp_data;
                img_ptr++;
                comp_data++;
            }
        }
    }
}

__attribute__((used)) static inline void libopenjpeg_copyto16(AVFrame *picture, opj_image_t *image) {
    int *comp_data;
    uint16_t *img_ptr;
    const AVPixFmtDescriptor *desc = av_pix_fmt_desc_get(picture->format);
    int index, x, y;
    int adjust[4];
    for (x = 0; x < image->numcomps; x++)
        adjust[x] = FFMAX(FFMIN(desc->comp[x].depth - image->comps[x].prec, 8), 0) + desc->comp[x].shift;

    for (index = 0; index < image->numcomps; index++) {
        comp_data = image->comps[index].data;
        for (y = 0; y < image->comps[index].h; y++) {
            img_ptr = (uint16_t *)(picture->data[index] + y * picture->linesize[index]);
            for (x = 0; x < image->comps[index].w; x++) {
                *img_ptr = (1 << image->comps[index].prec - 1) * image->comps[index].sgnd +
                           (unsigned)*comp_data << adjust[index];
                img_ptr++;
                comp_data++;
            }
        }
    }
}

__attribute__((used)) static int libopenjpeg_decode_frame(AVCodecContext *avctx,
                                    void *data, int *got_frame,
                                    AVPacket *avpkt)
{
    uint8_t *buf            = avpkt->data;
    int buf_size            = avpkt->size;
    LibOpenJPEGContext *ctx = avctx->priv_data;
    ThreadFrame frame       = { .f = data };
    AVFrame *picture        = data;
    const AVPixFmtDescriptor *desc;
    int width, height, ret;
    int pixel_size = 0;
    int ispacked   = 0;
    int i;
    opj_image_t *image = NULL;
    BufferReader reader = {0, avpkt->size, avpkt->data};
    opj_codec_t *dec = NULL;
    opj_stream_t *stream = NULL;

    *got_frame = 0;

    // Check if input is a raw jpeg2k codestream or in jp2 wrapping
    if ((AV_RB32(buf) == 12) &&
        (AV_RB32(buf + 4) == JP2_SIG_TYPE) &&
        (AV_RB32(buf + 8) == JP2_SIG_VALUE)) {
        dec = opj_create_decompress(OPJ_CODEC_JP2);
    } else {
        /* If the AVPacket contains a jp2c box, then skip to
         * the starting byte of the codestream. */
        if (AV_RB32(buf + 4) == AV_RB32("jp2c"))
            buf += 8;
        dec = opj_create_decompress(OPJ_CODEC_J2K);
    }

    if (!dec) {
        av_log(avctx, AV_LOG_ERROR, "Error initializing decoder.\n");
        ret = AVERROR_EXTERNAL;
        goto done;
    }

    if (!opj_set_error_handler(dec, error_callback, avctx) ||
        !opj_set_warning_handler(dec, warning_callback, avctx) ||
        !opj_set_info_handler(dec, info_callback, avctx)) {
        av_log(avctx, AV_LOG_ERROR, "Error setting decoder handlers.\n");
        ret = AVERROR_EXTERNAL;
        goto done;
    }

    ctx->dec_params.cp_layer = ctx->lowqual;
    ctx->dec_params.cp_reduce = avctx->lowres;

    // Tie decoder with decoding parameters
    opj_setup_decoder(dec, &ctx->dec_params);

    stream = opj_stream_default_create(OPJ_STREAM_READ);

    if (!stream) {
        av_log(avctx, AV_LOG_ERROR,
               "Codestream could not be opened for reading.\n");
        ret = AVERROR_EXTERNAL;
        goto done;
    }

    opj_stream_set_read_function(stream, stream_read);
    opj_stream_set_skip_function(stream, stream_skip);
    opj_stream_set_seek_function(stream, stream_seek);
    opj_stream_set_user_data(stream, &reader, NULL);
    opj_stream_set_user_data_length(stream, avpkt->size);
    // Decode the header only.
    ret = !opj_read_header(stream, dec, &image);

    if (ret) {
        av_log(avctx, AV_LOG_ERROR, "Error decoding codestream header.\n");
        ret = AVERROR_EXTERNAL;
        goto done;
    }

    width  = image->x1 - image->x0;
    height = image->y1 - image->y0;

    ret = ff_set_dimensions(avctx, width, height);
    if (ret < 0)
        goto done;

    if (avctx->pix_fmt != AV_PIX_FMT_NONE)
        if (!libopenjpeg_matches_pix_fmt(image, avctx->pix_fmt))
            avctx->pix_fmt = AV_PIX_FMT_NONE;

    if (avctx->pix_fmt == AV_PIX_FMT_NONE)
        avctx->pix_fmt = libopenjpeg_guess_pix_fmt(image);

    if (avctx->pix_fmt == AV_PIX_FMT_NONE) {
        av_log(avctx, AV_LOG_ERROR, "Unable to determine pixel format.\n");
        ret = AVERROR_UNKNOWN;
        goto done;
    }
    for (i = 0; i < image->numcomps; i++)
        if (image->comps[i].prec > avctx->bits_per_raw_sample)
            avctx->bits_per_raw_sample = image->comps[i].prec;

    if ((ret = ff_thread_get_buffer(avctx, &frame, 0)) < 0)
        goto done;

    ret = !opj_decode(dec, stream, image);

    if (ret) {
        av_log(avctx, AV_LOG_ERROR, "Error decoding codestream.\n");
        ret = AVERROR_EXTERNAL;
        goto done;
    }

    for (i = 0; i < image->numcomps; i++) {
        if (!image->comps[i].data) {
            av_log(avctx, AV_LOG_ERROR,
                   "Image component %d contains no data.\n", i);
            ret = AVERROR_INVALIDDATA;
            goto done;
        }
    }

    desc       = av_pix_fmt_desc_get(avctx->pix_fmt);
    pixel_size = desc->comp[0].step;
    ispacked   = libopenjpeg_ispacked(avctx->pix_fmt);

    switch (pixel_size) {
    case 1:
        if (ispacked) {
            libopenjpeg_copy_to_packed8(picture, image);
        } else {
            libopenjpeg_copyto8(picture, image);
        }
        break;
    case 2:
        if (ispacked) {
            libopenjpeg_copy_to_packed8(picture, image);
        } else {
            libopenjpeg_copyto16(picture, image);
        }
        break;
    case 3:
    case 4:
        if (ispacked) {
            libopenjpeg_copy_to_packed8(picture, image);
        }
        break;
    case 6:
    case 8:
        if (ispacked) {
            libopenjpeg_copy_to_packed16(picture, image);
        }
        break;
    default:
        avpriv_report_missing_feature(avctx, "Pixel size %d", pixel_size);
        ret = AVERROR_PATCHWELCOME;
        goto done;
    }

    *got_frame = 1;
    picture->pict_type = AV_PICTURE_TYPE_I;
    picture->key_frame = 1;
    ret        = buf_size;

done:
    opj_image_destroy(image);
    opj_stream_destroy(stream);
    opj_destroy_codec(dec);
    return ret;
}

