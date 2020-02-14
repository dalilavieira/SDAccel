#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint64_t ;
typedef  int u32 ;
struct resource {scalar_t__ start; scalar_t__ end; } ;
struct mtd_info {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  cs; int /*<<< orphan*/  flash_mmio; } ;

/* Variables and functions */
 int /*<<< orphan*/  FLASH_CSADDR_MASK (int) ; 
 int /*<<< orphan*/  FLASH_CSBASE_ADDR (int) ; 
 int /*<<< orphan*/  FLASH_NAND_ALE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FLASH_NAND_CLE (int /*<<< orphan*/ ) ; 
 unsigned int NAND_ALE ; 
 unsigned int NAND_CLE ; 
 TYPE_1__ nand_priv ; 
 int nlm_read_reg (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nlm_write_reg (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void xlr_nand_ctrl(struct mtd_info *mtd, int cmd,
		unsigned int ctrl)
{
	if (ctrl & NAND_CLE)
		nlm_write_reg(nand_priv.flash_mmio,
			FLASH_NAND_CLE(nand_priv.cs), cmd);
	else if (ctrl & NAND_ALE)
		nlm_write_reg(nand_priv.flash_mmio,
			FLASH_NAND_ALE(nand_priv.cs), cmd);
}

__attribute__((used)) static void setup_flash_resource(uint64_t flash_mmio,
	uint64_t flash_map_base, int cs, struct resource *res)
{
	u32 base, mask;

	base = nlm_read_reg(flash_mmio, FLASH_CSBASE_ADDR(cs));
	mask = nlm_read_reg(flash_mmio, FLASH_CSADDR_MASK(cs));

	res->start = flash_map_base + ((unsigned long)base << 16);
	res->end = res->start + (mask + 1) * 64 * 1024;
}

