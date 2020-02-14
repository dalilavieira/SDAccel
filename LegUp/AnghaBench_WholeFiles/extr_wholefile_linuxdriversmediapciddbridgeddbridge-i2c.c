#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u32 ;
struct TYPE_7__ {int /*<<< orphan*/  parent; } ;
struct i2c_adapter {TYPE_2__ dev; void* algo_data; int /*<<< orphan*/ * algo; int /*<<< orphan*/  name; } ;
struct ddb_regmap {size_t irq_base_i2c; TYPE_3__* i2c; TYPE_1__* i2c_buf; } ;
struct ddb_i2c {int nr; int link; int bsize; int wbuf; int rbuf; int regs; struct i2c_adapter adap; int /*<<< orphan*/  completion; struct ddb* dev; } ;
struct ddb {int i2c_num; int nr; struct ddb_i2c* i2c; TYPE_5__* link; int /*<<< orphan*/  dev; } ;
struct TYPE_10__ {TYPE_4__* info; } ;
struct TYPE_9__ {int i2c_mask; struct ddb_regmap* regmap; } ;
struct TYPE_8__ {int base; int size; size_t num; } ;
struct TYPE_6__ {int size; int base; } ;

/* Variables and functions */
 int DDB_LINK_TAG (int) ; 
 size_t DDB_MAX_LINK ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
 int I2C_SPEED_100 ; 
 scalar_t__ I2C_TASKADDRESS ; 
 scalar_t__ I2C_TIMING ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ddb_i2c_algo ; 
 int /*<<< orphan*/  ddb_irq_set (struct ddb*,size_t,size_t,void (*) (void*),struct ddb_i2c*) ; 
 int /*<<< orphan*/  ddbwritel (struct ddb*,int,scalar_t__) ; 
 int i2c_add_adapter (struct i2c_adapter*) ; 
 int /*<<< orphan*/  i2c_del_adapter (struct i2c_adapter*) ; 
 int /*<<< orphan*/  i2c_set_adapdata (struct i2c_adapter*,struct ddb_i2c*) ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int,int,int) ; 

void ddb_i2c_release(struct ddb *dev)
{
	int i;
	struct ddb_i2c *i2c;

	for (i = 0; i < dev->i2c_num; i++) {
		i2c = &dev->i2c[i];
		i2c_del_adapter(&i2c->adap);
	}
}

__attribute__((used)) static void i2c_handler(void *priv)
{
	struct ddb_i2c *i2c = (struct ddb_i2c *)priv;

	complete(&i2c->completion);
}

__attribute__((used)) static int ddb_i2c_add(struct ddb *dev, struct ddb_i2c *i2c,
		       const struct ddb_regmap *regmap, int link,
		       int i, int num)
{
	struct i2c_adapter *adap;

	i2c->nr = i;
	i2c->dev = dev;
	i2c->link = link;
	i2c->bsize = regmap->i2c_buf->size;
	i2c->wbuf = DDB_LINK_TAG(link) |
		(regmap->i2c_buf->base + i2c->bsize * i);
	i2c->rbuf = i2c->wbuf; /* + i2c->bsize / 2 */
	i2c->regs = DDB_LINK_TAG(link) |
		(regmap->i2c->base + regmap->i2c->size * i);
	ddbwritel(dev, I2C_SPEED_100, i2c->regs + I2C_TIMING);
	ddbwritel(dev, ((i2c->rbuf & 0xffff) << 16) | (i2c->wbuf & 0xffff),
		  i2c->regs + I2C_TASKADDRESS);
	init_completion(&i2c->completion);

	adap = &i2c->adap;
	i2c_set_adapdata(adap, i2c);
#ifdef I2C_ADAP_CLASS_TV_DIGITAL
	adap->class = I2C_ADAP_CLASS_TV_DIGITAL | I2C_CLASS_TV_ANALOG;
#else
#ifdef I2C_CLASS_TV_ANALOG
	adap->class = I2C_CLASS_TV_ANALOG;
#endif
#endif
	snprintf(adap->name, I2C_NAME_SIZE, "ddbridge_%02x.%x.%x",
		 dev->nr, i2c->link, i);
	adap->algo = &ddb_i2c_algo;
	adap->algo_data = (void *)i2c;
	adap->dev.parent = dev->dev;
	return i2c_add_adapter(adap);
}

int ddb_i2c_init(struct ddb *dev)
{
	int stat = 0;
	u32 i, j, num = 0, l, base;
	struct ddb_i2c *i2c;
	struct i2c_adapter *adap;
	const struct ddb_regmap *regmap;

	for (l = 0; l < DDB_MAX_LINK; l++) {
		if (!dev->link[l].info)
			continue;
		regmap = dev->link[l].info->regmap;
		if (!regmap || !regmap->i2c)
			continue;
		base = regmap->irq_base_i2c;
		for (i = 0; i < regmap->i2c->num; i++) {
			if (!(dev->link[l].info->i2c_mask & (1 << i)))
				continue;
			i2c = &dev->i2c[num];
			ddb_irq_set(dev, l, i + base, i2c_handler, i2c);
			stat = ddb_i2c_add(dev, i2c, regmap, l, i, num);
			if (stat)
				break;
			num++;
		}
	}
	if (stat) {
		for (j = 0; j < num; j++) {
			i2c = &dev->i2c[j];
			adap = &i2c->adap;
			i2c_del_adapter(adap);
		}
	} else {
		dev->i2c_num = num;
	}

	return stat;
}

