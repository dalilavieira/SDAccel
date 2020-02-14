#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_9__ ;
typedef  struct TYPE_18__   TYPE_8__ ;
typedef  struct TYPE_17__   TYPE_7__ ;
typedef  struct TYPE_16__   TYPE_6__ ;
typedef  struct TYPE_15__   TYPE_5__ ;
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u8 ;
typedef  int u64 ;
typedef  int u32 ;
typedef  size_t u16 ;
struct i40e_rx_ptype_decoded {int dummy; } ;
struct TYPE_19__ {scalar_t__ va; } ;
struct TYPE_13__ {int sd_cnt; struct i40e_hmc_sd_entry* sd_entry; TYPE_9__ addr; scalar_t__ ref_cnt; } ;
struct i40e_hmc_info {scalar_t__ signature; size_t hmc_fn_id; struct i40e_hmc_obj_info* hmc_obj; TYPE_3__ sd_table; TYPE_9__ hmc_obj_virt_mem; scalar_t__ first_sd_index; } ;
struct TYPE_11__ {scalar_t__ type; } ;
struct i40e_hw {size_t pf_id; struct i40e_hmc_info hmc; TYPE_1__ mac; } ;
struct TYPE_16__ {scalar_t__ va; int /*<<< orphan*/  pa; } ;
struct TYPE_17__ {TYPE_6__ addr; } ;
struct TYPE_12__ {int /*<<< orphan*/  pa; } ;
struct i40e_hmc_pd_table {struct i40e_hmc_pd_entry* pd_entry; TYPE_2__ pd_page_addr; } ;
struct TYPE_18__ {TYPE_7__ bp; struct i40e_hmc_pd_table pd_table; } ;
struct i40e_hmc_sd_entry {int entry_type; int valid; TYPE_8__ u; } ;
struct TYPE_14__ {scalar_t__ va; } ;
struct TYPE_15__ {TYPE_4__ addr; } ;
struct i40e_hmc_pd_entry {TYPE_5__ bp; scalar_t__ valid; } ;
struct i40e_hmc_obj_txq {int dummy; } ;
struct i40e_hmc_obj_rxq {int dummy; } ;
struct i40e_hmc_obj_info {int max_cnt; int cnt; int base; int size; } ;
struct i40e_hmc_lan_delete_obj_info {scalar_t__ start_idx; size_t rsrc_type; scalar_t__ count; struct i40e_hmc_info* hmc_info; } ;
struct i40e_hmc_lan_create_obj_info {scalar_t__ start_idx; size_t rsrc_type; scalar_t__ count; int direct_mode_sz; int entry_type; struct i40e_hmc_info* hmc_info; } ;
struct i40e_context_ele {int offset; int lsb; int width; int size_of; } ;
typedef  scalar_t__ i40e_status ;
typedef  enum virtchnl_link_speed { ____Placeholder_virtchnl_link_speed } virtchnl_link_speed ;
typedef  enum i40e_hmc_model { ____Placeholder_i40e_hmc_model } i40e_hmc_model ;
typedef  enum i40e_hmc_lan_rsrc_type { ____Placeholder_i40e_hmc_lan_rsrc_type } i40e_hmc_lan_rsrc_type ;
typedef  enum i40e_aq_link_speed { ____Placeholder_i40e_aq_link_speed } i40e_aq_link_speed ;
typedef  int /*<<< orphan*/  dest_word ;
typedef  int /*<<< orphan*/  dest_qword ;
typedef  int /*<<< orphan*/  dest_dword ;
typedef  int /*<<< orphan*/  dest_byte ;
typedef  int /*<<< orphan*/  aq_to_posix ;
typedef  size_t __le64 ;
typedef  size_t __le32 ;
typedef  size_t __le16 ;

/* Variables and functions */
 int BIT (int) ; 
 void* BIT_ULL (int) ; 
 int E2BIG ; 
 int EACCES ; 
 int EAGAIN ; 
 int EBUSY ; 
 int EEXIST ; 
 int EFAULT ; 
 int EFBIG ; 
 int EINTR ; 
 int EINVAL ; 
 int EIO ; 
 int ENOENT ; 
 int ENOMEM ; 
 int ENOSPC ; 
 int ENOSYS ; 
 int ENOTTY ; 
 int ENXIO ; 
 int EPERM ; 
 int EPIPE ; 
 int ERANGE ; 
 int EROFS ; 
 int ESPIPE ; 
 int ESRCH ; 
 int I40E_ERR_ADMIN_QUEUE_TIMEOUT ; 
 scalar_t__ I40E_ERR_BAD_PTR ; 
 scalar_t__ I40E_ERR_INVALID_HMC_OBJ_COUNT ; 
 scalar_t__ I40E_ERR_INVALID_HMC_OBJ_INDEX ; 
 scalar_t__ I40E_ERR_INVALID_SD_INDEX ; 
 scalar_t__ I40E_ERR_INVALID_SD_TYPE ; 
 int /*<<< orphan*/  I40E_FIND_PD_INDEX_LIMIT (struct i40e_hmc_info*,int,int,int,int*,int*) ; 
 int /*<<< orphan*/  I40E_FIND_SD_INDEX_LIMIT (struct i40e_hmc_info*,int,int,int,int*,int*) ; 
 int /*<<< orphan*/  I40E_GLHMC_FCOEDDPBASE (size_t) ; 
 int I40E_GLHMC_FCOEDDPBASE_FPMFCOEDDPBASE_MASK ; 
 int /*<<< orphan*/  I40E_GLHMC_FCOEDDPCNT (size_t) ; 
 int /*<<< orphan*/  I40E_GLHMC_FCOEDDPOBJSZ ; 
 int /*<<< orphan*/  I40E_GLHMC_FCOEFBASE (size_t) ; 
 int I40E_GLHMC_FCOEFBASE_FPMFCOEFBASE_MASK ; 
 int /*<<< orphan*/  I40E_GLHMC_FCOEFCNT (size_t) ; 
 int /*<<< orphan*/  I40E_GLHMC_FCOEFMAX ; 
 int /*<<< orphan*/  I40E_GLHMC_FCOEFOBJSZ ; 
 int /*<<< orphan*/  I40E_GLHMC_FCOEMAX ; 
 int /*<<< orphan*/  I40E_GLHMC_LANQMAX ; 
 int /*<<< orphan*/  I40E_GLHMC_LANRXBASE (size_t) ; 
 int I40E_GLHMC_LANRXBASE_FPMLANRXBASE_MASK ; 
 int /*<<< orphan*/  I40E_GLHMC_LANRXCNT (size_t) ; 
 int /*<<< orphan*/  I40E_GLHMC_LANRXOBJSZ ; 
 int /*<<< orphan*/  I40E_GLHMC_LANTXBASE (size_t) ; 
 int I40E_GLHMC_LANTXBASE_FPMLANTXBASE_MASK ; 
 int /*<<< orphan*/  I40E_GLHMC_LANTXCNT (size_t) ; 
 int /*<<< orphan*/  I40E_GLHMC_LANTXOBJSZ ; 
 int I40E_HMC_DIRECT_BP_SIZE ; 
 size_t I40E_HMC_FCOE_CTX ; 
 size_t I40E_HMC_FCOE_FILT ; 
 scalar_t__ I40E_HMC_INFO_SIGNATURE ; 
 int I40E_HMC_L2OBJ_BASE_ALIGNMENT ; 
 size_t I40E_HMC_LAN_FULL ; 
 int I40E_HMC_LAN_MAX ; 
 size_t I40E_HMC_LAN_RX ; 
 size_t I40E_HMC_LAN_TX ; 
 int I40E_HMC_MAX_BP_COUNT ; 
