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
struct TYPE_22__ {scalar_t__ codec_type; scalar_t__ codec_id; scalar_t__ format; int width; int /*<<< orphan*/  height; } ;
struct TYPE_21__ {int nb_streams; TYPE_2__* priv_data; int /*<<< orphan*/  url; TYPE_3__** streams; } ;
struct TYPE_20__ {int /*<<< orphan*/  data; } ;
struct TYPE_19__ {TYPE_1__* codec; TYPE_6__* codecpar; } ;
struct TYPE_18__ {int /*<<< orphan*/ * display; int /*<<< orphan*/ * dither; scalar_t__ window_height; scalar_t__ window_width; int /*<<< orphan*/ * canvas; scalar_t__ window_title; int /*<<< orphan*/  driver; int /*<<< orphan*/  color; int /*<<< orphan*/  charset; int /*<<< orphan*/  antialias; int /*<<< orphan*/  algorithm; int /*<<< orphan*/  list_dither; scalar_t__ list_drivers; TYPE_5__* ctx; } ;
struct TYPE_17__ {int /*<<< orphan*/  time_base; } ;
typedef  TYPE_2__ CACAContext ;
typedef  TYPE_3__ AVStream ;
typedef  TYPE_4__ AVPacket ;
typedef  TYPE_5__ AVFormatContext ;
typedef  TYPE_6__ AVCodecParameters ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_EXIT ; 
 scalar_t__ AVMEDIA_TYPE_VIDEO ; 
 scalar_t__ AV_CODEC_ID_RAWVIDEO ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_LOG_INFO ; 
 scalar_t__ AV_PIX_FMT_RGB24 ; 
 int /*<<< orphan*/  AV_TIME_BASE_Q ; 
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  av_freep (scalar_t__*) ; 
 int av_get_bits_per_pixel (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  av_get_pix_fmt_name (scalar_t__) ; 
 int /*<<< orphan*/  av_log (TYPE_5__*,int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  av_pix_fmt_desc_get (scalar_t__) ; 
 int /*<<< orphan*/  av_rescale_q (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ av_strdup (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * caca_create_canvas (scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/ * caca_create_display_with_driver (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * caca_create_dither (int,int,int /*<<< orphan*/ ,int,int,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  caca_dither_bitmap (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  caca_free_canvas (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  caca_free_display (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  caca_free_dither (int /*<<< orphan*/ *) ; 
 scalar_t__ caca_get_canvas_height (int /*<<< orphan*/ *) ; 
 scalar_t__ caca_get_canvas_width (int /*<<< orphan*/ *) ; 
 char** caca_get_display_driver_list () ; 
 int /*<<< orphan*/  caca_refresh_display (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  caca_set_display_time (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  caca_set_display_title (int /*<<< orphan*/ *,scalar_t__) ; 
 scalar_t__ caca_set_dither_algorithm (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ caca_set_dither_antialias (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ caca_set_dither_charset (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ caca_set_dither_color (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  errno ; 
 int /*<<< orphan*/  list_dither_algorithm (TYPE_2__*) ; 
 int /*<<< orphan*/  list_dither_antialias (TYPE_2__*) ; 
 int /*<<< orphan*/  list_dither_charset (TYPE_2__*) ; 
 int /*<<< orphan*/  list_dither_color (TYPE_2__*) ; 
 int /*<<< orphan*/  strcmp (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static int caca_write_trailer(AVFormatContext *s)
{
    CACAContext *c = s->priv_data;

    av_freep(&c->window_title);

    if (c->display) {
        caca_free_display(c->display);
        c->display = NULL;
    }
    if (c->dither) {
        caca_free_dither(c->dither);
        c->dither = NULL;
    }
    if (c->canvas) {
        caca_free_canvas(c->canvas);
        c->canvas = NULL;
    }
    return 0;
}

__attribute__((used)) static void list_drivers(CACAContext *c)
{
    const char *const *drivers = caca_get_display_driver_list();
    int i;

    av_log(c->ctx, AV_LOG_INFO, "Available drivers:\n");
    for (i = 0; drivers[i]; i += 2)
        av_log(c->ctx, AV_LOG_INFO, "%s: %s\n", drivers[i], drivers[i + 1]);
}

__attribute__((used)) static int caca_write_header(AVFormatContext *s)
{
    CACAContext *c = s->priv_data;
    AVStream *st = s->streams[0];
    AVCodecParameters *encctx = st->codecpar;
    int ret, bpp;

    c->ctx = s;
    if (c->list_drivers) {
        list_drivers(c);
        return AVERROR_EXIT;
    }
    if (c->list_dither) {
        if (!strcmp(c->list_dither, "colors")) {
            list_dither_color(c);
        } else if (!strcmp(c->list_dither, "charsets")) {
            list_dither_charset(c);
        } else if (!strcmp(c->list_dither, "algorithms")) {
            list_dither_algorithm(c);
        } else if (!strcmp(c->list_dither, "antialiases")) {
            list_dither_antialias(c);
        } else {
            av_log(s, AV_LOG_ERROR,
                   "Invalid argument '%s', for 'list_dither' option\n"
                   "Argument must be one of 'algorithms, 'antialiases', 'charsets', 'colors'\n",
                   c->list_dither);
            return AVERROR(EINVAL);
        }
        return AVERROR_EXIT;
    }

    if (   s->nb_streams > 1
        || encctx->codec_type != AVMEDIA_TYPE_VIDEO
        || encctx->codec_id   != AV_CODEC_ID_RAWVIDEO) {
        av_log(s, AV_LOG_ERROR, "Only supports one rawvideo stream\n");
        return AVERROR(EINVAL);
    }

    if (encctx->format != AV_PIX_FMT_RGB24) {
        av_log(s, AV_LOG_ERROR,
               "Unsupported pixel format '%s', choose rgb24\n",
               av_get_pix_fmt_name(encctx->format));
        return AVERROR(EINVAL);
    }

    c->canvas = caca_create_canvas(c->window_width, c->window_height);
    if (!c->canvas) {
        ret = AVERROR(errno);
        av_log(s, AV_LOG_ERROR, "Failed to create canvas\n");
        goto fail;
    }

    bpp = av_get_bits_per_pixel(av_pix_fmt_desc_get(encctx->format));
    c->dither = caca_create_dither(bpp, encctx->width, encctx->height,
                                   bpp / 8 * encctx->width,
                                   0x0000ff, 0x00ff00, 0xff0000, 0);
    if (!c->dither) {
        ret =  AVERROR(errno);
        av_log(s, AV_LOG_ERROR, "Failed to create dither\n");
        goto fail;
    }

#define CHECK_DITHER_OPT(opt) do {                                              \
    if (caca_set_dither_##opt(c->dither, c->opt) < 0)  {                        \
        ret = AVERROR(errno);                                                   \
        av_log(s, AV_LOG_ERROR, "Failed to set value '%s' for option '%s'\n",   \
               c->opt, #opt);                                                   \
        goto fail;                                                              \
    }                                                                           \
} while (0)

    CHECK_DITHER_OPT(algorithm);
    CHECK_DITHER_OPT(antialias);
    CHECK_DITHER_OPT(charset);
    CHECK_DITHER_OPT(color);

    c->display = caca_create_display_with_driver(c->canvas, c->driver);
    if (!c->display) {
        ret = AVERROR(errno);
        av_log(s, AV_LOG_ERROR, "Failed to create display\n");
        list_drivers(c);
        goto fail;
    }

    if (!c->window_width || !c->window_height) {
        c->window_width  = caca_get_canvas_width(c->canvas);
        c->window_height = caca_get_canvas_height(c->canvas);
    }

    if (!c->window_title)
        c->window_title = av_strdup(s->url);
    caca_set_display_title(c->display, c->window_title);
    caca_set_display_time(c->display, av_rescale_q(1, st->codec->time_base, AV_TIME_BASE_Q));

    return 0;

fail:
    caca_write_trailer(s);
    return ret;
}

__attribute__((used)) static int caca_write_packet(AVFormatContext *s, AVPacket *pkt)
{
    CACAContext *c = s->priv_data;

    caca_dither_bitmap(c->canvas, 0, 0, c->window_width, c->window_height, c->dither, pkt->data);
    caca_refresh_display(c->display);

    return 0;
}

