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
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  void* u16 ;
struct vprbrd_gpiob_msg {int clk; unsigned int offset; int t1; int t2; int invert; int pwmlevel; int outval; int risefall; int answer; int __fill; void* mask; void* val; void* cmd; } ;
struct vprbrd_gpioa_msg {int clk; unsigned int offset; int t1; int t2; int invert; int pwmlevel; int outval; int risefall; int answer; int __fill; void* mask; void* val; void* cmd; } ;
struct TYPE_6__ {char* label; int base; int ngpio; int can_sleep; void (* set ) (struct gpio_chip*,unsigned int,int) ;int (* get ) (struct gpio_chip*,unsigned int) ;int (* direction_input ) (struct gpio_chip*,unsigned int) ;int (* direction_output ) (struct gpio_chip*,unsigned int,int) ;TYPE_1__* parent; void* owner; } ;
struct vprbrd_gpio {int gpioa_out; int gpioa_val; int gpiob_out; int gpiob_val; TYPE_3__ gpiob; TYPE_3__ gpioa; struct vprbrd* vb; } ;
struct vprbrd {int /*<<< orphan*/  lock; int /*<<< orphan*/  usb_dev; scalar_t__ buf; } ;
struct TYPE_5__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_1__ dev; } ;
struct gpio_chip {TYPE_1__* parent; } ;

