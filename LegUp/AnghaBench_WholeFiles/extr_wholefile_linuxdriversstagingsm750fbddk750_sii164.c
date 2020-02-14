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

/* Variables and functions */
 int /*<<< orphan*/  DEFAULT_I2C_SCL ; 
 int /*<<< orphan*/  DEFAULT_I2C_SDA ; 
 int /*<<< orphan*/  SII164_CONFIGURATION ; 
 unsigned char SII164_CONFIGURATION_BUS_12BITS ; 
 unsigned char SII164_CONFIGURATION_BUS_24BITS ; 
 unsigned char SII164_CONFIGURATION_CLOCK_DUAL ; 
 unsigned char SII164_CONFIGURATION_CLOCK_SINGLE ; 
 unsigned char SII164_CONFIGURATION_HSYNC_AS_IS ; 
 unsigned char SII164_CONFIGURATION_HSYNC_FORCE_LOW ; 
 unsigned char SII164_CONFIGURATION_LATCH_FALLING ; 
 unsigned char SII164_CONFIGURATION_LATCH_RISING ; 
 unsigned char SII164_CONFIGURATION_POWER_NORMAL ; 
 unsigned char SII164_CONFIGURATION_VSYNC_AS_IS ; 
 unsigned char SII164_CONFIGURATION_VSYNC_FORCE_LOW ; 
 int /*<<< orphan*/  SII164_DESKEW ; 
 unsigned char SII164_DESKEW_1_STEP ; 
 unsigned char SII164_DESKEW_2_STEP ; 
 unsigned char SII164_DESKEW_3_STEP ; 
 unsigned char SII164_DESKEW_4_STEP ; 
 unsigned char SII164_DESKEW_5_STEP ; 
 unsigned char SII164_DESKEW_6_STEP ; 
 unsigned char SII164_DESKEW_7_STEP ; 
 unsigned char SII164_DESKEW_8_STEP ; 
 unsigned char SII164_DESKEW_DISABLE ; 
 unsigned char SII164_DESKEW_ENABLE ; 
 scalar_t__ SII164_DEVICE_ID ; 
 int /*<<< orphan*/  SII164_DEVICE_ID_HIGH ; 
 int /*<<< orphan*/  SII164_DEVICE_ID_LOW ; 
 int /*<<< orphan*/  SII164_I2C_ADDRESS ; 
 int /*<<< orphan*/  SII164_PLL ; 
 unsigned char SII164_PLL_FILTER_DISABLE ; 
 unsigned char SII164_PLL_FILTER_ENABLE ; 
 unsigned char SII164_PLL_FILTER_SYNC_CONTINUOUS_DISABLE ; 
 unsigned char SII164_PLL_FILTER_SYNC_CONTINUOUS_ENABLE ; 
 scalar_t__ SII164_VENDOR_ID ; 
 int /*<<< orphan*/  SII164_VENDOR_ID_HIGH ; 
 int /*<<< orphan*/  SII164_VENDOR_ID_LOW ; 
 unsigned char i2cReadReg (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2cWriteReg (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned char) ; 
 int /*<<< orphan*/  sm750_sw_i2c_init (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

unsigned short sii164GetVendorID(void)
{
	unsigned short vendorID;

	vendorID = ((unsigned short) i2cReadReg(SII164_I2C_ADDRESS, SII164_VENDOR_ID_HIGH) << 8) |
		    (unsigned short) i2cReadReg(SII164_I2C_ADDRESS, SII164_VENDOR_ID_LOW);

	return vendorID;
}

unsigned short sii164GetDeviceID(void)
{
	unsigned short deviceID;

	deviceID = ((unsigned short) i2cReadReg(SII164_I2C_ADDRESS, SII164_DEVICE_ID_HIGH) << 8) |
		    (unsigned short) i2cReadReg(SII164_I2C_ADDRESS, SII164_DEVICE_ID_LOW);

	return deviceID;
}

long sii164InitChip(unsigned char edgeSelect,
		    unsigned char busSelect,
		    unsigned char dualEdgeClkSelect,
		    unsigned char hsyncEnable,
		    unsigned char vsyncEnable,
		    unsigned char deskewEnable,
		    unsigned char deskewSetting,
		    unsigned char continuousSyncEnable,
		    unsigned char pllFilterEnable,
		    unsigned char pllFilterValue)
{
	unsigned char config;

	/* Initialize the i2c bus */
#ifdef USE_HW_I2C
	/* Use fast mode. */
	sm750_hw_i2c_init(1);
#else
	sm750_sw_i2c_init(DEFAULT_I2C_SCL, DEFAULT_I2C_SDA);
#endif

	/* Check if SII164 Chip exists */
	if ((sii164GetVendorID() == SII164_VENDOR_ID) && (sii164GetDeviceID() == SII164_DEVICE_ID)) {
		/*
		 *  Initialize SII164 controller chip.
		 */

		/* Select the edge */
		if (edgeSelect == 0)
			config = SII164_CONFIGURATION_LATCH_FALLING;
		else
			config = SII164_CONFIGURATION_LATCH_RISING;

		/* Select bus wide */
		if (busSelect == 0)
			config |= SII164_CONFIGURATION_BUS_12BITS;
		else
			config |= SII164_CONFIGURATION_BUS_24BITS;

		/* Select Dual/Single Edge Clock */
		if (dualEdgeClkSelect == 0)
			config |= SII164_CONFIGURATION_CLOCK_SINGLE;
		else
			config |= SII164_CONFIGURATION_CLOCK_DUAL;

		/* Select HSync Enable */
		if (hsyncEnable == 0)
			config |= SII164_CONFIGURATION_HSYNC_FORCE_LOW;
		else
			config |= SII164_CONFIGURATION_HSYNC_AS_IS;

		/* Select VSync Enable */
		if (vsyncEnable == 0)
			config |= SII164_CONFIGURATION_VSYNC_FORCE_LOW;
		else
			config |= SII164_CONFIGURATION_VSYNC_AS_IS;

		i2cWriteReg(SII164_I2C_ADDRESS, SII164_CONFIGURATION, config);

		/*
		 * De-skew enabled with default 111b value.
		 * This fixes some artifacts problem in some mode on board 2.2.
		 * Somehow this fix does not affect board 2.1.
		 */
		if (deskewEnable == 0)
			config = SII164_DESKEW_DISABLE;
		else
			config = SII164_DESKEW_ENABLE;

		switch (deskewSetting) {
		case 0:
			config |= SII164_DESKEW_1_STEP;
			break;
		case 1:
			config |= SII164_DESKEW_2_STEP;
			break;
		case 2:
			config |= SII164_DESKEW_3_STEP;
			break;
		case 3:
			config |= SII164_DESKEW_4_STEP;
			break;
		case 4:
			config |= SII164_DESKEW_5_STEP;
			break;
		case 5:
			config |= SII164_DESKEW_6_STEP;
			break;
		case 6:
			config |= SII164_DESKEW_7_STEP;
			break;
		case 7:
			config |= SII164_DESKEW_8_STEP;
			break;
		}
		i2cWriteReg(SII164_I2C_ADDRESS, SII164_DESKEW, config);

		/* Enable/Disable Continuous Sync. */
		if (continuousSyncEnable == 0)
			config = SII164_PLL_FILTER_SYNC_CONTINUOUS_DISABLE;
		else
			config = SII164_PLL_FILTER_SYNC_CONTINUOUS_ENABLE;

		/* Enable/Disable PLL Filter */
		if (pllFilterEnable == 0)
			config |= SII164_PLL_FILTER_DISABLE;
		else
			config |= SII164_PLL_FILTER_ENABLE;

		/* Set the PLL Filter value */
		config |= ((pllFilterValue & 0x07) << 1);

		i2cWriteReg(SII164_I2C_ADDRESS, SII164_PLL, config);

		/* Recover from Power Down and enable output. */
		config = i2cReadReg(SII164_I2C_ADDRESS, SII164_CONFIGURATION);
		config |= SII164_CONFIGURATION_POWER_NORMAL;
		i2cWriteReg(SII164_I2C_ADDRESS, SII164_CONFIGURATION, config);

		return 0;
	}

	/* Return -1 if initialization fails. */
	return -1;
}

