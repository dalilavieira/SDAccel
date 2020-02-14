#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_6__ ;
typedef  struct TYPE_19__   TYPE_3__ ;
typedef  struct TYPE_18__   TYPE_2__ ;
typedef  struct TYPE_17__   TYPE_1__ ;
typedef  struct TYPE_16__   TYPE_12__ ;

/* Type definitions */
struct pci_dev {scalar_t__ vendor; } ;
struct backlight_properties {int max_brightness; int /*<<< orphan*/  type; } ;
struct TYPE_17__ {int brightness; } ;
struct backlight_device {TYPE_1__ props; } ;
struct acpi_device {int dummy; } ;
struct TYPE_16__ {int (* get_brightness ) (TYPE_3__*) ;} ;
struct TYPE_20__ {int /*<<< orphan*/  iolen; int /*<<< orphan*/  iostart; TYPE_12__ backlight_ops; int /*<<< orphan*/  (* set_brightness ) (int) ;} ;
struct TYPE_18__ {int brightness; } ;
struct TYPE_19__ {TYPE_2__ props; } ;

/* Variables and functions */
 int /*<<< orphan*/  BACKLIGHT_PLATFORM ; 
 int ENODEV ; 
 int ENXIO ; 
 scalar_t__ IS_ERR (TYPE_3__*) ; 
 scalar_t__ PCI_VENDOR_ID_INTEL ; 
 scalar_t__ PCI_VENDOR_ID_NVIDIA ; 
 int PTR_ERR (TYPE_3__*) ; 
 int acpi_bus_register_driver (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  acpi_bus_unregister_driver (int /*<<< orphan*/ *) ; 
 TYPE_3__* apple_backlight_device ; 
 int /*<<< orphan*/  apple_bl_driver ; 
 int /*<<< orphan*/  apple_bl_registered ; 
 int atomic_xchg (int /*<<< orphan*/ *,int) ; 
 TYPE_3__* backlight_device_register (char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_12__*,struct backlight_properties*) ; 
 int /*<<< orphan*/  backlight_device_unregister (TYPE_3__*) ; 
 int /*<<< orphan*/  backlight_update_status (TYPE_3__*) ; 
 scalar_t__ debug ; 
 TYPE_6__* hw_data ; 
 int inb (int) ; 
 TYPE_6__ intel_chipset_data ; 
 int /*<<< orphan*/  memset (struct backlight_properties*,int /*<<< orphan*/ ,int) ; 
 TYPE_6__ nvidia_chipset_data ; 
 int /*<<< orphan*/  outb (int,int) ; 
 int /*<<< orphan*/  pci_dev_put (struct pci_dev*) ; 
 struct pci_dev* pci_get_domain_bus_and_slot (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_debug (char*,int) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  release_region (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  request_region (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int stub1 (TYPE_3__*) ; 
 int /*<<< orphan*/  stub2 (int) ; 
 int stub3 (TYPE_3__*) ; 
 int /*<<< orphan*/  stub4 (int) ; 
 int stub5 (TYPE_3__*) ; 

__attribute__((used)) static void intel_chipset_set_brightness(int intensity)
{
	outb(0x04 | (intensity << 4), 0xb3);
	outb(0xbf, 0xb2);
}

__attribute__((used)) static int intel_chipset_send_intensity(struct backlight_device *bd)
{
	int intensity = bd->props.brightness;

	if (debug)
		pr_debug("setting brightness to %d\n", intensity);

	intel_chipset_set_brightness(intensity);
	return 0;
}

__attribute__((used)) static int intel_chipset_get_intensity(struct backlight_device *bd)
{
	int intensity;

	outb(0x03, 0xb3);
	outb(0xbf, 0xb2);
	intensity = inb(0xb3) >> 4;

	if (debug)
		pr_debug("read brightness of %d\n", intensity);

	return intensity;
}

__attribute__((used)) static void nvidia_chipset_set_brightness(int intensity)
{
	outb(0x04 | (intensity << 4), 0x52f);
	outb(0xbf, 0x52e);
}

__attribute__((used)) static int nvidia_chipset_send_intensity(struct backlight_device *bd)
{
	int intensity = bd->props.brightness;

	if (debug)
		pr_debug("setting brightness to %d\n", intensity);

	nvidia_chipset_set_brightness(intensity);
	return 0;
}

__attribute__((used)) static int nvidia_chipset_get_intensity(struct backlight_device *bd)
{
	int intensity;

	outb(0x03, 0x52f);
	outb(0xbf, 0x52e);
	intensity = inb(0x52f) >> 4;

	if (debug)
		pr_debug("read brightness of %d\n", intensity);

	return intensity;
}

__attribute__((used)) static int apple_bl_add(struct acpi_device *dev)
{
	struct backlight_properties props;
	struct pci_dev *host;
	int intensity;

	host = pci_get_domain_bus_and_slot(0, 0, 0);

	if (!host) {
		pr_err("unable to find PCI host\n");
		return -ENODEV;
	}

	if (host->vendor == PCI_VENDOR_ID_INTEL)
		hw_data = &intel_chipset_data;
	else if (host->vendor == PCI_VENDOR_ID_NVIDIA)
		hw_data = &nvidia_chipset_data;

	pci_dev_put(host);

	if (!hw_data) {
		pr_err("unknown hardware\n");
		return -ENODEV;
	}

	/* Check that the hardware responds - this may not work under EFI */

	intensity = hw_data->backlight_ops.get_brightness(NULL);

	if (!intensity) {
		hw_data->set_brightness(1);
		if (!hw_data->backlight_ops.get_brightness(NULL))
			return -ENODEV;

		hw_data->set_brightness(0);
	}

	if (!request_region(hw_data->iostart, hw_data->iolen,
			    "Apple backlight"))
		return -ENXIO;

	memset(&props, 0, sizeof(struct backlight_properties));
	props.type = BACKLIGHT_PLATFORM;
	props.max_brightness = 15;
	apple_backlight_device = backlight_device_register("apple_backlight",
				  NULL, NULL, &hw_data->backlight_ops, &props);

	if (IS_ERR(apple_backlight_device)) {
		release_region(hw_data->iostart, hw_data->iolen);
		return PTR_ERR(apple_backlight_device);
	}

	apple_backlight_device->props.brightness =
		hw_data->backlight_ops.get_brightness(apple_backlight_device);
	backlight_update_status(apple_backlight_device);

	return 0;
}

__attribute__((used)) static int apple_bl_remove(struct acpi_device *dev)
{
	backlight_device_unregister(apple_backlight_device);

	release_region(hw_data->iostart, hw_data->iolen);
	hw_data = NULL;
	return 0;
}

int apple_bl_register(void)
{
	if (atomic_xchg(&apple_bl_registered, 1) == 0)
		return acpi_bus_register_driver(&apple_bl_driver);

	return 0;
}

void apple_bl_unregister(void)
{
	if (atomic_xchg(&apple_bl_registered, 0) == 1)
		acpi_bus_unregister_driver(&apple_bl_driver);
}

