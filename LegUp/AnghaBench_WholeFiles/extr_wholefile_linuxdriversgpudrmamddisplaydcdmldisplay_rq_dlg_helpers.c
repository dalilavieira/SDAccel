#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_36__   TYPE_9__ ;
typedef  struct TYPE_35__   TYPE_8__ ;
typedef  struct TYPE_34__   TYPE_7__ ;
typedef  struct TYPE_33__   TYPE_6__ ;
typedef  struct TYPE_32__   TYPE_5__ ;
typedef  struct TYPE_31__   TYPE_4__ ;
typedef  struct TYPE_30__   TYPE_3__ ;
typedef  struct TYPE_29__   TYPE_2__ ;
typedef  struct TYPE_28__   TYPE_1__ ;
typedef  struct TYPE_27__   TYPE_13__ ;
typedef  struct TYPE_26__   TYPE_12__ ;
typedef  struct TYPE_25__   TYPE_11__ ;
typedef  struct TYPE_24__   TYPE_10__ ;

/* Type definitions */
struct display_mode_lib {int dummy; } ;
struct TYPE_31__ {int /*<<< orphan*/  qos_ramp_disable_cur1; int /*<<< orphan*/  qos_level_fixed_cur1; int /*<<< orphan*/  qos_ramp_disable_cur0; int /*<<< orphan*/  qos_level_fixed_cur0; int /*<<< orphan*/  qos_ramp_disable_c; int /*<<< orphan*/  qos_level_fixed_c; int /*<<< orphan*/  qos_ramp_disable_l; int /*<<< orphan*/  qos_level_fixed_l; int /*<<< orphan*/  refcyc_per_req_delivery_pre_cur1; int /*<<< orphan*/  refcyc_per_req_delivery_cur1; int /*<<< orphan*/  refcyc_per_req_delivery_pre_cur0; int /*<<< orphan*/  refcyc_per_req_delivery_cur0; int /*<<< orphan*/  refcyc_per_req_delivery_c; int /*<<< orphan*/  refcyc_per_req_delivery_pre_c; int /*<<< orphan*/  refcyc_per_req_delivery_l; int /*<<< orphan*/  refcyc_per_req_delivery_pre_l; int /*<<< orphan*/  qos_level_flip; int /*<<< orphan*/  min_ttu_vblank; int /*<<< orphan*/  qos_level_high_wm; int /*<<< orphan*/  qos_level_low_wm; } ;
typedef  TYPE_4__ display_ttu_regs_st ;
struct TYPE_25__ {int /*<<< orphan*/  pte_row_height_linear; int /*<<< orphan*/  swath_height; int /*<<< orphan*/  mpte_group_size; int /*<<< orphan*/  dpte_group_size; int /*<<< orphan*/  min_meta_chunk_size; int /*<<< orphan*/  meta_chunk_size; int /*<<< orphan*/  min_chunk_size; int /*<<< orphan*/  chunk_size; } ;
struct TYPE_32__ {int /*<<< orphan*/  plane1_base_address; int /*<<< orphan*/  crq_expansion_mode; int /*<<< orphan*/  mrq_expansion_mode; int /*<<< orphan*/  prq_expansion_mode; int /*<<< orphan*/  drq_expansion_mode; TYPE_11__ rq_regs_c; TYPE_11__ rq_regs_l; } ;
typedef  TYPE_5__ display_rq_regs_st ;
struct TYPE_26__ {int /*<<< orphan*/  req_height; int /*<<< orphan*/  req_width; int /*<<< orphan*/  blk256_height; int /*<<< orphan*/  blk256_width; int /*<<< orphan*/  stored_swath_bytes; int /*<<< orphan*/  full_swath_bytes; } ;
struct TYPE_30__ {TYPE_12__ rq_c; TYPE_12__ rq_l; } ;
struct TYPE_27__ {int /*<<< orphan*/  meta_bytes_per_row_ub; int /*<<< orphan*/  meta_row_height; int /*<<< orphan*/  meta_req_per_row_ub; int /*<<< orphan*/  meta_chunks_per_row_ub; int /*<<< orphan*/  dpte_bytes_per_row_ub; int /*<<< orphan*/  dpte_row_height; int /*<<< orphan*/  dpte_groups_per_row_ub; int /*<<< orphan*/  dpte_req_per_row_ub; int /*<<< orphan*/  meta_pte_bytes_per_frame_ub; int /*<<< orphan*/  req_per_swath_ub; int /*<<< orphan*/  swath_height; int /*<<< orphan*/  swath_width_ub; } ;
struct TYPE_29__ {TYPE_13__ rq_c; TYPE_13__ rq_l; } ;
struct TYPE_24__ {int /*<<< orphan*/  dpte_group_bytes; int /*<<< orphan*/  mpte_group_bytes; int /*<<< orphan*/  min_meta_chunk_bytes; int /*<<< orphan*/  meta_chunk_bytes; int /*<<< orphan*/  min_chunk_bytes; int /*<<< orphan*/  chunk_bytes; } ;
struct TYPE_28__ {TYPE_10__ rq_c; TYPE_10__ rq_l; } ;
struct TYPE_33__ {TYPE_3__ misc; TYPE_2__ dlg; TYPE_1__ sizing; } ;
typedef  TYPE_6__ display_rq_params_st ;
struct TYPE_34__ {TYPE_13__ rq_c; TYPE_13__ rq_l; } ;
typedef  TYPE_7__ display_rq_dlg_params_st ;
struct TYPE_35__ {int /*<<< orphan*/  total_flip_bytes; int /*<<< orphan*/  total_flip_bw; int /*<<< orphan*/  deepsleep_dcfclk_mhz; int /*<<< orphan*/  t_srx_delay_us; int /*<<< orphan*/  t_extra_us; int /*<<< orphan*/  t_sr_wm_us; int /*<<< orphan*/  t_urg_wm_us; int /*<<< orphan*/  t_mclk_wm_us; } ;
typedef  TYPE_8__ display_dlg_sys_params_st ;
struct TYPE_36__ {int /*<<< orphan*/  xfc_reg_remote_surface_flip_latency; int /*<<< orphan*/  xfc_reg_precharge_delay; int /*<<< orphan*/  xfc_reg_transfer_delay; int /*<<< orphan*/  dst_y_delta_drq_limit; int /*<<< orphan*/  vready_after_vcount0; int /*<<< orphan*/  chunk_hdl_adjust_cur1; int /*<<< orphan*/  dst_y_offset_cur1; int /*<<< orphan*/  chunk_hdl_adjust_cur0; int /*<<< orphan*/  refcyc_per_line_delivery_c; int /*<<< orphan*/  refcyc_per_line_delivery_l; int /*<<< orphan*/  refcyc_per_line_delivery_pre_c; int /*<<< orphan*/  refcyc_per_line_delivery_pre_l; int /*<<< orphan*/  refcyc_per_meta_chunk_nom_c; int /*<<< orphan*/  refcyc_per_meta_chunk_nom_l; int /*<<< orphan*/  dst_y_per_meta_row_nom_c; int /*<<< orphan*/  dst_y_per_meta_row_nom_l; int /*<<< orphan*/  refcyc_per_pte_group_nom_c; int /*<<< orphan*/  refcyc_per_pte_group_nom_l; int /*<<< orphan*/  dst_y_per_pte_row_nom_c; int /*<<< orphan*/  dst_y_per_pte_row_nom_l; int /*<<< orphan*/  refcyc_per_meta_chunk_flip_c; int /*<<< orphan*/  refcyc_per_meta_chunk_flip_l; int /*<<< orphan*/  refcyc_per_pte_group_flip_c; int /*<<< orphan*/  refcyc_per_pte_group_flip_l; int /*<<< orphan*/  refcyc_per_meta_chunk_vblank_c; int /*<<< orphan*/  refcyc_per_meta_chunk_vblank_l; int /*<<< orphan*/  refcyc_per_pte_group_vblank_c; int /*<<< orphan*/  refcyc_per_pte_group_vblank_l; int /*<<< orphan*/  vratio_prefetch_c; int /*<<< orphan*/  vratio_prefetch; int /*<<< orphan*/  ref_freq_to_pix_freq; int /*<<< orphan*/  dst_y_per_row_flip; int /*<<< orphan*/  dst_y_per_vm_flip; int /*<<< orphan*/  dst_y_per_row_vblank; int /*<<< orphan*/  dst_y_per_vm_vblank; int /*<<< orphan*/  dst_y_prefetch; int /*<<< orphan*/  dst_y_after_scaler; int /*<<< orphan*/  refcyc_x_after_scaler; int /*<<< orphan*/  refcyc_per_htotal; int /*<<< orphan*/  min_dst_y_next_start; int /*<<< orphan*/  dlg_vblank_end; int /*<<< orphan*/  refcyc_h_blank_end; } ;
typedef  TYPE_9__ display_dlg_regs_st ;
typedef  TYPE_10__ display_data_rq_sizing_params_st ;
typedef  TYPE_11__ display_data_rq_regs_st ;
typedef  TYPE_12__ display_data_rq_misc_params_st ;
typedef  TYPE_13__ display_data_rq_dlg_params_st ;

