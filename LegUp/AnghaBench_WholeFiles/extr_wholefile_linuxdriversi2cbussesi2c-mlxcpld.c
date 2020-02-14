#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct platform_device {int id; int /*<<< orphan*/  dev; } ;
struct TYPE_8__ {int /*<<< orphan*/ * parent; } ;
struct TYPE_9__ {int nr; TYPE_2__ dev; int /*<<< orphan*/ * quirks; int /*<<< orphan*/  timeout; } ;
struct TYPE_7__ {int msg_num; int cmd; int addr_width; int data_len; struct i2c_msg* msg; } ;
struct mlxcpld_i2c_priv {int base_addr; int smbus_block; int /*<<< orphan*/  lock; TYPE_3__ adap; int /*<<< orphan*/ * dev; TYPE_1__ xfer; } ;
struct i2c_msg {int addr; int* buf; int flags; int len; } ;
struct i2c_adapter {int dummy; } ;

/* Variables and functions */
 int E2BIG ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int ENXIO ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int I2C_FUNC_I2C ; 
 int I2C_FUNC_SMBUS_BLOCK_DATA ; 
 int I2C_FUNC_SMBUS_EMUL ; 
 int I2C_FUNC_SMBUS_I2C_BLOCK ; 
 int I2C_M_RD ; 
 int I2C_M_RECV_LEN ; 
 int /*<<< orphan*/  I2C_SMBUS_BLOCK_MAX ; 
 int MLXCPLD_I2C_DATA_SZ_BIT ; 
 int MLXCPLD_I2C_DATA_SZ_MASK ; 
 int MLXCPLD_I2C_POLL_TIME ; 
 int MLXCPLD_I2C_SMBUS_BLK_BIT ; 
 int MLXCPLD_I2C_XFER_TO ; 
#define  MLXCPLD_LPCI2C_ACK_IND 130 
 int MLXCPLD_LPCI2C_CMD_REG ; 
 int MLXCPLD_LPCI2C_CPBLTY_REG ; 
 int MLXCPLD_LPCI2C_CTRL_REG ; 
 int MLXCPLD_LPCI2C_DATA_REG ; 
#define  MLXCPLD_LPCI2C_NACK_IND 129 
#define  MLXCPLD_LPCI2C_NO_IND 128 
 int MLXCPLD_LPCI2C_NUM_ADDR_REG ; 
 int MLXCPLD_LPCI2C_NUM_DAT_REG ; 
 int MLXCPLD_LPCI2C_RST_SEL_MASK ; 
 int MLXCPLD_LPCI2C_STATUS_NACK ; 
 int MLXCPLD_LPCI2C_STATUS_REG ; 
 int MLXCPLD_LPCI2C_TRANS_END ; 
 int MLXPLAT_CPLD_LPC_I2C_BASE_ADDR ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 struct mlxcpld_i2c_priv* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int i2c_add_numbered_adapter (TYPE_3__*) ; 
 int /*<<< orphan*/  i2c_del_adapter (TYPE_3__*) ; 
 struct mlxcpld_i2c_priv* i2c_get_adapdata (struct i2c_adapter*) ; 
 int /*<<< orphan*/  i2c_set_adapdata (TYPE_3__*,struct mlxcpld_i2c_priv*) ; 
 int inb (int) ; 
 int inl (int) ; 
 int /*<<< orphan*/  inw (int) ; 
 TYPE_3__ mlxcpld_i2c_adapter ; 
 int /*<<< orphan*/  mlxcpld_i2c_quirks_ext ; 
 int /*<<< orphan*/  mutex_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  outb (int,int) ; 
 int /*<<< orphan*/  outl (int,int) ; 
 int /*<<< orphan*/  outw (int /*<<< orphan*/ ,int) ; 
 struct mlxcpld_i2c_priv* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct mlxcpld_i2c_priv*) ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  usecs_to_jiffies (int) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static void mlxcpld_i2c_lpc_write_buf(u8 *data, u8 len, u32 addr)
{
	int i;

	for (i = 0; i < len - len % 4; i += 4)
		outl(*(u32 *)(data + i), addr + i);
	for (; i < len; ++i)
		outb(*(data + i), addr + i);
}

__attribute__((used)) static void mlxcpld_i2c_lpc_read_buf(u8 *data, u8 len, u32 addr)
{
	int i;

	for (i = 0; i < len - len % 4; i += 4)
		*(u32 *)(data + i) = inl(addr + i);
	for (; i < len; ++i)
		*(data + i) = inb(addr + i);
}

