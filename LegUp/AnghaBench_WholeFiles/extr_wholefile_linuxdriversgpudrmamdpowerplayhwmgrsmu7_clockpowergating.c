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
typedef  int uint32_t ;
struct smu7_hwmgr {int uvd_power_gated; int vce_power_gated; } ;
struct TYPE_6__ {int /*<<< orphan*/  platformCaps; } ;
struct pp_hwmgr {int feature_mask; struct amdgpu_device* adev; scalar_t__ backend; TYPE_3__ platform_descriptor; } ;
struct TYPE_4__ {int number; } ;
struct TYPE_5__ {TYPE_1__ cu_info; } ;
struct amdgpu_device {TYPE_2__ gfx; } ;
typedef  int /*<<< orphan*/  PPSMC_Msg ;

/* Variables and functions */
 int /*<<< orphan*/  AMD_CG_STATE_GATE ; 
 int /*<<< orphan*/  AMD_CG_STATE_UNGATE ; 
 int /*<<< orphan*/  AMD_IP_BLOCK_TYPE_UVD ; 
 int /*<<< orphan*/  AMD_IP_BLOCK_TYPE_VCE ; 
 int /*<<< orphan*/  AMD_PG_STATE_GATE ; 
 int /*<<< orphan*/  AMD_PG_STATE_UNGATE ; 
 int CG_CPF_MGCG_MASK ; 
 int CG_GFX_3DCG_MASK ; 
 int CG_GFX_3DLS_MASK ; 
 int CG_GFX_CGCG_MASK ; 
 int CG_GFX_CGLS_MASK ; 
 int CG_GFX_CP_LS_MASK ; 
 int CG_GFX_OTHERS_MGCG_MASK ; 
 int CG_GFX_RLC_LS_MASK ; 
 int CG_RLC_MGCG_MASK ; 
 int CG_SYS_BIF_MGCG_MASK ; 
 int CG_SYS_BIF_MGLS_MASK ; 
 int CG_SYS_DRM_MGCG_MASK ; 
 int CG_SYS_DRM_MGLS_MASK ; 
 int CG_SYS_HDP_MGCG_MASK ; 
 int CG_SYS_HDP_MGLS_MASK ; 
 int CG_SYS_MC_MGCG_MASK ; 
 int CG_SYS_MC_MGLS_MASK ; 
 int CG_SYS_ROM_MASK ; 
 int CG_SYS_SDMA_MGCG_MASK ; 
 int CG_SYS_SDMA_MGLS_MASK ; 
 int EINVAL ; 
 int /*<<< orphan*/  PHM_PlatformCaps_UVDDynamicPowerGating ; 
 int /*<<< orphan*/  PPSMC_MSG_DisableClockGatingFeature ; 
 int /*<<< orphan*/  PPSMC_MSG_EnableClockGatingFeature ; 
 int /*<<< orphan*/  PPSMC_MSG_GFX_CU_PG_DISABLE ; 
 int /*<<< orphan*/  PPSMC_MSG_GFX_CU_PG_ENABLE ; 
 int /*<<< orphan*/  PPSMC_MSG_UVDDPM_Disable ; 
 int /*<<< orphan*/  PPSMC_MSG_UVDDPM_Enable ; 
 int /*<<< orphan*/  PPSMC_MSG_UVDPowerOFF ; 
 int /*<<< orphan*/  PPSMC_MSG_UVDPowerON ; 
 int /*<<< orphan*/  PPSMC_MSG_VCEDPM_Disable ; 
 int /*<<< orphan*/  PPSMC_MSG_VCEDPM_Enable ; 
 int /*<<< orphan*/  PPSMC_MSG_VCEPowerOFF ; 
 int /*<<< orphan*/  PPSMC_MSG_VCEPowerON ; 
#define  PP_BLOCK_GFX_3D 140 
#define  PP_BLOCK_GFX_CG 139 
#define  PP_BLOCK_GFX_CP 138 
#define  PP_BLOCK_GFX_MG 137 
#define  PP_BLOCK_GFX_RLC 136 
 int const PP_BLOCK_MASK ; 
 int const PP_BLOCK_SHIFT ; 
#define  PP_BLOCK_SYS_BIF 135 
#define  PP_BLOCK_SYS_DRM 134 
#define  PP_BLOCK_SYS_HDP 133 
#define  PP_BLOCK_SYS_MC 132 
#define  PP_BLOCK_SYS_ROM 131 
#define  PP_BLOCK_SYS_SDMA 130 
 int PP_ENABLE_GFX_CG_THRU_SMU ; 