#define  I40E_HMC_MODEL_DIRECT_ONLY 139 
#define  I40E_HMC_MODEL_DIRECT_PREFERRED 138 
#define  I40E_HMC_MODEL_PAGED_ONLY 137 
 int I40E_HMC_OBJ_SIZE_FCOE_CNTX ; 
 int I40E_HMC_OBJ_SIZE_FCOE_FILT ; 
 int I40E_HMC_OBJ_SIZE_RXQ ; 
 int I40E_HMC_OBJ_SIZE_TXQ ; 
 int I40E_HMC_PAGED_BP_SIZE ; 
 int I40E_HMC_PD_CNT_IN_SD ; 
#define  I40E_LINK_SPEED_100MB 136 
#define  I40E_LINK_SPEED_10GB 135 
#define  I40E_LINK_SPEED_1GB 134 
#define  I40E_LINK_SPEED_20GB 133 
#define  I40E_LINK_SPEED_25GB 132 
#define  I40E_LINK_SPEED_40GB 131 
#define  I40E_LINK_SPEED_UNKNOWN 130 
 scalar_t__ I40E_MAC_VF ; 
 scalar_t__ I40E_MAC_X722_VF ; 
#define  I40E_SD_TYPE_DIRECT 129 
#define  I40E_SD_TYPE_PAGED 128 
 int /*<<< orphan*/  I40E_SET_PF_SD_ENTRY (struct i40e_hw*,int /*<<< orphan*/ ,int,int) ; 
 int VIRTCHNL_LINK_SPEED_100MB ; 
 int VIRTCHNL_LINK_SPEED_10GB ; 
 int VIRTCHNL_LINK_SPEED_1GB ; 
 int VIRTCHNL_LINK_SPEED_20GB ; 
 int VIRTCHNL_LINK_SPEED_25GB ; 
 int VIRTCHNL_LINK_SPEED_40GB ; 
 int VIRTCHNL_LINK_SPEED_UNKNOWN ; 
 size_t cpu_to_le16 (size_t) ; 
 size_t cpu_to_le32 (int) ; 
 size_t cpu_to_le64 (int) ; 
 struct i40e_hw* hw ; 
 int /*<<< orphan*/  hw_dbg (struct i40e_hw*,char*,...) ; 
 scalar_t__ i40e_add_pd_table_entry (struct i40e_hw*,struct i40e_hmc_info*,int,int /*<<< orphan*/ *) ; 
 scalar_t__ i40e_add_sd_table_entry (struct i40e_hw*,struct i40e_hmc_info*,int,int,int) ; 
 scalar_t__ i40e_allocate_virt_mem (struct i40e_hw*,TYPE_9__*,int) ; 
 int /*<<< orphan*/  i40e_free_virt_mem (struct i40e_hw*,TYPE_9__*) ; 
 struct i40e_context_ele* i40e_hmc_rxq_ce_info ; 
 struct i40e_context_ele* i40e_hmc_txq_ce_info ; 
 int /*<<< orphan*/  i40e_prep_remove_pd_page (struct i40e_hmc_info*,int) ; 
 int /*<<< orphan*/  i40e_prep_remove_sd_bp (struct i40e_hmc_info*,int) ; 
 struct i40e_rx_ptype_decoded* i40e_ptype_lookup ; 
 scalar_t__ i40e_remove_pd_bp (struct i40e_hw*,struct i40e_hmc_info*,int) ; 
 scalar_t__ i40e_remove_pd_page_new (struct i40e_hw*,struct i40e_hmc_info*,int,int) ; 
 scalar_t__ i40e_remove_sd_bp_new (struct i40e_hw*,struct i40e_hmc_info*,int,int) ; 
 int max (int,int) ; 
 int /*<<< orphan*/  memcpy (size_t*,size_t*,int) ; 
 int /*<<< orphan*/  memset (size_t*,int /*<<< orphan*/ ,int) ; 
 int min (int,int) ; 
 void* rd32 (struct i40e_hw*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wr32 (struct i40e_hw*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline int i40e_aq_rc_to_posix(int aq_ret, int aq_rc)
{
	int aq_to_posix[] = {
		0,           /* I40E_AQ_RC_OK */
		-EPERM,      /* I40E_AQ_RC_EPERM */
		-ENOENT,     /* I40E_AQ_RC_ENOENT */
		-ESRCH,      /* I40E_AQ_RC_ESRCH */
		-EINTR,      /* I40E_AQ_RC_EINTR */
		-EIO,        /* I40E_AQ_RC_EIO */
		-ENXIO,      /* I40E_AQ_RC_ENXIO */
		-E2BIG,      /* I40E_AQ_RC_E2BIG */
		-EAGAIN,     /* I40E_AQ_RC_EAGAIN */
		-ENOMEM,     /* I40E_AQ_RC_ENOMEM */
		-EACCES,     /* I40E_AQ_RC_EACCES */
		-EFAULT,     /* I40E_AQ_RC_EFAULT */
		-EBUSY,      /* I40E_AQ_RC_EBUSY */
		-EEXIST,     /* I40E_AQ_RC_EEXIST */
		-EINVAL,     /* I40E_AQ_RC_EINVAL */
		-ENOTTY,     /* I40E_AQ_RC_ENOTTY */
		-ENOSPC,     /* I40E_AQ_RC_ENOSPC */
		-ENOSYS,     /* I40E_AQ_RC_ENOSYS */
		-ERANGE,     /* I40E_AQ_RC_ERANGE */
		-EPIPE,      /* I40E_AQ_RC_EFLUSHED */
		-ESPIPE,     /* I40E_AQ_RC_BAD_ADDR */
		-EROFS,      /* I40E_AQ_RC_EMODE */
		-EFBIG,      /* I40E_AQ_RC_EFBIG */
	};

	/* aq_rc is invalid if AQ timed out */
	if (aq_ret == I40E_ERR_ADMIN_QUEUE_TIMEOUT)
		return -EAGAIN;

	if (!((u32)aq_rc < (sizeof(aq_to_posix) / sizeof((aq_to_posix)[0]))))
		return -ERANGE;

	return aq_to_posix[aq_rc];
}

__attribute__((used)) static inline bool i40e_is_vf(struct i40e_hw *hw)
{
	return (hw->mac.type == I40E_MAC_VF ||
		hw->mac.type == I40E_MAC_X722_VF);
}

__attribute__((used)) static inline struct i40e_rx_ptype_decoded decode_rx_desc_ptype(u8 ptype)
{
	return i40e_ptype_lookup[ptype];
}

__attribute__((used)) static inline enum virtchnl_link_speed
i40e_virtchnl_link_speed(enum i40e_aq_link_speed link_speed)
{
	switch (link_speed) {
	case I40E_LINK_SPEED_100MB:
		return VIRTCHNL_LINK_SPEED_100MB;
	case I40E_LINK_SPEED_1GB:
		return VIRTCHNL_LINK_SPEED_1GB;
	case I40E_LINK_SPEED_10GB:
		return VIRTCHNL_LINK_SPEED_10GB;
	case I40E_LINK_SPEED_40GB:
		return VIRTCHNL_LINK_SPEED_40GB;
	case I40E_LINK_SPEED_20GB:
		return VIRTCHNL_LINK_SPEED_20GB;
	case I40E_LINK_SPEED_25GB:
		return VIRTCHNL_LINK_SPEED_25GB;
	case I40E_LINK_SPEED_UNKNOWN:
	default:
		return VIRTCHNL_LINK_SPEED_UNKNOWN;
	}
}

__attribute__((used)) static u64 i40e_align_l2obj_base(u64 offset)
{
	u64 aligned_offset = offset;

	if ((offset % I40E_HMC_L2OBJ_BASE_ALIGNMENT) > 0)
		aligned_offset += (I40E_HMC_L2OBJ_BASE_ALIGNMENT -
				   (offset % I40E_HMC_L2OBJ_BASE_ALIGNMENT));

	return aligned_offset;
}

__attribute__((used)) static u64 i40e_calculate_l2fpm_size(u32 txq_num, u32 rxq_num,
			      u32 fcoe_cntx_num, u32 fcoe_filt_num)
{
	u64 fpm_size = 0;

	fpm_size = txq_num * I40E_HMC_OBJ_SIZE_TXQ;
	fpm_size = i40e_align_l2obj_base(fpm_size);

	fpm_size += (rxq_num * I40E_HMC_OBJ_SIZE_RXQ);
	fpm_size = i40e_align_l2obj_base(fpm_size);

	fpm_size += (fcoe_cntx_num * I40E_HMC_OBJ_SIZE_FCOE_CNTX);
	fpm_size = i40e_align_l2obj_base(fpm_size);

	fpm_size += (fcoe_filt_num * I40E_HMC_OBJ_SIZE_FCOE_FILT);
	fpm_size = i40e_align_l2obj_base(fpm_size);

	return fpm_size;
}

i40e_status i40e_init_lan_hmc(struct i40e_hw *hw, u32 txq_num,
					u32 rxq_num, u32 fcoe_cntx_num,
					u32 fcoe_filt_num)
{
	struct i40e_hmc_obj_info *obj, *full_obj;
	i40e_status ret_code = 0;
	u64 l2fpm_size;
	u32 size_exp;

	hw->hmc.signature = I40E_HMC_INFO_SIGNATURE;
	hw->hmc.hmc_fn_id = hw->pf_id;

	/* allocate memory for hmc_obj */
	ret_code = i40e_allocate_virt_mem(hw, &hw->hmc.hmc_obj_virt_mem,
			sizeof(struct i40e_hmc_obj_info) * I40E_HMC_LAN_MAX);
	if (ret_code)
		goto init_lan_hmc_out;
	hw->hmc.hmc_obj = (struct i40e_hmc_obj_info *)
			  hw->hmc.hmc_obj_virt_mem.va;

	/* The full object will be used to create the LAN HMC SD */
	full_obj = &hw->hmc.hmc_obj[I40E_HMC_LAN_FULL];
	full_obj->max_cnt = 0;
	full_obj->cnt = 0;
	full_obj->base = 0;
	full_obj->size = 0;

	/* Tx queue context information */
	obj = &hw->hmc.hmc_obj[I40E_HMC_LAN_TX];
	obj->max_cnt = rd32(hw, I40E_GLHMC_LANQMAX);
	obj->cnt = txq_num;
	obj->base = 0;
	size_exp = rd32(hw, I40E_GLHMC_LANTXOBJSZ);
	obj->size = BIT_ULL(size_exp);

	/* validate values requested by driver don't exceed HMC capacity */
	if (txq_num > obj->max_cnt) {
		ret_code = I40E_ERR_INVALID_HMC_OBJ_COUNT;
		hw_dbg(hw, "i40e_init_lan_hmc: Tx context: asks for 0x%x but max allowed is 0x%x, returns error %d\n",
			  txq_num, obj->max_cnt, ret_code);
		goto init_lan_hmc_out;
	}

	/* aggregate values into the full LAN object for later */
	full_obj->max_cnt += obj->max_cnt;
	full_obj->cnt += obj->cnt;

	/* Rx queue context information */
	obj = &hw->hmc.hmc_obj[I40E_HMC_LAN_RX];
	obj->max_cnt = rd32(hw, I40E_GLHMC_LANQMAX);
	obj->cnt = rxq_num;
	obj->base = hw->hmc.hmc_obj[I40E_HMC_LAN_TX].base +
		    (hw->hmc.hmc_obj[I40E_HMC_LAN_TX].cnt *
		     hw->hmc.hmc_obj[I40E_HMC_LAN_TX].size);
	obj->base = i40e_align_l2obj_base(obj->base);
	size_exp = rd32(hw, I40E_GLHMC_LANRXOBJSZ);
	obj->size = BIT_ULL(size_exp);

	/* validate values requested by driver don't exceed HMC capacity */
	if (rxq_num > obj->max_cnt) {
		ret_code = I40E_ERR_INVALID_HMC_OBJ_COUNT;
		hw_dbg(hw, "i40e_init_lan_hmc: Rx context: asks for 0x%x but max allowed is 0x%x, returns error %d\n",
			  rxq_num, obj->max_cnt, ret_code);
		goto init_lan_hmc_out;
	}

	/* aggregate values into the full LAN object for later */
	full_obj->max_cnt += obj->max_cnt;
	full_obj->cnt += obj->cnt;

	/* FCoE context information */
	obj = &hw->hmc.hmc_obj[I40E_HMC_FCOE_CTX];
	obj->max_cnt = rd32(hw, I40E_GLHMC_FCOEMAX);
	obj->cnt = fcoe_cntx_num;
	obj->base = hw->hmc.hmc_obj[I40E_HMC_LAN_RX].base +
		    (hw->hmc.hmc_obj[I40E_HMC_LAN_RX].cnt *
		     hw->hmc.hmc_obj[I40E_HMC_LAN_RX].size);
	obj->base = i40e_align_l2obj_base(obj->base);
	size_exp = rd32(hw, I40E_GLHMC_FCOEDDPOBJSZ);
	obj->size = BIT_ULL(size_exp);

	/* validate values requested by driver don't exceed HMC capacity */
	if (fcoe_cntx_num > obj->max_cnt) {
		ret_code = I40E_ERR_INVALID_HMC_OBJ_COUNT;
		hw_dbg(hw, "i40e_init_lan_hmc: FCoE context: asks for 0x%x but max allowed is 0x%x, returns error %d\n",
			  fcoe_cntx_num, obj->max_cnt, ret_code);
		goto init_lan_hmc_out;
	}

	/* aggregate values into the full LAN object for later */
	full_obj->max_cnt += obj->max_cnt;
	full_obj->cnt += obj->cnt;

	/* FCoE filter information */
	obj = &hw->hmc.hmc_obj[I40E_HMC_FCOE_FILT];
	obj->max_cnt = rd32(hw, I40E_GLHMC_FCOEFMAX);
	obj->cnt = fcoe_filt_num;
	obj->base = hw->hmc.hmc_obj[I40E_HMC_FCOE_CTX].base +
		    (hw->hmc.hmc_obj[I40E_HMC_FCOE_CTX].cnt *
		     hw->hmc.hmc_obj[I40E_HMC_FCOE_CTX].size);
	obj->base = i40e_align_l2obj_base(obj->base);
	size_exp = rd32(hw, I40E_GLHMC_FCOEFOBJSZ);
	obj->size = BIT_ULL(size_exp);

	/* validate values requested by driver don't exceed HMC capacity */
	if (fcoe_filt_num > obj->max_cnt) {
		ret_code = I40E_ERR_INVALID_HMC_OBJ_COUNT;
		hw_dbg(hw, "i40e_init_lan_hmc: FCoE filter: asks for 0x%x but max allowed is 0x%x, returns error %d\n",
			  fcoe_filt_num, obj->max_cnt, ret_code);
		goto init_lan_hmc_out;
	}

	/* aggregate values into the full LAN object for later */
	full_obj->max_cnt += obj->max_cnt;
	full_obj->cnt += obj->cnt;

	hw->hmc.first_sd_index = 0;
	hw->hmc.sd_table.ref_cnt = 0;
	l2fpm_size = i40e_calculate_l2fpm_size(txq_num, rxq_num, fcoe_cntx_num,
					       fcoe_filt_num);
	if (NULL == hw->hmc.sd_table.sd_entry) {
		hw->hmc.sd_table.sd_cnt = (u32)
				   (l2fpm_size + I40E_HMC_DIRECT_BP_SIZE - 1) /
				   I40E_HMC_DIRECT_BP_SIZE;

		/* allocate the sd_entry members in the sd_table */
		ret_code = i40e_allocate_virt_mem(hw, &hw->hmc.sd_table.addr,
					  (sizeof(struct i40e_hmc_sd_entry) *
					  hw->hmc.sd_table.sd_cnt));
		if (ret_code)
			goto init_lan_hmc_out;
		hw->hmc.sd_table.sd_entry =
			(struct i40e_hmc_sd_entry *)hw->hmc.sd_table.addr.va;
	}
	/* store in the LAN full object for later */
	full_obj->size = l2fpm_size;

init_lan_hmc_out:
	return ret_code;
}

__attribute__((used)) static i40e_status i40e_remove_pd_page(struct i40e_hw *hw,
						 struct i40e_hmc_info *hmc_info,
						 u32 idx)
{
	i40e_status ret_code = 0;

	if (!i40e_prep_remove_pd_page(hmc_info, idx))
		ret_code = i40e_remove_pd_page_new(hw, hmc_info, idx, true);

	return ret_code;
}

__attribute__((used)) static i40e_status i40e_remove_sd_bp(struct i40e_hw *hw,
					       struct i40e_hmc_info *hmc_info,
					       u32 idx)
{
	i40e_status ret_code = 0;

	if (!i40e_prep_remove_sd_bp(hmc_info, idx))
		ret_code = i40e_remove_sd_bp_new(hw, hmc_info, idx, true);

	return ret_code;
}

__attribute__((used)) static i40e_status i40e_create_lan_hmc_object(struct i40e_hw *hw,
				struct i40e_hmc_lan_create_obj_info *info)
{
	i40e_status ret_code = 0;
	struct i40e_hmc_sd_entry *sd_entry;
	u32 pd_idx1 = 0, pd_lmt1 = 0;
	u32 pd_idx = 0, pd_lmt = 0;
	bool pd_error = false;
	u32 sd_idx, sd_lmt;
	u64 sd_size;
	u32 i, j;

	if (NULL == info) {
		ret_code = I40E_ERR_BAD_PTR;
		hw_dbg(hw, "i40e_create_lan_hmc_object: bad info ptr\n");
		goto exit;
	}
	if (NULL == info->hmc_info) {
		ret_code = I40E_ERR_BAD_PTR;
		hw_dbg(hw, "i40e_create_lan_hmc_object: bad hmc_info ptr\n");
		goto exit;
	}
	if (I40E_HMC_INFO_SIGNATURE != info->hmc_info->signature) {
		ret_code = I40E_ERR_BAD_PTR;
		hw_dbg(hw, "i40e_create_lan_hmc_object: bad signature\n");
		goto exit;
	}

	if (info->start_idx >= info->hmc_info->hmc_obj[info->rsrc_type].cnt) {
		ret_code = I40E_ERR_INVALID_HMC_OBJ_INDEX;
		hw_dbg(hw, "i40e_create_lan_hmc_object: returns error %d\n",
			  ret_code);
		goto exit;
	}
	if ((info->start_idx + info->count) >
	    info->hmc_info->hmc_obj[info->rsrc_type].cnt) {
		ret_code = I40E_ERR_INVALID_HMC_OBJ_COUNT;
		hw_dbg(hw, "i40e_create_lan_hmc_object: returns error %d\n",
			  ret_code);
		goto exit;
	}

	/* find sd index and limit */
	I40E_FIND_SD_INDEX_LIMIT(info->hmc_info, info->rsrc_type,
				 info->start_idx, info->count,
				 &sd_idx, &sd_lmt);
	if (sd_idx >= info->hmc_info->sd_table.sd_cnt ||
	    sd_lmt > info->hmc_info->sd_table.sd_cnt) {
			ret_code = I40E_ERR_INVALID_SD_INDEX;
			goto exit;
	}
	/* find pd index */
	I40E_FIND_PD_INDEX_LIMIT(info->hmc_info, info->rsrc_type,
				 info->start_idx, info->count, &pd_idx,
				 &pd_lmt);

	/* This is to cover for cases where you may not want to have an SD with
	 * the full 2M memory but something smaller. By not filling out any
	 * size, the function will default the SD size to be 2M.
	 */
	if (info->direct_mode_sz == 0)
		sd_size = I40E_HMC_DIRECT_BP_SIZE;
	else
		sd_size = info->direct_mode_sz;

	/* check if all the sds are valid. If not, allocate a page and
	 * initialize it.
	 */
	for (j = sd_idx; j < sd_lmt; j++) {
		/* update the sd table entry */
		ret_code = i40e_add_sd_table_entry(hw, info->hmc_info, j,
						   info->entry_type,
						   sd_size);
		if (ret_code)
			goto exit_sd_error;
		sd_entry = &info->hmc_info->sd_table.sd_entry[j];
		if (I40E_SD_TYPE_PAGED == sd_entry->entry_type) {
			/* check if all the pds in this sd are valid. If not,
			 * allocate a page and initialize it.
			 */

			/* find pd_idx and pd_lmt in this sd */
			pd_idx1 = max(pd_idx, (j * I40E_HMC_MAX_BP_COUNT));
			pd_lmt1 = min(pd_lmt,
				      ((j + 1) * I40E_HMC_MAX_BP_COUNT));
			for (i = pd_idx1; i < pd_lmt1; i++) {
				/* update the pd table entry */
				ret_code = i40e_add_pd_table_entry(hw,
								info->hmc_info,
								i, NULL);
				if (ret_code) {
					pd_error = true;
					break;
				}
			}
			if (pd_error) {
				/* remove the backing pages from pd_idx1 to i */
				while (i && (i > pd_idx1)) {
					i40e_remove_pd_bp(hw, info->hmc_info,
							  (i - 1));
					i--;
				}
			}
		}
		if (!sd_entry->valid) {
			sd_entry->valid = true;
			switch (sd_entry->entry_type) {
			case I40E_SD_TYPE_PAGED:
				I40E_SET_PF_SD_ENTRY(hw,
					sd_entry->u.pd_table.pd_page_addr.pa,
					j, sd_entry->entry_type);
				break;
			case I40E_SD_TYPE_DIRECT:
				I40E_SET_PF_SD_ENTRY(hw, sd_entry->u.bp.addr.pa,
						     j, sd_entry->entry_type);
				break;
			default:
				ret_code = I40E_ERR_INVALID_SD_TYPE;
				goto exit;
			}
		}
	}
	goto exit;

exit_sd_error:
	/* cleanup for sd entries from j to sd_idx */
	while (j && (j > sd_idx)) {
		sd_entry = &info->hmc_info->sd_table.sd_entry[j - 1];
		switch (sd_entry->entry_type) {
		case I40E_SD_TYPE_PAGED:
			pd_idx1 = max(pd_idx,
				      ((j - 1) * I40E_HMC_MAX_BP_COUNT));
			pd_lmt1 = min(pd_lmt, (j * I40E_HMC_MAX_BP_COUNT));
			for (i = pd_idx1; i < pd_lmt1; i++)
				i40e_remove_pd_bp(hw, info->hmc_info, i);
			i40e_remove_pd_page(hw, info->hmc_info, (j - 1));
			break;
		case I40E_SD_TYPE_DIRECT:
			i40e_remove_sd_bp(hw, info->hmc_info, (j - 1));
			break;
		default:
			ret_code = I40E_ERR_INVALID_SD_TYPE;
			break;
		}
		j--;
	}
exit:
	return ret_code;
}

i40e_status i40e_configure_lan_hmc(struct i40e_hw *hw,
					     enum i40e_hmc_model model)
{
	struct i40e_hmc_lan_create_obj_info info;
	i40e_status ret_code = 0;
	u8 hmc_fn_id = hw->hmc.hmc_fn_id;
	struct i40e_hmc_obj_info *obj;

	/* Initialize part of the create object info struct */
	info.hmc_info = &hw->hmc;
	info.rsrc_type = I40E_HMC_LAN_FULL;
	info.start_idx = 0;
	info.direct_mode_sz = hw->hmc.hmc_obj[I40E_HMC_LAN_FULL].size;

	/* Build the SD entry for the LAN objects */
	switch (model) {
	case I40E_HMC_MODEL_DIRECT_PREFERRED:
	case I40E_HMC_MODEL_DIRECT_ONLY:
		info.entry_type = I40E_SD_TYPE_DIRECT;
		/* Make one big object, a single SD */
		info.count = 1;
		ret_code = i40e_create_lan_hmc_object(hw, &info);
		if (ret_code && (model == I40E_HMC_MODEL_DIRECT_PREFERRED))
			goto try_type_paged;
		else if (ret_code)
			goto configure_lan_hmc_out;
		/* else clause falls through the break */
		break;
	case I40E_HMC_MODEL_PAGED_ONLY:
try_type_paged:
		info.entry_type = I40E_SD_TYPE_PAGED;
		/* Make one big object in the PD table */
		info.count = 1;
		ret_code = i40e_create_lan_hmc_object(hw, &info);
		if (ret_code)
			goto configure_lan_hmc_out;
		break;
	default:
		/* unsupported type */
		ret_code = I40E_ERR_INVALID_SD_TYPE;
		hw_dbg(hw, "i40e_configure_lan_hmc: Unknown SD type: %d\n",
			  ret_code);
		goto configure_lan_hmc_out;
	}

	/* Configure and program the FPM registers so objects can be created */

	/* Tx contexts */
	obj = &hw->hmc.hmc_obj[I40E_HMC_LAN_TX];
	wr32(hw, I40E_GLHMC_LANTXBASE(hmc_fn_id),
	     (u32)((obj->base & I40E_GLHMC_LANTXBASE_FPMLANTXBASE_MASK) / 512));
	wr32(hw, I40E_GLHMC_LANTXCNT(hmc_fn_id), obj->cnt);

	/* Rx contexts */
	obj = &hw->hmc.hmc_obj[I40E_HMC_LAN_RX];
	wr32(hw, I40E_GLHMC_LANRXBASE(hmc_fn_id),
	     (u32)((obj->base & I40E_GLHMC_LANRXBASE_FPMLANRXBASE_MASK) / 512));
	wr32(hw, I40E_GLHMC_LANRXCNT(hmc_fn_id), obj->cnt);

	/* FCoE contexts */
	obj = &hw->hmc.hmc_obj[I40E_HMC_FCOE_CTX];
	wr32(hw, I40E_GLHMC_FCOEDDPBASE(hmc_fn_id),
	 (u32)((obj->base & I40E_GLHMC_FCOEDDPBASE_FPMFCOEDDPBASE_MASK) / 512));
	wr32(hw, I40E_GLHMC_FCOEDDPCNT(hmc_fn_id), obj->cnt);

	/* FCoE filters */
	obj = &hw->hmc.hmc_obj[I40E_HMC_FCOE_FILT];
	wr32(hw, I40E_GLHMC_FCOEFBASE(hmc_fn_id),
	     (u32)((obj->base & I40E_GLHMC_FCOEFBASE_FPMFCOEFBASE_MASK) / 512));
	wr32(hw, I40E_GLHMC_FCOEFCNT(hmc_fn_id), obj->cnt);

configure_lan_hmc_out:
	return ret_code;
}

__attribute__((used)) static i40e_status i40e_delete_lan_hmc_object(struct i40e_hw *hw,
				struct i40e_hmc_lan_delete_obj_info *info)
{
	i40e_status ret_code = 0;
	struct i40e_hmc_pd_table *pd_table;
	u32 pd_idx, pd_lmt, rel_pd_idx;
	u32 sd_idx, sd_lmt;
	u32 i, j;

	if (NULL == info) {
		ret_code = I40E_ERR_BAD_PTR;
		hw_dbg(hw, "i40e_delete_hmc_object: bad info ptr\n");
		goto exit;
	}
	if (NULL == info->hmc_info) {
		ret_code = I40E_ERR_BAD_PTR;
		hw_dbg(hw, "i40e_delete_hmc_object: bad info->hmc_info ptr\n");
		goto exit;
	}
	if (I40E_HMC_INFO_SIGNATURE != info->hmc_info->signature) {
		ret_code = I40E_ERR_BAD_PTR;
		hw_dbg(hw, "i40e_delete_hmc_object: bad hmc_info->signature\n");
		goto exit;
	}

	if (NULL == info->hmc_info->sd_table.sd_entry) {
		ret_code = I40E_ERR_BAD_PTR;
		hw_dbg(hw, "i40e_delete_hmc_object: bad sd_entry\n");
		goto exit;
	}

	if (NULL == info->hmc_info->hmc_obj) {
		ret_code = I40E_ERR_BAD_PTR;
		hw_dbg(hw, "i40e_delete_hmc_object: bad hmc_info->hmc_obj\n");
		goto exit;
	}
	if (info->start_idx >= info->hmc_info->hmc_obj[info->rsrc_type].cnt) {
		ret_code = I40E_ERR_INVALID_HMC_OBJ_INDEX;
		hw_dbg(hw, "i40e_delete_hmc_object: returns error %d\n",
			  ret_code);
		goto exit;
	}

	if ((info->start_idx + info->count) >
	    info->hmc_info->hmc_obj[info->rsrc_type].cnt) {
		ret_code = I40E_ERR_INVALID_HMC_OBJ_COUNT;
		hw_dbg(hw, "i40e_delete_hmc_object: returns error %d\n",
			  ret_code);
		goto exit;
	}

	I40E_FIND_PD_INDEX_LIMIT(info->hmc_info, info->rsrc_type,
				 info->start_idx, info->count, &pd_idx,
				 &pd_lmt);

	for (j = pd_idx; j < pd_lmt; j++) {
		sd_idx = j / I40E_HMC_PD_CNT_IN_SD;

		if (I40E_SD_TYPE_PAGED !=
		    info->hmc_info->sd_table.sd_entry[sd_idx].entry_type)
			continue;

		rel_pd_idx = j % I40E_HMC_PD_CNT_IN_SD;

		pd_table =
			&info->hmc_info->sd_table.sd_entry[sd_idx].u.pd_table;
		if (pd_table->pd_entry[rel_pd_idx].valid) {
			ret_code = i40e_remove_pd_bp(hw, info->hmc_info, j);
			if (ret_code)
				goto exit;
		}
	}

	/* find sd index and limit */
	I40E_FIND_SD_INDEX_LIMIT(info->hmc_info, info->rsrc_type,
				 info->start_idx, info->count,
				 &sd_idx, &sd_lmt);
	if (sd_idx >= info->hmc_info->sd_table.sd_cnt ||
	    sd_lmt > info->hmc_info->sd_table.sd_cnt) {
		ret_code = I40E_ERR_INVALID_SD_INDEX;
		goto exit;
	}

	for (i = sd_idx; i < sd_lmt; i++) {
		if (!info->hmc_info->sd_table.sd_entry[i].valid)
			continue;
		switch (info->hmc_info->sd_table.sd_entry[i].entry_type) {
		case I40E_SD_TYPE_DIRECT:
			ret_code = i40e_remove_sd_bp(hw, info->hmc_info, i);
			if (ret_code)
				goto exit;
			break;
		case I40E_SD_TYPE_PAGED:
			ret_code = i40e_remove_pd_page(hw, info->hmc_info, i);
			if (ret_code)
				goto exit;
			break;
		default:
			break;
		}
	}
exit:
	return ret_code;
}

i40e_status i40e_shutdown_lan_hmc(struct i40e_hw *hw)
{
	struct i40e_hmc_lan_delete_obj_info info;
	i40e_status ret_code;

	info.hmc_info = &hw->hmc;
	info.rsrc_type = I40E_HMC_LAN_FULL;
	info.start_idx = 0;
	info.count = 1;

	/* delete the object */
	ret_code = i40e_delete_lan_hmc_object(hw, &info);

	/* free the SD table entry for LAN */
	i40e_free_virt_mem(hw, &hw->hmc.sd_table.addr);
	hw->hmc.sd_table.sd_cnt = 0;
	hw->hmc.sd_table.sd_entry = NULL;

	/* free memory used for hmc_obj */
	i40e_free_virt_mem(hw, &hw->hmc.hmc_obj_virt_mem);
	hw->hmc.hmc_obj = NULL;

	return ret_code;
}

__attribute__((used)) static void i40e_write_byte(u8 *hmc_bits,
			    struct i40e_context_ele *ce_info,
			    u8 *src)
{
	u8 src_byte, dest_byte, mask;
	u8 *from, *dest;
	u16 shift_width;

	/* copy from the next struct field */
	from = src + ce_info->offset;

	/* prepare the bits and mask */
	shift_width = ce_info->lsb % 8;
	mask = (u8)(BIT(ce_info->width) - 1);

	src_byte = *from;
	src_byte &= mask;

	/* shift to correct alignment */
	mask <<= shift_width;
	src_byte <<= shift_width;

	/* get the current bits from the target bit string */
	dest = hmc_bits + (ce_info->lsb / 8);

	memcpy(&dest_byte, dest, sizeof(dest_byte));

	dest_byte &= ~mask;	/* get the bits not changing */
	dest_byte |= src_byte;	/* add in the new bits */

	/* put it all back */
	memcpy(dest, &dest_byte, sizeof(dest_byte));
}

__attribute__((used)) static void i40e_write_word(u8 *hmc_bits,
			    struct i40e_context_ele *ce_info,
			    u8 *src)
{
	u16 src_word, mask;
	u8 *from, *dest;
	u16 shift_width;
	__le16 dest_word;

	/* copy from the next struct field */
	from = src + ce_info->offset;

	/* prepare the bits and mask */
	shift_width = ce_info->lsb % 8;
	mask = BIT(ce_info->width) - 1;

	/* don't swizzle the bits until after the mask because the mask bits
	 * will be in a different bit position on big endian machines
	 */
	src_word = *(u16 *)from;
	src_word &= mask;

	/* shift to correct alignment */
	mask <<= shift_width;
	src_word <<= shift_width;

	/* get the current bits from the target bit string */
	dest = hmc_bits + (ce_info->lsb / 8);

	memcpy(&dest_word, dest, sizeof(dest_word));

	dest_word &= ~(cpu_to_le16(mask));	/* get the bits not changing */
	dest_word |= cpu_to_le16(src_word);	/* add in the new bits */

	/* put it all back */
	memcpy(dest, &dest_word, sizeof(dest_word));
}

__attribute__((used)) static void i40e_write_dword(u8 *hmc_bits,
			     struct i40e_context_ele *ce_info,
			     u8 *src)
{
	u32 src_dword, mask;
	u8 *from, *dest;
	u16 shift_width;
	__le32 dest_dword;

	/* copy from the next struct field */
	from = src + ce_info->offset;

	/* prepare the bits and mask */
	shift_width = ce_info->lsb % 8;

	/* if the field width is exactly 32 on an x86 machine, then the shift
	 * operation will not work because the SHL instructions count is masked
	 * to 5 bits so the shift will do nothing
	 */
	if (ce_info->width < 32)
		mask = BIT(ce_info->width) - 1;
	else
		mask = ~(u32)0;

	/* don't swizzle the bits until after the mask because the mask bits
	 * will be in a different bit position on big endian machines
	 */
	src_dword = *(u32 *)from;
	src_dword &= mask;

	/* shift to correct alignment */
	mask <<= shift_width;
	src_dword <<= shift_width;

	/* get the current bits from the target bit string */
	dest = hmc_bits + (ce_info->lsb / 8);

	memcpy(&dest_dword, dest, sizeof(dest_dword));

	dest_dword &= ~(cpu_to_le32(mask));	/* get the bits not changing */
	dest_dword |= cpu_to_le32(src_dword);	/* add in the new bits */

	/* put it all back */
	memcpy(dest, &dest_dword, sizeof(dest_dword));
}

__attribute__((used)) static void i40e_write_qword(u8 *hmc_bits,
			     struct i40e_context_ele *ce_info,
			     u8 *src)
{
	u64 src_qword, mask;
	u8 *from, *dest;
	u16 shift_width;
	__le64 dest_qword;

	/* copy from the next struct field */
	from = src + ce_info->offset;

	/* prepare the bits and mask */
	shift_width = ce_info->lsb % 8;

	/* if the field width is exactly 64 on an x86 machine, then the shift
	 * operation will not work because the SHL instructions count is masked
	 * to 6 bits so the shift will do nothing
	 */
	if (ce_info->width < 64)
		mask = BIT_ULL(ce_info->width) - 1;
	else
		mask = ~(u64)0;

	/* don't swizzle the bits until after the mask because the mask bits
	 * will be in a different bit position on big endian machines
	 */
	src_qword = *(u64 *)from;
	src_qword &= mask;

	/* shift to correct alignment */
	mask <<= shift_width;
	src_qword <<= shift_width;

	/* get the current bits from the target bit string */
	dest = hmc_bits + (ce_info->lsb / 8);

	memcpy(&dest_qword, dest, sizeof(dest_qword));

	dest_qword &= ~(cpu_to_le64(mask));	/* get the bits not changing */
	dest_qword |= cpu_to_le64(src_qword);	/* add in the new bits */

	/* put it all back */
	memcpy(dest, &dest_qword, sizeof(dest_qword));
}

__attribute__((used)) static i40e_status i40e_clear_hmc_context(struct i40e_hw *hw,
					u8 *context_bytes,
					enum i40e_hmc_lan_rsrc_type hmc_type)
{
	/* clean the bit array */
	memset(context_bytes, 0, (u32)hw->hmc.hmc_obj[hmc_type].size);

	return 0;
}

__attribute__((used)) static i40e_status i40e_set_hmc_context(u8 *context_bytes,
					struct i40e_context_ele *ce_info,
					u8 *dest)
{
	int f;

	for (f = 0; ce_info[f].width != 0; f++) {

		/* we have to deal with each element of the HMC using the
		 * correct size so that we are correct regardless of the
		 * endianness of the machine
		 */
		switch (ce_info[f].size_of) {
		case 1:
			i40e_write_byte(context_bytes, &ce_info[f], dest);
			break;
		case 2:
			i40e_write_word(context_bytes, &ce_info[f], dest);
			break;
		case 4:
			i40e_write_dword(context_bytes, &ce_info[f], dest);
			break;
		case 8:
			i40e_write_qword(context_bytes, &ce_info[f], dest);
			break;
		}
	}

	return 0;
}

__attribute__((used)) static
i40e_status i40e_hmc_get_object_va(struct i40e_hmc_info *hmc_info,
					u8 **object_base,
					enum i40e_hmc_lan_rsrc_type rsrc_type,
					u32 obj_idx)
{
	u32 obj_offset_in_sd, obj_offset_in_pd;
	i40e_status ret_code = 0;
	struct i40e_hmc_sd_entry *sd_entry;
	struct i40e_hmc_pd_entry *pd_entry;
	u32 pd_idx, pd_lmt, rel_pd_idx;
	u64 obj_offset_in_fpm;
	u32 sd_idx, sd_lmt;

	if (NULL == hmc_info) {
		ret_code = I40E_ERR_BAD_PTR;
		hw_dbg(hw, "i40e_hmc_get_object_va: bad hmc_info ptr\n");
		goto exit;
	}
	if (NULL == hmc_info->hmc_obj) {
		ret_code = I40E_ERR_BAD_PTR;
		hw_dbg(hw, "i40e_hmc_get_object_va: bad hmc_info->hmc_obj ptr\n");
		goto exit;
	}
	if (NULL == object_base) {
		ret_code = I40E_ERR_BAD_PTR;
		hw_dbg(hw, "i40e_hmc_get_object_va: bad object_base ptr\n");
		goto exit;
	}
	if (I40E_HMC_INFO_SIGNATURE != hmc_info->signature) {
		ret_code = I40E_ERR_BAD_PTR;
		hw_dbg(hw, "i40e_hmc_get_object_va: bad hmc_info->signature\n");
		goto exit;
	}
	if (obj_idx >= hmc_info->hmc_obj[rsrc_type].cnt) {
		hw_dbg(hw, "i40e_hmc_get_object_va: returns error %d\n",
			  ret_code);
		ret_code = I40E_ERR_INVALID_HMC_OBJ_INDEX;
		goto exit;
	}
	/* find sd index and limit */
	I40E_FIND_SD_INDEX_LIMIT(hmc_info, rsrc_type, obj_idx, 1,
				 &sd_idx, &sd_lmt);

	sd_entry = &hmc_info->sd_table.sd_entry[sd_idx];
	obj_offset_in_fpm = hmc_info->hmc_obj[rsrc_type].base +
			    hmc_info->hmc_obj[rsrc_type].size * obj_idx;

	if (I40E_SD_TYPE_PAGED == sd_entry->entry_type) {
		I40E_FIND_PD_INDEX_LIMIT(hmc_info, rsrc_type, obj_idx, 1,
					 &pd_idx, &pd_lmt);
		rel_pd_idx = pd_idx % I40E_HMC_PD_CNT_IN_SD;
		pd_entry = &sd_entry->u.pd_table.pd_entry[rel_pd_idx];
		obj_offset_in_pd = (u32)(obj_offset_in_fpm %
					 I40E_HMC_PAGED_BP_SIZE);
		*object_base = (u8 *)pd_entry->bp.addr.va + obj_offset_in_pd;
	} else {
		obj_offset_in_sd = (u32)(obj_offset_in_fpm %
					 I40E_HMC_DIRECT_BP_SIZE);
		*object_base = (u8 *)sd_entry->u.bp.addr.va + obj_offset_in_sd;
	}
exit:
	return ret_code;
}

i40e_status i40e_clear_lan_tx_queue_context(struct i40e_hw *hw,
						      u16 queue)
{
	i40e_status err;
	u8 *context_bytes;

	err = i40e_hmc_get_object_va(&hw->hmc, &context_bytes,
				     I40E_HMC_LAN_TX, queue);
	if (err < 0)
		return err;

	return i40e_clear_hmc_context(hw, context_bytes, I40E_HMC_LAN_TX);
}

i40e_status i40e_set_lan_tx_queue_context(struct i40e_hw *hw,
						    u16 queue,
						    struct i40e_hmc_obj_txq *s)
{
	i40e_status err;
	u8 *context_bytes;

	err = i40e_hmc_get_object_va(&hw->hmc, &context_bytes,
				     I40E_HMC_LAN_TX, queue);
	if (err < 0)
		return err;

	return i40e_set_hmc_context(context_bytes,
				    i40e_hmc_txq_ce_info, (u8 *)s);
}

i40e_status i40e_clear_lan_rx_queue_context(struct i40e_hw *hw,
						      u16 queue)
{
	i40e_status err;
	u8 *context_bytes;

	err = i40e_hmc_get_object_va(&hw->hmc, &context_bytes,
				     I40E_HMC_LAN_RX, queue);
	if (err < 0)
		return err;

	return i40e_clear_hmc_context(hw, context_bytes, I40E_HMC_LAN_RX);
}

i40e_status i40e_set_lan_rx_queue_context(struct i40e_hw *hw,
						    u16 queue,
						    struct i40e_hmc_obj_rxq *s)
{
	i40e_status err;
	u8 *context_bytes;

	err = i40e_hmc_get_object_va(&hw->hmc, &context_bytes,
				     I40E_HMC_LAN_RX, queue);
	if (err < 0)
		return err;

	return i40e_set_hmc_context(context_bytes,
				    i40e_hmc_rxq_ce_info, (u8 *)s);
}

