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
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  irq; int /*<<< orphan*/  dev; } ;
struct ad714x_chip {void** xfer_buf; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUS_I2C ; 
 scalar_t__ IS_ERR (struct ad714x_chip*) ; 
 int PTR_ERR (struct ad714x_chip*) ; 
 struct ad714x_chip* ad714x_probe (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int (*) (struct ad714x_chip*,unsigned short,unsigned short*,size_t),int (*) (struct ad714x_chip*,unsigned short,unsigned short)) ; 
 unsigned short be16_to_cpu (void*) ; 
 void* cpu_to_be16 (unsigned short) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 int i2c_master_recv (struct i2c_client*,int /*<<< orphan*/ *,size_t) ; 
 int i2c_master_send (struct i2c_client*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct ad714x_chip*) ; 
 struct i2c_client* to_i2c_client (int /*<<< orphan*/ ) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static int ad714x_i2c_write(struct ad714x_chip *chip,
			    unsigned short reg, unsigned short data)
{
	struct i2c_client *client = to_i2c_client(chip->dev);
	int error;

	chip->xfer_buf[0] = cpu_to_be16(reg);
	chip->xfer_buf[1] = cpu_to_be16(data);

	error = i2c_master_send(client, (u8 *)chip->xfer_buf,
				2 * sizeof(*chip->xfer_buf));
	if (unlikely(error < 0)) {
		dev_err(&client->dev, "I2C write error: %d\n", error);
		return error;
	}

	return 0;
}

__attribute__((used)) static int ad714x_i2c_read(struct ad714x_chip *chip,
			   unsigned short reg, unsigned short *data, size_t len)
{
	struct i2c_client *client = to_i2c_client(chip->dev);
	int i;
	int error;

	chip->xfer_buf[0] = cpu_to_be16(reg);

	error = i2c_master_send(client, (u8 *)chip->xfer_buf,
				sizeof(*chip->xfer_buf));
	if (error >= 0)
		error = i2c_master_recv(client, (u8 *)chip->xfer_buf,
					len * sizeof(*chip->xfer_buf));

	if (unlikely(error < 0)) {
		dev_err(&client->dev, "I2C read error: %d\n", error);
		return error;
	}

	for (i = 0; i < len; i++)
		data[i] = be16_to_cpu(chip->xfer_buf[i]);

	return 0;
}

__attribute__((used)) static int ad714x_i2c_probe(struct i2c_client *client,
					const struct i2c_device_id *id)
{
	struct ad714x_chip *chip;

	chip = ad714x_probe(&client->dev, BUS_I2C, client->irq,
			    ad714x_i2c_read, ad714x_i2c_write);
	if (IS_ERR(chip))
		return PTR_ERR(chip);

	i2c_set_clientdata(client, chip);

	return 0;
}

