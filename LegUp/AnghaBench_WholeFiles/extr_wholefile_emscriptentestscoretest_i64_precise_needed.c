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
 int /*<<< orphan*/  printf (char*,unsigned long long) ; 

int main( int argc, char ** argv )
{
    unsigned long a = 0x60DD1695U;
    unsigned long b = 0xCA8C4E7BU;
    unsigned long long c = (unsigned long long)a * b;
    printf( "c = %016llx\n", c );

    return 0;
}

