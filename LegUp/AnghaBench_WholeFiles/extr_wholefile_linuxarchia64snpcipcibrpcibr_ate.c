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
typedef  int u64 ;
struct ate_resource {int* ate; int num_ate; int lowest_free_index; } ;
struct pcibus_info {int /*<<< orphan*/  pbi_lock; struct ate_resource pbi_int_ate_resource; } ;

/* Variables and functions */
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static void mark_ate(struct ate_resource *ate_resource, int start, int number,
		     u64 value)
{
	u64 *ate = ate_resource->ate;
	int index;
	int length = 0;

	for (index = start; length < number; index++, length++)
		ate[index] = value;
}

__attribute__((used)) static int find_free_ate(struct ate_resource *ate_resource, int start,
			 int count)
{
	u64 *ate = ate_resource->ate;
	int index;
	int start_free;

	for (index = start; index < ate_resource->num_ate;) {
		if (!ate[index]) {
			int i;
			int free;
			free = 0;
			start_free = index;	/* Found start free ate */
			for (i = start_free; i < ate_resource->num_ate; i++) {
				if (!ate[i]) {	/* This is free */
					if (++free == count)
						return start_free;
				} else {
					index = i + 1;
					break;
				}
			}
			if (i >= ate_resource->num_ate)
				return -1;
		} else
			index++;	/* Try next ate */
	}

	return -1;
}

__attribute__((used)) static inline void free_ate_resource(struct ate_resource *ate_resource,
				     int start)
{
	mark_ate(ate_resource, start, ate_resource->ate[start], 0);
	if ((ate_resource->lowest_free_index > start) ||
	    (ate_resource->lowest_free_index < 0))
		ate_resource->lowest_free_index = start;
}

__attribute__((used)) static inline int alloc_ate_resource(struct ate_resource *ate_resource,
				     int ate_needed)
{
	int start_index;

	/*
	 * Check for ate exhaustion.
	 */
	if (ate_resource->lowest_free_index < 0)
		return -1;

	/*
	 * Find the required number of free consecutive ates.
	 */
	start_index =
	    find_free_ate(ate_resource, ate_resource->lowest_free_index,
			  ate_needed);
	if (start_index >= 0)
		mark_ate(ate_resource, start_index, ate_needed, ate_needed);

	ate_resource->lowest_free_index =
	    find_free_ate(ate_resource, ate_resource->lowest_free_index, 1);

	return start_index;
}

int pcibr_ate_alloc(struct pcibus_info *pcibus_info, int count)
{
	int status;
	unsigned long flags;

	spin_lock_irqsave(&pcibus_info->pbi_lock, flags);
	status = alloc_ate_resource(&pcibus_info->pbi_int_ate_resource, count);
	spin_unlock_irqrestore(&pcibus_info->pbi_lock, flags);

	return status;
}

