#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_8__ ;
typedef  struct TYPE_14__   TYPE_5__ ;
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
typedef  int u16 ;
struct TYPE_11__ {int size; struct tegra_bpmp_message* data; } ;
struct TYPE_10__ {int size; struct tegra_bpmp_message* data; } ;
struct TYPE_13__ {char* data_buf; unsigned int data_size; int bus_id; } ;
struct tegra_bpmp_message {TYPE_2__ rx; TYPE_1__ tx; int /*<<< orphan*/  mrq; TYPE_4__ xfer; int /*<<< orphan*/  cmd; } ;
struct TYPE_12__ {int /*<<< orphan*/  of_node; TYPE_8__* parent; } ;
struct TYPE_14__ {TYPE_3__ dev; int /*<<< orphan*/ * algo; int /*<<< orphan*/  name; int /*<<< orphan*/  owner; } ;
struct tegra_bpmp_i2c {int bus; TYPE_5__ adapter; int /*<<< orphan*/  bpmp; TYPE_8__* dev; } ;
struct TYPE_15__ {int /*<<< orphan*/  of_node; int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_8__ dev; } ;
struct mrq_i2c_response {TYPE_2__ rx; TYPE_1__ tx; int /*<<< orphan*/  mrq; TYPE_4__ xfer; int /*<<< orphan*/  cmd; } ;
struct mrq_i2c_request {TYPE_2__ rx; TYPE_1__ tx; int /*<<< orphan*/  mrq; TYPE_4__ xfer; int /*<<< orphan*/  cmd; } ;
struct i2c_msg {int flags; int addr; int len; char* buf; } ;
struct i2c_adapter {int dummy; } ;
typedef  int /*<<< orphan*/  response ;
typedef  int /*<<< orphan*/  request ;
typedef  int /*<<< orphan*/  msg ;

/* Variables and functions */
 int /*<<< orphan*/  CMD_I2C_XFER ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int I2C_FUNC_10BIT_ADDR ; 
 int I2C_FUNC_I2C ; 
 int I2C_FUNC_NOSTART ; 
 int I2C_FUNC_PROTOCOL_MANGLING ; 
 int I2C_FUNC_SMBUS_EMUL ; 
 int I2C_M_IGNORE_NAK ; 
 int I2C_M_NOSTART ; 
 int I2C_M_NO_RD_ACK ; 
 int I2C_M_RD ; 
 int I2C_M_RECV_LEN ; 
 int I2C_M_REV_DIR_ADDR ; 
 int I2C_M_STOP ; 
 int I2C_M_TEN ; 
 int /*<<< orphan*/  MRQ_I2C ; 
 unsigned int SERIALI2C_HDR_SIZE ; 
 int SERIALI2C_IGNORE_NAK ; 
 int SERIALI2C_NOSTART ; 
 int SERIALI2C_NO_RD_ACK ; 
 int SERIALI2C_RD ; 
 int SERIALI2C_RECV_LEN ; 
 int SERIALI2C_REV_DIR_ADDR ; 
 int SERIALI2C_STOP ; 
 int SERIALI2C_TEN ; 
 size_t TEGRA_I2C_IPC_MAX_IN_BUF_SIZE ; 
 size_t TEGRA_I2C_IPC_MAX_OUT_BUF_SIZE ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  dev_err (TYPE_8__*,char*,...) ; 
 int /*<<< orphan*/  dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct tegra_bpmp_i2c* devm_kzalloc (TYPE_8__*,int,int /*<<< orphan*/ ) ; 
 int i2c_add_adapter (TYPE_5__*) ; 
 int /*<<< orphan*/  i2c_del_adapter (TYPE_5__*) ; 
 struct tegra_bpmp_i2c* i2c_get_adapdata (struct i2c_adapter*) ; 
 int /*<<< orphan*/  i2c_set_adapdata (TYPE_5__*,struct tegra_bpmp_i2c*) ; 
 scalar_t__ irqs_disabled () ; 
 int /*<<< orphan*/  memcpy (char*,char*,unsigned int) ; 
 int /*<<< orphan*/  memset (struct tegra_bpmp_message*,int /*<<< orphan*/ ,int) ; 
 int of_property_read_u32 (int /*<<< orphan*/ ,char*,int*) ; 
 struct tegra_bpmp_i2c* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct tegra_bpmp_i2c*) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  tegra_bpmp_i2c_algo ; 
 int tegra_bpmp_transfer (int /*<<< orphan*/ ,struct tegra_bpmp_message*) ; 
 int tegra_bpmp_transfer_atomic (int /*<<< orphan*/ ,struct tegra_bpmp_message*) ; 

