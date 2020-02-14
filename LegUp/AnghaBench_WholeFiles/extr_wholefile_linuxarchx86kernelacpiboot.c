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
typedef  int /*<<< orphan*/  u64 ;
typedef  int u32 ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  acpi_handle ;

/* Variables and functions */
 int ENOSYS ; 
 scalar_t__ INVALID_ACPI_IRQ ; 
 int __acpi_register_gsi (struct device*,int,int,int) ; 
 int /*<<< orphan*/  __acpi_unregister_gsi (int) ; 
 unsigned int cmpxchg (unsigned int*,unsigned int,unsigned int) ; 
 scalar_t__* isa_irq_to_gsi ; 
 unsigned int nr_legacy_irqs () ; 
 scalar_t__ unlikely (int) ; 

int acpi_isa_irq_to_gsi(unsigned isa_irq, u32 *gsi)
{
	if (isa_irq < nr_legacy_irqs() &&
	    isa_irq_to_gsi[isa_irq] != INVALID_ACPI_IRQ) {
		*gsi = isa_irq_to_gsi[isa_irq];
		return 0;
	}

	return -1;
}

__attribute__((used)) static int acpi_register_gsi_pic(struct device *dev, u32 gsi,
				 int trigger, int polarity)
{
#ifdef CONFIG_PCI
	/*
	 * Make sure all (legacy) PCI IRQs are set as level-triggered.
	 */
	if (trigger == ACPI_LEVEL_SENSITIVE)
		elcr_set_level_irq(gsi);
#endif

	return gsi;
}

int acpi_register_gsi(struct device *dev, u32 gsi, int trigger, int polarity)
{
	return __acpi_register_gsi(dev, gsi, trigger, polarity);
}

void acpi_unregister_gsi(u32 gsi)
{
	if (__acpi_unregister_gsi)
		__acpi_unregister_gsi(gsi);
}

int acpi_register_ioapic(acpi_handle handle, u64 phys_addr, u32 gsi_base)
{
	int ret = -ENOSYS;
#ifdef CONFIG_ACPI_HOTPLUG_IOAPIC
	int ioapic_id;
	u64 addr;
	struct ioapic_domain_cfg cfg = {
		.type = IOAPIC_DOMAIN_DYNAMIC,
		.ops = &mp_ioapic_irqdomain_ops,
	};

	ioapic_id = acpi_get_ioapic_id(handle, gsi_base, &addr);
	if (ioapic_id < 0) {
		unsigned long long uid;
		acpi_status status;

		status = acpi_evaluate_integer(handle, METHOD_NAME__UID,
					       NULL, &uid);
		if (ACPI_FAILURE(status)) {
			acpi_handle_warn(handle, "failed to get IOAPIC ID.\n");
			return -EINVAL;
		}
		ioapic_id = (int)uid;
	}

	mutex_lock(&acpi_ioapic_lock);
	ret  = mp_register_ioapic(ioapic_id, phys_addr, gsi_base, &cfg);
	mutex_unlock(&acpi_ioapic_lock);
#endif

	return ret;
}

int acpi_unregister_ioapic(acpi_handle handle, u32 gsi_base)
{
	int ret = -ENOSYS;

#ifdef CONFIG_ACPI_HOTPLUG_IOAPIC
	mutex_lock(&acpi_ioapic_lock);
	ret  = mp_unregister_ioapic(gsi_base);
	mutex_unlock(&acpi_ioapic_lock);
#endif

	return ret;
}

int acpi_ioapic_registered(acpi_handle handle, u32 gsi_base)
{
	int ret = 0;

#ifdef CONFIG_ACPI_HOTPLUG_IOAPIC
	mutex_lock(&acpi_ioapic_lock);
	ret  = mp_ioapic_registered(gsi_base);
	mutex_unlock(&acpi_ioapic_lock);
#endif

	return ret;
}

int __acpi_acquire_global_lock(unsigned int *lock)
{
	unsigned int old, new, val;
	do {
		old = *lock;
		new = (((old & ~0x3) + 2) + ((old >> 1) & 0x1));
		val = cmpxchg(lock, old, new);
	} while (unlikely (val != old));
	return (new < 3) ? -1 : 0;
}

int __acpi_release_global_lock(unsigned int *lock)
{
	unsigned int old, new, val;
	do {
		old = *lock;
		new = old & ~0x3;
		val = cmpxchg(lock, old, new);
	} while (unlikely (val != old));
	return old & 0x1;
}

