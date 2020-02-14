#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct watchdog_device {unsigned int timeout; } ;
struct TYPE_12__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_6__ dev; } ;
struct TYPE_11__ {TYPE_6__* parent; int /*<<< orphan*/  max_timeout; int /*<<< orphan*/  min_timeout; int /*<<< orphan*/ * info; int /*<<< orphan*/ * ops; int /*<<< orphan*/  bootstatus; } ;
struct menf21bmc_wdt {struct i2c_client* i2c_client; TYPE_1__ wdt; } ;
struct i2c_client {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BMC_CMD_RST_RSN ; 
 int /*<<< orphan*/  BMC_CMD_WD_OFF ; 
 int /*<<< orphan*/  BMC_CMD_WD_ON ; 
 int /*<<< orphan*/  BMC_CMD_WD_TIME ; 
 int /*<<< orphan*/  BMC_CMD_WD_TRIG ; 
 unsigned int BMC_WD_OFF_VAL ; 
 int /*<<< orphan*/  BMC_WD_TIMEOUT_MAX ; 
 int /*<<< orphan*/  BMC_WD_TIMEOUT_MIN ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  WDIOF_CARDRESET ; 
 int /*<<< orphan*/  WDIOF_EXTERN1 ; 
 int /*<<< orphan*/  WDIOF_EXTERN2 ; 
 int /*<<< orphan*/  WDIOF_POWERUNDER ; 
 int /*<<< orphan*/  dev_err (TYPE_6__*,char*) ; 
 int /*<<< orphan*/  dev_info (TYPE_6__*,char*) ; 
 int /*<<< orphan*/  dev_warn (TYPE_6__*,char*) ; 
 struct menf21bmc_wdt* devm_kzalloc (TYPE_6__*,int,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_read_word_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_write_byte (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,unsigned int) ; 
 int i2c_smbus_write_word_data (struct i2c_client*,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  menf21bmc_wdt_info ; 
 int /*<<< orphan*/  menf21bmc_wdt_ops ; 
 int /*<<< orphan*/  nowayout ; 
 struct menf21bmc_wdt* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct menf21bmc_wdt*) ; 
 struct i2c_client* to_i2c_client (int /*<<< orphan*/ ) ; 
 struct menf21bmc_wdt* watchdog_get_drvdata (struct watchdog_device*) ; 
 int /*<<< orphan*/  watchdog_init_timeout (TYPE_1__*,int,TYPE_6__*) ; 
 int watchdog_register_device (TYPE_1__*) ; 
 int /*<<< orphan*/  watchdog_set_drvdata (TYPE_1__*,struct menf21bmc_wdt*) ; 
 int /*<<< orphan*/  watchdog_set_nowayout (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  watchdog_unregister_device (TYPE_1__*) ; 

__attribute__((used)) static int menf21bmc_wdt_set_bootstatus(struct menf21bmc_wdt *data)
{
	int rst_rsn;

	rst_rsn = i2c_smbus_read_byte_data(data->i2c_client, BMC_CMD_RST_RSN);
	if (rst_rsn < 0)
		return rst_rsn;

	if (rst_rsn == 0x02)
		data->wdt.bootstatus |= WDIOF_CARDRESET;
	else if (rst_rsn == 0x05)
		data->wdt.bootstatus |= WDIOF_EXTERN1;
	else if (rst_rsn == 0x06)
		data->wdt.bootstatus |= WDIOF_EXTERN2;
	else if (rst_rsn == 0x0A)
		data->wdt.bootstatus |= WDIOF_POWERUNDER;

	return 0;
}

__attribute__((used)) static int menf21bmc_wdt_start(struct watchdog_device *wdt)
{
	struct menf21bmc_wdt *drv_data = watchdog_get_drvdata(wdt);

	return i2c_smbus_write_byte(drv_data->i2c_client, BMC_CMD_WD_ON);
}

__attribute__((used)) static int menf21bmc_wdt_stop(struct watchdog_device *wdt)
{
	struct menf21bmc_wdt *drv_data = watchdog_get_drvdata(wdt);

	return i2c_smbus_write_byte_data(drv_data->i2c_client,
					 BMC_CMD_WD_OFF, BMC_WD_OFF_VAL);
}

__attribute__((used)) static int
menf21bmc_wdt_settimeout(struct watchdog_device *wdt, unsigned int timeout)
{
	int ret;
	struct menf21bmc_wdt *drv_data = watchdog_get_drvdata(wdt);

	/*
	 *  BMC Watchdog does have a resolution of 100ms.
	 *  Watchdog API defines the timeout in seconds, so we have to
	 *  multiply the value.
	 */
	ret = i2c_smbus_write_word_data(drv_data->i2c_client,
					BMC_CMD_WD_TIME, timeout * 10);
	if (ret < 0)
		return ret;

	wdt->timeout = timeout;

	return 0;
}

__attribute__((used)) static int menf21bmc_wdt_ping(struct watchdog_device *wdt)
{
	struct menf21bmc_wdt *drv_data = watchdog_get_drvdata(wdt);

	return i2c_smbus_write_byte(drv_data->i2c_client, BMC_CMD_WD_TRIG);
}

__attribute__((used)) static int menf21bmc_wdt_probe(struct platform_device *pdev)
{
	int ret, bmc_timeout;
	struct menf21bmc_wdt *drv_data;
	struct i2c_client *i2c_client = to_i2c_client(pdev->dev.parent);

	drv_data = devm_kzalloc(&pdev->dev,
				sizeof(struct menf21bmc_wdt), GFP_KERNEL);
	if (!drv_data)
		return -ENOMEM;

	drv_data->wdt.ops = &menf21bmc_wdt_ops;
	drv_data->wdt.info = &menf21bmc_wdt_info;
	drv_data->wdt.min_timeout = BMC_WD_TIMEOUT_MIN;
	drv_data->wdt.max_timeout = BMC_WD_TIMEOUT_MAX;
	drv_data->wdt.parent = &pdev->dev;
	drv_data->i2c_client = i2c_client;

	/*
	 * Get the current wdt timeout value from the BMC because
	 * the BMC will save the value set before if the system restarts.
	 */
	bmc_timeout = i2c_smbus_read_word_data(drv_data->i2c_client,
					       BMC_CMD_WD_TIME);
	if (bmc_timeout < 0) {
		dev_err(&pdev->dev, "failed to get current WDT timeout\n");
		return bmc_timeout;
	}

	watchdog_init_timeout(&drv_data->wdt, bmc_timeout / 10, &pdev->dev);
	watchdog_set_nowayout(&drv_data->wdt, nowayout);
	watchdog_set_drvdata(&drv_data->wdt, drv_data);
	platform_set_drvdata(pdev, drv_data);

	ret = menf21bmc_wdt_set_bootstatus(drv_data);
	if (ret < 0) {
		dev_err(&pdev->dev, "failed to set Watchdog bootstatus\n");
		return ret;
	}

	ret = watchdog_register_device(&drv_data->wdt);
	if (ret) {
		dev_err(&pdev->dev, "failed to register Watchdog device\n");
		return ret;
	}

	dev_info(&pdev->dev, "MEN 14F021P00 BMC Watchdog device enabled\n");

	return 0;
}

__attribute__((used)) static int menf21bmc_wdt_remove(struct platform_device *pdev)
{
	struct menf21bmc_wdt *drv_data = platform_get_drvdata(pdev);

	dev_warn(&pdev->dev,
		 "Unregister MEN 14F021P00 BMC Watchdog device, board may reset\n");

	watchdog_unregister_device(&drv_data->wdt);

	return 0;
}

__attribute__((used)) static void menf21bmc_wdt_shutdown(struct platform_device *pdev)
{
	struct menf21bmc_wdt *drv_data = platform_get_drvdata(pdev);

	i2c_smbus_write_word_data(drv_data->i2c_client,
				  BMC_CMD_WD_OFF, BMC_WD_OFF_VAL);
}

