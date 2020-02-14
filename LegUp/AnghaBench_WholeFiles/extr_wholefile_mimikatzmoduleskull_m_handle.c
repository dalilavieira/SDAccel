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
typedef  int /*<<< orphan*/  UNICODE_STRING ;
typedef  size_t ULONG ;
struct TYPE_12__ {size_t HandleCount; int /*<<< orphan*/ * Handles; } ;
struct TYPE_11__ {int /*<<< orphan*/ * type; struct TYPE_11__* member_4; int /*<<< orphan*/  member_3; int /*<<< orphan*/  member_2; int /*<<< orphan*/  member_1; int /*<<< orphan*/ * member_0; } ;
typedef  TYPE_1__* PVOID ;
typedef  TYPE_2__* PSYSTEM_HANDLE_INFORMATION ;
typedef  scalar_t__ (* PKULL_M_SYSTEM_HANDLE_ENUM_CALLBACK ) (int /*<<< orphan*/ *,TYPE_1__*) ;
typedef  int /*<<< orphan*/  PKULL_M_HANDLE_ENUM_CALLBACK ;
typedef  int /*<<< orphan*/  NTSTATUS ;
typedef  int /*<<< orphan*/  LPCTSTR ;
typedef  TYPE_1__ HANDLE_ENUM_DATA ;
typedef  int /*<<< orphan*/  DWORD ;

/* Variables and functions */
 int /*<<< orphan*/  LocalFree (TYPE_2__*) ; 
 scalar_t__ NT_SUCCESS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RtlInitUnicodeString (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SystemHandleInformation ; 
 scalar_t__ kull_m_handle_getHandlesOfType_callback (int /*<<< orphan*/ *,TYPE_1__*) ; 
 int /*<<< orphan*/  kull_m_process_NtQuerySystemInformation (int /*<<< orphan*/ ,TYPE_2__**,int /*<<< orphan*/ ) ; 

NTSTATUS kull_m_handle_getHandles(PKULL_M_SYSTEM_HANDLE_ENUM_CALLBACK callBack, PVOID pvArg)
{
	NTSTATUS status;
	ULONG i;
	PSYSTEM_HANDLE_INFORMATION buffer = NULL;

	status = kull_m_process_NtQuerySystemInformation(SystemHandleInformation, &buffer, 0);
	if(NT_SUCCESS(status))
	{
		for(i = 0; (i < buffer->HandleCount) && callBack(&buffer->Handles[i], pvArg); i++);
		LocalFree(buffer);
	}
	return status;
}

NTSTATUS kull_m_handle_getHandlesOfType(PKULL_M_HANDLE_ENUM_CALLBACK callBack, LPCTSTR type, DWORD dwDesiredAccess, DWORD dwOptions, PVOID pvArg)
{
	UNICODE_STRING uStr;
	HANDLE_ENUM_DATA data = {NULL, dwDesiredAccess, dwOptions, callBack, pvArg};
	if(type)
	{
		RtlInitUnicodeString(&uStr, type);
		data.type = &uStr;
	}
	return kull_m_handle_getHandles(kull_m_handle_getHandlesOfType_callback, &data);
}