/* Variables and functions */
 int /*<<< orphan*/  dml_print (char*,...) ; 
 void print__data_rq_dlg_params_st (struct display_mode_lib*,TYPE_13__) ; 
 void print__data_rq_misc_params_st (struct display_mode_lib*,TYPE_12__) ; 
 void print__data_rq_sizing_params_st (struct display_mode_lib*,TYPE_10__) ; 

void print__rq_params_st(struct display_mode_lib *mode_lib, display_rq_params_st rq_param)
{
	dml_print("DML_RQ_DLG_CALC: ***************************\n");
	dml_print("DML_RQ_DLG_CALC: DISPLAY_RQ_PARAM_ST\n");
	dml_print("DML_RQ_DLG_CALC:  <LUMA>\n");
	print__data_rq_sizing_params_st(mode_lib, rq_param.sizing.rq_l);
	dml_print("DML_RQ_DLG_CALC:  <CHROMA> ===\n");
	print__data_rq_sizing_params_st(mode_lib, rq_param.sizing.rq_c);

	dml_print("DML_RQ_DLG_CALC: <LUMA>\n");
	print__data_rq_dlg_params_st(mode_lib, rq_param.dlg.rq_l);
	dml_print("DML_RQ_DLG_CALC: <CHROMA>\n");
	print__data_rq_dlg_params_st(mode_lib, rq_param.dlg.rq_c);

	dml_print("DML_RQ_DLG_CALC: <LUMA>\n");
	print__data_rq_misc_params_st(mode_lib, rq_param.misc.rq_l);
	dml_print("DML_RQ_DLG_CALC: <CHROMA>\n");
	print__data_rq_misc_params_st(mode_lib, rq_param.misc.rq_c);
	dml_print("DML_RQ_DLG_CALC: ***************************\n");
}

