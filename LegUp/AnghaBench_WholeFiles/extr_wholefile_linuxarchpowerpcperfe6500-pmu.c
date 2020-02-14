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
typedef  int u64 ;
typedef  scalar_t__ u32 ;
struct TYPE_2__ {int /*<<< orphan*/  oprofile_cpu_type; } ;

/* Variables and functions */
 int ENODEV ; 
 int FSL_EMB_EVENT_THRESH ; 
 int FSL_EMB_EVENT_THRESHMUL ; 
 int FSL_EMB_EVENT_VALID ; 
 TYPE_1__* cur_cpu_spec ; 
 int /*<<< orphan*/  e6500_pmu ; 
 scalar_t__ num_events ; 
 int register_fsl_emb_pmu (int /*<<< orphan*/ *) ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static u64 e6500_xlate_event(u64 event_id)
{
	u32 event_low = (u32)event_id;
	if (event_low >= num_events ||
		(event_id & (FSL_EMB_EVENT_THRESHMUL | FSL_EMB_EVENT_THRESH)))
		return 0;

	return FSL_EMB_EVENT_VALID;
}

__attribute__((used)) static int init_e6500_pmu(void)
{
	if (!cur_cpu_spec->oprofile_cpu_type ||
		strcmp(cur_cpu_spec->oprofile_cpu_type, "ppc/e6500"))
		return -ENODEV;

	return register_fsl_emb_pmu(&e6500_pmu);
}

