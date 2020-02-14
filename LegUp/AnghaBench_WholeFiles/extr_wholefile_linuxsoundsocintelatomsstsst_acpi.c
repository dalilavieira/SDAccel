#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct x86_cpu_id {int member_1; int member_2; int /*<<< orphan*/  member_0; } ;
struct sst_platform_info {int platform; TYPE_3__* res_info; } ;
struct snd_soc_acpi_mach {int drv_name; int /*<<< orphan*/  fw_filename; struct sst_platform_info* pdata; } ;
struct resource {int /*<<< orphan*/  end; scalar_t__ start; } ;
struct device {TYPE_2__* driver; } ;
struct platform_device {struct device dev; } ;
struct TYPE_4__ {scalar_t__ mailbox_start; } ;
struct intel_sst_drv {int irq_num; int /*<<< orphan*/  firmware_name; struct sst_platform_info* pdata; int /*<<< orphan*/  dev; void* ddr; scalar_t__ ddr_base; int /*<<< orphan*/  ddr_end; TYPE_1__ info; scalar_t__ mailbox_add; void* mailbox; scalar_t__ shim_phy_add; void* shim; void* dram; scalar_t__ dram_base; scalar_t__ dram_end; void* iram; scalar_t__ iram_base; scalar_t__ iram_end; } ;
struct acpi_device_id {unsigned int id; scalar_t__ driver_data; } ;
struct TYPE_6__ {int /*<<< orphan*/  acpi_ipc_irq_index; int /*<<< orphan*/  acpi_ddr_index; scalar_t__ mbox_size; scalar_t__ mbox_offset; scalar_t__ shim_phy_addr; scalar_t__ shim_size; scalar_t__ shim_offset; scalar_t__ dram_size; scalar_t__ dram_offset; scalar_t__ iram_size; scalar_t__ iram_offset; int /*<<< orphan*/  acpi_lpe_res_index; } ;
struct TYPE_5__ {int /*<<< orphan*/  acpi_match_table; } ;

/* Variables and functions */
 int /*<<< orphan*/  BT_MBI_UNIT_PMC ; 
 int /*<<< orphan*/  CONFIG_IOSF_MBI ; 
 int EIO ; 
 int ENODEV ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ENABLED (int /*<<< orphan*/ ) ; 
 scalar_t__ IS_ERR (struct platform_device*) ; 
 int /*<<< orphan*/  MBI_REG_READ ; 
 int PTR_ERR (struct platform_device*) ; 
#define  X86_VENDOR_INTEL 128 
 struct acpi_device_id* acpi_match_device (int /*<<< orphan*/ ,struct device*) ; 
 struct sst_platform_info byt_rvp_platform_data ; 
 TYPE_3__ bytcr_res_info ; 
 struct sst_platform_info chv_platform_data ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,unsigned int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,...) ; 
 void* devm_ioremap_nocache (int /*<<< orphan*/ ,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  iosf_mbi_available () ; 
 int iosf_mbi_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int*) ; 
 int kstrtouint (unsigned int,int,unsigned int*) ; 
 struct platform_device* platform_device_register_data (struct device*,int,int,void const*,int) ; 
 struct intel_sst_drv* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct intel_sst_drv*) ; 
 scalar_t__ resource_size (struct resource*) ; 
 struct snd_soc_acpi_mach* snd_soc_acpi_find_machine (struct snd_soc_acpi_mach*) ; 
 int sst_alloc_drv_context (struct intel_sst_drv**,struct device*,unsigned int) ; 
 int /*<<< orphan*/  sst_configure_runtime_pm (struct intel_sst_drv*) ; 
 int /*<<< orphan*/  sst_context_cleanup (struct intel_sst_drv*) ; 
 int sst_context_init (struct intel_sst_drv*) ; 
 int /*<<< orphan*/  strcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct platform_device* to_platform_device (int /*<<< orphan*/ ) ; 
 scalar_t__ x86_match_cpu (struct x86_cpu_id const*) ; 

