#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_6__ ;
typedef  struct TYPE_19__   TYPE_5__ ;
typedef  struct TYPE_18__   TYPE_4__ ;
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;
typedef  struct TYPE_14__   TYPE_11__ ;

/* Type definitions */
typedef  int uint32_t ;
struct vdp_functions {int /*<<< orphan*/  (* video_surface_get_parameters ) (intptr_t,int /*<<< orphan*/ *,int*,int*) ;int /*<<< orphan*/  (* output_surface_create ) (intptr_t,int /*<<< orphan*/ ,int,int,scalar_t__*) ;int /*<<< orphan*/  (* output_surface_destroy ) (scalar_t__) ;} ;
struct ra_tex_params {int dimensions; int w; int h; int d; int render_src; int src_linear; int /*<<< orphan*/  format; } ;
struct TYPE_17__ {scalar_t__ hw_subfmt; int w; int h; scalar_t__ imgfmt; } ;
struct ra_hwdec_mapper {int vdpau_fields; void** tex; int /*<<< orphan*/  ra; TYPE_3__ src_params; TYPE_5__* src; struct priv* priv; int /*<<< orphan*/  log; TYPE_3__ dst_params; TYPE_2__* owner; } ;
struct ra_hwdec {int /*<<< orphan*/  devs; struct priv_owner* priv; TYPE_1__* driver; scalar_t__ probing; int /*<<< orphan*/  log; int /*<<< orphan*/  ra; } ;
struct priv_owner {TYPE_6__* ctx; } ;
struct priv {int mapped; int direct_mode; scalar_t__ vdp_surface; int vdpgl_initialized; int /*<<< orphan*/ * gl_textures; scalar_t__ vdpgl_surface; int /*<<< orphan*/  mixer; int /*<<< orphan*/  preemption_counter; TYPE_6__* ctx; TYPE_4__* gl; } ;
typedef  intptr_t VdpVideoSurface ;
typedef  int /*<<< orphan*/  VdpStatus ;
typedef  int /*<<< orphan*/  VdpChromaType ;
struct TYPE_14__ {int /*<<< orphan*/  driver_name; } ;
struct TYPE_20__ {intptr_t vdp_device; struct vdp_functions vdp; int /*<<< orphan*/  get_proc_address; TYPE_11__ hwctx; } ;
struct TYPE_19__ {int /*<<< orphan*/ * planes; } ;
struct TYPE_18__ {int mpgl_caps; int /*<<< orphan*/  (* VDPAUMapSurfacesNV ) (int,scalar_t__*) ;int /*<<< orphan*/  (* VDPAUSurfaceAccessNV ) (scalar_t__,int /*<<< orphan*/ ) ;scalar_t__ (* VDPAURegisterVideoSurfaceNV ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ;scalar_t__ (* VDPAURegisterOutputSurfaceNV ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* BindTexture ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* TexParameteri ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* GenTextures ) (int,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* VDPAUInitNV ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* VDPAUFiniNV ) () ;int /*<<< orphan*/  (* DeleteTextures ) (int,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* VDPAUUnregisterSurfaceNV ) (scalar_t__) ;int /*<<< orphan*/  (* VDPAUUnmapSurfacesNV ) (int,scalar_t__*) ;} ;
struct TYPE_16__ {struct priv_owner* priv; } ;
struct TYPE_15__ {int /*<<< orphan*/  name; } ;
typedef  TYPE_4__ GL ;
typedef  int /*<<< orphan*/  Display ;

/* Variables and functions */
 int /*<<< orphan*/  BRAINDEATH (intptr_t) ; 
 int /*<<< orphan*/  CHECK_VDP_ERROR (struct ra_hwdec_mapper*,char*) ; 
 int /*<<< orphan*/  CHECK_VDP_WARNING (struct ra_hwdec_mapper*,char*) ; 
 int /*<<< orphan*/  GL_CLAMP_TO_EDGE ; 
 int /*<<< orphan*/  GL_LINEAR ; 
 int /*<<< orphan*/  GL_NEAREST ; 
 int /*<<< orphan*/  GL_READ_ONLY ; 
 int /*<<< orphan*/  GL_TEXTURE_2D ; 
 int /*<<< orphan*/  GL_TEXTURE_MAG_FILTER ; 
 int /*<<< orphan*/  GL_TEXTURE_MIN_FILTER ; 
 int /*<<< orphan*/  GL_TEXTURE_WRAP_S ; 
 int /*<<< orphan*/  GL_TEXTURE_WRAP_T ; 
 scalar_t__ IMGFMT_420P ; 
 scalar_t__ IMGFMT_NV12 ; 
 scalar_t__ IMGFMT_RGB0 ; 
 int MPGL_CAP_VDPAU ; 
 scalar_t__ VDP_INVALID_HANDLE ; 
 int /*<<< orphan*/  VDP_RGBA_FORMAT_B8G8R8A8 ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/ * glXGetCurrentDisplay () ; 
 int /*<<< orphan*/  gl_check_error (TYPE_4__*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  hwdec_devices_add (int /*<<< orphan*/ ,TYPE_11__*) ; 
 int /*<<< orphan*/  hwdec_devices_remove (int /*<<< orphan*/ ,TYPE_11__*) ; 
 TYPE_6__* mp_vdpau_create_device_x11 (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  mp_vdpau_destroy (TYPE_6__*) ; 
 scalar_t__ mp_vdpau_guess_if_emulated (TYPE_6__*) ; 
 scalar_t__ mp_vdpau_handle_preemption (TYPE_6__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mp_vdpau_mixer_create (TYPE_6__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mp_vdpau_mixer_destroy (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mp_vdpau_mixer_render (int /*<<< orphan*/ ,int /*<<< orphan*/ *,intptr_t,int /*<<< orphan*/ *,TYPE_5__*,int /*<<< orphan*/ *) ; 
 void* ra_create_wrapped_tex (int /*<<< orphan*/ ,struct ra_tex_params*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ra_find_unorm_format (int /*<<< orphan*/ ,int,int) ; 
 void* ra_gl_get (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ra_is_gl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ra_tex_free (int /*<<< orphan*/ ,void**) ; 
 int /*<<< orphan*/  stub1 (int,scalar_t__*) ; 
 int /*<<< orphan*/  stub10 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub11 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub12 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub13 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub14 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub15 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub16 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub17 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub18 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub19 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub2 (scalar_t__) ; 
 int /*<<< orphan*/  stub20 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub21 (intptr_t,int /*<<< orphan*/ ,int,int,scalar_t__*) ; 
 scalar_t__ stub22 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub23 (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub24 (intptr_t,int /*<<< orphan*/ *,int*,int*) ; 
 scalar_t__ stub25 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub26 (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub27 (int,scalar_t__*) ; 
 int /*<<< orphan*/  stub28 (int,scalar_t__*) ; 
 int /*<<< orphan*/  stub3 (scalar_t__) ; 
 int /*<<< orphan*/  stub4 (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub5 (scalar_t__) ; 
 int /*<<< orphan*/  stub6 () ; 
 int /*<<< orphan*/  stub7 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub8 (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub9 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int init(struct ra_hwdec *hw)
{
    Display *x11disp = glXGetCurrentDisplay();
    if (!x11disp || !ra_is_gl(hw->ra))
        return -1;
    GL *gl = ra_gl_get(hw->ra);
    if (!(gl->mpgl_caps & MPGL_CAP_VDPAU))
        return -1;
    struct priv_owner *p = hw->priv;
    p->ctx = mp_vdpau_create_device_x11(hw->log, x11disp, true);
    if (!p->ctx)
        return -1;
    if (mp_vdpau_handle_preemption(p->ctx, NULL) < 1)
        return -1;
    if (hw->probing && mp_vdpau_guess_if_emulated(p->ctx))
        return -1;
    p->ctx->hwctx.driver_name = hw->driver->name;
    hwdec_devices_add(hw->devs, &p->ctx->hwctx);
    return 0;
}

__attribute__((used)) static void uninit(struct ra_hwdec *hw)
{
    struct priv_owner *p = hw->priv;

    if (p->ctx)
        hwdec_devices_remove(hw->devs, &p->ctx->hwctx);
    mp_vdpau_destroy(p->ctx);
}

__attribute__((used)) static void mapper_unmap(struct ra_hwdec_mapper *mapper)
{
    struct priv *p = mapper->priv;
    GL *gl = p->gl;

    for (int n = 0; n < 4; n++)
        ra_tex_free(mapper->ra, &mapper->tex[n]);

    if (p->mapped) {
        gl->VDPAUUnmapSurfacesNV(1, &p->vdpgl_surface);
        if (p->direct_mode) {
            gl->VDPAUUnregisterSurfaceNV(p->vdpgl_surface);
            p->vdpgl_surface = 0;
        }
    }
    p->mapped = false;
}

__attribute__((used)) static void mark_vdpau_objects_uninitialized(struct ra_hwdec_mapper *mapper)
{
    struct priv *p = mapper->priv;

    p->vdp_surface = VDP_INVALID_HANDLE;
    p->mapped = false;
}

__attribute__((used)) static void mapper_uninit(struct ra_hwdec_mapper *mapper)
{
    struct priv *p = mapper->priv;
    GL *gl = p->gl;
    struct vdp_functions *vdp = &p->ctx->vdp;
    VdpStatus vdp_st;

    assert(!p->mapped);

    if (p->vdpgl_surface)
        gl->VDPAUUnregisterSurfaceNV(p->vdpgl_surface);
    p->vdpgl_surface = 0;

    gl->DeleteTextures(4, p->gl_textures);

    if (p->vdp_surface != VDP_INVALID_HANDLE) {
        vdp_st = vdp->output_surface_destroy(p->vdp_surface);
        CHECK_VDP_WARNING(mapper, "Error when calling vdp_output_surface_destroy");
    }
    p->vdp_surface = VDP_INVALID_HANDLE;

    gl_check_error(gl, mapper->log, "Before uninitializing OpenGL interop");

    if (p->vdpgl_initialized)
        gl->VDPAUFiniNV();

    p->vdpgl_initialized = false;

    gl_check_error(gl, mapper->log, "After uninitializing OpenGL interop");

    mp_vdpau_mixer_destroy(p->mixer);
}

__attribute__((used)) static int mapper_init(struct ra_hwdec_mapper *mapper)
{
    struct priv_owner *p_owner = mapper->owner->priv;
    struct priv *p = mapper->priv;

    p->gl = ra_gl_get(mapper->ra);
    p->ctx = p_owner->ctx;

    GL *gl = p->gl;
    struct vdp_functions *vdp = &p->ctx->vdp;
    VdpStatus vdp_st;

    p->vdp_surface = VDP_INVALID_HANDLE;
    p->mixer = mp_vdpau_mixer_create(p->ctx, mapper->log);
    if (!p->mixer)
        return -1;

    mapper->dst_params = mapper->src_params;

    if (mp_vdpau_handle_preemption(p->ctx, &p->preemption_counter) < 0)
        return -1;

    gl->VDPAUInitNV(BRAINDEATH(p->ctx->vdp_device), p->ctx->get_proc_address);

    p->vdpgl_initialized = true;

    p->direct_mode = mapper->dst_params.hw_subfmt == IMGFMT_NV12 ||
                     mapper->dst_params.hw_subfmt == IMGFMT_420P;
    mapper->vdpau_fields = p->direct_mode;

    gl->GenTextures(4, p->gl_textures);

    if (p->direct_mode) {
        mapper->dst_params.imgfmt = IMGFMT_NV12;
        mapper->dst_params.hw_subfmt = 0;

        for (int n = 0; n < 4; n++) {
            gl->BindTexture(GL_TEXTURE_2D, p->gl_textures[n]);
            gl->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            gl->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
            gl->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            gl->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            gl->BindTexture(GL_TEXTURE_2D, 0);
        }
    } else {
        gl->BindTexture(GL_TEXTURE_2D, p->gl_textures[0]);
        gl->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        gl->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        gl->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        gl->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        gl->BindTexture(GL_TEXTURE_2D, 0);

        vdp_st = vdp->output_surface_create(p->ctx->vdp_device,
                                            VDP_RGBA_FORMAT_B8G8R8A8,
                                            mapper->src_params.w,
                                            mapper->src_params.h,
                                            &p->vdp_surface);
        CHECK_VDP_ERROR(mapper, "Error when calling vdp_output_surface_create");

        p->vdpgl_surface = gl->VDPAURegisterOutputSurfaceNV(BRAINDEATH(p->vdp_surface),
                                                            GL_TEXTURE_2D,
                                                            1, p->gl_textures);
        if (!p->vdpgl_surface)
            return -1;

        gl->VDPAUSurfaceAccessNV(p->vdpgl_surface, GL_READ_ONLY);

        mapper->dst_params.imgfmt = IMGFMT_RGB0;
        mapper->dst_params.hw_subfmt = 0;
    }

    gl_check_error(gl, mapper->log, "After initializing vdpau OpenGL interop");

    return 0;
}

__attribute__((used)) static int mapper_map(struct ra_hwdec_mapper *mapper)
{
    struct priv *p = mapper->priv;
    GL *gl = p->gl;
    struct vdp_functions *vdp = &p->ctx->vdp;
    VdpStatus vdp_st;

    int pe = mp_vdpau_handle_preemption(p->ctx, &p->preemption_counter);
    if (pe < 1) {
        mark_vdpau_objects_uninitialized(mapper);
        if (pe < 0)
            return -1;
        mapper_uninit(mapper);
        if (mapper_init(mapper) < 0)
            return -1;
    }

    if (p->direct_mode) {
        VdpVideoSurface surface = (intptr_t)mapper->src->planes[3];

        // We need the uncropped size.
        VdpChromaType s_chroma_type;
        uint32_t s_w, s_h;
        vdp_st = vdp->video_surface_get_parameters(surface, &s_chroma_type, &s_w, &s_h);
        CHECK_VDP_ERROR(mapper, "Error when calling vdp_video_surface_get_parameters");

        p->vdpgl_surface = gl->VDPAURegisterVideoSurfaceNV(BRAINDEATH(surface),
                                                           GL_TEXTURE_2D,
                                                           4, p->gl_textures);
        if (!p->vdpgl_surface)
            return -1;

        gl->VDPAUSurfaceAccessNV(p->vdpgl_surface, GL_READ_ONLY);
        gl->VDPAUMapSurfacesNV(1, &p->vdpgl_surface);

        p->mapped = true;

        for (int n = 0; n < 4; n++) {
            bool chroma = n >= 2;

            struct ra_tex_params params = {
                .dimensions = 2,
                .w = s_w / (chroma ? 2 : 1),
                .h = s_h / (chroma ? 4 : 2),
                .d = 1,
                .format = ra_find_unorm_format(mapper->ra, 1, chroma ? 2 : 1),
                .render_src = true,
            };

            if (!params.format)
                return -1;

            mapper->tex[n] =
                ra_create_wrapped_tex(mapper->ra, &params, p->gl_textures[n]);
            if (!mapper->tex[n])
                return -1;
        }
    } else {
        if (!p->vdpgl_surface)
            return -1;

        mp_vdpau_mixer_render(p->mixer, NULL, p->vdp_surface, NULL, mapper->src,
                              NULL);

        gl->VDPAUMapSurfacesNV(1, &p->vdpgl_surface);

        p->mapped = true;

        struct ra_tex_params params = {
            .dimensions = 2,
            .w = mapper->src_params.w,
            .h = mapper->src_params.h,
            .d = 1,
            .format = ra_find_unorm_format(mapper->ra, 1, 4),
            .render_src = true,
            .src_linear = true,
        };

        if (!params.format)
            return -1;

        mapper->tex[0] =
            ra_create_wrapped_tex(mapper->ra, &params, p->gl_textures[0]);
        if (!mapper->tex[0])
            return -1;
    }

    return 0;
}

