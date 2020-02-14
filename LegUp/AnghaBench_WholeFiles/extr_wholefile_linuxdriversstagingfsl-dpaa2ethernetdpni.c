#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_24__   TYPE_9__ ;
typedef  struct TYPE_23__   TYPE_8__ ;
typedef  struct TYPE_22__   TYPE_7__ ;
typedef  struct TYPE_21__   TYPE_6__ ;
typedef  struct TYPE_20__   TYPE_5__ ;
typedef  struct TYPE_19__   TYPE_4__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;
typedef  struct TYPE_15__   TYPE_12__ ;
typedef  struct TYPE_14__   TYPE_11__ ;
typedef  struct TYPE_13__   TYPE_10__ ;

/* Type definitions */
struct TYPE_15__ {void** counter; } ;
union dpni_statistics {TYPE_12__ raw; } ;
typedef  int u8 ;
typedef  int u32 ;
typedef  void* u16 ;
struct fsl_mc_io {int dummy; } ;
struct fsl_mc_command {scalar_t__ params; void* header; int /*<<< orphan*/  member_0; } ;
struct dpni_taildrop {int enable; int threshold; int /*<<< orphan*/  units; } ;
struct TYPE_24__ {int miss_action; void* default_flow_id; } ;
struct dpni_rx_tc_dist_cfg {int dist_mode; void* key_cfg_iova; TYPE_9__ fs_cfg; void* dist_size; } ;
struct dpni_rsp_is_enabled {int /*<<< orphan*/  enabled; } ;
struct dpni_rsp_get_unicast_promisc {int /*<<< orphan*/  enabled; } ;
struct dpni_rsp_get_tx_data_offset {int /*<<< orphan*/  data_offset; } ;
struct dpni_rsp_get_taildrop {int /*<<< orphan*/  threshold; int /*<<< orphan*/  units; int /*<<< orphan*/  enable; } ;
struct dpni_rsp_get_statistics {int /*<<< orphan*/ * counter; } ;
struct dpni_rsp_get_queue {int /*<<< orphan*/  qdbin; int /*<<< orphan*/  fqid; int /*<<< orphan*/  user_context; int /*<<< orphan*/  flc; int /*<<< orphan*/  flags; int /*<<< orphan*/  dest_prio; int /*<<< orphan*/  dest_id; } ;
struct dpni_rsp_get_qdid {int /*<<< orphan*/  qdid; } ;
struct dpni_rsp_get_primary_mac_addr {int* mac_addr; } ;
struct dpni_rsp_get_port_mac_addr {int* mac_addr; } ;
struct dpni_rsp_get_offload {int /*<<< orphan*/  config; } ;
struct dpni_rsp_get_multicast_promisc {int /*<<< orphan*/  enabled; } ;
struct dpni_rsp_get_max_frame_length {int /*<<< orphan*/  max_frame_length; } ;
struct dpni_rsp_get_link_state {int /*<<< orphan*/  options; int /*<<< orphan*/  rate; int /*<<< orphan*/  flags; } ;
struct dpni_rsp_get_irq_status {int /*<<< orphan*/  status; } ;
struct dpni_rsp_get_irq_mask {int /*<<< orphan*/  mask; } ;
struct dpni_rsp_get_irq_enable {int /*<<< orphan*/  enabled; } ;
struct dpni_rsp_get_buffer_layout {int /*<<< orphan*/  tail_room; int /*<<< orphan*/  head_room; int /*<<< orphan*/  data_align; int /*<<< orphan*/  private_data_size; int /*<<< orphan*/  flags; } ;
struct dpni_rsp_get_attr {int /*<<< orphan*/  wriop_version; int /*<<< orphan*/  fs_key_size; int /*<<< orphan*/  qos_key_size; int /*<<< orphan*/  fs_entries; int /*<<< orphan*/  qos_entries; int /*<<< orphan*/  vlan_filter_entries; int /*<<< orphan*/  mac_filter_entries; int /*<<< orphan*/  num_tcs; int /*<<< orphan*/  num_queues; int /*<<< orphan*/  options; } ;
struct dpni_rsp_get_api_version {int /*<<< orphan*/  minor; int /*<<< orphan*/  major; } ;
struct dpni_queue_id {void* qdbin; void* fqid; } ;
struct TYPE_14__ {int stash_control; void* value; } ;
struct TYPE_13__ {int id; int type; int hold_active; int /*<<< orphan*/  priority; } ;
struct dpni_queue {void* user_context; TYPE_11__ flc; TYPE_10__ destination; } ;
struct dpni_pools_cfg {TYPE_8__* pools; int /*<<< orphan*/  num_dpbp; } ;
struct dpni_link_state {void* options; void* rate; void* up; } ;
struct dpni_link_cfg {int rate; void* options; } ;
struct dpni_ext_set_rx_tc_dist {int num_extracts; struct dpni_dist_extract* extracts; } ;
struct dpni_error_cfg {int errors; int error_action; int set_frame_annotation; } ;
struct dpni_dist_extract {TYPE_5__* masks; int /*<<< orphan*/  extract_type; int /*<<< orphan*/  num_of_byte_masks; int /*<<< orphan*/  offset; int /*<<< orphan*/  size; int /*<<< orphan*/  hdr_index; void* field; int /*<<< orphan*/  efh_type; int /*<<< orphan*/  prot; } ;
struct dpni_cmd_set_unicast_promisc {int /*<<< orphan*/  enable; } ;
struct dpni_cmd_set_taildrop {int congestion_point; int qtype; int tc; int index; void* threshold; int /*<<< orphan*/  units; int /*<<< orphan*/  enable; } ;
struct dpni_cmd_set_rx_tc_dist {int tc_id; void* key_cfg_iova; void* default_flow_id; int /*<<< orphan*/  flags; void* dist_size; } ;
struct dpni_cmd_set_queue {int qtype; int tc; int index; int options; void* user_context; void* flc; int /*<<< orphan*/  flags; int /*<<< orphan*/  dest_prio; void* dest_id; } ;
struct dpni_cmd_set_primary_mac_addr {int* mac_addr; } ;
struct dpni_cmd_set_pools {int /*<<< orphan*/  backup_pool_mask; void** buffer_size; void** dpbp_id; int /*<<< orphan*/  num_dpbp; } ;
struct dpni_cmd_set_offload {int dpni_offload; void* config; } ;
struct dpni_cmd_set_multicast_promisc {int /*<<< orphan*/  enable; } ;
struct dpni_cmd_set_max_frame_length {void* max_frame_length; } ;
struct dpni_cmd_set_link_cfg {void* options; void* rate; } ;
struct dpni_cmd_set_irq_mask {int irq_index; void* mask; } ;
struct dpni_cmd_set_irq_enable {int irq_index; int /*<<< orphan*/  enable; } ;
struct dpni_cmd_set_errors_behavior {int /*<<< orphan*/  flags; void* errors; } ;
struct dpni_cmd_set_buffer_layout {int qtype; void* tail_room; void* head_room; void* data_align; void* private_data_size; int /*<<< orphan*/  flags; void* options; } ;
struct dpni_cmd_remove_mac_addr {int* mac_addr; } ;
struct dpni_cmd_open {void* dpni_id; } ;
struct dpni_cmd_get_taildrop {int congestion_point; int qtype; int tc; int index; } ;
struct dpni_cmd_get_statistics {int page_number; } ;
struct dpni_cmd_get_queue {int qtype; int tc; int index; } ;
struct dpni_cmd_get_qdid {int qtype; } ;
struct dpni_cmd_get_offload {int dpni_offload; } ;
struct dpni_cmd_get_irq_status {int irq_index; void* status; } ;
struct dpni_cmd_get_irq_mask {int irq_index; } ;
struct dpni_cmd_get_irq_enable {int irq_index; } ;
struct dpni_cmd_get_buffer_layout {int qtype; } ;
struct dpni_cmd_clear_mac_filters {int /*<<< orphan*/  flags; } ;
struct dpni_cmd_clear_irq_status {int irq_index; void* status; } ;
struct dpni_cmd_add_mac_addr {int* mac_addr; } ;
struct dpni_buffer_layout {int pass_timestamp; int pass_parser_result; int pass_frame_status; void* data_tail_room; void* data_head_room; void* data_align; void* private_data_size; void* options; } ;
struct dpni_attr {void* wriop_version; int /*<<< orphan*/  fs_key_size; int /*<<< orphan*/  qos_key_size; void* fs_entries; int /*<<< orphan*/  qos_entries; int /*<<< orphan*/  vlan_filter_entries; int /*<<< orphan*/  mac_filter_entries; int /*<<< orphan*/  num_tcs; int /*<<< orphan*/  num_queues; void* options; } ;
struct dpkg_profile_cfg {int num_extracts; TYPE_7__* extracts; } ;
typedef  enum dpni_queue_type { ____Placeholder_dpni_queue_type } dpni_queue_type ;
typedef  enum dpni_offload { ____Placeholder_dpni_offload } dpni_offload ;
typedef  enum dpni_congestion_point { ____Placeholder_dpni_congestion_point } dpni_congestion_point ;
struct TYPE_23__ {int dpbp_id; int /*<<< orphan*/  backup_pool; void* buffer_size; } ;
struct TYPE_18__ {int /*<<< orphan*/  offset; int /*<<< orphan*/  size; } ;
struct TYPE_17__ {int /*<<< orphan*/  offset; int /*<<< orphan*/  size; } ;
struct TYPE_16__ {int type; int field; int /*<<< orphan*/  hdr_index; int /*<<< orphan*/  offset; int /*<<< orphan*/  size; int /*<<< orphan*/  prot; } ;
struct TYPE_19__ {TYPE_3__ from_parse; TYPE_2__ from_data; TYPE_1__ from_hdr; } ;
struct TYPE_22__ {int type; TYPE_6__* masks; int /*<<< orphan*/  num_of_byte_masks; TYPE_4__ extract; } ;
struct TYPE_21__ {int /*<<< orphan*/  offset; int /*<<< orphan*/  mask; } ;
struct TYPE_20__ {int /*<<< orphan*/  offset; int /*<<< orphan*/  mask; } ;

