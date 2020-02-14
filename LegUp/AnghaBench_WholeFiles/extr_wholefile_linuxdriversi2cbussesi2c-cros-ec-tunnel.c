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
typedef  int /*<<< orphan*/  const u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct device {int /*<<< orphan*/  parent; struct device_node* of_node; } ;
struct platform_device {struct device dev; } ;
struct i2c_msg {int flags; scalar_t__ len; int /*<<< orphan*/  const* buf; int /*<<< orphan*/  addr; } ;
struct i2c_adapter {struct ec_i2c_device* algo_data; } ;
struct ec_response_i2c_passthru {int i2c_status; int num_msgs; } ;
struct ec_params_i2c_passthru_msg {scalar_t__ len; int /*<<< orphan*/  addr_flags; } ;
struct ec_params_i2c_passthru {int port; int num_msgs; struct ec_params_i2c_passthru_msg* msg; } ;
struct TYPE_4__ {struct device_node* of_node; struct device* parent; } ;
struct TYPE_5__ {int /*<<< orphan*/  retries; TYPE_1__ dev; struct ec_i2c_device* algo_data; int /*<<< orphan*/ * algo; int /*<<< orphan*/  name; int /*<<< orphan*/  owner; } ;
struct ec_i2c_device {int remote_bus; TYPE_2__ adap; struct device* dev; struct cros_ec_device* ec; } ;
struct device_node {int dummy; } ;
struct cros_ec_device {int /*<<< orphan*/  cmd_xfer; } ;
struct cros_ec_command {int outsize; int insize; int /*<<< orphan*/  const* data; int /*<<< orphan*/  command; scalar_t__ version; } ;

/* Variables and functions */
 int /*<<< orphan*/  EC_CMD_I2C_PASSTHRU ; 
 int /*<<< orphan*/  EC_I2C_FLAG_READ ; 
 int EC_I2C_STATUS_ERROR ; 
 int EC_I2C_STATUS_NAK ; 
 int EC_I2C_STATUS_TIMEOUT ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int ENXIO ; 
 int EPROTO ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int I2C_FUNC_I2C ; 
 int I2C_FUNC_SMBUS_EMUL ; 
 int /*<<< orphan*/  I2C_MAX_RETRIES ; 
 int I2C_M_RD ; 
 int I2C_M_TEN ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int cros_ec_cmd_xfer_status (struct cros_ec_device*,struct cros_ec_command*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct cros_ec_device* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,int) ; 
 struct ec_i2c_device* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ec_i2c_algorithm ; 
 int i2c_add_adapter (TYPE_2__*) ; 
 int /*<<< orphan*/  i2c_del_adapter (TYPE_2__*) ; 
 int /*<<< orphan*/  kfree (struct cros_ec_command*) ; 
 struct cros_ec_command* kmalloc (int,int /*<<< orphan*/ ) ; 
 int max (int,int) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,scalar_t__) ; 
 int of_property_read_u32 (struct device_node*,char*,int*) ; 
 struct ec_i2c_device* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct ec_i2c_device*) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int) ; 

__attribute__((used)) static int ec_i2c_count_message(const struct i2c_msg i2c_msgs[], int num)
{
	int i;
	int size;

	size = sizeof(struct ec_params_i2c_passthru);
	size += num * sizeof(struct ec_params_i2c_passthru_msg);
	for (i = 0; i < num; i++)
		if (!(i2c_msgs[i].flags & I2C_M_RD))
			size += i2c_msgs[i].len;

	return size;
}

__attribute__((used)) static int ec_i2c_construct_message(u8 *buf, const struct i2c_msg i2c_msgs[],
				    int num, u16 bus_num)
{
	struct ec_params_i2c_passthru *params;
	u8 *out_data;
	int i;

	out_data = buf + sizeof(struct ec_params_i2c_passthru) +
		   num * sizeof(struct ec_params_i2c_passthru_msg);

	params = (struct ec_params_i2c_passthru *)buf;
	params->port = bus_num;
	params->num_msgs = num;
	for (i = 0; i < num; i++) {
		const struct i2c_msg *i2c_msg = &i2c_msgs[i];
		struct ec_params_i2c_passthru_msg *msg = &params->msg[i];

		msg->len = i2c_msg->len;
		msg->addr_flags = i2c_msg->addr;

		if (i2c_msg->flags & I2C_M_TEN)
			return -EINVAL;

		if (i2c_msg->flags & I2C_M_RD) {
			msg->addr_flags |= EC_I2C_FLAG_READ;
		} else {
			memcpy(out_data, i2c_msg->buf, msg->len);
			out_data += msg->len;
		}
	}

	return 0;
}

__attribute__((used)) static int ec_i2c_count_response(struct i2c_msg i2c_msgs[], int num)
{
	int size;
	int i;

	size = sizeof(struct ec_response_i2c_passthru);
	for (i = 0; i < num; i++)
		if (i2c_msgs[i].flags & I2C_M_RD)
			size += i2c_msgs[i].len;

	return size;
}

