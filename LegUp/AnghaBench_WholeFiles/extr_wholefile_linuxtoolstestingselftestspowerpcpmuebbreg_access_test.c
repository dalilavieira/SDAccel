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
typedef  int uint64_t ;
typedef  scalar_t__ uint32_t ;
struct TYPE_2__ {int* pmc_enable; } ;

/* Variables and functions */
 scalar_t__ COUNTER_OVERFLOW ; 
 int /*<<< orphan*/  FAIL_IF (int) ; 
 size_t PMC_INDEX (int) ; 
 int /*<<< orphan*/  SKIP_IF (int) ; 
 int /*<<< orphan*/  SPRN_BESCR ; 
 int /*<<< orphan*/  SPRN_EBBHR ; 
 int /*<<< orphan*/  ebb_is_supported () ; 
 TYPE_1__ ebb_state ; 
 int mfspr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtspr (int /*<<< orphan*/ ,int) ; 
 int test_harness (int (*) (),char*) ; 

__attribute__((used)) static inline uint32_t pmc_sample_period(uint32_t value)
{
	return COUNTER_OVERFLOW - value;
}

__attribute__((used)) static inline void ebb_enable_pmc_counting(int pmc)
{
	ebb_state.pmc_enable[PMC_INDEX(pmc)] = true;
}

int reg_access(void)
{
	uint64_t val, expected;

	SKIP_IF(!ebb_is_supported());

	expected = 0x8000000100000000ull;
	mtspr(SPRN_BESCR, expected);
	val = mfspr(SPRN_BESCR);

	FAIL_IF(val != expected);

	expected = 0x0000000001000000ull;
	mtspr(SPRN_EBBHR, expected);
	val = mfspr(SPRN_EBBHR);

	FAIL_IF(val != expected);

	return 0;
}

int main(void)
{
	return test_harness(reg_access, "reg_access");
}

