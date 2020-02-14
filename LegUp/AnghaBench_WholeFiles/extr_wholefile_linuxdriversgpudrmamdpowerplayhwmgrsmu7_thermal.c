#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int uint64_t ;
typedef  scalar_t__ uint32_t ;
struct TYPE_7__ {int ucTachometerPulsesPerRevolution; scalar_t__ ulMinRPM; scalar_t__ ulMaxRPM; scalar_t__ bNoFan; } ;
struct TYPE_6__ {scalar_t__ ucTargetTemperature; int /*<<< orphan*/  usMaxFanPWM; int /*<<< orphan*/  usMaxFanRPM; } ;
struct TYPE_8__ {TYPE_3__ fanInfo; TYPE_2__ advanceFanControlParameters; } ;
struct pp_hwmgr {int fan_ctrl_is_in_default_mode; scalar_t__ fan_ctrl_default_mode; scalar_t__ tmin; int fan_ctrl_enabled; TYPE_4__ thermal_controller; int /*<<< orphan*/  device; scalar_t__ adev; TYPE_1__* hwmgr_func; } ;
struct phm_fan_speed_info {int supports_percent_read; int supports_percent_write; int max_percent; int supports_rpm_read; int supports_rpm_write; scalar_t__ min_rpm; scalar_t__ max_rpm; scalar_t__ min_percent; } ;
struct amdgpu_device {int dummy; } ;
struct PP_TemperatureRange {int min; int max; } ;
struct TYPE_5__ {int /*<<< orphan*/  (* set_max_fan_pwm_output ) (struct pp_hwmgr*,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* set_max_fan_rpm_output ) (struct pp_hwmgr*,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  CGS_IND_REG__SMC ; 
 int /*<<< orphan*/  CG_FDO_CTRL0 ; 
 int /*<<< orphan*/  CG_FDO_CTRL1 ; 
 int /*<<< orphan*/  CG_FDO_CTRL2 ; 
 int /*<<< orphan*/  CG_MULT_THERMAL_STATUS ; 
 int /*<<< orphan*/  CG_TACH_CTRL ; 
 int /*<<< orphan*/  CG_TACH_STATUS ; 
 int /*<<< orphan*/  CG_THERMAL_CTRL ; 
 int /*<<< orphan*/  CG_THERMAL_INT ; 
 int /*<<< orphan*/  CG_THERMAL_STATUS ; 
 int /*<<< orphan*/  CTF_TEMP ; 
 int /*<<< orphan*/  DIG_THERM_DPM ; 
 int /*<<< orphan*/  DIG_THERM_INTH ; 
 int /*<<< orphan*/  DIG_THERM_INTL ; 
 int /*<<< orphan*/  EDGE_PER_REV ; 
 int EINVAL ; 
 int ENODEV ; 
 int /*<<< orphan*/  FAN_CONTROL_FUZZY ; 
 int /*<<< orphan*/  FAN_CONTROL_TABLE ; 
 int /*<<< orphan*/  FDO_PWM_DUTY ; 
 int /*<<< orphan*/  FDO_PWM_MODE ; 
 scalar_t__ FDO_PWM_MODE_STATIC ; 
 scalar_t__ FDO_PWM_MODE_STATIC_RPM ; 
 int /*<<< orphan*/  FDO_STATIC_DUTY ; 
 int /*<<< orphan*/  FMAX_DUTY100 ; 
 int /*<<< orphan*/  PHM_PlatformCaps_FanSpeedInTableIsRPM ; 
 int /*<<< orphan*/  PHM_PlatformCaps_MicrocodeFanControl ; 
 int /*<<< orphan*/  PHM_PlatformCaps_ODFuzzyFanControlSupport ; 
 void* PHM_READ_VFPF_INDIRECT_FIELD (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PHM_WRITE_VFPF_INDIRECT_FIELD (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  PPSMC_MSG_SetFanTemperatureTarget ; 
 int /*<<< orphan*/  PPSMC_MSG_Thermal_Cntl_Disable ; 
 int /*<<< orphan*/  PPSMC_MSG_Thermal_Cntl_Enable ; 
 int /*<<< orphan*/  PPSMC_StartFanControl ; 
 int /*<<< orphan*/  PPSMC_StopFanControl ; 
 scalar_t__ PP_CAP (int /*<<< orphan*/ ) ; 
 int PP_TEMPERATURE_UNITS_PER_CENTIGRADES ; 
 scalar_t__ SMU7_THERMAL_HIGH_ALERT_MASK ; 
 scalar_t__ SMU7_THERMAL_LOW_ALERT_MASK ; 
 int SMU7_THERMAL_MAXIMUM_ALERT_TEMP ; 
 int SMU7_THERMAL_MAXIMUM_TEMP_READING ; 
 int SMU7_THERMAL_MINIMUM_ALERT_TEMP ; 
 int /*<<< orphan*/  TACH_PERIOD ; 
 int /*<<< orphan*/  TACH_PWM_RESP_RATE ; 
 int /*<<< orphan*/  THERM_INT_MASK ; 
 int /*<<< orphan*/  TMIN ; 
 scalar_t__ amdgpu_asic_get_xclk (struct amdgpu_device*) ; 
 int /*<<< orphan*/  cgs_write_register (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  do_div (int,int) ; 
 int /*<<< orphan*/  mmSMC_MSG_ARG_0 ; 
 int smum_send_msg_to_smc (struct pp_hwmgr*,int /*<<< orphan*/ ) ; 
 int smum_send_msg_to_smc_with_parameter (struct pp_hwmgr*,int /*<<< orphan*/ ,scalar_t__) ; 
 int smum_thermal_avfs_enable (struct pp_hwmgr*) ; 
 int /*<<< orphan*/  smum_thermal_setup_fan_table (struct pp_hwmgr*) ; 
 int /*<<< orphan*/  stub1 (struct pp_hwmgr*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub2 (struct pp_hwmgr*,int /*<<< orphan*/ ) ; 

int smu7_fan_ctrl_get_fan_speed_info(struct pp_hwmgr *hwmgr,
		struct phm_fan_speed_info *fan_speed_info)
{
	if (hwmgr->thermal_controller.fanInfo.bNoFan)
		return -ENODEV;

	fan_speed_info->supports_percent_read = true;
	fan_speed_info->supports_percent_write = true;
	fan_speed_info->min_percent = 0;
	fan_speed_info->max_percent = 100;

	if (PP_CAP(PHM_PlatformCaps_FanSpeedInTableIsRPM) &&
	    hwmgr->thermal_controller.fanInfo.ucTachometerPulsesPerRevolution) {
		fan_speed_info->supports_rpm_read = true;
		fan_speed_info->supports_rpm_write = true;
		fan_speed_info->min_rpm = hwmgr->thermal_controller.fanInfo.ulMinRPM;
		fan_speed_info->max_rpm = hwmgr->thermal_controller.fanInfo.ulMaxRPM;
	} else {
		fan_speed_info->min_rpm = 0;
		fan_speed_info->max_rpm = 0;
	}

	return 0;
}

int smu7_fan_ctrl_get_fan_speed_percent(struct pp_hwmgr *hwmgr,
		uint32_t *speed)
{
	uint32_t duty100;
	uint32_t duty;
	uint64_t tmp64;

	if (hwmgr->thermal_controller.fanInfo.bNoFan)
		return -ENODEV;

	duty100 = PHM_READ_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
			CG_FDO_CTRL1, FMAX_DUTY100);
	duty = PHM_READ_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
			CG_THERMAL_STATUS, FDO_PWM_DUTY);

	if (duty100 == 0)
		return -EINVAL;


	tmp64 = (uint64_t)duty * 100;
	do_div(tmp64, duty100);
	*speed = (uint32_t)tmp64;

	if (*speed > 100)
		*speed = 100;

	return 0;
}

int smu7_fan_ctrl_get_fan_speed_rpm(struct pp_hwmgr *hwmgr, uint32_t *speed)
{
	uint32_t tach_period;
	uint32_t crystal_clock_freq;

	if (hwmgr->thermal_controller.fanInfo.bNoFan ||
	    !hwmgr->thermal_controller.fanInfo.ucTachometerPulsesPerRevolution)
		return -ENODEV;

	tach_period = PHM_READ_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
			CG_TACH_STATUS, TACH_PERIOD);

	if (tach_period == 0)
		return -EINVAL;

	crystal_clock_freq = amdgpu_asic_get_xclk((struct amdgpu_device *)hwmgr->adev);

	*speed = 60 * crystal_clock_freq * 10000 / tach_period;

	return 0;
}

int smu7_fan_ctrl_set_static_mode(struct pp_hwmgr *hwmgr, uint32_t mode)
{
	if (hwmgr->fan_ctrl_is_in_default_mode) {
		hwmgr->fan_ctrl_default_mode =
				PHM_READ_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
						CG_FDO_CTRL2, FDO_PWM_MODE);
		hwmgr->tmin =
				PHM_READ_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
						CG_FDO_CTRL2, TMIN);
		hwmgr->fan_ctrl_is_in_default_mode = false;
	}

	PHM_WRITE_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
			CG_FDO_CTRL2, TMIN, 0);
	PHM_WRITE_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
			CG_FDO_CTRL2, FDO_PWM_MODE, mode);

	return 0;
}

