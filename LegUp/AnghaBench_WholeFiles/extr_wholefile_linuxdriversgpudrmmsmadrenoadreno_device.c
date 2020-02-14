#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int uint32_t ;
typedef  int uint16_t ;
typedef  int /*<<< orphan*/  u64 ;
typedef  int u32 ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct msm_ringbuffer {int cur; int start; } ;
struct msm_gpu {TYPE_3__* funcs; } ;
struct msm_drm_private {struct platform_device* gpu_pdev; } ;
struct drm_device {struct device* dev; struct msm_drm_private* dev_private; int /*<<< orphan*/  struct_mutex; } ;
struct device_node {int dummy; } ;
struct device {struct adreno_platform_config* platform_data; struct device_node* of_node; } ;
struct adreno_rev {int core; int major; int minor; int patchid; } ;
struct adreno_platform_config {struct adreno_rev rev; } ;
struct TYPE_5__ {int core; int major; int minor; int patchid; } ;
struct adreno_info {struct msm_gpu* (* init ) (struct drm_device*) ;TYPE_2__ rev; } ;
struct TYPE_4__ {scalar_t__ patchid; } ;
struct adreno_gpu {int revn; scalar_t__* reg_offsets; int /*<<< orphan*/  base; TYPE_1__ rev; } ;
typedef  enum vgt_event_type { ____Placeholder_vgt_event_type } vgt_event_type ;
typedef  enum render_mode_cmd { ____Placeholder_render_mode_cmd } render_mode_cmd ;
typedef  enum pseudo_reg { ____Placeholder_pseudo_reg } pseudo_reg ;
typedef  enum pc_di_vis_cull_mode { ____Placeholder_pc_di_vis_cull_mode } pc_di_vis_cull_mode ;
typedef  enum pc_di_src_sel { ____Placeholder_pc_di_src_sel } pc_di_src_sel ;
typedef  enum pc_di_primtype { ____Placeholder_pc_di_primtype } pc_di_primtype ;
typedef  enum pc_di_index_size { ____Placeholder_pc_di_index_size } pc_di_index_size ;
typedef  enum cp_cond_function { ____Placeholder_cp_cond_function } cp_cond_function ;
typedef  enum cp_blit_cmd { ____Placeholder_cp_blit_cmd } cp_blit_cmd ;
typedef  enum adreno_state_type { ____Placeholder_adreno_state_type } adreno_state_type ;
typedef  enum adreno_state_src { ____Placeholder_adreno_state_src } adreno_state_src ;
typedef  enum adreno_state_block { ____Placeholder_adreno_state_block } adreno_state_block ;
typedef  enum adreno_regs { ____Placeholder_adreno_regs } adreno_regs ;
typedef  enum a6xx_state_type { ____Placeholder_a6xx_state_type } a6xx_state_type ;
typedef  enum a6xx_state_src { ____Placeholder_a6xx_state_src } a6xx_state_src ;
typedef  enum a6xx_state_block { ____Placeholder_a6xx_state_block } a6xx_state_block ;
typedef  enum a6xx_render_mode { ____Placeholder_a6xx_render_mode } a6xx_render_mode ;
typedef  enum a4xx_state_type { ____Placeholder_a4xx_state_type } a4xx_state_type ;
typedef  enum a4xx_state_src { ____Placeholder_a4xx_state_src } a4xx_state_src ;
typedef  enum a4xx_state_block { ____Placeholder_a4xx_state_block } a4xx_state_block ;
typedef  enum a4xx_index_size { ____Placeholder_a4xx_index_size } a4xx_index_size ;
struct TYPE_6__ {int /*<<< orphan*/  (* destroy ) (struct msm_gpu*) ;int /*<<< orphan*/  (* pm_suspend ) (struct msm_gpu*) ;} ;

