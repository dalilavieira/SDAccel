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
typedef  int u32 ;
typedef  int u16 ;
struct rtsx_hw_param {int ocp_glitch; int /*<<< orphan*/  interrupt_en; } ;
struct rtsx_cr_option {int ocp_en; int sd_400mA_ocp_thd; int ltr_en; int ltr_enabled; int ltr_active; int force_clkreq_0; scalar_t__ dev_aspm_mode; int ltr_l1off_snooze_sspwrgate; int ltr_l1off_sspwrgate; int dev_flags; int /*<<< orphan*/  sd_800mA_ocp_thd; int /*<<< orphan*/  l1_snooze_delay; int /*<<< orphan*/  ltr_l1off_latency; int /*<<< orphan*/  ltr_idle_latency; int /*<<< orphan*/  ltr_active_latency; } ;
struct rtsx_pcr {int sd30_drive_sel_3v3; int sd30_drive_sel_1v8; int aspm_en; int card_drive_sel; int flags; int reg_pm_ctrl3; int extra_caps; int ocp_stat; int ocp_stat2; int card_exist; int aspm_enabled; int num_slots; int ic_version; int /*<<< orphan*/ * ops; int /*<<< orphan*/  ms_pull_ctl_disable_tbl; int /*<<< orphan*/  ms_pull_ctl_enable_tbl; int /*<<< orphan*/  sd_pull_ctl_disable_tbl; int /*<<< orphan*/  sd_pull_ctl_enable_tbl; void* rx_initial_phase; void* tx_initial_phase; struct rtsx_hw_param hw_param; struct rtsx_cr_option option; scalar_t__ pcie_cap; int /*<<< orphan*/  pci; } ;

/* Variables and functions */
 int ALL_POWER_DOWN ; 
 int ASPM_FORCE_CTL ; 
 int ASPM_L1_1_EN ; 
 int ASPM_L1_1_EN_MASK ; 
 int ASPM_L1_2_EN ; 
 int ASPM_L1_2_EN_MASK ; 
 int ASPM_L1_EN ; 
 int /*<<< orphan*/  ASPM_MASK_NEG ; 
 int AUTOLOAD_CFG_BASE ; 
 int AUX_CLK_ACTIVE_SEL_MASK ; 
 int CARD_CLK_SOURCE ; 
 int CARD_OE ; 
 int CARD_STOP ; 
 void* CFG_DRIVER_TYPE_B ; 
 int CFG_L1_0_CRC_MISC_RET_VALUE ; 
 int CFG_L1_0_CRC_MISC_RET_VALUE_DEFAULT ; 
 int CFG_L1_0_CRC_SD30_RET_VALUE ; 
 int CFG_L1_0_CRC_SD40_RET_VALUE ; 
 int CFG_L1_0_PCIE_DPHY_RET_VALUE ; 
 int CFG_L1_0_PCIE_MAC_RET_VALUE ; 
 int CFG_L1_0_RET_VALUE_DEFAULT ; 
 int CFG_L1_0_SYS_RET_VALUE ; 
 int CFG_LP_FPWM_VALUE ; 
 int CFG_LP_FPWM_VALUE_DEFAULT ; 
 int CFG_PCIE_APHY_OFF_0 ; 
 int CFG_PCIE_APHY_OFF_0_DEFAULT ; 
 int CFG_PCIE_APHY_OFF_1 ; 
 int CFG_PCIE_APHY_OFF_1_DEFAULT ; 
 int CFG_PCIE_APHY_OFF_2 ; 
 int CFG_PCIE_APHY_OFF_2_DEFAULT ; 
 int CFG_PCIE_APHY_OFF_3 ; 
 int CFG_PCIE_APHY_OFF_3_DEFAULT ; 
 int CLK_CTL ; 
 int CLK_LOW_FREQ ; 
 int CLK_PM_EN ; 
 int /*<<< orphan*/  CMD_TIMEOUT_DEF ; 
 int CRC_VAR_CLK0 ; 
 int D3_DELINK_MODE_EN ; 
 scalar_t__ DEV_ASPM_BACKDOOR ; 
 scalar_t__ DEV_ASPM_DYNAMIC ; 
 int /*<<< orphan*/  DUMMY_REG_RESET_0 ; 
 int DV331812_17 ; 
 int DV331812_33 ; 
 int DV331812_MASK ; 
 int DV331812_POWEROFF ; 
 int DV331812_POWERON ; 
 int DV331812_VDD1 ; 
 int DV3318_DETECT_EN ; 
 int DV3318_OCP_CLR ; 
 int DV3318_OCP_EVER ; 
 int DV3318_OCP_INT_CLR ; 
 int DV3318_OCP_INT_EN ; 
 int DV3318_OCP_NOW ; 
 int EINVAL ; 
 int EN_INFINITE_MODE ; 
 int EXTRA_CAPS_SD_SDR104 ; 
 int EXTRA_CAPS_SD_SDR50 ; 
 int FORCE_ASPM_CTL0 ; 
 int FORCE_ASPM_VAL_MASK ; 
 int FORCE_CLKREQ_DELINK_MASK ; 
 int FORCE_CLKREQ_HIGH ; 
 int FORCE_CLKREQ_LOW ; 
 int FPDCTL ; 
 int HOST_ENTER_S3 ; 
 int IC_VERSION_MASK ; 
 int L1OFF_MBIAS2_EN_5250 ; 
 int L1SUB_CONFIG1 ; 
 int L1SUB_CONFIG3 ; 
 int /*<<< orphan*/  L1_SNOOZE_DELAY_DEF ; 
 int LDO_CONFIG2 ; 
 int LDO_DV18_CFG ; 
 int LDO_POW_SDVDD1_MASK ; 
 int LDO_POW_SDVDD1_OFF ; 
 int LDO_POW_SDVDD1_ON ; 
 int LDO_VCC_CFG0 ; 
 int LDO_VCC_CFG1 ; 
 int LED_SHINE_DISABLE ; 
 int LED_SHINE_EN ; 
 int LED_SHINE_MASK ; 
 int /*<<< orphan*/  LTR_ACTIVE_LATENCY_DEF ; 
 int /*<<< orphan*/  LTR_IDLE_LATENCY_DEF ; 
 int /*<<< orphan*/  LTR_L1OFF_LATENCY_DEF ; 
 int LTR_L1OFF_SNOOZE_SSPWRGATE_5250_DEF ; 
 int LTR_L1OFF_SSPWRGATE_5250_DEF ; 
 int LTR_L1SS_PWR_GATE_CHECK_CARD_EN ; 
 int LTR_L1SS_PWR_GATE_EN ; 
 int MAC_CKSW_DONE ; 
 int MASK_8_BIT_DEF ; 
 int MS_EXIST ; 
 int MS_OUTPUT_EN ; 
 int OBFF_CFG ; 
 int OBFF_DISABLE ; 
 int OBFF_EN_MASK ; 
 int OC_POWER_DOWN ; 
 int OLT_LED_CTL ; 
