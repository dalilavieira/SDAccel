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
struct cpumask {int dummy; } ;
struct cpuidle_driver {scalar_t__ refcnt; int state_count; int bctimer; struct cpumask* cpumask; TYPE_1__* states; } ;
struct cpuidle_device {int cpu; } ;
struct TYPE_2__ {int flags; } ;

/* Variables and functions */
 int CPUIDLE_FLAG_TIMER_STOP ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENODEV ; 
 scalar_t__ WARN_ON (int) ; 
 scalar_t__ cpu_possible_mask ; 
 struct cpuidle_driver* cpuidle_curr_driver ; 
 scalar_t__ cpuidle_disabled () ; 
 int /*<<< orphan*/  cpuidle_driver_lock ; 
 int get_cpu () ; 
 int /*<<< orphan*/  on_each_cpu_mask (struct cpumask*,void (*) (void*),void*,int) ; 
 int /*<<< orphan*/  put_cpu () ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tick_broadcast_disable () ; 
 int /*<<< orphan*/  tick_broadcast_enable () ; 

__attribute__((used)) static inline
bool cpuidle_state_is_coupled(struct cpuidle_driver *drv, int state)
{
	return false;
}

__attribute__((used)) static inline int cpuidle_coupled_state_verify(struct cpuidle_driver *drv)
{
	return 0;
}

__attribute__((used)) static inline int cpuidle_enter_state_coupled(struct cpuidle_device *dev,
		struct cpuidle_driver *drv, int next_state)
{
	return -1;
}

__attribute__((used)) static inline int cpuidle_coupled_register_device(struct cpuidle_device *dev)
{
	return 0;
}

__attribute__((used)) static inline void cpuidle_coupled_unregister_device(struct cpuidle_device *dev)
{
}

__attribute__((used)) static inline struct cpuidle_driver *__cpuidle_get_cpu_driver(int cpu)
{
	return cpuidle_curr_driver;
}

__attribute__((used)) static inline int __cpuidle_set_driver(struct cpuidle_driver *drv)
{
	if (cpuidle_curr_driver)
		return -EBUSY;

	cpuidle_curr_driver = drv;

	return 0;
}

__attribute__((used)) static inline void __cpuidle_unset_driver(struct cpuidle_driver *drv)
{
	if (drv == cpuidle_curr_driver)
		cpuidle_curr_driver = NULL;
}

__attribute__((used)) static void cpuidle_setup_broadcast_timer(void *arg)
{
	if (arg)
		tick_broadcast_enable();
	else
		tick_broadcast_disable();
}

__attribute__((used)) static void __cpuidle_driver_init(struct cpuidle_driver *drv)
{
	int i;

	drv->refcnt = 0;

	/*
	 * Use all possible CPUs as the default, because if the kernel boots
	 * with some CPUs offline and then we online one of them, the CPU
	 * notifier has to know which driver to assign.
	 */
	if (!drv->cpumask)
		drv->cpumask = (struct cpumask *)cpu_possible_mask;

	/*
	 * Look for the timer stop flag in the different states, so that we know
	 * if the broadcast timer has to be set up.  The loop is in the reverse
	 * order, because usually one of the deeper states have this flag set.
	 */
	for (i = drv->state_count - 1; i >= 0 ; i--) {
		if (drv->states[i].flags & CPUIDLE_FLAG_TIMER_STOP) {
			drv->bctimer = 1;
			break;
		}
	}
}

__attribute__((used)) static int __cpuidle_register_driver(struct cpuidle_driver *drv)
{
	int ret;

	if (!drv || !drv->state_count)
		return -EINVAL;

	ret = cpuidle_coupled_state_verify(drv);
	if (ret)
		return ret;

	if (cpuidle_disabled())
		return -ENODEV;

	__cpuidle_driver_init(drv);

	ret = __cpuidle_set_driver(drv);
	if (ret)
		return ret;

	if (drv->bctimer)
		on_each_cpu_mask(drv->cpumask, cpuidle_setup_broadcast_timer,
				 (void *)1, 1);

	return 0;
}

__attribute__((used)) static void __cpuidle_unregister_driver(struct cpuidle_driver *drv)
{
	if (WARN_ON(drv->refcnt > 0))
		return;

	if (drv->bctimer) {
		drv->bctimer = 0;
		on_each_cpu_mask(drv->cpumask, cpuidle_setup_broadcast_timer,
				 NULL, 1);
	}

	__cpuidle_unset_driver(drv);
}

int cpuidle_register_driver(struct cpuidle_driver *drv)
{
	int ret;

	spin_lock(&cpuidle_driver_lock);
	ret = __cpuidle_register_driver(drv);
	spin_unlock(&cpuidle_driver_lock);

	return ret;
}

void cpuidle_unregister_driver(struct cpuidle_driver *drv)
{
	spin_lock(&cpuidle_driver_lock);
	__cpuidle_unregister_driver(drv);
	spin_unlock(&cpuidle_driver_lock);
}

struct cpuidle_driver *cpuidle_get_driver(void)
{
	struct cpuidle_driver *drv;
	int cpu;

	cpu = get_cpu();
	drv = __cpuidle_get_cpu_driver(cpu);
	put_cpu();

	return drv;
}

struct cpuidle_driver *cpuidle_get_cpu_driver(struct cpuidle_device *dev)
{
	if (!dev)
		return NULL;

	return __cpuidle_get_cpu_driver(dev->cpu);
}

struct cpuidle_driver *cpuidle_driver_ref(void)
{
	struct cpuidle_driver *drv;

	spin_lock(&cpuidle_driver_lock);

	drv = cpuidle_get_driver();
	if (drv)
		drv->refcnt++;

	spin_unlock(&cpuidle_driver_lock);
	return drv;
}

void cpuidle_driver_unref(void)
{
	struct cpuidle_driver *drv;

	spin_lock(&cpuidle_driver_lock);

	drv = cpuidle_get_driver();
	if (drv && !WARN_ON(drv->refcnt <= 0))
		drv->refcnt--;

	spin_unlock(&cpuidle_driver_lock);
}

