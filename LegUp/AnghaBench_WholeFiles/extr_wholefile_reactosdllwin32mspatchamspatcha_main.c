#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  USHORT ;
typedef  int UINT ;
struct TYPE_7__ {scalar_t__ Ptr; scalar_t__ Root; scalar_t__ Size; } ;
typedef  void** PVOID ;
typedef  int /*<<< orphan*/ * PUSHORT ;
typedef  TYPE_1__* PSAFE_READ ;
typedef  int* PDWORD ;
typedef  void** PBYTE ;
typedef  int INT ;
typedef  scalar_t__ HANDLE ;
typedef  int DWORD ;
typedef  void* BYTE ;

/* Variables and functions */
 int /*<<< orphan*/  CloseHandle (scalar_t__) ; 
 scalar_t__ CreateFileMappingW (scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FILE_MAP_READ ; 
 int GetFileSize (scalar_t__,int /*<<< orphan*/ *) ; 
 scalar_t__ INVALID_HANDLE_VALUE ; 
 void** MapViewOfFile (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PAGE_READONLY ; 

BYTE ReadByte(PSAFE_READ pRead)
{
    if (pRead->Ptr + sizeof(BYTE) <= (pRead->Root + pRead->Size))
    {
        BYTE Value = *(PBYTE)pRead->Ptr;
        pRead->Ptr += sizeof(BYTE);
        return Value;
    }
    pRead->Ptr = pRead->Root + pRead->Size;
    return 0;
}

USHORT ReadUShort(PSAFE_READ pRead)
{
    if (pRead->Ptr + sizeof(USHORT) <= (pRead->Root + pRead->Size))
    {
        USHORT Value = *(PUSHORT)pRead->Ptr;
        pRead->Ptr += sizeof(USHORT);
        return Value;
    }
    pRead->Ptr = pRead->Root + pRead->Size;
    return 0;
}

DWORD ReadDWord(PSAFE_READ pRead)
{
    if (pRead->Ptr + sizeof(DWORD) <= (pRead->Root + pRead->Size))
    {
        DWORD Value = *(PDWORD)pRead->Ptr;
        pRead->Ptr += sizeof(DWORD);
        return Value;
    }
    pRead->Ptr = pRead->Root + pRead->Size;
    return 0;
}

DWORD DecodeDWord(PSAFE_READ pRead)
{
    UINT Result = 0, offset;

    for (offset = 0; offset < 32; offset += 7)
    {
        DWORD val = ReadByte(pRead);
        Result |= ((val & 0x7f) << offset);
        if (val & 0x80)
            break;
    }

    return Result;
}

INT DecodeInt(PSAFE_READ pRead)
{
    INT Result = 0, offset;

    for (offset = 0; offset < 32; offset += 6)
    {
        INT val = (INT)(DWORD)ReadByte(pRead);
        Result |= ((val & 0x3f) << offset);
        if (val & 0x80)
        {
            if (val & 0x40)
                Result *= -1;
            break;
        }
    }

    return Result;
}

__attribute__((used)) static PBYTE MapFile(HANDLE hFile, DWORD* dwSize)
{
    HANDLE hMap;
    PVOID pView;

    *dwSize = GetFileSize(hFile, NULL);
    hMap = CreateFileMappingW(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
    if (hMap != INVALID_HANDLE_VALUE)
    {
        pView = MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0);
        CloseHandle(hMap);
        return pView;
    }

    return NULL;
}

