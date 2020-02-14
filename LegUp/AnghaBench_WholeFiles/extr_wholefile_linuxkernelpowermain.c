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
typedef  scalar_t__ suspend_state_t ;
struct kobject {int dummy; } ;
struct kobj_attribute {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int EBUSY ; 
 int EINVAL ; 
 int ENOSYS ; 
 scalar_t__ PM_SUSPEND_MAX ; 
 scalar_t__ PM_SUSPEND_MEM ; 
 scalar_t__ PM_SUSPEND_ON ; 
 int hibernate () ; 
 scalar_t__ hibernation_available () ; 
 scalar_t__ mem_sleep_current ; 
 char* memchr (char const*,char,size_t) ; 
 int pm_suspend (scalar_t__) ; 
 int /*<<< orphan*/  sprintf (char*,char*) ; 
 int /*<<< orphan*/  strncmp (char const*,char*,int) ; 

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

__attribute__((used)) static inline void pm_print_times_init(void) {}

__attribute__((used)) static ssize_t state_show(struct kobject *kobj, struct kobj_attribute *attr,
			  char *buf)
{
	char *s = buf;
#ifdef CONFIG_SUSPEND
	suspend_state_t i;

	for (i = PM_SUSPEND_MIN; i < PM_SUSPEND_MAX; i++)
		if (pm_states[i])
			s += sprintf(s,"%s ", pm_states[i]);

#endif
	if (hibernation_available())
		s += sprintf(s, "disk ");
	if (s != buf)
		/* convert the last space to a newline */
		*(s-1) = '\n';
	return (s - buf);
}

__attribute__((used)) static suspend_state_t decode_state(const char *buf, size_t n)
{
#ifdef CONFIG_SUSPEND
	suspend_state_t state;
#endif
	char *p;
	int len;

	p = memchr(buf, '\n', n);
	len = p ? p - buf : n;

	/* Check hibernation first. */
	if (len == 4 && !strncmp(buf, "disk", len))
		return PM_SUSPEND_MAX;

#ifdef CONFIG_SUSPEND
	for (state = PM_SUSPEND_MIN; state < PM_SUSPEND_MAX; state++) {
		const char *label = pm_states[state];

		if (label && len == strlen(label) && !strncmp(buf, label, len))
			return state;
	}
#endif

	return PM_SUSPEND_ON;
}

__attribute__((used)) static ssize_t state_store(struct kobject *kobj, struct kobj_attribute *attr,
			   const char *buf, size_t n)
{
	suspend_state_t state;
	int error;

	error = pm_autosleep_lock();
	if (error)
		return error;

	if (pm_autosleep_state() > PM_SUSPEND_ON) {
		error = -EBUSY;
		goto out;
	}

	state = decode_state(buf, n);
	if (state < PM_SUSPEND_MAX) {
		if (state == PM_SUSPEND_MEM)
			state = mem_sleep_current;

		error = pm_suspend(state);
	} else if (state == PM_SUSPEND_MAX) {
		error = hibernate();
	} else {
		error = -EINVAL;
	}

 out:
	pm_autosleep_unlock();
	return error ? error : n;
}

