#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u64 ;
typedef  int u32 ;
struct i2c_device_id {int driver_data; } ;
struct TYPE_9__ {TYPE_1__* of_node; } ;
struct i2c_client {TYPE_2__ dev; } ;
struct device {int dummy; } ;
struct clk_si544_muldiv {int ls_div_bits; int hs_div; int fb_div_int; int fb_div_frac; } ;
struct TYPE_10__ {struct clk_init_data* init; } ;
struct clk_si544 {int speed_grade; TYPE_3__ hw; int /*<<< orphan*/  regmap; struct i2c_client* i2c_client; } ;
struct clk_init_data {int /*<<< orphan*/  name; scalar_t__ num_parents; scalar_t__ flags; int /*<<< orphan*/ * ops; } ;
struct clk_hw {int dummy; } ;
struct TYPE_8__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int BIT (int) ; 
 long EINVAL ; 
 int ENOMEM ; 
 int FVCO_MIN ; 
 int FXO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HS_DIV_MAX ; 
 int HS_DIV_MAX_ODD ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 unsigned long MIN_HSDIV_FREQ ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SI544_CONTROL_MS_ICAL2 ; 
 unsigned long SI544_MIN_FREQ ; 
 unsigned int SI544_OE_STATE_ODC_OE ; 
#define  SI544_REG_CONTROL 132 
 int /*<<< orphan*/  SI544_REG_FBDIV0 ; 