__attribute__((used)) static int tegra_bpmp_xlate_flags(u16 flags, u16 *out)
{
	if (flags & I2C_M_TEN) {
		*out |= SERIALI2C_TEN;
		flags &= ~I2C_M_TEN;
	}

	if (flags & I2C_M_RD) {
		*out |= SERIALI2C_RD;
		flags &= ~I2C_M_RD;
	}

	if (flags & I2C_M_STOP) {
		*out |= SERIALI2C_STOP;
		flags &= ~I2C_M_STOP;
	}

	if (flags & I2C_M_NOSTART) {
		*out |= SERIALI2C_NOSTART;
		flags &= ~I2C_M_NOSTART;
	}

	if (flags & I2C_M_REV_DIR_ADDR) {
		*out |= SERIALI2C_REV_DIR_ADDR;
		flags &= ~I2C_M_REV_DIR_ADDR;
	}

	if (flags & I2C_M_IGNORE_NAK) {
		*out |= SERIALI2C_IGNORE_NAK;
		flags &= ~I2C_M_IGNORE_NAK;
	}

	if (flags & I2C_M_NO_RD_ACK) {
		*out |= SERIALI2C_NO_RD_ACK;
		flags &= ~I2C_M_NO_RD_ACK;
	}

	if (flags & I2C_M_RECV_LEN) {
		*out |= SERIALI2C_RECV_LEN;
		flags &= ~I2C_M_RECV_LEN;
	}

	return (flags != 0) ? -EINVAL : 0;
}

__attribute__((used)) static int tegra_bpmp_serialize_i2c_msg(struct tegra_bpmp_i2c *i2c,
					struct mrq_i2c_request *request,
					struct i2c_msg *msgs,
					unsigned int num)
{
	char *buf = request->xfer.data_buf;
	unsigned int i, j, pos = 0;
	int err;

	for (i = 0; i < num; i++) {
		struct i2c_msg *msg = &msgs[i];
		u16 flags = 0;

		err = tegra_bpmp_xlate_flags(msg->flags, &flags);
		if (err < 0)
			return err;

		buf[pos++] = msg->addr & 0xff;
		buf[pos++] = (msg->addr & 0xff00) >> 8;
		buf[pos++] = flags & 0xff;
		buf[pos++] = (flags & 0xff00) >> 8;
		buf[pos++] = msg->len & 0xff;
		buf[pos++] = (msg->len & 0xff00) >> 8;

		if ((flags & SERIALI2C_RD) == 0) {
			for (j = 0; j < msg->len; j++)
				buf[pos++] = msg->buf[j];
		}
	}

	request->xfer.data_size = pos;

	return 0;
}

__attribute__((used)) static int tegra_bpmp_i2c_deserialize(struct tegra_bpmp_i2c *i2c,
				      struct mrq_i2c_response *response,
				      struct i2c_msg *msgs,
				      unsigned int num)
{
	size_t size = response->xfer.data_size, len = 0, pos = 0;
	char *buf = response->xfer.data_buf;
	unsigned int i;

	for (i = 0; i < num; i++)
		if (msgs[i].flags & I2C_M_RD)
			len += msgs[i].len;

	if (len != size)
		return -EINVAL;

	for (i = 0; i < num; i++) {
		if (msgs[i].flags & I2C_M_RD) {
			memcpy(msgs[i].buf, buf + pos, msgs[i].len);
			pos += msgs[i].len;
		}
	}

	return 0;
}

__attribute__((used)) static int tegra_bpmp_i2c_msg_len_check(struct i2c_msg *msgs, unsigned int num)
{
	size_t tx_len = 0, rx_len = 0;
	unsigned int i;

	for (i = 0; i < num; i++)
		if (!(msgs[i].flags & I2C_M_RD))
			tx_len += SERIALI2C_HDR_SIZE + msgs[i].len;

	if (tx_len > TEGRA_I2C_IPC_MAX_IN_BUF_SIZE)
		return -EINVAL;

	for (i = 0; i < num; i++)
		if ((msgs[i].flags & I2C_M_RD))
			rx_len += msgs[i].len;

	if (rx_len > TEGRA_I2C_IPC_MAX_OUT_BUF_SIZE)
		return -EINVAL;

	return 0;
}

