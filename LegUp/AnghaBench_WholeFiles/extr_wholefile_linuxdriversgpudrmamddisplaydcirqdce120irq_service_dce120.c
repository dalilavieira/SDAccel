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
typedef  scalar_t__ uint32_t ;
struct irq_source_info {scalar_t__ enable_reg; scalar_t__ status_reg; } ;
struct irq_service_init_data {int dummy; } ;
struct irq_service {int /*<<< orphan*/ * funcs; int /*<<< orphan*/  info; int /*<<< orphan*/  ctx; } ;

/* Variables and functions */
 int /*<<< orphan*/  DC_HPD_INT_POLARITY ; 
 int /*<<< orphan*/  DC_HPD_SENSE_DELAYED ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  HPD0_DC_HPD_INT_CONTROL ; 
 int /*<<< orphan*/  HPD0_DC_HPD_INT_STATUS ; 
 int /*<<< orphan*/  dal_irq_service_ack_generic (struct irq_service*,struct irq_source_info const*) ; 
 int /*<<< orphan*/  dal_irq_service_construct (struct irq_service*,struct irq_service_init_data*) ; 
 scalar_t__ dm_read_reg (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  dm_write_reg (int /*<<< orphan*/ ,scalar_t__,scalar_t__) ; 
 scalar_t__ get_reg_field_value (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_service_funcs_dce120 ; 
 int /*<<< orphan*/  irq_source_info_dce120 ; 
 struct irq_service* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_reg_field_value (scalar_t__,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool hpd_ack(
	struct irq_service *irq_service,
	const struct irq_source_info *info)
{
	uint32_t addr = info->status_reg;
	uint32_t value = dm_read_reg(irq_service->ctx, addr);
	uint32_t current_status =
		get_reg_field_value(
			value,
			HPD0_DC_HPD_INT_STATUS,
			DC_HPD_SENSE_DELAYED);

	dal_irq_service_ack_generic(irq_service, info);

	value = dm_read_reg(irq_service->ctx, info->enable_reg);

	set_reg_field_value(
		value,
		current_status ? 0 : 1,
		HPD0_DC_HPD_INT_CONTROL,
		DC_HPD_INT_POLARITY);

	dm_write_reg(irq_service->ctx, info->enable_reg, value);

	return true;
}

__attribute__((used)) static void construct(
	struct irq_service *irq_service,
	struct irq_service_init_data *init_data)
{
	dal_irq_service_construct(irq_service, init_data);

	irq_service->info = irq_source_info_dce120;
	irq_service->funcs = &irq_service_funcs_dce120;
}

struct irq_service *dal_irq_service_dce120_create(
	struct irq_service_init_data *init_data)
{
	struct irq_service *irq_service = kzalloc(sizeof(*irq_service),
						  GFP_KERNEL);

	if (!irq_service)
		return NULL;

	construct(irq_service, init_data);
	return irq_service;
}

