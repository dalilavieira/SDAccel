#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
union i2c_smbus_data {int byte; int word; } ;
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct pci_device_id {int dummy; } ;
struct pci_dev {int /*<<< orphan*/  dev; } ;
struct i2c_adapter {int /*<<< orphan*/  dev; } ;
typedef  int s32 ;
struct TYPE_5__ {int /*<<< orphan*/ * parent; } ;
struct TYPE_7__ {int /*<<< orphan*/  name; TYPE_1__ dev; } ;
struct TYPE_6__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_BASE ; 
 int EBUSY ; 
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
 scalar_t__ PCIBIOS_SUCCESSFUL ; 
 int /*<<< orphan*/  PCI_VENDOR_ID_SI ; 
#define  SIS5595_BYTE 131 
#define  SIS5595_BYTE_DATA 130 
 int /*<<< orphan*/  SIS5595_ENABLE_REG ; 
 int SIS5595_EXTENT ; 
#define  SIS5595_PROC_CALL 129 
 int SIS5595_QUICK ; 
#define  SIS5595_WORD_DATA 128 
 int SMB_ADDR ; 
 int SMB_BYTE ; 
 int SMB_CMD ; 
 int SMB_CTL_LO ; 
 int SMB_DAT ; 
 int SMB_INDEX ; 
 int SMB_STS_HI ; 
 int SMB_STS_LO ; 
 int acpi_check_region (int,int,int /*<<< orphan*/ ) ; 
 int* blacklist ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*,int) ; 
 int force_addr ; 
 int i2c_add_adapter (TYPE_3__*) ; 
 int inb (int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  outb (int,int) ; 
 int /*<<< orphan*/  pci_dev_get (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_dev_put (struct pci_dev*) ; 
 struct pci_dev* pci_get_device (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 scalar_t__ pci_read_config_byte (struct pci_dev*,int /*<<< orphan*/ ,int*) ; 
 scalar_t__ pci_read_config_word (struct pci_dev*,int /*<<< orphan*/ ,int*) ; 
 scalar_t__ pci_write_config_byte (struct pci_dev*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ pci_write_config_word (struct pci_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  release_region (int,int) ; 
 int /*<<< orphan*/  request_region (int,int,int /*<<< orphan*/ ) ; 
 TYPE_3__ sis5595_adapter ; 
 int sis5595_base ; 
 TYPE_2__ sis5595_driver ; 
 int /*<<< orphan*/  sis5595_pdev ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,int) ; 

__attribute__((used)) static u8 sis5595_read(u8 reg)
{
	outb(reg, sis5595_base + SMB_INDEX);
	return inb(sis5595_base + SMB_DAT);
}

__attribute__((used)) static void sis5595_write(u8 reg, u8 data)
{
	outb(reg, sis5595_base + SMB_INDEX);
	outb(data, sis5595_base + SMB_DAT);
}

__attribute__((used)) static int sis5595_setup(struct pci_dev *SIS5595_dev)
{
	u16 a;
	u8 val;
	int *i;
	int retval;

	/* Look for imposters */
	for (i = blacklist; *i != 0; i++) {
		struct pci_dev *dev;
		dev = pci_get_device(PCI_VENDOR_ID_SI, *i, NULL);
		if (dev) {
			dev_err(&SIS5595_dev->dev, "Looked for SIS5595 but found unsupported device %.4x\n", *i);
			pci_dev_put(dev);
			return -ENODEV;
		}
	}

	/* Determine the address of the SMBus areas */
	pci_read_config_word(SIS5595_dev, ACPI_BASE, &sis5595_base);
	if (sis5595_base == 0 && force_addr == 0) {
		dev_err(&SIS5595_dev->dev, "ACPI base address uninitialized - upgrade BIOS or use force_addr=0xaddr\n");
		return -ENODEV;
	}

	if (force_addr)
		sis5595_base = force_addr & ~(SIS5595_EXTENT - 1);
	dev_dbg(&SIS5595_dev->dev, "ACPI Base address: %04x\n", sis5595_base);

	/* NB: We grab just the two SMBus registers here, but this may still
	 * interfere with ACPI :-(  */
	retval = acpi_check_region(sis5595_base + SMB_INDEX, 2,
				   sis5595_driver.name);
	if (retval)
		return retval;

	if (!request_region(sis5595_base + SMB_INDEX, 2,
			    sis5595_driver.name)) {
		dev_err(&SIS5595_dev->dev, "SMBus registers 0x%04x-0x%04x already in use!\n",
			sis5595_base + SMB_INDEX, sis5595_base + SMB_INDEX + 1);
		return -ENODEV;
	}

	if (force_addr) {
		dev_info(&SIS5595_dev->dev, "forcing ISA address 0x%04X\n", sis5595_base);
		if (pci_write_config_word(SIS5595_dev, ACPI_BASE, sis5595_base)
		    != PCIBIOS_SUCCESSFUL)
			goto error;
		if (pci_read_config_word(SIS5595_dev, ACPI_BASE, &a)
		    != PCIBIOS_SUCCESSFUL)
			goto error;
		if ((a & ~(SIS5595_EXTENT - 1)) != sis5595_base) {
			/* doesn't work for some chips! */
			dev_err(&SIS5595_dev->dev, "force address failed - not supported?\n");
			goto error;
		}
	}

	if (pci_read_config_byte(SIS5595_dev, SIS5595_ENABLE_REG, &val)
	    != PCIBIOS_SUCCESSFUL)
		goto error;
	if ((val & 0x80) == 0) {
		dev_info(&SIS5595_dev->dev, "enabling ACPI\n");
		if (pci_write_config_byte(SIS5595_dev, SIS5595_ENABLE_REG, val | 0x80)
		    != PCIBIOS_SUCCESSFUL)
			goto error;
		if (pci_read_config_byte(SIS5595_dev, SIS5595_ENABLE_REG, &val)
		    != PCIBIOS_SUCCESSFUL)
			goto error;
		if ((val & 0x80) == 0) {
			/* doesn't work for some chips? */
			dev_err(&SIS5595_dev->dev, "ACPI enable failed - not supported?\n");
			goto error;
		}
	}

	/* Everything is happy */
	return 0;

error:
	release_region(sis5595_base + SMB_INDEX, 2);
	return -ENODEV;
}

__attribute__((used)) static int sis5595_transaction(struct i2c_adapter *adap)
{
	int temp;
	int result = 0;
	int timeout = 0;

	/* Make sure the SMBus host is ready to start transmitting */
	temp = sis5595_read(SMB_STS_LO) + (sis5595_read(SMB_STS_HI) << 8);
	if (temp != 0x00) {
		dev_dbg(&adap->dev, "SMBus busy (%04x). Resetting...\n", temp);
		sis5595_write(SMB_STS_LO, temp & 0xff);
		sis5595_write(SMB_STS_HI, temp >> 8);
		if ((temp = sis5595_read(SMB_STS_LO) + (sis5595_read(SMB_STS_HI) << 8)) != 0x00) {
			dev_dbg(&adap->dev, "Failed! (%02x)\n", temp);
			return -EBUSY;
		} else {
			dev_dbg(&adap->dev, "Successful!\n");
		}
	}

	/* start the transaction by setting bit 4 */
	sis5595_write(SMB_CTL_LO, sis5595_read(SMB_CTL_LO) | 0x10);

	/* We will always wait for a fraction of a second! */
	do {
		msleep(1);
		temp = sis5595_read(SMB_STS_LO);
	} while (!(temp & 0x40) && (timeout++ < MAX_TIMEOUT));

	/* If the SMBus is still busy, we give up */
	if (timeout > MAX_TIMEOUT) {
		dev_dbg(&adap->dev, "SMBus Timeout!\n");
		result = -ETIMEDOUT;
	}

	if (temp & 0x10) {
		dev_dbg(&adap->dev, "Error: Failed bus transaction\n");
		result = -ENXIO;
	}

	if (temp & 0x20) {
		dev_err(&adap->dev, "Bus collision! SMBus may be locked until "
			"next hard reset (or not...)\n");
		/* Clock stops and slave is stuck in mid-transmission */
		result = -EIO;
	}

	temp = sis5595_read(SMB_STS_LO) + (sis5595_read(SMB_STS_HI) << 8);
	if (temp != 0x00) {
		sis5595_write(SMB_STS_LO, temp & 0xff);
		sis5595_write(SMB_STS_HI, temp >> 8);
	}

	temp = sis5595_read(SMB_STS_LO) + (sis5595_read(SMB_STS_HI) << 8);
	if (temp != 0x00)
		dev_dbg(&adap->dev, "Failed reset at end of transaction (%02x)\n", temp);

	return result;
}

__attribute__((used)) static s32 sis5595_access(struct i2c_adapter *adap, u16 addr,
			  unsigned short flags, char read_write,
			  u8 command, int size, union i2c_smbus_data *data)
{
	int status;

	switch (size) {
	case I2C_SMBUS_QUICK:
		sis5595_write(SMB_ADDR, ((addr & 0x7f) << 1) | (read_write & 0x01));
		size = SIS5595_QUICK;
		break;
	case I2C_SMBUS_BYTE:
		sis5595_write(SMB_ADDR, ((addr & 0x7f) << 1) | (read_write & 0x01));
		if (read_write == I2C_SMBUS_WRITE)
			sis5595_write(SMB_CMD, command);
		size = SIS5595_BYTE;
		break;
	case I2C_SMBUS_BYTE_DATA:
		sis5595_write(SMB_ADDR, ((addr & 0x7f) << 1) | (read_write & 0x01));
		sis5595_write(SMB_CMD, command);
		if (read_write == I2C_SMBUS_WRITE)
			sis5595_write(SMB_BYTE, data->byte);
		size = SIS5595_BYTE_DATA;
		break;
	case I2C_SMBUS_PROC_CALL:
	case I2C_SMBUS_WORD_DATA:
		sis5595_write(SMB_ADDR, ((addr & 0x7f) << 1) | (read_write & 0x01));
		sis5595_write(SMB_CMD, command);
		if (read_write == I2C_SMBUS_WRITE) {
			sis5595_write(SMB_BYTE, data->word & 0xff);
			sis5595_write(SMB_BYTE + 1,
				      (data->word & 0xff00) >> 8);
		}
		size = (size == I2C_SMBUS_PROC_CALL) ? SIS5595_PROC_CALL : SIS5595_WORD_DATA;
		break;
	default:
		dev_warn(&adap->dev, "Unsupported transaction %d\n", size);
		return -EOPNOTSUPP;
	}

	sis5595_write(SMB_CTL_LO, ((size & 0x0E)));

	status = sis5595_transaction(adap);
	if (status)
		return status;

	if ((size != SIS5595_PROC_CALL) &&
	    ((read_write == I2C_SMBUS_WRITE) || (size == SIS5595_QUICK)))
		return 0;


	switch (size) {
	case SIS5595_BYTE:
	case SIS5595_BYTE_DATA:
		data->byte = sis5595_read(SMB_BYTE);
		break;
	case SIS5595_WORD_DATA:
	case SIS5595_PROC_CALL:
		data->word = sis5595_read(SMB_BYTE) + (sis5595_read(SMB_BYTE + 1) << 8);
		break;
	}
	return 0;
}

__attribute__((used)) static u32 sis5595_func(struct i2c_adapter *adapter)
{
	return I2C_FUNC_SMBUS_QUICK | I2C_FUNC_SMBUS_BYTE |
	    I2C_FUNC_SMBUS_BYTE_DATA | I2C_FUNC_SMBUS_WORD_DATA |
	    I2C_FUNC_SMBUS_PROC_CALL;
}

__attribute__((used)) static int sis5595_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
	int err;

	if (sis5595_setup(dev)) {
		dev_err(&dev->dev, "SIS5595 not detected, module not inserted.\n");
		return -ENODEV;
	}

	/* set up the sysfs linkage to our parent device */
	sis5595_adapter.dev.parent = &dev->dev;

	snprintf(sis5595_adapter.name, sizeof(sis5595_adapter.name),
		 "SMBus SIS5595 adapter at %04x", sis5595_base + SMB_INDEX);
	err = i2c_add_adapter(&sis5595_adapter);
	if (err) {
		release_region(sis5595_base + SMB_INDEX, 2);
		return err;
	}

	/* Always return failure here.  This is to allow other drivers to bind
	 * to this pci device.  We don't really want to have control over the
	 * pci device, we only wanted to read as few register values from it.
	 */
	sis5595_pdev =  pci_dev_get(dev);
	return -ENODEV;
}

