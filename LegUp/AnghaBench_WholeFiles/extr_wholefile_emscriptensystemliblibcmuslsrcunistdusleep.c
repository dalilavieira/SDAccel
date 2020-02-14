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
struct timespec {unsigned int tv_sec; unsigned int tv_nsec; } ;

/* Variables and functions */
 int nanosleep (struct timespec*,struct timespec*) ; 

int usleep(unsigned useconds)
{
	struct timespec tv = {
		.tv_sec = useconds/1000000,
		.tv_nsec = (useconds%1000000)*1000
	};
	return nanosleep(&tv, &tv);
}

