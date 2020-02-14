#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_32__   TYPE_8__ ;
typedef  struct TYPE_31__   TYPE_7__ ;
typedef  struct TYPE_30__   TYPE_6__ ;
typedef  struct TYPE_29__   TYPE_5__ ;
typedef  struct TYPE_28__   TYPE_4__ ;
typedef  struct TYPE_27__   TYPE_3__ ;
typedef  struct TYPE_26__   TYPE_2__ ;
typedef  struct TYPE_25__   TYPE_20__ ;
typedef  struct TYPE_24__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  UNICODE_STRING ;
typedef  size_t ULONG_PTR ;
typedef  size_t ULONG ;
struct TYPE_31__ {size_t off1; scalar_t__ off2; scalar_t__ off3; int /*<<< orphan*/  off0; } ;
struct TYPE_24__ {int /*<<< orphan*/  Length; int /*<<< orphan*/  Pattern; } ;
struct TYPE_32__ {TYPE_7__ Offsets; TYPE_1__ Search; int /*<<< orphan*/  end; int /*<<< orphan*/  start; } ;
struct TYPE_30__ {scalar_t__ callback; } ;
struct TYPE_29__ {scalar_t__ Flink; } ;
struct TYPE_26__ {scalar_t__ Flink; } ;
struct TYPE_28__ {scalar_t__ PostOperation; scalar_t__ PreOperation; int /*<<< orphan*/  Handle; int /*<<< orphan*/  Operations; TYPE_2__ CallbackList; } ;
struct TYPE_27__ {scalar_t__ Object; struct TYPE_27__* ChainLink; } ;
struct TYPE_25__ {TYPE_3__** HashBuckets; } ;
typedef  int /*<<< orphan*/  SIZE_T ;
typedef  scalar_t__ PVOID ;
typedef  size_t* PULONG ;
typedef  scalar_t__ PUCHAR ;
typedef  TYPE_3__* POBJECT_DIRECTORY_ENTRY ;
typedef  TYPE_4__* POBJECT_CALLBACK_ENTRY ;
typedef  TYPE_5__* PLIST_ENTRY ;
typedef  TYPE_6__* PKKLL_M_NOTIFY_CALLBACK ;
typedef  TYPE_7__* PKKLL_M_MEMORY_OFFSETS ;
typedef  TYPE_8__* PKKLL_M_MEMORY_GENERIC ;
typedef  int /*<<< orphan*/  PKIWI_BUFFER ;
typedef  int /*<<< orphan*/  NTSTATUS ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAYSIZE (TYPE_8__*) ; 
 size_t CM_REG_MAX_CALLBACKS ; 
 scalar_t__* CallbackListHeadOrCmpCallBackVector ; 
 TYPE_8__* ImageReferences ; 
 scalar_t__ KIWI_mask3bits (scalar_t__) ; 
 scalar_t__ KiwiOsIndex ; 
 scalar_t__ KiwiOsIndex_VISTA ; 
 scalar_t__ MmGetSystemRoutineAddress (int /*<<< orphan*/ *) ; 
 scalar_t__ NT_SUCCESS (int /*<<< orphan*/ ) ; 
 size_t OBJECT_HASH_TABLE_SIZE ; 
 TYPE_8__* ObjectReferences ; 
 TYPE_20__** ObpTypeDirectoryObject ; 
 TYPE_8__* ProcessReferences ; 
 int /*<<< orphan*/  PspCreateProcessNotifyRoutine ; 
 size_t PspCreateProcessNotifyRoutineMax ; 
 int /*<<< orphan*/  PspCreateThreadNotifyRoutine ; 
 size_t PspCreateThreadNotifyRoutineMax ; 
 int /*<<< orphan*/  PspLoadImageNotifyRoutine ; 
 size_t PspLoadImageNotifyRoutineMax ; 
 TYPE_8__* RegReferences ; 
 int /*<<< orphan*/  RtlInitUnicodeString (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  STATUS_NOT_FOUND ; 
 int /*<<< orphan*/  STATUS_SUCCESS ; 
 TYPE_8__* ThreadReferences ; 
 int /*<<< orphan*/  kkll_m_memory_genericPointerSearch (scalar_t__*,scalar_t__,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_8__* kkll_m_memory_getGenericFromBuild (TYPE_8__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kkll_m_modules_fromAddr (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  kkll_m_notify_desc_object_callback (TYPE_4__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kkll_m_notify_search (TYPE_8__*,int /*<<< orphan*/ ,scalar_t__*,size_t*,TYPE_7__**) ; 
 int /*<<< orphan*/  kprintf (int /*<<< orphan*/ ,char*,...) ; 
 TYPE_7__* pCmpCallBackOffsets ; 
 TYPE_7__* pObpTypeDirectoryObjectOffsets ; 
 int /*<<< orphan*/ * procCallToName ; 

NTSTATUS kkll_m_notify_list(PKIWI_BUFFER outBuffer, PKKLL_M_MEMORY_GENERIC generics, SIZE_T cbGenerics, PUCHAR * ptr, PULONG pRoutineMax)
{
	NTSTATUS status = STATUS_SUCCESS;
	PKKLL_M_NOTIFY_CALLBACK pNotifyCallback;
	ULONG i;
	
	if(!*ptr)
		status = kkll_m_notify_search(generics, cbGenerics, ptr, pRoutineMax, NULL);

	if(*ptr)
	{
		for(i = 0; NT_SUCCESS(status) && (i < *pRoutineMax); i++)
		{
			if(pNotifyCallback = (PKKLL_M_NOTIFY_CALLBACK) KIWI_mask3bits(((PVOID *) *ptr)[i]))
			{
				status = kprintf(outBuffer, L"[%.2u] ", i);
				if(NT_SUCCESS(status))
					status = kkll_m_modules_fromAddr(outBuffer, pNotifyCallback->callback);
			}
		}
	}
	return status;
}

NTSTATUS kkll_m_notify_search(PKKLL_M_MEMORY_GENERIC generics, SIZE_T cbGenerics, PUCHAR * ptr, PULONG pRoutineMax, PKKLL_M_MEMORY_OFFSETS * pOffsets)
{
	NTSTATUS status = STATUS_NOT_FOUND;
	PKKLL_M_MEMORY_GENERIC pGeneric;
	UNICODE_STRING stringStart, stringEnd;
	PUCHAR start, end;
	
	if(pGeneric = kkll_m_memory_getGenericFromBuild(generics, cbGenerics))
	{
		RtlInitUnicodeString(&stringStart, pGeneric->start);
		RtlInitUnicodeString(&stringEnd, pGeneric->end);
		start = (PUCHAR) MmGetSystemRoutineAddress(&stringStart);
		end = (PUCHAR) MmGetSystemRoutineAddress(&stringEnd);

		if(start && end)
		{
			status = kkll_m_memory_genericPointerSearch(ptr, start, end, pGeneric->Search.Pattern, pGeneric->Search.Length, pGeneric->Offsets.off0);
			if(NT_SUCCESS(status))
			{
				if(pRoutineMax)
					*pRoutineMax = pGeneric->Offsets.off1;
				if(pOffsets)
					*pOffsets = &pGeneric->Offsets;
			}
		}
	}
	return status;
}

NTSTATUS kkll_m_notify_list_thread(PKIWI_BUFFER outBuffer)
{
	return kkll_m_notify_list(outBuffer, ThreadReferences, ARRAYSIZE(ThreadReferences), (PUCHAR *) &PspCreateThreadNotifyRoutine, &PspCreateThreadNotifyRoutineMax);
}

NTSTATUS kkll_m_notify_list_process(PKIWI_BUFFER outBuffer)
{
	return kkll_m_notify_list(outBuffer, ProcessReferences, ARRAYSIZE(ProcessReferences), (PUCHAR *) &PspCreateProcessNotifyRoutine, &PspCreateProcessNotifyRoutineMax);
}

NTSTATUS kkll_m_notify_list_image(PKIWI_BUFFER outBuffer)
{
	return kkll_m_notify_list(outBuffer, ImageReferences, ARRAYSIZE(ImageReferences), (PUCHAR *) &PspLoadImageNotifyRoutine, &PspLoadImageNotifyRoutineMax);
}

NTSTATUS kkll_m_notify_list_reg(PKIWI_BUFFER outBuffer)
{
	NTSTATUS status = STATUS_SUCCESS;
	PKKLL_M_NOTIFY_CALLBACK pNotifyCallback;
	PLIST_ENTRY pEntry;
	ULONG i;

	if(!CallbackListHeadOrCmpCallBackVector)
		status = kkll_m_notify_search(RegReferences, ARRAYSIZE(RegReferences), (PUCHAR *) &CallbackListHeadOrCmpCallBackVector, NULL, &pCmpCallBackOffsets);
	
	if(CallbackListHeadOrCmpCallBackVector)
	{
		if(KiwiOsIndex < KiwiOsIndex_VISTA)
		{
			for(i = 0; NT_SUCCESS(status) && (i < CM_REG_MAX_CALLBACKS); i++)
			{
				if(pNotifyCallback = (PKKLL_M_NOTIFY_CALLBACK) KIWI_mask3bits(CallbackListHeadOrCmpCallBackVector[i]))
				{
					status = kprintf(outBuffer, L"[%.2u] ", i);
					if(NT_SUCCESS(status))
						status = kkll_m_modules_fromAddr(outBuffer, pNotifyCallback->callback);
				}
			}
		}
		else
		{
			for(pEntry = (PLIST_ENTRY) *CallbackListHeadOrCmpCallBackVector, i = 0 ; NT_SUCCESS(status) && (pEntry != (PLIST_ENTRY) CallbackListHeadOrCmpCallBackVector); pEntry = (PLIST_ENTRY) (pEntry->Flink), i++)
			{
				status = kprintf(outBuffer, L"[%.2u] ", i);
				if(NT_SUCCESS(status))
					status = kkll_m_modules_fromAddr(outBuffer, *(PVOID *) ((ULONG_PTR) pEntry + pCmpCallBackOffsets->off1));
			}
		}
	}
	return status;
}

NTSTATUS kkll_m_notify_list_object(PKIWI_BUFFER outBuffer)
{
	NTSTATUS status = STATUS_SUCCESS;
	POBJECT_DIRECTORY_ENTRY pEntry;
	ULONG_PTR pType;
	POBJECT_CALLBACK_ENTRY pCallbackEntry;
	ULONG i, j;
	PVOID miniProc;

	if(!ObpTypeDirectoryObject)
		status = kkll_m_notify_search(ObjectReferences, ARRAYSIZE(ObjectReferences), (PUCHAR *) &ObpTypeDirectoryObject, NULL, &pObpTypeDirectoryObjectOffsets);
	
	if(ObpTypeDirectoryObject)
	{
		for(i = 0; NT_SUCCESS(status) && (i < OBJECT_HASH_TABLE_SIZE); i++)
		{
			for(pEntry = (*ObpTypeDirectoryObject)->HashBuckets[i]; NT_SUCCESS(status) && pEntry; pEntry = pEntry->ChainLink)
			{
				if(pType = (ULONG_PTR) pEntry->Object)
				{
					status = kprintf(outBuffer, L"\n * %wZ\n", pType + pObpTypeDirectoryObjectOffsets->off1);
					if(KiwiOsIndex >= KiwiOsIndex_VISTA)
					{
						for(pCallbackEntry = *(POBJECT_CALLBACK_ENTRY *) (pType + pObpTypeDirectoryObjectOffsets->off3) ; NT_SUCCESS(status) && (pCallbackEntry != (POBJECT_CALLBACK_ENTRY) (pType + pObpTypeDirectoryObjectOffsets->off3)) ; pCallbackEntry = (POBJECT_CALLBACK_ENTRY) pCallbackEntry->CallbackList.Flink)
							status = kkll_m_notify_desc_object_callback(pCallbackEntry, outBuffer);
					}
					for(j = 0; NT_SUCCESS(status) && (j < 8) ; j++)
					{
						if(miniProc = *(PVOID *) (pType + pObpTypeDirectoryObjectOffsets->off2 + (sizeof(PVOID) * j)))
						{
							status = kprintf(outBuffer, L"\t%s - ", procCallToName[j]);
							if(NT_SUCCESS(status))
								status = kkll_m_modules_fromAddr(outBuffer, miniProc);
						}
					}
				}
			}
		}
	}
	return status;
}

NTSTATUS kkll_m_notify_desc_object_callback(POBJECT_CALLBACK_ENTRY pCallbackEntry, PKIWI_BUFFER outBuffer)
{
	NTSTATUS status = STATUS_SUCCESS;
	if(pCallbackEntry->PreOperation || pCallbackEntry->PostOperation)
	{
		status = kprintf(outBuffer, L"\t* Callback [type %u] - Handle 0x%p (@ 0x%p)\n", pCallbackEntry->Operations, pCallbackEntry->Handle, pCallbackEntry);
		if(NT_SUCCESS(status) && pCallbackEntry->PreOperation)
		{
			status = kprintf(outBuffer, L"\t\tPreOperation  : ");
			if(NT_SUCCESS(status))
				status = kkll_m_modules_fromAddr(outBuffer, pCallbackEntry->PreOperation);
		}
		if(NT_SUCCESS(status) && pCallbackEntry->PostOperation)
		{
			status = kprintf(outBuffer, L"\t\tPostOperation : ");
			if(NT_SUCCESS(status))
				status = kkll_m_modules_fromAddr(outBuffer, pCallbackEntry->PostOperation);
		}
	}
	return status;
}

