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
 int /*<<< orphan*/  SYS_quotactl ; 
 int syscall (int /*<<< orphan*/ ,int,char const*,int,char*) ; 

int quotactl(int cmd, const char *special, int id, char *addr)
{
	return syscall(SYS_quotactl, cmd, special, id, addr);
}

