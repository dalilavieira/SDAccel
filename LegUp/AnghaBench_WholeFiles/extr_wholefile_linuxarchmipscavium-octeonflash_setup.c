#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {int base; scalar_t__ width; scalar_t__ en; } ;
union cvmx_mio_boot_reg_cfgx {TYPE_2__ s; int /*<<< orphan*/  u64; } ;
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_8__ {struct device_node* of_node; } ;
struct platform_device {TYPE_1__ dev; } ;
struct map_info {int dummy; } ;
struct device_node {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;
typedef  int /*<<< orphan*/  map_word ;
struct TYPE_11__ {char* name; int phys; int size; void (* write ) (struct map_info*,int /*<<< orphan*/  const,unsigned long) ;void (* copy_from ) (struct map_info*,void*,unsigned long,int /*<<< orphan*/ ) ;void (* copy_to ) (struct map_info*,unsigned long,void const*,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* read ) (struct map_info*,unsigned long) ;scalar_t__ bankwidth; int /*<<< orphan*/  virt; } ;
struct TYPE_10__ {int /*<<< orphan*/  owner; } ;

/* Variables and functions */
 int /*<<< orphan*/  CVMX_MIO_BOOT_REG_CFGX (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  cvmx_read_csr (int /*<<< orphan*/ ) ; 
 TYPE_3__* do_map_probe (char*,TYPE_5__*) ; 
 int /*<<< orphan*/  down (int /*<<< orphan*/ *) ; 
 TYPE_5__ flash_map ; 
 int /*<<< orphan*/  inline_map_copy_from (struct map_info*,void*,unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  inline_map_copy_to (struct map_info*,unsigned long,void const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  inline_map_read (struct map_info*,unsigned long) ; 
 int /*<<< orphan*/  inline_map_write (struct map_info*,int /*<<< orphan*/  const,unsigned long) ; 
 int /*<<< orphan*/  ioremap (int,int) ; 
 int /*<<< orphan*/  map_bankwidth_supported (scalar_t__) ; 
 int /*<<< orphan*/  mtd_device_parse_register (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 TYPE_3__* mymtd ; 
 int /*<<< orphan*/  octeon_bootbus_sem ; 
 int /*<<< orphan*/  of_flash_driver ; 
 int of_property_read_u32 (struct device_node*,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  part_probe_types ; 
 int platform_driver_register (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  pr_notice (char*,int,int) ; 
 int /*<<< orphan*/  up (int /*<<< orphan*/ *) ; 

__attribute__((used)) static map_word octeon_flash_map_read(struct map_info *map, unsigned long ofs)
{
	map_word r;

	down(&octeon_bootbus_sem);
	r = inline_map_read(map, ofs);
	up(&octeon_bootbus_sem);

	return r;
}

__attribute__((used)) static void octeon_flash_map_write(struct map_info *map, const map_word datum,
				   unsigned long ofs)
{
	down(&octeon_bootbus_sem);
	inline_map_write(map, datum, ofs);
	up(&octeon_bootbus_sem);
}

__attribute__((used)) static void octeon_flash_map_copy_from(struct map_info *map, void *to,
				       unsigned long from, ssize_t len)
{
	down(&octeon_bootbus_sem);
	inline_map_copy_from(map, to, from, len);
	up(&octeon_bootbus_sem);
}

__attribute__((used)) static void octeon_flash_map_copy_to(struct map_info *map, unsigned long to,
				     const void *from, ssize_t len)
{
	down(&octeon_bootbus_sem);
	inline_map_copy_to(map, to, from, len);
	up(&octeon_bootbus_sem);
}

__attribute__((used)) static int octeon_flash_probe(struct platform_device *pdev)
{
	union cvmx_mio_boot_reg_cfgx region_cfg;
	u32 cs;
	int r;
	struct device_node *np = pdev->dev.of_node;

	r = of_property_read_u32(np, "reg", &cs);
	if (r)
		return r;

	/*
	 * Read the bootbus region 0 setup to determine the base
	 * address of the flash.
	 */
	region_cfg.u64 = cvmx_read_csr(CVMX_MIO_BOOT_REG_CFGX(cs));
	if (region_cfg.s.en) {
		/*
		 * The bootloader always takes the flash and sets its
		 * address so the entire flash fits below
		 * 0x1fc00000. This way the flash aliases to
		 * 0x1fc00000 for booting. Software can access the
		 * full flash at the true address, while core boot can
		 * access 4MB.
		 */
		/* Use this name so old part lines work */
		flash_map.name = "phys_mapped_flash";
		flash_map.phys = region_cfg.s.base << 16;
		flash_map.size = 0x1fc00000 - flash_map.phys;
		/* 8-bit bus (0 + 1) or 16-bit bus (1 + 1) */
		flash_map.bankwidth = region_cfg.s.width + 1;
		flash_map.virt = ioremap(flash_map.phys, flash_map.size);
		pr_notice("Bootbus flash: Setting flash for %luMB flash at "
			  "0x%08llx\n", flash_map.size >> 20, flash_map.phys);
		WARN_ON(!map_bankwidth_supported(flash_map.bankwidth));
		flash_map.read = octeon_flash_map_read;
		flash_map.write = octeon_flash_map_write;
		flash_map.copy_from = octeon_flash_map_copy_from;
		flash_map.copy_to = octeon_flash_map_copy_to;
		mymtd = do_map_probe("cfi_probe", &flash_map);
		if (mymtd) {
			mymtd->owner = THIS_MODULE;
			mtd_device_parse_register(mymtd, part_probe_types,
						  NULL, NULL, 0);
		} else {
			pr_err("Failed to register MTD device for flash\n");
		}
	}
	return 0;
}

__attribute__((used)) static int octeon_flash_init(void)
{
	return platform_driver_register(&of_flash_driver);
}

