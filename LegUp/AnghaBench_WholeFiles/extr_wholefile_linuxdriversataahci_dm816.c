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
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct ata_link {int dummy; } ;
struct ahci_host_priv {scalar_t__ mmio; int /*<<< orphan*/ * clks; } ;

/* Variables and functions */
 scalar_t__ AHCI_DM816_P0PHYCR_REG ; 
 scalar_t__ AHCI_DM816_P1PHYCR_REG ; 
 int AHCI_DM816_PHY_ENPLL (int) ; 
 int AHCI_DM816_PHY_LOS (int) ; 
 int AHCI_DM816_PHY_MPY (int) ; 
 int AHCI_DM816_PHY_RXCDR (int) ; 
 int AHCI_DM816_PHY_RXEQ (int) ; 
 int AHCI_DM816_PHY_TXSWING (int) ; 
 unsigned long AHCI_DM816_PLL_OUT ; 
 int ARRAY_SIZE (unsigned long*) ; 
 int EBUSY ; 
 int EINVAL ; 
 scalar_t__ IS_ERR (struct ahci_host_priv*) ; 
 int PTR_ERR (struct ahci_host_priv*) ; 
 int /*<<< orphan*/  ahci_check_ready ; 
 int /*<<< orphan*/  ahci_dm816_platform_sht ; 
 int /*<<< orphan*/  ahci_dm816_port_info ; 
 int ahci_do_softreset (struct ata_link*,unsigned int*,int,unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ahci_platform_disable_resources (struct ahci_host_priv*) ; 
 int ahci_platform_enable_resources (struct ahci_host_priv*) ; 
 struct ahci_host_priv* ahci_platform_get_resources (struct platform_device*,int /*<<< orphan*/ ) ; 
 int ahci_platform_init_host (struct platform_device*,struct ahci_host_priv*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 unsigned long clk_get_rate (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 unsigned long* pll_mpy_table ; 
 int sata_srst_pmp (struct ata_link*) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static int ahci_dm816_get_mpy_bits(unsigned long refclk_rate)
{
	unsigned long pll_multiplier;
	int i;

	/*
	 * We need to determine the value of the multiplier (MPY) bits.
	 * In order to include the 8.25 multiplier we need to first divide
	 * the refclk rate by 100.
	 */
	pll_multiplier = AHCI_DM816_PLL_OUT / (refclk_rate / 100);

	for (i = 0; i < ARRAY_SIZE(pll_mpy_table); i++) {
		if (pll_mpy_table[i] == pll_multiplier)
			return i;
	}

	/*
	 * We should have divided evenly - if not, return an invalid
	 * value.
	 */
	return -1;
}

__attribute__((used)) static int ahci_dm816_phy_init(struct ahci_host_priv *hpriv, struct device *dev)
{
	unsigned long refclk_rate;
	int mpy;
	u32 val;

	/*
	 * We should have been supplied two clocks: the functional and
	 * keep-alive clock and the external reference clock. We need the
	 * rate of the latter to calculate the correct value of MPY bits.
	 */
	if (!hpriv->clks[1]) {
		dev_err(dev, "reference clock not supplied\n");
		return -EINVAL;
	}

	refclk_rate = clk_get_rate(hpriv->clks[1]);
	if ((refclk_rate % 100) != 0) {
		dev_err(dev, "reference clock rate must be divisible by 100\n");
		return -EINVAL;
	}

	mpy = ahci_dm816_get_mpy_bits(refclk_rate);
	if (mpy < 0) {
		dev_err(dev, "can't calculate the MPY bits value\n");
		return -EINVAL;
	}

	/* Enable the PHY and configure the first HBA port. */
	val = AHCI_DM816_PHY_MPY(mpy) | AHCI_DM816_PHY_LOS(1) |
	      AHCI_DM816_PHY_RXCDR(4) | AHCI_DM816_PHY_RXEQ(1) |
	      AHCI_DM816_PHY_TXSWING(3) | AHCI_DM816_PHY_ENPLL(1);
	writel(val, hpriv->mmio + AHCI_DM816_P0PHYCR_REG);

	/* Configure the second HBA port. */
	val = AHCI_DM816_PHY_LOS(1) | AHCI_DM816_PHY_RXCDR(4) |
	      AHCI_DM816_PHY_RXEQ(1) | AHCI_DM816_PHY_TXSWING(3);
	writel(val, hpriv->mmio + AHCI_DM816_P1PHYCR_REG);

	return 0;
}

__attribute__((used)) static int ahci_dm816_softreset(struct ata_link *link,
				unsigned int *class, unsigned long deadline)
{
	int pmp, ret;

	pmp = sata_srst_pmp(link);

	/*
	 * There's an issue with the SATA controller on DM816 SoC: if we
	 * enable Port Multiplier support, but the drive is connected directly
	 * to the board, it can't be detected. As a workaround: if PMP is
	 * enabled, we first call ahci_do_softreset() and pass it the result of
	 * sata_srst_pmp(). If this call fails, we retry with pmp = 0.
	 */
	ret = ahci_do_softreset(link, class, pmp, deadline, ahci_check_ready);
	if (pmp && ret == -EBUSY)
		return ahci_do_softreset(link, class, 0,
					 deadline, ahci_check_ready);

	return ret;
}

__attribute__((used)) static int ahci_dm816_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct ahci_host_priv *hpriv;
	int rc;

	hpriv = ahci_platform_get_resources(pdev, 0);
	if (IS_ERR(hpriv))
		return PTR_ERR(hpriv);

	rc = ahci_platform_enable_resources(hpriv);
	if (rc)
		return rc;

	rc = ahci_dm816_phy_init(hpriv, dev);
	if (rc)
		goto disable_resources;

	rc = ahci_platform_init_host(pdev, hpriv,
				     &ahci_dm816_port_info,
				     &ahci_dm816_platform_sht);
	if (rc)
		goto disable_resources;

	return 0;

disable_resources:
	ahci_platform_disable_resources(hpriv);

	return rc;
}

