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
typedef  int u32 ;

/* Variables and functions */
 void* GPIO_DATA ; 
 void* GPIO_DATA_DIRECTION ; 
 void* GPIO_DATA_DIRECTION_SM750LE ; 
 void* GPIO_DATA_SM750LE ; 
 void* GPIO_MUX ; 
 scalar_t__ SM750LE ; 
 int mmio750 ; 
 int readl (int) ; 
 int /*<<< orphan*/  sm750_enable_gpio (int) ; 
 scalar_t__ sm750_get_chip_type () ; 
 int sw_i2c_clk_gpio ; 
 int sw_i2c_clk_gpio_data_dir_reg ; 
 int sw_i2c_clk_gpio_data_reg ; 
 int sw_i2c_clk_gpio_mux_reg ; 
 int sw_i2c_data_gpio ; 
 int sw_i2c_data_gpio_data_dir_reg ; 
 int sw_i2c_data_gpio_data_reg ; 
 int sw_i2c_data_gpio_mux_reg ; 
 int /*<<< orphan*/  writel (int,int) ; 

__attribute__((used)) static inline u32 peek32(u32 addr)
{
	return readl(addr + mmio750);
}

__attribute__((used)) static inline void poke32(u32 addr, u32 data)
{
	writel(data, addr + mmio750);
}

__attribute__((used)) static void sw_i2c_wait(void)
{
	/* find a bug:
	 * peekIO method works well before suspend/resume
	 * but after suspend, peekIO(0x3ce,0x61) & 0x10
	 * always be non-zero,which makes the while loop
	 * never finish.
	 * use non-ultimate for loop below is safe
	 */

    /* Change wait algorithm to use PCI bus clock,
     * it's more reliable than counter loop ..
     * write 0x61 to 0x3ce and read from 0x3cf
     */
	int i, tmp;

	for (i = 0; i < 600; i++) {
		tmp = i;
		tmp += i;
	}
}

__attribute__((used)) static void sw_i2c_scl(unsigned char value)
{
	unsigned long gpio_data;
	unsigned long gpio_dir;

	gpio_dir = peek32(sw_i2c_clk_gpio_data_dir_reg);
	if (value) {    /* High */
		/*
		 * Set direction as input. This will automatically
		 * pull the signal up.
		 */
		gpio_dir &= ~(1 << sw_i2c_clk_gpio);
		poke32(sw_i2c_clk_gpio_data_dir_reg, gpio_dir);
	} else {        /* Low */
		/* Set the signal down */
		gpio_data = peek32(sw_i2c_clk_gpio_data_reg);
		gpio_data &= ~(1 << sw_i2c_clk_gpio);
		poke32(sw_i2c_clk_gpio_data_reg, gpio_data);

		/* Set direction as output */
		gpio_dir |= (1 << sw_i2c_clk_gpio);
		poke32(sw_i2c_clk_gpio_data_dir_reg, gpio_dir);
	}
}

__attribute__((used)) static void sw_i2c_sda(unsigned char value)
{
	unsigned long gpio_data;
	unsigned long gpio_dir;

	gpio_dir = peek32(sw_i2c_data_gpio_data_dir_reg);
	if (value) {    /* High */
		/*
		 * Set direction as input. This will automatically
		 * pull the signal up.
		 */
		gpio_dir &= ~(1 << sw_i2c_data_gpio);
		poke32(sw_i2c_data_gpio_data_dir_reg, gpio_dir);
	} else {        /* Low */
		/* Set the signal down */
		gpio_data = peek32(sw_i2c_data_gpio_data_reg);
		gpio_data &= ~(1 << sw_i2c_data_gpio);
		poke32(sw_i2c_data_gpio_data_reg, gpio_data);

		/* Set direction as output */
		gpio_dir |= (1 << sw_i2c_data_gpio);
		poke32(sw_i2c_data_gpio_data_dir_reg, gpio_dir);
	}
}

__attribute__((used)) static unsigned char sw_i2c_read_sda(void)
{
	unsigned long gpio_dir;
	unsigned long gpio_data;
	unsigned long dir_mask = 1 << sw_i2c_data_gpio;

	/* Make sure that the direction is input (High) */
	gpio_dir = peek32(sw_i2c_data_gpio_data_dir_reg);
	if ((gpio_dir & dir_mask) != ~dir_mask) {
		gpio_dir &= ~(1 << sw_i2c_data_gpio);
		poke32(sw_i2c_data_gpio_data_dir_reg, gpio_dir);
	}

	/* Now read the SDA line */
	gpio_data = peek32(sw_i2c_data_gpio_data_reg);
	if (gpio_data & (1 << sw_i2c_data_gpio))
		return 1;
	else
		return 0;
}

__attribute__((used)) static void sw_i2c_ack(void)
{
	return;  /* Single byte read is ok without it. */
}

__attribute__((used)) static void sw_i2c_start(void)
{
	/* Start I2C */
	sw_i2c_sda(1);
	sw_i2c_scl(1);
	sw_i2c_sda(0);
}

__attribute__((used)) static void sw_i2c_stop(void)
{
	/* Stop the I2C */
	sw_i2c_scl(1);
	sw_i2c_sda(0);
	sw_i2c_sda(1);
}

