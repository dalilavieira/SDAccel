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
typedef  scalar_t__ uint32_t ;
struct dc_bios {scalar_t__ bios_size; TYPE_1__* regs; int /*<<< orphan*/ * bios; } ;
struct TYPE_2__ {scalar_t__ BIOS_SCRATCH_3; } ;

/* Variables and functions */
 int /*<<< orphan*/  BIOS_SCRATCH_3 ; 
 int /*<<< orphan*/  BIOS_SCRATCH_6 ; 
 int /*<<< orphan*/  REG_GET (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__*) ; 
 int REG_READ (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  REG_UPDATE (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  S6_ACC_MODE ; 
 int /*<<< orphan*/  S6_CRITICAL_STATE ; 

uint8_t *bios_get_image(struct dc_bios *bp,
	uint32_t offset,
	uint32_t size)
{
	if (bp->bios && offset + size < bp->bios_size)
		return bp->bios + offset;
	else
		return NULL;
}

bool bios_is_accelerated_mode(
	struct dc_bios *bios)
{
	uint32_t acc_mode;
	REG_GET(BIOS_SCRATCH_6, S6_ACC_MODE, &acc_mode);
	return (acc_mode == 1);
}

void bios_set_scratch_acc_mode_change(
	struct dc_bios *bios)
{
	REG_UPDATE(BIOS_SCRATCH_6, S6_ACC_MODE, 1);
}

void bios_set_scratch_critical_state(
	struct dc_bios *bios,
	bool state)
{
	uint32_t critial_state = state ? 1 : 0;
	REG_UPDATE(BIOS_SCRATCH_6, S6_CRITICAL_STATE, critial_state);
}

uint32_t bios_get_vga_enabled_displays(
	struct dc_bios *bios)
{
	uint32_t active_disp = 1;

	if (bios->regs->BIOS_SCRATCH_3) /*follow up with other asic, todo*/
		active_disp = REG_READ(BIOS_SCRATCH_3) & 0XFFFF;
	return active_disp;
}