/* Variables and functions */
 int /*<<< orphan*/  DEST_TYPE ; 
 int /*<<< orphan*/  DIST_MODE ; 
#define  DPKG_EXTRACT_FROM_DATA 130 
#define  DPKG_EXTRACT_FROM_HDR 129 
#define  DPKG_EXTRACT_FROM_PARSE 128 
 int DPKG_MAX_NUM_OF_EXTRACTS ; 
 int DPKG_NUM_OF_MASKS ; 
 int /*<<< orphan*/  DPNI_BACKUP_POOL (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  DPNI_CMDID_ADD_MAC_ADDR ; 
 int /*<<< orphan*/  DPNI_CMDID_CLEAR_IRQ_STATUS ; 
 int /*<<< orphan*/  DPNI_CMDID_CLOSE ; 
 int /*<<< orphan*/  DPNI_CMDID_CLR_MAC_FILTERS ; 
 int /*<<< orphan*/  DPNI_CMDID_DISABLE ; 
 int /*<<< orphan*/  DPNI_CMDID_ENABLE ; 
 int /*<<< orphan*/  DPNI_CMDID_GET_API_VERSION ; 
 int /*<<< orphan*/  DPNI_CMDID_GET_ATTR ; 
 int /*<<< orphan*/  DPNI_CMDID_GET_BUFFER_LAYOUT ; 
 int /*<<< orphan*/  DPNI_CMDID_GET_IRQ_ENABLE ; 
 int /*<<< orphan*/  DPNI_CMDID_GET_IRQ_MASK ; 
 int /*<<< orphan*/  DPNI_CMDID_GET_IRQ_STATUS ; 
 int /*<<< orphan*/  DPNI_CMDID_GET_LINK_STATE ; 
 int /*<<< orphan*/  DPNI_CMDID_GET_MAX_FRAME_LENGTH ; 
 int /*<<< orphan*/  DPNI_CMDID_GET_MCAST_PROMISC ; 
 int /*<<< orphan*/  DPNI_CMDID_GET_OFFLOAD ; 
 int /*<<< orphan*/  DPNI_CMDID_GET_PORT_MAC_ADDR ; 
 int /*<<< orphan*/  DPNI_CMDID_GET_PRIM_MAC ; 
 int /*<<< orphan*/  DPNI_CMDID_GET_QDID ; 
 int /*<<< orphan*/  DPNI_CMDID_GET_QUEUE ; 
 int /*<<< orphan*/  DPNI_CMDID_GET_STATISTICS ; 
 int /*<<< orphan*/  DPNI_CMDID_GET_TAILDROP ; 
 int /*<<< orphan*/  DPNI_CMDID_GET_TX_DATA_OFFSET ; 
 int /*<<< orphan*/  DPNI_CMDID_GET_UNICAST_PROMISC ; 
 int /*<<< orphan*/  DPNI_CMDID_IS_ENABLED ; 
 int /*<<< orphan*/  DPNI_CMDID_OPEN ; 
 int /*<<< orphan*/  DPNI_CMDID_REMOVE_MAC_ADDR ; 
 int /*<<< orphan*/  DPNI_CMDID_RESET ; 
 int /*<<< orphan*/  DPNI_CMDID_SET_BUFFER_LAYOUT ; 
 int /*<<< orphan*/  DPNI_CMDID_SET_ERRORS_BEHAVIOR ; 
 int /*<<< orphan*/  DPNI_CMDID_SET_IRQ_ENABLE ; 
 int /*<<< orphan*/  DPNI_CMDID_SET_IRQ_MASK ; 
 int /*<<< orphan*/  DPNI_CMDID_SET_LINK_CFG ; 
 int /*<<< orphan*/  DPNI_CMDID_SET_MAX_FRAME_LENGTH ; 
 int /*<<< orphan*/  DPNI_CMDID_SET_MCAST_PROMISC ; 
 int /*<<< orphan*/  DPNI_CMDID_SET_OFFLOAD ; 
 int /*<<< orphan*/  DPNI_CMDID_SET_POOLS ; 
 int /*<<< orphan*/  DPNI_CMDID_SET_PRIM_MAC ; 
 int /*<<< orphan*/  DPNI_CMDID_SET_QUEUE ; 
 int /*<<< orphan*/  DPNI_CMDID_SET_RX_TC_DIST ; 
 int /*<<< orphan*/  DPNI_CMDID_SET_TAILDROP ; 
 int /*<<< orphan*/  DPNI_CMDID_SET_UNICAST_PROMISC ; 
 int DPNI_MAX_DPBP ; 
 int DPNI_STATISTICS_CNT ; 
 int /*<<< orphan*/  EFH_TYPE ; 
 int EINVAL ; 
 int /*<<< orphan*/  ENABLE ; 
 int /*<<< orphan*/  ERROR_ACTION ; 
 int /*<<< orphan*/  EXTRACT_TYPE ; 
 int /*<<< orphan*/  FRAME_ANN ; 
 int /*<<< orphan*/  HOLD_ACTIVE ; 
 int /*<<< orphan*/  LINK_STATE ; 
 int /*<<< orphan*/  MISS_ACTION ; 
 int /*<<< orphan*/  MULTICAST_FILTERS ; 
 int /*<<< orphan*/  PASS_FS ; 
 int /*<<< orphan*/  PASS_PR ; 
 int /*<<< orphan*/  PASS_TS ; 
 int /*<<< orphan*/  STASH_CTRL ; 
 int /*<<< orphan*/  UNICAST_FILTERS ; 
 void* cpu_to_le16 (void*) ; 
 void* cpu_to_le32 (int) ; 
 void* cpu_to_le64 (void*) ; 
 void* dpni_get_field (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dpni_set_field (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 void* le16_to_cpu (int /*<<< orphan*/ ) ; 
 void* le32_to_cpu (int /*<<< orphan*/ ) ; 
 void* le64_to_cpu (int /*<<< orphan*/ ) ; 
 void* mc_cmd_hdr_read_token (struct fsl_mc_command*) ; 
 void* mc_encode_cmd_header (int /*<<< orphan*/ ,int,void*) ; 
 int mc_send_command (struct fsl_mc_io*,struct fsl_mc_command*) ; 

int dpni_prepare_key_cfg(const struct dpkg_profile_cfg *cfg, u8 *key_cfg_buf)
{
	int i, j;
	struct dpni_ext_set_rx_tc_dist *dpni_ext;
	struct dpni_dist_extract *extr;

	if (cfg->num_extracts > DPKG_MAX_NUM_OF_EXTRACTS)
		return -EINVAL;

	dpni_ext = (struct dpni_ext_set_rx_tc_dist *)key_cfg_buf;
	dpni_ext->num_extracts = cfg->num_extracts;

	for (i = 0; i < cfg->num_extracts; i++) {
		extr = &dpni_ext->extracts[i];

		switch (cfg->extracts[i].type) {
		case DPKG_EXTRACT_FROM_HDR:
			extr->prot = cfg->extracts[i].extract.from_hdr.prot;
			dpni_set_field(extr->efh_type, EFH_TYPE,
				       cfg->extracts[i].extract.from_hdr.type);
			extr->size = cfg->extracts[i].extract.from_hdr.size;
			extr->offset = cfg->extracts[i].extract.from_hdr.offset;
			extr->field = cpu_to_le32(
				cfg->extracts[i].extract.from_hdr.field);
			extr->hdr_index =
				cfg->extracts[i].extract.from_hdr.hdr_index;
			break;
		case DPKG_EXTRACT_FROM_DATA:
			extr->size = cfg->extracts[i].extract.from_data.size;
			extr->offset =
				cfg->extracts[i].extract.from_data.offset;
			break;
		case DPKG_EXTRACT_FROM_PARSE:
			extr->size = cfg->extracts[i].extract.from_parse.size;
			extr->offset =
				cfg->extracts[i].extract.from_parse.offset;
			break;
		default:
			return -EINVAL;
		}

		extr->num_of_byte_masks = cfg->extracts[i].num_of_byte_masks;
		dpni_set_field(extr->extract_type, EXTRACT_TYPE,
			       cfg->extracts[i].type);

		for (j = 0; j < DPKG_NUM_OF_MASKS; j++) {
			extr->masks[j].mask = cfg->extracts[i].masks[j].mask;
			extr->masks[j].offset =
				cfg->extracts[i].masks[j].offset;
		}
	}

	return 0;
}

int dpni_open(struct fsl_mc_io *mc_io,
	      u32 cmd_flags,
	      int dpni_id,
	      u16 *token)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_cmd_open *cmd_params;

	int err;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_OPEN,
					  cmd_flags,
					  0);
	cmd_params = (struct dpni_cmd_open *)cmd.params;
	cmd_params->dpni_id = cpu_to_le32(dpni_id);

	/* send command to mc*/
	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	/* retrieve response parameters */
	*token = mc_cmd_hdr_read_token(&cmd);

	return 0;
}

int dpni_close(struct fsl_mc_io *mc_io,
	       u32 cmd_flags,
	       u16 token)
{
	struct fsl_mc_command cmd = { 0 };

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_CLOSE,
					  cmd_flags,
					  token);

	/* send command to mc*/
	return mc_send_command(mc_io, &cmd);
}

