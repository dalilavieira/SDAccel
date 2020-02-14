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
typedef  int uint32_t ;
struct irq_source_info {int status_reg; int enable_reg; } ;
struct irq_service_init_data {int dummy; } ;
struct irq_service {int /*<<< orphan*/ * funcs; int /*<<< orphan*/  info; int /*<<< orphan*/  ctx; } ;
typedef  enum dc_irq_source { ____Placeholder_dc_irq_source } dc_irq_source ;

/* Variables and functions */
#define  DCN_1_0__CTXID__DC_HPD1_INT 152 
#define  DCN_1_0__CTXID__DC_HPD1_RX_INT 151 
#define  DCN_1_0__CTXID__DC_HPD2_INT 150 
#define  DCN_1_0__CTXID__DC_HPD2_RX_INT 149 
#define  DCN_1_0__CTXID__DC_HPD3_INT 148 
#define  DCN_1_0__CTXID__DC_HPD3_RX_INT 147 
#define  DCN_1_0__CTXID__DC_HPD4_INT 146 
#define  DCN_1_0__CTXID__DC_HPD4_RX_INT 145 
#define  DCN_1_0__CTXID__DC_HPD5_INT 144 
#define  DCN_1_0__CTXID__DC_HPD5_RX_INT 143 
#define  DCN_1_0__CTXID__DC_HPD6_INT 142 
#define  DCN_1_0__CTXID__DC_HPD6_RX_INT 141 
#define  DCN_1_0__SRCID__DC_D1_OTG_VSTARTUP 140 
#define  DCN_1_0__SRCID__DC_D2_OTG_VSTARTUP 139 
#define  DCN_1_0__SRCID__DC_D3_OTG_VSTARTUP 138 
#define  DCN_1_0__SRCID__DC_D4_OTG_VSTARTUP 137 
#define  DCN_1_0__SRCID__DC_D5_OTG_VSTARTUP 136 
#define  DCN_1_0__SRCID__DC_D6_OTG_VSTARTUP 135 
#define  DCN_1_0__SRCID__DC_HPD1_INT 134 
#define  DCN_1_0__SRCID__HUBP0_FLIP_INTERRUPT 133 
#define  DCN_1_0__SRCID__HUBP1_FLIP_INTERRUPT 132 
#define  DCN_1_0__SRCID__HUBP2_FLIP_INTERRUPT 131 
#define  DCN_1_0__SRCID__HUBP3_FLIP_INTERRUPT 130 
#define  DCN_1_0__SRCID__HUBP4_FLIP_INTERRUPT 129 
#define  DCN_1_0__SRCID__HUBP5_FLIP_INTERRUPT 128 
 int /*<<< orphan*/  DC_HPD_INT_POLARITY ; 
 int /*<<< orphan*/  DC_HPD_SENSE_DELAYED ; 
 int DC_IRQ_SOURCE_HPD1 ; 
 int DC_IRQ_SOURCE_HPD1RX ; 
 int DC_IRQ_SOURCE_HPD2 ; 
 int DC_IRQ_SOURCE_HPD2RX ; 
 int DC_IRQ_SOURCE_HPD3 ; 
 int DC_IRQ_SOURCE_HPD3RX ; 
 int DC_IRQ_SOURCE_HPD4 ; 
 int DC_IRQ_SOURCE_HPD4RX ; 
 int DC_IRQ_SOURCE_HPD5 ; 
 int DC_IRQ_SOURCE_HPD5RX ; 
 int DC_IRQ_SOURCE_HPD6 ; 
 int DC_IRQ_SOURCE_HPD6RX ; 
 int DC_IRQ_SOURCE_INVALID ; 
 int DC_IRQ_SOURCE_PFLIP1 ; 
 int DC_IRQ_SOURCE_PFLIP2 ; 
 int DC_IRQ_SOURCE_PFLIP3 ; 
 int DC_IRQ_SOURCE_PFLIP4 ; 
 int DC_IRQ_SOURCE_PFLIP5 ; 
 int DC_IRQ_SOURCE_PFLIP6 ; 
 int DC_IRQ_SOURCE_VBLANK1 ; 
 int DC_IRQ_SOURCE_VBLANK2 ; 
 int DC_IRQ_SOURCE_VBLANK3 ; 
 int DC_IRQ_SOURCE_VBLANK4 ; 
 int DC_IRQ_SOURCE_VBLANK5 ; 
 int DC_IRQ_SOURCE_VBLANK6 ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  HPD0_DC_HPD_INT_CONTROL ; 
 int /*<<< orphan*/  HPD0_DC_HPD_INT_STATUS ; 
 int /*<<< orphan*/  dal_irq_service_ack_generic (struct irq_service*,struct irq_source_info const*) ; 
 int /*<<< orphan*/  dal_irq_service_construct (struct irq_service*,struct irq_service_init_data*) ; 
 int dm_read_reg (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  dm_write_reg (int /*<<< orphan*/ ,int,int) ; 
 int get_reg_field_value (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_service_funcs_dcn10 ; 
 int /*<<< orphan*/  irq_source_info_dcn10 ; 
 struct irq_service* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_reg_field_value (int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

enum dc_irq_source to_dal_irq_source_dcn10(
		struct irq_service *irq_service,
		uint32_t src_id,
		uint32_t ext_id)
{
	switch (src_id) {
	case DCN_1_0__SRCID__DC_D1_OTG_VSTARTUP:
		return DC_IRQ_SOURCE_VBLANK1;
	case DCN_1_0__SRCID__DC_D2_OTG_VSTARTUP:
		return DC_IRQ_SOURCE_VBLANK2;
	case DCN_1_0__SRCID__DC_D3_OTG_VSTARTUP:
		return DC_IRQ_SOURCE_VBLANK3;
	case DCN_1_0__SRCID__DC_D4_OTG_VSTARTUP:
		return DC_IRQ_SOURCE_VBLANK4;
	case DCN_1_0__SRCID__DC_D5_OTG_VSTARTUP:
		return DC_IRQ_SOURCE_VBLANK5;
	case DCN_1_0__SRCID__DC_D6_OTG_VSTARTUP:
		return DC_IRQ_SOURCE_VBLANK6;
	case DCN_1_0__SRCID__HUBP0_FLIP_INTERRUPT:
		return DC_IRQ_SOURCE_PFLIP1;
	case DCN_1_0__SRCID__HUBP1_FLIP_INTERRUPT:
		return DC_IRQ_SOURCE_PFLIP2;
	case DCN_1_0__SRCID__HUBP2_FLIP_INTERRUPT:
		return DC_IRQ_SOURCE_PFLIP3;
	case DCN_1_0__SRCID__HUBP3_FLIP_INTERRUPT:
		return DC_IRQ_SOURCE_PFLIP4;
	case DCN_1_0__SRCID__HUBP4_FLIP_INTERRUPT:
		return DC_IRQ_SOURCE_PFLIP5;
	case DCN_1_0__SRCID__HUBP5_FLIP_INTERRUPT:
		return DC_IRQ_SOURCE_PFLIP6;

	case DCN_1_0__SRCID__DC_HPD1_INT:
		/* generic src_id for all HPD and HPDRX interrupts */
		switch (ext_id) {
		case DCN_1_0__CTXID__DC_HPD1_INT:
			return DC_IRQ_SOURCE_HPD1;
		case DCN_1_0__CTXID__DC_HPD2_INT:
			return DC_IRQ_SOURCE_HPD2;
		case DCN_1_0__CTXID__DC_HPD3_INT:
			return DC_IRQ_SOURCE_HPD3;
		case DCN_1_0__CTXID__DC_HPD4_INT:
			return DC_IRQ_SOURCE_HPD4;
		case DCN_1_0__CTXID__DC_HPD5_INT:
			return DC_IRQ_SOURCE_HPD5;
		case DCN_1_0__CTXID__DC_HPD6_INT:
			return DC_IRQ_SOURCE_HPD6;
		case DCN_1_0__CTXID__DC_HPD1_RX_INT:
			return DC_IRQ_SOURCE_HPD1RX;
		case DCN_1_0__CTXID__DC_HPD2_RX_INT:
			return DC_IRQ_SOURCE_HPD2RX;
		case DCN_1_0__CTXID__DC_HPD3_RX_INT:
			return DC_IRQ_SOURCE_HPD3RX;
		case DCN_1_0__CTXID__DC_HPD4_RX_INT:
			return DC_IRQ_SOURCE_HPD4RX;
		case DCN_1_0__CTXID__DC_HPD5_RX_INT:
			return DC_IRQ_SOURCE_HPD5RX;
		case DCN_1_0__CTXID__DC_HPD6_RX_INT:
			return DC_IRQ_SOURCE_HPD6RX;
		default:
			return DC_IRQ_SOURCE_INVALID;
		}
		break;

	default:
		return DC_IRQ_SOURCE_INVALID;
	}
}

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

	irq_service->info = irq_source_info_dcn10;
	irq_service->funcs = &irq_service_funcs_dcn10;
}

struct irq_service *dal_irq_service_dcn10_create(
	struct irq_service_init_data *init_data)
{
	struct irq_service *irq_service = kzalloc(sizeof(*irq_service),
						  GFP_KERNEL);

	if (!irq_service)
		return NULL;

	construct(irq_service, init_data);
	return irq_service;
}

