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
 int /*<<< orphan*/  __NR_setns ; 
 void* calloc (int,size_t) ; 
 int syscall (int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static inline void *zalloc(size_t size)
{
	return calloc(1, size);
}

int setns(int fd, int nstype)
{
	return syscall(__NR_setns, fd, nstype);
}

