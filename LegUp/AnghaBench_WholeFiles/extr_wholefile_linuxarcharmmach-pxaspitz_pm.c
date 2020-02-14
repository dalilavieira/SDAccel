#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_12__ {int flags; TYPE_1__* machinfo; int /*<<< orphan*/  dev; int /*<<< orphan*/  charge_mode; } ;
struct TYPE_10__ {int /*<<< orphan*/ * platform_data; } ;
struct TYPE_11__ {TYPE_2__ dev; } ;
struct TYPE_9__ {int (* read_devdata ) (int) ;int /*<<< orphan*/  gpio_fatal; int /*<<< orphan*/  gpio_batfull; int /*<<< orphan*/  gpio_batlock; int /*<<< orphan*/  (* charge ) (int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_AND_SIZE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CHRG_OFF ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GPIOF_OUT_INIT_HIGH ; 
 int GPIO_bit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MAX1111_ACIN_VOLT ; 
 int /*<<< orphan*/  MAX1111_BATT_TEMP ; 
 int /*<<< orphan*/  MAX1111_BATT_VOLT ; 
 int PCFR ; 
 int PCFR_GPR_EN ; 
 int PCFR_OPDE ; 
 int PEDR ; 
 int PFER ; 
 int PGSR0 ; 
 int PGSR1 ; 
 int PGSR2 ; 
 int PGSR3 ; 
 int PKSR ; 
 int PKWR ; 
 int PRER ; 
 int /*<<< orphan*/  PSLR ; 
 int /*<<< orphan*/  PSLR_SL_ROD ; 
 int PWER ; 
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
 int /*<<< orphan*/  SPITZ_GPIO_AC_IN ; 
 int /*<<< orphan*/  SPITZ_GPIO_ADC_TEMP_ON ; 
 int /*<<< orphan*/  SPITZ_GPIO_CHRG_ON ; 
 int SPITZ_GPIO_G0_STROBE_BIT ; 
 int SPITZ_GPIO_G1_STROBE_BIT ; 
 int SPITZ_GPIO_G2_STROBE_BIT ; 
 int SPITZ_GPIO_G3_STROBE_BIT ; 
 int /*<<< orphan*/  SPITZ_GPIO_JK_A ; 
 int /*<<< orphan*/  SPITZ_GPIO_JK_B ; 
 int /*<<< orphan*/  SPITZ_GPIO_KEY_INT ; 
 int /*<<< orphan*/  SPITZ_GPIO_KEY_STROBE0 ; 
 int /*<<< orphan*/  SPITZ_GPIO_LED_GREEN ; 
 int /*<<< orphan*/  SPITZ_GPIO_RESET ; 
 int /*<<< orphan*/  SPITZ_GPIO_SYNC ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  gpio18_config ; 
 int /*<<< orphan*/  gpio_free (int) ; 
 unsigned long gpio_get_value (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_request_array (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_request_one (int,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 
 scalar_t__ machine_is_akita () ; 
 int /*<<< orphan*/  machine_is_borzoi () ; 
 int /*<<< orphan*/  machine_is_spitz () ; 
 int platform_device_add (TYPE_3__*) ; 
 TYPE_3__* platform_device_alloc (char*,int) ; 
 int /*<<< orphan*/  platform_device_put (TYPE_3__*) ; 
 int /*<<< orphan*/  platform_device_unregister (TYPE_3__*) ; 
 int /*<<< orphan*/  pxa2xx_mfp_config (int /*<<< orphan*/ *,int) ; 
 TYPE_4__ sharpsl_pm ; 
 int /*<<< orphan*/  sharpsl_pm_led (int /*<<< orphan*/ ) ; 
 unsigned long sharpsl_pm_pxa_read_max1111 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spitz_charger_gpios ; 
 int spitz_last_ac_status ; 
 int /*<<< orphan*/  spitz_pm_machinfo ; 
 TYPE_3__* spitzpm_device ; 
 int stub1 (int) ; 
 int stub2 (int) ; 
 int /*<<< orphan*/  stub3 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void pxa2xx_clear_reset_status(unsigned int mask) {}

__attribute__((used)) static void spitz_charger_init(void)
{
	gpio_request_array(ARRAY_AND_SIZE(spitz_charger_gpios));
}

__attribute__((used)) static void spitz_measure_temp(int on)
{
	gpio_set_value(SPITZ_GPIO_ADC_TEMP_ON, on);
}

__attribute__((used)) static void spitz_charge(int on)
{
	if (on) {
		if (sharpsl_pm.flags & SHARPSL_SUSPENDED) {
			gpio_set_value(SPITZ_GPIO_JK_B, 1);
			gpio_set_value(SPITZ_GPIO_CHRG_ON, 0);
		} else {
			gpio_set_value(SPITZ_GPIO_JK_B, 0);
			gpio_set_value(SPITZ_GPIO_CHRG_ON, 0);
		}
	} else {
		gpio_set_value(SPITZ_GPIO_JK_B, 0);
		gpio_set_value(SPITZ_GPIO_CHRG_ON, 1);
	}
}

__attribute__((used)) static void spitz_discharge(int on)
{
	gpio_set_value(SPITZ_GPIO_JK_A, on);
}

__attribute__((used)) static void spitz_discharge1(int on)
{
	gpio_set_value(SPITZ_GPIO_LED_GREEN, on);
}

__attribute__((used)) static void spitz_presuspend(void)
{
	spitz_last_ac_status = sharpsl_pm.machinfo->read_devdata(SHARPSL_STATUS_ACIN);

	/* GPIO Sleep Register */
	PGSR0 = 0x00144018;
	PGSR1 = 0x00EF0000;
	if (machine_is_akita()) {
		PGSR2 = 0x2121C000;
		PGSR3 = 0x00600400;
	} else {
		PGSR2 = 0x0121C000;
		PGSR3 = 0x00600000;
	}

	PGSR0 &= ~SPITZ_GPIO_G0_STROBE_BIT;
	PGSR1 &= ~SPITZ_GPIO_G1_STROBE_BIT;
	PGSR2 &= ~SPITZ_GPIO_G2_STROBE_BIT;
	PGSR3 &= ~SPITZ_GPIO_G3_STROBE_BIT;
	PGSR2 |= GPIO_bit(SPITZ_GPIO_KEY_STROBE0);

	pxa2xx_mfp_config(&gpio18_config, 1);
	gpio_request_one(18, GPIOF_OUT_INIT_HIGH, "Unknown");
	gpio_free(18);

	PRER = GPIO_bit(SPITZ_GPIO_KEY_INT);
	PFER = GPIO_bit(SPITZ_GPIO_KEY_INT) | GPIO_bit(SPITZ_GPIO_RESET);
	PWER = GPIO_bit(SPITZ_GPIO_KEY_INT) | GPIO_bit(SPITZ_GPIO_RESET) | PWER_RTC;
	PKWR = GPIO_bit(SPITZ_GPIO_SYNC) | GPIO_bit(SPITZ_GPIO_KEY_INT) | GPIO_bit(SPITZ_GPIO_RESET);
	PKSR = 0xffffffff; /* clear */

	/* nRESET_OUT Disable */
	PSLR |= PSLR_SL_ROD;

	/* Stop 3.6MHz and drive HIGH to PCMCIA and CS */
	PCFR = PCFR_GPR_EN | PCFR_OPDE;
}

__attribute__((used)) static void spitz_postsuspend(void)
{
}

__attribute__((used)) static int spitz_should_wakeup(unsigned int resume_on_alarm)
{
	int is_resume = 0;
	int acin = sharpsl_pm.machinfo->read_devdata(SHARPSL_STATUS_ACIN);

	if (spitz_last_ac_status != acin) {
		if (acin) {
			/* charge on */
			sharpsl_pm.flags |= SHARPSL_DO_OFFLINE_CHRG;
			dev_dbg(sharpsl_pm.dev, "AC Inserted\n");
		} else {
			/* charge off */
			dev_dbg(sharpsl_pm.dev, "AC Removed\n");
			sharpsl_pm_led(SHARPSL_LED_OFF);
			sharpsl_pm.machinfo->charge(0);
			sharpsl_pm.charge_mode = CHRG_OFF;
		}
		spitz_last_ac_status = acin;
		/* Return to suspend as this must be what we were woken for */
		return 0;
	}

	if (PEDR & GPIO_bit(SPITZ_GPIO_KEY_INT))
		is_resume |= GPIO_bit(SPITZ_GPIO_KEY_INT);

	if (PKSR & GPIO_bit(SPITZ_GPIO_SYNC))
		is_resume |= GPIO_bit(SPITZ_GPIO_SYNC);

	if (resume_on_alarm && (PEDR & PWER_RTC))
		is_resume |= PWER_RTC;

	dev_dbg(sharpsl_pm.dev, "is_resume: %x\n", is_resume);
	return is_resume;
}

__attribute__((used)) static bool spitz_charger_wakeup(void)
{
	return !gpio_get_value(SPITZ_GPIO_KEY_INT) ||
		gpio_get_value(SPITZ_GPIO_SYNC);
}

unsigned long spitzpm_read_devdata(int type)
{
	switch (type) {
	case SHARPSL_STATUS_ACIN:
		return !gpio_get_value(SPITZ_GPIO_AC_IN);
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

__attribute__((used)) static int spitzpm_init(void)
{
	int ret;

	if (!machine_is_spitz() && !machine_is_akita()
			&& !machine_is_borzoi())
		return -ENODEV;

	spitzpm_device = platform_device_alloc("sharpsl-pm", -1);
	if (!spitzpm_device)
		return -ENOMEM;

	spitzpm_device->dev.platform_data = &spitz_pm_machinfo;
	ret = platform_device_add(spitzpm_device);

	if (ret)
		platform_device_put(spitzpm_device);

	return ret;
}

__attribute__((used)) static void spitzpm_exit(void)
{
	platform_device_unregister(spitzpm_device);
}