#define  OUTPUT_1V8 129 
#define  OUTPUT_3V3 128 
 int PCIE_L1_0_EN ; 
 int PCIE_L1_0_PD_FE_EN ; 
 int PCIE_L1_1_EN ; 
 int PCIE_L1_1_PD_FE_EN ; 
 int PCIE_L1_2_EN ; 
 int PCIE_L1_2_PD_FE_EN ; 
 int /*<<< orphan*/  PCI_EXP_DEVCTL2 ; 
 int PCI_EXP_DEVCTL2_LTR_EN ; 
 scalar_t__ PCI_EXP_LNKCTL ; 
 int PCLK_CTL ; 
 int PCLK_MODE_SEL ; 
 int /*<<< orphan*/  PCR_ASPM_SETTING_5260 ; 
 int PCR_REVERSE_SOCKET ; 
 int /*<<< orphan*/  PCR_SETTING_REG1 ; 
 int /*<<< orphan*/  PCR_SETTING_REG2 ; 
 int PETXCFG ; 
 int PM_CLK_FORCE_CTL ; 
 int PM_L1_1_EN ; 
 int PM_L1_1_EN_MASK ; 
 int PM_L1_2_EN ; 
 int PM_L1_2_EN_MASK ; 
 int PWC_CDR ; 
 int PWC_CDR_DEFAULT ; 
 int PWD_SUSPEND_EN ; 
 int PWD_SUSPND_EN ; 
 int PWR_FE_CTL ; 
 int PWR_GATE_CTRL ; 
 int PWR_GATE_EN ; 
 int PWR_GLOBAL_CTRL ; 
 int RBCTL ; 
 int RB_FLUSH ; 
 int REG_DV3318_OCPCTL ; 
 int /*<<< orphan*/  REG_DV3318_OCPSTAT ; 
 int REG_OCPCTL ; 
 int REG_OCPGLITCH ; 
 int /*<<< orphan*/  REG_OCPSTAT ; 
 int REG_PRE_RW_MODE ; 
 int REG_SD_STOP_SDCLK_CFG ; 
 int REG_VREF ; 
 int RELINK_TIME_MASK ; 
 int RTS524A_PM_CTRL3 ; 
 int RTS5260_ADMA3_RST ; 
 int RTS5260_AUTOLOAD_CFG4 ; 
 int RTS5260_DMA_RST ; 
 int RTS5260_DMA_RST_CTL_0 ; 
 int RTS5260_DV331812_CFG ; 
 int RTS5260_DV331812_OCP_THD_210 ; 
 int RTS5260_DV331812_OCP_THD_MASK ; 
 int RTS5260_DVCC_33 ; 
 int RTS5260_DVCC_CTRL ; 
 int RTS5260_DVCC_OCP_CL_EN ; 
 int RTS5260_DVCC_OCP_EN ; 
 int RTS5260_DVCC_OCP_THD_550 ; 
 int /*<<< orphan*/  RTS5260_DVCC_OCP_THD_970 ; 
 int RTS5260_DVCC_OCP_THD_MASK ; 
 int RTS5260_DVCC_TUNE_MASK ; 
 int RTS5260_DVIO_CTRL ; 
 int RTS5260_DVIO_OCP_CL_EN ; 
 int RTS5260_DVIO_OCP_EN ; 
 int RTS5260_DVIO_OCP_THD_350 ; 
 int RTS5260_DVIO_OCP_THD_MASK ; 
 int RTS5260_MIMO_DISABLE ; 
 int RTS5260_REG_GPIO_CTL0 ; 
 int RTS5260_REG_GPIO_MASK ; 
 int RTS5260_REG_GPIO_OFF ; 
 int RTS5260_REG_GPIO_ON ; 
 int /*<<< orphan*/  RTSX_BIPR ; 
 int RTSX_CARD_DRIVE_DEFAULT ; 
 int /*<<< orphan*/  RTSX_HCBCTLR ; 
 int /*<<< orphan*/  RTSX_HDBCTLR ; 
 int SAMPLE_VAR_CLK1 ; 
 int SD20_RX_POS_EDGE ; 
 int SD30_CLK_DRIVE_SEL ; 
 int SD30_CLK_END_EN ; 
 int SD30_CLK_STOP_CFG0 ; 
 int SD30_CLK_STOP_CFG1 ; 
 int SD30_CLK_STOP_CFG_EN ; 
 int SD30_CMD_DRIVE_SEL ; 
 int SD30_DAT_DRIVE_SEL ; 
 int SD30_FIX_CLK ; 
 int SDVIO_DETECT_EN ; 
 int SDVIO_OCP_GLITCH_800U ; 
 int SDVIO_OCP_GLITCH_MASK ; 
 int SDVIO_OCP_INT_CLR ; 
 int SDVIO_OCP_INT_EN ; 
 int SDVIO_OC_CLR ; 
 int SDVIO_OC_EVER ; 
 int SDVIO_OC_NOW ; 
 int SD_20_MODE ; 
 int SD_30_MODE ; 
 int SD_ASYNC_FIFO_NOT_RST ; 
 int SD_CFG1 ; 
 int SD_CFG3 ; 
 int SD_CLK_DIVIDE_128 ; 
 int SD_CLR_ERR ; 
 int SD_DETECT_EN ; 
 int SD_EXIST ; 
 int SD_IO_USING_1V8 ; 
 int SD_MODE_SELECT_MASK ; 
 int SD_OCP_GLITCH_10M ; 
 int SD_OCP_GLITCH_MASK ; 
 int SD_OCP_INT_CLR ; 
 int SD_OCP_INT_EN ; 
 int SD_OC_CLR ; 
 int SD_OC_EVER ; 
 int /*<<< orphan*/  SD_OC_INT_EN ; 
 int SD_OC_NOW ; 
 int SD_OUTPUT_EN ; 
 int SD_PAD_CTL ; 
 int SD_PUSH_POINT_CTL ; 
 int SD_SAMPLE_POINT_CTL ; 
 int SD_STOP ; 
 void* SET_CLOCK_PHASE (int,int,int) ; 
 int SSC_DIV_N_0 ; 
 int /*<<< orphan*/  STOP_CMD ; 
 int /*<<< orphan*/  STOP_DMA ; 
 int U_AUTO_DMA_DISABLE ; 
 int U_AUTO_DMA_EN_MASK ; 
 int /*<<< orphan*/  WRITE_REG_CMD ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  pcie_capability_read_word (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  pcr_dbg (struct rtsx_pcr*,char*,...) ; 
 int /*<<< orphan*/  rts5260_ms_pull_ctl_disable_tbl ; 
 int /*<<< orphan*/  rts5260_ms_pull_ctl_enable_tbl ; 
 int /*<<< orphan*/  rts5260_pcr_ops ; 
 int /*<<< orphan*/  rts5260_sd_pull_ctl_disable_tbl ; 
 int /*<<< orphan*/  rts5260_sd_pull_ctl_enable_tbl ; 
 int rtsx_check_dev_flag (struct rtsx_pcr*,int) ; 
 int /*<<< orphan*/  rtsx_ms_power_off_card3v3 (struct rtsx_pcr*) ; 
 int /*<<< orphan*/  rtsx_pci_add_cmd (struct rtsx_pcr*,int /*<<< orphan*/ ,int,int,int) ; 
 int /*<<< orphan*/  rtsx_pci_clear_ocpstat (struct rtsx_pcr*) ; 
 int /*<<< orphan*/  rtsx_pci_disable_ocp (struct rtsx_pcr*) ; 
 int /*<<< orphan*/  rtsx_pci_enable_ocp (struct rtsx_pcr*) ; 
 int /*<<< orphan*/  rtsx_pci_get_ocpstat (struct rtsx_pcr*,int*) ; 
 int /*<<< orphan*/  rtsx_pci_init_cmd (struct rtsx_pcr*) ; 
 int /*<<< orphan*/  rtsx_pci_init_ocp (struct rtsx_pcr*) ; 
 int /*<<< orphan*/  rtsx_pci_read_config_dword (struct rtsx_pcr*,int /*<<< orphan*/ ,int*) ; 
 int rtsx_pci_read_register (struct rtsx_pcr*,int /*<<< orphan*/ ,int*) ; 
 int rtsx_pci_readl (struct rtsx_pcr*,int /*<<< orphan*/ ) ; 
 int rtsx_pci_send_cmd (struct rtsx_pcr*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rtsx_pci_update_cfg_byte (struct rtsx_pcr*,scalar_t__,int /*<<< orphan*/ ,int) ; 
 int rtsx_pci_write_register (struct rtsx_pcr*,int,int,int) ; 
 int /*<<< orphan*/  rtsx_pci_writel (struct rtsx_pcr*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ rtsx_reg_check_reverse_socket (int) ; 
 int rtsx_reg_to_aspm (int) ; 
 int rtsx_reg_to_card_drive_sel (int) ; 
 int rtsx_reg_to_sd30_drive_sel_1v8 (int) ; 
 int rtsx_reg_to_sd30_drive_sel_3v3 (int) ; 
 int /*<<< orphan*/  rtsx_sd_power_off_card3v3 (struct rtsx_pcr*) ; 
 int /*<<< orphan*/  rtsx_set_dev_flag (struct rtsx_pcr*,int) ; 
 int /*<<< orphan*/  rtsx_set_l1off_sub (struct rtsx_pcr*,int) ; 
 int /*<<< orphan*/  rtsx_set_ltr_latency (struct rtsx_pcr*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rtsx_vendor_setting_valid (int) ; 
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

__attribute__((used)) static u8 rts5260_get_ic_version(struct rtsx_pcr *pcr)
{
	u8 val;

	rtsx_pci_read_register(pcr, DUMMY_REG_RESET_0, &val);
	return val & IC_VERSION_MASK;
}

__attribute__((used)) static void rts5260_fill_driving(struct rtsx_pcr *pcr, u8 voltage)
{
	u8 driving_3v3[6][3] = {
		{0x94, 0x94, 0x94},
		{0x11, 0x11, 0x18},
		{0x55, 0x55, 0x5C},
		{0x94, 0x94, 0x94},
		{0x94, 0x94, 0x94},
		{0xFF, 0xFF, 0xFF},
	};
	u8 driving_1v8[6][3] = {
		{0x9A, 0x89, 0x89},
		{0xC4, 0xC4, 0xC4},
		{0x3C, 0x3C, 0x3C},
		{0x9B, 0x99, 0x99},
		{0x9A, 0x89, 0x89},
		{0xFE, 0xFE, 0xFE},
	};
	u8 (*driving)[3], drive_sel;

	if (voltage == OUTPUT_3V3) {
		driving = driving_3v3;
		drive_sel = pcr->sd30_drive_sel_3v3;
	} else {
		driving = driving_1v8;
		drive_sel = pcr->sd30_drive_sel_1v8;
	}

	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, SD30_CLK_DRIVE_SEL,
			 0xFF, driving[drive_sel][0]);
	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, SD30_CMD_DRIVE_SEL,
			 0xFF, driving[drive_sel][1]);
	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, SD30_DAT_DRIVE_SEL,
			 0xFF, driving[drive_sel][2]);
}

__attribute__((used)) static void rtsx_base_fetch_vendor_settings(struct rtsx_pcr *pcr)
{
	u32 reg;

	rtsx_pci_read_config_dword(pcr, PCR_SETTING_REG1, &reg);
	pcr_dbg(pcr, "Cfg 0x%x: 0x%x\n", PCR_SETTING_REG1, reg);

	if (!rtsx_vendor_setting_valid(reg)) {
		pcr_dbg(pcr, "skip fetch vendor setting\n");
		return;
	}

	pcr->aspm_en = rtsx_reg_to_aspm(reg);
	pcr->sd30_drive_sel_1v8 = rtsx_reg_to_sd30_drive_sel_1v8(reg);
	pcr->card_drive_sel &= 0x3F;
	pcr->card_drive_sel |= rtsx_reg_to_card_drive_sel(reg);

	rtsx_pci_read_config_dword(pcr, PCR_SETTING_REG2, &reg);
	pcr_dbg(pcr, "Cfg 0x%x: 0x%x\n", PCR_SETTING_REG2, reg);
	pcr->sd30_drive_sel_3v3 = rtsx_reg_to_sd30_drive_sel_3v3(reg);
	if (rtsx_reg_check_reverse_socket(reg))
		pcr->flags |= PCR_REVERSE_SOCKET;
}

__attribute__((used)) static void rtsx_base_force_power_down(struct rtsx_pcr *pcr, u8 pm_state)
{
	/* Set relink_time to 0 */
	rtsx_pci_write_register(pcr, AUTOLOAD_CFG_BASE + 1, MASK_8_BIT_DEF, 0);
	rtsx_pci_write_register(pcr, AUTOLOAD_CFG_BASE + 2, MASK_8_BIT_DEF, 0);
	rtsx_pci_write_register(pcr, AUTOLOAD_CFG_BASE + 3,
				RELINK_TIME_MASK, 0);

	if (pm_state == HOST_ENTER_S3)
		rtsx_pci_write_register(pcr, pcr->reg_pm_ctrl3,
					D3_DELINK_MODE_EN, D3_DELINK_MODE_EN);

	rtsx_pci_write_register(pcr, FPDCTL, ALL_POWER_DOWN, ALL_POWER_DOWN);
}

__attribute__((used)) static int rtsx_base_enable_auto_blink(struct rtsx_pcr *pcr)
{
	return rtsx_pci_write_register(pcr, OLT_LED_CTL,
		LED_SHINE_MASK, LED_SHINE_EN);
}

__attribute__((used)) static int rtsx_base_disable_auto_blink(struct rtsx_pcr *pcr)
{
	return rtsx_pci_write_register(pcr, OLT_LED_CTL,
		LED_SHINE_MASK, LED_SHINE_DISABLE);
}

__attribute__((used)) static int rts5260_turn_on_led(struct rtsx_pcr *pcr)
{
	return rtsx_pci_write_register(pcr, RTS5260_REG_GPIO_CTL0,
		RTS5260_REG_GPIO_MASK, RTS5260_REG_GPIO_ON);
}

__attribute__((used)) static int rts5260_turn_off_led(struct rtsx_pcr *pcr)
{
	return rtsx_pci_write_register(pcr, RTS5260_REG_GPIO_CTL0,
		RTS5260_REG_GPIO_MASK, RTS5260_REG_GPIO_OFF);
}

__attribute__((used)) static int sd_set_sample_push_timing_sd30(struct rtsx_pcr *pcr)
{
	rtsx_pci_write_register(pcr, SD_CFG1, SD_MODE_SELECT_MASK
		| SD_ASYNC_FIFO_NOT_RST, SD_30_MODE | SD_ASYNC_FIFO_NOT_RST);
	rtsx_pci_write_register(pcr, CLK_CTL, CLK_LOW_FREQ, CLK_LOW_FREQ);
	rtsx_pci_write_register(pcr, CARD_CLK_SOURCE, 0xFF,
				CRC_VAR_CLK0 | SD30_FIX_CLK | SAMPLE_VAR_CLK1);
	rtsx_pci_write_register(pcr, CLK_CTL, CLK_LOW_FREQ, 0);

	return 0;
}

__attribute__((used)) static int rts5260_card_power_on(struct rtsx_pcr *pcr, int card)
{
	int err = 0;
	struct rtsx_cr_option *option = &pcr->option;

	if (option->ocp_en)
		rtsx_pci_enable_ocp(pcr);

	rtsx_pci_init_cmd(pcr);
	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, LDO_CONFIG2,
			 DV331812_VDD1, DV331812_VDD1);
	err = rtsx_pci_send_cmd(pcr, CMD_TIMEOUT_DEF);
	if (err < 0)
		return err;

	rtsx_pci_init_cmd(pcr);
	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, LDO_VCC_CFG0,
			 RTS5260_DVCC_TUNE_MASK, RTS5260_DVCC_33);
	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, LDO_VCC_CFG1,
			 LDO_POW_SDVDD1_MASK, LDO_POW_SDVDD1_ON);
	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, LDO_CONFIG2,
			 DV331812_POWERON, DV331812_POWERON);
	err = rtsx_pci_send_cmd(pcr, CMD_TIMEOUT_DEF);

	msleep(20);

	if (pcr->extra_caps & EXTRA_CAPS_SD_SDR50 ||
	    pcr->extra_caps & EXTRA_CAPS_SD_SDR104)
		sd_set_sample_push_timing_sd30(pcr);

	/* Initialize SD_CFG1 register */
	rtsx_pci_write_register(pcr, SD_CFG1, 0xFF,
				SD_CLK_DIVIDE_128 | SD_20_MODE);

	rtsx_pci_write_register(pcr, SD_SAMPLE_POINT_CTL,
				0xFF, SD20_RX_POS_EDGE);
	rtsx_pci_write_register(pcr, SD_PUSH_POINT_CTL, 0xFF, 0);
	rtsx_pci_write_register(pcr, CARD_STOP, SD_STOP | SD_CLR_ERR,
				SD_STOP | SD_CLR_ERR);

	/* Reset SD_CFG3 register */
	rtsx_pci_write_register(pcr, SD_CFG3, SD30_CLK_END_EN, 0);
	rtsx_pci_write_register(pcr, REG_SD_STOP_SDCLK_CFG,
				SD30_CLK_STOP_CFG_EN | SD30_CLK_STOP_CFG1 |
				SD30_CLK_STOP_CFG0, 0);

	rtsx_pci_write_register(pcr, REG_PRE_RW_MODE, EN_INFINITE_MODE, 0);

	return err;
}

