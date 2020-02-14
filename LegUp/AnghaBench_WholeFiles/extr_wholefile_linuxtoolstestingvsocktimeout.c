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

/* Variables and functions */
 int /*<<< orphan*/  EXIT_FAILURE ; 
 int /*<<< orphan*/  alarm (unsigned int) ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char const*) ; 
 int /*<<< orphan*/  stderr ; 
 int timeout ; 

void sigalrm(int signo)
{
	timeout = true;
}

void timeout_begin(unsigned int seconds)
{
	alarm(seconds);
}

void timeout_check(const char *operation)
{
	if (timeout) {
		fprintf(stderr, "%s timed out\n", operation);
		exit(EXIT_FAILURE);
	}
}

void timeout_end(void)
{
	alarm(0);
	timeout = false;
}

