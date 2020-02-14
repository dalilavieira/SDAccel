#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct regmap {unsigned int cache_word_size; char const* name; unsigned int reg_stride_order; unsigned int reg_stride; unsigned int max_register; unsigned int* cache; int num_reg_defaults; TYPE_1__* reg_defaults; scalar_t__ dev; } ;
struct TYPE_2__ {unsigned int reg; unsigned int def; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 char const* dev_name (scalar_t__) ; 
 unsigned int* kcalloc (unsigned int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (unsigned int*) ; 

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

__attribute__((used)) static inline unsigned int regcache_flat_get_index(const struct regmap *map,
						   unsigned int reg)
{
	return regcache_get_index_by_order(map, reg);
}

__attribute__((used)) static int regcache_flat_init(struct regmap *map)
{
	int i;
	unsigned int *cache;

	if (!map || map->reg_stride_order < 0 || !map->max_register)
		return -EINVAL;

	map->cache = kcalloc(regcache_flat_get_index(map, map->max_register)
			     + 1, sizeof(unsigned int), GFP_KERNEL);
	if (!map->cache)
		return -ENOMEM;

	cache = map->cache;

	for (i = 0; i < map->num_reg_defaults; i++) {
		unsigned int reg = map->reg_defaults[i].reg;
		unsigned int index = regcache_flat_get_index(map, reg);

		cache[index] = map->reg_defaults[i].def;
	}

	return 0;
}

__attribute__((used)) static int regcache_flat_exit(struct regmap *map)
{
	kfree(map->cache);
	map->cache = NULL;

	return 0;
}

__attribute__((used)) static int regcache_flat_read(struct regmap *map,
			      unsigned int reg, unsigned int *value)
{
	unsigned int *cache = map->cache;
	unsigned int index = regcache_flat_get_index(map, reg);

	*value = cache[index];

	return 0;
}

__attribute__((used)) static int regcache_flat_write(struct regmap *map, unsigned int reg,
			       unsigned int value)
{
	unsigned int *cache = map->cache;
	unsigned int index = regcache_flat_get_index(map, reg);

	cache[index] = value;

	return 0;
}