#define  SI544_REG_FCAL_OVR 131 
 int /*<<< orphan*/  SI544_REG_HS_DIV ; 
 int /*<<< orphan*/  SI544_REG_OE_STATE ; 
 int SI544_REG_PAGE_SELECT ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*) ; 
 int devm_clk_hw_register (TYPE_2__*,TYPE_3__*) ; 
 struct clk_si544* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 int devm_of_clk_add_hw_provider (TYPE_2__*,int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int do_div (int,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct clk_si544*) ; 
 int /*<<< orphan*/  of_clk_hw_simple_get ; 
 scalar_t__ of_property_read_string (TYPE_1__*,char*,int /*<<< orphan*/ *) ; 
 int regmap_bulk_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int) ; 
 int regmap_bulk_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 int regmap_write (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  si544_clk_ops ; 
 int /*<<< orphan*/  si544_regmap_config ; 
#define  si544a 130 
#define  si544b 129 
#define  si544c 128 
 struct clk_si544* to_clk_si544 (struct clk_hw*) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static int si544_enable_output(struct clk_si544 *data, bool enable)
{
	return regmap_update_bits(data->regmap, SI544_REG_OE_STATE,
		SI544_OE_STATE_ODC_OE, enable ? SI544_OE_STATE_ODC_OE : 0);
}

__attribute__((used)) static int si544_prepare(struct clk_hw *hw)
{
	struct clk_si544 *data = to_clk_si544(hw);

	return si544_enable_output(data, true);
}

__attribute__((used)) static void si544_unprepare(struct clk_hw *hw)
{
	struct clk_si544 *data = to_clk_si544(hw);

	si544_enable_output(data, false);
}

__attribute__((used)) static int si544_is_prepared(struct clk_hw *hw)
{
	struct clk_si544 *data = to_clk_si544(hw);
	unsigned int val;
	int err;

	err = regmap_read(data->regmap, SI544_REG_OE_STATE, &val);
	if (err < 0)
		return err;

	return !!(val & SI544_OE_STATE_ODC_OE);
}

__attribute__((used)) static int si544_get_muldiv(struct clk_si544 *data,
	struct clk_si544_muldiv *settings)
{
	int err;
	u8 reg[6];

	err = regmap_bulk_read(data->regmap, SI544_REG_HS_DIV, reg, 2);
	if (err)
		return err;

	settings->ls_div_bits = (reg[1] >> 4) & 0x07;
	settings->hs_div = (reg[1] & 0x07) << 8 | reg[0];

	err = regmap_bulk_read(data->regmap, SI544_REG_FBDIV0, reg, 6);
	if (err)
		return err;

	settings->fb_div_int = reg[4] | (reg[5] & 0x07) << 8;
	settings->fb_div_frac = reg[0] | reg[1] << 8 | reg[2] << 16 |
				reg[3] << 24;
	return 0;
}

__attribute__((used)) static int si544_set_muldiv(struct clk_si544 *data,
	struct clk_si544_muldiv *settings)
{
	int err;
	u8 reg[6];

	reg[0] = settings->hs_div;
	reg[1] = settings->hs_div >> 8 | settings->ls_div_bits << 4;

	err = regmap_bulk_write(data->regmap, SI544_REG_HS_DIV, reg, 2);
	if (err < 0)
		return err;

	reg[0] = settings->fb_div_frac;
	reg[1] = settings->fb_div_frac >> 8;
	reg[2] = settings->fb_div_frac >> 16;
	reg[3] = settings->fb_div_frac >> 24;
	reg[4] = settings->fb_div_int;
	reg[5] = settings->fb_div_int >> 8;

	/*
	 * Writing to SI544_REG_FBDIV40 triggers the clock change, so that
	 * must be written last
	 */
	return regmap_bulk_write(data->regmap, SI544_REG_FBDIV0, reg, 6);
}

__attribute__((used)) static bool is_valid_frequency(const struct clk_si544 *data,
	unsigned long frequency)
{
	unsigned long max_freq = 0;

	if (frequency < SI544_MIN_FREQ)
		return false;

	switch (data->speed_grade) {
	case si544a:
		max_freq = 1500000000;
		break;
	case si544b:
		max_freq = 800000000;
		break;
	case si544c:
		max_freq = 350000000;
		break;
	}

	return frequency <= max_freq;
}

__attribute__((used)) static int si544_calc_muldiv(struct clk_si544_muldiv *settings,
	unsigned long frequency)
{
	u64 vco;
	u32 ls_freq;
	u32 tmp;
	u8 res;

	/* Determine the minimum value of LS_DIV and resulting target freq. */
	ls_freq = frequency;
	settings->ls_div_bits = 0;

	if (frequency >= MIN_HSDIV_FREQ) {
		settings->ls_div_bits = 0;
	} else {
		res = 1;
		tmp = 2 * HS_DIV_MAX;
		while (tmp <= (HS_DIV_MAX * 32)) {
			if (((u64)frequency * tmp) >= FVCO_MIN)
				break;
			++res;
			tmp <<= 1;
		}
		settings->ls_div_bits = res;
		ls_freq = frequency << res;
	}

	/* Determine minimum HS_DIV by rounding up */
	vco = FVCO_MIN + ls_freq - 1;
	do_div(vco, ls_freq);
	settings->hs_div = vco;

	/* round up to even number when required */
	if ((settings->hs_div & 1) &&
	    (settings->hs_div > HS_DIV_MAX_ODD || settings->ls_div_bits))
		++settings->hs_div;

	/* Calculate VCO frequency (in 10..12GHz range) */
	vco = (u64)ls_freq * settings->hs_div;

	/* Calculate the integer part of the feedback divider */
	tmp = do_div(vco, FXO);
	settings->fb_div_int = vco;

	/* And the fractional bits using the remainder */
	vco = (u64)tmp << 32;
	vco += FXO / 2; /* Round to nearest multiple */
	do_div(vco, FXO);
	settings->fb_div_frac = vco;

	return 0;
}

__attribute__((used)) static unsigned long si544_calc_rate(struct clk_si544_muldiv *settings)
{
	u32 d = settings->hs_div * BIT(settings->ls_div_bits);
	u64 vco;

	/* Calculate VCO from the fractional part */
	vco = (u64)settings->fb_div_frac * FXO;
	vco += (FXO / 2);
	vco >>= 32;

	/* Add the integer part of the VCO frequency */
	vco += (u64)settings->fb_div_int * FXO;

	/* Apply divider to obtain the generated frequency */
	do_div(vco, d);

	return vco;
}

__attribute__((used)) static unsigned long si544_recalc_rate(struct clk_hw *hw,
		unsigned long parent_rate)
{
	struct clk_si544 *data = to_clk_si544(hw);
	struct clk_si544_muldiv settings;
	int err;

	err = si544_get_muldiv(data, &settings);
	if (err)
		return 0;

	return si544_calc_rate(&settings);
}

__attribute__((used)) static long si544_round_rate(struct clk_hw *hw, unsigned long rate,
		unsigned long *parent_rate)
{
	struct clk_si544 *data = to_clk_si544(hw);
	struct clk_si544_muldiv settings;
	int err;

	if (!is_valid_frequency(data, rate))
		return -EINVAL;

	err = si544_calc_muldiv(&settings, rate);
	if (err)
		return err;

	return si544_calc_rate(&settings);
}

__attribute__((used)) static int si544_set_rate(struct clk_hw *hw, unsigned long rate,
		unsigned long parent_rate)
{
	struct clk_si544 *data = to_clk_si544(hw);
	struct clk_si544_muldiv settings;
	unsigned int old_oe_state;
	int err;

	if (!is_valid_frequency(data, rate))
		return -EINVAL;

	err = si544_calc_muldiv(&settings, rate);
	if (err)
		return err;

	err = regmap_read(data->regmap, SI544_REG_OE_STATE, &old_oe_state);
	if (err)
		return err;

	si544_enable_output(data, false);

	/* Allow FCAL for this frequency update */
	err = regmap_write(data->regmap, SI544_REG_FCAL_OVR, 0);
	if (err < 0)
		return err;


	err = si544_set_muldiv(data, &settings);
	if (err < 0)
		return err; /* Undefined state now, best to leave disabled */

	/* Trigger calibration */
	err = regmap_write(data->regmap, SI544_REG_CONTROL,
			   SI544_CONTROL_MS_ICAL2);
	if (err < 0)
		return err;

	/* Applying a new frequency can take up to 10ms */
	usleep_range(10000, 12000);

	if (old_oe_state & SI544_OE_STATE_ODC_OE)
		si544_enable_output(data, true);

	return err;
}

__attribute__((used)) static bool si544_regmap_is_volatile(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case SI544_REG_CONTROL:
	case SI544_REG_FCAL_OVR:
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static int si544_probe(struct i2c_client *client,
		const struct i2c_device_id *id)
{
	struct clk_si544 *data;
	struct clk_init_data init;
	int err;

	data = devm_kzalloc(&client->dev, sizeof(*data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	init.ops = &si544_clk_ops;
	init.flags = 0;
	init.num_parents = 0;
	data->hw.init = &init;
	data->i2c_client = client;
	data->speed_grade = id->driver_data;

	if (of_property_read_string(client->dev.of_node, "clock-output-names",
			&init.name))
		init.name = client->dev.of_node->name;

	data->regmap = devm_regmap_init_i2c(client, &si544_regmap_config);
	if (IS_ERR(data->regmap))
		return PTR_ERR(data->regmap);

	i2c_set_clientdata(client, data);

	/* Select page 0, just to be sure, there appear to be no more */
	err = regmap_write(data->regmap, SI544_REG_PAGE_SELECT, 0);
	if (err < 0)
		return err;

	err = devm_clk_hw_register(&client->dev, &data->hw);
	if (err) {
		dev_err(&client->dev, "clock registration failed\n");
		return err;
	}
	err = devm_of_clk_add_hw_provider(&client->dev, of_clk_hw_simple_get,
					  &data->hw);
	if (err) {
		dev_err(&client->dev, "unable to add clk provider\n");
		return err;
	}

	return 0;
}