int smu7_fan_ctrl_set_default_mode(struct pp_hwmgr *hwmgr)
{
	if (!hwmgr->fan_ctrl_is_in_default_mode) {
		PHM_WRITE_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
				CG_FDO_CTRL2, FDO_PWM_MODE, hwmgr->fan_ctrl_default_mode);
		PHM_WRITE_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
				CG_FDO_CTRL2, TMIN, hwmgr->tmin);
		hwmgr->fan_ctrl_is_in_default_mode = true;
	}

	return 0;
}

int smu7_fan_ctrl_start_smc_fan_control(struct pp_hwmgr *hwmgr)
{
	int result;

	if (PP_CAP(PHM_PlatformCaps_ODFuzzyFanControlSupport)) {
		cgs_write_register(hwmgr->device, mmSMC_MSG_ARG_0, FAN_CONTROL_FUZZY);
		result = smum_send_msg_to_smc(hwmgr, PPSMC_StartFanControl);

		if (PP_CAP(PHM_PlatformCaps_FanSpeedInTableIsRPM))
			hwmgr->hwmgr_func->set_max_fan_rpm_output(hwmgr,
					hwmgr->thermal_controller.
					advanceFanControlParameters.usMaxFanRPM);
		else
			hwmgr->hwmgr_func->set_max_fan_pwm_output(hwmgr,
					hwmgr->thermal_controller.
					advanceFanControlParameters.usMaxFanPWM);

	} else {
		cgs_write_register(hwmgr->device, mmSMC_MSG_ARG_0, FAN_CONTROL_TABLE);
		result = smum_send_msg_to_smc(hwmgr, PPSMC_StartFanControl);
	}

	if (!result && hwmgr->thermal_controller.
			advanceFanControlParameters.ucTargetTemperature)
		result = smum_send_msg_to_smc_with_parameter(hwmgr,
				PPSMC_MSG_SetFanTemperatureTarget,
				hwmgr->thermal_controller.
				advanceFanControlParameters.ucTargetTemperature);
	hwmgr->fan_ctrl_enabled = true;

	return result;
}

