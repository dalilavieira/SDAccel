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
struct regmap_config {int reg_bits; int val_bits; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int cs4271_probe (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct regmap_config cs4271_regmap_config ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,struct regmap_config*) ; 

__attribute__((used)) static int cs4271_i2c_probe(struct i2c_client *client,
			     const struct i2c_device_id *id)
{
	struct regmap_config config;

	config = cs4271_regmap_config;
	config.reg_bits = 8;
	config.val_bits = 8;

	return cs4271_probe(&client->dev,
			    devm_regmap_init_i2c(client, &config));
}

