#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  WCHAR ;
struct TYPE_13__ {int cVersion; } ;
struct TYPE_12__ {int cVersion; char* pDependentFiles; } ;
struct TYPE_11__ {TYPE_1__* pPrinter; } ;
struct TYPE_10__ {char* pwszPrinterDriver; } ;
typedef  TYPE_2__* PLOCAL_PRINTER_HANDLE ;
typedef  int* PDWORD ;
typedef  TYPE_3__* PDRIVER_INFO_3W ;
typedef  TYPE_4__* PDRIVER_INFO_2W ;
typedef  scalar_t__ PDRIVER_INFO_1W ;
typedef  char* PCWSTR ;
typedef  int /*<<< orphan*/  PBYTE ;
typedef  char* LPWSTR ;
typedef  size_t DWORD ;
typedef  int /*<<< orphan*/  DRIVER_INFO_3W ;
typedef  int /*<<< orphan*/  DRIVER_INFO_2W ;
typedef  int /*<<< orphan*/  DRIVER_INFO_1W ;

/* Variables and functions */
 int /*<<< orphan*/  PackStrings (char**,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 size_t _countof (char**) ; 
 int /*<<< orphan*/  dwDriverInfo1Offsets ; 
 int /*<<< orphan*/  dwDriverInfo2Offsets ; 
 int /*<<< orphan*/  dwDriverInfo3Offsets ; 
 int wcslen (char*) ; 
 char* wszCurrentEnvironment ; 

__attribute__((used)) static void
ToMultiSz(LPWSTR pString)
{
    while (*pString)
    {
        if (*pString == '|')
            *pString = '\0';
        pString++;
    }
}

__attribute__((used)) static void
_LocalGetPrinterDriverLevel1(PLOCAL_PRINTER_HANDLE pHandle, PDRIVER_INFO_1W* ppDriverInfo, PBYTE* ppDriverInfoEnd, PDWORD pcbNeeded)
{
    DWORD n;
    PCWSTR pwszStrings[1];

    /* This value is only here to send something, I have not verified if it is actually correct */
    pwszStrings[0] = pHandle->pPrinter->pwszPrinterDriver;

    // Calculate the string lengths.
    if (!ppDriverInfo)
    {
        for (n = 0; n < _countof(pwszStrings); ++n)
        {
            *pcbNeeded += (wcslen(pwszStrings[n]) + 1) * sizeof(WCHAR);
        }

        *pcbNeeded += sizeof(DRIVER_INFO_1W);
        return;
    }


    // Finally copy the structure and advance to the next one in the output buffer.
    *ppDriverInfoEnd = PackStrings(pwszStrings, (PBYTE)(*ppDriverInfo), dwDriverInfo1Offsets, *ppDriverInfoEnd);
    (*ppDriverInfo)++;
}

__attribute__((used)) static void
_LocalGetPrinterDriverLevel2(PLOCAL_PRINTER_HANDLE pHandle, PDRIVER_INFO_2W* ppDriverInfo, PBYTE* ppDriverInfoEnd, PDWORD pcbNeeded)
{
    DWORD n;
    PCWSTR pwszStrings[5];

    /* Clearly these things should not be hardcoded, so when it is needed, someone can add meaningfull values here */
    pwszStrings[0] = pHandle->pPrinter->pwszPrinterDriver;  // pName
    pwszStrings[1] = wszCurrentEnvironment;  // pEnvironment
    pwszStrings[2] = L"c:\\reactos\\system32\\localspl.dll";  // pDriverPath
    pwszStrings[3] = L"c:\\reactos\\system32\\localspl.dll";  // pDataFile
    pwszStrings[4] = L"c:\\reactos\\system32\\localspl.dll";  // pConfigFile

    // Calculate the string lengths.
    if (!ppDriverInfo)
    {
        for (n = 0; n < _countof(pwszStrings); ++n)
        {
            *pcbNeeded += (wcslen(pwszStrings[n]) + 1) * sizeof(WCHAR);
        }

        *pcbNeeded += sizeof(DRIVER_INFO_2W);
        return;
    }

    (*ppDriverInfo)->cVersion = 3;

    // Finally copy the structure and advance to the next one in the output buffer.
    *ppDriverInfoEnd = PackStrings(pwszStrings, (PBYTE)(*ppDriverInfo), dwDriverInfo2Offsets, *ppDriverInfoEnd);
    (*ppDriverInfo)++;
}

__attribute__((used)) static void
_LocalGetPrinterDriverLevel3(PLOCAL_PRINTER_HANDLE pHandle, PDRIVER_INFO_3W* ppDriverInfo, PBYTE* ppDriverInfoEnd, PDWORD pcbNeeded)
{
    DWORD n;
    PCWSTR pwszStrings[9];

    /* Clearly these things should not be hardcoded, so when it is needed, someone can add meaningfull values here */
    pwszStrings[0] = pHandle->pPrinter->pwszPrinterDriver;  // pName
    pwszStrings[1] = wszCurrentEnvironment;  // pEnvironment
    pwszStrings[2] = L"c:\\reactos\\system32\\localspl.dll";  // pDriverPath
    pwszStrings[3] = L"c:\\reactos\\system32\\localspl.dll";  // pDataFile
    pwszStrings[4] = L"c:\\reactos\\system32\\printui.dll";  // pConfigFile
    pwszStrings[5] = L"";  // pHelpFile
    pwszStrings[6] = L"localspl.dll|printui.dll|";  // pDependentFiles, | is separator and terminator!
    pwszStrings[7] = NULL;  // pMonitorName
    pwszStrings[8] = NULL;  // pDefaultDataType


    // Calculate the string lengths.
    if (!ppDriverInfo)
    {
        for (n = 0; n < _countof(pwszStrings); ++n)
        {
            if (pwszStrings[n])
            {
                *pcbNeeded += (wcslen(pwszStrings[n]) + 1) * sizeof(WCHAR);
            }
        }

        *pcbNeeded += sizeof(DRIVER_INFO_3W);
        return;
    }

    (*ppDriverInfo)->cVersion = 3;

    // Finally copy the structure and advance to the next one in the output buffer.
    *ppDriverInfoEnd = PackStrings(pwszStrings, (PBYTE)(*ppDriverInfo), dwDriverInfo3Offsets, *ppDriverInfoEnd);
    ToMultiSz((*ppDriverInfo)->pDependentFiles);
    (*ppDriverInfo)++;
}