void print__data_rq_sizing_params_st(struct display_mode_lib *mode_lib, display_data_rq_sizing_params_st rq_sizing)
{
	dml_print("DML_RQ_DLG_CALC: =====================================\n");
	dml_print("DML_RQ_DLG_CALC: DISPLAY_DATA_RQ_SIZING_PARAM_ST\n");
	dml_print("DML_RQ_DLG_CALC:    chunk_bytes           = %0d\n", rq_sizing.chunk_bytes);
	dml_print("DML_RQ_DLG_CALC:    min_chunk_bytes       = %0d\n", rq_sizing.min_chunk_bytes);
	dml_print("DML_RQ_DLG_CALC:    meta_chunk_bytes      = %0d\n", rq_sizing.meta_chunk_bytes);
	dml_print(
			"DML_RQ_DLG_CALC:    min_meta_chunk_bytes  = %0d\n",
			rq_sizing.min_meta_chunk_bytes);
	dml_print("DML_RQ_DLG_CALC:    mpte_group_bytes      = %0d\n", rq_sizing.mpte_group_bytes);
	dml_print("DML_RQ_DLG_CALC:    dpte_group_bytes      = %0d\n", rq_sizing.dpte_group_bytes);
	dml_print("DML_RQ_DLG_CALC: =====================================\n");
}

