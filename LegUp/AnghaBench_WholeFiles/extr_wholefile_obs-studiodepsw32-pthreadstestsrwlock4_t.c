#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct timespec {long tv_sec; int tv_nsec; int /*<<< orphan*/  member_1; int /*<<< orphan*/  member_0; } ;
typedef  int /*<<< orphan*/  pthread_t ;
struct TYPE_3__ {int const millitm; scalar_t__ time; } ;
typedef  TYPE_1__ PTW32_STRUCT_TIMEB ;
typedef  int DWORD ;

/* Variables and functions */
 scalar_t__ EBUSY ; 
 int /*<<< orphan*/  PTW32_FTIME (TYPE_1__*) ; 
 int /*<<< orphan*/  Sleep (int) ; 
 int /*<<< orphan*/  assert (int) ; 
 scalar_t__ pthread_create (int /*<<< orphan*/ *,int /*<<< orphan*/ *,void* (*) (void*),int /*<<< orphan*/ *) ; 
 scalar_t__ pthread_rwlock_timedrdlock (int /*<<< orphan*/ *,struct timespec*) ; 
 scalar_t__ pthread_rwlock_trywrlock (int /*<<< orphan*/ *) ; 
 scalar_t__ pthread_rwlock_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rwlock1 ; 
 int washere ; 

void * func(void * arg)
{
  assert(pthread_rwlock_trywrlock(&rwlock1) == EBUSY);

  washere = 1;

  return 0; 
}

int
main()
{
  pthread_t t;
  struct timespec abstime = { 0, 0 };
  PTW32_STRUCT_TIMEB currSysTime;
  const DWORD NANOSEC_PER_MILLISEC = 1000000;

  PTW32_FTIME(&currSysTime);

  abstime.tv_sec = (long)currSysTime.time;
  abstime.tv_nsec = NANOSEC_PER_MILLISEC * currSysTime.millitm;

  abstime.tv_sec += 1;

  assert(pthread_rwlock_timedrdlock(&rwlock1, &abstime) == 0);

  assert(pthread_create(&t, NULL, func, NULL) == 0);

  Sleep(2000);

  assert(pthread_rwlock_unlock(&rwlock1) == 0);

  assert(washere == 1);

  return 0;
}