int smu7_fan_ctrl_stop_smc_fan_control(struct pp_hwmgr *hwmgr)
{
	hwmgr->fan_ctrl_enabled = false;
	return smum_send_msg_to_smc(hwmgr, PPSMC_StopFanControl);
}

int smu7_fan_ctrl_set_fan_speed_percent(struct pp_hwmgr *hwmgr,
		uint32_t speed)
{
	uint32_t duty100;
	uint32_t duty;
	uint64_t tmp64;

	if (hwmgr->thermal_controller.fanInfo.bNoFan)
		return 0;

	if (speed > 100)
		speed = 100;

	if (PP_CAP(PHM_PlatformCaps_MicrocodeFanControl))
		smu7_fan_ctrl_stop_smc_fan_control(hwmgr);

	duty100 = PHM_READ_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
			CG_FDO_CTRL1, FMAX_DUTY100);

	if (duty100 == 0)
		return -EINVAL;

	tmp64 = (uint64_t)speed * duty100;
	do_div(tmp64, 100);
	duty = (uint32_t)tmp64;

	PHM_WRITE_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
			CG_FDO_CTRL0, FDO_STATIC_DUTY, duty);

	return smu7_fan_ctrl_set_static_mode(hwmgr, FDO_PWM_MODE_STATIC);
}

