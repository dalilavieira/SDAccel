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
typedef  int /*<<< orphan*/  uint64_t ;
typedef  void* u8 ;
typedef  int u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct fsl_mc_io {int dummy; } ;
struct fsl_mc_command {scalar_t__ params; void* header; int /*<<< orphan*/  member_0; } ;
struct dprtc_time {void* time; } ;
struct dprtc_rsp_is_enabled {int /*<<< orphan*/  en; } ;
struct dprtc_rsp_get_irq_status {void* status; } ;
struct dprtc_rsp_get_irq_mask {void* mask; } ;
struct dprtc_rsp_get_irq_enable {void* en; } ;
struct dprtc_rsp_get_attributes {void* id; } ;
struct dprtc_rsp_get_api_version {int /*<<< orphan*/  minor; int /*<<< orphan*/  major; } ;
struct dprtc_get_freq_compensation {void* freq_compensation; } ;
struct dprtc_cmd_set_irq_mask {void* irq_index; void* mask; } ;
struct dprtc_cmd_set_irq_enable {void* en; void* irq_index; } ;
struct dprtc_cmd_set_clock_offset {void* offset; } ;
struct dprtc_cmd_open {void* dprtc_id; } ;
struct dprtc_cmd_get_irq_status {void* irq_index; void* status; } ;
struct dprtc_cmd_get_irq {void* irq_index; } ;
struct dprtc_cmd_destroy {void* object_id; } ;
struct dprtc_cmd_clear_irq_status {void* status; void* irq_index; } ;
struct dprtc_cfg {int dummy; } ;
struct dprtc_attr {void* id; } ;
typedef  int /*<<< orphan*/  int64_t ;

