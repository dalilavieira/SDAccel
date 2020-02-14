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
typedef  unsigned int u64 ;
typedef  unsigned int u32 ;
struct rnd_state {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUILD_BUG_ON (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned int* kmalloc_array (unsigned int,int,int /*<<< orphan*/ ) ; 
 scalar_t__ prandom_u32_state (struct rnd_state*) ; 
 int /*<<< orphan*/  swap (unsigned int,unsigned int) ; 
 unsigned int upper_32_bits (unsigned int) ; 

__attribute__((used)) static inline u32 drm_prandom_u32_max_state(u32 ep_ro, struct rnd_state *state)
{
	return upper_32_bits((u64)prandom_u32_state(state) * ep_ro);
}

void drm_random_reorder(unsigned int *order, unsigned int count,
			struct rnd_state *state)
{
	unsigned int i, j;

	for (i = 0; i < count; ++i) {
		BUILD_BUG_ON(sizeof(unsigned int) > sizeof(u32));
		j = drm_prandom_u32_max_state(count, state);
		swap(order[i], order[j]);
	}
}

unsigned int *drm_random_order(unsigned int count, struct rnd_state *state)
{
	unsigned int *order, i;

	order = kmalloc_array(count, sizeof(*order), GFP_KERNEL);
	if (!order)
		return order;

	for (i = 0; i < count; i++)
		order[i] = i;

	drm_random_reorder(order, count, state);
	return order;
}

