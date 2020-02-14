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
typedef  int /*<<< orphan*/  time_t ;

/* Variables and functions */
 int /*<<< orphan*/  SYS_stime ; 
 int errno ; 
 int syscall1 (int /*<<< orphan*/ ,int) ; 

int stime( time_t *t ) {
    int error;

    error = syscall1( SYS_stime, ( int )t );

    if ( error < 0 ) {
        errno = -error;
        return -1;
    }

    return 0;
}

