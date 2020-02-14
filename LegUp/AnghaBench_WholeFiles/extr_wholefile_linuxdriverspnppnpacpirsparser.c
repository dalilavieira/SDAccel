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
typedef  scalar_t__ u8 ;
typedef  scalar_t__ u64 ;
struct resource {int flags; int /*<<< orphan*/  start; } ;
struct TYPE_4__ {int /*<<< orphan*/  member_0; } ;
struct resource_win {struct resource res; int /*<<< orphan*/  member_1; TYPE_2__ member_0; } ;
struct pnp_option {int flags; } ;
struct pnp_dev {unsigned int num_dependent_sets; int /*<<< orphan*/  dev; struct acpi_device* data; int /*<<< orphan*/  capabilities; } ;
struct acpi_vendor_uuid {scalar_t__ subtype; int /*<<< orphan*/  data; } ;
struct acpi_resource_vendor_typed {scalar_t__ uuid_subtype; int byte_length; scalar_t__ byte_data; scalar_t__* uuid; } ;
struct acpi_resource_gpio {int /*<<< orphan*/  sharable; int /*<<< orphan*/  polarity; int /*<<< orphan*/  triggering; } ;
struct acpi_resource_dma {scalar_t__* channels; int type; int bus_master; int transfer; int /*<<< orphan*/  channel_count; } ;
struct TYPE_3__ {struct acpi_resource_vendor_typed vendor_typed; struct acpi_resource_dma dma; } ;
struct acpi_resource {int type; TYPE_1__ data; } ;
struct acpi_device {int /*<<< orphan*/  handle; } ;
typedef  int /*<<< orphan*/  start ;
typedef  int /*<<< orphan*/  length ;
typedef  int acpi_status ;
typedef  int /*<<< orphan*/  acpi_handle ;

/* Variables and functions */
 scalar_t__ ACPI_ACTIVE_HIGH ; 
 scalar_t__ ACPI_ACTIVE_LOW ; 
#define  ACPI_COMPATIBILITY 150 
 scalar_t__ ACPI_EDGE_SENSITIVE ; 
 scalar_t__ ACPI_EXCLUSIVE ; 
 scalar_t__ ACPI_FAILURE (int) ; 
 scalar_t__ ACPI_LEVEL_SENSITIVE ; 
#define  ACPI_RESOURCE_TYPE_DMA 149 
#define  ACPI_RESOURCE_TYPE_END_DEPENDENT 148 
#define  ACPI_RESOURCE_TYPE_END_TAG 147 
#define  ACPI_RESOURCE_TYPE_FIXED_IO 146 
#define  ACPI_RESOURCE_TYPE_FIXED_MEMORY32 145 
#define  ACPI_RESOURCE_TYPE_GENERIC_REGISTER 144 
#define  ACPI_RESOURCE_TYPE_IO 143 
#define  ACPI_RESOURCE_TYPE_MEMORY24 142 
#define  ACPI_RESOURCE_TYPE_MEMORY32 141 
#define  ACPI_RESOURCE_TYPE_SERIAL_BUS 140 
#define  ACPI_RESOURCE_TYPE_START_DEPENDENT 139 
#define  ACPI_RESOURCE_TYPE_VENDOR 138 
 scalar_t__ ACPI_SHARED ; 
#define  ACPI_TRANSFER_16 137 
#define  ACPI_TRANSFER_8 136 
#define  ACPI_TRANSFER_8_16 135 
#define  ACPI_TYPE_A 134 
#define  ACPI_TYPE_B 133 
#define  ACPI_TYPE_F 132 
 int AE_ERROR ; 
 int AE_NOT_FOUND ; 
 int AE_OK ; 
 int EPERM ; 
 int IORESOURCE_DISABLED ; 
 int IORESOURCE_DMA_16BIT ; 
 int IORESOURCE_DMA_8AND16BIT ; 
 int IORESOURCE_DMA_8BIT ; 
 int IORESOURCE_DMA_COMPATIBLE ; 
 int IORESOURCE_DMA_MASTER ; 
 int IORESOURCE_DMA_TYPEA ; 
 int IORESOURCE_DMA_TYPEB ; 
 int IORESOURCE_DMA_TYPEF ; 
