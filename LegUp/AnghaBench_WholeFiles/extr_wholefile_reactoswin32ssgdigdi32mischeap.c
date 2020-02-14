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
typedef  int /*<<< orphan*/  WCHAR ;
typedef  int /*<<< orphan*/  VOID ;
typedef  int ULONG ;
typedef  int* PVOID ;
typedef  int /*<<< orphan*/  PCHAR ;
typedef  int /*<<< orphan*/  NTSTATUS ;
typedef  int* LPWSTR ;
typedef  int /*<<< orphan*/  LPVOID ;
typedef  scalar_t__ LPCSTR ;
typedef  int DWORD ;

/* Variables and functions */
 int* RtlAllocateHeap (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  RtlFreeHeap (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RtlMultiByteToUnicodeN (int*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  STATUS_NO_MEMORY ; 
 int /*<<< orphan*/  STATUS_SUCCESS ; 
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hProcessHeap ; 
 int lstrlenA (scalar_t__) ; 

PVOID
HEAP_alloc ( DWORD len )
{
    /* make sure hProcessHeap gets initialized by GdiProcessSetup before we get here */
    assert(hProcessHeap);
    return RtlAllocateHeap ( hProcessHeap, 0, len );
}

NTSTATUS
HEAP_strdupA2W ( LPWSTR* ppszW, LPCSTR lpszA )
{
    ULONG len;
    NTSTATUS Status;

    *ppszW = NULL;
    if ( !lpszA )
        return STATUS_SUCCESS;
    len = lstrlenA(lpszA);

    *ppszW = HEAP_alloc ( (len+1) * sizeof(WCHAR) );
    if ( !*ppszW )
        return STATUS_NO_MEMORY;
    Status = RtlMultiByteToUnicodeN ( *ppszW, len*sizeof(WCHAR), NULL, (PCHAR)lpszA, len );
    (*ppszW)[len] = L'\0';
    return Status;
}

VOID
HEAP_free ( LPVOID memory )
{
    /* make sure hProcessHeap gets initialized by GdiProcessSetup before we get here */
    assert(hProcessHeap);

    RtlFreeHeap ( hProcessHeap, 0, memory );
}

