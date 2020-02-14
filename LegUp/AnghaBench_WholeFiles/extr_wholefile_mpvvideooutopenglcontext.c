#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_9__ ;
typedef  struct TYPE_17__   TYPE_7__ ;
typedef  struct TYPE_16__   TYPE_6__ ;
typedef  struct TYPE_15__   TYPE_5__ ;
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct vo_vsync_info {int dummy; } ;
struct ra_swapchain {TYPE_7__* ctx; struct priv* priv; } ;
struct ra_ctx {scalar_t__ ra; TYPE_6__* swapchain; } ;
struct TYPE_12__ {int /*<<< orphan*/  (* get_vsync ) (TYPE_7__*,struct vo_vsync_info*) ;int /*<<< orphan*/  (* swap_buffers ) (TYPE_7__*) ;} ;
struct priv {int main_fb; size_t last_pattern; int frames_rendered; unsigned int prev_sgi_sync_count; scalar_t__ num_vsync_fences; TYPE_2__ params; int /*<<< orphan*/ * vsync_fences; TYPE_3__* opts; TYPE_5__* gl; int /*<<< orphan*/  mismatches; int /*<<< orphan*/  matches; TYPE_9__* wrapped_fb; } ;
struct TYPE_11__ {int w; int h; } ;
struct TYPE_18__ {TYPE_1__ params; } ;
struct TYPE_14__ {scalar_t__ swapchain_depth; int /*<<< orphan*/  debug; } ;
struct TYPE_17__ {TYPE_4__ opts; scalar_t__ ra; } ;
struct TYPE_16__ {struct priv* priv; } ;
struct TYPE_15__ {int es; int mpgl_caps; int /*<<< orphan*/  (* DeleteSync ) (int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* ClientWaitSync ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ;int /*<<< orphan*/  (* WaitVideoSync ) (int,unsigned int,unsigned int*) ;int /*<<< orphan*/  (* GetVideoSync ) (unsigned int*) ;int /*<<< orphan*/  (* BindFramebuffer ) (int /*<<< orphan*/ ,int) ;int /*<<< orphan*/  (* GetFramebufferAttachmentParameteriv ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ;scalar_t__ version; } ;
struct TYPE_13__ {int* vsync_pattern; scalar_t__ waitvsync; } ;
typedef  int GLint ;
typedef  int /*<<< orphan*/  GLenum ;
typedef  TYPE_5__ GL ;

/* Variables and functions */
 int /*<<< orphan*/  GL_BACK ; 
 int /*<<< orphan*/  GL_BACK_LEFT ; 
 int /*<<< orphan*/  GL_COLOR_ATTACHMENT0 ; 
 int /*<<< orphan*/  GL_FRAMEBUFFER ; 
 int /*<<< orphan*/  GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE ; 
 int /*<<< orphan*/  GL_SYNC_FLUSH_COMMANDS_BIT ; 
 int MPGL_CAP_FB ; 
 int /*<<< orphan*/  MP_DBG (struct priv*,char*,unsigned int,unsigned int,int) ; 
 int /*<<< orphan*/  MP_TARRAY_REMOVE_AT (int /*<<< orphan*/ *,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MP_WARN (struct priv*,char*,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_9__* ra_create_wrapped_fb (scalar_t__,int,int,int) ; 
 int /*<<< orphan*/  ra_free (scalar_t__*) ; 
 int /*<<< orphan*/  ra_gl_set_debug (scalar_t__,int) ; 
 int /*<<< orphan*/  ra_tex_free (scalar_t__,TYPE_9__**) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  stub3 (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub4 (TYPE_7__*) ; 
 int /*<<< orphan*/  stub5 (unsigned int*) ; 
 int /*<<< orphan*/  stub6 (int,unsigned int,unsigned int*) ; 
 int /*<<< orphan*/  stub7 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub8 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub9 (TYPE_7__*,struct vo_vsync_info*) ; 
 int /*<<< orphan*/  talloc_free (TYPE_6__*) ; 

void ra_gl_ctx_uninit(struct ra_ctx *ctx)
{
    if (ctx->swapchain) {
        struct priv *p = ctx->swapchain->priv;
        if (ctx->ra && p->wrapped_fb)
            ra_tex_free(ctx->ra, &p->wrapped_fb);
        talloc_free(ctx->swapchain);
        ctx->swapchain = NULL;
    }

    ra_free(&ctx->ra);
}

void ra_gl_ctx_resize(struct ra_swapchain *sw, int w, int h, int fbo)
{
    struct priv *p = sw->priv;
    if (p->main_fb == fbo && p->wrapped_fb && p->wrapped_fb->params.w == w
        && p->wrapped_fb->params.h == h)
        return;

    if (p->wrapped_fb)
        ra_tex_free(sw->ctx->ra, &p->wrapped_fb);

    p->main_fb = fbo;
    p->wrapped_fb = ra_create_wrapped_fb(sw->ctx->ra, fbo, w, h);
}

int ra_gl_ctx_color_depth(struct ra_swapchain *sw)
{
    struct priv *p = sw->priv;
    GL *gl = p->gl;

    if (!p->wrapped_fb)
        return 0;

    if ((gl->es < 300 && !gl->version) || !(gl->mpgl_caps & MPGL_CAP_FB))
        return 0;

    gl->BindFramebuffer(GL_FRAMEBUFFER, p->main_fb);

    GLenum obj = gl->version ? GL_BACK_LEFT : GL_BACK;
    if (p->main_fb)
        obj = GL_COLOR_ATTACHMENT0;

    GLint depth_g = 0;

    gl->GetFramebufferAttachmentParameteriv(GL_FRAMEBUFFER, obj,
                            GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE, &depth_g);

    gl->BindFramebuffer(GL_FRAMEBUFFER, 0);

    return depth_g;
}

__attribute__((used)) static void check_pattern(struct priv *p, int item)
{
    int expected = p->opts->vsync_pattern[p->last_pattern];
    if (item == expected) {
        p->last_pattern++;
        if (p->last_pattern >= 2)
            p->last_pattern = 0;
        p->matches++;
    } else {
        p->mismatches++;
        MP_WARN(p, "wrong pattern, expected %d got %d (hit: %d, mis: %d)\n",
                expected, item, p->matches, p->mismatches);
    }
}

void ra_gl_ctx_swap_buffers(struct ra_swapchain *sw)
{
    struct priv *p = sw->priv;
    GL *gl = p->gl;

    p->params.swap_buffers(sw->ctx);
    p->frames_rendered++;

    if (p->frames_rendered > 5 && !sw->ctx->opts.debug)
        ra_gl_set_debug(sw->ctx->ra, false);

    if ((p->opts->waitvsync || p->opts->vsync_pattern[0])
        && gl->GetVideoSync)
    {
        unsigned int n1 = 0, n2 = 0;
        gl->GetVideoSync(&n1);
        if (p->opts->waitvsync)
            gl->WaitVideoSync(2, (n1 + 1) % 2, &n2);
        int step = n1 - p->prev_sgi_sync_count;
        p->prev_sgi_sync_count = n1;
        MP_DBG(p, "Flip counts: %u->%u, step=%d\n", n1, n2, step);
        if (p->opts->vsync_pattern[0])
            check_pattern(p, step);
    }

    while (p->num_vsync_fences >= sw->ctx->opts.swapchain_depth) {
        gl->ClientWaitSync(p->vsync_fences[0], GL_SYNC_FLUSH_COMMANDS_BIT, 1e9);
        gl->DeleteSync(p->vsync_fences[0]);
        MP_TARRAY_REMOVE_AT(p->vsync_fences, p->num_vsync_fences, 0);
    }
}

__attribute__((used)) static void ra_gl_ctx_get_vsync(struct ra_swapchain *sw,
                                struct vo_vsync_info *info)
{
    struct priv *p = sw->priv;
    if (p->params.get_vsync)
        p->params.get_vsync(sw->ctx, info);
}

