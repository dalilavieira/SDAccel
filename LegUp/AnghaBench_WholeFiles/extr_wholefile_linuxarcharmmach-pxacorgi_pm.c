#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_9__ ;
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct TYPE_14__ {int batfull_irq; } ;
struct TYPE_11__ {TYPE_9__* platform_data; } ;
struct TYPE_13__ {TYPE_2__ dev; } ;
struct TYPE_12__ {int flags; TYPE_1__* machinfo; int /*<<< orphan*/  dev; int /*<<< orphan*/  charge_mode; } ;
struct TYPE_10__ {int /*<<< orphan*/  gpio_fatal; int /*<<< orphan*/  gpio_batfull; int /*<<< orphan*/  gpio_batlock; int /*<<< orphan*/  (* charge ) (int /*<<< orphan*/ ) ;scalar_t__ (* read_devdata ) (int) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_AND_SIZE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CHRG_OFF ; 
 int /*<<< orphan*/  CORGI_GPIO_AC_IN ; 
 int /*<<< orphan*/  CORGI_GPIO_ADC_TEMP_ON ; 
 int /*<<< orphan*/  CORGI_GPIO_CHRG_FULL ; 
 int /*<<< orphan*/  CORGI_GPIO_CHRG_ON ; 
 int /*<<< orphan*/  CORGI_GPIO_CHRG_UKN ; 
 int /*<<< orphan*/  CORGI_GPIO_DISCHARGE_ON ; 
 int /*<<< orphan*/  CORGI_GPIO_KEY_INT ; 
 int /*<<< orphan*/  CORGI_GPIO_WAKEUP ; 
 int ENODEV ; 
 int ENOMEM ; 
 int GPIO_bit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MAX1111_ACIN_VOLT ; 
 int /*<<< orphan*/  MAX1111_BATT_TEMP ; 
 int /*<<< orphan*/  MAX1111_BATT_VOLT ; 
 int PEDR ; 
 int PWER_RTC ; 
#define  SHARPSL_ACIN_VOLT 134 
#define  SHARPSL_BATT_TEMP 133 
#define  SHARPSL_BATT_VOLT 132 
 int SHARPSL_DO_OFFLINE_CHRG ; 
 int /*<<< orphan*/  SHARPSL_LED_OFF ; 
#define  SHARPSL_STATUS_ACIN 131 
#define  SHARPSL_STATUS_CHRGFULL 130 
#define  SHARPSL_STATUS_FATAL 129 
#define  SHARPSL_STATUS_LOCK 128 
 int SHARPSL_SUSPENDED ; 
 int /*<<< orphan*/  charger_gpios ; 
 TYPE_9__ corgi_pm_machinfo ; 
 TYPE_4__* corgipm_device ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,...) ; 
 unsigned long gpio_get_value (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_request_array (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 
 scalar_t__ machine_is_corgi () ; 
 int /*<<< orphan*/  machine_is_husky () ; 
 int /*<<< orphan*/  machine_is_shepherd () ; 
 int platform_device_add (TYPE_4__*) ; 
 TYPE_4__* platform_device_alloc (char*,int) ; 
 int /*<<< orphan*/  platform_device_put (TYPE_4__*) ; 
 int /*<<< orphan*/  platform_device_unregister (TYPE_4__*) ; 
 TYPE_3__ sharpsl_pm ; 
 int /*<<< orphan*/  sharpsl_pm_led (int /*<<< orphan*/ ) ; 
 unsigned long sharpsl_pm_pxa_read_max1111 (int /*<<< orphan*/ ) ; 
 scalar_t__ stub1 (int) ; 
 int /*<<< orphan*/  stub2 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void pxa2xx_clear_reset_status(unsigned int mask) {}

__attribute__((used)) static void corgi_charger_init(void)
{
	gpio_request_array(ARRAY_AND_SIZE(charger_gpios));
}

__attribute__((used)) static void corgi_measure_temp(int on)
{
	gpio_set_value(CORGI_GPIO_ADC_TEMP_ON, on);
}

__attribute__((used)) static void corgi_charge(int on)
{
	if (on) {
		if (machine_is_corgi() && (sharpsl_pm.flags & SHARPSL_SUSPENDED)) {
			gpio_set_value(CORGI_GPIO_CHRG_ON, 0);
			gpio_set_value(CORGI_GPIO_CHRG_UKN, 1);
		} else {
			gpio_set_value(CORGI_GPIO_CHRG_ON, 1);
			gpio_set_value(CORGI_GPIO_CHRG_UKN, 0);
		}
	} else {
		gpio_set_value(CORGI_GPIO_CHRG_ON, 0);
		gpio_set_value(CORGI_GPIO_CHRG_UKN, 0);
	}
}

__attribute__((used)) static void corgi_discharge(int on)
{
	gpio_set_value(CORGI_GPIO_DISCHARGE_ON, on);
}

__attribute__((used)) static void corgi_presuspend(void)
{
}

__attribute__((used)) static void corgi_postsuspend(void)
{
}

__attribute__((used)) static int corgi_should_wakeup(unsigned int resume_on_alarm)
{
	int is_resume = 0;

	dev_dbg(sharpsl_pm.dev, "PEDR = %x, GPIO_AC_IN = %d, "
		"GPIO_CHRG_FULL = %d, GPIO_KEY_INT = %d, GPIO_WAKEUP = %d\n",
		PEDR, gpio_get_value(CORGI_GPIO_AC_IN),
		gpio_get_value(CORGI_GPIO_CHRG_FULL),
		gpio_get_value(CORGI_GPIO_KEY_INT),
		gpio_get_value(CORGI_GPIO_WAKEUP));

	if ((PEDR & GPIO_bit(CORGI_GPIO_AC_IN))) {
		if (sharpsl_pm.machinfo->read_devdata(SHARPSL_STATUS_ACIN)) {
			/* charge on */
			dev_dbg(sharpsl_pm.dev, "ac insert\n");
			sharpsl_pm.flags |= SHARPSL_DO_OFFLINE_CHRG;
		} else {
			/* charge off */
			dev_dbg(sharpsl_pm.dev, "ac remove\n");
			sharpsl_pm_led(SHARPSL_LED_OFF);
			sharpsl_pm.machinfo->charge(0);
			sharpsl_pm.charge_mode = CHRG_OFF;
		}
	}

	if ((PEDR & GPIO_bit(CORGI_GPIO_CHRG_FULL)))
		dev_dbg(sharpsl_pm.dev, "Charge full interrupt\n");

	if (PEDR & GPIO_bit(CORGI_GPIO_KEY_INT))
		is_resume |= GPIO_bit(CORGI_GPIO_KEY_INT);

	if (PEDR & GPIO_bit(CORGI_GPIO_WAKEUP))
		is_resume |= GPIO_bit(CORGI_GPIO_WAKEUP);

	if (resume_on_alarm && (PEDR & PWER_RTC))
		is_resume |= PWER_RTC;

	dev_dbg(sharpsl_pm.dev, "is_resume: %x\n",is_resume);
	return is_resume;
}

__attribute__((used)) static bool corgi_charger_wakeup(void)
{
	return !gpio_get_value(CORGI_GPIO_AC_IN) ||
		!gpio_get_value(CORGI_GPIO_KEY_INT) ||
		!gpio_get_value(CORGI_GPIO_WAKEUP);
}

unsigned long corgipm_read_devdata(int type)
{
	switch(type) {
	case SHARPSL_STATUS_ACIN:
		return !gpio_get_value(CORGI_GPIO_AC_IN);
	case SHARPSL_STATUS_LOCK:
		return gpio_get_value(sharpsl_pm.machinfo->gpio_batlock);
	case SHARPSL_STATUS_CHRGFULL:
		return gpio_get_value(sharpsl_pm.machinfo->gpio_batfull);
	case SHARPSL_STATUS_FATAL:
		return gpio_get_value(sharpsl_pm.machinfo->gpio_fatal);
	case SHARPSL_ACIN_VOLT:
		return sharpsl_pm_pxa_read_max1111(MAX1111_ACIN_VOLT);
	case SHARPSL_BATT_TEMP:
		return sharpsl_pm_pxa_read_max1111(MAX1111_BATT_TEMP);
	case SHARPSL_BATT_VOLT:
	default:
		return sharpsl_pm_pxa_read_max1111(MAX1111_BATT_VOLT);
	}
}

__attribute__((used)) static int corgipm_init(void)
{
	int ret;

	if (!machine_is_corgi() && !machine_is_shepherd()
			&& !machine_is_husky())
		return -ENODEV;

	corgipm_device = platform_device_alloc("sharpsl-pm", -1);
	if (!corgipm_device)
		return -ENOMEM;

	if (!machine_is_corgi())
	    corgi_pm_machinfo.batfull_irq = 1;

	corgipm_device->dev.platform_data = &corgi_pm_machinfo;
	ret = platform_device_add(corgipm_device);

	if (ret)
		platform_device_put(corgipm_device);

	return ret;
}

__attribute__((used)) static void corgipm_exit(void)
{
	platform_device_unregister(corgipm_device);
}

