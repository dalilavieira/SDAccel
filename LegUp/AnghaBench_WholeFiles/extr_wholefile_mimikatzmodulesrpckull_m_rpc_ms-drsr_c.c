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
typedef  int /*<<< orphan*/  handle_t ;
typedef  int /*<<< orphan*/  ULONG ;
typedef  int /*<<< orphan*/  DWORD ;
typedef  int /*<<< orphan*/  DRS_MSG_REPDEL ;
typedef  int /*<<< orphan*/  DRS_MSG_REPADD ;
typedef  int /*<<< orphan*/  DRS_MSG_DCINFOREQ ;
typedef  int /*<<< orphan*/  DRS_MSG_DCINFOREPLY ;
typedef  int /*<<< orphan*/  DRS_MSG_CRACKREQ ;
typedef  int /*<<< orphan*/  DRS_MSG_CRACKREPLY ;
typedef  int /*<<< orphan*/  DRS_MSG_ADDENTRYREQ ;
typedef  int /*<<< orphan*/  DRS_MSG_ADDENTRYREPLY ;
typedef  int /*<<< orphan*/  DRS_HANDLE ;

/* Variables and functions */
 int /*<<< orphan*/  STATUS_NOT_IMPLEMENTED ; 

void SRV_OpnumNotImplemented(handle_t IDL_handle)
{
}

ULONG SRV_IDL_DRSReplicaAddNotImplemented(DRS_HANDLE hDrs, DWORD dwVersion, DRS_MSG_REPADD *pmsgAdd)
{
	return STATUS_NOT_IMPLEMENTED;
}

ULONG SRV_IDL_DRSReplicaDelNotImplemented(DRS_HANDLE hDrs, DWORD dwVersion, DRS_MSG_REPDEL *pmsgDel)
{
	return STATUS_NOT_IMPLEMENTED;
}

ULONG SRV_IDL_DRSCrackNamesNotImplemented(DRS_HANDLE hDrs, DWORD dwInVersion, DRS_MSG_CRACKREQ *pmsgIn, DWORD *pdwOutVersion, DRS_MSG_CRACKREPLY *pmsgOut)
{
	return STATUS_NOT_IMPLEMENTED;
}

ULONG SRV_IDL_DRSDomainControllerInfoNotImplemented(DRS_HANDLE hDrs, DWORD dwInVersion, DRS_MSG_DCINFOREQ *pmsgIn, DWORD *pdwOutVersion, DRS_MSG_DCINFOREPLY *pmsgOut)
{
	return STATUS_NOT_IMPLEMENTED;
}

ULONG SRV_IDL_DRSAddEntryNotImplemented(DRS_HANDLE hDrs, DWORD dwInVersion, DRS_MSG_ADDENTRYREQ *pmsgIn, DWORD *pdwOutVersion, DRS_MSG_ADDENTRYREPLY *pmsgOut)
{
	return STATUS_NOT_IMPLEMENTED;
}