__attribute__((used)) static int rts5260_switch_output_voltage(struct rtsx_pcr *pcr, u8 voltage)
{
	switch (voltage) {
	case OUTPUT_3V3:
		rtsx_pci_write_register(pcr, LDO_CONFIG2,
					DV331812_VDD1, DV331812_VDD1);
		rtsx_pci_write_register(pcr, LDO_DV18_CFG,
					DV331812_MASK, DV331812_33);
		rtsx_pci_write_register(pcr, SD_PAD_CTL, SD_IO_USING_1V8, 0);
		break;
	case OUTPUT_1V8:
		rtsx_pci_write_register(pcr, LDO_CONFIG2,
					DV331812_VDD1, DV331812_VDD1);
		rtsx_pci_write_register(pcr, LDO_DV18_CFG,
					DV331812_MASK, DV331812_17);
		rtsx_pci_write_register(pcr, SD_PAD_CTL, SD_IO_USING_1V8,
					SD_IO_USING_1V8);
		break;
	default:
		return -EINVAL;
	}

	/* set pad drive */
	rtsx_pci_init_cmd(pcr);
	rts5260_fill_driving(pcr, voltage);
	return rtsx_pci_send_cmd(pcr, CMD_TIMEOUT_DEF);
}

__attribute__((used)) static void rts5260_stop_cmd(struct rtsx_pcr *pcr)
{
	rtsx_pci_writel(pcr, RTSX_HCBCTLR, STOP_CMD);
	rtsx_pci_writel(pcr, RTSX_HDBCTLR, STOP_DMA);
	rtsx_pci_write_register(pcr, RTS5260_DMA_RST_CTL_0,
				RTS5260_DMA_RST | RTS5260_ADMA3_RST,
				RTS5260_DMA_RST | RTS5260_ADMA3_RST);
	rtsx_pci_write_register(pcr, RBCTL, RB_FLUSH, RB_FLUSH);
}

