#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  void* u32 ;
struct resource {int start; int end; int /*<<< orphan*/  flags; } ;
struct irq_fwspec {int param_count; struct fwnode_handle* fwnode; void** param; } ;
struct irq_domain {int dummy; } ;
struct fwnode_handle {int dummy; } ;
struct device {int dummy; } ;
struct acpi_resource_source {int /*<<< orphan*/  string_ptr; int /*<<< orphan*/  string_length; } ;
struct acpi_resource_irq {size_t interrupt_count; int triggering; int polarity; int sharable; void** interrupts; } ;
struct acpi_resource_extended_irq {size_t interrupt_count; int triggering; int polarity; int sharable; void** interrupts; struct acpi_resource_source resource_source; int /*<<< orphan*/  producer_consumer; } ;
struct TYPE_4__ {struct acpi_resource_extended_irq extended_irq; struct acpi_resource_irq irq; } ;
struct acpi_resource {int type; TYPE_2__ data; } ;
struct acpi_irq_parse_one_ctx {int rc; size_t index; int member_0; unsigned int member_1; unsigned long* member_2; struct irq_fwspec* member_3; TYPE_1__* fwspec; int /*<<< orphan*/ * res_flags; } ;
struct acpi_device {struct fwnode_handle fwnode; } ;
typedef  int /*<<< orphan*/  acpi_status ;
typedef  int /*<<< orphan*/  acpi_handle ;
struct TYPE_3__ {int param_count; void** param; struct fwnode_handle* fwnode; } ;

/* Variables and functions */
 int ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_PRODUCER ; 
