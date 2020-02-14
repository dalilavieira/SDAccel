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
typedef  int /*<<< orphan*/  u64 ;
typedef  int u32 ;

/* Variables and functions */
 int CALDUTY ; 
 int CR_REG_TIMER ; 
 int CR_TIME_SCALE ; 
 int M_CSYSREQ ; 
 int P0_IPDIPDMSYNTH ; 
 int P0_IPDRXL ; 
 int P0_IPDTXL ; 
 int P0_IRST_HARD_SYNTH ; 
 int P0_IRST_HARD_TXRX ; 
 int P0_IRST_POR ; 
 int P0_PHY_READY ; 
 int P1_IPDIPDMSYNTH ; 
 int P1_IPDRXL ; 
 int P1_IPDTXL ; 
 int P1_IRST_HARD_SYNTH ; 
 int P1_IRST_HARD_TXRX ; 
 int P1_IRST_POR ; 
 int P1_PHY_READY ; 
 int PHY_MEM_ACCESS ; 
 int PPMDRIFTMAX_HI ; 
 int RXCDRCALFOSC0 ; 
 int RXDPIF ; 
 int SATA_CTL ; 
 int SATA_RST_N ; 
 int SATA_STATUS ; 
 int S_CSYSREQ ; 
 int /*<<< orphan*/  nlm_get_sata_regbase (int) ; 
 int nlm_read_sata_reg (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  nlm_write_sata_reg (int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  pr_debug (char*) ; 
 int /*<<< orphan*/  pr_info (char*,...) ; 
 int* sata_phy_config1 ; 
 int* sata_phy_config2 ; 
 scalar_t__ sata_phy_debug ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static void sata_clear_glue_reg(u64 regbase, u32 off, u32 bit)
{
	u32 reg_val;

	reg_val = nlm_read_sata_reg(regbase, off);
	nlm_write_sata_reg(regbase, off, (reg_val & ~bit));
}

__attribute__((used)) static void sata_set_glue_reg(u64 regbase, u32 off, u32 bit)
{
	u32 reg_val;

	reg_val = nlm_read_sata_reg(regbase, off);
	nlm_write_sata_reg(regbase, off, (reg_val | bit));
}

__attribute__((used)) static void write_phy_reg(u64 regbase, u32 addr, u32 physel, u8 data)
{
	nlm_write_sata_reg(regbase, PHY_MEM_ACCESS,
		(1u << 31) | (physel << 24) | (data << 16) | addr);
	udelay(850);
}

__attribute__((used)) static u8 read_phy_reg(u64 regbase, u32 addr, u32 physel)
{
	u32 val;

	nlm_write_sata_reg(regbase, PHY_MEM_ACCESS,
		(0 << 31) | (physel << 24) | (0 << 16) | addr);
	udelay(850);
	val = nlm_read_sata_reg(regbase, PHY_MEM_ACCESS);
	return (val >> 16) & 0xff;
}

__attribute__((used)) static void config_sata_phy(u64 regbase)
{
	u32 port, i, reg;
	u8 val;

	for (port = 0; port < 2; port++) {
		for (i = 0, reg = RXCDRCALFOSC0; reg <= CALDUTY; reg++, i++)
			write_phy_reg(regbase, reg, port, sata_phy_config1[i]);

		for (i = 0, reg = RXDPIF; reg <= PPMDRIFTMAX_HI; reg++, i++)
			write_phy_reg(regbase, reg, port, sata_phy_config2[i]);

		/* Fix for PHY link up failures at lower temperatures */
		write_phy_reg(regbase, 0x800F, port, 0x1f);

		val = read_phy_reg(regbase, 0x0029, port);
		write_phy_reg(regbase, 0x0029, port, val | (0x7 << 1));

		val = read_phy_reg(regbase, 0x0056, port);
		write_phy_reg(regbase, 0x0056, port, val & ~(1 << 3));

		val = read_phy_reg(regbase, 0x0018, port);
		write_phy_reg(regbase, 0x0018, port, val & ~(0x7 << 0));
	}
}

__attribute__((used)) static void check_phy_register(u64 regbase, u32 addr, u32 physel, u8 xdata)
{
	u8 data;

	data = read_phy_reg(regbase, addr, physel);
	pr_info("PHY read addr = 0x%x physel = %d data = 0x%x %s\n",
		addr, physel, data, data == xdata ? "TRUE" : "FALSE");
}

__attribute__((used)) static void verify_sata_phy_config(u64 regbase)
{
	u32 port, i, reg;

	for (port = 0; port < 2; port++) {
		for (i = 0, reg = RXCDRCALFOSC0; reg <= CALDUTY; reg++, i++)
			check_phy_register(regbase, reg, port,
						sata_phy_config1[i]);

		for (i = 0, reg = RXDPIF; reg <= PPMDRIFTMAX_HI; reg++, i++)
			check_phy_register(regbase, reg, port,
						sata_phy_config2[i]);
	}
}

__attribute__((used)) static void nlm_sata_firmware_init(int node)
{
	u32 reg_val;
	u64 regbase;
	int n;

	pr_info("Initializing XLP9XX On-chip AHCI...\n");
	regbase = nlm_get_sata_regbase(node);

	/* Reset port0 */
	sata_clear_glue_reg(regbase, SATA_CTL, P0_IRST_POR);
	sata_clear_glue_reg(regbase, SATA_CTL, P0_IRST_HARD_TXRX);
	sata_clear_glue_reg(regbase, SATA_CTL, P0_IRST_HARD_SYNTH);
	sata_clear_glue_reg(regbase, SATA_CTL, P0_IPDTXL);
	sata_clear_glue_reg(regbase, SATA_CTL, P0_IPDRXL);
	sata_clear_glue_reg(regbase, SATA_CTL, P0_IPDIPDMSYNTH);

	/* port1 */
	sata_clear_glue_reg(regbase, SATA_CTL, P1_IRST_POR);
	sata_clear_glue_reg(regbase, SATA_CTL, P1_IRST_HARD_TXRX);
	sata_clear_glue_reg(regbase, SATA_CTL, P1_IRST_HARD_SYNTH);
	sata_clear_glue_reg(regbase, SATA_CTL, P1_IPDTXL);
	sata_clear_glue_reg(regbase, SATA_CTL, P1_IPDRXL);
	sata_clear_glue_reg(regbase, SATA_CTL, P1_IPDIPDMSYNTH);
	udelay(300);

	/* Set PHY */
	sata_set_glue_reg(regbase, SATA_CTL, P0_IPDTXL);
	sata_set_glue_reg(regbase, SATA_CTL, P0_IPDRXL);
	sata_set_glue_reg(regbase, SATA_CTL, P0_IPDIPDMSYNTH);
	sata_set_glue_reg(regbase, SATA_CTL, P1_IPDTXL);
	sata_set_glue_reg(regbase, SATA_CTL, P1_IPDRXL);
	sata_set_glue_reg(regbase, SATA_CTL, P1_IPDIPDMSYNTH);

	udelay(1000);
	sata_set_glue_reg(regbase, SATA_CTL, P0_IRST_POR);
	udelay(1000);
	sata_set_glue_reg(regbase, SATA_CTL, P1_IRST_POR);
	udelay(1000);

	/* setup PHY */
	config_sata_phy(regbase);
	if (sata_phy_debug)
		verify_sata_phy_config(regbase);

	udelay(1000);
	sata_set_glue_reg(regbase, SATA_CTL, P0_IRST_HARD_TXRX);
	sata_set_glue_reg(regbase, SATA_CTL, P0_IRST_HARD_SYNTH);
	sata_set_glue_reg(regbase, SATA_CTL, P1_IRST_HARD_TXRX);
	sata_set_glue_reg(regbase, SATA_CTL, P1_IRST_HARD_SYNTH);
	udelay(300);

	/* Override reset in serial PHY mode */
	sata_set_glue_reg(regbase, CR_REG_TIMER, CR_TIME_SCALE);
	/* Set reset SATA */
	sata_set_glue_reg(regbase, SATA_CTL, SATA_RST_N);
	sata_set_glue_reg(regbase, SATA_CTL, M_CSYSREQ);
	sata_set_glue_reg(regbase, SATA_CTL, S_CSYSREQ);

	pr_debug("Waiting for PHYs to come up.\n");
	n = 10000;
	do {
		reg_val = nlm_read_sata_reg(regbase, SATA_STATUS);
		if ((reg_val & P1_PHY_READY) && (reg_val & P0_PHY_READY))
			break;
		udelay(10);
	} while (--n > 0);

	if (reg_val  & P0_PHY_READY)
		pr_info("PHY0 is up.\n");
	else
		pr_info("PHY0 is down.\n");
	if (reg_val  & P1_PHY_READY)
		pr_info("PHY1 is up.\n");
	else
		pr_info("PHY1 is down.\n");

	pr_info("XLP AHCI Init Done.\n");
}

