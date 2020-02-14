#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct gpio_device {int ngpio; TYPE_2__* descs; int /*<<< orphan*/  dev; } ;
struct gpio_desc {TYPE_1__* gdev; } ;
struct gpio_chip {struct gpio_device* gpiodev; } ;
struct fwnode_handle {int dummy; } ;
struct device_node {int dummy; } ;
struct device {int dummy; } ;
struct acpi_gpio_info {int dummy; } ;
struct acpi_device {int dummy; } ;
typedef  enum of_gpio_flags { ____Placeholder_of_gpio_flags } of_gpio_flags ;
typedef  enum gpiod_flags { ____Placeholder_gpiod_flags } gpiod_flags ;
typedef  enum gpio_lookup_flags { ____Placeholder_gpio_lookup_flags } gpio_lookup_flags ;
struct TYPE_4__ {char const* name; } ;
struct TYPE_3__ {struct gpio_desc const* descs; } ;

/* Variables and functions */
 int ENODEV ; 
 int /*<<< orphan*/  ENOENT ; 
 int /*<<< orphan*/  ENXIO ; 
 struct gpio_desc* ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*,...) ; 
 int fwnode_property_read_string_array (struct fwnode_handle const*,char*,char const**,int) ; 
 char** kcalloc (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (char const**) ; 

__attribute__((used)) static inline struct gpio_desc *of_find_gpio(struct device *dev,
					     const char *con_id,
					     unsigned int idx,
					     enum gpio_lookup_flags *flags)
{
	return ERR_PTR(-ENOENT);
}

__attribute__((used)) static inline struct gpio_desc *of_get_named_gpiod_flags(struct device_node *np,
		   const char *list_name, int index, enum of_gpio_flags *flags)
{
	return ERR_PTR(-ENOENT);
}

__attribute__((used)) static inline int of_gpiochip_add(struct gpio_chip *gc) { return 0; }

__attribute__((used)) static inline void of_gpiochip_remove(struct gpio_chip *gc) { }

__attribute__((used)) static inline void acpi_gpiochip_add(struct gpio_chip *chip) { }

__attribute__((used)) static inline void acpi_gpiochip_remove(struct gpio_chip *chip) { }

__attribute__((used)) static inline void
acpi_gpiochip_request_interrupts(struct gpio_chip *chip) { }

__attribute__((used)) static inline void
acpi_gpiochip_free_interrupts(struct gpio_chip *chip) { }

__attribute__((used)) static inline int
acpi_gpio_update_gpiod_flags(enum gpiod_flags *flags, struct acpi_gpio_info *info)
{
	return 0;
}

__attribute__((used)) static inline struct gpio_desc *
acpi_find_gpio(struct device *dev, const char *con_id,
	       unsigned int idx, enum gpiod_flags *dflags,
	       enum gpio_lookup_flags *lookupflags)
{
	return ERR_PTR(-ENOENT);
}

__attribute__((used)) static inline struct gpio_desc *
acpi_node_get_gpiod(struct fwnode_handle *fwnode, const char *propname,
		    int index, struct acpi_gpio_info *info)
{
	return ERR_PTR(-ENXIO);
}

__attribute__((used)) static inline int acpi_gpio_count(struct device *dev, const char *con_id)
{
	return -ENODEV;
}

__attribute__((used)) static inline bool acpi_can_fallback_to_crs(struct acpi_device *adev,
					    const char *con_id)
{
	return false;
}

__attribute__((used)) static inline int gpio_chip_hwgpio(const struct gpio_desc *desc)
{
	return desc - &desc->gdev->descs[0];
}

__attribute__((used)) static inline int gpiochip_sysfs_register(struct gpio_device *gdev)
{
	return 0;
}

__attribute__((used)) static inline void gpiochip_sysfs_unregister(struct gpio_device *gdev)
{
}

void devprop_gpiochip_set_names(struct gpio_chip *chip,
				const struct fwnode_handle *fwnode)
{
	struct gpio_device *gdev = chip->gpiodev;
	const char **names;
	int ret, i;

	ret = fwnode_property_read_string_array(fwnode, "gpio-line-names",
						NULL, 0);
	if (ret < 0)
		return;

	if (ret != gdev->ngpio) {
		dev_warn(&gdev->dev,
			 "names %d do not match number of GPIOs %d\n", ret,
			 gdev->ngpio);
		return;
	}

	names = kcalloc(gdev->ngpio, sizeof(*names), GFP_KERNEL);
	if (!names)
		return;

	ret = fwnode_property_read_string_array(fwnode, "gpio-line-names",
						names, gdev->ngpio);
	if (ret < 0) {
		dev_warn(&gdev->dev, "failed to read GPIO line names\n");
		kfree(names);
		return;
	}

	for (i = 0; i < gdev->ngpio; i++)
		gdev->descs[i].name = names[i];

	kfree(names);
}

