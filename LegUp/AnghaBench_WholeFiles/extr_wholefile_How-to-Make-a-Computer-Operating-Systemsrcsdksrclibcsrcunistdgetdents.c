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
struct dirent {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  SYS_getdents ; 
 int errno ; 
 int syscall3 (int /*<<< orphan*/ ,int,int,unsigned int) ; 

int getdents( int fd, struct dirent* entry, unsigned int count ) {
    int error;

    error = syscall3( SYS_getdents, fd, ( int )entry, count );

    if ( error < 0 ) {
        errno = -error;
        return -1;
    }

    return error;
}