__attribute__((used)) static int ec_i2c_parse_response(const u8 *buf, struct i2c_msg i2c_msgs[],
				 int *num)
{
	const struct ec_response_i2c_passthru *resp;
	const u8 *in_data;
	int i;

	in_data = buf + sizeof(struct ec_response_i2c_passthru);

	resp = (const struct ec_response_i2c_passthru *)buf;
	if (resp->i2c_status & EC_I2C_STATUS_TIMEOUT)
		return -ETIMEDOUT;
	else if (resp->i2c_status & EC_I2C_STATUS_NAK)
		return -ENXIO;
	else if (resp->i2c_status & EC_I2C_STATUS_ERROR)
		return -EIO;

	/* Other side could send us back fewer messages, but not more */
	if (resp->num_msgs > *num)
		return -EPROTO;
	*num = resp->num_msgs;

	for (i = 0; i < *num; i++) {
		struct i2c_msg *i2c_msg = &i2c_msgs[i];

		if (i2c_msgs[i].flags & I2C_M_RD) {
			memcpy(i2c_msg->buf, in_data, i2c_msg->len);
			in_data += i2c_msg->len;
		}
	}

	return 0;
}

__attribute__((used)) static int ec_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg i2c_msgs[],
		       int num)
{
	struct ec_i2c_device *bus = adap->algo_data;
	struct device *dev = bus->dev;
	const u16 bus_num = bus->remote_bus;
	int request_len;
	int response_len;
	int alloc_size;
	int result;
	struct cros_ec_command *msg;

	request_len = ec_i2c_count_message(i2c_msgs, num);
	if (request_len < 0) {
		dev_warn(dev, "Error constructing message %d\n", request_len);
		return request_len;
	}

	response_len = ec_i2c_count_response(i2c_msgs, num);
	if (response_len < 0) {
		/* Unexpected; no errors should come when NULL response */
		dev_warn(dev, "Error preparing response %d\n", response_len);
		return response_len;
	}

	alloc_size = max(request_len, response_len);
	msg = kmalloc(sizeof(*msg) + alloc_size, GFP_KERNEL);
	if (!msg)
		return -ENOMEM;

	result = ec_i2c_construct_message(msg->data, i2c_msgs, num, bus_num);
	if (result) {
		dev_err(dev, "Error constructing EC i2c message %d\n", result);
		goto exit;
	}

	msg->version = 0;
	msg->command = EC_CMD_I2C_PASSTHRU;
	msg->outsize = request_len;
	msg->insize = response_len;

	result = cros_ec_cmd_xfer_status(bus->ec, msg);
	if (result < 0) {
		dev_err(dev, "Error transferring EC i2c message %d\n", result);
		goto exit;
	}

	result = ec_i2c_parse_response(msg->data, i2c_msgs, &num);
	if (result < 0)
		goto exit;

	/* Indicate success by saying how many messages were sent */
	result = num;
exit:
	kfree(msg);
	return result;
}

__attribute__((used)) static u32 ec_i2c_functionality(struct i2c_adapter *adap)
{
	return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}

__attribute__((used)) static int ec_i2c_probe(struct platform_device *pdev)
{
	struct device_node *np = pdev->dev.of_node;
	struct cros_ec_device *ec = dev_get_drvdata(pdev->dev.parent);
	struct device *dev = &pdev->dev;
	struct ec_i2c_device *bus = NULL;
	u32 remote_bus;
	int err;

	if (!ec->cmd_xfer) {
		dev_err(dev, "Missing sendrecv\n");
		return -EINVAL;
	}

	bus = devm_kzalloc(dev, sizeof(*bus), GFP_KERNEL);
	if (bus == NULL)
		return -ENOMEM;

	err = of_property_read_u32(np, "google,remote-bus", &remote_bus);
	if (err) {
		dev_err(dev, "Couldn't read remote-bus property\n");
		return err;
	}
	bus->remote_bus = remote_bus;

	bus->ec = ec;
	bus->dev = dev;

	bus->adap.owner = THIS_MODULE;
	strlcpy(bus->adap.name, "cros-ec-i2c-tunnel", sizeof(bus->adap.name));
	bus->adap.algo = &ec_i2c_algorithm;
	bus->adap.algo_data = bus;
	bus->adap.dev.parent = &pdev->dev;
	bus->adap.dev.of_node = np;
	bus->adap.retries = I2C_MAX_RETRIES;

	err = i2c_add_adapter(&bus->adap);
	if (err)
		return err;
	platform_set_drvdata(pdev, bus);

	return err;
}

__attribute__((used)) static int ec_i2c_remove(struct platform_device *dev)
{
	struct ec_i2c_device *bus = platform_get_drvdata(dev);

	i2c_del_adapter(&bus->adap);

	return 0;
}

