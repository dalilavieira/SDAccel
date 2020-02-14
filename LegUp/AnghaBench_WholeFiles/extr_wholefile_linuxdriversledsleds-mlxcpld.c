#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u8 ;
typedef  scalar_t__ u32 ;
typedef  scalar_t__ u16 ;
struct TYPE_7__ {scalar_t__ mask; scalar_t__ offset; scalar_t__ base_color; } ;
struct mlxcpld_led_priv {TYPE_1__ param; } ;
struct mlxcpld_led_pdata {int num_led_instances; TYPE_6__* pled; TYPE_2__* profile; } ;
struct led_classdev {int max_brightness; void (* brightness_set ) (struct led_classdev*,int) ;int (* blink_set ) (struct led_classdev*,unsigned long*,unsigned long*) ;int /*<<< orphan*/  flags; int /*<<< orphan*/  brightness; int /*<<< orphan*/  name; } ;
struct device {int dummy; } ;
typedef  enum mlxcpld_led_platform_types { ____Placeholder_mlxcpld_led_platform_types } mlxcpld_led_platform_types ;
typedef  enum led_brightness { ____Placeholder_led_brightness } led_brightness ;
struct TYPE_9__ {int /*<<< orphan*/  base_color; int /*<<< orphan*/  mask; int /*<<< orphan*/  offset; } ;
struct TYPE_12__ {struct led_classdev cdev; TYPE_3__ param; } ;
struct TYPE_11__ {TYPE_4__* profile; int /*<<< orphan*/  lock; } ;
struct TYPE_10__ {int brightness; int /*<<< orphan*/  base_color; int /*<<< orphan*/  mask; int /*<<< orphan*/  offset; } ;
struct TYPE_8__ {int /*<<< orphan*/  brightness; int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DMI_PRODUCT_NAME ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  LED_CORE_SUSPENDRESUME ; 
 unsigned long MLXCPLD_LED_BLINK_3HZ ; 
 unsigned long MLXCPLD_LED_BLINK_6HZ ; 
 scalar_t__ MLXCPLD_LED_IS_OFF ; 
 scalar_t__ MLXCPLD_LED_OFFSET_FULL ; 
 scalar_t__ MLXCPLD_LED_OFFSET_HALF ; 
 int MLXCPLD_LED_PLATFORM_DEFAULT ; 
 scalar_t__ MLXPLAT_CPLD_LPC_REG_BASE_ADRR ; 
 struct mlxcpld_led_priv* cdev_to_priv (struct led_classdev*) ; 
 TYPE_6__* devm_kcalloc (struct device*,int,int,int /*<<< orphan*/ ) ; 
 int devm_led_classdev_register (struct device*,struct led_classdev*) ; 
 char* dmi_get_system_info (int /*<<< orphan*/ ) ; 
 scalar_t__ inb (scalar_t__) ; 
 int /*<<< orphan*/ * mlx_product_names ; 
 TYPE_5__* mlxcpld_led ; 
 int /*<<< orphan*/  outb (scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ strstr (char const*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static enum
mlxcpld_led_platform_types mlxcpld_led_platform_check_sys_type(void)
{
	const char *mlx_product_name;
	int i;

	mlx_product_name = dmi_get_system_info(DMI_PRODUCT_NAME);
	if (!mlx_product_name)
		return MLXCPLD_LED_PLATFORM_DEFAULT;

	for (i = 1;  i < ARRAY_SIZE(mlx_product_names); i++) {
		if (strstr(mlx_product_name, mlx_product_names[i]))
			return i;
	}

	return MLXCPLD_LED_PLATFORM_DEFAULT;
}

__attribute__((used)) static void mlxcpld_led_bus_access_func(u16 base, u8 offset, u8 rw_flag,
					u8 *data)
{
	u32 addr = base + offset;

	if (rw_flag == 0)
		outb(*data, addr);
	else
		*data = inb(addr);
}

__attribute__((used)) static void mlxcpld_led_store_hw(u8 mask, u8 off, u8 vset)
{
	u8 nib, val;

	/*
	 * Each LED is controlled through low or high nibble of the relevant
	 * CPLD register. Register offset is specified by off parameter.
	 * Parameter vset provides color code: 0x0 for off, 0x5 for solid red,
	 * 0x6 for 3Hz blink red, 0xd for solid green, 0xe for 3Hz blink
	 * green.
	 * Parameter mask specifies which nibble is used for specific LED: mask
	 * 0xf0 - lower nibble is to be used (bits from 0 to 3), mask 0x0f -
	 * higher nibble (bits from 4 to 7).
	 */
	spin_lock(&mlxcpld_led->lock);
	mlxcpld_led_bus_access_func(MLXPLAT_CPLD_LPC_REG_BASE_ADRR, off, 1,
				    &val);
	nib = (mask == 0xf0) ? vset : (vset << 4);
	val = (val & mask) | nib;
	mlxcpld_led_bus_access_func(MLXPLAT_CPLD_LPC_REG_BASE_ADRR, off, 0,
				    &val);
	spin_unlock(&mlxcpld_led->lock);
}

__attribute__((used)) static void mlxcpld_led_brightness_set(struct led_classdev *led,
				       enum led_brightness value)
{
	struct mlxcpld_led_priv *pled = cdev_to_priv(led);

	if (value) {
		mlxcpld_led_store_hw(pled->param.mask, pled->param.offset,
				     pled->param.base_color);
		return;
	}

	mlxcpld_led_store_hw(pled->param.mask, pled->param.offset,
			     MLXCPLD_LED_IS_OFF);
}

__attribute__((used)) static int mlxcpld_led_blink_set(struct led_classdev *led,
				 unsigned long *delay_on,
				 unsigned long *delay_off)
{
	struct mlxcpld_led_priv *pled = cdev_to_priv(led);

	/*
	 * HW supports two types of blinking: full (6Hz) and half (3Hz).
	 * For delay on/off zero default setting 3Hz is used.
	 */
	if (!(*delay_on == 0 && *delay_off == 0) &&
	    !(*delay_on == MLXCPLD_LED_BLINK_3HZ &&
	      *delay_off == MLXCPLD_LED_BLINK_3HZ) &&
	    !(*delay_on == MLXCPLD_LED_BLINK_6HZ &&
	      *delay_off == MLXCPLD_LED_BLINK_6HZ))
		return -EINVAL;

	if (*delay_on == MLXCPLD_LED_BLINK_6HZ)
		mlxcpld_led_store_hw(pled->param.mask, pled->param.offset,
				     pled->param.base_color +
				     MLXCPLD_LED_OFFSET_FULL);
	else
		mlxcpld_led_store_hw(pled->param.mask, pled->param.offset,
				     pled->param.base_color +
				     MLXCPLD_LED_OFFSET_HALF);

	return 0;
}

__attribute__((used)) static int mlxcpld_led_config(struct device *dev,
			      struct mlxcpld_led_pdata *cpld)
{
	int i;
	int err;

	cpld->pled = devm_kcalloc(dev,
				  cpld->num_led_instances,
				  sizeof(struct mlxcpld_led_priv),
				  GFP_KERNEL);
	if (!cpld->pled)
		return -ENOMEM;

	for (i = 0; i < cpld->num_led_instances; i++) {
		cpld->pled[i].cdev.name = cpld->profile[i].name;
		cpld->pled[i].cdev.brightness = cpld->profile[i].brightness;
		cpld->pled[i].cdev.max_brightness = 1;
		cpld->pled[i].cdev.brightness_set = mlxcpld_led_brightness_set;
		cpld->pled[i].cdev.blink_set = mlxcpld_led_blink_set;
		cpld->pled[i].cdev.flags = LED_CORE_SUSPENDRESUME;
		err = devm_led_classdev_register(dev, &cpld->pled[i].cdev);
		if (err)
			return err;

		cpld->pled[i].param.offset = mlxcpld_led->profile[i].offset;
		cpld->pled[i].param.mask = mlxcpld_led->profile[i].mask;
		cpld->pled[i].param.base_color =
					mlxcpld_led->profile[i].base_color;

		if (mlxcpld_led->profile[i].brightness)
			mlxcpld_led_brightness_set(&cpld->pled[i].cdev,
					mlxcpld_led->profile[i].brightness);
	}

	return 0;
}

