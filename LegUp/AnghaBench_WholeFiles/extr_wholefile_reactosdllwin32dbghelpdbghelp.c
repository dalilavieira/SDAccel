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
struct process {scalar_t__ handle; unsigned int buffer_size; void* buffer; struct process* next; } ;
struct cpu {scalar_t__ machine; } ;
struct TYPE_3__ {int Mode; int Offset; int /*<<< orphan*/  Segment; } ;
typedef  scalar_t__ HANDLE ;
typedef  int DWORD64 ;
typedef  scalar_t__ DWORD ;
typedef  int /*<<< orphan*/  BOOL ;
typedef  TYPE_1__ ADDRESS64 ;

/* Variables and functions */
#define  AddrMode1616 131 
#define  AddrMode1632 130 
#define  AddrModeFlat 129 
#define  AddrModeReal 128 
 int /*<<< orphan*/  ERROR_INVALID_HANDLE ; 
 int /*<<< orphan*/  ERROR_INVALID_PARAMETER ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  FIXME (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 void* HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int) ; 
 void* HeapReAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*,unsigned int) ; 
 int /*<<< orphan*/  SetLastError (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TRUE ; 
 struct cpu** dbghelp_cpus ; 
 struct process* process_first ; 
 char const* wine_dbg_sprintf (char*,int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  wine_dbgstr_longlong (int) ; 

struct process*    process_find_by_handle(HANDLE hProcess)
{
    struct process* p;

    for (p = process_first; p && p->handle != hProcess; p = p->next);
    if (!p) SetLastError(ERROR_INVALID_HANDLE);
    return p;
}

BOOL validate_addr64(DWORD64 addr)
{
    if (sizeof(void*) == sizeof(int) && (addr >> 32))
    {
        FIXME("Unsupported address %s\n", wine_dbgstr_longlong(addr));
        SetLastError(ERROR_INVALID_PARAMETER);
        return FALSE;
    }
    return TRUE;
}

void* fetch_buffer(struct process* pcs, unsigned size)
{
    if (size > pcs->buffer_size)
    {
        if (pcs->buffer)
            pcs->buffer = HeapReAlloc(GetProcessHeap(), 0, pcs->buffer, size);
        else
            pcs->buffer = HeapAlloc(GetProcessHeap(), 0, size);
        pcs->buffer_size = (pcs->buffer) ? size : 0;
    }
    return pcs->buffer;
}

const char* wine_dbgstr_addr(const ADDRESS64* addr)
{
    if (!addr) return "(null)";
    switch (addr->Mode)
    {
    case AddrModeFlat:
        return wine_dbg_sprintf("flat<%s>", wine_dbgstr_longlong(addr->Offset));
    case AddrMode1616:
        return wine_dbg_sprintf("1616<%04x:%04x>", addr->Segment, (DWORD)addr->Offset);
    case AddrMode1632:
        return wine_dbg_sprintf("1632<%04x:%08x>", addr->Segment, (DWORD)addr->Offset);
    case AddrModeReal:
        return wine_dbg_sprintf("real<%04x:%04x>", addr->Segment, (DWORD)addr->Offset);
    default:
        return "unknown";
    }
}

struct cpu* cpu_find(DWORD machine)
{
    struct cpu** cpu;

    for (cpu = dbghelp_cpus ; *cpu; cpu++)
    {
        if (cpu[0]->machine == machine) return cpu[0];
    }
    return NULL;
}

