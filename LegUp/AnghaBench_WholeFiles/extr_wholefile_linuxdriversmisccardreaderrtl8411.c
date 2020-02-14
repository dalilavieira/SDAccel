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
struct rtsx_pcr {int sd30_drive_sel_1v8; int card_drive_sel; int sd30_drive_sel_3v3; int extra_caps; int num_slots; int ic_version; int /*<<< orphan*/ * ops; void* rx_initial_phase; void* tx_initial_phase; void* aspm_en; scalar_t__ flags; } ;

/* Variables and functions */
 void* ASPM_L1_EN ; 
 int BPP_ASIC_1V8 ; 
 int BPP_ASIC_2V0 ; 
 int BPP_ASIC_3V3 ; 
 int BPP_LDO_ON ; 
 int BPP_LDO_POWB ; 
 int BPP_LDO_SUSPEND ; 
 int BPP_PAD_1V8 ; 
 int BPP_PAD_3V3 ; 
 int BPP_PAD_MASK ; 
 int BPP_POWER_10_PERCENT_ON ; 
 int BPP_POWER_15_PERCENT_ON ; 
 int BPP_POWER_5_PERCENT_ON ; 
 int BPP_POWER_MASK ; 
 int BPP_POWER_OFF ; 
 int BPP_POWER_ON ; 
 int BPP_REG_TUNED18 ; 
 int BPP_TUNED18_SHIFT_8402 ; 
 int BPP_TUNED18_SHIFT_8411 ; 
 int /*<<< orphan*/  CARD_AUTO_BLINK ; 
 unsigned int CARD_EXIST ; 
 int /*<<< orphan*/  CARD_GPIO ; 
 int /*<<< orphan*/  CARD_PULL_CTL3 ; 
 int /*<<< orphan*/  CARD_PWR_CTL ; 
 int CD_AUTO_DISABLE ; 
 int CD_DISABLE_MASK ; 
 int CD_ENABLE ; 
 int /*<<< orphan*/  CD_PAD_CTL ; 
 int CLK_TO_DIV_N ; 
 int DRIVER_TYPE_B ; 
 int DRIVER_TYPE_D ; 
 int /*<<< orphan*/  EFUSE_CONTENT ; 
 int EINVAL ; 
 int EXTRA_CAPS_SD_SDR104 ; 
 int EXTRA_CAPS_SD_SDR50 ; 
 int /*<<< orphan*/  FPDCTL ; 
 int /*<<< orphan*/  FUNC_FORCE_CTL ; 
 int /*<<< orphan*/  LDO_CTL ; 
 int MS_CD_EN_ONLY ; 
 unsigned int MS_EXIST ; 
 int OUTPUT_1V8 ; 
 int OUTPUT_3V3 ; 
 int /*<<< orphan*/  PCR_SETTING_REG1 ; 
 int /*<<< orphan*/  PCR_SETTING_REG3 ; 
 int /*<<< orphan*/  RTL8411B_PACKAGE_MODE ; 
 int RTL8411_CARD_DRIVE_DEFAULT ; 
 int /*<<< orphan*/  RTSX_BIPR ; 
 int /*<<< orphan*/  SD30_DRIVE_SEL ; 
 int SD_CD_EN_ONLY ; 
 unsigned int SD_EXIST ; 
 void* SET_CLOCK_PHASE (int,int,int) ; 
 int /*<<< orphan*/  SYS_VER ; 
 int /*<<< orphan*/  WRITE_REG_CMD ; 
 int hweight32 (unsigned int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  pcr_dbg (struct rtsx_pcr*,char*,unsigned int,...) ; 
 int /*<<< orphan*/  rtl8402_pcr_ops ; 
 int /*<<< orphan*/  rtl8411 ; 
 int /*<<< orphan*/  rtl8411_pcr_ops ; 
 int rtl8411_reg_to_sd30_drive_sel_3v3 (int) ; 
 int /*<<< orphan*/  rtl8411b_pcr_ops ; 
 int /*<<< orphan*/  rtl8411b_qfn48 ; 
 int /*<<< orphan*/  rtl8411b_qfn64 ; 
 int rtl8411b_reg_to_sd30_drive_sel_3v3 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rtsx_pci_add_cmd (struct rtsx_pcr*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  rtsx_pci_init_cmd (struct rtsx_pcr*) ; 
 int /*<<< orphan*/  rtsx_pci_read_config_byte (struct rtsx_pcr*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  rtsx_pci_read_config_dword (struct rtsx_pcr*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rtsx_pci_read_register (struct rtsx_pcr*,int /*<<< orphan*/ ,int*) ; 
 unsigned int rtsx_pci_readl (struct rtsx_pcr*,int /*<<< orphan*/ ) ; 
 int rtsx_pci_send_cmd (struct rtsx_pcr*,int) ; 
 int rtsx_pci_write_register (struct rtsx_pcr*,int /*<<< orphan*/ ,int,int) ; 
 void* rtsx_reg_to_aspm (int /*<<< orphan*/ ) ; 
 int rtsx_reg_to_card_drive_sel (int /*<<< orphan*/ ) ; 
 int rtsx_reg_to_sd30_drive_sel_1v8 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rtsx_vendor_setting_valid (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_pull_ctrl_tables (struct rtsx_pcr*,int /*<<< orphan*/ ) ; 
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

__attribute__((used)) static u8 rtl8411_get_ic_version(struct rtsx_pcr *pcr)
{
	u8 val;

	rtsx_pci_read_register(pcr, SYS_VER, &val);
	return val & 0x0F;
}

__attribute__((used)) static int rtl8411b_is_qfn48(struct rtsx_pcr *pcr)
{
	u8 val = 0;

	rtsx_pci_read_register(pcr, RTL8411B_PACKAGE_MODE, &val);

	if (val & 0x2)
		return 1;
	else
		return 0;
}

__attribute__((used)) static void rtl8411_fetch_vendor_settings(struct rtsx_pcr *pcr)
{
	u32 reg1 = 0;
	u8 reg3 = 0;

	rtsx_pci_read_config_dword(pcr, PCR_SETTING_REG1, &reg1);
	pcr_dbg(pcr, "Cfg 0x%x: 0x%x\n", PCR_SETTING_REG1, reg1);

	if (!rtsx_vendor_setting_valid(reg1))
		return;

	pcr->aspm_en = rtsx_reg_to_aspm(reg1);
	pcr->sd30_drive_sel_1v8 =
		map_sd_drive(rtsx_reg_to_sd30_drive_sel_1v8(reg1));
	pcr->card_drive_sel &= 0x3F;
	pcr->card_drive_sel |= rtsx_reg_to_card_drive_sel(reg1);

	rtsx_pci_read_config_byte(pcr, PCR_SETTING_REG3, &reg3);
	pcr_dbg(pcr, "Cfg 0x%x: 0x%x\n", PCR_SETTING_REG3, reg3);
	pcr->sd30_drive_sel_3v3 = rtl8411_reg_to_sd30_drive_sel_3v3(reg3);
}

__attribute__((used)) static void rtl8411b_fetch_vendor_settings(struct rtsx_pcr *pcr)
{
	u32 reg = 0;

	rtsx_pci_read_config_dword(pcr, PCR_SETTING_REG1, &reg);
	pcr_dbg(pcr, "Cfg 0x%x: 0x%x\n", PCR_SETTING_REG1, reg);

	if (!rtsx_vendor_setting_valid(reg))
		return;

	pcr->aspm_en = rtsx_reg_to_aspm(reg);
	pcr->sd30_drive_sel_1v8 =
		map_sd_drive(rtsx_reg_to_sd30_drive_sel_1v8(reg));
	pcr->sd30_drive_sel_3v3 =
		map_sd_drive(rtl8411b_reg_to_sd30_drive_sel_3v3(reg));
}

__attribute__((used)) static void rtl8411_force_power_down(struct rtsx_pcr *pcr, u8 pm_state)
{
	rtsx_pci_write_register(pcr, FPDCTL, 0x07, 0x07);
}

__attribute__((used)) static int rtl8411_extra_init_hw(struct rtsx_pcr *pcr)
{
	rtsx_pci_init_cmd(pcr);

	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, SD30_DRIVE_SEL,
			0xFF, pcr->sd30_drive_sel_3v3);
	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, CD_PAD_CTL,
			CD_DISABLE_MASK | CD_AUTO_DISABLE, CD_ENABLE);

	return rtsx_pci_send_cmd(pcr, 100);
}

__attribute__((used)) static int rtl8411b_extra_init_hw(struct rtsx_pcr *pcr)
{
	rtsx_pci_init_cmd(pcr);

	if (rtl8411b_is_qfn48(pcr))
		rtsx_pci_add_cmd(pcr, WRITE_REG_CMD,
				CARD_PULL_CTL3, 0xFF, 0xF5);
	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, SD30_DRIVE_SEL,
			0xFF, pcr->sd30_drive_sel_3v3);
	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, CD_PAD_CTL,
			CD_DISABLE_MASK | CD_AUTO_DISABLE, CD_ENABLE);
	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, FUNC_FORCE_CTL,
			0x06, 0x00);

	return rtsx_pci_send_cmd(pcr, 100);
}