__attribute__((used)) static void rts5260_card_before_power_off(struct rtsx_pcr *pcr)
{
	struct rtsx_cr_option *option = &pcr->option;

	rts5260_stop_cmd(pcr);
	rts5260_switch_output_voltage(pcr, OUTPUT_3V3);

	if (option->ocp_en)
		rtsx_pci_disable_ocp(pcr);
}

__attribute__((used)) static int rts5260_card_power_off(struct rtsx_pcr *pcr, int card)
{
	int err = 0;

	rts5260_card_before_power_off(pcr);

	rtsx_pci_init_cmd(pcr);
	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, LDO_VCC_CFG1,
			 LDO_POW_SDVDD1_MASK, LDO_POW_SDVDD1_OFF);
	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, LDO_CONFIG2,
			 DV331812_POWERON, DV331812_POWEROFF);
	err = rtsx_pci_send_cmd(pcr, CMD_TIMEOUT_DEF);

	return err;
}

__attribute__((used)) static void rts5260_init_ocp(struct rtsx_pcr *pcr)
{
	struct rtsx_cr_option *option = &pcr->option;

	if (option->ocp_en) {
		u8 mask, val;

		rtsx_pci_write_register(pcr, RTS5260_DVCC_CTRL,
					RTS5260_DVCC_OCP_EN |
					RTS5260_DVCC_OCP_CL_EN,
					RTS5260_DVCC_OCP_EN |
					RTS5260_DVCC_OCP_CL_EN);
		rtsx_pci_write_register(pcr, RTS5260_DVIO_CTRL,
					RTS5260_DVIO_OCP_EN |
					RTS5260_DVIO_OCP_CL_EN,
					RTS5260_DVIO_OCP_EN |
					RTS5260_DVIO_OCP_CL_EN);

		rtsx_pci_write_register(pcr, RTS5260_DVCC_CTRL,
					RTS5260_DVCC_OCP_THD_MASK,
					option->sd_400mA_ocp_thd);

		rtsx_pci_write_register(pcr, RTS5260_DVIO_CTRL,
					RTS5260_DVIO_OCP_THD_MASK,
					RTS5260_DVIO_OCP_THD_350);

		rtsx_pci_write_register(pcr, RTS5260_DV331812_CFG,
					RTS5260_DV331812_OCP_THD_MASK,
					RTS5260_DV331812_OCP_THD_210);

		mask = SD_OCP_GLITCH_MASK | SDVIO_OCP_GLITCH_MASK;
		val = pcr->hw_param.ocp_glitch;
		rtsx_pci_write_register(pcr, REG_OCPGLITCH, mask, val);

		rtsx_pci_enable_ocp(pcr);
	} else {
		rtsx_pci_write_register(pcr, RTS5260_DVCC_CTRL,
					RTS5260_DVCC_OCP_EN |
					RTS5260_DVCC_OCP_CL_EN, 0);
		rtsx_pci_write_register(pcr, RTS5260_DVIO_CTRL,
					RTS5260_DVIO_OCP_EN |
					RTS5260_DVIO_OCP_CL_EN, 0);
	}
}

