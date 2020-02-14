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
typedef  int uint32_t ;
typedef  int u32 ;
struct platform_device {int dummy; } ;
struct hdmi_phy {int mmio; } ;
struct hdmi_hdcp_ctrl {int dummy; } ;
struct hdmi {int mmio; int qfprom_mmio; } ;
typedef  enum hdmi_hdcp_key_state { ____Placeholder_hdmi_hdcp_key_state } hdmi_hdcp_key_state ;
typedef  enum hdmi_ddc_read_write { ____Placeholder_hdmi_ddc_read_write } hdmi_ddc_read_write ;
typedef  enum hdmi_acr_cts { ____Placeholder_hdmi_acr_cts } hdmi_acr_cts ;

/* Variables and functions */
 int ENODEV ; 
 int /*<<< orphan*/  ENXIO ; 
 struct hdmi_hdcp_ctrl* ERR_PTR (int /*<<< orphan*/ ) ; 
 int HDMI_8x60_PHY_REG0_DESER_DEL_CTRL__MASK ; 
 int HDMI_8x60_PHY_REG0_DESER_DEL_CTRL__SHIFT ; 
 int HDMI_8x60_PHY_REG12_FORCE_LOCK ; 
 int HDMI_8x60_PHY_REG12_PLL_LOCK_DETECT_EN ; 
 int HDMI_8x60_PHY_REG12_RETIMING_EN ; 
 int HDMI_8x60_PHY_REG1_DTEST_MUX_SEL__MASK ; 
 int HDMI_8x60_PHY_REG1_DTEST_MUX_SEL__SHIFT ; 
 int HDMI_8x60_PHY_REG1_OUTVOL_SWING_CTRL__MASK ; 
 int HDMI_8x60_PHY_REG1_OUTVOL_SWING_CTRL__SHIFT ; 
 int HDMI_8x60_PHY_REG2_PD_DESER ; 
 int HDMI_8x60_PHY_REG2_PD_DRIVE_1 ; 
 int HDMI_8x60_PHY_REG2_PD_DRIVE_2 ; 
 int HDMI_8x60_PHY_REG2_PD_DRIVE_3 ; 
 int HDMI_8x60_PHY_REG2_PD_DRIVE_4 ; 
 int HDMI_8x60_PHY_REG2_PD_PLL ; 
 int HDMI_8x60_PHY_REG2_PD_PWRGEN ; 
 int HDMI_8x60_PHY_REG2_RCV_SENSE_EN ; 
 int HDMI_8x60_PHY_REG3_PLL_ENABLE ; 
 int HDMI_ACR_0_CTS__MASK ; 
 int HDMI_ACR_0_CTS__SHIFT ; 
 int HDMI_ACR_1_N__MASK ; 
 int HDMI_ACR_1_N__SHIFT ; 
 int HDMI_ACR_PKT_CTRL_N_MULTIPLIER__MASK ; 
 int HDMI_ACR_PKT_CTRL_N_MULTIPLIER__SHIFT ; 
 int HDMI_ACR_PKT_CTRL_SELECT__MASK ; 
 int HDMI_ACR_PKT_CTRL_SELECT__SHIFT ; 
 int HDMI_ACTIVE_HSYNC_END__MASK ; 
 int HDMI_ACTIVE_HSYNC_END__SHIFT ; 
 int HDMI_ACTIVE_HSYNC_START__MASK ; 
 int HDMI_ACTIVE_HSYNC_START__SHIFT ; 
 int HDMI_ACTIVE_VSYNC_END__MASK ; 
 int HDMI_ACTIVE_VSYNC_END__SHIFT ; 
 int HDMI_ACTIVE_VSYNC_START__MASK ; 
 int HDMI_ACTIVE_VSYNC_START__SHIFT ; 
 int HDMI_AUDIO_CFG_FIFO_WATERMARK__MASK ; 
 int HDMI_AUDIO_CFG_FIFO_WATERMARK__SHIFT ; 
 int HDMI_AUDIO_INFO0_CC__MASK ; 
 int HDMI_AUDIO_INFO0_CC__SHIFT ; 
 int HDMI_AUDIO_INFO0_CHECKSUM__MASK ; 
 int HDMI_AUDIO_INFO0_CHECKSUM__SHIFT ; 
 int HDMI_AUDIO_INFO1_CA__MASK ; 
 int HDMI_AUDIO_INFO1_CA__SHIFT ; 
 int HDMI_AUDIO_INFO1_LSV__MASK ; 
 int HDMI_AUDIO_INFO1_LSV__SHIFT ; 
 int HDMI_DDC_CTRL_TRANSACTION_CNT__MASK ; 
 int HDMI_DDC_CTRL_TRANSACTION_CNT__SHIFT ; 
 int HDMI_DDC_DATA_DATA_RW__MASK ; 
 int HDMI_DDC_DATA_DATA_RW__SHIFT ; 
 int HDMI_DDC_DATA_DATA__MASK ; 
 int HDMI_DDC_DATA_DATA__SHIFT ; 
 int HDMI_DDC_DATA_INDEX__MASK ; 
 int HDMI_DDC_DATA_INDEX__SHIFT ; 
 int HDMI_DDC_REF_REFTIMER__MASK ; 
 int HDMI_DDC_REF_REFTIMER__SHIFT ; 
 int HDMI_DDC_SETUP_TIMEOUT__MASK ; 
 int HDMI_DDC_SETUP_TIMEOUT__SHIFT ; 
 int HDMI_DDC_SPEED_PRESCALE__MASK ; 
 int HDMI_DDC_SPEED_PRESCALE__SHIFT ; 
 int HDMI_DDC_SPEED_THRESHOLD__MASK ; 
 int HDMI_DDC_SPEED_THRESHOLD__SHIFT ; 
 int HDMI_GEN_PKT_CTRL_GENERIC0_LINE__MASK ; 
 int HDMI_GEN_PKT_CTRL_GENERIC0_LINE__SHIFT ; 
 int HDMI_GEN_PKT_CTRL_GENERIC0_UPDATE__MASK ; 
 int HDMI_GEN_PKT_CTRL_GENERIC0_UPDATE__SHIFT ; 
 int HDMI_GEN_PKT_CTRL_GENERIC1_LINE__MASK ; 
 int HDMI_GEN_PKT_CTRL_GENERIC1_LINE__SHIFT ; 
 int HDMI_HDCP_LINK0_STATUS_KEY_STATE__MASK ; 
 int HDMI_HDCP_LINK0_STATUS_KEY_STATE__SHIFT ; 
 int HDMI_HPD_CTRL_TIMEOUT__MASK ; 
 int HDMI_HPD_CTRL_TIMEOUT__SHIFT ; 
 int HDMI_I2C_TRANSACTION_REG_CNT__MASK ; 
 int HDMI_I2C_TRANSACTION_REG_CNT__SHIFT ; 
 int HDMI_I2C_TRANSACTION_REG_RW__MASK ; 
 int HDMI_I2C_TRANSACTION_REG_RW__SHIFT ; 
 int HDMI_INFOFRAME_CTRL1_AUDIO_INFO_LINE__MASK ; 
 int HDMI_INFOFRAME_CTRL1_AUDIO_INFO_LINE__SHIFT ; 
 int HDMI_INFOFRAME_CTRL1_AVI_INFO_LINE__MASK ; 
 int HDMI_INFOFRAME_CTRL1_AVI_INFO_LINE__SHIFT ; 
 int HDMI_INFOFRAME_CTRL1_MPEG_INFO_LINE__MASK ; 
 int HDMI_INFOFRAME_CTRL1_MPEG_INFO_LINE__SHIFT ; 
 int HDMI_INFOFRAME_CTRL1_VENSPEC_INFO_LINE__MASK ; 
 int HDMI_INFOFRAME_CTRL1_VENSPEC_INFO_LINE__SHIFT ; 
 int HDMI_PHY_CTRL_SW_RESET ; 
 int HDMI_TOTAL_H_TOTAL__MASK ; 
 int HDMI_TOTAL_H_TOTAL__SHIFT ; 
 int HDMI_TOTAL_V_TOTAL__MASK ; 
 int HDMI_TOTAL_V_TOTAL__SHIFT ; 
 int HDMI_VSYNC_ACTIVE_F2_END__MASK ; 
 int HDMI_VSYNC_ACTIVE_F2_END__SHIFT ; 
 int HDMI_VSYNC_ACTIVE_F2_START__MASK ; 
 int HDMI_VSYNC_ACTIVE_F2_START__SHIFT ; 
 int HDMI_VSYNC_TOTAL_F2_V_TOTAL__MASK ; 
 int HDMI_VSYNC_TOTAL_F2_V_TOTAL__SHIFT ; 
 int REG_HDMI_8x60_PHY_REG0 ; 
 int REG_HDMI_8x60_PHY_REG1 ; 
 int REG_HDMI_8x60_PHY_REG10 ; 
 int REG_HDMI_8x60_PHY_REG11 ; 
 int REG_HDMI_8x60_PHY_REG12 ; 
 int REG_HDMI_8x60_PHY_REG2 ; 
 int REG_HDMI_8x60_PHY_REG3 ; 
 int REG_HDMI_8x60_PHY_REG4 ; 
 int REG_HDMI_8x60_PHY_REG5 ; 
 int REG_HDMI_8x60_PHY_REG6 ; 
 int REG_HDMI_8x60_PHY_REG7 ; 
 int REG_HDMI_8x60_PHY_REG8 ; 
 int REG_HDMI_8x60_PHY_REG9 ; 
 int REG_HDMI_PHY_CTRL ; 
 int msm_readl (int) ; 
 int /*<<< orphan*/  msm_writel (int,int) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static inline uint32_t HDMI_ACR_PKT_CTRL_SELECT(enum hdmi_acr_cts val)
{
	return ((val) << HDMI_ACR_PKT_CTRL_SELECT__SHIFT) & HDMI_ACR_PKT_CTRL_SELECT__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_ACR_PKT_CTRL_N_MULTIPLIER(uint32_t val)
{
	return ((val) << HDMI_ACR_PKT_CTRL_N_MULTIPLIER__SHIFT) & HDMI_ACR_PKT_CTRL_N_MULTIPLIER__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_INFOFRAME_CTRL1_AVI_INFO_LINE(uint32_t val)
{
	return ((val) << HDMI_INFOFRAME_CTRL1_AVI_INFO_LINE__SHIFT) & HDMI_INFOFRAME_CTRL1_AVI_INFO_LINE__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_INFOFRAME_CTRL1_AUDIO_INFO_LINE(uint32_t val)
{
	return ((val) << HDMI_INFOFRAME_CTRL1_AUDIO_INFO_LINE__SHIFT) & HDMI_INFOFRAME_CTRL1_AUDIO_INFO_LINE__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_INFOFRAME_CTRL1_MPEG_INFO_LINE(uint32_t val)
{
	return ((val) << HDMI_INFOFRAME_CTRL1_MPEG_INFO_LINE__SHIFT) & HDMI_INFOFRAME_CTRL1_MPEG_INFO_LINE__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_INFOFRAME_CTRL1_VENSPEC_INFO_LINE(uint32_t val)
{
	return ((val) << HDMI_INFOFRAME_CTRL1_VENSPEC_INFO_LINE__SHIFT) & HDMI_INFOFRAME_CTRL1_VENSPEC_INFO_LINE__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_GEN_PKT_CTRL_GENERIC0_UPDATE(uint32_t val)
{
	return ((val) << HDMI_GEN_PKT_CTRL_GENERIC0_UPDATE__SHIFT) & HDMI_GEN_PKT_CTRL_GENERIC0_UPDATE__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_GEN_PKT_CTRL_GENERIC0_LINE(uint32_t val)
{
	return ((val) << HDMI_GEN_PKT_CTRL_GENERIC0_LINE__SHIFT) & HDMI_GEN_PKT_CTRL_GENERIC0_LINE__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_GEN_PKT_CTRL_GENERIC1_LINE(uint32_t val)
{
	return ((val) << HDMI_GEN_PKT_CTRL_GENERIC1_LINE__SHIFT) & HDMI_GEN_PKT_CTRL_GENERIC1_LINE__MASK;
}

__attribute__((used)) static inline uint32_t REG_HDMI_AVI_INFO(uint32_t i0) { return 0x0000006c + 0x4*i0; }

__attribute__((used)) static inline uint32_t REG_HDMI_GENERIC0(uint32_t i0) { return 0x00000088 + 0x4*i0; }

__attribute__((used)) static inline uint32_t REG_HDMI_GENERIC1(uint32_t i0) { return 0x000000a8 + 0x4*i0; }

__attribute__((used)) static inline uint32_t REG_HDMI_ACR(enum hdmi_acr_cts i0) { return 0x000000c4 + 0x8*i0; }

__attribute__((used)) static inline uint32_t REG_HDMI_ACR_0(enum hdmi_acr_cts i0) { return 0x000000c4 + 0x8*i0; }

__attribute__((used)) static inline uint32_t HDMI_ACR_0_CTS(uint32_t val)
{
	return ((val) << HDMI_ACR_0_CTS__SHIFT) & HDMI_ACR_0_CTS__MASK;
}

__attribute__((used)) static inline uint32_t REG_HDMI_ACR_1(enum hdmi_acr_cts i0) { return 0x000000c8 + 0x8*i0; }

__attribute__((used)) static inline uint32_t HDMI_ACR_1_N(uint32_t val)
{
	return ((val) << HDMI_ACR_1_N__SHIFT) & HDMI_ACR_1_N__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_AUDIO_INFO0_CHECKSUM(uint32_t val)
{
	return ((val) << HDMI_AUDIO_INFO0_CHECKSUM__SHIFT) & HDMI_AUDIO_INFO0_CHECKSUM__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_AUDIO_INFO0_CC(uint32_t val)
{
	return ((val) << HDMI_AUDIO_INFO0_CC__SHIFT) & HDMI_AUDIO_INFO0_CC__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_AUDIO_INFO1_CA(uint32_t val)
{
	return ((val) << HDMI_AUDIO_INFO1_CA__SHIFT) & HDMI_AUDIO_INFO1_CA__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_AUDIO_INFO1_LSV(uint32_t val)
{
	return ((val) << HDMI_AUDIO_INFO1_LSV__SHIFT) & HDMI_AUDIO_INFO1_LSV__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_HDCP_LINK0_STATUS_KEY_STATE(enum hdmi_hdcp_key_state val)
{
	return ((val) << HDMI_HDCP_LINK0_STATUS_KEY_STATE__SHIFT) & HDMI_HDCP_LINK0_STATUS_KEY_STATE__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_AUDIO_CFG_FIFO_WATERMARK(uint32_t val)
{
	return ((val) << HDMI_AUDIO_CFG_FIFO_WATERMARK__SHIFT) & HDMI_AUDIO_CFG_FIFO_WATERMARK__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_DDC_CTRL_TRANSACTION_CNT(uint32_t val)
{
	return ((val) << HDMI_DDC_CTRL_TRANSACTION_CNT__SHIFT) & HDMI_DDC_CTRL_TRANSACTION_CNT__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_DDC_SPEED_THRESHOLD(uint32_t val)
{
	return ((val) << HDMI_DDC_SPEED_THRESHOLD__SHIFT) & HDMI_DDC_SPEED_THRESHOLD__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_DDC_SPEED_PRESCALE(uint32_t val)
{
	return ((val) << HDMI_DDC_SPEED_PRESCALE__SHIFT) & HDMI_DDC_SPEED_PRESCALE__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_DDC_SETUP_TIMEOUT(uint32_t val)
{
	return ((val) << HDMI_DDC_SETUP_TIMEOUT__SHIFT) & HDMI_DDC_SETUP_TIMEOUT__MASK;
}

__attribute__((used)) static inline uint32_t REG_HDMI_I2C_TRANSACTION(uint32_t i0) { return 0x00000228 + 0x4*i0; }

__attribute__((used)) static inline uint32_t REG_HDMI_I2C_TRANSACTION_REG(uint32_t i0) { return 0x00000228 + 0x4*i0; }

__attribute__((used)) static inline uint32_t HDMI_I2C_TRANSACTION_REG_RW(enum hdmi_ddc_read_write val)
{
	return ((val) << HDMI_I2C_TRANSACTION_REG_RW__SHIFT) & HDMI_I2C_TRANSACTION_REG_RW__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_I2C_TRANSACTION_REG_CNT(uint32_t val)
{
	return ((val) << HDMI_I2C_TRANSACTION_REG_CNT__SHIFT) & HDMI_I2C_TRANSACTION_REG_CNT__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_DDC_DATA_DATA_RW(enum hdmi_ddc_read_write val)
{
	return ((val) << HDMI_DDC_DATA_DATA_RW__SHIFT) & HDMI_DDC_DATA_DATA_RW__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_DDC_DATA_DATA(uint32_t val)
{
	return ((val) << HDMI_DDC_DATA_DATA__SHIFT) & HDMI_DDC_DATA_DATA__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_DDC_DATA_INDEX(uint32_t val)
{
	return ((val) << HDMI_DDC_DATA_INDEX__SHIFT) & HDMI_DDC_DATA_INDEX__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_HPD_CTRL_TIMEOUT(uint32_t val)
{
	return ((val) << HDMI_HPD_CTRL_TIMEOUT__SHIFT) & HDMI_HPD_CTRL_TIMEOUT__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_DDC_REF_REFTIMER(uint32_t val)
{
	return ((val) << HDMI_DDC_REF_REFTIMER__SHIFT) & HDMI_DDC_REF_REFTIMER__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_ACTIVE_HSYNC_START(uint32_t val)
{
	return ((val) << HDMI_ACTIVE_HSYNC_START__SHIFT) & HDMI_ACTIVE_HSYNC_START__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_ACTIVE_HSYNC_END(uint32_t val)
{
	return ((val) << HDMI_ACTIVE_HSYNC_END__SHIFT) & HDMI_ACTIVE_HSYNC_END__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_ACTIVE_VSYNC_START(uint32_t val)
{
	return ((val) << HDMI_ACTIVE_VSYNC_START__SHIFT) & HDMI_ACTIVE_VSYNC_START__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_ACTIVE_VSYNC_END(uint32_t val)
{
	return ((val) << HDMI_ACTIVE_VSYNC_END__SHIFT) & HDMI_ACTIVE_VSYNC_END__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_VSYNC_ACTIVE_F2_START(uint32_t val)
{
	return ((val) << HDMI_VSYNC_ACTIVE_F2_START__SHIFT) & HDMI_VSYNC_ACTIVE_F2_START__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_VSYNC_ACTIVE_F2_END(uint32_t val)
{
	return ((val) << HDMI_VSYNC_ACTIVE_F2_END__SHIFT) & HDMI_VSYNC_ACTIVE_F2_END__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_TOTAL_H_TOTAL(uint32_t val)
{
	return ((val) << HDMI_TOTAL_H_TOTAL__SHIFT) & HDMI_TOTAL_H_TOTAL__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_TOTAL_V_TOTAL(uint32_t val)
{
	return ((val) << HDMI_TOTAL_V_TOTAL__SHIFT) & HDMI_TOTAL_V_TOTAL__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_VSYNC_TOTAL_F2_V_TOTAL(uint32_t val)
{
	return ((val) << HDMI_VSYNC_TOTAL_F2_V_TOTAL__SHIFT) & HDMI_VSYNC_TOTAL_F2_V_TOTAL__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_8x60_PHY_REG0_DESER_DEL_CTRL(uint32_t val)
{
	return ((val) << HDMI_8x60_PHY_REG0_DESER_DEL_CTRL__SHIFT) & HDMI_8x60_PHY_REG0_DESER_DEL_CTRL__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_8x60_PHY_REG1_DTEST_MUX_SEL(uint32_t val)
{
	return ((val) << HDMI_8x60_PHY_REG1_DTEST_MUX_SEL__SHIFT) & HDMI_8x60_PHY_REG1_DTEST_MUX_SEL__MASK;
}

__attribute__((used)) static inline uint32_t HDMI_8x60_PHY_REG1_OUTVOL_SWING_CTRL(uint32_t val)
{
	return ((val) << HDMI_8x60_PHY_REG1_OUTVOL_SWING_CTRL__SHIFT) & HDMI_8x60_PHY_REG1_OUTVOL_SWING_CTRL__MASK;
}

__attribute__((used)) static inline void hdmi_write(struct hdmi *hdmi, u32 reg, u32 data)
{
	msm_writel(data, hdmi->mmio + reg);
}

__attribute__((used)) static inline u32 hdmi_read(struct hdmi *hdmi, u32 reg)
{
	return msm_readl(hdmi->mmio + reg);
}

__attribute__((used)) static inline u32 hdmi_qfprom_read(struct hdmi *hdmi, u32 reg)
{
	return msm_readl(hdmi->qfprom_mmio + reg);
}

__attribute__((used)) static inline void hdmi_phy_write(struct hdmi_phy *phy, u32 reg, u32 data)
{
	msm_writel(data, phy->mmio + reg);
}

__attribute__((used)) static inline u32 hdmi_phy_read(struct hdmi_phy *phy, u32 reg)
{
	return msm_readl(phy->mmio + reg);
}

__attribute__((used)) static inline int msm_hdmi_pll_8960_init(struct platform_device *pdev)
{
	return -ENODEV;
}

__attribute__((used)) static inline int msm_hdmi_pll_8996_init(struct platform_device *pdev)
{
	return -ENODEV;
}

__attribute__((used)) static inline struct hdmi_hdcp_ctrl *msm_hdmi_hdcp_init(struct hdmi *hdmi)
{
	return ERR_PTR(-ENXIO);
}

__attribute__((used)) static inline void msm_hdmi_hdcp_destroy(struct hdmi *hdmi) {}

__attribute__((used)) static inline void msm_hdmi_hdcp_on(struct hdmi_hdcp_ctrl *hdcp_ctrl) {}

__attribute__((used)) static inline void msm_hdmi_hdcp_off(struct hdmi_hdcp_ctrl *hdcp_ctrl) {}

__attribute__((used)) static inline void msm_hdmi_hdcp_irq(struct hdmi_hdcp_ctrl *hdcp_ctrl) {}

__attribute__((used)) static void hdmi_phy_8x60_powerup(struct hdmi_phy *phy,
		unsigned long int pixclock)
{
	/* De-serializer delay D/C for non-lbk mode: */
	hdmi_phy_write(phy, REG_HDMI_8x60_PHY_REG0,
		       HDMI_8x60_PHY_REG0_DESER_DEL_CTRL(3));

	if (pixclock == 27000000) {
		/* video_format == HDMI_VFRMT_720x480p60_16_9 */
		hdmi_phy_write(phy, REG_HDMI_8x60_PHY_REG1,
			       HDMI_8x60_PHY_REG1_DTEST_MUX_SEL(5) |
			       HDMI_8x60_PHY_REG1_OUTVOL_SWING_CTRL(3));
	} else {
		hdmi_phy_write(phy, REG_HDMI_8x60_PHY_REG1,
			       HDMI_8x60_PHY_REG1_DTEST_MUX_SEL(5) |
			       HDMI_8x60_PHY_REG1_OUTVOL_SWING_CTRL(4));
	}

	/* No matter what, start from the power down mode: */
	hdmi_phy_write(phy, REG_HDMI_8x60_PHY_REG2,
		       HDMI_8x60_PHY_REG2_PD_PWRGEN |
		       HDMI_8x60_PHY_REG2_PD_PLL |
		       HDMI_8x60_PHY_REG2_PD_DRIVE_4 |
		       HDMI_8x60_PHY_REG2_PD_DRIVE_3 |
		       HDMI_8x60_PHY_REG2_PD_DRIVE_2 |
		       HDMI_8x60_PHY_REG2_PD_DRIVE_1 |
		       HDMI_8x60_PHY_REG2_PD_DESER);

	/* Turn PowerGen on: */
	hdmi_phy_write(phy, REG_HDMI_8x60_PHY_REG2,
		       HDMI_8x60_PHY_REG2_PD_PLL |
		       HDMI_8x60_PHY_REG2_PD_DRIVE_4 |
		       HDMI_8x60_PHY_REG2_PD_DRIVE_3 |
		       HDMI_8x60_PHY_REG2_PD_DRIVE_2 |
		       HDMI_8x60_PHY_REG2_PD_DRIVE_1 |
		       HDMI_8x60_PHY_REG2_PD_DESER);

	/* Turn PLL power on: */
	hdmi_phy_write(phy, REG_HDMI_8x60_PHY_REG2,
		       HDMI_8x60_PHY_REG2_PD_DRIVE_4 |
		       HDMI_8x60_PHY_REG2_PD_DRIVE_3 |
		       HDMI_8x60_PHY_REG2_PD_DRIVE_2 |
		       HDMI_8x60_PHY_REG2_PD_DRIVE_1 |
		       HDMI_8x60_PHY_REG2_PD_DESER);

	/* Write to HIGH after PLL power down de-assert: */
	hdmi_phy_write(phy, REG_HDMI_8x60_PHY_REG3,
		       HDMI_8x60_PHY_REG3_PLL_ENABLE);

	/* ASIC power on; PHY REG9 = 0 */
	hdmi_phy_write(phy, REG_HDMI_8x60_PHY_REG9, 0);

	/* Enable PLL lock detect, PLL lock det will go high after lock
	 * Enable the re-time logic
	 */
	hdmi_phy_write(phy, REG_HDMI_8x60_PHY_REG12,
		       HDMI_8x60_PHY_REG12_RETIMING_EN |
		       HDMI_8x60_PHY_REG12_PLL_LOCK_DETECT_EN);

	/* Drivers are on: */
	hdmi_phy_write(phy, REG_HDMI_8x60_PHY_REG2,
		       HDMI_8x60_PHY_REG2_PD_DESER);

	/* If the RX detector is needed: */
	hdmi_phy_write(phy, REG_HDMI_8x60_PHY_REG2,
		       HDMI_8x60_PHY_REG2_RCV_SENSE_EN |
		       HDMI_8x60_PHY_REG2_PD_DESER);

	hdmi_phy_write(phy, REG_HDMI_8x60_PHY_REG4, 0);
	hdmi_phy_write(phy, REG_HDMI_8x60_PHY_REG5, 0);
	hdmi_phy_write(phy, REG_HDMI_8x60_PHY_REG6, 0);
	hdmi_phy_write(phy, REG_HDMI_8x60_PHY_REG7, 0);
	hdmi_phy_write(phy, REG_HDMI_8x60_PHY_REG8, 0);
	hdmi_phy_write(phy, REG_HDMI_8x60_PHY_REG9, 0);
	hdmi_phy_write(phy, REG_HDMI_8x60_PHY_REG10, 0);
	hdmi_phy_write(phy, REG_HDMI_8x60_PHY_REG11, 0);

	/* If we want to use lock enable based on counting: */
	hdmi_phy_write(phy, REG_HDMI_8x60_PHY_REG12,
		       HDMI_8x60_PHY_REG12_RETIMING_EN |
		       HDMI_8x60_PHY_REG12_PLL_LOCK_DETECT_EN |
		       HDMI_8x60_PHY_REG12_FORCE_LOCK);
}

__attribute__((used)) static void hdmi_phy_8x60_powerdown(struct hdmi_phy *phy)
{
	/* Assert RESET PHY from controller */
	hdmi_phy_write(phy, REG_HDMI_PHY_CTRL,
		       HDMI_PHY_CTRL_SW_RESET);
	udelay(10);
	/* De-assert RESET PHY from controller */
	hdmi_phy_write(phy, REG_HDMI_PHY_CTRL, 0);
	/* Turn off Driver */
	hdmi_phy_write(phy, REG_HDMI_8x60_PHY_REG2,
		       HDMI_8x60_PHY_REG2_PD_DRIVE_4 |
		       HDMI_8x60_PHY_REG2_PD_DRIVE_3 |
		       HDMI_8x60_PHY_REG2_PD_DRIVE_2 |
		       HDMI_8x60_PHY_REG2_PD_DRIVE_1 |
		       HDMI_8x60_PHY_REG2_PD_DESER);
	udelay(10);
	/* Disable PLL */
	hdmi_phy_write(phy, REG_HDMI_8x60_PHY_REG3, 0);
	/* Power down PHY, but keep RX-sense: */
	hdmi_phy_write(phy, REG_HDMI_8x60_PHY_REG2,
		       HDMI_8x60_PHY_REG2_RCV_SENSE_EN |
		       HDMI_8x60_PHY_REG2_PD_PWRGEN |
		       HDMI_8x60_PHY_REG2_PD_PLL |
		       HDMI_8x60_PHY_REG2_PD_DRIVE_4 |
		       HDMI_8x60_PHY_REG2_PD_DRIVE_3 |
		       HDMI_8x60_PHY_REG2_PD_DRIVE_2 |
		       HDMI_8x60_PHY_REG2_PD_DRIVE_1 |
		       HDMI_8x60_PHY_REG2_PD_DESER);
}

