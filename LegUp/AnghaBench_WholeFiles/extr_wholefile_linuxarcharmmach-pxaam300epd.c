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
struct fb_info {struct broadsheetfb_par* par; } ;
struct broadsheetfb_par {int /*<<< orphan*/  waitq; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
#define  BS_CS 130 
#define  BS_DC 129 
#define  BS_WR 128 
 int CFG_GPIO_PIN ; 
 int CS_GPIO_PIN ; 
 int DB0_GPIO_PIN ; 
 int DB15_GPIO_PIN ; 
 int DC_GPIO_PIN ; 
 int /*<<< orphan*/  IRQF_TRIGGER_RISING ; 
 int IRQ_GPIO_PIN ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int PWR_GPIO_PIN ; 
 int /*<<< orphan*/  PXA_GPIO_TO_IRQ (int) ; 
 int RDY_GPIO_PIN ; 
 int RD_GPIO_PIN ; 
 int RST_GPIO_PIN ; 
 int WR_GPIO_PIN ; 
 TYPE_1__* am300_device ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  free_irq (int /*<<< orphan*/ ,struct broadsheetfb_par*) ; 
 int /*<<< orphan*/  gpio_direction_input (int) ; 
 int /*<<< orphan*/  gpio_direction_output (int,int) ; 
 int /*<<< orphan*/  gpio_free (int) ; 
 scalar_t__ gpio_get_value (int) ; 
 char** gpio_names ; 
 int gpio_request (int,char*) ; 
 int /*<<< orphan*/  gpio_set_value (int,int) ; 
 int* gpios ; 
 int /*<<< orphan*/  msleep (int) ; 
 int panel_type ; 
 int request_irq (int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct broadsheetfb_par*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  wait_event (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void pxa2xx_clear_reset_status(unsigned int mask) {}

__attribute__((used)) static int am300_wait_event(struct broadsheetfb_par *par)
{
	/* todo: improve err recovery */
	wait_event(par->waitq, gpio_get_value(RDY_GPIO_PIN));
	return 0;
}

__attribute__((used)) static int am300_init_gpio_regs(struct broadsheetfb_par *par)
{
	int i;
	int err;
	char dbname[8];

	for (i = 0; i < ARRAY_SIZE(gpios); i++) {
		err = gpio_request(gpios[i], gpio_names[i]);
		if (err) {
			dev_err(&am300_device->dev, "failed requesting "
				"gpio %s, err=%d\n", gpio_names[i], err);
			goto err_req_gpio;
		}
	}

	/* we also need to take care of the hdb bus */
	for (i = DB0_GPIO_PIN; i <= DB15_GPIO_PIN; i++) {
		sprintf(dbname, "DB%d", i);
		err = gpio_request(i, dbname);
		if (err) {
			dev_err(&am300_device->dev, "failed requesting "
				"gpio %d, err=%d\n", i, err);
			goto err_req_gpio2;
		}
	}

	/* setup the outputs and init values */
	gpio_direction_output(PWR_GPIO_PIN, 0);
	gpio_direction_output(CFG_GPIO_PIN, 1);
	gpio_direction_output(DC_GPIO_PIN, 0);
	gpio_direction_output(RD_GPIO_PIN, 1);
	gpio_direction_output(WR_GPIO_PIN, 1);
	gpio_direction_output(CS_GPIO_PIN, 1);
	gpio_direction_output(RST_GPIO_PIN, 0);

	/* setup the inputs */
	gpio_direction_input(RDY_GPIO_PIN);
	gpio_direction_input(IRQ_GPIO_PIN);

	/* start the hdb bus as an input */
	for (i = DB0_GPIO_PIN; i <= DB15_GPIO_PIN; i++)
		gpio_direction_output(i, 0);

	/* go into command mode */
	gpio_set_value(CFG_GPIO_PIN, 1);
	gpio_set_value(RST_GPIO_PIN, 0);
	msleep(10);
	gpio_set_value(RST_GPIO_PIN, 1);
	msleep(10);
	am300_wait_event(par);

	return 0;

err_req_gpio2:
	while (--i >= DB0_GPIO_PIN)
		gpio_free(i);
	i = ARRAY_SIZE(gpios);
err_req_gpio:
	while (--i >= 0)
		gpio_free(gpios[i]);

	return err;
}

__attribute__((used)) static int am300_init_board(struct broadsheetfb_par *par)
{
	return am300_init_gpio_regs(par);
}

__attribute__((used)) static void am300_cleanup(struct broadsheetfb_par *par)
{
	int i;

	free_irq(PXA_GPIO_TO_IRQ(RDY_GPIO_PIN), par);

	for (i = 0; i < ARRAY_SIZE(gpios); i++)
		gpio_free(gpios[i]);

	for (i = DB0_GPIO_PIN; i <= DB15_GPIO_PIN; i++)
		gpio_free(i);

}

__attribute__((used)) static u16 am300_get_hdb(struct broadsheetfb_par *par)
{
	u16 res = 0;
	int i;

	for (i = 0; i <= (DB15_GPIO_PIN - DB0_GPIO_PIN) ; i++)
		res |= (gpio_get_value(DB0_GPIO_PIN + i)) ? (1 << i) : 0;

	return res;
}

__attribute__((used)) static void am300_set_hdb(struct broadsheetfb_par *par, u16 data)
{
	int i;

	for (i = 0; i <= (DB15_GPIO_PIN - DB0_GPIO_PIN) ; i++)
		gpio_set_value(DB0_GPIO_PIN + i, (data >> i) & 0x01);
}

__attribute__((used)) static void am300_set_ctl(struct broadsheetfb_par *par, unsigned char bit,
				u8 state)
{
	switch (bit) {
	case BS_CS:
		gpio_set_value(CS_GPIO_PIN, state);
		break;
	case BS_DC:
		gpio_set_value(DC_GPIO_PIN, state);
		break;
	case BS_WR:
		gpio_set_value(WR_GPIO_PIN, state);
		break;
	}
}

__attribute__((used)) static int am300_get_panel_type(void)
{
	return panel_type;
}

__attribute__((used)) static irqreturn_t am300_handle_irq(int irq, void *dev_id)
{
	struct broadsheetfb_par *par = dev_id;

	wake_up(&par->waitq);
	return IRQ_HANDLED;
}

__attribute__((used)) static int am300_setup_irq(struct fb_info *info)
{
	int ret;
	struct broadsheetfb_par *par = info->par;

	ret = request_irq(PXA_GPIO_TO_IRQ(RDY_GPIO_PIN), am300_handle_irq,
				IRQF_TRIGGER_RISING, "AM300", par);
	if (ret)
		dev_err(&am300_device->dev, "request_irq failed: %d\n", ret);

	return ret;
}

