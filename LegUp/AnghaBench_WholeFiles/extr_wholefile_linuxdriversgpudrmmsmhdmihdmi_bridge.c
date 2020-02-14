#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
union hdmi_infoframe {int /*<<< orphan*/  avi; } ;
typedef  int uint32_t ;
typedef  int u8 ;
typedef  int u32 ;
struct platform_device {int dummy; } ;
struct hdmi_platform_config {int pwr_reg_cnt; int pwr_clk_cnt; int /*<<< orphan*/ * pwr_reg_names; int /*<<< orphan*/ * pwr_clk_names; } ;
struct hdmi_phy {int mmio; } ;
struct hdmi_hdcp_ctrl {int /*<<< orphan*/ * funcs; struct drm_device* dev; } ;
struct hdmi_bridge {struct hdmi_hdcp_ctrl base; struct hdmi* hdmi; } ;
struct hdmi {int mmio; int qfprom_mmio; int pixclock; int power_on; TYPE_4__* encoder; TYPE_3__* dev; scalar_t__ hdmi_mode; struct hdmi_hdcp_ctrl* hdcp_ctrl; struct hdmi_phy* phy; TYPE_2__* pdev; int /*<<< orphan*/ * pwr_regs; int /*<<< orphan*/ * pwr_clks; struct hdmi_platform_config* config; } ;
struct drm_display_mode {int clock; int htotal; int hsync_start; int hdisplay; int vtotal; int vsync_start; int vdisplay; int flags; } ;
struct drm_device {int /*<<< orphan*/  dev; } ;
struct drm_crtc {TYPE_1__* state; } ;
struct drm_bridge {int /*<<< orphan*/ * funcs; struct drm_device* dev; } ;
typedef  enum hdmi_hdcp_key_state { ____Placeholder_hdmi_hdcp_key_state } hdmi_hdcp_key_state ;
typedef  enum hdmi_ddc_read_write { ____Placeholder_hdmi_ddc_read_write } hdmi_ddc_read_write ;
typedef  enum hdmi_acr_cts { ____Placeholder_hdmi_acr_cts } hdmi_acr_cts ;
typedef  int /*<<< orphan*/  buffer ;
struct TYPE_8__ {struct drm_crtc* crtc; } ;
struct TYPE_7__ {int /*<<< orphan*/  dev; } ;
struct TYPE_6__ {int /*<<< orphan*/  dev; } ;
struct TYPE_5__ {struct drm_display_mode adjusted_mode; } ;

