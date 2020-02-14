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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u64 ;
typedef  scalar_t__ u32 ;
struct apei_resources {int /*<<< orphan*/  ioport; int /*<<< orphan*/  iomem; } ;
struct apei_exec_context {int /*<<< orphan*/  value; } ;
struct acpi_hest_generic_status {scalar_t__ data_length; scalar_t__ raw_data_length; scalar_t__ raw_data_offset; } ;
struct acpi_generic_address {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 int __apei_exec_run (struct apei_exec_context*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  acpi_os_unmap_generic_address (struct acpi_generic_address*) ; 

__attribute__((used)) static inline void apei_exec_ctx_set_input(struct apei_exec_context *ctx,
					   u64 input)
{
	ctx->value = input;
}

__attribute__((used)) static inline u64 apei_exec_ctx_get_output(struct apei_exec_context *ctx)
{
	return ctx->value;
}

__attribute__((used)) static inline int apei_exec_run(struct apei_exec_context *ctx, u8 action)
{
	return __apei_exec_run(ctx, action, 0);
}

__attribute__((used)) static inline int apei_exec_run_optional(struct apei_exec_context *ctx, u8 action)
{
	return __apei_exec_run(ctx, action, 1);
}

__attribute__((used)) static inline void apei_unmap_generic_address(struct acpi_generic_address *reg)
{
	acpi_os_unmap_generic_address(reg);
}

__attribute__((used)) static inline void apei_resources_init(struct apei_resources *resources)
{
	INIT_LIST_HEAD(&resources->iomem);
	INIT_LIST_HEAD(&resources->ioport);
}

__attribute__((used)) static inline u32 cper_estatus_len(struct acpi_hest_generic_status *estatus)
{
	if (estatus->raw_data_length)
		return estatus->raw_data_offset + \
			estatus->raw_data_length;
	else
		return sizeof(*estatus) + estatus->data_length;
}