int dpni_set_pools(struct fsl_mc_io *mc_io,
		   u32 cmd_flags,
		   u16 token,
		   const struct dpni_pools_cfg *cfg)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_cmd_set_pools *cmd_params;
	int i;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_SET_POOLS,
					  cmd_flags,
					  token);
	cmd_params = (struct dpni_cmd_set_pools *)cmd.params;
	cmd_params->num_dpbp = cfg->num_dpbp;
	for (i = 0; i < DPNI_MAX_DPBP; i++) {
		cmd_params->dpbp_id[i] = cpu_to_le32(cfg->pools[i].dpbp_id);
		cmd_params->buffer_size[i] =
			cpu_to_le16(cfg->pools[i].buffer_size);
		cmd_params->backup_pool_mask |=
			DPNI_BACKUP_POOL(cfg->pools[i].backup_pool, i);
	}

	/* send command to mc*/
	return mc_send_command(mc_io, &cmd);
}

int dpni_enable(struct fsl_mc_io *mc_io,
		u32 cmd_flags,
		u16 token)
{
	struct fsl_mc_command cmd = { 0 };

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_ENABLE,
					  cmd_flags,
					  token);

	/* send command to mc*/
	return mc_send_command(mc_io, &cmd);
}

int dpni_disable(struct fsl_mc_io *mc_io,
		 u32 cmd_flags,
		 u16 token)
{
	struct fsl_mc_command cmd = { 0 };

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_DISABLE,
					  cmd_flags,
					  token);

	/* send command to mc*/
	return mc_send_command(mc_io, &cmd);
}

