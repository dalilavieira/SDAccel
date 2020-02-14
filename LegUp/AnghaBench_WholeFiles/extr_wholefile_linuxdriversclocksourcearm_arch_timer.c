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
struct cyclecounter {int dummy; } ;
struct clocksource {int dummy; } ;
struct arch_timer_kvm_info {int dummy; } ;

/* Variables and functions */
 struct arch_timer_kvm_info arch_timer_kvm_info ; 
 int /*<<< orphan*/  arch_timer_read_counter () ; 

__attribute__((used)) static u64 arch_counter_read(struct clocksource *cs)
{
	return arch_timer_read_counter();
}

__attribute__((used)) static u64 arch_counter_read_cc(const struct cyclecounter *cc)
{
	return arch_timer_read_counter();
}

struct arch_timer_kvm_info *arch_timer_get_kvm_info(void)
{
	return &arch_timer_kvm_info;
}

