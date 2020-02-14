#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_7__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct mp_frame {scalar_t__ type; struct mp_image* data; } ;
struct TYPE_10__ {void* out; void* in; void* filter; struct mp_frame frame; } ;
struct rotate_priv {scalar_t__ prev_imgfmt; scalar_t__ prev_setting; int prev_rotate; int target_rotate; double cur_speed; TYPE_2__ sub; TYPE_7__* opts; } ;
struct mp_stream_info {scalar_t__ rotate90; } ;
struct TYPE_9__ {int rotate; } ;
struct mp_image {scalar_t__ imgfmt; TYPE_1__ params; } ;
struct mp_filter_command {scalar_t__ type; int is_active; double speed; } ;
struct mp_filter {struct rotate_priv* priv; int /*<<< orphan*/  global; } ;
struct filter_opts {scalar_t__ deinterlace; } ;
struct deint_priv {scalar_t__ prev_imgfmt; scalar_t__ prev_setting; int prev_rotate; int target_rotate; double cur_speed; TYPE_2__ sub; TYPE_7__* opts; } ;
struct aspeed_priv {scalar_t__ prev_imgfmt; scalar_t__ prev_setting; int prev_rotate; int target_rotate; double cur_speed; TYPE_2__ sub; TYPE_7__* opts; } ;
struct TYPE_11__ {struct filter_opts* opts; } ;