__attribute__((used)) static int rtl8411_turn_on_led(struct rtsx_pcr *pcr)
{
	return rtsx_pci_write_register(pcr, CARD_GPIO, 0x01, 0x00);
}

__attribute__((used)) static int rtl8411_turn_off_led(struct rtsx_pcr *pcr)
{
	return rtsx_pci_write_register(pcr, CARD_GPIO, 0x01, 0x01);
}

__attribute__((used)) static int rtl8411_enable_auto_blink(struct rtsx_pcr *pcr)
{
	return rtsx_pci_write_register(pcr, CARD_AUTO_BLINK, 0xFF, 0x0D);
}

__attribute__((used)) static int rtl8411_disable_auto_blink(struct rtsx_pcr *pcr)
{
	return rtsx_pci_write_register(pcr, CARD_AUTO_BLINK, 0x08, 0x00);
}

__attribute__((used)) static int rtl8411_card_power_on(struct rtsx_pcr *pcr, int card)
{
	int err;

	rtsx_pci_init_cmd(pcr);
	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, CARD_PWR_CTL,
			BPP_POWER_MASK, BPP_POWER_5_PERCENT_ON);
	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, LDO_CTL,
			BPP_LDO_POWB, BPP_LDO_SUSPEND);
	err = rtsx_pci_send_cmd(pcr, 100);
	if (err < 0)
		return err;

	/* To avoid too large in-rush current */
	udelay(150);

	err = rtsx_pci_write_register(pcr, CARD_PWR_CTL,
			BPP_POWER_MASK, BPP_POWER_10_PERCENT_ON);
	if (err < 0)
		return err;

	udelay(150);

	err = rtsx_pci_write_register(pcr, CARD_PWR_CTL,
			BPP_POWER_MASK, BPP_POWER_15_PERCENT_ON);
	if (err < 0)
		return err;

	udelay(150);

	err = rtsx_pci_write_register(pcr, CARD_PWR_CTL,
			BPP_POWER_MASK, BPP_POWER_ON);
	if (err < 0)
		return err;

	return rtsx_pci_write_register(pcr, LDO_CTL, BPP_LDO_POWB, BPP_LDO_ON);
}

