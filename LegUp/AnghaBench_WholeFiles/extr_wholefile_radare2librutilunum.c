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
 int rand () ; 
 int /*<<< orphan*/  srand (int) ; 

__attribute__((used)) static void r_srand (int seed) {
#if HAVE_ARC4RANDOM_UNIFORM
	// no-op
	(void)seed;
#else
	srand (seed);
#endif
}

__attribute__((used)) static int r_rand (int mod) {
#if HAVE_ARC4RANDOM_UNIFORM
	return (int)arc4random_uniform (mod);
#else
	return rand ()%mod;
#endif
}

