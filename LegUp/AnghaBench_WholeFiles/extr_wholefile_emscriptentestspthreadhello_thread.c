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
typedef  int /*<<< orphan*/  pthread_t ;

/* Variables and functions */
 int /*<<< orphan*/  EM_ASM (int) ; 
 int* Module ; 
 int out (char) ; 
 int /*<<< orphan*/  pthread_create (int /*<<< orphan*/ *,int /*<<< orphan*/ *,void* (*) (void*),int /*<<< orphan*/ *) ; 

void *thread_main(void *arg)
{
	EM_ASM(out('hello from thread!'));
#ifdef REPORT_RESULT
	REPORT_RESULT(1);
#endif
	return 0;
}

int main()
{
	pthread_t thread;
	pthread_create(&thread, NULL, thread_main, NULL);
	EM_ASM(Module['noExitRuntime']=true);
}

