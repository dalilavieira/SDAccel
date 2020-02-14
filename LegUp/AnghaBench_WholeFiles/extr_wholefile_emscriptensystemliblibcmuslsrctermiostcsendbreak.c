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
 int /*<<< orphan*/  TCSBRK ; 
 int ioctl (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int tcsendbreak(int fd, int dur)
{
	/* nonzero duration is implementation-defined, so ignore it */
	return ioctl(fd, TCSBRK, 0);
}

