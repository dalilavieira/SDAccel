#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct tinydrm_device {struct drm_gem_object* drm; int /*<<< orphan*/  dirty_lock; struct drm_framebuffer_funcs const* fb_funcs; } ;
struct sg_table {int dummy; } ;
struct drm_mode_fb_cmd2 {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/ * funcs; } ;
struct drm_gem_object {struct device* dev; struct tinydrm_device* dev_private; TYPE_2__ mode_config; TYPE_1__* import_attach; } ;
struct drm_gem_cma_object {void* vaddr; } ;
struct drm_framebuffer_funcs {int dummy; } ;
struct drm_framebuffer {int dummy; } ;
struct drm_file {int dummy; } ;
struct drm_driver {int dummy; } ;
struct drm_device {struct device* dev; struct tinydrm_device* dev_private; TYPE_2__ mode_config; TYPE_1__* import_attach; } ;
struct dma_buf_attachment {int /*<<< orphan*/  dmabuf; } ;
struct device {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/  dmabuf; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRM_ERROR (char*,...) ; 
 int /*<<< orphan*/  ENOMEM ; 
 struct drm_gem_object* ERR_PTR (int /*<<< orphan*/ ) ; 
 scalar_t__ IS_ERR (struct drm_gem_object*) ; 
 int PTR_ERR (struct drm_gem_object*) ; 
 int devm_add_action (struct device*,void (*) (void*),struct tinydrm_device*) ; 
 void* dma_buf_vmap (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_buf_vunmap (int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  drm_atomic_helper_shutdown (struct drm_gem_object*) ; 
 struct drm_gem_object* drm_dev_alloc (struct drm_driver*,struct device*) ; 
 int drm_dev_register (struct drm_gem_object*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_dev_unref (struct drm_gem_object*) ; 
 int /*<<< orphan*/  drm_dev_unregister (struct drm_gem_object*) ; 
 int drm_fbdev_generic_setup (struct drm_gem_object*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_gem_cma_free_object (struct drm_gem_object*) ; 
 struct drm_gem_object* drm_gem_cma_prime_import_sg_table (struct drm_gem_object*,struct dma_buf_attachment*,struct sg_table*) ; 
 struct drm_framebuffer* drm_gem_fb_create_with_funcs (struct drm_gem_object*,struct drm_file*,struct drm_mode_fb_cmd2 const*,struct drm_framebuffer_funcs const*) ; 
 int /*<<< orphan*/  drm_mode_config_cleanup (struct drm_gem_object*) ; 
 int /*<<< orphan*/  drm_mode_config_init (struct drm_gem_object*) ; 
 int /*<<< orphan*/  mutex_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tinydrm_mode_config_funcs ; 
 struct drm_gem_cma_object* to_drm_gem_cma_obj (struct drm_gem_object*) ; 

struct drm_gem_object *
tinydrm_gem_cma_prime_import_sg_table(struct drm_device *drm,
				      struct dma_buf_attachment *attach,
				      struct sg_table *sgt)
{
	struct drm_gem_cma_object *cma_obj;
	struct drm_gem_object *obj;
	void *vaddr;

	vaddr = dma_buf_vmap(attach->dmabuf);
	if (!vaddr) {
		DRM_ERROR("Failed to vmap PRIME buffer\n");
		return ERR_PTR(-ENOMEM);
	}

	obj = drm_gem_cma_prime_import_sg_table(drm, attach, sgt);
	if (IS_ERR(obj)) {
		dma_buf_vunmap(attach->dmabuf, vaddr);
		return obj;
	}

	cma_obj = to_drm_gem_cma_obj(obj);
	cma_obj->vaddr = vaddr;

	return obj;
}

void tinydrm_gem_cma_free_object(struct drm_gem_object *gem_obj)
{
	if (gem_obj->import_attach) {
		struct drm_gem_cma_object *cma_obj;

		cma_obj = to_drm_gem_cma_obj(gem_obj);
		dma_buf_vunmap(gem_obj->import_attach->dmabuf, cma_obj->vaddr);
		cma_obj->vaddr = NULL;
	}

	drm_gem_cma_free_object(gem_obj);
}

__attribute__((used)) static struct drm_framebuffer *
tinydrm_fb_create(struct drm_device *drm, struct drm_file *file_priv,
		  const struct drm_mode_fb_cmd2 *mode_cmd)
{
	struct tinydrm_device *tdev = drm->dev_private;

	return drm_gem_fb_create_with_funcs(drm, file_priv, mode_cmd,
					    tdev->fb_funcs);
}

__attribute__((used)) static int tinydrm_init(struct device *parent, struct tinydrm_device *tdev,
			const struct drm_framebuffer_funcs *fb_funcs,
			struct drm_driver *driver)
{
	struct drm_device *drm;

	mutex_init(&tdev->dirty_lock);
	tdev->fb_funcs = fb_funcs;

	/*
	 * We don't embed drm_device, because that prevent us from using
	 * devm_kzalloc() to allocate tinydrm_device in the driver since
	 * drm_dev_unref() frees the structure. The devm_ functions provide
	 * for easy error handling.
	 */
	drm = drm_dev_alloc(driver, parent);
	if (IS_ERR(drm))
		return PTR_ERR(drm);

	tdev->drm = drm;
	drm->dev_private = tdev;
	drm_mode_config_init(drm);
	drm->mode_config.funcs = &tinydrm_mode_config_funcs;

	return 0;
}

__attribute__((used)) static void tinydrm_fini(struct tinydrm_device *tdev)
{
	drm_mode_config_cleanup(tdev->drm);
	mutex_destroy(&tdev->dirty_lock);
	tdev->drm->dev_private = NULL;
	drm_dev_unref(tdev->drm);
}

__attribute__((used)) static void devm_tinydrm_release(void *data)
{
	tinydrm_fini(data);
}

int devm_tinydrm_init(struct device *parent, struct tinydrm_device *tdev,
		      const struct drm_framebuffer_funcs *fb_funcs,
		      struct drm_driver *driver)
{
	int ret;

	ret = tinydrm_init(parent, tdev, fb_funcs, driver);
	if (ret)
		return ret;

	ret = devm_add_action(parent, devm_tinydrm_release, tdev);
	if (ret)
		tinydrm_fini(tdev);

	return ret;
}

__attribute__((used)) static int tinydrm_register(struct tinydrm_device *tdev)
{
	struct drm_device *drm = tdev->drm;
	int ret;

	ret = drm_dev_register(tdev->drm, 0);
	if (ret)
		return ret;

	ret = drm_fbdev_generic_setup(drm, 0);
	if (ret)
		DRM_ERROR("Failed to initialize fbdev: %d\n", ret);

	return 0;
}

__attribute__((used)) static void tinydrm_unregister(struct tinydrm_device *tdev)
{
	drm_atomic_helper_shutdown(tdev->drm);
	drm_dev_unregister(tdev->drm);
}

__attribute__((used)) static void devm_tinydrm_register_release(void *data)
{
	tinydrm_unregister(data);
}

int devm_tinydrm_register(struct tinydrm_device *tdev)
{
	struct device *dev = tdev->drm->dev;
	int ret;

	ret = tinydrm_register(tdev);
	if (ret)
		return ret;

	ret = devm_add_action(dev, devm_tinydrm_register_release, tdev);
	if (ret)
		tinydrm_unregister(tdev);

	return ret;
}

void tinydrm_shutdown(struct tinydrm_device *tdev)
{
	drm_atomic_helper_shutdown(tdev->drm);
}

