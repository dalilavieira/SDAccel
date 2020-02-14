#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint64_t ;
typedef  scalar_t__ uint32_t ;
typedef  TYPE_1__* thread_t ;
typedef  int /*<<< orphan*/  thread_continue_t ;
typedef  scalar_t__ task_t ;
struct kperf_sample {int dummy; } ;
typedef  int pid_t ;
typedef  int /*<<< orphan*/  mach_port_name_t ;
typedef  int /*<<< orphan*/  lck_grp_attr_t ;
typedef  int boolean_t ;
struct TYPE_13__ {unsigned int logical_cpu_max; } ;
struct TYPE_12__ {scalar_t__ c_switch; scalar_t__ kperf_c_switch; scalar_t__ kperf_flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUF_DATA (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int ECANCELED ; 
 int ENOMEM ; 
 scalar_t__ FALSE ; 
 unsigned int KPERF_SAMPLING_OFF ; 
 unsigned int KPERF_SAMPLING_ON ; 
 unsigned int KPERF_SAMPLING_SHUTDOWN ; 
 int /*<<< orphan*/  KTRACE_KPERF ; 
 int /*<<< orphan*/  MACH_PORT_VALID (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PERF_TI_CSWITCH ; 
 scalar_t__ TASK_NULL ; 
 scalar_t__ TRUE ; 
 int /*<<< orphan*/  VM_KERN_MEMORY_DIAG ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  bzero (struct kperf_sample*,unsigned int) ; 
 unsigned int cpu_number () ; 
 scalar_t__ get_threadtask (TYPE_1__*) ; 
 unsigned int intr_samplec ; 
 struct kperf_sample* intr_samplev ; 
 struct kperf_sample* kalloc_tag (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct kperf_sample*,unsigned int) ; 
 scalar_t__ kperf_action_get_count () ; 
 int /*<<< orphan*/  kperf_action_reset () ; 
 int /*<<< orphan*/  kperf_action_set_count (int) ; 
 int /*<<< orphan*/  kperf_action_set_samplers (int,scalar_t__) ; 
 scalar_t__ kperf_initted ; 
 int /*<<< orphan*/  kperf_kdbg_cswitch_set (int /*<<< orphan*/ ) ; 
 scalar_t__ kperf_kdebug_cswitch ; 
 int kperf_kdebug_init () ; 
 int /*<<< orphan*/  kperf_kdebug_reset () ; 
 int /*<<< orphan*/  kperf_lazy_reset () ; 
 scalar_t__ kperf_lazy_wait_action ; 
 int /*<<< orphan*/  kperf_lazy_wait_sample (TYPE_1__*,int /*<<< orphan*/ ,uintptr_t*) ; 
 int /*<<< orphan*/  kperf_lck_grp ; 
 scalar_t__ kperf_lightweight_pet_active ; 
 int /*<<< orphan*/  kperf_lightweight_pet_active_update () ; 
 int kperf_on_cpu_active ; 
 int /*<<< orphan*/  kperf_pet_on_cpu (TYPE_1__*,int /*<<< orphan*/ ,uintptr_t*) ; 
 int kperf_sampling_disable () ; 
 int kperf_sampling_enable () ; 
 int /*<<< orphan*/  kperf_set_lightweight_pet (int) ; 
 struct kperf_sample* kperf_tid_on_cpus ; 
 int /*<<< orphan*/  kperf_timer_go () ; 
 int /*<<< orphan*/  kperf_timer_reset () ; 
 int /*<<< orphan*/  kperf_timer_set_action (int,int) ; 
 int /*<<< orphan*/  kperf_timer_set_count (int) ; 
 int /*<<< orphan*/  kperf_timer_set_period (int,scalar_t__) ; 
 int /*<<< orphan*/  kperf_timer_set_petid (int) ; 
 int /*<<< orphan*/  kperf_timer_stop () ; 
 int /*<<< orphan*/  kprintf (char*,...) ; 
 int /*<<< orphan*/  ktrace_end_single_threaded () ; 
 int /*<<< orphan*/  ktrace_kernel_configure (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ktrace_start_single_threaded () ; 
 int /*<<< orphan*/  lck_grp_attr_setdefault (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lck_grp_init (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *) ; 
 TYPE_3__ machine_info ; 
 scalar_t__ ml_get_interrupts_enabled () ; 
 int /*<<< orphan*/  nanoseconds_to_absolutetime (scalar_t__,scalar_t__*) ; 
 int /*<<< orphan*/  panic (char*,unsigned int) ; 
 scalar_t__ port_name_to_task (int /*<<< orphan*/ ) ; 
 unsigned int sampling_status ; 
 scalar_t__ strtouq (char const*,char**,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  task_deallocate_internal (scalar_t__) ; 
 int task_pid (scalar_t__) ; 
 int /*<<< orphan*/  thread_tid (TYPE_1__*) ; 

struct kperf_sample *
kperf_intr_sample_buffer(void)
{
	unsigned ncpu = cpu_number();

	assert(ml_get_interrupts_enabled() == FALSE);
	assert(ncpu < intr_samplec);

	return &(intr_samplev[ncpu]);
}

int
kperf_init(void)
{
	static lck_grp_attr_t lck_grp_attr;

	unsigned ncpus = 0;
	int err;

	if (kperf_initted) {
		return 0;
	}

	lck_grp_attr_setdefault(&lck_grp_attr);
	lck_grp_init(&kperf_lck_grp, "kperf", &lck_grp_attr);

	ncpus = machine_info.logical_cpu_max;

	/* create buffers to remember which threads don't need to be sampled by PET */
	kperf_tid_on_cpus = kalloc_tag(ncpus * sizeof(*kperf_tid_on_cpus),
	                                  VM_KERN_MEMORY_DIAG);
	if (kperf_tid_on_cpus == NULL) {
		err = ENOMEM;
		goto error;
	}
	bzero(kperf_tid_on_cpus, ncpus * sizeof(*kperf_tid_on_cpus));

	/* create the interrupt buffers */
	intr_samplec = ncpus;
	intr_samplev = kalloc_tag(ncpus * sizeof(*intr_samplev),
	                          VM_KERN_MEMORY_DIAG);
	if (intr_samplev == NULL) {
		err = ENOMEM;
		goto error;
	}
	bzero(intr_samplev, ncpus * sizeof(*intr_samplev));

	/* create kdebug trigger filter buffers */
	if ((err = kperf_kdebug_init())) {
		goto error;
	}

	kperf_initted = TRUE;
	return 0;

error:
	if (intr_samplev) {
		kfree(intr_samplev, ncpus * sizeof(*intr_samplev));
		intr_samplev = NULL;
		intr_samplec = 0;
	}

	if (kperf_tid_on_cpus) {
		kfree(kperf_tid_on_cpus, ncpus * sizeof(*kperf_tid_on_cpus));
		kperf_tid_on_cpus = NULL;
	}

	return err;
}

void
kperf_reset(void)
{
	/* turn off sampling first */
	(void)kperf_sampling_disable();

	/* cleanup miscellaneous configuration first */
	kperf_lazy_reset();
	(void)kperf_kdbg_cswitch_set(0);
	(void)kperf_set_lightweight_pet(0);
	kperf_kdebug_reset();

	/* timers, which require actions, first */
	kperf_timer_reset();
	kperf_action_reset();
}

void
kperf_kernel_configure(const char *config)
{
	int pairs = 0;
	char *end;
	bool pet = false;

	assert(config != NULL);

	ktrace_start_single_threaded();

	ktrace_kernel_configure(KTRACE_KPERF);

	if (config[0] == 'p') {
		pet = true;
		config++;
	}

	do {
		uint32_t action_samplers;
		uint64_t timer_period_ns;
		uint64_t timer_period;

		pairs += 1;
		kperf_action_set_count(pairs);
		kperf_timer_set_count(pairs);

		action_samplers = (uint32_t)strtouq(config, &end, 0);
		if (config == end) {
			kprintf("kperf: unable to parse '%s' as action sampler\n", config);
			goto out;
		}
		config = end;

		kperf_action_set_samplers(pairs, action_samplers);

		if (config[0] == '\0') {
			kprintf("kperf: missing timer period in config\n");
			goto out;
		}
		config++;

		timer_period_ns = strtouq(config, &end, 0);
		if (config == end) {
			kprintf("kperf: unable to parse '%s' as timer period\n", config);
			goto out;
		}
		nanoseconds_to_absolutetime(timer_period_ns, &timer_period);
		config = end;

		kperf_timer_set_period(pairs - 1, timer_period);
		kperf_timer_set_action(pairs - 1, pairs);

		if (pet) {
			kperf_timer_set_petid(pairs - 1);
			kperf_set_lightweight_pet(1);
			pet = false;
		}
	} while (*(config++) == ',');

	int error = kperf_sampling_enable();
	if (error) {
		kprintf("kperf: cannot enable sampling at boot: %d", error);
	}

out:
	ktrace_end_single_threaded();
}

void
kperf_on_cpu_internal(thread_t thread, thread_continue_t continuation,
                      uintptr_t *starting_fp)
{
	if (kperf_kdebug_cswitch) {
		/* trace the new thread's PID for Instruments */
		int pid = task_pid(get_threadtask(thread));
		BUF_DATA(PERF_TI_CSWITCH, thread_tid(thread), pid);
	}
	if (kperf_lightweight_pet_active) {
		kperf_pet_on_cpu(thread, continuation, starting_fp);
	}
	if (kperf_lazy_wait_action != 0) {
		kperf_lazy_wait_sample(thread, continuation, starting_fp);
	}
}

void
kperf_on_cpu_update(void)
{
	kperf_on_cpu_active = kperf_kdebug_cswitch ||
	                      kperf_lightweight_pet_active ||
	                      kperf_lazy_wait_action != 0;
}

uint32_t
kperf_get_thread_flags(thread_t thread)
{
	return thread->kperf_flags;
}

void
kperf_set_thread_flags(thread_t thread, uint32_t flags)
{
	thread->kperf_flags = flags;
}

unsigned int
kperf_sampling_status(void)
{
	return sampling_status;
}

int
kperf_sampling_enable(void)
{
	if (sampling_status == KPERF_SAMPLING_ON) {
		return 0;
	}

	if (sampling_status != KPERF_SAMPLING_OFF) {
		panic("kperf: sampling was %d when asked to enable", sampling_status);
	}

	/* make sure interrupt tables and actions are initted */
	if (!kperf_initted || (kperf_action_get_count() == 0)) {
		return ECANCELED;
	}

	/* mark as running */
	sampling_status = KPERF_SAMPLING_ON;
	kperf_lightweight_pet_active_update();

	/* tell timers to enable */
	kperf_timer_go();

	return 0;
}

int
kperf_sampling_disable(void)
{
	if (sampling_status != KPERF_SAMPLING_ON) {
		return 0;
	}

	/* mark a shutting down */
	sampling_status = KPERF_SAMPLING_SHUTDOWN;

	/* tell timers to disable */
	kperf_timer_stop();

	/* mark as off */
	sampling_status = KPERF_SAMPLING_OFF;
	kperf_lightweight_pet_active_update();

	return 0;
}

boolean_t
kperf_thread_get_dirty(thread_t thread)
{
	return (thread->c_switch != thread->kperf_c_switch);
}

void
kperf_thread_set_dirty(thread_t thread, boolean_t dirty)
{
	if (dirty) {
		thread->kperf_c_switch = thread->c_switch - 1;
	} else {
		thread->kperf_c_switch = thread->c_switch;
	}
}

int
kperf_port_to_pid(mach_port_name_t portname)
{
	if (!MACH_PORT_VALID(portname)) {
		return -1;
	}

	task_t task = port_name_to_task(portname);
	if (task == TASK_NULL) {
		return -1;
	}
	pid_t pid = task_pid(task);
	/* drop the ref taken by port_name_to_task */
	task_deallocate_internal(task);

	return pid;
}