void print__data_rq_dlg_params_st(struct display_mode_lib *mode_lib, display_data_rq_dlg_params_st rq_dlg_param)
{
	dml_print("DML_RQ_DLG_CALC: =====================================\n");
	dml_print("DML_RQ_DLG_CALC: DISPLAY_DATA_RQ_DLG_PARAM_ST\n");
	dml_print(
			"DML_RQ_DLG_CALC:    swath_width_ub              = %0d\n",
			rq_dlg_param.swath_width_ub);
	dml_print(
			"DML_RQ_DLG_CALC:    swath_height                = %0d\n",
			rq_dlg_param.swath_height);
	dml_print(
			"DML_RQ_DLG_CALC:    req_per_swath_ub            = %0d\n",
			rq_dlg_param.req_per_swath_ub);
	dml_print(
			"DML_RQ_DLG_CALC:    meta_pte_bytes_per_frame_ub = %0d\n",
			rq_dlg_param.meta_pte_bytes_per_frame_ub);
	dml_print(
			"DML_RQ_DLG_CALC:    dpte_req_per_row_ub         = %0d\n",
			rq_dlg_param.dpte_req_per_row_ub);
	dml_print(
			"DML_RQ_DLG_CALC:    dpte_groups_per_row_ub      = %0d\n",
			rq_dlg_param.dpte_groups_per_row_ub);
	dml_print(
			"DML_RQ_DLG_CALC:    dpte_row_height             = %0d\n",
			rq_dlg_param.dpte_row_height);
	dml_print(
			"DML_RQ_DLG_CALC:    dpte_bytes_per_row_ub       = %0d\n",
			rq_dlg_param.dpte_bytes_per_row_ub);
	dml_print(
			"DML_RQ_DLG_CALC:    meta_chunks_per_row_ub      = %0d\n",
			rq_dlg_param.meta_chunks_per_row_ub);
	dml_print(
			"DML_RQ_DLG_CALC:    meta_req_per_row_ub         = %0d\n",
			rq_dlg_param.meta_req_per_row_ub);
	dml_print(
			"DML_RQ_DLG_CALC:    meta_row_height             = %0d\n",
			rq_dlg_param.meta_row_height);
	dml_print(
			"DML_RQ_DLG_CALC:    meta_bytes_per_row_ub       = %0d\n",
			rq_dlg_param.meta_bytes_per_row_ub);
	dml_print("DML_RQ_DLG_CALC: =====================================\n");
}

void print__data_rq_misc_params_st(struct display_mode_lib *mode_lib, display_data_rq_misc_params_st rq_misc_param)
{
	dml_print("DML_RQ_DLG_CALC: =====================================\n");
	dml_print("DML_RQ_DLG_CALC: DISPLAY_DATA_RQ_MISC_PARAM_ST\n");
	dml_print(
			"DML_RQ_DLG_CALC:     full_swath_bytes   = %0d\n",
			rq_misc_param.full_swath_bytes);
	dml_print(
			"DML_RQ_DLG_CALC:     stored_swath_bytes = %0d\n",
			rq_misc_param.stored_swath_bytes);
	dml_print("DML_RQ_DLG_CALC:     blk256_width       = %0d\n", rq_misc_param.blk256_width);
	dml_print("DML_RQ_DLG_CALC:     blk256_height      = %0d\n", rq_misc_param.blk256_height);
	dml_print("DML_RQ_DLG_CALC:     req_width          = %0d\n", rq_misc_param.req_width);
	dml_print("DML_RQ_DLG_CALC:     req_height         = %0d\n", rq_misc_param.req_height);
	dml_print("DML_RQ_DLG_CALC: =====================================\n");
}

void print__rq_dlg_params_st(struct display_mode_lib *mode_lib, display_rq_dlg_params_st rq_dlg_param)
{
	dml_print("DML_RQ_DLG_CALC: =====================================\n");
	dml_print("DML_RQ_DLG_CALC: DISPLAY_RQ_DLG_PARAM_ST\n");
	dml_print("DML_RQ_DLG_CALC:  <LUMA>\n");
	print__data_rq_dlg_params_st(mode_lib, rq_dlg_param.rq_l);
	dml_print("DML_RQ_DLG_CALC:  <CHROMA>\n");
	print__data_rq_dlg_params_st(mode_lib, rq_dlg_param.rq_c);
	dml_print("DML_RQ_DLG_CALC: =====================================\n");
}