__attribute__((used)) static int sst_platform_get_resources(struct intel_sst_drv *ctx)
{
	struct resource *rsrc;
	struct platform_device *pdev = to_platform_device(ctx->dev);

	/* All ACPI resource request here */
	/* Get Shim addr */
	rsrc = platform_get_resource(pdev, IORESOURCE_MEM,
					ctx->pdata->res_info->acpi_lpe_res_index);
	if (!rsrc) {
		dev_err(ctx->dev, "Invalid SHIM base from IFWI\n");
		return -EIO;
	}
	dev_info(ctx->dev, "LPE base: %#x size:%#x", (unsigned int) rsrc->start,
					(unsigned int)resource_size(rsrc));

	ctx->iram_base = rsrc->start + ctx->pdata->res_info->iram_offset;
	ctx->iram_end =  ctx->iram_base + ctx->pdata->res_info->iram_size - 1;
	dev_info(ctx->dev, "IRAM base: %#x", ctx->iram_base);
	ctx->iram = devm_ioremap_nocache(ctx->dev, ctx->iram_base,
					 ctx->pdata->res_info->iram_size);
	if (!ctx->iram) {
		dev_err(ctx->dev, "unable to map IRAM\n");
		return -EIO;
	}

	ctx->dram_base = rsrc->start + ctx->pdata->res_info->dram_offset;
	ctx->dram_end = ctx->dram_base + ctx->pdata->res_info->dram_size - 1;
	dev_info(ctx->dev, "DRAM base: %#x", ctx->dram_base);
	ctx->dram = devm_ioremap_nocache(ctx->dev, ctx->dram_base,
					 ctx->pdata->res_info->dram_size);
	if (!ctx->dram) {
		dev_err(ctx->dev, "unable to map DRAM\n");
		return -EIO;
	}

	ctx->shim_phy_add = rsrc->start + ctx->pdata->res_info->shim_offset;
	dev_info(ctx->dev, "SHIM base: %#x", ctx->shim_phy_add);
	ctx->shim = devm_ioremap_nocache(ctx->dev, ctx->shim_phy_add,
					ctx->pdata->res_info->shim_size);
	if (!ctx->shim) {
		dev_err(ctx->dev, "unable to map SHIM\n");
		return -EIO;
	}

	/* reassign physical address to LPE viewpoint address */
	ctx->shim_phy_add = ctx->pdata->res_info->shim_phy_addr;

	/* Get mailbox addr */
	ctx->mailbox_add = rsrc->start + ctx->pdata->res_info->mbox_offset;
	dev_info(ctx->dev, "Mailbox base: %#x", ctx->mailbox_add);
	ctx->mailbox = devm_ioremap_nocache(ctx->dev, ctx->mailbox_add,
					    ctx->pdata->res_info->mbox_size);
	if (!ctx->mailbox) {
		dev_err(ctx->dev, "unable to map mailbox\n");
		return -EIO;
	}

	/* reassign physical address to LPE viewpoint address */
	ctx->mailbox_add = ctx->info.mailbox_start;

	rsrc = platform_get_resource(pdev, IORESOURCE_MEM,
					ctx->pdata->res_info->acpi_ddr_index);
	if (!rsrc) {
		dev_err(ctx->dev, "Invalid DDR base from IFWI\n");
		return -EIO;
	}
	ctx->ddr_base = rsrc->start;
	ctx->ddr_end = rsrc->end;
	dev_info(ctx->dev, "DDR base: %#x", ctx->ddr_base);
	ctx->ddr = devm_ioremap_nocache(ctx->dev, ctx->ddr_base,
					resource_size(rsrc));
	if (!ctx->ddr) {
		dev_err(ctx->dev, "unable to map DDR\n");
		return -EIO;
	}

	/* Find the IRQ */
	ctx->irq_num = platform_get_irq(pdev,
				ctx->pdata->res_info->acpi_ipc_irq_index);
	if (ctx->irq_num <= 0)
		return ctx->irq_num < 0 ? ctx->irq_num : -EIO;

	return 0;
}

__attribute__((used)) static int is_byt(void)
{
	bool status = false;
	static const struct x86_cpu_id cpu_ids[] = {
		{ X86_VENDOR_INTEL, 6, 55 }, /* Valleyview, Bay Trail */
		{}
	};
	if (x86_match_cpu(cpu_ids))
		status = true;
	return status;
}

