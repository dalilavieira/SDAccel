#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
union i2c_smbus_data {int* block; int byte; int word; } ;
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct pci_device_id {int dummy; } ;
struct pci_dev {int /*<<< orphan*/  dev; } ;
struct i2c_adapter {int /*<<< orphan*/  dev; } ;
typedef  int s32 ;
struct TYPE_6__ {int /*<<< orphan*/ * parent; } ;
struct TYPE_8__ {int /*<<< orphan*/  name; TYPE_1__ dev; } ;
struct TYPE_7__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int BYTE_DONE_STS ; 
 int EAGAIN ; 
 int EBUSY ; 
 int ENODEV ; 
 int ENXIO ; 
 int EOPNOTSUPP ; 
 int ETIMEDOUT ; 
 int I2C_FUNC_SMBUS_BLOCK_DATA ; 
 int I2C_FUNC_SMBUS_BYTE ; 
 int I2C_FUNC_SMBUS_BYTE_DATA ; 
 int I2C_FUNC_SMBUS_PROC_CALL ; 
 int I2C_FUNC_SMBUS_QUICK ; 
 int I2C_FUNC_SMBUS_WORD_DATA ; 
#define  I2C_SMBUS_BLOCK_DATA 137 
#define  I2C_SMBUS_BYTE 136 
#define  I2C_SMBUS_BYTE_DATA 135 
#define  I2C_SMBUS_PROC_CALL 134 
#define  I2C_SMBUS_QUICK 133 
#define  I2C_SMBUS_WORD_DATA 132 
 int I2C_SMBUS_WRITE ; 
 int MAX_TIMEOUT ; 
 int MSTO_EN ; 
 scalar_t__ PCI_DEVICE_ID_SI_760 ; 
 int /*<<< orphan*/  PCI_VENDOR_ID_SI ; 
 int /*<<< orphan*/  SIS630_ACPI_BASE_REG ; 
 int /*<<< orphan*/  SIS630_BIOS_CTL_REG ; 
 int SIS630_BLOCK_DATA ; 
#define  SIS630_BYTE 131 
#define  SIS630_BYTE_DATA 130 
#define  SIS630_PCALL 129 
 int SIS630_QUICK ; 
 int SIS630_SMB_IOREGION ; 
#define  SIS630_WORD_DATA 128 
 int SMBCLK_SEL ; 
 int SMBCOL_STS ; 
 int SMBERR_STS ; 
 int SMBHOST_CNT ; 
 int SMB_ADDR ; 
 int SMB_BYTE ; 
 int SMB_CMD ; 
 int SMB_CNT ; 
 int SMB_COUNT ; 
 int SMB_HOSTBUSY ; 
 int SMB_KILL ; 
 int SMB_PROBE ; 
 int SMB_START ; 
 int SMB_STS ; 
 int acpi_check_region (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*,int) ; 
 scalar_t__ force ; 
 scalar_t__ high_clock ; 
 int i2c_add_adapter (TYPE_3__*) ; 
 int /*<<< orphan*/  i2c_del_adapter (TYPE_3__*) ; 
 int inb (int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  outb (int,int) ; 
 int /*<<< orphan*/  pci_dev_put (struct pci_dev*) ; 
 struct pci_dev* pci_get_device (int /*<<< orphan*/ ,scalar_t__,struct pci_dev*) ; 
 scalar_t__ pci_read_config_byte (struct pci_dev*,int /*<<< orphan*/ ,unsigned char*) ; 
 scalar_t__ pci_read_config_word (struct pci_dev*,int /*<<< orphan*/ ,unsigned short*) ; 
 scalar_t__ pci_write_config_byte (struct pci_dev*,int /*<<< orphan*/ ,unsigned char) ; 
 int /*<<< orphan*/  release_region (int,int) ; 
 int /*<<< orphan*/  request_region (int,int,int /*<<< orphan*/ ) ; 
 TYPE_3__ sis630_adapter ; 
 TYPE_2__ sis630_driver ; 
 int smbus_base ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,int) ; 
 scalar_t__* supported ; 

__attribute__((used)) static inline u8 sis630_read(u8 reg)
{
	return inb(smbus_base + reg);
}

__attribute__((used)) static inline void sis630_write(u8 reg, u8 data)
{
	outb(data, smbus_base + reg);
}

