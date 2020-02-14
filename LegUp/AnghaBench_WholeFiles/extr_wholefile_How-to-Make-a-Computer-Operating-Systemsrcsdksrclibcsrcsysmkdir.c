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
typedef  scalar_t__ mode_t ;

/* Variables and functions */
 int /*<<< orphan*/  SYS_mkdir ; 
 int errno ; 
 int syscall2 (int /*<<< orphan*/ ,int,int) ; 

int mkdir( const char* pathname, mode_t mode ) {
    int error;

    error = syscall2( SYS_mkdir, ( int )pathname, ( int )mode );

    if ( error < 0 ) {
        errno = -error;
        return -1;
    }

    return 0;
}

