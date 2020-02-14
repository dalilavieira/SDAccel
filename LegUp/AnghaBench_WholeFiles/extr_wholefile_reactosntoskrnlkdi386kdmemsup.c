#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  VOID ;
typedef  int ULONG_PTR ;
typedef  int /*<<< orphan*/  ULONGLONG ;
struct TYPE_6__ {int PageFrameNumber; } ;
struct TYPE_7__ {int Long; TYPE_1__ Hard; } ;
struct TYPE_8__ {TYPE_2__ u; } ;
typedef  int /*<<< orphan*/  PVOID ;
typedef  int /*<<< orphan*/ * PUSHORT ;
typedef  int /*<<< orphan*/ * PULONGLONG ;
typedef  int /*<<< orphan*/ * PULONG ;
typedef  int /*<<< orphan*/ * PUCHAR ;
typedef  TYPE_3__* PMMPTE ;
typedef  TYPE_3__ MMPTE ;
typedef  int LONG ;

/* Variables and functions */
 int /*<<< orphan*/  KeInvalidateTlbEntry (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MI_KDBG_TMP_PAGE_0 ; 
 int /*<<< orphan*/  MI_KDBG_TMP_PAGE_1 ; 
 TYPE_3__* MiAddressToPte (int /*<<< orphan*/ ) ; 
 int PAGE_SHIFT ; 
 int PAGE_SIZE ; 
 int PDE_ACCESSED_BIT ; 
 int PDE_DIRTY_BIT ; 
 int PDE_PCD_BIT ; 
 int PDE_PRESENT_BIT ; 
 int PDE_PWT_BIT ; 
 int PDE_W_BIT ; 

__attribute__((used)) static
ULONG_PTR
KdpPhysMap(ULONG_PTR PhysAddr, LONG Len)
{
    MMPTE TempPte;
    PMMPTE PointerPte;
    ULONG_PTR VirtAddr;

    TempPte.u.Long = PDE_PRESENT_BIT | PDE_W_BIT | PDE_PWT_BIT |
                     PDE_PCD_BIT | PDE_ACCESSED_BIT | PDE_DIRTY_BIT;

    if ((PhysAddr & (PAGE_SIZE - 1)) + Len > PAGE_SIZE)
    {
        TempPte.u.Hard.PageFrameNumber = (PhysAddr >> PAGE_SHIFT) + 1;
        PointerPte = MiAddressToPte(MI_KDBG_TMP_PAGE_1);
        *PointerPte = TempPte;
        VirtAddr = (ULONG_PTR)PointerPte << 10;
        KeInvalidateTlbEntry((PVOID)VirtAddr);
    }

    TempPte.u.Hard.PageFrameNumber = PhysAddr >> PAGE_SHIFT;
    PointerPte = MiAddressToPte(MI_KDBG_TMP_PAGE_0);
    *PointerPte = TempPte;
    VirtAddr = (ULONG_PTR)PointerPte << 10;
    KeInvalidateTlbEntry((PVOID)VirtAddr);

    return VirtAddr + (PhysAddr & (PAGE_SIZE - 1));
}

__attribute__((used)) static
ULONGLONG
KdpPhysRead(ULONG_PTR PhysAddr, LONG Len)
{
    ULONG_PTR Addr;
    ULONGLONG Result = 0;

    Addr = KdpPhysMap(PhysAddr, Len);

    switch (Len)
    {
    case 8:
        Result = *((PULONGLONG)Addr);
        break;
    case 4:
        Result = *((PULONG)Addr);
        break;
    case 2:
        Result = *((PUSHORT)Addr);
        break;
    case 1:
        Result = *((PUCHAR)Addr);
        break;
    }

    return Result;
}

__attribute__((used)) static
VOID
KdpPhysWrite(ULONG_PTR PhysAddr, LONG Len, ULONGLONG Value)
{
    ULONG_PTR Addr;

    Addr = KdpPhysMap(PhysAddr, Len);

    switch (Len)
    {
    case 8:
        *((PULONGLONG)Addr) = Value;
        break;
    case 4:
        *((PULONG)Addr) = Value;
        break;
    case 2:
        *((PUSHORT)Addr) = Value;
        break;
    case 1:
        *((PUCHAR)Addr) = Value;
        break;
    }
}

