#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int* mbctype; } ;

/* Variables and functions */
 int _MBPUNCT ; 
 TYPE_1__* get_mbcinfo () ; 

int _ismbbpunct(unsigned int c)
{
// (0xA1 <= c <= 0xA6)
    return (get_mbcinfo()->mbctype[c & 0xff] & _MBPUNCT);
}