/* Variables and functions */
 int /*<<< orphan*/  AVI ; 
 int AVI_IFRAME_LINE_NUMBER ; 
 int /*<<< orphan*/  DBG (char*,...) ; 
 int DRM_MODE_FLAG_INTERLACE ; 
 int DRM_MODE_FLAG_NHSYNC ; 
 int DRM_MODE_FLAG_NVSYNC ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENXIO ; 
 struct hdmi_hdcp_ctrl* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HDMI_8x60_PHY_REG0_DESER_DEL_CTRL__MASK ; 
 int HDMI_8x60_PHY_REG0_DESER_DEL_CTRL__SHIFT ; 
 int HDMI_8x60_PHY_REG1_DTEST_MUX_SEL__MASK ; 
 int HDMI_8x60_PHY_REG1_DTEST_MUX_SEL__SHIFT ; 
 int HDMI_8x60_PHY_REG1_OUTVOL_SWING_CTRL__MASK ; 
 int HDMI_8x60_PHY_REG1_OUTVOL_SWING_CTRL__SHIFT ; 
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
 int HDMI_FRAME_CTRL_HSYNC_LOW ; 
 int HDMI_FRAME_CTRL_INTERLACED_EN ; 
 int HDMI_FRAME_CTRL_VSYNC_LOW ; 
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
 int HDMI_INFOFRAME_CTRL0_AVI_CONT ; 
 int HDMI_INFOFRAME_CTRL0_AVI_SEND ; 
 int HDMI_INFOFRAME_CTRL1_AUDIO_INFO_LINE__MASK ; 
 int HDMI_INFOFRAME_CTRL1_AUDIO_INFO_LINE__SHIFT ; 
 int HDMI_INFOFRAME_CTRL1_AVI_INFO_LINE__MASK ; 
 int HDMI_INFOFRAME_CTRL1_AVI_INFO_LINE__SHIFT ; 
 int HDMI_INFOFRAME_CTRL1_MPEG_INFO_LINE__MASK ; 
 int HDMI_INFOFRAME_CTRL1_MPEG_INFO_LINE__SHIFT ; 
 int HDMI_INFOFRAME_CTRL1_VENSPEC_INFO_LINE__MASK ; 
 int HDMI_INFOFRAME_CTRL1_VENSPEC_INFO_LINE__SHIFT ; 
 int HDMI_INFOFRAME_SIZE (int /*<<< orphan*/ ) ; 
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
 int REG_HDMI_ACTIVE_HSYNC ; 
 int REG_HDMI_ACTIVE_VSYNC ; 
 int REG_HDMI_FRAME_CTRL ; 
 int REG_HDMI_INFOFRAME_CTRL0 ; 
 int REG_HDMI_INFOFRAME_CTRL1 ; 
 int REG_HDMI_TOTAL ; 
 int REG_HDMI_VSYNC_ACTIVE_F2 ; 
 int REG_HDMI_VSYNC_TOTAL_F2 ; 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 int clk_prepare_enable (int /*<<< orphan*/ ) ; 
 int clk_set_rate (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct hdmi_bridge* devm_kzalloc (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int drm_bridge_attach (TYPE_4__*,struct hdmi_hdcp_ctrl*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  drm_hdmi_avi_infoframe_from_display_mode (int /*<<< orphan*/ *,struct drm_display_mode const*,int) ; 
 int hdmi_infoframe_pack (union hdmi_infoframe*,int*,int) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  msm_hdmi_audio_update (struct hdmi*) ; 
 int /*<<< orphan*/  msm_hdmi_bridge_funcs ; 
 int /*<<< orphan*/  msm_hdmi_phy_powerdown (struct hdmi_phy*) ; 
 int /*<<< orphan*/  msm_hdmi_phy_powerup (struct hdmi_phy*,int) ; 
 int /*<<< orphan*/  msm_hdmi_phy_resource_disable (struct hdmi_phy*) ; 
 int /*<<< orphan*/  msm_hdmi_phy_resource_enable (struct hdmi_phy*) ; 
 int /*<<< orphan*/  msm_hdmi_set_mode (struct hdmi*,int) ; 
 int msm_readl (int) ; 
 int /*<<< orphan*/  msm_writel (int,int) ; 
 int /*<<< orphan*/  pm_runtime_get_sync (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_put_autosuspend (int /*<<< orphan*/ *) ; 
 int regulator_disable (int /*<<< orphan*/ ) ; 
 int regulator_enable (int /*<<< orphan*/ ) ; 
 struct hdmi_bridge* to_hdmi_bridge (struct hdmi_hdcp_ctrl*) ; 

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

void msm_hdmi_bridge_destroy(struct drm_bridge *bridge)
{
}

__attribute__((used)) static void msm_hdmi_power_on(struct drm_bridge *bridge)
{
	struct drm_device *dev = bridge->dev;
	struct hdmi_bridge *hdmi_bridge = to_hdmi_bridge(bridge);
	struct hdmi *hdmi = hdmi_bridge->hdmi;
	const struct hdmi_platform_config *config = hdmi->config;
	int i, ret;

	pm_runtime_get_sync(&hdmi->pdev->dev);

	for (i = 0; i < config->pwr_reg_cnt; i++) {
		ret = regulator_enable(hdmi->pwr_regs[i]);
		if (ret) {
			dev_err(dev->dev, "failed to enable pwr regulator: %s (%d)\n",
					config->pwr_reg_names[i], ret);
		}
	}

	if (config->pwr_clk_cnt > 0) {
		DBG("pixclock: %lu", hdmi->pixclock);
		ret = clk_set_rate(hdmi->pwr_clks[0], hdmi->pixclock);
		if (ret) {
			dev_err(dev->dev, "failed to set pixel clk: %s (%d)\n",
					config->pwr_clk_names[0], ret);
		}
	}

	for (i = 0; i < config->pwr_clk_cnt; i++) {
		ret = clk_prepare_enable(hdmi->pwr_clks[i]);
		if (ret) {
			dev_err(dev->dev, "failed to enable pwr clk: %s (%d)\n",
					config->pwr_clk_names[i], ret);
		}
	}
}

__attribute__((used)) static void power_off(struct drm_bridge *bridge)
{
	struct drm_device *dev = bridge->dev;
	struct hdmi_bridge *hdmi_bridge = to_hdmi_bridge(bridge);
	struct hdmi *hdmi = hdmi_bridge->hdmi;
	const struct hdmi_platform_config *config = hdmi->config;
	int i, ret;

	/* TODO do we need to wait for final vblank somewhere before
	 * cutting the clocks?
	 */
	mdelay(16 + 4);

	for (i = 0; i < config->pwr_clk_cnt; i++)
		clk_disable_unprepare(hdmi->pwr_clks[i]);

	for (i = 0; i < config->pwr_reg_cnt; i++) {
		ret = regulator_disable(hdmi->pwr_regs[i]);
		if (ret) {
			dev_err(dev->dev, "failed to disable pwr regulator: %s (%d)\n",
					config->pwr_reg_names[i], ret);
		}
	}

	pm_runtime_put_autosuspend(&hdmi->pdev->dev);
}

__attribute__((used)) static void msm_hdmi_config_avi_infoframe(struct hdmi *hdmi)
{
	struct drm_crtc *crtc = hdmi->encoder->crtc;
	const struct drm_display_mode *mode = &crtc->state->adjusted_mode;
	union hdmi_infoframe frame;
	u8 buffer[HDMI_INFOFRAME_SIZE(AVI)];
	u32 val;
	int len;

	drm_hdmi_avi_infoframe_from_display_mode(&frame.avi, mode, false);

	len = hdmi_infoframe_pack(&frame, buffer, sizeof(buffer));
	if (len < 0) {
		dev_err(&hdmi->pdev->dev,
			"failed to configure avi infoframe\n");
		return;
	}

	/*
	 * the AVI_INFOx registers don't map exactly to how the AVI infoframes
	 * are packed according to the spec. The checksum from the header is
	 * written to the LSB byte of AVI_INFO0 and the version is written to
	 * the third byte from the LSB of AVI_INFO3
	 */
	hdmi_write(hdmi, REG_HDMI_AVI_INFO(0),
		   buffer[3] |
		   buffer[4] << 8 |
		   buffer[5] << 16 |
		   buffer[6] << 24);

	hdmi_write(hdmi, REG_HDMI_AVI_INFO(1),
		   buffer[7] |
		   buffer[8] << 8 |
		   buffer[9] << 16 |
		   buffer[10] << 24);

	hdmi_write(hdmi, REG_HDMI_AVI_INFO(2),
		   buffer[11] |
		   buffer[12] << 8 |
		   buffer[13] << 16 |
		   buffer[14] << 24);

	hdmi_write(hdmi, REG_HDMI_AVI_INFO(3),
		   buffer[15] |
		   buffer[16] << 8 |
		   buffer[1] << 24);

	hdmi_write(hdmi, REG_HDMI_INFOFRAME_CTRL0,
		   HDMI_INFOFRAME_CTRL0_AVI_SEND |
		   HDMI_INFOFRAME_CTRL0_AVI_CONT);

	val = hdmi_read(hdmi, REG_HDMI_INFOFRAME_CTRL1);
	val &= ~HDMI_INFOFRAME_CTRL1_AVI_INFO_LINE__MASK;
	val |= HDMI_INFOFRAME_CTRL1_AVI_INFO_LINE(AVI_IFRAME_LINE_NUMBER);
	hdmi_write(hdmi, REG_HDMI_INFOFRAME_CTRL1, val);
}

__attribute__((used)) static void msm_hdmi_bridge_pre_enable(struct drm_bridge *bridge)
{
	struct hdmi_bridge *hdmi_bridge = to_hdmi_bridge(bridge);
	struct hdmi *hdmi = hdmi_bridge->hdmi;
	struct hdmi_phy *phy = hdmi->phy;

	DBG("power up");

	if (!hdmi->power_on) {
		msm_hdmi_phy_resource_enable(phy);
		msm_hdmi_power_on(bridge);
		hdmi->power_on = true;
		if (hdmi->hdmi_mode) {
			msm_hdmi_config_avi_infoframe(hdmi);
			msm_hdmi_audio_update(hdmi);
		}
	}

	msm_hdmi_phy_powerup(phy, hdmi->pixclock);

	msm_hdmi_set_mode(hdmi, true);

	if (hdmi->hdcp_ctrl)
		msm_hdmi_hdcp_on(hdmi->hdcp_ctrl);
}

__attribute__((used)) static void msm_hdmi_bridge_enable(struct drm_bridge *bridge)
{
}

__attribute__((used)) static void msm_hdmi_bridge_disable(struct drm_bridge *bridge)
{
}

__attribute__((used)) static void msm_hdmi_bridge_post_disable(struct drm_bridge *bridge)
{
	struct hdmi_bridge *hdmi_bridge = to_hdmi_bridge(bridge);
	struct hdmi *hdmi = hdmi_bridge->hdmi;
	struct hdmi_phy *phy = hdmi->phy;

	if (hdmi->hdcp_ctrl)
		msm_hdmi_hdcp_off(hdmi->hdcp_ctrl);

	DBG("power down");
	msm_hdmi_set_mode(hdmi, false);

	msm_hdmi_phy_powerdown(phy);

	if (hdmi->power_on) {
		power_off(bridge);
		hdmi->power_on = false;
		if (hdmi->hdmi_mode)
			msm_hdmi_audio_update(hdmi);
		msm_hdmi_phy_resource_disable(phy);
	}
}

__attribute__((used)) static void msm_hdmi_bridge_mode_set(struct drm_bridge *bridge,
		 struct drm_display_mode *mode,
		 struct drm_display_mode *adjusted_mode)
{
	struct hdmi_bridge *hdmi_bridge = to_hdmi_bridge(bridge);
	struct hdmi *hdmi = hdmi_bridge->hdmi;
	int hstart, hend, vstart, vend;
	uint32_t frame_ctrl;

	mode = adjusted_mode;

	hdmi->pixclock = mode->clock * 1000;

	hstart = mode->htotal - mode->hsync_start;
	hend   = mode->htotal - mode->hsync_start + mode->hdisplay;

	vstart = mode->vtotal - mode->vsync_start - 1;
	vend   = mode->vtotal - mode->vsync_start + mode->vdisplay - 1;

	DBG("htotal=%d, vtotal=%d, hstart=%d, hend=%d, vstart=%d, vend=%d",
			mode->htotal, mode->vtotal, hstart, hend, vstart, vend);

	hdmi_write(hdmi, REG_HDMI_TOTAL,
			HDMI_TOTAL_H_TOTAL(mode->htotal - 1) |
			HDMI_TOTAL_V_TOTAL(mode->vtotal - 1));

	hdmi_write(hdmi, REG_HDMI_ACTIVE_HSYNC,
			HDMI_ACTIVE_HSYNC_START(hstart) |
			HDMI_ACTIVE_HSYNC_END(hend));
	hdmi_write(hdmi, REG_HDMI_ACTIVE_VSYNC,
			HDMI_ACTIVE_VSYNC_START(vstart) |
			HDMI_ACTIVE_VSYNC_END(vend));

	if (mode->flags & DRM_MODE_FLAG_INTERLACE) {
		hdmi_write(hdmi, REG_HDMI_VSYNC_TOTAL_F2,
				HDMI_VSYNC_TOTAL_F2_V_TOTAL(mode->vtotal));
		hdmi_write(hdmi, REG_HDMI_VSYNC_ACTIVE_F2,
				HDMI_VSYNC_ACTIVE_F2_START(vstart + 1) |
				HDMI_VSYNC_ACTIVE_F2_END(vend + 1));
	} else {
		hdmi_write(hdmi, REG_HDMI_VSYNC_TOTAL_F2,
				HDMI_VSYNC_TOTAL_F2_V_TOTAL(0));
		hdmi_write(hdmi, REG_HDMI_VSYNC_ACTIVE_F2,
				HDMI_VSYNC_ACTIVE_F2_START(0) |
				HDMI_VSYNC_ACTIVE_F2_END(0));
	}

	frame_ctrl = 0;
	if (mode->flags & DRM_MODE_FLAG_NHSYNC)
		frame_ctrl |= HDMI_FRAME_CTRL_HSYNC_LOW;
	if (mode->flags & DRM_MODE_FLAG_NVSYNC)
		frame_ctrl |= HDMI_FRAME_CTRL_VSYNC_LOW;
	if (mode->flags & DRM_MODE_FLAG_INTERLACE)
		frame_ctrl |= HDMI_FRAME_CTRL_INTERLACED_EN;
	DBG("frame_ctrl=%08x", frame_ctrl);
	hdmi_write(hdmi, REG_HDMI_FRAME_CTRL, frame_ctrl);

	if (hdmi->hdmi_mode)
		msm_hdmi_audio_update(hdmi);
}

struct drm_bridge *msm_hdmi_bridge_init(struct hdmi *hdmi)
{
	struct drm_bridge *bridge = NULL;
	struct hdmi_bridge *hdmi_bridge;
	int ret;

	hdmi_bridge = devm_kzalloc(hdmi->dev->dev,
			sizeof(*hdmi_bridge), GFP_KERNEL);
	if (!hdmi_bridge) {
		ret = -ENOMEM;
		goto fail;
	}

	hdmi_bridge->hdmi = hdmi;

	bridge = &hdmi_bridge->base;
	bridge->funcs = &msm_hdmi_bridge_funcs;

	ret = drm_bridge_attach(hdmi->encoder, bridge, NULL);
	if (ret)
		goto fail;

	return bridge;

fail:
	if (bridge)
		msm_hdmi_bridge_destroy(bridge);

	return ERR_PTR(ret);
}