__attribute__((used)) static void rts5260_enable_ocp(struct rtsx_pcr *pcr)
{
	u8 val = 0;

	rtsx_pci_write_register(pcr, FPDCTL, OC_POWER_DOWN, 0);

	val = SD_OCP_INT_EN | SD_DETECT_EN;
	val |= SDVIO_OCP_INT_EN | SDVIO_DETECT_EN;
	rtsx_pci_write_register(pcr, REG_OCPCTL, 0xFF, val);
	rtsx_pci_write_register(pcr, REG_DV3318_OCPCTL,
				DV3318_DETECT_EN | DV3318_OCP_INT_EN,
				DV3318_DETECT_EN | DV3318_OCP_INT_EN);
}

__attribute__((used)) static void rts5260_disable_ocp(struct rtsx_pcr *pcr)
{
	u8 mask = 0;

	mask = SD_OCP_INT_EN | SD_DETECT_EN;
	mask |= SDVIO_OCP_INT_EN | SDVIO_DETECT_EN;
	rtsx_pci_write_register(pcr, REG_OCPCTL, mask, 0);
	rtsx_pci_write_register(pcr, REG_DV3318_OCPCTL,
				DV3318_DETECT_EN | DV3318_OCP_INT_EN, 0);

	rtsx_pci_write_register(pcr, FPDCTL, OC_POWER_DOWN,
				OC_POWER_DOWN);
}

