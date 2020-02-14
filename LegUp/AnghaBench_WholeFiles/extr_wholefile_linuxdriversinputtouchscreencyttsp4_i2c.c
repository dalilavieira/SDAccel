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
typedef  int /*<<< orphan*/  u16 ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  irq; int /*<<< orphan*/  dev; int /*<<< orphan*/  adapter; } ;
struct cyttsp4 {int /*<<< orphan*/  xfer_buf; int /*<<< orphan*/  dev; TYPE_1__* bus_ops; } ;
struct TYPE_2__ {int (* read ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,void*) ;int (* write ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,void const*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  CYTTSP4_I2C_DATA_SIZE ; 
 int EIO ; 
 int /*<<< orphan*/  I2C_FUNC_I2C ; 
 int PTR_ERR_OR_ZERO (struct cyttsp4*) ; 
 int /*<<< orphan*/  cyttsp4_i2c_bus_ops ; 
 struct cyttsp4* cyttsp4_probe (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cyttsp4_remove (struct cyttsp4*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  i2c_check_functionality (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct cyttsp4* i2c_get_clientdata (struct i2c_client*) ; 
 int stub1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,void*) ; 
 int stub2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,void const*) ; 

__attribute__((used)) static inline int cyttsp4_adap_read(struct cyttsp4 *ts, u16 addr, int size,
		void *buf)
{
	return ts->bus_ops->read(ts->dev, ts->xfer_buf, addr, size, buf);
}

__attribute__((used)) static inline int cyttsp4_adap_write(struct cyttsp4 *ts, u16 addr, int size,
		const void *buf)
{
	return ts->bus_ops->write(ts->dev, ts->xfer_buf, addr, size, buf);
}

__attribute__((used)) static int cyttsp4_i2c_probe(struct i2c_client *client,
				      const struct i2c_device_id *id)
{
	struct cyttsp4 *ts;

	if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
		dev_err(&client->dev, "I2C functionality not Supported\n");
		return -EIO;
	}

	ts = cyttsp4_probe(&cyttsp4_i2c_bus_ops, &client->dev, client->irq,
			  CYTTSP4_I2C_DATA_SIZE);

	return PTR_ERR_OR_ZERO(ts);
}

__attribute__((used)) static int cyttsp4_i2c_remove(struct i2c_client *client)
{
	struct cyttsp4 *ts = i2c_get_clientdata(client);

	cyttsp4_remove(ts);

	return 0;
}

