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
struct regmap_config {int val_bits; int reg_bits; } ;
struct regmap_bus {int dummy; } ;
struct regmap {unsigned int cache_word_size; char const* name; unsigned int reg_stride_order; unsigned int reg_stride; scalar_t__ dev; } ;
struct lock_class_key {int dummy; } ;
struct i2c_msg {size_t len; void* buf; scalar_t__ flags; int /*<<< orphan*/  addr; } ;
struct i2c_client {int /*<<< orphan*/  dev; int /*<<< orphan*/  adapter; int /*<<< orphan*/  addr; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int EIO ; 
 int ENOTSUPP ; 
 struct regmap* ERR_CAST (struct regmap_bus const*) ; 
 struct regmap_bus const* ERR_PTR (int) ; 
 int /*<<< orphan*/  I2C_FUNC_I2C ; 
 int /*<<< orphan*/  I2C_FUNC_NOSTART ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE_DATA ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_I2C_BLOCK ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_WORD_DATA ; 
 scalar_t__ I2C_M_NOSTART ; 
 scalar_t__ I2C_M_RD ; 
 scalar_t__ IS_ERR (struct regmap_bus const*) ; 
#define  REGMAP_ENDIAN_BIG 129 
#define  REGMAP_ENDIAN_LITTLE 128 
 struct regmap* __devm_regmap_init (int /*<<< orphan*/ *,struct regmap_bus const*,int /*<<< orphan*/ *,struct regmap_config const*,struct lock_class_key*,char const*) ; 
 struct regmap* __regmap_init (int /*<<< orphan*/ *,struct regmap_bus const*,int /*<<< orphan*/ *,struct regmap_config const*,struct lock_class_key*,char const*) ; 
 char const* dev_name (scalar_t__) ; 
 scalar_t__ i2c_check_functionality (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int i2c_master_send (struct i2c_client*,void const*,size_t) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,unsigned int) ; 
 int i2c_smbus_read_i2c_block_data (struct i2c_client*,int /*<<< orphan*/ ,size_t,void*) ; 
 int i2c_smbus_read_word_data (struct i2c_client*,unsigned int) ; 
 int i2c_smbus_read_word_swapped (struct i2c_client*,unsigned int) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,unsigned int,unsigned int) ; 
 int i2c_smbus_write_i2c_block_data (struct i2c_client*,int /*<<< orphan*/ ,size_t,int /*<<< orphan*/ *) ; 
 int i2c_smbus_write_word_data (struct i2c_client*,unsigned int,unsigned int) ; 
 int i2c_smbus_write_word_swapped (struct i2c_client*,unsigned int,unsigned int) ; 
 int i2c_transfer (int /*<<< orphan*/ ,struct i2c_msg*,int) ; 
 int regmap_get_val_endian (int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct regmap_config const*) ; 
 struct regmap_bus const regmap_i2c ; 
 struct regmap_bus const regmap_i2c_smbus_i2c_block ; 
 struct regmap_bus const regmap_smbus_byte ; 
 struct regmap_bus const regmap_smbus_word ; 
 struct regmap_bus const regmap_smbus_word_swapped ; 
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

__attribute__((used)) static int regmap_smbus_byte_reg_read(void *context, unsigned int reg,
				      unsigned int *val)
{
	struct device *dev = context;
	struct i2c_client *i2c = to_i2c_client(dev);
	int ret;

	if (reg > 0xff)
		return -EINVAL;

	ret = i2c_smbus_read_byte_data(i2c, reg);
	if (ret < 0)
		return ret;

	*val = ret;

	return 0;
}

__attribute__((used)) static int regmap_smbus_byte_reg_write(void *context, unsigned int reg,
				       unsigned int val)
{
	struct device *dev = context;
	struct i2c_client *i2c = to_i2c_client(dev);

	if (val > 0xff || reg > 0xff)
		return -EINVAL;

	return i2c_smbus_write_byte_data(i2c, reg, val);
}

__attribute__((used)) static int regmap_smbus_word_reg_read(void *context, unsigned int reg,
				      unsigned int *val)
{
	struct device *dev = context;
	struct i2c_client *i2c = to_i2c_client(dev);
	int ret;

	if (reg > 0xff)
		return -EINVAL;

	ret = i2c_smbus_read_word_data(i2c, reg);
	if (ret < 0)
		return ret;

	*val = ret;

	return 0;
}

__attribute__((used)) static int regmap_smbus_word_reg_write(void *context, unsigned int reg,
				       unsigned int val)
{
	struct device *dev = context;
	struct i2c_client *i2c = to_i2c_client(dev);

	if (val > 0xffff || reg > 0xff)
		return -EINVAL;

	return i2c_smbus_write_word_data(i2c, reg, val);
}

__attribute__((used)) static int regmap_smbus_word_read_swapped(void *context, unsigned int reg,
					  unsigned int *val)
{
	struct device *dev = context;
	struct i2c_client *i2c = to_i2c_client(dev);
	int ret;

	if (reg > 0xff)
		return -EINVAL;

	ret = i2c_smbus_read_word_swapped(i2c, reg);
	if (ret < 0)
		return ret;

	*val = ret;

	return 0;
}

__attribute__((used)) static int regmap_smbus_word_write_swapped(void *context, unsigned int reg,
					   unsigned int val)
{
	struct device *dev = context;
	struct i2c_client *i2c = to_i2c_client(dev);

	if (val > 0xffff || reg > 0xff)
		return -EINVAL;

	return i2c_smbus_write_word_swapped(i2c, reg, val);
}

