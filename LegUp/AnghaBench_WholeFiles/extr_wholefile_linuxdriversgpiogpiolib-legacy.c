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
struct gpio_device {int dummy; } ;
struct gpio_desc {int /*<<< orphan*/  flags; TYPE_1__* gdev; } ;
struct gpio_chip {int dummy; } ;
struct gpio {unsigned int gpio; unsigned long flags; char* label; } ;
struct fwnode_handle {int dummy; } ;
struct device_node {int dummy; } ;
struct device {int dummy; } ;
struct acpi_gpio_info {int dummy; } ;
struct acpi_device {int dummy; } ;
typedef  enum of_gpio_flags { ____Placeholder_of_gpio_flags } of_gpio_flags ;
typedef  enum gpiod_flags { ____Placeholder_gpiod_flags } gpiod_flags ;
typedef  enum gpio_lookup_flags { ____Placeholder_gpio_lookup_flags } gpio_lookup_flags ;
struct TYPE_4__ {unsigned int gpio; } ;
struct TYPE_3__ {struct gpio_desc const* descs; } ;

/* Variables and functions */
 int ENODEV ; 
 int /*<<< orphan*/  ENOENT ; 
 int /*<<< orphan*/  ENXIO ; 
 int EPROBE_DEFER ; 
 struct gpio_desc* ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FLAG_ACTIVE_LOW ; 
 int /*<<< orphan*/  FLAG_OPEN_DRAIN ; 
 int /*<<< orphan*/  FLAG_OPEN_SOURCE ; 
 unsigned long GPIOF_ACTIVE_LOW ; 
 unsigned long GPIOF_DIR_IN ; 
 unsigned long GPIOF_EXPORT ; 
 unsigned long GPIOF_EXPORT_CHANGEABLE ; 
 unsigned long GPIOF_INIT_HIGH ; 
 unsigned long GPIOF_OPEN_DRAIN ; 
 unsigned long GPIOF_OPEN_SOURCE ; 
 scalar_t__ gpio_is_valid (unsigned int) ; 
 struct gpio_desc* gpio_to_desc (unsigned int) ; 
 int gpiod_direction_input (struct gpio_desc*) ; 
 int gpiod_direction_output_raw (struct gpio_desc*,int) ; 
 int gpiod_export (struct gpio_desc*,unsigned long) ; 
 int /*<<< orphan*/  gpiod_free (struct gpio_desc*) ; 
 int gpiod_request (struct gpio_desc*,char const*) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

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

void gpio_free(unsigned gpio)
{
	gpiod_free(gpio_to_desc(gpio));
}

int gpio_request_one(unsigned gpio, unsigned long flags, const char *label)
{
	struct gpio_desc *desc;
	int err;

	desc = gpio_to_desc(gpio);

	/* Compatibility: assume unavailable "valid" GPIOs will appear later */
	if (!desc && gpio_is_valid(gpio))
		return -EPROBE_DEFER;

	err = gpiod_request(desc, label);
	if (err)
		return err;

	if (flags & GPIOF_OPEN_DRAIN)
		set_bit(FLAG_OPEN_DRAIN, &desc->flags);

	if (flags & GPIOF_OPEN_SOURCE)
		set_bit(FLAG_OPEN_SOURCE, &desc->flags);

	if (flags & GPIOF_ACTIVE_LOW)
		set_bit(FLAG_ACTIVE_LOW, &desc->flags);

	if (flags & GPIOF_DIR_IN)
		err = gpiod_direction_input(desc);
	else
		err = gpiod_direction_output_raw(desc,
				(flags & GPIOF_INIT_HIGH) ? 1 : 0);

	if (err)
		goto free_gpio;

	if (flags & GPIOF_EXPORT) {
		err = gpiod_export(desc, flags & GPIOF_EXPORT_CHANGEABLE);
		if (err)
			goto free_gpio;
	}

	return 0;

 free_gpio:
	gpiod_free(desc);
	return err;
}

int gpio_request(unsigned gpio, const char *label)
{
	struct gpio_desc *desc = gpio_to_desc(gpio);

	/* Compatibility: assume unavailable "valid" GPIOs will appear later */
	if (!desc && gpio_is_valid(gpio))
		return -EPROBE_DEFER;

	return gpiod_request(desc, label);
}

int gpio_request_array(const struct gpio *array, size_t num)
{
	int i, err;

	for (i = 0; i < num; i++, array++) {
		err = gpio_request_one(array->gpio, array->flags, array->label);
		if (err)
			goto err_free;
	}
	return 0;

err_free:
	while (i--)
		gpio_free((--array)->gpio);
	return err;
}

void gpio_free_array(const struct gpio *array, size_t num)
{
	while (num--)
		gpio_free((array++)->gpio);
}

