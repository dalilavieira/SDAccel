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
typedef  scalar_t__ uint64_t ;
typedef  int /*<<< orphan*/  uint32_t ;

/* Variables and functions */
#define  BITMAP_AREA 133 
 scalar_t__* BootPTD ; 
#define  COPY_PAGE_AREA 132 
#define  DEST_COPY_AREA 131 
 scalar_t__ I386_LPGBYTES ; 
 scalar_t__ I386_LPGMASK ; 
 uintptr_t I386_LPGSHIFT ; 
#define  IMAGE2_AREA 130 
#define  IMAGE_AREA 129 
 scalar_t__ INTEL_PTE_PS ; 
 scalar_t__ INTEL_PTE_VALID ; 
 scalar_t__ INTEL_PTE_WRITE ; 
#define  SRC_COPY_AREA 128 
 int /*<<< orphan*/  __nosan_memcpy (scalar_t__*,scalar_t__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  invlpg (uintptr_t) ; 
 uintptr_t pal_hib_map (uintptr_t,scalar_t__) ; 

uintptr_t 
hibernate_restore_phys_page(uint64_t src, uint64_t dst, uint32_t len, uint32_t procFlags)
{
	(void)procFlags;
	uint64_t * d;
	uint64_t * s;

	if (src == 0)
		return (uintptr_t)dst;

	d = (uint64_t *)pal_hib_map(DEST_COPY_AREA, dst);
	s = (uint64_t *) (uintptr_t)src;

	__nosan_memcpy(d, s, len);

	return (uintptr_t)d;
}

uintptr_t
pal_hib_map(uintptr_t virt, uint64_t phys)
{
    uintptr_t index;

    switch (virt)
    {
	case DEST_COPY_AREA:
	case SRC_COPY_AREA:
	case COPY_PAGE_AREA:
	case BITMAP_AREA:
	case IMAGE_AREA:
	case IMAGE2_AREA:
	    break;

	default:
	    asm("cli;hlt;");
	    break;
    }
    if (phys < IMAGE2_AREA)
    {
    	// first 4Gb is all mapped,
	// and do not expect source areas to cross 4Gb
        return (phys);
    }
    index = (virt >> I386_LPGSHIFT);
    virt += (uintptr_t)(phys & I386_LPGMASK);
    phys  = ((phys & ~((uint64_t)I386_LPGMASK)) | INTEL_PTE_PS  | INTEL_PTE_VALID | INTEL_PTE_WRITE);
    if (phys == BootPTD[index]) return (virt);
    BootPTD[index] = phys;
    invlpg(virt);
    BootPTD[index + 1] = (phys + I386_LPGBYTES);
    invlpg(virt + I386_LPGBYTES);

    return (virt);
}

void hibernateRestorePALState(uint32_t *arg)
{
    (void)arg;
}

void
pal_hib_patchup(void)
{
}

