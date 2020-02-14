#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_8__ ;
typedef  struct TYPE_15__   TYPE_7__ ;
typedef  struct TYPE_14__   TYPE_6__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned long long u64 ;
struct TYPE_10__ {int bit_width; unsigned long long address; unsigned long long bit_offset; scalar_t__ space_id; } ;
struct lpit_residency_info {int frequency; TYPE_2__ gaddr; int /*<<< orphan*/  iomem_addr; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct TYPE_12__ {unsigned long long length; } ;
struct acpi_table_lpit {TYPE_4__ header; } ;
struct acpi_table_header {int dummy; } ;
struct TYPE_11__ {unsigned long long length; int /*<<< orphan*/  flags; int /*<<< orphan*/  type; } ;
struct acpi_lpit_native {int counter_frequency; TYPE_3__ header; TYPE_2__ residency_counter; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  acpi_status ;
struct TYPE_16__ {int flags; } ;
struct TYPE_15__ {TYPE_1__* dev_root; } ;
struct TYPE_14__ {int /*<<< orphan*/  attr; } ;
struct TYPE_13__ {int /*<<< orphan*/  attr; } ;
struct TYPE_9__ {int /*<<< orphan*/  kobj; } ;

/* Variables and functions */
 scalar_t__ ACPI_ADR_SPACE_FIXED_HARDWARE ; 
 scalar_t__ ACPI_ADR_SPACE_SYSTEM_MEMORY ; 
 int ACPI_FADT_LOW_POWER_S0 ; 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_SIG_LPIT ; 
 int EINVAL ; 
 int ENODATA ; 
 unsigned long long GENMASK_ULL (int,unsigned long long) ; 
 TYPE_8__ acpi_gbl_FADT ; 
 int /*<<< orphan*/  acpi_get_table (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct acpi_table_header**) ; 
 int acpi_os_read_iomem (int /*<<< orphan*/ ,unsigned long long*,int) ; 
 TYPE_7__ cpu_subsys ; 
 TYPE_6__ dev_attr_low_power_idle_cpu_residency_us ; 
 TYPE_5__ dev_attr_low_power_idle_system_residency_us ; 
 unsigned long long div64_u64 (unsigned long long,int) ; 
 int /*<<< orphan*/  ioremap_nocache (unsigned long long,int) ; 
 int rdmsrl_safe (unsigned long long,unsigned long long*) ; 
 struct lpit_residency_info residency_info_ffh ; 
 struct lpit_residency_info residency_info_mem ; 
 int sprintf (char*,char*,unsigned long long) ; 
 int /*<<< orphan*/  sysfs_add_file_to_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*) ; 
 int tsc_khz ; 

__attribute__((used)) static int lpit_read_residency_counter_us(u64 *counter, bool io_mem)
{
	int err;

	if (io_mem) {
		u64 count = 0;
		int error;

		error = acpi_os_read_iomem(residency_info_mem.iomem_addr, &count,
					   residency_info_mem.gaddr.bit_width);
		if (error)
			return error;

		*counter = div64_u64(count * 1000000ULL, residency_info_mem.frequency);
		return 0;
	}

	err = rdmsrl_safe(residency_info_ffh.gaddr.address, counter);
	if (!err) {
		u64 mask = GENMASK_ULL(residency_info_ffh.gaddr.bit_offset +
				       residency_info_ffh.gaddr. bit_width - 1,
				       residency_info_ffh.gaddr.bit_offset);

		*counter &= mask;
		*counter >>= residency_info_ffh.gaddr.bit_offset;
		*counter = div64_u64(*counter * 1000000ULL, residency_info_ffh.frequency);
		return 0;
	}

	return -ENODATA;
}

__attribute__((used)) static ssize_t low_power_idle_system_residency_us_show(struct device *dev,
						       struct device_attribute *attr,
						       char *buf)
{
	u64 counter;
	int ret;

	ret = lpit_read_residency_counter_us(&counter, true);
	if (ret)
		return ret;

	return sprintf(buf, "%llu\n", counter);
}

__attribute__((used)) static ssize_t low_power_idle_cpu_residency_us_show(struct device *dev,
						    struct device_attribute *attr,
						    char *buf)
{
	u64 counter;
	int ret;

	ret = lpit_read_residency_counter_us(&counter, false);
	if (ret)
		return ret;

	return sprintf(buf, "%llu\n", counter);
}

int lpit_read_residency_count_address(u64 *address)
{
	if (!residency_info_mem.gaddr.address)
		return -EINVAL;

	*address = residency_info_mem.gaddr.address;

	return 0;
}

__attribute__((used)) static void lpit_update_residency(struct lpit_residency_info *info,
				 struct acpi_lpit_native *lpit_native)
{
	info->frequency = lpit_native->counter_frequency ?
				lpit_native->counter_frequency : tsc_khz * 1000;
	if (!info->frequency)
		info->frequency = 1;

	info->gaddr = lpit_native->residency_counter;
	if (info->gaddr.space_id == ACPI_ADR_SPACE_SYSTEM_MEMORY) {
		info->iomem_addr = ioremap_nocache(info->gaddr.address,
						   info->gaddr.bit_width / 8);
		if (!info->iomem_addr)
			return;

		if (!(acpi_gbl_FADT.flags & ACPI_FADT_LOW_POWER_S0))
			return;

		/* Silently fail, if cpuidle attribute group is not present */
		sysfs_add_file_to_group(&cpu_subsys.dev_root->kobj,
					&dev_attr_low_power_idle_system_residency_us.attr,
					"cpuidle");
	} else if (info->gaddr.space_id == ACPI_ADR_SPACE_FIXED_HARDWARE) {
		if (!(acpi_gbl_FADT.flags & ACPI_FADT_LOW_POWER_S0))
			return;

		/* Silently fail, if cpuidle attribute group is not present */
		sysfs_add_file_to_group(&cpu_subsys.dev_root->kobj,
					&dev_attr_low_power_idle_cpu_residency_us.attr,
					"cpuidle");
	}
}

__attribute__((used)) static void lpit_process(u64 begin, u64 end)
{
	while (begin + sizeof(struct acpi_lpit_native) < end) {
		struct acpi_lpit_native *lpit_native = (struct acpi_lpit_native *)begin;

		if (!lpit_native->header.type && !lpit_native->header.flags) {
			if (lpit_native->residency_counter.space_id == ACPI_ADR_SPACE_SYSTEM_MEMORY &&
			    !residency_info_mem.gaddr.address) {
				lpit_update_residency(&residency_info_mem, lpit_native);
			} else if (lpit_native->residency_counter.space_id == ACPI_ADR_SPACE_FIXED_HARDWARE &&
				   !residency_info_ffh.gaddr.address) {
				lpit_update_residency(&residency_info_ffh, lpit_native);
			}
		}
		begin += lpit_native->header.length;
	}
}

void acpi_init_lpit(void)
{
	acpi_status status;
	u64 lpit_begin;
	struct acpi_table_lpit *lpit;

	status = acpi_get_table(ACPI_SIG_LPIT, 0, (struct acpi_table_header **)&lpit);

	if (ACPI_FAILURE(status))
		return;

	lpit_begin = (u64)lpit + sizeof(*lpit);
	lpit_process(lpit_begin, lpit_begin + lpit->header.length);
}

