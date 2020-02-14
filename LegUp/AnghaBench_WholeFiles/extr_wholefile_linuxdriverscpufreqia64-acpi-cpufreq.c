#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u64 ;
typedef  unsigned int u32 ;
struct TYPE_8__ {int transition_latency; } ;
struct cpufreq_policy {unsigned int cpu; struct cpufreq_frequency_table* freq_table; TYPE_3__ cpuinfo; } ;
struct TYPE_7__ {scalar_t__ space_id; } ;
struct TYPE_6__ {scalar_t__ space_id; } ;
struct TYPE_10__ {unsigned long state_count; int state; TYPE_4__* states; TYPE_2__ status_register; TYPE_1__ control_register; } ;
struct cpufreq_frequency_table {int resume; int frequency; TYPE_5__ acpi_data; } ;
struct cpufreq_acpi_req {unsigned int cpu; int state; } ;
struct cpufreq_acpi_io {int resume; int frequency; TYPE_5__ acpi_data; } ;
typedef  scalar_t__ s64 ;
struct TYPE_9__ {unsigned int status; int core_frequency; int transition_latency; scalar_t__ control; scalar_t__ bus_master_latency; scalar_t__ power; } ;

/* Variables and functions */
 scalar_t__ ACPI_ADR_SPACE_FIXED_HARDWARE ; 
 int CPUFREQ_TABLE_END ; 
 long EAGAIN ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  PAL_GET_PSTATE_TYPE_INSTANT ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 struct cpufreq_frequency_table** acpi_io_data ; 
 int /*<<< orphan*/  acpi_processor_notify_smm (int /*<<< orphan*/ ) ; 
 unsigned int acpi_processor_register_performance (TYPE_5__*,unsigned int) ; 
 int /*<<< orphan*/  acpi_processor_unregister_performance (unsigned int) ; 
 scalar_t__ ia64_pal_get_pstate (scalar_t__*,int /*<<< orphan*/ ) ; 
 scalar_t__ ia64_pal_set_pstate (scalar_t__) ; 
 struct cpufreq_frequency_table* kcalloc (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct cpufreq_frequency_table*) ; 
 struct cpufreq_frequency_table* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_debug (char*,...) ; 
 int /*<<< orphan*/  pr_info (char*,unsigned int) ; 
 int /*<<< orphan*/  pr_warn (char*,int) ; 
 unsigned int smp_processor_id () ; 
 scalar_t__ unlikely (int) ; 
 int work_on_cpu (unsigned int,long (*) (void*),struct cpufreq_acpi_req*) ; 

__attribute__((used)) static int
processor_set_pstate (
	u32	value)
{
	s64 retval;

	pr_debug("processor_set_pstate\n");

	retval = ia64_pal_set_pstate((u64)value);

	if (retval) {
		pr_debug("Failed to set freq to 0x%x, with error 0x%lx\n",
		        value, retval);
		return -ENODEV;
	}
	return (int)retval;
}

__attribute__((used)) static int
processor_get_pstate (
	u32	*value)
{
	u64	pstate_index = 0;
	s64 	retval;

	pr_debug("processor_get_pstate\n");

	retval = ia64_pal_get_pstate(&pstate_index,
	                             PAL_GET_PSTATE_TYPE_INSTANT);
	*value = (u32) pstate_index;

	if (retval)
		pr_debug("Failed to get current freq with "
			"error 0x%lx, idx 0x%x\n", retval, *value);

	return (int)retval;
}

__attribute__((used)) static unsigned
extract_clock (
	struct cpufreq_acpi_io *data,
	unsigned value)
{
	unsigned long i;

	pr_debug("extract_clock\n");

	for (i = 0; i < data->acpi_data.state_count; i++) {
		if (value == data->acpi_data.states[i].status)
			return data->acpi_data.states[i].core_frequency;
	}
	return data->acpi_data.states[i-1].core_frequency;
}

__attribute__((used)) static long
processor_get_freq (
	void *arg)
{
	struct cpufreq_acpi_req *req = arg;
	unsigned int		cpu = req->cpu;
	struct cpufreq_acpi_io	*data = acpi_io_data[cpu];
	u32			value;
	int			ret;

	pr_debug("processor_get_freq\n");
	if (smp_processor_id() != cpu)
		return -EAGAIN;

	/* processor_get_pstate gets the instantaneous frequency */
	ret = processor_get_pstate(&value);
	if (ret) {
		pr_warn("get performance failed with error %d\n", ret);
		return ret;
	}
	return 1000 * extract_clock(data, value);
}

__attribute__((used)) static long
processor_set_freq (
	void *arg)
{
	struct cpufreq_acpi_req *req = arg;
	unsigned int		cpu = req->cpu;
	struct cpufreq_acpi_io	*data = acpi_io_data[cpu];
	int			ret, state = req->state;
	u32			value;

	pr_debug("processor_set_freq\n");
	if (smp_processor_id() != cpu)
		return -EAGAIN;

	if (state == data->acpi_data.state) {
		if (unlikely(data->resume)) {
			pr_debug("Called after resume, resetting to P%d\n", state);
			data->resume = 0;
		} else {
			pr_debug("Already at target state (P%d)\n", state);
			return 0;
		}
	}

	pr_debug("Transitioning from P%d to P%d\n",
		data->acpi_data.state, state);

	/*
	 * First we write the target state's 'control' value to the
	 * control_register.
	 */
	value = (u32) data->acpi_data.states[state].control;

	pr_debug("Transitioning to state: 0x%08x\n", value);

	ret = processor_set_pstate(value);
	if (ret) {
		pr_warn("Transition failed with error %d\n", ret);
		return -ENODEV;
	}

	data->acpi_data.state = state;
	return 0;
}