__attribute__((used)) static long sw_i2c_write_byte(unsigned char data)
{
	unsigned char value = data;
	int i;

	/* Sending the data bit by bit */
	for (i = 0; i < 8; i++) {
		/* Set SCL to low */
		sw_i2c_scl(0);

		/* Send data bit */
		if ((value & 0x80) != 0)
			sw_i2c_sda(1);
		else
			sw_i2c_sda(0);

		sw_i2c_wait();

		/* Toggle clk line to one */
		sw_i2c_scl(1);
		sw_i2c_wait();

		/* Shift byte to be sent */
		value = value << 1;
	}

	/* Set the SCL Low and SDA High (prepare to get input) */
	sw_i2c_scl(0);
	sw_i2c_sda(1);

	/* Set the SCL High for ack */
	sw_i2c_wait();
	sw_i2c_scl(1);
	sw_i2c_wait();

	/* Read SDA, until SDA==0 */
	for (i = 0; i < 0xff; i++) {
		if (!sw_i2c_read_sda())
			break;

		sw_i2c_scl(0);
		sw_i2c_wait();
		sw_i2c_scl(1);
		sw_i2c_wait();
	}

	/* Set the SCL Low and SDA High */
	sw_i2c_scl(0);
	sw_i2c_sda(1);

	if (i < 0xff)
		return 0;
	else
		return -1;
}

__attribute__((used)) static unsigned char sw_i2c_read_byte(unsigned char ack)
{
	int i;
	unsigned char data = 0;

	for (i = 7; i >= 0; i--) {
		/* Set the SCL to Low and SDA to High (Input) */
		sw_i2c_scl(0);
		sw_i2c_sda(1);
		sw_i2c_wait();

		/* Set the SCL High */
		sw_i2c_scl(1);
		sw_i2c_wait();

		/* Read data bits from SDA */
		data |= (sw_i2c_read_sda() << i);
	}

	if (ack)
		sw_i2c_ack();

	/* Set the SCL Low and SDA High */
	sw_i2c_scl(0);
	sw_i2c_sda(1);

	return data;
}

__attribute__((used)) static long sm750le_i2c_init(unsigned char clk_gpio, unsigned char data_gpio)
{
	int i;

	/* Initialize the GPIO pin for the i2c Clock Register */
	sw_i2c_clk_gpio_data_reg = GPIO_DATA_SM750LE;
	sw_i2c_clk_gpio_data_dir_reg = GPIO_DATA_DIRECTION_SM750LE;

	/* Initialize the Clock GPIO Offset */
	sw_i2c_clk_gpio = clk_gpio;

	/* Initialize the GPIO pin for the i2c Data Register */
	sw_i2c_data_gpio_data_reg = GPIO_DATA_SM750LE;
	sw_i2c_data_gpio_data_dir_reg = GPIO_DATA_DIRECTION_SM750LE;

	/* Initialize the Data GPIO Offset */
	sw_i2c_data_gpio = data_gpio;

	/* Note that SM750LE don't have GPIO MUX and power is always on */

	/* Clear the i2c lines. */
	for (i = 0; i < 9; i++)
		sw_i2c_stop();

	return 0;
}

long sm750_sw_i2c_init(unsigned char clk_gpio, unsigned char data_gpio)
{
	int i;

	/*
	 * Return 0 if the GPIO pins to be used is out of range. The
	 * range is only from [0..63]
	 */
	if ((clk_gpio > 31) || (data_gpio > 31))
		return -1;

	if (sm750_get_chip_type() == SM750LE)
		return sm750le_i2c_init(clk_gpio, data_gpio);

	/* Initialize the GPIO pin for the i2c Clock Register */
	sw_i2c_clk_gpio_mux_reg = GPIO_MUX;
	sw_i2c_clk_gpio_data_reg = GPIO_DATA;
	sw_i2c_clk_gpio_data_dir_reg = GPIO_DATA_DIRECTION;

	/* Initialize the Clock GPIO Offset */
	sw_i2c_clk_gpio = clk_gpio;

	/* Initialize the GPIO pin for the i2c Data Register */
	sw_i2c_data_gpio_mux_reg = GPIO_MUX;
	sw_i2c_data_gpio_data_reg = GPIO_DATA;
	sw_i2c_data_gpio_data_dir_reg = GPIO_DATA_DIRECTION;

	/* Initialize the Data GPIO Offset */
	sw_i2c_data_gpio = data_gpio;

	/* Enable the GPIO pins for the i2c Clock and Data (GPIO MUX) */
	poke32(sw_i2c_clk_gpio_mux_reg,
	       peek32(sw_i2c_clk_gpio_mux_reg) & ~(1 << sw_i2c_clk_gpio));
	poke32(sw_i2c_data_gpio_mux_reg,
	       peek32(sw_i2c_data_gpio_mux_reg) & ~(1 << sw_i2c_data_gpio));

	/* Enable GPIO power */
	sm750_enable_gpio(1);

	/* Clear the i2c lines. */
	for (i = 0; i < 9; i++)
		sw_i2c_stop();

	return 0;
}

unsigned char sm750_sw_i2c_read_reg(unsigned char addr, unsigned char reg)
{
	unsigned char data;

	/* Send the Start signal */
	sw_i2c_start();

	/* Send the device address */
	sw_i2c_write_byte(addr);

	/* Send the register index */
	sw_i2c_write_byte(reg);

	/* Get the bus again and get the data from the device read address */
	sw_i2c_start();
	sw_i2c_write_byte(addr + 1);
	data = sw_i2c_read_byte(1);

	/* Stop swI2C and release the bus */
	sw_i2c_stop();

	return data;
}

long sm750_sw_i2c_write_reg(unsigned char addr,
			    unsigned char reg,
			    unsigned char data)
{
	long ret = 0;

	/* Send the Start signal */
	sw_i2c_start();

	/* Send the device address and read the data. All should return success
	 * in order for the writing processed to be successful
	 */
	if ((sw_i2c_write_byte(addr) != 0) ||
	    (sw_i2c_write_byte(reg) != 0) ||
	    (sw_i2c_write_byte(data) != 0)) {
		ret = -1;
	}

	/* Stop i2c and release the bus */
	sw_i2c_stop();

	return ret;
}