#define  PP_GROUP_GFX 129 
 int const PP_GROUP_MASK ; 
 int const PP_GROUP_SHIFT ; 
#define  PP_GROUP_SYS 128 
 int const PP_STATE_CG ; 
 int const PP_STATE_LS ; 
 int const PP_STATE_MASK ; 
 int const PP_STATE_SUPPORT_CG ; 
 int const PP_STATE_SUPPORT_LS ; 
 int /*<<< orphan*/  SMU_UVD_TABLE ; 
 int /*<<< orphan*/  SMU_VCE_TABLE ; 
 int /*<<< orphan*/  amdgpu_device_ip_set_clockgating_state (struct amdgpu_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  amdgpu_device_ip_set_powergating_state (struct amdgpu_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ phm_cap_enabled (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ phm_cf_want_uvd_power_gating (struct pp_hwmgr*) ; 
 scalar_t__ phm_cf_want_vce_power_gating (struct pp_hwmgr*) ; 
 int smum_send_msg_to_smc (struct pp_hwmgr*,int /*<<< orphan*/ ) ; 
 int smum_send_msg_to_smc_with_parameter (struct pp_hwmgr*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  smum_update_smc_table (struct pp_hwmgr*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int smu7_enable_disable_uvd_dpm(struct pp_hwmgr *hwmgr, bool enable)
{
	return smum_send_msg_to_smc(hwmgr, enable ?
			PPSMC_MSG_UVDDPM_Enable :
			PPSMC_MSG_UVDDPM_Disable);
}

__attribute__((used)) static int smu7_enable_disable_vce_dpm(struct pp_hwmgr *hwmgr, bool enable)
{
	return smum_send_msg_to_smc(hwmgr, enable ?
			PPSMC_MSG_VCEDPM_Enable :
			PPSMC_MSG_VCEDPM_Disable);
}

__attribute__((used)) static int smu7_update_uvd_dpm(struct pp_hwmgr *hwmgr, bool bgate)
{
	if (!bgate)
		smum_update_smc_table(hwmgr, SMU_UVD_TABLE);
	return smu7_enable_disable_uvd_dpm(hwmgr, !bgate);
}

__attribute__((used)) static int smu7_update_vce_dpm(struct pp_hwmgr *hwmgr, bool bgate)
{
	if (!bgate)
		smum_update_smc_table(hwmgr, SMU_VCE_TABLE);
	return smu7_enable_disable_vce_dpm(hwmgr, !bgate);
}

int smu7_powerdown_uvd(struct pp_hwmgr *hwmgr)
{
	if (phm_cf_want_uvd_power_gating(hwmgr))
		return smum_send_msg_to_smc(hwmgr,
				PPSMC_MSG_UVDPowerOFF);
	return 0;
}

__attribute__((used)) static int smu7_powerup_uvd(struct pp_hwmgr *hwmgr)
{
	if (phm_cf_want_uvd_power_gating(hwmgr)) {
		if (phm_cap_enabled(hwmgr->platform_descriptor.platformCaps,
				  PHM_PlatformCaps_UVDDynamicPowerGating)) {
			return smum_send_msg_to_smc_with_parameter(hwmgr,
					PPSMC_MSG_UVDPowerON, 1);
		} else {
			return smum_send_msg_to_smc_with_parameter(hwmgr,
					PPSMC_MSG_UVDPowerON, 0);
		}
	}

	return 0;
}

__attribute__((used)) static int smu7_powerdown_vce(struct pp_hwmgr *hwmgr)
{
	if (phm_cf_want_vce_power_gating(hwmgr))
		return smum_send_msg_to_smc(hwmgr,
				PPSMC_MSG_VCEPowerOFF);
	return 0;
}

__attribute__((used)) static int smu7_powerup_vce(struct pp_hwmgr *hwmgr)
{
	if (phm_cf_want_vce_power_gating(hwmgr))
		return smum_send_msg_to_smc(hwmgr,
				PPSMC_MSG_VCEPowerON);
	return 0;
}

int smu7_disable_clock_power_gating(struct pp_hwmgr *hwmgr)
{
	struct smu7_hwmgr *data = (struct smu7_hwmgr *)(hwmgr->backend);

	data->uvd_power_gated = false;
	data->vce_power_gated = false;

	smu7_powerup_uvd(hwmgr);
	smu7_powerup_vce(hwmgr);

	return 0;
}

void smu7_powergate_uvd(struct pp_hwmgr *hwmgr, bool bgate)
{
	struct smu7_hwmgr *data = (struct smu7_hwmgr *)(hwmgr->backend);

	data->uvd_power_gated = bgate;

	if (bgate) {
		amdgpu_device_ip_set_powergating_state(hwmgr->adev,
						AMD_IP_BLOCK_TYPE_UVD,
						AMD_PG_STATE_GATE);
		amdgpu_device_ip_set_clockgating_state(hwmgr->adev,
				AMD_IP_BLOCK_TYPE_UVD,
				AMD_CG_STATE_GATE);
		smu7_update_uvd_dpm(hwmgr, true);
		smu7_powerdown_uvd(hwmgr);
	} else {
		smu7_powerup_uvd(hwmgr);
		amdgpu_device_ip_set_clockgating_state(hwmgr->adev,
				AMD_IP_BLOCK_TYPE_UVD,
				AMD_CG_STATE_UNGATE);
		amdgpu_device_ip_set_powergating_state(hwmgr->adev,
						AMD_IP_BLOCK_TYPE_UVD,
						AMD_PG_STATE_UNGATE);
		smu7_update_uvd_dpm(hwmgr, false);
	}

}

void smu7_powergate_vce(struct pp_hwmgr *hwmgr, bool bgate)
{
	struct smu7_hwmgr *data = (struct smu7_hwmgr *)(hwmgr->backend);

	data->vce_power_gated = bgate;

	if (bgate) {
		amdgpu_device_ip_set_powergating_state(hwmgr->adev,
						AMD_IP_BLOCK_TYPE_VCE,
						AMD_PG_STATE_GATE);
		amdgpu_device_ip_set_clockgating_state(hwmgr->adev,
				AMD_IP_BLOCK_TYPE_VCE,
				AMD_CG_STATE_GATE);
		smu7_update_vce_dpm(hwmgr, true);
		smu7_powerdown_vce(hwmgr);
	} else {
		smu7_powerup_vce(hwmgr);
		amdgpu_device_ip_set_clockgating_state(hwmgr->adev,
				AMD_IP_BLOCK_TYPE_VCE,
				AMD_CG_STATE_UNGATE);
		amdgpu_device_ip_set_powergating_state(hwmgr->adev,
						AMD_IP_BLOCK_TYPE_VCE,
						AMD_PG_STATE_UNGATE);
		smu7_update_vce_dpm(hwmgr, false);
	}
}

int smu7_update_clock_gatings(struct pp_hwmgr *hwmgr,
					const uint32_t *msg_id)
{
	PPSMC_Msg msg;
	uint32_t value;

	if (!(hwmgr->feature_mask & PP_ENABLE_GFX_CG_THRU_SMU))
		return 0;

	switch ((*msg_id & PP_GROUP_MASK) >> PP_GROUP_SHIFT) {
	case PP_GROUP_GFX:
		switch ((*msg_id & PP_BLOCK_MASK) >> PP_BLOCK_SHIFT) {
		case PP_BLOCK_GFX_CG:
			if (PP_STATE_SUPPORT_CG & *msg_id) {
				msg = ((*msg_id & PP_STATE_MASK) & PP_STATE_CG) ?
						PPSMC_MSG_EnableClockGatingFeature :
						PPSMC_MSG_DisableClockGatingFeature;
				value = CG_GFX_CGCG_MASK;

				if (smum_send_msg_to_smc_with_parameter(
						hwmgr, msg, value))
					return -EINVAL;
			}
			if (PP_STATE_SUPPORT_LS & *msg_id) {
				msg = (*msg_id & PP_STATE_MASK) & PP_STATE_LS
					? PPSMC_MSG_EnableClockGatingFeature
					: PPSMC_MSG_DisableClockGatingFeature;
				value = CG_GFX_CGLS_MASK;

				if (smum_send_msg_to_smc_with_parameter(
						hwmgr, msg, value))
					return -EINVAL;
			}
			break;

		case PP_BLOCK_GFX_3D:
			if (PP_STATE_SUPPORT_CG & *msg_id) {
				msg = ((*msg_id & PP_STATE_MASK) & PP_STATE_CG) ?
						PPSMC_MSG_EnableClockGatingFeature :
						PPSMC_MSG_DisableClockGatingFeature;
				value = CG_GFX_3DCG_MASK;

				if (smum_send_msg_to_smc_with_parameter(
						hwmgr, msg, value))
					return -EINVAL;
			}

			if  (PP_STATE_SUPPORT_LS & *msg_id) {
				msg = (*msg_id & PP_STATE_MASK) & PP_STATE_LS ?
						PPSMC_MSG_EnableClockGatingFeature :
						PPSMC_MSG_DisableClockGatingFeature;
				value = CG_GFX_3DLS_MASK;

				if (smum_send_msg_to_smc_with_parameter(
						hwmgr, msg, value))
					return -EINVAL;
			}
			break;

		case PP_BLOCK_GFX_RLC:
			if (PP_STATE_SUPPORT_LS & *msg_id) {
				msg = (*msg_id & PP_STATE_MASK) & PP_STATE_LS ?
						PPSMC_MSG_EnableClockGatingFeature :
						PPSMC_MSG_DisableClockGatingFeature;
				value = CG_GFX_RLC_LS_MASK;

				if (smum_send_msg_to_smc_with_parameter(
						hwmgr, msg, value))
					return -EINVAL;
			}
			break;

		case PP_BLOCK_GFX_CP:
			if (PP_STATE_SUPPORT_LS & *msg_id) {
				msg = (*msg_id & PP_STATE_MASK) & PP_STATE_LS ?
						PPSMC_MSG_EnableClockGatingFeature :
						PPSMC_MSG_DisableClockGatingFeature;
				value = CG_GFX_CP_LS_MASK;

				if (smum_send_msg_to_smc_with_parameter(
						hwmgr, msg, value))
					return -EINVAL;
			}
			break;

		case PP_BLOCK_GFX_MG:
			if (PP_STATE_SUPPORT_CG & *msg_id) {
				msg = ((*msg_id & PP_STATE_MASK) & PP_STATE_CG)	?
						PPSMC_MSG_EnableClockGatingFeature :
						PPSMC_MSG_DisableClockGatingFeature;
				value = (CG_CPF_MGCG_MASK | CG_RLC_MGCG_MASK |
						CG_GFX_OTHERS_MGCG_MASK);

				if (smum_send_msg_to_smc_with_parameter(
						hwmgr, msg, value))
					return -EINVAL;
			}
			break;

		default:
			return -EINVAL;
		}
		break;

	case PP_GROUP_SYS:
		switch ((*msg_id & PP_BLOCK_MASK) >> PP_BLOCK_SHIFT) {
		case PP_BLOCK_SYS_BIF:
			if (PP_STATE_SUPPORT_CG & *msg_id) {
				msg = (*msg_id & PP_STATE_MASK) & PP_STATE_CG ?
						PPSMC_MSG_EnableClockGatingFeature :
						PPSMC_MSG_DisableClockGatingFeature;
				value = CG_SYS_BIF_MGCG_MASK;

				if (smum_send_msg_to_smc_with_parameter(
						hwmgr, msg, value))
					return -EINVAL;
			}
			if  (PP_STATE_SUPPORT_LS & *msg_id) {
				msg = (*msg_id & PP_STATE_MASK) & PP_STATE_LS ?
						PPSMC_MSG_EnableClockGatingFeature :
						PPSMC_MSG_DisableClockGatingFeature;
				value = CG_SYS_BIF_MGLS_MASK;

				if (smum_send_msg_to_smc_with_parameter(
						hwmgr, msg, value))
					return -EINVAL;
			}
			break;

		case PP_BLOCK_SYS_MC:
			if (PP_STATE_SUPPORT_CG & *msg_id) {
				msg = ((*msg_id & PP_STATE_MASK) & PP_STATE_CG)	?
						PPSMC_MSG_EnableClockGatingFeature :
						PPSMC_MSG_DisableClockGatingFeature;
				value = CG_SYS_MC_MGCG_MASK;

				if (smum_send_msg_to_smc_with_parameter(
						hwmgr, msg, value))
					return -EINVAL;
			}

			if (PP_STATE_SUPPORT_LS & *msg_id) {
				msg = (*msg_id & PP_STATE_MASK) & PP_STATE_LS ?
						PPSMC_MSG_EnableClockGatingFeature :
						PPSMC_MSG_DisableClockGatingFeature;
				value = CG_SYS_MC_MGLS_MASK;

				if (smum_send_msg_to_smc_with_parameter(
						hwmgr, msg, value))
					return -EINVAL;
			}
			break;

		case PP_BLOCK_SYS_DRM:
			if (PP_STATE_SUPPORT_CG & *msg_id) {
				msg = (*msg_id & PP_STATE_MASK) & PP_STATE_CG ?
						PPSMC_MSG_EnableClockGatingFeature :
						PPSMC_MSG_DisableClockGatingFeature;
				value = CG_SYS_DRM_MGCG_MASK;

				if (smum_send_msg_to_smc_with_parameter(
						hwmgr, msg, value))
					return -EINVAL;
			}
			if (PP_STATE_SUPPORT_LS & *msg_id) {
				msg = (*msg_id & PP_STATE_MASK) & PP_STATE_LS ?
						PPSMC_MSG_EnableClockGatingFeature :
						PPSMC_MSG_DisableClockGatingFeature;
				value = CG_SYS_DRM_MGLS_MASK;

				if (smum_send_msg_to_smc_with_parameter(
						hwmgr, msg, value))
					return -EINVAL;
			}
			break;

		case PP_BLOCK_SYS_HDP:
			if (PP_STATE_SUPPORT_CG & *msg_id) {
				msg = ((*msg_id & PP_STATE_MASK) & PP_STATE_CG) ?
						PPSMC_MSG_EnableClockGatingFeature :
						PPSMC_MSG_DisableClockGatingFeature;
				value = CG_SYS_HDP_MGCG_MASK;

				if (smum_send_msg_to_smc_with_parameter(
						hwmgr, msg, value))
					return -EINVAL;
			}

			if (PP_STATE_SUPPORT_LS & *msg_id) {
				msg = (*msg_id & PP_STATE_MASK) & PP_STATE_LS ?
						PPSMC_MSG_EnableClockGatingFeature :
						PPSMC_MSG_DisableClockGatingFeature;
				value = CG_SYS_HDP_MGLS_MASK;

				if (smum_send_msg_to_smc_with_parameter(
						hwmgr, msg, value))
					return -EINVAL;
			}
			break;

		case PP_BLOCK_SYS_SDMA:
			if (PP_STATE_SUPPORT_CG & *msg_id) {
				msg = ((*msg_id & PP_STATE_MASK) & PP_STATE_CG)	?
						PPSMC_MSG_EnableClockGatingFeature :
						PPSMC_MSG_DisableClockGatingFeature;
				value = CG_SYS_SDMA_MGCG_MASK;

				if (smum_send_msg_to_smc_with_parameter(
						hwmgr, msg, value))
					return -EINVAL;
			}

			if (PP_STATE_SUPPORT_LS & *msg_id) {
				msg = (*msg_id & PP_STATE_MASK) & PP_STATE_LS ?
						PPSMC_MSG_EnableClockGatingFeature :
						PPSMC_MSG_DisableClockGatingFeature;
				value = CG_SYS_SDMA_MGLS_MASK;

				if (smum_send_msg_to_smc_with_parameter(
						hwmgr, msg, value))
					return -EINVAL;
			}
			break;

		case PP_BLOCK_SYS_ROM:
			if (PP_STATE_SUPPORT_CG & *msg_id) {
				msg = ((*msg_id & PP_STATE_MASK) & PP_STATE_CG) ?
						PPSMC_MSG_EnableClockGatingFeature :
						PPSMC_MSG_DisableClockGatingFeature;
				value = CG_SYS_ROM_MASK;

				if (smum_send_msg_to_smc_with_parameter(
						hwmgr, msg, value))
					return -EINVAL;
			}
			break;

		default:
			return -EINVAL;

		}
		break;

	default:
		return -EINVAL;

	}

	return 0;
}

int smu7_powergate_gfx(struct pp_hwmgr *hwmgr, bool enable)
{
	struct amdgpu_device *adev = hwmgr->adev;

	if (enable)
		return smum_send_msg_to_smc_with_parameter(hwmgr,
					PPSMC_MSG_GFX_CU_PG_ENABLE,
					adev->gfx.cu_info.number);
	else
		return smum_send_msg_to_smc(hwmgr,
				PPSMC_MSG_GFX_CU_PG_DISABLE);
}

