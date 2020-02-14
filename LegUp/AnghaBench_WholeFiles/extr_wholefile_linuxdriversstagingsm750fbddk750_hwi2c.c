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
typedef  unsigned int u32 ;

/* Variables and functions */
 unsigned int GPIO_MUX ; 
 unsigned int GPIO_MUX_30 ; 
 unsigned int GPIO_MUX_31 ; 
 unsigned int HWI2C_WAIT_TIMEOUT ; 
 unsigned int I2C_BYTE_COUNT ; 
 unsigned int I2C_CTRL ; 
 unsigned int I2C_CTRL_CTRL ; 
 unsigned int I2C_CTRL_EN ; 
 unsigned int I2C_CTRL_MODE ; 
 unsigned int I2C_DATA0 ; 
 unsigned int I2C_RESET ; 
 unsigned int I2C_SLAVE_ADDRESS ; 
 unsigned int I2C_STATUS ; 
 unsigned int I2C_STATUS_TX ; 
 unsigned int MAX_HWI2C_FIFO ; 
 unsigned int mmio750 ; 
 unsigned int readl (unsigned int) ; 
 int /*<<< orphan*/  sm750_enable_i2c (int) ; 
 int /*<<< orphan*/  writel (unsigned int,unsigned int) ; 

__attribute__((used)) static inline u32 peek32(u32 addr)
{
	return readl(addr + mmio750);
}

__attribute__((used)) static inline void poke32(u32 addr, u32 data)
{
	writel(data, addr + mmio750);
}

int sm750_hw_i2c_init(unsigned char bus_speed_mode)
{
	unsigned int value;

	/* Enable GPIO 30 & 31 as IIC clock & data */
	value = peek32(GPIO_MUX);

	value |= (GPIO_MUX_30 | GPIO_MUX_31);
	poke32(GPIO_MUX, value);

	/*
	 * Enable Hardware I2C power.
	 * TODO: Check if we need to enable GPIO power?
	 */
	sm750_enable_i2c(1);

	/* Enable the I2C Controller and set the bus speed mode */
	value = peek32(I2C_CTRL) & ~(I2C_CTRL_MODE | I2C_CTRL_EN);
	if (bus_speed_mode)
		value |= I2C_CTRL_MODE;
	value |= I2C_CTRL_EN;
	poke32(I2C_CTRL, value);

	return 0;
}

void sm750_hw_i2c_close(void)
{
	unsigned int value;

	/* Disable I2C controller */
	value = peek32(I2C_CTRL) & ~I2C_CTRL_EN;
	poke32(I2C_CTRL, value);

	/* Disable I2C Power */
	sm750_enable_i2c(0);

	/* Set GPIO 30 & 31 back as GPIO pins */
	value = peek32(GPIO_MUX);
	value &= ~GPIO_MUX_30;
	value &= ~GPIO_MUX_31;
	poke32(GPIO_MUX, value);
}

__attribute__((used)) static long hw_i2c_wait_tx_done(void)
{
	unsigned int timeout;

	/* Wait until the transfer is completed. */
	timeout = HWI2C_WAIT_TIMEOUT;
	while (!(peek32(I2C_STATUS) & I2C_STATUS_TX) && (timeout != 0))
		timeout--;

	if (timeout == 0)
		return -1;

	return 0;
}

__attribute__((used)) static unsigned int hw_i2c_write_data(unsigned char addr,
				      unsigned int length,
				      unsigned char *buf)
{
	unsigned char count, i;
	unsigned int total_bytes = 0;

	/* Set the Device Address */
	poke32(I2C_SLAVE_ADDRESS, addr & ~0x01);

	/*
	 * Write data.
	 * Note:
	 *      Only 16 byte can be accessed per i2c start instruction.
	 */
	do {
		/*
		 * Reset I2C by writing 0 to I2C_RESET register to
		 * clear the previous status.
		 */
		poke32(I2C_RESET, 0);

		/* Set the number of bytes to be written */
		if (length < MAX_HWI2C_FIFO)
			count = length - 1;
		else
			count = MAX_HWI2C_FIFO - 1;
		poke32(I2C_BYTE_COUNT, count);

		/* Move the data to the I2C data register */
		for (i = 0; i <= count; i++)
			poke32(I2C_DATA0 + i, *buf++);

		/* Start the I2C */
		poke32(I2C_CTRL, peek32(I2C_CTRL) | I2C_CTRL_CTRL);

		/* Wait until the transfer is completed. */
		if (hw_i2c_wait_tx_done() != 0)
			break;

		/* Subtract length */
		length -= (count + 1);

		/* Total byte written */
		total_bytes += (count + 1);

	} while (length > 0);

	return total_bytes;
}

__attribute__((used)) static unsigned int hw_i2c_read_data(unsigned char addr,
				     unsigned int length,
				     unsigned char *buf)
{
	unsigned char count, i;
	unsigned int total_bytes = 0;

	/* Set the Device Address */
	poke32(I2C_SLAVE_ADDRESS, addr | 0x01);

	/*
	 * Read data and save them to the buffer.
	 * Note:
	 *      Only 16 byte can be accessed per i2c start instruction.
	 */
	do {
		/*
		 * Reset I2C by writing 0 to I2C_RESET register to
		 * clear all the status.
		 */
		poke32(I2C_RESET, 0);

		/* Set the number of bytes to be read */
		if (length <= MAX_HWI2C_FIFO)
			count = length - 1;
		else
			count = MAX_HWI2C_FIFO - 1;
		poke32(I2C_BYTE_COUNT, count);

		/* Start the I2C */
		poke32(I2C_CTRL, peek32(I2C_CTRL) | I2C_CTRL_CTRL);

		/* Wait until transaction done. */
		if (hw_i2c_wait_tx_done() != 0)
			break;

		/* Save the data to the given buffer */
		for (i = 0; i <= count; i++)
			*buf++ = peek32(I2C_DATA0 + i);

		/* Subtract length by 16 */
		length -= (count + 1);

		/* Number of bytes read. */
		total_bytes += (count + 1);

	} while (length > 0);

	return total_bytes;
}

unsigned char sm750_hw_i2c_read_reg(unsigned char addr, unsigned char reg)
{
	unsigned char value = 0xFF;

	if (hw_i2c_write_data(addr, 1, &reg) == 1)
		hw_i2c_read_data(addr, 1, &value);

	return value;
}

int sm750_hw_i2c_write_reg(unsigned char addr,
			   unsigned char reg,
			   unsigned char data)
{
	unsigned char value[2];

	value[0] = reg;
	value[1] = data;
	if (hw_i2c_write_data(addr, 2, value) == 2)
		return 0;

	return -1;
}

