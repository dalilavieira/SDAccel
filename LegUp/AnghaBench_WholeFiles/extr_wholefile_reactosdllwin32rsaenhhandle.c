#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct handle_table_entry {scalar_t__ dwType; unsigned int iNextFree; int /*<<< orphan*/  (* destructor ) (struct handle_table_entry*) ;scalar_t__ refcount; struct handle_table_entry* pObject; } ;
struct TYPE_7__ {TYPE_1__* DebugInfo; } ;
struct handle_table {unsigned int iEntries; unsigned int iFirstFree; TYPE_2__ mutex; struct handle_table_entry* paEntries; } ;
struct TYPE_6__ {scalar_t__* Spare; } ;
typedef  struct handle_table_entry OBJECTHDR ;
typedef  struct handle_table_entry* HCRYPTKEY ;
typedef  scalar_t__ DWORD_PTR ;
typedef  scalar_t__ DWORD ;
typedef  int /*<<< orphan*/  (* DESTRUCTOR ) (struct handle_table_entry*) ;
typedef  void* BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  DeleteCriticalSection (TYPE_2__*) ; 
 int /*<<< orphan*/  EnterCriticalSection (TYPE_2__*) ; 
 void* FALSE ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 size_t HANDLE2INDEX (struct handle_table_entry*) ; 
 void* HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct handle_table_entry*) ; 
 struct handle_table_entry* INDEX2HANDLE (unsigned int) ; 
 scalar_t__ INVALID_HANDLE_VALUE ; 
 int /*<<< orphan*/  InitializeCriticalSection (TYPE_2__*) ; 
 scalar_t__ InterlockedDecrement (scalar_t__*) ; 
 int /*<<< orphan*/  InterlockedIncrement (scalar_t__*) ; 
 int /*<<< orphan*/  LeaveCriticalSection (TYPE_2__*) ; 
 unsigned int TABLE_SIZE_INCREMENT ; 
 int /*<<< orphan*/  TRACE (char*,...) ; 
 void* TRUE ; 
 int /*<<< orphan*/  memcpy (struct handle_table_entry*,struct handle_table_entry*,int) ; 
 int /*<<< orphan*/  stub1 (struct handle_table_entry*) ; 

void init_handle_table(struct handle_table *lpTable)
{
    TRACE("(lpTable=%p)\n", lpTable);
        
    lpTable->paEntries = NULL;
    lpTable->iEntries = 0;
    lpTable->iFirstFree = 0;
    InitializeCriticalSection(&lpTable->mutex);
    lpTable->mutex.DebugInfo->Spare[0] = (DWORD_PTR)(__FILE__ ": HANDLETABLE.mutex");
}

void destroy_handle_table(struct handle_table *lpTable)
{
    TRACE("(lpTable=%p)\n", lpTable);
        
    HeapFree(GetProcessHeap(), 0, lpTable->paEntries);
    lpTable->mutex.DebugInfo->Spare[0] = 0;
    DeleteCriticalSection(&lpTable->mutex);
}

BOOL is_valid_handle(struct handle_table *lpTable, HCRYPTKEY handle, DWORD dwType)
{
    unsigned int index = HANDLE2INDEX(handle);
    BOOL ret = FALSE;

    TRACE("(lpTable=%p, handle=%ld)\n", lpTable, handle);
    
    EnterCriticalSection(&lpTable->mutex);
        
    /* We don't use zero handle values */
    if (!handle) goto exit;
 
    /* Check for index out of table bounds */    
    if (index >= lpTable->iEntries) goto exit;
    
    /* Check if this handle is currently allocated */
    if (!lpTable->paEntries[index].pObject) goto exit;
    
    /* Check if this handle references an object of the correct type. */
    if (lpTable->paEntries[index].pObject->dwType != dwType) goto exit;

    ret = TRUE;
exit:
    LeaveCriticalSection(&lpTable->mutex);
    return ret;
}

__attribute__((used)) static BOOL grow_handle_table(struct handle_table *lpTable)
{
    struct handle_table_entry *newEntries;
    unsigned int i, newIEntries;

    newIEntries = lpTable->iEntries + TABLE_SIZE_INCREMENT;

    newEntries = HeapAlloc(GetProcessHeap(), 0, sizeof(struct handle_table_entry)*newIEntries);
    if (!newEntries)
        return FALSE;

    if (lpTable->paEntries)
    {
        memcpy(newEntries, lpTable->paEntries, sizeof(struct handle_table_entry)*lpTable->iEntries);
        HeapFree(GetProcessHeap(), 0, lpTable->paEntries);
    }

    for (i=lpTable->iEntries; i<newIEntries; i++)
    {
        newEntries[i].pObject = NULL;
        newEntries[i].iNextFree = i+1;
    }

    lpTable->paEntries = newEntries;
    lpTable->iEntries = newIEntries;

    return TRUE;
}

