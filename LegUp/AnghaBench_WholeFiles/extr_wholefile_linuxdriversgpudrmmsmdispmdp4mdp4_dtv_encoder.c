#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
typedef  int u32 ;
struct msm_drm_private {int /*<<< orphan*/  kms; } ;
struct mdp4_kms {int mmio; int /*<<< orphan*/  base; } ;
struct drm_encoder {int /*<<< orphan*/  crtc; struct drm_device* dev; } ;
struct mdp4_dtv_encoder {int pixclock; int enabled; void* mdp_clk; void* hdmi_clk; struct drm_encoder base; } ;
struct TYPE_2__ {int /*<<< orphan*/  id; } ;
struct drm_display_mode {int clock; int hdisplay; int hsync_start; int hsync_end; int htotal; int vdisplay; int vsync_start; int vsync_end; int vtotal; int flags; int /*<<< orphan*/  type; int /*<<< orphan*/  vrefresh; int /*<<< orphan*/  name; TYPE_1__ base; } ;
struct drm_device {int /*<<< orphan*/  dev; struct msm_drm_private* dev_private; } ;
struct clk {int /*<<< orphan*/  crtc; struct drm_device* dev; } ;
typedef  enum mdp_mixer_stage_id { ____Placeholder_mdp_mixer_stage_id } mdp_mixer_stage_id ;
typedef  enum mdp_chroma_samp_type { ____Placeholder_mdp_chroma_samp_type } mdp_chroma_samp_type ;
typedef  enum mdp_bpc_alpha { ____Placeholder_mdp_bpc_alpha } mdp_bpc_alpha ;
typedef  enum mdp_bpc { ____Placeholder_mdp_bpc } mdp_bpc ;
typedef  enum mdp_alpha_type { ____Placeholder_mdp_alpha_type } mdp_alpha_type ;
typedef  enum mdp4_scale_unit { ____Placeholder_mdp4_scale_unit } mdp4_scale_unit ;
typedef  enum mdp4_pipe { ____Placeholder_mdp4_pipe } mdp4_pipe ;
typedef  enum mdp4_intf { ____Placeholder_mdp4_intf } mdp4_intf ;
typedef  enum mdp4_frame_format { ____Placeholder_mdp4_frame_format } mdp4_frame_format ;
typedef  enum mdp4_dma { ____Placeholder_mdp4_dma } mdp4_dma ;
typedef  enum mdp4_cursor_format { ____Placeholder_mdp4_cursor_format } mdp4_cursor_format ;

/* Variables and functions */
 int BPC8 ; 
 int COND (int,int) ; 
 int /*<<< orphan*/  DBG (char*,unsigned long,...) ; 
