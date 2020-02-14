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
typedef  int /*<<< orphan*/  u32 ;
struct rtsx_pcr {int flags; int sd30_drive_sel_1v8; int sd30_drive_sel_3v3; int extra_caps; int num_slots; int ic_version; int /*<<< orphan*/  ms_pull_ctl_disable_tbl; int /*<<< orphan*/  ms_pull_ctl_enable_tbl; int /*<<< orphan*/  sd_pull_ctl_disable_tbl; int /*<<< orphan*/  sd_pull_ctl_enable_tbl; void* rx_initial_phase; void* tx_initial_phase; int /*<<< orphan*/  aspm_en; int /*<<< orphan*/  card_drive_sel; int /*<<< orphan*/ * ops; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASPM_FORCE_CTL ; 
 int /*<<< orphan*/  ASPM_L1_EN ; 
 int /*<<< orphan*/  CARD_AUTO_BLINK ; 
 int /*<<< orphan*/  CARD_GPIO ; 
 int /*<<< orphan*/  CARD_GPIO_DIR ; 
 int /*<<< orphan*/  CARD_PWR_CTL ; 
 int DRIVER_TYPE_B ; 
 int DRIVER_TYPE_D ; 
 int EINVAL ; 
 int EXTRA_CAPS_MMC_8BIT ; 
 int EXTRA_CAPS_SD_SDR104 ; 
 int EXTRA_CAPS_SD_SDR50 ; 
 int /*<<< orphan*/  FPDCTL ; 
 int LDO3318_PWR_MASK ; 
 int MS_PARTIAL_POWER_ON ; 
 int MS_POWER_MASK ; 
 int MS_POWER_OFF ; 
 int MS_POWER_ON ; 
 int OUTPUT_1V8 ; 
 int OUTPUT_3V3 ; 
 int PCR_MS_PMOS ; 
 int /*<<< orphan*/  PCR_SETTING_REG1 ; 
 int /*<<< orphan*/  PCR_SETTING_REG2 ; 
 int /*<<< orphan*/  PETXCFG ; 
 int PMOS_STRG_400mA ; 
 int PMOS_STRG_MASK ; 
 int /*<<< orphan*/  PWR_GATE_CTRL ; 
 int /*<<< orphan*/  RTS5209_CARD_DRIVE_DEFAULT ; 
 int RTSX_MS_CARD ; 
 int /*<<< orphan*/  SD30_DRIVE_SEL ; 
 int SD_PARTIAL_POWER_ON ; 
 int SD_POWER_MASK ; 
 int SD_POWER_OFF ; 
 int SD_POWER_ON ; 
 void* SET_CLOCK_PHASE (int,int,int) ; 
 int /*<<< orphan*/  WRITE_REG_CMD ; 
 int /*<<< orphan*/  pcr_dbg (struct rtsx_pcr*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rts5209_ms_pull_ctl_disable_tbl ; 
 int /*<<< orphan*/  rts5209_ms_pull_ctl_enable_tbl ; 
 int /*<<< orphan*/  rts5209_pcr_ops ; 
 scalar_t__ rts5209_reg_check_ms_pmos (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rts5209_reg_to_aspm (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rts5209_reg_to_card_drive_sel (int /*<<< orphan*/ ) ; 
 int rts5209_reg_to_sd30_drive_sel_1v8 (int /*<<< orphan*/ ) ; 
 int rts5209_reg_to_sd30_drive_sel_3v3 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rts5209_sd_pull_ctl_disable_tbl ; 
 int /*<<< orphan*/  rts5209_sd_pull_ctl_enable_tbl ; 
 scalar_t__ rts5209_vendor_setting1_valid (int /*<<< orphan*/ ) ; 
 scalar_t__ rts5209_vendor_setting2_valid (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rtsx_pci_add_cmd (struct rtsx_pcr*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  rtsx_pci_init_cmd (struct rtsx_pcr*) ; 
 int /*<<< orphan*/  rtsx_pci_read_config_dword (struct rtsx_pcr*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int rtsx_pci_readb (struct rtsx_pcr*,int) ; 
 int rtsx_pci_send_cmd (struct rtsx_pcr*,int) ; 
 int rtsx_pci_write_phy_register (struct rtsx_pcr*,int,int) ; 
 int rtsx_pci_write_register (struct rtsx_pcr*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static inline u8 map_sd_drive(int idx)
{
	u8 sd_drive[4] = {
		0x01,	/* Type D */
		0x02,	/* Type C */
		0x05,	/* Type A */
		0x03	/* Type B */
	};

	return sd_drive[idx];
}

__attribute__((used)) static u8 rts5209_get_ic_version(struct rtsx_pcr *pcr)
{
	u8 val;

	val = rtsx_pci_readb(pcr, 0x1C);
	return val & 0x0F;
}

__attribute__((used)) static void rts5209_fetch_vendor_settings(struct rtsx_pcr *pcr)
{
	u32 reg;

	rtsx_pci_read_config_dword(pcr, PCR_SETTING_REG1, &reg);
	pcr_dbg(pcr, "Cfg 0x%x: 0x%x\n", PCR_SETTING_REG1, reg);

	if (rts5209_vendor_setting1_valid(reg)) {
		if (rts5209_reg_check_ms_pmos(reg))
			pcr->flags |= PCR_MS_PMOS;
		pcr->aspm_en = rts5209_reg_to_aspm(reg);
	}

	rtsx_pci_read_config_dword(pcr, PCR_SETTING_REG2, &reg);
	pcr_dbg(pcr, "Cfg 0x%x: 0x%x\n", PCR_SETTING_REG2, reg);

	if (rts5209_vendor_setting2_valid(reg)) {
		pcr->sd30_drive_sel_1v8 =
			rts5209_reg_to_sd30_drive_sel_1v8(reg);
		pcr->sd30_drive_sel_3v3 =
			rts5209_reg_to_sd30_drive_sel_3v3(reg);
		pcr->card_drive_sel = rts5209_reg_to_card_drive_sel(reg);
	}
}

__attribute__((used)) static void rts5209_force_power_down(struct rtsx_pcr *pcr, u8 pm_state)
{
	rtsx_pci_write_register(pcr, FPDCTL, 0x07, 0x07);
}

__attribute__((used)) static int rts5209_extra_init_hw(struct rtsx_pcr *pcr)
{
	rtsx_pci_init_cmd(pcr);

	/* Turn off LED */
	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, CARD_GPIO, 0xFF, 0x03);
	/* Reset ASPM state to default value */
	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, ASPM_FORCE_CTL, 0x3F, 0);
	/* Force CLKREQ# PIN to drive 0 to request clock */
	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, PETXCFG, 0x08, 0x08);
	/* Configure GPIO as output */
	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, CARD_GPIO_DIR, 0xFF, 0x03);
	/* Configure driving */
	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, SD30_DRIVE_SEL,
			0xFF, pcr->sd30_drive_sel_3v3);

	return rtsx_pci_send_cmd(pcr, 100);
}

__attribute__((used)) static int rts5209_optimize_phy(struct rtsx_pcr *pcr)
{
	return rtsx_pci_write_phy_register(pcr, 0x00, 0xB966);
}

__attribute__((used)) static int rts5209_turn_on_led(struct rtsx_pcr *pcr)
{
	return rtsx_pci_write_register(pcr, CARD_GPIO, 0x01, 0x00);
}

__attribute__((used)) static int rts5209_turn_off_led(struct rtsx_pcr *pcr)
{
	return rtsx_pci_write_register(pcr, CARD_GPIO, 0x01, 0x01);
}

__attribute__((used)) static int rts5209_enable_auto_blink(struct rtsx_pcr *pcr)
{
	return rtsx_pci_write_register(pcr, CARD_AUTO_BLINK, 0xFF, 0x0D);
}

__attribute__((used)) static int rts5209_disable_auto_blink(struct rtsx_pcr *pcr)
{
	return rtsx_pci_write_register(pcr, CARD_AUTO_BLINK, 0x08, 0x00);
}

__attribute__((used)) static int rts5209_card_power_on(struct rtsx_pcr *pcr, int card)
{
	int err;
	u8 pwr_mask, partial_pwr_on, pwr_on;

	pwr_mask = SD_POWER_MASK;
	partial_pwr_on = SD_PARTIAL_POWER_ON;
	pwr_on = SD_POWER_ON;

	if ((pcr->flags & PCR_MS_PMOS) && (card == RTSX_MS_CARD)) {
		pwr_mask = MS_POWER_MASK;
		partial_pwr_on = MS_PARTIAL_POWER_ON;
		pwr_on = MS_POWER_ON;
	}

	rtsx_pci_init_cmd(pcr);
	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, CARD_PWR_CTL,
			pwr_mask, partial_pwr_on);
	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, PWR_GATE_CTRL,
			LDO3318_PWR_MASK, 0x04);
	err = rtsx_pci_send_cmd(pcr, 100);
	if (err < 0)
		return err;

	/* To avoid too large in-rush current */
	udelay(150);

	rtsx_pci_init_cmd(pcr);
	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, CARD_PWR_CTL, pwr_mask, pwr_on);
	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, PWR_GATE_CTRL,
			LDO3318_PWR_MASK, 0x00);
	return rtsx_pci_send_cmd(pcr, 100);
}