int smu7_fan_ctrl_reset_fan_speed_to_default(struct pp_hwmgr *hwmgr)
{
	int result;

	if (hwmgr->thermal_controller.fanInfo.bNoFan)
		return 0;

	if (PP_CAP(PHM_PlatformCaps_MicrocodeFanControl)) {
		result = smu7_fan_ctrl_set_static_mode(hwmgr, FDO_PWM_MODE_STATIC);
		if (!result)
			result = smu7_fan_ctrl_start_smc_fan_control(hwmgr);
	} else
		result = smu7_fan_ctrl_set_default_mode(hwmgr);

	return result;
}

int smu7_fan_ctrl_set_fan_speed_rpm(struct pp_hwmgr *hwmgr, uint32_t speed)
{
	uint32_t tach_period;
	uint32_t crystal_clock_freq;

	if (hwmgr->thermal_controller.fanInfo.bNoFan ||
			(hwmgr->thermal_controller.fanInfo.
			ucTachometerPulsesPerRevolution == 0) ||
			(speed < hwmgr->thermal_controller.fanInfo.ulMinRPM) ||
			(speed > hwmgr->thermal_controller.fanInfo.ulMaxRPM))
		return 0;

	if (PP_CAP(PHM_PlatformCaps_MicrocodeFanControl))
		smu7_fan_ctrl_stop_smc_fan_control(hwmgr);

	crystal_clock_freq = amdgpu_asic_get_xclk((struct amdgpu_device *)hwmgr->adev);

	tach_period = 60 * crystal_clock_freq * 10000 / (8 * speed);

	PHM_WRITE_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
				CG_TACH_STATUS, TACH_PERIOD, tach_period);

	return smu7_fan_ctrl_set_static_mode(hwmgr, FDO_PWM_MODE_STATIC_RPM);
}

int smu7_thermal_get_temperature(struct pp_hwmgr *hwmgr)
{
	int temp;

	temp = PHM_READ_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
			CG_MULT_THERMAL_STATUS, CTF_TEMP);

	/* Bit 9 means the reading is lower than the lowest usable value. */
	if (temp & 0x200)
		temp = SMU7_THERMAL_MAXIMUM_TEMP_READING;
	else
		temp = temp & 0x1ff;

	temp *= PP_TEMPERATURE_UNITS_PER_CENTIGRADES;

	return temp;
}

__attribute__((used)) static int smu7_thermal_set_temperature_range(struct pp_hwmgr *hwmgr,
		int low_temp, int high_temp)
{
	int low = SMU7_THERMAL_MINIMUM_ALERT_TEMP *
			PP_TEMPERATURE_UNITS_PER_CENTIGRADES;
	int high = SMU7_THERMAL_MAXIMUM_ALERT_TEMP *
			PP_TEMPERATURE_UNITS_PER_CENTIGRADES;

	if (low < low_temp)
		low = low_temp;
	if (high > high_temp)
		high = high_temp;

	if (low > high)
		return -EINVAL;

	PHM_WRITE_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
			CG_THERMAL_INT, DIG_THERM_INTH,
			(high / PP_TEMPERATURE_UNITS_PER_CENTIGRADES));
	PHM_WRITE_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
			CG_THERMAL_INT, DIG_THERM_INTL,
			(low / PP_TEMPERATURE_UNITS_PER_CENTIGRADES));
	PHM_WRITE_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
			CG_THERMAL_CTRL, DIG_THERM_DPM,
			(high / PP_TEMPERATURE_UNITS_PER_CENTIGRADES));

	return 0;
}

