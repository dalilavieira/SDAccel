#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
union i2c_smbus_data {unsigned char byte; unsigned char word; int* block; } ;
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct pci_device_id {int dummy; } ;
struct TYPE_6__ {struct TYPE_6__* parent; } ;
struct pci_dev {int device; TYPE_2__ dev; } ;
struct i2c_adapter {int class; TYPE_2__ dev; int /*<<< orphan*/  name; struct nforce2_smbus* algo_data; int /*<<< orphan*/ * algo; int /*<<< orphan*/  owner; } ;
struct nforce2_smbus {int can_abort; int blockops; int base; int size; struct i2c_adapter adapter; } ;
typedef  int s32 ;
struct TYPE_5__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int EBUSY ; 
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int EPERM ; 
 int EPROTO ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int I2C_CLASS_HWMON ; 
 int I2C_CLASS_SPD ; 
 unsigned short I2C_CLIENT_PEC ; 
 int I2C_FUNC_SMBUS_BLOCK_DATA ; 
 int I2C_FUNC_SMBUS_BYTE ; 
 int I2C_FUNC_SMBUS_BYTE_DATA ; 
 int I2C_FUNC_SMBUS_PEC ; 
 int I2C_FUNC_SMBUS_QUICK ; 
 int I2C_FUNC_SMBUS_WORD_DATA ; 
#define  I2C_SMBUS_BLOCK_DATA 135 
 int I2C_SMBUS_BLOCK_MAX ; 
#define  I2C_SMBUS_BYTE 134 
#define  I2C_SMBUS_BYTE_DATA 133 
#define  I2C_SMBUS_QUICK 132 
 char I2C_SMBUS_READ ; 
#define  I2C_SMBUS_WORD_DATA 131 
 char I2C_SMBUS_WRITE ; 
 int MAX_TIMEOUT ; 
 int NFORCE_PCI_SMB1 ; 
 int NFORCE_PCI_SMB2 ; 
 int /*<<< orphan*/  NVIDIA_SMB_ADDR ; 
 int /*<<< orphan*/  NVIDIA_SMB_BCNT ; 
 int /*<<< orphan*/  NVIDIA_SMB_CMD ; 
 int /*<<< orphan*/  NVIDIA_SMB_CTRL ; 
 unsigned char NVIDIA_SMB_CTRL_ABORT ; 
 int /*<<< orphan*/  NVIDIA_SMB_DATA ; 
 int /*<<< orphan*/  NVIDIA_SMB_PRTCL ; 
 unsigned char NVIDIA_SMB_PRTCL_BLOCK_DATA ; 
 unsigned char NVIDIA_SMB_PRTCL_BYTE ; 
 unsigned char NVIDIA_SMB_PRTCL_BYTE_DATA ; 
 unsigned char NVIDIA_SMB_PRTCL_PEC ; 
 unsigned char NVIDIA_SMB_PRTCL_QUICK ; 
 unsigned char NVIDIA_SMB_PRTCL_READ ; 
 unsigned char NVIDIA_SMB_PRTCL_WORD_DATA ; 
 unsigned char NVIDIA_SMB_PRTCL_WRITE ; 
 int /*<<< orphan*/  NVIDIA_SMB_STATUS_ABRT ; 
 unsigned char NVIDIA_SMB_STATUS_ABRT_STS ; 
 int /*<<< orphan*/  NVIDIA_SMB_STS ; 
 unsigned char NVIDIA_SMB_STS_DONE ; 
 unsigned char NVIDIA_SMB_STS_STATUS ; 
 scalar_t__ PCIBIOS_SUCCESSFUL ; 
 int PCI_BASE_ADDRESS_IO_MASK ; 
