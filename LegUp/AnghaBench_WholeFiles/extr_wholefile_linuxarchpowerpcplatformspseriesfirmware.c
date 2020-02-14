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
struct pseries_hp_errorlog {int dummy; } ;

/* Variables and functions */
 unsigned long CMO_PageSize ; 
 int CMO_PrPSP ; 
 int CMO_SecPSP ; 
 int EOPNOTSUPP ; 

__attribute__((used)) static inline void smp_init_pseries(void) { }

__attribute__((used)) static inline int dlpar_memory(struct pseries_hp_errorlog *hp_elog)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline int dlpar_cpu(struct pseries_hp_errorlog *hp_elog)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline int cmo_get_primary_psp(void)
{
	return CMO_PrPSP;
}

__attribute__((used)) static inline int cmo_get_secondary_psp(void)
{
	return CMO_SecPSP;
}

__attribute__((used)) static inline unsigned long cmo_get_page_size(void)
{
	return CMO_PageSize;
}

