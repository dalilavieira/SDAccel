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
struct property {size_t length; void const* value; } ;
typedef  void const nvmem_cell ;
struct device_node {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 size_t ETH_ALEN ; 
 scalar_t__ IS_ERR (void const*) ; 
 int PHY_INTERFACE_MODE_MAX ; 
 int PTR_ERR (void const*) ; 
 int /*<<< orphan*/  ether_addr_copy (void*,void const*) ; 
 scalar_t__ is_valid_ether_addr (void const*) ; 
 int /*<<< orphan*/  kfree (void const*) ; 
 int /*<<< orphan*/  nvmem_cell_put (void const*) ; 
 void* nvmem_cell_read (void const*,size_t*) ; 
 struct property* of_find_property (struct device_node*,char const*,int /*<<< orphan*/ *) ; 
 void* of_nvmem_cell_get (struct device_node*,char*) ; 
 int of_property_read_string (struct device_node*,char*,char const**) ; 
 int /*<<< orphan*/  phy_modes (int) ; 
 int /*<<< orphan*/  strcasecmp (char const*,int /*<<< orphan*/ ) ; 

int of_get_phy_mode(struct device_node *np)
{
	const char *pm;
	int err, i;

	err = of_property_read_string(np, "phy-mode", &pm);
	if (err < 0)
		err = of_property_read_string(np, "phy-connection-type", &pm);
	if (err < 0)
		return err;

	for (i = 0; i < PHY_INTERFACE_MODE_MAX; i++)
		if (!strcasecmp(pm, phy_modes(i)))
			return i;

	return -ENODEV;
}

__attribute__((used)) static const void *of_get_mac_addr(struct device_node *np, const char *name)
{
	struct property *pp = of_find_property(np, name, NULL);

	if (pp && pp->length == ETH_ALEN && is_valid_ether_addr(pp->value))
		return pp->value;
	return NULL;
}

const void *of_get_mac_address(struct device_node *np)
{
	const void *addr;

	addr = of_get_mac_addr(np, "mac-address");
	if (addr)
		return addr;

	addr = of_get_mac_addr(np, "local-mac-address");
	if (addr)
		return addr;

	return of_get_mac_addr(np, "address");
}

int of_get_nvmem_mac_address(struct device_node *np, void *addr)
{
	struct nvmem_cell *cell;
	const void *mac;
	size_t len;
	int ret;

	cell = of_nvmem_cell_get(np, "mac-address");
	if (IS_ERR(cell))
		return PTR_ERR(cell);

	mac = nvmem_cell_read(cell, &len);

	nvmem_cell_put(cell);

	if (IS_ERR(mac))
		return PTR_ERR(mac);

	if (len < ETH_ALEN || !is_valid_ether_addr(mac)) {
		ret = -EINVAL;
	} else {
		ether_addr_copy(addr, mac);
		ret = 0;
	}

	kfree(mac);

	return ret;
}

