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
struct clk {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 scalar_t__ IS_ERR (struct clk*) ; 
 int /*<<< orphan*/  MODE_PIN9 ; 
 int /*<<< orphan*/  MODSWR ; 
 int /*<<< orphan*/  PCIECR ; 
 int PCIECR_CLKEN ; 
 int PTR_ERR (struct clk*) ; 
 int /*<<< orphan*/  PWRCR ; 
 int PWRCR_PDWNACK ; 
 int PWRCR_PDWNREQ ; 
 int /*<<< orphan*/  SBCR ; 
 unsigned int SCBR_I2CCEN ; 
 unsigned int SCBR_I2CMEN ; 
 int /*<<< orphan*/  SRSTR ; 
 struct clk* clk_get (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  clk_put (struct clk*) ; 
 int clk_register (int /*<<< orphan*/ *) ; 
 int clk_set_rate (struct clk*,int) ; 
 int /*<<< orphan*/  clkdev_add (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cpu_sleep () ; 
 int fpga_read_reg (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fpga_write_reg (int,int /*<<< orphan*/ ) ; 
 int i2c_register_board_info (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  sdk7786_i2c_devices ; 
 int /*<<< orphan*/  sdk7786_pcie_cl ; 
 int /*<<< orphan*/  sdk7786_pcie_clk ; 
 scalar_t__ test_mode_pin (int /*<<< orphan*/ ) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static int sdk7786_i2c_setup(void)
{
	unsigned int tmp;

	/*
	 * Hand over I2C control to the FPGA.
	 */
	tmp = fpga_read_reg(SBCR);
	tmp &= ~SCBR_I2CCEN;
	tmp |= SCBR_I2CMEN;
	fpga_write_reg(tmp, SBCR);

	return i2c_register_board_info(0, sdk7786_i2c_devices,
				       ARRAY_SIZE(sdk7786_i2c_devices));
}

__attribute__((used)) static int sdk7786_mode_pins(void)
{
	return fpga_read_reg(MODSWR);
}

__attribute__((used)) static int sdk7786_pcie_clk_enable(struct clk *clk)
{
	fpga_write_reg(fpga_read_reg(PCIECR) | PCIECR_CLKEN, PCIECR);
	return 0;
}

__attribute__((used)) static void sdk7786_pcie_clk_disable(struct clk *clk)
{
	fpga_write_reg(fpga_read_reg(PCIECR) & ~PCIECR_CLKEN, PCIECR);
}

__attribute__((used)) static int sdk7786_clk_init(void)
{
	struct clk *clk;
	int ret;

	/*
	 * Only handle the EXTAL case, anyone interfacing a crystal
	 * resonator will need to provide their own input clock.
	 */
	if (test_mode_pin(MODE_PIN9))
		return -EINVAL;

	clk = clk_get(NULL, "extal");
	if (IS_ERR(clk))
		return PTR_ERR(clk);
	ret = clk_set_rate(clk, 33333333);
	clk_put(clk);

	/*
	 * Setup the FPGA clocks.
	 */
	ret = clk_register(&sdk7786_pcie_clk);
	if (unlikely(ret)) {
		pr_err("FPGA clock registration failed\n");
		return ret;
	}

	clkdev_add(&sdk7786_pcie_cl);

	return 0;
}

__attribute__((used)) static void sdk7786_restart(char *cmd)
{
	fpga_write_reg(0xa5a5, SRSTR);
}

__attribute__((used)) static void sdk7786_power_off(void)
{
	fpga_write_reg(fpga_read_reg(PWRCR) | PWRCR_PDWNREQ, PWRCR);

	/*
	 * It can take up to 20us for the R8C to do its job, back off and
	 * wait a bit until we've been shut off. Even though newer FPGA
	 * versions don't set the ACK bit, the latency issue remains.
	 */
	while ((fpga_read_reg(PWRCR) & PWRCR_PDWNACK) == 0)
		cpu_sleep();
}

