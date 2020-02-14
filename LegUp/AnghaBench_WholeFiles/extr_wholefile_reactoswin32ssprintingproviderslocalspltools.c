#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {scalar_t__ dmDriverExtra; scalar_t__ dmSize; } ;
typedef  int /*<<< orphan*/ * PWSTR ;
typedef  TYPE_1__* PDEVMODEW ;
typedef  int /*<<< orphan*/  PCWSTR ;
typedef  int /*<<< orphan*/ * PBYTE ;
typedef  scalar_t__ LONG ;
typedef  int /*<<< orphan*/  HKEY ;
typedef  scalar_t__ DWORD ;

/* Variables and functions */
 int /*<<< orphan*/  CopyMemory (TYPE_1__*,TYPE_1__*,scalar_t__) ; 
 void* DllAllocSplMem (scalar_t__) ; 
 int /*<<< orphan*/  DllFreeSplMem (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ERR (char*,...) ; 
 scalar_t__ ERROR_SUCCESS ; 
 scalar_t__ RegQueryValueExW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,scalar_t__*) ; 

PWSTR
AllocAndRegQueryWSZ(HKEY hKey, PCWSTR pwszValueName)
{
    DWORD cbNeeded;
    LONG lStatus;
    PWSTR pwszValue;

    // Determine the size of the required buffer.
    lStatus = RegQueryValueExW(hKey, pwszValueName, NULL, NULL, NULL, &cbNeeded);
    if (lStatus != ERROR_SUCCESS)
    {
        ERR("RegQueryValueExW failed with status %ld!\n", lStatus);
        return NULL;
    }

    // Allocate it.
    pwszValue = DllAllocSplMem(cbNeeded);
    if (!pwszValue)
    {
        ERR("DllAllocSplMem failed!\n");
        return NULL;
    }

    // Now get the actual value.
    lStatus = RegQueryValueExW(hKey, pwszValueName, NULL, NULL, (PBYTE)pwszValue, &cbNeeded);
    if (lStatus != ERROR_SUCCESS)
    {
        ERR("RegQueryValueExW failed with status %ld!\n", lStatus);
        DllFreeSplMem(pwszValue);
        return NULL;
    }

    return pwszValue;
}

PDEVMODEW
DuplicateDevMode(PDEVMODEW pInput)
{
    PDEVMODEW pOutput;

    // Allocate a buffer for this DevMode.
    pOutput = DllAllocSplMem(pInput->dmSize + pInput->dmDriverExtra);
    if (!pOutput)
    {
        ERR("DllAllocSplMem failed!\n");
        return NULL;
    }

    // Copy it.
    CopyMemory(pOutput, pInput, pInput->dmSize + pInput->dmDriverExtra);

    return pOutput;
}

