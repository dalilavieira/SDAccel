#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
union i2c_smbus_data {int byte; int word; int* block; } ;
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct pci_device_id {scalar_t__ device; int /*<<< orphan*/  driver_data; } ;
struct TYPE_10__ {struct TYPE_10__* parent; } ;
struct pci_dev {int device; int revision; TYPE_4__ dev; } ;
struct i2c_adapter {int dummy; } ;
typedef  int s32 ;
struct TYPE_9__ {int /*<<< orphan*/  name; TYPE_4__ dev; } ;
struct TYPE_8__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int EBUSY ; 
 int EIO ; 
 int ENODEV ; 
 int ENXIO ; 
 int EOPNOTSUPP ; 
 int ETIMEDOUT ; 
 int FEATURE_I2CBLOCK ; 
 int const I2C_FUNC_SMBUS_BLOCK_DATA ; 
 int const I2C_FUNC_SMBUS_BYTE ; 
 int const I2C_FUNC_SMBUS_BYTE_DATA ; 
 int I2C_FUNC_SMBUS_I2C_BLOCK ; 
 int const I2C_FUNC_SMBUS_QUICK ; 
 int const I2C_FUNC_SMBUS_WORD_DATA ; 
#define  I2C_SMBUS_BLOCK_DATA 152 
 int I2C_SMBUS_BLOCK_MAX ; 
#define  I2C_SMBUS_BYTE 151 
#define  I2C_SMBUS_BYTE_DATA 150 
#define  I2C_SMBUS_I2C_BLOCK_DATA 149 
#define  I2C_SMBUS_PROC_CALL 148 
#define  I2C_SMBUS_QUICK 147 
 char I2C_SMBUS_READ ; 
#define  I2C_SMBUS_WORD_DATA 146 
 char I2C_SMBUS_WRITE ; 
 int MAX_TIMEOUT ; 
#define  PCI_DEVICE_ID_VIA_8233A 145 
#define  PCI_DEVICE_ID_VIA_8233_0 144 
#define  PCI_DEVICE_ID_VIA_8235 143 
#define  PCI_DEVICE_ID_VIA_8237 142 
#define  PCI_DEVICE_ID_VIA_8237A 141 
#define  PCI_DEVICE_ID_VIA_8237S 140 
#define  PCI_DEVICE_ID_VIA_8251 139 
 scalar_t__ PCI_DEVICE_ID_VIA_82C596_3 ; 
#define  PCI_DEVICE_ID_VIA_82C686_4 138 
#define  PCI_DEVICE_ID_VIA_CX700 137 
#define  PCI_DEVICE_ID_VIA_VX800 136 
#define  PCI_DEVICE_ID_VIA_VX855 135 
#define  PCI_DEVICE_ID_VIA_VX900 134 
 int /*<<< orphan*/  SMBBA2 ; 
 int /*<<< orphan*/  SMBBLKDAT ; 
 int /*<<< orphan*/  SMBHSTADD ; 
 int SMBHSTCFG ; 
 int /*<<< orphan*/  SMBHSTCMD ; 
 int /*<<< orphan*/  SMBHSTCNT ; 
 int /*<<< orphan*/  SMBHSTDAT0 ; 
 int /*<<< orphan*/  SMBHSTDAT1 ; 
 int /*<<< orphan*/  SMBHSTSTS ; 
#define  VT596_BLOCK_DATA 133 
#define  VT596_BYTE 132 
#define  VT596_BYTE_DATA 131 
#define  VT596_I2C_BLOCK_DATA 130 
#define  VT596_PROC_CALL 129 
 int VT596_QUICK ; 