__attribute__((used)) static int smu7_thermal_initialize(struct pp_hwmgr *hwmgr)
{
	if (hwmgr->thermal_controller.fanInfo.ucTachometerPulsesPerRevolution)
		PHM_WRITE_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
				CG_TACH_CTRL, EDGE_PER_REV,
				hwmgr->thermal_controller.fanInfo.
				ucTachometerPulsesPerRevolution - 1);

	PHM_WRITE_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
			CG_FDO_CTRL2, TACH_PWM_RESP_RATE, 0x28);

	return 0;
}

__attribute__((used)) static void smu7_thermal_enable_alert(struct pp_hwmgr *hwmgr)
{
	uint32_t alert;

	alert = PHM_READ_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
			CG_THERMAL_INT, THERM_INT_MASK);
	alert &= ~(SMU7_THERMAL_HIGH_ALERT_MASK | SMU7_THERMAL_LOW_ALERT_MASK);
	PHM_WRITE_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
			CG_THERMAL_INT, THERM_INT_MASK, alert);

	/* send message to SMU to enable internal thermal interrupts */
	smum_send_msg_to_smc(hwmgr, PPSMC_MSG_Thermal_Cntl_Enable);
}

int smu7_thermal_disable_alert(struct pp_hwmgr *hwmgr)
{
	uint32_t alert;

	alert = PHM_READ_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
			CG_THERMAL_INT, THERM_INT_MASK);
	alert |= (SMU7_THERMAL_HIGH_ALERT_MASK | SMU7_THERMAL_LOW_ALERT_MASK);
	PHM_WRITE_VFPF_INDIRECT_FIELD(hwmgr->device, CGS_IND_REG__SMC,
			CG_THERMAL_INT, THERM_INT_MASK, alert);

	/* send message to SMU to disable internal thermal interrupts */
	return smum_send_msg_to_smc(hwmgr, PPSMC_MSG_Thermal_Cntl_Disable);
}

int smu7_thermal_stop_thermal_controller(struct pp_hwmgr *hwmgr)
{
	int result = smu7_thermal_disable_alert(hwmgr);

	if (!hwmgr->thermal_controller.fanInfo.bNoFan)
		smu7_fan_ctrl_set_default_mode(hwmgr);

	return result;
}

__attribute__((used)) static int smu7_thermal_start_smc_fan_control(struct pp_hwmgr *hwmgr)
{
/* If the fantable setup has failed we could have disabled
 * PHM_PlatformCaps_MicrocodeFanControl even after
 * this function was included in the table.
 * Make sure that we still think controlling the fan is OK.
*/
	if (PP_CAP(PHM_PlatformCaps_MicrocodeFanControl)) {
		smu7_fan_ctrl_start_smc_fan_control(hwmgr);
		smu7_fan_ctrl_set_static_mode(hwmgr, FDO_PWM_MODE_STATIC);
	}

	return 0;
}

int smu7_start_thermal_controller(struct pp_hwmgr *hwmgr,
				struct PP_TemperatureRange *range)
{
	int ret = 0;

	if (range == NULL)
		return -EINVAL;

	smu7_thermal_initialize(hwmgr);
	ret = smu7_thermal_set_temperature_range(hwmgr, range->min, range->max);
	if (ret)
		return -EINVAL;
	smu7_thermal_enable_alert(hwmgr);
	ret = smum_thermal_avfs_enable(hwmgr);
	if (ret)
		return -EINVAL;

/* We should restrict performance levels to low before we halt the SMC.
 * On the other hand we are still in boot state when we do this
 * so it would be pointless.
 * If this assumption changes we have to revisit this table.
 */
	smum_thermal_setup_fan_table(hwmgr);
	smu7_thermal_start_smc_fan_control(hwmgr);
	return 0;
}

int smu7_thermal_ctrl_uninitialize_thermal_controller(struct pp_hwmgr *hwmgr)
{
	if (!hwmgr->thermal_controller.fanInfo.bNoFan)
		smu7_fan_ctrl_set_default_mode(hwmgr);
	return 0;
}

