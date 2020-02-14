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
typedef  int EM_BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  EM_ASM (int) ; 
 int* Module ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  emscripten_set_timeout (void (*) (void*),int,void*) ; 
 int /*<<< orphan*/  emscripten_set_timeout_loop (int (*) (double,void*),int,void*) ; 
 int funcExecuted ; 
 double previousSetTimeouTime ; 

void testDone(void *userData)
{
	assert((int)userData == 2);
	assert(funcExecuted == 10);
#ifdef REPORT_RESULT
	REPORT_RESULT(0);
#endif
}

EM_BOOL tick(double time, void *userData)
{
	assert(time >= previousSetTimeouTime);
	previousSetTimeouTime = time;
	assert((int)userData == 1);
	++funcExecuted;
	if (funcExecuted == 10)
	{
		emscripten_set_timeout(testDone, 300, (void*)2);
	}
	return funcExecuted < 10;
}

int main()
{
	emscripten_set_timeout_loop(tick, 100, (void*)1);
	EM_ASM(Module['noExitRuntime'] = 1);
}

