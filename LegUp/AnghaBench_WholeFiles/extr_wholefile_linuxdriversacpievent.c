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
typedef  int /*<<< orphan*/  u8 ;
typedef  void* u32 ;
struct notifier_block {int dummy; } ;
struct acpi_pci_root {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  bus_id; int /*<<< orphan*/  device_class; } ;
struct acpi_device {TYPE_1__ pnp; } ;
struct acpi_bus_event {void* data; void* type; int /*<<< orphan*/  bus_id; int /*<<< orphan*/  device_class; } ;
typedef  int /*<<< orphan*/  acpi_handle ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENXIO ; 
 scalar_t__ NOTIFY_BAD ; 
 int /*<<< orphan*/  acpi_chain_head ; 
 scalar_t__ blocking_notifier_call_chain (int /*<<< orphan*/ *,int /*<<< orphan*/ ,void*) ; 
 int blocking_notifier_chain_register (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int blocking_notifier_chain_unregister (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int /*<<< orphan*/  strcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void acpi_amba_init(void) {}

__attribute__((used)) static inline void pci_ioapic_remove(struct acpi_pci_root *root) { return; }

__attribute__((used)) static inline int acpi_ioapic_remove(struct acpi_pci_root *root) { return 0; }

__attribute__((used)) static inline void register_dock_dependent_device(struct acpi_device *adev,
						  acpi_handle dshandle) {}

__attribute__((used)) static inline int dock_notify(struct acpi_device *adev, u32 event) { return -ENODEV; }

__attribute__((used)) static inline void acpi_dock_add(struct acpi_device *adev) {}

__attribute__((used)) static inline void acpi_cmos_rtc_init(void) {}

__attribute__((used)) static inline void acpi_debugfs_init(void) { return; }

__attribute__((used)) static inline void acpi_early_processor_set_pdc(void) {}

__attribute__((used)) static inline void acpi_early_processor_osc(void) {}

__attribute__((used)) static inline bool acpi_s2idle_wakeup(void) { return false; }

__attribute__((used)) static inline bool acpi_sleep_no_ec_events(void) { return true; }

__attribute__((used)) static inline int acpi_sleep_init(void) { return -ENXIO; }

__attribute__((used)) static inline void acpi_sleep_proc_init(void) {}

__attribute__((used)) static inline int suspend_nvs_alloc(void) { return 0; }

__attribute__((used)) static inline void suspend_nvs_free(void) {}

__attribute__((used)) static inline int suspend_nvs_save(void) { return 0; }

__attribute__((used)) static inline void suspend_nvs_restore(void) {}

__attribute__((used)) static inline void acpi_extract_apple_properties(struct acpi_device *adev) {}

__attribute__((used)) static inline void acpi_watchdog_init(void) {}

__attribute__((used)) static inline void acpi_init_lpit(void) { }

int acpi_notifier_call_chain(struct acpi_device *dev, u32 type, u32 data)
{
	struct acpi_bus_event event;

	strcpy(event.device_class, dev->pnp.device_class);
	strcpy(event.bus_id, dev->pnp.bus_id);
	event.type = type;
	event.data = data;
	return (blocking_notifier_call_chain(&acpi_chain_head, 0, (void *)&event)
                        == NOTIFY_BAD) ? -EINVAL : 0;
}

int register_acpi_notifier(struct notifier_block *nb)
{
	return blocking_notifier_chain_register(&acpi_chain_head, nb);
}

int unregister_acpi_notifier(struct notifier_block *nb)
{
	return blocking_notifier_chain_unregister(&acpi_chain_head, nb);
}

int acpi_bus_generate_netlink_event(const char *device_class,
				      const char *bus_id,
				      u8 type, int data)
{
	return 0;
}

__attribute__((used)) static int acpi_event_genetlink_init(void)
{
	return -ENODEV;
}

