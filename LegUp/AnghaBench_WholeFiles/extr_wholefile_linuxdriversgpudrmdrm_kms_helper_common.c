#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct drm_dp_aux {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline int drm_fb_helper_modinit(void)
{
	return 0;
}

__attribute__((used)) static inline int drm_dp_aux_dev_init(void)
{
	return 0;
}

__attribute__((used)) static inline void drm_dp_aux_dev_exit(void)
{
}

__attribute__((used)) static inline int drm_dp_aux_register_devnode(struct drm_dp_aux *aux)
{
	return 0;
}

__attribute__((used)) static inline void drm_dp_aux_unregister_devnode(struct drm_dp_aux *aux)
{
}