#define  PCI_DEVICE_ID_NVIDIA_NFORCE2_SMBUS 130 
#define  PCI_DEVICE_ID_NVIDIA_NFORCE_MCP51_SMBUS 129 
#define  PCI_DEVICE_ID_NVIDIA_NFORCE_MCP55_SMBUS 128 
 int /*<<< orphan*/  THIS_MODULE ; 
 int acpi_check_region (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (TYPE_2__*,char*,...) ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,...) ; 
 int /*<<< orphan*/  dev_info (TYPE_2__*,char*,int) ; 
 scalar_t__ dmi_check_system (int /*<<< orphan*/ ) ; 
 int i2c_add_adapter (struct i2c_adapter*) ; 
 int /*<<< orphan*/  i2c_del_adapter (struct i2c_adapter*) ; 
 int inb_p (int /*<<< orphan*/ ) ; 
 struct nforce2_smbus* kcalloc (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct nforce2_smbus*) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  nforce2_dmi_blacklist2 ; 
 TYPE_1__ nforce2_driver ; 
 int /*<<< orphan*/  outb_p (unsigned char,int /*<<< orphan*/ ) ; 
 struct nforce2_smbus* pci_get_drvdata (struct pci_dev*) ; 
 scalar_t__ pci_read_config_word (struct pci_dev*,int,int*) ; 
 int pci_resource_len (struct pci_dev*,int) ; 
 int pci_resource_start (struct pci_dev*,int) ; 
 int /*<<< orphan*/  pci_set_drvdata (struct pci_dev*,struct nforce2_smbus*) ; 
 int /*<<< orphan*/  release_region (int,int) ; 
 int /*<<< orphan*/  request_region (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  smbus_algorithm ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,int) ; 

__attribute__((used)) static inline void nforce2_set_reference(struct i2c_adapter *adap) { }

__attribute__((used)) static void nforce2_abort(struct i2c_adapter *adap)
{
	struct nforce2_smbus *smbus = adap->algo_data;
	int timeout = 0;
	unsigned char temp;

	dev_dbg(&adap->dev, "Aborting current transaction\n");

	outb_p(NVIDIA_SMB_CTRL_ABORT, NVIDIA_SMB_CTRL);
	do {
		msleep(1);
		temp = inb_p(NVIDIA_SMB_STATUS_ABRT);
	} while (!(temp & NVIDIA_SMB_STATUS_ABRT_STS) &&
			(timeout++ < MAX_TIMEOUT));
	if (!(temp & NVIDIA_SMB_STATUS_ABRT_STS))
		dev_err(&adap->dev, "Can't reset the smbus\n");
	outb_p(NVIDIA_SMB_STATUS_ABRT_STS, NVIDIA_SMB_STATUS_ABRT);
}

__attribute__((used)) static int nforce2_check_status(struct i2c_adapter *adap)
{
	struct nforce2_smbus *smbus = adap->algo_data;
	int timeout = 0;
	unsigned char temp;

	do {
		msleep(1);
		temp = inb_p(NVIDIA_SMB_STS);
	} while ((!temp) && (timeout++ < MAX_TIMEOUT));

	if (timeout > MAX_TIMEOUT) {
		dev_dbg(&adap->dev, "SMBus Timeout!\n");
		if (smbus->can_abort)
			nforce2_abort(adap);
		return -ETIMEDOUT;
	}
	if (!(temp & NVIDIA_SMB_STS_DONE) || (temp & NVIDIA_SMB_STS_STATUS)) {
		dev_dbg(&adap->dev, "Transaction failed (0x%02x)!\n", temp);
		return -EIO;
	}
	return 0;
}

