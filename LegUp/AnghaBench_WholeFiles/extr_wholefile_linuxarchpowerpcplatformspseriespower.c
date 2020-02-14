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
struct kobject {int dummy; } ;
struct kobj_attribute {int dummy; } ;
typedef  size_t ssize_t ;

/* Variables and functions */
 unsigned long CMO_PageSize ; 
 int CMO_PrPSP ; 
 int CMO_SecPSP ; 
 size_t EINVAL ; 
 int EOPNOTSUPP ; 
 unsigned long rtas_poweron_auto ; 
 size_t sprintf (char*,char*,unsigned long) ; 
 int sscanf (char const*,char*,unsigned long*) ; 

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

__attribute__((used)) static ssize_t auto_poweron_show(struct kobject *kobj,
				 struct kobj_attribute *attr, char *buf)
{
        return sprintf(buf, "%lu\n", rtas_poweron_auto);
}

__attribute__((used)) static ssize_t auto_poweron_store(struct kobject *kobj,
				  struct kobj_attribute *attr,
				  const char *buf, size_t n)
{
	int ret;
	unsigned long ups_restart;
	ret = sscanf(buf, "%lu", &ups_restart);

	if ((ret == 1) && ((ups_restart == 1) || (ups_restart == 0))){
		rtas_poweron_auto = ups_restart;
		return n;
	}
	return -EINVAL;
}

