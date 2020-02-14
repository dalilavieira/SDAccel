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
typedef  unsigned int u32 ;
struct rnd_state {int dummy; } ;
struct pci_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUILD_BUG_ON (int) ; 
 int GFP_KERNEL ; 
 int __GFP_NOWARN ; 
 int __GFP_RETRY_MAYFAIL ; 
 unsigned int* kmalloc_array (unsigned int,int,int) ; 
 int /*<<< orphan*/  mul_u32_u32 (int,unsigned int) ; 
 int prandom_u32_state (struct rnd_state*) ; 
 int /*<<< orphan*/  swap (unsigned int,unsigned int) ; 
 unsigned int upper_32_bits (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int i915_mock_selftests(void) { return 0; }

__attribute__((used)) static inline int i915_live_selftests(struct pci_dev *pdev) { return 0; }

__attribute__((used)) static inline u32 i915_prandom_u32_max_state(u32 ep_ro, struct rnd_state *state)
{
	return upper_32_bits(mul_u32_u32(prandom_u32_state(state), ep_ro));
}

u64 i915_prandom_u64_state(struct rnd_state *rnd)
{
	u64 x;

	x = prandom_u32_state(rnd);
	x <<= 32;
	x |= prandom_u32_state(rnd);

	return x;
}

void i915_random_reorder(unsigned int *order, unsigned int count,
			 struct rnd_state *state)
{
	unsigned int i, j;

	for (i = 0; i < count; i++) {
		BUILD_BUG_ON(sizeof(unsigned int) > sizeof(u32));
		j = i915_prandom_u32_max_state(count, state);
		swap(order[i], order[j]);
	}
}

unsigned int *i915_random_order(unsigned int count, struct rnd_state *state)
{
	unsigned int *order, i;

	order = kmalloc_array(count, sizeof(*order),
			      GFP_KERNEL | __GFP_RETRY_MAYFAIL | __GFP_NOWARN);
	if (!order)
		return order;

	for (i = 0; i < count; i++)
		order[i] = i;

	i915_random_reorder(order, count, state);
	return order;
}