__attribute__((used)) static s32 nforce2_access(struct i2c_adapter *adap, u16 addr,
		unsigned short flags, char read_write,
		u8 command, int size, union i2c_smbus_data *data)
{
	struct nforce2_smbus *smbus = adap->algo_data;
	unsigned char protocol, pec;
	u8 len;
	int i, status;

	protocol = (read_write == I2C_SMBUS_READ) ? NVIDIA_SMB_PRTCL_READ :
		NVIDIA_SMB_PRTCL_WRITE;
	pec = (flags & I2C_CLIENT_PEC) ? NVIDIA_SMB_PRTCL_PEC : 0;

	switch (size) {
	case I2C_SMBUS_QUICK:
		protocol |= NVIDIA_SMB_PRTCL_QUICK;
		read_write = I2C_SMBUS_WRITE;
		break;

	case I2C_SMBUS_BYTE:
		if (read_write == I2C_SMBUS_WRITE)
			outb_p(command, NVIDIA_SMB_CMD);
		protocol |= NVIDIA_SMB_PRTCL_BYTE;
		break;

	case I2C_SMBUS_BYTE_DATA:
		outb_p(command, NVIDIA_SMB_CMD);
		if (read_write == I2C_SMBUS_WRITE)
			outb_p(data->byte, NVIDIA_SMB_DATA);
		protocol |= NVIDIA_SMB_PRTCL_BYTE_DATA;
		break;

	case I2C_SMBUS_WORD_DATA:
		outb_p(command, NVIDIA_SMB_CMD);
		if (read_write == I2C_SMBUS_WRITE) {
			outb_p(data->word, NVIDIA_SMB_DATA);
			outb_p(data->word >> 8, NVIDIA_SMB_DATA + 1);
		}
		protocol |= NVIDIA_SMB_PRTCL_WORD_DATA | pec;
		break;

	case I2C_SMBUS_BLOCK_DATA:
		outb_p(command, NVIDIA_SMB_CMD);
		if (read_write == I2C_SMBUS_WRITE) {
			len = data->block[0];
			if ((len == 0) || (len > I2C_SMBUS_BLOCK_MAX)) {
				dev_err(&adap->dev,
					"Transaction failed (requested block size: %d)\n",
					len);
				return -EINVAL;
			}
			outb_p(len, NVIDIA_SMB_BCNT);
			for (i = 0; i < I2C_SMBUS_BLOCK_MAX; i++)
				outb_p(data->block[i + 1],
				       NVIDIA_SMB_DATA + i);
		}
		protocol |= NVIDIA_SMB_PRTCL_BLOCK_DATA | pec;
		break;

	default:
		dev_err(&adap->dev, "Unsupported transaction %d\n", size);
		return -EOPNOTSUPP;
	}

	outb_p((addr & 0x7f) << 1, NVIDIA_SMB_ADDR);
	outb_p(protocol, NVIDIA_SMB_PRTCL);

	status = nforce2_check_status(adap);
	if (status)
		return status;

	if (read_write == I2C_SMBUS_WRITE)
		return 0;

	switch (size) {
	case I2C_SMBUS_BYTE:
	case I2C_SMBUS_BYTE_DATA:
		data->byte = inb_p(NVIDIA_SMB_DATA);
		break;

	case I2C_SMBUS_WORD_DATA:
		data->word = inb_p(NVIDIA_SMB_DATA) |
			     (inb_p(NVIDIA_SMB_DATA + 1) << 8);
		break;

	case I2C_SMBUS_BLOCK_DATA:
		len = inb_p(NVIDIA_SMB_BCNT);
		if ((len <= 0) || (len > I2C_SMBUS_BLOCK_MAX)) {
			dev_err(&adap->dev,
				"Transaction failed (received block size: 0x%02x)\n",
				len);
			return -EPROTO;
		}
		for (i = 0; i < len; i++)
			data->block[i + 1] = inb_p(NVIDIA_SMB_DATA + i);
		data->block[0] = len;
		break;
	}

	return 0;
}

__attribute__((used)) static u32 nforce2_func(struct i2c_adapter *adapter)
{
	/* other functionality might be possible, but is not tested */
	return I2C_FUNC_SMBUS_QUICK | I2C_FUNC_SMBUS_BYTE |
	       I2C_FUNC_SMBUS_BYTE_DATA | I2C_FUNC_SMBUS_WORD_DATA |
	       I2C_FUNC_SMBUS_PEC |
	       (((struct nforce2_smbus *)adapter->algo_data)->blockops ?
		I2C_FUNC_SMBUS_BLOCK_DATA : 0);
}

__attribute__((used)) static int nforce2_probe_smb(struct pci_dev *dev, int bar, int alt_reg,
			     struct nforce2_smbus *smbus, const char *name)
{
	int error;

