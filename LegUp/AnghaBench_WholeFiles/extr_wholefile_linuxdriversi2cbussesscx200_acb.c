#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
union i2c_smbus_data {int byte; int* block; int /*<<< orphan*/  word; } ;
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct TYPE_4__ {struct device* parent; } ;
struct i2c_adapter {int class; int /*<<< orphan*/  name; TYPE_1__ dev; int /*<<< orphan*/ * algo; int /*<<< orphan*/  owner; } ;
struct scx200_acb_iface {size_t state; int result; int address_byte; int command; int len; int* ptr; int needs_reset; unsigned long base; struct i2c_adapter adapter; struct scx200_acb_iface* next; int /*<<< orphan*/  mutex; } ;
struct resource {unsigned long start; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
typedef  int s32 ;

/* Variables and functions */
 int /*<<< orphan*/  ACBADDR ; 
 int /*<<< orphan*/  ACBCST ; 
 int ACBCST_BB ; 
 int /*<<< orphan*/  ACBCTL1 ; 
 int ACBCTL1_ACK ; 
 int ACBCTL1_NMINTE ; 
 int ACBCTL1_START ; 
 int ACBCTL1_STASTRE ; 
 int ACBCTL1_STOP ; 
 int /*<<< orphan*/  ACBCTL2 ; 
 int ACBCTL2_ENABLE ; 
 int /*<<< orphan*/  ACBSDA ; 
 int /*<<< orphan*/  ACBST ; 
 int ACBST_BER ; 
 int ACBST_MASTER ; 
 int ACBST_NEGACK ; 
 int ACBST_SDAST ; 
 int ACBST_STASTR ; 
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENXIO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int I2C_CLASS_HWMON ; 
 int I2C_CLASS_SPD ; 
 int I2C_FUNC_SMBUS_BYTE ; 
 int I2C_FUNC_SMBUS_BYTE_DATA ; 
 int I2C_FUNC_SMBUS_I2C_BLOCK ; 
 int I2C_FUNC_SMBUS_QUICK ; 
 int I2C_FUNC_SMBUS_WORD_DATA ; 
 int I2C_SMBUS_BLOCK_MAX ; 
#define  I2C_SMBUS_BYTE 139 
#define  I2C_SMBUS_BYTE_DATA 138 
#define  I2C_SMBUS_I2C_BLOCK_DATA 137 
#define  I2C_SMBUS_QUICK 136 
 char I2C_SMBUS_READ ; 
#define  I2C_SMBUS_WORD_DATA 135 
 int /*<<< orphan*/  IORESOURCE_IO ; 
 unsigned long POLL_TIMEOUT ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  cond_resched () ; 
 int /*<<< orphan*/  cpu_relax () ; 
 int cpu_to_le16 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (TYPE_1__*,char*,...) ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,...) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_warn (TYPE_1__*,char*) ; 
 scalar_t__ i2c_add_adapter (struct i2c_adapter*) ; 
 int /*<<< orphan*/  i2c_del_adapter (struct i2c_adapter*) ; 
 struct scx200_acb_iface* i2c_get_adapdata (struct i2c_adapter*) ; 
 int /*<<< orphan*/  i2c_set_adapdata (struct i2c_adapter*,struct scx200_acb_iface*) ; 
 int inb (int /*<<< orphan*/ ) ; 
 unsigned long jiffies ; 
 int /*<<< orphan*/  kfree (struct scx200_acb_iface*) ; 
 struct scx200_acb_iface* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  le16_to_cpu (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  outb (int,int /*<<< orphan*/ ) ; 
 struct scx200_acb_iface* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct scx200_acb_iface*) ; 
 int /*<<< orphan*/  pr_debug (char*,...) ; 
 int /*<<< orphan*/  pr_err (char*,...) ; 
 int /*<<< orphan*/  pr_warn (char*) ; 
 int /*<<< orphan*/  release_region (unsigned long,int) ; 
 int /*<<< orphan*/  request_region (unsigned long,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  scx200_acb_algorithm ; 
 struct scx200_acb_iface* scx200_acb_list ; 
 int /*<<< orphan*/  scx200_acb_list_mutex ; 
 int /*<<< orphan*/ * scx200_acb_state_name ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,char const*,int) ; 
