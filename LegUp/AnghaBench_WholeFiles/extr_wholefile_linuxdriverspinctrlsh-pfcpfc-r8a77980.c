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
typedef  int /*<<< orphan*/  u32 ;
struct sh_pfc {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  reg; } ;

/* Variables and functions */
 int EINVAL ; 
 size_t IOCTRL30 ; 
 size_t IOCTRL31 ; 
 size_t IOCTRL32 ; 
 unsigned int RCAR_GP_PIN (int,int) ; 
 TYPE_1__* pinmux_ioctrl_regs ; 

__attribute__((used)) static int r8a77980_pin_to_pocctrl(struct sh_pfc *pfc, unsigned int pin,
				   u32 *pocctrl)
{
	int bit = pin & 0x1f;

	*pocctrl = pinmux_ioctrl_regs[IOCTRL30].reg;
	if (pin >= RCAR_GP_PIN(0, 0) && pin <= RCAR_GP_PIN(0, 21))
		return bit;
	else if (pin >= RCAR_GP_PIN(2, 0) && pin <= RCAR_GP_PIN(2, 9))
		return bit + 22;

	*pocctrl = pinmux_ioctrl_regs[IOCTRL31].reg;
	if (pin >= RCAR_GP_PIN(2, 10) && pin <= RCAR_GP_PIN(2, 16))
		return bit - 10;
	if ((pin >= RCAR_GP_PIN(2, 17) && pin <= RCAR_GP_PIN(2, 24)) ||
	    (pin >= RCAR_GP_PIN(3,  0) && pin <= RCAR_GP_PIN(3, 16)))
		return bit + 7;

	*pocctrl = pinmux_ioctrl_regs[IOCTRL32].reg;
	if (pin >= RCAR_GP_PIN(2, 25) && pin <= RCAR_GP_PIN(2, 29))
		return pin - 25;

	return -EINVAL;
}

