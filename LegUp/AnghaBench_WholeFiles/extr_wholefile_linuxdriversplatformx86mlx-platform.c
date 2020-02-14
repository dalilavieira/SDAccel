#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct mlxplat_mlxcpld_regmap_context {scalar_t__ base; } ;
struct i2c_adapter {int dummy; } ;
struct device {int dummy; } ;
struct TYPE_5__ {int shift_nr; } ;
struct TYPE_4__ {int parent; int base_nr; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 int ENODEV ; 
#define  MLXPLAT_CPLD_LPC_REG_AGGRLO_MASK_OFFSET 169 
#define  MLXPLAT_CPLD_LPC_REG_AGGRLO_OFFSET 168 
#define  MLXPLAT_CPLD_LPC_REG_AGGR_MASK_OFFSET 167 
#define  MLXPLAT_CPLD_LPC_REG_AGGR_OFFSET 166 
#define  MLXPLAT_CPLD_LPC_REG_ASIC_EVENT_OFFSET 165 
#define  MLXPLAT_CPLD_LPC_REG_ASIC_HEALTH_OFFSET 164 
#define  MLXPLAT_CPLD_LPC_REG_ASIC_MASK_OFFSET 163 
#define  MLXPLAT_CPLD_LPC_REG_CPLD1_VER_OFFSET 162 
#define  MLXPLAT_CPLD_LPC_REG_CPLD2_VER_OFFSET 161 
#define  MLXPLAT_CPLD_LPC_REG_FAN_EVENT_OFFSET 160 
#define  MLXPLAT_CPLD_LPC_REG_FAN_MASK_OFFSET 159 
#define  MLXPLAT_CPLD_LPC_REG_FAN_OFFSET 158 
#define  MLXPLAT_CPLD_LPC_REG_GP1_OFFSET 157 
#define  MLXPLAT_CPLD_LPC_REG_GP2_OFFSET 156 
#define  MLXPLAT_CPLD_LPC_REG_LED1_OFFSET 155 
#define  MLXPLAT_CPLD_LPC_REG_LED2_OFFSET 154 
#define  MLXPLAT_CPLD_LPC_REG_LED3_OFFSET 153 
#define  MLXPLAT_CPLD_LPC_REG_LED4_OFFSET 152 
#define  MLXPLAT_CPLD_LPC_REG_LED5_OFFSET 151 
#define  MLXPLAT_CPLD_LPC_REG_PSU_EVENT_OFFSET 150 
#define  MLXPLAT_CPLD_LPC_REG_PSU_MASK_OFFSET 149 
#define  MLXPLAT_CPLD_LPC_REG_PSU_OFFSET 148 
#define  MLXPLAT_CPLD_LPC_REG_PWM1_OFFSET 147 
#define  MLXPLAT_CPLD_LPC_REG_PWM_CONTROL_OFFSET 146 
#define  MLXPLAT_CPLD_LPC_REG_PWR_EVENT_OFFSET 145 
#define  MLXPLAT_CPLD_LPC_REG_PWR_MASK_OFFSET 144 
#define  MLXPLAT_CPLD_LPC_REG_PWR_OFFSET 143 
#define  MLXPLAT_CPLD_LPC_REG_RESET_CAUSE_OFFSET 142 
#define  MLXPLAT_CPLD_LPC_REG_TACHO10_OFFSET 141 
#define  MLXPLAT_CPLD_LPC_REG_TACHO11_OFFSET 140 
#define  MLXPLAT_CPLD_LPC_REG_TACHO12_OFFSET 139 
#define  MLXPLAT_CPLD_LPC_REG_TACHO1_OFFSET 138 
#define  MLXPLAT_CPLD_LPC_REG_TACHO2_OFFSET 137 
#define  MLXPLAT_CPLD_LPC_REG_TACHO3_OFFSET 136 
#define  MLXPLAT_CPLD_LPC_REG_TACHO4_OFFSET 135 
#define  MLXPLAT_CPLD_LPC_REG_TACHO5_OFFSET 134 
#define  MLXPLAT_CPLD_LPC_REG_TACHO6_OFFSET 133 
#define  MLXPLAT_CPLD_LPC_REG_TACHO7_OFFSET 132 
#define  MLXPLAT_CPLD_LPC_REG_TACHO8_OFFSET 131 
#define  MLXPLAT_CPLD_LPC_REG_TACHO9_OFFSET 130 
#define  MLXPLAT_CPLD_LPC_REG_WP1_OFFSET 129 
#define  MLXPLAT_CPLD_LPC_REG_WP2_OFFSET 128 
 int MLXPLAT_CPLD_MAX_PHYS_ADAPTER_NUM ; 
 int MLXPLAT_CPLD_PHYS_ADAPTER_DEF_NR ; 
 struct i2c_adapter* i2c_get_adapter (int) ; 
 int /*<<< orphan*/  i2c_put_adapter (struct i2c_adapter*) ; 
 unsigned int ioread8 (scalar_t__) ; 
 int /*<<< orphan*/  iowrite8 (unsigned int,scalar_t__) ; 
 TYPE_2__* mlxplat_hotplug ; 
 TYPE_1__* mlxplat_mux_data ; 

__attribute__((used)) static bool mlxplat_mlxcpld_writeable_reg(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case MLXPLAT_CPLD_LPC_REG_LED1_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_LED2_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_LED3_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_LED4_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_LED5_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_GP1_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_WP1_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_GP2_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_WP2_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_AGGR_MASK_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_AGGRLO_MASK_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_ASIC_EVENT_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_ASIC_MASK_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_PSU_EVENT_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_PSU_MASK_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_PWR_EVENT_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_PWR_MASK_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_FAN_EVENT_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_FAN_MASK_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_PWM1_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_PWM_CONTROL_OFFSET:
		return true;
	}
	return false;
}

