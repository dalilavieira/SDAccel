#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  unsigned int u8 ;
struct l3_pins {void (* setclk ) (struct l3_pins*,int) ;void (* setdat ) (struct l3_pins*,unsigned int) ;void (* setmode ) (struct l3_pins*,int) ;int /*<<< orphan*/  gpio_mode; int /*<<< orphan*/  gpio_clk; int /*<<< orphan*/  gpio_data; int /*<<< orphan*/  use_gpios; int /*<<< orphan*/  mode_hold; int /*<<< orphan*/  mode_setup; int /*<<< orphan*/  mode; int /*<<< orphan*/  clock_high; int /*<<< orphan*/  data_setup; int /*<<< orphan*/  data_hold; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  GPIOF_OUT_INIT_LOW ; 
 int devm_gpio_request_one (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 
 void stub1 (struct l3_pins*,int) ; 
 void stub10 (struct l3_pins*,int) ; 
 void stub11 (struct l3_pins*,int) ; 
 void stub12 (struct l3_pins*,int) ; 
 void stub2 (struct l3_pins*,unsigned int) ; 
 void stub3 (struct l3_pins*,int) ; 
 void stub4 (struct l3_pins*,int) ; 
 void stub5 (struct l3_pins*,int) ; 
 void stub6 (struct l3_pins*,int) ; 
 void stub7 (struct l3_pins*,int) ; 
 void stub8 (struct l3_pins*,int) ; 
 void stub9 (struct l3_pins*,int) ; 
 int /*<<< orphan*/  udelay (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void sendbyte(struct l3_pins *adap, unsigned int byte)
{
	int i;

	for (i = 0; i < 8; i++) {
		adap->setclk(adap, 0);
		udelay(adap->data_hold);
		adap->setdat(adap, byte & 1);
		udelay(adap->data_setup);
		adap->setclk(adap, 1);
		udelay(adap->clock_high);
		byte >>= 1;
	}
}

__attribute__((used)) static void sendbytes(struct l3_pins *adap, const u8 *buf,
		      int len)
{
	int i;

	for (i = 0; i < len; i++) {
		if (i) {
			udelay(adap->mode_hold);
			adap->setmode(adap, 0);
			udelay(adap->mode);
		}
		adap->setmode(adap, 1);
		udelay(adap->mode_setup);
		sendbyte(adap, buf[i]);
	}
}

int l3_write(struct l3_pins *adap, u8 addr, u8 *data, int len)
{
	adap->setclk(adap, 1);
	adap->setdat(adap, 1);
	adap->setmode(adap, 1);
	udelay(adap->mode);

	adap->setmode(adap, 0);
	udelay(adap->mode_setup);
	sendbyte(adap, addr);
	udelay(adap->mode_hold);

	sendbytes(adap, data, len);

	adap->setclk(adap, 1);
	adap->setdat(adap, 1);
	adap->setmode(adap, 0);

	return len;
}

__attribute__((used)) static void l3_set_clk(struct l3_pins *adap, int val)
{
	gpio_set_value(adap->gpio_clk, val);
}

__attribute__((used)) static void l3_set_data(struct l3_pins *adap, int val)
{
	gpio_set_value(adap->gpio_data, val);
}

__attribute__((used)) static void l3_set_mode(struct l3_pins *adap, int val)
{
	gpio_set_value(adap->gpio_mode, val);
}

int l3_set_gpio_ops(struct device *dev, struct l3_pins *adap)
{
	int ret;

	if (!adap->use_gpios)
		return -EINVAL;

	ret = devm_gpio_request_one(dev, adap->gpio_data,
				GPIOF_OUT_INIT_LOW, "l3_data");
	if (ret < 0)
		return ret;
	adap->setdat = l3_set_data;

	ret = devm_gpio_request_one(dev, adap->gpio_clk,
				GPIOF_OUT_INIT_LOW, "l3_clk");
	if (ret < 0)
		return ret;
	adap->setclk = l3_set_clk;

	ret = devm_gpio_request_one(dev, adap->gpio_mode,
				GPIOF_OUT_INIT_LOW, "l3_mode");
	if (ret < 0)
		return ret;
	adap->setmode = l3_set_mode;

	return 0;
}

