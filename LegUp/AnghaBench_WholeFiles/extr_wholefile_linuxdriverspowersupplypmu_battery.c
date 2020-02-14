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
union power_supply_propval {int intval; char* strval; } ;
struct power_supply {int dummy; } ;
struct pmu_battery_info {int flags; int charge; int max_charge; int amperage; int voltage; int time_remaining; } ;
struct pmu_battery_dev {struct pmu_battery_info* pbi; } ;
typedef  enum power_supply_property { ____Placeholder_power_supply_property } power_supply_property ;

/* Variables and functions */
 int EINVAL ; 
 int PMU_BATT_CHARGING ; 
 int PMU_BATT_PRESENT ; 
#define  PMU_BATT_TYPE_COMET 139 
#define  PMU_BATT_TYPE_HOOPER 138 
 int PMU_BATT_TYPE_MASK ; 
#define  PMU_BATT_TYPE_SMART 137 
 int PMU_PWR_AC_PRESENT ; 
#define  POWER_SUPPLY_PROP_CURRENT_AVG 136 
#define  POWER_SUPPLY_PROP_ENERGY_AVG 135 
#define  POWER_SUPPLY_PROP_ENERGY_FULL 134 
#define  POWER_SUPPLY_PROP_MODEL_NAME 133 
#define  POWER_SUPPLY_PROP_ONLINE 132 
#define  POWER_SUPPLY_PROP_PRESENT 131 
#define  POWER_SUPPLY_PROP_STATUS 130 
#define  POWER_SUPPLY_PROP_TIME_TO_EMPTY_AVG 129 
#define  POWER_SUPPLY_PROP_VOLTAGE_AVG 128 
 int POWER_SUPPLY_STATUS_CHARGING ; 
 int POWER_SUPPLY_STATUS_DISCHARGING ; 
 int POWER_SUPPLY_STATUS_FULL ; 
 char** pmu_batt_types ; 
 int /*<<< orphan*/  pmu_battery_count ; 
 int pmu_power_flags ; 
 struct pmu_battery_dev* to_pmu_battery_dev (struct power_supply*) ; 

__attribute__((used)) static int pmu_get_ac_prop(struct power_supply *psy,
			   enum power_supply_property psp,
			   union power_supply_propval *val)
{
	switch (psp) {
	case POWER_SUPPLY_PROP_ONLINE:
		val->intval = (!!(pmu_power_flags & PMU_PWR_AC_PRESENT)) ||
			      (pmu_battery_count == 0);
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static char *pmu_bat_get_model_name(struct pmu_battery_info *pbi)
{
	switch (pbi->flags & PMU_BATT_TYPE_MASK) {
	case PMU_BATT_TYPE_SMART:
		return pmu_batt_types[0];
	case PMU_BATT_TYPE_COMET:
		return pmu_batt_types[1];
	case PMU_BATT_TYPE_HOOPER:
		return pmu_batt_types[2];
	default: break;
	}
	return pmu_batt_types[3];
}

__attribute__((used)) static int pmu_bat_get_property(struct power_supply *psy,
				enum power_supply_property psp,
				union power_supply_propval *val)
{
	struct pmu_battery_dev *pbat = to_pmu_battery_dev(psy);
	struct pmu_battery_info *pbi = pbat->pbi;

	switch (psp) {
	case POWER_SUPPLY_PROP_STATUS:
		if (pbi->flags & PMU_BATT_CHARGING)
			val->intval = POWER_SUPPLY_STATUS_CHARGING;
		else if (pmu_power_flags & PMU_PWR_AC_PRESENT)
			val->intval = POWER_SUPPLY_STATUS_FULL;
		else
			val->intval = POWER_SUPPLY_STATUS_DISCHARGING;
		break;
	case POWER_SUPPLY_PROP_PRESENT:
		val->intval = !!(pbi->flags & PMU_BATT_PRESENT);
		break;
	case POWER_SUPPLY_PROP_MODEL_NAME:
		val->strval = pmu_bat_get_model_name(pbi);
		break;
	case POWER_SUPPLY_PROP_ENERGY_AVG:
		val->intval = pbi->charge     * 1000; /* mWh -> µWh */
		break;
	case POWER_SUPPLY_PROP_ENERGY_FULL:
		val->intval = pbi->max_charge * 1000; /* mWh -> µWh */
		break;
	case POWER_SUPPLY_PROP_CURRENT_AVG:
		val->intval = pbi->amperage   * 1000; /* mA -> µA */
		break;
	case POWER_SUPPLY_PROP_VOLTAGE_AVG:
		val->intval = pbi->voltage    * 1000; /* mV -> µV */
		break;
	case POWER_SUPPLY_PROP_TIME_TO_EMPTY_AVG:
		val->intval = pbi->time_remaining;
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

