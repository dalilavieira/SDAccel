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
typedef  int uint32_t ;
typedef  int uint16_t ;
struct pp_hwmgr {struct amdgpu_device* adev; } ;
struct amdgpu_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MP1 ; 
 int /*<<< orphan*/  MP1_C2PMSG_90__CONTENT_MASK ; 
 int MP1_FIRMWARE_FLAGS__INTERRUPTS_ENABLED_MASK ; 
 int MP1_Public ; 
 int /*<<< orphan*/  NBIF ; 
 int RREG32_SOC15 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int SOC15_REG_OFFSET (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WREG32_SOC15 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mmMP1_SMN_C2PMSG_66 ; 
 int /*<<< orphan*/  mmMP1_SMN_C2PMSG_82 ; 
 int /*<<< orphan*/  mmMP1_SMN_C2PMSG_90 ; 
 int /*<<< orphan*/  mmPCIE_DATA2 ; 
 int /*<<< orphan*/  mmPCIE_INDEX2 ; 
 int phm_wait_for_register_unequal (struct pp_hwmgr*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_err (char*,...) ; 
 int smnMP1_FIRMWARE_FLAGS ; 

bool smu9_is_smc_ram_running(struct pp_hwmgr *hwmgr)
{
	struct amdgpu_device *adev = hwmgr->adev;
	uint32_t mp1_fw_flags;

	WREG32_SOC15(NBIF, 0, mmPCIE_INDEX2,
			(MP1_Public | (smnMP1_FIRMWARE_FLAGS & 0xffffffff)));

	mp1_fw_flags = RREG32_SOC15(NBIF, 0, mmPCIE_DATA2);

	if (mp1_fw_flags & MP1_FIRMWARE_FLAGS__INTERRUPTS_ENABLED_MASK)
		return true;

	return false;
}

__attribute__((used)) static uint32_t smu9_wait_for_response(struct pp_hwmgr *hwmgr)
{
	struct amdgpu_device *adev = hwmgr->adev;
	uint32_t reg;
	uint32_t ret;

	reg = SOC15_REG_OFFSET(MP1, 0, mmMP1_SMN_C2PMSG_90);

	ret = phm_wait_for_register_unequal(hwmgr, reg,
			0, MP1_C2PMSG_90__CONTENT_MASK);

	if (ret)
		pr_err("No response from smu\n");

	return RREG32_SOC15(MP1, 0, mmMP1_SMN_C2PMSG_90);
}

__attribute__((used)) static int smu9_send_msg_to_smc_without_waiting(struct pp_hwmgr *hwmgr,
						uint16_t msg)
{
	struct amdgpu_device *adev = hwmgr->adev;

	WREG32_SOC15(MP1, 0, mmMP1_SMN_C2PMSG_66, msg);

	return 0;
}

int smu9_send_msg_to_smc(struct pp_hwmgr *hwmgr, uint16_t msg)
{
	struct amdgpu_device *adev = hwmgr->adev;
	uint32_t ret;

	smu9_wait_for_response(hwmgr);

	WREG32_SOC15(MP1, 0, mmMP1_SMN_C2PMSG_90, 0);

	smu9_send_msg_to_smc_without_waiting(hwmgr, msg);

	ret = smu9_wait_for_response(hwmgr);
	if (ret != 1)
		pr_err("Failed to send message: 0x%x, ret value: 0x%x\n", msg, ret);

	return 0;
}

int smu9_send_msg_to_smc_with_parameter(struct pp_hwmgr *hwmgr,
					uint16_t msg, uint32_t parameter)
{
	struct amdgpu_device *adev = hwmgr->adev;
	uint32_t ret;

	smu9_wait_for_response(hwmgr);

	WREG32_SOC15(MP1, 0, mmMP1_SMN_C2PMSG_90, 0);

	WREG32_SOC15(MP1, 0, mmMP1_SMN_C2PMSG_82, parameter);

	smu9_send_msg_to_smc_without_waiting(hwmgr, msg);

	ret = smu9_wait_for_response(hwmgr);
	if (ret != 1)
		pr_err("Failed message: 0x%x, input parameter: 0x%x, error code: 0x%x\n", msg, parameter, ret);

	return 0;
}

uint32_t smu9_get_argument(struct pp_hwmgr *hwmgr)
{
	struct amdgpu_device *adev = hwmgr->adev;

	return RREG32_SOC15(MP1, 0, mmMP1_SMN_C2PMSG_82);
}