#define  DMA_E 137 
#define  DMA_P 136 
#define  DMA_S 135 
 int /*<<< orphan*/  DRM_MODE_ENCODER_TMDS ; 
 int DRM_MODE_FLAG_NHSYNC ; 
 int DRM_MODE_FLAG_NVSYNC ; 
 int ENODEV ; 
 int ENOMEM ; 
 struct drm_encoder* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  INTF_LCDC_DTV ; 
 int INVALID_IDX (int) ; 
 scalar_t__ IS_ERR (void*) ; 
 int MDP4_DISP_INTF_SEL_EXT__MASK ; 
 int MDP4_DISP_INTF_SEL_EXT__SHIFT ; 
 int MDP4_DISP_INTF_SEL_PRIM__MASK ; 
 int MDP4_DISP_INTF_SEL_PRIM__SHIFT ; 
 int MDP4_DISP_INTF_SEL_SEC__MASK ; 
 int MDP4_DISP_INTF_SEL_SEC__SHIFT ; 
 int MDP4_DMA_CONFIG_B_BPC__MASK ; 
 int MDP4_DMA_CONFIG_B_BPC__SHIFT ; 
 int MDP4_DMA_CONFIG_G_BPC__MASK ; 
 int MDP4_DMA_CONFIG_G_BPC__SHIFT ; 
 int MDP4_DMA_CONFIG_PACK__MASK ; 
 int MDP4_DMA_CONFIG_PACK__SHIFT ; 
 int MDP4_DMA_CONFIG_R_BPC__MASK ; 
 int MDP4_DMA_CONFIG_R_BPC__SHIFT ; 
 int MDP4_DMA_CURSOR_BLEND_CONFIG_FORMAT__MASK ; 
 int MDP4_DMA_CURSOR_BLEND_CONFIG_FORMAT__SHIFT ; 
 int MDP4_DMA_CURSOR_POS_X__MASK ; 
 int MDP4_DMA_CURSOR_POS_X__SHIFT ; 
 int MDP4_DMA_CURSOR_POS_Y__MASK ; 
 int MDP4_DMA_CURSOR_POS_Y__SHIFT ; 
 int MDP4_DMA_CURSOR_SIZE_HEIGHT__MASK ; 
 int MDP4_DMA_CURSOR_SIZE_HEIGHT__SHIFT ; 
 int MDP4_DMA_CURSOR_SIZE_WIDTH__MASK ; 
 int MDP4_DMA_CURSOR_SIZE_WIDTH__SHIFT ; 
 int MDP4_DMA_DST_SIZE_HEIGHT__MASK ; 
 int MDP4_DMA_DST_SIZE_HEIGHT__SHIFT ; 
 int MDP4_DMA_DST_SIZE_WIDTH__MASK ; 
 int MDP4_DMA_DST_SIZE_WIDTH__SHIFT ; 
 int MDP4_DMA_SRC_SIZE_HEIGHT__MASK ; 
 int MDP4_DMA_SRC_SIZE_HEIGHT__SHIFT ; 
 int MDP4_DMA_SRC_SIZE_WIDTH__MASK ; 
 int MDP4_DMA_SRC_SIZE_WIDTH__SHIFT ; 
 int MDP4_DSI_ACTIVE_HCTL_END__MASK ; 
 int MDP4_DSI_ACTIVE_HCTL_END__SHIFT ; 
 int MDP4_DSI_ACTIVE_HCTL_START__MASK ; 
 int MDP4_DSI_ACTIVE_HCTL_START__SHIFT ; 
 int MDP4_DSI_DISPLAY_HCTRL_END__MASK ; 
 int MDP4_DSI_DISPLAY_HCTRL_END__SHIFT ; 
 int MDP4_DSI_DISPLAY_HCTRL_START__MASK ; 
 int MDP4_DSI_DISPLAY_HCTRL_START__SHIFT ; 
 int MDP4_DSI_HSYNC_CTRL_PERIOD__MASK ; 
 int MDP4_DSI_HSYNC_CTRL_PERIOD__SHIFT ; 
 int MDP4_DSI_HSYNC_CTRL_PULSEW__MASK ; 
 int MDP4_DSI_HSYNC_CTRL_PULSEW__SHIFT ; 
 int MDP4_DSI_UNDERFLOW_CLR_COLOR__MASK ; 
 int MDP4_DSI_UNDERFLOW_CLR_COLOR__SHIFT ; 
 int MDP4_DTV_ACTIVE_HCTL_END__MASK ; 
 int MDP4_DTV_ACTIVE_HCTL_END__SHIFT ; 
 int MDP4_DTV_ACTIVE_HCTL_START__MASK ; 
 int MDP4_DTV_ACTIVE_HCTL_START__SHIFT ; 
 int MDP4_DTV_CTRL_POLARITY_HSYNC_LOW ; 
 int MDP4_DTV_CTRL_POLARITY_VSYNC_LOW ; 
 int MDP4_DTV_DISPLAY_HCTRL_END__MASK ; 
 int MDP4_DTV_DISPLAY_HCTRL_END__SHIFT ; 
 int MDP4_DTV_DISPLAY_HCTRL_START__MASK ; 
 int MDP4_DTV_DISPLAY_HCTRL_START__SHIFT ; 
 int MDP4_DTV_HSYNC_CTRL_PERIOD__MASK ; 
 int MDP4_DTV_HSYNC_CTRL_PERIOD__SHIFT ; 
 int MDP4_DTV_HSYNC_CTRL_PULSEW__MASK ; 
 int MDP4_DTV_HSYNC_CTRL_PULSEW__SHIFT ; 
 int MDP4_DTV_UNDERFLOW_CLR_COLOR__MASK ; 
 int MDP4_DTV_UNDERFLOW_CLR_COLOR__SHIFT ; 
 int MDP4_DTV_UNDERFLOW_CLR_ENABLE_RECOVERY ; 
 int MDP4_IRQ_DMA_E_DONE ; 
 int MDP4_IRQ_DMA_P_DONE ; 
 int MDP4_IRQ_DMA_S_DONE ; 
 int MDP4_IRQ_EXTERNAL_INTF_UDERRUN ; 
 int /*<<< orphan*/  MDP4_IRQ_EXTERNAL_VSYNC ; 
 int MDP4_IRQ_PRIMARY_INTF_UDERRUN ; 
 int MDP4_LAYERMIXER2_IN_CFG_PIPE0__MASK ; 
 int MDP4_LAYERMIXER2_IN_CFG_PIPE0__SHIFT ; 
 int MDP4_LAYERMIXER2_IN_CFG_PIPE1__MASK ; 
 int MDP4_LAYERMIXER2_IN_CFG_PIPE1__SHIFT ; 
 int MDP4_LAYERMIXER2_IN_CFG_PIPE2__MASK ; 
 int MDP4_LAYERMIXER2_IN_CFG_PIPE2__SHIFT ; 
 int MDP4_LAYERMIXER2_IN_CFG_PIPE3__MASK ; 
 int MDP4_LAYERMIXER2_IN_CFG_PIPE3__SHIFT ; 
 int MDP4_LAYERMIXER2_IN_CFG_PIPE4__MASK ; 
 int MDP4_LAYERMIXER2_IN_CFG_PIPE4__SHIFT ; 
 int MDP4_LAYERMIXER2_IN_CFG_PIPE5__MASK ; 
 int MDP4_LAYERMIXER2_IN_CFG_PIPE5__SHIFT ; 
 int MDP4_LAYERMIXER2_IN_CFG_PIPE6__MASK ; 
 int MDP4_LAYERMIXER2_IN_CFG_PIPE6__SHIFT ; 
 int MDP4_LAYERMIXER2_IN_CFG_PIPE7__MASK ; 
 int MDP4_LAYERMIXER2_IN_CFG_PIPE7__SHIFT ; 
 int MDP4_LAYERMIXER_IN_CFG_PIPE0_MIXER1 ; 
 int MDP4_LAYERMIXER_IN_CFG_PIPE0__MASK ; 
 int MDP4_LAYERMIXER_IN_CFG_PIPE0__SHIFT ; 
 int MDP4_LAYERMIXER_IN_CFG_PIPE1_MIXER1 ; 
 int MDP4_LAYERMIXER_IN_CFG_PIPE1__MASK ; 
 int MDP4_LAYERMIXER_IN_CFG_PIPE1__SHIFT ; 
 int MDP4_LAYERMIXER_IN_CFG_PIPE2_MIXER1 ; 
 int MDP4_LAYERMIXER_IN_CFG_PIPE2__MASK ; 
 int MDP4_LAYERMIXER_IN_CFG_PIPE2__SHIFT ; 
 int MDP4_LAYERMIXER_IN_CFG_PIPE3_MIXER1 ; 
 int MDP4_LAYERMIXER_IN_CFG_PIPE3__MASK ; 
 int MDP4_LAYERMIXER_IN_CFG_PIPE3__SHIFT ; 
 int MDP4_LAYERMIXER_IN_CFG_PIPE4_MIXER1 ; 
 int MDP4_LAYERMIXER_IN_CFG_PIPE4__MASK ; 
 int MDP4_LAYERMIXER_IN_CFG_PIPE4__SHIFT ; 
 int MDP4_LAYERMIXER_IN_CFG_PIPE5_MIXER1 ; 
 int MDP4_LAYERMIXER_IN_CFG_PIPE5__MASK ; 
 int MDP4_LAYERMIXER_IN_CFG_PIPE5__SHIFT ; 
 int MDP4_LAYERMIXER_IN_CFG_PIPE6_MIXER1 ; 
 int MDP4_LAYERMIXER_IN_CFG_PIPE6__MASK ; 
 int MDP4_LAYERMIXER_IN_CFG_PIPE6__SHIFT ; 
 int MDP4_LAYERMIXER_IN_CFG_PIPE7__MASK ; 
 int MDP4_LAYERMIXER_IN_CFG_PIPE7__SHIFT ; 
 int MDP4_LCDC_ACTIVE_HCTL_END__MASK ; 
 int MDP4_LCDC_ACTIVE_HCTL_END__SHIFT ; 
 int MDP4_LCDC_ACTIVE_HCTL_START__MASK ; 
 int MDP4_LCDC_ACTIVE_HCTL_START__SHIFT ; 
 int MDP4_LCDC_DISPLAY_HCTRL_END__MASK ; 
 int MDP4_LCDC_DISPLAY_HCTRL_END__SHIFT ; 
 int MDP4_LCDC_DISPLAY_HCTRL_START__MASK ; 
 int MDP4_LCDC_DISPLAY_HCTRL_START__SHIFT ; 
 int MDP4_LCDC_HSYNC_CTRL_PERIOD__MASK ; 
 int MDP4_LCDC_HSYNC_CTRL_PERIOD__SHIFT ; 
 int MDP4_LCDC_HSYNC_CTRL_PULSEW__MASK ; 
 int MDP4_LCDC_HSYNC_CTRL_PULSEW__SHIFT ; 
 int MDP4_LCDC_LVDS_MUX_CTL_3_TO_0_BIT0__MASK ; 
 int MDP4_LCDC_LVDS_MUX_CTL_3_TO_0_BIT0__SHIFT ; 
 int MDP4_LCDC_LVDS_MUX_CTL_3_TO_0_BIT1__MASK ; 
 int MDP4_LCDC_LVDS_MUX_CTL_3_TO_0_BIT1__SHIFT ; 
 int MDP4_LCDC_LVDS_MUX_CTL_3_TO_0_BIT2__MASK ; 
 int MDP4_LCDC_LVDS_MUX_CTL_3_TO_0_BIT2__SHIFT ; 
 int MDP4_LCDC_LVDS_MUX_CTL_3_TO_0_BIT3__MASK ; 
 int MDP4_LCDC_LVDS_MUX_CTL_3_TO_0_BIT3__SHIFT ; 
 int MDP4_LCDC_LVDS_MUX_CTL_6_TO_4_BIT4__MASK ; 
 int MDP4_LCDC_LVDS_MUX_CTL_6_TO_4_BIT4__SHIFT ; 
 int MDP4_LCDC_LVDS_MUX_CTL_6_TO_4_BIT5__MASK ; 
 int MDP4_LCDC_LVDS_MUX_CTL_6_TO_4_BIT5__SHIFT ; 
 int MDP4_LCDC_LVDS_MUX_CTL_6_TO_4_BIT6__MASK ; 
 int MDP4_LCDC_LVDS_MUX_CTL_6_TO_4_BIT6__SHIFT ; 
 int MDP4_LCDC_UNDERFLOW_CLR_COLOR__MASK ; 
 int MDP4_LCDC_UNDERFLOW_CLR_COLOR__SHIFT ; 
 int MDP4_OVERLAY_FLUSH_OVLP0 ; 
 int MDP4_OVERLAY_FLUSH_OVLP1 ; 
 int MDP4_OVERLAY_FLUSH_RGB1 ; 
 int MDP4_OVERLAY_FLUSH_RGB2 ; 
 int MDP4_OVERLAY_FLUSH_VG1 ; 
 int MDP4_OVERLAY_FLUSH_VG2 ; 
 int MDP4_OVLP_SIZE_HEIGHT__MASK ; 
 int MDP4_OVLP_SIZE_HEIGHT__SHIFT ; 
 int MDP4_OVLP_SIZE_WIDTH__MASK ; 
 int MDP4_OVLP_SIZE_WIDTH__SHIFT ; 
 int MDP4_OVLP_STAGE_OP_BG_ALPHA__MASK ; 
 int MDP4_OVLP_STAGE_OP_BG_ALPHA__SHIFT ; 
 int MDP4_OVLP_STAGE_OP_FG_ALPHA__MASK ; 
 int MDP4_OVLP_STAGE_OP_FG_ALPHA__SHIFT ; 
 int MDP4_PIPE_DST_SIZE_HEIGHT__MASK ; 
 int MDP4_PIPE_DST_SIZE_HEIGHT__SHIFT ; 
 int MDP4_PIPE_DST_SIZE_WIDTH__MASK ; 
 int MDP4_PIPE_DST_SIZE_WIDTH__SHIFT ; 
 int MDP4_PIPE_DST_XY_X__MASK ; 
 int MDP4_PIPE_DST_XY_X__SHIFT ; 
 int MDP4_PIPE_DST_XY_Y__MASK ; 
 int MDP4_PIPE_DST_XY_Y__SHIFT ; 
 int MDP4_PIPE_OP_MODE_SCALEX_UNIT_SEL__MASK ; 
 int MDP4_PIPE_OP_MODE_SCALEX_UNIT_SEL__SHIFT ; 
 int MDP4_PIPE_OP_MODE_SCALEY_UNIT_SEL__MASK ; 
 int MDP4_PIPE_OP_MODE_SCALEY_UNIT_SEL__SHIFT ; 
 int MDP4_PIPE_SRC_FORMAT_A_BPC__MASK ; 
 int MDP4_PIPE_SRC_FORMAT_A_BPC__SHIFT ; 
 int MDP4_PIPE_SRC_FORMAT_B_BPC__MASK ; 
 int MDP4_PIPE_SRC_FORMAT_B_BPC__SHIFT ; 
 int MDP4_PIPE_SRC_FORMAT_CHROMA_SAMP__MASK ; 
 int MDP4_PIPE_SRC_FORMAT_CHROMA_SAMP__SHIFT ; 
 int MDP4_PIPE_SRC_FORMAT_CPP__MASK ; 
 int MDP4_PIPE_SRC_FORMAT_CPP__SHIFT ; 
 int MDP4_PIPE_SRC_FORMAT_FETCH_PLANES__MASK ; 
 int MDP4_PIPE_SRC_FORMAT_FETCH_PLANES__SHIFT ; 
 int MDP4_PIPE_SRC_FORMAT_FRAME_FORMAT__MASK ; 
 int MDP4_PIPE_SRC_FORMAT_FRAME_FORMAT__SHIFT ; 
 int MDP4_PIPE_SRC_FORMAT_G_BPC__MASK ; 
 int MDP4_PIPE_SRC_FORMAT_G_BPC__SHIFT ; 
 int MDP4_PIPE_SRC_FORMAT_R_BPC__MASK ; 
 int MDP4_PIPE_SRC_FORMAT_R_BPC__SHIFT ; 
 int MDP4_PIPE_SRC_FORMAT_UNPACK_COUNT__MASK ; 
 int MDP4_PIPE_SRC_FORMAT_UNPACK_COUNT__SHIFT ; 
 int MDP4_PIPE_SRC_SIZE_HEIGHT__MASK ; 
 int MDP4_PIPE_SRC_SIZE_HEIGHT__SHIFT ; 
 int MDP4_PIPE_SRC_SIZE_WIDTH__MASK ; 
 int MDP4_PIPE_SRC_SIZE_WIDTH__SHIFT ; 
 int MDP4_PIPE_SRC_STRIDE_A_P0__MASK ; 
 int MDP4_PIPE_SRC_STRIDE_A_P0__SHIFT ; 
 int MDP4_PIPE_SRC_STRIDE_A_P1__MASK ; 
 int MDP4_PIPE_SRC_STRIDE_A_P1__SHIFT ; 
 int MDP4_PIPE_SRC_STRIDE_B_P2__MASK ; 
 int MDP4_PIPE_SRC_STRIDE_B_P2__SHIFT ; 
 int MDP4_PIPE_SRC_STRIDE_B_P3__MASK ; 
 int MDP4_PIPE_SRC_STRIDE_B_P3__SHIFT ; 
 int MDP4_PIPE_SRC_UNPACK_ELEM0__MASK ; 
 int MDP4_PIPE_SRC_UNPACK_ELEM0__SHIFT ; 
 int MDP4_PIPE_SRC_UNPACK_ELEM1__MASK ; 
 int MDP4_PIPE_SRC_UNPACK_ELEM1__SHIFT ; 
 int MDP4_PIPE_SRC_UNPACK_ELEM2__MASK ; 
 int MDP4_PIPE_SRC_UNPACK_ELEM2__SHIFT ; 
 int MDP4_PIPE_SRC_UNPACK_ELEM3__MASK ; 
 int MDP4_PIPE_SRC_UNPACK_ELEM3__SHIFT ; 
 int MDP4_PIPE_SRC_XY_X__MASK ; 
 int MDP4_PIPE_SRC_XY_X__SHIFT ; 
 int MDP4_PIPE_SRC_XY_Y__MASK ; 
 int MDP4_PIPE_SRC_XY_Y__SHIFT ; 
 int MDP4_PIPE_SSTILE_FRAME_SIZE_HEIGHT__MASK ; 
 int MDP4_PIPE_SSTILE_FRAME_SIZE_HEIGHT__SHIFT ; 
 int MDP4_PIPE_SSTILE_FRAME_SIZE_WIDTH__MASK ; 
 int MDP4_PIPE_SSTILE_FRAME_SIZE_WIDTH__SHIFT ; 
 int MDP4_VERSION_MAJOR__MASK ; 
 int MDP4_VERSION_MAJOR__SHIFT ; 
 int MDP4_VERSION_MINOR__MASK ; 
 int MDP4_VERSION_MINOR__SHIFT ; 
 int MDP_PIPE_CAP_CSC ; 
 int MDP_PIPE_CAP_HFLIP ; 
 int MDP_PIPE_CAP_SCALE ; 
 int MDP_PIPE_CAP_VFLIP ; 
 int PTR_ERR (void*) ; 
 int REG_MDP4_DTV_ACTIVE_HCTL ; 
 int REG_MDP4_DTV_ACTIVE_VEND ; 
 int REG_MDP4_DTV_ACTIVE_VSTART ; 
 int REG_MDP4_DTV_BORDER_CLR ; 
 int REG_MDP4_DTV_CTRL_POLARITY ; 
 int REG_MDP4_DTV_DISPLAY_HCTRL ; 
 int REG_MDP4_DTV_DISPLAY_VEND ; 
 int REG_MDP4_DTV_DISPLAY_VSTART ; 
 int REG_MDP4_DTV_ENABLE ; 
 int REG_MDP4_DTV_HSYNC_CTRL ; 
 int REG_MDP4_DTV_HSYNC_SKEW ; 
 int REG_MDP4_DTV_UNDERFLOW_CLR ; 
 int REG_MDP4_DTV_VSYNC_LEN ; 
 int REG_MDP4_DTV_VSYNC_PERIOD ; 