#define  state_address 134 
#define  state_command 133 
#define  state_idle 132 
#define  state_quick 131 
#define  state_read 130 
#define  state_repeat_start 129 
#define  state_write 128 
 scalar_t__ time_after (unsigned long,unsigned long) ; 

__attribute__((used)) static void scx200_acb_machine(struct scx200_acb_iface *iface, u8 status)
{
	const char *errmsg;

	dev_dbg(&iface->adapter.dev, "state %s, status = 0x%02x\n",
		scx200_acb_state_name[iface->state], status);

	if (status & ACBST_BER) {
		errmsg = "bus error";
		goto error;
	}
	if (!(status & ACBST_MASTER)) {
		errmsg = "not master";
		goto error;
	}
	if (status & ACBST_NEGACK) {
		dev_dbg(&iface->adapter.dev, "negative ack in state %s\n",
			scx200_acb_state_name[iface->state]);

		iface->state = state_idle;
		iface->result = -ENXIO;

		outb(inb(ACBCTL1) | ACBCTL1_STOP, ACBCTL1);
		outb(ACBST_STASTR | ACBST_NEGACK, ACBST);

		/* Reset the status register */
		outb(0, ACBST);
		return;
	}

	switch (iface->state) {
	case state_idle:
		dev_warn(&iface->adapter.dev, "interrupt in idle state\n");
		break;

	case state_address:
		/* Do a pointer write first */
		outb(iface->address_byte & ~1, ACBSDA);

		iface->state = state_command;
		break;

	case state_command:
		outb(iface->command, ACBSDA);

		if (iface->address_byte & 1)
			iface->state = state_repeat_start;
		else
			iface->state = state_write;
		break;

	case state_repeat_start:
		outb(inb(ACBCTL1) | ACBCTL1_START, ACBCTL1);
		/* fallthrough */

	case state_quick:
		if (iface->address_byte & 1) {
			if (iface->len == 1)
				outb(inb(ACBCTL1) | ACBCTL1_ACK, ACBCTL1);
			else
				outb(inb(ACBCTL1) & ~ACBCTL1_ACK, ACBCTL1);
			outb(iface->address_byte, ACBSDA);

			iface->state = state_read;
		} else {
			outb(iface->address_byte, ACBSDA);

			iface->state = state_write;
		}
		break;

	case state_read:
		/* Set ACK if _next_ byte will be the last one */
		if (iface->len == 2)
			outb(inb(ACBCTL1) | ACBCTL1_ACK, ACBCTL1);
		else
			outb(inb(ACBCTL1) & ~ACBCTL1_ACK, ACBCTL1);

		if (iface->len == 1) {
			iface->result = 0;
			iface->state = state_idle;
			outb(inb(ACBCTL1) | ACBCTL1_STOP, ACBCTL1);
		}

		*iface->ptr++ = inb(ACBSDA);
		--iface->len;

		break;

	case state_write:
		if (iface->len == 0) {
			iface->result = 0;
			iface->state = state_idle;
			outb(inb(ACBCTL1) | ACBCTL1_STOP, ACBCTL1);
			break;
		}

		outb(*iface->ptr++, ACBSDA);
		--iface->len;

		break;
	}

	return;

 error:
	dev_err(&iface->adapter.dev,
		"%s in state %s (addr=0x%02x, len=%d, status=0x%02x)\n", errmsg,
		scx200_acb_state_name[iface->state], iface->address_byte,
		iface->len, status);

	iface->state = state_idle;
	iface->result = -EIO;
	iface->needs_reset = 1;
}

__attribute__((used)) static void scx200_acb_poll(struct scx200_acb_iface *iface)
{
	u8 status;
	unsigned long timeout;

	timeout = jiffies + POLL_TIMEOUT;
	while (1) {
		status = inb(ACBST);

		/* Reset the status register to avoid the hang */
		outb(0, ACBST);

		if ((status & (ACBST_SDAST|ACBST_BER|ACBST_NEGACK)) != 0) {
			scx200_acb_machine(iface, status);
			return;
		}
		if (time_after(jiffies, timeout))
			break;
		cpu_relax();
		cond_resched();
	}

	dev_err(&iface->adapter.dev, "timeout in state %s\n",
		scx200_acb_state_name[iface->state]);

	iface->state = state_idle;
	iface->result = -EIO;
	iface->needs_reset = 1;
}

