#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  wchar_t ;
typedef  int /*<<< orphan*/  ULONG ;
struct TYPE_3__ {int /*<<< orphan*/  HighPart; int /*<<< orphan*/  LowPart; } ;
typedef  int /*<<< orphan*/  NTSTATUS ;
typedef  TYPE_1__ LUID ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 scalar_t__ LookupPrivilegeValue (int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_1__*) ; 
 scalar_t__ NT_SUCCESS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PRINT_ERROR (char*,...) ; 
 int /*<<< orphan*/  PRINT_ERROR_AUTO (char*) ; 
 int /*<<< orphan*/  RtlAdjustPrivilege (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SE_BACKUP ; 
 int /*<<< orphan*/  SE_DEBUG ; 
 int /*<<< orphan*/  SE_LOAD_DRIVER ; 
 int /*<<< orphan*/  SE_RESTORE ; 
 int /*<<< orphan*/  SE_SECURITY ; 
 int /*<<< orphan*/  SE_SYSTEM_ENVIRONMENT ; 
 int /*<<< orphan*/  SE_TCB ; 
 int /*<<< orphan*/  STATUS_INVALID_PARAMETER ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  kprintf (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wcstoul (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

NTSTATUS kuhl_m_privilege_simple(ULONG privId)
{
	ULONG previousState;
	NTSTATUS status = RtlAdjustPrivilege(privId, TRUE, FALSE, &previousState);
	if(NT_SUCCESS(status))
		kprintf(L"Privilege \'%u\' OK\n", privId);
	else PRINT_ERROR(L"RtlAdjustPrivilege (%u) %08x\n", privId, status);
	return status;
}

NTSTATUS kuhl_m_privilege_id(int argc, wchar_t * argv[])
{
	NTSTATUS status = STATUS_INVALID_PARAMETER;
	if(argc)
		status = kuhl_m_privilege_simple(wcstoul(argv[0], NULL, 0));
	else PRINT_ERROR(L"Missing \'id\'\n");
	return status;
}

NTSTATUS kuhl_m_privilege_name(int argc, wchar_t * argv[])
{
	NTSTATUS status = STATUS_INVALID_PARAMETER;
	LUID luid;
	if(argc)
	{
		if(LookupPrivilegeValue(NULL, argv[0], &luid))
		{
			if(!luid.HighPart)
				status = kuhl_m_privilege_simple(luid.LowPart);
			else PRINT_ERROR(L"LUID high part is %u\n", luid.HighPart);
		}
		else PRINT_ERROR_AUTO(L"LookupPrivilegeValue");
	}
	else PRINT_ERROR(L"Missing \'name\'\n");
	return status;
}

NTSTATUS kuhl_m_privilege_debug(int argc, wchar_t * argv[])
{
	return kuhl_m_privilege_simple(SE_DEBUG);
}

NTSTATUS kuhl_m_privilege_driver(int argc, wchar_t * argv[])
{
	return kuhl_m_privilege_simple(SE_LOAD_DRIVER);
}

NTSTATUS kuhl_m_privilege_security(int argc, wchar_t * argv[])
{
	return kuhl_m_privilege_simple(SE_SECURITY);
}

NTSTATUS kuhl_m_privilege_tcb(int argc, wchar_t * argv[])
{
	return kuhl_m_privilege_simple(SE_TCB);
}

NTSTATUS kuhl_m_privilege_backup(int argc, wchar_t * argv[])
{
	return kuhl_m_privilege_simple(SE_BACKUP);
}

NTSTATUS kuhl_m_privilege_restore(int argc, wchar_t * argv[])
{
	return kuhl_m_privilege_simple(SE_RESTORE);
}

NTSTATUS kuhl_m_privilege_sysenv(int argc, wchar_t * argv[])
{
	return kuhl_m_privilege_simple(SE_SYSTEM_ENVIRONMENT);
}

