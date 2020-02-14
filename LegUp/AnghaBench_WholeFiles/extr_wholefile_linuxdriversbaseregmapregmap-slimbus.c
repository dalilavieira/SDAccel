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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u16 ;
struct slim_device {int /*<<< orphan*/  dev; } ;
struct regmap_config {int val_bits; int reg_bits; } ;
struct regmap_bus {int dummy; } ;
struct regmap {unsigned int cache_word_size; char const* name; unsigned int reg_stride_order; unsigned int reg_stride; scalar_t__ dev; } ;
struct lock_class_key {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ENOTSUPP ; 
 struct regmap* ERR_CAST (struct regmap_bus const*) ; 
 struct regmap_bus const* ERR_PTR (int /*<<< orphan*/ ) ; 
 scalar_t__ IS_ERR (struct regmap_bus const*) ; 
 struct regmap* __devm_regmap_init (int /*<<< orphan*/ *,struct regmap_bus const*,struct slim_device**,struct regmap_config const*,struct lock_class_key*,char const*) ; 
 struct regmap* __regmap_init (int /*<<< orphan*/ *,struct regmap_bus const*,int /*<<< orphan*/ *,struct regmap_config const*,struct lock_class_key*,char const*) ; 
 char const* dev_name (scalar_t__) ; 
 struct regmap_bus const regmap_slimbus_bus ; 
 int slim_read (struct slim_device*,int /*<<< orphan*/ ,size_t,void*) ; 
 int slim_write (struct slim_device*,int /*<<< orphan*/ ,size_t,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void regmap_debugfs_initcall(void) { }

__attribute__((used)) static inline void regmap_debugfs_init(struct regmap *map, const char *name) { }

__attribute__((used)) static inline void regmap_debugfs_exit(struct regmap *map) { }

__attribute__((used)) static inline void regmap_debugfs_disable(struct regmap *map) { }

__attribute__((used)) static inline const void *regcache_get_val_addr(struct regmap *map,
						const void *base,
						unsigned int idx)
{
	return base + (map->cache_word_size * idx);
}

__attribute__((used)) static inline const char *regmap_name(const struct regmap *map)
{
	if (map->dev)
		return dev_name(map->dev);

	return map->name;
}

__attribute__((used)) static inline unsigned int regmap_get_offset(const struct regmap *map,
					     unsigned int index)
{
	if (map->reg_stride_order >= 0)
		return index << map->reg_stride_order;
	else
		return index * map->reg_stride;
}

__attribute__((used)) static inline unsigned int regcache_get_index_by_order(const struct regmap *map,
						       unsigned int reg)
{
	return reg >> map->reg_stride_order;
}

__attribute__((used)) static int regmap_slimbus_write(void *context, const void *data, size_t count)
{
	struct slim_device *sdev = context;

	return slim_write(sdev, *(u16 *)data, count - 2, (u8 *)data + 2);
}

__attribute__((used)) static int regmap_slimbus_read(void *context, const void *reg, size_t reg_size,
			       void *val, size_t val_size)
{
	struct slim_device *sdev = context;

	return slim_read(sdev, *(u16 *)reg, val_size, val);
}

__attribute__((used)) static const struct regmap_bus *regmap_get_slimbus(struct slim_device *slim,
					const struct regmap_config *config)
{
	if (config->val_bits == 8 && config->reg_bits == 16)
		return &regmap_slimbus_bus;

	return ERR_PTR(-ENOTSUPP);
}

struct regmap *__regmap_init_slimbus(struct slim_device *slimbus,
				     const struct regmap_config *config,
				     struct lock_class_key *lock_key,
				     const char *lock_name)
{
	const struct regmap_bus *bus = regmap_get_slimbus(slimbus, config);

	if (IS_ERR(bus))
		return ERR_CAST(bus);

	return __regmap_init(&slimbus->dev, bus, &slimbus->dev, config,
			     lock_key, lock_name);
}

struct regmap *__devm_regmap_init_slimbus(struct slim_device *slimbus,
					  const struct regmap_config *config,
					  struct lock_class_key *lock_key,
					  const char *lock_name)
{
	const struct regmap_bus *bus = regmap_get_slimbus(slimbus, config);

	if (IS_ERR(bus))
		return ERR_CAST(bus);

	return __devm_regmap_init(&slimbus->dev, bus, &slimbus, config,
				  lock_key, lock_name);
}

