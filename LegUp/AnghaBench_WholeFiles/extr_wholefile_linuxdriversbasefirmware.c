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
struct module {int dummy; } ;
struct device_driver {TYPE_1__* bus; } ;
struct device {int dummy; } ;
struct TYPE_2__ {int (* match ) (struct device*,struct device_driver*) ;} ;

/* Variables and functions */
 int stub1 (struct device*,struct device_driver*) ; 

__attribute__((used)) static inline int hypervisor_init(void) { return 0; }

__attribute__((used)) static inline int driver_match_device(struct device_driver *drv,
				      struct device *dev)
{
	return drv->bus->match ? drv->bus->match(dev, drv) : 1;
}

__attribute__((used)) static inline void module_add_driver(struct module *mod,
				     struct device_driver *drv) { }

__attribute__((used)) static inline void module_remove_driver(struct device_driver *drv) { }

__attribute__((used)) static inline int devtmpfs_init(void) { return 0; }

