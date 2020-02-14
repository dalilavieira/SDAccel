#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct vf610_adc_feature {size_t conv_mode; int clk_div; int default_sample_time; int lst_adder_index; int clk_sel; int vol_ref; int calibration; int ovwren; int res_mode; int sample_rate; } ;
struct vf610_adc {unsigned int clk; unsigned long* max_adck_rate; unsigned long* sample_freq_avail; unsigned int regs; int value; int* buffer; int vref_uv; unsigned int vref; int /*<<< orphan*/  completion; struct vf610_adc_feature adc_feature; TYPE_2__* dev; } ;
struct resource {int dummy; } ;
struct TYPE_10__ {int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_2__ dev; } ;
struct TYPE_9__ {int /*<<< orphan*/  of_node; TYPE_2__* parent; } ;
struct iio_dev {int* channels; int num_channels; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; TYPE_1__ dev; int /*<<< orphan*/  name; int /*<<< orphan*/  masklength; int /*<<< orphan*/  active_scan_mask; int /*<<< orphan*/  mlock; int /*<<< orphan*/  trig; } ;
struct iio_chan_spec {unsigned int channel; int /*<<< orphan*/  type; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  size_t ssize_t ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
 int DEFAULT_SAMPLE_TIME ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ETIMEDOUT ; 
#define  IIO_CHAN_INFO_PROCESSED 152 
#define  IIO_CHAN_INFO_RAW 151 
#define  IIO_CHAN_INFO_SAMP_FREQ 150 
#define  IIO_CHAN_INFO_SCALE 149 
#define  IIO_TEMP 148 
 int IIO_VAL_FRACTIONAL_LOG2 ; 
 int IIO_VAL_INT ; 
#define  IIO_VOLTAGE 147 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (unsigned int) ; 
 unsigned long NSEC_PER_SEC ; 
 scalar_t__ PAGE_SIZE ; 
 int PTR_ERR (unsigned int) ; 
#define  VF610_ADCIOC_ADACK_SET 146 
#define  VF610_ADCIOC_ALTCLK_SET 145 
#define  VF610_ADCIOC_BUSCLK_SET 144 
#define  VF610_ADCIOC_VR_VALT_SET 143 
#define  VF610_ADCIOC_VR_VBG_SET 142 
#define  VF610_ADCIOC_VR_VREF_SET 141 
#define  VF610_ADCK_CYCLES_13 140 
#define  VF610_ADCK_CYCLES_17 139 
#define  VF610_ADCK_CYCLES_21 138 
#define  VF610_ADCK_CYCLES_25 137 
#define  VF610_ADCK_CYCLES_3 136 
#define  VF610_ADCK_CYCLES_5 135 
#define  VF610_ADCK_CYCLES_7 134 
#define  VF610_ADCK_CYCLES_9 133 
 int VF610_ADC_ADACK_SEL ; 
 int VF610_ADC_ADCCLK_MASK ; 
 void* VF610_ADC_ADCHC (unsigned int) ; 
 int VF610_ADC_ADCON ; 
 int VF610_ADC_ADHSC_EN ; 
 int VF610_ADC_ADLPC_EN ; 
 int VF610_ADC_ADLSMP_LONG ; 
 int VF610_ADC_ADSTS_LONG ; 
 int VF610_ADC_ADSTS_NORMAL ; 
 int VF610_ADC_ADSTS_SHORT ; 
 unsigned int VF610_ADC_AIEN ; 
 int VF610_ADC_ALTCLK_SEL ; 
 int VF610_ADC_AVGEN ; 
 int VF610_ADC_AVGS_16 ; 
 int VF610_ADC_AVGS_32 ; 
 int VF610_ADC_AVGS_8 ; 
 int VF610_ADC_AVGS_MASK ; 
 int VF610_ADC_BUSCLK2_SEL ; 
 int VF610_ADC_CAL ; 
 int VF610_ADC_CALF ; 
 int VF610_ADC_CLK_DIV2 ; 
 int VF610_ADC_CLK_DIV4 ; 
 int VF610_ADC_CLK_DIV8 ; 
 int VF610_ADC_CLK_MASK ; 
 unsigned int VF610_ADC_CONV_DISABLE ; 
 scalar_t__ VF610_ADC_CONV_HIGH_SPEED ; 
 scalar_t__ VF610_ADC_CONV_LOW_POWER ; 
 int VF610_ADC_HS_COCO0 ; 
 int VF610_ADC_MODE_BIT10 ; 
 int VF610_ADC_MODE_BIT12 ; 
 int VF610_ADC_MODE_BIT8 ; 
 int VF610_ADC_MODE_MASK ; 
 int VF610_ADC_OVWREN ; 
 int VF610_ADC_REFSEL_VALT ; 
 int VF610_ADC_REFSEL_VBG ; 
#define  VF610_ADC_SAMPLE_1 132 
#define  VF610_ADC_SAMPLE_16 131 
#define  VF610_ADC_SAMPLE_32 130 
#define  VF610_ADC_SAMPLE_4 129 
#define  VF610_ADC_SAMPLE_8 128 
 int /*<<< orphan*/  VF610_ADC_TIMEOUT ; 
 unsigned int VF610_REG_ADC_CFG ; 
 unsigned int VF610_REG_ADC_GC ; 
 unsigned int VF610_REG_ADC_GS ; 
 unsigned int VF610_REG_ADC_HC0 ; 
 unsigned int VF610_REG_ADC_HS ; 
 unsigned int VF610_REG_ADC_PCTL ; 
 unsigned int VF610_REG_ADC_R0 ; 
 int VF610_TEMP_SLOPE_COEFF ; 
 int /*<<< orphan*/  VF610_VTEMP25_3V3 ; 
 int /*<<< orphan*/  clk_disable_unprepare (unsigned int) ; 
 unsigned long clk_get_rate (unsigned int) ; 
 int clk_prepare_enable (unsigned int) ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,...) ; 
 int /*<<< orphan*/  dev_name (TYPE_2__*) ; 
 struct iio_dev* dev_to_iio_dev (struct device*) ; 
 unsigned int devm_clk_get (TYPE_2__*,char*) ; 
 struct iio_dev* devm_iio_device_alloc (TYPE_2__*,int) ; 
 unsigned int devm_ioremap_resource (TYPE_2__*,struct resource*) ; 
 unsigned int devm_regulator_get (TYPE_2__*,char*) ; 
 int devm_request_irq (TYPE_2__*,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct iio_dev*) ; 
 unsigned int find_first_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int fls (int) ; 
 scalar_t__ iio_buffer_enabled (struct iio_dev*) ; 
 int iio_device_register (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_get_time_ns (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_pollfunc_store_time ; 
 struct vf610_adc* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_push_to_buffers_with_timestamp (struct iio_dev*,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_trigger_notify_done (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_triggered_buffer_cleanup (struct iio_dev*) ; 
 int iio_triggered_buffer_postenable (struct iio_dev*) ; 
 int iio_triggered_buffer_predisable (struct iio_dev*) ; 
 int iio_triggered_buffer_setup (struct iio_dev*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  iio_triggered_buffer_setup_ops ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int of_property_read_u32 (int /*<<< orphan*/ ,char*,int*) ; 
 int /*<<< orphan*/  of_property_read_u32_array (int /*<<< orphan*/ ,char*,unsigned long*,int) ; 
 struct iio_dev* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct iio_dev*) ; 
 void* readl (unsigned int) ; 
 int /*<<< orphan*/  regulator_disable (unsigned int) ; 
 int regulator_enable (unsigned int) ; 
 int regulator_get_voltage (unsigned int) ; 
 int /*<<< orphan*/  reinit_completion (int /*<<< orphan*/ *) ; 
 scalar_t__ scnprintf (char*,scalar_t__,char*,int) ; 
 int* vf610_adc_iio_channels ; 
 int /*<<< orphan*/  vf610_adc_iio_info ; 
 int* vf610_hw_avgs ; 
 int* vf610_lst_adder ; 
 long wait_for_completion_interruptible_timeout (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wait_for_completion_timeout (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writel (unsigned int,unsigned int) ; 

__attribute__((used)) static inline void vf610_adc_calculate_rates(struct vf610_adc *info)
{
	struct vf610_adc_feature *adc_feature = &info->adc_feature;
	unsigned long adck_rate, ipg_rate = clk_get_rate(info->clk);
	u32 adck_period, lst_addr_min;
	int divisor, i;

	adck_rate = info->max_adck_rate[adc_feature->conv_mode];

	if (adck_rate) {
		/* calculate clk divider which is within specification */
		divisor = ipg_rate / adck_rate;
		adc_feature->clk_div = 1 << fls(divisor + 1);
	} else {
		/* fall-back value using a safe divisor */
		adc_feature->clk_div = 8;
	}

	adck_rate = ipg_rate / adc_feature->clk_div;

	/*
	 * Determine the long sample time adder value to be used based
	 * on the default minimum sample time provided.
	 */
	adck_period = NSEC_PER_SEC / adck_rate;
	lst_addr_min = adc_feature->default_sample_time / adck_period;
	for (i = 0; i < ARRAY_SIZE(vf610_lst_adder); i++) {
		if (vf610_lst_adder[i] > lst_addr_min) {
			adc_feature->lst_adder_index = i;
			break;
		}
	}

	/*
	 * Calculate ADC sample frequencies
	 * Sample time unit is ADCK cycles. ADCK clk source is ipg clock,
	 * which is the same as bus clock.
	 *
	 * ADC conversion time = SFCAdder + AverageNum x (BCT + LSTAdder)
	 * SFCAdder: fixed to 6 ADCK cycles
	 * AverageNum: 1, 4, 8, 16, 32 samples for hardware average.
	 * BCT (Base Conversion Time): fixed to 25 ADCK cycles for 12 bit mode
	 * LSTAdder(Long Sample Time): 3, 5, 7, 9, 13, 17, 21, 25 ADCK cycles
	 */
	for (i = 0; i < ARRAY_SIZE(vf610_hw_avgs); i++)
		info->sample_freq_avail[i] =
			adck_rate / (6 + vf610_hw_avgs[i] *
			 (25 + vf610_lst_adder[adc_feature->lst_adder_index]));
}

__attribute__((used)) static inline void vf610_adc_cfg_init(struct vf610_adc *info)
{
	struct vf610_adc_feature *adc_feature = &info->adc_feature;

	/* set default Configuration for ADC controller */
	adc_feature->clk_sel = VF610_ADCIOC_BUSCLK_SET;
	adc_feature->vol_ref = VF610_ADCIOC_VR_VREF_SET;

	adc_feature->calibration = true;
	adc_feature->ovwren = true;

	adc_feature->res_mode = 12;
	adc_feature->sample_rate = 1;

	adc_feature->conv_mode = VF610_ADC_CONV_LOW_POWER;

	vf610_adc_calculate_rates(info);
}

__attribute__((used)) static void vf610_adc_cfg_post_set(struct vf610_adc *info)
{
	struct vf610_adc_feature *adc_feature = &info->adc_feature;
	int cfg_data = 0;
	int gc_data = 0;

	switch (adc_feature->clk_sel) {
	case VF610_ADCIOC_ALTCLK_SET:
		cfg_data |= VF610_ADC_ALTCLK_SEL;
		break;
	case VF610_ADCIOC_ADACK_SET:
		cfg_data |= VF610_ADC_ADACK_SEL;
		break;
	default:
		break;
	}

	/* low power set for calibration */
	cfg_data |= VF610_ADC_ADLPC_EN;

	/* enable high speed for calibration */
	cfg_data |= VF610_ADC_ADHSC_EN;

	/* voltage reference */
	switch (adc_feature->vol_ref) {
	case VF610_ADCIOC_VR_VREF_SET:
		break;
	case VF610_ADCIOC_VR_VALT_SET:
		cfg_data |= VF610_ADC_REFSEL_VALT;
		break;
	case VF610_ADCIOC_VR_VBG_SET:
		cfg_data |= VF610_ADC_REFSEL_VBG;
		break;
	default:
		dev_err(info->dev, "error voltage reference\n");
	}

	/* data overwrite enable */
	if (adc_feature->ovwren)
		cfg_data |= VF610_ADC_OVWREN;

	writel(cfg_data, info->regs + VF610_REG_ADC_CFG);
	writel(gc_data, info->regs + VF610_REG_ADC_GC);
}

__attribute__((used)) static void vf610_adc_calibration(struct vf610_adc *info)
{
	int adc_gc, hc_cfg;

	if (!info->adc_feature.calibration)
		return;

	/* enable calibration interrupt */
	hc_cfg = VF610_ADC_AIEN | VF610_ADC_CONV_DISABLE;
	writel(hc_cfg, info->regs + VF610_REG_ADC_HC0);

	adc_gc = readl(info->regs + VF610_REG_ADC_GC);
	writel(adc_gc | VF610_ADC_CAL, info->regs + VF610_REG_ADC_GC);

	if (!wait_for_completion_timeout(&info->completion, VF610_ADC_TIMEOUT))
		dev_err(info->dev, "Timeout for adc calibration\n");

	adc_gc = readl(info->regs + VF610_REG_ADC_GS);
	if (adc_gc & VF610_ADC_CALF)
		dev_err(info->dev, "ADC calibration failed\n");

	info->adc_feature.calibration = false;
}

__attribute__((used)) static void vf610_adc_cfg_set(struct vf610_adc *info)
{
	struct vf610_adc_feature *adc_feature = &(info->adc_feature);
	int cfg_data;

	cfg_data = readl(info->regs + VF610_REG_ADC_CFG);

	cfg_data &= ~VF610_ADC_ADLPC_EN;
	if (adc_feature->conv_mode == VF610_ADC_CONV_LOW_POWER)
		cfg_data |= VF610_ADC_ADLPC_EN;

	cfg_data &= ~VF610_ADC_ADHSC_EN;
	if (adc_feature->conv_mode == VF610_ADC_CONV_HIGH_SPEED)
		cfg_data |= VF610_ADC_ADHSC_EN;

	writel(cfg_data, info->regs + VF610_REG_ADC_CFG);
}

__attribute__((used)) static void vf610_adc_sample_set(struct vf610_adc *info)
{
	struct vf610_adc_feature *adc_feature = &(info->adc_feature);
	int cfg_data, gc_data;

	cfg_data = readl(info->regs + VF610_REG_ADC_CFG);
	gc_data = readl(info->regs + VF610_REG_ADC_GC);

	/* resolution mode */
	cfg_data &= ~VF610_ADC_MODE_MASK;
	switch (adc_feature->res_mode) {
	case 8:
		cfg_data |= VF610_ADC_MODE_BIT8;
		break;
	case 10:
		cfg_data |= VF610_ADC_MODE_BIT10;
		break;
	case 12:
		cfg_data |= VF610_ADC_MODE_BIT12;
		break;
	default:
		dev_err(info->dev, "error resolution mode\n");
		break;
	}

	/* clock select and clock divider */
	cfg_data &= ~(VF610_ADC_CLK_MASK | VF610_ADC_ADCCLK_MASK);
	switch (adc_feature->clk_div) {
	case 1:
		break;
	case 2:
		cfg_data |= VF610_ADC_CLK_DIV2;
		break;
	case 4:
		cfg_data |= VF610_ADC_CLK_DIV4;
		break;
	case 8:
		cfg_data |= VF610_ADC_CLK_DIV8;
		break;
	case 16:
		switch (adc_feature->clk_sel) {
		case VF610_ADCIOC_BUSCLK_SET:
			cfg_data |= VF610_ADC_BUSCLK2_SEL | VF610_ADC_CLK_DIV8;
			break;
		default:
			dev_err(info->dev, "error clk divider\n");
			break;
		}
		break;
	}

	/*
	 * Set ADLSMP and ADSTS based on the Long Sample Time Adder value
	 * determined.
	 */
	switch (adc_feature->lst_adder_index) {
	case VF610_ADCK_CYCLES_3:
		break;
	case VF610_ADCK_CYCLES_5:
		cfg_data |= VF610_ADC_ADSTS_SHORT;
		break;
	case VF610_ADCK_CYCLES_7:
		cfg_data |= VF610_ADC_ADSTS_NORMAL;
		break;
	case VF610_ADCK_CYCLES_9:
		cfg_data |= VF610_ADC_ADSTS_LONG;
		break;
	case VF610_ADCK_CYCLES_13:
		cfg_data |= VF610_ADC_ADLSMP_LONG;
		break;
	case VF610_ADCK_CYCLES_17:
		cfg_data |= VF610_ADC_ADLSMP_LONG;
		cfg_data |= VF610_ADC_ADSTS_SHORT;
		break;
	case VF610_ADCK_CYCLES_21:
		cfg_data |= VF610_ADC_ADLSMP_LONG;
		cfg_data |= VF610_ADC_ADSTS_NORMAL;
		break;
	case VF610_ADCK_CYCLES_25:
		cfg_data |= VF610_ADC_ADLSMP_LONG;
		cfg_data |= VF610_ADC_ADSTS_NORMAL;
		break;
	default:
		dev_err(info->dev, "error in sample time select\n");
	}

	/* update hardware average selection */
	cfg_data &= ~VF610_ADC_AVGS_MASK;
	gc_data &= ~VF610_ADC_AVGEN;
	switch (adc_feature->sample_rate) {
	case VF610_ADC_SAMPLE_1:
		break;
	case VF610_ADC_SAMPLE_4:
		gc_data |= VF610_ADC_AVGEN;
		break;
	case VF610_ADC_SAMPLE_8:
		gc_data |= VF610_ADC_AVGEN;
		cfg_data |= VF610_ADC_AVGS_8;
		break;
	case VF610_ADC_SAMPLE_16:
		gc_data |= VF610_ADC_AVGEN;
		cfg_data |= VF610_ADC_AVGS_16;
		break;
	case VF610_ADC_SAMPLE_32:
		gc_data |= VF610_ADC_AVGEN;
		cfg_data |= VF610_ADC_AVGS_32;
		break;
	default:
		dev_err(info->dev,
			"error hardware sample average select\n");
	}

	writel(cfg_data, info->regs + VF610_REG_ADC_CFG);
	writel(gc_data, info->regs + VF610_REG_ADC_GC);
}

__attribute__((used)) static void vf610_adc_hw_init(struct vf610_adc *info)
{
	/* CFG: Feature set */
	vf610_adc_cfg_post_set(info);
	vf610_adc_sample_set(info);

	/* adc calibration */
	vf610_adc_calibration(info);

	/* CFG: power and speed set */
	vf610_adc_cfg_set(info);
}

__attribute__((used)) static int vf610_set_conversion_mode(struct iio_dev *indio_dev,
				     const struct iio_chan_spec *chan,
				     unsigned int mode)
{
	struct vf610_adc *info = iio_priv(indio_dev);

	mutex_lock(&indio_dev->mlock);
	info->adc_feature.conv_mode = mode;
	vf610_adc_calculate_rates(info);
	vf610_adc_hw_init(info);
	mutex_unlock(&indio_dev->mlock);

	return 0;
}

__attribute__((used)) static int vf610_get_conversion_mode(struct iio_dev *indio_dev,
				     const struct iio_chan_spec *chan)
{
	struct vf610_adc *info = iio_priv(indio_dev);

	return info->adc_feature.conv_mode;
}

__attribute__((used)) static int vf610_adc_read_data(struct vf610_adc *info)
{
	int result;

	result = readl(info->regs + VF610_REG_ADC_R0);

	switch (info->adc_feature.res_mode) {
	case 8:
		result &= 0xFF;
		break;
	case 10:
		result &= 0x3FF;
		break;
	case 12:
		result &= 0xFFF;
		break;
	default:
		break;
	}

	return result;
}

__attribute__((used)) static irqreturn_t vf610_adc_isr(int irq, void *dev_id)
{
	struct iio_dev *indio_dev = dev_id;
	struct vf610_adc *info = iio_priv(indio_dev);
	int coco;

	coco = readl(info->regs + VF610_REG_ADC_HS);
	if (coco & VF610_ADC_HS_COCO0) {
		info->value = vf610_adc_read_data(info);
		if (iio_buffer_enabled(indio_dev)) {
			info->buffer[0] = info->value;
			iio_push_to_buffers_with_timestamp(indio_dev,
					info->buffer,
					iio_get_time_ns(indio_dev));
			iio_trigger_notify_done(indio_dev->trig);
		} else
			complete(&info->completion);
	}

	return IRQ_HANDLED;
}

__attribute__((used)) static ssize_t vf610_show_samp_freq_avail(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct vf610_adc *info = iio_priv(dev_to_iio_dev(dev));
	size_t len = 0;
	int i;

	for (i = 0; i < ARRAY_SIZE(info->sample_freq_avail); i++)
		len += scnprintf(buf + len, PAGE_SIZE - len,
			"%u ", info->sample_freq_avail[i]);

	/* replace trailing space by newline */
	buf[len - 1] = '\n';

	return len;
}

__attribute__((used)) static int vf610_read_raw(struct iio_dev *indio_dev,
			struct iio_chan_spec const *chan,
			int *val,
			int *val2,
			long mask)
{
	struct vf610_adc *info = iio_priv(indio_dev);
	unsigned int hc_cfg;
	long ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
	case IIO_CHAN_INFO_PROCESSED:
		mutex_lock(&indio_dev->mlock);
		if (iio_buffer_enabled(indio_dev)) {
			mutex_unlock(&indio_dev->mlock);
			return -EBUSY;
		}

		reinit_completion(&info->completion);
		hc_cfg = VF610_ADC_ADCHC(chan->channel);
		hc_cfg |= VF610_ADC_AIEN;
		writel(hc_cfg, info->regs + VF610_REG_ADC_HC0);
		ret = wait_for_completion_interruptible_timeout
				(&info->completion, VF610_ADC_TIMEOUT);
		if (ret == 0) {
			mutex_unlock(&indio_dev->mlock);
			return -ETIMEDOUT;
		}
		if (ret < 0) {
			mutex_unlock(&indio_dev->mlock);
			return ret;
		}

		switch (chan->type) {
		case IIO_VOLTAGE:
			*val = info->value;
			break;
		case IIO_TEMP:
			/*
			 * Calculate in degree Celsius times 1000
			 * Using the typical sensor slope of 1.84 mV/°C
			 * and VREFH_ADC at 3.3V, V at 25°C of 699 mV
			 */
			*val = 25000 - ((int)info->value - VF610_VTEMP25_3V3) *
					1000000 / VF610_TEMP_SLOPE_COEFF;

			break;
		default:
			mutex_unlock(&indio_dev->mlock);
			return -EINVAL;
		}

		mutex_unlock(&indio_dev->mlock);
		return IIO_VAL_INT;

	case IIO_CHAN_INFO_SCALE:
		*val = info->vref_uv / 1000;
		*val2 = info->adc_feature.res_mode;
		return IIO_VAL_FRACTIONAL_LOG2;

	case IIO_CHAN_INFO_SAMP_FREQ:
		*val = info->sample_freq_avail[info->adc_feature.sample_rate];
		*val2 = 0;
		return IIO_VAL_INT;

	default:
		break;
	}

	return -EINVAL;
}

__attribute__((used)) static int vf610_write_raw(struct iio_dev *indio_dev,
			struct iio_chan_spec const *chan,
			int val,
			int val2,
			long mask)
{
	struct vf610_adc *info = iio_priv(indio_dev);
	int i;

	switch (mask) {
	case IIO_CHAN_INFO_SAMP_FREQ:
		for (i = 0;
			i < ARRAY_SIZE(info->sample_freq_avail);
			i++)
			if (val == info->sample_freq_avail[i]) {
				info->adc_feature.sample_rate = i;
				vf610_adc_sample_set(info);
				return 0;
			}
		break;

	default:
		break;
	}

	return -EINVAL;
}

__attribute__((used)) static int vf610_adc_buffer_postenable(struct iio_dev *indio_dev)
{
	struct vf610_adc *info = iio_priv(indio_dev);
	unsigned int channel;
	int ret;
	int val;

	ret = iio_triggered_buffer_postenable(indio_dev);
	if (ret)
		return ret;

	val = readl(info->regs + VF610_REG_ADC_GC);
	val |= VF610_ADC_ADCON;
	writel(val, info->regs + VF610_REG_ADC_GC);

	channel = find_first_bit(indio_dev->active_scan_mask,
						indio_dev->masklength);

	val = VF610_ADC_ADCHC(channel);
	val |= VF610_ADC_AIEN;

	writel(val, info->regs + VF610_REG_ADC_HC0);

	return 0;
}

__attribute__((used)) static int vf610_adc_buffer_predisable(struct iio_dev *indio_dev)
{
	struct vf610_adc *info = iio_priv(indio_dev);
	unsigned int hc_cfg = 0;
	int val;

	val = readl(info->regs + VF610_REG_ADC_GC);
	val &= ~VF610_ADC_ADCON;
	writel(val, info->regs + VF610_REG_ADC_GC);

	hc_cfg |= VF610_ADC_CONV_DISABLE;
	hc_cfg &= ~VF610_ADC_AIEN;

	writel(hc_cfg, info->regs + VF610_REG_ADC_HC0);

	return iio_triggered_buffer_predisable(indio_dev);
}

__attribute__((used)) static int vf610_adc_reg_access(struct iio_dev *indio_dev,
			unsigned reg, unsigned writeval,
			unsigned *readval)
{
	struct vf610_adc *info = iio_priv(indio_dev);

	if ((readval == NULL) ||
		((reg % 4) || (reg > VF610_REG_ADC_PCTL)))
		return -EINVAL;

	*readval = readl(info->regs + reg);

	return 0;
}

__attribute__((used)) static int vf610_adc_probe(struct platform_device *pdev)
{
	struct vf610_adc *info;
	struct iio_dev *indio_dev;
	struct resource *mem;
	int irq;
	int ret;

	indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(struct vf610_adc));
	if (!indio_dev) {
		dev_err(&pdev->dev, "Failed allocating iio device\n");
		return -ENOMEM;
	}

	info = iio_priv(indio_dev);
	info->dev = &pdev->dev;

	mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	info->regs = devm_ioremap_resource(&pdev->dev, mem);
	if (IS_ERR(info->regs))
		return PTR_ERR(info->regs);

	irq = platform_get_irq(pdev, 0);
	if (irq < 0) {
		dev_err(&pdev->dev, "no irq resource?\n");
		return irq;
	}

	ret = devm_request_irq(info->dev, irq,
				vf610_adc_isr, 0,
				dev_name(&pdev->dev), indio_dev);
	if (ret < 0) {
		dev_err(&pdev->dev, "failed requesting irq, irq = %d\n", irq);
		return ret;
	}

	info->clk = devm_clk_get(&pdev->dev, "adc");
	if (IS_ERR(info->clk)) {
		dev_err(&pdev->dev, "failed getting clock, err = %ld\n",
						PTR_ERR(info->clk));
		return PTR_ERR(info->clk);
	}

	info->vref = devm_regulator_get(&pdev->dev, "vref");
	if (IS_ERR(info->vref))
		return PTR_ERR(info->vref);

	ret = regulator_enable(info->vref);
	if (ret)
		return ret;

	info->vref_uv = regulator_get_voltage(info->vref);

	of_property_read_u32_array(pdev->dev.of_node, "fsl,adck-max-frequency",
			info->max_adck_rate, 3);

	ret = of_property_read_u32(pdev->dev.of_node, "min-sample-time",
			&info->adc_feature.default_sample_time);
	if (ret)
		info->adc_feature.default_sample_time = DEFAULT_SAMPLE_TIME;

	platform_set_drvdata(pdev, indio_dev);

	init_completion(&info->completion);

	indio_dev->name = dev_name(&pdev->dev);
	indio_dev->dev.parent = &pdev->dev;
	indio_dev->dev.of_node = pdev->dev.of_node;
	indio_dev->info = &vf610_adc_iio_info;
	indio_dev->modes = INDIO_DIRECT_MODE;
	indio_dev->channels = vf610_adc_iio_channels;
	indio_dev->num_channels = ARRAY_SIZE(vf610_adc_iio_channels);

	ret = clk_prepare_enable(info->clk);
	if (ret) {
		dev_err(&pdev->dev,
			"Could not prepare or enable the clock.\n");
		goto error_adc_clk_enable;
	}

	vf610_adc_cfg_init(info);
	vf610_adc_hw_init(info);

	ret = iio_triggered_buffer_setup(indio_dev, &iio_pollfunc_store_time,
					NULL, &iio_triggered_buffer_setup_ops);
	if (ret < 0) {
		dev_err(&pdev->dev, "Couldn't initialise the buffer\n");
		goto error_iio_device_register;
	}

	ret = iio_device_register(indio_dev);
	if (ret) {
		dev_err(&pdev->dev, "Couldn't register the device.\n");
		goto error_adc_buffer_init;
	}

	return 0;

error_adc_buffer_init:
	iio_triggered_buffer_cleanup(indio_dev);
error_iio_device_register:
	clk_disable_unprepare(info->clk);
error_adc_clk_enable:
	regulator_disable(info->vref);

	return ret;
}

__attribute__((used)) static int vf610_adc_remove(struct platform_device *pdev)
{
	struct iio_dev *indio_dev = platform_get_drvdata(pdev);
	struct vf610_adc *info = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);
	iio_triggered_buffer_cleanup(indio_dev);
	regulator_disable(info->vref);
	clk_disable_unprepare(info->clk);

	return 0;
}