/* Variables and functions */
 int /*<<< orphan*/  DPRTC_CMDID_CLEAR_IRQ_STATUS ; 
 int /*<<< orphan*/  DPRTC_CMDID_CLOSE ; 
 int /*<<< orphan*/  DPRTC_CMDID_CREATE ; 
 int /*<<< orphan*/  DPRTC_CMDID_DESTROY ; 
 int /*<<< orphan*/  DPRTC_CMDID_DISABLE ; 
 int /*<<< orphan*/  DPRTC_CMDID_ENABLE ; 
 int /*<<< orphan*/  DPRTC_CMDID_GET_API_VERSION ; 
 int /*<<< orphan*/  DPRTC_CMDID_GET_ATTR ; 
 int /*<<< orphan*/  DPRTC_CMDID_GET_FREQ_COMPENSATION ; 
 int /*<<< orphan*/  DPRTC_CMDID_GET_IRQ_ENABLE ; 
 int /*<<< orphan*/  DPRTC_CMDID_GET_IRQ_MASK ; 
 int /*<<< orphan*/  DPRTC_CMDID_GET_IRQ_STATUS ; 
 int /*<<< orphan*/  DPRTC_CMDID_GET_TIME ; 
 int /*<<< orphan*/  DPRTC_CMDID_IS_ENABLED ; 
 int /*<<< orphan*/  DPRTC_CMDID_OPEN ; 
 int /*<<< orphan*/  DPRTC_CMDID_RESET ; 
 int /*<<< orphan*/  DPRTC_CMDID_SET_ALARM ; 
 int /*<<< orphan*/  DPRTC_CMDID_SET_CLOCK_OFFSET ; 
 int /*<<< orphan*/  DPRTC_CMDID_SET_FREQ_COMPENSATION ; 
 int /*<<< orphan*/  DPRTC_CMDID_SET_IRQ_ENABLE ; 
 int /*<<< orphan*/  DPRTC_CMDID_SET_IRQ_MASK ; 
 int /*<<< orphan*/  DPRTC_CMDID_SET_TIME ; 
 int /*<<< orphan*/  ENABLE ; 
 void* cpu_to_le32 (int) ; 
 void* cpu_to_le64 (int /*<<< orphan*/ ) ; 
 int dprtc_get_field (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  le16_to_cpu (int /*<<< orphan*/ ) ; 
 void* le32_to_cpu (void*) ; 
 int /*<<< orphan*/  le64_to_cpu (void*) ; 
 int /*<<< orphan*/  mc_cmd_hdr_read_token (struct fsl_mc_command*) ; 
 int mc_cmd_read_object_id (struct fsl_mc_command*) ; 
 void* mc_encode_cmd_header (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int mc_send_command (struct fsl_mc_io*,struct fsl_mc_command*) ; 

int dprtc_open(struct fsl_mc_io *mc_io,
	       u32 cmd_flags,
	       int dprtc_id,
	       u16 *token)
{
	struct dprtc_cmd_open *cmd_params;
	struct fsl_mc_command cmd = { 0 };
	int err;

	cmd.header = mc_encode_cmd_header(DPRTC_CMDID_OPEN,
					  cmd_flags,
					  0);
	cmd_params = (struct dprtc_cmd_open *)cmd.params;
	cmd_params->dprtc_id = cpu_to_le32(dprtc_id);

	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	*token = mc_cmd_hdr_read_token(&cmd);

	return 0;
}

int dprtc_close(struct fsl_mc_io *mc_io,
		u32 cmd_flags,
		u16 token)
{
	struct fsl_mc_command cmd = { 0 };

	cmd.header = mc_encode_cmd_header(DPRTC_CMDID_CLOSE, cmd_flags,
					  token);

	return mc_send_command(mc_io, &cmd);
}

int dprtc_create(struct fsl_mc_io *mc_io,
		 u16 dprc_token,
		 u32 cmd_flags,
		 const struct dprtc_cfg *cfg,
		 u32 *obj_id)
{
	struct fsl_mc_command cmd = { 0 };
	int err;

	cmd.header = mc_encode_cmd_header(DPRTC_CMDID_CREATE,
					  cmd_flags,
					  dprc_token);

	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	*obj_id = mc_cmd_read_object_id(&cmd);

	return 0;
}

int dprtc_destroy(struct fsl_mc_io *mc_io,
		  u16 dprc_token,
		  u32 cmd_flags,
		  u32 object_id)
{
	struct dprtc_cmd_destroy *cmd_params;
	struct fsl_mc_command cmd = { 0 };

	cmd.header = mc_encode_cmd_header(DPRTC_CMDID_DESTROY,
					  cmd_flags,
					  dprc_token);
	cmd_params = (struct dprtc_cmd_destroy *)cmd.params;
	cmd_params->object_id = cpu_to_le32(object_id);

	return mc_send_command(mc_io, &cmd);
}

int dprtc_enable(struct fsl_mc_io *mc_io,
		 u32 cmd_flags,
		 u16 token)
{
	struct fsl_mc_command cmd = { 0 };

	cmd.header = mc_encode_cmd_header(DPRTC_CMDID_ENABLE, cmd_flags,
					  token);

	return mc_send_command(mc_io, &cmd);
}

int dprtc_disable(struct fsl_mc_io *mc_io,
		  u32 cmd_flags,
		  u16 token)
{
	struct fsl_mc_command cmd = { 0 };

	cmd.header = mc_encode_cmd_header(DPRTC_CMDID_DISABLE,
					  cmd_flags,
					  token);

	return mc_send_command(mc_io, &cmd);
}

int dprtc_is_enabled(struct fsl_mc_io *mc_io,
		     u32 cmd_flags,
		     u16 token,
		     int *en)
{
	struct dprtc_rsp_is_enabled *rsp_params;
	struct fsl_mc_command cmd = { 0 };
	int err;

	cmd.header = mc_encode_cmd_header(DPRTC_CMDID_IS_ENABLED, cmd_flags,
					  token);

	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	rsp_params = (struct dprtc_rsp_is_enabled *)cmd.params;
	*en = dprtc_get_field(rsp_params->en, ENABLE);

	return 0;
}

int dprtc_reset(struct fsl_mc_io *mc_io,
		u32 cmd_flags,
		u16 token)
{
	struct fsl_mc_command cmd = { 0 };

	cmd.header = mc_encode_cmd_header(DPRTC_CMDID_RESET,
					  cmd_flags,
					  token);

	return mc_send_command(mc_io, &cmd);
}

int dprtc_set_irq_enable(struct fsl_mc_io *mc_io,
			 u32 cmd_flags,
			 u16 token,
			 u8 irq_index,
			 u8 en)
{
	struct dprtc_cmd_set_irq_enable *cmd_params;
	struct fsl_mc_command cmd = { 0 };

	cmd.header = mc_encode_cmd_header(DPRTC_CMDID_SET_IRQ_ENABLE,
					  cmd_flags,
					  token);
	cmd_params = (struct dprtc_cmd_set_irq_enable *)cmd.params;
	cmd_params->irq_index = irq_index;
	cmd_params->en = en;

	return mc_send_command(mc_io, &cmd);
}

int dprtc_get_irq_enable(struct fsl_mc_io *mc_io,
			 u32 cmd_flags,
			 u16 token,
			 u8 irq_index,
			 u8 *en)
{
	struct dprtc_rsp_get_irq_enable *rsp_params;
	struct dprtc_cmd_get_irq *cmd_params;
	struct fsl_mc_command cmd = { 0 };
	int err;

	cmd.header = mc_encode_cmd_header(DPRTC_CMDID_GET_IRQ_ENABLE,
					  cmd_flags,
					  token);
	cmd_params = (struct dprtc_cmd_get_irq *)cmd.params;
	cmd_params->irq_index = irq_index;

	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	rsp_params = (struct dprtc_rsp_get_irq_enable *)cmd.params;
	*en = rsp_params->en;

	return 0;
}

int dprtc_set_irq_mask(struct fsl_mc_io *mc_io,
		       u32 cmd_flags,
		       u16 token,
		       u8 irq_index,
		       u32 mask)
{
	struct dprtc_cmd_set_irq_mask *cmd_params;
	struct fsl_mc_command cmd = { 0 };

	cmd.header = mc_encode_cmd_header(DPRTC_CMDID_SET_IRQ_MASK,
					  cmd_flags,
					  token);
	cmd_params = (struct dprtc_cmd_set_irq_mask *)cmd.params;
	cmd_params->mask = cpu_to_le32(mask);
	cmd_params->irq_index = irq_index;

	return mc_send_command(mc_io, &cmd);
}

int dprtc_get_irq_mask(struct fsl_mc_io *mc_io,
		       u32 cmd_flags,
		       u16 token,
		       u8 irq_index,
		       u32 *mask)
{
	struct dprtc_rsp_get_irq_mask *rsp_params;
	struct dprtc_cmd_get_irq *cmd_params;
	struct fsl_mc_command cmd = { 0 };
	int err;

	cmd.header = mc_encode_cmd_header(DPRTC_CMDID_GET_IRQ_MASK,
					  cmd_flags,
					  token);
	cmd_params = (struct dprtc_cmd_get_irq *)cmd.params;
	cmd_params->irq_index = irq_index;

	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	rsp_params = (struct dprtc_rsp_get_irq_mask *)cmd.params;
	*mask = le32_to_cpu(rsp_params->mask);

	return 0;
}

int dprtc_get_irq_status(struct fsl_mc_io *mc_io,
			 u32 cmd_flags,
			 u16 token,
			 u8 irq_index,
			 u32 *status)
{
	struct dprtc_cmd_get_irq_status *cmd_params;
	struct dprtc_rsp_get_irq_status *rsp_params;
	struct fsl_mc_command cmd = { 0 };
	int err;

	cmd.header = mc_encode_cmd_header(DPRTC_CMDID_GET_IRQ_STATUS,
					  cmd_flags,
					  token);
	cmd_params = (struct dprtc_cmd_get_irq_status *)cmd.params;
	cmd_params->status = cpu_to_le32(*status);
	cmd_params->irq_index = irq_index;

	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	rsp_params = (struct dprtc_rsp_get_irq_status *)cmd.params;
	*status = le32_to_cpu(rsp_params->status);

	return 0;
}

int dprtc_clear_irq_status(struct fsl_mc_io *mc_io,
			   u32 cmd_flags,
			   u16 token,
			   u8 irq_index,
			   u32 status)
{
	struct dprtc_cmd_clear_irq_status *cmd_params;
	struct fsl_mc_command cmd = { 0 };

	cmd.header = mc_encode_cmd_header(DPRTC_CMDID_CLEAR_IRQ_STATUS,
					  cmd_flags,
					  token);
	cmd_params = (struct dprtc_cmd_clear_irq_status *)cmd.params;
	cmd_params->irq_index = irq_index;
	cmd_params->status = cpu_to_le32(status);

	return mc_send_command(mc_io, &cmd);
}

int dprtc_get_attributes(struct fsl_mc_io *mc_io,
			 u32 cmd_flags,
			 u16 token,
			 struct dprtc_attr *attr)
{
	struct dprtc_rsp_get_attributes *rsp_params;
	struct fsl_mc_command cmd = { 0 };
	int err;

	cmd.header = mc_encode_cmd_header(DPRTC_CMDID_GET_ATTR,
					  cmd_flags,
					  token);

	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	rsp_params = (struct dprtc_rsp_get_attributes *)cmd.params;
	attr->id = le32_to_cpu(rsp_params->id);

	return 0;
}

int dprtc_set_clock_offset(struct fsl_mc_io *mc_io,
			   u32 cmd_flags,
			   u16 token,
			   int64_t offset)
{
	struct dprtc_cmd_set_clock_offset *cmd_params;
	struct fsl_mc_command cmd = { 0 };

	cmd.header = mc_encode_cmd_header(DPRTC_CMDID_SET_CLOCK_OFFSET,
					  cmd_flags,
					  token);
	cmd_params = (struct dprtc_cmd_set_clock_offset *)cmd.params;
	cmd_params->offset = cpu_to_le64(offset);

	return mc_send_command(mc_io, &cmd);
}

int dprtc_set_freq_compensation(struct fsl_mc_io *mc_io,
				u32 cmd_flags,
				u16 token,
				u32 freq_compensation)
{
	struct dprtc_get_freq_compensation *cmd_params;
	struct fsl_mc_command cmd = { 0 };

	cmd.header = mc_encode_cmd_header(DPRTC_CMDID_SET_FREQ_COMPENSATION,
					  cmd_flags,
					  token);
	cmd_params = (struct dprtc_get_freq_compensation *)cmd.params;
	cmd_params->freq_compensation = cpu_to_le32(freq_compensation);

	return mc_send_command(mc_io, &cmd);
}

int dprtc_get_freq_compensation(struct fsl_mc_io *mc_io,
				u32 cmd_flags,
				u16 token,
				u32 *freq_compensation)
{
	struct dprtc_get_freq_compensation *rsp_params;
	struct fsl_mc_command cmd = { 0 };
	int err;

	cmd.header = mc_encode_cmd_header(DPRTC_CMDID_GET_FREQ_COMPENSATION,
					  cmd_flags,
					  token);

	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	rsp_params = (struct dprtc_get_freq_compensation *)cmd.params;
	*freq_compensation = le32_to_cpu(rsp_params->freq_compensation);

	return 0;
}

int dprtc_get_time(struct fsl_mc_io *mc_io,
		   u32 cmd_flags,
		   u16 token,
		   uint64_t *time)
{
	struct dprtc_time *rsp_params;
	struct fsl_mc_command cmd = { 0 };
	int err;

	cmd.header = mc_encode_cmd_header(DPRTC_CMDID_GET_TIME,
					  cmd_flags,
					  token);

	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	rsp_params = (struct dprtc_time *)cmd.params;
	*time = le64_to_cpu(rsp_params->time);

	return 0;
}

int dprtc_set_time(struct fsl_mc_io *mc_io,
		   u32 cmd_flags,
		   u16 token,
		   uint64_t time)
{
	struct dprtc_time *cmd_params;
	struct fsl_mc_command cmd = { 0 };

	cmd.header = mc_encode_cmd_header(DPRTC_CMDID_SET_TIME,
					  cmd_flags,
					  token);
	cmd_params = (struct dprtc_time *)cmd.params;
	cmd_params->time = cpu_to_le64(time);

	return mc_send_command(mc_io, &cmd);
}

int dprtc_set_alarm(struct fsl_mc_io *mc_io,
		    u32 cmd_flags,
		    u16 token, uint64_t time)
{
	struct dprtc_time *cmd_params;
	struct fsl_mc_command cmd = { 0 };

	cmd.header = mc_encode_cmd_header(DPRTC_CMDID_SET_ALARM,
					  cmd_flags,
					  token);
	cmd_params = (struct dprtc_time *)cmd.params;
	cmd_params->time = cpu_to_le64(time);

	return mc_send_command(mc_io, &cmd);
}

int dprtc_get_api_version(struct fsl_mc_io *mc_io,
			  u32 cmd_flags,
			  u16 *major_ver,
			  u16 *minor_ver)
{
	struct dprtc_rsp_get_api_version *rsp_params;
	struct fsl_mc_command cmd = { 0 };
	int err;

	cmd.header = mc_encode_cmd_header(DPRTC_CMDID_GET_API_VERSION,
					  cmd_flags,
					  0);

	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	rsp_params = (struct dprtc_rsp_get_api_version *)cmd.params;
	*major_ver = le16_to_cpu(rsp_params->major);
	*minor_ver = le16_to_cpu(rsp_params->minor);

	return 0;
}

