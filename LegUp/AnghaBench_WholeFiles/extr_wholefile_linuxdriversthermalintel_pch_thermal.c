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
typedef  int u8 ;
typedef  int u16 ;
struct thermal_zone_device {struct pch_thermal_device* devdata; } ;
struct pci_device_id {int driver_data; } ;
struct pci_dev {int /*<<< orphan*/  dev; } ;
struct pch_thermal_device {int psv_trip_id; int bios_enabled; int crt_trip_id; int crt_temp; int hot_trip_id; int hot_temp; int psv_temp; TYPE_1__* ops; scalar_t__ hw_base; int /*<<< orphan*/  tzd; struct pci_dev* pdev; } ;
struct device {int dummy; } ;
struct board_info {int /*<<< orphan*/  name; TYPE_1__* ops; } ;
typedef  enum thermal_trip_type { ____Placeholder_thermal_trip_type } thermal_trip_type ;
typedef  enum board_ids { ____Placeholder_board_ids } board_ids ;
struct TYPE_2__ {int (* get_temp ) (struct pch_thermal_device*,int*) ;int (* hw_init ) (struct pch_thermal_device*,int*) ;int (* suspend ) (struct pch_thermal_device*) ;int (* resume ) (struct pch_thermal_device*) ;} ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int THERMAL_TRIP_CRITICAL ; 
 int THERMAL_TRIP_HOT ; 
 int THERMAL_TRIP_PASSIVE ; 
 scalar_t__ WPT_CTT ; 
 scalar_t__ WPT_PHL ; 
 scalar_t__ WPT_TEMP ; 
 int WPT_TEMP_TSR ; 
 scalar_t__ WPT_TSEL ; 
 int WPT_TSEL_ETS ; 
 int WPT_TSEL_PLDB ; 
 struct board_info* board_info ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct pch_thermal_device* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  driver_name ; 
 int /*<<< orphan*/  iounmap (scalar_t__) ; 
 int /*<<< orphan*/  pci_disable_device (struct pci_dev*) ; 
 int pci_enable_device (struct pci_dev*) ; 
 struct pch_thermal_device* pci_get_drvdata (struct pci_dev*) ; 
 scalar_t__ pci_ioremap_bar (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_release_region (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_release_regions (struct pci_dev*) ; 
 int pci_request_regions (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_set_drvdata (struct pci_dev*,struct pch_thermal_device*) ; 
 int readb (scalar_t__) ; 
 int readw (scalar_t__) ; 
 int stub1 (struct pch_thermal_device*,int*) ; 
 int stub2 (struct pch_thermal_device*,int*) ; 
 int stub3 (struct pch_thermal_device*) ; 
 int stub4 (struct pch_thermal_device*) ; 
 int /*<<< orphan*/  thermal_zone_device_register (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,struct pch_thermal_device*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  thermal_zone_device_unregister (int /*<<< orphan*/ ) ; 
 struct pci_dev* to_pci_dev (struct device*) ; 
 int /*<<< orphan*/  tzd_ops ; 
 int /*<<< orphan*/  writeb (int,scalar_t__) ; 

__attribute__((used)) static void pch_wpt_add_acpi_psv_trip(struct pch_thermal_device *ptd,
				      int *nr_trips)
{
	ptd->psv_trip_id = -1;

}

__attribute__((used)) static int pch_wpt_init(struct pch_thermal_device *ptd, int *nr_trips)
{
	u8 tsel;
	u16 trip_temp;

	*nr_trips = 0;

	/* Check if BIOS has already enabled thermal sensor */
	if (WPT_TSEL_ETS & readb(ptd->hw_base + WPT_TSEL)) {
		ptd->bios_enabled = true;
		goto read_trips;
	}

	tsel = readb(ptd->hw_base + WPT_TSEL);
	/*
	 * When TSEL's Policy Lock-Down bit is 1, TSEL become RO.
	 * If so, thermal sensor cannot enable. Bail out.
	 */
	if (tsel & WPT_TSEL_PLDB) {
		dev_err(&ptd->pdev->dev, "Sensor can't be enabled\n");
		return -ENODEV;
	}

	writeb(tsel|WPT_TSEL_ETS, ptd->hw_base + WPT_TSEL);
	if (!(WPT_TSEL_ETS & readb(ptd->hw_base + WPT_TSEL))) {
		dev_err(&ptd->pdev->dev, "Sensor can't be enabled\n");
		return -ENODEV;
	}

read_trips:
	ptd->crt_trip_id = -1;
	trip_temp = readw(ptd->hw_base + WPT_CTT);
	trip_temp &= 0x1FF;
	if (trip_temp) {
		/* Resolution of 1/2 degree C and an offset of -50C */
		ptd->crt_temp = trip_temp * 1000 / 2 - 50000;
		ptd->crt_trip_id = 0;
		++(*nr_trips);
	}

	ptd->hot_trip_id = -1;
	trip_temp = readw(ptd->hw_base + WPT_PHL);
	trip_temp &= 0x1FF;
	if (trip_temp) {
		/* Resolution of 1/2 degree C and an offset of -50C */
		ptd->hot_temp = trip_temp * 1000 / 2 - 50000;
		ptd->hot_trip_id = *nr_trips;
		++(*nr_trips);
	}

	pch_wpt_add_acpi_psv_trip(ptd, nr_trips);

	return 0;
}

__attribute__((used)) static int pch_wpt_get_temp(struct pch_thermal_device *ptd, int *temp)
{
	u16 wpt_temp;

	wpt_temp = WPT_TEMP_TSR & readw(ptd->hw_base + WPT_TEMP);

	/* Resolution of 1/2 degree C and an offset of -50C */
	*temp = (wpt_temp * 1000 / 2 - 50000);

	return 0;
}

__attribute__((used)) static int pch_wpt_suspend(struct pch_thermal_device *ptd)
{
	u8 tsel;

	if (ptd->bios_enabled)
		return 0;

	tsel = readb(ptd->hw_base + WPT_TSEL);

	writeb(tsel & 0xFE, ptd->hw_base + WPT_TSEL);

	return 0;
}

__attribute__((used)) static int pch_wpt_resume(struct pch_thermal_device *ptd)
{
	u8 tsel;

	if (ptd->bios_enabled)
		return 0;

	tsel = readb(ptd->hw_base + WPT_TSEL);

	writeb(tsel | WPT_TSEL_ETS, ptd->hw_base + WPT_TSEL);

	return 0;
}

__attribute__((used)) static int pch_thermal_get_temp(struct thermal_zone_device *tzd, int *temp)
{
	struct pch_thermal_device *ptd = tzd->devdata;

	return	ptd->ops->get_temp(ptd, temp);
}

__attribute__((used)) static int pch_get_trip_type(struct thermal_zone_device *tzd, int trip,
			     enum thermal_trip_type *type)
{
	struct pch_thermal_device *ptd = tzd->devdata;

	if (ptd->crt_trip_id == trip)
		*type = THERMAL_TRIP_CRITICAL;
	else if (ptd->hot_trip_id == trip)
		*type = THERMAL_TRIP_HOT;
	else if (ptd->psv_trip_id == trip)
		*type = THERMAL_TRIP_PASSIVE;
	else
		return -EINVAL;

	return 0;
}

__attribute__((used)) static int pch_get_trip_temp(struct thermal_zone_device *tzd, int trip, int *temp)
{
	struct pch_thermal_device *ptd = tzd->devdata;

	if (ptd->crt_trip_id == trip)
		*temp = ptd->crt_temp;
	else if (ptd->hot_trip_id == trip)
		*temp = ptd->hot_temp;
	else if (ptd->psv_trip_id == trip)
		*temp = ptd->psv_temp;
	else
		return -EINVAL;

	return 0;
}

__attribute__((used)) static int intel_pch_thermal_probe(struct pci_dev *pdev,
				   const struct pci_device_id *id)
{
	enum board_ids board_id = id->driver_data;
	const struct board_info *bi = &board_info[board_id];
	struct pch_thermal_device *ptd;
	int err;
	int nr_trips;

	ptd = devm_kzalloc(&pdev->dev, sizeof(*ptd), GFP_KERNEL);
	if (!ptd)
		return -ENOMEM;

	ptd->ops = bi->ops;

	pci_set_drvdata(pdev, ptd);
	ptd->pdev = pdev;

	err = pci_enable_device(pdev);
	if (err) {
		dev_err(&pdev->dev, "failed to enable pci device\n");
		return err;
	}

	err = pci_request_regions(pdev, driver_name);
	if (err) {
		dev_err(&pdev->dev, "failed to request pci region\n");
		goto error_disable;
	}

	ptd->hw_base = pci_ioremap_bar(pdev, 0);
	if (!ptd->hw_base) {
		err = -ENOMEM;
		dev_err(&pdev->dev, "failed to map mem base\n");
		goto error_release;
	}

	err = ptd->ops->hw_init(ptd, &nr_trips);
	if (err)
		goto error_cleanup;

	ptd->tzd = thermal_zone_device_register(bi->name, nr_trips, 0, ptd,
						&tzd_ops, NULL, 0, 0);
	if (IS_ERR(ptd->tzd)) {
		dev_err(&pdev->dev, "Failed to register thermal zone %s\n",
			bi->name);
		err = PTR_ERR(ptd->tzd);
		goto error_cleanup;
	}

	return 0;

error_cleanup:
	iounmap(ptd->hw_base);
error_release:
	pci_release_regions(pdev);
error_disable:
	pci_disable_device(pdev);
	dev_err(&pdev->dev, "pci device failed to probe\n");
	return err;
}

__attribute__((used)) static void intel_pch_thermal_remove(struct pci_dev *pdev)
{
	struct pch_thermal_device *ptd = pci_get_drvdata(pdev);

	thermal_zone_device_unregister(ptd->tzd);
	iounmap(ptd->hw_base);
	pci_set_drvdata(pdev, NULL);
	pci_release_region(pdev, 0);
	pci_disable_device(pdev);
}

__attribute__((used)) static int intel_pch_thermal_suspend(struct device *device)
{
	struct pci_dev *pdev = to_pci_dev(device);
	struct pch_thermal_device *ptd = pci_get_drvdata(pdev);

	return ptd->ops->suspend(ptd);
}

__attribute__((used)) static int intel_pch_thermal_resume(struct device *device)
{
	struct pci_dev *pdev = to_pci_dev(device);
	struct pch_thermal_device *ptd = pci_get_drvdata(pdev);

	return ptd->ops->resume(ptd);
}

