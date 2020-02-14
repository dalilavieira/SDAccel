#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  unsigned long long u64 ;
typedef  int u32 ;
typedef  unsigned short u16 ;
struct device {struct adf4350_platform_data* platform_data; scalar_t__ of_node; } ;
struct spi_device {struct device dev; } ;
struct regulator {int dummy; } ;
struct TYPE_3__ {struct device* parent; } ;
struct iio_dev {scalar_t__* name; int num_channels; int /*<<< orphan*/ * channels; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; TYPE_1__ dev; int /*<<< orphan*/  mlock; } ;
struct iio_chan_spec {int dummy; } ;
typedef  struct regulator clk ;
struct adf4350_state {int* regs_hw; int* regs; int fpfd; int clkin; unsigned long long min_out_freq; int r4_rf_div_sel; int chspc; unsigned short r0_int; int r1_mod; int r0_fract; unsigned long long freq_req; struct regulator* clk; struct regulator* reg; struct adf4350_platform_data* pdata; struct spi_device* spi; int /*<<< orphan*/  val; } ;
struct adf4350_platform_data {unsigned short ref_div_factor; int r2_user_settings; int r3_user_settings; int r4_user_settings; unsigned long long clkin; scalar_t__* name; unsigned long long channel_spacing; int power_up_frequency; int /*<<< orphan*/  gpio_lock_detect; scalar_t__ ref_div2_en; scalar_t__ ref_doubler_en; } ;
typedef  int ssize_t ;
struct TYPE_4__ {scalar_t__* name; int driver_data; } ;

/* Variables and functions */
#define  ADF4350_FREQ 133 
#define  ADF4350_FREQ_REFIN 132 
#define  ADF4350_FREQ_RESOLUTION 131 
 int /*<<< orphan*/  ADF4350_MAX_BANDSEL_CLK ; 
 unsigned long long ADF4350_MAX_FREQ_45_PRESC ; 
 int ADF4350_MAX_FREQ_PFD ; 
 unsigned long long ADF4350_MAX_FREQ_REFIN ; 
 int ADF4350_MAX_MODULUS ; 
 unsigned long long ADF4350_MAX_OUT_FREQ ; 
 unsigned short ADF4350_MAX_R_CNT ; 
 unsigned long long ADF4350_MIN_OUT_FREQ ; 
 unsigned long long ADF4350_MIN_VCO_FREQ ; 
#define  ADF4350_PWRDOWN 130 
 int ADF4350_REG0 ; 
 int ADF4350_REG0_FRACT (int) ; 
 int ADF4350_REG0_INT (unsigned long long) ; 
#define  ADF4350_REG1 129 
 int ADF4350_REG1_MOD (int) ; 
 int ADF4350_REG1_PHASE (int) ; 
 int ADF4350_REG1_PRESCALER ; 
 size_t ADF4350_REG2 ; 
 int ADF4350_REG2_10BIT_R_CNT (unsigned short) ; 
 int ADF4350_REG2_CHARGE_PUMP_CURR_uA (int) ; 
 int ADF4350_REG2_DOUBLE_BUFF_EN ; 
 int ADF4350_REG2_LDF_INT_N ; 
 int ADF4350_REG2_LDP_6ns ; 
 int ADF4350_REG2_MUXOUT (int) ; 
 int ADF4350_REG2_NOISE_MODE (int) ; 
 int ADF4350_REG2_PD_POLARITY_POS ; 
 int ADF4350_REG2_POWER_DOWN_EN ; 
 int ADF4350_REG2_RDIV2_EN ; 
 int ADF4350_REG2_RMULT2_EN ; 
 size_t ADF4350_REG3 ; 
 int ADF4350_REG3_12BIT_CLKDIV (int) ; 
 int ADF4350_REG3_12BIT_CLKDIV_MODE (int) ; 
 int ADF4350_REG3_12BIT_CSR_EN ; 
