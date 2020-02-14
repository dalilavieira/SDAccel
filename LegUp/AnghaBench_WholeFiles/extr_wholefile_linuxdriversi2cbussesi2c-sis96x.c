#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_5__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
union i2c_smbus_data {int byte; int word; } ;
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct pci_device_id {int dummy; } ;
struct pci_dev {int /*<<< orphan*/  dev; int /*<<< orphan*/ * resource; } ;
struct i2c_adapter {int /*<<< orphan*/  dev; } ;
typedef  int s32 ;
struct TYPE_8__ {int /*<<< orphan*/ * parent; } ;
struct TYPE_7__ {int /*<<< orphan*/  name; TYPE_5__ dev; } ;
struct TYPE_6__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int EBUSY ; 
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENXIO ; 
 int EOPNOTSUPP ; 
 int ETIMEDOUT ; 
 int I2C_FUNC_SMBUS_BYTE ; 
 int I2C_FUNC_SMBUS_BYTE_DATA ; 
 int I2C_FUNC_SMBUS_PROC_CALL ; 
 int I2C_FUNC_SMBUS_QUICK ; 
 int I2C_FUNC_SMBUS_WORD_DATA ; 
#define  I2C_SMBUS_BYTE 136 
#define  I2C_SMBUS_BYTE_DATA 135 
#define  I2C_SMBUS_PROC_CALL 134 
#define  I2C_SMBUS_QUICK 133 
#define  I2C_SMBUS_WORD_DATA 132 
 char I2C_SMBUS_WRITE ; 
 int MAX_TIMEOUT ; 
 int /*<<< orphan*/  PCI_CLASS_DEVICE ; 
 int PCI_CLASS_SERIAL_SMBUS ; 
 size_t SIS96x_BAR ; 
#define  SIS96x_BYTE 131 
#define  SIS96x_BYTE_DATA 130 
#define  SIS96x_PROC_CALL 129 
 int SIS96x_QUICK ; 
#define  SIS96x_WORD_DATA 128 
 int SMB_ADDR ; 
 int SMB_BYTE ; 
 int SMB_CMD ; 
 int SMB_CNT ; 
 int SMB_HOST_CNT ; 
 int SMB_IOSIZE ; 
 int SMB_STS ; 
 int acpi_check_resource_conflict (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_dbg (TYPE_5__*,char*,...) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*,int) ; 
 int i2c_add_adapter (TYPE_2__*) ; 
 int /*<<< orphan*/  i2c_del_adapter (TYPE_2__*) ; 
 int inb (int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  outb (int,int) ; 
 int /*<<< orphan*/  pci_read_config_word (struct pci_dev*,int /*<<< orphan*/ ,int*) ; 
 int pci_resource_start (struct pci_dev*,size_t) ; 
 int /*<<< orphan*/  release_region (int,int) ; 
 int /*<<< orphan*/  request_region (int,int,int /*<<< orphan*/ ) ; 
 TYPE_2__ sis96x_adapter ; 
 TYPE_1__ sis96x_driver ; 
 int sis96x_smbus_base ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,int) ; 

__attribute__((used)) static inline u8 sis96x_read(u8 reg)
{
	return inb(sis96x_smbus_base + reg) ;
}

__attribute__((used)) static inline void sis96x_write(u8 reg, u8 data)
{
	outb(data, sis96x_smbus_base + reg) ;
}

__attribute__((used)) static int sis96x_transaction(int size)
{
	int temp;
	int result = 0;
	int timeout = 0;

	dev_dbg(&sis96x_adapter.dev, "SMBus transaction %d\n", size);

	/* Make sure the SMBus host is ready to start transmitting */
	if (((temp = sis96x_read(SMB_CNT)) & 0x03) != 0x00) {

		dev_dbg(&sis96x_adapter.dev, "SMBus busy (0x%02x). "
			"Resetting...\n", temp);

		/* kill the transaction */
		sis96x_write(SMB_HOST_CNT, 0x20);

		/* check it again */
		if (((temp = sis96x_read(SMB_CNT)) & 0x03) != 0x00) {
			dev_dbg(&sis96x_adapter.dev, "Failed (0x%02x)\n", temp);
			return -EBUSY;
		} else {
			dev_dbg(&sis96x_adapter.dev, "Successful\n");
		}
	}

	/* Turn off timeout interrupts, set fast host clock */
	sis96x_write(SMB_CNT, 0x20);

	/* clear all (sticky) status flags */
	temp = sis96x_read(SMB_STS);
	sis96x_write(SMB_STS, temp & 0x1e);

	/* start the transaction by setting bit 4 and size bits */
	sis96x_write(SMB_HOST_CNT, 0x10 | (size & 0x07));

	/* We will always wait for a fraction of a second! */
	do {
		msleep(1);
		temp = sis96x_read(SMB_STS);
	} while (!(temp & 0x0e) && (timeout++ < MAX_TIMEOUT));

	/* If the SMBus is still busy, we give up */
	if (timeout > MAX_TIMEOUT) {
		dev_dbg(&sis96x_adapter.dev, "SMBus Timeout! (0x%02x)\n", temp);
		result = -ETIMEDOUT;
	}

	/* device error - probably missing ACK */
	if (temp & 0x02) {
		dev_dbg(&sis96x_adapter.dev, "Failed bus transaction!\n");
		result = -ENXIO;
	}

	/* bus collision */
	if (temp & 0x04) {
		dev_dbg(&sis96x_adapter.dev, "Bus collision!\n");
		result = -EIO;
	}

	/* Finish up by resetting the bus */
	sis96x_write(SMB_STS, temp);
	if ((temp = sis96x_read(SMB_STS))) {
		dev_dbg(&sis96x_adapter.dev, "Failed reset at "
			"end of transaction! (0x%02x)\n", temp);
	}

	return result;
}

