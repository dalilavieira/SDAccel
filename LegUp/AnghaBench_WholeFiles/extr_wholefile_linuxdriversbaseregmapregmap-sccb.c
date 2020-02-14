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
union i2c_smbus_data {unsigned int byte; } ;
typedef  int u32 ;
struct regmap_config {int val_bits; int reg_bits; } ;
struct regmap_bus {int dummy; } ;
struct regmap {unsigned int cache_word_size; char const* name; unsigned int reg_stride_order; unsigned int reg_stride; scalar_t__ dev; } ;
struct lock_class_key {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; struct i2c_adapter* adapter; int /*<<< orphan*/  flags; int /*<<< orphan*/  addr; } ;
struct i2c_adapter {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ENOTSUPP ; 
 struct regmap* ERR_CAST (struct regmap_bus const*) ; 
 struct regmap_bus const* ERR_PTR (int /*<<< orphan*/ ) ; 
 int I2C_FUNC_SMBUS_BYTE ; 
 int I2C_FUNC_SMBUS_WRITE_BYTE_DATA ; 
 int /*<<< orphan*/  I2C_LOCK_SEGMENT ; 
 int /*<<< orphan*/  I2C_SMBUS_BYTE ; 
 int /*<<< orphan*/  I2C_SMBUS_READ ; 
 int /*<<< orphan*/  I2C_SMBUS_WRITE ; 
 scalar_t__ IS_ERR (struct regmap_bus const*) ; 
 struct regmap* __devm_regmap_init (int /*<<< orphan*/ *,struct regmap_bus const*,int /*<<< orphan*/ *,struct regmap_config const*,struct lock_class_key*,char const*) ; 
 int __i2c_smbus_xfer (struct i2c_adapter*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,int /*<<< orphan*/ ,union i2c_smbus_data*) ; 
 struct regmap* __regmap_init (int /*<<< orphan*/ *,struct regmap_bus const*,int /*<<< orphan*/ *,struct regmap_config const*,struct lock_class_key*,char const*) ; 
 char const* dev_name (scalar_t__) ; 
 int i2c_get_functionality (struct i2c_adapter*) ; 
 int /*<<< orphan*/  i2c_lock_bus (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  i2c_unlock_bus (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 struct regmap_bus const regmap_sccb_bus ; 
 struct i2c_client* to_i2c_client (struct device*) ; 

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

__attribute__((used)) static bool sccb_is_available(struct i2c_adapter *adap)
{
	u32 needed_funcs = I2C_FUNC_SMBUS_BYTE | I2C_FUNC_SMBUS_WRITE_BYTE_DATA;

	/*
	 * If we ever want support for hardware doing SCCB natively, we will
	 * introduce a sccb_xfer() callback to struct i2c_algorithm and check
	 * for it here.
	 */

	return (i2c_get_functionality(adap) & needed_funcs) == needed_funcs;
}

__attribute__((used)) static int regmap_sccb_read(void *context, unsigned int reg, unsigned int *val)
{
	struct device *dev = context;
	struct i2c_client *i2c = to_i2c_client(dev);
	int ret;
	union i2c_smbus_data data;

	i2c_lock_bus(i2c->adapter, I2C_LOCK_SEGMENT);

	ret = __i2c_smbus_xfer(i2c->adapter, i2c->addr, i2c->flags,
			       I2C_SMBUS_WRITE, reg, I2C_SMBUS_BYTE, NULL);
	if (ret < 0)
		goto out;

	ret = __i2c_smbus_xfer(i2c->adapter, i2c->addr, i2c->flags,
			       I2C_SMBUS_READ, 0, I2C_SMBUS_BYTE, &data);
	if (ret < 0)
		goto out;

	*val = data.byte;
out:
	i2c_unlock_bus(i2c->adapter, I2C_LOCK_SEGMENT);

	return ret;
}

__attribute__((used)) static int regmap_sccb_write(void *context, unsigned int reg, unsigned int val)
{
	struct device *dev = context;
	struct i2c_client *i2c = to_i2c_client(dev);

	return i2c_smbus_write_byte_data(i2c, reg, val);
}

__attribute__((used)) static const struct regmap_bus *regmap_get_sccb_bus(struct i2c_client *i2c,
					const struct regmap_config *config)
{
	if (config->val_bits == 8 && config->reg_bits == 8 &&
			sccb_is_available(i2c->adapter))
		return &regmap_sccb_bus;

	return ERR_PTR(-ENOTSUPP);
}

struct regmap *__regmap_init_sccb(struct i2c_client *i2c,
				  const struct regmap_config *config,
				  struct lock_class_key *lock_key,
				  const char *lock_name)
{
	const struct regmap_bus *bus = regmap_get_sccb_bus(i2c, config);

	if (IS_ERR(bus))
		return ERR_CAST(bus);

	return __regmap_init(&i2c->dev, bus, &i2c->dev, config,
			     lock_key, lock_name);
}

struct regmap *__devm_regmap_init_sccb(struct i2c_client *i2c,
				       const struct regmap_config *config,
				       struct lock_class_key *lock_key,
				       const char *lock_name)
{
	const struct regmap_bus *bus = regmap_get_sccb_bus(i2c, config);

	if (IS_ERR(bus))
		return ERR_CAST(bus);

	return __devm_regmap_init(&i2c->dev, bus, &i2c->dev, config,
				  lock_key, lock_name);
}

