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
typedef  int u8 ;
typedef  int u16 ;
struct stk1160 {int dummy; } ;

/* Variables and functions */
 int EBUSY ; 
 scalar_t__ STK1160_AC97CTL_0 ; 
 int STK1160_AC97CTL_0_CR ; 
 int STK1160_AC97CTL_0_CW ; 
 scalar_t__ STK1160_AC97CTL_1 ; 
 scalar_t__ STK1160_AC97_ADDR ; 
 scalar_t__ STK1160_AC97_CMD ; 
 int /*<<< orphan*/  STK1160_AC97_TIMEOUT ; 
 scalar_t__ STK1160_POSV_L ; 
 int STK1160_POSV_L_ACDOUT ; 
 int STK1160_POSV_L_ACSYNC ; 
 unsigned long jiffies ; 
 unsigned long msecs_to_jiffies (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stk1160_err (char*) ; 
 int /*<<< orphan*/  stk1160_info (char*) ; 
 int /*<<< orphan*/  stk1160_read_reg (struct stk1160*,scalar_t__,int*) ; 
 int /*<<< orphan*/  stk1160_write_reg (struct stk1160*,scalar_t__,int) ; 
 scalar_t__ time_is_after_jiffies (unsigned long) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static int stk1160_ac97_wait_transfer_complete(struct stk1160 *dev)
{
	unsigned long timeout = jiffies + msecs_to_jiffies(STK1160_AC97_TIMEOUT);
	u8 value;

	/* Wait for AC97 transfer to complete */
	while (time_is_after_jiffies(timeout)) {
		stk1160_read_reg(dev, STK1160_AC97CTL_0, &value);

		if (!(value & (STK1160_AC97CTL_0_CR | STK1160_AC97CTL_0_CW)))
			return 0;

		usleep_range(50, 100);
	}

	stk1160_err("AC97 transfer took too long, this should never happen!");
	return -EBUSY;
}

__attribute__((used)) static void stk1160_write_ac97(struct stk1160 *dev, u16 reg, u16 value)
{
	/* Set codec register address */
	stk1160_write_reg(dev, STK1160_AC97_ADDR, reg);

	/* Set codec command */
	stk1160_write_reg(dev, STK1160_AC97_CMD, value & 0xff);
	stk1160_write_reg(dev, STK1160_AC97_CMD + 1, (value & 0xff00) >> 8);

	/* Set command write bit to initiate write operation */
	stk1160_write_reg(dev, STK1160_AC97CTL_0, 0x8c);

	/* Wait for command write bit to be cleared */
	stk1160_ac97_wait_transfer_complete(dev);
}

__attribute__((used)) static int stk1160_has_audio(struct stk1160 *dev)
{
	u8 value;

	stk1160_read_reg(dev, STK1160_POSV_L, &value);
	return !(value & STK1160_POSV_L_ACDOUT);
}

__attribute__((used)) static int stk1160_has_ac97(struct stk1160 *dev)
{
	u8 value;

	stk1160_read_reg(dev, STK1160_POSV_L, &value);
	return !(value & STK1160_POSV_L_ACSYNC);
}

void stk1160_ac97_setup(struct stk1160 *dev)
{
	if (!stk1160_has_audio(dev)) {
		stk1160_info("Device doesn't support audio, skipping AC97 setup.");
		return;
	}

	if (!stk1160_has_ac97(dev)) {
		stk1160_info("Device uses internal 8-bit ADC, skipping AC97 setup.");
		return;
	}

	/* Two-step reset AC97 interface and hardware codec */
	stk1160_write_reg(dev, STK1160_AC97CTL_0, 0x94);
	stk1160_write_reg(dev, STK1160_AC97CTL_0, 0x8c);

	/* Set 16-bit audio data and choose L&R channel*/
	stk1160_write_reg(dev, STK1160_AC97CTL_1 + 2, 0x01);
	stk1160_write_reg(dev, STK1160_AC97CTL_1 + 3, 0x00);

	/* Setup channels */
	stk1160_write_ac97(dev, 0x12, 0x8808); /* CD volume */
	stk1160_write_ac97(dev, 0x10, 0x0808); /* Line-in volume */
	stk1160_write_ac97(dev, 0x0e, 0x0008); /* MIC volume (mono) */
	stk1160_write_ac97(dev, 0x16, 0x0808); /* Aux volume */
	stk1160_write_ac97(dev, 0x1a, 0x0404); /* Record select */
	stk1160_write_ac97(dev, 0x02, 0x0000); /* Master volume */
	stk1160_write_ac97(dev, 0x1c, 0x0808); /* Record gain */

#ifdef DEBUG
	stk1160_ac97_dump_regs(dev);
#endif
}

