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
typedef  unsigned int u32 ;
struct meson_sm_cmd {unsigned int smc_id; unsigned int index; } ;
struct meson_sm_chip {struct meson_sm_cmd* cmd; } ;
struct arm_smccc_res {unsigned int a0; } ;
struct TYPE_4__ {void* sm_shmem_out_base; void* sm_shmem_in_base; TYPE_1__* chip; } ;
struct TYPE_3__ {unsigned int shmem_size; int /*<<< orphan*/  cmd_shmem_in_base; int /*<<< orphan*/  cmd_shmem_out_base; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOENT ; 
 int /*<<< orphan*/  arm_smccc_smc (unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct arm_smccc_res*) ; 
 TYPE_2__ fw ; 
 int /*<<< orphan*/  memcpy (void*,void*,unsigned int) ; 
 scalar_t__ meson_sm_call (unsigned int,unsigned int*,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int) ; 

__attribute__((used)) static u32 meson_sm_get_cmd(const struct meson_sm_chip *chip,
			    unsigned int cmd_index)
{
	const struct meson_sm_cmd *cmd = chip->cmd;

	while (cmd->smc_id && cmd->index != cmd_index)
		cmd++;

	return cmd->smc_id;
}

__attribute__((used)) static u32 __meson_sm_call(u32 cmd, u32 arg0, u32 arg1, u32 arg2,
			   u32 arg3, u32 arg4)
{
	struct arm_smccc_res res;

	arm_smccc_smc(cmd, arg0, arg1, arg2, arg3, arg4, 0, 0, &res);
	return res.a0;
}

int meson_sm_call_read(void *buffer, unsigned int bsize, unsigned int cmd_index,
		       u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4)
{
	u32 size;
	int ret;

	if (!fw.chip)
		return -ENOENT;

	if (!fw.chip->cmd_shmem_out_base)
		return -EINVAL;

	if (bsize > fw.chip->shmem_size)
		return -EINVAL;

	if (meson_sm_call(cmd_index, &size, arg0, arg1, arg2, arg3, arg4) < 0)
		return -EINVAL;

	if (size > bsize)
		return -EINVAL;

	ret = size;

	if (!size)
		size = bsize;

	if (buffer)
		memcpy(buffer, fw.sm_shmem_out_base, size);

	return ret;
}

int meson_sm_call_write(void *buffer, unsigned int size, unsigned int cmd_index,
			u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4)
{
	u32 written;

	if (!fw.chip)
		return -ENOENT;

	if (size > fw.chip->shmem_size)
		return -EINVAL;

	if (!fw.chip->cmd_shmem_in_base)
		return -EINVAL;

	memcpy(fw.sm_shmem_in_base, buffer, size);

	if (meson_sm_call(cmd_index, &written, arg0, arg1, arg2, arg3, arg4) < 0)
		return -EINVAL;

	if (!written)
		return -EINVAL;

	return written;
}

