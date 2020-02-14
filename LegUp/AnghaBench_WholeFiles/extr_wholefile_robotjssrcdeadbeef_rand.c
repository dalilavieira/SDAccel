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
typedef  int uint32_t ;

/* Variables and functions */
 int /*<<< orphan*/  clock () ; 
 int deadbeef_beef ; 
 int deadbeef_seed ; 
 int /*<<< orphan*/  time (int /*<<< orphan*/ *) ; 

uint32_t deadbeef_rand(void)
{
	deadbeef_seed = (deadbeef_seed << 7) ^ ((deadbeef_seed >> 25) + deadbeef_beef);
	deadbeef_beef = (deadbeef_beef << 7) ^ ((deadbeef_beef >> 25) + 0xdeadbeef);
	return deadbeef_seed;
}

void deadbeef_srand(uint32_t x)
{
	deadbeef_seed = x;
	deadbeef_beef = 0xdeadbeef;
}

uint32_t deadbeef_generate_seed(void)
{
	  uint32_t t = (uint32_t)time(NULL);
	  uint32_t c = (uint32_t)clock();
	  return (t << 24) ^ (c << 11) ^ t ^ (size_t) &c;
}