int dpni_is_enabled(struct fsl_mc_io *mc_io,
		    u32 cmd_flags,
		    u16 token,
		    int *en)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_rsp_is_enabled *rsp_params;
	int err;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_IS_ENABLED,
					  cmd_flags,
					  token);

	/* send command to mc*/
	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	/* retrieve response parameters */
	rsp_params = (struct dpni_rsp_is_enabled *)cmd.params;
	*en = dpni_get_field(rsp_params->enabled, ENABLE);

	return 0;
}

int dpni_reset(struct fsl_mc_io *mc_io,
	       u32 cmd_flags,
	       u16 token)
{
	struct fsl_mc_command cmd = { 0 };

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_RESET,
					  cmd_flags,
					  token);

	/* send command to mc*/
	return mc_send_command(mc_io, &cmd);
}

int dpni_set_irq_enable(struct fsl_mc_io *mc_io,
			u32 cmd_flags,
			u16 token,
			u8 irq_index,
			u8 en)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_cmd_set_irq_enable *cmd_params;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_SET_IRQ_ENABLE,
					  cmd_flags,
					  token);
	cmd_params = (struct dpni_cmd_set_irq_enable *)cmd.params;
	dpni_set_field(cmd_params->enable, ENABLE, en);
	cmd_params->irq_index = irq_index;

	/* send command to mc*/
	return mc_send_command(mc_io, &cmd);
}

int dpni_get_irq_enable(struct fsl_mc_io *mc_io,
			u32 cmd_flags,
			u16 token,
			u8 irq_index,
			u8 *en)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_cmd_get_irq_enable *cmd_params;
	struct dpni_rsp_get_irq_enable *rsp_params;

	int err;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_IRQ_ENABLE,
					  cmd_flags,
					  token);
	cmd_params = (struct dpni_cmd_get_irq_enable *)cmd.params;
	cmd_params->irq_index = irq_index;

	/* send command to mc*/
	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	/* retrieve response parameters */
	rsp_params = (struct dpni_rsp_get_irq_enable *)cmd.params;
	*en = dpni_get_field(rsp_params->enabled, ENABLE);

	return 0;
}

int dpni_set_irq_mask(struct fsl_mc_io *mc_io,
		      u32 cmd_flags,
		      u16 token,
		      u8 irq_index,
		      u32 mask)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_cmd_set_irq_mask *cmd_params;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_SET_IRQ_MASK,
					  cmd_flags,
					  token);
	cmd_params = (struct dpni_cmd_set_irq_mask *)cmd.params;
	cmd_params->mask = cpu_to_le32(mask);
	cmd_params->irq_index = irq_index;

	/* send command to mc*/
	return mc_send_command(mc_io, &cmd);
}