__attribute__((used)) static int rtl8411_card_power_off(struct rtsx_pcr *pcr, int card)
{
	int err;

	err = rtsx_pci_write_register(pcr, CARD_PWR_CTL,
			BPP_POWER_MASK, BPP_POWER_OFF);
	if (err < 0)
		return err;

	return rtsx_pci_write_register(pcr, LDO_CTL,
			BPP_LDO_POWB, BPP_LDO_SUSPEND);
}

__attribute__((used)) static int rtl8411_do_switch_output_voltage(struct rtsx_pcr *pcr, u8 voltage,
		int bpp_tuned18_shift, int bpp_asic_1v8)
{
	u8 mask, val;
	int err;

	mask = (BPP_REG_TUNED18 << bpp_tuned18_shift) | BPP_PAD_MASK;
	if (voltage == OUTPUT_3V3) {
		err = rtsx_pci_write_register(pcr,
				SD30_DRIVE_SEL, 0x07, pcr->sd30_drive_sel_3v3);
		if (err < 0)
			return err;
		val = (BPP_ASIC_3V3 << bpp_tuned18_shift) | BPP_PAD_3V3;
	} else if (voltage == OUTPUT_1V8) {
		err = rtsx_pci_write_register(pcr,
				SD30_DRIVE_SEL, 0x07, pcr->sd30_drive_sel_1v8);
		if (err < 0)
			return err;
		val = (bpp_asic_1v8 << bpp_tuned18_shift) | BPP_PAD_1V8;
	} else {
		return -EINVAL;
	}

	return rtsx_pci_write_register(pcr, LDO_CTL, mask, val);
}

__attribute__((used)) static int rtl8411_switch_output_voltage(struct rtsx_pcr *pcr, u8 voltage)
{
	return rtl8411_do_switch_output_voltage(pcr, voltage,
			BPP_TUNED18_SHIFT_8411, BPP_ASIC_1V8);
}