__attribute__((used)) static void mlxcpld_i2c_read_comm(struct mlxcpld_i2c_priv *priv, u8 offs,
				  u8 *data, u8 datalen)
{
	u32 addr = priv->base_addr + offs;

	switch (datalen) {
	case 1:
		*(data) = inb(addr);
		break;
	case 2:
		*((u16 *)data) = inw(addr);
		break;
	case 3:
		*((u16 *)data) = inw(addr);
		*(data + 2) = inb(addr + 2);
		break;
	case 4:
		*((u32 *)data) = inl(addr);
		break;
	default:
		mlxcpld_i2c_lpc_read_buf(data, datalen, addr);
		break;
	}
}

__attribute__((used)) static void mlxcpld_i2c_write_comm(struct mlxcpld_i2c_priv *priv, u8 offs,
				   u8 *data, u8 datalen)
{
	u32 addr = priv->base_addr + offs;

	switch (datalen) {
	case 1:
		outb(*(data), addr);
		break;
	case 2:
		outw(*((u16 *)data), addr);
		break;
	case 3:
		outw(*((u16 *)data), addr);
		outb(*(data + 2), addr + 2);
		break;
	case 4:
		outl(*((u32 *)data), addr);
		break;
	default:
		mlxcpld_i2c_lpc_write_buf(data, datalen, addr);
		break;
	}
}

__attribute__((used)) static int mlxcpld_i2c_check_msg_params(struct mlxcpld_i2c_priv *priv,
					struct i2c_msg *msgs, int num)
{
	int i;

	if (!num) {
		dev_err(priv->dev, "Incorrect 0 num of messages\n");
		return -EINVAL;
	}

	if (unlikely(msgs[0].addr > 0x7f)) {
		dev_err(priv->dev, "Invalid address 0x%03x\n",
			msgs[0].addr);
		return -EINVAL;
	}

	for (i = 0; i < num; ++i) {
		if (unlikely(!msgs[i].buf)) {
			dev_err(priv->dev, "Invalid buf in msg[%d]\n",
				i);
			return -EINVAL;
		}
		if (unlikely(msgs[0].addr != msgs[i].addr)) {
			dev_err(priv->dev, "Invalid addr in msg[%d]\n",
				i);
			return -EINVAL;
		}
	}

	return 0;
}

__attribute__((used)) static int mlxcpld_i2c_check_status(struct mlxcpld_i2c_priv *priv, int *status)
{
	u8 val;

	mlxcpld_i2c_read_comm(priv, MLXCPLD_LPCI2C_STATUS_REG, &val, 1);

	if (val & MLXCPLD_LPCI2C_TRANS_END) {
		if (val & MLXCPLD_LPCI2C_STATUS_NACK)
			/*
			 * The slave is unable to accept the data. No such
			 * slave, command not understood, or unable to accept
			 * any more data.
			 */
			*status = MLXCPLD_LPCI2C_NACK_IND;
		else
			*status = MLXCPLD_LPCI2C_ACK_IND;
		return 0;
	}
	*status = MLXCPLD_LPCI2C_NO_IND;

	return -EIO;
}

__attribute__((used)) static void mlxcpld_i2c_set_transf_data(struct mlxcpld_i2c_priv *priv,
					struct i2c_msg *msgs, int num,
					u8 comm_len)
{
	priv->xfer.msg = msgs;
	priv->xfer.msg_num = num;

	/*
	 * All upper layers currently are never use transfer with more than
	 * 2 messages. Actually, it's also not so relevant in Mellanox systems
	 * because of HW limitation. Max size of transfer is not more than 32
	 * or 68 bytes in the current x86 LPCI2C bridge.
	 */
	priv->xfer.cmd = msgs[num - 1].flags & I2C_M_RD;

	if (priv->xfer.cmd == I2C_M_RD && comm_len != msgs[0].len) {
		priv->xfer.addr_width = msgs[0].len;
		priv->xfer.data_len = comm_len - priv->xfer.addr_width;
	} else {
		priv->xfer.addr_width = 0;
		priv->xfer.data_len = comm_len;
	}
}

__attribute__((used)) static void mlxcpld_i2c_reset(struct mlxcpld_i2c_priv *priv)
{
	u8 val;

	mutex_lock(&priv->lock);

	mlxcpld_i2c_read_comm(priv, MLXCPLD_LPCI2C_CTRL_REG, &val, 1);
	val &= ~MLXCPLD_LPCI2C_RST_SEL_MASK;
	mlxcpld_i2c_write_comm(priv, MLXCPLD_LPCI2C_CTRL_REG, &val, 1);

	mutex_unlock(&priv->lock);
}