__attribute__((used)) static BOOL alloc_handle(struct handle_table *lpTable, OBJECTHDR *lpObject, HCRYPTKEY *lpHandle)
{
    BOOL ret = FALSE;

    TRACE("(lpTable=%p, lpObject=%p, lpHandle=%p)\n", lpTable, lpObject, lpHandle);
        
    EnterCriticalSection(&lpTable->mutex);
    if (lpTable->iFirstFree >= lpTable->iEntries) 
        if (!grow_handle_table(lpTable))
        {
            *lpHandle = (HCRYPTKEY)INVALID_HANDLE_VALUE;
            goto exit;
        }

    *lpHandle = INDEX2HANDLE(lpTable->iFirstFree);
    
    lpTable->paEntries[lpTable->iFirstFree].pObject = lpObject;
    lpTable->iFirstFree = lpTable->paEntries[lpTable->iFirstFree].iNextFree;
    InterlockedIncrement(&lpObject->refcount);

    ret = TRUE;
exit:
    LeaveCriticalSection(&lpTable->mutex);
    return ret;
}

BOOL release_handle(struct handle_table *lpTable, HCRYPTKEY handle, DWORD dwType)
{
    unsigned int index = HANDLE2INDEX(handle);
    OBJECTHDR *pObject;
    BOOL ret = FALSE;

    TRACE("(lpTable=%p, handle=%ld)\n", lpTable, handle);
    
    EnterCriticalSection(&lpTable->mutex);
    
    if (!is_valid_handle(lpTable, handle, dwType))
        goto exit;

    pObject = lpTable->paEntries[index].pObject;
    if (InterlockedDecrement(&pObject->refcount) == 0)
    {
        TRACE("destroying handle %ld\n", handle);
        if (pObject->destructor)
            pObject->destructor(pObject);
    }

    lpTable->paEntries[index].pObject = NULL;
    lpTable->paEntries[index].iNextFree = lpTable->iFirstFree;
    lpTable->iFirstFree = index;

    ret = TRUE;
exit:
    LeaveCriticalSection(&lpTable->mutex);
    return ret;
}

BOOL lookup_handle(struct handle_table *lpTable, HCRYPTKEY handle, DWORD dwType, OBJECTHDR **lplpObject)
{
    BOOL ret = FALSE;

    TRACE("(lpTable=%p, handle=%ld, lplpObject=%p)\n", lpTable, handle, lplpObject);
    
    EnterCriticalSection(&lpTable->mutex);
    if (!is_valid_handle(lpTable, handle, dwType)) 
    {
        *lplpObject = NULL;
        goto exit;
    }
    *lplpObject = lpTable->paEntries[HANDLE2INDEX(handle)].pObject;

    ret = TRUE;
exit:
    LeaveCriticalSection(&lpTable->mutex);
    return ret;
}

BOOL copy_handle(struct handle_table *lpTable, HCRYPTKEY handle, DWORD dwType, HCRYPTKEY *copy)
{
    OBJECTHDR *pObject;
    BOOL ret;

    TRACE("(lpTable=%p, handle=%ld, copy=%p)\n", lpTable, handle, copy);

    EnterCriticalSection(&lpTable->mutex);
    if (!lookup_handle(lpTable, handle, dwType, &pObject)) 
    {
        *copy = (HCRYPTKEY)INVALID_HANDLE_VALUE;
        LeaveCriticalSection(&lpTable->mutex);
        return FALSE;
    }

    ret = alloc_handle(lpTable, pObject, copy);
    LeaveCriticalSection(&lpTable->mutex);
    return ret;
}

HCRYPTKEY new_object(struct handle_table *lpTable, size_t cbSize, DWORD dwType, DESTRUCTOR destructor,
                        OBJECTHDR **ppObject)
{
    OBJECTHDR *pObject;
    HCRYPTKEY hObject;

    if (ppObject)
        *ppObject = NULL;

    pObject = HeapAlloc(GetProcessHeap(), 0, cbSize);
    if (!pObject)
        return (HCRYPTKEY)INVALID_HANDLE_VALUE;

    pObject->dwType = dwType;
    pObject->refcount = 0;
    pObject->destructor = destructor;

    if (!alloc_handle(lpTable, pObject, &hObject))
        HeapFree(GetProcessHeap(), 0, pObject);
    else
        if (ppObject)
            *ppObject = pObject;

    return hObject;
}