	smbus->base = pci_resource_start(dev, bar);
	if (smbus->base) {
		smbus->size = pci_resource_len(dev, bar);
	} else {
		/* Older incarnations of the device used non-standard BARs */
		u16 iobase;

		if (pci_read_config_word(dev, alt_reg, &iobase)
		    != PCIBIOS_SUCCESSFUL) {
			dev_err(&dev->dev, "Error reading PCI config for %s\n",
				name);
			return -EIO;
		}

		smbus->base = iobase & PCI_BASE_ADDRESS_IO_MASK;
		smbus->size = 64;
	}

	error = acpi_check_region(smbus->base, smbus->size,
				  nforce2_driver.name);
	if (error)
		return error;

	if (!request_region(smbus->base, smbus->size, nforce2_driver.name)) {
		dev_err(&smbus->adapter.dev, "Error requesting region %02x .. %02X for %s\n",
			smbus->base, smbus->base+smbus->size-1, name);
		return -EBUSY;
	}
	smbus->adapter.owner = THIS_MODULE;
	smbus->adapter.class = I2C_CLASS_HWMON | I2C_CLASS_SPD;
	smbus->adapter.algo = &smbus_algorithm;
	smbus->adapter.algo_data = smbus;
	smbus->adapter.dev.parent = &dev->dev;
	snprintf(smbus->adapter.name, sizeof(smbus->adapter.name),
		"SMBus nForce2 adapter at %04x", smbus->base);

	error = i2c_add_adapter(&smbus->adapter);
	if (error) {
		release_region(smbus->base, smbus->size);
		return error;
	}
	dev_info(&smbus->adapter.dev, "nForce2 SMBus adapter at %#x\n",
		smbus->base);
	return 0;
}

__attribute__((used)) static int nforce2_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
	struct nforce2_smbus *smbuses;
	int res1, res2;

	/* we support 2 SMBus adapters */
	smbuses = kcalloc(2, sizeof(struct nforce2_smbus), GFP_KERNEL);
	if (!smbuses)
		return -ENOMEM;
	pci_set_drvdata(dev, smbuses);

	switch (dev->device) {
	case PCI_DEVICE_ID_NVIDIA_NFORCE2_SMBUS:
	case PCI_DEVICE_ID_NVIDIA_NFORCE_MCP51_SMBUS:
	case PCI_DEVICE_ID_NVIDIA_NFORCE_MCP55_SMBUS:
		smbuses[0].blockops = 1;
		smbuses[1].blockops = 1;
		smbuses[0].can_abort = 1;
		smbuses[1].can_abort = 1;
	}

	/* SMBus adapter 1 */
	res1 = nforce2_probe_smb(dev, 4, NFORCE_PCI_SMB1, &smbuses[0], "SMB1");
	if (res1 < 0)
		smbuses[0].base = 0;	/* to have a check value */

	/* SMBus adapter 2 */
	if (dmi_check_system(nforce2_dmi_blacklist2)) {
		dev_err(&dev->dev, "Disabling SMB2 for safety reasons.\n");
		res2 = -EPERM;
		smbuses[1].base = 0;
	} else {
		res2 = nforce2_probe_smb(dev, 5, NFORCE_PCI_SMB2, &smbuses[1],
					 "SMB2");
		if (res2 < 0)
			smbuses[1].base = 0;	/* to have a check value */
	}

	if ((res1 < 0) && (res2 < 0)) {
		/* we did not find even one of the SMBuses, so we give up */
		kfree(smbuses);
		return -ENODEV;
	}

	nforce2_set_reference(&smbuses[0].adapter);
	return 0;
}

__attribute__((used)) static void nforce2_remove(struct pci_dev *dev)
{
	struct nforce2_smbus *smbuses = pci_get_drvdata(dev);

	nforce2_set_reference(NULL);
	if (smbuses[0].base) {
		i2c_del_adapter(&smbuses[0].adapter);
		release_region(smbuses[0].base, smbuses[0].size);
	}
	if (smbuses[1].base) {
		i2c_del_adapter(&smbuses[1].adapter);
		release_region(smbuses[1].base, smbuses[1].size);
	}
	kfree(smbuses);
}