__attribute__((used)) static int mlxcpld_i2c_check_busy(struct mlxcpld_i2c_priv *priv)
{
	u8 val;

	mlxcpld_i2c_read_comm(priv, MLXCPLD_LPCI2C_STATUS_REG, &val, 1);

	if (val & MLXCPLD_LPCI2C_TRANS_END)
		return 0;

	return -EIO;
}

__attribute__((used)) static int mlxcpld_i2c_wait_for_free(struct mlxcpld_i2c_priv *priv)
{
	int timeout = 0;

	do {
		if (!mlxcpld_i2c_check_busy(priv))
			break;
		usleep_range(MLXCPLD_I2C_POLL_TIME / 2, MLXCPLD_I2C_POLL_TIME);
		timeout += MLXCPLD_I2C_POLL_TIME;
	} while (timeout <= MLXCPLD_I2C_XFER_TO);

	if (timeout > MLXCPLD_I2C_XFER_TO)
		return -ETIMEDOUT;

	return 0;
}

__attribute__((used)) static int mlxcpld_i2c_wait_for_tc(struct mlxcpld_i2c_priv *priv)
{
	int status, i, timeout = 0;
	u8 datalen, val;

	do {
		usleep_range(MLXCPLD_I2C_POLL_TIME / 2, MLXCPLD_I2C_POLL_TIME);
		if (!mlxcpld_i2c_check_status(priv, &status))
			break;
		timeout += MLXCPLD_I2C_POLL_TIME;
	} while (status == 0 && timeout < MLXCPLD_I2C_XFER_TO);

	switch (status) {
	case MLXCPLD_LPCI2C_NO_IND:
		return -ETIMEDOUT;

	case MLXCPLD_LPCI2C_ACK_IND:
		if (priv->xfer.cmd != I2C_M_RD)
			return (priv->xfer.addr_width + priv->xfer.data_len);

		if (priv->xfer.msg_num == 1)
			i = 0;
		else
			i = 1;

		if (!priv->xfer.msg[i].buf)
			return -EINVAL;

		/*
		 * Actual read data len will be always the same as
		 * requested len. 0xff (line pull-up) will be returned
		 * if slave has no data to return. Thus don't read
		 * MLXCPLD_LPCI2C_NUM_DAT_REG reg from CPLD.  Only in case of
		 * SMBus block read transaction data len can be different,
		 * check this case.
		 */
		mlxcpld_i2c_read_comm(priv, MLXCPLD_LPCI2C_NUM_ADDR_REG, &val,
				      1);
		if (priv->smbus_block && (val & MLXCPLD_I2C_SMBUS_BLK_BIT)) {
			mlxcpld_i2c_read_comm(priv, MLXCPLD_LPCI2C_NUM_DAT_REG,
					      &datalen, 1);
			if (unlikely(datalen > (I2C_SMBUS_BLOCK_MAX + 1))) {
				dev_err(priv->dev, "Incorrect smbus block read message len\n");
				return -E2BIG;
			}
		} else {
			datalen = priv->xfer.data_len;
		}

		mlxcpld_i2c_read_comm(priv, MLXCPLD_LPCI2C_DATA_REG,
				      priv->xfer.msg[i].buf, datalen);

		return datalen;

	case MLXCPLD_LPCI2C_NACK_IND:
		return -ENXIO;

	default:
		return -EINVAL;
	}
}

__attribute__((used)) static void mlxcpld_i2c_xfer_msg(struct mlxcpld_i2c_priv *priv)
{
	int i, len = 0;
	u8 cmd, val;

	mlxcpld_i2c_write_comm(priv, MLXCPLD_LPCI2C_NUM_DAT_REG,
			       &priv->xfer.data_len, 1);

	val = priv->xfer.addr_width;
	/* Notify HW about SMBus block read transaction */
	if (priv->smbus_block && priv->xfer.msg_num >= 2 &&
	    priv->xfer.msg[1].len == 1 &&
	    (priv->xfer.msg[1].flags & I2C_M_RECV_LEN) &&
	    (priv->xfer.msg[1].flags & I2C_M_RD))
		val |= MLXCPLD_I2C_SMBUS_BLK_BIT;

	mlxcpld_i2c_write_comm(priv, MLXCPLD_LPCI2C_NUM_ADDR_REG, &val, 1);

	for (i = 0; i < priv->xfer.msg_num; i++) {
		if ((priv->xfer.msg[i].flags & I2C_M_RD) != I2C_M_RD) {
			/* Don't write to CPLD buffer in read transaction */
			mlxcpld_i2c_write_comm(priv, MLXCPLD_LPCI2C_DATA_REG +
					       len, priv->xfer.msg[i].buf,
					       priv->xfer.msg[i].len);
			len += priv->xfer.msg[i].len;
		}
	}

	/*
	 * Set target slave address with command for master transfer.
	 * It should be latest executed function before CPLD transaction.
	 */
	cmd = (priv->xfer.msg[0].addr << 1) | priv->xfer.cmd;
	mlxcpld_i2c_write_comm(priv, MLXCPLD_LPCI2C_CMD_REG, &cmd, 1);
}

