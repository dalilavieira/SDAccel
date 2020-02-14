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
typedef  int /*<<< orphan*/  SDL_Thread ;

/* Variables and functions */
 int /*<<< orphan*/ * SDL_CreateThread (int (*) (void*),char*,void*) ; 
 int /*<<< orphan*/  SDL_WaitThread (int /*<<< orphan*/ *,int*) ; 

__attribute__((used)) static int test_thread(void *data)
{
	return 2 + 2;
}

int main()
{
	SDL_Thread *thread;
	int result;

	thread = SDL_CreateThread(test_thread, "Test Thread", (void *)NULL);

	if (NULL == thread) {
		return 1;
	} else {
		SDL_WaitThread(thread, &result);
	}

#ifdef REPORT_RESULT
	REPORT_RESULT(result);
#endif
	return 0;
}

