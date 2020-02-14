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
typedef  int /*<<< orphan*/  WINSPOOL_PRINTER_HANDLE ;
typedef  char WCHAR ;
typedef  scalar_t__ DWORD ;
typedef  int /*<<< orphan*/  BYTE ;

/* Variables and functions */
 int /*<<< orphan*/  ERR (char*,scalar_t__) ; 
 scalar_t__ ERROR_INVALID_FUNCTION ; 
 scalar_t__ ERROR_SUCCESS ; 
 scalar_t__ GetPrinterDataExW (int /*<<< orphan*/ ,char const*,char const*,scalar_t__*,int /*<<< orphan*/ *,scalar_t__,scalar_t__*) ; 
 scalar_t__ RpcImpersonateClient (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  RpcRevertToSelf () ; 
 scalar_t__ SetPrinterDataExW (int /*<<< orphan*/ ,char const*,char const*,scalar_t__,int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  UNIMPLEMENTED ; 
 scalar_t__ _RpcGetPrinterDataEx (int /*<<< orphan*/ ,char const*,char const*,scalar_t__*,int /*<<< orphan*/ *,scalar_t__,scalar_t__*) ; 
 scalar_t__ _RpcSetPrinterDataEx (int /*<<< orphan*/ ,char const*,char const*,scalar_t__,int /*<<< orphan*/ *,scalar_t__) ; 

DWORD
_RpcDeletePrinterData(WINSPOOL_PRINTER_HANDLE hPrinter, WCHAR* pValueName)
{
    UNIMPLEMENTED;
    return ERROR_INVALID_FUNCTION;
}

DWORD
_RpcDeletePrinterDataEx(WINSPOOL_PRINTER_HANDLE hPrinter, const WCHAR* pKeyName, const WCHAR* pValueName)
{
    UNIMPLEMENTED;
    return ERROR_INVALID_FUNCTION;
}

DWORD
_RpcDeletePrinterKey(WINSPOOL_PRINTER_HANDLE hPrinter, const WCHAR* pKeyName)
{
    UNIMPLEMENTED;
    return ERROR_INVALID_FUNCTION;
}

DWORD
_RpcEnumPrinterData(WINSPOOL_PRINTER_HANDLE hPrinter, DWORD dwIndex, WCHAR* pValueName, DWORD cbValueName, DWORD* pcbValueName, DWORD* pType, BYTE* pData, DWORD cbData, DWORD* pcbData)
{
    UNIMPLEMENTED;
    return ERROR_INVALID_FUNCTION;
}

DWORD
_RpcEnumPrinterKey(WINSPOOL_PRINTER_HANDLE hPrinter, const WCHAR* pKeyName, WCHAR* pSubkey, DWORD cbSubkey, DWORD* pcbSubkey)
{
    UNIMPLEMENTED;
    return ERROR_INVALID_FUNCTION;
}

DWORD
_RpcEnumPrinterDataEx(WINSPOOL_PRINTER_HANDLE hPrinter, const WCHAR* pKeyName, BYTE* pEnumValues, DWORD cbEnumValues, DWORD* pcbEnumValues, DWORD* pnEnumValues)
{
    UNIMPLEMENTED;
    return ERROR_INVALID_FUNCTION;
}

DWORD
_RpcGetPrinterData(WINSPOOL_PRINTER_HANDLE hPrinter, WCHAR* pValueName, DWORD* pType, BYTE* pData, DWORD nSize, DWORD* pcbNeeded)
{
    return _RpcGetPrinterDataEx(hPrinter, L"PrinterDriverData", pValueName, pType, pData, nSize, pcbNeeded);
}

DWORD
_RpcGetPrinterDataEx(WINSPOOL_PRINTER_HANDLE hPrinter, const WCHAR* pKeyName, const WCHAR* pValueName, DWORD* pType, BYTE* pData, DWORD nSize, DWORD* pcbNeeded)
{
    DWORD dwErrorCode;

    dwErrorCode = RpcImpersonateClient(NULL);
    if (dwErrorCode != ERROR_SUCCESS)
    {
        ERR("RpcImpersonateClient failed with error %lu!\n", dwErrorCode);
        return dwErrorCode;
    }

    dwErrorCode = GetPrinterDataExW(hPrinter, pKeyName, pValueName, pType, pData, nSize, pcbNeeded);

    RpcRevertToSelf();

    return dwErrorCode;
}

DWORD
_RpcSetPrinterData(WINSPOOL_PRINTER_HANDLE hPrinter, WCHAR* pValueName, DWORD Type, BYTE* pData, DWORD cbData)
{
    return _RpcSetPrinterDataEx(hPrinter, L"PrinterDriverData", pValueName, Type, pData, cbData);
}

DWORD
_RpcSetPrinterDataEx(WINSPOOL_PRINTER_HANDLE hPrinter, const WCHAR* pKeyName, const WCHAR* pValueName, DWORD Type, BYTE* pData, DWORD cbData)
{
    DWORD dwErrorCode;

    dwErrorCode = RpcImpersonateClient(NULL);
    if (dwErrorCode != ERROR_SUCCESS)
    {
        ERR("RpcImpersonateClient failed with error %lu!\n", dwErrorCode);
        return dwErrorCode;
    }

    dwErrorCode = SetPrinterDataExW(hPrinter, pKeyName, pValueName, Type, pData, cbData);

    RpcRevertToSelf();

    return dwErrorCode;
}