__attribute__((used)) static int sis630_transaction_start(struct i2c_adapter *adap, int size,
				    u8 *oldclock)
{
	int temp;

	/* Make sure the SMBus host is ready to start transmitting. */
	temp = sis630_read(SMB_CNT);
	if ((temp & (SMB_PROBE | SMB_HOSTBUSY)) != 0x00) {
		dev_dbg(&adap->dev, "SMBus busy (%02x). Resetting...\n", temp);
		/* kill smbus transaction */
		sis630_write(SMBHOST_CNT, SMB_KILL);

		temp = sis630_read(SMB_CNT);
		if (temp & (SMB_PROBE | SMB_HOSTBUSY)) {
			dev_dbg(&adap->dev, "Failed! (%02x)\n", temp);
			return -EBUSY;
		} else {
			dev_dbg(&adap->dev, "Successful!\n");
		}
	}

	/* save old clock, so we can prevent machine for hung */
	*oldclock = sis630_read(SMB_CNT);

	dev_dbg(&adap->dev, "saved clock 0x%02x\n", *oldclock);

	/* disable timeout interrupt,
	 * set Host Master Clock to 56KHz if requested */
	if (high_clock)
		sis630_write(SMB_CNT, SMBCLK_SEL);
	else
		sis630_write(SMB_CNT, (*oldclock & ~MSTO_EN));

	/* clear all sticky bits */
	temp = sis630_read(SMB_STS);
	sis630_write(SMB_STS, temp & 0x1e);

	/* start the transaction by setting bit 4 and size */
	sis630_write(SMBHOST_CNT, SMB_START | (size & 0x07));

	return 0;
}

__attribute__((used)) static int sis630_transaction_wait(struct i2c_adapter *adap, int size)
{
	int temp, result = 0, timeout = 0;

	/* We will always wait for a fraction of a second! */
	do {
		msleep(1);
		temp = sis630_read(SMB_STS);
		/* check if block transmitted */
		if (size == SIS630_BLOCK_DATA && (temp & BYTE_DONE_STS))
			break;
	} while (!(temp & 0x0e) && (timeout++ < MAX_TIMEOUT));

	/* If the SMBus is still busy, we give up */
	if (timeout > MAX_TIMEOUT) {
		dev_dbg(&adap->dev, "SMBus Timeout!\n");
		result = -ETIMEDOUT;
	}

	if (temp & SMBERR_STS) {
		dev_dbg(&adap->dev, "Error: Failed bus transaction\n");
		result = -ENXIO;
	}

	if (temp & SMBCOL_STS) {
		dev_err(&adap->dev, "Bus collision!\n");
		result = -EAGAIN;
	}

	return result;
}

__attribute__((used)) static void sis630_transaction_end(struct i2c_adapter *adap, u8 oldclock)
{
	/* clear all status "sticky" bits */
	sis630_write(SMB_STS, 0xFF);

	dev_dbg(&adap->dev,
		"SMB_CNT before clock restore 0x%02x\n", sis630_read(SMB_CNT));

	/*
	 * restore old Host Master Clock if high_clock is set
	 * and oldclock was not 56KHz
	 */
	if (high_clock && !(oldclock & SMBCLK_SEL))
		sis630_write(SMB_CNT, sis630_read(SMB_CNT) & ~SMBCLK_SEL);

	dev_dbg(&adap->dev,
		"SMB_CNT after clock restore 0x%02x\n", sis630_read(SMB_CNT));
}

__attribute__((used)) static int sis630_transaction(struct i2c_adapter *adap, int size)
{
	int result = 0;
	u8 oldclock = 0;

	result = sis630_transaction_start(adap, size, &oldclock);
	if (!result) {
		result = sis630_transaction_wait(adap, size);
		sis630_transaction_end(adap, oldclock);
	}

	return result;
}

__attribute__((used)) static int sis630_block_data(struct i2c_adapter *adap,
			     union i2c_smbus_data *data, int read_write)
{
	int i, len = 0, rc = 0;
	u8 oldclock = 0;

