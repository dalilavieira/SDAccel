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
typedef  scalar_t__ u32 ;
struct drm_encoder {scalar_t__ doublescan_allowed; scalar_t__ interlace_allowed; scalar_t__ polled; } ;
struct mdp4_lvds_connector {struct drm_encoder base; struct device_node* panel_node; struct drm_encoder* encoder; struct drm_panel* panel; } ;
struct mdp4_kms {scalar_t__ mmio; } ;
struct drm_panel {TYPE_1__* funcs; } ;
struct drm_display_mode {int clock; } ;
struct drm_device {int dummy; } ;
struct drm_connector {scalar_t__ doublescan_allowed; scalar_t__ interlace_allowed; scalar_t__ polled; } ;
struct device_node {int dummy; } ;
struct clk {scalar_t__ doublescan_allowed; scalar_t__ interlace_allowed; scalar_t__ polled; } ;
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
typedef  enum drm_connector_status { ____Placeholder_drm_connector_status } drm_connector_status ;
struct TYPE_2__ {int (* get_modes ) (struct drm_panel*) ;} ;

/* Variables and functions */
 int COND (int,int) ; 
 int /*<<< orphan*/  DBG (char*,long,long) ; 
#define  DMA_E 137 
#define  DMA_P 136 
#define  DMA_S 135 
 int /*<<< orphan*/  DRM_MODE_CONNECTOR_LVDS ; 
 int /*<<< orphan*/  ENODEV ; 
 int /*<<< orphan*/  ENOMEM ; 
 struct drm_encoder* ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int INVALID_IDX (int) ; 
 scalar_t__ IS_ERR (struct drm_panel*) ; 
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
 int MDP4_IRQ_DMA_E_DONE ; 
 int MDP4_IRQ_DMA_P_DONE ; 
 int MDP4_IRQ_DMA_S_DONE ; 
 int MDP4_IRQ_EXTERNAL_INTF_UDERRUN ; 
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
 int MODE_CLOCK_RANGE ; 
 int MODE_OK ; 
#define  RGB1 134 
#define  RGB2 133 
#define  RGB3 132 
#define  VG1 131 
#define  VG2 130 
#define  VG3 129 
#define  VG4 128 
 int /*<<< orphan*/  WARN (int,char*) ; 
 int connector_status_connected ; 
 int connector_status_disconnected ; 
 int /*<<< orphan*/  drm_connector_attach_encoder (struct drm_encoder*,struct drm_encoder*) ; 
 int /*<<< orphan*/  drm_connector_cleanup (struct drm_encoder*) ; 
 int /*<<< orphan*/  drm_connector_helper_add (struct drm_encoder*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  drm_connector_init (struct drm_device*,struct drm_encoder*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_panel_attach (struct drm_panel*,struct drm_encoder*) ; 
 int /*<<< orphan*/  drm_panel_detach (struct drm_panel*) ; 
 int /*<<< orphan*/  kfree (struct mdp4_lvds_connector*) ; 
 struct mdp4_lvds_connector* kzalloc (int,int /*<<< orphan*/ ) ; 
 long mdp4_lcdc_round_pixclk (struct drm_encoder*,long) ; 
 int /*<<< orphan*/  mdp4_lvds_connector_funcs ; 
 int /*<<< orphan*/  mdp4_lvds_connector_helper_funcs ; 
 scalar_t__ msm_readl (scalar_t__) ; 
 int /*<<< orphan*/  msm_writel (scalar_t__,scalar_t__) ; 
 struct drm_panel* of_drm_find_panel (struct device_node*) ; 
 int stub1 (struct drm_panel*) ; 
 struct mdp4_lvds_connector* to_mdp4_lvds_connector (struct drm_encoder*) ; 

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

__attribute__((used)) static enum drm_connector_status mdp4_lvds_connector_detect(
		struct drm_connector *connector, bool force)
{
	struct mdp4_lvds_connector *mdp4_lvds_connector =
			to_mdp4_lvds_connector(connector);

	if (!mdp4_lvds_connector->panel) {
		mdp4_lvds_connector->panel =
			of_drm_find_panel(mdp4_lvds_connector->panel_node);
		if (IS_ERR(mdp4_lvds_connector->panel))
			mdp4_lvds_connector->panel = NULL;
	}

	return mdp4_lvds_connector->panel ?
			connector_status_connected :
			connector_status_disconnected;
}

__attribute__((used)) static void mdp4_lvds_connector_destroy(struct drm_connector *connector)
{
	struct mdp4_lvds_connector *mdp4_lvds_connector =
			to_mdp4_lvds_connector(connector);

	drm_connector_cleanup(connector);

	kfree(mdp4_lvds_connector);
}

__attribute__((used)) static int mdp4_lvds_connector_get_modes(struct drm_connector *connector)
{
	struct mdp4_lvds_connector *mdp4_lvds_connector =
			to_mdp4_lvds_connector(connector);
	struct drm_panel *panel = mdp4_lvds_connector->panel;
	int ret = 0;

	if (panel) {
		drm_panel_attach(panel, connector);

		ret = panel->funcs->get_modes(panel);

		drm_panel_detach(panel);
	}

	return ret;
}

__attribute__((used)) static int mdp4_lvds_connector_mode_valid(struct drm_connector *connector,
				 struct drm_display_mode *mode)
{
	struct mdp4_lvds_connector *mdp4_lvds_connector =
			to_mdp4_lvds_connector(connector);
	struct drm_encoder *encoder = mdp4_lvds_connector->encoder;
	long actual, requested;

	requested = 1000 * mode->clock;
	actual = mdp4_lcdc_round_pixclk(encoder, requested);

	DBG("requested=%ld, actual=%ld", requested, actual);

	if (actual != requested)
		return MODE_CLOCK_RANGE;

	return MODE_OK;
}

struct drm_connector *mdp4_lvds_connector_init(struct drm_device *dev,
		struct device_node *panel_node, struct drm_encoder *encoder)
{
	struct drm_connector *connector = NULL;
	struct mdp4_lvds_connector *mdp4_lvds_connector;

	mdp4_lvds_connector = kzalloc(sizeof(*mdp4_lvds_connector), GFP_KERNEL);
	if (!mdp4_lvds_connector)
		return ERR_PTR(-ENOMEM);

	mdp4_lvds_connector->encoder = encoder;
	mdp4_lvds_connector->panel_node = panel_node;

	connector = &mdp4_lvds_connector->base;

	drm_connector_init(dev, connector, &mdp4_lvds_connector_funcs,
			DRM_MODE_CONNECTOR_LVDS);
	drm_connector_helper_add(connector, &mdp4_lvds_connector_helper_funcs);

	connector->polled = 0;

	connector->interlace_allowed = 0;
	connector->doublescan_allowed = 0;

	drm_connector_attach_encoder(connector, encoder);

	return connector;
}

