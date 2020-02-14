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
struct property {int dummy; } ;
struct of_drc_info {char* drc_type; char* drc_name_prefix; int drc_index_start; int drc_name_suffix_start; int num_sequential_elems; int sequential_inc; int drc_power_domain; scalar_t__ last_drc_index; } ;
struct device_node {int dummy; } ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 struct device_node* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 char* kbasename (char const*) ; 
 int /*<<< orphan*/  kfree (char*) ; 
 char* kstrndup (char const*,int,int /*<<< orphan*/ ) ; 
 struct device_node* of_find_node_by_path (char*) ; 
 char* of_prop_next_string (struct property*,char const*) ; 
 int /*<<< orphan*/ * of_prop_next_u32 (struct property*,int /*<<< orphan*/  const*,int*) ; 
 scalar_t__ strcmp (char const*,char*) ; 

struct device_node *pseries_of_derive_parent(const char *path)
{
	struct device_node *parent;
	char *parent_path = "/";
	const char *tail;

	/* We do not want the trailing '/' character */
	tail = kbasename(path) - 1;

	/* reject if path is "/" */
	if (!strcmp(path, "/"))
		return ERR_PTR(-EINVAL);

	if (tail > path) {
		parent_path = kstrndup(path, tail - path, GFP_KERNEL);
		if (!parent_path)
			return ERR_PTR(-ENOMEM);
	}
	parent = of_find_node_by_path(parent_path);
	if (strcmp(parent_path, "/"))
		kfree(parent_path);
	return parent ? parent : ERR_PTR(-EINVAL);
}

int of_read_drc_info_cell(struct property **prop, const __be32 **curval,
			struct of_drc_info *data)
{
	const char *p;
	const __be32 *p2;

	if (!data)
		return -EINVAL;

	/* Get drc-type:encode-string */
	p = data->drc_type = (char*) (*curval);
	p = of_prop_next_string(*prop, p);
	if (!p)
		return -EINVAL;

	/* Get drc-name-prefix:encode-string */
	data->drc_name_prefix = (char *)p;
	p = of_prop_next_string(*prop, p);
	if (!p)
		return -EINVAL;

	/* Get drc-index-start:encode-int */
	p2 = (const __be32 *)p;
	p2 = of_prop_next_u32(*prop, p2, &data->drc_index_start);
	if (!p2)
		return -EINVAL;

	/* Get drc-name-suffix-start:encode-int */
	p2 = of_prop_next_u32(*prop, p2, &data->drc_name_suffix_start);
	if (!p2)
		return -EINVAL;

	/* Get number-sequential-elements:encode-int */
	p2 = of_prop_next_u32(*prop, p2, &data->num_sequential_elems);
	if (!p2)
		return -EINVAL;

	/* Get sequential-increment:encode-int */
	p2 = of_prop_next_u32(*prop, p2, &data->sequential_inc);
	if (!p2)
		return -EINVAL;

	/* Get drc-power-domain:encode-int */
	p2 = of_prop_next_u32(*prop, p2, &data->drc_power_domain);
	if (!p2)
		return -EINVAL;

	/* Should now know end of current entry */
	(*curval) = (void *)p2;
	data->last_drc_index = data->drc_index_start +
		((data->num_sequential_elems - 1) * data->sequential_inc);

	return 0;
}

