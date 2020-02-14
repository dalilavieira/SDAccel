#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  size_t uint32_t ;
struct TYPE_7__ {int /*<<< orphan*/ * regs; } ;
struct hw_hpd {TYPE_2__ base; int /*<<< orphan*/ * masks; int /*<<< orphan*/ * shifts; TYPE_3__* regs; } ;
struct hw_gpio_pin {int id; } ;
struct hw_factory {int* number_of_pins; int /*<<< orphan*/ * funcs; } ;
struct TYPE_6__ {int /*<<< orphan*/ * regs; } ;
struct hw_ddc {int /*<<< orphan*/ * masks; int /*<<< orphan*/ * shifts; TYPE_1__ base; TYPE_4__* regs; } ;
struct TYPE_9__ {int /*<<< orphan*/  gpio; } ;
struct TYPE_8__ {int /*<<< orphan*/  gpio; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT_CRITICAL (int) ; 
#define  GPIO_ID_DDC_CLOCK 129 
#define  GPIO_ID_DDC_DATA 128 
 size_t GPIO_ID_GENERIC ; 
 size_t GPIO_ID_GPIO_PAD ; 
 size_t GPIO_ID_GSL ; 
 size_t GPIO_ID_HPD ; 
 size_t GPIO_ID_SYNC ; 
 size_t GPIO_ID_VIP_PAD ; 
 struct hw_ddc* HW_DDC_FROM_BASE (struct hw_gpio_pin*) ; 
 struct hw_hpd* HW_HPD_FROM_BASE (struct hw_gpio_pin*) ; 
 TYPE_4__* ddc_clk_regs ; 
 TYPE_4__* ddc_data_regs ; 
 int /*<<< orphan*/  ddc_mask ; 
 int /*<<< orphan*/  ddc_shift ; 
 int /*<<< orphan*/  funcs ; 
 int /*<<< orphan*/  hpd_mask ; 
 TYPE_3__* hpd_regs ; 
 int /*<<< orphan*/  hpd_shift ; 

__attribute__((used)) static void define_ddc_registers(
		struct hw_gpio_pin *pin,
		uint32_t en)
{
	struct hw_ddc *ddc = HW_DDC_FROM_BASE(pin);

	switch (pin->id) {
	case GPIO_ID_DDC_DATA:
		ddc->regs = &ddc_data_regs[en];
		ddc->base.regs = &ddc_data_regs[en].gpio;
		break;
	case GPIO_ID_DDC_CLOCK:
		ddc->regs = &ddc_clk_regs[en];
		ddc->base.regs = &ddc_clk_regs[en].gpio;
		break;
	default:
		ASSERT_CRITICAL(false);
		return;
	}

	ddc->shifts = &ddc_shift;
	ddc->masks = &ddc_mask;

}

__attribute__((used)) static void define_hpd_registers(struct hw_gpio_pin *pin, uint32_t en)
{
	struct hw_hpd *hpd = HW_HPD_FROM_BASE(pin);

	hpd->regs = &hpd_regs[en];
	hpd->shifts = &hpd_shift;
	hpd->masks = &hpd_mask;
	hpd->base.regs = &hpd_regs[en].gpio;
}

void dal_hw_factory_dcn10_init(struct hw_factory *factory)
{
	/*TODO check ASIC CAPs*/
	factory->number_of_pins[GPIO_ID_DDC_DATA] = 8;
	factory->number_of_pins[GPIO_ID_DDC_CLOCK] = 8;
	factory->number_of_pins[GPIO_ID_GENERIC] = 7;
	factory->number_of_pins[GPIO_ID_HPD] = 6;
	factory->number_of_pins[GPIO_ID_GPIO_PAD] = 31;
	factory->number_of_pins[GPIO_ID_VIP_PAD] = 0;
	factory->number_of_pins[GPIO_ID_SYNC] = 2;
	factory->number_of_pins[GPIO_ID_GSL] = 4;

	factory->funcs = &funcs;
}

