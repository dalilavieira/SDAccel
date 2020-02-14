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
typedef  int /*<<< orphan*/  u32 ;
struct acpi_table_wdat {int dummy; } ;
struct acpi_table_header {int dummy; } ;
struct acpi_pci_root {int dummy; } ;
struct acpi_device {int dummy; } ;
typedef  int /*<<< orphan*/  acpi_status ;
typedef  int /*<<< orphan*/  acpi_handle ;

/* Variables and functions */
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_SIG_WDAT ; 
 int ENODEV ; 
 int ENXIO ; 
 scalar_t__ acpi_disabled ; 
 int /*<<< orphan*/  acpi_get_table (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct acpi_table_header**) ; 
 int /*<<< orphan*/  pr_info (char*) ; 

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

__attribute__((used)) static bool acpi_watchdog_uses_rtc(const struct acpi_table_wdat *wdat)
{
	return false;
}

__attribute__((used)) static const struct acpi_table_wdat *acpi_watchdog_get_wdat(void)
{
	const struct acpi_table_wdat *wdat = NULL;
	acpi_status status;

	if (acpi_disabled)
		return NULL;

	status = acpi_get_table(ACPI_SIG_WDAT, 0,
				(struct acpi_table_header **)&wdat);
	if (ACPI_FAILURE(status)) {
		/* It is fine if there is no WDAT */
		return NULL;
	}

	if (acpi_watchdog_uses_rtc(wdat)) {
		pr_info("Skipping WDAT on this system because it uses RTC SRAM\n");
		return NULL;
	}

	return wdat;
}

bool acpi_has_watchdog(void)
{
	return !!acpi_watchdog_get_wdat();
}

