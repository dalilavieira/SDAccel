#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct ra_tex_params {int dimensions; int d; int render_src; int /*<<< orphan*/  src_linear; struct ra_format const* format; int /*<<< orphan*/  h; int /*<<< orphan*/  w; } ;
struct ra_hwdec_mapper {struct cuda_mapper_priv* priv; TYPE_1__* owner; int /*<<< orphan*/ * tex; int /*<<< orphan*/  ra; } ;
struct ra_hwdec {int /*<<< orphan*/  global; int /*<<< orphan*/  ra; struct cuda_hw_priv* priv; } ;
struct ra_format {int /*<<< orphan*/  linear_filter; } ;
struct ext_gl {scalar_t__ cu_res; } ;
struct cuda_mapper_priv {struct ext_gl** ext; int /*<<< orphan*/ * cu_array; int /*<<< orphan*/  layout; } ;
struct cuda_hw_priv {int (* ext_init ) (struct ra_hwdec_mapper*,struct ra_format const*,int) ;void (* ext_uninit ) (struct ra_hwdec_mapper const*,int) ;int /*<<< orphan*/  decode_ctx; int /*<<< orphan*/  display_ctx; TYPE_3__* cu; } ;
struct TYPE_7__ {int /*<<< orphan*/  (* cuCtxCreate ) (int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__) ;int /*<<< orphan*/  (* cuCtxPopCurrent ) (int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* cuDeviceGet ) (scalar_t__*,int) ;int /*<<< orphan*/  (* cuGLGetDevices ) (unsigned int*,scalar_t__*,int,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* cuGraphicsUnregisterResource ) (scalar_t__) ;int /*<<< orphan*/  (* cuGraphicsUnmapResources ) (int,scalar_t__*,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* cuGraphicsSubResourceGetMappedArray ) (int /*<<< orphan*/ *,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* cuGraphicsMapResources ) (int,scalar_t__*,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* cuGraphicsGLRegisterImage ) (scalar_t__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;} ;
struct TYPE_6__ {int version; int es; } ;
struct TYPE_5__ {struct cuda_hw_priv* priv; } ;
typedef  int /*<<< orphan*/  GLuint ;
typedef  int /*<<< orphan*/  GLenum ;
typedef  TYPE_2__ GL ;
typedef  TYPE_3__ CudaFunctions ;
typedef  scalar_t__ CUdevice ;
typedef  int /*<<< orphan*/  CUcontext ;

/* Variables and functions */
 int CHECK_CU (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CU_CTX_SCHED_BLOCKING_SYNC ; 
 int /*<<< orphan*/  CU_GL_DEVICE_LIST_ALL ; 
 int /*<<< orphan*/  CU_GRAPHICS_REGISTER_FLAGS_WRITE_DISCARD ; 
 int /*<<< orphan*/  MP_INFO (struct ra_hwdec const*,char*) ; 
 int /*<<< orphan*/  MP_VERBOSE (struct ra_hwdec const*,char*) ; 
 struct ext_gl* egl ; 
 int /*<<< orphan*/  m_option_type_choice ; 
 int /*<<< orphan*/  mp_image_plane_h (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  mp_image_plane_w (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  mp_read_option_raw (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *,int*) ; 
 TYPE_2__* ra_gl_get (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ra_gl_get_raw_tex (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ ra_is_gl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ra_tex_create (int /*<<< orphan*/ ,struct ra_tex_params*) ; 
 int /*<<< orphan*/  stub1 (scalar_t__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub10 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub11 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub12 (int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  stub2 (int,scalar_t__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub3 (int /*<<< orphan*/ *,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub4 (int,scalar_t__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub5 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub6 (scalar_t__) ; 
 int /*<<< orphan*/  stub7 (unsigned int*,scalar_t__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub8 (int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  stub9 (scalar_t__*,int) ; 
 int /*<<< orphan*/  talloc_free (struct ext_gl*) ; 
 struct ext_gl* talloc_ptrtype (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool cuda_ext_gl_init(struct ra_hwdec_mapper *mapper,
                             const struct ra_format *format, int n)
{
    struct cuda_hw_priv *p_owner = mapper->owner->priv;
    struct cuda_mapper_priv *p = mapper->priv;
    CudaFunctions *cu = p_owner->cu;
    int ret = 0;
    CUcontext dummy;

    struct ext_gl *egl = talloc_ptrtype(NULL, egl);
    p->ext[n] = egl;

    struct ra_tex_params params = {
        .dimensions = 2,
        .w = mp_image_plane_w(&p->layout, n),
        .h = mp_image_plane_h(&p->layout, n),
        .d = 1,
        .format = format,
        .render_src = true,
        .src_linear = format->linear_filter,
    };

    mapper->tex[n] = ra_tex_create(mapper->ra, &params);
    if (!mapper->tex[n]) {
        goto error;
    }

    GLuint texture;
    GLenum target;
    ra_gl_get_raw_tex(mapper->ra, mapper->tex[n], &texture, &target);

    ret = CHECK_CU(cu->cuGraphicsGLRegisterImage(&egl->cu_res, texture, target,
                                                 CU_GRAPHICS_REGISTER_FLAGS_WRITE_DISCARD));
    if (ret < 0)
        goto error;

    ret = CHECK_CU(cu->cuGraphicsMapResources(1, &egl->cu_res, 0));
    if (ret < 0)
        goto error;

    ret = CHECK_CU(cu->cuGraphicsSubResourceGetMappedArray(&p->cu_array[n], egl->cu_res,
                                                           0, 0));
    if (ret < 0)
        goto error;

    ret = CHECK_CU(cu->cuGraphicsUnmapResources(1, &egl->cu_res, 0));
    if (ret < 0)
        goto error;

    return true;

error:
    CHECK_CU(cu->cuCtxPopCurrent(&dummy));
    return false;
}

__attribute__((used)) static void cuda_ext_gl_uninit(const struct ra_hwdec_mapper *mapper, int n)
{
    struct cuda_hw_priv *p_owner = mapper->owner->priv;
    struct cuda_mapper_priv *p = mapper->priv;
    CudaFunctions *cu = p_owner->cu;

    struct ext_gl *egl = p->ext[n];
    if (egl && egl->cu_res) {
        CHECK_CU(cu->cuGraphicsUnregisterResource(egl->cu_res));
        egl->cu_res = 0;
    }
    talloc_free(egl);
}

bool cuda_gl_init(const struct ra_hwdec *hw) {
    int ret = 0;
    struct cuda_hw_priv *p = hw->priv;
    CudaFunctions *cu = p->cu;

    if (ra_is_gl(hw->ra)) {
        GL *gl = ra_gl_get(hw->ra);
        if (gl->version < 210 && gl->es < 300) {
            MP_VERBOSE(hw, "need OpenGL >= 2.1 or OpenGL-ES >= 3.0\n");
            return false;
        }
    } else {
        // This is not an error.
        return true;
    }

    CUdevice display_dev;
    unsigned int device_count;
    ret = CHECK_CU(cu->cuGLGetDevices(&device_count, &display_dev, 1,
                                      CU_GL_DEVICE_LIST_ALL));
    if (ret < 0)
        return false;

    ret = CHECK_CU(cu->cuCtxCreate(&p->display_ctx, CU_CTX_SCHED_BLOCKING_SYNC,
                                   display_dev));
    if (ret < 0)
        return false;

    p->decode_ctx = p->display_ctx;

    int decode_dev_idx = -1;
    mp_read_option_raw(hw->global, "cuda-decode-device", &m_option_type_choice,
                       &decode_dev_idx);

    if (decode_dev_idx > -1) {
        CUcontext dummy;
        CUdevice decode_dev;
        ret = CHECK_CU(cu->cuDeviceGet(&decode_dev, decode_dev_idx));
        if (ret < 0) {
            CHECK_CU(cu->cuCtxPopCurrent(&dummy));
            return false;
        }

        if (decode_dev != display_dev) {
            MP_INFO(hw, "Using separate decoder and display devices\n");

            // Pop the display context. We won't use it again during init()
            ret = CHECK_CU(cu->cuCtxPopCurrent(&dummy));
            if (ret < 0)
                return false;

            ret = CHECK_CU(cu->cuCtxCreate(&p->decode_ctx, CU_CTX_SCHED_BLOCKING_SYNC,
                                           decode_dev));
            if (ret < 0)
                return false;
        }
    }

    p->ext_init = cuda_ext_gl_init;
    p->ext_uninit = cuda_ext_gl_uninit;

    return true;
}

