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
struct regmap {int dummy; } ;
struct i2c_device_id {char* name; } ;
struct i2c_client {int /*<<< orphan*/  dev; int /*<<< orphan*/  irq; } ;

/* Variables and functions */
 scalar_t__ IS_ERR (struct regmap*) ; 
 int PTR_ERR (struct regmap*) ; 
 int bmg160_core_probe (int /*<<< orphan*/ *,struct regmap*,int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  bmg160_core_remove (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bmg160_regmap_i2c_conf ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 struct regmap* devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int bmg160_i2c_probe(struct i2c_client *client,
			    const struct i2c_device_id *id)
{
	struct regmap *regmap;
	const char *name = NULL;

	regmap = devm_regmap_init_i2c(client, &bmg160_regmap_i2c_conf);
	if (IS_ERR(regmap)) {
		dev_err(&client->dev, "Failed to register i2c regmap %d\n",
			(int)PTR_ERR(regmap));
		return PTR_ERR(regmap);
	}

	if (id)
		name = id->name;

	return bmg160_core_probe(&client->dev, regmap, client->irq, name);
}

__attribute__((used)) static int bmg160_i2c_remove(struct i2c_client *client)
{
	bmg160_core_remove(&client->dev);

	return 0;
}