int dpni_get_irq_mask(struct fsl_mc_io *mc_io,
		      u32 cmd_flags,
		      u16 token,
		      u8 irq_index,
		      u32 *mask)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_cmd_get_irq_mask *cmd_params;
	struct dpni_rsp_get_irq_mask *rsp_params;
	int err;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_IRQ_MASK,
					  cmd_flags,
					  token);
	cmd_params = (struct dpni_cmd_get_irq_mask *)cmd.params;
	cmd_params->irq_index = irq_index;

	/* send command to mc*/
	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	/* retrieve response parameters */
	rsp_params = (struct dpni_rsp_get_irq_mask *)cmd.params;
	*mask = le32_to_cpu(rsp_params->mask);

	return 0;
}

int dpni_get_irq_status(struct fsl_mc_io *mc_io,
			u32 cmd_flags,
			u16 token,
			u8 irq_index,
			u32 *status)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_cmd_get_irq_status *cmd_params;
	struct dpni_rsp_get_irq_status *rsp_params;
	int err;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_IRQ_STATUS,
					  cmd_flags,
					  token);
	cmd_params = (struct dpni_cmd_get_irq_status *)cmd.params;
	cmd_params->status = cpu_to_le32(*status);
	cmd_params->irq_index = irq_index;

	/* send command to mc*/
	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	/* retrieve response parameters */
	rsp_params = (struct dpni_rsp_get_irq_status *)cmd.params;
	*status = le32_to_cpu(rsp_params->status);

	return 0;
}

int dpni_clear_irq_status(struct fsl_mc_io *mc_io,
			  u32 cmd_flags,
			  u16 token,
			  u8 irq_index,
			  u32 status)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_cmd_clear_irq_status *cmd_params;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_CLEAR_IRQ_STATUS,
					  cmd_flags,
					  token);
	cmd_params = (struct dpni_cmd_clear_irq_status *)cmd.params;
	cmd_params->irq_index = irq_index;
	cmd_params->status = cpu_to_le32(status);

	/* send command to mc*/
	return mc_send_command(mc_io, &cmd);
}

int dpni_get_attributes(struct fsl_mc_io *mc_io,
			u32 cmd_flags,
			u16 token,
			struct dpni_attr *attr)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_rsp_get_attr *rsp_params;

	int err;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_ATTR,
					  cmd_flags,
					  token);

	/* send command to mc*/
	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	/* retrieve response parameters */
	rsp_params = (struct dpni_rsp_get_attr *)cmd.params;
	attr->options = le32_to_cpu(rsp_params->options);
	attr->num_queues = rsp_params->num_queues;
	attr->num_tcs = rsp_params->num_tcs;
	attr->mac_filter_entries = rsp_params->mac_filter_entries;
	attr->vlan_filter_entries = rsp_params->vlan_filter_entries;
	attr->qos_entries = rsp_params->qos_entries;
	attr->fs_entries = le16_to_cpu(rsp_params->fs_entries);
	attr->qos_key_size = rsp_params->qos_key_size;
	attr->fs_key_size = rsp_params->fs_key_size;
	attr->wriop_version = le16_to_cpu(rsp_params->wriop_version);

	return 0;
}

int dpni_set_errors_behavior(struct fsl_mc_io *mc_io,
			     u32 cmd_flags,
			     u16 token,
			     struct dpni_error_cfg *cfg)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_cmd_set_errors_behavior *cmd_params;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_SET_ERRORS_BEHAVIOR,
					  cmd_flags,
					  token);
	cmd_params = (struct dpni_cmd_set_errors_behavior *)cmd.params;
	cmd_params->errors = cpu_to_le32(cfg->errors);
	dpni_set_field(cmd_params->flags, ERROR_ACTION, cfg->error_action);
	dpni_set_field(cmd_params->flags, FRAME_ANN, cfg->set_frame_annotation);

	/* send command to mc*/
	return mc_send_command(mc_io, &cmd);
}

int dpni_get_buffer_layout(struct fsl_mc_io *mc_io,
			   u32 cmd_flags,
			   u16 token,
			   enum dpni_queue_type qtype,
			   struct dpni_buffer_layout *layout)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_cmd_get_buffer_layout *cmd_params;
	struct dpni_rsp_get_buffer_layout *rsp_params;
	int err;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_BUFFER_LAYOUT,
					  cmd_flags,
					  token);
	cmd_params = (struct dpni_cmd_get_buffer_layout *)cmd.params;
	cmd_params->qtype = qtype;

	/* send command to mc*/
	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	/* retrieve response parameters */
	rsp_params = (struct dpni_rsp_get_buffer_layout *)cmd.params;
	layout->pass_timestamp = dpni_get_field(rsp_params->flags, PASS_TS);
	layout->pass_parser_result = dpni_get_field(rsp_params->flags, PASS_PR);
	layout->pass_frame_status = dpni_get_field(rsp_params->flags, PASS_FS);
	layout->private_data_size = le16_to_cpu(rsp_params->private_data_size);
	layout->data_align = le16_to_cpu(rsp_params->data_align);
	layout->data_head_room = le16_to_cpu(rsp_params->head_room);
	layout->data_tail_room = le16_to_cpu(rsp_params->tail_room);

	return 0;
}

int dpni_set_buffer_layout(struct fsl_mc_io *mc_io,
			   u32 cmd_flags,
			   u16 token,
			   enum dpni_queue_type qtype,
			   const struct dpni_buffer_layout *layout)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_cmd_set_buffer_layout *cmd_params;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_SET_BUFFER_LAYOUT,
					  cmd_flags,
					  token);
	cmd_params = (struct dpni_cmd_set_buffer_layout *)cmd.params;
	cmd_params->qtype = qtype;
	cmd_params->options = cpu_to_le16(layout->options);
	dpni_set_field(cmd_params->flags, PASS_TS, layout->pass_timestamp);
	dpni_set_field(cmd_params->flags, PASS_PR, layout->pass_parser_result);
	dpni_set_field(cmd_params->flags, PASS_FS, layout->pass_frame_status);
	cmd_params->private_data_size = cpu_to_le16(layout->private_data_size);
	cmd_params->data_align = cpu_to_le16(layout->data_align);
	cmd_params->head_room = cpu_to_le16(layout->data_head_room);
	cmd_params->tail_room = cpu_to_le16(layout->data_tail_room);

	/* send command to mc*/
	return mc_send_command(mc_io, &cmd);
}

