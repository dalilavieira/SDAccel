#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct acpi_pci_root {int dummy; } ;
struct TYPE_6__ {int /*<<< orphan*/  unique_id; } ;
struct acpi_device {TYPE_1__ pnp; } ;
typedef  int /*<<< orphan*/  acpi_handle ;
struct TYPE_9__ {TYPE_3__* dmi_ids; int /*<<< orphan*/  cpu_ids; int /*<<< orphan*/  uid; int /*<<< orphan*/  hid; } ;
struct TYPE_8__ {TYPE_2__* matches; } ;
struct TYPE_7__ {scalar_t__ slot; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (TYPE_4__*) ; 
 int ENODEV ; 
 int ENXIO ; 
 scalar_t__ acpi_match_device_ids (struct acpi_device*,int /*<<< orphan*/ ) ; 
 TYPE_4__* always_present_ids ; 
 int /*<<< orphan*/  dmi_check_system (TYPE_3__*) ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  x86_match_cpu (int /*<<< orphan*/ ) ; 

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

bool acpi_device_always_present(struct acpi_device *adev)
{
	bool ret = false;
	unsigned int i;

	for (i = 0; i < ARRAY_SIZE(always_present_ids); i++) {
		if (acpi_match_device_ids(adev, always_present_ids[i].hid))
			continue;

		if (!adev->pnp.unique_id ||
		    strcmp(adev->pnp.unique_id, always_present_ids[i].uid))
			continue;

		if (!x86_match_cpu(always_present_ids[i].cpu_ids))
			continue;

		if (always_present_ids[i].dmi_ids[0].matches[0].slot &&
		    !dmi_check_system(always_present_ids[i].dmi_ids))
			continue;

		ret = true;
		break;
	}

	return ret;
}

