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
struct drm_minor {int dummy; } ;
struct drm_crtc {int dummy; } ;
struct drm_connector {int dummy; } ;
struct dentry {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline int drm_debugfs_init(struct drm_minor *minor, int minor_id,
				   struct dentry *root)
{
	return 0;
}

__attribute__((used)) static inline int drm_debugfs_cleanup(struct drm_minor *minor)
{
	return 0;
}

__attribute__((used)) static inline int drm_debugfs_connector_add(struct drm_connector *connector)
{
	return 0;
}

__attribute__((used)) static inline void drm_debugfs_connector_remove(struct drm_connector *connector)
{
}

__attribute__((used)) static inline int drm_debugfs_crtc_add(struct drm_crtc *crtc)
{
	return 0;
}

__attribute__((used)) static inline void drm_debugfs_crtc_remove(struct drm_crtc *crtc)
{
}

__attribute__((used)) static inline int drm_debugfs_crtc_crc_add(struct drm_crtc *crtc)
{
	return 0;
}

