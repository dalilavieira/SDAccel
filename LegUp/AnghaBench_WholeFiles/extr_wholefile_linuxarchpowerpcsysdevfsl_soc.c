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
typedef  int u32 ;
struct device_node {int dummy; } ;
typedef  int phys_addr_t ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 int be32_to_cpup (int /*<<< orphan*/  const*) ; 
 int immrbase ; 
 struct device_node* of_find_node_by_type (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/ * of_get_property (struct device_node*,char*,int*) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 int /*<<< orphan*/  of_property_read_u32 (struct device_node*,char*,int*) ; 
 int of_translate_address (struct device_node*,int /*<<< orphan*/  const*) ; 

phys_addr_t get_immrbase(void)
{
	struct device_node *soc;

	if (immrbase != -1)
		return immrbase;

	soc = of_find_node_by_type(NULL, "soc");
	if (soc) {
		int size;
		u32 naddr;
		const __be32 *prop = of_get_property(soc, "#address-cells", &size);

		if (prop && size == 4)
			naddr = be32_to_cpup(prop);
		else
			naddr = 2;

		prop = of_get_property(soc, "ranges", &size);
		if (prop)
			immrbase = of_translate_address(soc, prop + naddr);

		of_node_put(soc);
	}

	return immrbase;
}

u32 fsl_get_sys_freq(void)
{
	static u32 sysfreq = -1;
	struct device_node *soc;

	if (sysfreq != -1)
		return sysfreq;

	soc = of_find_node_by_type(NULL, "soc");
	if (!soc)
		return -1;

	of_property_read_u32(soc, "clock-frequency", &sysfreq);
	if (sysfreq == -1 || !sysfreq)
		of_property_read_u32(soc, "bus-frequency", &sysfreq);

	of_node_put(soc);
	return sysfreq;
}