__attribute__((used)) static int rts5260_get_ocpstat(struct rtsx_pcr *pcr, u8 *val)
{
	return rtsx_pci_read_register(pcr, REG_OCPSTAT, val);
}

__attribute__((used)) static int rts5260_get_ocpstat2(struct rtsx_pcr *pcr, u8 *val)
{
	return rtsx_pci_read_register(pcr, REG_DV3318_OCPSTAT, val);
}

__attribute__((used)) static void rts5260_clear_ocpstat(struct rtsx_pcr *pcr)
{
	u8 mask = 0;
	u8 val = 0;

	mask = SD_OCP_INT_CLR | SD_OC_CLR;
	mask |= SDVIO_OCP_INT_CLR | SDVIO_OC_CLR;
	val = SD_OCP_INT_CLR | SD_OC_CLR;
	val |= SDVIO_OCP_INT_CLR | SDVIO_OC_CLR;

	rtsx_pci_write_register(pcr, REG_OCPCTL, mask, val);
	rtsx_pci_write_register(pcr, REG_DV3318_OCPCTL,
				DV3318_OCP_INT_CLR | DV3318_OCP_CLR,
				DV3318_OCP_INT_CLR | DV3318_OCP_CLR);
	udelay(10);
	rtsx_pci_write_register(pcr, REG_OCPCTL, mask, 0);
	rtsx_pci_write_register(pcr, REG_DV3318_OCPCTL,
				DV3318_OCP_INT_CLR | DV3318_OCP_CLR, 0);
}

__attribute__((used)) static void rts5260_process_ocp(struct rtsx_pcr *pcr)
{
	if (!pcr->option.ocp_en)
		return;

	rtsx_pci_get_ocpstat(pcr, &pcr->ocp_stat);
	rts5260_get_ocpstat2(pcr, &pcr->ocp_stat2);
	if (pcr->card_exist & SD_EXIST)
		rtsx_sd_power_off_card3v3(pcr);
	else if (pcr->card_exist & MS_EXIST)
		rtsx_ms_power_off_card3v3(pcr);

	if (!(pcr->card_exist & MS_EXIST) && !(pcr->card_exist & SD_EXIST)) {
		if ((pcr->ocp_stat & (SD_OC_NOW | SD_OC_EVER |
			SDVIO_OC_NOW | SDVIO_OC_EVER)) ||
			(pcr->ocp_stat2 & (DV3318_OCP_NOW | DV3318_OCP_EVER)))
			rtsx_pci_clear_ocpstat(pcr);
		pcr->ocp_stat = 0;
		pcr->ocp_stat2 = 0;
	}

	if ((pcr->ocp_stat & (SD_OC_NOW | SD_OC_EVER |
			SDVIO_OC_NOW | SDVIO_OC_EVER)) ||
			(pcr->ocp_stat2 & (DV3318_OCP_NOW | DV3318_OCP_EVER))) {
		if (pcr->card_exist & SD_EXIST)
			rtsx_pci_write_register(pcr, CARD_OE, SD_OUTPUT_EN, 0);
		else if (pcr->card_exist & MS_EXIST)
			rtsx_pci_write_register(pcr, CARD_OE, MS_OUTPUT_EN, 0);
	}
}

__attribute__((used)) static int rts5260_init_hw(struct rtsx_pcr *pcr)
{
	int err;

	rtsx_pci_init_ocp(pcr);

	rtsx_pci_init_cmd(pcr);

	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, L1SUB_CONFIG1,
			 AUX_CLK_ACTIVE_SEL_MASK, MAC_CKSW_DONE);
	/* Rest L1SUB Config */
	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, L1SUB_CONFIG3, 0xFF, 0x00);
	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, PM_CLK_FORCE_CTL,
			 CLK_PM_EN, CLK_PM_EN);
	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, PWD_SUSPEND_EN, 0xFF, 0xFF);
	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, PWR_GATE_CTRL,
			 PWR_GATE_EN, PWR_GATE_EN);
	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, REG_VREF,
			 PWD_SUSPND_EN, PWD_SUSPND_EN);
	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, RBCTL,
			 U_AUTO_DMA_EN_MASK, U_AUTO_DMA_DISABLE);

	if (pcr->flags & PCR_REVERSE_SOCKET)
		rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, PETXCFG, 0xB0, 0xB0);
	else
		rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, PETXCFG, 0xB0, 0x80);

	rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, OBFF_CFG,
			 OBFF_EN_MASK, OBFF_DISABLE);

	err = rtsx_pci_send_cmd(pcr, CMD_TIMEOUT_DEF);
	if (err < 0)
		return err;

	return 0;
}