	if (read_write == I2C_SMBUS_WRITE) {
		len = data->block[0];
		if (len < 0)
			len = 0;
		else if (len > 32)
			len = 32;
		sis630_write(SMB_COUNT, len);
		for (i = 1; i <= len; i++) {
			dev_dbg(&adap->dev,
				"set data 0x%02x\n", data->block[i]);
			/* set data */
			sis630_write(SMB_BYTE + (i - 1) % 8, data->block[i]);
			if (i == 8 || (len < 8 && i == len)) {
				dev_dbg(&adap->dev,
					"start trans len=%d i=%d\n", len, i);
				/* first transaction */
				rc = sis630_transaction_start(adap,
						SIS630_BLOCK_DATA, &oldclock);
				if (rc)
					return rc;
			} else if ((i - 1) % 8 == 7 || i == len) {
				dev_dbg(&adap->dev,
					"trans_wait len=%d i=%d\n", len, i);
				if (i > 8) {
					dev_dbg(&adap->dev,
						"clear smbary_sts"
						" len=%d i=%d\n", len, i);
					/*
					   If this is not first transaction,
					   we must clear sticky bit.
					   clear SMBARY_STS
					*/
					sis630_write(SMB_STS, BYTE_DONE_STS);
				}
				rc = sis630_transaction_wait(adap,
						SIS630_BLOCK_DATA);
				if (rc) {
					dev_dbg(&adap->dev,
						"trans_wait failed\n");
					break;
				}
			}
		}
	} else {
		/* read request */
		data->block[0] = len = 0;
		rc = sis630_transaction_start(adap,
				SIS630_BLOCK_DATA, &oldclock);
		if (rc)
			return rc;
		do {
			rc = sis630_transaction_wait(adap, SIS630_BLOCK_DATA);
			if (rc) {
				dev_dbg(&adap->dev, "trans_wait failed\n");
				break;
			}
			/* if this first transaction then read byte count */
			if (len == 0)
				data->block[0] = sis630_read(SMB_COUNT);

			/* just to be sure */
			if (data->block[0] > 32)
				data->block[0] = 32;

			dev_dbg(&adap->dev,
				"block data read len=0x%x\n", data->block[0]);

			for (i = 0; i < 8 && len < data->block[0]; i++, len++) {
				dev_dbg(&adap->dev,
					"read i=%d len=%d\n", i, len);
				data->block[len + 1] = sis630_read(SMB_BYTE +
								   i);
			}

			dev_dbg(&adap->dev,
				"clear smbary_sts len=%d i=%d\n", len, i);

			/* clear SMBARY_STS */
			sis630_write(SMB_STS, BYTE_DONE_STS);
		} while (len < data->block[0]);
	}

	sis630_transaction_end(adap, oldclock);

	return rc;
}

__attribute__((used)) static s32 sis630_access(struct i2c_adapter *adap, u16 addr,
			 unsigned short flags, char read_write,
			 u8 command, int size, union i2c_smbus_data *data)
{
	int status;

	switch (size) {
	case I2C_SMBUS_QUICK:
		sis630_write(SMB_ADDR,
			     ((addr & 0x7f) << 1) | (read_write & 0x01));
		size = SIS630_QUICK;
		break;
	case I2C_SMBUS_BYTE:
		sis630_write(SMB_ADDR,
			     ((addr & 0x7f) << 1) | (read_write & 0x01));
		if (read_write == I2C_SMBUS_WRITE)
			sis630_write(SMB_CMD, command);
		size = SIS630_BYTE;
		break;
	case I2C_SMBUS_BYTE_DATA:
		sis630_write(SMB_ADDR,
			     ((addr & 0x7f) << 1) | (read_write & 0x01));
		sis630_write(SMB_CMD, command);
		if (read_write == I2C_SMBUS_WRITE)
			sis630_write(SMB_BYTE, data->byte);
		size = SIS630_BYTE_DATA;
		break;
	case I2C_SMBUS_PROC_CALL:
	case I2C_SMBUS_WORD_DATA:
		sis630_write(SMB_ADDR,
			     ((addr & 0x7f) << 1) | (read_write & 0x01));
		sis630_write(SMB_CMD, command);
		if (read_write == I2C_SMBUS_WRITE) {
			sis630_write(SMB_BYTE, data->word & 0xff);
			sis630_write(SMB_BYTE + 1, (data->word & 0xff00) >> 8);
		}
		size = (size == I2C_SMBUS_PROC_CALL ?
			SIS630_PCALL : SIS630_WORD_DATA);
		break;
	case I2C_SMBUS_BLOCK_DATA:
		sis630_write(SMB_ADDR,
			     ((addr & 0x7f) << 1) | (read_write & 0x01));
		sis630_write(SMB_CMD, command);
		size = SIS630_BLOCK_DATA;
		return sis630_block_data(adap, data, read_write);
	default:
		dev_warn(&adap->dev, "Unsupported transaction %d\n", size);
		return -EOPNOTSUPP;
	}

	status = sis630_transaction(adap, size);
	if (status)
		return status;

	if ((size != SIS630_PCALL) &&
		((read_write == I2C_SMBUS_WRITE) || (size == SIS630_QUICK))) {
		return 0;
	}

	switch (size) {
	case SIS630_BYTE:
	case SIS630_BYTE_DATA:
		data->byte = sis630_read(SMB_BYTE);
		break;
	case SIS630_PCALL:
	case SIS630_WORD_DATA:
		data->word = sis630_read(SMB_BYTE) +
			     (sis630_read(SMB_BYTE + 1) << 8);
		break;
	}

	return 0;
}

