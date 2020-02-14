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
struct tc_driver {struct tc_device_id* id_table; int /*<<< orphan*/  driver; } ;
struct tc_device_id {scalar_t__* vendor; scalar_t__* name; } ;
struct tc_dev {int /*<<< orphan*/  vendor; int /*<<< orphan*/  name; } ;
struct device_driver {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int driver_register (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  driver_unregister (int /*<<< orphan*/ *) ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,scalar_t__*) ; 
 struct tc_dev* to_tc_dev (struct device*) ; 
 struct tc_driver* to_tc_driver (struct device_driver*) ; 

int tc_register_driver(struct tc_driver *tdrv)
{
	return driver_register(&tdrv->driver);
}

void tc_unregister_driver(struct tc_driver *tdrv)
{
	driver_unregister(&tdrv->driver);
}

const struct tc_device_id *tc_match_device(struct tc_driver *tdrv,
					   struct tc_dev *tdev)
{
	const struct tc_device_id *id = tdrv->id_table;

	if (id) {
		while (id->name[0] || id->vendor[0]) {
			if (strcmp(tdev->name, id->name) == 0 &&
			    strcmp(tdev->vendor, id->vendor) == 0)
				return id;
			id++;
		}
	}
	return NULL;
}

__attribute__((used)) static int tc_bus_match(struct device *dev, struct device_driver *drv)
{
	struct tc_dev *tdev = to_tc_dev(dev);
	struct tc_driver *tdrv = to_tc_driver(drv);
	const struct tc_device_id *id;

	id = tc_match_device(tdrv, tdev);
	if (id)
		return 1;

	return 0;
}

