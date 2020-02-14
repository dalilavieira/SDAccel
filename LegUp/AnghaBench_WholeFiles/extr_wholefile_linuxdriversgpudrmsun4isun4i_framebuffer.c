#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int max_width; int max_height; int /*<<< orphan*/ * helper_private; int /*<<< orphan*/ * funcs; } ;
struct drm_device {TYPE_1__ mode_config; } ;
struct drm_atomic_state {int dummy; } ;

/* Variables and functions */
 int drm_atomic_helper_check_modeset (struct drm_device*,struct drm_atomic_state*) ; 
 int drm_atomic_helper_check_planes (struct drm_device*,struct drm_atomic_state*) ; 
 int drm_atomic_normalize_zpos (struct drm_device*,struct drm_atomic_state*) ; 
 int /*<<< orphan*/  drm_fb_cma_fbdev_fini (struct drm_device*) ; 
 int drm_fb_cma_fbdev_init (struct drm_device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_mode_config_reset (struct drm_device*) ; 
 int /*<<< orphan*/  sun4i_de_mode_config_funcs ; 
 int /*<<< orphan*/  sun4i_de_mode_config_helpers ; 

__attribute__((used)) static int sun4i_de_atomic_check(struct drm_device *dev,
				 struct drm_atomic_state *state)
{
	int ret;

	ret = drm_atomic_helper_check_modeset(dev, state);
	if (ret)
		return ret;

	ret = drm_atomic_normalize_zpos(dev, state);
	if (ret)
		return ret;

	return drm_atomic_helper_check_planes(dev, state);
}

int sun4i_framebuffer_init(struct drm_device *drm)
{
	drm_mode_config_reset(drm);

	drm->mode_config.max_width = 8192;
	drm->mode_config.max_height = 8192;

	drm->mode_config.funcs = &sun4i_de_mode_config_funcs;
	drm->mode_config.helper_private = &sun4i_de_mode_config_helpers;

	return drm_fb_cma_fbdev_init(drm, 32, 0);
}

void sun4i_framebuffer_free(struct drm_device *drm)
{
	drm_fb_cma_fbdev_fini(drm);
}