__attribute__((used)) static void scx200_acb_reset(struct scx200_acb_iface *iface)
{
	/* Disable the ACCESS.bus device and Configure the SCL
	   frequency: 16 clock cycles */
	outb(0x70, ACBCTL2);
	/* Polling mode */
	outb(0, ACBCTL1);
	/* Disable slave address */
	outb(0, ACBADDR);
	/* Enable the ACCESS.bus device */
	outb(inb(ACBCTL2) | ACBCTL2_ENABLE, ACBCTL2);
	/* Free STALL after START */
	outb(inb(ACBCTL1) & ~(ACBCTL1_STASTRE | ACBCTL1_NMINTE), ACBCTL1);
	/* Send a STOP */
	outb(inb(ACBCTL1) | ACBCTL1_STOP, ACBCTL1);
	/* Clear BER, NEGACK and STASTR bits */
	outb(ACBST_BER | ACBST_NEGACK | ACBST_STASTR, ACBST);
	/* Clear BB bit */
	outb(inb(ACBCST) | ACBCST_BB, ACBCST);
}

__attribute__((used)) static s32 scx200_acb_smbus_xfer(struct i2c_adapter *adapter,
				 u16 address, unsigned short flags,
				 char rw, u8 command, int size,
				 union i2c_smbus_data *data)
{
	struct scx200_acb_iface *iface = i2c_get_adapdata(adapter);
	int len;
	u8 *buffer;
	u16 cur_word;
	int rc;

	switch (size) {
	case I2C_SMBUS_QUICK:
		len = 0;
		buffer = NULL;
		break;

	case I2C_SMBUS_BYTE:
		len = 1;
		buffer = rw ? &data->byte : &command;
		break;

	case I2C_SMBUS_BYTE_DATA:
		len = 1;
		buffer = &data->byte;
		break;

	case I2C_SMBUS_WORD_DATA:
		len = 2;
		cur_word = cpu_to_le16(data->word);
		buffer = (u8 *)&cur_word;
		break;

	case I2C_SMBUS_I2C_BLOCK_DATA:
		len = data->block[0];
		if (len == 0 || len > I2C_SMBUS_BLOCK_MAX)
			return -EINVAL;
		buffer = &data->block[1];
		break;

	default:
		return -EINVAL;
	}

	dev_dbg(&adapter->dev,
		"size=%d, address=0x%x, command=0x%x, len=%d, read=%d\n",
		size, address, command, len, rw);

	if (!len && rw == I2C_SMBUS_READ) {
		dev_dbg(&adapter->dev, "zero length read\n");
		return -EINVAL;
	}

	mutex_lock(&iface->mutex);

	iface->address_byte = (address << 1) | rw;
	iface->command = command;
	iface->ptr = buffer;
	iface->len = len;
	iface->result = -EINVAL;
	iface->needs_reset = 0;

	outb(inb(ACBCTL1) | ACBCTL1_START, ACBCTL1);

	if (size == I2C_SMBUS_QUICK || size == I2C_SMBUS_BYTE)
		iface->state = state_quick;
	else
		iface->state = state_address;

	while (iface->state != state_idle)
		scx200_acb_poll(iface);

	if (iface->needs_reset)
		scx200_acb_reset(iface);

	rc = iface->result;

	mutex_unlock(&iface->mutex);

	if (rc == 0 && size == I2C_SMBUS_WORD_DATA && rw == I2C_SMBUS_READ)
		data->word = le16_to_cpu(cur_word);

#ifdef DEBUG
	dev_dbg(&adapter->dev, "transfer done, result: %d", rc);
	if (buffer) {
		int i;
		printk(" data:");
		for (i = 0; i < len; ++i)
			printk(" %02x", buffer[i]);
	}
	printk("\n");
#endif

	return rc;
}

__attribute__((used)) static u32 scx200_acb_func(struct i2c_adapter *adapter)
{
	return I2C_FUNC_SMBUS_QUICK | I2C_FUNC_SMBUS_BYTE |
	       I2C_FUNC_SMBUS_BYTE_DATA | I2C_FUNC_SMBUS_WORD_DATA |
	       I2C_FUNC_SMBUS_I2C_BLOCK;
}