__attribute__((used)) static bool mlxplat_mlxcpld_readable_reg(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case MLXPLAT_CPLD_LPC_REG_CPLD1_VER_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_CPLD2_VER_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_RESET_CAUSE_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_LED1_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_LED2_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_LED3_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_LED4_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_LED5_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_GP1_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_WP1_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_GP2_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_WP2_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_AGGR_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_AGGR_MASK_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_AGGRLO_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_AGGRLO_MASK_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_ASIC_HEALTH_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_ASIC_EVENT_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_ASIC_MASK_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_PSU_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_PSU_EVENT_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_PSU_MASK_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_PWR_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_PWR_EVENT_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_PWR_MASK_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_FAN_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_FAN_EVENT_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_FAN_MASK_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_PWM1_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_TACHO1_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_TACHO2_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_TACHO3_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_TACHO4_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_TACHO5_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_TACHO6_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_TACHO7_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_TACHO8_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_TACHO9_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_TACHO10_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_TACHO11_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_TACHO12_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_PWM_CONTROL_OFFSET:
		return true;
	}
	return false;
}

__attribute__((used)) static bool mlxplat_mlxcpld_volatile_reg(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case MLXPLAT_CPLD_LPC_REG_CPLD1_VER_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_CPLD2_VER_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_RESET_CAUSE_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_LED1_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_LED2_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_LED3_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_LED4_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_LED5_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_GP1_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_GP2_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_AGGR_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_AGGR_MASK_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_AGGRLO_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_AGGRLO_MASK_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_ASIC_HEALTH_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_ASIC_EVENT_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_ASIC_MASK_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_PSU_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_PSU_EVENT_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_PSU_MASK_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_PWR_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_PWR_EVENT_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_PWR_MASK_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_FAN_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_FAN_EVENT_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_FAN_MASK_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_PWM1_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_TACHO1_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_TACHO2_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_TACHO3_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_TACHO4_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_TACHO5_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_TACHO6_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_TACHO7_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_TACHO8_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_TACHO9_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_TACHO10_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_TACHO11_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_TACHO12_OFFSET:
	case MLXPLAT_CPLD_LPC_REG_PWM_CONTROL_OFFSET:
		return true;
	}
	return false;
}

__attribute__((used)) static int
mlxplat_mlxcpld_reg_read(void *context, unsigned int reg, unsigned int *val)
{
	struct mlxplat_mlxcpld_regmap_context *ctx = context;

	*val = ioread8(ctx->base + reg);
	return 0;
}

__attribute__((used)) static int
mlxplat_mlxcpld_reg_write(void *context, unsigned int reg, unsigned int val)
{
	struct mlxplat_mlxcpld_regmap_context *ctx = context;

	iowrite8(val, ctx->base + reg);
	return 0;
}

__attribute__((used)) static int mlxplat_mlxcpld_verify_bus_topology(int *nr)
{
	struct i2c_adapter *search_adap;
	int shift, i;

	/* Scan adapters from expected id to verify it is free. */
	*nr = MLXPLAT_CPLD_PHYS_ADAPTER_DEF_NR;
	for (i = MLXPLAT_CPLD_PHYS_ADAPTER_DEF_NR; i <
	     MLXPLAT_CPLD_MAX_PHYS_ADAPTER_NUM; i++) {
		search_adap = i2c_get_adapter(i);
		if (search_adap) {
			i2c_put_adapter(search_adap);
			continue;
		}

		/* Return if expected parent adapter is free. */
		if (i == MLXPLAT_CPLD_PHYS_ADAPTER_DEF_NR)
			return 0;
		break;
	}

	/* Return with error if free id for adapter is not found. */
	if (i == MLXPLAT_CPLD_MAX_PHYS_ADAPTER_NUM)
		return -ENODEV;

	/* Shift adapter ids, since expected parent adapter is not free. */
	*nr = i;
	for (i = 0; i < ARRAY_SIZE(mlxplat_mux_data); i++) {
		shift = *nr - mlxplat_mux_data[i].parent;
		mlxplat_mux_data[i].parent = *nr;
		mlxplat_mux_data[i].base_nr += shift;
		if (shift > 0)
			mlxplat_hotplug->shift_nr = shift;
	}

	return 0;
}

