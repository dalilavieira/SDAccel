#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
struct resource {int start; scalar_t__ end; } ;
struct pci_device_id {size_t driver_data; } ;
struct pci_dev {int /*<<< orphan*/  dev; struct pci_bus* bus; } ;
struct pci_bus {int dummy; } ;
struct mfd_cell {int pdata_size; struct lpc_ich_info* platform_data; int /*<<< orphan*/  num_resources; int /*<<< orphan*/  name; } ;
struct lpc_ich_priv {int abase_save; int actrl_pbase_save; int gctrl_save; size_t chipset; int /*<<< orphan*/  gctrl; int /*<<< orphan*/  gbase; int /*<<< orphan*/  actrl_pbase; int /*<<< orphan*/  abase; } ;
struct lpc_ich_info {int iTCO_version; int version; int gpio_version; int use_gpio; int type; int spi_type; int writeable; int /*<<< orphan*/  name; } ;
struct itco_wdt_platform_data {int iTCO_version; int version; int gpio_version; int use_gpio; int type; int spi_type; int writeable; int /*<<< orphan*/  name; } ;
struct intel_spi_boardinfo {int iTCO_version; int version; int gpio_version; int use_gpio; int type; int spi_type; int writeable; int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int /*<<< orphan*/  ACPIBASE ; 
 scalar_t__ ACPIBASE_GCS_END ; 
 int ACPIBASE_GCS_OFF ; 
 scalar_t__ ACPIBASE_GPE_END ; 
 int ACPIBASE_GPE_OFF ; 
 scalar_t__ ACPIBASE_PMC_END ; 
 int ACPIBASE_PMC_OFF ; 
 scalar_t__ ACPIBASE_SMI_END ; 
 int ACPIBASE_SMI_OFF ; 
 scalar_t__ ACPIBASE_TCO_END ; 
 int ACPIBASE_TCO_OFF ; 
 int /*<<< orphan*/  ACPICTRL_PMCBASE ; 
 int /*<<< orphan*/  BCR ; 
 int BCR_WPD ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOBASE_ICH0 ; 
 int /*<<< orphan*/  GPIOBASE_ICH6 ; 
 int /*<<< orphan*/  GPIOCTRL_ICH0 ; 
 int /*<<< orphan*/  GPIOCTRL_ICH6 ; 
 size_t ICH_RES_GPE0 ; 
 size_t ICH_RES_GPIO ; 
 int /*<<< orphan*/  ICH_RES_IO_SMI ; 
 int /*<<< orphan*/  ICH_RES_IO_TCO ; 
 int /*<<< orphan*/  ICH_RES_MEM_GCS_PMC ; 
#define  ICH_V10CORP_GPIO 132 
#define  ICH_V5_GPIO 131 
#define  INTEL_SPI_BXT 130 
#define  INTEL_SPI_BYT 129 
#define  INTEL_SPI_LPT 128 
 size_t LPC_ICH5 ; 
 int /*<<< orphan*/  PCI_BASE_ADDRESS_0 ; 
 unsigned int PCI_DEVFN (int,int) ; 
 int /*<<< orphan*/  PLATFORM_DEVID_AUTO ; 
 int /*<<< orphan*/  PLATFORM_DEVID_NONE ; 
 int /*<<< orphan*/  RCBABASE ; 
 int SPIBASE_APL_SZ ; 
 int /*<<< orphan*/  SPIBASE_BYT ; 
 int SPIBASE_BYT_EN ; 
 int SPIBASE_BYT_SZ ; 
 int SPIBASE_LPT ; 
 int SPIBASE_LPT_SZ ; 
 int acpi_check_region (int,int,char*) ; 
 int acpi_check_resource_conflict (struct resource*) ; 
 scalar_t__ acpi_has_watchdog () ; 
 int /*<<< orphan*/  dev_notice (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*) ; 
 void* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct resource* gpio_ich_res ; 
 struct resource* intel_spi_res ; 
 struct lpc_ich_info* lpc_chipset_info ; 
 struct mfd_cell lpc_ich_gpio_cell ; 
 struct mfd_cell lpc_ich_spi_cell ; 
 struct mfd_cell lpc_ich_wdt_cell ; 
 int mfd_add_devices (int /*<<< orphan*/ *,int /*<<< orphan*/ ,struct mfd_cell*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mfd_remove_devices (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pci_bus_read_config_dword (struct pci_bus*,unsigned int,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  pci_bus_write_config_byte (struct pci_bus*,unsigned int,int,int) ; 
 struct lpc_ich_priv* pci_get_drvdata (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_read_config_byte (struct pci_dev*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  pci_read_config_dword (struct pci_dev*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  pci_set_drvdata (struct pci_dev*,struct lpc_ich_priv*) ; 
 int /*<<< orphan*/  pci_write_config_byte (struct pci_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pr_warn (char*,int /*<<< orphan*/ ) ; 
 int resource_size (struct resource*) ; 
 int round_down (int,int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 struct resource* wdt_io_res (int /*<<< orphan*/ ) ; 
 struct resource* wdt_mem_res (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void lpc_ich_restore_config_space(struct pci_dev *dev)
{
	struct lpc_ich_priv *priv = pci_get_drvdata(dev);

	if (priv->abase_save >= 0) {
		pci_write_config_byte(dev, priv->abase, priv->abase_save);
		priv->abase_save = -1;
	}

	if (priv->actrl_pbase_save >= 0) {
		pci_write_config_byte(dev, priv->actrl_pbase,
			priv->actrl_pbase_save);
		priv->actrl_pbase_save = -1;
	}

	if (priv->gctrl_save >= 0) {
		pci_write_config_byte(dev, priv->gctrl, priv->gctrl_save);
		priv->gctrl_save = -1;
	}
}

__attribute__((used)) static void lpc_ich_enable_acpi_space(struct pci_dev *dev)
{
	struct lpc_ich_priv *priv = pci_get_drvdata(dev);
	u8 reg_save;

	switch (lpc_chipset_info[priv->chipset].iTCO_version) {
	case 3:
		/*
		 * Some chipsets (eg Avoton) enable the ACPI space in the
		 * ACPI BASE register.
		 */
		pci_read_config_byte(dev, priv->abase, &reg_save);
		pci_write_config_byte(dev, priv->abase, reg_save | 0x2);
		priv->abase_save = reg_save;
		break;
	default:
		/*
		 * Most chipsets enable the ACPI space in the ACPI control
		 * register.
		 */
		pci_read_config_byte(dev, priv->actrl_pbase, &reg_save);
		pci_write_config_byte(dev, priv->actrl_pbase, reg_save | 0x80);
		priv->actrl_pbase_save = reg_save;
		break;
	}
}

__attribute__((used)) static void lpc_ich_enable_gpio_space(struct pci_dev *dev)
{
	struct lpc_ich_priv *priv = pci_get_drvdata(dev);
	u8 reg_save;

	pci_read_config_byte(dev, priv->gctrl, &reg_save);
	pci_write_config_byte(dev, priv->gctrl, reg_save | 0x10);
	priv->gctrl_save = reg_save;
}

__attribute__((used)) static void lpc_ich_enable_pmc_space(struct pci_dev *dev)
{
	struct lpc_ich_priv *priv = pci_get_drvdata(dev);
	u8 reg_save;

	pci_read_config_byte(dev, priv->actrl_pbase, &reg_save);
	pci_write_config_byte(dev, priv->actrl_pbase, reg_save | 0x2);

	priv->actrl_pbase_save = reg_save;
}

__attribute__((used)) static int lpc_ich_finalize_wdt_cell(struct pci_dev *dev)
{
	struct itco_wdt_platform_data *pdata;
	struct lpc_ich_priv *priv = pci_get_drvdata(dev);
	struct lpc_ich_info *info;
	struct mfd_cell *cell = &lpc_ich_wdt_cell;

	pdata = devm_kzalloc(&dev->dev, sizeof(*pdata), GFP_KERNEL);
	if (!pdata)
		return -ENOMEM;

	info = &lpc_chipset_info[priv->chipset];

	pdata->version = info->iTCO_version;
	strlcpy(pdata->name, info->name, sizeof(pdata->name));

	cell->platform_data = pdata;
	cell->pdata_size = sizeof(*pdata);
	return 0;
}

__attribute__((used)) static void lpc_ich_finalize_gpio_cell(struct pci_dev *dev)
{
	struct lpc_ich_priv *priv = pci_get_drvdata(dev);
	struct mfd_cell *cell = &lpc_ich_gpio_cell;

	cell->platform_data = &lpc_chipset_info[priv->chipset];
	cell->pdata_size = sizeof(struct lpc_ich_info);
}

__attribute__((used)) static int lpc_ich_check_conflict_gpio(struct resource *res)
{
	int ret;
	u8 use_gpio = 0;

	if (resource_size(res) >= 0x50 &&
	    !acpi_check_region(res->start + 0x40, 0x10, "LPC ICH GPIO3"))
		use_gpio |= 1 << 2;

	if (!acpi_check_region(res->start + 0x30, 0x10, "LPC ICH GPIO2"))
		use_gpio |= 1 << 1;

	ret = acpi_check_region(res->start + 0x00, 0x30, "LPC ICH GPIO1");
	if (!ret)
		use_gpio |= 1 << 0;

	return use_gpio ? use_gpio : ret;
}

__attribute__((used)) static int lpc_ich_init_gpio(struct pci_dev *dev)
{
	struct lpc_ich_priv *priv = pci_get_drvdata(dev);
	u32 base_addr_cfg;
	u32 base_addr;
	int ret;
	bool acpi_conflict = false;
	struct resource *res;

	/* Setup power management base register */
	pci_read_config_dword(dev, priv->abase, &base_addr_cfg);
	base_addr = base_addr_cfg & 0x0000ff80;
	if (!base_addr) {
		dev_notice(&dev->dev, "I/O space for ACPI uninitialized\n");
		lpc_ich_gpio_cell.num_resources--;
		goto gpe0_done;
	}

	res = &gpio_ich_res[ICH_RES_GPE0];
	res->start = base_addr + ACPIBASE_GPE_OFF;
	res->end = base_addr + ACPIBASE_GPE_END;
	ret = acpi_check_resource_conflict(res);
	if (ret) {
		/*
		 * This isn't fatal for the GPIO, but we have to make sure that
		 * the platform_device subsystem doesn't see this resource
		 * or it will register an invalid region.
		 */
		lpc_ich_gpio_cell.num_resources--;
		acpi_conflict = true;
	} else {
		lpc_ich_enable_acpi_space(dev);
	}

gpe0_done:
	/* Setup GPIO base register */
	pci_read_config_dword(dev, priv->gbase, &base_addr_cfg);
	base_addr = base_addr_cfg & 0x0000ff80;
	if (!base_addr) {
		dev_notice(&dev->dev, "I/O space for GPIO uninitialized\n");
		ret = -ENODEV;
		goto gpio_done;
	}

	/* Older devices provide fewer GPIO and have a smaller resource size. */
	res = &gpio_ich_res[ICH_RES_GPIO];
	res->start = base_addr;
	switch (lpc_chipset_info[priv->chipset].gpio_version) {
	case ICH_V5_GPIO:
	case ICH_V10CORP_GPIO:
		res->end = res->start + 128 - 1;
		break;
	default:
		res->end = res->start + 64 - 1;
		break;
	}

	ret = lpc_ich_check_conflict_gpio(res);
	if (ret < 0) {
		/* this isn't necessarily fatal for the GPIO */
		acpi_conflict = true;
		goto gpio_done;
	}
	lpc_chipset_info[priv->chipset].use_gpio = ret;
	lpc_ich_enable_gpio_space(dev);

	lpc_ich_finalize_gpio_cell(dev);
	ret = mfd_add_devices(&dev->dev, PLATFORM_DEVID_AUTO,
			      &lpc_ich_gpio_cell, 1, NULL, 0, NULL);

gpio_done:
	if (acpi_conflict)
		pr_warn("Resource conflict(s) found affecting %s\n",
				lpc_ich_gpio_cell.name);
	return ret;
}

__attribute__((used)) static int lpc_ich_init_wdt(struct pci_dev *dev)
{
	struct lpc_ich_priv *priv = pci_get_drvdata(dev);
	u32 base_addr_cfg;
	u32 base_addr;
	int ret;
	struct resource *res;

	/* If we have ACPI based watchdog use that instead */
	if (acpi_has_watchdog())
		return -ENODEV;

	/* Setup power management base register */
	pci_read_config_dword(dev, priv->abase, &base_addr_cfg);
	base_addr = base_addr_cfg & 0x0000ff80;
	if (!base_addr) {
		dev_notice(&dev->dev, "I/O space for ACPI uninitialized\n");
		ret = -ENODEV;
		goto wdt_done;
	}

	res = wdt_io_res(ICH_RES_IO_TCO);
	res->start = base_addr + ACPIBASE_TCO_OFF;
	res->end = base_addr + ACPIBASE_TCO_END;

	res = wdt_io_res(ICH_RES_IO_SMI);
	res->start = base_addr + ACPIBASE_SMI_OFF;
	res->end = base_addr + ACPIBASE_SMI_END;

	lpc_ich_enable_acpi_space(dev);

	/*
	 * iTCO v2:
	 * Get the Memory-Mapped GCS register. To get access to it
	 * we have to read RCBA from PCI Config space 0xf0 and use
	 * it as base. GCS = RCBA + ICH6_GCS(0x3410).
	 *
	 * iTCO v3:
	 * Get the Power Management Configuration register.  To get access
	 * to it we have to read the PMC BASE from config space and address
	 * the register at offset 0x8.
	 */
	if (lpc_chipset_info[priv->chipset].iTCO_version == 1) {
		/* Don't register iomem for TCO ver 1 */
		lpc_ich_wdt_cell.num_resources--;
	} else if (lpc_chipset_info[priv->chipset].iTCO_version == 2) {
		pci_read_config_dword(dev, RCBABASE, &base_addr_cfg);
		base_addr = base_addr_cfg & 0xffffc000;
		if (!(base_addr_cfg & 1)) {
			dev_notice(&dev->dev, "RCBA is disabled by "
					"hardware/BIOS, device disabled\n");
			ret = -ENODEV;
			goto wdt_done;
		}
		res = wdt_mem_res(ICH_RES_MEM_GCS_PMC);
		res->start = base_addr + ACPIBASE_GCS_OFF;
		res->end = base_addr + ACPIBASE_GCS_END;
	} else if (lpc_chipset_info[priv->chipset].iTCO_version == 3) {
		lpc_ich_enable_pmc_space(dev);
		pci_read_config_dword(dev, ACPICTRL_PMCBASE, &base_addr_cfg);
		base_addr = base_addr_cfg & 0xfffffe00;

		res = wdt_mem_res(ICH_RES_MEM_GCS_PMC);
		res->start = base_addr + ACPIBASE_PMC_OFF;
		res->end = base_addr + ACPIBASE_PMC_END;
	}

	ret = lpc_ich_finalize_wdt_cell(dev);
	if (ret)
		goto wdt_done;

	ret = mfd_add_devices(&dev->dev, PLATFORM_DEVID_AUTO,
			      &lpc_ich_wdt_cell, 1, NULL, 0, NULL);

wdt_done:
	return ret;
}

__attribute__((used)) static int lpc_ich_init_spi(struct pci_dev *dev)
{
	struct lpc_ich_priv *priv = pci_get_drvdata(dev);
	struct resource *res = &intel_spi_res[0];
	struct intel_spi_boardinfo *info;
	u32 spi_base, rcba, bcr;

	info = devm_kzalloc(&dev->dev, sizeof(*info), GFP_KERNEL);
	if (!info)
		return -ENOMEM;

	info->type = lpc_chipset_info[priv->chipset].spi_type;

	switch (info->type) {
	case INTEL_SPI_BYT:
		pci_read_config_dword(dev, SPIBASE_BYT, &spi_base);
		if (spi_base & SPIBASE_BYT_EN) {
			res->start = spi_base & ~(SPIBASE_BYT_SZ - 1);
			res->end = res->start + SPIBASE_BYT_SZ - 1;
		}
		break;

	case INTEL_SPI_LPT:
		pci_read_config_dword(dev, RCBABASE, &rcba);
		if (rcba & 1) {
			spi_base = round_down(rcba, SPIBASE_LPT_SZ);
			res->start = spi_base + SPIBASE_LPT;
			res->end = res->start + SPIBASE_LPT_SZ - 1;

			pci_read_config_dword(dev, BCR, &bcr);
			info->writeable = !!(bcr & BCR_WPD);
		}
		break;

	case INTEL_SPI_BXT: {
		unsigned int p2sb = PCI_DEVFN(13, 0);
		unsigned int spi = PCI_DEVFN(13, 2);
		struct pci_bus *bus = dev->bus;

		/*
		 * The P2SB is hidden by BIOS and we need to unhide it in
		 * order to read BAR of the SPI flash device. Once that is
		 * done we hide it again.
		 */
		pci_bus_write_config_byte(bus, p2sb, 0xe1, 0x0);
		pci_bus_read_config_dword(bus, spi, PCI_BASE_ADDRESS_0,
					  &spi_base);
		if (spi_base != ~0) {
			res->start = spi_base & 0xfffffff0;
			res->end = res->start + SPIBASE_APL_SZ - 1;

			pci_bus_read_config_dword(bus, spi, BCR, &bcr);
			info->writeable = !!(bcr & BCR_WPD);
		}

		pci_bus_write_config_byte(bus, p2sb, 0xe1, 0x1);
		break;
	}

	default:
		return -EINVAL;
	}

	if (!res->start)
		return -ENODEV;

	lpc_ich_spi_cell.platform_data = info;
	lpc_ich_spi_cell.pdata_size = sizeof(*info);

	return mfd_add_devices(&dev->dev, PLATFORM_DEVID_NONE,
			       &lpc_ich_spi_cell, 1, NULL, 0, NULL);
}

__attribute__((used)) static int lpc_ich_probe(struct pci_dev *dev,
				const struct pci_device_id *id)
{
	struct lpc_ich_priv *priv;
	int ret;
	bool cell_added = false;

	priv = devm_kzalloc(&dev->dev,
			    sizeof(struct lpc_ich_priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	priv->chipset = id->driver_data;

	priv->actrl_pbase_save = -1;
	priv->abase_save = -1;

	priv->abase = ACPIBASE;
	priv->actrl_pbase = ACPICTRL_PMCBASE;

	priv->gctrl_save = -1;
	if (priv->chipset <= LPC_ICH5) {
		priv->gbase = GPIOBASE_ICH0;
		priv->gctrl = GPIOCTRL_ICH0;
	} else {
		priv->gbase = GPIOBASE_ICH6;
		priv->gctrl = GPIOCTRL_ICH6;
	}

	pci_set_drvdata(dev, priv);

	if (lpc_chipset_info[priv->chipset].iTCO_version) {
		ret = lpc_ich_init_wdt(dev);
		if (!ret)
			cell_added = true;
	}

	if (lpc_chipset_info[priv->chipset].gpio_version) {
		ret = lpc_ich_init_gpio(dev);
		if (!ret)
			cell_added = true;
	}

	if (lpc_chipset_info[priv->chipset].spi_type) {
		ret = lpc_ich_init_spi(dev);
		if (!ret)
			cell_added = true;
	}

	/*
	 * We only care if at least one or none of the cells registered
	 * successfully.
	 */
	if (!cell_added) {
		dev_warn(&dev->dev, "No MFD cells added\n");
		lpc_ich_restore_config_space(dev);
		return -ENODEV;
	}

	return 0;
}

__attribute__((used)) static void lpc_ich_remove(struct pci_dev *dev)
{
	mfd_remove_devices(&dev->dev);
	lpc_ich_restore_config_space(dev);
}