__attribute__((used)) static int rts5209_card_power_off(struct rtsx_pcr *pcr, int card)
{
	u8 pwr_mask, pwr_off;

	pwr_mask = SD_POWER_MASK;
	pwr_off = SD_POWER_OFF;

	if ((pcr->flags & PCR_MS_PMOS) && (card == RTSX_MS_CARD)) {
		pwr_mask = MS_POWER_MASK;
		pwr_off = MS_POWER_OFF;
	}

	rtsx_pci_init_cmd(pcr);
	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, CARD_PWR_CTL,
			pwr_mask | PMOS_STRG_MASK, pwr_off | PMOS_STRG_400mA);
	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, PWR_GATE_CTRL,
			LDO3318_PWR_MASK, 0x06);
	return rtsx_pci_send_cmd(pcr, 100);
}

__attribute__((used)) static int rts5209_switch_output_voltage(struct rtsx_pcr *pcr, u8 voltage)
{
	int err;

	if (voltage == OUTPUT_3V3) {
		err = rtsx_pci_write_register(pcr,
				SD30_DRIVE_SEL, 0x07, pcr->sd30_drive_sel_3v3);
		if (err < 0)
			return err;
		err = rtsx_pci_write_phy_register(pcr, 0x08, 0x4FC0 | 0x24);
		if (err < 0)
			return err;
	} else if (voltage == OUTPUT_1V8) {
		err = rtsx_pci_write_register(pcr,
				SD30_DRIVE_SEL, 0x07, pcr->sd30_drive_sel_1v8);
		if (err < 0)
			return err;
		err = rtsx_pci_write_phy_register(pcr, 0x08, 0x4C40 | 0x24);
		if (err < 0)
			return err;
	} else {
		return -EINVAL;
	}

	return 0;
}

