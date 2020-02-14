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
typedef  int /*<<< orphan*/  u64 ;
struct clocksource {int dummy; } ;

/* Variables and functions */
 scalar_t__ SCx200_TIMER_OFFSET ; 
 int /*<<< orphan*/  inl (scalar_t__) ; 
 scalar_t__ scx200_cb_base ; 

__attribute__((used)) static u64 read_hrt(struct clocksource *cs)
{
	/* Read the timer value */
	return (u64) inl(scx200_cb_base + SCx200_TIMER_OFFSET);
}

