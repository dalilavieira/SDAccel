#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct notifier_block {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  minimum; } ;
struct TYPE_5__ {TYPE_1__ io; } ;
struct acpi_resource {int type; TYPE_2__ data; } ;
struct TYPE_6__ {int /*<<< orphan*/  functional; int /*<<< orphan*/  enabled; } ;
struct acpi_device {int /*<<< orphan*/  handle; TYPE_3__ status; } ;
typedef  int /*<<< orphan*/  acpi_status ;

/* Variables and functions */
#define  ACPI_RESOURCE_TYPE_END_TAG 129 
#define  ACPI_RESOURCE_TYPE_IO 128 
 int /*<<< orphan*/  AE_ERROR ; 
 int /*<<< orphan*/  AE_OK ; 
 int ENODEV ; 
 int /*<<< orphan*/  METHOD_NAME__CRS ; 
 int NOTIFY_DONE ; 
 unsigned int PVPANIC_PANICKED ; 
 int acpi_bus_get_status (struct acpi_device*) ; 
 int /*<<< orphan*/  acpi_walk_resources (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (struct acpi_resource*,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_notifier_chain_register (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_notifier_chain_unregister (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  outb (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  panic_notifier_list ; 
 int /*<<< orphan*/  port ; 
 int /*<<< orphan*/  pvpanic_panic_nb ; 

__attribute__((used)) static void
pvpanic_send_event(unsigned int event)
{
	outb(event, port);
}

__attribute__((used)) static int
pvpanic_panic_notify(struct notifier_block *nb, unsigned long code,
		     void *unused)
{
	pvpanic_send_event(PVPANIC_PANICKED);
	return NOTIFY_DONE;
}

__attribute__((used)) static acpi_status
pvpanic_walk_resources(struct acpi_resource *res, void *context)
{
	switch (res->type) {
	case ACPI_RESOURCE_TYPE_END_TAG:
		return AE_OK;

	case ACPI_RESOURCE_TYPE_IO:
		port = res->data.io.minimum;
		return AE_OK;

	default:
		return AE_ERROR;
	}
}

__attribute__((used)) static int pvpanic_add(struct acpi_device *device)
{
	int ret;

	ret = acpi_bus_get_status(device);
	if (ret < 0)
		return ret;

	if (!device->status.enabled || !device->status.functional)
		return -ENODEV;

	acpi_walk_resources(device->handle, METHOD_NAME__CRS,
			    pvpanic_walk_resources, NULL);

	if (!port)
		return -ENODEV;

	atomic_notifier_chain_register(&panic_notifier_list,
				       &pvpanic_panic_nb);

	return 0;
}

__attribute__((used)) static int pvpanic_remove(struct acpi_device *device)
{

	atomic_notifier_chain_unregister(&panic_notifier_list,
					 &pvpanic_panic_nb);
	return 0;
}

