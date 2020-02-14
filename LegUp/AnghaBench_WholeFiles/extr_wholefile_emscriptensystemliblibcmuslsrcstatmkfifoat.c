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
typedef  int mode_t ;

/* Variables and functions */
 int S_IFIFO ; 
 int mknodat (int,char const*,int,int /*<<< orphan*/ ) ; 

int mkfifoat(int fd, const char *path, mode_t mode)
{
	return mknodat(fd, path, mode | S_IFIFO, 0);
}

