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
typedef  int uint32_t ;
typedef  int u32 ;
struct TYPE_2__ {int /*<<< orphan*/  devdisr; } ;

/* Variables and functions */
 int CCSR_GUTS_DEVDISR_TB0 ; 
 int CCSR_GUTS_DEVDISR_TB1 ; 
 int HID0_DOZE ; 
 int HID0_NAP ; 
 int HID0_SLEEP ; 
 int MSR_WE ; 
 int /*<<< orphan*/  SPRN_HID0 ; 
 int /*<<< orphan*/  clrbits32 (int /*<<< orphan*/ *,int) ; 
 TYPE_1__* guts ; 
 int /*<<< orphan*/  in_be32 (int /*<<< orphan*/ *) ; 
 int mfmsr () ; 
 int mfspr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtspr (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  setbits32 (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static void mpc85xx_irq_mask(int cpu)
{

}

__attribute__((used)) static void mpc85xx_irq_unmask(int cpu)
{

}

__attribute__((used)) static void mpc85xx_cpu_die(int cpu)
{
	u32 tmp;

	tmp = (mfspr(SPRN_HID0) & ~(HID0_DOZE|HID0_SLEEP)) | HID0_NAP;
	mtspr(SPRN_HID0, tmp);

	/* Enter NAP mode. */
	tmp = mfmsr();
	tmp |= MSR_WE;
	asm volatile(
		"msync\n"
		"mtmsr %0\n"
		"isync\n"
		:
		: "r" (tmp));
}

__attribute__((used)) static void mpc85xx_cpu_up_prepare(int cpu)
{

}

__attribute__((used)) static void mpc85xx_freeze_time_base(bool freeze)
{
	uint32_t mask;

	mask = CCSR_GUTS_DEVDISR_TB0 | CCSR_GUTS_DEVDISR_TB1;
	if (freeze)
		setbits32(&guts->devdisr, mask);
	else
		clrbits32(&guts->devdisr, mask);

	in_be32(&guts->devdisr);
}

