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
typedef  unsigned int u64 ;
typedef  int /*<<< orphan*/  suspend_state_t ;
struct platform_hibernation_ops {int (* begin ) () ;int (* pre_snapshot ) () ;int (* pre_restore ) () ;int /*<<< orphan*/  (* recover ) () ;int /*<<< orphan*/  (* restore_cleanup ) () ;int /*<<< orphan*/  (* finish ) () ;int /*<<< orphan*/  (* leave ) () ;int /*<<< orphan*/  (* end ) () ;scalar_t__ enter; scalar_t__ prepare; } ;
struct kobject {int dummy; } ;
struct kobj_attribute {int dummy; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  pm_message_t ;
typedef  int /*<<< orphan*/  ktime_t ;
typedef  char* dev_t ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int ENOSYS ; 
 int EPERM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HIBERNATION_FIRST ; 
 int HIBERNATION_INVALID ; 
 int HIBERNATION_MAX ; 
#define  HIBERNATION_PLATFORM 131 
#define  HIBERNATION_REBOOT 130 
#define  HIBERNATION_SHUTDOWN 129 
#define  HIBERNATION_TEST_RESUME 128 
 int MAJOR (char*) ; 
 int MINOR (char*) ; 
 int NSEC_PER_MSEC ; 
 int PAGE_SIZE ; 
 int /*<<< orphan*/  PMSG_FREEZE ; 
 int /*<<< orphan*/  PMSG_RECOVER ; 
 int /*<<< orphan*/  PMSG_RESTORE ; 
 int /*<<< orphan*/  PMSG_THAW ; 
 int /*<<< orphan*/  PM_EVENT_HIBERNATE ; 
 int /*<<< orphan*/  PM_SUSPEND_ON ; 
 int /*<<< orphan*/  SYSTEM_RUNNING ; 
 int /*<<< orphan*/  SYSTEM_SUSPEND ; 
 int TEST_CORE ; 
 int TEST_CPUS ; 
 int TEST_DEVICES ; 
 int TEST_FREEZER ; 
 int TEST_PLATFORM ; 
 int /*<<< orphan*/  TPS (char*) ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  clear_free_pages () ; 
 int disable_nonboot_cpus () ; 
 int /*<<< orphan*/  dpm_complete (int /*<<< orphan*/ ) ; 
 int dpm_prepare (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dpm_resume (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dpm_resume_start (int /*<<< orphan*/ ) ; 
 int dpm_suspend (int /*<<< orphan*/ ) ; 
 int dpm_suspend_end (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  enable_nonboot_cpus () ; 
 int entering_platform_hibernation ; 
 int events_check_enabled ; 
 int freeze_kernel_threads () ; 
 int freezer_test_done ; 
 int hibernate_preallocate_memory () ; 
 int hibernation_mode ; 
 char** hibernation_modes ; 
 struct platform_hibernation_ops const* hibernation_ops ; 
 unsigned long long image_size ; 
 int in_suspend ; 
 int /*<<< orphan*/  kfree (char*) ; 
 char* kstrndup (char const*,int,int /*<<< orphan*/ ) ; 
 int kstrtoull (char const*,int /*<<< orphan*/ ,unsigned long long*) ; 
 unsigned int ktime_divns (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ktime_sub (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  local_irq_disable () ; 
 int /*<<< orphan*/  local_irq_enable () ; 
 int /*<<< orphan*/  lock_system_sleep () ; 
 char* memchr (char const*,char,size_t) ; 
 char* name_to_dev_t (char*) ; 
 scalar_t__ nohibernate ; 
 scalar_t__ noresume ; 
 int /*<<< orphan*/  pm_pr_dbg (char*,char*) ; 
 int /*<<< orphan*/  pm_restore_gfp_mask () ; 
 int /*<<< orphan*/  pm_restrict_gfp_mask () ; 
 int /*<<< orphan*/  pm_suspend_clear_flags () ; 
 scalar_t__ pm_wakeup_pending () ; 
 int /*<<< orphan*/  pr_err (char*,...) ; 
 int /*<<< orphan*/  pr_info (char*,char*,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int) ; 
 unsigned long long reserved_size ; 
 int /*<<< orphan*/  restore_processor_state () ; 
 int /*<<< orphan*/  resume_console () ; 
 int /*<<< orphan*/  save_processor_state () ; 
 int /*<<< orphan*/  software_resume () ; 
 int sprintf (char*,char*,...) ; 
 int sscanf (char const*,char*,unsigned long*) ; 
 int strlen (char*) ; 
 int /*<<< orphan*/  strncmp (char const*,char*,int) ; 
 int stub1 () ; 
 int /*<<< orphan*/  stub2 () ; 
 int stub3 () ; 
 int /*<<< orphan*/  stub4 () ; 
 int /*<<< orphan*/  stub5 () ; 
 int stub6 () ; 
 int /*<<< orphan*/  stub7 () ; 
 int /*<<< orphan*/  stub8 () ; 
 int /*<<< orphan*/  suspend_console () ; 
 int swsusp_arch_suspend () ; 
 int /*<<< orphan*/  swsusp_free () ; 
 unsigned long long swsusp_resume_block ; 
 char* swsusp_resume_device ; 
 int /*<<< orphan*/  syscore_resume () ; 
 int syscore_suspend () ; 
 int /*<<< orphan*/  system_state ; 
 int /*<<< orphan*/  thaw_kernel_threads () ; 
 int /*<<< orphan*/  trace_suspend_resume (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  unlock_system_sleep () ; 

__attribute__((used)) static inline void hibernate_reserved_size_init(void) {}

__attribute__((used)) static inline void hibernate_image_size_init(void) {}

__attribute__((used)) static inline int suspend_devices_and_enter(suspend_state_t state)
{
	return -ENOSYS;
}

__attribute__((used)) static inline void suspend_test_start(void) {}

__attribute__((used)) static inline void suspend_test_finish(const char *label) {}

__attribute__((used)) static inline unsigned int count_highmem_pages(void) { return 0; }

__attribute__((used)) static inline int restore_highmem(void) { return 0; }

__attribute__((used)) static inline int suspend_freeze_processes(void)
{
	return 0;
}

__attribute__((used)) static inline void suspend_thaw_processes(void)
{
}

__attribute__((used)) static inline int pm_autosleep_init(void) { return 0; }

__attribute__((used)) static inline int pm_autosleep_lock(void) { return 0; }

__attribute__((used)) static inline void pm_autosleep_unlock(void) {}

__attribute__((used)) static inline suspend_state_t pm_autosleep_state(void) { return PM_SUSPEND_ON; }

bool hibernation_available(void)
{
	return (nohibernate == 0);
}

void hibernation_set_ops(const struct platform_hibernation_ops *ops)
{
	if (ops && !(ops->begin && ops->end &&  ops->pre_snapshot
	    && ops->prepare && ops->finish && ops->enter && ops->pre_restore
	    && ops->restore_cleanup && ops->leave)) {
		WARN_ON(1);
		return;
	}
	lock_system_sleep();
	hibernation_ops = ops;
	if (ops)
		hibernation_mode = HIBERNATION_PLATFORM;
	else if (hibernation_mode == HIBERNATION_PLATFORM)
		hibernation_mode = HIBERNATION_SHUTDOWN;

	unlock_system_sleep();
}

bool system_entering_hibernation(void)
{
	return entering_platform_hibernation;
}

__attribute__((used)) static int hibernation_test(int level) { return 0; }

__attribute__((used)) static int platform_begin(int platform_mode)
{
	return (platform_mode && hibernation_ops) ?
		hibernation_ops->begin() : 0;
}

__attribute__((used)) static void platform_end(int platform_mode)
{
	if (platform_mode && hibernation_ops)
		hibernation_ops->end();
}

__attribute__((used)) static int platform_pre_snapshot(int platform_mode)
{
	return (platform_mode && hibernation_ops) ?
		hibernation_ops->pre_snapshot() : 0;
}

__attribute__((used)) static void platform_leave(int platform_mode)
{
	if (platform_mode && hibernation_ops)
		hibernation_ops->leave();
}

__attribute__((used)) static void platform_finish(int platform_mode)
{
	if (platform_mode && hibernation_ops)
		hibernation_ops->finish();
}

__attribute__((used)) static int platform_pre_restore(int platform_mode)
{
	return (platform_mode && hibernation_ops) ?
		hibernation_ops->pre_restore() : 0;
}

__attribute__((used)) static void platform_restore_cleanup(int platform_mode)
{
	if (platform_mode && hibernation_ops)
		hibernation_ops->restore_cleanup();
}

__attribute__((used)) static void platform_recover(int platform_mode)
{
	if (platform_mode && hibernation_ops && hibernation_ops->recover)
		hibernation_ops->recover();
}

void swsusp_show_speed(ktime_t start, ktime_t stop,
		      unsigned nr_pages, char *msg)
{
	ktime_t diff;
	u64 elapsed_centisecs64;
	unsigned int centisecs;
	unsigned int k;
	unsigned int kps;

	diff = ktime_sub(stop, start);
	elapsed_centisecs64 = ktime_divns(diff, 10*NSEC_PER_MSEC);
	centisecs = elapsed_centisecs64;
	if (centisecs == 0)
		centisecs = 1;	/* avoid div-by-zero */
	k = nr_pages * (PAGE_SIZE / 1024);
	kps = (k * 100) / centisecs;
	pr_info("%s %u kbytes in %u.%02u seconds (%u.%02u MB/s)\n",
		msg, k, centisecs / 100, centisecs % 100, kps / 1000,
		(kps % 1000) / 10);
}

__attribute__((used)) static int create_image(int platform_mode)
{
	int error;

	error = dpm_suspend_end(PMSG_FREEZE);
	if (error) {
		pr_err("Some devices failed to power down, aborting hibernation\n");
		return error;
	}

	error = platform_pre_snapshot(platform_mode);
	if (error || hibernation_test(TEST_PLATFORM))
		goto Platform_finish;

	error = disable_nonboot_cpus();
	if (error || hibernation_test(TEST_CPUS))
		goto Enable_cpus;

	local_irq_disable();

	system_state = SYSTEM_SUSPEND;

	error = syscore_suspend();
	if (error) {
		pr_err("Some system devices failed to power down, aborting hibernation\n");
		goto Enable_irqs;
	}

	if (hibernation_test(TEST_CORE) || pm_wakeup_pending())
		goto Power_up;

	in_suspend = 1;
	save_processor_state();
	trace_suspend_resume(TPS("machine_suspend"), PM_EVENT_HIBERNATE, true);
	error = swsusp_arch_suspend();
	/* Restore control flow magically appears here */
	restore_processor_state();
	trace_suspend_resume(TPS("machine_suspend"), PM_EVENT_HIBERNATE, false);
	if (error)
		pr_err("Error %d creating hibernation image\n", error);

	if (!in_suspend) {
		events_check_enabled = false;
		clear_free_pages();
	}

	platform_leave(platform_mode);

 Power_up:
	syscore_resume();

 Enable_irqs:
	system_state = SYSTEM_RUNNING;
	local_irq_enable();

 Enable_cpus:
	enable_nonboot_cpus();

 Platform_finish:
	platform_finish(platform_mode);

	dpm_resume_start(in_suspend ?
		(error ? PMSG_RECOVER : PMSG_THAW) : PMSG_RESTORE);

	return error;
}

int hibernation_snapshot(int platform_mode)
{
	pm_message_t msg;
	int error;

	pm_suspend_clear_flags();
	error = platform_begin(platform_mode);
	if (error)
		goto Close;

	/* Preallocate image memory before shutting down devices. */
	error = hibernate_preallocate_memory();
	if (error)
		goto Close;

	error = freeze_kernel_threads();
	if (error)
		goto Cleanup;

	if (hibernation_test(TEST_FREEZER)) {

		/*
		 * Indicate to the caller that we are returning due to a
		 * successful freezer test.
		 */
		freezer_test_done = true;
		goto Thaw;
	}

	error = dpm_prepare(PMSG_FREEZE);
	if (error) {
		dpm_complete(PMSG_RECOVER);
		goto Thaw;
	}

	suspend_console();
	pm_restrict_gfp_mask();

	error = dpm_suspend(PMSG_FREEZE);

	if (error || hibernation_test(TEST_DEVICES))
		platform_recover(platform_mode);
	else
		error = create_image(platform_mode);

	/*
	 * In the case that we call create_image() above, the control
	 * returns here (1) after the image has been created or the
	 * image creation has failed and (2) after a successful restore.
	 */

	/* We may need to release the preallocated image pages here. */
	if (error || !in_suspend)
		swsusp_free();

	msg = in_suspend ? (error ? PMSG_RECOVER : PMSG_THAW) : PMSG_RESTORE;
	dpm_resume(msg);

	if (error || !in_suspend)
		pm_restore_gfp_mask();

	resume_console();
	dpm_complete(msg);

 Close:
	platform_end(platform_mode);
	return error;

 Thaw:
	thaw_kernel_threads();
 Cleanup:
	swsusp_free();
	goto Close;
}

__attribute__((used)) static ssize_t disk_show(struct kobject *kobj, struct kobj_attribute *attr,
			 char *buf)
{
	int i;
	char *start = buf;

	if (!hibernation_available())
		return sprintf(buf, "[disabled]\n");

	for (i = HIBERNATION_FIRST; i <= HIBERNATION_MAX; i++) {
		if (!hibernation_modes[i])
			continue;
		switch (i) {
		case HIBERNATION_SHUTDOWN:
		case HIBERNATION_REBOOT:
#ifdef CONFIG_SUSPEND
		case HIBERNATION_SUSPEND:
#endif
		case HIBERNATION_TEST_RESUME:
			break;
		case HIBERNATION_PLATFORM:
			if (hibernation_ops)
				break;
			/* not a valid mode, continue with loop */
			continue;
		}
		if (i == hibernation_mode)
			buf += sprintf(buf, "[%s] ", hibernation_modes[i]);
		else
			buf += sprintf(buf, "%s ", hibernation_modes[i]);
	}
	buf += sprintf(buf, "\n");
	return buf-start;
}

__attribute__((used)) static ssize_t disk_store(struct kobject *kobj, struct kobj_attribute *attr,
			  const char *buf, size_t n)
{
	int error = 0;
	int i;
	int len;
	char *p;
	int mode = HIBERNATION_INVALID;

	if (!hibernation_available())
		return -EPERM;

	p = memchr(buf, '\n', n);
	len = p ? p - buf : n;

	lock_system_sleep();
	for (i = HIBERNATION_FIRST; i <= HIBERNATION_MAX; i++) {
		if (len == strlen(hibernation_modes[i])
		    && !strncmp(buf, hibernation_modes[i], len)) {
			mode = i;
			break;
		}
	}
	if (mode != HIBERNATION_INVALID) {
		switch (mode) {
		case HIBERNATION_SHUTDOWN:
		case HIBERNATION_REBOOT:
#ifdef CONFIG_SUSPEND
		case HIBERNATION_SUSPEND:
#endif
		case HIBERNATION_TEST_RESUME:
			hibernation_mode = mode;
			break;
		case HIBERNATION_PLATFORM:
			if (hibernation_ops)
				hibernation_mode = mode;
			else
				error = -EINVAL;
		}
	} else
		error = -EINVAL;

	if (!error)
		pm_pr_dbg("Hibernation mode set to '%s'\n",
			       hibernation_modes[mode]);
	unlock_system_sleep();
	return error ? error : n;
}

__attribute__((used)) static ssize_t resume_show(struct kobject *kobj, struct kobj_attribute *attr,
			   char *buf)
{
	return sprintf(buf,"%d:%d\n", MAJOR(swsusp_resume_device),
		       MINOR(swsusp_resume_device));
}

__attribute__((used)) static ssize_t resume_store(struct kobject *kobj, struct kobj_attribute *attr,
			    const char *buf, size_t n)
{
	dev_t res;
	int len = n;
	char *name;

	if (len && buf[len-1] == '\n')
		len--;
	name = kstrndup(buf, len, GFP_KERNEL);
	if (!name)
		return -ENOMEM;

	res = name_to_dev_t(name);
	kfree(name);
	if (!res)
		return -EINVAL;

	lock_system_sleep();
	swsusp_resume_device = res;
	unlock_system_sleep();
	pm_pr_dbg("Configured resume from disk to %u\n", swsusp_resume_device);
	noresume = 0;
	software_resume();
	return n;
}

__attribute__((used)) static ssize_t resume_offset_show(struct kobject *kobj,
				  struct kobj_attribute *attr, char *buf)
{
	return sprintf(buf, "%llu\n", (unsigned long long)swsusp_resume_block);
}

__attribute__((used)) static ssize_t resume_offset_store(struct kobject *kobj,
				   struct kobj_attribute *attr, const char *buf,
				   size_t n)
{
	unsigned long long offset;
	int rc;

	rc = kstrtoull(buf, 0, &offset);
	if (rc)
		return rc;
	swsusp_resume_block = offset;

	return n;
}

__attribute__((used)) static ssize_t image_size_show(struct kobject *kobj, struct kobj_attribute *attr,
			       char *buf)
{
	return sprintf(buf, "%lu\n", image_size);
}

__attribute__((used)) static ssize_t image_size_store(struct kobject *kobj, struct kobj_attribute *attr,
				const char *buf, size_t n)
{
	unsigned long size;

	if (sscanf(buf, "%lu", &size) == 1) {
		image_size = size;
		return n;
	}

	return -EINVAL;
}

__attribute__((used)) static ssize_t reserved_size_show(struct kobject *kobj,
				  struct kobj_attribute *attr, char *buf)
{
	return sprintf(buf, "%lu\n", reserved_size);
}

__attribute__((used)) static ssize_t reserved_size_store(struct kobject *kobj,
				   struct kobj_attribute *attr,
				   const char *buf, size_t n)
{
	unsigned long size;

	if (sscanf(buf, "%lu", &size) == 1) {
		reserved_size = size;
		return n;
	}

	return -EINVAL;
}