void rts5209_init_params(struct rtsx_pcr *pcr)
{
	pcr->extra_caps = EXTRA_CAPS_SD_SDR50 |
		EXTRA_CAPS_SD_SDR104 | EXTRA_CAPS_MMC_8BIT;
	pcr->num_slots = 2;
	pcr->ops = &rts5209_pcr_ops;

	pcr->flags = 0;
	pcr->card_drive_sel = RTS5209_CARD_DRIVE_DEFAULT;
	pcr->sd30_drive_sel_1v8 = DRIVER_TYPE_B;
	pcr->sd30_drive_sel_3v3 = DRIVER_TYPE_D;
	pcr->aspm_en = ASPM_L1_EN;
	pcr->tx_initial_phase = SET_CLOCK_PHASE(27, 27, 16);
	pcr->rx_initial_phase = SET_CLOCK_PHASE(24, 6, 5);

	pcr->ic_version = rts5209_get_ic_version(pcr);
	pcr->sd_pull_ctl_enable_tbl = rts5209_sd_pull_ctl_enable_tbl;
	pcr->sd_pull_ctl_disable_tbl = rts5209_sd_pull_ctl_disable_tbl;
	pcr->ms_pull_ctl_enable_tbl = rts5209_ms_pull_ctl_enable_tbl;
	pcr->ms_pull_ctl_disable_tbl = rts5209_ms_pull_ctl_disable_tbl;
}