__attribute__((used)) static int is_byt_cr(struct device *dev, bool *bytcr)
{
	int status = 0;

	if (IS_ENABLED(CONFIG_IOSF_MBI)) {
		u32 bios_status;

		if (!is_byt() || !iosf_mbi_available()) {
			/* bail silently */
			return status;
		}

		status = iosf_mbi_read(BT_MBI_UNIT_PMC, /* 0x04 PUNIT */
				       MBI_REG_READ, /* 0x10 */
				       0x006, /* BIOS_CONFIG */
				       &bios_status);

		if (status) {
			dev_err(dev, "could not read PUNIT BIOS_CONFIG\n");
		} else {
			/* bits 26:27 mirror PMIC options */
			bios_status = (bios_status >> 26) & 3;

			if ((bios_status == 1) || (bios_status == 3))
				*bytcr = true;
			else
				dev_info(dev, "BYT-CR not detected\n");
		}
	} else {
		dev_info(dev, "IOSF_MBI not enabled, no BYT-CR detection\n");
	}
	return status;
}

__attribute__((used)) static int sst_acpi_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	int ret = 0;
	struct intel_sst_drv *ctx;
	const struct acpi_device_id *id;
	struct snd_soc_acpi_mach *mach;
	struct platform_device *mdev;
	struct platform_device *plat_dev;
	struct sst_platform_info *pdata;
	unsigned int dev_id;
	bool bytcr = false;

	id = acpi_match_device(dev->driver->acpi_match_table, dev);
	if (!id)
		return -ENODEV;
	dev_dbg(dev, "for %s\n", id->id);

	mach = (struct snd_soc_acpi_mach *)id->driver_data;
	mach = snd_soc_acpi_find_machine(mach);
	if (mach == NULL) {
		dev_err(dev, "No matching machine driver found\n");
		return -ENODEV;
	}

	if (is_byt())
		mach->pdata = &byt_rvp_platform_data;
	else
		mach->pdata = &chv_platform_data;
	pdata = mach->pdata;

	ret = kstrtouint(id->id, 16, &dev_id);
	if (ret < 0) {
		dev_err(dev, "Unique device id conversion error: %d\n", ret);
		return ret;
	}

	dev_dbg(dev, "ACPI device id: %x\n", dev_id);

	ret = sst_alloc_drv_context(&ctx, dev, dev_id);
	if (ret < 0)
		return ret;

	ret = is_byt_cr(dev, &bytcr);
	if (!((ret < 0) || (bytcr == false))) {
		dev_info(dev, "Detected Baytrail-CR platform\n");

		/* override resource info */
		byt_rvp_platform_data.res_info = &bytcr_res_info;
	}

	plat_dev = platform_device_register_data(dev, pdata->platform, -1,
						NULL, 0);
	if (IS_ERR(plat_dev)) {
		dev_err(dev, "Failed to create machine device: %s\n",
			pdata->platform);
		return PTR_ERR(plat_dev);
	}

	/*
	 * Create platform device for sst machine driver,
	 * pass machine info as pdata
	 */
	mdev = platform_device_register_data(dev, mach->drv_name, -1,
					(const void *)mach, sizeof(*mach));
	if (IS_ERR(mdev)) {
		dev_err(dev, "Failed to create machine device: %s\n",
			mach->drv_name);
		return PTR_ERR(mdev);
	}

	/* Fill sst platform data */
	ctx->pdata = pdata;
	strcpy(ctx->firmware_name, mach->fw_filename);

	ret = sst_platform_get_resources(ctx);
	if (ret)
		return ret;

	ret = sst_context_init(ctx);
	if (ret < 0)
		return ret;

	sst_configure_runtime_pm(ctx);
	platform_set_drvdata(pdev, ctx);
	return ret;
}

__attribute__((used)) static int sst_acpi_remove(struct platform_device *pdev)
{
	struct intel_sst_drv *ctx;

	ctx = platform_get_drvdata(pdev);
	sst_context_cleanup(ctx);
	platform_set_drvdata(pdev, NULL);
	return 0;
}