int dpni_set_offload(struct fsl_mc_io *mc_io,
		     u32 cmd_flags,
		     u16 token,
		     enum dpni_offload type,
		     u32 config)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_cmd_set_offload *cmd_params;

	cmd.header = mc_encode_cmd_header(DPNI_CMDID_SET_OFFLOAD,
					  cmd_flags,
					  token);
	cmd_params = (struct dpni_cmd_set_offload *)cmd.params;
	cmd_params->dpni_offload = type;
	cmd_params->config = cpu_to_le32(config);

	return mc_send_command(mc_io, &cmd);
}

int dpni_get_offload(struct fsl_mc_io *mc_io,
		     u32 cmd_flags,
		     u16 token,
		     enum dpni_offload type,
		     u32 *config)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_cmd_get_offload *cmd_params;
	struct dpni_rsp_get_offload *rsp_params;
	int err;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_OFFLOAD,
					  cmd_flags,
					  token);
	cmd_params = (struct dpni_cmd_get_offload *)cmd.params;
	cmd_params->dpni_offload = type;

	/* send command to mc*/
	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	/* retrieve response parameters */
	rsp_params = (struct dpni_rsp_get_offload *)cmd.params;
	*config = le32_to_cpu(rsp_params->config);

	return 0;
}

int dpni_get_qdid(struct fsl_mc_io *mc_io,
		  u32 cmd_flags,
		  u16 token,
		  enum dpni_queue_type qtype,
		  u16 *qdid)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_cmd_get_qdid *cmd_params;
	struct dpni_rsp_get_qdid *rsp_params;
	int err;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_QDID,
					  cmd_flags,
					  token);
	cmd_params = (struct dpni_cmd_get_qdid *)cmd.params;
	cmd_params->qtype = qtype;

	/* send command to mc*/
	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	/* retrieve response parameters */
	rsp_params = (struct dpni_rsp_get_qdid *)cmd.params;
	*qdid = le16_to_cpu(rsp_params->qdid);

	return 0;
}

int dpni_get_tx_data_offset(struct fsl_mc_io *mc_io,
			    u32 cmd_flags,
			    u16 token,
			    u16 *data_offset)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_rsp_get_tx_data_offset *rsp_params;
	int err;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_TX_DATA_OFFSET,
					  cmd_flags,
					  token);

	/* send command to mc*/
	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	/* retrieve response parameters */
	rsp_params = (struct dpni_rsp_get_tx_data_offset *)cmd.params;
	*data_offset = le16_to_cpu(rsp_params->data_offset);

	return 0;
}

int dpni_set_link_cfg(struct fsl_mc_io *mc_io,
		      u32 cmd_flags,
		      u16 token,
		      const struct dpni_link_cfg *cfg)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_cmd_set_link_cfg *cmd_params;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_SET_LINK_CFG,
					  cmd_flags,
					  token);
	cmd_params = (struct dpni_cmd_set_link_cfg *)cmd.params;
	cmd_params->rate = cpu_to_le32(cfg->rate);
	cmd_params->options = cpu_to_le64(cfg->options);

	/* send command to mc*/
	return mc_send_command(mc_io, &cmd);
}

int dpni_get_link_state(struct fsl_mc_io *mc_io,
			u32 cmd_flags,
			u16 token,
			struct dpni_link_state *state)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_rsp_get_link_state *rsp_params;
	int err;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_LINK_STATE,
					  cmd_flags,
					  token);

	/* send command to mc*/
	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	/* retrieve response parameters */
	rsp_params = (struct dpni_rsp_get_link_state *)cmd.params;
	state->up = dpni_get_field(rsp_params->flags, LINK_STATE);
	state->rate = le32_to_cpu(rsp_params->rate);
	state->options = le64_to_cpu(rsp_params->options);

	return 0;
}

int dpni_set_max_frame_length(struct fsl_mc_io *mc_io,
			      u32 cmd_flags,
			      u16 token,
			      u16 max_frame_length)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_cmd_set_max_frame_length *cmd_params;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_SET_MAX_FRAME_LENGTH,
					  cmd_flags,
					  token);
	cmd_params = (struct dpni_cmd_set_max_frame_length *)cmd.params;
	cmd_params->max_frame_length = cpu_to_le16(max_frame_length);

	/* send command to mc*/
	return mc_send_command(mc_io, &cmd);
}

int dpni_get_max_frame_length(struct fsl_mc_io *mc_io,
			      u32 cmd_flags,
			      u16 token,
			      u16 *max_frame_length)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_rsp_get_max_frame_length *rsp_params;
	int err;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_MAX_FRAME_LENGTH,
					  cmd_flags,
					  token);

	/* send command to mc*/
	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	/* retrieve response parameters */
	rsp_params = (struct dpni_rsp_get_max_frame_length *)cmd.params;
	*max_frame_length = le16_to_cpu(rsp_params->max_frame_length);

	return 0;
}

int dpni_set_multicast_promisc(struct fsl_mc_io *mc_io,
			       u32 cmd_flags,
			       u16 token,
			       int en)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_cmd_set_multicast_promisc *cmd_params;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_SET_MCAST_PROMISC,
					  cmd_flags,
					  token);
	cmd_params = (struct dpni_cmd_set_multicast_promisc *)cmd.params;
	dpni_set_field(cmd_params->enable, ENABLE, en);

	/* send command to mc*/
	return mc_send_command(mc_io, &cmd);
}

int dpni_get_multicast_promisc(struct fsl_mc_io *mc_io,
			       u32 cmd_flags,
			       u16 token,
			       int *en)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_rsp_get_multicast_promisc *rsp_params;
	int err;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_MCAST_PROMISC,
					  cmd_flags,
					  token);

	/* send command to mc*/
	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	/* retrieve response parameters */
	rsp_params = (struct dpni_rsp_get_multicast_promisc *)cmd.params;
	*en = dpni_get_field(rsp_params->enabled, ENABLE);

	return 0;
}

