#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ ULONG_PTR ;
typedef  scalar_t__ ULONG ;
struct TYPE_9__ {int /*<<< orphan*/  IsClient; } ;
struct TYPE_11__ {int MesVersion; TYPE_1__ StubMsg; } ;
struct TYPE_10__ {scalar_t__ ActualCount; scalar_t__ Offset; scalar_t__ MaxCount; } ;
typedef  TYPE_2__* PMIDL_STUB_MESSAGE ;
typedef  int /*<<< orphan*/  PFORMAT_STRING ;
typedef  TYPE_3__ MIDL_ES_MESSAGE ;

/* Variables and functions */
 int /*<<< orphan*/  ComputeConformanceOrVariance (TYPE_2__*,unsigned char*,int /*<<< orphan*/ ,scalar_t__,scalar_t__*) ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  memset (TYPE_3__*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline PFORMAT_STRING ComputeConformance(PMIDL_STUB_MESSAGE pStubMsg, unsigned char *pMemory, PFORMAT_STRING pFormat, ULONG def)
{
    return ComputeConformanceOrVariance(pStubMsg, pMemory, pFormat, def, &pStubMsg->MaxCount);
}

__attribute__((used)) static inline PFORMAT_STRING ComputeVariance(PMIDL_STUB_MESSAGE pStubMsg, unsigned char *pMemory, PFORMAT_STRING pFormat, ULONG def)
{
    PFORMAT_STRING ret;
    ULONG_PTR ActualCount = pStubMsg->ActualCount;

    pStubMsg->Offset = 0;
    ret = ComputeConformanceOrVariance(pStubMsg, pMemory, pFormat, def, &ActualCount);
    pStubMsg->ActualCount = (ULONG)ActualCount;
    return ret;
}

__attribute__((used)) static inline void init_MIDL_ES_MESSAGE(MIDL_ES_MESSAGE *pEsMsg)
{
    memset(pEsMsg, 0, sizeof(*pEsMsg));
    /* even if we are unmarshalling, as we don't want pointers to be pointed
     * to buffer memory */
    pEsMsg->StubMsg.IsClient = TRUE;
    pEsMsg->MesVersion = 1;
}