void print__dlg_sys_params_st(struct display_mode_lib *mode_lib, display_dlg_sys_params_st dlg_sys_param)
{
	dml_print("DML_RQ_DLG_CALC: =====================================\n");
	dml_print("DML_RQ_DLG_CALC: DISPLAY_RQ_DLG_PARAM_ST\n");
	dml_print("DML_RQ_DLG_CALC:    t_mclk_wm_us         = %3.2f\n", dlg_sys_param.t_mclk_wm_us);
	dml_print("DML_RQ_DLG_CALC:    t_urg_wm_us          = %3.2f\n", dlg_sys_param.t_urg_wm_us);
	dml_print("DML_RQ_DLG_CALC:    t_sr_wm_us           = %3.2f\n", dlg_sys_param.t_sr_wm_us);
	dml_print("DML_RQ_DLG_CALC:    t_extra_us           = %3.2f\n", dlg_sys_param.t_extra_us);
	dml_print(
			"DML_RQ_DLG_CALC:    t_srx_delay_us       = %3.2f\n",
			dlg_sys_param.t_srx_delay_us);
	dml_print(
			"DML_RQ_DLG_CALC:    deepsleep_dcfclk_mhz = %3.2f\n",
			dlg_sys_param.deepsleep_dcfclk_mhz);
	dml_print(
			"DML_RQ_DLG_CALC:    total_flip_bw        = %3.2f\n",
			dlg_sys_param.total_flip_bw);
	dml_print(
			"DML_RQ_DLG_CALC:    total_flip_bytes     = %i\n",
			dlg_sys_param.total_flip_bytes);
	dml_print("DML_RQ_DLG_CALC: =====================================\n");
}

void print__data_rq_regs_st(struct display_mode_lib *mode_lib, display_data_rq_regs_st rq_regs)
{
	dml_print("DML_RQ_DLG_CALC: =====================================\n");
	dml_print("DML_RQ_DLG_CALC: DISPLAY_DATA_RQ_REGS_ST\n");
	dml_print("DML_RQ_DLG_CALC:    chunk_size              = 0x%0x\n", rq_regs.chunk_size);
	dml_print("DML_RQ_DLG_CALC:    min_chunk_size          = 0x%0x\n", rq_regs.min_chunk_size);
	dml_print("DML_RQ_DLG_CALC:    meta_chunk_size         = 0x%0x\n", rq_regs.meta_chunk_size);
	dml_print(
			"DML_RQ_DLG_CALC:    min_meta_chunk_size     = 0x%0x\n",
			rq_regs.min_meta_chunk_size);
	dml_print("DML_RQ_DLG_CALC:    dpte_group_size         = 0x%0x\n", rq_regs.dpte_group_size);
	dml_print("DML_RQ_DLG_CALC:    mpte_group_size         = 0x%0x\n", rq_regs.mpte_group_size);
	dml_print("DML_RQ_DLG_CALC:    swath_height            = 0x%0x\n", rq_regs.swath_height);
	dml_print(
			"DML_RQ_DLG_CALC:    pte_row_height_linear   = 0x%0x\n",
			rq_regs.pte_row_height_linear);
	dml_print("DML_RQ_DLG_CALC: =====================================\n");
}

void print__rq_regs_st(struct display_mode_lib *mode_lib, display_rq_regs_st rq_regs)
{
	dml_print("DML_RQ_DLG_CALC: =====================================\n");
	dml_print("DML_RQ_DLG_CALC: DISPLAY_RQ_REGS_ST\n");
	dml_print("DML_RQ_DLG_CALC:  <LUMA>\n");
	print__data_rq_regs_st(mode_lib, rq_regs.rq_regs_l);
	dml_print("DML_RQ_DLG_CALC:  <CHROMA>\n");
	print__data_rq_regs_st(mode_lib, rq_regs.rq_regs_c);
	dml_print("DML_RQ_DLG_CALC:    drq_expansion_mode  = 0x%0x\n", rq_regs.drq_expansion_mode);
	dml_print("DML_RQ_DLG_CALC:    prq_expansion_mode  = 0x%0x\n", rq_regs.prq_expansion_mode);
	dml_print("DML_RQ_DLG_CALC:    mrq_expansion_mode  = 0x%0x\n", rq_regs.mrq_expansion_mode);
	dml_print("DML_RQ_DLG_CALC:    crq_expansion_mode  = 0x%0x\n", rq_regs.crq_expansion_mode);
	dml_print("DML_RQ_DLG_CALC:    plane1_base_address = 0x%0x\n", rq_regs.plane1_base_address);
	dml_print("DML_RQ_DLG_CALC: =====================================\n");
}

