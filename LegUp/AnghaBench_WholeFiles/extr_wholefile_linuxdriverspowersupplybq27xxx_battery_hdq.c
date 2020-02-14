#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct w1_slave {int /*<<< orphan*/  dev; TYPE_2__* master; } ;
struct TYPE_4__ {int (* read ) (struct bq27xxx_device_info*,int,int) ;} ;
struct bq27xxx_device_info {char* name; TYPE_1__ bus; int /*<<< orphan*/  chip; int /*<<< orphan*/ * dev; } ;
struct TYPE_5__ {int /*<<< orphan*/  bus_mutex; } ;

/* Variables and functions */
 int /*<<< orphan*/  BQ27000 ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned int HDQ_CMD_READ ; 
 int bq27xxx_battery_setup (struct bq27xxx_device_info*) ; 
 int /*<<< orphan*/  bq27xxx_battery_teardown (struct bq27xxx_device_info*) ; 
 struct bq27xxx_device_info* dev_get_drvdata (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_set_drvdata (int /*<<< orphan*/ *,struct bq27xxx_device_info*) ; 
 struct w1_slave* dev_to_w1_slave (int /*<<< orphan*/ *) ; 
 struct bq27xxx_device_info* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int w1_read_8 (TYPE_2__*) ; 
 int /*<<< orphan*/  w1_write_8 (TYPE_2__*,unsigned int) ; 

__attribute__((used)) static int w1_bq27000_read(struct w1_slave *sl, unsigned int reg)
{
	u8 val;

	mutex_lock(&sl->master->bus_mutex);
	w1_write_8(sl->master, HDQ_CMD_READ | reg);
	val = w1_read_8(sl->master);
	mutex_unlock(&sl->master->bus_mutex);

	return val;
}

__attribute__((used)) static int bq27xxx_battery_hdq_read(struct bq27xxx_device_info *di, u8 reg,
				    bool single)
{
	struct w1_slave *sl = dev_to_w1_slave(di->dev);
	unsigned int timeout = 3;
	int upper, lower;
	int temp;

	if (!single) {
		/*
		 * Make sure the value has not changed in between reading the
		 * lower and the upper part
		 */
		upper = w1_bq27000_read(sl, reg + 1);
		do {
			temp = upper;
			if (upper < 0)
				return upper;

			lower = w1_bq27000_read(sl, reg);
			if (lower < 0)
				return lower;

			upper = w1_bq27000_read(sl, reg + 1);
		} while (temp != upper && --timeout);

		if (timeout == 0)
			return -EIO;

		return (upper << 8) | lower;
	}

	return w1_bq27000_read(sl, reg);
}

__attribute__((used)) static int bq27xxx_battery_hdq_add_slave(struct w1_slave *sl)
{
	struct bq27xxx_device_info *di;

	di = devm_kzalloc(&sl->dev, sizeof(*di), GFP_KERNEL);
	if (!di)
		return -ENOMEM;

	dev_set_drvdata(&sl->dev, di);

	di->dev = &sl->dev;
	di->chip = BQ27000;
	di->name = "bq27000-battery";
	di->bus.read = bq27xxx_battery_hdq_read;

	return bq27xxx_battery_setup(di);
}

__attribute__((used)) static void bq27xxx_battery_hdq_remove_slave(struct w1_slave *sl)
{
	struct bq27xxx_device_info *di = dev_get_drvdata(&sl->dev);

	bq27xxx_battery_teardown(di);
}

