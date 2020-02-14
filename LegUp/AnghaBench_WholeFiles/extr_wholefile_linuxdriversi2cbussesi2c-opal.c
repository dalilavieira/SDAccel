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
union i2c_smbus_data {int byte; int word; int* block; } ;
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct TYPE_5__ {int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_2__ dev; } ;
struct opal_msg {int dummy; } ;
struct opal_i2c_request {int subaddr_sz; int subaddr; void* type; void* size; void* buffer_ra; void* addr; } ;
struct i2c_msg {int flags; int addr; int len; int* buf; } ;
struct TYPE_4__ {int /*<<< orphan*/  of_node; TYPE_2__* parent; } ;
struct i2c_adapter {int /*<<< orphan*/  name; TYPE_1__ dev; int /*<<< orphan*/ * quirks; void* algo_data; int /*<<< orphan*/ * algo; } ;
typedef  int /*<<< orphan*/  req ;

/* Variables and functions */
 int EAGAIN ; 
 int EBUSY ; 
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENXIO ; 
 int ERESTARTSYS ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int I2C_FUNC_I2C ; 
 int I2C_FUNC_SMBUS_BYTE ; 
 int I2C_FUNC_SMBUS_BYTE_DATA ; 
 int I2C_FUNC_SMBUS_I2C_BLOCK ; 
 int I2C_FUNC_SMBUS_QUICK ; 
 int I2C_FUNC_SMBUS_WORD_DATA ; 
 int I2C_M_RD ; 
#define  I2C_SMBUS_BYTE 138 
#define  I2C_SMBUS_BYTE_DATA 137 
#define  I2C_SMBUS_I2C_BLOCK_DATA 136 
#define  I2C_SMBUS_QUICK 135 
 char I2C_SMBUS_READ ; 
#define  I2C_SMBUS_WORD_DATA 134 
 int OPAL_ASYNC_COMPLETION ; 
#define  OPAL_I2C_ARBT_LOST 133 
#define  OPAL_I2C_NACK_RCVD 132 
 void* OPAL_I2C_RAW_READ ; 
 void* OPAL_I2C_RAW_WRITE ; 
 void* OPAL_I2C_SM_READ ; 
 void* OPAL_I2C_SM_WRITE ; 
#define  OPAL_I2C_STOP_ERR 131 
#define  OPAL_I2C_TIMEOUT 130 
#define  OPAL_NO_MEM 129 
#define  OPAL_PARAMETER 128 
 int OPAL_SUCCESS ; 
 int /*<<< orphan*/  __pa (int*) ; 
 void* cpu_to_be16 (int) ; 
 void* cpu_to_be32 (int) ; 
 void* cpu_to_be64 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*) ; 
 struct i2c_adapter* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 int i2c_add_adapter (struct i2c_adapter*) ; 
 int /*<<< orphan*/  i2c_del_adapter (struct i2c_adapter*) ; 
 int /*<<< orphan*/  i2c_opal_algo ; 
 int /*<<< orphan*/  i2c_opal_quirks ; 
 int /*<<< orphan*/  memset (struct opal_i2c_request*,int /*<<< orphan*/ ,int) ; 
 char* of_get_property (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  of_node_get (int /*<<< orphan*/ ) ; 
 int of_property_read_u32 (int /*<<< orphan*/ ,char*,int*) ; 
 int opal_async_get_token_interruptible () ; 
 int /*<<< orphan*/  opal_async_release_token (int) ; 
 int opal_async_wait_response (int,struct opal_msg*) ; 
 int opal_get_async_rc (struct opal_msg) ; 
 int opal_i2c_request (int,int,struct opal_i2c_request*) ; 
 struct i2c_adapter* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct i2c_adapter*) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char const*,int) ; 

__attribute__((used)) static int i2c_opal_translate_error(int rc)
{
	switch (rc) {
	case OPAL_NO_MEM:
		return -ENOMEM;
	case OPAL_PARAMETER:
		return -EINVAL;
	case OPAL_I2C_ARBT_LOST:
		return -EAGAIN;
	case OPAL_I2C_TIMEOUT:
		return -ETIMEDOUT;
	case OPAL_I2C_NACK_RCVD:
		return -ENXIO;
	case OPAL_I2C_STOP_ERR:
		return -EBUSY;
	default:
		return -EIO;
	}
}

__attribute__((used)) static int i2c_opal_send_request(u32 bus_id, struct opal_i2c_request *req)
{
	struct opal_msg msg;
	int token, rc;

	token = opal_async_get_token_interruptible();
	if (token < 0) {
		if (token != -ERESTARTSYS)
			pr_err("Failed to get the async token\n");

		return token;
	}

	rc = opal_i2c_request(token, bus_id, req);
	if (rc != OPAL_ASYNC_COMPLETION) {
		rc = i2c_opal_translate_error(rc);
		goto exit;
	}

	rc = opal_async_wait_response(token, &msg);
	if (rc)
		goto exit;

	rc = opal_get_async_rc(msg);
	if (rc != OPAL_SUCCESS) {
		rc = i2c_opal_translate_error(rc);
		goto exit;
	}

exit:
	opal_async_release_token(token);
	return rc;
}