#define  IORESOURCE_IRQ_HIGHEDGE 131 
#define  IORESOURCE_IRQ_HIGHLEVEL 130 
#define  IORESOURCE_IRQ_LOWEDGE 129 
#define  IORESOURCE_IRQ_LOWLEVEL 128 
 int IORESOURCE_IRQ_SHAREABLE ; 
 int /*<<< orphan*/  METHOD_NAME__CRS ; 
 int PNP_OPTION_DEPENDENT ; 
 unsigned int PNP_OPTION_PRIORITY_MASK ; 
 unsigned int PNP_OPTION_PRIORITY_SHIFT ; 
 unsigned int PNP_OPTION_SET_MASK ; 
 unsigned int PNP_OPTION_SET_SHIFT ; 
 int PNP_RES_PRIORITY_FUNCTIONAL ; 
 int PNP_RES_PRIORITY_INVALID ; 
 int /*<<< orphan*/  PNP_WRITE ; 
 int acpi_dev_gpio_irq_get (struct acpi_device*,int /*<<< orphan*/ ) ; 
 int acpi_dev_irq_flags (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ acpi_dev_resource_address_space (struct acpi_resource*,struct resource_win*) ; 
 scalar_t__ acpi_dev_resource_ext_address_space (struct acpi_resource*,struct resource_win*) ; 
 scalar_t__ acpi_dev_resource_interrupt (struct acpi_resource*,int,struct resource*) ; 
 int /*<<< orphan*/  acpi_dev_resource_io (struct acpi_resource*,struct resource*) ; 
 int /*<<< orphan*/  acpi_dev_resource_memory (struct acpi_resource*,struct resource*) ; 
 scalar_t__ acpi_gpio_get_irq_resource (struct acpi_resource*,struct acpi_resource_gpio**) ; 
 int acpi_walk_resources (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int (*) (struct acpi_resource*,void*),struct pnp_dev*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int,...) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*,...) ; 
 struct acpi_vendor_uuid hp_ccsr_uuid ; 
 scalar_t__ memcmp (scalar_t__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  memcpy (scalar_t__*,scalar_t__,int) ; 
 int /*<<< orphan*/  pcibios_penalize_isa_irq (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pnp_add_dma_resource (struct pnp_dev*,scalar_t__,int) ; 
 int /*<<< orphan*/  pnp_add_irq_resource (struct pnp_dev*,int,int) ; 
 int /*<<< orphan*/  pnp_add_mem_resource (struct pnp_dev*,scalar_t__,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pnp_add_resource (struct pnp_dev*,struct resource*) ; 
 scalar_t__ pnp_can_write (struct pnp_dev*) ; 
 int /*<<< orphan*/  pnp_dbg (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  pnp_init_resources (struct pnp_dev*) ; 

__attribute__((used)) static inline int pnp_option_is_dependent(struct pnp_option *option)
{
	return option->flags & PNP_OPTION_DEPENDENT ? 1 : 0;
}

__attribute__((used)) static inline unsigned int pnp_option_set(struct pnp_option *option)
{
	return (option->flags >> PNP_OPTION_SET_SHIFT) & PNP_OPTION_SET_MASK;
}

__attribute__((used)) static inline unsigned int pnp_option_priority(struct pnp_option *option)
{
	return (option->flags >> PNP_OPTION_PRIORITY_SHIFT) &
	    PNP_OPTION_PRIORITY_MASK;
}

__attribute__((used)) static inline unsigned int pnp_new_dependent_set(struct pnp_dev *dev,
						 int priority)
{
	unsigned int flags;

	if (priority > PNP_RES_PRIORITY_FUNCTIONAL) {
		dev_warn(&dev->dev, "invalid dependent option priority %d "
			 "clipped to %d", priority,
			 PNP_RES_PRIORITY_INVALID);
		priority = PNP_RES_PRIORITY_INVALID;
	}

	flags = PNP_OPTION_DEPENDENT |
	    ((dev->num_dependent_sets & PNP_OPTION_SET_MASK) <<
		PNP_OPTION_SET_SHIFT) |
	    ((priority & PNP_OPTION_PRIORITY_MASK) <<
		PNP_OPTION_PRIORITY_SHIFT);

	dev->num_dependent_sets++;

	return flags;
}

__attribute__((used)) static void decode_irq_flags(struct pnp_dev *dev, int flags, u8 *triggering,
			     u8 *polarity, u8 *shareable)
{
	switch (flags & (IORESOURCE_IRQ_LOWLEVEL | IORESOURCE_IRQ_HIGHLEVEL |
			 IORESOURCE_IRQ_LOWEDGE  | IORESOURCE_IRQ_HIGHEDGE)) {
	case IORESOURCE_IRQ_LOWLEVEL:
		*triggering = ACPI_LEVEL_SENSITIVE;
		*polarity = ACPI_ACTIVE_LOW;
		break;
	case IORESOURCE_IRQ_HIGHLEVEL:
		*triggering = ACPI_LEVEL_SENSITIVE;
		*polarity = ACPI_ACTIVE_HIGH;
		break;
	case IORESOURCE_IRQ_LOWEDGE:
		*triggering = ACPI_EDGE_SENSITIVE;
		*polarity = ACPI_ACTIVE_LOW;
		break;
	case IORESOURCE_IRQ_HIGHEDGE:
		*triggering = ACPI_EDGE_SENSITIVE;
		*polarity = ACPI_ACTIVE_HIGH;
		break;
	default:
		dev_err(&dev->dev, "can't encode invalid IRQ mode %#x\n",
			flags);
		*triggering = ACPI_EDGE_SENSITIVE;
		*polarity = ACPI_ACTIVE_HIGH;
		break;
	}

	if (flags & IORESOURCE_IRQ_SHAREABLE)
		*shareable = ACPI_SHARED;
	else
		*shareable = ACPI_EXCLUSIVE;
}

__attribute__((used)) static int dma_flags(struct pnp_dev *dev, int type, int bus_master,
		     int transfer)
{
	int flags = 0;

	if (bus_master)
		flags |= IORESOURCE_DMA_MASTER;
	switch (type) {
	case ACPI_COMPATIBILITY:
		flags |= IORESOURCE_DMA_COMPATIBLE;
		break;
	case ACPI_TYPE_A:
		flags |= IORESOURCE_DMA_TYPEA;
		break;
	case ACPI_TYPE_B:
		flags |= IORESOURCE_DMA_TYPEB;
		break;
	case ACPI_TYPE_F:
		flags |= IORESOURCE_DMA_TYPEF;
		break;
	default:
		/* Set a default value ? */
		flags |= IORESOURCE_DMA_COMPATIBLE;
		dev_err(&dev->dev, "invalid DMA type %d\n", type);
	}
	switch (transfer) {
	case ACPI_TRANSFER_8:
		flags |= IORESOURCE_DMA_8BIT;
		break;
	case ACPI_TRANSFER_8_16:
		flags |= IORESOURCE_DMA_8AND16BIT;
		break;
	case ACPI_TRANSFER_16:
		flags |= IORESOURCE_DMA_16BIT;
		break;
	default:
		/* Set a default value ? */
		flags |= IORESOURCE_DMA_8AND16BIT;
		dev_err(&dev->dev, "invalid DMA transfer type %d\n", transfer);
	}

	return flags;
}

__attribute__((used)) static void pnpacpi_add_irqresource(struct pnp_dev *dev, struct resource *r)
{
	if (!(r->flags & IORESOURCE_DISABLED))
		pcibios_penalize_isa_irq(r->start, 1);

	pnp_add_resource(dev, r);
}

__attribute__((used)) static int vendor_resource_matches(struct pnp_dev *dev,
				   struct acpi_resource_vendor_typed *vendor,
				   struct acpi_vendor_uuid *match,
				   int expected_len)
{
	int uuid_len = sizeof(vendor->uuid);
	u8 uuid_subtype = vendor->uuid_subtype;
	u8 *uuid = vendor->uuid;
	int actual_len;

	/* byte_length includes uuid_subtype and uuid */
	actual_len = vendor->byte_length - uuid_len - 1;

	if (uuid_subtype == match->subtype &&
	    uuid_len == sizeof(match->data) &&
	    memcmp(uuid, match->data, uuid_len) == 0) {
		if (expected_len && expected_len != actual_len) {
			dev_err(&dev->dev,
				"wrong vendor descriptor size; expected %d, found %d bytes\n",
				expected_len, actual_len);
			return 0;
		}

		return 1;
	}

	return 0;
}

__attribute__((used)) static void pnpacpi_parse_allocated_vendor(struct pnp_dev *dev,
				    struct acpi_resource_vendor_typed *vendor)
{
	if (vendor_resource_matches(dev, vendor, &hp_ccsr_uuid, 16)) {
		u64 start, length;

		memcpy(&start, vendor->byte_data, sizeof(start));
		memcpy(&length, vendor->byte_data + 8, sizeof(length));

		pnp_add_mem_resource(dev, start, start + length - 1, 0);
	}
}

__attribute__((used)) static acpi_status pnpacpi_allocated_resource(struct acpi_resource *res,
					      void *data)
{
	struct pnp_dev *dev = data;
	struct acpi_resource_dma *dma;
	struct acpi_resource_vendor_typed *vendor_typed;
	struct acpi_resource_gpio *gpio;
	struct resource_win win = {{0}, 0};
	struct resource *r = &win.res;
	int i, flags;

	if (acpi_dev_resource_address_space(res, &win)
	    || acpi_dev_resource_ext_address_space(res, &win)) {
		pnp_add_resource(dev, &win.res);
		return AE_OK;
	}

	r->flags = 0;
	if (acpi_dev_resource_interrupt(res, 0, r)) {
		pnpacpi_add_irqresource(dev, r);
		for (i = 1; acpi_dev_resource_interrupt(res, i, r); i++)
			pnpacpi_add_irqresource(dev, r);

		if (i > 1) {
			/*
			 * The IRQ encoder puts a single interrupt in each
			 * descriptor, so if a _CRS descriptor has more than
			 * one interrupt, we won't be able to re-encode it.
			 */
			if (pnp_can_write(dev)) {
				dev_warn(&dev->dev,
					 "multiple interrupts in _CRS descriptor; configuration can't be changed\n");
				dev->capabilities &= ~PNP_WRITE;
			}
		}
		return AE_OK;
	} else if (acpi_gpio_get_irq_resource(res, &gpio)) {
		/*
		 * If the resource is GpioInt() type then extract the IRQ
		 * from GPIO resource and fill it into IRQ resource type.
		 */
		i = acpi_dev_gpio_irq_get(dev->data, 0);
		if (i >= 0) {
			flags = acpi_dev_irq_flags(gpio->triggering,
						   gpio->polarity,
						   gpio->sharable);
		} else {
			flags = IORESOURCE_DISABLED;
		}
		pnp_add_irq_resource(dev, i, flags);
		return AE_OK;
	} else if (r->flags & IORESOURCE_DISABLED) {
		pnp_add_irq_resource(dev, 0, IORESOURCE_DISABLED);
		return AE_OK;
	}

	switch (res->type) {
	case ACPI_RESOURCE_TYPE_MEMORY24:
	case ACPI_RESOURCE_TYPE_MEMORY32:
	case ACPI_RESOURCE_TYPE_FIXED_MEMORY32:
		if (acpi_dev_resource_memory(res, r))
			pnp_add_resource(dev, r);
		break;
	case ACPI_RESOURCE_TYPE_IO:
	case ACPI_RESOURCE_TYPE_FIXED_IO:
		if (acpi_dev_resource_io(res, r))
			pnp_add_resource(dev, r);
		break;
	case ACPI_RESOURCE_TYPE_DMA:
		dma = &res->data.dma;
		if (dma->channel_count > 0 && dma->channels[0] != (u8) -1)
			flags = dma_flags(dev, dma->type, dma->bus_master,
					  dma->transfer);
		else
			flags = IORESOURCE_DISABLED;
		pnp_add_dma_resource(dev, dma->channels[0], flags);
		break;

	case ACPI_RESOURCE_TYPE_START_DEPENDENT:
	case ACPI_RESOURCE_TYPE_END_DEPENDENT:
		break;

	case ACPI_RESOURCE_TYPE_VENDOR:
		vendor_typed = &res->data.vendor_typed;
		pnpacpi_parse_allocated_vendor(dev, vendor_typed);
		break;

	case ACPI_RESOURCE_TYPE_END_TAG:
		break;

	case ACPI_RESOURCE_TYPE_GENERIC_REGISTER:
		break;

	case ACPI_RESOURCE_TYPE_SERIAL_BUS:
		/* serial bus connections (I2C/SPI/UART) are not pnp */
		break;

	default:
		dev_warn(&dev->dev, "unknown resource type %d in _CRS\n",
			 res->type);
		return AE_ERROR;
	}

	return AE_OK;
}

int pnpacpi_parse_allocated_resource(struct pnp_dev *dev)
{
	struct acpi_device *acpi_dev = dev->data;
	acpi_handle handle = acpi_dev->handle;
	acpi_status status;

	pnp_dbg(&dev->dev, "parse allocated resources\n");

	pnp_init_resources(dev);

	status = acpi_walk_resources(handle, METHOD_NAME__CRS,
				     pnpacpi_allocated_resource, dev);

	if (ACPI_FAILURE(status)) {
		if (status != AE_NOT_FOUND)
			dev_err(&dev->dev, "can't evaluate _CRS: %d", status);
		return -EPERM;
	}
	return 0;
}

