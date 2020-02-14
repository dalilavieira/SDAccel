#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
typedef  size_t u16 ;
struct TYPE_3__ {int numtc; int /*<<< orphan*/  ena_tc; } ;
struct ice_vsi {int base_vector; unsigned long* state; TYPE_1__ tc_cfg; } ;
struct ice_sq_cd {int dummy; } ;
struct ice_rx_ptype_decoded {int dummy; } ;
struct ice_q_vector {int v_idx; } ;
struct ice_pf {int oicr_idx; } ;
struct ice_nvm_info {int sr_words; int blank_nvm_mode; size_t ver; size_t eetrack; } ;
struct ice_hw {struct ice_nvm_info nvm; scalar_t__ back; } ;
struct ice_aqc_nvm {int offset_high; void* length; void* offset_low; void* module_typeid; int /*<<< orphan*/  cmd_flags; } ;
struct TYPE_4__ {struct ice_aqc_nvm nvm; } ;
struct ice_aq_desc {TYPE_2__ params; } ;
typedef  enum ice_status { ____Placeholder_ice_status } ice_status ;
typedef  enum ice_aq_res_access_type { ____Placeholder_ice_aq_res_access_type } ice_aq_res_access_type ;
typedef  int /*<<< orphan*/  __le16 ;

/* Variables and functions */
 int BIT (int) ; 
 int /*<<< orphan*/  GLINT_DYN_CTL (int) ; 
 int GLINT_DYN_CTL_CLEARPBA_M ; 
 int GLINT_DYN_CTL_INTENA_M ; 
 int GLINT_DYN_CTL_ITR_INDX_S ; 
 int /*<<< orphan*/  GLNVM_FLA ; 
 int GLNVM_FLA_LOCKED_M ; 
 int /*<<< orphan*/  GLNVM_GENS ; 
 int GLNVM_GENS_SR_SIZE_M ; 
 int GLNVM_GENS_SR_SIZE_S ; 
 int /*<<< orphan*/  ICE_AQC_NVM_LAST_CMD ; 
 int /*<<< orphan*/  ICE_DBG_INIT ; 
 int /*<<< orphan*/  ICE_DBG_NVM ; 
 int /*<<< orphan*/  ICE_DFLT_TRAFFIC_CLASS ; 
 int ICE_ERR_NVM_BLANK_MODE ; 
 int ICE_ERR_PARAM ; 
 int ICE_ITR_NONE ; 
 int /*<<< orphan*/  ICE_NVM_RES_ID ; 
 int ICE_RES_READ ; 
 size_t ICE_SR_NVM_DEV_STARTER_VER ; 
 size_t ICE_SR_NVM_EETRACK_HI ; 
 size_t ICE_SR_NVM_EETRACK_LO ; 
 size_t ICE_SR_SECTOR_SIZE_IN_WORDS ; 
 int ICE_SR_WORDS_IN_1KB ; 
 int __ICE_DOWN ; 
 void* cpu_to_le16 (size_t) ; 
 int ice_acquire_res (struct ice_hw*,int /*<<< orphan*/ ,int) ; 
 int ice_aq_send_cmd (struct ice_hw*,struct ice_aq_desc*,void*,size_t,struct ice_sq_cd*) ; 
 int /*<<< orphan*/  ice_aqc_opc_nvm_read ; 
 int /*<<< orphan*/  ice_debug (struct ice_hw*,int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  ice_fill_dflt_direct_cmd_desc (struct ice_aq_desc*,int /*<<< orphan*/ ) ; 
 struct ice_rx_ptype_decoded* ice_ptype_lkup ; 
 int /*<<< orphan*/  ice_release_res (struct ice_hw*,int /*<<< orphan*/ ) ; 
 size_t le16_to_cpu (int /*<<< orphan*/ ) ; 
 int rd32 (struct ice_hw*,int /*<<< orphan*/ ) ; 
 int test_bit (int,unsigned long*) ; 
 int /*<<< orphan*/  wr32 (struct ice_hw*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline struct ice_rx_ptype_decoded ice_decode_rx_desc_ptype(u16 ptype)
{
	return ice_ptype_lkup[ptype];
}

__attribute__((used)) static inline bool ice_is_tc_ena(u8 bitmap, u8 tc)
{
	return test_bit(tc, (unsigned long *)&bitmap);
}

__attribute__((used)) static inline void ice_irq_dynamic_ena(struct ice_hw *hw, struct ice_vsi *vsi,
				       struct ice_q_vector *q_vector)
{
	u32 vector = (vsi && q_vector) ? vsi->base_vector + q_vector->v_idx :
					((struct ice_pf *)hw->back)->oicr_idx;
	int itr = ICE_ITR_NONE;
	u32 val;

	/* clear the PBA here, as this function is meant to clean out all
	 * previous interrupts and enable the interrupt
	 */
	val = GLINT_DYN_CTL_INTENA_M | GLINT_DYN_CTL_CLEARPBA_M |
	      (itr << GLINT_DYN_CTL_ITR_INDX_S);
	if (vsi)
		if (test_bit(__ICE_DOWN, vsi->state))
			return;
	wr32(hw, GLINT_DYN_CTL(vector), val);
}

__attribute__((used)) static inline void ice_vsi_set_tc_cfg(struct ice_vsi *vsi)
{
	vsi->tc_cfg.ena_tc =  ICE_DFLT_TRAFFIC_CLASS;
	vsi->tc_cfg.numtc = 1;
}

__attribute__((used)) static enum ice_status
ice_aq_read_nvm(struct ice_hw *hw, u16 module_typeid, u32 offset, u16 length,
		void *data, bool last_command, struct ice_sq_cd *cd)
{
	struct ice_aq_desc desc;
	struct ice_aqc_nvm *cmd;

	cmd = &desc.params.nvm;

	/* In offset the highest byte must be zeroed. */
	if (offset & 0xFF000000)
		return ICE_ERR_PARAM;

	ice_fill_dflt_direct_cmd_desc(&desc, ice_aqc_opc_nvm_read);

	/* If this is the last command in a series, set the proper flag. */
	if (last_command)
		cmd->cmd_flags |= ICE_AQC_NVM_LAST_CMD;
	cmd->module_typeid = cpu_to_le16(module_typeid);
	cmd->offset_low = cpu_to_le16(offset & 0xFFFF);
	cmd->offset_high = (offset >> 16) & 0xFF;
	cmd->length = cpu_to_le16(length);

	return ice_aq_send_cmd(hw, &desc, data, length, cd);
}

__attribute__((used)) static enum ice_status
ice_check_sr_access_params(struct ice_hw *hw, u32 offset, u16 words)
{
	if ((offset + words) > hw->nvm.sr_words) {
		ice_debug(hw, ICE_DBG_NVM,
			  "NVM error: offset beyond SR lmt.\n");
		return ICE_ERR_PARAM;
	}

	if (words > ICE_SR_SECTOR_SIZE_IN_WORDS) {
		/* We can access only up to 4KB (one sector), in one AQ write */
		ice_debug(hw, ICE_DBG_NVM,
			  "NVM error: tried to access %d words, limit is %d.\n",
			  words, ICE_SR_SECTOR_SIZE_IN_WORDS);
		return ICE_ERR_PARAM;
	}

	if (((offset + (words - 1)) / ICE_SR_SECTOR_SIZE_IN_WORDS) !=
	    (offset / ICE_SR_SECTOR_SIZE_IN_WORDS)) {
		/* A single access cannot spread over two sectors */
		ice_debug(hw, ICE_DBG_NVM,
			  "NVM error: cannot spread over two sectors.\n");
		return ICE_ERR_PARAM;
	}

	return 0;
}

__attribute__((used)) static enum ice_status
ice_read_sr_aq(struct ice_hw *hw, u32 offset, u16 words, u16 *data,
	       bool last_command)
{
	enum ice_status status;

	status = ice_check_sr_access_params(hw, offset, words);

	/* values in "offset" and "words" parameters are sized as words
	 * (16 bits) but ice_aq_read_nvm expects these values in bytes.
	 * So do this conversion while calling ice_aq_read_nvm.
	 */
	if (!status)
		status = ice_aq_read_nvm(hw, 0, 2 * offset, 2 * words, data,
					 last_command, NULL);

	return status;
}

__attribute__((used)) static enum ice_status
ice_read_sr_word_aq(struct ice_hw *hw, u16 offset, u16 *data)
{
	enum ice_status status;

	status = ice_read_sr_aq(hw, offset, 1, data, true);
	if (!status)
		*data = le16_to_cpu(*(__le16 *)data);

	return status;
}

__attribute__((used)) static enum ice_status
ice_acquire_nvm(struct ice_hw *hw, enum ice_aq_res_access_type access)
{
	if (hw->nvm.blank_nvm_mode)
		return 0;

	return ice_acquire_res(hw, ICE_NVM_RES_ID, access);
}

__attribute__((used)) static void ice_release_nvm(struct ice_hw *hw)
{
	if (hw->nvm.blank_nvm_mode)
		return;

	ice_release_res(hw, ICE_NVM_RES_ID);
}

__attribute__((used)) static enum ice_status
ice_read_sr_word(struct ice_hw *hw, u16 offset, u16 *data)
{
	enum ice_status status;

	status = ice_acquire_nvm(hw, ICE_RES_READ);
	if (!status) {
		status = ice_read_sr_word_aq(hw, offset, data);
		ice_release_nvm(hw);
	}

	return status;
}

enum ice_status ice_init_nvm(struct ice_hw *hw)
{
	struct ice_nvm_info *nvm = &hw->nvm;
	u16 eetrack_lo, eetrack_hi;
	enum ice_status status = 0;
	u32 fla, gens_stat;
	u8 sr_size;

	/* The SR size is stored regardless of the nvm programming mode
	 * as the blank mode may be used in the factory line.
	 */
	gens_stat = rd32(hw, GLNVM_GENS);
	sr_size = (gens_stat & GLNVM_GENS_SR_SIZE_M) >> GLNVM_GENS_SR_SIZE_S;

	/* Switching to words (sr_size contains power of 2) */
	nvm->sr_words = BIT(sr_size) * ICE_SR_WORDS_IN_1KB;

	/* Check if we are in the normal or blank NVM programming mode */
	fla = rd32(hw, GLNVM_FLA);
	if (fla & GLNVM_FLA_LOCKED_M) { /* Normal programming mode */
		nvm->blank_nvm_mode = false;
	} else { /* Blank programming mode */
		nvm->blank_nvm_mode = true;
		status = ICE_ERR_NVM_BLANK_MODE;
		ice_debug(hw, ICE_DBG_NVM,
			  "NVM init error: unsupported blank mode.\n");
		return status;
	}

	status = ice_read_sr_word(hw, ICE_SR_NVM_DEV_STARTER_VER, &hw->nvm.ver);
	if (status) {
		ice_debug(hw, ICE_DBG_INIT,
			  "Failed to read DEV starter version.\n");
		return status;
	}

	status = ice_read_sr_word(hw, ICE_SR_NVM_EETRACK_LO, &eetrack_lo);
	if (status) {
		ice_debug(hw, ICE_DBG_INIT, "Failed to read EETRACK lo.\n");
		return status;
	}
	status = ice_read_sr_word(hw, ICE_SR_NVM_EETRACK_HI, &eetrack_hi);
	if (status) {
		ice_debug(hw, ICE_DBG_INIT, "Failed to read EETRACK hi.\n");
		return status;
	}

	hw->nvm.eetrack = (eetrack_hi << 16) | eetrack_lo;

	return status;
}

