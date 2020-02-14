#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  VOID ;
typedef  size_t ULONG ;
struct TYPE_11__ {int /*<<< orphan*/  Guid; } ;
struct TYPE_10__ {struct TYPE_10__* Next; } ;
typedef  TYPE_1__ SLIST_ENTRY ;
typedef  size_t* PULONG ;
typedef  TYPE_2__* PGUIDREGINFO ;
typedef  int /*<<< orphan*/  LPGUID ;
typedef  int /*<<< orphan*/  BOOLEAN ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 scalar_t__ IsEqualGUID (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  PAGED_CODE () ; 
 int /*<<< orphan*/  TRUE ; 

__attribute__((used)) static inline VOID SimpleInitSlistHdr(SLIST_ENTRY *SListHdr)
{
    SListHdr->Next = NULL;
}

__attribute__((used)) static inline VOID SimplePushSlist(SLIST_ENTRY *SListHdr, SLIST_ENTRY *SListEntry)
{
    SListEntry->Next = SListHdr->Next;
    SListHdr->Next = SListEntry;
}

__attribute__((used)) static inline SLIST_ENTRY *SimplePopSlist(SLIST_ENTRY *SListHdr)
{
    SLIST_ENTRY *sListEntry = SListHdr->Next;
    if (sListEntry){
        SListHdr->Next = sListEntry->Next;
        sListEntry->Next = NULL;
    }
    return sListEntry;
}

__attribute__((used)) static inline BOOLEAN SimpleIsSlistEmpty(SLIST_ENTRY *SListHdr)
{
    return (SListHdr->Next == NULL);
}

BOOLEAN
ClassFindGuid(
    PGUIDREGINFO GuidList,
    ULONG GuidCount,
    LPGUID Guid,
    PULONG GuidIndex
    )
{
    ULONG i;

    PAGED_CODE();

    for (i = 0; i < GuidCount; i++)
    {
        if (IsEqualGUID(Guid, &GuidList[i].Guid))
        {
            *GuidIndex = i;
            return(TRUE);
        }
    }

    return(FALSE);
}

