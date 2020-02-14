#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  VOID ;
typedef  int /*<<< orphan*/  ULONG ;
struct TYPE_12__ {int cSlotsPerSection; int /*<<< orphan*/  slhLog; int /*<<< orphan*/  ulTag; } ;
struct TYPE_11__ {scalar_t__ cAllocCount; int /*<<< orphan*/ * pvBaseAddress; int /*<<< orphan*/  bitmap; int /*<<< orphan*/  aulBits; scalar_t__ ulCommitBitmap; } ;
typedef  int SIZE_T ;
typedef  int /*<<< orphan*/ * PVOID ;
typedef  TYPE_1__* PGDI_POOL_SECTION ;
typedef  TYPE_2__* PGDI_POOL ;
typedef  int /*<<< orphan*/  NTSTATUS ;
typedef  int /*<<< orphan*/  GDI_POOL_SECTION ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DBG_DUMP_EVENT_LIST (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DPRINT1 (char*,scalar_t__,TYPE_1__*,TYPE_2__*) ; 
 TYPE_1__* EngAllocMem (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  EngFreeMem (TYPE_1__*) ; 
 int /*<<< orphan*/  FALSE ; 
 int GDI_POOL_ALLOCATION_GRANULARITY ; 
 int /*<<< orphan*/  MEM_RELEASE ; 
 int /*<<< orphan*/  MEM_RESERVE ; 
 int /*<<< orphan*/  NT_SUCCESS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NtCurrentProcess () ; 
 int /*<<< orphan*/  PAGE_READWRITE ; 
 int /*<<< orphan*/  RtlClearAllBits (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  RtlInitializeBitMap (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ZwAllocateVirtualMemory (int /*<<< orphan*/ ,int /*<<< orphan*/ **,int /*<<< orphan*/ ,int*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ZwFreeVirtualMemory (int /*<<< orphan*/ ,int /*<<< orphan*/ **,int*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static
PGDI_POOL_SECTION
GdiPoolAllocateSection(PGDI_POOL pPool)
{
    PGDI_POOL_SECTION pSection;
    PVOID pvBaseAddress;
    SIZE_T cjSize;
    NTSTATUS status;

    /* Allocate a section object */
    cjSize = sizeof(GDI_POOL_SECTION) + pPool->cSlotsPerSection / sizeof(ULONG);
    pSection = EngAllocMem(0, cjSize, pPool->ulTag);
    if (!pSection)
    {
        return NULL;
    }

    /* Reserve user mode memory */
    cjSize = GDI_POOL_ALLOCATION_GRANULARITY;
    pvBaseAddress = NULL;
    status = ZwAllocateVirtualMemory(NtCurrentProcess(),
                                     &pvBaseAddress,
                                     0,
                                     &cjSize,
                                     MEM_RESERVE,
                                     PAGE_READWRITE);
    if (!NT_SUCCESS(status))
    {
        EngFreeMem(pSection);
        return NULL;
    }

    /* Initialize the section */
    pSection->pvBaseAddress = pvBaseAddress;
    pSection->ulCommitBitmap = 0;
    pSection->cAllocCount = 0;
    RtlInitializeBitMap(&pSection->bitmap,
                        pSection->aulBits,
                        pPool->cSlotsPerSection);
    RtlClearAllBits(&pSection->bitmap);

    /* Return the section */
    return pSection;
}

__attribute__((used)) static
VOID
GdiPoolDeleteSection(PGDI_POOL pPool, PGDI_POOL_SECTION pSection)
{
    NTSTATUS status;
    SIZE_T cjSize = 0;

    /* Should not have any allocations */
    if (pSection->cAllocCount != 0)
    {
        DPRINT1("There are %lu allocations left, section=%p, pool=%p\n",
                pSection->cAllocCount, pSection, pPool);
        DBG_DUMP_EVENT_LIST(&pPool->slhLog);
        ASSERT(FALSE);
    }

    /* Release the virtual memory */
    status = ZwFreeVirtualMemory(NtCurrentProcess(),
                                 &pSection->pvBaseAddress,
                                 &cjSize,
                                 MEM_RELEASE);
    ASSERT(NT_SUCCESS(status));

    /* Free the section object */
    EngFreeMem(pSection);
}