__attribute__((used)) static void rts5260_pwr_saving_setting(struct rtsx_pcr *pcr)
{
	int lss_l1_1, lss_l1_2;

	lss_l1_1 = rtsx_check_dev_flag(pcr, ASPM_L1_1_EN)
			| rtsx_check_dev_flag(pcr, PM_L1_1_EN);
	lss_l1_2 = rtsx_check_dev_flag(pcr, ASPM_L1_2_EN)
			| rtsx_check_dev_flag(pcr, PM_L1_2_EN);

	if (lss_l1_2) {
		pcr_dbg(pcr, "Set parameters for L1.2.");
		rtsx_pci_write_register(pcr, PWR_GLOBAL_CTRL,
					0xFF, PCIE_L1_2_EN);
		rtsx_pci_write_register(pcr, PWR_FE_CTL,
					0xFF, PCIE_L1_2_PD_FE_EN);
	} else if (lss_l1_1) {
		pcr_dbg(pcr, "Set parameters for L1.1.");
		rtsx_pci_write_register(pcr, PWR_GLOBAL_CTRL,
					0xFF, PCIE_L1_1_EN);
		rtsx_pci_write_register(pcr, PWR_FE_CTL,
					0xFF, PCIE_L1_1_PD_FE_EN);
	} else {
		pcr_dbg(pcr, "Set parameters for L1.");
		rtsx_pci_write_register(pcr, PWR_GLOBAL_CTRL,
					0xFF, PCIE_L1_0_EN);
		rtsx_pci_write_register(pcr, PWR_FE_CTL,
					0xFF, PCIE_L1_0_PD_FE_EN);
	}

	rtsx_pci_write_register(pcr, CFG_L1_0_PCIE_DPHY_RET_VALUE,
				0xFF, CFG_L1_0_RET_VALUE_DEFAULT);
	rtsx_pci_write_register(pcr, CFG_L1_0_PCIE_MAC_RET_VALUE,
				0xFF, CFG_L1_0_RET_VALUE_DEFAULT);
	rtsx_pci_write_register(pcr, CFG_L1_0_CRC_SD30_RET_VALUE,
				0xFF, CFG_L1_0_RET_VALUE_DEFAULT);
	rtsx_pci_write_register(pcr, CFG_L1_0_CRC_SD40_RET_VALUE,
				0xFF, CFG_L1_0_RET_VALUE_DEFAULT);
	rtsx_pci_write_register(pcr, CFG_L1_0_SYS_RET_VALUE,
				0xFF, CFG_L1_0_RET_VALUE_DEFAULT);
	/*Option cut APHY*/
	rtsx_pci_write_register(pcr, CFG_PCIE_APHY_OFF_0,
				0xFF, CFG_PCIE_APHY_OFF_0_DEFAULT);
	rtsx_pci_write_register(pcr, CFG_PCIE_APHY_OFF_1,
				0xFF, CFG_PCIE_APHY_OFF_1_DEFAULT);
	rtsx_pci_write_register(pcr, CFG_PCIE_APHY_OFF_2,
				0xFF, CFG_PCIE_APHY_OFF_2_DEFAULT);
	rtsx_pci_write_register(pcr, CFG_PCIE_APHY_OFF_3,
				0xFF, CFG_PCIE_APHY_OFF_3_DEFAULT);
	/*CDR DEC*/
	rtsx_pci_write_register(pcr, PWC_CDR, 0xFF, PWC_CDR_DEFAULT);
	/*PWMPFM*/
	rtsx_pci_write_register(pcr, CFG_LP_FPWM_VALUE,
				0xFF, CFG_LP_FPWM_VALUE_DEFAULT);
	/*No Power Saving WA*/
	rtsx_pci_write_register(pcr, CFG_L1_0_CRC_MISC_RET_VALUE,
				0xFF, CFG_L1_0_CRC_MISC_RET_VALUE_DEFAULT);
}

__attribute__((used)) static void rts5260_init_from_cfg(struct rtsx_pcr *pcr)
{
	struct rtsx_cr_option *option = &pcr->option;
	u32 lval;

	rtsx_pci_read_config_dword(pcr, PCR_ASPM_SETTING_5260, &lval);

	if (lval & ASPM_L1_1_EN_MASK)
		rtsx_set_dev_flag(pcr, ASPM_L1_1_EN);

	if (lval & ASPM_L1_2_EN_MASK)
		rtsx_set_dev_flag(pcr, ASPM_L1_2_EN);

	if (lval & PM_L1_1_EN_MASK)
		rtsx_set_dev_flag(pcr, PM_L1_1_EN);

	if (lval & PM_L1_2_EN_MASK)
		rtsx_set_dev_flag(pcr, PM_L1_2_EN);

	rts5260_pwr_saving_setting(pcr);

	if (option->ltr_en) {
		u16 val;

		pcie_capability_read_word(pcr->pci, PCI_EXP_DEVCTL2, &val);
		if (val & PCI_EXP_DEVCTL2_LTR_EN) {
			option->ltr_enabled = true;
			option->ltr_active = true;
			rtsx_set_ltr_latency(pcr, option->ltr_active_latency);
		} else {
			option->ltr_enabled = false;
		}
	}

	if (rtsx_check_dev_flag(pcr, ASPM_L1_1_EN | ASPM_L1_2_EN
				| PM_L1_1_EN | PM_L1_2_EN))
		option->force_clkreq_0 = false;
	else
		option->force_clkreq_0 = true;
}

__attribute__((used)) static int rts5260_extra_init_hw(struct rtsx_pcr *pcr)
{
	struct rtsx_cr_option *option = &pcr->option;

	/* Set mcu_cnt to 7 to ensure data can be sampled properly */
	rtsx_pci_write_register(pcr, 0xFC03, 0x7F, 0x07);
	rtsx_pci_write_register(pcr, SSC_DIV_N_0, 0xFF, 0x5D);

	rts5260_init_from_cfg(pcr);

	/* force no MDIO*/
	rtsx_pci_write_register(pcr, RTS5260_AUTOLOAD_CFG4,
				0xFF, RTS5260_MIMO_DISABLE);
	/*Modify SDVCC Tune Default Parameters!*/
	rtsx_pci_write_register(pcr, LDO_VCC_CFG0,
				RTS5260_DVCC_TUNE_MASK, RTS5260_DVCC_33);

	rtsx_pci_write_register(pcr, PCLK_CTL, PCLK_MODE_SEL, PCLK_MODE_SEL);

	rts5260_init_hw(pcr);

	/*
	 * If u_force_clkreq_0 is enabled, CLKREQ# PIN will be forced
	 * to drive low, and we forcibly request clock.
	 */
	if (option->force_clkreq_0)
		rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, PETXCFG,
				 FORCE_CLKREQ_DELINK_MASK, FORCE_CLKREQ_LOW);
	else
		rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, PETXCFG,
				 FORCE_CLKREQ_DELINK_MASK, FORCE_CLKREQ_HIGH);

	return 0;
}

