#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  pthread_t ;
struct TYPE_7__ {long tv_sec; int tv_nsec; } ;
struct TYPE_6__ {int const millitm; scalar_t__ time; } ;
typedef  TYPE_1__ PTW32_STRUCT_TIMEB ;
typedef  int DWORD ;

/* Variables and functions */
 int ETIMEDOUT ; 
 int /*<<< orphan*/  PTW32_FTIME (TYPE_1__*) ; 
 int /*<<< orphan*/  Sleep (int) ; 
 TYPE_2__ abstime ; 
 int /*<<< orphan*/  assert (int) ; 
 scalar_t__ bankAccount ; 
 scalar_t__ pthread_create (int /*<<< orphan*/ *,int /*<<< orphan*/ *,void* (*) (void*),void*) ; 
 scalar_t__ pthread_join (int /*<<< orphan*/ ,void**) ; 
 int pthread_rwlock_timedrdlock (int /*<<< orphan*/ *,TYPE_2__*) ; 
 int pthread_rwlock_timedwrlock (int /*<<< orphan*/ *,TYPE_2__*) ; 
 scalar_t__ pthread_rwlock_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rwlock1 ; 

void * wrfunc(void * arg)
{
  int result;

  result = pthread_rwlock_timedwrlock(&rwlock1, &abstime);
  if ((int) (size_t)arg == 1)
    {
      assert(result == 0);
      Sleep(2000);
      bankAccount += 10;
      assert(pthread_rwlock_unlock(&rwlock1) == 0);
      return ((void *)(size_t)bankAccount);
    }
  else if ((int) (size_t)arg == 2)
    {
      assert(result == ETIMEDOUT);
      return ((void *) 100);
    }

  return ((void *)(size_t)-1);
}

void * rdfunc(void * arg)
{
  int ba = 0;

  assert(pthread_rwlock_timedrdlock(&rwlock1, &abstime) == ETIMEDOUT);

  return ((void *)(size_t)ba);
}

int
main()
{
  pthread_t wrt1;
  pthread_t wrt2;
  pthread_t rdt;
  void* wr1Result = (void*)0;
  void* wr2Result = (void*)0;
  void* rdResult = (void*)0;
  PTW32_STRUCT_TIMEB currSysTime;
  const DWORD NANOSEC_PER_MILLISEC = 1000000;

  PTW32_FTIME(&currSysTime);

  abstime.tv_sec = (long)currSysTime.time;
  abstime.tv_nsec = NANOSEC_PER_MILLISEC * currSysTime.millitm;

  abstime.tv_sec += 1;

  bankAccount = 0;

  assert(pthread_create(&wrt1, NULL, wrfunc, (void *)(size_t)1) == 0);
  Sleep(100);
  assert(pthread_create(&rdt, NULL, rdfunc, NULL) == 0);
  Sleep(100);
  assert(pthread_create(&wrt2, NULL, wrfunc, (void *)(size_t)2) == 0);

  assert(pthread_join(wrt1, &wr1Result) == 0);
  assert(pthread_join(rdt, &rdResult) == 0);
  assert(pthread_join(wrt2, &wr2Result) == 0);

  assert((int)(size_t)wr1Result == 10);
  assert((int)(size_t)rdResult == 0);
  assert((int)(size_t)wr2Result == 100);

  return 0;
}

