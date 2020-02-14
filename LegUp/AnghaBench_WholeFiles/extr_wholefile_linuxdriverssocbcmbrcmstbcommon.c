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
typedef  int /*<<< orphan*/  u32 ;
struct of_device_id {int dummy; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  brcmstb_machine_match ; 
 int /*<<< orphan*/  family_id ; 
 struct device_node* of_find_node_by_path (char*) ; 
 struct of_device_id* of_match_node (int /*<<< orphan*/ ,struct device_node*) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 int /*<<< orphan*/  product_id ; 

bool soc_is_brcmstb(void)
{
	const struct of_device_id *match;
	struct device_node *root;

	root = of_find_node_by_path("/");
	if (!root)
		return false;

	match = of_match_node(brcmstb_machine_match, root);
	of_node_put(root);

	return match != NULL;
}

u32 brcmstb_get_family_id(void)
{
	return family_id;
}

u32 brcmstb_get_product_id(void)
{
	return product_id;
}

