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
struct platform_device {int dummy; } ;
struct omap_dss_device {int src; scalar_t__ state; } ;
struct dss_device {int dummy; } ;
struct dss_debugfs_entry {int dummy; } ;
struct device_node {int dummy; } ;
struct device {int dummy; } ;
typedef  enum omap_channel { ____Placeholder_omap_channel } omap_channel ;
typedef  enum dss_model { ____Placeholder_dss_model } dss_model ;

/* Variables and functions */
 int OMAP_DSS_CHANNEL_LCD ; 
 int OMAP_DSS_CHANNEL_LCD2 ; 
 int OMAP_DSS_CHANNEL_LCD3 ; 
 scalar_t__ OMAP_DSS_DISPLAY_ACTIVE ; 
 int /*<<< orphan*/  omapdss_get_dss () ; 

__attribute__((used)) static inline bool omapdss_is_initialized(void)
{
	return !!omapdss_get_dss();
}

__attribute__((used)) static inline bool omapdss_device_is_connected(struct omap_dss_device *dssdev)
{
	return dssdev->src;
}

__attribute__((used)) static inline bool omapdss_device_is_enabled(struct omap_dss_device *dssdev)
{
	return dssdev->state == OMAP_DSS_DISPLAY_ACTIVE;
}

__attribute__((used)) static inline int dss_set_min_bus_tput(struct device *dev, unsigned long tput)
{
	/* To be implemented when the OMAP platform will provide this feature */
	return 0;
}

__attribute__((used)) static inline bool dss_mgr_is_lcd(enum omap_channel id)
{
	if (id == OMAP_DSS_CHANNEL_LCD || id == OMAP_DSS_CHANNEL_LCD2 ||
			id == OMAP_DSS_CHANNEL_LCD3)
		return true;
	else
		return false;
}

__attribute__((used)) static inline struct dss_debugfs_entry *
dss_debugfs_create_file(struct dss_device *dss, const char *name,
			int (*show_fn)(struct seq_file *s, void *data),
			void *data)
{
	return NULL;
}

__attribute__((used)) static inline void dss_debugfs_remove_file(struct dss_debugfs_entry *entry)
{
}

__attribute__((used)) static inline int sdi_init_port(struct dss_device *dss,
				struct platform_device *pdev,
				struct device_node *port)
{
	return 0;
}

__attribute__((used)) static inline void sdi_uninit_port(struct device_node *port)
{
}

__attribute__((used)) static inline int dpi_init_port(struct dss_device *dss,
				struct platform_device *pdev,
				struct device_node *port,
				enum dss_model dss_model)
{
	return 0;
}

__attribute__((used)) static inline void dpi_uninit_port(struct device_node *port)
{
}