/* Variables and functions */
 scalar_t__ IMGFMT_CUDA ; 
 scalar_t__ IMGFMT_D3D11 ; 
 scalar_t__ IMGFMT_VAAPI ; 
 scalar_t__ IMGFMT_VDPAU ; 
 int /*<<< orphan*/  MP_ERR (struct mp_filter*,char*) ; 
 scalar_t__ MP_FILTER_COMMAND_IS_ACTIVE ; 
 scalar_t__ MP_FILTER_COMMAND_SET_SPEED ; 
 scalar_t__ MP_FRAME_VIDEO ; 
 int /*<<< orphan*/  MP_INFO (struct mp_filter*,char*) ; 
 int /*<<< orphan*/  MP_OUTPUT_CHAIN_AUDIO ; 
 int /*<<< orphan*/  MP_OUTPUT_CHAIN_VIDEO ; 
 int /*<<< orphan*/  MP_PIN_IN ; 
 int /*<<< orphan*/  MP_PIN_OUT ; 
 int /*<<< orphan*/  MP_VERBOSE (struct mp_filter*,char*) ; 
 int M_PI ; 
 int /*<<< orphan*/  TA_FREEP (void**) ; 
 int /*<<< orphan*/  aspeed_filter ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  deint_filter ; 
 int fabs (double) ; 
 int /*<<< orphan*/  filter_conf ; 
 TYPE_7__* m_config_cache_alloc (struct mp_filter*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  m_config_cache_update (TYPE_7__*) ; 
 void* mp_create_user_filter (struct mp_filter*,int /*<<< orphan*/ ,char*,char**) ; 
 void* mp_filter_add_pin (struct mp_filter*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  mp_filter_command (void*,struct mp_filter_command*) ; 
 struct mp_filter* mp_filter_create (struct mp_filter*,int /*<<< orphan*/ *) ; 
 struct mp_stream_info* mp_filter_find_stream_info (struct mp_filter*) ; 
 int /*<<< orphan*/  mp_filter_internal_mark_failed (struct mp_filter*) ; 
 scalar_t__ mp_frame_is_signaling (struct mp_frame) ; 
 int /*<<< orphan*/  mp_subfilter_continue (TYPE_2__*) ; 
 int /*<<< orphan*/  mp_subfilter_destroy (TYPE_2__*) ; 
 int /*<<< orphan*/  mp_subfilter_drain_destroy (TYPE_2__*) ; 
 int /*<<< orphan*/  mp_subfilter_read (TYPE_2__*) ; 
 int /*<<< orphan*/  mp_subfilter_reset (TYPE_2__*) ; 
 scalar_t__ mp_sws_supports_input (scalar_t__) ; 
 char* mp_tprintf (int,char*,double) ; 
 int /*<<< orphan*/  rotate_filter ; 

__attribute__((used)) static void deint_process(struct mp_filter *f)
{
    struct deint_priv *p = f->priv;

    if (!mp_subfilter_read(&p->sub))
        return;

    struct mp_frame frame = p->sub.frame;

    if (mp_frame_is_signaling(frame)) {
        mp_subfilter_continue(&p->sub);
        return;
    }

    if (frame.type != MP_FRAME_VIDEO) {
        MP_ERR(f, "video input required!\n");
        mp_filter_internal_mark_failed(f);
        return;
    }

    m_config_cache_update(p->opts);
    struct filter_opts *opts = p->opts->opts;

    if (!opts->deinterlace)
        mp_subfilter_destroy(&p->sub);

    struct mp_image *img = frame.data;

    if (img->imgfmt == p->prev_imgfmt && p->prev_setting == opts->deinterlace) {
        mp_subfilter_continue(&p->sub);
        return;
    }

    if (!mp_subfilter_drain_destroy(&p->sub))
        return;

    assert(!p->sub.filter);

    p->prev_imgfmt = img->imgfmt;
    p->prev_setting = opts->deinterlace;
    if (!p->prev_setting) {
        mp_subfilter_continue(&p->sub);
        return;
    }

    if (img->imgfmt == IMGFMT_VDPAU) {
        char *args[] = {"deint", "yes", NULL};
        p->sub.filter =
            mp_create_user_filter(f, MP_OUTPUT_CHAIN_VIDEO, "vdpaupp", args);
    } else if (img->imgfmt == IMGFMT_VAAPI) {
        p->sub.filter =
            mp_create_user_filter(f, MP_OUTPUT_CHAIN_VIDEO, "vavpp", NULL);
    } else if (img->imgfmt == IMGFMT_D3D11) {
        p->sub.filter =
            mp_create_user_filter(f, MP_OUTPUT_CHAIN_VIDEO, "d3d11vpp", NULL);
    } else if (img->imgfmt == IMGFMT_CUDA) {
        char *args[] = {"mode", "send_field", NULL};
        p->sub.filter =
            mp_create_user_filter(f, MP_OUTPUT_CHAIN_VIDEO, "yadif_cuda", args);
    } else if (mp_sws_supports_input(img->imgfmt)) {
        char *args[] = {"mode", "send_field", NULL};
        p->sub.filter =
            mp_create_user_filter(f, MP_OUTPUT_CHAIN_VIDEO, "yadif", args);
    } else {
        MP_ERR(f, "no deinterlace filter available for this format\n");
        mp_subfilter_continue(&p->sub);
        return;
    }

    if (!p->sub.filter)
        MP_ERR(f, "creating deinterlacer failed\n");

    mp_subfilter_continue(&p->sub);
}

__attribute__((used)) static void deint_reset(struct mp_filter *f)
{
    struct deint_priv *p = f->priv;

    mp_subfilter_reset(&p->sub);
}

__attribute__((used)) static void deint_destroy(struct mp_filter *f)
{
    struct deint_priv *p = f->priv;

    mp_subfilter_reset(&p->sub);
    TA_FREEP(&p->sub.filter);
}

__attribute__((used)) static bool deint_command(struct mp_filter *f, struct mp_filter_command *cmd)
{
    struct deint_priv *p = f->priv;

    if (cmd->type == MP_FILTER_COMMAND_IS_ACTIVE) {
        cmd->is_active = !!p->sub.filter;
        return true;
    }
    return false;
}

struct mp_filter *mp_deint_create(struct mp_filter *parent)
{
    struct mp_filter *f = mp_filter_create(parent, &deint_filter);
    if (!f)
        return NULL;

    struct deint_priv *p = f->priv;

    p->sub.in = mp_filter_add_pin(f, MP_PIN_IN, "in");
    p->sub.out = mp_filter_add_pin(f, MP_PIN_OUT, "out");

    p->opts = m_config_cache_alloc(f, f->global, &filter_conf);

    return f;
}

__attribute__((used)) static void rotate_process(struct mp_filter *f)
{
    struct rotate_priv *p = f->priv;

    if (!mp_subfilter_read(&p->sub))
        return;

    struct mp_frame frame = p->sub.frame;

    if (mp_frame_is_signaling(frame)) {
        mp_subfilter_continue(&p->sub);
        return;
    }

    if (frame.type != MP_FRAME_VIDEO) {
        MP_ERR(f, "video input required!\n");
        return;
    }

    struct mp_image *img = frame.data;

    if (img->params.rotate == p->prev_rotate &&
        img->imgfmt == p->prev_imgfmt)
    {
        img->params.rotate = p->target_rotate;
        mp_subfilter_continue(&p->sub);
        return;
    }

    if (!mp_subfilter_drain_destroy(&p->sub))
        return;

    assert(!p->sub.filter);

    int rotate = p->prev_rotate = img->params.rotate;
    p->target_rotate = rotate;
    p->prev_imgfmt = img->imgfmt;

    struct mp_stream_info *info = mp_filter_find_stream_info(f);
    if (rotate == 0 || (info && info->rotate90 && !(rotate % 90))) {
        mp_subfilter_continue(&p->sub);
        return;
    }

    if (!mp_sws_supports_input(img->imgfmt)) {
        MP_ERR(f, "Video rotation with this format not supported\n");
        mp_subfilter_continue(&p->sub);
        return;
    }

    double angle = rotate / 360.0 * M_PI * 2;
    char *args[] = {"angle", mp_tprintf(30, "%f", angle),
                    "ow", mp_tprintf(30, "rotw(%f)", angle),
                    "oh", mp_tprintf(30, "roth(%f)", angle),
                    NULL};
    p->sub.filter =
        mp_create_user_filter(f, MP_OUTPUT_CHAIN_VIDEO, "rotate", args);

    if (p->sub.filter) {
        MP_INFO(f, "Inserting rotation filter.\n");
        p->target_rotate = 0;
    } else {
        MP_ERR(f, "could not create rotation filter\n");
    }

    mp_subfilter_continue(&p->sub);
}

__attribute__((used)) static void rotate_reset(struct mp_filter *f)
{
    struct rotate_priv *p = f->priv;

    mp_subfilter_reset(&p->sub);
}

__attribute__((used)) static void rotate_destroy(struct mp_filter *f)
{
    struct rotate_priv *p = f->priv;

    mp_subfilter_reset(&p->sub);
    TA_FREEP(&p->sub.filter);
}

__attribute__((used)) static bool rotate_command(struct mp_filter *f, struct mp_filter_command *cmd)
{
    struct rotate_priv *p = f->priv;

    if (cmd->type == MP_FILTER_COMMAND_IS_ACTIVE) {
        cmd->is_active = !!p->sub.filter;
        return true;
    }
    return false;
}

struct mp_filter *mp_autorotate_create(struct mp_filter *parent)
{
    struct mp_filter *f = mp_filter_create(parent, &rotate_filter);
    if (!f)
        return NULL;

    struct rotate_priv *p = f->priv;
    p->prev_rotate = -1;

    p->sub.in = mp_filter_add_pin(f, MP_PIN_IN, "in");
    p->sub.out = mp_filter_add_pin(f, MP_PIN_OUT, "out");

    return f;
}

__attribute__((used)) static void aspeed_process(struct mp_filter *f)
{
    struct aspeed_priv *p = f->priv;

    if (!mp_subfilter_read(&p->sub))
        return;

    if (fabs(p->cur_speed - 1.0) < 1e-8) {
        if (p->sub.filter)
            MP_VERBOSE(f, "removing scaletempo\n");
        if (!mp_subfilter_drain_destroy(&p->sub))
            return;
    } else if (!p->sub.filter) {
        MP_VERBOSE(f, "adding scaletempo\n");
        p->sub.filter =
            mp_create_user_filter(f, MP_OUTPUT_CHAIN_AUDIO, "scaletempo", NULL);
        if (!p->sub.filter) {
            MP_ERR(f, "could not create scaletempo filter\n");
            mp_subfilter_continue(&p->sub);
            return;
        }
    }

    if (p->sub.filter) {
        struct mp_filter_command cmd = {
            .type = MP_FILTER_COMMAND_SET_SPEED,
            .speed = p->cur_speed,
        };
        mp_filter_command(p->sub.filter, &cmd);
    }

    mp_subfilter_continue(&p->sub);
}

__attribute__((used)) static bool aspeed_command(struct mp_filter *f, struct mp_filter_command *cmd)
{
    struct aspeed_priv *p = f->priv;

    if (cmd->type == MP_FILTER_COMMAND_SET_SPEED) {
        p->cur_speed = cmd->speed;
        return true;
    }

    if (cmd->type == MP_FILTER_COMMAND_IS_ACTIVE) {
        cmd->is_active = !!p->sub.filter;
        return true;
    }

    return false;
}

__attribute__((used)) static void aspeed_reset(struct mp_filter *f)
{
    struct aspeed_priv *p = f->priv;

    mp_subfilter_reset(&p->sub);
}

__attribute__((used)) static void aspeed_destroy(struct mp_filter *f)
{
    struct aspeed_priv *p = f->priv;

    mp_subfilter_reset(&p->sub);
    TA_FREEP(&p->sub.filter);
}

struct mp_filter *mp_autoaspeed_create(struct mp_filter *parent)
{
    struct mp_filter *f = mp_filter_create(parent, &aspeed_filter);
    if (!f)
        return NULL;

    struct aspeed_priv *p = f->priv;
    p->cur_speed = 1.0;

    p->sub.in = mp_filter_add_pin(f, MP_PIN_IN, "in");
    p->sub.out = mp_filter_add_pin(f, MP_PIN_OUT, "out");

    return f;
}