__attribute__((used)) static s32 sis96x_access(struct i2c_adapter * adap, u16 addr,
			 unsigned short flags, char read_write,
			 u8 command, int size, union i2c_smbus_data * data)
{
	int status;

	switch (size) {
	case I2C_SMBUS_QUICK:
		sis96x_write(SMB_ADDR, ((addr & 0x7f) << 1) | (read_write & 0x01));
		size = SIS96x_QUICK;
		break;

	case I2C_SMBUS_BYTE:
		sis96x_write(SMB_ADDR, ((addr & 0x7f) << 1) | (read_write & 0x01));
		if (read_write == I2C_SMBUS_WRITE)
			sis96x_write(SMB_CMD, command);
		size = SIS96x_BYTE;
		break;

	case I2C_SMBUS_BYTE_DATA:
		sis96x_write(SMB_ADDR, ((addr & 0x7f) << 1) | (read_write & 0x01));
		sis96x_write(SMB_CMD, command);
		if (read_write == I2C_SMBUS_WRITE)
			sis96x_write(SMB_BYTE, data->byte);
		size = SIS96x_BYTE_DATA;
		break;

	case I2C_SMBUS_PROC_CALL:
	case I2C_SMBUS_WORD_DATA:
		sis96x_write(SMB_ADDR, ((addr & 0x7f) << 1) | (read_write & 0x01));
		sis96x_write(SMB_CMD, command);
		if (read_write == I2C_SMBUS_WRITE) {
			sis96x_write(SMB_BYTE, data->word & 0xff);
			sis96x_write(SMB_BYTE + 1, (data->word & 0xff00) >> 8);
		}
		size = (size == I2C_SMBUS_PROC_CALL ? 
			SIS96x_PROC_CALL : SIS96x_WORD_DATA);
		break;

	default:
		dev_warn(&adap->dev, "Unsupported transaction %d\n", size);
		return -EOPNOTSUPP;
	}

	status = sis96x_transaction(size);
	if (status)
		return status;

	if ((size != SIS96x_PROC_CALL) &&
		((read_write == I2C_SMBUS_WRITE) || (size == SIS96x_QUICK)))
		return 0;

	switch (size) {
	case SIS96x_BYTE:
	case SIS96x_BYTE_DATA:
		data->byte = sis96x_read(SMB_BYTE);
		break;

	case SIS96x_WORD_DATA:
	case SIS96x_PROC_CALL:
		data->word = sis96x_read(SMB_BYTE) +
				(sis96x_read(SMB_BYTE + 1) << 8);
		break;
	}
	return 0;
}

__attribute__((used)) static u32 sis96x_func(struct i2c_adapter *adapter)
{
	return I2C_FUNC_SMBUS_QUICK | I2C_FUNC_SMBUS_BYTE |
	    I2C_FUNC_SMBUS_BYTE_DATA | I2C_FUNC_SMBUS_WORD_DATA |
	    I2C_FUNC_SMBUS_PROC_CALL;
}

__attribute__((used)) static int sis96x_probe(struct pci_dev *dev,
				const struct pci_device_id *id)
{
	u16 ww = 0;
	int retval;

	if (sis96x_smbus_base) {
		dev_err(&dev->dev, "Only one device supported.\n");
		return -EBUSY;
	}

	pci_read_config_word(dev, PCI_CLASS_DEVICE, &ww);
	if (PCI_CLASS_SERIAL_SMBUS != ww) {
		dev_err(&dev->dev, "Unsupported device class 0x%04x!\n", ww);
		return -ENODEV;
	}

	sis96x_smbus_base = pci_resource_start(dev, SIS96x_BAR);
	if (!sis96x_smbus_base) {
		dev_err(&dev->dev, "SiS96x SMBus base address "
			"not initialized!\n");
		return -EINVAL;
	}
	dev_info(&dev->dev, "SiS96x SMBus base address: 0x%04x\n",
			sis96x_smbus_base);

	retval = acpi_check_resource_conflict(&dev->resource[SIS96x_BAR]);
	if (retval)
		return -ENODEV;

	/* Everything is happy, let's grab the memory and set things up. */
	if (!request_region(sis96x_smbus_base, SMB_IOSIZE,
			    sis96x_driver.name)) {
		dev_err(&dev->dev, "SMBus registers 0x%04x-0x%04x "
			"already in use!\n", sis96x_smbus_base,
			sis96x_smbus_base + SMB_IOSIZE - 1);

		sis96x_smbus_base = 0;
		return -EINVAL;
	}

	/* set up the sysfs linkage to our parent device */
	sis96x_adapter.dev.parent = &dev->dev;

	snprintf(sis96x_adapter.name, sizeof(sis96x_adapter.name),
		"SiS96x SMBus adapter at 0x%04x", sis96x_smbus_base);

	if ((retval = i2c_add_adapter(&sis96x_adapter))) {
		dev_err(&dev->dev, "Couldn't register adapter!\n");
		release_region(sis96x_smbus_base, SMB_IOSIZE);
		sis96x_smbus_base = 0;
	}

	return retval;
}

__attribute__((used)) static void sis96x_remove(struct pci_dev *dev)
{
	if (sis96x_smbus_base) {
		i2c_del_adapter(&sis96x_adapter);
		release_region(sis96x_smbus_base, SMB_IOSIZE);
		sis96x_smbus_base = 0;
	}
}