#define  VT596_WORD_DATA 128 
 int acpi_check_region (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (TYPE_4__*,char*,...) ; 
 int /*<<< orphan*/  dev_err (TYPE_4__*,char*,...) ; 
 int /*<<< orphan*/  dev_info (TYPE_4__*,char*) ; 
 int /*<<< orphan*/  dev_warn (TYPE_4__*,char*,int) ; 
 scalar_t__ force ; 
 int force_addr ; 
 int i2c_add_adapter (TYPE_2__*) ; 
 int inb_p (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  outb_p (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * pci_dev_get (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_dev_put (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pci_read_config_byte (struct pci_dev*,int,unsigned char*) ; 
 scalar_t__ pci_read_config_word (struct pci_dev*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  pci_write_config_byte (struct pci_dev*,int,unsigned char) ; 
 int /*<<< orphan*/  pci_write_config_word (struct pci_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  release_region (int,int) ; 
 int /*<<< orphan*/  request_region (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,int) ; 
 TYPE_2__ vt596_adapter ; 
 TYPE_1__ vt596_driver ; 
 int vt596_features ; 
 int /*<<< orphan*/ * vt596_pdev ; 
 int vt596_smba ; 

__attribute__((used)) static inline void vt596_dump_regs(const char *msg, u8 size) { }

__attribute__((used)) static int vt596_transaction(u8 size)
{
	int temp;
	int result = 0;
	int timeout = 0;

	vt596_dump_regs("Transaction (pre)", size);

	/* Make sure the SMBus host is ready to start transmitting */
	if ((temp = inb_p(SMBHSTSTS)) & 0x1F) {
		dev_dbg(&vt596_adapter.dev, "SMBus busy (0x%02x). "
			"Resetting...\n", temp);

		outb_p(temp, SMBHSTSTS);
		if ((temp = inb_p(SMBHSTSTS)) & 0x1F) {
			dev_err(&vt596_adapter.dev, "SMBus reset failed! "
				"(0x%02x)\n", temp);
			return -EBUSY;
		}
	}

	/* Start the transaction by setting bit 6 */
	outb_p(0x40 | size, SMBHSTCNT);

	/* We will always wait for a fraction of a second */
	do {
		msleep(1);
		temp = inb_p(SMBHSTSTS);
	} while ((temp & 0x01) && (++timeout < MAX_TIMEOUT));

	/* If the SMBus is still busy, we give up */
	if (timeout == MAX_TIMEOUT) {
		result = -ETIMEDOUT;
		dev_err(&vt596_adapter.dev, "SMBus timeout!\n");
	}

	if (temp & 0x10) {
		result = -EIO;
		dev_err(&vt596_adapter.dev, "Transaction failed (0x%02x)\n",
			size);
	}

	if (temp & 0x08) {
		result = -EIO;
		dev_err(&vt596_adapter.dev, "SMBus collision!\n");
	}

	if (temp & 0x04) {
		result = -ENXIO;
		dev_dbg(&vt596_adapter.dev, "No response\n");
	}

	/* Resetting status register */
	if (temp & 0x1F)
		outb_p(temp, SMBHSTSTS);

	vt596_dump_regs("Transaction (post)", size);

	return result;
}

__attribute__((used)) static s32 vt596_access(struct i2c_adapter *adap, u16 addr,
		unsigned short flags, char read_write, u8 command,
		int size, union i2c_smbus_data *data)
{
	int i;
	int status;

	switch (size) {
	case I2C_SMBUS_QUICK:
		size = VT596_QUICK;
		break;
	case I2C_SMBUS_BYTE:
		if (read_write == I2C_SMBUS_WRITE)
			outb_p(command, SMBHSTCMD);
		size = VT596_BYTE;
		break;
	case I2C_SMBUS_BYTE_DATA:
		outb_p(command, SMBHSTCMD);
		if (read_write == I2C_SMBUS_WRITE)
			outb_p(data->byte, SMBHSTDAT0);
		size = VT596_BYTE_DATA;
		break;
	case I2C_SMBUS_WORD_DATA:
		outb_p(command, SMBHSTCMD);
		if (read_write == I2C_SMBUS_WRITE) {
			outb_p(data->word & 0xff, SMBHSTDAT0);
			outb_p((data->word & 0xff00) >> 8, SMBHSTDAT1);
		}
		size = VT596_WORD_DATA;
		break;
	case I2C_SMBUS_PROC_CALL:
		outb_p(command, SMBHSTCMD);
		outb_p(data->word & 0xff, SMBHSTDAT0);
		outb_p((data->word & 0xff00) >> 8, SMBHSTDAT1);
		size = VT596_PROC_CALL;
		break;
	case I2C_SMBUS_I2C_BLOCK_DATA:
		if (!(vt596_features & FEATURE_I2CBLOCK))
			goto exit_unsupported;
		if (read_write == I2C_SMBUS_READ)
			outb_p(data->block[0], SMBHSTDAT0);
		/* Fall through */
	case I2C_SMBUS_BLOCK_DATA:
		outb_p(command, SMBHSTCMD);
		if (read_write == I2C_SMBUS_WRITE) {
			u8 len = data->block[0];
			if (len > I2C_SMBUS_BLOCK_MAX)
				len = I2C_SMBUS_BLOCK_MAX;
			outb_p(len, SMBHSTDAT0);
			inb_p(SMBHSTCNT);	/* Reset SMBBLKDAT */
			for (i = 1; i <= len; i++)
				outb_p(data->block[i], SMBBLKDAT);
		}
		size = (size == I2C_SMBUS_I2C_BLOCK_DATA) ?
		       VT596_I2C_BLOCK_DATA : VT596_BLOCK_DATA;
		break;
	default:
		goto exit_unsupported;
	}

	outb_p(((addr & 0x7f) << 1) | read_write, SMBHSTADD);

	status = vt596_transaction(size);
	if (status)
		return status;

	if (size == VT596_PROC_CALL)
		read_write = I2C_SMBUS_READ;

	if ((read_write == I2C_SMBUS_WRITE) || (size == VT596_QUICK))
		return 0;

	switch (size) {
	case VT596_BYTE:
	case VT596_BYTE_DATA:
		data->byte = inb_p(SMBHSTDAT0);
		break;
	case VT596_WORD_DATA:
	case VT596_PROC_CALL:
		data->word = inb_p(SMBHSTDAT0) + (inb_p(SMBHSTDAT1) << 8);
		break;
	case VT596_I2C_BLOCK_DATA:
	case VT596_BLOCK_DATA:
		data->block[0] = inb_p(SMBHSTDAT0);
		if (data->block[0] > I2C_SMBUS_BLOCK_MAX)
			data->block[0] = I2C_SMBUS_BLOCK_MAX;
		inb_p(SMBHSTCNT);	/* Reset SMBBLKDAT */
		for (i = 1; i <= data->block[0]; i++)
			data->block[i] = inb_p(SMBBLKDAT);
		break;
	}
	return 0;

exit_unsupported:
	dev_warn(&vt596_adapter.dev, "Unsupported transaction %d\n",
		 size);
	return -EOPNOTSUPP;
}

__attribute__((used)) static u32 vt596_func(struct i2c_adapter *adapter)
{
	u32 func = I2C_FUNC_SMBUS_QUICK | I2C_FUNC_SMBUS_BYTE |
	    I2C_FUNC_SMBUS_BYTE_DATA | I2C_FUNC_SMBUS_WORD_DATA |
	    I2C_SMBUS_PROC_CALL | I2C_FUNC_SMBUS_BLOCK_DATA;

	if (vt596_features & FEATURE_I2CBLOCK)
		func |= I2C_FUNC_SMBUS_I2C_BLOCK;
	return func;
}

__attribute__((used)) static int vt596_probe(struct pci_dev *pdev,
		       const struct pci_device_id *id)
{
	unsigned char temp;
	int error;

	/* Determine the address of the SMBus areas */
	if (force_addr) {
		vt596_smba = force_addr & 0xfff0;
		force = 0;
		goto found;
	}

	if ((pci_read_config_word(pdev, id->driver_data, &vt596_smba)) ||
	    !(vt596_smba & 0x0001)) {
		/* try 2nd address and config reg. for 596 */
		if (id->device == PCI_DEVICE_ID_VIA_82C596_3 &&
		    !pci_read_config_word(pdev, SMBBA2, &vt596_smba) &&
		    (vt596_smba & 0x0001)) {
			SMBHSTCFG = 0x84;
		} else {
			/* no matches at all */
			dev_err(&pdev->dev, "Cannot configure "
				"SMBus I/O Base address\n");
			return -ENODEV;
		}
	}

	vt596_smba &= 0xfff0;
	if (vt596_smba == 0) {
		dev_err(&pdev->dev, "SMBus base address "
			"uninitialized - upgrade BIOS or use "
			"force_addr=0xaddr\n");
		return -ENODEV;
	}

found:
	error = acpi_check_region(vt596_smba, 8, vt596_driver.name);
	if (error)
		return -ENODEV;

	if (!request_region(vt596_smba, 8, vt596_driver.name)) {
		dev_err(&pdev->dev, "SMBus region 0x%x already in use!\n",
			vt596_smba);
		return -ENODEV;
	}

	pci_read_config_byte(pdev, SMBHSTCFG, &temp);
	/* If force_addr is set, we program the new address here. Just to make
	   sure, we disable the VT596 first. */
	if (force_addr) {
		pci_write_config_byte(pdev, SMBHSTCFG, temp & 0xfe);
		pci_write_config_word(pdev, id->driver_data, vt596_smba);
		pci_write_config_byte(pdev, SMBHSTCFG, temp | 0x01);
		dev_warn(&pdev->dev, "WARNING: SMBus interface set to new "
			 "address 0x%04x!\n", vt596_smba);
	} else if (!(temp & 0x01)) {
		if (force) {
			/* NOTE: This assumes I/O space and other allocations
			 * WERE done by the Bios!  Don't complain if your
			 * hardware does weird things after enabling this.
			 * :') Check for Bios updates before resorting to
			 * this.
			 */
			pci_write_config_byte(pdev, SMBHSTCFG, temp | 0x01);
			dev_info(&pdev->dev, "Enabling SMBus device\n");
		} else {
			dev_err(&pdev->dev, "SMBUS: Error: Host SMBus "
				"controller not enabled! - upgrade BIOS or "
				"use force=1\n");
			error = -ENODEV;
			goto release_region;
		}
	}

	dev_dbg(&pdev->dev, "VT596_smba = 0x%X\n", vt596_smba);

	switch (pdev->device) {
	case PCI_DEVICE_ID_VIA_CX700:
	case PCI_DEVICE_ID_VIA_VX800:
	case PCI_DEVICE_ID_VIA_VX855:
	case PCI_DEVICE_ID_VIA_VX900:
	case PCI_DEVICE_ID_VIA_8251:
	case PCI_DEVICE_ID_VIA_8237:
	case PCI_DEVICE_ID_VIA_8237A:
	case PCI_DEVICE_ID_VIA_8237S:
	case PCI_DEVICE_ID_VIA_8235:
	case PCI_DEVICE_ID_VIA_8233A:
	case PCI_DEVICE_ID_VIA_8233_0:
		vt596_features |= FEATURE_I2CBLOCK;
		break;
	case PCI_DEVICE_ID_VIA_82C686_4:
		/* The VT82C686B (rev 0x40) does support I2C block
		   transactions, but the VT82C686A (rev 0x30) doesn't */
		if (pdev->revision >= 0x40)
			vt596_features |= FEATURE_I2CBLOCK;
		break;
	}

	vt596_adapter.dev.parent = &pdev->dev;
	snprintf(vt596_adapter.name, sizeof(vt596_adapter.name),
		 "SMBus Via Pro adapter at %04x", vt596_smba);

	vt596_pdev = pci_dev_get(pdev);
	error = i2c_add_adapter(&vt596_adapter);
	if (error) {
		pci_dev_put(vt596_pdev);
		vt596_pdev = NULL;
		goto release_region;
	}

	/* Always return failure here.  This is to allow other drivers to bind
	 * to this pci device.  We don't really want to have control over the
	 * pci device, we only wanted to read as few register values from it.
	 */
	return -ENODEV;

release_region:
	release_region(vt596_smba, 8);
	return error;
}

