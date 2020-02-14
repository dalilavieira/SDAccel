#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_26__   TYPE_5__ ;
typedef  struct TYPE_25__   TYPE_4__ ;
typedef  struct TYPE_24__   TYPE_3__ ;
typedef  struct TYPE_23__   TYPE_2__ ;
typedef  struct TYPE_22__   TYPE_1__ ;

/* Type definitions */
struct sched_param {int /*<<< orphan*/  sched_priority; } ;
struct TYPE_22__ {int* __attr; } ;
typedef  TYPE_1__ pthread_rwlockattr_t ;
struct TYPE_23__ {unsigned int __attr; } ;
typedef  TYPE_2__ pthread_mutexattr_t ;
struct TYPE_24__ {int __attr; } ;
typedef  TYPE_3__ pthread_condattr_t ;
struct TYPE_25__ {int /*<<< orphan*/  __attr; } ;
typedef  TYPE_4__ pthread_barrierattr_t ;
struct TYPE_26__ {int _a_detach; size_t _a_guardsize; int _a_sched; int _a_policy; size_t _a_stacksize; size_t _a_stackaddr; int /*<<< orphan*/  _a_prio; } ;
typedef  TYPE_5__ pthread_attr_t ;
typedef  int clockid_t ;

/* Variables and functions */
 size_t DEFAULT_GUARD_SIZE ; 
 size_t DEFAULT_STACK_SIZE ; 
 int EINVAL ; 
 int PTHREAD_PRIO_NONE ; 
 int PTHREAD_SCOPE_SYSTEM ; 

int pthread_attr_getdetachstate(const pthread_attr_t *a, int *state)
{
	*state = a->_a_detach;
	return 0;
}

int pthread_attr_getguardsize(const pthread_attr_t *restrict a, size_t *restrict size)
{
	*size = a->_a_guardsize + DEFAULT_GUARD_SIZE;
	return 0;
}

int pthread_attr_getinheritsched(const pthread_attr_t *restrict a, int *restrict inherit)
{
	*inherit = a->_a_sched;
	return 0;
}

int pthread_attr_getschedparam(const pthread_attr_t *restrict a, struct sched_param *restrict param)
{
	param->sched_priority = a->_a_prio;
	return 0;
}

int pthread_attr_getschedpolicy(const pthread_attr_t *restrict a, int *restrict policy)
{
	*policy = a->_a_policy;
	return 0;
}

int pthread_attr_getscope(const pthread_attr_t *restrict a, int *restrict scope)
{
	*scope = PTHREAD_SCOPE_SYSTEM;
	return 0;
}

int pthread_attr_getstack(const pthread_attr_t *restrict a, void **restrict addr, size_t *restrict size)
{
/// XXX musl is not standard-conforming? It should not report EINVAL if _a_stackaddr is zero, and it should
///     report EINVAL if a is null: http://pubs.opengroup.org/onlinepubs/009695399/functions/pthread_attr_getstack.html
	if (!a) return EINVAL;
//	if (!a->_a_stackaddr)
//		return EINVAL;

	*size = a->_a_stacksize + DEFAULT_STACK_SIZE;
	*addr = (void *)(a->_a_stackaddr - *size);
	return 0;
}

int pthread_attr_getstacksize(const pthread_attr_t *restrict a, size_t *restrict size)
{
	*size = a->_a_stacksize + DEFAULT_STACK_SIZE;
	return 0;
}

int pthread_barrierattr_getpshared(const pthread_barrierattr_t *restrict a, int *restrict pshared)
{
	*pshared = !!a->__attr;
	return 0;
}

int pthread_condattr_getclock(const pthread_condattr_t *restrict a, clockid_t *restrict clk)
{
	*clk = a->__attr & 0x7fffffff;
	return 0;
}

int pthread_condattr_getpshared(const pthread_condattr_t *restrict a, int *restrict pshared)
{
	*pshared = a->__attr>>31;
	return 0;
}

int pthread_mutexattr_getprotocol(const pthread_mutexattr_t *restrict a, int *restrict protocol)
{
	*protocol = PTHREAD_PRIO_NONE;
	return 0;
}

int pthread_mutexattr_getpshared(const pthread_mutexattr_t *restrict a, int *restrict pshared)
{
	*pshared = a->__attr / 128U % 2;
	return 0;
}

int pthread_mutexattr_getrobust(const pthread_mutexattr_t *restrict a, int *restrict robust)
{
	*robust = a->__attr / 4U % 2;
	return 0;
}

int pthread_mutexattr_gettype(const pthread_mutexattr_t *restrict a, int *restrict type)
{
	*type = a->__attr & 3;
	return 0;
}

int pthread_rwlockattr_getpshared(const pthread_rwlockattr_t *restrict a, int *restrict pshared)
{
	*pshared = a->__attr[0];
	return 0;
}