__attribute__((used)) static int regmap_i2c_write(void *context, const void *data, size_t count)
{
	struct device *dev = context;
	struct i2c_client *i2c = to_i2c_client(dev);
	int ret;

	ret = i2c_master_send(i2c, data, count);
	if (ret == count)
		return 0;
	else if (ret < 0)
		return ret;
	else
		return -EIO;
}

__attribute__((used)) static int regmap_i2c_gather_write(void *context,
				   const void *reg, size_t reg_size,
				   const void *val, size_t val_size)
{
	struct device *dev = context;
	struct i2c_client *i2c = to_i2c_client(dev);
	struct i2c_msg xfer[2];
	int ret;

	/* If the I2C controller can't do a gather tell the core, it
	 * will substitute in a linear write for us.
	 */
	if (!i2c_check_functionality(i2c->adapter, I2C_FUNC_NOSTART))
		return -ENOTSUPP;

	xfer[0].addr = i2c->addr;
	xfer[0].flags = 0;
	xfer[0].len = reg_size;
	xfer[0].buf = (void *)reg;

	xfer[1].addr = i2c->addr;
	xfer[1].flags = I2C_M_NOSTART;
	xfer[1].len = val_size;
	xfer[1].buf = (void *)val;

	ret = i2c_transfer(i2c->adapter, xfer, 2);
	if (ret == 2)
		return 0;
	if (ret < 0)
		return ret;
	else
		return -EIO;
}

__attribute__((used)) static int regmap_i2c_read(void *context,
			   const void *reg, size_t reg_size,
			   void *val, size_t val_size)
{
	struct device *dev = context;
	struct i2c_client *i2c = to_i2c_client(dev);
	struct i2c_msg xfer[2];
	int ret;

	xfer[0].addr = i2c->addr;
	xfer[0].flags = 0;
	xfer[0].len = reg_size;
	xfer[0].buf = (void *)reg;

	xfer[1].addr = i2c->addr;
	xfer[1].flags = I2C_M_RD;
	xfer[1].len = val_size;
	xfer[1].buf = val;

	ret = i2c_transfer(i2c->adapter, xfer, 2);
	if (ret == 2)
		return 0;
	else if (ret < 0)
		return ret;
	else
		return -EIO;
}

__attribute__((used)) static int regmap_i2c_smbus_i2c_write(void *context, const void *data,
				      size_t count)
{
	struct device *dev = context;
	struct i2c_client *i2c = to_i2c_client(dev);

	if (count < 1)
		return -EINVAL;

	--count;
	return i2c_smbus_write_i2c_block_data(i2c, ((u8 *)data)[0], count,
					      ((u8 *)data + 1));
}

__attribute__((used)) static int regmap_i2c_smbus_i2c_read(void *context, const void *reg,
				     size_t reg_size, void *val,
				     size_t val_size)
{
	struct device *dev = context;
	struct i2c_client *i2c = to_i2c_client(dev);
	int ret;

	if (reg_size != 1 || val_size < 1)
		return -EINVAL;

	ret = i2c_smbus_read_i2c_block_data(i2c, ((u8 *)reg)[0], val_size, val);
	if (ret == val_size)
		return 0;
	else if (ret < 0)
		return ret;
	else
		return -EIO;
}

__attribute__((used)) static const struct regmap_bus *regmap_get_i2c_bus(struct i2c_client *i2c,
					const struct regmap_config *config)
{
	if (i2c_check_functionality(i2c->adapter, I2C_FUNC_I2C))
		return &regmap_i2c;
	else if (config->val_bits == 8 && config->reg_bits == 8 &&
		 i2c_check_functionality(i2c->adapter,
					 I2C_FUNC_SMBUS_I2C_BLOCK))
		return &regmap_i2c_smbus_i2c_block;
	else if (config->val_bits == 16 && config->reg_bits == 8 &&
		 i2c_check_functionality(i2c->adapter,
					 I2C_FUNC_SMBUS_WORD_DATA))
		switch (regmap_get_val_endian(&i2c->dev, NULL, config)) {
		case REGMAP_ENDIAN_LITTLE:
			return &regmap_smbus_word;
		case REGMAP_ENDIAN_BIG:
			return &regmap_smbus_word_swapped;
		default:		/* everything else is not supported */
			break;
		}
	else if (config->val_bits == 8 && config->reg_bits == 8 &&
		 i2c_check_functionality(i2c->adapter,
					 I2C_FUNC_SMBUS_BYTE_DATA))
		return &regmap_smbus_byte;

	return ERR_PTR(-ENOTSUPP);
}

struct regmap *__regmap_init_i2c(struct i2c_client *i2c,
				 const struct regmap_config *config,
				 struct lock_class_key *lock_key,
				 const char *lock_name)
{
	const struct regmap_bus *bus = regmap_get_i2c_bus(i2c, config);

	if (IS_ERR(bus))
		return ERR_CAST(bus);

	return __regmap_init(&i2c->dev, bus, &i2c->dev, config,
			     lock_key, lock_name);
}

struct regmap *__devm_regmap_init_i2c(struct i2c_client *i2c,
				      const struct regmap_config *config,
				      struct lock_class_key *lock_key,
				      const char *lock_name)
{
	const struct regmap_bus *bus = regmap_get_i2c_bus(i2c, config);

	if (IS_ERR(bus))
		return ERR_CAST(bus);

	return __devm_regmap_init(&i2c->dev, bus, &i2c->dev, config,
				  lock_key, lock_name);
}

