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
 char* asctime (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  localtime (int /*<<< orphan*/  const*) ; 

char* ctime_r( const time_t* timep, char *buf) {
    buf = asctime( localtime( timep ) );

    return buf;
}

