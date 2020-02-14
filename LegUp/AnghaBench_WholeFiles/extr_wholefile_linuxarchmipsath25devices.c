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
struct TYPE_2__ {scalar_t__ cputype; } ;

/* Variables and functions */
 size_t ARRAY_SIZE (char const**) ; 
 size_t ATH25_SOC_UNKNOWN ; 
 scalar_t__ CPU_4KEC ; 
 size_t ath25_soc ; 
 TYPE_1__ current_cpu_data ; 
 char const** soc_type_strings ; 

__attribute__((used)) static inline bool is_ar2315(void)
{
	return (current_cpu_data.cputype == CPU_4KEC);
}

__attribute__((used)) static inline bool is_ar5312(void)
{
	return !is_ar2315();
}

__attribute__((used)) static inline void ar5312_arch_init_irq(void) {}

__attribute__((used)) static inline void ar5312_init_devices(void) {}

__attribute__((used)) static inline void ar5312_plat_time_init(void) {}

__attribute__((used)) static inline void ar5312_plat_mem_setup(void) {}

__attribute__((used)) static inline void ar5312_arch_init(void) {}

__attribute__((used)) static inline void ar2315_arch_init_irq(void) {}

__attribute__((used)) static inline void ar2315_init_devices(void) {}

__attribute__((used)) static inline void ar2315_plat_time_init(void) {}

__attribute__((used)) static inline void ar2315_plat_mem_setup(void) {}

__attribute__((used)) static inline void ar2315_arch_init(void) {}

const char *get_system_type(void)
{
	if ((ath25_soc >= ARRAY_SIZE(soc_type_strings)) ||
	    !soc_type_strings[ath25_soc])
		return soc_type_strings[ATH25_SOC_UNKNOWN];
	return soc_type_strings[ath25_soc];
}

