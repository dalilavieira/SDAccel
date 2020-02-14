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
struct mtd_info {int dummy; } ;
struct map_info {int dummy; } ;
struct cfi_private {scalar_t__ mfr; scalar_t__ id; } ;
struct cfi_early_fixup {scalar_t__ mfr; scalar_t__ id; int /*<<< orphan*/  (* fixup ) (struct cfi_private*) ;} ;

/* Variables and functions */
 scalar_t__ CFI_ID_ANY ; 
 scalar_t__ CFI_MFR_ANY ; 
 int /*<<< orphan*/  cfi_chip_probe ; 
 struct mtd_info* mtd_do_chip_probe (struct map_info*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (struct cfi_private*) ; 

__attribute__((used)) static void cfi_early_fixup(struct cfi_private *cfi,
			    const struct cfi_early_fixup *fixups)
{
	const struct cfi_early_fixup *f;

	for (f = fixups; f->fixup; f++) {
		if (((f->mfr == CFI_MFR_ANY) || (f->mfr == cfi->mfr)) &&
		    ((f->id == CFI_ID_ANY) || (f->id == cfi->id))) {
			f->fixup(cfi);
		}
	}
}

struct mtd_info *cfi_probe(struct map_info *map)
{
	/*
	 * Just use the generic probe stuff to call our CFI-specific
	 * chip_probe routine in all the possible permutations, etc.
	 */
	return mtd_do_chip_probe(map, &cfi_chip_probe);
}

