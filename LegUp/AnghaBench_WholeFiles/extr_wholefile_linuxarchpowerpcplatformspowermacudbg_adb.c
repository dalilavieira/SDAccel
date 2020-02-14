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

/* Variables and functions */
 int udbg_adb_old_getc () ; 
 int udbg_adb_old_getc_poll () ; 
 void udbg_adb_old_putc (char) ; 

__attribute__((used)) static inline void udbg_adb_poll(void)
{
#ifdef CONFIG_ADB_PMU
	if (input_type == input_adb_pmu)
		pmu_poll_adb();
#endif /* CONFIG_ADB_PMU */
#ifdef CONFIG_ADB_CUDA
	if (input_type == input_adb_cuda)
		cuda_poll();
#endif /* CONFIG_ADB_CUDA */
}

__attribute__((used)) static int udbg_adb_getc(void)
{
#ifdef CONFIG_BOOTX_TEXT
	if (udbg_adb_use_btext && input_type != input_adb_none)
		return udbg_adb_local_getc();
#endif
	if (udbg_adb_old_getc)
		return udbg_adb_old_getc();
	return -1;
}

__attribute__((used)) static int udbg_adb_getc_poll(void)
{
	udbg_adb_poll();

	if (udbg_adb_old_getc_poll)
		return udbg_adb_old_getc_poll();
	return -1;
}

__attribute__((used)) static void udbg_adb_putc(char c)
{
#ifdef CONFIG_BOOTX_TEXT
	if (udbg_adb_use_btext)
		btext_drawchar(c);
#endif
	if (udbg_adb_old_putc)
		return udbg_adb_old_putc(c);
}