void print__dlg_regs_st(struct display_mode_lib *mode_lib, display_dlg_regs_st dlg_regs)
{
	dml_print("DML_RQ_DLG_CALC: =====================================\n");
	dml_print("DML_RQ_DLG_CALC: DISPLAY_DLG_REGS_ST\n");
	dml_print(
			"DML_RQ_DLG_CALC:    refcyc_h_blank_end              = 0x%0x\n",
			dlg_regs.refcyc_h_blank_end);
	dml_print(
			"DML_RQ_DLG_CALC:    dlg_vblank_end                  = 0x%0x\n",
			dlg_regs.dlg_vblank_end);
	dml_print(
			"DML_RQ_DLG_CALC:    min_dst_y_next_start            = 0x%0x\n",
			dlg_regs.min_dst_y_next_start);
	dml_print(
			"DML_RQ_DLG_CALC:    refcyc_per_htotal               = 0x%0x\n",
			dlg_regs.refcyc_per_htotal);
	dml_print(
			"DML_RQ_DLG_CALC:    refcyc_x_after_scaler           = 0x%0x\n",
			dlg_regs.refcyc_x_after_scaler);
	dml_print(
			"DML_RQ_DLG_CALC:    dst_y_after_scaler              = 0x%0x\n",
			dlg_regs.dst_y_after_scaler);
	dml_print(
			"DML_RQ_DLG_CALC:    dst_y_prefetch                  = 0x%0x\n",
			dlg_regs.dst_y_prefetch);
	dml_print(
			"DML_RQ_DLG_CALC:    dst_y_per_vm_vblank             = 0x%0x\n",
			dlg_regs.dst_y_per_vm_vblank);
	dml_print(
			"DML_RQ_DLG_CALC:    dst_y_per_row_vblank            = 0x%0x\n",
			dlg_regs.dst_y_per_row_vblank);
	dml_print(
			"DML_RQ_DLG_CALC:    dst_y_per_vm_flip               = 0x%0x\n",
			dlg_regs.dst_y_per_vm_flip);
	dml_print(
			"DML_RQ_DLG_CALC:    dst_y_per_row_flip              = 0x%0x\n",
			dlg_regs.dst_y_per_row_flip);
	dml_print(
			"DML_RQ_DLG_CALC:    ref_freq_to_pix_freq            = 0x%0x\n",
			dlg_regs.ref_freq_to_pix_freq);
	dml_print(
			"DML_RQ_DLG_CALC:    vratio_prefetch                 = 0x%0x\n",
			dlg_regs.vratio_prefetch);
	dml_print(
			"DML_RQ_DLG_CALC:    vratio_prefetch_c               = 0x%0x\n",
			dlg_regs.vratio_prefetch_c);
	dml_print(
			"DML_RQ_DLG_CALC:    refcyc_per_pte_group_vblank_l   = 0x%0x\n",
			dlg_regs.refcyc_per_pte_group_vblank_l);
	dml_print(
			"DML_RQ_DLG_CALC:    refcyc_per_pte_group_vblank_c   = 0x%0x\n",
			dlg_regs.refcyc_per_pte_group_vblank_c);
	dml_print(
			"DML_RQ_DLG_CALC:    refcyc_per_meta_chunk_vblank_l  = 0x%0x\n",
			dlg_regs.refcyc_per_meta_chunk_vblank_l);
	dml_print(
			"DML_RQ_DLG_CALC:    refcyc_per_meta_chunk_vblank_c  = 0x%0x\n",
			dlg_regs.refcyc_per_meta_chunk_vblank_c);
	dml_print(
			"DML_RQ_DLG_CALC:    refcyc_per_pte_group_flip_l     = 0x%0x\n",
			dlg_regs.refcyc_per_pte_group_flip_l);
	dml_print(
			"DML_RQ_DLG_CALC:    refcyc_per_pte_group_flip_c     = 0x%0x\n",
			dlg_regs.refcyc_per_pte_group_flip_c);
	dml_print(
			"DML_RQ_DLG_CALC:    refcyc_per_meta_chunk_flip_l    = 0x%0x\n",
			dlg_regs.refcyc_per_meta_chunk_flip_l);
	dml_print(
			"DML_RQ_DLG_CALC:    refcyc_per_meta_chunk_flip_c    = 0x%0x\n",
			dlg_regs.refcyc_per_meta_chunk_flip_c);
	dml_print(
			"DML_RQ_DLG_CALC:    dst_y_per_pte_row_nom_l         = 0x%0x\n",
			dlg_regs.dst_y_per_pte_row_nom_l);
	dml_print(
			"DML_RQ_DLG_CALC:    dst_y_per_pte_row_nom_c         = 0x%0x\n",
			dlg_regs.dst_y_per_pte_row_nom_c);
	dml_print(
			"DML_RQ_DLG_CALC:    refcyc_per_pte_group_nom_l      = 0x%0x\n",
			dlg_regs.refcyc_per_pte_group_nom_l);
	dml_print(
			"DML_RQ_DLG_CALC:    refcyc_per_pte_group_nom_c      = 0x%0x\n",
			dlg_regs.refcyc_per_pte_group_nom_c);
	dml_print(
			"DML_RQ_DLG_CALC:    dst_y_per_meta_row_nom_l        = 0x%0x\n",
			dlg_regs.dst_y_per_meta_row_nom_l);
	dml_print(
			"DML_RQ_DLG_CALC:    dst_y_per_meta_row_nom_c        = 0x%0x\n",
			dlg_regs.dst_y_per_meta_row_nom_c);
	dml_print(
			"DML_RQ_DLG_CALC:    refcyc_per_meta_chunk_nom_l     = 0x%0x\n",
			dlg_regs.refcyc_per_meta_chunk_nom_l);
	dml_print(
			"DML_RQ_DLG_CALC:    refcyc_per_meta_chunk_nom_c     = 0x%0x\n",
			dlg_regs.refcyc_per_meta_chunk_nom_c);
	dml_print(
			"DML_RQ_DLG_CALC:    refcyc_per_line_delivery_pre_l  = 0x%0x\n",
			dlg_regs.refcyc_per_line_delivery_pre_l);
	dml_print(
			"DML_RQ_DLG_CALC:    refcyc_per_line_delivery_pre_c  = 0x%0x\n",
			dlg_regs.refcyc_per_line_delivery_pre_c);
	dml_print(
			"DML_RQ_DLG_CALC:    refcyc_per_line_delivery_l      = 0x%0x\n",
			dlg_regs.refcyc_per_line_delivery_l);
	dml_print(
			"DML_RQ_DLG_CALC:    refcyc_per_line_delivery_c      = 0x%0x\n",
			dlg_regs.refcyc_per_line_delivery_c);
	dml_print(
			"DML_RQ_DLG_CALC:    chunk_hdl_adjust_cur0           = 0x%0x\n",
			dlg_regs.chunk_hdl_adjust_cur0);
	dml_print(
			"DML_RQ_DLG_CALC:    dst_y_offset_cur1               = 0x%0x\n",
			dlg_regs.dst_y_offset_cur1);
	dml_print(
			"DML_RQ_DLG_CALC:    chunk_hdl_adjust_cur1           = 0x%0x\n",
			dlg_regs.chunk_hdl_adjust_cur1);
	dml_print(
			"DML_RQ_DLG_CALC:    vready_after_vcount0            = 0x%0x\n",
			dlg_regs.vready_after_vcount0);
	dml_print(
			"DML_RQ_DLG_CALC:    dst_y_delta_drq_limit           = 0x%0x\n",
			dlg_regs.dst_y_delta_drq_limit);
	dml_print(
			"DML_RQ_DLG_CALC:    xfc_reg_transfer_delay          = 0x%0x\n",
			dlg_regs.xfc_reg_transfer_delay);
	dml_print(
			"DML_RQ_DLG_CALC:    xfc_reg_precharge_delay         = 0x%0x\n",
			dlg_regs.xfc_reg_precharge_delay);
	dml_print(
			"DML_RQ_DLG_CALC:    xfc_reg_remote_surface_flip_latency = 0x%0x\n",
			dlg_regs.xfc_reg_remote_surface_flip_latency);

	dml_print("DML_RQ_DLG_CALC: =====================================\n");
}

