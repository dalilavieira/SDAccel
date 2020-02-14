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
struct property {int dummy; } ;
struct device_node {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline int of_property_notify(int action, struct device_node *np,
				     struct property *prop, struct property *old_prop)
{
	return 0;
}

__attribute__((used)) static inline int __of_add_property_sysfs(struct device_node *np, struct property *pp)
{
	return 0;
}

__attribute__((used)) static inline void __of_remove_property_sysfs(struct device_node *np, struct property *prop) {}

__attribute__((used)) static inline void __of_update_property_sysfs(struct device_node *np,
		struct property *newprop, struct property *oldprop) {}

__attribute__((used)) static inline int __of_attach_node_sysfs(struct device_node *np)
{
	return 0;
}

__attribute__((used)) static inline void __of_detach_node_sysfs(struct device_node *np) {}

__attribute__((used)) static inline void of_overlay_mutex_lock(void) {}

__attribute__((used)) static inline void of_overlay_mutex_unlock(void) {}

__attribute__((used)) static inline void unittest_unflatten_overlay_base(void) {}

