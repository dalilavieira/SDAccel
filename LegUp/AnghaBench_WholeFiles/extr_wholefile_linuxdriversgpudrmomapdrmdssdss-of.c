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
typedef  scalar_t__ u32 ;
struct property {int dummy; } ;
struct omap_dss_device {int src; scalar_t__ state; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  EPROBE_DEFER ; 
 struct omap_dss_device* ERR_PTR (int /*<<< orphan*/ ) ; 
 scalar_t__ OMAP_DSS_DISPLAY_ACTIVE ; 
 struct property* of_find_property (struct device_node*,char*,int /*<<< orphan*/ *) ; 
 struct device_node* of_get_next_parent (struct device_node*) ; 
 struct device_node* of_get_parent (struct device_node*) ; 
 struct device_node* of_graph_get_endpoint_by_regs (struct device_node*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct device_node* of_graph_get_remote_port (struct device_node*) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 int of_property_read_u32 (struct device_node*,char*,scalar_t__*) ; 
 struct omap_dss_device* omap_dss_find_output_by_port_node (struct device_node*) ; 
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

struct device_node *dss_of_port_get_parent_device(struct device_node *port)
{
	struct device_node *np;
	int i;

	if (!port)
		return NULL;

	np = of_get_parent(port);

	for (i = 0; i < 2 && np; ++i) {
		struct property *prop;

		prop = of_find_property(np, "compatible", NULL);

		if (prop)
			return np;

		np = of_get_next_parent(np);
	}

	return NULL;
}

u32 dss_of_port_get_port_number(struct device_node *port)
{
	int r;
	u32 reg;

	r = of_property_read_u32(port, "reg", &reg);
	if (r)
		reg = 0;

	return reg;
}

struct omap_dss_device *
omapdss_of_find_source_for_first_ep(struct device_node *node)
{
	struct device_node *ep;
	struct device_node *src_port;
	struct omap_dss_device *src;

	ep = of_graph_get_endpoint_by_regs(node, 0, 0);
	if (!ep)
		return ERR_PTR(-EINVAL);

	src_port = of_graph_get_remote_port(ep);
	if (!src_port) {
		of_node_put(ep);
		return ERR_PTR(-EINVAL);
	}

	of_node_put(ep);

	src = omap_dss_find_output_by_port_node(src_port);

	of_node_put(src_port);

	return src ? src : ERR_PTR(-EPROBE_DEFER);
}

