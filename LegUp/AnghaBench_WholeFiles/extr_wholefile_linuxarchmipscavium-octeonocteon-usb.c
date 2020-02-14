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
struct TYPE_9__ {int output_sel; } ;
struct TYPE_8__ {int tx_oe; } ;
struct TYPE_7__ {int output_sel; } ;
union cvmx_gpio_bit_cfgx {void* u64; TYPE_4__ cn70xx; TYPE_3__ s; TYPE_2__ cn73xx; } ;
struct TYPE_10__ {int ppc_en; int ppc_active_high_en; } ;
union cvm_usbdrd_uctl_host_cfg {void* u64; TYPE_5__ s; } ;
struct TYPE_6__ {int uphy_rst; int uahc_rst; int uctl_rst; int h_clkdiv_rst; int h_clkdiv_sel; int h_clk_en; int ref_clk_sel; int ref_clk_fsel; int mpll_multiplier; int ssc_en; int ref_ssp_en; int hs_power_en; int ss_power_en; int csclk_en; scalar_t__ drd_mode; scalar_t__ ref_clk_div2; } ;
union cvm_usbdrd_uctl_ctl {void* u64; TYPE_1__ s; } ;
typedef  int uint32_t ;
typedef  int u64 ;
typedef  int u32 ;
struct device_node {int dummy; } ;
struct device {struct device_node* of_node; } ;

