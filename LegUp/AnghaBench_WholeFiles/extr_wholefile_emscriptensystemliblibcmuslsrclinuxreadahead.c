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
typedef  int /*<<< orphan*/  ssize_t ;
typedef  int /*<<< orphan*/  off_t ;

/* Variables and functions */
 int /*<<< orphan*/  SYS_readahead ; 
 int /*<<< orphan*/  __SYSCALL_LL_O (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  syscall (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,size_t) ; 

ssize_t readahead(int fd, off_t pos, size_t len)
{
	return syscall(SYS_readahead, fd, __SYSCALL_LL_O(pos), len);
}

