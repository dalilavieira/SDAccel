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
typedef  int u32 ;
struct sp_platform {unsigned int irq_count; int coherent; } ;
struct sp_device {int psp_irq; int ccp_irq; int /*<<< orphan*/  axcache; int /*<<< orphan*/  io_map; struct sp_dev_vdata* dev_vdata; struct sp_platform* dev_specific; struct device* dev; } ;
struct sp_dev_vdata {int dummy; } ;
struct resource {int dummy; } ;
struct device {scalar_t__ of_node; } ;
struct platform_device {unsigned int num_resources; struct device dev; struct resource* resource; } ;
struct ccp_dma_info {scalar_t__ offset; scalar_t__ address; } ;
typedef  int /*<<< orphan*/  pm_message_t ;
typedef  enum dev_dma_attr { ____Placeholder_dev_dma_attr } dev_dma_attr ;

/* Variables and functions */
 int /*<<< orphan*/  CACHE_NONE ; 
 int /*<<< orphan*/  CACHE_WB_NO_ALLOC ; 
 int DEV_DMA_COHERENT ; 
 int DEV_DMA_NOT_SUPPORTED ; 
 int /*<<< orphan*/  DMA_BIT_MASK (int) ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IORESOURCE_IRQ ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct sp_device* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_notice (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct sp_device*) ; 
 int device_get_dma_attr (struct device*) ; 
 int /*<<< orphan*/  devm_ioremap_resource (struct device*,struct resource*) ; 
 struct sp_platform* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int dma_set_mask_and_coherent (struct device*,int /*<<< orphan*/ ) ; 
 int lower_32_bits (scalar_t__) ; 
 int platform_driver_register (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  platform_driver_unregister (int /*<<< orphan*/ *) ; 
 int platform_get_irq (struct platform_device*,int) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ resource_type (struct resource*) ; 
 struct sp_device* sp_alloc_struct (struct device*) ; 
 int /*<<< orphan*/  sp_destroy (struct sp_device*) ; 
 int sp_init (struct sp_device*) ; 
 int /*<<< orphan*/  sp_platform_driver ; 
 struct platform_device* to_platform_device (struct device*) ; 
 int upper_32_bits (scalar_t__) ; 

__attribute__((used)) static inline int ccp_dev_init(struct sp_device *sp)
{
	return 0;
}

__attribute__((used)) static inline void ccp_dev_destroy(struct sp_device *sp) { }

__attribute__((used)) static inline int ccp_dev_suspend(struct sp_device *sp, pm_message_t state)
{
	return 0;
}

__attribute__((used)) static inline int ccp_dev_resume(struct sp_device *sp)
{
	return 0;
}

__attribute__((used)) static inline int psp_dev_init(struct sp_device *sp) { return 0; }

__attribute__((used)) static inline void psp_pci_init(void) { }

__attribute__((used)) static inline void psp_dev_destroy(struct sp_device *sp) { }

__attribute__((used)) static inline void psp_pci_exit(void) { }

__attribute__((used)) static inline u32 ccp_addr_lo(struct ccp_dma_info *info)
{
	return lower_32_bits(info->address + info->offset);
}

__attribute__((used)) static inline u32 ccp_addr_hi(struct ccp_dma_info *info)
{
	return upper_32_bits(info->address + info->offset) & 0x0000ffff;
}

__attribute__((used)) static struct sp_dev_vdata *sp_get_of_version(struct platform_device *pdev)
{
#ifdef CONFIG_OF
	const struct of_device_id *match;

	match = of_match_node(sp_of_match, pdev->dev.of_node);
	if (match && match->data)
		return (struct sp_dev_vdata *)match->data;
#endif
	return NULL;
}

__attribute__((used)) static struct sp_dev_vdata *sp_get_acpi_version(struct platform_device *pdev)
{
#ifdef CONFIG_ACPI
	const struct acpi_device_id *match;

	match = acpi_match_device(sp_acpi_match, &pdev->dev);
	if (match && match->driver_data)
		return (struct sp_dev_vdata *)match->driver_data;
#endif
	return NULL;
}

__attribute__((used)) static int sp_get_irqs(struct sp_device *sp)
{
	struct sp_platform *sp_platform = sp->dev_specific;
	struct device *dev = sp->dev;
	struct platform_device *pdev = to_platform_device(dev);
	unsigned int i, count;
	int ret;

	for (i = 0, count = 0; i < pdev->num_resources; i++) {
		struct resource *res = &pdev->resource[i];

		if (resource_type(res) == IORESOURCE_IRQ)
			count++;
	}

	sp_platform->irq_count = count;

	ret = platform_get_irq(pdev, 0);
	if (ret < 0) {
		dev_notice(dev, "unable to get IRQ (%d)\n", ret);
		return ret;
	}

	sp->psp_irq = ret;
	if (count == 1) {
		sp->ccp_irq = ret;
	} else {
		ret = platform_get_irq(pdev, 1);
		if (ret < 0) {
			dev_notice(dev, "unable to get IRQ (%d)\n", ret);
			return ret;
		}

		sp->ccp_irq = ret;
	}

	return 0;
}

__attribute__((used)) static int sp_platform_probe(struct platform_device *pdev)
{
	struct sp_device *sp;
	struct sp_platform *sp_platform;
	struct device *dev = &pdev->dev;
	enum dev_dma_attr attr;
	struct resource *ior;
	int ret;

	ret = -ENOMEM;
	sp = sp_alloc_struct(dev);
	if (!sp)
		goto e_err;

	sp_platform = devm_kzalloc(dev, sizeof(*sp_platform), GFP_KERNEL);
	if (!sp_platform)
		goto e_err;

	sp->dev_specific = sp_platform;
	sp->dev_vdata = pdev->dev.of_node ? sp_get_of_version(pdev)
					 : sp_get_acpi_version(pdev);
	if (!sp->dev_vdata) {
		ret = -ENODEV;
		dev_err(dev, "missing driver data\n");
		goto e_err;
	}

	ior = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	sp->io_map = devm_ioremap_resource(dev, ior);
	if (IS_ERR(sp->io_map)) {
		ret = PTR_ERR(sp->io_map);
		goto e_err;
	}

	attr = device_get_dma_attr(dev);
	if (attr == DEV_DMA_NOT_SUPPORTED) {
		dev_err(dev, "DMA is not supported");
		goto e_err;
	}

	sp_platform->coherent = (attr == DEV_DMA_COHERENT);
	if (sp_platform->coherent)
		sp->axcache = CACHE_WB_NO_ALLOC;
	else
		sp->axcache = CACHE_NONE;

	ret = dma_set_mask_and_coherent(dev, DMA_BIT_MASK(48));
	if (ret) {
		dev_err(dev, "dma_set_mask_and_coherent failed (%d)\n", ret);
		goto e_err;
	}

	ret = sp_get_irqs(sp);
	if (ret)
		goto e_err;

	dev_set_drvdata(dev, sp);

	ret = sp_init(sp);
	if (ret)
		goto e_err;

	dev_notice(dev, "enabled\n");

	return 0;

e_err:
	dev_notice(dev, "initialization failed\n");
	return ret;
}

__attribute__((used)) static int sp_platform_remove(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct sp_device *sp = dev_get_drvdata(dev);

	sp_destroy(sp);

	dev_notice(dev, "disabled\n");

	return 0;
}

int sp_platform_init(void)
{
	return platform_driver_register(&sp_platform_driver);
}

void sp_platform_exit(void)
{
	platform_driver_unregister(&sp_platform_driver);
}