__attribute__((used)) static int mlxcpld_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg *msgs,
			    int num)
{
	struct mlxcpld_i2c_priv *priv = i2c_get_adapdata(adap);
	u8 comm_len = 0;
	int i, err;

	err = mlxcpld_i2c_check_msg_params(priv, msgs, num);
	if (err) {
		dev_err(priv->dev, "Incorrect message\n");
		return err;
	}

	for (i = 0; i < num; ++i)
		comm_len += msgs[i].len;

	/* Check bus state */
	if (mlxcpld_i2c_wait_for_free(priv)) {
		dev_err(priv->dev, "LPCI2C bridge is busy\n");

		/*
		 * Usually it means something serious has happened.
		 * We can not have unfinished previous transfer
		 * so it doesn't make any sense to try to stop it.
		 * Probably we were not able to recover from the
		 * previous error.
		 * The only reasonable thing - is soft reset.
		 */
		mlxcpld_i2c_reset(priv);
		if (mlxcpld_i2c_check_busy(priv)) {
			dev_err(priv->dev, "LPCI2C bridge is busy after reset\n");
			return -EIO;
		}
	}

	mlxcpld_i2c_set_transf_data(priv, msgs, num, comm_len);

	mutex_lock(&priv->lock);

	/* Do real transfer. Can't fail */
	mlxcpld_i2c_xfer_msg(priv);

	/* Wait for transaction complete */
	err = mlxcpld_i2c_wait_for_tc(priv);

	mutex_unlock(&priv->lock);

	return err < 0 ? err : num;
}

__attribute__((used)) static u32 mlxcpld_i2c_func(struct i2c_adapter *adap)
{
	struct mlxcpld_i2c_priv *priv = i2c_get_adapdata(adap);

	if (priv->smbus_block)
		return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL |
			I2C_FUNC_SMBUS_I2C_BLOCK | I2C_FUNC_SMBUS_BLOCK_DATA;
	else
		return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL |
			I2C_FUNC_SMBUS_I2C_BLOCK;
}

__attribute__((used)) static int mlxcpld_i2c_probe(struct platform_device *pdev)
{
	struct mlxcpld_i2c_priv *priv;
	int err;
	u8 val;

	priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	mutex_init(&priv->lock);
	platform_set_drvdata(pdev, priv);

	priv->dev = &pdev->dev;

	/* Register with i2c layer */
	mlxcpld_i2c_adapter.timeout = usecs_to_jiffies(MLXCPLD_I2C_XFER_TO);
	/* Read capability register */
	mlxcpld_i2c_read_comm(priv, MLXCPLD_LPCI2C_CPBLTY_REG, &val, 1);
	/* Check support for extended transaction length */
	if ((val & MLXCPLD_I2C_DATA_SZ_MASK) == MLXCPLD_I2C_DATA_SZ_BIT)
		mlxcpld_i2c_adapter.quirks = &mlxcpld_i2c_quirks_ext;
	/* Check support for smbus block transaction */
	if (val & MLXCPLD_I2C_SMBUS_BLK_BIT)
		priv->smbus_block = true;
	if (pdev->id >= -1)
		mlxcpld_i2c_adapter.nr = pdev->id;
	priv->adap = mlxcpld_i2c_adapter;
	priv->adap.dev.parent = &pdev->dev;
	priv->base_addr = MLXPLAT_CPLD_LPC_I2C_BASE_ADDR;
	i2c_set_adapdata(&priv->adap, priv);

	err = i2c_add_numbered_adapter(&priv->adap);
	if (err)
		mutex_destroy(&priv->lock);

	return err;
}

__attribute__((used)) static int mlxcpld_i2c_remove(struct platform_device *pdev)
{
	struct mlxcpld_i2c_priv *priv = platform_get_drvdata(pdev);

	i2c_del_adapter(&priv->adap);
	mutex_destroy(&priv->lock);

	return 0;
}

