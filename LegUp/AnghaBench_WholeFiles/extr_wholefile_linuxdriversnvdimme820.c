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
struct resource {int /*<<< orphan*/  start; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct nvdimm_bus_descriptor {char* provider_name; int /*<<< orphan*/  module; int /*<<< orphan*/  attr_groups; } ;
struct nvdimm_bus {int dummy; } ;
struct nd_region_desc {int numa_node; int /*<<< orphan*/  flags; int /*<<< orphan*/  attr_groups; struct resource* res; } ;
typedef  int /*<<< orphan*/  resource_size_t ;
typedef  int /*<<< orphan*/  ndr_desc ;

/* Variables and functions */
 int ENXIO ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IORES_DESC_PERSISTENT_MEMORY_LEGACY ; 
 int /*<<< orphan*/  ND_REGION_PAGEMAP ; 
 int NUMA_NO_NODE ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 int /*<<< orphan*/  e820_pmem_attribute_groups ; 
 int /*<<< orphan*/  e820_pmem_region_attribute_groups ; 
 int /*<<< orphan*/  memset (struct nd_region_desc*,int /*<<< orphan*/ ,int) ; 
 struct nvdimm_bus* nvdimm_bus_register (struct device*,struct nvdimm_bus_descriptor*) ; 
 int /*<<< orphan*/  nvdimm_bus_unregister (struct nvdimm_bus*) ; 
 int /*<<< orphan*/  nvdimm_pmem_region_create (struct nvdimm_bus*,struct nd_region_desc*) ; 
 struct nvdimm_bus* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct nvdimm_bus*) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int walk_iomem_res_desc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,struct nvdimm_bus*,int (*) (struct resource*,void*)) ; 

__attribute__((used)) static int e820_pmem_remove(struct platform_device *pdev)
{
	struct nvdimm_bus *nvdimm_bus = platform_get_drvdata(pdev);

	nvdimm_bus_unregister(nvdimm_bus);
	return 0;
}

__attribute__((used)) static int e820_range_to_nid(resource_size_t addr)
{
	return NUMA_NO_NODE;
}

__attribute__((used)) static int e820_register_one(struct resource *res, void *data)
{
	struct nd_region_desc ndr_desc;
	struct nvdimm_bus *nvdimm_bus = data;

	memset(&ndr_desc, 0, sizeof(ndr_desc));
	ndr_desc.res = res;
	ndr_desc.attr_groups = e820_pmem_region_attribute_groups;
	ndr_desc.numa_node = e820_range_to_nid(res->start);
	set_bit(ND_REGION_PAGEMAP, &ndr_desc.flags);
	if (!nvdimm_pmem_region_create(nvdimm_bus, &ndr_desc))
		return -ENXIO;
	return 0;
}

__attribute__((used)) static int e820_pmem_probe(struct platform_device *pdev)
{
	static struct nvdimm_bus_descriptor nd_desc;
	struct device *dev = &pdev->dev;
	struct nvdimm_bus *nvdimm_bus;
	int rc = -ENXIO;

	nd_desc.attr_groups = e820_pmem_attribute_groups;
	nd_desc.provider_name = "e820";
	nd_desc.module = THIS_MODULE;
	nvdimm_bus = nvdimm_bus_register(dev, &nd_desc);
	if (!nvdimm_bus)
		goto err;
	platform_set_drvdata(pdev, nvdimm_bus);

	rc = walk_iomem_res_desc(IORES_DESC_PERSISTENT_MEMORY_LEGACY,
			IORESOURCE_MEM, 0, -1, nvdimm_bus, e820_register_one);
	if (rc)
		goto err;
	return 0;
err:
	nvdimm_bus_unregister(nvdimm_bus);
	dev_err(dev, "failed to register legacy persistent memory ranges\n");
	return rc;
}