__attribute__((used)) static int i2c_opal_master_xfer(struct i2c_adapter *adap, struct i2c_msg *msgs,
				int num)
{
	unsigned long opal_id = (unsigned long)adap->algo_data;
	struct opal_i2c_request req;
	int rc, i;

	/* We only support fairly simple combinations here of one
	 * or two messages
	 */
	memset(&req, 0, sizeof(req));
	switch(num) {
	case 1:
		req.type = (msgs[0].flags & I2C_M_RD) ?
			OPAL_I2C_RAW_READ : OPAL_I2C_RAW_WRITE;
		req.addr = cpu_to_be16(msgs[0].addr);
		req.size = cpu_to_be32(msgs[0].len);
		req.buffer_ra = cpu_to_be64(__pa(msgs[0].buf));
		break;
	case 2:
		req.type = (msgs[1].flags & I2C_M_RD) ?
			OPAL_I2C_SM_READ : OPAL_I2C_SM_WRITE;
		req.addr = cpu_to_be16(msgs[0].addr);
		req.subaddr_sz = msgs[0].len;
		for (i = 0; i < msgs[0].len; i++)
			req.subaddr = (req.subaddr << 8) | msgs[0].buf[i];
		req.subaddr = cpu_to_be32(req.subaddr);
		req.size = cpu_to_be32(msgs[1].len);
		req.buffer_ra = cpu_to_be64(__pa(msgs[1].buf));
		break;
	}

	rc = i2c_opal_send_request(opal_id, &req);
	if (rc)
		return rc;

	return num;
}

__attribute__((used)) static int i2c_opal_smbus_xfer(struct i2c_adapter *adap, u16 addr,
			       unsigned short flags, char read_write,
			       u8 command, int size, union i2c_smbus_data *data)
{
	unsigned long opal_id = (unsigned long)adap->algo_data;
	struct opal_i2c_request req;
	u8 local[2];
	int rc;

	memset(&req, 0, sizeof(req));

	req.addr = cpu_to_be16(addr);
	switch (size) {
	case I2C_SMBUS_BYTE:
		req.buffer_ra = cpu_to_be64(__pa(&data->byte));
		req.size = cpu_to_be32(1);
		/* Fall through */
	case I2C_SMBUS_QUICK:
		req.type = (read_write == I2C_SMBUS_READ) ?
			OPAL_I2C_RAW_READ : OPAL_I2C_RAW_WRITE;
		break;
	case I2C_SMBUS_BYTE_DATA:
		req.buffer_ra = cpu_to_be64(__pa(&data->byte));
		req.size = cpu_to_be32(1);
		req.subaddr = cpu_to_be32(command);
		req.subaddr_sz = 1;
		req.type = (read_write == I2C_SMBUS_READ) ?
			OPAL_I2C_SM_READ : OPAL_I2C_SM_WRITE;
		break;
	case I2C_SMBUS_WORD_DATA:
		if (!read_write) {
			local[0] = data->word & 0xff;
			local[1] = (data->word >> 8) & 0xff;
		}
		req.buffer_ra = cpu_to_be64(__pa(local));
		req.size = cpu_to_be32(2);
		req.subaddr = cpu_to_be32(command);
		req.subaddr_sz = 1;
		req.type = (read_write == I2C_SMBUS_READ) ?
			OPAL_I2C_SM_READ : OPAL_I2C_SM_WRITE;
		break;
	case I2C_SMBUS_I2C_BLOCK_DATA:
		req.buffer_ra = cpu_to_be64(__pa(&data->block[1]));
		req.size = cpu_to_be32(data->block[0]);
		req.subaddr = cpu_to_be32(command);
		req.subaddr_sz = 1;
		req.type = (read_write == I2C_SMBUS_READ) ?
			OPAL_I2C_SM_READ : OPAL_I2C_SM_WRITE;
		break;
	default:
		return -EINVAL;
	}

	rc = i2c_opal_send_request(opal_id, &req);
	if (!rc && read_write && size == I2C_SMBUS_WORD_DATA) {
		data->word = ((u16)local[1]) << 8;
		data->word |= local[0];
	}

	return rc;
}

__attribute__((used)) static u32 i2c_opal_func(struct i2c_adapter *adapter)
{
	return I2C_FUNC_I2C | I2C_FUNC_SMBUS_QUICK | I2C_FUNC_SMBUS_BYTE |
	       I2C_FUNC_SMBUS_BYTE_DATA | I2C_FUNC_SMBUS_WORD_DATA |
	       I2C_FUNC_SMBUS_I2C_BLOCK;
}

__attribute__((used)) static int i2c_opal_probe(struct platform_device *pdev)
{
	struct i2c_adapter	*adapter;
	const char		*pname;
	u32			opal_id;
	int			rc;

	if (!pdev->dev.of_node)
		return -ENODEV;

	rc = of_property_read_u32(pdev->dev.of_node, "ibm,opal-id", &opal_id);
	if (rc) {
		dev_err(&pdev->dev, "Missing ibm,opal-id property !\n");
		return -EIO;
	}

	adapter = devm_kzalloc(&pdev->dev, sizeof(*adapter), GFP_KERNEL);
	if (!adapter)
		return -ENOMEM;

	adapter->algo = &i2c_opal_algo;
	adapter->algo_data = (void *)(unsigned long)opal_id;
	adapter->quirks = &i2c_opal_quirks;
	adapter->dev.parent = &pdev->dev;
	adapter->dev.of_node = of_node_get(pdev->dev.of_node);
	pname = of_get_property(pdev->dev.of_node, "ibm,port-name", NULL);
	if (pname)
		strlcpy(adapter->name, pname, sizeof(adapter->name));
	else
		strlcpy(adapter->name, "opal", sizeof(adapter->name));

	platform_set_drvdata(pdev, adapter);
	rc = i2c_add_adapter(adapter);
	if (rc)
		dev_err(&pdev->dev, "Failed to register the i2c adapter\n");

	return rc;
}

__attribute__((used)) static int i2c_opal_remove(struct platform_device *pdev)
{
	struct i2c_adapter *adapter = platform_get_drvdata(pdev);

	i2c_del_adapter(adapter);

	return 0;
}

