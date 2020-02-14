#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  TxSyncObj; int /*<<< orphan*/  TxLockObj; scalar_t__ TxPoolCnt; } ;
struct TYPE_4__ {TYPE_1__ FlowContCB; } ;

/* Variables and functions */
 scalar_t__ FLOW_CONT_MIN ; 
 int /*<<< orphan*/  OSI_RET_OK_CHECK (int /*<<< orphan*/ ) ; 
 TYPE_2__* g_pCB ; 
 int /*<<< orphan*/  sl_LockObjCreate (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  sl_LockObjDelete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sl_SyncObjCreate (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  sl_SyncObjDelete (int /*<<< orphan*/ *) ; 

void _SlDrvFlowContInit(void)
{
    g_pCB->FlowContCB.TxPoolCnt = FLOW_CONT_MIN;

    OSI_RET_OK_CHECK(sl_LockObjCreate(&g_pCB->FlowContCB.TxLockObj, "TxLockObj"));

    OSI_RET_OK_CHECK(sl_SyncObjCreate(&g_pCB->FlowContCB.TxSyncObj, "TxSyncObj"));
}

void _SlDrvFlowContDeinit(void)
{
    g_pCB->FlowContCB.TxPoolCnt = 0;

    OSI_RET_OK_CHECK(sl_LockObjDelete(&g_pCB->FlowContCB.TxLockObj));

    OSI_RET_OK_CHECK(sl_SyncObjDelete(&g_pCB->FlowContCB.TxSyncObj));
}