__attribute__((used)) static u32 sis630_func(struct i2c_adapter *adapter)
{
	return I2C_FUNC_SMBUS_QUICK | I2C_FUNC_SMBUS_BYTE |
		I2C_FUNC_SMBUS_BYTE_DATA | I2C_FUNC_SMBUS_WORD_DATA |
		I2C_FUNC_SMBUS_PROC_CALL | I2C_FUNC_SMBUS_BLOCK_DATA;
}

__attribute__((used)) static int sis630_setup(struct pci_dev *sis630_dev)
{
	unsigned char b;
	struct pci_dev *dummy = NULL;
	int retval, i;
	/* acpi base address */
	unsigned short acpi_base;

	/* check for supported SiS devices */
	for (i = 0; supported[i] > 0; i++) {
		dummy = pci_get_device(PCI_VENDOR_ID_SI, supported[i], dummy);
		if (dummy)
			break; /* found */
	}

	if (dummy) {
		pci_dev_put(dummy);
	} else if (force) {
		dev_err(&sis630_dev->dev,
			"WARNING: Can't detect SIS630 compatible device, but "
			"loading because of force option enabled\n");
	} else {
		return -ENODEV;
	}

	/*
	   Enable ACPI first , so we can accsess reg 74-75
	   in acpi io space and read acpi base addr
	*/
	if (pci_read_config_byte(sis630_dev, SIS630_BIOS_CTL_REG, &b)) {
		dev_err(&sis630_dev->dev, "Error: Can't read bios ctl reg\n");
		retval = -ENODEV;
		goto exit;
	}
	/* if ACPI already enabled , do nothing */
	if (!(b & 0x80) &&
	    pci_write_config_byte(sis630_dev, SIS630_BIOS_CTL_REG, b | 0x80)) {
		dev_err(&sis630_dev->dev, "Error: Can't enable ACPI\n");
		retval = -ENODEV;
		goto exit;
	}

	/* Determine the ACPI base address */
	if (pci_read_config_word(sis630_dev,
				 SIS630_ACPI_BASE_REG, &acpi_base)) {
		dev_err(&sis630_dev->dev,
			"Error: Can't determine ACPI base address\n");
		retval = -ENODEV;
		goto exit;
	}

	dev_dbg(&sis630_dev->dev, "ACPI base at 0x%04hx\n", acpi_base);

	if (supported[i] == PCI_DEVICE_ID_SI_760)
		smbus_base = acpi_base + 0xE0;
	else
		smbus_base = acpi_base + 0x80;

	dev_dbg(&sis630_dev->dev, "SMBus base at 0x%04hx\n", smbus_base);

	retval = acpi_check_region(smbus_base + SMB_STS, SIS630_SMB_IOREGION,
				   sis630_driver.name);
	if (retval)
		goto exit;

	/* Everything is happy, let's grab the memory and set things up. */
	if (!request_region(smbus_base + SMB_STS, SIS630_SMB_IOREGION,
			    sis630_driver.name)) {
		dev_err(&sis630_dev->dev,
			"I/O Region 0x%04hx-0x%04hx for SMBus already in use.\n",
			smbus_base + SMB_STS,
			smbus_base + SMB_STS + SIS630_SMB_IOREGION - 1);
		retval = -EBUSY;
		goto exit;
	}

	retval = 0;

exit:
	if (retval)
		smbus_base = 0;
	return retval;
}

__attribute__((used)) static int sis630_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
	if (sis630_setup(dev)) {
		dev_err(&dev->dev,
			"SIS630 compatible bus not detected, "
			"module not inserted.\n");
		return -ENODEV;
	}

	/* set up the sysfs linkage to our parent device */
	sis630_adapter.dev.parent = &dev->dev;

	snprintf(sis630_adapter.name, sizeof(sis630_adapter.name),
		 "SMBus SIS630 adapter at %04hx", smbus_base + SMB_STS);

	return i2c_add_adapter(&sis630_adapter);
}

__attribute__((used)) static void sis630_remove(struct pci_dev *dev)
{
	if (smbus_base) {
		i2c_del_adapter(&sis630_adapter);
		release_region(smbus_base + SMB_STS, SIS630_SMB_IOREGION);
		smbus_base = 0;
	}
}

