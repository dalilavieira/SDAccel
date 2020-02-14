#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
union i2c_smbus_data {int* block; char byte; int word; } ;
typedef  char u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct pci_device_id {int dummy; } ;
struct pci_dev {int /*<<< orphan*/  dev; } ;
struct i2c_adapter {int /*<<< orphan*/  dev; } ;
typedef  int s32 ;
struct TYPE_8__ {int /*<<< orphan*/  name; } ;
struct TYPE_6__ {int /*<<< orphan*/ * parent; } ;
struct TYPE_7__ {int /*<<< orphan*/  name; TYPE_1__ dev; } ;

/* Variables and functions */
 int ALI1563_MAX_TIMEOUT ; 
 int /*<<< orphan*/  ALI1563_SMBBA ; 
 int ALI1563_SMB_HOSTEN ; 
 int ALI1563_SMB_IOEN ; 
 int ALI1563_SMB_IOSIZE ; 
 int EBUSY ; 
 int EIO ; 
 int ENODEV ; 
 int ENXIO ; 
 int EOPNOTSUPP ; 
 int ETIMEDOUT ; 
 char HST_CNTL1_LAST ; 
 char HST_CNTL1_TIMEOUT ; 
#define  HST_CNTL2_BLOCK 136 
#define  HST_CNTL2_BYTE 135 
#define  HST_CNTL2_BYTE_DATA 134 
 char HST_CNTL2_KILL ; 
 int HST_CNTL2_QUICK ; 
 int HST_CNTL2_SIZEMASK ; 
 char HST_CNTL2_START ; 
#define  HST_CNTL2_WORD_DATA 133 
 int HST_STS_BAD ; 
 int HST_STS_BUSERR ; 
 int HST_STS_BUSY ; 
 int HST_STS_DEVERR ; 
 int HST_STS_DONE ; 
 int HST_STS_FAIL ; 
 int I2C_FUNC_SMBUS_BLOCK_DATA ; 
 int I2C_FUNC_SMBUS_BYTE ; 
 int I2C_FUNC_SMBUS_BYTE_DATA ; 
 int I2C_FUNC_SMBUS_QUICK ; 
 int I2C_FUNC_SMBUS_WORD_DATA ; 
