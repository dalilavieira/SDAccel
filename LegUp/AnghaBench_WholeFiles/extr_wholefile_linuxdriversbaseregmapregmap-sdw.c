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
struct sdw_slave {int /*<<< orphan*/  dev; } ;
struct regmap_config {int val_bits; int reg_bits; scalar_t__ pad_bits; } ;
struct regmap {unsigned int cache_word_size; char const* name; unsigned int reg_stride_order; unsigned int reg_stride; scalar_t__ dev; } ;
struct lock_class_key {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int ENOTSUPP ; 
 struct regmap* ERR_PTR (int) ; 
 struct regmap* __devm_regmap_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct regmap_config const*,struct lock_class_key*,char const*) ; 
 struct regmap* __regmap_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct regmap_config const*,struct lock_class_key*,char const*) ; 
 char const* dev_name (scalar_t__) ; 
 struct sdw_slave* dev_to_sdw_dev (struct device*) ; 
 int /*<<< orphan*/  regmap_sdw ; 
 int sdw_read (struct sdw_slave*,unsigned int) ; 
 int sdw_write (struct sdw_slave*,unsigned int,unsigned int) ; 

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

__attribute__((used)) static int regmap_sdw_write(void *context, unsigned int reg, unsigned int val)
{
	struct device *dev = context;
	struct sdw_slave *slave = dev_to_sdw_dev(dev);

	return sdw_write(slave, reg, val);
}

__attribute__((used)) static int regmap_sdw_read(void *context, unsigned int reg, unsigned int *val)
{
	struct device *dev = context;
	struct sdw_slave *slave = dev_to_sdw_dev(dev);
	int read;

	read = sdw_read(slave, reg);
	if (read < 0)
		return read;

	*val = read;
	return 0;
}

__attribute__((used)) static int regmap_sdw_config_check(const struct regmap_config *config)
{
	/* All register are 8-bits wide as per MIPI Soundwire 1.0 Spec */
	if (config->val_bits != 8)
		return -ENOTSUPP;

	/* Registers are 32 bits wide */
	if (config->reg_bits != 32)
		return -ENOTSUPP;

	if (config->pad_bits != 0)
		return -ENOTSUPP;

	return 0;
}

struct regmap *__regmap_init_sdw(struct sdw_slave *sdw,
				 const struct regmap_config *config,
				 struct lock_class_key *lock_key,
				 const char *lock_name)
{
	int ret;

	ret = regmap_sdw_config_check(config);
	if (ret)
		return ERR_PTR(ret);

	return __regmap_init(&sdw->dev, &regmap_sdw,
			&sdw->dev, config, lock_key, lock_name);
}

struct regmap *__devm_regmap_init_sdw(struct sdw_slave *sdw,
				      const struct regmap_config *config,
				      struct lock_class_key *lock_key,
				      const char *lock_name)
{
	int ret;

	ret = regmap_sdw_config_check(config);
	if (ret)
		return ERR_PTR(ret);

	return __devm_regmap_init(&sdw->dev, &regmap_sdw,
			&sdw->dev, config, lock_key, lock_name);
}

