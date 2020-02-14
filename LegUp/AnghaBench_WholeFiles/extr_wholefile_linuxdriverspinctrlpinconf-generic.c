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
struct seq_file {int dummy; } ;
struct pinctrl_setting {int dummy; } ;
struct pinctrl_map {int dummy; } ;
struct pinctrl_dev {int /*<<< orphan*/  pin_desc_tree; } ;
struct pin_desc {int dummy; } ;
struct dentry {int dummy; } ;

/* Variables and functions */
 int ENOTSUPP ; 
 struct pin_desc* radix_tree_lookup (int /*<<< orphan*/ *,unsigned int) ; 

__attribute__((used)) static inline struct pin_desc *pin_desc_get(struct pinctrl_dev *pctldev,
					    unsigned int pin)
{
	return radix_tree_lookup(&pctldev->pin_desc_tree, pin);
}

__attribute__((used)) static inline int pinconf_check_ops(struct pinctrl_dev *pctldev)
{
	return 0;
}

__attribute__((used)) static inline int pinconf_validate_map(const struct pinctrl_map *map, int i)
{
	return 0;
}

__attribute__((used)) static inline int pinconf_map_to_setting(const struct pinctrl_map *map,
			  struct pinctrl_setting *setting)
{
	return 0;
}

__attribute__((used)) static inline void pinconf_free_setting(const struct pinctrl_setting *setting)
{
}

__attribute__((used)) static inline int pinconf_apply_setting(const struct pinctrl_setting *setting)
{
	return 0;
}

__attribute__((used)) static inline int pinconf_set_config(struct pinctrl_dev *pctldev, unsigned pin,
				     unsigned long *configs, size_t nconfigs)
{
	return -ENOTSUPP;
}

__attribute__((used)) static inline void pinconf_show_map(struct seq_file *s,
				    const struct pinctrl_map *map)
{
}

__attribute__((used)) static inline void pinconf_show_setting(struct seq_file *s,
					const struct pinctrl_setting *setting)
{
}

__attribute__((used)) static inline void pinconf_init_device_debugfs(struct dentry *devroot,
					       struct pinctrl_dev *pctldev)
{
}

__attribute__((used)) static inline void pinconf_generic_dump_pins(struct pinctrl_dev *pctldev,
					     struct seq_file *s,
					     const char *gname, unsigned pin)
{
	return;
}

__attribute__((used)) static inline void pinconf_generic_dump_config(struct pinctrl_dev *pctldev,
					       struct seq_file *s,
					       unsigned long config)
{
	return;
}

