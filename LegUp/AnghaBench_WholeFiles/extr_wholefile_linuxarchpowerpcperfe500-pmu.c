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
typedef  int u32 ;
struct TYPE_2__ {int /*<<< orphan*/  oprofile_cpu_type; } ;

/* Variables and functions */
 int ENODEV ; 
 int FSL_EMB_EVENT_RESTRICTED ; 
 int FSL_EMB_EVENT_THRESH ; 
 int FSL_EMB_EVENT_THRESHMUL ; 
 int FSL_EMB_EVENT_VALID ; 
 TYPE_1__* cur_cpu_spec ; 
 int /*<<< orphan*/  e500_pmu ; 
 int num_events ; 
 int register_fsl_emb_pmu (int /*<<< orphan*/ *) ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static u64 e500_xlate_event(u64 event_id)
{
	u32 event_low = (u32)event_id;
	u64 ret;

	if (event_low >= num_events)
		return 0;

	ret = FSL_EMB_EVENT_VALID;

	if (event_low >= 76 && event_low <= 81) {
		ret |= FSL_EMB_EVENT_RESTRICTED;
		ret |= event_id &
		       (FSL_EMB_EVENT_THRESHMUL | FSL_EMB_EVENT_THRESH);
	} else if (event_id &
	           (FSL_EMB_EVENT_THRESHMUL | FSL_EMB_EVENT_THRESH)) {
		/* Threshold requested on non-threshold event */
		return 0;
	}

	return ret;
}

__attribute__((used)) static int init_e500_pmu(void)
{
	if (!cur_cpu_spec->oprofile_cpu_type)
		return -ENODEV;

	if (!strcmp(cur_cpu_spec->oprofile_cpu_type, "ppc/e500mc"))
		num_events = 256;
	else if (strcmp(cur_cpu_spec->oprofile_cpu_type, "ppc/e500"))
		return -ENODEV;

	return register_fsl_emb_pmu(&e500_pmu);
}