__attribute__((used)) static int tegra_bpmp_i2c_msg_xfer(struct tegra_bpmp_i2c *i2c,
				   struct mrq_i2c_request *request,
				   struct mrq_i2c_response *response)
{
	struct tegra_bpmp_message msg;
	int err;

	request->cmd = CMD_I2C_XFER;
	request->xfer.bus_id = i2c->bus;

	memset(&msg, 0, sizeof(msg));
	msg.mrq = MRQ_I2C;
	msg.tx.data = request;
	msg.tx.size = sizeof(*request);
	msg.rx.data = response;
	msg.rx.size = sizeof(*response);

	if (irqs_disabled())
		err = tegra_bpmp_transfer_atomic(i2c->bpmp, &msg);
	else
		err = tegra_bpmp_transfer(i2c->bpmp, &msg);

	return err;
}

__attribute__((used)) static int tegra_bpmp_i2c_xfer(struct i2c_adapter *adapter,
			       struct i2c_msg *msgs, int num)
{
	struct tegra_bpmp_i2c *i2c = i2c_get_adapdata(adapter);
	struct mrq_i2c_response response;
	struct mrq_i2c_request request;
	int err;

	err = tegra_bpmp_i2c_msg_len_check(msgs, num);
	if (err < 0) {
		dev_err(i2c->dev, "unsupported message length\n");
		return err;
	}

	memset(&request, 0, sizeof(request));
	memset(&response, 0, sizeof(response));

	err = tegra_bpmp_serialize_i2c_msg(i2c, &request, msgs, num);
	if (err < 0) {
		dev_err(i2c->dev, "failed to serialize message: %d\n", err);
		return err;
	}

	err = tegra_bpmp_i2c_msg_xfer(i2c, &request, &response);
	if (err < 0) {
		dev_err(i2c->dev, "failed to transfer message: %d\n", err);
		return err;
	}

	err = tegra_bpmp_i2c_deserialize(i2c, &response, msgs, num);
	if (err < 0) {
		dev_err(i2c->dev, "failed to deserialize message: %d\n", err);
		return err;
	}

	return num;
}

__attribute__((used)) static u32 tegra_bpmp_i2c_func(struct i2c_adapter *adapter)
{
	return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL | I2C_FUNC_10BIT_ADDR |
	       I2C_FUNC_PROTOCOL_MANGLING | I2C_FUNC_NOSTART;
}

__attribute__((used)) static int tegra_bpmp_i2c_probe(struct platform_device *pdev)
{
	struct tegra_bpmp_i2c *i2c;
	u32 value;
	int err;

	i2c = devm_kzalloc(&pdev->dev, sizeof(*i2c), GFP_KERNEL);
	if (!i2c)
		return -ENOMEM;

	i2c->dev = &pdev->dev;

	i2c->bpmp = dev_get_drvdata(pdev->dev.parent);
	if (!i2c->bpmp)
		return -ENODEV;

	err = of_property_read_u32(pdev->dev.of_node, "nvidia,bpmp-bus-id",
				   &value);
	if (err < 0)
		return err;

	i2c->bus = value;

	i2c_set_adapdata(&i2c->adapter, i2c);
	i2c->adapter.owner = THIS_MODULE;
	strlcpy(i2c->adapter.name, "Tegra BPMP I2C adapter",
		sizeof(i2c->adapter.name));
	i2c->adapter.algo = &tegra_bpmp_i2c_algo;
	i2c->adapter.dev.parent = &pdev->dev;
	i2c->adapter.dev.of_node = pdev->dev.of_node;

	platform_set_drvdata(pdev, i2c);

	return i2c_add_adapter(&i2c->adapter);
}

__attribute__((used)) static int tegra_bpmp_i2c_remove(struct platform_device *pdev)
{
	struct tegra_bpmp_i2c *i2c = platform_get_drvdata(pdev);

	i2c_del_adapter(&i2c->adapter);

	return 0;
}