__attribute__((used)) static int scx200_acb_probe(struct scx200_acb_iface *iface)
{
	u8 val;

	/* Disable the ACCESS.bus device and Configure the SCL
	   frequency: 16 clock cycles */
	outb(0x70, ACBCTL2);

	if (inb(ACBCTL2) != 0x70) {
		pr_debug("ACBCTL2 readback failed\n");
		return -ENXIO;
	}

	outb(inb(ACBCTL1) | ACBCTL1_NMINTE, ACBCTL1);

	val = inb(ACBCTL1);
	if (val) {
		pr_debug("disabled, but ACBCTL1=0x%02x\n", val);
		return -ENXIO;
	}

	outb(inb(ACBCTL2) | ACBCTL2_ENABLE, ACBCTL2);

	outb(inb(ACBCTL1) | ACBCTL1_NMINTE, ACBCTL1);

	val = inb(ACBCTL1);
	if ((val & ACBCTL1_NMINTE) != ACBCTL1_NMINTE) {
		pr_debug("enabled, but NMINTE won't be set, ACBCTL1=0x%02x\n",
			 val);
		return -ENXIO;
	}

	return 0;
}

__attribute__((used)) static struct scx200_acb_iface *scx200_create_iface(const char *text,
		struct device *dev, int index)
{
	struct scx200_acb_iface *iface;
	struct i2c_adapter *adapter;

	iface = kzalloc(sizeof(*iface), GFP_KERNEL);
	if (!iface)
		return NULL;

	adapter = &iface->adapter;
	i2c_set_adapdata(adapter, iface);
	snprintf(adapter->name, sizeof(adapter->name), "%s ACB%d", text, index);
	adapter->owner = THIS_MODULE;
	adapter->algo = &scx200_acb_algorithm;
	adapter->class = I2C_CLASS_HWMON | I2C_CLASS_SPD;
	adapter->dev.parent = dev;

	mutex_init(&iface->mutex);

	return iface;
}

__attribute__((used)) static int scx200_acb_create(struct scx200_acb_iface *iface)
{
	struct i2c_adapter *adapter;
	int rc;

	adapter = &iface->adapter;

	rc = scx200_acb_probe(iface);
	if (rc) {
		pr_warn("probe failed\n");
		return rc;
	}

	scx200_acb_reset(iface);

	if (i2c_add_adapter(adapter) < 0) {
		pr_err("failed to register\n");
		return -ENODEV;
	}

	if (!adapter->dev.parent) {
		/* If there's no dev, we're tracking (ISA) ifaces manually */
		mutex_lock(&scx200_acb_list_mutex);
		iface->next = scx200_acb_list;
		scx200_acb_list = iface;
		mutex_unlock(&scx200_acb_list_mutex);
	}

	return 0;
}

__attribute__((used)) static struct scx200_acb_iface *scx200_create_dev(const char *text,
		unsigned long base, int index, struct device *dev)
{
	struct scx200_acb_iface *iface;
	int rc;

	iface = scx200_create_iface(text, dev, index);

	if (iface == NULL)
		return NULL;

	if (!request_region(base, 8, iface->adapter.name)) {
		pr_err("can't allocate io 0x%lx-0x%lx\n", base, base + 8 - 1);
		goto errout_free;
	}

	iface->base = base;
	rc = scx200_acb_create(iface);

	if (rc == 0)
		return iface;

	release_region(base, 8);
 errout_free:
	kfree(iface);
	return NULL;
}

__attribute__((used)) static int scx200_probe(struct platform_device *pdev)
{
	struct scx200_acb_iface *iface;
	struct resource *res;

	res = platform_get_resource(pdev, IORESOURCE_IO, 0);
	if (!res) {
		dev_err(&pdev->dev, "can't fetch device resource info\n");
		return -ENODEV;
	}

	iface = scx200_create_dev("CS5535", res->start, 0, &pdev->dev);
	if (!iface)
		return -EIO;

	dev_info(&pdev->dev, "SCx200 device '%s' registered\n",
			iface->adapter.name);
	platform_set_drvdata(pdev, iface);

	return 0;
}

__attribute__((used)) static void scx200_cleanup_iface(struct scx200_acb_iface *iface)
{
	i2c_del_adapter(&iface->adapter);
	release_region(iface->base, 8);
	kfree(iface);
}

__attribute__((used)) static int scx200_remove(struct platform_device *pdev)
{
	struct scx200_acb_iface *iface;

	iface = platform_get_drvdata(pdev);
	scx200_cleanup_iface(iface);

	return 0;
}

