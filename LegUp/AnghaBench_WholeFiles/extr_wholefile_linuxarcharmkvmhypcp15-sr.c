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
struct kvm_cpu_context {scalar_t__ cp15; } ;

/* Variables and functions */

__attribute__((used)) static u64 *cp15_64(struct kvm_cpu_context *ctxt, int idx)
{
	return (u64 *)(ctxt->cp15 + idx);
}

