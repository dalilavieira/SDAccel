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
typedef  int u32 ;
struct ssp_device {int /*<<< orphan*/  irq; int /*<<< orphan*/  clk; } ;
struct platform_device {int /*<<< orphan*/  dev; int /*<<< orphan*/  name; } ;
struct navpoint_platform_data {int port; int /*<<< orphan*/  gpio; } ;
struct navpoint {int* data; int index; struct input_dev* input; struct ssp_device* ssp; int /*<<< orphan*/  gpio; int /*<<< orphan*/ * dev; } ;
struct TYPE_2__ {int /*<<< orphan*/ * parent; } ;
struct input_dev {int (* open ) (struct input_dev*) ;void (* close ) (struct input_dev*) ;int /*<<< orphan*/  keybit; int /*<<< orphan*/  evbit; TYPE_1__ dev; int /*<<< orphan*/  name; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  ABS_PRESSURE ; 
 int /*<<< orphan*/  ABS_X ; 
 int /*<<< orphan*/  ABS_Y ; 
 int /*<<< orphan*/  BTN_LEFT ; 
 int /*<<< orphan*/  BTN_TOOL_FINGER ; 
 int /*<<< orphan*/  BTN_TOUCH ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_ABS ; 
 int /*<<< orphan*/  EV_KEY ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOF_OUT_INIT_LOW ; 
 int HEADER_LENGTH (int) ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 int /*<<< orphan*/  NAVPOINT_PRESSURE_MAX ; 
 int /*<<< orphan*/  NAVPOINT_PRESSURE_MIN ; 
 int /*<<< orphan*/  NAVPOINT_X_MAX ; 
 int /*<<< orphan*/  NAVPOINT_X_MIN ; 
 int /*<<< orphan*/  NAVPOINT_Y_MAX ; 
 int /*<<< orphan*/  NAVPOINT_Y_MIN ; 
 int /*<<< orphan*/  SSCR0 ; 
 int SSCR0_SSE ; 
 int /*<<< orphan*/  SSCR1 ; 
 int /*<<< orphan*/  SSDR ; 
 int /*<<< orphan*/  SSSR ; 
 int SSSR_CSS ; 
 int SSSR_RNE ; 
 int /*<<< orphan*/  SSTO ; 
 int /*<<< orphan*/  __set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_prepare_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct navpoint_platform_data* dev_get_platdata (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*,int,...) ; 
 int /*<<< orphan*/  free_irq (int /*<<< orphan*/ ,struct navpoint*) ; 
 int /*<<< orphan*/  gpio_free (int /*<<< orphan*/ ) ; 
 scalar_t__ gpio_is_valid (int /*<<< orphan*/ ) ; 
 int gpio_request_one (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 
 struct input_dev* input_allocate_device () ; 
 int /*<<< orphan*/  input_free_device (struct input_dev*) ; 
 struct navpoint* input_get_drvdata (struct input_dev*) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_report_abs (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_report_key (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_set_abs_params (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  input_set_drvdata (struct input_dev*,struct navpoint*) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 int /*<<< orphan*/  input_unregister_device (struct input_dev*) ; 
 int /*<<< orphan*/  kfree (struct navpoint*) ; 
 struct navpoint* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msleep (int) ; 
 struct navpoint* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct navpoint*) ; 
 int /*<<< orphan*/  pxa_ssp_free (struct ssp_device*) ; 
 int pxa_ssp_read_reg (struct ssp_device*,int /*<<< orphan*/ ) ; 
 struct ssp_device* pxa_ssp_request (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pxa_ssp_write_reg (struct ssp_device*,int /*<<< orphan*/ ,int) ; 
 int request_irq (int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct navpoint*) ; 
 int sscr0 ; 
 int sscr1 ; 
 int sssr ; 

__attribute__((used)) static void navpoint_packet(struct navpoint *navpoint)
{
	int finger;
	int gesture;
	int x, y, z;

	switch (navpoint->data[0]) {
	case 0xff:	/* Garbage (packet?) between reset and Hello packet */
	case 0x00:	/* Module 0, NULL packet */
		break;

	case 0x0e:	/* Module 0, Absolute packet */
		finger = (navpoint->data[1] & 0x01);
		gesture = (navpoint->data[1] & 0x02);
		x = ((navpoint->data[2] & 0x1f) << 8) | navpoint->data[3];
		y = ((navpoint->data[4] & 0x1f) << 8) | navpoint->data[5];
		z = navpoint->data[6];
		input_report_key(navpoint->input, BTN_TOUCH, finger);
		input_report_abs(navpoint->input, ABS_X, x);
		input_report_abs(navpoint->input, ABS_Y, y);
		input_report_abs(navpoint->input, ABS_PRESSURE, z);
		input_report_key(navpoint->input, BTN_TOOL_FINGER, finger);
		input_report_key(navpoint->input, BTN_LEFT, gesture);
		input_sync(navpoint->input);
		break;

	case 0x19:	/* Module 0, Hello packet */
		if ((navpoint->data[1] & 0xf0) == 0x10)
			break;
		/* FALLTHROUGH */
	default:
		dev_warn(navpoint->dev,
			 "spurious packet: data=0x%02x,0x%02x,...\n",
			 navpoint->data[0], navpoint->data[1]);
		break;
	}
}

__attribute__((used)) static irqreturn_t navpoint_irq(int irq, void *dev_id)
{
	struct navpoint *navpoint = dev_id;
	struct ssp_device *ssp = navpoint->ssp;
	irqreturn_t ret = IRQ_NONE;
	u32 status;

	status = pxa_ssp_read_reg(ssp, SSSR);
	if (status & sssr) {
		dev_warn(navpoint->dev,
			 "unexpected interrupt: status=0x%08x\n", status);
		pxa_ssp_write_reg(ssp, SSSR, (status & sssr));
		ret = IRQ_HANDLED;
	}

	while (status & SSSR_RNE) {
		u32 data;

		data = pxa_ssp_read_reg(ssp, SSDR);
		navpoint->data[navpoint->index + 0] = (data >> 8);
		navpoint->data[navpoint->index + 1] = data;
		navpoint->index += 2;
		if (HEADER_LENGTH(navpoint->data[0]) < navpoint->index) {
			navpoint_packet(navpoint);
			navpoint->index = 0;
		}
		status = pxa_ssp_read_reg(ssp, SSSR);
		ret = IRQ_HANDLED;
	}

	return ret;
}

__attribute__((used)) static void navpoint_up(struct navpoint *navpoint)
{
	struct ssp_device *ssp = navpoint->ssp;
	int timeout;

	clk_prepare_enable(ssp->clk);

	pxa_ssp_write_reg(ssp, SSCR1, sscr1);
	pxa_ssp_write_reg(ssp, SSSR, sssr);
	pxa_ssp_write_reg(ssp, SSTO, 0);
	pxa_ssp_write_reg(ssp, SSCR0, sscr0);	/* SSCR0_SSE written last */

	/* Wait until SSP port is ready for slave clock operations */
	for (timeout = 100; timeout != 0; --timeout) {
		if (!(pxa_ssp_read_reg(ssp, SSSR) & SSSR_CSS))
			break;
		msleep(1);
	}

	if (timeout == 0)
		dev_err(navpoint->dev,
			"timeout waiting for SSSR[CSS] to clear\n");

	if (gpio_is_valid(navpoint->gpio))
		gpio_set_value(navpoint->gpio, 1);
}

__attribute__((used)) static void navpoint_down(struct navpoint *navpoint)
{
	struct ssp_device *ssp = navpoint->ssp;

	if (gpio_is_valid(navpoint->gpio))
		gpio_set_value(navpoint->gpio, 0);

	pxa_ssp_write_reg(ssp, SSCR0, 0);

	clk_disable_unprepare(ssp->clk);
}

__attribute__((used)) static int navpoint_open(struct input_dev *input)
{
	struct navpoint *navpoint = input_get_drvdata(input);

	navpoint_up(navpoint);

	return 0;
}

__attribute__((used)) static void navpoint_close(struct input_dev *input)
{
	struct navpoint *navpoint = input_get_drvdata(input);

	navpoint_down(navpoint);
}

__attribute__((used)) static int navpoint_probe(struct platform_device *pdev)
{
	const struct navpoint_platform_data *pdata =
					dev_get_platdata(&pdev->dev);
	struct ssp_device *ssp;
	struct input_dev *input;
	struct navpoint *navpoint;
	int error;

	if (!pdata) {
		dev_err(&pdev->dev, "no platform data\n");
		return -EINVAL;
	}

	if (gpio_is_valid(pdata->gpio)) {
		error = gpio_request_one(pdata->gpio, GPIOF_OUT_INIT_LOW,
					 "SYNAPTICS_ON");
		if (error)
			return error;
	}

	ssp = pxa_ssp_request(pdata->port, pdev->name);
	if (!ssp) {
		error = -ENODEV;
		goto err_free_gpio;
	}

	/* HaRET does not disable devices before jumping into Linux */
	if (pxa_ssp_read_reg(ssp, SSCR0) & SSCR0_SSE) {
		pxa_ssp_write_reg(ssp, SSCR0, 0);
		dev_warn(&pdev->dev, "ssp%d already enabled\n", pdata->port);
	}

	navpoint = kzalloc(sizeof(*navpoint), GFP_KERNEL);
	input = input_allocate_device();
	if (!navpoint || !input) {
		error = -ENOMEM;
		goto err_free_mem;
	}

	navpoint->ssp = ssp;
	navpoint->input = input;
	navpoint->dev = &pdev->dev;
	navpoint->gpio = pdata->gpio;

	input->name = pdev->name;
	input->dev.parent = &pdev->dev;

	__set_bit(EV_KEY, input->evbit);
	__set_bit(EV_ABS, input->evbit);
	__set_bit(BTN_LEFT, input->keybit);
	__set_bit(BTN_TOUCH, input->keybit);
	__set_bit(BTN_TOOL_FINGER, input->keybit);

	input_set_abs_params(input, ABS_X,
			     NAVPOINT_X_MIN, NAVPOINT_X_MAX, 0, 0);
	input_set_abs_params(input, ABS_Y,
			     NAVPOINT_Y_MIN, NAVPOINT_Y_MAX, 0, 0);
	input_set_abs_params(input, ABS_PRESSURE,
			     NAVPOINT_PRESSURE_MIN, NAVPOINT_PRESSURE_MAX,
			     0, 0);

	input->open = navpoint_open;
	input->close = navpoint_close;

	input_set_drvdata(input, navpoint);

	error = request_irq(ssp->irq, navpoint_irq, 0, pdev->name, navpoint);
	if (error)
		goto err_free_mem;

	error = input_register_device(input);
	if (error)
		goto err_free_irq;

	platform_set_drvdata(pdev, navpoint);
	dev_dbg(&pdev->dev, "ssp%d, irq %d\n", pdata->port, ssp->irq);

	return 0;

err_free_irq:
	free_irq(ssp->irq, navpoint);
err_free_mem:
	input_free_device(input);
	kfree(navpoint);
	pxa_ssp_free(ssp);
err_free_gpio:
	if (gpio_is_valid(pdata->gpio))
		gpio_free(pdata->gpio);

	return error;
}

__attribute__((used)) static int navpoint_remove(struct platform_device *pdev)
{
	const struct navpoint_platform_data *pdata =
					dev_get_platdata(&pdev->dev);
	struct navpoint *navpoint = platform_get_drvdata(pdev);
	struct ssp_device *ssp = navpoint->ssp;

	free_irq(ssp->irq, navpoint);

	input_unregister_device(navpoint->input);
	kfree(navpoint);

	pxa_ssp_free(ssp);

	if (gpio_is_valid(pdata->gpio))
		gpio_free(pdata->gpio);

	return 0;
}