/* Variables and functions */
 int CVMX_GPIO_BIT_CFGX (int) ; 
 int CVMX_GPIO_XBIT_CFGX (int) ; 
 int EINVAL ; 
 int /*<<< orphan*/  OCTEON_CN73XX ; 
 int /*<<< orphan*/  OCTEON_CNF75XX ; 
 int OCTEON_H_CLKDIV_SEL ; 
 scalar_t__ OCTEON_IS_MODEL (int /*<<< orphan*/ ) ; 
 int OCTEON_MAX_H_CLK_RATE ; 
 int OCTEON_MIN_H_CLK_RATE ; 
 int* clk_div ; 
 void* cvmx_read_csr (int) ; 
 int /*<<< orphan*/  cvmx_write_csr (int,void*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 int octeon_get_io_clock_rate () ; 
 int /*<<< orphan*/ * of_find_property (struct device_node*,char*,int*) ; 
 int of_property_read_string (struct device_node*,char*,char const**) ; 
 int of_property_read_u32 (struct device_node*,char*,int*) ; 
 int /*<<< orphan*/  of_property_read_u32_array (struct device_node*,char*,int*,int) ; 
 int /*<<< orphan*/  pr_err (char*,...) ; 
 scalar_t__ strcmp (char const*,char const*) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static int dwc3_octeon_config_power(struct device *dev, u64 base)
{
#define UCTL_HOST_CFG	0xe0
	union cvm_usbdrd_uctl_host_cfg uctl_host_cfg;
	union cvmx_gpio_bit_cfgx gpio_bit;
	uint32_t gpio_pwr[3];
	int gpio, len, power_active_low;
	struct device_node *node = dev->of_node;
	int index = (base >> 24) & 1;

	if (of_find_property(node, "power", &len) != NULL) {
		if (len == 12) {
			of_property_read_u32_array(node, "power", gpio_pwr, 3);
			power_active_low = gpio_pwr[2] & 0x01;
			gpio = gpio_pwr[1];
		} else if (len == 8) {
			of_property_read_u32_array(node, "power", gpio_pwr, 2);
			power_active_low = 0;
			gpio = gpio_pwr[1];
		} else {
			dev_err(dev, "dwc3 controller clock init failure.\n");
			return -EINVAL;
		}
		if ((OCTEON_IS_MODEL(OCTEON_CN73XX) ||
		    OCTEON_IS_MODEL(OCTEON_CNF75XX))
		    && gpio <= 31) {
			gpio_bit.u64 = cvmx_read_csr(CVMX_GPIO_BIT_CFGX(gpio));
			gpio_bit.s.tx_oe = 1;
			gpio_bit.cn73xx.output_sel = (index == 0 ? 0x14 : 0x15);
			cvmx_write_csr(CVMX_GPIO_BIT_CFGX(gpio), gpio_bit.u64);
		} else if (gpio <= 15) {
			gpio_bit.u64 = cvmx_read_csr(CVMX_GPIO_BIT_CFGX(gpio));
			gpio_bit.s.tx_oe = 1;
			gpio_bit.cn70xx.output_sel = (index == 0 ? 0x14 : 0x19);
			cvmx_write_csr(CVMX_GPIO_BIT_CFGX(gpio), gpio_bit.u64);
		} else {
			gpio_bit.u64 = cvmx_read_csr(CVMX_GPIO_XBIT_CFGX(gpio));
			gpio_bit.s.tx_oe = 1;
			gpio_bit.cn70xx.output_sel = (index == 0 ? 0x14 : 0x19);
			cvmx_write_csr(CVMX_GPIO_XBIT_CFGX(gpio), gpio_bit.u64);
		}

		/* Enable XHCI power control and set if active high or low. */
		uctl_host_cfg.u64 = cvmx_read_csr(base + UCTL_HOST_CFG);
		uctl_host_cfg.s.ppc_en = 1;
		uctl_host_cfg.s.ppc_active_high_en = !power_active_low;
		cvmx_write_csr(base + UCTL_HOST_CFG, uctl_host_cfg.u64);
	} else {
		/* Disable XHCI power control and set if active high. */
		uctl_host_cfg.u64 = cvmx_read_csr(base + UCTL_HOST_CFG);
		uctl_host_cfg.s.ppc_en = 0;
		uctl_host_cfg.s.ppc_active_high_en = 0;
		cvmx_write_csr(base + UCTL_HOST_CFG, uctl_host_cfg.u64);
		dev_warn(dev, "dwc3 controller clock init failure.\n");
	}
	return 0;
}

__attribute__((used)) static int dwc3_octeon_clocks_start(struct device *dev, u64 base)
{
	union cvm_usbdrd_uctl_ctl uctl_ctl;
	int ref_clk_sel = 2;
	u64 div;
	u32 clock_rate;
	int mpll_mul;
	int i;
	u64 h_clk_rate;
	u64 uctl_ctl_reg = base;

	if (dev->of_node) {
		const char *ss_clock_type;
		const char *hs_clock_type;

		i = of_property_read_u32(dev->of_node,
					 "refclk-frequency", &clock_rate);
		if (i) {
			pr_err("No UCTL \"refclk-frequency\"\n");
			return -EINVAL;
		}
		i = of_property_read_string(dev->of_node,
					    "refclk-type-ss", &ss_clock_type);
		if (i) {
			pr_err("No UCTL \"refclk-type-ss\"\n");
			return -EINVAL;
		}
		i = of_property_read_string(dev->of_node,
					    "refclk-type-hs", &hs_clock_type);
		if (i) {
			pr_err("No UCTL \"refclk-type-hs\"\n");
			return -EINVAL;
		}
		if (strcmp("dlmc_ref_clk0", ss_clock_type) == 0) {
			if (strcmp(hs_clock_type, "dlmc_ref_clk0") == 0)
				ref_clk_sel = 0;
			else if (strcmp(hs_clock_type, "pll_ref_clk") == 0)
				ref_clk_sel = 2;
			else
				pr_err("Invalid HS clock type %s, using  pll_ref_clk instead\n",
				       hs_clock_type);
		} else if (strcmp(ss_clock_type, "dlmc_ref_clk1") == 0) {
			if (strcmp(hs_clock_type, "dlmc_ref_clk1") == 0)
				ref_clk_sel = 1;
			else if (strcmp(hs_clock_type, "pll_ref_clk") == 0)
				ref_clk_sel = 3;
			else {
				pr_err("Invalid HS clock type %s, using  pll_ref_clk instead\n",
				       hs_clock_type);
				ref_clk_sel = 3;
			}
		} else
			pr_err("Invalid SS clock type %s, using  dlmc_ref_clk0 instead\n",
			       ss_clock_type);

		if ((ref_clk_sel == 0 || ref_clk_sel == 1) &&
				  (clock_rate != 100000000))
			pr_err("Invalid UCTL clock rate of %u, using 100000000 instead\n",
			       clock_rate);

	} else {
		pr_err("No USB UCTL device node\n");
		return -EINVAL;
	}

	/*
	 * Step 1: Wait for all voltages to be stable...that surely
	 *         happened before starting the kernel. SKIP
	 */

	/* Step 2: Select GPIO for overcurrent indication, if desired. SKIP */

	/* Step 3: Assert all resets. */
	uctl_ctl.u64 = cvmx_read_csr(uctl_ctl_reg);
	uctl_ctl.s.uphy_rst = 1;
	uctl_ctl.s.uahc_rst = 1;
	uctl_ctl.s.uctl_rst = 1;
	cvmx_write_csr(uctl_ctl_reg, uctl_ctl.u64);

	/* Step 4a: Reset the clock dividers. */
	uctl_ctl.u64 = cvmx_read_csr(uctl_ctl_reg);
	uctl_ctl.s.h_clkdiv_rst = 1;
	cvmx_write_csr(uctl_ctl_reg, uctl_ctl.u64);

	/* Step 4b: Select controller clock frequency. */
	for (div = 0; div < OCTEON_H_CLKDIV_SEL; div++) {
		h_clk_rate = octeon_get_io_clock_rate() / clk_div[div];
		if (h_clk_rate <= OCTEON_MAX_H_CLK_RATE &&
				 h_clk_rate >= OCTEON_MIN_H_CLK_RATE)
			break;
	}
	uctl_ctl.u64 = cvmx_read_csr(uctl_ctl_reg);
	uctl_ctl.s.h_clkdiv_sel = div;
	uctl_ctl.s.h_clk_en = 1;
	cvmx_write_csr(uctl_ctl_reg, uctl_ctl.u64);
	uctl_ctl.u64 = cvmx_read_csr(uctl_ctl_reg);
	if ((div != uctl_ctl.s.h_clkdiv_sel) || (!uctl_ctl.s.h_clk_en)) {
		dev_err(dev, "dwc3 controller clock init failure.\n");
			return -EINVAL;
	}

	/* Step 4c: Deassert the controller clock divider reset. */
	uctl_ctl.u64 = cvmx_read_csr(uctl_ctl_reg);
	uctl_ctl.s.h_clkdiv_rst = 0;
	cvmx_write_csr(uctl_ctl_reg, uctl_ctl.u64);

	/* Step 5a: Reference clock configuration. */
	uctl_ctl.u64 = cvmx_read_csr(uctl_ctl_reg);
	uctl_ctl.s.ref_clk_sel = ref_clk_sel;
	uctl_ctl.s.ref_clk_fsel = 0x07;
	uctl_ctl.s.ref_clk_div2 = 0;
	switch (clock_rate) {
	default:
		dev_err(dev, "Invalid ref_clk %u, using 100000000 instead\n",
			clock_rate);
	case 100000000:
		mpll_mul = 0x19;
		if (ref_clk_sel < 2)
			uctl_ctl.s.ref_clk_fsel = 0x27;
		break;
	case 50000000:
		mpll_mul = 0x32;
		break;
	case 125000000:
		mpll_mul = 0x28;
		break;
	}
	uctl_ctl.s.mpll_multiplier = mpll_mul;

	/* Step 5b: Configure and enable spread-spectrum for SuperSpeed. */
	uctl_ctl.s.ssc_en = 1;

	/* Step 5c: Enable SuperSpeed. */
	uctl_ctl.s.ref_ssp_en = 1;

	/* Step 5d: Cofngiure PHYs. SKIP */

	/* Step 6a & 6b: Power up PHYs. */
	uctl_ctl.s.hs_power_en = 1;
	uctl_ctl.s.ss_power_en = 1;
	cvmx_write_csr(uctl_ctl_reg, uctl_ctl.u64);

	/* Step 7: Wait 10 controller-clock cycles to take effect. */
	udelay(10);

	/* Step 8a: Deassert UCTL reset signal. */
	uctl_ctl.u64 = cvmx_read_csr(uctl_ctl_reg);
	uctl_ctl.s.uctl_rst = 0;
	cvmx_write_csr(uctl_ctl_reg, uctl_ctl.u64);

	/* Step 8b: Wait 10 controller-clock cycles. */
	udelay(10);

	/* Steo 8c: Setup power-power control. */
	if (dwc3_octeon_config_power(dev, base)) {
		dev_err(dev, "Error configuring power.\n");
		return -EINVAL;
	}

	/* Step 8d: Deassert UAHC reset signal. */
	uctl_ctl.u64 = cvmx_read_csr(uctl_ctl_reg);
	uctl_ctl.s.uahc_rst = 0;
	cvmx_write_csr(uctl_ctl_reg, uctl_ctl.u64);

	/* Step 8e: Wait 10 controller-clock cycles. */
	udelay(10);

	/* Step 9: Enable conditional coprocessor clock of UCTL. */
	uctl_ctl.u64 = cvmx_read_csr(uctl_ctl_reg);
	uctl_ctl.s.csclk_en = 1;
	cvmx_write_csr(uctl_ctl_reg, uctl_ctl.u64);

	/*Step 10: Set for host mode only. */
	uctl_ctl.u64 = cvmx_read_csr(uctl_ctl_reg);
	uctl_ctl.s.drd_mode = 0;
	cvmx_write_csr(uctl_ctl_reg, uctl_ctl.u64);

	return 0;
}

