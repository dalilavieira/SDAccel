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
union i2c_smbus_data {int byte; int word; int* block; } ;
typedef  int u8 ;
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
 int ALI1535_BLOCK_CLR ; 
#define  ALI1535_BLOCK_DATA 136 
#define  ALI1535_BYTE 135 
#define  ALI1535_BYTE_DATA 134 
 int ALI1535_KILL ; 
 int ALI1535_QUICK ; 
 unsigned char ALI1535_SMBIO_EN ; 
 int ALI1535_SMB_IOSIZE ; 
 int ALI1535_STS_BUSERR ; 
 int ALI1535_STS_BUSY ; 
 int ALI1535_STS_DEV ; 
 int ALI1535_STS_DONE ; 
 int ALI1535_STS_ERR ; 
 int ALI1535_STS_FAIL ; 
 int ALI1535_STS_IDLE ; 
 int ALI1535_T_OUT ; 
#define  ALI1535_WORD_DATA 133 
 int EBUSY ; 
 int EIO ; 
 int ENODEV ; 
 int ENXIO ; 
 int EOPNOTSUPP ; 
 int ETIMEDOUT ; 
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
 int IORESOURCE_IO ; 
 int MAX_TIMEOUT ; 
 int /*<<< orphan*/  SMBBA ; 
 int /*<<< orphan*/  SMBBLKDAT ; 
 int /*<<< orphan*/  SMBCFG ; 
 int /*<<< orphan*/  SMBCLK ; 
 int /*<<< orphan*/  SMBHSTADD ; 
 int /*<<< orphan*/  SMBHSTCFG ; 
 int /*<<< orphan*/  SMBHSTCMD ; 
 int /*<<< orphan*/  SMBHSTDAT0 ; 
 int /*<<< orphan*/  SMBHSTDAT1 ; 
 int /*<<< orphan*/  SMBHSTPORT ; 
 int /*<<< orphan*/  SMBHSTSTS ; 
 int /*<<< orphan*/  SMBHSTTYP ; 
 int /*<<< orphan*/  SMBREV ; 
 int acpi_check_region (int,int,int /*<<< orphan*/ ) ; 
 TYPE_2__ ali1535_adapter ; 
 TYPE_4__ ali1535_driver ; 
 int ali1535_offset ; 
 int ali1535_smba ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*,...) ; 
 int i2c_add_adapter (TYPE_2__*) ; 
 int /*<<< orphan*/  i2c_del_adapter (TYPE_2__*) ; 
 int inb_p (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  outb_p (int,int /*<<< orphan*/ ) ; 
 int pci_enable_device (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_read_config_byte (struct pci_dev*,int /*<<< orphan*/ ,unsigned char*) ; 
 int /*<<< orphan*/  pci_read_config_word (struct pci_dev*,int /*<<< orphan*/ ,int*) ; 
 int pci_resource_flags (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int pci_resource_start (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_write_config_byte (struct pci_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  release_region (int,int) ; 
 int /*<<< orphan*/  request_region (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,int) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static int ali1535_setup(struct pci_dev *dev)
{
	int retval;
	unsigned char temp;

	/* Check the following things:
		- SMB I/O address is initialized
		- Device is enabled
		- We can use the addresses
	*/

	retval = pci_enable_device(dev);
	if (retval) {
		dev_err(&dev->dev, "ALI1535_smb can't enable device\n");
		goto exit;
	}

	/* Determine the address of the SMBus area */
	pci_read_config_word(dev, SMBBA, &ali1535_offset);
	dev_dbg(&dev->dev, "ALI1535_smb is at offset 0x%04x\n", ali1535_offset);
	ali1535_offset &= (0xffff & ~(ALI1535_SMB_IOSIZE - 1));
	if (ali1535_offset == 0) {
		dev_warn(&dev->dev,
			"ALI1535_smb region uninitialized - upgrade BIOS?\n");
		retval = -ENODEV;
		goto exit;
	}

	if (pci_resource_flags(dev, 0) & IORESOURCE_IO)
		ali1535_smba = pci_resource_start(dev, 0) + ali1535_offset;
	else
		ali1535_smba = ali1535_offset;

	retval = acpi_check_region(ali1535_smba, ALI1535_SMB_IOSIZE,
				   ali1535_driver.name);
	if (retval)
		goto exit;

	if (!request_region(ali1535_smba, ALI1535_SMB_IOSIZE,
			    ali1535_driver.name)) {
		dev_err(&dev->dev, "ALI1535_smb region 0x%lx already in use!\n",
			ali1535_smba);
		retval = -EBUSY;
		goto exit;
	}

	/* check if whole device is enabled */
	pci_read_config_byte(dev, SMBCFG, &temp);
	if ((temp & ALI1535_SMBIO_EN) == 0) {
		dev_err(&dev->dev, "SMB device not enabled - upgrade BIOS?\n");
		retval = -ENODEV;
		goto exit_free;
	}

	/* Is SMB Host controller enabled? */
	pci_read_config_byte(dev, SMBHSTCFG, &temp);
	if ((temp & 1) == 0) {
		dev_err(&dev->dev, "SMBus controller not enabled - upgrade BIOS?\n");
		retval = -ENODEV;
		goto exit_free;
	}

	/* set SMB clock to 74KHz as recommended in data sheet */
	pci_write_config_byte(dev, SMBCLK, 0x20);

	/*
	  The interrupt routing for SMB is set up in register 0x77 in the
	  1533 ISA Bridge device, NOT in the 7101 device.
	  Don't bother with finding the 1533 device and reading the register.
	if ((....... & 0x0F) == 1)
		dev_dbg(&dev->dev, "ALI1535 using Interrupt 9 for SMBus.\n");
	*/
	pci_read_config_byte(dev, SMBREV, &temp);
	dev_dbg(&dev->dev, "SMBREV = 0x%X\n", temp);
	dev_dbg(&dev->dev, "ALI1535_smba = 0x%lx\n", ali1535_smba);

	return 0;

exit_free:
	release_region(ali1535_smba, ALI1535_SMB_IOSIZE);
exit:
	return retval;
}

__attribute__((used)) static int ali1535_transaction(struct i2c_adapter *adap)
{
	int temp;
	int result = 0;
	int timeout = 0;

	dev_dbg(&adap->dev, "Transaction (pre): STS=%02x, TYP=%02x, "
		"CMD=%02x, ADD=%02x, DAT0=%02x, DAT1=%02x\n",
		inb_p(SMBHSTSTS), inb_p(SMBHSTTYP), inb_p(SMBHSTCMD),
		inb_p(SMBHSTADD), inb_p(SMBHSTDAT0), inb_p(SMBHSTDAT1));

	/* get status */
	temp = inb_p(SMBHSTSTS);

	/* Make sure the SMBus host is ready to start transmitting */
	/* Check the busy bit first */
	if (temp & ALI1535_STS_BUSY) {
		/* If the host controller is still busy, it may have timed out
		 * in the previous transaction, resulting in a "SMBus Timeout"
		 * printk.  I've tried the following to reset a stuck busy bit.
		 *   1. Reset the controller with an KILL command. (this
		 *      doesn't seem to clear the controller if an external
		 *      device is hung)
		 *   2. Reset the controller and the other SMBus devices with a
		 *      T_OUT command. (this clears the host busy bit if an
		 *      external device is hung, but it comes back upon a new
		 *      access to a device)
		 *   3. Disable and reenable the controller in SMBHSTCFG. Worst
		 *      case, nothing seems to work except power reset.
		 */

		/* Try resetting entire SMB bus, including other devices - This
		 * may not work either - it clears the BUSY bit but then the
		 * BUSY bit may come back on when you try and use the chip
		 * again.  If that's the case you are stuck.
		 */
		dev_info(&adap->dev,
			"Resetting entire SMB Bus to clear busy condition (%02x)\n",
			temp);
		outb_p(ALI1535_T_OUT, SMBHSTTYP);
		temp = inb_p(SMBHSTSTS);
	}

	/* now check the error bits and the busy bit */
	if (temp & (ALI1535_STS_ERR | ALI1535_STS_BUSY)) {
		/* do a clear-on-write */
		outb_p(0xFF, SMBHSTSTS);
		temp = inb_p(SMBHSTSTS);
		if (temp & (ALI1535_STS_ERR | ALI1535_STS_BUSY)) {
			/* This is probably going to be correctable only by a
			 * power reset as one of the bits now appears to be
			 * stuck */
			/* This may be a bus or device with electrical problems. */
			dev_err(&adap->dev,
				"SMBus reset failed! (0x%02x) - controller or "
				"device on bus is probably hung\n", temp);
			return -EBUSY;
		}
	} else {
		/* check and clear done bit */
		if (temp & ALI1535_STS_DONE)
			outb_p(temp, SMBHSTSTS);
	}

	/* start the transaction by writing anything to the start register */
	outb_p(0xFF, SMBHSTPORT);

	/* We will always wait for a fraction of a second! */
	timeout = 0;
	do {
		usleep_range(1000, 2000);
		temp = inb_p(SMBHSTSTS);
	} while (((temp & ALI1535_STS_BUSY) && !(temp & ALI1535_STS_IDLE))
		 && (timeout++ < MAX_TIMEOUT));

	/* If the SMBus is still busy, we give up */
	if (timeout > MAX_TIMEOUT) {
		result = -ETIMEDOUT;
		dev_err(&adap->dev, "SMBus Timeout!\n");
	}

	if (temp & ALI1535_STS_FAIL) {
		result = -EIO;
		dev_dbg(&adap->dev, "Error: Failed bus transaction\n");
	}

	/* Unfortunately the ALI SMB controller maps "no response" and "bus
	 * collision" into a single bit. No response is the usual case so don't
	 * do a printk.  This means that bus collisions go unreported.
	 */
	if (temp & ALI1535_STS_BUSERR) {
		result = -ENXIO;
		dev_dbg(&adap->dev,
			"Error: no response or bus collision ADD=%02x\n",
			inb_p(SMBHSTADD));
	}

	/* haven't ever seen this */
	if (temp & ALI1535_STS_DEV) {
		result = -EIO;
		dev_err(&adap->dev, "Error: device error\n");
	}

	/* check to see if the "command complete" indication is set */
	if (!(temp & ALI1535_STS_DONE)) {
		result = -ETIMEDOUT;
		dev_err(&adap->dev, "Error: command never completed\n");
	}

	dev_dbg(&adap->dev, "Transaction (post): STS=%02x, TYP=%02x, "
		"CMD=%02x, ADD=%02x, DAT0=%02x, DAT1=%02x\n",
		inb_p(SMBHSTSTS), inb_p(SMBHSTTYP), inb_p(SMBHSTCMD),
		inb_p(SMBHSTADD), inb_p(SMBHSTDAT0), inb_p(SMBHSTDAT1));

	/* take consequent actions for error conditions */
	if (!(temp & ALI1535_STS_DONE)) {
		/* issue "kill" to reset host controller */
		outb_p(ALI1535_KILL, SMBHSTTYP);
		outb_p(0xFF, SMBHSTSTS);
	} else if (temp & ALI1535_STS_ERR) {
		/* issue "timeout" to reset all devices on bus */
		outb_p(ALI1535_T_OUT, SMBHSTTYP);
		outb_p(0xFF, SMBHSTSTS);
	}

	return result;
}

__attribute__((used)) static s32 ali1535_access(struct i2c_adapter *adap, u16 addr,
			  unsigned short flags, char read_write, u8 command,
			  int size, union i2c_smbus_data *data)
{
	int i, len;
	int temp;
	int timeout;
	s32 result = 0;

	/* make sure SMBus is idle */
	temp = inb_p(SMBHSTSTS);
	for (timeout = 0;
	     (timeout < MAX_TIMEOUT) && !(temp & ALI1535_STS_IDLE);
	     timeout++) {
		usleep_range(1000, 2000);
		temp = inb_p(SMBHSTSTS);
	}
	if (timeout >= MAX_TIMEOUT)
		dev_warn(&adap->dev, "Idle wait Timeout! STS=0x%02x\n", temp);

	/* clear status register (clear-on-write) */
	outb_p(0xFF, SMBHSTSTS);

	switch (size) {
	case I2C_SMBUS_QUICK:
		outb_p(((addr & 0x7f) << 1) | (read_write & 0x01),
		       SMBHSTADD);
		size = ALI1535_QUICK;
		outb_p(size, SMBHSTTYP);	/* output command */
		break;
	case I2C_SMBUS_BYTE:
		outb_p(((addr & 0x7f) << 1) | (read_write & 0x01),
		       SMBHSTADD);
		size = ALI1535_BYTE;
		outb_p(size, SMBHSTTYP);	/* output command */
		if (read_write == I2C_SMBUS_WRITE)
			outb_p(command, SMBHSTCMD);
		break;
	case I2C_SMBUS_BYTE_DATA:
		outb_p(((addr & 0x7f) << 1) | (read_write & 0x01),
		       SMBHSTADD);
		size = ALI1535_BYTE_DATA;
		outb_p(size, SMBHSTTYP);	/* output command */
		outb_p(command, SMBHSTCMD);
		if (read_write == I2C_SMBUS_WRITE)
			outb_p(data->byte, SMBHSTDAT0);
		break;
	case I2C_SMBUS_WORD_DATA:
		outb_p(((addr & 0x7f) << 1) | (read_write & 0x01),
		       SMBHSTADD);
		size = ALI1535_WORD_DATA;
		outb_p(size, SMBHSTTYP);	/* output command */
		outb_p(command, SMBHSTCMD);
		if (read_write == I2C_SMBUS_WRITE) {
			outb_p(data->word & 0xff, SMBHSTDAT0);
			outb_p((data->word & 0xff00) >> 8, SMBHSTDAT1);
		}
		break;
	case I2C_SMBUS_BLOCK_DATA:
		outb_p(((addr & 0x7f) << 1) | (read_write & 0x01),
		       SMBHSTADD);
		size = ALI1535_BLOCK_DATA;
		outb_p(size, SMBHSTTYP);	/* output command */
		outb_p(command, SMBHSTCMD);
		if (read_write == I2C_SMBUS_WRITE) {
			len = data->block[0];
			if (len < 0) {
				len = 0;
				data->block[0] = len;
			}
			if (len > 32) {
				len = 32;
				data->block[0] = len;
			}
			outb_p(len, SMBHSTDAT0);
			/* Reset SMBBLKDAT */
			outb_p(inb_p(SMBHSTTYP) | ALI1535_BLOCK_CLR, SMBHSTTYP);
			for (i = 1; i <= len; i++)
				outb_p(data->block[i], SMBBLKDAT);
		}
		break;
	default:
		dev_warn(&adap->dev, "Unsupported transaction %d\n", size);
		result = -EOPNOTSUPP;
		goto EXIT;
	}

	result = ali1535_transaction(adap);
	if (result)
		goto EXIT;

	if ((read_write == I2C_SMBUS_WRITE) || (size == ALI1535_QUICK)) {
		result = 0;
		goto EXIT;
	}

	switch (size) {
	case ALI1535_BYTE:	/* Result put in SMBHSTDAT0 */
		data->byte = inb_p(SMBHSTDAT0);
		break;
	case ALI1535_BYTE_DATA:
		data->byte = inb_p(SMBHSTDAT0);
		break;
	case ALI1535_WORD_DATA:
		data->word = inb_p(SMBHSTDAT0) + (inb_p(SMBHSTDAT1) << 8);
		break;
	case ALI1535_BLOCK_DATA:
		len = inb_p(SMBHSTDAT0);
		if (len > 32)
			len = 32;
		data->block[0] = len;
		/* Reset SMBBLKDAT */
		outb_p(inb_p(SMBHSTTYP) | ALI1535_BLOCK_CLR, SMBHSTTYP);
		for (i = 1; i <= data->block[0]; i++) {
			data->block[i] = inb_p(SMBBLKDAT);
			dev_dbg(&adap->dev, "Blk: len=%d, i=%d, data=%02x\n",
				len, i, data->block[i]);
		}
		break;
	}
EXIT:
	return result;
}

__attribute__((used)) static u32 ali1535_func(struct i2c_adapter *adapter)
{
	return I2C_FUNC_SMBUS_QUICK | I2C_FUNC_SMBUS_BYTE |
	    I2C_FUNC_SMBUS_BYTE_DATA | I2C_FUNC_SMBUS_WORD_DATA |
	    I2C_FUNC_SMBUS_BLOCK_DATA;
}

__attribute__((used)) static int ali1535_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
	if (ali1535_setup(dev)) {
		dev_warn(&dev->dev,
			"ALI1535 not detected, module not inserted.\n");
		return -ENODEV;
	}

	/* set up the sysfs linkage to our parent device */
	ali1535_adapter.dev.parent = &dev->dev;

	snprintf(ali1535_adapter.name, sizeof(ali1535_adapter.name),
		"SMBus ALI1535 adapter at %04x", ali1535_offset);
	return i2c_add_adapter(&ali1535_adapter);
}

__attribute__((used)) static void ali1535_remove(struct pci_dev *dev)
{
	i2c_del_adapter(&ali1535_adapter);
	release_region(ali1535_smba, ALI1535_SMB_IOSIZE);
}