__attribute__((used)) static unsigned int
acpi_cpufreq_get (
	unsigned int		cpu)
{
	struct cpufreq_acpi_req req;
	long ret;

	req.cpu = cpu;
	ret = work_on_cpu(cpu, processor_get_freq, &req);

	return ret > 0 ? (unsigned int) ret : 0;
}

__attribute__((used)) static int
acpi_cpufreq_target (
	struct cpufreq_policy   *policy,
	unsigned int index)
{
	struct cpufreq_acpi_req req;

	req.cpu = policy->cpu;
	req.state = index;

	return work_on_cpu(req.cpu, processor_set_freq, &req);
}

__attribute__((used)) static int
acpi_cpufreq_cpu_init (
	struct cpufreq_policy   *policy)
{
	unsigned int		i;
	unsigned int		cpu = policy->cpu;
	struct cpufreq_acpi_io	*data;
	unsigned int		result = 0;
	struct cpufreq_frequency_table *freq_table;

	pr_debug("acpi_cpufreq_cpu_init\n");

	data = kzalloc(sizeof(*data), GFP_KERNEL);
	if (!data)
		return (-ENOMEM);

	acpi_io_data[cpu] = data;

	result = acpi_processor_register_performance(&data->acpi_data, cpu);

	if (result)
		goto err_free;

	/* capability check */
	if (data->acpi_data.state_count <= 1) {
		pr_debug("No P-States\n");
		result = -ENODEV;
		goto err_unreg;
	}

	if ((data->acpi_data.control_register.space_id !=
					ACPI_ADR_SPACE_FIXED_HARDWARE) ||
	    (data->acpi_data.status_register.space_id !=
					ACPI_ADR_SPACE_FIXED_HARDWARE)) {
		pr_debug("Unsupported address space [%d, %d]\n",
			(u32) (data->acpi_data.control_register.space_id),
			(u32) (data->acpi_data.status_register.space_id));
		result = -ENODEV;
		goto err_unreg;
	}

	/* alloc freq_table */
	freq_table = kcalloc(data->acpi_data.state_count + 1,
	                           sizeof(*freq_table),
	                           GFP_KERNEL);
	if (!freq_table) {
		result = -ENOMEM;
		goto err_unreg;
	}

	/* detect transition latency */
	policy->cpuinfo.transition_latency = 0;
	for (i=0; i<data->acpi_data.state_count; i++) {
		if ((data->acpi_data.states[i].transition_latency * 1000) >
		    policy->cpuinfo.transition_latency) {
			policy->cpuinfo.transition_latency =
			    data->acpi_data.states[i].transition_latency * 1000;
		}
	}

	/* table init */
	for (i = 0; i <= data->acpi_data.state_count; i++)
	{
		if (i < data->acpi_data.state_count) {
			freq_table[i].frequency =
			      data->acpi_data.states[i].core_frequency * 1000;
		} else {
			freq_table[i].frequency = CPUFREQ_TABLE_END;
		}
	}

	policy->freq_table = freq_table;

	/* notify BIOS that we exist */
	acpi_processor_notify_smm(THIS_MODULE);

	pr_info("CPU%u - ACPI performance management activated\n", cpu);

	for (i = 0; i < data->acpi_data.state_count; i++)
		pr_debug("     %cP%d: %d MHz, %d mW, %d uS, %d uS, 0x%x 0x%x\n",
			(i == data->acpi_data.state?'*':' '), i,
			(u32) data->acpi_data.states[i].core_frequency,
			(u32) data->acpi_data.states[i].power,
			(u32) data->acpi_data.states[i].transition_latency,
			(u32) data->acpi_data.states[i].bus_master_latency,
			(u32) data->acpi_data.states[i].status,
			(u32) data->acpi_data.states[i].control);

	/* the first call to ->target() should result in us actually
	 * writing something to the appropriate registers. */
	data->resume = 1;

	return (result);

 err_unreg:
	acpi_processor_unregister_performance(cpu);
 err_free:
	kfree(data);
	acpi_io_data[cpu] = NULL;

	return (result);
}

__attribute__((used)) static int
acpi_cpufreq_cpu_exit (
	struct cpufreq_policy   *policy)
{
	struct cpufreq_acpi_io *data = acpi_io_data[policy->cpu];

	pr_debug("acpi_cpufreq_cpu_exit\n");

	if (data) {
		acpi_io_data[policy->cpu] = NULL;
		acpi_processor_unregister_performance(policy->cpu);
		kfree(policy->freq_table);
		kfree(data);
	}

	return (0);
}

