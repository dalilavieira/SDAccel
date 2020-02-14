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
typedef  scalar_t__ u64 ;
struct csr_space {scalar_t__ length; scalar_t__ base; int /*<<< orphan*/  member_1; int /*<<< orphan*/  member_0; } ;
struct acpi_resource_vendor_typed {int byte_length; scalar_t__ byte_data; } ;
struct TYPE_4__ {scalar_t__ address_length; scalar_t__ minimum; } ;
struct acpi_resource_address64 {scalar_t__ resource_type; scalar_t__ producer_consumer; TYPE_2__ address; } ;
struct TYPE_3__ {struct acpi_resource_vendor_typed vendor_typed; } ;
struct acpi_resource {TYPE_1__ data; } ;
struct acpi_buffer {struct acpi_resource* pointer; int /*<<< orphan*/ * member_1; int /*<<< orphan*/  member_0; } ;
typedef  int /*<<< orphan*/  acpi_status ;
typedef  int /*<<< orphan*/  acpi_handle ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_ALLOCATE_BUFFER ; 
 scalar_t__ ACPI_CONSUMER ; 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_MEMORY_RANGE ; 
 scalar_t__ ACPI_SUCCESS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AE_CTRL_TERMINATE ; 
 int /*<<< orphan*/  AE_NOT_FOUND ; 
 int /*<<< orphan*/  AE_OK ; 
 int /*<<< orphan*/  METHOD_NAME__CRS ; 
 int /*<<< orphan*/  acpi_get_vendor_resource (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct acpi_buffer*) ; 
 int /*<<< orphan*/  acpi_resource_to_address64 (struct acpi_resource*,struct acpi_resource_address64*) ; 
 int /*<<< orphan*/  acpi_walk_resources (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (struct acpi_resource*,void*),struct csr_space*) ; 
 int /*<<< orphan*/  hp_ccsr_uuid ; 
 int /*<<< orphan*/  kfree (struct acpi_resource*) ; 
 int /*<<< orphan*/  memcpy (scalar_t__*,scalar_t__,int) ; 

__attribute__((used)) static acpi_status hp_ccsr_locate(acpi_handle obj, u64 *base, u64 *length)
{
	acpi_status status;
	struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
	struct acpi_resource *resource;
	struct acpi_resource_vendor_typed *vendor;

	status = acpi_get_vendor_resource(obj, METHOD_NAME__CRS, &hp_ccsr_uuid,
		&buffer);

	resource = buffer.pointer;
	vendor = &resource->data.vendor_typed;

	if (ACPI_FAILURE(status) || vendor->byte_length < 16) {
		status = AE_NOT_FOUND;
		goto exit;
	}

	memcpy(base, vendor->byte_data, sizeof(*base));
	memcpy(length, vendor->byte_data + 8, sizeof(*length));

  exit:
	kfree(buffer.pointer);
	return status;
}

__attribute__((used)) static acpi_status find_csr_space(struct acpi_resource *resource, void *data)
{
	struct csr_space *space = data;
	struct acpi_resource_address64 addr;
	acpi_status status;

	status = acpi_resource_to_address64(resource, &addr);
	if (ACPI_SUCCESS(status) &&
	    addr.resource_type == ACPI_MEMORY_RANGE &&
	    addr.address.address_length &&
	    addr.producer_consumer == ACPI_CONSUMER) {
		space->base = addr.address.minimum;
		space->length = addr.address.address_length;
		return AE_CTRL_TERMINATE;
	}
	return AE_OK;		/* keep looking */
}

__attribute__((used)) static acpi_status hp_crs_locate(acpi_handle obj, u64 *base, u64 *length)
{
	struct csr_space space = { 0, 0 };

	acpi_walk_resources(obj, METHOD_NAME__CRS, find_csr_space, &space);
	if (!space.length)
		return AE_NOT_FOUND;

	*base = space.base;
	*length = space.length;
	return AE_OK;
}

acpi_status hp_acpi_csr_space(acpi_handle obj, u64 *csr_base, u64 *csr_length)
{
	acpi_status status;

	status = hp_ccsr_locate(obj, csr_base, csr_length);
	if (ACPI_SUCCESS(status))
		return status;

	return hp_crs_locate(obj, csr_base, csr_length);
}