/* Variables and functions */
 int ENOMEM ; 
 int EREMOTEIO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 void* THIS_MODULE ; 
 void* VPRBRD_GPIOA_CMD_GETIN ; 
 void* VPRBRD_GPIOA_CMD_SETIN ; 
 void* VPRBRD_GPIOA_CMD_SETOUT ; 
 void* VPRBRD_GPIOB_CMD_SETDIR ; 
 void* VPRBRD_GPIOB_CMD_SETVAL ; 
 int /*<<< orphan*/  VPRBRD_USB_REQUEST_GPIOA ; 
 int /*<<< orphan*/  VPRBRD_USB_REQUEST_GPIOB ; 
 int /*<<< orphan*/  VPRBRD_USB_TIMEOUT_MS ; 
 int /*<<< orphan*/  VPRBRD_USB_TYPE_IN ; 
 int /*<<< orphan*/  VPRBRD_USB_TYPE_OUT ; 
 int be16_to_cpu (void*) ; 
 void* cpu_to_be16 (int) ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*) ; 
 struct vprbrd* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int devm_gpiochip_add_data (TYPE_1__*,TYPE_3__*,struct vprbrd_gpio*) ; 
 struct vprbrd_gpio* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int gpioa_clk ; 
 struct vprbrd_gpio* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct vprbrd_gpio*) ; 
 int usb_control_msg (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,struct vprbrd_gpiob_msg*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_rcvctrlpipe (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_sndctrlpipe (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int vprbrd_gpioa_get(struct gpio_chip *chip,
		unsigned offset)
{
	int ret, answer, error = 0;
	struct vprbrd_gpio *gpio = gpiochip_get_data(chip);
	struct vprbrd *vb = gpio->vb;
	struct vprbrd_gpioa_msg *gamsg = (struct vprbrd_gpioa_msg *)vb->buf;

	/* if io is set to output, just return the saved value */
	if (gpio->gpioa_out & (1 << offset))
		return !!(gpio->gpioa_val & (1 << offset));

	mutex_lock(&vb->lock);

	gamsg->cmd = VPRBRD_GPIOA_CMD_GETIN;
	gamsg->clk = 0x00;
	gamsg->offset = offset;
	gamsg->t1 = 0x00;
	gamsg->t2 = 0x00;
	gamsg->invert = 0x00;
	gamsg->pwmlevel = 0x00;
	gamsg->outval = 0x00;
	gamsg->risefall = 0x00;
	gamsg->answer = 0x00;
	gamsg->__fill = 0x00;

	ret = usb_control_msg(vb->usb_dev, usb_sndctrlpipe(vb->usb_dev, 0),
		VPRBRD_USB_REQUEST_GPIOA, VPRBRD_USB_TYPE_OUT, 0x0000,
		0x0000, gamsg, sizeof(struct vprbrd_gpioa_msg),
		VPRBRD_USB_TIMEOUT_MS);
	if (ret != sizeof(struct vprbrd_gpioa_msg))
		error = -EREMOTEIO;

	ret = usb_control_msg(vb->usb_dev, usb_rcvctrlpipe(vb->usb_dev, 0),
		VPRBRD_USB_REQUEST_GPIOA, VPRBRD_USB_TYPE_IN, 0x0000,
		0x0000, gamsg, sizeof(struct vprbrd_gpioa_msg),
		VPRBRD_USB_TIMEOUT_MS);
	answer = gamsg->answer & 0x01;

	mutex_unlock(&vb->lock);

	if (ret != sizeof(struct vprbrd_gpioa_msg))
		error = -EREMOTEIO;

	if (error)
		return error;

	return answer;
}

__attribute__((used)) static void vprbrd_gpioa_set(struct gpio_chip *chip,
		unsigned offset, int value)
{
	int ret;
	struct vprbrd_gpio *gpio = gpiochip_get_data(chip);
	struct vprbrd *vb = gpio->vb;
	struct vprbrd_gpioa_msg *gamsg = (struct vprbrd_gpioa_msg *)vb->buf;

	if (gpio->gpioa_out & (1 << offset)) {
		if (value)
			gpio->gpioa_val |= (1 << offset);
		else
			gpio->gpioa_val &= ~(1 << offset);

		mutex_lock(&vb->lock);

		gamsg->cmd = VPRBRD_GPIOA_CMD_SETOUT;
		gamsg->clk = 0x00;
		gamsg->offset = offset;
		gamsg->t1 = 0x00;
		gamsg->t2 = 0x00;
		gamsg->invert = 0x00;
		gamsg->pwmlevel = 0x00;
		gamsg->outval = value;
		gamsg->risefall = 0x00;
		gamsg->answer = 0x00;
		gamsg->__fill = 0x00;

		ret = usb_control_msg(vb->usb_dev,
			usb_sndctrlpipe(vb->usb_dev, 0),
			VPRBRD_USB_REQUEST_GPIOA, VPRBRD_USB_TYPE_OUT,
			0x0000,	0x0000, gamsg,
			sizeof(struct vprbrd_gpioa_msg), VPRBRD_USB_TIMEOUT_MS);

		mutex_unlock(&vb->lock);

		if (ret != sizeof(struct vprbrd_gpioa_msg))
			dev_err(chip->parent, "usb error setting pin value\n");
	}
}

__attribute__((used)) static int vprbrd_gpioa_direction_input(struct gpio_chip *chip,
			unsigned offset)
{
	int ret;
	struct vprbrd_gpio *gpio = gpiochip_get_data(chip);
	struct vprbrd *vb = gpio->vb;
	struct vprbrd_gpioa_msg *gamsg = (struct vprbrd_gpioa_msg *)vb->buf;

	gpio->gpioa_out &= ~(1 << offset);

	mutex_lock(&vb->lock);

	gamsg->cmd = VPRBRD_GPIOA_CMD_SETIN;
	gamsg->clk = gpioa_clk;
	gamsg->offset = offset;
	gamsg->t1 = 0x00;
	gamsg->t2 = 0x00;
	gamsg->invert = 0x00;
	gamsg->pwmlevel = 0x00;
	gamsg->outval = 0x00;
	gamsg->risefall = 0x00;
	gamsg->answer = 0x00;
	gamsg->__fill = 0x00;

	ret = usb_control_msg(vb->usb_dev, usb_sndctrlpipe(vb->usb_dev, 0),
		VPRBRD_USB_REQUEST_GPIOA, VPRBRD_USB_TYPE_OUT, 0x0000,
		0x0000, gamsg, sizeof(struct vprbrd_gpioa_msg),
		VPRBRD_USB_TIMEOUT_MS);

	mutex_unlock(&vb->lock);

	if (ret != sizeof(struct vprbrd_gpioa_msg))
		return -EREMOTEIO;

	return 0;
}

__attribute__((used)) static int vprbrd_gpioa_direction_output(struct gpio_chip *chip,
			unsigned offset, int value)
{
	int ret;
	struct vprbrd_gpio *gpio = gpiochip_get_data(chip);
	struct vprbrd *vb = gpio->vb;
	struct vprbrd_gpioa_msg *gamsg = (struct vprbrd_gpioa_msg *)vb->buf;

	gpio->gpioa_out |= (1 << offset);
	if (value)
		gpio->gpioa_val |= (1 << offset);
	else
		gpio->gpioa_val &= ~(1 << offset);

	mutex_lock(&vb->lock);

	gamsg->cmd = VPRBRD_GPIOA_CMD_SETOUT;
	gamsg->clk = 0x00;
	gamsg->offset = offset;
	gamsg->t1 = 0x00;
	gamsg->t2 = 0x00;
	gamsg->invert = 0x00;
	gamsg->pwmlevel = 0x00;
	gamsg->outval = value;
	gamsg->risefall = 0x00;
	gamsg->answer = 0x00;
	gamsg->__fill = 0x00;

	ret = usb_control_msg(vb->usb_dev, usb_sndctrlpipe(vb->usb_dev, 0),
		VPRBRD_USB_REQUEST_GPIOA, VPRBRD_USB_TYPE_OUT, 0x0000,
		0x0000, gamsg, sizeof(struct vprbrd_gpioa_msg),
		VPRBRD_USB_TIMEOUT_MS);

	mutex_unlock(&vb->lock);

	if (ret != sizeof(struct vprbrd_gpioa_msg))
		return -EREMOTEIO;

	return 0;
}

__attribute__((used)) static int vprbrd_gpiob_setdir(struct vprbrd *vb, unsigned offset,
	unsigned dir)
{
	struct vprbrd_gpiob_msg *gbmsg = (struct vprbrd_gpiob_msg *)vb->buf;
	int ret;

	gbmsg->cmd = VPRBRD_GPIOB_CMD_SETDIR;
	gbmsg->val = cpu_to_be16(dir << offset);
	gbmsg->mask = cpu_to_be16(0x0001 << offset);

	ret = usb_control_msg(vb->usb_dev, usb_sndctrlpipe(vb->usb_dev, 0),
		VPRBRD_USB_REQUEST_GPIOB, VPRBRD_USB_TYPE_OUT, 0x0000,
		0x0000, gbmsg, sizeof(struct vprbrd_gpiob_msg),
		VPRBRD_USB_TIMEOUT_MS);

	if (ret != sizeof(struct vprbrd_gpiob_msg))
		return -EREMOTEIO;

	return 0;
}

__attribute__((used)) static int vprbrd_gpiob_get(struct gpio_chip *chip,
		unsigned offset)
{
	int ret;
	u16 val;
	struct vprbrd_gpio *gpio = gpiochip_get_data(chip);
	struct vprbrd *vb = gpio->vb;
	struct vprbrd_gpiob_msg *gbmsg = (struct vprbrd_gpiob_msg *)vb->buf;

	/* if io is set to output, just return the saved value */
	if (gpio->gpiob_out & (1 << offset))
		return gpio->gpiob_val & (1 << offset);

	mutex_lock(&vb->lock);

	ret = usb_control_msg(vb->usb_dev, usb_rcvctrlpipe(vb->usb_dev, 0),
		VPRBRD_USB_REQUEST_GPIOB, VPRBRD_USB_TYPE_IN, 0x0000,
		0x0000, gbmsg,	sizeof(struct vprbrd_gpiob_msg),
		VPRBRD_USB_TIMEOUT_MS);
	val = gbmsg->val;

	mutex_unlock(&vb->lock);

	if (ret != sizeof(struct vprbrd_gpiob_msg))
		return ret;

	/* cache the read values */
	gpio->gpiob_val = be16_to_cpu(val);

	return (gpio->gpiob_val >> offset) & 0x1;
}

__attribute__((used)) static void vprbrd_gpiob_set(struct gpio_chip *chip,
		unsigned offset, int value)
{
	int ret;
	struct vprbrd_gpio *gpio = gpiochip_get_data(chip);
	struct vprbrd *vb = gpio->vb;
	struct vprbrd_gpiob_msg *gbmsg = (struct vprbrd_gpiob_msg *)vb->buf;

	if (gpio->gpiob_out & (1 << offset)) {
		if (value)
			gpio->gpiob_val |= (1 << offset);
		else
			gpio->gpiob_val &= ~(1 << offset);

		mutex_lock(&vb->lock);

		gbmsg->cmd = VPRBRD_GPIOB_CMD_SETVAL;
		gbmsg->val = cpu_to_be16(value << offset);
		gbmsg->mask = cpu_to_be16(0x0001 << offset);

		ret = usb_control_msg(vb->usb_dev,
			usb_sndctrlpipe(vb->usb_dev, 0),
			VPRBRD_USB_REQUEST_GPIOB, VPRBRD_USB_TYPE_OUT,
			0x0000,	0x0000, gbmsg,
			sizeof(struct vprbrd_gpiob_msg), VPRBRD_USB_TIMEOUT_MS);

		mutex_unlock(&vb->lock);

		if (ret != sizeof(struct vprbrd_gpiob_msg))
			dev_err(chip->parent, "usb error setting pin value\n");
	}
}

__attribute__((used)) static int vprbrd_gpiob_direction_input(struct gpio_chip *chip,
			unsigned offset)
{
	int ret;
	struct vprbrd_gpio *gpio = gpiochip_get_data(chip);
	struct vprbrd *vb = gpio->vb;

	gpio->gpiob_out &= ~(1 << offset);

	mutex_lock(&vb->lock);

	ret = vprbrd_gpiob_setdir(vb, offset, 0);

	mutex_unlock(&vb->lock);

	if (ret)
		dev_err(chip->parent, "usb error setting pin to input\n");

	return ret;
}

__attribute__((used)) static int vprbrd_gpiob_direction_output(struct gpio_chip *chip,
			unsigned offset, int value)
{
	int ret;
	struct vprbrd_gpio *gpio = gpiochip_get_data(chip);
	struct vprbrd *vb = gpio->vb;

	gpio->gpiob_out |= (1 << offset);

	mutex_lock(&vb->lock);

	ret = vprbrd_gpiob_setdir(vb, offset, 1);
	if (ret)
		dev_err(chip->parent, "usb error setting pin to output\n");

	mutex_unlock(&vb->lock);

	vprbrd_gpiob_set(chip, offset, value);

	return ret;
}

__attribute__((used)) static int vprbrd_gpio_probe(struct platform_device *pdev)
{
	struct vprbrd *vb = dev_get_drvdata(pdev->dev.parent);
	struct vprbrd_gpio *vb_gpio;
	int ret;

	vb_gpio = devm_kzalloc(&pdev->dev, sizeof(*vb_gpio), GFP_KERNEL);
	if (vb_gpio == NULL)
		return -ENOMEM;

	vb_gpio->vb = vb;
	/* registering gpio a */
	vb_gpio->gpioa.label = "viperboard gpio a";
	vb_gpio->gpioa.parent = &pdev->dev;
	vb_gpio->gpioa.owner = THIS_MODULE;
	vb_gpio->gpioa.base = -1;
	vb_gpio->gpioa.ngpio = 16;
	vb_gpio->gpioa.can_sleep = true;
	vb_gpio->gpioa.set = vprbrd_gpioa_set;
	vb_gpio->gpioa.get = vprbrd_gpioa_get;
	vb_gpio->gpioa.direction_input = vprbrd_gpioa_direction_input;
	vb_gpio->gpioa.direction_output = vprbrd_gpioa_direction_output;
	ret = devm_gpiochip_add_data(&pdev->dev, &vb_gpio->gpioa, vb_gpio);
	if (ret < 0) {
		dev_err(vb_gpio->gpioa.parent, "could not add gpio a");
		return ret;
	}

	/* registering gpio b */
	vb_gpio->gpiob.label = "viperboard gpio b";
	vb_gpio->gpiob.parent = &pdev->dev;
	vb_gpio->gpiob.owner = THIS_MODULE;
	vb_gpio->gpiob.base = -1;
	vb_gpio->gpiob.ngpio = 16;
	vb_gpio->gpiob.can_sleep = true;
	vb_gpio->gpiob.set = vprbrd_gpiob_set;
	vb_gpio->gpiob.get = vprbrd_gpiob_get;
	vb_gpio->gpiob.direction_input = vprbrd_gpiob_direction_input;
	vb_gpio->gpiob.direction_output = vprbrd_gpiob_direction_output;
	ret = devm_gpiochip_add_data(&pdev->dev, &vb_gpio->gpiob, vb_gpio);
	if (ret < 0) {
		dev_err(vb_gpio->gpiob.parent, "could not add gpio b");
		return ret;
	}

	platform_set_drvdata(pdev, vb_gpio);

	return ret;
}