#define  RGB1 134 
#define  RGB2 133 
#define  RGB3 132 
#define  VG1 131 
#define  VG2 130 
#define  VG3 129 
#define  VG4 128 
 int /*<<< orphan*/  WARN (int,char*) ; 
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  clk_disable_unprepare (void*) ; 
 int clk_prepare_enable (void*) ; 
 long clk_round_rate (void*,unsigned long) ; 
 int clk_set_rate (void*,unsigned long) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,...) ; 
 void* devm_clk_get (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  drm_encoder_cleanup (struct drm_encoder*) ; 
 int /*<<< orphan*/  drm_encoder_helper_add (struct drm_encoder*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  drm_encoder_init (struct drm_device*,struct drm_encoder*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct mdp4_dtv_encoder*) ; 
 struct mdp4_dtv_encoder* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mdp4_crtc_set_config (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mdp4_crtc_set_intf (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mdp4_dtv_encoder_funcs ; 
 int /*<<< orphan*/  mdp4_dtv_encoder_helper_funcs ; 
 int /*<<< orphan*/  mdp_irq_wait (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int msm_readl (int) ; 
 int /*<<< orphan*/  msm_writel (int,int) ; 
 struct mdp4_dtv_encoder* to_mdp4_dtv_encoder (struct drm_encoder*) ; 
 struct mdp4_kms* to_mdp4_kms (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  to_mdp_kms (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline uint32_t MDP4_VERSION_MINOR(uint32_t val)
{
	return ((val) << MDP4_VERSION_MINOR__SHIFT) & MDP4_VERSION_MINOR__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_VERSION_MAJOR(uint32_t val)
{
	return ((val) << MDP4_VERSION_MAJOR__SHIFT) & MDP4_VERSION_MAJOR__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_DISP_INTF_SEL_PRIM(enum mdp4_intf val)
{
	return ((val) << MDP4_DISP_INTF_SEL_PRIM__SHIFT) & MDP4_DISP_INTF_SEL_PRIM__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_DISP_INTF_SEL_SEC(enum mdp4_intf val)
{
	return ((val) << MDP4_DISP_INTF_SEL_SEC__SHIFT) & MDP4_DISP_INTF_SEL_SEC__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_DISP_INTF_SEL_EXT(enum mdp4_intf val)
{
	return ((val) << MDP4_DISP_INTF_SEL_EXT__SHIFT) & MDP4_DISP_INTF_SEL_EXT__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_LAYERMIXER2_IN_CFG_PIPE0(enum mdp_mixer_stage_id val)
{
	return ((val) << MDP4_LAYERMIXER2_IN_CFG_PIPE0__SHIFT) & MDP4_LAYERMIXER2_IN_CFG_PIPE0__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_LAYERMIXER2_IN_CFG_PIPE1(enum mdp_mixer_stage_id val)
{
	return ((val) << MDP4_LAYERMIXER2_IN_CFG_PIPE1__SHIFT) & MDP4_LAYERMIXER2_IN_CFG_PIPE1__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_LAYERMIXER2_IN_CFG_PIPE2(enum mdp_mixer_stage_id val)
{
	return ((val) << MDP4_LAYERMIXER2_IN_CFG_PIPE2__SHIFT) & MDP4_LAYERMIXER2_IN_CFG_PIPE2__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_LAYERMIXER2_IN_CFG_PIPE3(enum mdp_mixer_stage_id val)
{
	return ((val) << MDP4_LAYERMIXER2_IN_CFG_PIPE3__SHIFT) & MDP4_LAYERMIXER2_IN_CFG_PIPE3__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_LAYERMIXER2_IN_CFG_PIPE4(enum mdp_mixer_stage_id val)
{
	return ((val) << MDP4_LAYERMIXER2_IN_CFG_PIPE4__SHIFT) & MDP4_LAYERMIXER2_IN_CFG_PIPE4__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_LAYERMIXER2_IN_CFG_PIPE5(enum mdp_mixer_stage_id val)
{
	return ((val) << MDP4_LAYERMIXER2_IN_CFG_PIPE5__SHIFT) & MDP4_LAYERMIXER2_IN_CFG_PIPE5__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_LAYERMIXER2_IN_CFG_PIPE6(enum mdp_mixer_stage_id val)
{
	return ((val) << MDP4_LAYERMIXER2_IN_CFG_PIPE6__SHIFT) & MDP4_LAYERMIXER2_IN_CFG_PIPE6__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_LAYERMIXER2_IN_CFG_PIPE7(enum mdp_mixer_stage_id val)
{
	return ((val) << MDP4_LAYERMIXER2_IN_CFG_PIPE7__SHIFT) & MDP4_LAYERMIXER2_IN_CFG_PIPE7__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_LAYERMIXER_IN_CFG_PIPE0(enum mdp_mixer_stage_id val)
{
	return ((val) << MDP4_LAYERMIXER_IN_CFG_PIPE0__SHIFT) & MDP4_LAYERMIXER_IN_CFG_PIPE0__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_LAYERMIXER_IN_CFG_PIPE1(enum mdp_mixer_stage_id val)
{
	return ((val) << MDP4_LAYERMIXER_IN_CFG_PIPE1__SHIFT) & MDP4_LAYERMIXER_IN_CFG_PIPE1__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_LAYERMIXER_IN_CFG_PIPE2(enum mdp_mixer_stage_id val)
{
	return ((val) << MDP4_LAYERMIXER_IN_CFG_PIPE2__SHIFT) & MDP4_LAYERMIXER_IN_CFG_PIPE2__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_LAYERMIXER_IN_CFG_PIPE3(enum mdp_mixer_stage_id val)
{
	return ((val) << MDP4_LAYERMIXER_IN_CFG_PIPE3__SHIFT) & MDP4_LAYERMIXER_IN_CFG_PIPE3__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_LAYERMIXER_IN_CFG_PIPE4(enum mdp_mixer_stage_id val)
{
	return ((val) << MDP4_LAYERMIXER_IN_CFG_PIPE4__SHIFT) & MDP4_LAYERMIXER_IN_CFG_PIPE4__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_LAYERMIXER_IN_CFG_PIPE5(enum mdp_mixer_stage_id val)
{
	return ((val) << MDP4_LAYERMIXER_IN_CFG_PIPE5__SHIFT) & MDP4_LAYERMIXER_IN_CFG_PIPE5__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_LAYERMIXER_IN_CFG_PIPE6(enum mdp_mixer_stage_id val)
{
	return ((val) << MDP4_LAYERMIXER_IN_CFG_PIPE6__SHIFT) & MDP4_LAYERMIXER_IN_CFG_PIPE6__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_LAYERMIXER_IN_CFG_PIPE7(enum mdp_mixer_stage_id val)
{
	return ((val) << MDP4_LAYERMIXER_IN_CFG_PIPE7__SHIFT) & MDP4_LAYERMIXER_IN_CFG_PIPE7__MASK;
}

__attribute__((used)) static inline uint32_t __offset_OVLP(uint32_t idx)
{
	switch (idx) {
		case 0: return 0x00010000;
		case 1: return 0x00018000;
		case 2: return 0x00088000;
		default: return INVALID_IDX(idx);
	}
}

__attribute__((used)) static inline uint32_t REG_MDP4_OVLP(uint32_t i0) { return 0x00000000 + __offset_OVLP(i0); }

__attribute__((used)) static inline uint32_t REG_MDP4_OVLP_CFG(uint32_t i0) { return 0x00000004 + __offset_OVLP(i0); }

__attribute__((used)) static inline uint32_t REG_MDP4_OVLP_SIZE(uint32_t i0) { return 0x00000008 + __offset_OVLP(i0); }

__attribute__((used)) static inline uint32_t MDP4_OVLP_SIZE_HEIGHT(uint32_t val)
{
	return ((val) << MDP4_OVLP_SIZE_HEIGHT__SHIFT) & MDP4_OVLP_SIZE_HEIGHT__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_OVLP_SIZE_WIDTH(uint32_t val)
{
	return ((val) << MDP4_OVLP_SIZE_WIDTH__SHIFT) & MDP4_OVLP_SIZE_WIDTH__MASK;
}

__attribute__((used)) static inline uint32_t REG_MDP4_OVLP_BASE(uint32_t i0) { return 0x0000000c + __offset_OVLP(i0); }

__attribute__((used)) static inline uint32_t REG_MDP4_OVLP_STRIDE(uint32_t i0) { return 0x00000010 + __offset_OVLP(i0); }

__attribute__((used)) static inline uint32_t REG_MDP4_OVLP_OPMODE(uint32_t i0) { return 0x00000014 + __offset_OVLP(i0); }

__attribute__((used)) static inline uint32_t __offset_STAGE(uint32_t idx)
{
	switch (idx) {
		case 0: return 0x00000104;
		case 1: return 0x00000124;
		case 2: return 0x00000144;
		case 3: return 0x00000160;
		default: return INVALID_IDX(idx);
	}
}

__attribute__((used)) static inline uint32_t REG_MDP4_OVLP_STAGE(uint32_t i0, uint32_t i1) { return 0x00000000 + __offset_OVLP(i0) + __offset_STAGE(i1); }

__attribute__((used)) static inline uint32_t REG_MDP4_OVLP_STAGE_OP(uint32_t i0, uint32_t i1) { return 0x00000000 + __offset_OVLP(i0) + __offset_STAGE(i1); }

__attribute__((used)) static inline uint32_t MDP4_OVLP_STAGE_OP_FG_ALPHA(enum mdp_alpha_type val)
{
	return ((val) << MDP4_OVLP_STAGE_OP_FG_ALPHA__SHIFT) & MDP4_OVLP_STAGE_OP_FG_ALPHA__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_OVLP_STAGE_OP_BG_ALPHA(enum mdp_alpha_type val)
{
	return ((val) << MDP4_OVLP_STAGE_OP_BG_ALPHA__SHIFT) & MDP4_OVLP_STAGE_OP_BG_ALPHA__MASK;
}

__attribute__((used)) static inline uint32_t REG_MDP4_OVLP_STAGE_FG_ALPHA(uint32_t i0, uint32_t i1) { return 0x00000004 + __offset_OVLP(i0) + __offset_STAGE(i1); }

__attribute__((used)) static inline uint32_t REG_MDP4_OVLP_STAGE_BG_ALPHA(uint32_t i0, uint32_t i1) { return 0x00000008 + __offset_OVLP(i0) + __offset_STAGE(i1); }

__attribute__((used)) static inline uint32_t REG_MDP4_OVLP_STAGE_TRANSP_LOW0(uint32_t i0, uint32_t i1) { return 0x0000000c + __offset_OVLP(i0) + __offset_STAGE(i1); }

__attribute__((used)) static inline uint32_t REG_MDP4_OVLP_STAGE_TRANSP_LOW1(uint32_t i0, uint32_t i1) { return 0x00000010 + __offset_OVLP(i0) + __offset_STAGE(i1); }

__attribute__((used)) static inline uint32_t REG_MDP4_OVLP_STAGE_TRANSP_HIGH0(uint32_t i0, uint32_t i1) { return 0x00000014 + __offset_OVLP(i0) + __offset_STAGE(i1); }

__attribute__((used)) static inline uint32_t REG_MDP4_OVLP_STAGE_TRANSP_HIGH1(uint32_t i0, uint32_t i1) { return 0x00000018 + __offset_OVLP(i0) + __offset_STAGE(i1); }

__attribute__((used)) static inline uint32_t __offset_STAGE_CO3(uint32_t idx)
{
	switch (idx) {
		case 0: return 0x00001004;
		case 1: return 0x00001404;
		case 2: return 0x00001804;
		case 3: return 0x00001b84;
		default: return INVALID_IDX(idx);
	}
}

__attribute__((used)) static inline uint32_t REG_MDP4_OVLP_STAGE_CO3(uint32_t i0, uint32_t i1) { return 0x00000000 + __offset_OVLP(i0) + __offset_STAGE_CO3(i1); }

__attribute__((used)) static inline uint32_t REG_MDP4_OVLP_STAGE_CO3_SEL(uint32_t i0, uint32_t i1) { return 0x00000000 + __offset_OVLP(i0) + __offset_STAGE_CO3(i1); }

__attribute__((used)) static inline uint32_t REG_MDP4_OVLP_TRANSP_LOW0(uint32_t i0) { return 0x00000180 + __offset_OVLP(i0); }

__attribute__((used)) static inline uint32_t REG_MDP4_OVLP_TRANSP_LOW1(uint32_t i0) { return 0x00000184 + __offset_OVLP(i0); }

__attribute__((used)) static inline uint32_t REG_MDP4_OVLP_TRANSP_HIGH0(uint32_t i0) { return 0x00000188 + __offset_OVLP(i0); }

__attribute__((used)) static inline uint32_t REG_MDP4_OVLP_TRANSP_HIGH1(uint32_t i0) { return 0x0000018c + __offset_OVLP(i0); }

__attribute__((used)) static inline uint32_t REG_MDP4_OVLP_CSC_CONFIG(uint32_t i0) { return 0x00000200 + __offset_OVLP(i0); }

__attribute__((used)) static inline uint32_t REG_MDP4_OVLP_CSC(uint32_t i0) { return 0x00002000 + __offset_OVLP(i0); }

__attribute__((used)) static inline uint32_t REG_MDP4_OVLP_CSC_MV(uint32_t i0, uint32_t i1) { return 0x00002400 + __offset_OVLP(i0) + 0x4*i1; }

__attribute__((used)) static inline uint32_t REG_MDP4_OVLP_CSC_MV_VAL(uint32_t i0, uint32_t i1) { return 0x00002400 + __offset_OVLP(i0) + 0x4*i1; }

__attribute__((used)) static inline uint32_t REG_MDP4_OVLP_CSC_PRE_BV(uint32_t i0, uint32_t i1) { return 0x00002500 + __offset_OVLP(i0) + 0x4*i1; }

__attribute__((used)) static inline uint32_t REG_MDP4_OVLP_CSC_PRE_BV_VAL(uint32_t i0, uint32_t i1) { return 0x00002500 + __offset_OVLP(i0) + 0x4*i1; }

__attribute__((used)) static inline uint32_t REG_MDP4_OVLP_CSC_POST_BV(uint32_t i0, uint32_t i1) { return 0x00002580 + __offset_OVLP(i0) + 0x4*i1; }

__attribute__((used)) static inline uint32_t REG_MDP4_OVLP_CSC_POST_BV_VAL(uint32_t i0, uint32_t i1) { return 0x00002580 + __offset_OVLP(i0) + 0x4*i1; }

__attribute__((used)) static inline uint32_t REG_MDP4_OVLP_CSC_PRE_LV(uint32_t i0, uint32_t i1) { return 0x00002600 + __offset_OVLP(i0) + 0x4*i1; }

__attribute__((used)) static inline uint32_t REG_MDP4_OVLP_CSC_PRE_LV_VAL(uint32_t i0, uint32_t i1) { return 0x00002600 + __offset_OVLP(i0) + 0x4*i1; }

__attribute__((used)) static inline uint32_t REG_MDP4_OVLP_CSC_POST_LV(uint32_t i0, uint32_t i1) { return 0x00002680 + __offset_OVLP(i0) + 0x4*i1; }

__attribute__((used)) static inline uint32_t REG_MDP4_OVLP_CSC_POST_LV_VAL(uint32_t i0, uint32_t i1) { return 0x00002680 + __offset_OVLP(i0) + 0x4*i1; }

__attribute__((used)) static inline uint32_t REG_MDP4_LUTN(uint32_t i0) { return 0x00094800 + 0x400*i0; }

__attribute__((used)) static inline uint32_t REG_MDP4_LUTN_LUT(uint32_t i0, uint32_t i1) { return 0x00094800 + 0x400*i0 + 0x4*i1; }

__attribute__((used)) static inline uint32_t REG_MDP4_LUTN_LUT_VAL(uint32_t i0, uint32_t i1) { return 0x00094800 + 0x400*i0 + 0x4*i1; }

__attribute__((used)) static inline uint32_t REG_MDP4_DMA_E_QUANT(uint32_t i0) { return 0x000b0070 + 0x4*i0; }

__attribute__((used)) static inline uint32_t __offset_DMA(enum mdp4_dma idx)
{
	switch (idx) {
		case DMA_P: return 0x00090000;
		case DMA_S: return 0x000a0000;
		case DMA_E: return 0x000b0000;
		default: return INVALID_IDX(idx);
	}
}

__attribute__((used)) static inline uint32_t REG_MDP4_DMA(enum mdp4_dma i0) { return 0x00000000 + __offset_DMA(i0); }

__attribute__((used)) static inline uint32_t REG_MDP4_DMA_CONFIG(enum mdp4_dma i0) { return 0x00000000 + __offset_DMA(i0); }

__attribute__((used)) static inline uint32_t MDP4_DMA_CONFIG_G_BPC(enum mdp_bpc val)
{
	return ((val) << MDP4_DMA_CONFIG_G_BPC__SHIFT) & MDP4_DMA_CONFIG_G_BPC__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_DMA_CONFIG_B_BPC(enum mdp_bpc val)
{
	return ((val) << MDP4_DMA_CONFIG_B_BPC__SHIFT) & MDP4_DMA_CONFIG_B_BPC__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_DMA_CONFIG_R_BPC(enum mdp_bpc val)
{
	return ((val) << MDP4_DMA_CONFIG_R_BPC__SHIFT) & MDP4_DMA_CONFIG_R_BPC__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_DMA_CONFIG_PACK(uint32_t val)
{
	return ((val) << MDP4_DMA_CONFIG_PACK__SHIFT) & MDP4_DMA_CONFIG_PACK__MASK;
}

__attribute__((used)) static inline uint32_t REG_MDP4_DMA_SRC_SIZE(enum mdp4_dma i0) { return 0x00000004 + __offset_DMA(i0); }

__attribute__((used)) static inline uint32_t MDP4_DMA_SRC_SIZE_HEIGHT(uint32_t val)
{
	return ((val) << MDP4_DMA_SRC_SIZE_HEIGHT__SHIFT) & MDP4_DMA_SRC_SIZE_HEIGHT__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_DMA_SRC_SIZE_WIDTH(uint32_t val)
{
	return ((val) << MDP4_DMA_SRC_SIZE_WIDTH__SHIFT) & MDP4_DMA_SRC_SIZE_WIDTH__MASK;
}

__attribute__((used)) static inline uint32_t REG_MDP4_DMA_SRC_BASE(enum mdp4_dma i0) { return 0x00000008 + __offset_DMA(i0); }

__attribute__((used)) static inline uint32_t REG_MDP4_DMA_SRC_STRIDE(enum mdp4_dma i0) { return 0x0000000c + __offset_DMA(i0); }

__attribute__((used)) static inline uint32_t REG_MDP4_DMA_DST_SIZE(enum mdp4_dma i0) { return 0x00000010 + __offset_DMA(i0); }

__attribute__((used)) static inline uint32_t MDP4_DMA_DST_SIZE_HEIGHT(uint32_t val)
{
	return ((val) << MDP4_DMA_DST_SIZE_HEIGHT__SHIFT) & MDP4_DMA_DST_SIZE_HEIGHT__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_DMA_DST_SIZE_WIDTH(uint32_t val)
{
	return ((val) << MDP4_DMA_DST_SIZE_WIDTH__SHIFT) & MDP4_DMA_DST_SIZE_WIDTH__MASK;
}

__attribute__((used)) static inline uint32_t REG_MDP4_DMA_CURSOR_SIZE(enum mdp4_dma i0) { return 0x00000044 + __offset_DMA(i0); }

__attribute__((used)) static inline uint32_t MDP4_DMA_CURSOR_SIZE_WIDTH(uint32_t val)
{
	return ((val) << MDP4_DMA_CURSOR_SIZE_WIDTH__SHIFT) & MDP4_DMA_CURSOR_SIZE_WIDTH__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_DMA_CURSOR_SIZE_HEIGHT(uint32_t val)
{
	return ((val) << MDP4_DMA_CURSOR_SIZE_HEIGHT__SHIFT) & MDP4_DMA_CURSOR_SIZE_HEIGHT__MASK;
}

__attribute__((used)) static inline uint32_t REG_MDP4_DMA_CURSOR_BASE(enum mdp4_dma i0) { return 0x00000048 + __offset_DMA(i0); }

__attribute__((used)) static inline uint32_t REG_MDP4_DMA_CURSOR_POS(enum mdp4_dma i0) { return 0x0000004c + __offset_DMA(i0); }

__attribute__((used)) static inline uint32_t MDP4_DMA_CURSOR_POS_X(uint32_t val)
{
	return ((val) << MDP4_DMA_CURSOR_POS_X__SHIFT) & MDP4_DMA_CURSOR_POS_X__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_DMA_CURSOR_POS_Y(uint32_t val)
{
	return ((val) << MDP4_DMA_CURSOR_POS_Y__SHIFT) & MDP4_DMA_CURSOR_POS_Y__MASK;
}

__attribute__((used)) static inline uint32_t REG_MDP4_DMA_CURSOR_BLEND_CONFIG(enum mdp4_dma i0) { return 0x00000060 + __offset_DMA(i0); }

__attribute__((used)) static inline uint32_t MDP4_DMA_CURSOR_BLEND_CONFIG_FORMAT(enum mdp4_cursor_format val)
{
	return ((val) << MDP4_DMA_CURSOR_BLEND_CONFIG_FORMAT__SHIFT) & MDP4_DMA_CURSOR_BLEND_CONFIG_FORMAT__MASK;
}

__attribute__((used)) static inline uint32_t REG_MDP4_DMA_CURSOR_BLEND_PARAM(enum mdp4_dma i0) { return 0x00000064 + __offset_DMA(i0); }

__attribute__((used)) static inline uint32_t REG_MDP4_DMA_BLEND_TRANS_LOW(enum mdp4_dma i0) { return 0x00000068 + __offset_DMA(i0); }

__attribute__((used)) static inline uint32_t REG_MDP4_DMA_BLEND_TRANS_HIGH(enum mdp4_dma i0) { return 0x0000006c + __offset_DMA(i0); }

__attribute__((used)) static inline uint32_t REG_MDP4_DMA_FETCH_CONFIG(enum mdp4_dma i0) { return 0x00001004 + __offset_DMA(i0); }

__attribute__((used)) static inline uint32_t REG_MDP4_DMA_CSC(enum mdp4_dma i0) { return 0x00003000 + __offset_DMA(i0); }

__attribute__((used)) static inline uint32_t REG_MDP4_DMA_CSC_MV(enum mdp4_dma i0, uint32_t i1) { return 0x00003400 + __offset_DMA(i0) + 0x4*i1; }

__attribute__((used)) static inline uint32_t REG_MDP4_DMA_CSC_MV_VAL(enum mdp4_dma i0, uint32_t i1) { return 0x00003400 + __offset_DMA(i0) + 0x4*i1; }

__attribute__((used)) static inline uint32_t REG_MDP4_DMA_CSC_PRE_BV(enum mdp4_dma i0, uint32_t i1) { return 0x00003500 + __offset_DMA(i0) + 0x4*i1; }

__attribute__((used)) static inline uint32_t REG_MDP4_DMA_CSC_PRE_BV_VAL(enum mdp4_dma i0, uint32_t i1) { return 0x00003500 + __offset_DMA(i0) + 0x4*i1; }

__attribute__((used)) static inline uint32_t REG_MDP4_DMA_CSC_POST_BV(enum mdp4_dma i0, uint32_t i1) { return 0x00003580 + __offset_DMA(i0) + 0x4*i1; }

__attribute__((used)) static inline uint32_t REG_MDP4_DMA_CSC_POST_BV_VAL(enum mdp4_dma i0, uint32_t i1) { return 0x00003580 + __offset_DMA(i0) + 0x4*i1; }

__attribute__((used)) static inline uint32_t REG_MDP4_DMA_CSC_PRE_LV(enum mdp4_dma i0, uint32_t i1) { return 0x00003600 + __offset_DMA(i0) + 0x4*i1; }

__attribute__((used)) static inline uint32_t REG_MDP4_DMA_CSC_PRE_LV_VAL(enum mdp4_dma i0, uint32_t i1) { return 0x00003600 + __offset_DMA(i0) + 0x4*i1; }

__attribute__((used)) static inline uint32_t REG_MDP4_DMA_CSC_POST_LV(enum mdp4_dma i0, uint32_t i1) { return 0x00003680 + __offset_DMA(i0) + 0x4*i1; }

__attribute__((used)) static inline uint32_t REG_MDP4_DMA_CSC_POST_LV_VAL(enum mdp4_dma i0, uint32_t i1) { return 0x00003680 + __offset_DMA(i0) + 0x4*i1; }

__attribute__((used)) static inline uint32_t REG_MDP4_PIPE(enum mdp4_pipe i0) { return 0x00020000 + 0x10000*i0; }

__attribute__((used)) static inline uint32_t REG_MDP4_PIPE_SRC_SIZE(enum mdp4_pipe i0) { return 0x00020000 + 0x10000*i0; }

__attribute__((used)) static inline uint32_t MDP4_PIPE_SRC_SIZE_HEIGHT(uint32_t val)
{
	return ((val) << MDP4_PIPE_SRC_SIZE_HEIGHT__SHIFT) & MDP4_PIPE_SRC_SIZE_HEIGHT__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_PIPE_SRC_SIZE_WIDTH(uint32_t val)
{
	return ((val) << MDP4_PIPE_SRC_SIZE_WIDTH__SHIFT) & MDP4_PIPE_SRC_SIZE_WIDTH__MASK;
}

__attribute__((used)) static inline uint32_t REG_MDP4_PIPE_SRC_XY(enum mdp4_pipe i0) { return 0x00020004 + 0x10000*i0; }

__attribute__((used)) static inline uint32_t MDP4_PIPE_SRC_XY_Y(uint32_t val)
{
	return ((val) << MDP4_PIPE_SRC_XY_Y__SHIFT) & MDP4_PIPE_SRC_XY_Y__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_PIPE_SRC_XY_X(uint32_t val)
{
	return ((val) << MDP4_PIPE_SRC_XY_X__SHIFT) & MDP4_PIPE_SRC_XY_X__MASK;
}

__attribute__((used)) static inline uint32_t REG_MDP4_PIPE_DST_SIZE(enum mdp4_pipe i0) { return 0x00020008 + 0x10000*i0; }

__attribute__((used)) static inline uint32_t MDP4_PIPE_DST_SIZE_HEIGHT(uint32_t val)
{
	return ((val) << MDP4_PIPE_DST_SIZE_HEIGHT__SHIFT) & MDP4_PIPE_DST_SIZE_HEIGHT__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_PIPE_DST_SIZE_WIDTH(uint32_t val)
{
	return ((val) << MDP4_PIPE_DST_SIZE_WIDTH__SHIFT) & MDP4_PIPE_DST_SIZE_WIDTH__MASK;
}

__attribute__((used)) static inline uint32_t REG_MDP4_PIPE_DST_XY(enum mdp4_pipe i0) { return 0x0002000c + 0x10000*i0; }

__attribute__((used)) static inline uint32_t MDP4_PIPE_DST_XY_Y(uint32_t val)
{
	return ((val) << MDP4_PIPE_DST_XY_Y__SHIFT) & MDP4_PIPE_DST_XY_Y__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_PIPE_DST_XY_X(uint32_t val)
{
	return ((val) << MDP4_PIPE_DST_XY_X__SHIFT) & MDP4_PIPE_DST_XY_X__MASK;
}

__attribute__((used)) static inline uint32_t REG_MDP4_PIPE_SRCP0_BASE(enum mdp4_pipe i0) { return 0x00020010 + 0x10000*i0; }

__attribute__((used)) static inline uint32_t REG_MDP4_PIPE_SRCP1_BASE(enum mdp4_pipe i0) { return 0x00020014 + 0x10000*i0; }

__attribute__((used)) static inline uint32_t REG_MDP4_PIPE_SRCP2_BASE(enum mdp4_pipe i0) { return 0x00020018 + 0x10000*i0; }

__attribute__((used)) static inline uint32_t REG_MDP4_PIPE_SRCP3_BASE(enum mdp4_pipe i0) { return 0x0002001c + 0x10000*i0; }

__attribute__((used)) static inline uint32_t REG_MDP4_PIPE_SRC_STRIDE_A(enum mdp4_pipe i0) { return 0x00020040 + 0x10000*i0; }

__attribute__((used)) static inline uint32_t MDP4_PIPE_SRC_STRIDE_A_P0(uint32_t val)
{
	return ((val) << MDP4_PIPE_SRC_STRIDE_A_P0__SHIFT) & MDP4_PIPE_SRC_STRIDE_A_P0__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_PIPE_SRC_STRIDE_A_P1(uint32_t val)
{
	return ((val) << MDP4_PIPE_SRC_STRIDE_A_P1__SHIFT) & MDP4_PIPE_SRC_STRIDE_A_P1__MASK;
}

__attribute__((used)) static inline uint32_t REG_MDP4_PIPE_SRC_STRIDE_B(enum mdp4_pipe i0) { return 0x00020044 + 0x10000*i0; }

__attribute__((used)) static inline uint32_t MDP4_PIPE_SRC_STRIDE_B_P2(uint32_t val)
{
	return ((val) << MDP4_PIPE_SRC_STRIDE_B_P2__SHIFT) & MDP4_PIPE_SRC_STRIDE_B_P2__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_PIPE_SRC_STRIDE_B_P3(uint32_t val)
{
	return ((val) << MDP4_PIPE_SRC_STRIDE_B_P3__SHIFT) & MDP4_PIPE_SRC_STRIDE_B_P3__MASK;
}

__attribute__((used)) static inline uint32_t REG_MDP4_PIPE_SSTILE_FRAME_SIZE(enum mdp4_pipe i0) { return 0x00020048 + 0x10000*i0; }

__attribute__((used)) static inline uint32_t MDP4_PIPE_SSTILE_FRAME_SIZE_HEIGHT(uint32_t val)
{
	return ((val) << MDP4_PIPE_SSTILE_FRAME_SIZE_HEIGHT__SHIFT) & MDP4_PIPE_SSTILE_FRAME_SIZE_HEIGHT__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_PIPE_SSTILE_FRAME_SIZE_WIDTH(uint32_t val)
{
	return ((val) << MDP4_PIPE_SSTILE_FRAME_SIZE_WIDTH__SHIFT) & MDP4_PIPE_SSTILE_FRAME_SIZE_WIDTH__MASK;
}

__attribute__((used)) static inline uint32_t REG_MDP4_PIPE_SRC_FORMAT(enum mdp4_pipe i0) { return 0x00020050 + 0x10000*i0; }

__attribute__((used)) static inline uint32_t MDP4_PIPE_SRC_FORMAT_G_BPC(enum mdp_bpc val)
{
	return ((val) << MDP4_PIPE_SRC_FORMAT_G_BPC__SHIFT) & MDP4_PIPE_SRC_FORMAT_G_BPC__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_PIPE_SRC_FORMAT_B_BPC(enum mdp_bpc val)
{
	return ((val) << MDP4_PIPE_SRC_FORMAT_B_BPC__SHIFT) & MDP4_PIPE_SRC_FORMAT_B_BPC__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_PIPE_SRC_FORMAT_R_BPC(enum mdp_bpc val)
{
	return ((val) << MDP4_PIPE_SRC_FORMAT_R_BPC__SHIFT) & MDP4_PIPE_SRC_FORMAT_R_BPC__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_PIPE_SRC_FORMAT_A_BPC(enum mdp_bpc_alpha val)
{
	return ((val) << MDP4_PIPE_SRC_FORMAT_A_BPC__SHIFT) & MDP4_PIPE_SRC_FORMAT_A_BPC__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_PIPE_SRC_FORMAT_CPP(uint32_t val)
{
	return ((val) << MDP4_PIPE_SRC_FORMAT_CPP__SHIFT) & MDP4_PIPE_SRC_FORMAT_CPP__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_PIPE_SRC_FORMAT_UNPACK_COUNT(uint32_t val)
{
	return ((val) << MDP4_PIPE_SRC_FORMAT_UNPACK_COUNT__SHIFT) & MDP4_PIPE_SRC_FORMAT_UNPACK_COUNT__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_PIPE_SRC_FORMAT_FETCH_PLANES(uint32_t val)
{
	return ((val) << MDP4_PIPE_SRC_FORMAT_FETCH_PLANES__SHIFT) & MDP4_PIPE_SRC_FORMAT_FETCH_PLANES__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_PIPE_SRC_FORMAT_CHROMA_SAMP(enum mdp_chroma_samp_type val)
{
	return ((val) << MDP4_PIPE_SRC_FORMAT_CHROMA_SAMP__SHIFT) & MDP4_PIPE_SRC_FORMAT_CHROMA_SAMP__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_PIPE_SRC_FORMAT_FRAME_FORMAT(enum mdp4_frame_format val)
{
	return ((val) << MDP4_PIPE_SRC_FORMAT_FRAME_FORMAT__SHIFT) & MDP4_PIPE_SRC_FORMAT_FRAME_FORMAT__MASK;
}

__attribute__((used)) static inline uint32_t REG_MDP4_PIPE_SRC_UNPACK(enum mdp4_pipe i0) { return 0x00020054 + 0x10000*i0; }

__attribute__((used)) static inline uint32_t MDP4_PIPE_SRC_UNPACK_ELEM0(uint32_t val)
{
	return ((val) << MDP4_PIPE_SRC_UNPACK_ELEM0__SHIFT) & MDP4_PIPE_SRC_UNPACK_ELEM0__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_PIPE_SRC_UNPACK_ELEM1(uint32_t val)
{
	return ((val) << MDP4_PIPE_SRC_UNPACK_ELEM1__SHIFT) & MDP4_PIPE_SRC_UNPACK_ELEM1__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_PIPE_SRC_UNPACK_ELEM2(uint32_t val)
{
	return ((val) << MDP4_PIPE_SRC_UNPACK_ELEM2__SHIFT) & MDP4_PIPE_SRC_UNPACK_ELEM2__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_PIPE_SRC_UNPACK_ELEM3(uint32_t val)
{
	return ((val) << MDP4_PIPE_SRC_UNPACK_ELEM3__SHIFT) & MDP4_PIPE_SRC_UNPACK_ELEM3__MASK;
}

__attribute__((used)) static inline uint32_t REG_MDP4_PIPE_OP_MODE(enum mdp4_pipe i0) { return 0x00020058 + 0x10000*i0; }

__attribute__((used)) static inline uint32_t MDP4_PIPE_OP_MODE_SCALEX_UNIT_SEL(enum mdp4_scale_unit val)
{
	return ((val) << MDP4_PIPE_OP_MODE_SCALEX_UNIT_SEL__SHIFT) & MDP4_PIPE_OP_MODE_SCALEX_UNIT_SEL__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_PIPE_OP_MODE_SCALEY_UNIT_SEL(enum mdp4_scale_unit val)
{
	return ((val) << MDP4_PIPE_OP_MODE_SCALEY_UNIT_SEL__SHIFT) & MDP4_PIPE_OP_MODE_SCALEY_UNIT_SEL__MASK;
}

__attribute__((used)) static inline uint32_t REG_MDP4_PIPE_PHASEX_STEP(enum mdp4_pipe i0) { return 0x0002005c + 0x10000*i0; }

__attribute__((used)) static inline uint32_t REG_MDP4_PIPE_PHASEY_STEP(enum mdp4_pipe i0) { return 0x00020060 + 0x10000*i0; }

__attribute__((used)) static inline uint32_t REG_MDP4_PIPE_FETCH_CONFIG(enum mdp4_pipe i0) { return 0x00021004 + 0x10000*i0; }

__attribute__((used)) static inline uint32_t REG_MDP4_PIPE_SOLID_COLOR(enum mdp4_pipe i0) { return 0x00021008 + 0x10000*i0; }

__attribute__((used)) static inline uint32_t REG_MDP4_PIPE_CSC(enum mdp4_pipe i0) { return 0x00024000 + 0x10000*i0; }

__attribute__((used)) static inline uint32_t REG_MDP4_PIPE_CSC_MV(enum mdp4_pipe i0, uint32_t i1) { return 0x00024400 + 0x10000*i0 + 0x4*i1; }

__attribute__((used)) static inline uint32_t REG_MDP4_PIPE_CSC_MV_VAL(enum mdp4_pipe i0, uint32_t i1) { return 0x00024400 + 0x10000*i0 + 0x4*i1; }

__attribute__((used)) static inline uint32_t REG_MDP4_PIPE_CSC_PRE_BV(enum mdp4_pipe i0, uint32_t i1) { return 0x00024500 + 0x10000*i0 + 0x4*i1; }

__attribute__((used)) static inline uint32_t REG_MDP4_PIPE_CSC_PRE_BV_VAL(enum mdp4_pipe i0, uint32_t i1) { return 0x00024500 + 0x10000*i0 + 0x4*i1; }

__attribute__((used)) static inline uint32_t REG_MDP4_PIPE_CSC_POST_BV(enum mdp4_pipe i0, uint32_t i1) { return 0x00024580 + 0x10000*i0 + 0x4*i1; }

__attribute__((used)) static inline uint32_t REG_MDP4_PIPE_CSC_POST_BV_VAL(enum mdp4_pipe i0, uint32_t i1) { return 0x00024580 + 0x10000*i0 + 0x4*i1; }

__attribute__((used)) static inline uint32_t REG_MDP4_PIPE_CSC_PRE_LV(enum mdp4_pipe i0, uint32_t i1) { return 0x00024600 + 0x10000*i0 + 0x4*i1; }

__attribute__((used)) static inline uint32_t REG_MDP4_PIPE_CSC_PRE_LV_VAL(enum mdp4_pipe i0, uint32_t i1) { return 0x00024600 + 0x10000*i0 + 0x4*i1; }

__attribute__((used)) static inline uint32_t REG_MDP4_PIPE_CSC_POST_LV(enum mdp4_pipe i0, uint32_t i1) { return 0x00024680 + 0x10000*i0 + 0x4*i1; }

__attribute__((used)) static inline uint32_t REG_MDP4_PIPE_CSC_POST_LV_VAL(enum mdp4_pipe i0, uint32_t i1) { return 0x00024680 + 0x10000*i0 + 0x4*i1; }

__attribute__((used)) static inline uint32_t MDP4_LCDC_HSYNC_CTRL_PULSEW(uint32_t val)
{
	return ((val) << MDP4_LCDC_HSYNC_CTRL_PULSEW__SHIFT) & MDP4_LCDC_HSYNC_CTRL_PULSEW__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_LCDC_HSYNC_CTRL_PERIOD(uint32_t val)
{
	return ((val) << MDP4_LCDC_HSYNC_CTRL_PERIOD__SHIFT) & MDP4_LCDC_HSYNC_CTRL_PERIOD__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_LCDC_DISPLAY_HCTRL_START(uint32_t val)
{
	return ((val) << MDP4_LCDC_DISPLAY_HCTRL_START__SHIFT) & MDP4_LCDC_DISPLAY_HCTRL_START__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_LCDC_DISPLAY_HCTRL_END(uint32_t val)
{
	return ((val) << MDP4_LCDC_DISPLAY_HCTRL_END__SHIFT) & MDP4_LCDC_DISPLAY_HCTRL_END__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_LCDC_ACTIVE_HCTL_START(uint32_t val)
{
	return ((val) << MDP4_LCDC_ACTIVE_HCTL_START__SHIFT) & MDP4_LCDC_ACTIVE_HCTL_START__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_LCDC_ACTIVE_HCTL_END(uint32_t val)
{
	return ((val) << MDP4_LCDC_ACTIVE_HCTL_END__SHIFT) & MDP4_LCDC_ACTIVE_HCTL_END__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_LCDC_UNDERFLOW_CLR_COLOR(uint32_t val)
{
	return ((val) << MDP4_LCDC_UNDERFLOW_CLR_COLOR__SHIFT) & MDP4_LCDC_UNDERFLOW_CLR_COLOR__MASK;
}

__attribute__((used)) static inline uint32_t REG_MDP4_LCDC_LVDS_MUX_CTL(uint32_t i0) { return 0x000c2014 + 0x8*i0; }

__attribute__((used)) static inline uint32_t REG_MDP4_LCDC_LVDS_MUX_CTL_3_TO_0(uint32_t i0) { return 0x000c2014 + 0x8*i0; }

__attribute__((used)) static inline uint32_t MDP4_LCDC_LVDS_MUX_CTL_3_TO_0_BIT0(uint32_t val)
{
	return ((val) << MDP4_LCDC_LVDS_MUX_CTL_3_TO_0_BIT0__SHIFT) & MDP4_LCDC_LVDS_MUX_CTL_3_TO_0_BIT0__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_LCDC_LVDS_MUX_CTL_3_TO_0_BIT1(uint32_t val)
{
	return ((val) << MDP4_LCDC_LVDS_MUX_CTL_3_TO_0_BIT1__SHIFT) & MDP4_LCDC_LVDS_MUX_CTL_3_TO_0_BIT1__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_LCDC_LVDS_MUX_CTL_3_TO_0_BIT2(uint32_t val)
{
	return ((val) << MDP4_LCDC_LVDS_MUX_CTL_3_TO_0_BIT2__SHIFT) & MDP4_LCDC_LVDS_MUX_CTL_3_TO_0_BIT2__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_LCDC_LVDS_MUX_CTL_3_TO_0_BIT3(uint32_t val)
{
	return ((val) << MDP4_LCDC_LVDS_MUX_CTL_3_TO_0_BIT3__SHIFT) & MDP4_LCDC_LVDS_MUX_CTL_3_TO_0_BIT3__MASK;
}

__attribute__((used)) static inline uint32_t REG_MDP4_LCDC_LVDS_MUX_CTL_6_TO_4(uint32_t i0) { return 0x000c2018 + 0x8*i0; }

__attribute__((used)) static inline uint32_t MDP4_LCDC_LVDS_MUX_CTL_6_TO_4_BIT4(uint32_t val)
{
	return ((val) << MDP4_LCDC_LVDS_MUX_CTL_6_TO_4_BIT4__SHIFT) & MDP4_LCDC_LVDS_MUX_CTL_6_TO_4_BIT4__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_LCDC_LVDS_MUX_CTL_6_TO_4_BIT5(uint32_t val)
{
	return ((val) << MDP4_LCDC_LVDS_MUX_CTL_6_TO_4_BIT5__SHIFT) & MDP4_LCDC_LVDS_MUX_CTL_6_TO_4_BIT5__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_LCDC_LVDS_MUX_CTL_6_TO_4_BIT6(uint32_t val)
{
	return ((val) << MDP4_LCDC_LVDS_MUX_CTL_6_TO_4_BIT6__SHIFT) & MDP4_LCDC_LVDS_MUX_CTL_6_TO_4_BIT6__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_DTV_HSYNC_CTRL_PULSEW(uint32_t val)
{
	return ((val) << MDP4_DTV_HSYNC_CTRL_PULSEW__SHIFT) & MDP4_DTV_HSYNC_CTRL_PULSEW__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_DTV_HSYNC_CTRL_PERIOD(uint32_t val)
{
	return ((val) << MDP4_DTV_HSYNC_CTRL_PERIOD__SHIFT) & MDP4_DTV_HSYNC_CTRL_PERIOD__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_DTV_DISPLAY_HCTRL_START(uint32_t val)
{
	return ((val) << MDP4_DTV_DISPLAY_HCTRL_START__SHIFT) & MDP4_DTV_DISPLAY_HCTRL_START__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_DTV_DISPLAY_HCTRL_END(uint32_t val)
{
	return ((val) << MDP4_DTV_DISPLAY_HCTRL_END__SHIFT) & MDP4_DTV_DISPLAY_HCTRL_END__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_DTV_ACTIVE_HCTL_START(uint32_t val)
{
	return ((val) << MDP4_DTV_ACTIVE_HCTL_START__SHIFT) & MDP4_DTV_ACTIVE_HCTL_START__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_DTV_ACTIVE_HCTL_END(uint32_t val)
{
	return ((val) << MDP4_DTV_ACTIVE_HCTL_END__SHIFT) & MDP4_DTV_ACTIVE_HCTL_END__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_DTV_UNDERFLOW_CLR_COLOR(uint32_t val)
{
	return ((val) << MDP4_DTV_UNDERFLOW_CLR_COLOR__SHIFT) & MDP4_DTV_UNDERFLOW_CLR_COLOR__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_DSI_HSYNC_CTRL_PULSEW(uint32_t val)
{
	return ((val) << MDP4_DSI_HSYNC_CTRL_PULSEW__SHIFT) & MDP4_DSI_HSYNC_CTRL_PULSEW__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_DSI_HSYNC_CTRL_PERIOD(uint32_t val)
{
	return ((val) << MDP4_DSI_HSYNC_CTRL_PERIOD__SHIFT) & MDP4_DSI_HSYNC_CTRL_PERIOD__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_DSI_DISPLAY_HCTRL_START(uint32_t val)
{
	return ((val) << MDP4_DSI_DISPLAY_HCTRL_START__SHIFT) & MDP4_DSI_DISPLAY_HCTRL_START__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_DSI_DISPLAY_HCTRL_END(uint32_t val)
{
	return ((val) << MDP4_DSI_DISPLAY_HCTRL_END__SHIFT) & MDP4_DSI_DISPLAY_HCTRL_END__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_DSI_ACTIVE_HCTL_START(uint32_t val)
{
	return ((val) << MDP4_DSI_ACTIVE_HCTL_START__SHIFT) & MDP4_DSI_ACTIVE_HCTL_START__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_DSI_ACTIVE_HCTL_END(uint32_t val)
{
	return ((val) << MDP4_DSI_ACTIVE_HCTL_END__SHIFT) & MDP4_DSI_ACTIVE_HCTL_END__MASK;
}

__attribute__((used)) static inline uint32_t MDP4_DSI_UNDERFLOW_CLR_COLOR(uint32_t val)
{
	return ((val) << MDP4_DSI_UNDERFLOW_CLR_COLOR__SHIFT) & MDP4_DSI_UNDERFLOW_CLR_COLOR__MASK;
}

__attribute__((used)) static inline void mdp4_write(struct mdp4_kms *mdp4_kms, u32 reg, u32 data)
{
	msm_writel(data, mdp4_kms->mmio + reg);
}

__attribute__((used)) static inline u32 mdp4_read(struct mdp4_kms *mdp4_kms, u32 reg)
{
	return msm_readl(mdp4_kms->mmio + reg);
}

__attribute__((used)) static inline uint32_t pipe2flush(enum mdp4_pipe pipe)
{
	switch (pipe) {
	case VG1:      return MDP4_OVERLAY_FLUSH_VG1;
	case VG2:      return MDP4_OVERLAY_FLUSH_VG2;
	case RGB1:     return MDP4_OVERLAY_FLUSH_RGB1;
	case RGB2:     return MDP4_OVERLAY_FLUSH_RGB2;
	default:       return 0;
	}
}

__attribute__((used)) static inline uint32_t ovlp2flush(int ovlp)
{
	switch (ovlp) {
	case 0:        return MDP4_OVERLAY_FLUSH_OVLP0;
	case 1:        return MDP4_OVERLAY_FLUSH_OVLP1;
	default:       return 0;
	}
}

__attribute__((used)) static inline uint32_t dma2irq(enum mdp4_dma dma)
{
	switch (dma) {
	case DMA_P:    return MDP4_IRQ_DMA_P_DONE;
	case DMA_S:    return MDP4_IRQ_DMA_S_DONE;
	case DMA_E:    return MDP4_IRQ_DMA_E_DONE;
	default:       return 0;
	}
}

__attribute__((used)) static inline uint32_t dma2err(enum mdp4_dma dma)
{
	switch (dma) {
	case DMA_P:    return MDP4_IRQ_PRIMARY_INTF_UDERRUN;
	case DMA_S:    return 0;  // ???
	case DMA_E:    return MDP4_IRQ_EXTERNAL_INTF_UDERRUN;
	default:       return 0;
	}
}

__attribute__((used)) static inline uint32_t mixercfg(uint32_t mixer_cfg, int mixer,
		enum mdp4_pipe pipe, enum mdp_mixer_stage_id stage)
{
	switch (pipe) {
	case VG1:
		mixer_cfg &= ~(MDP4_LAYERMIXER_IN_CFG_PIPE0__MASK |
				MDP4_LAYERMIXER_IN_CFG_PIPE0_MIXER1);
		mixer_cfg |= MDP4_LAYERMIXER_IN_CFG_PIPE0(stage) |
			COND(mixer == 1, MDP4_LAYERMIXER_IN_CFG_PIPE0_MIXER1);
		break;
	case VG2:
		mixer_cfg &= ~(MDP4_LAYERMIXER_IN_CFG_PIPE1__MASK |
				MDP4_LAYERMIXER_IN_CFG_PIPE1_MIXER1);
		mixer_cfg |= MDP4_LAYERMIXER_IN_CFG_PIPE1(stage) |
			COND(mixer == 1, MDP4_LAYERMIXER_IN_CFG_PIPE1_MIXER1);
		break;
	case RGB1:
		mixer_cfg &= ~(MDP4_LAYERMIXER_IN_CFG_PIPE2__MASK |
				MDP4_LAYERMIXER_IN_CFG_PIPE2_MIXER1);
		mixer_cfg |= MDP4_LAYERMIXER_IN_CFG_PIPE2(stage) |
			COND(mixer == 1, MDP4_LAYERMIXER_IN_CFG_PIPE2_MIXER1);
		break;
	case RGB2:
		mixer_cfg &= ~(MDP4_LAYERMIXER_IN_CFG_PIPE3__MASK |
				MDP4_LAYERMIXER_IN_CFG_PIPE3_MIXER1);
		mixer_cfg |= MDP4_LAYERMIXER_IN_CFG_PIPE3(stage) |
			COND(mixer == 1, MDP4_LAYERMIXER_IN_CFG_PIPE3_MIXER1);
		break;
	case RGB3:
		mixer_cfg &= ~(MDP4_LAYERMIXER_IN_CFG_PIPE4__MASK |
				MDP4_LAYERMIXER_IN_CFG_PIPE4_MIXER1);
		mixer_cfg |= MDP4_LAYERMIXER_IN_CFG_PIPE4(stage) |
			COND(mixer == 1, MDP4_LAYERMIXER_IN_CFG_PIPE4_MIXER1);
		break;
	case VG3:
		mixer_cfg &= ~(MDP4_LAYERMIXER_IN_CFG_PIPE5__MASK |
				MDP4_LAYERMIXER_IN_CFG_PIPE5_MIXER1);
		mixer_cfg |= MDP4_LAYERMIXER_IN_CFG_PIPE5(stage) |
			COND(mixer == 1, MDP4_LAYERMIXER_IN_CFG_PIPE5_MIXER1);
		break;
	case VG4:
		mixer_cfg &= ~(MDP4_LAYERMIXER_IN_CFG_PIPE6__MASK |
				MDP4_LAYERMIXER_IN_CFG_PIPE6_MIXER1);
		mixer_cfg |= MDP4_LAYERMIXER_IN_CFG_PIPE6(stage) |
			COND(mixer == 1, MDP4_LAYERMIXER_IN_CFG_PIPE6_MIXER1);
		break;
	default:
		WARN(1, "invalid pipe");
		break;
	}

	return mixer_cfg;
}

__attribute__((used)) static inline uint32_t mdp4_pipe_caps(enum mdp4_pipe pipe)
{
	switch (pipe) {
	case VG1:
	case VG2:
	case VG3:
	case VG4:
		return MDP_PIPE_CAP_HFLIP | MDP_PIPE_CAP_VFLIP |
				MDP_PIPE_CAP_SCALE | MDP_PIPE_CAP_CSC;
	case RGB1:
	case RGB2:
	case RGB3:
		return MDP_PIPE_CAP_SCALE;
	default:
		return 0;
	}
}

__attribute__((used)) static inline struct drm_encoder *mdp4_dsi_encoder_init(struct drm_device *dev)
{
	return ERR_PTR(-ENODEV);
}

__attribute__((used)) static inline struct clk *mpd4_lvds_pll_init(struct drm_device *dev)
{
	return ERR_PTR(-ENODEV);
}

__attribute__((used)) static struct mdp4_kms *get_kms(struct drm_encoder *encoder)
{
	struct msm_drm_private *priv = encoder->dev->dev_private;
	return to_mdp4_kms(to_mdp_kms(priv->kms));
}

__attribute__((used)) static void bs_init(struct mdp4_dtv_encoder *mdp4_dtv_encoder) {}

__attribute__((used)) static void bs_fini(struct mdp4_dtv_encoder *mdp4_dtv_encoder) {}

__attribute__((used)) static void bs_set(struct mdp4_dtv_encoder *mdp4_dtv_encoder, int idx) {}

__attribute__((used)) static void mdp4_dtv_encoder_destroy(struct drm_encoder *encoder)
{
	struct mdp4_dtv_encoder *mdp4_dtv_encoder = to_mdp4_dtv_encoder(encoder);
	bs_fini(mdp4_dtv_encoder);
	drm_encoder_cleanup(encoder);
	kfree(mdp4_dtv_encoder);
}

__attribute__((used)) static void mdp4_dtv_encoder_mode_set(struct drm_encoder *encoder,
		struct drm_display_mode *mode,
		struct drm_display_mode *adjusted_mode)
{
	struct mdp4_dtv_encoder *mdp4_dtv_encoder = to_mdp4_dtv_encoder(encoder);
	struct mdp4_kms *mdp4_kms = get_kms(encoder);
	uint32_t dtv_hsync_skew, vsync_period, vsync_len, ctrl_pol;
	uint32_t display_v_start, display_v_end;
	uint32_t hsync_start_x, hsync_end_x;

	mode = adjusted_mode;

	DBG("set mode: %d:\"%s\" %d %d %d %d %d %d %d %d %d %d 0x%x 0x%x",
			mode->base.id, mode->name,
			mode->vrefresh, mode->clock,
			mode->hdisplay, mode->hsync_start,
			mode->hsync_end, mode->htotal,
			mode->vdisplay, mode->vsync_start,
			mode->vsync_end, mode->vtotal,
			mode->type, mode->flags);

	mdp4_dtv_encoder->pixclock = mode->clock * 1000;

	DBG("pixclock=%lu", mdp4_dtv_encoder->pixclock);

	ctrl_pol = 0;
	if (mode->flags & DRM_MODE_FLAG_NHSYNC)
		ctrl_pol |= MDP4_DTV_CTRL_POLARITY_HSYNC_LOW;
	if (mode->flags & DRM_MODE_FLAG_NVSYNC)
		ctrl_pol |= MDP4_DTV_CTRL_POLARITY_VSYNC_LOW;
	/* probably need to get DATA_EN polarity from panel.. */

	dtv_hsync_skew = 0;  /* get this from panel? */

	hsync_start_x = (mode->htotal - mode->hsync_start);
	hsync_end_x = mode->htotal - (mode->hsync_start - mode->hdisplay) - 1;

	vsync_period = mode->vtotal * mode->htotal;
	vsync_len = (mode->vsync_end - mode->vsync_start) * mode->htotal;
	display_v_start = (mode->vtotal - mode->vsync_start) * mode->htotal + dtv_hsync_skew;
	display_v_end = vsync_period - ((mode->vsync_start - mode->vdisplay) * mode->htotal) + dtv_hsync_skew - 1;

	mdp4_write(mdp4_kms, REG_MDP4_DTV_HSYNC_CTRL,
			MDP4_DTV_HSYNC_CTRL_PULSEW(mode->hsync_end - mode->hsync_start) |
			MDP4_DTV_HSYNC_CTRL_PERIOD(mode->htotal));
	mdp4_write(mdp4_kms, REG_MDP4_DTV_VSYNC_PERIOD, vsync_period);
	mdp4_write(mdp4_kms, REG_MDP4_DTV_VSYNC_LEN, vsync_len);
	mdp4_write(mdp4_kms, REG_MDP4_DTV_DISPLAY_HCTRL,
			MDP4_DTV_DISPLAY_HCTRL_START(hsync_start_x) |
			MDP4_DTV_DISPLAY_HCTRL_END(hsync_end_x));
	mdp4_write(mdp4_kms, REG_MDP4_DTV_DISPLAY_VSTART, display_v_start);
	mdp4_write(mdp4_kms, REG_MDP4_DTV_DISPLAY_VEND, display_v_end);
	mdp4_write(mdp4_kms, REG_MDP4_DTV_BORDER_CLR, 0);
	mdp4_write(mdp4_kms, REG_MDP4_DTV_UNDERFLOW_CLR,
			MDP4_DTV_UNDERFLOW_CLR_ENABLE_RECOVERY |
			MDP4_DTV_UNDERFLOW_CLR_COLOR(0xff));
	mdp4_write(mdp4_kms, REG_MDP4_DTV_HSYNC_SKEW, dtv_hsync_skew);
	mdp4_write(mdp4_kms, REG_MDP4_DTV_CTRL_POLARITY, ctrl_pol);
	mdp4_write(mdp4_kms, REG_MDP4_DTV_ACTIVE_HCTL,
			MDP4_DTV_ACTIVE_HCTL_START(0) |
			MDP4_DTV_ACTIVE_HCTL_END(0));
	mdp4_write(mdp4_kms, REG_MDP4_DTV_ACTIVE_VSTART, 0);
	mdp4_write(mdp4_kms, REG_MDP4_DTV_ACTIVE_VEND, 0);
}

__attribute__((used)) static void mdp4_dtv_encoder_disable(struct drm_encoder *encoder)
{
	struct mdp4_dtv_encoder *mdp4_dtv_encoder = to_mdp4_dtv_encoder(encoder);
	struct mdp4_kms *mdp4_kms = get_kms(encoder);

	if (WARN_ON(!mdp4_dtv_encoder->enabled))
		return;

	mdp4_write(mdp4_kms, REG_MDP4_DTV_ENABLE, 0);

	/*
	 * Wait for a vsync so we know the ENABLE=0 latched before
	 * the (connector) source of the vsync's gets disabled,
	 * otherwise we end up in a funny state if we re-enable
	 * before the disable latches, which results that some of
	 * the settings changes for the new modeset (like new
	 * scanout buffer) don't latch properly..
	 */
	mdp_irq_wait(&mdp4_kms->base, MDP4_IRQ_EXTERNAL_VSYNC);

	clk_disable_unprepare(mdp4_dtv_encoder->hdmi_clk);
	clk_disable_unprepare(mdp4_dtv_encoder->mdp_clk);

	bs_set(mdp4_dtv_encoder, 0);

	mdp4_dtv_encoder->enabled = false;
}

__attribute__((used)) static void mdp4_dtv_encoder_enable(struct drm_encoder *encoder)
{
	struct drm_device *dev = encoder->dev;
	struct mdp4_dtv_encoder *mdp4_dtv_encoder = to_mdp4_dtv_encoder(encoder);
	struct mdp4_kms *mdp4_kms = get_kms(encoder);
	unsigned long pc = mdp4_dtv_encoder->pixclock;
	int ret;

	if (WARN_ON(mdp4_dtv_encoder->enabled))
		return;

	mdp4_crtc_set_config(encoder->crtc,
			MDP4_DMA_CONFIG_R_BPC(BPC8) |
			MDP4_DMA_CONFIG_G_BPC(BPC8) |
			MDP4_DMA_CONFIG_B_BPC(BPC8) |
			MDP4_DMA_CONFIG_PACK(0x21));
	mdp4_crtc_set_intf(encoder->crtc, INTF_LCDC_DTV, 1);

	bs_set(mdp4_dtv_encoder, 1);

	DBG("setting mdp_clk=%lu", pc);

	ret = clk_set_rate(mdp4_dtv_encoder->mdp_clk, pc);
	if (ret)
		dev_err(dev->dev, "failed to set mdp_clk to %lu: %d\n",
			pc, ret);

	ret = clk_prepare_enable(mdp4_dtv_encoder->mdp_clk);
	if (ret)
		dev_err(dev->dev, "failed to enabled mdp_clk: %d\n", ret);

	ret = clk_prepare_enable(mdp4_dtv_encoder->hdmi_clk);
	if (ret)
		dev_err(dev->dev, "failed to enable hdmi_clk: %d\n", ret);

	mdp4_write(mdp4_kms, REG_MDP4_DTV_ENABLE, 1);

	mdp4_dtv_encoder->enabled = true;
}

long mdp4_dtv_round_pixclk(struct drm_encoder *encoder, unsigned long rate)
{
	struct mdp4_dtv_encoder *mdp4_dtv_encoder = to_mdp4_dtv_encoder(encoder);
	return clk_round_rate(mdp4_dtv_encoder->mdp_clk, rate);
}

struct drm_encoder *mdp4_dtv_encoder_init(struct drm_device *dev)
{
	struct drm_encoder *encoder = NULL;
	struct mdp4_dtv_encoder *mdp4_dtv_encoder;
	int ret;

	mdp4_dtv_encoder = kzalloc(sizeof(*mdp4_dtv_encoder), GFP_KERNEL);
	if (!mdp4_dtv_encoder) {
		ret = -ENOMEM;
		goto fail;
	}

	encoder = &mdp4_dtv_encoder->base;

	drm_encoder_init(dev, encoder, &mdp4_dtv_encoder_funcs,
			 DRM_MODE_ENCODER_TMDS, NULL);
	drm_encoder_helper_add(encoder, &mdp4_dtv_encoder_helper_funcs);

	mdp4_dtv_encoder->hdmi_clk = devm_clk_get(dev->dev, "hdmi_clk");
	if (IS_ERR(mdp4_dtv_encoder->hdmi_clk)) {
		dev_err(dev->dev, "failed to get hdmi_clk\n");
		ret = PTR_ERR(mdp4_dtv_encoder->hdmi_clk);
		goto fail;
	}

	mdp4_dtv_encoder->mdp_clk = devm_clk_get(dev->dev, "tv_clk");
	if (IS_ERR(mdp4_dtv_encoder->mdp_clk)) {
		dev_err(dev->dev, "failed to get tv_clk\n");
		ret = PTR_ERR(mdp4_dtv_encoder->mdp_clk);
		goto fail;
	}

	bs_init(mdp4_dtv_encoder);

	return encoder;

fail:
	if (encoder)
		mdp4_dtv_encoder_destroy(encoder);

	return ERR_PTR(ret);
}