void print__ttu_regs_st(struct display_mode_lib *mode_lib, display_ttu_regs_st ttu_regs)
{
	dml_print("DML_RQ_DLG_CALC: =====================================\n");
	dml_print("DML_RQ_DLG_CALC: DISPLAY_TTU_REGS_ST\n");
	dml_print(
			"DML_RQ_DLG_CALC:    qos_level_low_wm                  = 0x%0x\n",
			ttu_regs.qos_level_low_wm);
	dml_print(
			"DML_RQ_DLG_CALC:    qos_level_high_wm                 = 0x%0x\n",
			ttu_regs.qos_level_high_wm);
	dml_print(
			"DML_RQ_DLG_CALC:    min_ttu_vblank                    = 0x%0x\n",
			ttu_regs.min_ttu_vblank);
	dml_print(
			"DML_RQ_DLG_CALC:    qos_level_flip                    = 0x%0x\n",
			ttu_regs.qos_level_flip);
	dml_print(
			"DML_RQ_DLG_CALC:    refcyc_per_req_delivery_pre_l     = 0x%0x\n",
			ttu_regs.refcyc_per_req_delivery_pre_l);
	dml_print(
			"DML_RQ_DLG_CALC:    refcyc_per_req_delivery_l         = 0x%0x\n",
			ttu_regs.refcyc_per_req_delivery_l);
	dml_print(
			"DML_RQ_DLG_CALC:    refcyc_per_req_delivery_pre_c     = 0x%0x\n",
			ttu_regs.refcyc_per_req_delivery_pre_c);
	dml_print(
			"DML_RQ_DLG_CALC:    refcyc_per_req_delivery_c         = 0x%0x\n",
			ttu_regs.refcyc_per_req_delivery_c);
	dml_print(
			"DML_RQ_DLG_CALC:    refcyc_per_req_delivery_cur0      = 0x%0x\n",
			ttu_regs.refcyc_per_req_delivery_cur0);
	dml_print(
			"DML_RQ_DLG_CALC:    refcyc_per_req_delivery_pre_cur0  = 0x%0x\n",
			ttu_regs.refcyc_per_req_delivery_pre_cur0);
	dml_print(
			"DML_RQ_DLG_CALC:    refcyc_per_req_delivery_cur1      = 0x%0x\n",
			ttu_regs.refcyc_per_req_delivery_cur1);
	dml_print(
			"DML_RQ_DLG_CALC:    refcyc_per_req_delivery_pre_cur1  = 0x%0x\n",
			ttu_regs.refcyc_per_req_delivery_pre_cur1);
	dml_print(
			"DML_RQ_DLG_CALC:    qos_level_fixed_l                 = 0x%0x\n",
			ttu_regs.qos_level_fixed_l);
	dml_print(
			"DML_RQ_DLG_CALC:    qos_ramp_disable_l                = 0x%0x\n",
			ttu_regs.qos_ramp_disable_l);
	dml_print(
			"DML_RQ_DLG_CALC:    qos_level_fixed_c                 = 0x%0x\n",
			ttu_regs.qos_level_fixed_c);
	dml_print(
			"DML_RQ_DLG_CALC:    qos_ramp_disable_c                = 0x%0x\n",
			ttu_regs.qos_ramp_disable_c);
	dml_print(
			"DML_RQ_DLG_CALC:    qos_level_fixed_cur0              = 0x%0x\n",
			ttu_regs.qos_level_fixed_cur0);
	dml_print(
			"DML_RQ_DLG_CALC:    qos_ramp_disable_cur0             = 0x%0x\n",
			ttu_regs.qos_ramp_disable_cur0);
	dml_print(
			"DML_RQ_DLG_CALC:    qos_level_fixed_cur1              = 0x%0x\n",
			ttu_regs.qos_level_fixed_cur1);
	dml_print(
			"DML_RQ_DLG_CALC:    qos_ramp_disable_cur1             = 0x%0x\n",
			ttu_regs.qos_ramp_disable_cur1);
	dml_print("DML_RQ_DLG_CALC: =====================================\n");
}