#define  ADF4350_REG4 128 
 int ADF4350_REG4_8BIT_BAND_SEL_CLKDIV (int /*<<< orphan*/ ) ; 
 int ADF4350_REG4_AUX_OUTPUT_EN ; 
 int ADF4350_REG4_AUX_OUTPUT_FUND ; 
 int ADF4350_REG4_AUX_OUTPUT_PWR (int) ; 
 int ADF4350_REG4_FEEDBACK_FUND ; 
 int ADF4350_REG4_MUTE_TILL_LOCK_EN ; 
 int ADF4350_REG4_OUTPUT_PWR (int) ; 
 int ADF4350_REG4_RF_DIV_SEL (int) ; 
 int ADF4350_REG4_RF_OUT_EN ; 
 unsigned int ADF4350_REG5 ; 
 int ADF4350_REG5_LD_PIN_MODE_DIGITAL ; 
 unsigned long long ADF4351_MIN_OUT_FREQ ; 
 int ADF4351_REG3_ANTI_BACKLASH_3ns_EN ; 
 int ADF4351_REG3_BAND_SEL_CLOCK_MODE_HIGH ; 
 int ADF4351_REG3_CHARGE_CANCELLATION_EN ; 
 unsigned int BIT (int) ; 
 int /*<<< orphan*/  DIV_ROUND_UP (int,int /*<<< orphan*/ ) ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 scalar_t__ IS_ERR (struct regulator*) ; 
 int /*<<< orphan*/  adf4350_chan ; 
 int /*<<< orphan*/  adf4350_info ; 
 int /*<<< orphan*/  clk_disable_unprepare (struct regulator*) ; 
 void* clk_get_rate (struct regulator*) ; 
 int clk_prepare_enable (struct regulator*) ; 
 unsigned long clk_round_rate (struct regulator*,unsigned long long) ; 
 int clk_set_rate (struct regulator*,unsigned long) ; 
 int /*<<< orphan*/  cpu_to_be32 (int) ; 
 struct adf4350_platform_data default_pdata ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 struct regulator* devm_clk_get (struct device*,char*) ; 
 int devm_gpio_request (struct device*,int /*<<< orphan*/ ,scalar_t__*) ; 
 struct iio_dev* devm_iio_device_alloc (struct device*,int) ; 
 struct regulator* devm_regulator_get (struct device*,char*) ; 
 int do_div (unsigned long long,int) ; 
 int gcd (int,int) ; 
 int /*<<< orphan*/  gpio_direction_input (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_get_value (int /*<<< orphan*/ ) ; 
 scalar_t__ gpio_is_valid (int /*<<< orphan*/ ) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct adf4350_state* iio_priv (struct iio_dev*) ; 
 int kstrtoull (char const*,int,unsigned long long*) ; 
 int /*<<< orphan*/  memset (unsigned int*,int,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  regulator_disable (struct regulator*) ; 
 int regulator_enable (struct regulator*) ; 
 TYPE_2__* spi_get_device_id (struct spi_device*) ; 
 struct iio_dev* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct iio_dev*) ; 
 int spi_write (struct spi_device*,int /*<<< orphan*/ *,int) ; 
 int sprintf (char*,char*,unsigned long long) ; 

__attribute__((used)) static int adf4350_sync_config(struct adf4350_state *st)
{
	int ret, i, doublebuf = 0;

	for (i = ADF4350_REG5; i >= ADF4350_REG0; i--) {
		if ((st->regs_hw[i] != st->regs[i]) ||
			((i == ADF4350_REG0) && doublebuf)) {
			switch (i) {
			case ADF4350_REG1:
			case ADF4350_REG4:
				doublebuf = 1;
				break;
			}

			st->val  = cpu_to_be32(st->regs[i] | i);
			ret = spi_write(st->spi, &st->val, 4);
			if (ret < 0)
				return ret;
			st->regs_hw[i] = st->regs[i];
			dev_dbg(&st->spi->dev, "[%d] 0x%X\n",
				i, (u32)st->regs[i] | i);
		}
	}
	return 0;
}

__attribute__((used)) static int adf4350_reg_access(struct iio_dev *indio_dev,
			      unsigned reg, unsigned writeval,
			      unsigned *readval)
{
	struct adf4350_state *st = iio_priv(indio_dev);
	int ret;

	if (reg > ADF4350_REG5)
		return -EINVAL;

	mutex_lock(&indio_dev->mlock);
	if (readval == NULL) {
		st->regs[reg] = writeval & ~(BIT(0) | BIT(1) | BIT(2));
		ret = adf4350_sync_config(st);
	} else {
		*readval =  st->regs_hw[reg];
		ret = 0;
	}
	mutex_unlock(&indio_dev->mlock);

	return ret;
}

__attribute__((used)) static int adf4350_tune_r_cnt(struct adf4350_state *st, unsigned short r_cnt)
{
	struct adf4350_platform_data *pdata = st->pdata;

	do {
		r_cnt++;
		st->fpfd = (st->clkin * (pdata->ref_doubler_en ? 2 : 1)) /
			   (r_cnt * (pdata->ref_div2_en ? 2 : 1));
	} while (st->fpfd > ADF4350_MAX_FREQ_PFD);

	return r_cnt;
}

__attribute__((used)) static int adf4350_set_freq(struct adf4350_state *st, unsigned long long freq)
{
	struct adf4350_platform_data *pdata = st->pdata;
	u64 tmp;
	u32 div_gcd, prescaler, chspc;
	u16 mdiv, r_cnt = 0;
	u8 band_sel_div;

	if (freq > ADF4350_MAX_OUT_FREQ || freq < st->min_out_freq)
		return -EINVAL;

	if (freq > ADF4350_MAX_FREQ_45_PRESC) {
		prescaler = ADF4350_REG1_PRESCALER;
		mdiv = 75;
	} else {
		prescaler = 0;
		mdiv = 23;
	}

	st->r4_rf_div_sel = 0;

	while (freq < ADF4350_MIN_VCO_FREQ) {
		freq <<= 1;
		st->r4_rf_div_sel++;
	}

	/*
	 * Allow a predefined reference division factor
	 * if not set, compute our own
	 */
	if (pdata->ref_div_factor)
		r_cnt = pdata->ref_div_factor - 1;

	chspc = st->chspc;

	do  {
		do {
			do {
				r_cnt = adf4350_tune_r_cnt(st, r_cnt);
				st->r1_mod = st->fpfd / chspc;
				if (r_cnt > ADF4350_MAX_R_CNT) {
					/* try higher spacing values */
					chspc++;
					r_cnt = 0;
				}
			} while ((st->r1_mod > ADF4350_MAX_MODULUS) && r_cnt);
		} while (r_cnt == 0);

		tmp = freq * (u64)st->r1_mod + (st->fpfd >> 1);
		do_div(tmp, st->fpfd); /* Div round closest (n + d/2)/d */
		st->r0_fract = do_div(tmp, st->r1_mod);
		st->r0_int = tmp;
	} while (mdiv > st->r0_int);

	band_sel_div = DIV_ROUND_UP(st->fpfd, ADF4350_MAX_BANDSEL_CLK);

	if (st->r0_fract && st->r1_mod) {
		div_gcd = gcd(st->r1_mod, st->r0_fract);
		st->r1_mod /= div_gcd;
		st->r0_fract /= div_gcd;
	} else {
		st->r0_fract = 0;
		st->r1_mod = 1;
	}

	dev_dbg(&st->spi->dev, "VCO: %llu Hz, PFD %lu Hz\n"
		"REF_DIV %d, R0_INT %d, R0_FRACT %d\n"
		"R1_MOD %d, RF_DIV %d\nPRESCALER %s, BAND_SEL_DIV %d\n",
		freq, st->fpfd, r_cnt, st->r0_int, st->r0_fract, st->r1_mod,
		1 << st->r4_rf_div_sel, prescaler ? "8/9" : "4/5",
		band_sel_div);

	st->regs[ADF4350_REG0] = ADF4350_REG0_INT(st->r0_int) |
				 ADF4350_REG0_FRACT(st->r0_fract);

	st->regs[ADF4350_REG1] = ADF4350_REG1_PHASE(1) |
				 ADF4350_REG1_MOD(st->r1_mod) |
				 prescaler;

	st->regs[ADF4350_REG2] =
		ADF4350_REG2_10BIT_R_CNT(r_cnt) |
		ADF4350_REG2_DOUBLE_BUFF_EN |
		(pdata->ref_doubler_en ? ADF4350_REG2_RMULT2_EN : 0) |
		(pdata->ref_div2_en ? ADF4350_REG2_RDIV2_EN : 0) |
		(pdata->r2_user_settings & (ADF4350_REG2_PD_POLARITY_POS |
		ADF4350_REG2_LDP_6ns | ADF4350_REG2_LDF_INT_N |
		ADF4350_REG2_CHARGE_PUMP_CURR_uA(5000) |
		ADF4350_REG2_MUXOUT(0x7) | ADF4350_REG2_NOISE_MODE(0x3)));

	st->regs[ADF4350_REG3] = pdata->r3_user_settings &
				 (ADF4350_REG3_12BIT_CLKDIV(0xFFF) |
				 ADF4350_REG3_12BIT_CLKDIV_MODE(0x3) |
				 ADF4350_REG3_12BIT_CSR_EN |
				 ADF4351_REG3_CHARGE_CANCELLATION_EN |
				 ADF4351_REG3_ANTI_BACKLASH_3ns_EN |
				 ADF4351_REG3_BAND_SEL_CLOCK_MODE_HIGH);

	st->regs[ADF4350_REG4] =
		ADF4350_REG4_FEEDBACK_FUND |
		ADF4350_REG4_RF_DIV_SEL(st->r4_rf_div_sel) |
		ADF4350_REG4_8BIT_BAND_SEL_CLKDIV(band_sel_div) |
		ADF4350_REG4_RF_OUT_EN |
		(pdata->r4_user_settings &
		(ADF4350_REG4_OUTPUT_PWR(0x3) |
		ADF4350_REG4_AUX_OUTPUT_PWR(0x3) |
		ADF4350_REG4_AUX_OUTPUT_EN |
		ADF4350_REG4_AUX_OUTPUT_FUND |
		ADF4350_REG4_MUTE_TILL_LOCK_EN));

	st->regs[ADF4350_REG5] = ADF4350_REG5_LD_PIN_MODE_DIGITAL;
	st->freq_req = freq;

	return adf4350_sync_config(st);
}

__attribute__((used)) static ssize_t adf4350_write(struct iio_dev *indio_dev,
				    uintptr_t private,
				    const struct iio_chan_spec *chan,
				    const char *buf, size_t len)
{
	struct adf4350_state *st = iio_priv(indio_dev);
	unsigned long long readin;
	unsigned long tmp;
	int ret;

	ret = kstrtoull(buf, 10, &readin);
	if (ret)
		return ret;

	mutex_lock(&indio_dev->mlock);
	switch ((u32)private) {
	case ADF4350_FREQ:
		ret = adf4350_set_freq(st, readin);
		break;
	case ADF4350_FREQ_REFIN:
		if (readin > ADF4350_MAX_FREQ_REFIN) {
			ret = -EINVAL;
			break;
		}

		if (st->clk) {
			tmp = clk_round_rate(st->clk, readin);
			if (tmp != readin) {
				ret = -EINVAL;
				break;
			}
			ret = clk_set_rate(st->clk, tmp);
			if (ret < 0)
				break;
		}
		st->clkin = readin;
		ret = adf4350_set_freq(st, st->freq_req);
		break;
	case ADF4350_FREQ_RESOLUTION:
		if (readin == 0)
			ret = -EINVAL;
		else
			st->chspc = readin;
		break;
	case ADF4350_PWRDOWN:
		if (readin)
			st->regs[ADF4350_REG2] |= ADF4350_REG2_POWER_DOWN_EN;
		else
			st->regs[ADF4350_REG2] &= ~ADF4350_REG2_POWER_DOWN_EN;

		adf4350_sync_config(st);
		break;
	default:
		ret = -EINVAL;
	}
	mutex_unlock(&indio_dev->mlock);

	return ret ? ret : len;
}

__attribute__((used)) static ssize_t adf4350_read(struct iio_dev *indio_dev,
				   uintptr_t private,
				   const struct iio_chan_spec *chan,
				   char *buf)
{
	struct adf4350_state *st = iio_priv(indio_dev);
	unsigned long long val;
	int ret = 0;

	mutex_lock(&indio_dev->mlock);
	switch ((u32)private) {
	case ADF4350_FREQ:
		val = (u64)((st->r0_int * st->r1_mod) + st->r0_fract) *
			(u64)st->fpfd;
		do_div(val, st->r1_mod * (1 << st->r4_rf_div_sel));
		/* PLL unlocked? return error */
		if (gpio_is_valid(st->pdata->gpio_lock_detect))
			if (!gpio_get_value(st->pdata->gpio_lock_detect)) {
				dev_dbg(&st->spi->dev, "PLL un-locked\n");
				ret = -EBUSY;
			}
		break;
	case ADF4350_FREQ_REFIN:
		if (st->clk)
			st->clkin = clk_get_rate(st->clk);

		val = st->clkin;
		break;
	case ADF4350_FREQ_RESOLUTION:
		val = st->chspc;
		break;
	case ADF4350_PWRDOWN:
		val = !!(st->regs[ADF4350_REG2] & ADF4350_REG2_POWER_DOWN_EN);
		break;
	default:
		ret = -EINVAL;
		val = 0;
	}
	mutex_unlock(&indio_dev->mlock);

	return ret < 0 ? ret : sprintf(buf, "%llu\n", val);
}

__attribute__((used)) static
struct adf4350_platform_data *adf4350_parse_dt(struct device *dev)
{
	return NULL;
}

__attribute__((used)) static int adf4350_probe(struct spi_device *spi)
{
	struct adf4350_platform_data *pdata;
	struct iio_dev *indio_dev;
	struct adf4350_state *st;
	struct clk *clk = NULL;
	int ret;

	if (spi->dev.of_node) {
		pdata = adf4350_parse_dt(&spi->dev);
		if (pdata == NULL)
			return -EINVAL;
	} else {
		pdata = spi->dev.platform_data;
	}

	if (!pdata) {
		dev_warn(&spi->dev, "no platform data? using default\n");
		pdata = &default_pdata;
	}

	if (!pdata->clkin) {
		clk = devm_clk_get(&spi->dev, "clkin");
		if (IS_ERR(clk))
			return -EPROBE_DEFER;

		ret = clk_prepare_enable(clk);
		if (ret < 0)
			return ret;
	}

	indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
	if (indio_dev == NULL) {
		ret =  -ENOMEM;
		goto error_disable_clk;
	}

	st = iio_priv(indio_dev);

	st->reg = devm_regulator_get(&spi->dev, "vcc");
	if (!IS_ERR(st->reg)) {
		ret = regulator_enable(st->reg);
		if (ret)
			goto error_disable_clk;
	}

	spi_set_drvdata(spi, indio_dev);
	st->spi = spi;
	st->pdata = pdata;

	indio_dev->dev.parent = &spi->dev;
	indio_dev->name = (pdata->name[0] != 0) ? pdata->name :
		spi_get_device_id(spi)->name;

	indio_dev->info = &adf4350_info;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = &adf4350_chan;
	indio_dev->num_channels = 1;

	st->chspc = pdata->channel_spacing;
	if (clk) {
		st->clk = clk;
		st->clkin = clk_get_rate(clk);
	} else {
		st->clkin = pdata->clkin;
	}

	st->min_out_freq = spi_get_device_id(spi)->driver_data == 4351 ?
		ADF4351_MIN_OUT_FREQ : ADF4350_MIN_OUT_FREQ;

	memset(st->regs_hw, 0xFF, sizeof(st->regs_hw));

	if (gpio_is_valid(pdata->gpio_lock_detect)) {
		ret = devm_gpio_request(&spi->dev, pdata->gpio_lock_detect,
					indio_dev->name);
		if (ret) {
			dev_err(&spi->dev, "fail to request lock detect GPIO-%d",
				pdata->gpio_lock_detect);
			goto error_disable_reg;
		}
		gpio_direction_input(pdata->gpio_lock_detect);
	}

	if (pdata->power_up_frequency) {
		ret = adf4350_set_freq(st, pdata->power_up_frequency);
		if (ret)
			goto error_disable_reg;
	}

	ret = iio_device_register(indio_dev);
	if (ret)
		goto error_disable_reg;

	return 0;

error_disable_reg:
	if (!IS_ERR(st->reg))
		regulator_disable(st->reg);
error_disable_clk:
	if (clk)
		clk_disable_unprepare(clk);

	return ret;
}

__attribute__((used)) static int adf4350_remove(struct spi_device *spi)
{
	struct iio_dev *indio_dev = spi_get_drvdata(spi);
	struct adf4350_state *st = iio_priv(indio_dev);
	struct regulator *reg = st->reg;

	st->regs[ADF4350_REG2] |= ADF4350_REG2_POWER_DOWN_EN;
	adf4350_sync_config(st);

	iio_device_unregister(indio_dev);

	if (st->clk)
		clk_disable_unprepare(st->clk);

	if (!IS_ERR(reg))
		regulator_disable(reg);

	return 0;
}