int dpni_set_unicast_promisc(struct fsl_mc_io *mc_io,
			     u32 cmd_flags,
			     u16 token,
			     int en)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_cmd_set_unicast_promisc *cmd_params;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_SET_UNICAST_PROMISC,
					  cmd_flags,
					  token);
	cmd_params = (struct dpni_cmd_set_unicast_promisc *)cmd.params;
	dpni_set_field(cmd_params->enable, ENABLE, en);

	/* send command to mc*/
	return mc_send_command(mc_io, &cmd);
}

int dpni_get_unicast_promisc(struct fsl_mc_io *mc_io,
			     u32 cmd_flags,
			     u16 token,
			     int *en)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_rsp_get_unicast_promisc *rsp_params;
	int err;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_UNICAST_PROMISC,
					  cmd_flags,
					  token);

	/* send command to mc*/
	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	/* retrieve response parameters */
	rsp_params = (struct dpni_rsp_get_unicast_promisc *)cmd.params;
	*en = dpni_get_field(rsp_params->enabled, ENABLE);

	return 0;
}

int dpni_set_primary_mac_addr(struct fsl_mc_io *mc_io,
			      u32 cmd_flags,
			      u16 token,
			      const u8 mac_addr[6])
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_cmd_set_primary_mac_addr *cmd_params;
	int i;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_SET_PRIM_MAC,
					  cmd_flags,
					  token);
	cmd_params = (struct dpni_cmd_set_primary_mac_addr *)cmd.params;
	for (i = 0; i < 6; i++)
		cmd_params->mac_addr[i] = mac_addr[5 - i];

	/* send command to mc*/
	return mc_send_command(mc_io, &cmd);
}

int dpni_get_primary_mac_addr(struct fsl_mc_io *mc_io,
			      u32 cmd_flags,
			      u16 token,
			      u8 mac_addr[6])
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_rsp_get_primary_mac_addr *rsp_params;
	int i, err;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_PRIM_MAC,
					  cmd_flags,
					  token);

	/* send command to mc*/
	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	/* retrieve response parameters */
	rsp_params = (struct dpni_rsp_get_primary_mac_addr *)cmd.params;
	for (i = 0; i < 6; i++)
		mac_addr[5 - i] = rsp_params->mac_addr[i];

	return 0;
}

int dpni_get_port_mac_addr(struct fsl_mc_io *mc_io,
			   u32 cmd_flags,
			   u16 token,
			   u8 mac_addr[6])
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_rsp_get_port_mac_addr *rsp_params;
	int i, err;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_PORT_MAC_ADDR,
					  cmd_flags,
					  token);

	/* send command to mc*/
	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	/* retrieve response parameters */
	rsp_params = (struct dpni_rsp_get_port_mac_addr *)cmd.params;
	for (i = 0; i < 6; i++)
		mac_addr[5 - i] = rsp_params->mac_addr[i];

	return 0;
}

int dpni_add_mac_addr(struct fsl_mc_io *mc_io,
		      u32 cmd_flags,
		      u16 token,
		      const u8 mac_addr[6])
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_cmd_add_mac_addr *cmd_params;
	int i;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_ADD_MAC_ADDR,
					  cmd_flags,
					  token);
	cmd_params = (struct dpni_cmd_add_mac_addr *)cmd.params;
	for (i = 0; i < 6; i++)
		cmd_params->mac_addr[i] = mac_addr[5 - i];

	/* send command to mc*/
	return mc_send_command(mc_io, &cmd);
}

int dpni_remove_mac_addr(struct fsl_mc_io *mc_io,
			 u32 cmd_flags,
			 u16 token,
			 const u8 mac_addr[6])
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_cmd_remove_mac_addr *cmd_params;
	int i;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_REMOVE_MAC_ADDR,
					  cmd_flags,
					  token);
	cmd_params = (struct dpni_cmd_remove_mac_addr *)cmd.params;
	for (i = 0; i < 6; i++)
		cmd_params->mac_addr[i] = mac_addr[5 - i];

	/* send command to mc*/
	return mc_send_command(mc_io, &cmd);
}

int dpni_clear_mac_filters(struct fsl_mc_io *mc_io,
			   u32 cmd_flags,
			   u16 token,
			   int unicast,
			   int multicast)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_cmd_clear_mac_filters *cmd_params;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_CLR_MAC_FILTERS,
					  cmd_flags,
					  token);
	cmd_params = (struct dpni_cmd_clear_mac_filters *)cmd.params;
	dpni_set_field(cmd_params->flags, UNICAST_FILTERS, unicast);
	dpni_set_field(cmd_params->flags, MULTICAST_FILTERS, multicast);

	/* send command to mc*/
	return mc_send_command(mc_io, &cmd);
}

int dpni_set_rx_tc_dist(struct fsl_mc_io *mc_io,
			u32 cmd_flags,
			u16 token,
			u8 tc_id,
			const struct dpni_rx_tc_dist_cfg *cfg)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_cmd_set_rx_tc_dist *cmd_params;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_SET_RX_TC_DIST,
					  cmd_flags,
					  token);
	cmd_params = (struct dpni_cmd_set_rx_tc_dist *)cmd.params;
	cmd_params->dist_size = cpu_to_le16(cfg->dist_size);
	cmd_params->tc_id = tc_id;
	dpni_set_field(cmd_params->flags, DIST_MODE, cfg->dist_mode);
	dpni_set_field(cmd_params->flags, MISS_ACTION, cfg->fs_cfg.miss_action);
	cmd_params->default_flow_id = cpu_to_le16(cfg->fs_cfg.default_flow_id);
	cmd_params->key_cfg_iova = cpu_to_le64(cfg->key_cfg_iova);

	/* send command to mc*/
	return mc_send_command(mc_io, &cmd);
}

