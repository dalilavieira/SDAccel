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
 int /*<<< orphan*/  __seed48 ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,unsigned short*,int) ; 

void lcong48(unsigned short p[7])
{
	memcpy(__seed48, p, sizeof __seed48);
}

