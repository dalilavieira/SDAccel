#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  size_t u32 ;
typedef  int u16 ;
struct TYPE_9__ {int /*<<< orphan*/  flags; } ;
struct TYPE_6__ {int revision_number_major; } ;
struct smiapp_sensor {size_t* limits; int frame_skip; TYPE_4__ pll; TYPE_3__* hwcfg; TYPE_2__* src; TYPE_1__ minfo; } ;
struct smiapp_reg_8 {int reg; int val; int member_0; int member_1; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
struct TYPE_10__ {int /*<<< orphan*/  what; int /*<<< orphan*/  addr; } ;
struct TYPE_8__ {int ext_clk; } ;
struct TYPE_7__ {int /*<<< orphan*/  sd; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct smiapp_reg_8 const*) ; 
 size_t SMIAPP_LIMIT_ANALOGUE_GAIN_CODE_MAX ; 
 size_t SMIAPP_LIMIT_ANALOGUE_GAIN_CODE_MIN ; 
 size_t SMIAPP_LIMIT_MIN_LINE_BLANKING_PCK_BIN ; 
 size_t SMIAPP_LIMIT_MIN_PLL_IP_FREQ_HZ ; 
 size_t SMIAPP_LIMIT_X_ADDR_MAX ; 
 int /*<<< orphan*/  SMIAPP_PLL_FLAG_OP_PIX_CLOCK_PER_LANE ; 
 int /*<<< orphan*/  SMIAPP_REG_MK_U8 (int) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,size_t,size_t) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int,int,int) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*,int) ; 
 TYPE_5__* smiapp_reg_limits ; 
 int smiapp_write (struct smiapp_sensor*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 
 struct i2c_client* v4l2_get_subdevdata (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int smiapp_write_8(struct smiapp_sensor *sensor, u16 reg, u8 val)
{
	return smiapp_write(sensor, SMIAPP_REG_MK_U8(reg), val);
}

__attribute__((used)) static int smiapp_write_8s(struct smiapp_sensor *sensor,
			   const struct smiapp_reg_8 *regs, int len)
{
	struct i2c_client *client = v4l2_get_subdevdata(&sensor->src->sd);
	int rval;

	for (; len > 0; len--, regs++) {
		rval = smiapp_write_8(sensor, regs->reg, regs->val);
		if (rval < 0) {
			dev_err(&client->dev,
				"error %d writing reg 0x%4.4x, val 0x%2.2x",
				rval, regs->reg, regs->val);
			return rval;
		}
	}

	return 0;
}

void smiapp_replace_limit(struct smiapp_sensor *sensor,
			  u32 limit, u32 val)
{
	struct i2c_client *client = v4l2_get_subdevdata(&sensor->src->sd);

	dev_dbg(&client->dev, "quirk: 0x%8.8x \"%s\" = %d, 0x%x\n",
		smiapp_reg_limits[limit].addr,
		smiapp_reg_limits[limit].what, val, val);
	sensor->limits[limit] = val;
}

__attribute__((used)) static int jt8ew9_limits(struct smiapp_sensor *sensor)
{
	if (sensor->minfo.revision_number_major < 0x03)
		sensor->frame_skip = 1;

	/* Below 24 gain doesn't have effect at all, */
	/* but ~59 is needed for full dynamic range */
	smiapp_replace_limit(sensor, SMIAPP_LIMIT_ANALOGUE_GAIN_CODE_MIN, 59);
	smiapp_replace_limit(
		sensor, SMIAPP_LIMIT_ANALOGUE_GAIN_CODE_MAX, 6000);

	return 0;
}

__attribute__((used)) static int jt8ew9_post_poweron(struct smiapp_sensor *sensor)
{
	static const struct smiapp_reg_8 regs[] = {
		{ 0x30a3, 0xd8 }, /* Output port control : LVDS ports only */
		{ 0x30ae, 0x00 }, /* 0x0307 pll_multiplier maximum value on PLL input 9.6MHz ( 19.2MHz is divided on pre_pll_div) */
		{ 0x30af, 0xd0 }, /* 0x0307 pll_multiplier maximum value on PLL input 9.6MHz ( 19.2MHz is divided on pre_pll_div) */
		{ 0x322d, 0x04 }, /* Adjusting Processing Image Size to Scaler Toshiba Recommendation Setting */
		{ 0x3255, 0x0f }, /* Horizontal Noise Reduction Control Toshiba Recommendation Setting */
		{ 0x3256, 0x15 }, /* Horizontal Noise Reduction Control Toshiba Recommendation Setting */
		{ 0x3258, 0x70 }, /* Analog Gain Control Toshiba Recommendation Setting */
		{ 0x3259, 0x70 }, /* Analog Gain Control Toshiba Recommendation Setting */
		{ 0x325f, 0x7c }, /* Analog Gain Control Toshiba Recommendation Setting */
		{ 0x3302, 0x06 }, /* Pixel Reference Voltage Control Toshiba Recommendation Setting */
		{ 0x3304, 0x00 }, /* Pixel Reference Voltage Control Toshiba Recommendation Setting */
		{ 0x3307, 0x22 }, /* Pixel Reference Voltage Control Toshiba Recommendation Setting */
		{ 0x3308, 0x8d }, /* Pixel Reference Voltage Control Toshiba Recommendation Setting */
		{ 0x331e, 0x0f }, /* Black Hole Sun Correction Control Toshiba Recommendation Setting */
		{ 0x3320, 0x30 }, /* Black Hole Sun Correction Control Toshiba Recommendation Setting */
		{ 0x3321, 0x11 }, /* Black Hole Sun Correction Control Toshiba Recommendation Setting */
		{ 0x3322, 0x98 }, /* Black Hole Sun Correction Control Toshiba Recommendation Setting */
		{ 0x3323, 0x64 }, /* Black Hole Sun Correction Control Toshiba Recommendation Setting */
		{ 0x3325, 0x83 }, /* Read Out Timing Control Toshiba Recommendation Setting */
		{ 0x3330, 0x18 }, /* Read Out Timing Control Toshiba Recommendation Setting */
		{ 0x333c, 0x01 }, /* Read Out Timing Control Toshiba Recommendation Setting */
		{ 0x3345, 0x2f }, /* Black Hole Sun Correction Control Toshiba Recommendation Setting */
		{ 0x33de, 0x38 }, /* Horizontal Noise Reduction Control Toshiba Recommendation Setting */
		/* Taken from v03. No idea what the rest are. */
		{ 0x32e0, 0x05 },
		{ 0x32e1, 0x05 },
		{ 0x32e2, 0x04 },
		{ 0x32e5, 0x04 },
		{ 0x32e6, 0x04 },

	};

	return smiapp_write_8s(sensor, regs, ARRAY_SIZE(regs));
}

__attribute__((used)) static int imx125es_post_poweron(struct smiapp_sensor *sensor)
{
	/* Taken from v02. No idea what the other two are. */
	static const struct smiapp_reg_8 regs[] = {
		/*
		 * 0x3302: clk during frame blanking:
		 * 0x00 - HS mode, 0x01 - LP11
		 */
		{ 0x3302, 0x01 },
		{ 0x302d, 0x00 },
		{ 0x3b08, 0x8c },
	};

	return smiapp_write_8s(sensor, regs, ARRAY_SIZE(regs));
}

__attribute__((used)) static int jt8ev1_limits(struct smiapp_sensor *sensor)
{
	smiapp_replace_limit(sensor, SMIAPP_LIMIT_X_ADDR_MAX, 4271);
	smiapp_replace_limit(sensor,
			     SMIAPP_LIMIT_MIN_LINE_BLANKING_PCK_BIN, 184);

	return 0;
}

__attribute__((used)) static int jt8ev1_post_poweron(struct smiapp_sensor *sensor)
{
	struct i2c_client *client = v4l2_get_subdevdata(&sensor->src->sd);
	int rval;
	static const struct smiapp_reg_8 regs[] = {
		{ 0x3031, 0xcd }, /* For digital binning (EQ_MONI) */
		{ 0x30a3, 0xd0 }, /* FLASH STROBE enable */
		{ 0x3237, 0x00 }, /* For control of pulse timing for ADC */
		{ 0x3238, 0x43 },
		{ 0x3301, 0x06 }, /* For analog bias for sensor */
		{ 0x3302, 0x06 },
		{ 0x3304, 0x00 },
		{ 0x3305, 0x88 },
		{ 0x332a, 0x14 },
		{ 0x332c, 0x6b },
		{ 0x3336, 0x01 },
		{ 0x333f, 0x1f },
		{ 0x3355, 0x00 },
		{ 0x3356, 0x20 },
		{ 0x33bf, 0x20 }, /* Adjust the FBC speed */
		{ 0x33c9, 0x20 },
		{ 0x33ce, 0x30 }, /* Adjust the parameter for logic function */
		{ 0x33cf, 0xec }, /* For Black sun */
		{ 0x3328, 0x80 }, /* Ugh. No idea what's this. */
	};
	static const struct smiapp_reg_8 regs_96[] = {
		{ 0x30ae, 0x00 }, /* For control of ADC clock */
		{ 0x30af, 0xd0 },
		{ 0x30b0, 0x01 },
	};

	rval = smiapp_write_8s(sensor, regs, ARRAY_SIZE(regs));
	if (rval < 0)
		return rval;

	switch (sensor->hwcfg->ext_clk) {
	case 9600000:
		return smiapp_write_8s(sensor, regs_96,
				       ARRAY_SIZE(regs_96));
	default:
		dev_warn(&client->dev, "no MSRs for %d Hz ext_clk\n",
			 sensor->hwcfg->ext_clk);
		return 0;
	}
}

__attribute__((used)) static int jt8ev1_pre_streamon(struct smiapp_sensor *sensor)
{
	return smiapp_write_8(sensor, 0x3328, 0x00);
}

__attribute__((used)) static int jt8ev1_post_streamoff(struct smiapp_sensor *sensor)
{
	int rval;

	/* Workaround: allows fast standby to work properly */
	rval = smiapp_write_8(sensor, 0x3205, 0x04);
	if (rval < 0)
		return rval;

	/* Wait for 1 ms + one line => 2 ms is likely enough */
	usleep_range(2000, 2000);

	/* Restore it */
	rval = smiapp_write_8(sensor, 0x3205, 0x00);
	if (rval < 0)
		return rval;

	return smiapp_write_8(sensor, 0x3328, 0x80);
}

__attribute__((used)) static int jt8ev1_init(struct smiapp_sensor *sensor)
{
	sensor->pll.flags |= SMIAPP_PLL_FLAG_OP_PIX_CLOCK_PER_LANE;

	return 0;
}

__attribute__((used)) static int tcm8500md_limits(struct smiapp_sensor *sensor)
{
	smiapp_replace_limit(sensor, SMIAPP_LIMIT_MIN_PLL_IP_FREQ_HZ, 2700000);

	return 0;
}