__attribute__((used)) static void rts5260_set_aspm(struct rtsx_pcr *pcr, bool enable)
{
	struct rtsx_cr_option *option = &pcr->option;
	u8 val = 0;

	if (pcr->aspm_enabled == enable)
		return;

	if (option->dev_aspm_mode == DEV_ASPM_DYNAMIC) {
		if (enable)
			val = pcr->aspm_en;
		rtsx_pci_update_cfg_byte(pcr, pcr->pcie_cap + PCI_EXP_LNKCTL,
					 ASPM_MASK_NEG, val);
	} else if (option->dev_aspm_mode == DEV_ASPM_BACKDOOR) {
		u8 mask = FORCE_ASPM_VAL_MASK | FORCE_ASPM_CTL0;

		if (!enable)
			val = FORCE_ASPM_CTL0;
		rtsx_pci_write_register(pcr, ASPM_FORCE_CTL, mask, val);
	}

	pcr->aspm_enabled = enable;
}

__attribute__((used)) static void rts5260_set_l1off_cfg_sub_d0(struct rtsx_pcr *pcr, int active)
{
	struct rtsx_cr_option *option = &pcr->option;
	u32 interrupt = rtsx_pci_readl(pcr, RTSX_BIPR);
	int card_exist = (interrupt & SD_EXIST) | (interrupt & MS_EXIST);
	int aspm_L1_1, aspm_L1_2;
	u8 val = 0;

	aspm_L1_1 = rtsx_check_dev_flag(pcr, ASPM_L1_1_EN);
	aspm_L1_2 = rtsx_check_dev_flag(pcr, ASPM_L1_2_EN);

	if (active) {
		/* run, latency: 60us */
		if (aspm_L1_1)
			val = option->ltr_l1off_snooze_sspwrgate;
	} else {
		/* l1off, latency: 300us */
		if (aspm_L1_2)
			val = option->ltr_l1off_sspwrgate;
	}

	if (aspm_L1_1 || aspm_L1_2) {
		if (rtsx_check_dev_flag(pcr,
					LTR_L1SS_PWR_GATE_CHECK_CARD_EN)) {
			if (card_exist)
				val &= ~L1OFF_MBIAS2_EN_5250;
			else
				val |= L1OFF_MBIAS2_EN_5250;
		}
	}
	rtsx_set_l1off_sub(pcr, val);
}

void rts5260_init_params(struct rtsx_pcr *pcr)
{
	struct rtsx_cr_option *option = &pcr->option;
	struct rtsx_hw_param *hw_param = &pcr->hw_param;

	pcr->extra_caps = EXTRA_CAPS_SD_SDR50 | EXTRA_CAPS_SD_SDR104;
	pcr->num_slots = 2;

	pcr->flags = 0;
	pcr->card_drive_sel = RTSX_CARD_DRIVE_DEFAULT;
	pcr->sd30_drive_sel_1v8 = CFG_DRIVER_TYPE_B;
	pcr->sd30_drive_sel_3v3 = CFG_DRIVER_TYPE_B;
	pcr->aspm_en = ASPM_L1_EN;
	pcr->tx_initial_phase = SET_CLOCK_PHASE(1, 29, 16);
	pcr->rx_initial_phase = SET_CLOCK_PHASE(24, 6, 5);

	pcr->ic_version = rts5260_get_ic_version(pcr);
	pcr->sd_pull_ctl_enable_tbl = rts5260_sd_pull_ctl_enable_tbl;
	pcr->sd_pull_ctl_disable_tbl = rts5260_sd_pull_ctl_disable_tbl;
	pcr->ms_pull_ctl_enable_tbl = rts5260_ms_pull_ctl_enable_tbl;
	pcr->ms_pull_ctl_disable_tbl = rts5260_ms_pull_ctl_disable_tbl;

	pcr->reg_pm_ctrl3 = RTS524A_PM_CTRL3;

	pcr->ops = &rts5260_pcr_ops;

	option->dev_flags = (LTR_L1SS_PWR_GATE_CHECK_CARD_EN
				| LTR_L1SS_PWR_GATE_EN);
	option->ltr_en = true;

	/* init latency of active, idle, L1OFF to 60us, 300us, 3ms */
	option->ltr_active_latency = LTR_ACTIVE_LATENCY_DEF;
	option->ltr_idle_latency = LTR_IDLE_LATENCY_DEF;
	option->ltr_l1off_latency = LTR_L1OFF_LATENCY_DEF;
	option->dev_aspm_mode = DEV_ASPM_DYNAMIC;
	option->l1_snooze_delay = L1_SNOOZE_DELAY_DEF;
	option->ltr_l1off_sspwrgate = LTR_L1OFF_SSPWRGATE_5250_DEF;
	option->ltr_l1off_snooze_sspwrgate =
		LTR_L1OFF_SNOOZE_SSPWRGATE_5250_DEF;

	option->ocp_en = 1;
	if (option->ocp_en)
		hw_param->interrupt_en |= SD_OC_INT_EN;
	hw_param->ocp_glitch = SD_OCP_GLITCH_10M | SDVIO_OCP_GLITCH_800U;
	option->sd_400mA_ocp_thd = RTS5260_DVCC_OCP_THD_550;
	option->sd_800mA_ocp_thd = RTS5260_DVCC_OCP_THD_970;
}

