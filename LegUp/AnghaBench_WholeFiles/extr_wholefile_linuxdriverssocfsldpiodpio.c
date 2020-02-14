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
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct fsl_mc_io {int dummy; } ;
struct fsl_mc_command {void* header; int /*<<< orphan*/  member_0; scalar_t__ params; } ;
struct dpio_rsp_get_attr {int channel_mode; int /*<<< orphan*/  qbman_version; int /*<<< orphan*/  qbman_portal_ci_addr; int /*<<< orphan*/  qbman_portal_ce_addr; int /*<<< orphan*/  num_priorities; int /*<<< orphan*/  qbman_portal_id; int /*<<< orphan*/  id; } ;
struct dpio_cmd_open {int /*<<< orphan*/  dpio_id; } ;
struct dpio_attr {int channel_mode; void* qbman_version; void* qbman_portal_ci_offset; void* qbman_portal_ce_offset; int /*<<< orphan*/  num_priorities; int /*<<< orphan*/  qbman_portal_id; void* id; } ;

/* Variables and functions */
 int DPIO_CHANNEL_MODE_MASK ; 
 int /*<<< orphan*/  DPIO_CMDID_CLOSE ; 
 int /*<<< orphan*/  DPIO_CMDID_DISABLE ; 
 int /*<<< orphan*/  DPIO_CMDID_ENABLE ; 
 int /*<<< orphan*/  DPIO_CMDID_GET_API_VERSION ; 
 int /*<<< orphan*/  DPIO_CMDID_GET_ATTR ; 
 int /*<<< orphan*/  DPIO_CMDID_OPEN ; 
 int /*<<< orphan*/  cpu_to_le32 (int) ; 
 int /*<<< orphan*/  le16_to_cpu (int /*<<< orphan*/ ) ; 
 void* le32_to_cpu (int /*<<< orphan*/ ) ; 
 void* le64_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mc_cmd_hdr_read_token (struct fsl_mc_command*) ; 
 int /*<<< orphan*/  mc_cmd_read_api_version (struct fsl_mc_command*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 void* mc_encode_cmd_header (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int mc_send_command (struct fsl_mc_io*,struct fsl_mc_command*) ; 

int dpio_open(struct fsl_mc_io *mc_io,
	      u32 cmd_flags,
	      int dpio_id,
	      u16 *token)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpio_cmd_open *dpio_cmd;
	int err;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPIO_CMDID_OPEN,
					  cmd_flags,
					  0);
	dpio_cmd = (struct dpio_cmd_open *)cmd.params;
	dpio_cmd->dpio_id = cpu_to_le32(dpio_id);

	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	/* retrieve response parameters */
	*token = mc_cmd_hdr_read_token(&cmd);

	return 0;
}

int dpio_close(struct fsl_mc_io *mc_io,
	       u32 cmd_flags,
	       u16 token)
{
	struct fsl_mc_command cmd = { 0 };

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPIO_CMDID_CLOSE,
					  cmd_flags,
					  token);

	return mc_send_command(mc_io, &cmd);
}

int dpio_enable(struct fsl_mc_io *mc_io,
		u32 cmd_flags,
		u16 token)
{
	struct fsl_mc_command cmd = { 0 };

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPIO_CMDID_ENABLE,
					  cmd_flags,
					  token);

	return mc_send_command(mc_io, &cmd);
}

int dpio_disable(struct fsl_mc_io *mc_io,
		 u32 cmd_flags,
		 u16 token)
{
	struct fsl_mc_command cmd = { 0 };

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPIO_CMDID_DISABLE,
					  cmd_flags,
					  token);

	return mc_send_command(mc_io, &cmd);
}

int dpio_get_attributes(struct fsl_mc_io *mc_io,
			u32 cmd_flags,
			u16 token,
			struct dpio_attr *attr)
{
	struct fsl_mc_command cmd = { 0 };
	struct dpio_rsp_get_attr *dpio_rsp;
	int err;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPIO_CMDID_GET_ATTR,
					  cmd_flags,
					  token);

	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	/* retrieve response parameters */
	dpio_rsp = (struct dpio_rsp_get_attr *)cmd.params;
	attr->id = le32_to_cpu(dpio_rsp->id);
	attr->qbman_portal_id = le16_to_cpu(dpio_rsp->qbman_portal_id);
	attr->num_priorities = dpio_rsp->num_priorities;
	attr->channel_mode = dpio_rsp->channel_mode & DPIO_CHANNEL_MODE_MASK;
	attr->qbman_portal_ce_offset =
		le64_to_cpu(dpio_rsp->qbman_portal_ce_addr);
	attr->qbman_portal_ci_offset =
		le64_to_cpu(dpio_rsp->qbman_portal_ci_addr);
	attr->qbman_version = le32_to_cpu(dpio_rsp->qbman_version);

	return 0;
}

int dpio_get_api_version(struct fsl_mc_io *mc_io,
			 u32 cmd_flags,
			 u16 *major_ver,
			 u16 *minor_ver)
{
	struct fsl_mc_command cmd = { 0 };
	int err;

	/* prepare command */
	cmd.header = mc_encode_cmd_header(DPIO_CMDID_GET_API_VERSION,
					  cmd_flags, 0);

	err = mc_send_command(mc_io, &cmd);
	if (err)
		return err;

	/* retrieve response parameters */
	mc_cmd_read_api_version(&cmd, major_ver, minor_ver);

	return 0;
}

