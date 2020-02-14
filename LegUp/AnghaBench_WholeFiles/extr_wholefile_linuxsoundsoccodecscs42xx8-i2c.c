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
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int cs42xx8_probe (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cs42xx8_regmap_config ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_request_idle (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_disable (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_enable (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int cs42xx8_i2c_probe(struct i2c_client *i2c,
			     const struct i2c_device_id *id)
{
	int ret = cs42xx8_probe(&i2c->dev,
			devm_regmap_init_i2c(i2c, &cs42xx8_regmap_config));
	if (ret)
		return ret;

	pm_runtime_enable(&i2c->dev);
	pm_request_idle(&i2c->dev);

	return 0;
}

__attribute__((used)) static int cs42xx8_i2c_remove(struct i2c_client *i2c)
{
	pm_runtime_disable(&i2c->dev);

	return 0;
}