#define  I2C_SMBUS_BLOCK_DATA 132 
#define  I2C_SMBUS_BYTE 131 
#define  I2C_SMBUS_BYTE_DATA 130 
#define  I2C_SMBUS_QUICK 129 
#define  I2C_SMBUS_WORD_DATA 128 
 char I2C_SMBUS_WRITE ; 
 int /*<<< orphan*/  SMB_BLK_DAT ; 
 int /*<<< orphan*/  SMB_HST_ADD ; 
 int /*<<< orphan*/  SMB_HST_CMD ; 
 int /*<<< orphan*/  SMB_HST_CNTL1 ; 
 int /*<<< orphan*/  SMB_HST_CNTL2 ; 
 int /*<<< orphan*/  SMB_HST_DAT0 ; 
 int /*<<< orphan*/  SMB_HST_DAT1 ; 
 int /*<<< orphan*/  SMB_HST_STS ; 
 scalar_t__ acpi_check_region (int,int,int /*<<< orphan*/ ) ; 
 TYPE_2__ ali1563_adapter ; 
 TYPE_4__ ali1563_pci_driver ; 
 int ali1563_smba ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*,...) ; 
 int i2c_add_adapter (TYPE_2__*) ; 
 int /*<<< orphan*/  i2c_del_adapter (TYPE_2__*) ; 
 int inb_p (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  outb_p (char,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_read_config_word (struct pci_dev*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  pci_write_config_word (struct pci_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  release_region (int,int) ; 
 int /*<<< orphan*/  request_region (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,int) ; 

__attribute__((used)) static int ali1563_transaction(struct i2c_adapter *a, int size)
{
	u32 data;
	int timeout;
	int status = -EIO;

	dev_dbg(&a->dev, "Transaction (pre): STS=%02x, CNTL1=%02x, "
		"CNTL2=%02x, CMD=%02x, ADD=%02x, DAT0=%02x, DAT1=%02x\n",
		inb_p(SMB_HST_STS), inb_p(SMB_HST_CNTL1), inb_p(SMB_HST_CNTL2),
		inb_p(SMB_HST_CMD), inb_p(SMB_HST_ADD), inb_p(SMB_HST_DAT0),
		inb_p(SMB_HST_DAT1));

	data = inb_p(SMB_HST_STS);
	if (data & HST_STS_BAD) {
		dev_err(&a->dev, "ali1563: Trying to reset busy device\n");
		outb_p(data | HST_STS_BAD, SMB_HST_STS);
		data = inb_p(SMB_HST_STS);
		if (data & HST_STS_BAD)
			return -EBUSY;
	}
	outb_p(inb_p(SMB_HST_CNTL2) | HST_CNTL2_START, SMB_HST_CNTL2);

	timeout = ALI1563_MAX_TIMEOUT;
	do {
		msleep(1);
	} while (((data = inb_p(SMB_HST_STS)) & HST_STS_BUSY) && --timeout);

	dev_dbg(&a->dev, "Transaction (post): STS=%02x, CNTL1=%02x, "
		"CNTL2=%02x, CMD=%02x, ADD=%02x, DAT0=%02x, DAT1=%02x\n",
		inb_p(SMB_HST_STS), inb_p(SMB_HST_CNTL1), inb_p(SMB_HST_CNTL2),
		inb_p(SMB_HST_CMD), inb_p(SMB_HST_ADD), inb_p(SMB_HST_DAT0),
		inb_p(SMB_HST_DAT1));

	if (timeout && !(data & HST_STS_BAD))
		return 0;

	if (!timeout) {
		dev_err(&a->dev, "Timeout - Trying to KILL transaction!\n");
		/* Issue 'kill' to host controller */
		outb_p(HST_CNTL2_KILL, SMB_HST_CNTL2);
		data = inb_p(SMB_HST_STS);
		status = -ETIMEDOUT;
	}

	/* device error - no response, ignore the autodetection case */
	if (data & HST_STS_DEVERR) {
		if (size != HST_CNTL2_QUICK)
			dev_err(&a->dev, "Device error!\n");
		status = -ENXIO;
	}
	/* bus collision */
	if (data & HST_STS_BUSERR) {
		dev_err(&a->dev, "Bus collision!\n");
		/* Issue timeout, hoping it helps */
		outb_p(HST_CNTL1_TIMEOUT, SMB_HST_CNTL1);
	}

	if (data & HST_STS_FAIL) {
		dev_err(&a->dev, "Cleaning fail after KILL!\n");
		outb_p(0x0, SMB_HST_CNTL2);
	}

	return status;
}

__attribute__((used)) static int ali1563_block_start(struct i2c_adapter *a)
{
	u32 data;
	int timeout;
	int status = -EIO;

	dev_dbg(&a->dev, "Block (pre): STS=%02x, CNTL1=%02x, "
		"CNTL2=%02x, CMD=%02x, ADD=%02x, DAT0=%02x, DAT1=%02x\n",
		inb_p(SMB_HST_STS), inb_p(SMB_HST_CNTL1), inb_p(SMB_HST_CNTL2),
		inb_p(SMB_HST_CMD), inb_p(SMB_HST_ADD), inb_p(SMB_HST_DAT0),
		inb_p(SMB_HST_DAT1));

	data = inb_p(SMB_HST_STS);
	if (data & HST_STS_BAD) {
		dev_warn(&a->dev, "ali1563: Trying to reset busy device\n");
		outb_p(data | HST_STS_BAD, SMB_HST_STS);
		data = inb_p(SMB_HST_STS);
		if (data & HST_STS_BAD)
			return -EBUSY;
	}

	/* Clear byte-ready bit */
	outb_p(data | HST_STS_DONE, SMB_HST_STS);

	/* Start transaction and wait for byte-ready bit to be set */
	outb_p(inb_p(SMB_HST_CNTL2) | HST_CNTL2_START, SMB_HST_CNTL2);

	timeout = ALI1563_MAX_TIMEOUT;
	do {
		msleep(1);
	} while (!((data = inb_p(SMB_HST_STS)) & HST_STS_DONE) && --timeout);

	dev_dbg(&a->dev, "Block (post): STS=%02x, CNTL1=%02x, "
		"CNTL2=%02x, CMD=%02x, ADD=%02x, DAT0=%02x, DAT1=%02x\n",
		inb_p(SMB_HST_STS), inb_p(SMB_HST_CNTL1), inb_p(SMB_HST_CNTL2),
		inb_p(SMB_HST_CMD), inb_p(SMB_HST_ADD), inb_p(SMB_HST_DAT0),
		inb_p(SMB_HST_DAT1));

	if (timeout && !(data & HST_STS_BAD))
		return 0;

	if (timeout == 0)
		status = -ETIMEDOUT;

	if (data & HST_STS_DEVERR)
		status = -ENXIO;

	dev_err(&a->dev, "SMBus Error: %s%s%s%s%s\n",
		timeout ? "" : "Timeout ",
		data & HST_STS_FAIL ? "Transaction Failed " : "",
		data & HST_STS_BUSERR ? "No response or Bus Collision " : "",
		data & HST_STS_DEVERR ? "Device Error " : "",
		!(data & HST_STS_DONE) ? "Transaction Never Finished " : "");
	return status;
}

__attribute__((used)) static int ali1563_block(struct i2c_adapter *a,
			 union i2c_smbus_data *data, u8 rw)
{
	int i, len;
	int error = 0;

	/* Do we need this? */
	outb_p(HST_CNTL1_LAST, SMB_HST_CNTL1);

	if (rw == I2C_SMBUS_WRITE) {
		len = data->block[0];
		if (len < 1)
			len = 1;
		else if (len > 32)
			len = 32;
		outb_p(len, SMB_HST_DAT0);
		outb_p(data->block[1], SMB_BLK_DAT);
	} else
		len = 32;

	outb_p(inb_p(SMB_HST_CNTL2) | HST_CNTL2_BLOCK, SMB_HST_CNTL2);

	for (i = 0; i < len; i++) {
		if (rw == I2C_SMBUS_WRITE) {
			outb_p(data->block[i + 1], SMB_BLK_DAT);
			error = ali1563_block_start(a);
			if (error)
				break;
		} else {
			error = ali1563_block_start(a);
			if (error)
				break;
			if (i == 0) {
				len = inb_p(SMB_HST_DAT0);
				if (len < 1)
					len = 1;
				else if (len > 32)
					len = 32;
			}
			data->block[i+1] = inb_p(SMB_BLK_DAT);
		}
	}
	/* Do we need this? */
	outb_p(HST_CNTL1_LAST, SMB_HST_CNTL1);
	return error;
}

__attribute__((used)) static s32 ali1563_access(struct i2c_adapter *a, u16 addr,
			  unsigned short flags, char rw, u8 cmd,
			  int size, union i2c_smbus_data *data)
{
	int error = 0;
	int timeout;
	u32 reg;

	for (timeout = ALI1563_MAX_TIMEOUT; timeout; timeout--) {
		reg = inb_p(SMB_HST_STS);
		if (!(reg & HST_STS_BUSY))
			break;
	}
	if (!timeout)
		dev_warn(&a->dev, "SMBus not idle. HST_STS = %02x\n", reg);
	outb_p(0xff, SMB_HST_STS);

	/* Map the size to what the chip understands */
	switch (size) {
	case I2C_SMBUS_QUICK:
		size = HST_CNTL2_QUICK;
		break;
	case I2C_SMBUS_BYTE:
		size = HST_CNTL2_BYTE;
		break;
	case I2C_SMBUS_BYTE_DATA:
		size = HST_CNTL2_BYTE_DATA;
		break;
	case I2C_SMBUS_WORD_DATA:
		size = HST_CNTL2_WORD_DATA;
		break;
	case I2C_SMBUS_BLOCK_DATA:
		size = HST_CNTL2_BLOCK;
		break;
	default:
		dev_warn(&a->dev, "Unsupported transaction %d\n", size);
		error = -EOPNOTSUPP;
		goto Done;
	}

	outb_p(((addr & 0x7f) << 1) | (rw & 0x01), SMB_HST_ADD);
	outb_p((inb_p(SMB_HST_CNTL2) & ~HST_CNTL2_SIZEMASK) |
	       (size << 3), SMB_HST_CNTL2);

	/* Write the command register */

	switch (size) {
	case HST_CNTL2_BYTE:
		if (rw == I2C_SMBUS_WRITE)
			/* Beware it uses DAT0 register and not CMD! */
			outb_p(cmd, SMB_HST_DAT0);
		break;
	case HST_CNTL2_BYTE_DATA:
		outb_p(cmd, SMB_HST_CMD);
		if (rw == I2C_SMBUS_WRITE)
			outb_p(data->byte, SMB_HST_DAT0);
		break;
	case HST_CNTL2_WORD_DATA:
		outb_p(cmd, SMB_HST_CMD);
		if (rw == I2C_SMBUS_WRITE) {
			outb_p(data->word & 0xff, SMB_HST_DAT0);
			outb_p((data->word & 0xff00) >> 8, SMB_HST_DAT1);
		}
		break;
	case HST_CNTL2_BLOCK:
		outb_p(cmd, SMB_HST_CMD);
		error = ali1563_block(a, data, rw);
		goto Done;
	}

	error = ali1563_transaction(a, size);
	if (error)
		goto Done;

	if ((rw == I2C_SMBUS_WRITE) || (size == HST_CNTL2_QUICK))
		goto Done;

	switch (size) {
	case HST_CNTL2_BYTE:	/* Result put in SMBHSTDAT0 */
		data->byte = inb_p(SMB_HST_DAT0);
		break;
	case HST_CNTL2_BYTE_DATA:
		data->byte = inb_p(SMB_HST_DAT0);
		break;
	case HST_CNTL2_WORD_DATA:
		data->word = inb_p(SMB_HST_DAT0) + (inb_p(SMB_HST_DAT1) << 8);
		break;
	}
Done:
	return error;
}

__attribute__((used)) static u32 ali1563_func(struct i2c_adapter *a)
{
	return I2C_FUNC_SMBUS_QUICK | I2C_FUNC_SMBUS_BYTE |
	    I2C_FUNC_SMBUS_BYTE_DATA | I2C_FUNC_SMBUS_WORD_DATA |
	    I2C_FUNC_SMBUS_BLOCK_DATA;
}

__attribute__((used)) static int ali1563_setup(struct pci_dev *dev)
{
	u16 ctrl;

	pci_read_config_word(dev, ALI1563_SMBBA, &ctrl);

	/* SMB I/O Base in high 12 bits and must be aligned with the
	 * size of the I/O space. */
	ali1563_smba = ctrl & ~(ALI1563_SMB_IOSIZE - 1);
	if (!ali1563_smba) {
		dev_warn(&dev->dev, "ali1563_smba Uninitialized\n");
		goto Err;
	}

	/* Check if device is enabled */
	if (!(ctrl & ALI1563_SMB_HOSTEN)) {
		dev_warn(&dev->dev, "Host Controller not enabled\n");
		goto Err;
	}
	if (!(ctrl & ALI1563_SMB_IOEN)) {
		dev_warn(&dev->dev, "I/O space not enabled, trying manually\n");
		pci_write_config_word(dev, ALI1563_SMBBA,
				      ctrl | ALI1563_SMB_IOEN);
		pci_read_config_word(dev, ALI1563_SMBBA, &ctrl);
		if (!(ctrl & ALI1563_SMB_IOEN)) {
			dev_err(&dev->dev,
				"I/O space still not enabled, giving up\n");
			goto Err;
		}
	}

	if (acpi_check_region(ali1563_smba, ALI1563_SMB_IOSIZE,
			      ali1563_pci_driver.name))
		goto Err;

	if (!request_region(ali1563_smba, ALI1563_SMB_IOSIZE,
			    ali1563_pci_driver.name)) {
		dev_err(&dev->dev, "Could not allocate I/O space at 0x%04x\n",
			ali1563_smba);
		goto Err;
	}
	dev_info(&dev->dev, "Found ALi1563 SMBus at 0x%04x\n", ali1563_smba);

	return 0;
Err:
	return -ENODEV;
}

__attribute__((used)) static void ali1563_shutdown(struct pci_dev *dev)
{
	release_region(ali1563_smba, ALI1563_SMB_IOSIZE);
}

__attribute__((used)) static int ali1563_probe(struct pci_dev *dev,
			 const struct pci_device_id *id_table)
{
	int error;

	error = ali1563_setup(dev);
	if (error)
		goto exit;
	ali1563_adapter.dev.parent = &dev->dev;
	snprintf(ali1563_adapter.name, sizeof(ali1563_adapter.name),
		 "SMBus ALi 1563 Adapter @ %04x", ali1563_smba);
	error = i2c_add_adapter(&ali1563_adapter);
	if (error)
		goto exit_shutdown;
	return 0;

exit_shutdown:
	ali1563_shutdown(dev);
exit:
	dev_warn(&dev->dev, "ALi1563 SMBus probe failed (%d)\n", error);
	return error;
}

__attribute__((used)) static void ali1563_remove(struct pci_dev *dev)
{
	i2c_del_adapter(&ali1563_adapter);
	ali1563_shutdown(dev);
}

