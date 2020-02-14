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
typedef  int /*<<< orphan*/  socklen_t ;

/* Variables and functions */
 int socketcall (int (*) (int,int,int,void*,int /*<<< orphan*/ *),int,int,int,void*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

int getsockopt(int fd, int level, int optname, void *restrict optval, socklen_t *restrict optlen)
{
	return socketcall(getsockopt, fd, level, optname, optval, optlen, 0);
}

