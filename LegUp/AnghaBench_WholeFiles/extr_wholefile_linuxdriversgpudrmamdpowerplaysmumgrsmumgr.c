#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  uint16_t ;
struct pp_hwmgr {TYPE_1__* smumgr_funcs; } ;
struct TYPE_2__ {int (* thermal_avfs_enable ) (struct pp_hwmgr*) ;int (* thermal_setup_fan_table ) (struct pp_hwmgr*) ;int (* update_sclk_threshold ) (struct pp_hwmgr*) ;int (* update_smc_table ) (struct pp_hwmgr*,int /*<<< orphan*/ ) ;int (* process_firmware_header ) (struct pp_hwmgr*) ;int (* download_pptable_settings ) (struct pp_hwmgr*,void**) ;int (* upload_pptable_settings ) (struct pp_hwmgr*) ;int (* send_msg_to_smc ) (struct pp_hwmgr*,int /*<<< orphan*/ ) ;int (* send_msg_to_smc_with_parameter ) (struct pp_hwmgr*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;int (* init_smc_table ) (struct pp_hwmgr*) ;int (* populate_all_graphic_levels ) (struct pp_hwmgr*) ;int (* populate_all_memory_levels ) (struct pp_hwmgr*) ;int (* initialize_mc_reg_table ) (struct pp_hwmgr*) ;int (* is_dpm_running ) (struct pp_hwmgr*) ;int (* is_hw_avfs_present ) (struct pp_hwmgr*) ;int (* update_dpm_settings ) (struct pp_hwmgr*,void*) ;int (* smc_table_manager ) (struct pp_hwmgr*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ;int /*<<< orphan*/  (* get_mac_definition ) (int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* get_argument ) (struct pp_hwmgr*) ;int /*<<< orphan*/  (* get_offsetof ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int EINVAL ; 
 int stub1 (struct pp_hwmgr*) ; 
 int stub10 (struct pp_hwmgr*) ; 
 int stub11 (struct pp_hwmgr*,int /*<<< orphan*/ ) ; 
 int stub12 (struct pp_hwmgr*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int stub13 (struct pp_hwmgr*) ; 
 int stub14 (struct pp_hwmgr*) ; 
 int stub15 (struct pp_hwmgr*) ; 
 int stub16 (struct pp_hwmgr*) ; 
 int stub17 (struct pp_hwmgr*) ; 
 int stub18 (struct pp_hwmgr*) ; 
 int stub19 (struct pp_hwmgr*,void*) ; 
 int stub2 (struct pp_hwmgr*) ; 
 int stub20 (struct pp_hwmgr*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int stub3 (struct pp_hwmgr*) ; 
 int stub4 (struct pp_hwmgr*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub5 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int stub6 (struct pp_hwmgr*) ; 
 int /*<<< orphan*/  stub7 (struct pp_hwmgr*) ; 
 int /*<<< orphan*/  stub8 (int /*<<< orphan*/ ) ; 
 int stub9 (struct pp_hwmgr*,void**) ; 

int smum_thermal_avfs_enable(struct pp_hwmgr *hwmgr)
{
	if (NULL != hwmgr->smumgr_funcs->thermal_avfs_enable)
		return hwmgr->smumgr_funcs->thermal_avfs_enable(hwmgr);

	return 0;
}

int smum_thermal_setup_fan_table(struct pp_hwmgr *hwmgr)
{
	if (NULL != hwmgr->smumgr_funcs->thermal_setup_fan_table)
		return hwmgr->smumgr_funcs->thermal_setup_fan_table(hwmgr);

	return 0;
}

int smum_update_sclk_threshold(struct pp_hwmgr *hwmgr)
{

	if (NULL != hwmgr->smumgr_funcs->update_sclk_threshold)
		return hwmgr->smumgr_funcs->update_sclk_threshold(hwmgr);

	return 0;
}

int smum_update_smc_table(struct pp_hwmgr *hwmgr, uint32_t type)
{

	if (NULL != hwmgr->smumgr_funcs->update_smc_table)
		return hwmgr->smumgr_funcs->update_smc_table(hwmgr, type);

	return 0;
}

uint32_t smum_get_offsetof(struct pp_hwmgr *hwmgr, uint32_t type, uint32_t member)
{
	if (NULL != hwmgr->smumgr_funcs->get_offsetof)
		return hwmgr->smumgr_funcs->get_offsetof(type, member);

	return 0;
}

int smum_process_firmware_header(struct pp_hwmgr *hwmgr)
{
	if (NULL != hwmgr->smumgr_funcs->process_firmware_header)
		return hwmgr->smumgr_funcs->process_firmware_header(hwmgr);
	return 0;
}

uint32_t smum_get_argument(struct pp_hwmgr *hwmgr)
{
	if (NULL != hwmgr->smumgr_funcs->get_argument)
		return hwmgr->smumgr_funcs->get_argument(hwmgr);

	return 0;
}

uint32_t smum_get_mac_definition(struct pp_hwmgr *hwmgr, uint32_t value)
{
	if (NULL != hwmgr->smumgr_funcs->get_mac_definition)
		return hwmgr->smumgr_funcs->get_mac_definition(value);

	return 0;
}

int smum_download_powerplay_table(struct pp_hwmgr *hwmgr, void **table)
{
	if (NULL != hwmgr->smumgr_funcs->download_pptable_settings)
		return hwmgr->smumgr_funcs->download_pptable_settings(hwmgr,
									table);
	return 0;
}

int smum_upload_powerplay_table(struct pp_hwmgr *hwmgr)
{
	if (NULL != hwmgr->smumgr_funcs->upload_pptable_settings)
		return hwmgr->smumgr_funcs->upload_pptable_settings(hwmgr);

	return 0;
}

int smum_send_msg_to_smc(struct pp_hwmgr *hwmgr, uint16_t msg)
{
	if (hwmgr == NULL || hwmgr->smumgr_funcs->send_msg_to_smc == NULL)
		return -EINVAL;

	return hwmgr->smumgr_funcs->send_msg_to_smc(hwmgr, msg);
}

int smum_send_msg_to_smc_with_parameter(struct pp_hwmgr *hwmgr,
					uint16_t msg, uint32_t parameter)
{
	if (hwmgr == NULL ||
		hwmgr->smumgr_funcs->send_msg_to_smc_with_parameter == NULL)
		return -EINVAL;
	return hwmgr->smumgr_funcs->send_msg_to_smc_with_parameter(
						hwmgr, msg, parameter);
}

int smum_init_smc_table(struct pp_hwmgr *hwmgr)
{
	if (NULL != hwmgr->smumgr_funcs->init_smc_table)
		return hwmgr->smumgr_funcs->init_smc_table(hwmgr);

	return 0;
}

int smum_populate_all_graphic_levels(struct pp_hwmgr *hwmgr)
{
	if (NULL != hwmgr->smumgr_funcs->populate_all_graphic_levels)
		return hwmgr->smumgr_funcs->populate_all_graphic_levels(hwmgr);

	return 0;
}

int smum_populate_all_memory_levels(struct pp_hwmgr *hwmgr)
{
	if (NULL != hwmgr->smumgr_funcs->populate_all_memory_levels)
		return hwmgr->smumgr_funcs->populate_all_memory_levels(hwmgr);

	return 0;
}

int smum_initialize_mc_reg_table(struct pp_hwmgr *hwmgr)
{
	if (NULL != hwmgr->smumgr_funcs->initialize_mc_reg_table)
		return hwmgr->smumgr_funcs->initialize_mc_reg_table(hwmgr);

	return 0;
}

bool smum_is_dpm_running(struct pp_hwmgr *hwmgr)
{
	if (NULL != hwmgr->smumgr_funcs->is_dpm_running)
		return hwmgr->smumgr_funcs->is_dpm_running(hwmgr);

	return true;
}

bool smum_is_hw_avfs_present(struct pp_hwmgr *hwmgr)
{
	if (hwmgr->smumgr_funcs->is_hw_avfs_present)
		return hwmgr->smumgr_funcs->is_hw_avfs_present(hwmgr);

	return false;
}

int smum_update_dpm_settings(struct pp_hwmgr *hwmgr, void *profile_setting)
{
	if (hwmgr->smumgr_funcs->update_dpm_settings)
		return hwmgr->smumgr_funcs->update_dpm_settings(hwmgr, profile_setting);

	return -EINVAL;
}

int smum_smc_table_manager(struct pp_hwmgr *hwmgr, uint8_t *table, uint16_t table_id, bool rw)
{
	if (hwmgr->smumgr_funcs->smc_table_manager)
		return hwmgr->smumgr_funcs->smc_table_manager(hwmgr, table, table_id, rw);

	return -EINVAL;
}

