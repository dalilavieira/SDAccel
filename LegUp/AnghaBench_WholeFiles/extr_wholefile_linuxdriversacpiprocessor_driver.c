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
typedef  int u32 ;
struct device {int dummy; } ;
struct TYPE_4__ {scalar_t__ need_hotplug_init; } ;
struct acpi_processor {int performance_platform_limit; TYPE_2__ flags; int /*<<< orphan*/  handle; int /*<<< orphan*/  id; } ;
struct acpi_pci_root {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/  device_class; } ;
struct acpi_device {scalar_t__ handle; int /*<<< orphan*/  dev; TYPE_1__ pnp; } ;
typedef  int /*<<< orphan*/  acpi_status ;
typedef  scalar_t__ acpi_handle ;

/* Variables and functions */
 struct acpi_device* ACPI_COMPANION (struct device*) ; 
 int /*<<< orphan*/  ACPI_DB_INFO ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_DEVICE_NOTIFY ; 
#define  ACPI_PROCESSOR_NOTIFY_PERFORMANCE 130 
#define  ACPI_PROCESSOR_NOTIFY_POWER 129 
#define  ACPI_PROCESSOR_NOTIFY_THROTTLING 128 
 scalar_t__ ACPI_SUCCESS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CONFIG_ACPI_CPU_FREQ_PSS ; 
 int ENODEV ; 
 int ENXIO ; 
 int /*<<< orphan*/  IS_ENABLED (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WARN (int,char*,int /*<<< orphan*/ ) ; 
static  int __acpi_processor_start (struct acpi_device*) ; 
 int /*<<< orphan*/  acpi_bus_generate_netlink_event (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 scalar_t__ acpi_bus_get_device (int /*<<< orphan*/ ,struct acpi_device**) ; 
 int /*<<< orphan*/  acpi_cppc_processor_exit (struct acpi_processor*) ; 
 int acpi_cppc_processor_probe (struct acpi_processor*) ; 
 struct acpi_processor* acpi_driver_data (struct acpi_device*) ; 
 int /*<<< orphan*/  acpi_idle_driver ; 
 int /*<<< orphan*/  acpi_install_notify_handler (scalar_t__,int /*<<< orphan*/ ,void (*) (scalar_t__,int,void*),struct acpi_device*) ; 
 int /*<<< orphan*/  acpi_processor_hotplug (struct acpi_processor*) ; 
 int /*<<< orphan*/  acpi_processor_power_exit (struct acpi_processor*) ; 
 int /*<<< orphan*/  acpi_processor_power_init (struct acpi_processor*) ; 
 int /*<<< orphan*/  acpi_processor_power_state_has_changed (struct acpi_processor*) ; 
 int /*<<< orphan*/  acpi_processor_ppc_has_changed (struct acpi_processor*,int) ; 
 int /*<<< orphan*/  acpi_processor_reevaluate_tstate (struct acpi_processor*,int) ; 
 int /*<<< orphan*/  acpi_processor_tstate_has_changed (struct acpi_processor*) ; 
 int /*<<< orphan*/  acpi_remove_notify_handler (scalar_t__,int /*<<< orphan*/ ,void (*) (scalar_t__,int,void*)) ; 
 int /*<<< orphan*/  cpu_hotplug_disable () ; 
 int /*<<< orphan*/  cpu_hotplug_enable () ; 
 int /*<<< orphan*/ * cpuidle_get_driver () ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_name (int /*<<< orphan*/ *) ; 
 struct acpi_processor* per_cpu (int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  pr_info (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  processors ; 

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

__attribute__((used)) static void acpi_processor_notify(acpi_handle handle, u32 event, void *data)
{
	struct acpi_device *device = data;
	struct acpi_processor *pr;
	int saved;

	if (device->handle != handle)
		return;

	pr = acpi_driver_data(device);
	if (!pr)
		return;

	switch (event) {
	case ACPI_PROCESSOR_NOTIFY_PERFORMANCE:
		saved = pr->performance_platform_limit;
		acpi_processor_ppc_has_changed(pr, 1);
		if (saved == pr->performance_platform_limit)
			break;
		acpi_bus_generate_netlink_event(device->pnp.device_class,
						  dev_name(&device->dev), event,
						  pr->performance_platform_limit);
		break;
	case ACPI_PROCESSOR_NOTIFY_POWER:
		acpi_processor_power_state_has_changed(pr);
		acpi_bus_generate_netlink_event(device->pnp.device_class,
						  dev_name(&device->dev), event, 0);
		break;
	case ACPI_PROCESSOR_NOTIFY_THROTTLING:
		acpi_processor_tstate_has_changed(pr);
		acpi_bus_generate_netlink_event(device->pnp.device_class,
						  dev_name(&device->dev), event, 0);
		break;
	default:
		ACPI_DEBUG_PRINT((ACPI_DB_INFO,
				  "Unsupported event [0x%x]\n", event));
		break;
	}

	return;
}

__attribute__((used)) static int acpi_soft_cpu_online(unsigned int cpu)
{
	struct acpi_processor *pr = per_cpu(processors, cpu);
	struct acpi_device *device;

	if (!pr || acpi_bus_get_device(pr->handle, &device))
		return 0;
	/*
	 * CPU got physically hotplugged and onlined for the first time:
	 * Initialize missing things.
	 */
	if (pr->flags.need_hotplug_init) {
		int ret;

		pr_info("Will online and init hotplugged CPU: %d\n",
			pr->id);
		pr->flags.need_hotplug_init = 0;
		ret = __acpi_processor_start(device);
		WARN(ret, "Failed to start CPU: %d\n", pr->id);
	} else {
		/* Normal CPU soft online event. */
		acpi_processor_ppc_has_changed(pr, 0);
		acpi_processor_hotplug(pr);
		acpi_processor_reevaluate_tstate(pr, false);
		acpi_processor_tstate_has_changed(pr);
	}
	return 0;
}

__attribute__((used)) static int acpi_soft_cpu_dead(unsigned int cpu)
{
	struct acpi_processor *pr = per_cpu(processors, cpu);
	struct acpi_device *device;

	if (!pr || acpi_bus_get_device(pr->handle, &device))
		return 0;

	acpi_processor_reevaluate_tstate(pr, true);
	return 0;
}

__attribute__((used)) static inline int acpi_pss_perf_init(struct acpi_processor *pr,
		struct acpi_device *device)
{
	return 0;
}

__attribute__((used)) static inline void acpi_pss_perf_exit(struct acpi_processor *pr,
		struct acpi_device *device) {}

__attribute__((used)) static int __acpi_processor_start(struct acpi_device *device)
{
	struct acpi_processor *pr = acpi_driver_data(device);
	acpi_status status;
	int result = 0;

	if (!pr)
		return -ENODEV;

	if (pr->flags.need_hotplug_init)
		return 0;

	result = acpi_cppc_processor_probe(pr);
	if (result && !IS_ENABLED(CONFIG_ACPI_CPU_FREQ_PSS))
		dev_dbg(&device->dev, "CPPC data invalid or not present\n");

	if (!cpuidle_get_driver() || cpuidle_get_driver() == &acpi_idle_driver)
		acpi_processor_power_init(pr);

	result = acpi_pss_perf_init(pr, device);
	if (result)
		goto err_power_exit;

	status = acpi_install_notify_handler(device->handle, ACPI_DEVICE_NOTIFY,
					     acpi_processor_notify, device);
	if (ACPI_SUCCESS(status))
		return 0;

	result = -ENODEV;
	acpi_pss_perf_exit(pr, device);

err_power_exit:
	acpi_processor_power_exit(pr);
	return result;
}

__attribute__((used)) static int acpi_processor_start(struct device *dev)
{
	struct acpi_device *device = ACPI_COMPANION(dev);
	int ret;

	if (!device)
		return -ENODEV;

	/* Protect against concurrent CPU hotplug operations */
	cpu_hotplug_disable();
	ret = __acpi_processor_start(device);
	cpu_hotplug_enable();
	return ret;
}

__attribute__((used)) static int acpi_processor_stop(struct device *dev)
{
	struct acpi_device *device = ACPI_COMPANION(dev);
	struct acpi_processor *pr;

	if (!device)
		return 0;

	acpi_remove_notify_handler(device->handle, ACPI_DEVICE_NOTIFY,
				   acpi_processor_notify);

	pr = acpi_driver_data(device);
	if (!pr)
		return 0;
	acpi_processor_power_exit(pr);

	acpi_pss_perf_exit(pr, device);

	acpi_cppc_processor_exit(pr);

	return 0;
}