/* Variables and functions */
 int A2XX_CP_REG_TEST_0_BIT__MASK ; 
 int A2XX_CP_REG_TEST_0_BIT__SHIFT ; 
 int A2XX_CP_REG_TEST_0_REG__MASK ; 
 int A2XX_CP_REG_TEST_0_REG__SHIFT ; 
 int A2XX_CP_SET_MARKER_0_MARKER__MASK ; 
 int A2XX_CP_SET_MARKER_0_MARKER__SHIFT ; 
 int A2XX_CP_SET_MARKER_0_MODE__MASK ; 
 int A2XX_CP_SET_MARKER_0_MODE__SHIFT ; 
 int A2XX_CP_SET_PSEUDO_REG__0_PSEUDO_REG__MASK ; 
 int A2XX_CP_SET_PSEUDO_REG__0_PSEUDO_REG__SHIFT ; 
 int A2XX_CP_SET_PSEUDO_REG__1_LO__MASK ; 
 int A2XX_CP_SET_PSEUDO_REG__1_LO__SHIFT ; 
 int A2XX_CP_SET_PSEUDO_REG__2_HI__MASK ; 
 int A2XX_CP_SET_PSEUDO_REG__2_HI__SHIFT ; 
 int A4XX_CP_DRAW_INDIRECT_0_INDEX_SIZE__MASK ; 
 int A4XX_CP_DRAW_INDIRECT_0_INDEX_SIZE__SHIFT ; 
 int A4XX_CP_DRAW_INDIRECT_0_PRIM_TYPE__MASK ; 
 int A4XX_CP_DRAW_INDIRECT_0_PRIM_TYPE__SHIFT ; 
 int A4XX_CP_DRAW_INDIRECT_0_SOURCE_SELECT__MASK ; 
 int A4XX_CP_DRAW_INDIRECT_0_SOURCE_SELECT__SHIFT ; 
 int A4XX_CP_DRAW_INDIRECT_0_TESS_MODE__MASK ; 
 int A4XX_CP_DRAW_INDIRECT_0_TESS_MODE__SHIFT ; 
 int A4XX_CP_DRAW_INDIRECT_0_VIS_CULL__MASK ; 
 int A4XX_CP_DRAW_INDIRECT_0_VIS_CULL__SHIFT ; 
 int A4XX_CP_DRAW_INDIRECT_1_INDIRECT__MASK ; 
 int A4XX_CP_DRAW_INDIRECT_1_INDIRECT__SHIFT ; 
 int A4XX_CP_DRAW_INDX_INDIRECT_0_INDEX_SIZE__MASK ; 
 int A4XX_CP_DRAW_INDX_INDIRECT_0_INDEX_SIZE__SHIFT ; 
 int A4XX_CP_DRAW_INDX_INDIRECT_0_PRIM_TYPE__MASK ; 
 int A4XX_CP_DRAW_INDX_INDIRECT_0_PRIM_TYPE__SHIFT ; 
 int A4XX_CP_DRAW_INDX_INDIRECT_0_SOURCE_SELECT__MASK ; 
 int A4XX_CP_DRAW_INDX_INDIRECT_0_SOURCE_SELECT__SHIFT ; 
 int A4XX_CP_DRAW_INDX_INDIRECT_0_TESS_MODE__MASK ; 
 int A4XX_CP_DRAW_INDX_INDIRECT_0_TESS_MODE__SHIFT ; 
 int A4XX_CP_DRAW_INDX_INDIRECT_0_VIS_CULL__MASK ; 
 int A4XX_CP_DRAW_INDX_INDIRECT_0_VIS_CULL__SHIFT ; 
 int A4XX_CP_DRAW_INDX_INDIRECT_1_INDX_BASE__MASK ; 
 int A4XX_CP_DRAW_INDX_INDIRECT_1_INDX_BASE__SHIFT ; 
 int A4XX_CP_DRAW_INDX_INDIRECT_2_INDX_SIZE__MASK ; 
 int A4XX_CP_DRAW_INDX_INDIRECT_2_INDX_SIZE__SHIFT ; 
 int A4XX_CP_DRAW_INDX_INDIRECT_3_INDIRECT__MASK ; 
 int A4XX_CP_DRAW_INDX_INDIRECT_3_INDIRECT__SHIFT ; 
 int A4XX_CP_EXEC_CS_INDIRECT_1_ADDR__MASK ; 
 int A4XX_CP_EXEC_CS_INDIRECT_1_ADDR__SHIFT ; 
 int A4XX_CP_EXEC_CS_INDIRECT_2_LOCALSIZEX__MASK ; 
 int A4XX_CP_EXEC_CS_INDIRECT_2_LOCALSIZEX__SHIFT ; 
 int A4XX_CP_EXEC_CS_INDIRECT_2_LOCALSIZEY__MASK ; 
 int A4XX_CP_EXEC_CS_INDIRECT_2_LOCALSIZEY__SHIFT ; 
 int A4XX_CP_EXEC_CS_INDIRECT_2_LOCALSIZEZ__MASK ; 
 int A4XX_CP_EXEC_CS_INDIRECT_2_LOCALSIZEZ__SHIFT ; 
 int A5XX_CP_DRAW_INDIRECT_2_INDIRECT_HI__MASK ; 
 int A5XX_CP_DRAW_INDIRECT_2_INDIRECT_HI__SHIFT ; 
 int A5XX_CP_DRAW_INDX_INDIRECT_1_INDX_BASE_LO__MASK ; 
 int A5XX_CP_DRAW_INDX_INDIRECT_1_INDX_BASE_LO__SHIFT ; 
 int A5XX_CP_DRAW_INDX_INDIRECT_2_INDX_BASE_HI__MASK ; 
 int A5XX_CP_DRAW_INDX_INDIRECT_2_INDX_BASE_HI__SHIFT ; 
 int A5XX_CP_DRAW_INDX_INDIRECT_3_MAX_INDICES__MASK ; 
 int A5XX_CP_DRAW_INDX_INDIRECT_3_MAX_INDICES__SHIFT ; 
 int A5XX_CP_DRAW_INDX_INDIRECT_4_INDIRECT_LO__MASK ; 
 int A5XX_CP_DRAW_INDX_INDIRECT_4_INDIRECT_LO__SHIFT ; 
 int A5XX_CP_DRAW_INDX_INDIRECT_5_INDIRECT_HI__MASK ; 
 int A5XX_CP_DRAW_INDX_INDIRECT_5_INDIRECT_HI__SHIFT ; 
 int A5XX_CP_EXEC_CS_INDIRECT_1_ADDR_LO__MASK ; 
 int A5XX_CP_EXEC_CS_INDIRECT_1_ADDR_LO__SHIFT ; 
 int A5XX_CP_EXEC_CS_INDIRECT_2_ADDR_HI__MASK ; 
 int A5XX_CP_EXEC_CS_INDIRECT_2_ADDR_HI__SHIFT ; 
 int A5XX_CP_EXEC_CS_INDIRECT_3_LOCALSIZEX__MASK ; 
 int A5XX_CP_EXEC_CS_INDIRECT_3_LOCALSIZEX__SHIFT ; 
 int A5XX_CP_EXEC_CS_INDIRECT_3_LOCALSIZEY__MASK ; 
 int A5XX_CP_EXEC_CS_INDIRECT_3_LOCALSIZEY__SHIFT ; 
 int A5XX_CP_EXEC_CS_INDIRECT_3_LOCALSIZEZ__MASK ; 
 int A5XX_CP_EXEC_CS_INDIRECT_3_LOCALSIZEZ__SHIFT ; 
 int ANY_ID ; 
 int ARRAY_SIZE (struct adreno_info*) ; 
 int AXXX_CP_CSQ_AVAIL_IB1__MASK ; 
 int AXXX_CP_CSQ_AVAIL_IB1__SHIFT ; 
 int AXXX_CP_CSQ_AVAIL_IB2__MASK ; 
 int AXXX_CP_CSQ_AVAIL_IB2__SHIFT ; 
 int AXXX_CP_CSQ_AVAIL_RING__MASK ; 
 int AXXX_CP_CSQ_AVAIL_RING__SHIFT ; 
 int AXXX_CP_CSQ_IB1_STAT_RPTR__MASK ; 
 int AXXX_CP_CSQ_IB1_STAT_RPTR__SHIFT ; 
 int AXXX_CP_CSQ_IB1_STAT_WPTR__MASK ; 
 int AXXX_CP_CSQ_IB1_STAT_WPTR__SHIFT ; 
 int AXXX_CP_CSQ_IB2_STAT_RPTR__MASK ; 
 int AXXX_CP_CSQ_IB2_STAT_RPTR__SHIFT ; 
 int AXXX_CP_CSQ_IB2_STAT_WPTR__MASK ; 
 int AXXX_CP_CSQ_IB2_STAT_WPTR__SHIFT ; 
 int AXXX_CP_CSQ_RB_STAT_RPTR__MASK ; 
 int AXXX_CP_CSQ_RB_STAT_RPTR__SHIFT ; 
 int AXXX_CP_CSQ_RB_STAT_WPTR__MASK ; 
 int AXXX_CP_CSQ_RB_STAT_WPTR__SHIFT ; 
 int AXXX_CP_MEQ_AVAIL_MEQ__MASK ; 
 int AXXX_CP_MEQ_AVAIL_MEQ__SHIFT ; 
 int AXXX_CP_MEQ_THRESHOLDS_MEQ_END__MASK ; 
 int AXXX_CP_MEQ_THRESHOLDS_MEQ_END__SHIFT ; 
 int AXXX_CP_MEQ_THRESHOLDS_ROQ_END__MASK ; 
 int AXXX_CP_MEQ_THRESHOLDS_ROQ_END__SHIFT ; 
 int AXXX_CP_QUEUE_THRESHOLDS_CSQ_IB1_START__MASK ; 
 int AXXX_CP_QUEUE_THRESHOLDS_CSQ_IB1_START__SHIFT ; 
 int AXXX_CP_QUEUE_THRESHOLDS_CSQ_IB2_START__MASK ; 
 int AXXX_CP_QUEUE_THRESHOLDS_CSQ_IB2_START__SHIFT ; 
 int AXXX_CP_QUEUE_THRESHOLDS_CSQ_ST_START__MASK ; 
 int AXXX_CP_QUEUE_THRESHOLDS_CSQ_ST_START__SHIFT ; 
 int AXXX_CP_RB_CNTL_BLKSZ__MASK ; 
 int AXXX_CP_RB_CNTL_BLKSZ__SHIFT ; 
 int AXXX_CP_RB_CNTL_BUFSZ__MASK ; 
 int AXXX_CP_RB_CNTL_BUFSZ__SHIFT ; 
 int AXXX_CP_RB_CNTL_BUF_SWAP__MASK ; 
 int AXXX_CP_RB_CNTL_BUF_SWAP__SHIFT ; 
 int AXXX_CP_RB_RPTR_ADDR_ADDR__MASK ; 
 int AXXX_CP_RB_RPTR_ADDR_ADDR__SHIFT ; 
 int AXXX_CP_RB_RPTR_ADDR_SWAP__MASK ; 
 int AXXX_CP_RB_RPTR_ADDR_SWAP__SHIFT ; 
 int AXXX_CP_STQ_AVAIL_ST__MASK ; 
 int AXXX_CP_STQ_AVAIL_ST__SHIFT ; 
 int AXXX_SCRATCH_UMSK_SWAP__MASK ; 
 int AXXX_SCRATCH_UMSK_SWAP__SHIFT ; 
 int AXXX_SCRATCH_UMSK_UMSK__MASK ; 
 int AXXX_SCRATCH_UMSK_UMSK__SHIFT ; 
 int /*<<< orphan*/  BUG () ; 
 int CP_BLIT_0_OP__MASK ; 
 int CP_BLIT_0_OP__SHIFT ; 
 int CP_BLIT_1_SRC_X1__MASK ; 
 int CP_BLIT_1_SRC_X1__SHIFT ; 
 int CP_BLIT_1_SRC_Y1__MASK ; 
 int CP_BLIT_1_SRC_Y1__SHIFT ; 
 int CP_BLIT_2_SRC_X2__MASK ; 
 int CP_BLIT_2_SRC_X2__SHIFT ; 
 int CP_BLIT_2_SRC_Y2__MASK ; 
 int CP_BLIT_2_SRC_Y2__SHIFT ; 
 int CP_BLIT_3_DST_X1__MASK ; 
 int CP_BLIT_3_DST_X1__SHIFT ; 
 int CP_BLIT_3_DST_Y1__MASK ; 
 int CP_BLIT_3_DST_Y1__SHIFT ; 
 int CP_BLIT_4_DST_X2__MASK ; 
 int CP_BLIT_4_DST_X2__SHIFT ; 
 int CP_BLIT_4_DST_Y2__MASK ; 
 int CP_BLIT_4_DST_Y2__SHIFT ; 
 int CP_COMPUTE_CHECKPOINT_0_ADDR_0_LO__MASK ; 
 int CP_COMPUTE_CHECKPOINT_0_ADDR_0_LO__SHIFT ; 
 int CP_COMPUTE_CHECKPOINT_1_ADDR_0_HI__MASK ; 
 int CP_COMPUTE_CHECKPOINT_1_ADDR_0_HI__SHIFT ; 
 int CP_COMPUTE_CHECKPOINT_3_ADDR_1_LEN__MASK ; 
 int CP_COMPUTE_CHECKPOINT_3_ADDR_1_LEN__SHIFT ; 
 int CP_COMPUTE_CHECKPOINT_5_ADDR_1_LO__MASK ; 
 int CP_COMPUTE_CHECKPOINT_5_ADDR_1_LO__SHIFT ; 
 int CP_COMPUTE_CHECKPOINT_6_ADDR_1_HI__MASK ; 
 int CP_COMPUTE_CHECKPOINT_6_ADDR_1_HI__SHIFT ; 
 int CP_COND_WRITE5_0_FUNCTION__MASK ; 
 int CP_COND_WRITE5_0_FUNCTION__SHIFT ; 
 int CP_COND_WRITE5_1_POLL_ADDR_LO__MASK ; 
 int CP_COND_WRITE5_1_POLL_ADDR_LO__SHIFT ; 
 int CP_COND_WRITE5_2_POLL_ADDR_HI__MASK ; 
 int CP_COND_WRITE5_2_POLL_ADDR_HI__SHIFT ; 
 int CP_COND_WRITE5_3_REF__MASK ; 
 int CP_COND_WRITE5_3_REF__SHIFT ; 
 int CP_COND_WRITE5_4_MASK__MASK ; 
 int CP_COND_WRITE5_4_MASK__SHIFT ; 
 int CP_COND_WRITE5_5_WRITE_ADDR_LO__MASK ; 
 int CP_COND_WRITE5_5_WRITE_ADDR_LO__SHIFT ; 
 int CP_COND_WRITE5_6_WRITE_ADDR_HI__MASK ; 
 int CP_COND_WRITE5_6_WRITE_ADDR_HI__SHIFT ; 
 int CP_COND_WRITE5_7_WRITE_DATA__MASK ; 
 int CP_COND_WRITE5_7_WRITE_DATA__SHIFT ; 
 int CP_COND_WRITE_0_FUNCTION__MASK ; 
 int CP_COND_WRITE_0_FUNCTION__SHIFT ; 
 int CP_COND_WRITE_1_POLL_ADDR__MASK ; 
 int CP_COND_WRITE_1_POLL_ADDR__SHIFT ; 
 int CP_COND_WRITE_2_REF__MASK ; 
 int CP_COND_WRITE_2_REF__SHIFT ; 
 int CP_COND_WRITE_3_MASK__MASK ; 
 int CP_COND_WRITE_3_MASK__SHIFT ; 
 int CP_COND_WRITE_4_WRITE_ADDR__MASK ; 
 int CP_COND_WRITE_4_WRITE_ADDR__SHIFT ; 
 int CP_COND_WRITE_5_WRITE_DATA__MASK ; 
 int CP_COND_WRITE_5_WRITE_DATA__SHIFT ; 
 int CP_DISPATCH_COMPUTE_1_X__MASK ; 
 int CP_DISPATCH_COMPUTE_1_X__SHIFT ; 
 int CP_DISPATCH_COMPUTE_2_Y__MASK ; 
 int CP_DISPATCH_COMPUTE_2_Y__SHIFT ; 
 int CP_DISPATCH_COMPUTE_3_Z__MASK ; 
 int CP_DISPATCH_COMPUTE_3_Z__SHIFT ; 
 int CP_DRAW_INDX_0_VIZ_QUERY__MASK ; 
 int CP_DRAW_INDX_0_VIZ_QUERY__SHIFT ; 
 int CP_DRAW_INDX_1_INDEX_SIZE__MASK ; 
 int CP_DRAW_INDX_1_INDEX_SIZE__SHIFT ; 
 int CP_DRAW_INDX_1_NUM_INSTANCES__MASK ; 
 int CP_DRAW_INDX_1_NUM_INSTANCES__SHIFT ; 
 int CP_DRAW_INDX_1_PRIM_TYPE__MASK ; 
 int CP_DRAW_INDX_1_PRIM_TYPE__SHIFT ; 
 int CP_DRAW_INDX_1_SOURCE_SELECT__MASK ; 
 int CP_DRAW_INDX_1_SOURCE_SELECT__SHIFT ; 
 int CP_DRAW_INDX_1_VIS_CULL__MASK ; 
 int CP_DRAW_INDX_1_VIS_CULL__SHIFT ; 
 int CP_DRAW_INDX_2_0_VIZ_QUERY__MASK ; 
 int CP_DRAW_INDX_2_0_VIZ_QUERY__SHIFT ; 
 int CP_DRAW_INDX_2_1_INDEX_SIZE__MASK ; 
 int CP_DRAW_INDX_2_1_INDEX_SIZE__SHIFT ; 
 int CP_DRAW_INDX_2_1_NUM_INSTANCES__MASK ; 
 int CP_DRAW_INDX_2_1_NUM_INSTANCES__SHIFT ; 
 int CP_DRAW_INDX_2_1_PRIM_TYPE__MASK ; 
 int CP_DRAW_INDX_2_1_PRIM_TYPE__SHIFT ; 
 int CP_DRAW_INDX_2_1_SOURCE_SELECT__MASK ; 
 int CP_DRAW_INDX_2_1_SOURCE_SELECT__SHIFT ; 
 int CP_DRAW_INDX_2_1_VIS_CULL__MASK ; 
 int CP_DRAW_INDX_2_1_VIS_CULL__SHIFT ; 
 int CP_DRAW_INDX_2_2_NUM_INDICES__MASK ; 
 int CP_DRAW_INDX_2_2_NUM_INDICES__SHIFT ; 
 int CP_DRAW_INDX_2_NUM_INDICES__MASK ; 
 int CP_DRAW_INDX_2_NUM_INDICES__SHIFT ; 
 int CP_DRAW_INDX_3_INDX_BASE__MASK ; 
 int CP_DRAW_INDX_3_INDX_BASE__SHIFT ; 
 int CP_DRAW_INDX_4_INDX_SIZE__MASK ; 
 int CP_DRAW_INDX_4_INDX_SIZE__SHIFT ; 
 int CP_DRAW_INDX_OFFSET_0_INDEX_SIZE__MASK ; 
 int CP_DRAW_INDX_OFFSET_0_INDEX_SIZE__SHIFT ; 
 int CP_DRAW_INDX_OFFSET_0_PRIM_TYPE__MASK ; 
 int CP_DRAW_INDX_OFFSET_0_PRIM_TYPE__SHIFT ; 
 int CP_DRAW_INDX_OFFSET_0_SOURCE_SELECT__MASK ; 
 int CP_DRAW_INDX_OFFSET_0_SOURCE_SELECT__SHIFT ; 
 int CP_DRAW_INDX_OFFSET_0_TESS_MODE__MASK ; 
 int CP_DRAW_INDX_OFFSET_0_TESS_MODE__SHIFT ; 
 int CP_DRAW_INDX_OFFSET_0_VIS_CULL__MASK ; 
 int CP_DRAW_INDX_OFFSET_0_VIS_CULL__SHIFT ; 
 int CP_DRAW_INDX_OFFSET_1_NUM_INSTANCES__MASK ; 
 int CP_DRAW_INDX_OFFSET_1_NUM_INSTANCES__SHIFT ; 
 int CP_DRAW_INDX_OFFSET_2_NUM_INDICES__MASK ; 
 int CP_DRAW_INDX_OFFSET_2_NUM_INDICES__SHIFT ; 
 int CP_DRAW_INDX_OFFSET_4_INDX_BASE__MASK ; 
 int CP_DRAW_INDX_OFFSET_4_INDX_BASE__SHIFT ; 
 int CP_DRAW_INDX_OFFSET_5_INDX_SIZE__MASK ; 
 int CP_DRAW_INDX_OFFSET_5_INDX_SIZE__SHIFT ; 
 int CP_EVENT_WRITE_0_EVENT__MASK ; 
 int CP_EVENT_WRITE_0_EVENT__SHIFT ; 
 int CP_EVENT_WRITE_1_ADDR_0_LO__MASK ; 
 int CP_EVENT_WRITE_1_ADDR_0_LO__SHIFT ; 
 int CP_EVENT_WRITE_2_ADDR_0_HI__MASK ; 
 int CP_EVENT_WRITE_2_ADDR_0_HI__SHIFT ; 
 int CP_EXEC_CS_1_NGROUPS_X__MASK ; 
 int CP_EXEC_CS_1_NGROUPS_X__SHIFT ; 
 int CP_EXEC_CS_2_NGROUPS_Y__MASK ; 
 int CP_EXEC_CS_2_NGROUPS_Y__SHIFT ; 
 int CP_EXEC_CS_3_NGROUPS_Z__MASK ; 
 int CP_EXEC_CS_3_NGROUPS_Z__SHIFT ; 
 int CP_LOAD_STATE4_0_DST_OFF__MASK ; 
 int CP_LOAD_STATE4_0_DST_OFF__SHIFT ; 
 int CP_LOAD_STATE4_0_NUM_UNIT__MASK ; 
 int CP_LOAD_STATE4_0_NUM_UNIT__SHIFT ; 
 int CP_LOAD_STATE4_0_STATE_BLOCK__MASK ; 
 int CP_LOAD_STATE4_0_STATE_BLOCK__SHIFT ; 
 int CP_LOAD_STATE4_0_STATE_SRC__MASK ; 
 int CP_LOAD_STATE4_0_STATE_SRC__SHIFT ; 
 int CP_LOAD_STATE4_1_EXT_SRC_ADDR__MASK ; 
 int CP_LOAD_STATE4_1_EXT_SRC_ADDR__SHIFT ; 
 int CP_LOAD_STATE4_1_STATE_TYPE__MASK ; 
 int CP_LOAD_STATE4_1_STATE_TYPE__SHIFT ; 
 int CP_LOAD_STATE4_2_EXT_SRC_ADDR_HI__MASK ; 
 int CP_LOAD_STATE4_2_EXT_SRC_ADDR_HI__SHIFT ; 
 int CP_LOAD_STATE6_0_DST_OFF__MASK ; 
 int CP_LOAD_STATE6_0_DST_OFF__SHIFT ; 
 int CP_LOAD_STATE6_0_NUM_UNIT__MASK ; 
 int CP_LOAD_STATE6_0_NUM_UNIT__SHIFT ; 
 int CP_LOAD_STATE6_0_STATE_BLOCK__MASK ; 
 int CP_LOAD_STATE6_0_STATE_BLOCK__SHIFT ; 
 int CP_LOAD_STATE6_0_STATE_SRC__MASK ; 
 int CP_LOAD_STATE6_0_STATE_SRC__SHIFT ; 
 int CP_LOAD_STATE6_0_STATE_TYPE__MASK ; 
 int CP_LOAD_STATE6_0_STATE_TYPE__SHIFT ; 
 int CP_LOAD_STATE6_1_EXT_SRC_ADDR__MASK ; 
 int CP_LOAD_STATE6_1_EXT_SRC_ADDR__SHIFT ; 
 int CP_LOAD_STATE6_2_EXT_SRC_ADDR_HI__MASK ; 
 int CP_LOAD_STATE6_2_EXT_SRC_ADDR_HI__SHIFT ; 
 int CP_LOAD_STATE_0_DST_OFF__MASK ; 
 int CP_LOAD_STATE_0_DST_OFF__SHIFT ; 
 int CP_LOAD_STATE_0_NUM_UNIT__MASK ; 
 int CP_LOAD_STATE_0_NUM_UNIT__SHIFT ; 
 int CP_LOAD_STATE_0_STATE_BLOCK__MASK ; 
 int CP_LOAD_STATE_0_STATE_BLOCK__SHIFT ; 
 int CP_LOAD_STATE_0_STATE_SRC__MASK ; 
 int CP_LOAD_STATE_0_STATE_SRC__SHIFT ; 
 int CP_LOAD_STATE_1_EXT_SRC_ADDR__MASK ; 
 int CP_LOAD_STATE_1_EXT_SRC_ADDR__SHIFT ; 
 int CP_LOAD_STATE_1_STATE_TYPE__MASK ; 
 int CP_LOAD_STATE_1_STATE_TYPE__SHIFT ; 
 int CP_MEM_TO_REG_0_CNT__MASK ; 
 int CP_MEM_TO_REG_0_CNT__SHIFT ; 
 int CP_MEM_TO_REG_0_REG__MASK ; 
 int CP_MEM_TO_REG_0_REG__SHIFT ; 
 int CP_MEM_TO_REG_1_SRC__MASK ; 
 int CP_MEM_TO_REG_1_SRC__SHIFT ; 
 int CP_MEM_TO_REG_2_SRC_HI__MASK ; 
 int CP_MEM_TO_REG_2_SRC_HI__SHIFT ; 
 int CP_PERFCOUNTER_ACTION_1_ADDR_0_LO__MASK ; 
 int CP_PERFCOUNTER_ACTION_1_ADDR_0_LO__SHIFT ; 
 int CP_PERFCOUNTER_ACTION_2_ADDR_0_HI__MASK ; 
 int CP_PERFCOUNTER_ACTION_2_ADDR_0_HI__SHIFT ; 
 int CP_REG_TO_MEM_0_CNT__MASK ; 
 int CP_REG_TO_MEM_0_CNT__SHIFT ; 
 int CP_REG_TO_MEM_0_REG__MASK ; 
 int CP_REG_TO_MEM_0_REG__SHIFT ; 
 int CP_REG_TO_MEM_1_DEST__MASK ; 
 int CP_REG_TO_MEM_1_DEST__SHIFT ; 
 int CP_REG_TO_MEM_2_DEST_HI__MASK ; 
 int CP_REG_TO_MEM_2_DEST_HI__SHIFT ; 
 int CP_SET_BIN_1_X1__MASK ; 
 int CP_SET_BIN_1_X1__SHIFT ; 
 int CP_SET_BIN_1_Y1__MASK ; 
 int CP_SET_BIN_1_Y1__SHIFT ; 
 int CP_SET_BIN_2_X2__MASK ; 
 int CP_SET_BIN_2_X2__SHIFT ; 
 int CP_SET_BIN_2_Y2__MASK ; 
 int CP_SET_BIN_2_Y2__SHIFT ; 
 int CP_SET_BIN_DATA5_0_VSC_N__MASK ; 
 int CP_SET_BIN_DATA5_0_VSC_N__SHIFT ; 
 int CP_SET_BIN_DATA5_0_VSC_SIZE__MASK ; 
 int CP_SET_BIN_DATA5_0_VSC_SIZE__SHIFT ; 
 int CP_SET_BIN_DATA5_1_BIN_DATA_ADDR_LO__MASK ; 
 int CP_SET_BIN_DATA5_1_BIN_DATA_ADDR_LO__SHIFT ; 
 int CP_SET_BIN_DATA5_2_BIN_DATA_ADDR_HI__MASK ; 
 int CP_SET_BIN_DATA5_2_BIN_DATA_ADDR_HI__SHIFT ; 
 int CP_SET_BIN_DATA5_3_BIN_SIZE_ADDRESS_LO__MASK ; 
 int CP_SET_BIN_DATA5_3_BIN_SIZE_ADDRESS_LO__SHIFT ; 
 int CP_SET_BIN_DATA5_4_BIN_SIZE_ADDRESS_HI__MASK ; 
 int CP_SET_BIN_DATA5_4_BIN_SIZE_ADDRESS_HI__SHIFT ; 
 int CP_SET_BIN_DATA5_5_XXX_ADDRESS_LO__MASK ; 
 int CP_SET_BIN_DATA5_5_XXX_ADDRESS_LO__SHIFT ; 
 int CP_SET_BIN_DATA5_6_XXX_ADDRESS_HI__MASK ; 
 int CP_SET_BIN_DATA5_6_XXX_ADDRESS_HI__SHIFT ; 
 int CP_SET_BIN_DATA_0_BIN_DATA_ADDR__MASK ; 
 int CP_SET_BIN_DATA_0_BIN_DATA_ADDR__SHIFT ; 
 int CP_SET_BIN_DATA_1_BIN_SIZE_ADDRESS__MASK ; 
 int CP_SET_BIN_DATA_1_BIN_SIZE_ADDRESS__SHIFT ; 
 int CP_SET_DRAW_STATE__0_COUNT__MASK ; 
 int CP_SET_DRAW_STATE__0_COUNT__SHIFT ; 
 int CP_SET_DRAW_STATE__0_ENABLE_MASK__MASK ; 
 int CP_SET_DRAW_STATE__0_ENABLE_MASK__SHIFT ; 
 int CP_SET_DRAW_STATE__0_GROUP_ID__MASK ; 
 int CP_SET_DRAW_STATE__0_GROUP_ID__SHIFT ; 
 int CP_SET_DRAW_STATE__1_ADDR_LO__MASK ; 
 int CP_SET_DRAW_STATE__1_ADDR_LO__SHIFT ; 
 int CP_SET_DRAW_STATE__2_ADDR_HI__MASK ; 
 int CP_SET_DRAW_STATE__2_ADDR_HI__SHIFT ; 
 int CP_SET_RENDER_MODE_0_MODE__MASK ; 
 int CP_SET_RENDER_MODE_0_MODE__SHIFT ; 
 int CP_SET_RENDER_MODE_1_ADDR_0_LO__MASK ; 
 int CP_SET_RENDER_MODE_1_ADDR_0_LO__SHIFT ; 
 int CP_SET_RENDER_MODE_2_ADDR_0_HI__MASK ; 
 int CP_SET_RENDER_MODE_2_ADDR_0_HI__SHIFT ; 
 int CP_SET_RENDER_MODE_5_ADDR_1_LEN__MASK ; 
 int CP_SET_RENDER_MODE_5_ADDR_1_LEN__SHIFT ; 
 int CP_SET_RENDER_MODE_6_ADDR_1_LO__MASK ; 
 int CP_SET_RENDER_MODE_6_ADDR_1_LO__SHIFT ; 
 int CP_SET_RENDER_MODE_7_ADDR_1_HI__MASK ; 
 int CP_SET_RENDER_MODE_7_ADDR_1_HI__SHIFT ; 
 int CP_TYPE0_PKT ; 
 int CP_TYPE2_PKT ; 
 int CP_TYPE3_PKT ; 
 int CP_TYPE7_PKT ; 
 int /*<<< orphan*/  DBG (char*,int,int,int,int) ; 
 int ENXIO ; 
 scalar_t__ IS_ERR (struct msm_gpu*) ; 
 int MSM_GPU_RINGBUFFER_SZ ; 
 int /*<<< orphan*/  OUT_RING (struct msm_ringbuffer*,int) ; 
 int PKT4 (int,int) ; 
 int PTR_ERR (struct msm_gpu*) ; 
 int REG_ADRENO_REGISTER_MAX ; 
 scalar_t__ REG_SKIP ; 
 int /*<<< orphan*/  a3xx_ops ; 
 int adreno_load_fw (struct adreno_gpu*) ; 
 int /*<<< orphan*/  adreno_wait_ring (struct msm_ringbuffer*,int) ; 
 int component_add (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  component_del (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int) ; 
 int /*<<< orphan*/  dev_err_once (struct device*,char*) ; 
 void* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct msm_gpu*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,...) ; 
 int gpu_read (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  gpu_write (int /*<<< orphan*/ *,int,int) ; 
 struct adreno_info* gpulist ; 
 int lower_32_bits (int /*<<< orphan*/ ) ; 
 int msm_gpu_hw_init (struct msm_gpu*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int of_property_read_string_index (struct device_node*,char*,int /*<<< orphan*/ ,char const**) ; 
 int of_property_read_u32 (struct device_node*,char*,int*) ; 
 struct msm_gpu* platform_get_drvdata (struct platform_device*) ; 
 int pm_runtime_get_sync (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_put_autosuspend (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_set_active (int /*<<< orphan*/ *) ; 
 int sscanf (char const*,char*,unsigned int*,unsigned int*) ; 
 struct msm_gpu* stub1 (struct drm_device*) ; 
 int /*<<< orphan*/  stub2 (struct msm_gpu*) ; 
 int /*<<< orphan*/  stub3 (struct msm_gpu*) ; 
 struct adreno_gpu* to_adreno_gpu (struct msm_gpu*) ; 
 struct platform_device* to_platform_device (struct device*) ; 
 int upper_32_bits (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline uint32_t AXXX_CP_RB_CNTL_BUFSZ(uint32_t val)
{
	return ((val) << AXXX_CP_RB_CNTL_BUFSZ__SHIFT) & AXXX_CP_RB_CNTL_BUFSZ__MASK;
}

__attribute__((used)) static inline uint32_t AXXX_CP_RB_CNTL_BLKSZ(uint32_t val)
{
	return ((val) << AXXX_CP_RB_CNTL_BLKSZ__SHIFT) & AXXX_CP_RB_CNTL_BLKSZ__MASK;
}

__attribute__((used)) static inline uint32_t AXXX_CP_RB_CNTL_BUF_SWAP(uint32_t val)
{
	return ((val) << AXXX_CP_RB_CNTL_BUF_SWAP__SHIFT) & AXXX_CP_RB_CNTL_BUF_SWAP__MASK;
}

__attribute__((used)) static inline uint32_t AXXX_CP_RB_RPTR_ADDR_SWAP(uint32_t val)
{
	return ((val) << AXXX_CP_RB_RPTR_ADDR_SWAP__SHIFT) & AXXX_CP_RB_RPTR_ADDR_SWAP__MASK;
}

__attribute__((used)) static inline uint32_t AXXX_CP_RB_RPTR_ADDR_ADDR(uint32_t val)
{
	return ((val >> 2) << AXXX_CP_RB_RPTR_ADDR_ADDR__SHIFT) & AXXX_CP_RB_RPTR_ADDR_ADDR__MASK;
}

__attribute__((used)) static inline uint32_t AXXX_CP_QUEUE_THRESHOLDS_CSQ_IB1_START(uint32_t val)
{
	return ((val) << AXXX_CP_QUEUE_THRESHOLDS_CSQ_IB1_START__SHIFT) & AXXX_CP_QUEUE_THRESHOLDS_CSQ_IB1_START__MASK;
}

__attribute__((used)) static inline uint32_t AXXX_CP_QUEUE_THRESHOLDS_CSQ_IB2_START(uint32_t val)
{
	return ((val) << AXXX_CP_QUEUE_THRESHOLDS_CSQ_IB2_START__SHIFT) & AXXX_CP_QUEUE_THRESHOLDS_CSQ_IB2_START__MASK;
}

__attribute__((used)) static inline uint32_t AXXX_CP_QUEUE_THRESHOLDS_CSQ_ST_START(uint32_t val)
{
	return ((val) << AXXX_CP_QUEUE_THRESHOLDS_CSQ_ST_START__SHIFT) & AXXX_CP_QUEUE_THRESHOLDS_CSQ_ST_START__MASK;
}

__attribute__((used)) static inline uint32_t AXXX_CP_MEQ_THRESHOLDS_MEQ_END(uint32_t val)
{
	return ((val) << AXXX_CP_MEQ_THRESHOLDS_MEQ_END__SHIFT) & AXXX_CP_MEQ_THRESHOLDS_MEQ_END__MASK;
}

__attribute__((used)) static inline uint32_t AXXX_CP_MEQ_THRESHOLDS_ROQ_END(uint32_t val)
{
	return ((val) << AXXX_CP_MEQ_THRESHOLDS_ROQ_END__SHIFT) & AXXX_CP_MEQ_THRESHOLDS_ROQ_END__MASK;
}

__attribute__((used)) static inline uint32_t AXXX_CP_CSQ_AVAIL_RING(uint32_t val)
{
	return ((val) << AXXX_CP_CSQ_AVAIL_RING__SHIFT) & AXXX_CP_CSQ_AVAIL_RING__MASK;
}

__attribute__((used)) static inline uint32_t AXXX_CP_CSQ_AVAIL_IB1(uint32_t val)
{
	return ((val) << AXXX_CP_CSQ_AVAIL_IB1__SHIFT) & AXXX_CP_CSQ_AVAIL_IB1__MASK;
}

__attribute__((used)) static inline uint32_t AXXX_CP_CSQ_AVAIL_IB2(uint32_t val)
{
	return ((val) << AXXX_CP_CSQ_AVAIL_IB2__SHIFT) & AXXX_CP_CSQ_AVAIL_IB2__MASK;
}

__attribute__((used)) static inline uint32_t AXXX_CP_STQ_AVAIL_ST(uint32_t val)
{
	return ((val) << AXXX_CP_STQ_AVAIL_ST__SHIFT) & AXXX_CP_STQ_AVAIL_ST__MASK;
}

__attribute__((used)) static inline uint32_t AXXX_CP_MEQ_AVAIL_MEQ(uint32_t val)
{
	return ((val) << AXXX_CP_MEQ_AVAIL_MEQ__SHIFT) & AXXX_CP_MEQ_AVAIL_MEQ__MASK;
}

__attribute__((used)) static inline uint32_t AXXX_SCRATCH_UMSK_UMSK(uint32_t val)
{
	return ((val) << AXXX_SCRATCH_UMSK_UMSK__SHIFT) & AXXX_SCRATCH_UMSK_UMSK__MASK;
}

__attribute__((used)) static inline uint32_t AXXX_SCRATCH_UMSK_SWAP(uint32_t val)
{
	return ((val) << AXXX_SCRATCH_UMSK_SWAP__SHIFT) & AXXX_SCRATCH_UMSK_SWAP__MASK;
}

__attribute__((used)) static inline uint32_t AXXX_CP_CSQ_RB_STAT_RPTR(uint32_t val)
{
	return ((val) << AXXX_CP_CSQ_RB_STAT_RPTR__SHIFT) & AXXX_CP_CSQ_RB_STAT_RPTR__MASK;
}

__attribute__((used)) static inline uint32_t AXXX_CP_CSQ_RB_STAT_WPTR(uint32_t val)
{
	return ((val) << AXXX_CP_CSQ_RB_STAT_WPTR__SHIFT) & AXXX_CP_CSQ_RB_STAT_WPTR__MASK;
}

__attribute__((used)) static inline uint32_t AXXX_CP_CSQ_IB1_STAT_RPTR(uint32_t val)
{
	return ((val) << AXXX_CP_CSQ_IB1_STAT_RPTR__SHIFT) & AXXX_CP_CSQ_IB1_STAT_RPTR__MASK;
}

__attribute__((used)) static inline uint32_t AXXX_CP_CSQ_IB1_STAT_WPTR(uint32_t val)
{
	return ((val) << AXXX_CP_CSQ_IB1_STAT_WPTR__SHIFT) & AXXX_CP_CSQ_IB1_STAT_WPTR__MASK;
}

__attribute__((used)) static inline uint32_t AXXX_CP_CSQ_IB2_STAT_RPTR(uint32_t val)
{
	return ((val) << AXXX_CP_CSQ_IB2_STAT_RPTR__SHIFT) & AXXX_CP_CSQ_IB2_STAT_RPTR__MASK;
}

__attribute__((used)) static inline uint32_t AXXX_CP_CSQ_IB2_STAT_WPTR(uint32_t val)
{
	return ((val) << AXXX_CP_CSQ_IB2_STAT_WPTR__SHIFT) & AXXX_CP_CSQ_IB2_STAT_WPTR__MASK;
}

__attribute__((used)) static inline uint32_t CP_LOAD_STATE_0_DST_OFF(uint32_t val)
{
	return ((val) << CP_LOAD_STATE_0_DST_OFF__SHIFT) & CP_LOAD_STATE_0_DST_OFF__MASK;
}

__attribute__((used)) static inline uint32_t CP_LOAD_STATE_0_STATE_SRC(enum adreno_state_src val)
{
	return ((val) << CP_LOAD_STATE_0_STATE_SRC__SHIFT) & CP_LOAD_STATE_0_STATE_SRC__MASK;
}

__attribute__((used)) static inline uint32_t CP_LOAD_STATE_0_STATE_BLOCK(enum adreno_state_block val)
{
	return ((val) << CP_LOAD_STATE_0_STATE_BLOCK__SHIFT) & CP_LOAD_STATE_0_STATE_BLOCK__MASK;
}

__attribute__((used)) static inline uint32_t CP_LOAD_STATE_0_NUM_UNIT(uint32_t val)
{
	return ((val) << CP_LOAD_STATE_0_NUM_UNIT__SHIFT) & CP_LOAD_STATE_0_NUM_UNIT__MASK;
}

__attribute__((used)) static inline uint32_t CP_LOAD_STATE_1_STATE_TYPE(enum adreno_state_type val)
{
	return ((val) << CP_LOAD_STATE_1_STATE_TYPE__SHIFT) & CP_LOAD_STATE_1_STATE_TYPE__MASK;
}

__attribute__((used)) static inline uint32_t CP_LOAD_STATE_1_EXT_SRC_ADDR(uint32_t val)
{
	return ((val >> 2) << CP_LOAD_STATE_1_EXT_SRC_ADDR__SHIFT) & CP_LOAD_STATE_1_EXT_SRC_ADDR__MASK;
}

__attribute__((used)) static inline uint32_t CP_LOAD_STATE4_0_DST_OFF(uint32_t val)
{
	return ((val) << CP_LOAD_STATE4_0_DST_OFF__SHIFT) & CP_LOAD_STATE4_0_DST_OFF__MASK;
}

__attribute__((used)) static inline uint32_t CP_LOAD_STATE4_0_STATE_SRC(enum a4xx_state_src val)
{
	return ((val) << CP_LOAD_STATE4_0_STATE_SRC__SHIFT) & CP_LOAD_STATE4_0_STATE_SRC__MASK;
}

__attribute__((used)) static inline uint32_t CP_LOAD_STATE4_0_STATE_BLOCK(enum a4xx_state_block val)
{
	return ((val) << CP_LOAD_STATE4_0_STATE_BLOCK__SHIFT) & CP_LOAD_STATE4_0_STATE_BLOCK__MASK;
}

__attribute__((used)) static inline uint32_t CP_LOAD_STATE4_0_NUM_UNIT(uint32_t val)
{
	return ((val) << CP_LOAD_STATE4_0_NUM_UNIT__SHIFT) & CP_LOAD_STATE4_0_NUM_UNIT__MASK;
}

__attribute__((used)) static inline uint32_t CP_LOAD_STATE4_1_STATE_TYPE(enum a4xx_state_type val)
{
	return ((val) << CP_LOAD_STATE4_1_STATE_TYPE__SHIFT) & CP_LOAD_STATE4_1_STATE_TYPE__MASK;
}

__attribute__((used)) static inline uint32_t CP_LOAD_STATE4_1_EXT_SRC_ADDR(uint32_t val)
{
	return ((val >> 2) << CP_LOAD_STATE4_1_EXT_SRC_ADDR__SHIFT) & CP_LOAD_STATE4_1_EXT_SRC_ADDR__MASK;
}

__attribute__((used)) static inline uint32_t CP_LOAD_STATE4_2_EXT_SRC_ADDR_HI(uint32_t val)
{
	return ((val) << CP_LOAD_STATE4_2_EXT_SRC_ADDR_HI__SHIFT) & CP_LOAD_STATE4_2_EXT_SRC_ADDR_HI__MASK;
}

__attribute__((used)) static inline uint32_t CP_LOAD_STATE6_0_DST_OFF(uint32_t val)
{
	return ((val) << CP_LOAD_STATE6_0_DST_OFF__SHIFT) & CP_LOAD_STATE6_0_DST_OFF__MASK;
}

__attribute__((used)) static inline uint32_t CP_LOAD_STATE6_0_STATE_TYPE(enum a6xx_state_type val)
{
	return ((val) << CP_LOAD_STATE6_0_STATE_TYPE__SHIFT) & CP_LOAD_STATE6_0_STATE_TYPE__MASK;
}

__attribute__((used)) static inline uint32_t CP_LOAD_STATE6_0_STATE_SRC(enum a6xx_state_src val)
{
	return ((val) << CP_LOAD_STATE6_0_STATE_SRC__SHIFT) & CP_LOAD_STATE6_0_STATE_SRC__MASK;
}

__attribute__((used)) static inline uint32_t CP_LOAD_STATE6_0_STATE_BLOCK(enum a6xx_state_block val)
{
	return ((val) << CP_LOAD_STATE6_0_STATE_BLOCK__SHIFT) & CP_LOAD_STATE6_0_STATE_BLOCK__MASK;
}

__attribute__((used)) static inline uint32_t CP_LOAD_STATE6_0_NUM_UNIT(uint32_t val)
{
	return ((val) << CP_LOAD_STATE6_0_NUM_UNIT__SHIFT) & CP_LOAD_STATE6_0_NUM_UNIT__MASK;
}

__attribute__((used)) static inline uint32_t CP_LOAD_STATE6_1_EXT_SRC_ADDR(uint32_t val)
{
	return ((val >> 2) << CP_LOAD_STATE6_1_EXT_SRC_ADDR__SHIFT) & CP_LOAD_STATE6_1_EXT_SRC_ADDR__MASK;
}

__attribute__((used)) static inline uint32_t CP_LOAD_STATE6_2_EXT_SRC_ADDR_HI(uint32_t val)
{
	return ((val) << CP_LOAD_STATE6_2_EXT_SRC_ADDR_HI__SHIFT) & CP_LOAD_STATE6_2_EXT_SRC_ADDR_HI__MASK;
}

__attribute__((used)) static inline uint32_t CP_DRAW_INDX_0_VIZ_QUERY(uint32_t val)
{
	return ((val) << CP_DRAW_INDX_0_VIZ_QUERY__SHIFT) & CP_DRAW_INDX_0_VIZ_QUERY__MASK;
}

__attribute__((used)) static inline uint32_t CP_DRAW_INDX_1_PRIM_TYPE(enum pc_di_primtype val)
{
	return ((val) << CP_DRAW_INDX_1_PRIM_TYPE__SHIFT) & CP_DRAW_INDX_1_PRIM_TYPE__MASK;
}

__attribute__((used)) static inline uint32_t CP_DRAW_INDX_1_SOURCE_SELECT(enum pc_di_src_sel val)
{
	return ((val) << CP_DRAW_INDX_1_SOURCE_SELECT__SHIFT) & CP_DRAW_INDX_1_SOURCE_SELECT__MASK;
}

__attribute__((used)) static inline uint32_t CP_DRAW_INDX_1_VIS_CULL(enum pc_di_vis_cull_mode val)
{
	return ((val) << CP_DRAW_INDX_1_VIS_CULL__SHIFT) & CP_DRAW_INDX_1_VIS_CULL__MASK;
}

__attribute__((used)) static inline uint32_t CP_DRAW_INDX_1_INDEX_SIZE(enum pc_di_index_size val)
{
	return ((val) << CP_DRAW_INDX_1_INDEX_SIZE__SHIFT) & CP_DRAW_INDX_1_INDEX_SIZE__MASK;
}

__attribute__((used)) static inline uint32_t CP_DRAW_INDX_1_NUM_INSTANCES(uint32_t val)
{
	return ((val) << CP_DRAW_INDX_1_NUM_INSTANCES__SHIFT) & CP_DRAW_INDX_1_NUM_INSTANCES__MASK;
}

__attribute__((used)) static inline uint32_t CP_DRAW_INDX_2_NUM_INDICES(uint32_t val)
{
	return ((val) << CP_DRAW_INDX_2_NUM_INDICES__SHIFT) & CP_DRAW_INDX_2_NUM_INDICES__MASK;
}

__attribute__((used)) static inline uint32_t CP_DRAW_INDX_3_INDX_BASE(uint32_t val)
{
	return ((val) << CP_DRAW_INDX_3_INDX_BASE__SHIFT) & CP_DRAW_INDX_3_INDX_BASE__MASK;
}

__attribute__((used)) static inline uint32_t CP_DRAW_INDX_4_INDX_SIZE(uint32_t val)
{
	return ((val) << CP_DRAW_INDX_4_INDX_SIZE__SHIFT) & CP_DRAW_INDX_4_INDX_SIZE__MASK;
}

__attribute__((used)) static inline uint32_t CP_DRAW_INDX_2_0_VIZ_QUERY(uint32_t val)
{
	return ((val) << CP_DRAW_INDX_2_0_VIZ_QUERY__SHIFT) & CP_DRAW_INDX_2_0_VIZ_QUERY__MASK;
}

__attribute__((used)) static inline uint32_t CP_DRAW_INDX_2_1_PRIM_TYPE(enum pc_di_primtype val)
{
	return ((val) << CP_DRAW_INDX_2_1_PRIM_TYPE__SHIFT) & CP_DRAW_INDX_2_1_PRIM_TYPE__MASK;
}

__attribute__((used)) static inline uint32_t CP_DRAW_INDX_2_1_SOURCE_SELECT(enum pc_di_src_sel val)
{
	return ((val) << CP_DRAW_INDX_2_1_SOURCE_SELECT__SHIFT) & CP_DRAW_INDX_2_1_SOURCE_SELECT__MASK;
}

__attribute__((used)) static inline uint32_t CP_DRAW_INDX_2_1_VIS_CULL(enum pc_di_vis_cull_mode val)
{
	return ((val) << CP_DRAW_INDX_2_1_VIS_CULL__SHIFT) & CP_DRAW_INDX_2_1_VIS_CULL__MASK;
}

__attribute__((used)) static inline uint32_t CP_DRAW_INDX_2_1_INDEX_SIZE(enum pc_di_index_size val)
{
	return ((val) << CP_DRAW_INDX_2_1_INDEX_SIZE__SHIFT) & CP_DRAW_INDX_2_1_INDEX_SIZE__MASK;
}

__attribute__((used)) static inline uint32_t CP_DRAW_INDX_2_1_NUM_INSTANCES(uint32_t val)
{
	return ((val) << CP_DRAW_INDX_2_1_NUM_INSTANCES__SHIFT) & CP_DRAW_INDX_2_1_NUM_INSTANCES__MASK;
}

__attribute__((used)) static inline uint32_t CP_DRAW_INDX_2_2_NUM_INDICES(uint32_t val)
{
	return ((val) << CP_DRAW_INDX_2_2_NUM_INDICES__SHIFT) & CP_DRAW_INDX_2_2_NUM_INDICES__MASK;
}

__attribute__((used)) static inline uint32_t CP_DRAW_INDX_OFFSET_0_PRIM_TYPE(enum pc_di_primtype val)
{
	return ((val) << CP_DRAW_INDX_OFFSET_0_PRIM_TYPE__SHIFT) & CP_DRAW_INDX_OFFSET_0_PRIM_TYPE__MASK;
}

__attribute__((used)) static inline uint32_t CP_DRAW_INDX_OFFSET_0_SOURCE_SELECT(enum pc_di_src_sel val)
{
	return ((val) << CP_DRAW_INDX_OFFSET_0_SOURCE_SELECT__SHIFT) & CP_DRAW_INDX_OFFSET_0_SOURCE_SELECT__MASK;
}

__attribute__((used)) static inline uint32_t CP_DRAW_INDX_OFFSET_0_VIS_CULL(enum pc_di_vis_cull_mode val)
{
	return ((val) << CP_DRAW_INDX_OFFSET_0_VIS_CULL__SHIFT) & CP_DRAW_INDX_OFFSET_0_VIS_CULL__MASK;
}

__attribute__((used)) static inline uint32_t CP_DRAW_INDX_OFFSET_0_INDEX_SIZE(enum a4xx_index_size val)
{
	return ((val) << CP_DRAW_INDX_OFFSET_0_INDEX_SIZE__SHIFT) & CP_DRAW_INDX_OFFSET_0_INDEX_SIZE__MASK;
}

__attribute__((used)) static inline uint32_t CP_DRAW_INDX_OFFSET_0_TESS_MODE(uint32_t val)
{
	return ((val) << CP_DRAW_INDX_OFFSET_0_TESS_MODE__SHIFT) & CP_DRAW_INDX_OFFSET_0_TESS_MODE__MASK;
}

__attribute__((used)) static inline uint32_t CP_DRAW_INDX_OFFSET_1_NUM_INSTANCES(uint32_t val)
{
	return ((val) << CP_DRAW_INDX_OFFSET_1_NUM_INSTANCES__SHIFT) & CP_DRAW_INDX_OFFSET_1_NUM_INSTANCES__MASK;
}

__attribute__((used)) static inline uint32_t CP_DRAW_INDX_OFFSET_2_NUM_INDICES(uint32_t val)
{
	return ((val) << CP_DRAW_INDX_OFFSET_2_NUM_INDICES__SHIFT) & CP_DRAW_INDX_OFFSET_2_NUM_INDICES__MASK;
}

__attribute__((used)) static inline uint32_t CP_DRAW_INDX_OFFSET_4_INDX_BASE(uint32_t val)
{
	return ((val) << CP_DRAW_INDX_OFFSET_4_INDX_BASE__SHIFT) & CP_DRAW_INDX_OFFSET_4_INDX_BASE__MASK;
}

__attribute__((used)) static inline uint32_t CP_DRAW_INDX_OFFSET_5_INDX_SIZE(uint32_t val)
{
	return ((val) << CP_DRAW_INDX_OFFSET_5_INDX_SIZE__SHIFT) & CP_DRAW_INDX_OFFSET_5_INDX_SIZE__MASK;
}

__attribute__((used)) static inline uint32_t A4XX_CP_DRAW_INDIRECT_0_PRIM_TYPE(enum pc_di_primtype val)
{
	return ((val) << A4XX_CP_DRAW_INDIRECT_0_PRIM_TYPE__SHIFT) & A4XX_CP_DRAW_INDIRECT_0_PRIM_TYPE__MASK;
}

__attribute__((used)) static inline uint32_t A4XX_CP_DRAW_INDIRECT_0_SOURCE_SELECT(enum pc_di_src_sel val)
{
	return ((val) << A4XX_CP_DRAW_INDIRECT_0_SOURCE_SELECT__SHIFT) & A4XX_CP_DRAW_INDIRECT_0_SOURCE_SELECT__MASK;
}

__attribute__((used)) static inline uint32_t A4XX_CP_DRAW_INDIRECT_0_VIS_CULL(enum pc_di_vis_cull_mode val)
{
	return ((val) << A4XX_CP_DRAW_INDIRECT_0_VIS_CULL__SHIFT) & A4XX_CP_DRAW_INDIRECT_0_VIS_CULL__MASK;
}

__attribute__((used)) static inline uint32_t A4XX_CP_DRAW_INDIRECT_0_INDEX_SIZE(enum a4xx_index_size val)
{
	return ((val) << A4XX_CP_DRAW_INDIRECT_0_INDEX_SIZE__SHIFT) & A4XX_CP_DRAW_INDIRECT_0_INDEX_SIZE__MASK;
}

__attribute__((used)) static inline uint32_t A4XX_CP_DRAW_INDIRECT_0_TESS_MODE(uint32_t val)
{
	return ((val) << A4XX_CP_DRAW_INDIRECT_0_TESS_MODE__SHIFT) & A4XX_CP_DRAW_INDIRECT_0_TESS_MODE__MASK;
}

__attribute__((used)) static inline uint32_t A4XX_CP_DRAW_INDIRECT_1_INDIRECT(uint32_t val)
{
	return ((val) << A4XX_CP_DRAW_INDIRECT_1_INDIRECT__SHIFT) & A4XX_CP_DRAW_INDIRECT_1_INDIRECT__MASK;
}

__attribute__((used)) static inline uint32_t A5XX_CP_DRAW_INDIRECT_2_INDIRECT_HI(uint32_t val)
{
	return ((val) << A5XX_CP_DRAW_INDIRECT_2_INDIRECT_HI__SHIFT) & A5XX_CP_DRAW_INDIRECT_2_INDIRECT_HI__MASK;
}

__attribute__((used)) static inline uint32_t A4XX_CP_DRAW_INDX_INDIRECT_0_PRIM_TYPE(enum pc_di_primtype val)
{
	return ((val) << A4XX_CP_DRAW_INDX_INDIRECT_0_PRIM_TYPE__SHIFT) & A4XX_CP_DRAW_INDX_INDIRECT_0_PRIM_TYPE__MASK;
}

__attribute__((used)) static inline uint32_t A4XX_CP_DRAW_INDX_INDIRECT_0_SOURCE_SELECT(enum pc_di_src_sel val)
{
	return ((val) << A4XX_CP_DRAW_INDX_INDIRECT_0_SOURCE_SELECT__SHIFT) & A4XX_CP_DRAW_INDX_INDIRECT_0_SOURCE_SELECT__MASK;
}

__attribute__((used)) static inline uint32_t A4XX_CP_DRAW_INDX_INDIRECT_0_VIS_CULL(enum pc_di_vis_cull_mode val)
{
	return ((val) << A4XX_CP_DRAW_INDX_INDIRECT_0_VIS_CULL__SHIFT) & A4XX_CP_DRAW_INDX_INDIRECT_0_VIS_CULL__MASK;
}

__attribute__((used)) static inline uint32_t A4XX_CP_DRAW_INDX_INDIRECT_0_INDEX_SIZE(enum a4xx_index_size val)
{
	return ((val) << A4XX_CP_DRAW_INDX_INDIRECT_0_INDEX_SIZE__SHIFT) & A4XX_CP_DRAW_INDX_INDIRECT_0_INDEX_SIZE__MASK;
}

__attribute__((used)) static inline uint32_t A4XX_CP_DRAW_INDX_INDIRECT_0_TESS_MODE(uint32_t val)
{
	return ((val) << A4XX_CP_DRAW_INDX_INDIRECT_0_TESS_MODE__SHIFT) & A4XX_CP_DRAW_INDX_INDIRECT_0_TESS_MODE__MASK;
}

__attribute__((used)) static inline uint32_t A4XX_CP_DRAW_INDX_INDIRECT_1_INDX_BASE(uint32_t val)
{
	return ((val) << A4XX_CP_DRAW_INDX_INDIRECT_1_INDX_BASE__SHIFT) & A4XX_CP_DRAW_INDX_INDIRECT_1_INDX_BASE__MASK;
}

__attribute__((used)) static inline uint32_t A4XX_CP_DRAW_INDX_INDIRECT_2_INDX_SIZE(uint32_t val)
{
	return ((val) << A4XX_CP_DRAW_INDX_INDIRECT_2_INDX_SIZE__SHIFT) & A4XX_CP_DRAW_INDX_INDIRECT_2_INDX_SIZE__MASK;
}

__attribute__((used)) static inline uint32_t A4XX_CP_DRAW_INDX_INDIRECT_3_INDIRECT(uint32_t val)
{
	return ((val) << A4XX_CP_DRAW_INDX_INDIRECT_3_INDIRECT__SHIFT) & A4XX_CP_DRAW_INDX_INDIRECT_3_INDIRECT__MASK;
}

__attribute__((used)) static inline uint32_t A5XX_CP_DRAW_INDX_INDIRECT_1_INDX_BASE_LO(uint32_t val)
{
	return ((val) << A5XX_CP_DRAW_INDX_INDIRECT_1_INDX_BASE_LO__SHIFT) & A5XX_CP_DRAW_INDX_INDIRECT_1_INDX_BASE_LO__MASK;
}

__attribute__((used)) static inline uint32_t A5XX_CP_DRAW_INDX_INDIRECT_2_INDX_BASE_HI(uint32_t val)
{
	return ((val) << A5XX_CP_DRAW_INDX_INDIRECT_2_INDX_BASE_HI__SHIFT) & A5XX_CP_DRAW_INDX_INDIRECT_2_INDX_BASE_HI__MASK;
}

__attribute__((used)) static inline uint32_t A5XX_CP_DRAW_INDX_INDIRECT_3_MAX_INDICES(uint32_t val)
{
	return ((val) << A5XX_CP_DRAW_INDX_INDIRECT_3_MAX_INDICES__SHIFT) & A5XX_CP_DRAW_INDX_INDIRECT_3_MAX_INDICES__MASK;
}

__attribute__((used)) static inline uint32_t A5XX_CP_DRAW_INDX_INDIRECT_4_INDIRECT_LO(uint32_t val)
{
	return ((val) << A5XX_CP_DRAW_INDX_INDIRECT_4_INDIRECT_LO__SHIFT) & A5XX_CP_DRAW_INDX_INDIRECT_4_INDIRECT_LO__MASK;
}

__attribute__((used)) static inline uint32_t A5XX_CP_DRAW_INDX_INDIRECT_5_INDIRECT_HI(uint32_t val)
{
	return ((val) << A5XX_CP_DRAW_INDX_INDIRECT_5_INDIRECT_HI__SHIFT) & A5XX_CP_DRAW_INDX_INDIRECT_5_INDIRECT_HI__MASK;
}

__attribute__((used)) static inline uint32_t REG_CP_SET_DRAW_STATE_(uint32_t i0) { return 0x00000000 + 0x3*i0; }

__attribute__((used)) static inline uint32_t REG_CP_SET_DRAW_STATE__0(uint32_t i0) { return 0x00000000 + 0x3*i0; }

__attribute__((used)) static inline uint32_t CP_SET_DRAW_STATE__0_COUNT(uint32_t val)
{
	return ((val) << CP_SET_DRAW_STATE__0_COUNT__SHIFT) & CP_SET_DRAW_STATE__0_COUNT__MASK;
}

__attribute__((used)) static inline uint32_t CP_SET_DRAW_STATE__0_ENABLE_MASK(uint32_t val)
{
	return ((val) << CP_SET_DRAW_STATE__0_ENABLE_MASK__SHIFT) & CP_SET_DRAW_STATE__0_ENABLE_MASK__MASK;
}

__attribute__((used)) static inline uint32_t CP_SET_DRAW_STATE__0_GROUP_ID(uint32_t val)
{
	return ((val) << CP_SET_DRAW_STATE__0_GROUP_ID__SHIFT) & CP_SET_DRAW_STATE__0_GROUP_ID__MASK;
}

__attribute__((used)) static inline uint32_t REG_CP_SET_DRAW_STATE__1(uint32_t i0) { return 0x00000001 + 0x3*i0; }

__attribute__((used)) static inline uint32_t CP_SET_DRAW_STATE__1_ADDR_LO(uint32_t val)
{
	return ((val) << CP_SET_DRAW_STATE__1_ADDR_LO__SHIFT) & CP_SET_DRAW_STATE__1_ADDR_LO__MASK;
}

__attribute__((used)) static inline uint32_t REG_CP_SET_DRAW_STATE__2(uint32_t i0) { return 0x00000002 + 0x3*i0; }

__attribute__((used)) static inline uint32_t CP_SET_DRAW_STATE__2_ADDR_HI(uint32_t val)
{
	return ((val) << CP_SET_DRAW_STATE__2_ADDR_HI__SHIFT) & CP_SET_DRAW_STATE__2_ADDR_HI__MASK;
}

__attribute__((used)) static inline uint32_t CP_SET_BIN_1_X1(uint32_t val)
{
	return ((val) << CP_SET_BIN_1_X1__SHIFT) & CP_SET_BIN_1_X1__MASK;
}

__attribute__((used)) static inline uint32_t CP_SET_BIN_1_Y1(uint32_t val)
{
	return ((val) << CP_SET_BIN_1_Y1__SHIFT) & CP_SET_BIN_1_Y1__MASK;
}

__attribute__((used)) static inline uint32_t CP_SET_BIN_2_X2(uint32_t val)
{
	return ((val) << CP_SET_BIN_2_X2__SHIFT) & CP_SET_BIN_2_X2__MASK;
}

__attribute__((used)) static inline uint32_t CP_SET_BIN_2_Y2(uint32_t val)
{
	return ((val) << CP_SET_BIN_2_Y2__SHIFT) & CP_SET_BIN_2_Y2__MASK;
}

__attribute__((used)) static inline uint32_t CP_SET_BIN_DATA_0_BIN_DATA_ADDR(uint32_t val)
{
	return ((val) << CP_SET_BIN_DATA_0_BIN_DATA_ADDR__SHIFT) & CP_SET_BIN_DATA_0_BIN_DATA_ADDR__MASK;
}

__attribute__((used)) static inline uint32_t CP_SET_BIN_DATA_1_BIN_SIZE_ADDRESS(uint32_t val)
{
	return ((val) << CP_SET_BIN_DATA_1_BIN_SIZE_ADDRESS__SHIFT) & CP_SET_BIN_DATA_1_BIN_SIZE_ADDRESS__MASK;
}

__attribute__((used)) static inline uint32_t CP_SET_BIN_DATA5_0_VSC_SIZE(uint32_t val)
{
	return ((val) << CP_SET_BIN_DATA5_0_VSC_SIZE__SHIFT) & CP_SET_BIN_DATA5_0_VSC_SIZE__MASK;
}

__attribute__((used)) static inline uint32_t CP_SET_BIN_DATA5_0_VSC_N(uint32_t val)
{
	return ((val) << CP_SET_BIN_DATA5_0_VSC_N__SHIFT) & CP_SET_BIN_DATA5_0_VSC_N__MASK;
}

__attribute__((used)) static inline uint32_t CP_SET_BIN_DATA5_1_BIN_DATA_ADDR_LO(uint32_t val)
{
	return ((val) << CP_SET_BIN_DATA5_1_BIN_DATA_ADDR_LO__SHIFT) & CP_SET_BIN_DATA5_1_BIN_DATA_ADDR_LO__MASK;
}

__attribute__((used)) static inline uint32_t CP_SET_BIN_DATA5_2_BIN_DATA_ADDR_HI(uint32_t val)
{
	return ((val) << CP_SET_BIN_DATA5_2_BIN_DATA_ADDR_HI__SHIFT) & CP_SET_BIN_DATA5_2_BIN_DATA_ADDR_HI__MASK;
}

__attribute__((used)) static inline uint32_t CP_SET_BIN_DATA5_3_BIN_SIZE_ADDRESS_LO(uint32_t val)
{
	return ((val) << CP_SET_BIN_DATA5_3_BIN_SIZE_ADDRESS_LO__SHIFT) & CP_SET_BIN_DATA5_3_BIN_SIZE_ADDRESS_LO__MASK;
}

__attribute__((used)) static inline uint32_t CP_SET_BIN_DATA5_4_BIN_SIZE_ADDRESS_HI(uint32_t val)
{
	return ((val) << CP_SET_BIN_DATA5_4_BIN_SIZE_ADDRESS_HI__SHIFT) & CP_SET_BIN_DATA5_4_BIN_SIZE_ADDRESS_HI__MASK;
}

__attribute__((used)) static inline uint32_t CP_SET_BIN_DATA5_5_XXX_ADDRESS_LO(uint32_t val)
{
	return ((val) << CP_SET_BIN_DATA5_5_XXX_ADDRESS_LO__SHIFT) & CP_SET_BIN_DATA5_5_XXX_ADDRESS_LO__MASK;
}

__attribute__((used)) static inline uint32_t CP_SET_BIN_DATA5_6_XXX_ADDRESS_HI(uint32_t val)
{
	return ((val) << CP_SET_BIN_DATA5_6_XXX_ADDRESS_HI__SHIFT) & CP_SET_BIN_DATA5_6_XXX_ADDRESS_HI__MASK;
}

__attribute__((used)) static inline uint32_t CP_REG_TO_MEM_0_REG(uint32_t val)
{
	return ((val) << CP_REG_TO_MEM_0_REG__SHIFT) & CP_REG_TO_MEM_0_REG__MASK;
}

__attribute__((used)) static inline uint32_t CP_REG_TO_MEM_0_CNT(uint32_t val)
{
	return ((val) << CP_REG_TO_MEM_0_CNT__SHIFT) & CP_REG_TO_MEM_0_CNT__MASK;
}

__attribute__((used)) static inline uint32_t CP_REG_TO_MEM_1_DEST(uint32_t val)
{
	return ((val) << CP_REG_TO_MEM_1_DEST__SHIFT) & CP_REG_TO_MEM_1_DEST__MASK;
}

__attribute__((used)) static inline uint32_t CP_REG_TO_MEM_2_DEST_HI(uint32_t val)
{
	return ((val) << CP_REG_TO_MEM_2_DEST_HI__SHIFT) & CP_REG_TO_MEM_2_DEST_HI__MASK;
}

__attribute__((used)) static inline uint32_t CP_MEM_TO_REG_0_REG(uint32_t val)
{
	return ((val) << CP_MEM_TO_REG_0_REG__SHIFT) & CP_MEM_TO_REG_0_REG__MASK;
}

__attribute__((used)) static inline uint32_t CP_MEM_TO_REG_0_CNT(uint32_t val)
{
	return ((val) << CP_MEM_TO_REG_0_CNT__SHIFT) & CP_MEM_TO_REG_0_CNT__MASK;
}

__attribute__((used)) static inline uint32_t CP_MEM_TO_REG_1_SRC(uint32_t val)
{
	return ((val) << CP_MEM_TO_REG_1_SRC__SHIFT) & CP_MEM_TO_REG_1_SRC__MASK;
}

__attribute__((used)) static inline uint32_t CP_MEM_TO_REG_2_SRC_HI(uint32_t val)
{
	return ((val) << CP_MEM_TO_REG_2_SRC_HI__SHIFT) & CP_MEM_TO_REG_2_SRC_HI__MASK;
}

__attribute__((used)) static inline uint32_t CP_COND_WRITE_0_FUNCTION(enum cp_cond_function val)
{
	return ((val) << CP_COND_WRITE_0_FUNCTION__SHIFT) & CP_COND_WRITE_0_FUNCTION__MASK;
}

__attribute__((used)) static inline uint32_t CP_COND_WRITE_1_POLL_ADDR(uint32_t val)
{
	return ((val) << CP_COND_WRITE_1_POLL_ADDR__SHIFT) & CP_COND_WRITE_1_POLL_ADDR__MASK;
}

__attribute__((used)) static inline uint32_t CP_COND_WRITE_2_REF(uint32_t val)
{
	return ((val) << CP_COND_WRITE_2_REF__SHIFT) & CP_COND_WRITE_2_REF__MASK;
}

__attribute__((used)) static inline uint32_t CP_COND_WRITE_3_MASK(uint32_t val)
{
	return ((val) << CP_COND_WRITE_3_MASK__SHIFT) & CP_COND_WRITE_3_MASK__MASK;
}

__attribute__((used)) static inline uint32_t CP_COND_WRITE_4_WRITE_ADDR(uint32_t val)
{
	return ((val) << CP_COND_WRITE_4_WRITE_ADDR__SHIFT) & CP_COND_WRITE_4_WRITE_ADDR__MASK;
}

__attribute__((used)) static inline uint32_t CP_COND_WRITE_5_WRITE_DATA(uint32_t val)
{
	return ((val) << CP_COND_WRITE_5_WRITE_DATA__SHIFT) & CP_COND_WRITE_5_WRITE_DATA__MASK;
}

__attribute__((used)) static inline uint32_t CP_COND_WRITE5_0_FUNCTION(enum cp_cond_function val)
{
	return ((val) << CP_COND_WRITE5_0_FUNCTION__SHIFT) & CP_COND_WRITE5_0_FUNCTION__MASK;
}

__attribute__((used)) static inline uint32_t CP_COND_WRITE5_1_POLL_ADDR_LO(uint32_t val)
{
	return ((val) << CP_COND_WRITE5_1_POLL_ADDR_LO__SHIFT) & CP_COND_WRITE5_1_POLL_ADDR_LO__MASK;
}

__attribute__((used)) static inline uint32_t CP_COND_WRITE5_2_POLL_ADDR_HI(uint32_t val)
{
	return ((val) << CP_COND_WRITE5_2_POLL_ADDR_HI__SHIFT) & CP_COND_WRITE5_2_POLL_ADDR_HI__MASK;
}

__attribute__((used)) static inline uint32_t CP_COND_WRITE5_3_REF(uint32_t val)
{
	return ((val) << CP_COND_WRITE5_3_REF__SHIFT) & CP_COND_WRITE5_3_REF__MASK;
}

__attribute__((used)) static inline uint32_t CP_COND_WRITE5_4_MASK(uint32_t val)
{
	return ((val) << CP_COND_WRITE5_4_MASK__SHIFT) & CP_COND_WRITE5_4_MASK__MASK;
}

__attribute__((used)) static inline uint32_t CP_COND_WRITE5_5_WRITE_ADDR_LO(uint32_t val)
{
	return ((val) << CP_COND_WRITE5_5_WRITE_ADDR_LO__SHIFT) & CP_COND_WRITE5_5_WRITE_ADDR_LO__MASK;
}

__attribute__((used)) static inline uint32_t CP_COND_WRITE5_6_WRITE_ADDR_HI(uint32_t val)
{
	return ((val) << CP_COND_WRITE5_6_WRITE_ADDR_HI__SHIFT) & CP_COND_WRITE5_6_WRITE_ADDR_HI__MASK;
}

__attribute__((used)) static inline uint32_t CP_COND_WRITE5_7_WRITE_DATA(uint32_t val)
{
	return ((val) << CP_COND_WRITE5_7_WRITE_DATA__SHIFT) & CP_COND_WRITE5_7_WRITE_DATA__MASK;
}

__attribute__((used)) static inline uint32_t CP_DISPATCH_COMPUTE_1_X(uint32_t val)
{
	return ((val) << CP_DISPATCH_COMPUTE_1_X__SHIFT) & CP_DISPATCH_COMPUTE_1_X__MASK;
}

__attribute__((used)) static inline uint32_t CP_DISPATCH_COMPUTE_2_Y(uint32_t val)
{
	return ((val) << CP_DISPATCH_COMPUTE_2_Y__SHIFT) & CP_DISPATCH_COMPUTE_2_Y__MASK;
}

__attribute__((used)) static inline uint32_t CP_DISPATCH_COMPUTE_3_Z(uint32_t val)
{
	return ((val) << CP_DISPATCH_COMPUTE_3_Z__SHIFT) & CP_DISPATCH_COMPUTE_3_Z__MASK;
}

__attribute__((used)) static inline uint32_t CP_SET_RENDER_MODE_0_MODE(enum render_mode_cmd val)
{
	return ((val) << CP_SET_RENDER_MODE_0_MODE__SHIFT) & CP_SET_RENDER_MODE_0_MODE__MASK;
}

__attribute__((used)) static inline uint32_t CP_SET_RENDER_MODE_1_ADDR_0_LO(uint32_t val)
{
	return ((val) << CP_SET_RENDER_MODE_1_ADDR_0_LO__SHIFT) & CP_SET_RENDER_MODE_1_ADDR_0_LO__MASK;
}

__attribute__((used)) static inline uint32_t CP_SET_RENDER_MODE_2_ADDR_0_HI(uint32_t val)
{
	return ((val) << CP_SET_RENDER_MODE_2_ADDR_0_HI__SHIFT) & CP_SET_RENDER_MODE_2_ADDR_0_HI__MASK;
}

__attribute__((used)) static inline uint32_t CP_SET_RENDER_MODE_5_ADDR_1_LEN(uint32_t val)
{
	return ((val) << CP_SET_RENDER_MODE_5_ADDR_1_LEN__SHIFT) & CP_SET_RENDER_MODE_5_ADDR_1_LEN__MASK;
}

__attribute__((used)) static inline uint32_t CP_SET_RENDER_MODE_6_ADDR_1_LO(uint32_t val)
{
	return ((val) << CP_SET_RENDER_MODE_6_ADDR_1_LO__SHIFT) & CP_SET_RENDER_MODE_6_ADDR_1_LO__MASK;
}

__attribute__((used)) static inline uint32_t CP_SET_RENDER_MODE_7_ADDR_1_HI(uint32_t val)
{
	return ((val) << CP_SET_RENDER_MODE_7_ADDR_1_HI__SHIFT) & CP_SET_RENDER_MODE_7_ADDR_1_HI__MASK;
}

__attribute__((used)) static inline uint32_t CP_COMPUTE_CHECKPOINT_0_ADDR_0_LO(uint32_t val)
{
	return ((val) << CP_COMPUTE_CHECKPOINT_0_ADDR_0_LO__SHIFT) & CP_COMPUTE_CHECKPOINT_0_ADDR_0_LO__MASK;
}

__attribute__((used)) static inline uint32_t CP_COMPUTE_CHECKPOINT_1_ADDR_0_HI(uint32_t val)
{
	return ((val) << CP_COMPUTE_CHECKPOINT_1_ADDR_0_HI__SHIFT) & CP_COMPUTE_CHECKPOINT_1_ADDR_0_HI__MASK;
}

__attribute__((used)) static inline uint32_t CP_COMPUTE_CHECKPOINT_3_ADDR_1_LEN(uint32_t val)
{
	return ((val) << CP_COMPUTE_CHECKPOINT_3_ADDR_1_LEN__SHIFT) & CP_COMPUTE_CHECKPOINT_3_ADDR_1_LEN__MASK;
}

__attribute__((used)) static inline uint32_t CP_COMPUTE_CHECKPOINT_5_ADDR_1_LO(uint32_t val)
{
	return ((val) << CP_COMPUTE_CHECKPOINT_5_ADDR_1_LO__SHIFT) & CP_COMPUTE_CHECKPOINT_5_ADDR_1_LO__MASK;
}

__attribute__((used)) static inline uint32_t CP_COMPUTE_CHECKPOINT_6_ADDR_1_HI(uint32_t val)
{
	return ((val) << CP_COMPUTE_CHECKPOINT_6_ADDR_1_HI__SHIFT) & CP_COMPUTE_CHECKPOINT_6_ADDR_1_HI__MASK;
}

__attribute__((used)) static inline uint32_t CP_PERFCOUNTER_ACTION_1_ADDR_0_LO(uint32_t val)
{
	return ((val) << CP_PERFCOUNTER_ACTION_1_ADDR_0_LO__SHIFT) & CP_PERFCOUNTER_ACTION_1_ADDR_0_LO__MASK;
}

__attribute__((used)) static inline uint32_t CP_PERFCOUNTER_ACTION_2_ADDR_0_HI(uint32_t val)
{
	return ((val) << CP_PERFCOUNTER_ACTION_2_ADDR_0_HI__SHIFT) & CP_PERFCOUNTER_ACTION_2_ADDR_0_HI__MASK;
}

__attribute__((used)) static inline uint32_t CP_EVENT_WRITE_0_EVENT(enum vgt_event_type val)
{
	return ((val) << CP_EVENT_WRITE_0_EVENT__SHIFT) & CP_EVENT_WRITE_0_EVENT__MASK;
}

__attribute__((used)) static inline uint32_t CP_EVENT_WRITE_1_ADDR_0_LO(uint32_t val)
{
	return ((val) << CP_EVENT_WRITE_1_ADDR_0_LO__SHIFT) & CP_EVENT_WRITE_1_ADDR_0_LO__MASK;
}

__attribute__((used)) static inline uint32_t CP_EVENT_WRITE_2_ADDR_0_HI(uint32_t val)
{
	return ((val) << CP_EVENT_WRITE_2_ADDR_0_HI__SHIFT) & CP_EVENT_WRITE_2_ADDR_0_HI__MASK;
}

__attribute__((used)) static inline uint32_t CP_BLIT_0_OP(enum cp_blit_cmd val)
{
	return ((val) << CP_BLIT_0_OP__SHIFT) & CP_BLIT_0_OP__MASK;
}

__attribute__((used)) static inline uint32_t CP_BLIT_1_SRC_X1(uint32_t val)
{
	return ((val) << CP_BLIT_1_SRC_X1__SHIFT) & CP_BLIT_1_SRC_X1__MASK;
}

__attribute__((used)) static inline uint32_t CP_BLIT_1_SRC_Y1(uint32_t val)
{
	return ((val) << CP_BLIT_1_SRC_Y1__SHIFT) & CP_BLIT_1_SRC_Y1__MASK;
}

__attribute__((used)) static inline uint32_t CP_BLIT_2_SRC_X2(uint32_t val)
{
	return ((val) << CP_BLIT_2_SRC_X2__SHIFT) & CP_BLIT_2_SRC_X2__MASK;
}

__attribute__((used)) static inline uint32_t CP_BLIT_2_SRC_Y2(uint32_t val)
{
	return ((val) << CP_BLIT_2_SRC_Y2__SHIFT) & CP_BLIT_2_SRC_Y2__MASK;
}

__attribute__((used)) static inline uint32_t CP_BLIT_3_DST_X1(uint32_t val)
{
	return ((val) << CP_BLIT_3_DST_X1__SHIFT) & CP_BLIT_3_DST_X1__MASK;
}

__attribute__((used)) static inline uint32_t CP_BLIT_3_DST_Y1(uint32_t val)
{
	return ((val) << CP_BLIT_3_DST_Y1__SHIFT) & CP_BLIT_3_DST_Y1__MASK;
}

__attribute__((used)) static inline uint32_t CP_BLIT_4_DST_X2(uint32_t val)
{
	return ((val) << CP_BLIT_4_DST_X2__SHIFT) & CP_BLIT_4_DST_X2__MASK;
}

__attribute__((used)) static inline uint32_t CP_BLIT_4_DST_Y2(uint32_t val)
{
	return ((val) << CP_BLIT_4_DST_Y2__SHIFT) & CP_BLIT_4_DST_Y2__MASK;
}

__attribute__((used)) static inline uint32_t CP_EXEC_CS_1_NGROUPS_X(uint32_t val)
{
	return ((val) << CP_EXEC_CS_1_NGROUPS_X__SHIFT) & CP_EXEC_CS_1_NGROUPS_X__MASK;
}

__attribute__((used)) static inline uint32_t CP_EXEC_CS_2_NGROUPS_Y(uint32_t val)
{
	return ((val) << CP_EXEC_CS_2_NGROUPS_Y__SHIFT) & CP_EXEC_CS_2_NGROUPS_Y__MASK;
}

__attribute__((used)) static inline uint32_t CP_EXEC_CS_3_NGROUPS_Z(uint32_t val)
{
	return ((val) << CP_EXEC_CS_3_NGROUPS_Z__SHIFT) & CP_EXEC_CS_3_NGROUPS_Z__MASK;
}

__attribute__((used)) static inline uint32_t A4XX_CP_EXEC_CS_INDIRECT_1_ADDR(uint32_t val)
{
	return ((val) << A4XX_CP_EXEC_CS_INDIRECT_1_ADDR__SHIFT) & A4XX_CP_EXEC_CS_INDIRECT_1_ADDR__MASK;
}

__attribute__((used)) static inline uint32_t A4XX_CP_EXEC_CS_INDIRECT_2_LOCALSIZEX(uint32_t val)
{
	return ((val) << A4XX_CP_EXEC_CS_INDIRECT_2_LOCALSIZEX__SHIFT) & A4XX_CP_EXEC_CS_INDIRECT_2_LOCALSIZEX__MASK;
}

__attribute__((used)) static inline uint32_t A4XX_CP_EXEC_CS_INDIRECT_2_LOCALSIZEY(uint32_t val)
{
	return ((val) << A4XX_CP_EXEC_CS_INDIRECT_2_LOCALSIZEY__SHIFT) & A4XX_CP_EXEC_CS_INDIRECT_2_LOCALSIZEY__MASK;
}

__attribute__((used)) static inline uint32_t A4XX_CP_EXEC_CS_INDIRECT_2_LOCALSIZEZ(uint32_t val)
{
	return ((val) << A4XX_CP_EXEC_CS_INDIRECT_2_LOCALSIZEZ__SHIFT) & A4XX_CP_EXEC_CS_INDIRECT_2_LOCALSIZEZ__MASK;
}

__attribute__((used)) static inline uint32_t A5XX_CP_EXEC_CS_INDIRECT_1_ADDR_LO(uint32_t val)
{
	return ((val) << A5XX_CP_EXEC_CS_INDIRECT_1_ADDR_LO__SHIFT) & A5XX_CP_EXEC_CS_INDIRECT_1_ADDR_LO__MASK;
}

__attribute__((used)) static inline uint32_t A5XX_CP_EXEC_CS_INDIRECT_2_ADDR_HI(uint32_t val)
{
	return ((val) << A5XX_CP_EXEC_CS_INDIRECT_2_ADDR_HI__SHIFT) & A5XX_CP_EXEC_CS_INDIRECT_2_ADDR_HI__MASK;
}

__attribute__((used)) static inline uint32_t A5XX_CP_EXEC_CS_INDIRECT_3_LOCALSIZEX(uint32_t val)
{
	return ((val) << A5XX_CP_EXEC_CS_INDIRECT_3_LOCALSIZEX__SHIFT) & A5XX_CP_EXEC_CS_INDIRECT_3_LOCALSIZEX__MASK;
}

__attribute__((used)) static inline uint32_t A5XX_CP_EXEC_CS_INDIRECT_3_LOCALSIZEY(uint32_t val)
{
	return ((val) << A5XX_CP_EXEC_CS_INDIRECT_3_LOCALSIZEY__SHIFT) & A5XX_CP_EXEC_CS_INDIRECT_3_LOCALSIZEY__MASK;
}

__attribute__((used)) static inline uint32_t A5XX_CP_EXEC_CS_INDIRECT_3_LOCALSIZEZ(uint32_t val)
{
	return ((val) << A5XX_CP_EXEC_CS_INDIRECT_3_LOCALSIZEZ__SHIFT) & A5XX_CP_EXEC_CS_INDIRECT_3_LOCALSIZEZ__MASK;
}

__attribute__((used)) static inline uint32_t A2XX_CP_SET_MARKER_0_MARKER(uint32_t val)
{
	return ((val) << A2XX_CP_SET_MARKER_0_MARKER__SHIFT) & A2XX_CP_SET_MARKER_0_MARKER__MASK;
}

__attribute__((used)) static inline uint32_t A2XX_CP_SET_MARKER_0_MODE(enum a6xx_render_mode val)
{
	return ((val) << A2XX_CP_SET_MARKER_0_MODE__SHIFT) & A2XX_CP_SET_MARKER_0_MODE__MASK;
}

__attribute__((used)) static inline uint32_t REG_A2XX_CP_SET_PSEUDO_REG_(uint32_t i0) { return 0x00000000 + 0x3*i0; }

__attribute__((used)) static inline uint32_t REG_A2XX_CP_SET_PSEUDO_REG__0(uint32_t i0) { return 0x00000000 + 0x3*i0; }

__attribute__((used)) static inline uint32_t A2XX_CP_SET_PSEUDO_REG__0_PSEUDO_REG(enum pseudo_reg val)
{
	return ((val) << A2XX_CP_SET_PSEUDO_REG__0_PSEUDO_REG__SHIFT) & A2XX_CP_SET_PSEUDO_REG__0_PSEUDO_REG__MASK;
}

__attribute__((used)) static inline uint32_t REG_A2XX_CP_SET_PSEUDO_REG__1(uint32_t i0) { return 0x00000001 + 0x3*i0; }

__attribute__((used)) static inline uint32_t A2XX_CP_SET_PSEUDO_REG__1_LO(uint32_t val)
{
	return ((val) << A2XX_CP_SET_PSEUDO_REG__1_LO__SHIFT) & A2XX_CP_SET_PSEUDO_REG__1_LO__MASK;
}

__attribute__((used)) static inline uint32_t REG_A2XX_CP_SET_PSEUDO_REG__2(uint32_t i0) { return 0x00000002 + 0x3*i0; }

__attribute__((used)) static inline uint32_t A2XX_CP_SET_PSEUDO_REG__2_HI(uint32_t val)
{
	return ((val) << A2XX_CP_SET_PSEUDO_REG__2_HI__SHIFT) & A2XX_CP_SET_PSEUDO_REG__2_HI__MASK;
}

__attribute__((used)) static inline uint32_t A2XX_CP_REG_TEST_0_REG(uint32_t val)
{
	return ((val) << A2XX_CP_REG_TEST_0_REG__SHIFT) & A2XX_CP_REG_TEST_0_REG__MASK;
}

__attribute__((used)) static inline uint32_t A2XX_CP_REG_TEST_0_BIT(uint32_t val)
{
	return ((val) << A2XX_CP_REG_TEST_0_BIT__SHIFT) & A2XX_CP_REG_TEST_0_BIT__MASK;
}

__attribute__((used)) static inline bool adreno_is_a3xx(struct adreno_gpu *gpu)
{
	return (gpu->revn >= 300) && (gpu->revn < 400);
}

__attribute__((used)) static inline bool adreno_is_a305(struct adreno_gpu *gpu)
{
	return gpu->revn == 305;
}

__attribute__((used)) static inline bool adreno_is_a306(struct adreno_gpu *gpu)
{
	/* yes, 307, because a305c is 306 */
	return gpu->revn == 307;
}

__attribute__((used)) static inline bool adreno_is_a320(struct adreno_gpu *gpu)
{
	return gpu->revn == 320;
}

__attribute__((used)) static inline bool adreno_is_a330(struct adreno_gpu *gpu)
{
	return gpu->revn == 330;
}

__attribute__((used)) static inline bool adreno_is_a330v2(struct adreno_gpu *gpu)
{
	return adreno_is_a330(gpu) && (gpu->rev.patchid > 0);
}

__attribute__((used)) static inline bool adreno_is_a4xx(struct adreno_gpu *gpu)
{
	return (gpu->revn >= 400) && (gpu->revn < 500);
}

__attribute__((used)) static inline int adreno_is_a420(struct adreno_gpu *gpu)
{
	return gpu->revn == 420;
}

__attribute__((used)) static inline int adreno_is_a430(struct adreno_gpu *gpu)
{
       return gpu->revn == 430;
}

__attribute__((used)) static inline int adreno_is_a530(struct adreno_gpu *gpu)
{
	return gpu->revn == 530;
}

__attribute__((used)) static inline void
OUT_PKT0(struct msm_ringbuffer *ring, uint16_t regindx, uint16_t cnt)
{
	adreno_wait_ring(ring, cnt+1);
	OUT_RING(ring, CP_TYPE0_PKT | ((cnt-1) << 16) | (regindx & 0x7FFF));
}

__attribute__((used)) static inline void
OUT_PKT2(struct msm_ringbuffer *ring)
{
	adreno_wait_ring(ring, 1);
	OUT_RING(ring, CP_TYPE2_PKT);
}

__attribute__((used)) static inline void
OUT_PKT3(struct msm_ringbuffer *ring, uint8_t opcode, uint16_t cnt)
{
	adreno_wait_ring(ring, cnt+1);
	OUT_RING(ring, CP_TYPE3_PKT | ((cnt-1) << 16) | ((opcode & 0xFF) << 8));
}

__attribute__((used)) static inline u32 PM4_PARITY(u32 val)
{
	return (0x9669 >> (0xF & (val ^
		(val >> 4) ^ (val >> 8) ^ (val >> 12) ^
		(val >> 16) ^ ((val) >> 20) ^ (val >> 24) ^
		(val >> 28)))) & 1;
}

__attribute__((used)) static inline void
OUT_PKT4(struct msm_ringbuffer *ring, uint16_t regindx, uint16_t cnt)
{
	adreno_wait_ring(ring, cnt + 1);
	OUT_RING(ring, PKT4(regindx, cnt));
}

__attribute__((used)) static inline void
OUT_PKT7(struct msm_ringbuffer *ring, uint8_t opcode, uint16_t cnt)
{
	adreno_wait_ring(ring, cnt + 1);
	OUT_RING(ring, CP_TYPE7_PKT | (cnt << 0) | (PM4_PARITY(cnt) << 15) |
		((opcode & 0x7F) << 16) | (PM4_PARITY(opcode) << 23));
}

__attribute__((used)) static inline bool adreno_reg_check(struct adreno_gpu *gpu,
		enum adreno_regs offset_name)
{
	if (offset_name >= REG_ADRENO_REGISTER_MAX ||
			!gpu->reg_offsets[offset_name]) {
		BUG();
	}

	/*
	 * REG_SKIP is a special value that tell us that the register in
	 * question isn't implemented on target but don't trigger a BUG(). This
	 * is used to cleanly implement adreno_gpu_write64() and
	 * adreno_gpu_read64() in a generic fashion
	 */
	if (gpu->reg_offsets[offset_name] == REG_SKIP)
		return false;

	return true;
}

__attribute__((used)) static inline u32 adreno_gpu_read(struct adreno_gpu *gpu,
		enum adreno_regs offset_name)
{
	u32 reg = gpu->reg_offsets[offset_name];
	u32 val = 0;
	if(adreno_reg_check(gpu,offset_name))
		val = gpu_read(&gpu->base, reg - 1);
	return val;
}

__attribute__((used)) static inline void adreno_gpu_write(struct adreno_gpu *gpu,
		enum adreno_regs offset_name, u32 data)
{
	u32 reg = gpu->reg_offsets[offset_name];
	if(adreno_reg_check(gpu, offset_name))
		gpu_write(&gpu->base, reg - 1, data);
}

__attribute__((used)) static inline void adreno_gpu_write64(struct adreno_gpu *gpu,
		enum adreno_regs lo, enum adreno_regs hi, u64 data)
{
	adreno_gpu_write(gpu, lo, lower_32_bits(data));
	adreno_gpu_write(gpu, hi, upper_32_bits(data));
}

__attribute__((used)) static inline uint32_t get_wptr(struct msm_ringbuffer *ring)
{
	return (ring->cur - ring->start) % (MSM_GPU_RINGBUFFER_SZ >> 2);
}

__attribute__((used)) static inline bool _rev_match(uint8_t entry, uint8_t id)
{
	return (entry == ANY_ID) || (entry == id);
}

const struct adreno_info *adreno_info(struct adreno_rev rev)
{
	int i;

	/* identify gpu: */
	for (i = 0; i < ARRAY_SIZE(gpulist); i++) {
		const struct adreno_info *info = &gpulist[i];
		if (_rev_match(info->rev.core, rev.core) &&
				_rev_match(info->rev.major, rev.major) &&
				_rev_match(info->rev.minor, rev.minor) &&
				_rev_match(info->rev.patchid, rev.patchid))
			return info;
	}

	return NULL;
}

struct msm_gpu *adreno_load_gpu(struct drm_device *dev)
{
	struct msm_drm_private *priv = dev->dev_private;
	struct platform_device *pdev = priv->gpu_pdev;
	struct msm_gpu *gpu = NULL;
	struct adreno_gpu *adreno_gpu;
	int ret;

	if (pdev)
		gpu = platform_get_drvdata(pdev);

	if (!gpu) {
		dev_err_once(dev->dev, "no GPU device was found\n");
		return NULL;
	}

	adreno_gpu = to_adreno_gpu(gpu);

	/*
	 * The number one reason for HW init to fail is if the firmware isn't
	 * loaded yet. Try that first and don't bother continuing on
	 * otherwise
	 */

	ret = adreno_load_fw(adreno_gpu);
	if (ret)
		return NULL;

	/* Make sure pm runtime is active and reset any previous errors */
	pm_runtime_set_active(&pdev->dev);

	ret = pm_runtime_get_sync(&pdev->dev);
	if (ret < 0) {
		dev_err(dev->dev, "Couldn't power up the GPU: %d\n", ret);
		return NULL;
	}

	mutex_lock(&dev->struct_mutex);
	ret = msm_gpu_hw_init(gpu);
	mutex_unlock(&dev->struct_mutex);
	pm_runtime_put_autosuspend(&pdev->dev);
	if (ret) {
		dev_err(dev->dev, "gpu hw init failed: %d\n", ret);
		return NULL;
	}

#ifdef CONFIG_DEBUG_FS
	if (gpu->funcs->debugfs_init) {
		gpu->funcs->debugfs_init(gpu, dev->primary);
		gpu->funcs->debugfs_init(gpu, dev->render);
	}
#endif

	return gpu;
}

__attribute__((used)) static void set_gpu_pdev(struct drm_device *dev,
		struct platform_device *pdev)
{
	struct msm_drm_private *priv = dev->dev_private;
	priv->gpu_pdev = pdev;
}

__attribute__((used)) static int find_chipid(struct device *dev, struct adreno_rev *rev)
{
	struct device_node *node = dev->of_node;
	const char *compat;
	int ret;
	u32 chipid;

	/* first search the compat strings for qcom,adreno-XYZ.W: */
	ret = of_property_read_string_index(node, "compatible", 0, &compat);
	if (ret == 0) {
		unsigned int r, patch;

		if (sscanf(compat, "qcom,adreno-%u.%u", &r, &patch) == 2) {
			rev->core = r / 100;
			r %= 100;
			rev->major = r / 10;
			r %= 10;
			rev->minor = r;
			rev->patchid = patch;

			return 0;
		}
	}

	/* and if that fails, fall back to legacy "qcom,chipid" property: */
	ret = of_property_read_u32(node, "qcom,chipid", &chipid);
	if (ret) {
		dev_err(dev, "could not parse qcom,chipid: %d\n", ret);
		return ret;
	}

	rev->core = (chipid >> 24) & 0xff;
	rev->major = (chipid >> 16) & 0xff;
	rev->minor = (chipid >> 8) & 0xff;
	rev->patchid = (chipid & 0xff);

	dev_warn(dev, "Using legacy qcom,chipid binding!\n");
	dev_warn(dev, "Use compatible qcom,adreno-%u%u%u.%u instead.\n",
		rev->core, rev->major, rev->minor, rev->patchid);

	return 0;
}

__attribute__((used)) static int adreno_bind(struct device *dev, struct device *master, void *data)
{
	static struct adreno_platform_config config = {};
	const struct adreno_info *info;
	struct drm_device *drm = dev_get_drvdata(master);
	struct msm_gpu *gpu;
	int ret;

	ret = find_chipid(dev, &config.rev);
	if (ret)
		return ret;

	dev->platform_data = &config;
	set_gpu_pdev(drm, to_platform_device(dev));

	info = adreno_info(config.rev);

	if (!info) {
		dev_warn(drm->dev, "Unknown GPU revision: %u.%u.%u.%u\n",
			config.rev.core, config.rev.major,
			config.rev.minor, config.rev.patchid);
		return -ENXIO;
	}

	DBG("Found GPU: %u.%u.%u.%u", config.rev.core, config.rev.major,
		config.rev.minor, config.rev.patchid);

	gpu = info->init(drm);
	if (IS_ERR(gpu)) {
		dev_warn(drm->dev, "failed to load adreno gpu\n");
		return PTR_ERR(gpu);
	}

	dev_set_drvdata(dev, gpu);

	return 0;
}

__attribute__((used)) static void adreno_unbind(struct device *dev, struct device *master,
		void *data)
{
	struct msm_gpu *gpu = dev_get_drvdata(dev);

	gpu->funcs->pm_suspend(gpu);
	gpu->funcs->destroy(gpu);

	set_gpu_pdev(dev_get_drvdata(master), NULL);
}

__attribute__((used)) static int adreno_probe(struct platform_device *pdev)
{
	return component_add(&pdev->dev, &a3xx_ops);
}

__attribute__((used)) static int adreno_remove(struct platform_device *pdev)
{
	component_del(&pdev->dev, &a3xx_ops);
	return 0;
}