#define  ACPI_RESOURCE_TYPE_EXTENDED_IRQ 129 
#define  ACPI_RESOURCE_TYPE_IRQ 128 
 int /*<<< orphan*/  AE_CTRL_TERMINATE ; 
 int /*<<< orphan*/  AE_OK ; 
 int /*<<< orphan*/  DOMAIN_BUS_ANY ; 
 int EINVAL ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  METHOD_NAME__CRS ; 
 scalar_t__ WARN_ON (int) ; 
 struct acpi_device* acpi_bus_get_acpi_device (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  acpi_bus_put_acpi_device (struct acpi_device*) ; 
 void* acpi_dev_get_irq_type (int,int) ; 
 int /*<<< orphan*/  acpi_dev_irq_flags (int,int,int) ; 
 int /*<<< orphan*/  acpi_get_handle (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct fwnode_handle* acpi_gsi_domain_id ; 
 int /*<<< orphan*/  acpi_walk_resources (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (struct acpi_resource*,void*),struct acpi_irq_parse_one_ctx*) ; 
 int irq_create_fwspec_mapping (struct irq_fwspec*) ; 
 int /*<<< orphan*/  irq_dispose_mapping (int) ; 
 void* irq_find_mapping (struct irq_domain*,void*) ; 
 struct irq_domain* irq_find_matching_fwnode (struct fwnode_handle*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_warn (char*) ; 

int acpi_gsi_to_irq(u32 gsi, unsigned int *irq)
{
	struct irq_domain *d = irq_find_matching_fwnode(acpi_gsi_domain_id,
							DOMAIN_BUS_ANY);

	*irq = irq_find_mapping(d, gsi);
	/*
	 * *irq == 0 means no mapping, that should
	 * be reported as a failure
	 */
	return (*irq > 0) ? 0 : -EINVAL;
}

int acpi_register_gsi(struct device *dev, u32 gsi, int trigger,
		      int polarity)
{
	struct irq_fwspec fwspec;

	if (WARN_ON(!acpi_gsi_domain_id)) {
		pr_warn("GSI: No registered irqchip, giving up\n");
		return -EINVAL;
	}

	fwspec.fwnode = acpi_gsi_domain_id;
	fwspec.param[0] = gsi;
	fwspec.param[1] = acpi_dev_get_irq_type(trigger, polarity);
	fwspec.param_count = 2;

	return irq_create_fwspec_mapping(&fwspec);
}

void acpi_unregister_gsi(u32 gsi)
{
	struct irq_domain *d = irq_find_matching_fwnode(acpi_gsi_domain_id,
							DOMAIN_BUS_ANY);
	int irq = irq_find_mapping(d, gsi);

	irq_dispose_mapping(irq);
}

__attribute__((used)) static struct fwnode_handle *
acpi_get_irq_source_fwhandle(const struct acpi_resource_source *source)
{
	struct fwnode_handle *result;
	struct acpi_device *device;
	acpi_handle handle;
	acpi_status status;

	if (!source->string_length)
		return acpi_gsi_domain_id;

	status = acpi_get_handle(NULL, source->string_ptr, &handle);
	if (WARN_ON(ACPI_FAILURE(status)))
		return NULL;

	device = acpi_bus_get_acpi_device(handle);
	if (WARN_ON(!device))
		return NULL;

	result = &device->fwnode;
	acpi_bus_put_acpi_device(device);
	return result;
}

__attribute__((used)) static inline void acpi_irq_parse_one_match(struct fwnode_handle *fwnode,
					    u32 hwirq, u8 triggering,
					    u8 polarity, u8 shareable,
					    struct acpi_irq_parse_one_ctx *ctx)
{
	if (!fwnode)
		return;
	ctx->rc = 0;
	*ctx->res_flags = acpi_dev_irq_flags(triggering, polarity, shareable);
	ctx->fwspec->fwnode = fwnode;
	ctx->fwspec->param[0] = hwirq;
	ctx->fwspec->param[1] = acpi_dev_get_irq_type(triggering, polarity);
	ctx->fwspec->param_count = 2;
}

__attribute__((used)) static acpi_status acpi_irq_parse_one_cb(struct acpi_resource *ares,
					 void *context)
{
	struct acpi_irq_parse_one_ctx *ctx = context;
	struct acpi_resource_irq *irq;
	struct acpi_resource_extended_irq *eirq;
	struct fwnode_handle *fwnode;

	switch (ares->type) {
	case ACPI_RESOURCE_TYPE_IRQ:
		irq = &ares->data.irq;
		if (ctx->index >= irq->interrupt_count) {
			ctx->index -= irq->interrupt_count;
			return AE_OK;
		}
		fwnode = acpi_gsi_domain_id;
		acpi_irq_parse_one_match(fwnode, irq->interrupts[ctx->index],
					 irq->triggering, irq->polarity,
					 irq->sharable, ctx);
		return AE_CTRL_TERMINATE;
	case ACPI_RESOURCE_TYPE_EXTENDED_IRQ:
		eirq = &ares->data.extended_irq;
		if (eirq->producer_consumer == ACPI_PRODUCER)
			return AE_OK;
		if (ctx->index >= eirq->interrupt_count) {
			ctx->index -= eirq->interrupt_count;
			return AE_OK;
		}
		fwnode = acpi_get_irq_source_fwhandle(&eirq->resource_source);
		acpi_irq_parse_one_match(fwnode, eirq->interrupts[ctx->index],
					 eirq->triggering, eirq->polarity,
					 eirq->sharable, ctx);
		return AE_CTRL_TERMINATE;
	}

	return AE_OK;
}

__attribute__((used)) static int acpi_irq_parse_one(acpi_handle handle, unsigned int index,
			      struct irq_fwspec *fwspec, unsigned long *flags)
{
	struct acpi_irq_parse_one_ctx ctx = { -EINVAL, index, flags, fwspec };

	acpi_walk_resources(handle, METHOD_NAME__CRS, acpi_irq_parse_one_cb, &ctx);
	return ctx.rc;
}

int acpi_irq_get(acpi_handle handle, unsigned int index, struct resource *res)
{
	struct irq_fwspec fwspec;
	struct irq_domain *domain;
	unsigned long flags;
	int rc;

	rc = acpi_irq_parse_one(handle, index, &fwspec, &flags);
	if (rc)
		return rc;

	domain = irq_find_matching_fwnode(fwspec.fwnode, DOMAIN_BUS_ANY);
	if (!domain)
		return -EPROBE_DEFER;

	rc = irq_create_fwspec_mapping(&fwspec);
	if (rc <= 0)
		return -EINVAL;

	res->start = rc;
	res->end = rc;
	res->flags = flags;

	return 0;
}