int dpni_set_queue(struct fsl_mc_io *mc_io,
		   u32 cmd_flags,
		   u16 token,
		   enum dpni_queue_type qtype,
		   u8 tc,
		   u8 index,
		   u8 options,
		   const struct dpni_queue *queue)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_cmd_set_queue *cmd_params;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_SET_QUEUE,
					  cmd_flags,
					  token);
	cmd_params = (struct dpni_cmd_set_queue *)cmd.params;
	cmd_params->qtype = qtype;
	cmd_params->tc = tc;
	cmd_params->index = index;
	cmd_params->options = options;
	cmd_params->dest_id = cpu_to_le32(queue->destination.id);
	cmd_params->dest_prio = queue->destination.priority;
	dpni_set_field(cmd_params->flags, DEST_TYPE, queue->destination.type);
	dpni_set_field(cmd_params->flags, STASH_CTRL, queue->flc.stash_control);
	dpni_set_field(cmd_params->flags, HOLD_ACTIVE,
		       queue->destination.hold_active);
	cmd_params->flc = cpu_to_le64(queue->flc.value);
	cmd_params->user_context = cpu_to_le64(queue->user_context);

	/* send command to mc */
	return mc_send_command(mc_io, &cmd);
}

int dpni_get_queue(struct fsl_mc_io *mc_io,
		   u32 cmd_flags,
		   u16 token,
		   enum dpni_queue_type qtype,
		   u8 tc,
		   u8 index,
		   struct dpni_queue *queue,
		   struct dpni_queue_id *qid)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_cmd_get_queue *cmd_params;
	struct dpni_rsp_get_queue *rsp_params;
	int err;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_QUEUE,
					  cmd_flags,
					  token);
	cmd_params = (struct dpni_cmd_get_queue *)cmd.params;
	cmd_params->qtype = qtype;
	cmd_params->tc = tc;
	cmd_params->index = index;

	/* send command to mc */
	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	/* retrieve response parameters */
	rsp_params = (struct dpni_rsp_get_queue *)cmd.params;
	queue->destination.id = le32_to_cpu(rsp_params->dest_id);
	queue->destination.priority = rsp_params->dest_prio;
	queue->destination.type = dpni_get_field(rsp_params->flags,
						 DEST_TYPE);
	queue->flc.stash_control = dpni_get_field(rsp_params->flags,
						  STASH_CTRL);
	queue->destination.hold_active = dpni_get_field(rsp_params->flags,
							HOLD_ACTIVE);
	queue->flc.value = le64_to_cpu(rsp_params->flc);
	queue->user_context = le64_to_cpu(rsp_params->user_context);
	qid->fqid = le32_to_cpu(rsp_params->fqid);
	qid->qdbin = le16_to_cpu(rsp_params->qdbin);

	return 0;
}

int dpni_get_statistics(struct fsl_mc_io *mc_io,
			u32 cmd_flags,
			u16 token,
			u8 page,
			union dpni_statistics *stat)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_cmd_get_statistics *cmd_params;
	struct dpni_rsp_get_statistics *rsp_params;
	int i, err;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_STATISTICS,
					  cmd_flags,
					  token);
	cmd_params = (struct dpni_cmd_get_statistics *)cmd.params;
	cmd_params->page_number = page;

	/* send command to mc */
	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	/* retrieve response parameters */
	rsp_params = (struct dpni_rsp_get_statistics *)cmd.params;
	for (i = 0; i < DPNI_STATISTICS_CNT; i++)
		stat->raw.counter[i] = le64_to_cpu(rsp_params->counter[i]);

	return 0;
}

int dpni_set_taildrop(struct fsl_mc_io *mc_io,
		      u32 cmd_flags,
		      u16 token,
		      enum dpni_congestion_point cg_point,
		      enum dpni_queue_type qtype,
		      u8 tc,
		      u8 index,
		      struct dpni_taildrop *taildrop)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_cmd_set_taildrop *cmd_params;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_SET_TAILDROP,
					  cmd_flags,
					  token);
	cmd_params = (struct dpni_cmd_set_taildrop *)cmd.params;
	cmd_params->congestion_point = cg_point;
	cmd_params->qtype = qtype;
	cmd_params->tc = tc;
	cmd_params->index = index;
	dpni_set_field(cmd_params->enable, ENABLE, taildrop->enable);
	cmd_params->units = taildrop->units;
	cmd_params->threshold = cpu_to_le32(taildrop->threshold);

	/* send command to mc */
	return mc_send_command(mc_io, &cmd);
}

int dpni_get_taildrop(struct fsl_mc_io *mc_io,
		      u32 cmd_flags,
		      u16 token,
		      enum dpni_congestion_point cg_point,
		      enum dpni_queue_type qtype,
		      u8 tc,
		      u8 index,
		      struct dpni_taildrop *taildrop)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpni_cmd_get_taildrop *cmd_params;
	struct dpni_rsp_get_taildrop *rsp_params;
	int err;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_TAILDROP,
					  cmd_flags,
					  token);
	cmd_params = (struct dpni_cmd_get_taildrop *)cmd.params;
	cmd_params->congestion_point = cg_point;
	cmd_params->qtype = qtype;
	cmd_params->tc = tc;
	cmd_params->index = index;

	/* send command to mc */
	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	/* retrieve response parameters */
	rsp_params = (struct dpni_rsp_get_taildrop *)cmd.params;
	taildrop->enable = dpni_get_field(rsp_params->enable, ENABLE);
	taildrop->units = rsp_params->units;
	taildrop->threshold = le32_to_cpu(rsp_params->threshold);

	return 0;
}

int dpni_get_api_version(struct fsl_mc_io *mc_io,
			 u32 cmd_flags,
			 u16 *major_ver,
			 u16 *minor_ver)
{
	struct dpni_rsp_get_api_version *rsp_params;
	struct fsl_mc_command cmd = { 0 };
	int err;

	cmd.header = mc_encode_cmd_header(DPNI_CMDID_GET_API_VERSION,
					  cmd_flags, 0);

	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	rsp_params = (struct dpni_rsp_get_api_version *)cmd.params;
	*major_ver = le16_to_cpu(rsp_params->major);
	*minor_ver = le16_to_cpu(rsp_params->minor);

	return 0;
}