__attribute__((used)) static int rtl8402_switch_output_voltage(struct rtsx_pcr *pcr, u8 voltage)
{
	return rtl8411_do_switch_output_voltage(pcr, voltage,
			BPP_TUNED18_SHIFT_8402, BPP_ASIC_2V0);
}

__attribute__((used)) static unsigned int rtl8411_cd_deglitch(struct rtsx_pcr *pcr)
{
	unsigned int card_exist;

	card_exist = rtsx_pci_readl(pcr, RTSX_BIPR);
	card_exist &= CARD_EXIST;
	if (!card_exist) {
		/* Enable card CD */
		rtsx_pci_write_register(pcr, CD_PAD_CTL,
				CD_DISABLE_MASK, CD_ENABLE);
		/* Enable card interrupt */
		rtsx_pci_write_register(pcr, EFUSE_CONTENT, 0xe0, 0x00);
		return 0;
	}

	if (hweight32(card_exist) > 1) {
		rtsx_pci_write_register(pcr, CARD_PWR_CTL,
				BPP_POWER_MASK, BPP_POWER_5_PERCENT_ON);
		msleep(100);

		card_exist = rtsx_pci_readl(pcr, RTSX_BIPR);
		if (card_exist & MS_EXIST)
			card_exist = MS_EXIST;
		else if (card_exist & SD_EXIST)
			card_exist = SD_EXIST;
		else
			card_exist = 0;

		rtsx_pci_write_register(pcr, CARD_PWR_CTL,
				BPP_POWER_MASK, BPP_POWER_OFF);

		pcr_dbg(pcr, "After CD deglitch, card_exist = 0x%x\n",
			card_exist);
	}

	if (card_exist & MS_EXIST) {
		/* Disable SD interrupt */
		rtsx_pci_write_register(pcr, EFUSE_CONTENT, 0xe0, 0x40);
		rtsx_pci_write_register(pcr, CD_PAD_CTL,
				CD_DISABLE_MASK, MS_CD_EN_ONLY);
	} else if (card_exist & SD_EXIST) {
		/* Disable MS interrupt */
		rtsx_pci_write_register(pcr, EFUSE_CONTENT, 0xe0, 0x80);
		rtsx_pci_write_register(pcr, CD_PAD_CTL,
				CD_DISABLE_MASK, SD_CD_EN_ONLY);
	}

	return card_exist;
}

__attribute__((used)) static int rtl8411_conv_clk_and_div_n(int input, int dir)
{
	int output;

	if (dir == CLK_TO_DIV_N)
		output = input * 4 / 5 - 2;
	else
		output = (input + 2) * 5 / 4;

	return output;
}

__attribute__((used)) static void rtl8411_init_common_params(struct rtsx_pcr *pcr)
{
	pcr->extra_caps = EXTRA_CAPS_SD_SDR50 | EXTRA_CAPS_SD_SDR104;
	pcr->num_slots = 2;
	pcr->flags = 0;
	pcr->card_drive_sel = RTL8411_CARD_DRIVE_DEFAULT;
	pcr->sd30_drive_sel_1v8 = DRIVER_TYPE_B;
	pcr->sd30_drive_sel_3v3 = DRIVER_TYPE_D;
	pcr->aspm_en = ASPM_L1_EN;
	pcr->tx_initial_phase = SET_CLOCK_PHASE(23, 7, 14);
	pcr->rx_initial_phase = SET_CLOCK_PHASE(4, 3, 10);
	pcr->ic_version = rtl8411_get_ic_version(pcr);
}

void rtl8411_init_params(struct rtsx_pcr *pcr)
{
	rtl8411_init_common_params(pcr);
	pcr->ops = &rtl8411_pcr_ops;
	set_pull_ctrl_tables(pcr, rtl8411);
}

void rtl8411b_init_params(struct rtsx_pcr *pcr)
{
	rtl8411_init_common_params(pcr);
	pcr->ops = &rtl8411b_pcr_ops;
	if (rtl8411b_is_qfn48(pcr))
		set_pull_ctrl_tables(pcr, rtl8411b_qfn48);
	else
		set_pull_ctrl_tables(pcr, rtl8411b_qfn64);
}

void rtl8402_init_params(struct rtsx_pcr *pcr)
{
	rtl8411_init_common_params(pcr);
	pcr->ops = &rtl8402_pcr_ops;
	set_pull_ctrl_tables(pcr, rtl8411);
}

