#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct watchdog_device {unsigned int timeout; struct device* parent; int /*<<< orphan*/  max_timeout; int /*<<< orphan*/  min_timeout; int /*<<< orphan*/ * ops; int /*<<< orphan*/ * info; } ;
struct ni903x_wdt {scalar_t__ io_base; struct watchdog_device wdd; struct device* dev; } ;
struct device {int dummy; } ;
struct TYPE_3__ {scalar_t__ minimum; int /*<<< orphan*/  address_length; } ;
struct TYPE_4__ {TYPE_1__ io; } ;
struct acpi_resource {int type; TYPE_2__ data; } ;
struct acpi_device {int /*<<< orphan*/  handle; struct ni903x_wdt* driver_data; struct device dev; } ;
typedef  int /*<<< orphan*/  acpi_status ;

/* Variables and functions */
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
#define  ACPI_RESOURCE_TYPE_END_TAG 129 
#define  ACPI_RESOURCE_TYPE_IO 128 
 int /*<<< orphan*/  AE_ERROR ; 
 int /*<<< orphan*/  AE_OK ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  METHOD_NAME__CRS ; 
 scalar_t__ NIWD_CONTROL ; 
 int NIWD_CONTROL_CAPTURECOUNTER ; 
 int NIWD_CONTROL_MODE ; 
 int NIWD_CONTROL_PET ; 
 int NIWD_CONTROL_PROC_RESET ; 
 int NIWD_CONTROL_RESET ; 
 scalar_t__ NIWD_COUNTER0 ; 
 scalar_t__ NIWD_COUNTER1 ; 
 scalar_t__ NIWD_COUNTER2 ; 
 unsigned int NIWD_DEFAULT_TIMEOUT ; 
 int /*<<< orphan*/  NIWD_IO_SIZE ; 
 int /*<<< orphan*/  NIWD_MAX_TIMEOUT ; 
 int /*<<< orphan*/  NIWD_MIN_TIMEOUT ; 
 int /*<<< orphan*/  NIWD_NAME ; 
 int NIWD_PERIOD_NS ; 
 scalar_t__ NIWD_SEED0 ; 
 scalar_t__ NIWD_SEED1 ; 
 scalar_t__ NIWD_SEED2 ; 
 struct ni903x_wdt* acpi_driver_data (struct acpi_device*) ; 
 int /*<<< orphan*/  acpi_walk_resources (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (struct acpi_resource*,void*),struct ni903x_wdt*) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct ni903x_wdt* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_request_region (struct device*,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int inb (scalar_t__) ; 
 int /*<<< orphan*/  ni903x_wdd_info ; 
 int /*<<< orphan*/  ni903x_wdd_ops ; 
 int /*<<< orphan*/  nowayout ; 
 int /*<<< orphan*/  outb (int,scalar_t__) ; 
 int /*<<< orphan*/  timeout ; 
 struct ni903x_wdt* watchdog_get_drvdata (struct watchdog_device*) ; 
 int watchdog_init_timeout (struct watchdog_device*,int /*<<< orphan*/ ,struct device*) ; 
 int watchdog_register_device (struct watchdog_device*) ; 
 int /*<<< orphan*/  watchdog_set_drvdata (struct watchdog_device*,struct ni903x_wdt*) ; 
 int /*<<< orphan*/  watchdog_set_nowayout (struct watchdog_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  watchdog_unregister_device (struct watchdog_device*) ; 

__attribute__((used)) static void ni903x_start(struct ni903x_wdt *wdt)
{
	u8 control = inb(wdt->io_base + NIWD_CONTROL);

	outb(control | NIWD_CONTROL_RESET, wdt->io_base + NIWD_CONTROL);
	outb(control | NIWD_CONTROL_PET, wdt->io_base + NIWD_CONTROL);
}

__attribute__((used)) static int ni903x_wdd_set_timeout(struct watchdog_device *wdd,
				  unsigned int timeout)
{
	struct ni903x_wdt *wdt = watchdog_get_drvdata(wdd);
	u32 counter = timeout * (1000000000 / NIWD_PERIOD_NS);

	outb(((0x00FF0000 & counter) >> 16), wdt->io_base + NIWD_SEED2);
	outb(((0x0000FF00 & counter) >> 8), wdt->io_base + NIWD_SEED1);
	outb((0x000000FF & counter), wdt->io_base + NIWD_SEED0);

	wdd->timeout = timeout;

	return 0;
}

__attribute__((used)) static unsigned int ni903x_wdd_get_timeleft(struct watchdog_device *wdd)
{
	struct ni903x_wdt *wdt = watchdog_get_drvdata(wdd);
	u8 control, counter0, counter1, counter2;
	u32 counter;

	control = inb(wdt->io_base + NIWD_CONTROL);
	control |= NIWD_CONTROL_CAPTURECOUNTER;
	outb(control, wdt->io_base + NIWD_CONTROL);

	counter2 = inb(wdt->io_base + NIWD_COUNTER2);
	counter1 = inb(wdt->io_base + NIWD_COUNTER1);
	counter0 = inb(wdt->io_base + NIWD_COUNTER0);

	counter = (counter2 << 16) | (counter1 << 8) | counter0;

	return counter / (1000000000 / NIWD_PERIOD_NS);
}

__attribute__((used)) static int ni903x_wdd_ping(struct watchdog_device *wdd)
{
	struct ni903x_wdt *wdt = watchdog_get_drvdata(wdd);
	u8 control;

	control = inb(wdt->io_base + NIWD_CONTROL);
	outb(control | NIWD_CONTROL_PET, wdt->io_base + NIWD_CONTROL);

	return 0;
}

__attribute__((used)) static int ni903x_wdd_start(struct watchdog_device *wdd)
{
	struct ni903x_wdt *wdt = watchdog_get_drvdata(wdd);

	outb(NIWD_CONTROL_RESET | NIWD_CONTROL_PROC_RESET,
	     wdt->io_base + NIWD_CONTROL);

	ni903x_wdd_set_timeout(wdd, wdd->timeout);
	ni903x_start(wdt);

	return 0;
}

__attribute__((used)) static int ni903x_wdd_stop(struct watchdog_device *wdd)
{
	struct ni903x_wdt *wdt = watchdog_get_drvdata(wdd);

	outb(NIWD_CONTROL_RESET, wdt->io_base + NIWD_CONTROL);

	return 0;
}

__attribute__((used)) static acpi_status ni903x_resources(struct acpi_resource *res, void *data)
{
	struct ni903x_wdt *wdt = data;
	u16 io_size;

	switch (res->type) {
	case ACPI_RESOURCE_TYPE_IO:
		if (wdt->io_base != 0) {
			dev_err(wdt->dev, "too many IO resources\n");
			return AE_ERROR;
		}

		wdt->io_base = res->data.io.minimum;
		io_size = res->data.io.address_length;

		if (io_size < NIWD_IO_SIZE) {
			dev_err(wdt->dev, "memory region too small\n");
			return AE_ERROR;
		}

		if (!devm_request_region(wdt->dev, wdt->io_base, io_size,
					 NIWD_NAME)) {
			dev_err(wdt->dev, "failed to get memory region\n");
			return AE_ERROR;
		}

		return AE_OK;

	case ACPI_RESOURCE_TYPE_END_TAG:
	default:
		/* Ignore unsupported resources, e.g. IRQ */
		return AE_OK;
	}
}

__attribute__((used)) static int ni903x_acpi_add(struct acpi_device *device)
{
	struct device *dev = &device->dev;
	struct watchdog_device *wdd;
	struct ni903x_wdt *wdt;
	acpi_status status;
	int ret;

	wdt = devm_kzalloc(dev, sizeof(*wdt), GFP_KERNEL);
	if (!wdt)
		return -ENOMEM;

	device->driver_data = wdt;
	wdt->dev = dev;

	status = acpi_walk_resources(device->handle, METHOD_NAME__CRS,
				     ni903x_resources, wdt);
	if (ACPI_FAILURE(status) || wdt->io_base == 0) {
		dev_err(dev, "failed to get resources\n");
		return -ENODEV;
	}

	wdd = &wdt->wdd;
	wdd->info = &ni903x_wdd_info;
	wdd->ops = &ni903x_wdd_ops;
	wdd->min_timeout = NIWD_MIN_TIMEOUT;
	wdd->max_timeout = NIWD_MAX_TIMEOUT;
	wdd->timeout = NIWD_DEFAULT_TIMEOUT;
	wdd->parent = dev;
	watchdog_set_drvdata(wdd, wdt);
	watchdog_set_nowayout(wdd, nowayout);
	ret = watchdog_init_timeout(wdd, timeout, dev);
	if (ret)
		dev_err(dev, "unable to set timeout value, using default\n");

	ret = watchdog_register_device(wdd);
	if (ret) {
		dev_err(dev, "failed to register watchdog\n");
		return ret;
	}

	/* Switch from boot mode to user mode */
	outb(NIWD_CONTROL_RESET | NIWD_CONTROL_MODE,
	     wdt->io_base + NIWD_CONTROL);

	dev_dbg(dev, "io_base=0x%04X, timeout=%d, nowayout=%d\n",
		wdt->io_base, timeout, nowayout);

	return 0;
}

__attribute__((used)) static int ni903x_acpi_remove(struct acpi_device *device)
{
	struct ni903x_wdt *wdt = acpi_driver_data(device);

	ni903x_wdd_stop(&wdt->wdd);
	watchdog_unregister_device(&wdt->wdd);

	return 0;
}

