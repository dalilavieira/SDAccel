#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_47__   TYPE_8__ ;
typedef  struct TYPE_46__   TYPE_7__ ;
typedef  struct TYPE_45__   TYPE_6__ ;
typedef  struct TYPE_44__   TYPE_5__ ;
typedef  struct TYPE_43__   TYPE_4__ ;
typedef  struct TYPE_42__   TYPE_3__ ;
typedef  struct TYPE_41__   TYPE_2__ ;
typedef  struct TYPE_40__   TYPE_1__ ;
typedef  struct TYPE_39__   TYPE_14__ ;
typedef  struct TYPE_38__   TYPE_12__ ;

/* Type definitions */
struct TYPE_43__ {size_t dwFileVersionMS; size_t dwFileVersionLS; } ;
typedef  TYPE_4__ VS_FIXEDFILEINFO ;
typedef  scalar_t__ UINT ;
struct TYPE_44__ {int dwOSVersionInfoSize; int dwMajorVersion; int dwMinorVersion; int Caps; int Caps2; int Caps3; int DevCaps; int PresentationIntervals; int PrimitiveMiscCaps; int VertexProcessingCaps; float MaxPointSize; int DeviceType; int /*<<< orphan*/  NumberOfAdaptersInGroup; int /*<<< orphan*/  AdapterOrdinalInGroup; int /*<<< orphan*/  MasterAdapterOrdinal; int /*<<< orphan*/  RasterCaps; } ;
struct TYPE_41__ {TYPE_5__ DriverCaps9; } ;
struct TYPE_47__ {int /*<<< orphan*/  NumAdaptersInGroup; int /*<<< orphan*/  AdapterIndexInGroup; int /*<<< orphan*/  MasterAdapterIndex; TYPE_2__ DriverCaps; } ;
struct TYPE_46__ {int DeviceKey; int cb; char* DeviceID; int dmSize; int dmBitsPerPel; int /*<<< orphan*/  dmDisplayFrequency; int /*<<< orphan*/  dmPelsHeight; int /*<<< orphan*/  dmPelsWidth; int /*<<< orphan*/  DeviceName; int /*<<< orphan*/  DeviceString; } ;
struct TYPE_42__ {int biSize; scalar_t__ biCompression; int /*<<< orphan*/  biHeight; } ;
struct TYPE_45__ {int /*<<< orphan*/ * bmiColors; TYPE_3__ bmiHeader; } ;
struct TYPE_40__ {size_t HighPart; size_t LowPart; } ;
struct TYPE_39__ {char* Driver; size_t VendorId; size_t DeviceId; size_t SubSysId; size_t Revision; int /*<<< orphan*/  DeviceName; int /*<<< orphan*/  Description; TYPE_1__ DriverVersion; int /*<<< orphan*/  DeviceIdentifier; } ;
struct TYPE_38__ {int /*<<< orphan*/  Format; int /*<<< orphan*/  RefreshRate; int /*<<< orphan*/  Height; int /*<<< orphan*/  Width; } ;
typedef  int /*<<< orphan*/  RGBQUAD ;
typedef  int /*<<< orphan*/  PVOID ;
typedef  TYPE_5__ OSVERSIONINFOA ;
typedef  TYPE_6__* LPVOID ;
typedef  int /*<<< orphan*/  (* LPFN_REVERTWOW64FSREDIRECTION ) (int /*<<< orphan*/ *) ;
typedef  int /*<<< orphan*/  (* LPFN_ISWOW64PROCESS ) (int /*<<< orphan*/ ,scalar_t__*) ;
typedef  int /*<<< orphan*/  (* LPFN_DISABLEWOW64FSREDIRECTION ) (int /*<<< orphan*/ *) ;
typedef  size_t* LPDWORD ;
typedef  TYPE_7__* LPDISPLAY_DEVICEA ;
typedef  TYPE_8__* LPDIRECT3D9_DISPLAYADAPTER ;
typedef  char* LPCSTR ;
typedef  int /*<<< orphan*/  LPBYTE ;
typedef  TYPE_6__* LPBITMAPINFO ;
typedef  int /*<<< orphan*/  HRESULT ;
typedef  int /*<<< orphan*/  HMODULE ;
typedef  int /*<<< orphan*/  HKEY ;
typedef  int /*<<< orphan*/ * HDC ;
typedef  int /*<<< orphan*/ * HBITMAP ;
typedef  size_t DWORD ;
typedef  TYPE_7__ DISPLAY_DEVICEA ;
typedef  TYPE_7__ DEVMODEA ;
typedef  int /*<<< orphan*/  D3DFORMAT ;
typedef  TYPE_12__ D3DDISPLAYMODE ;
typedef  int D3DDEVTYPE ;
typedef  TYPE_5__ D3DCAPS9 ;
typedef  TYPE_14__ D3DADAPTER_IDENTIFIER9 ;
typedef  scalar_t__ BOOL ;
typedef  int /*<<< orphan*/  BITMAPINFOHEADER ;

/* Variables and functions */
 scalar_t__ BI_BITFIELDS ; 
 size_t CCHDEVICENAME ; 
 int /*<<< orphan*/  CLSID_DirectDraw ; 
 int /*<<< orphan*/ * CreateCompatibleBitmap (int /*<<< orphan*/ *,int,int) ; 
 int /*<<< orphan*/ * CreateDCA (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int D3D9_CAPS1 ; 
 int D3D9_CAPS3 ; 
 int D3D9_DEVCAPS ; 
 int D3D9_PRE_XP_CAPS2 ; 
 int D3D9_XP_OR_LATER_CAPS2 ; 
 int D3DCAPS2_PRESENT_INTERVAL_IMMEDIATE ; 
 int D3DCAPS2_PRESENT_INTERVAL_SEVERAL ; 
#define  D3DDEVTYPE_HAL 131 
#define  D3DDEVTYPE_NULLREF 130 
#define  D3DDEVTYPE_REF 129 
#define  D3DDEVTYPE_SW 128 
 int /*<<< orphan*/  D3DERR_INVALIDDEVICE ; 
 int /*<<< orphan*/  D3DFMT_P8 ; 
 int /*<<< orphan*/  D3DFMT_R5G6B5 ; 
 int /*<<< orphan*/  D3DFMT_R8G8B8 ; 
 int /*<<< orphan*/  D3DFMT_UNKNOWN ; 
 int /*<<< orphan*/  D3DFMT_X1R5G5B5 ; 
 int /*<<< orphan*/  D3DFMT_X8R8G8B8 ; 
 int D3DPMISCCAPS_FOGINFVF ; 
 int /*<<< orphan*/  D3DPRASTERCAPS_FOGVERTEX ; 
 int D3DPRESENT_INTERVAL_FOUR ; 
 int D3DPRESENT_INTERVAL_IMMEDIATE ; 
 int D3DPRESENT_INTERVAL_ONE ; 
 int D3DPRESENT_INTERVAL_THREE ; 
 int D3DPRESENT_INTERVAL_TWO ; 
 int D3DVTXPCAPS_FOGVERTEX ; 
 int /*<<< orphan*/  D3D_OK ; 
 int /*<<< orphan*/  DIB_RGB_COLORS ; 
 int /*<<< orphan*/  DPRINT1 (char*) ; 
 int /*<<< orphan*/  DeleteDC (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DeleteObject (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ENUM_CURRENT_SETTINGS ; 
 scalar_t__ ERROR_SUCCESS ; 
 scalar_t__ EnumDisplayDevicesA (int /*<<< orphan*/ *,size_t,TYPE_7__*,int /*<<< orphan*/ ) ; 
 scalar_t__ EnumDisplaySettingsA (char*,int /*<<< orphan*/ ,TYPE_7__*) ; 
 scalar_t__ FALSE ; 
 int /*<<< orphan*/  GetCurrentProcess () ; 
 scalar_t__ GetDIBits (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,TYPE_6__*,int /*<<< orphan*/ ) ; 
 scalar_t__ GetFileVersionInfoA (char*,int /*<<< orphan*/ ,scalar_t__,TYPE_6__*) ; 
 scalar_t__ GetFileVersionInfoSizeA (char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  GetModuleHandleA (char*) ; 
 scalar_t__ GetProcAddress (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 scalar_t__ GetVersionExA (TYPE_5__*) ; 
 int /*<<< orphan*/  HEAP_ZERO_MEMORY ; 
 int /*<<< orphan*/  HKEY_LOCAL_MACHINE ; 
 TYPE_6__* HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_6__*) ; 
 int /*<<< orphan*/  KEY_QUERY_VALUE ; 
 size_t MAX_DEVICE_IDENTIFIER_STRING ; 
 int /*<<< orphan*/  RegCloseKey (int /*<<< orphan*/ ) ; 
 scalar_t__ RegOpenKeyExA (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ RegQueryValueExA (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,size_t*,int /*<<< orphan*/ ,size_t*) ; 
 scalar_t__ SUCCEEDED (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SafeAppendString (char*,size_t,char*) ; 
 scalar_t__ TRUE ; 
 int /*<<< orphan*/  UNIMPLEMENTED ; 
 scalar_t__ VerQueryValueA (TYPE_6__*,char*,TYPE_6__**,scalar_t__*) ; 
 int /*<<< orphan*/  ZeroMemory (TYPE_5__*,int) ; 
 scalar_t__ _stricmp (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lstrcpynA (int /*<<< orphan*/ ,int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  memset (TYPE_7__*,int /*<<< orphan*/ ,int) ; 
 int strlen (char*) ; 
 char* strstr (char*,char*) ; 
 size_t strtol (char const*,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static BOOL GetDriverName(LPDISPLAY_DEVICEA pDisplayDevice, D3DADAPTER_IDENTIFIER9* pIdentifier)
{
    HKEY hKey;
    BOOL bResult = FALSE;

    if (ERROR_SUCCESS == RegOpenKeyExA(HKEY_LOCAL_MACHINE, pDisplayDevice->DeviceKey + strlen("\\Registry\\Machine\\"), 0, KEY_QUERY_VALUE, &hKey))
    {
        DWORD DriverNameLength = MAX_DEVICE_IDENTIFIER_STRING - (DWORD)strlen(".dll");
        DWORD Type = 0;

        if (ERROR_SUCCESS == RegQueryValueExA(hKey, "InstalledDisplayDrivers", 0, &Type, (LPBYTE)pIdentifier->Driver, &DriverNameLength))
        {
            pIdentifier->Driver[DriverNameLength] = '\0';
            SafeAppendString(pIdentifier->Driver, MAX_DEVICE_IDENTIFIER_STRING, ".dll");
            bResult = TRUE;
        }

        RegCloseKey(hKey);
    }

    return bResult;
}

__attribute__((used)) static void GetDriverVersion(LPDISPLAY_DEVICEA pDisplayDevice, D3DADAPTER_IDENTIFIER9* pIdentifier)
{
    HMODULE hModule;
    LPFN_ISWOW64PROCESS fnIsWow64Process;
    BOOL bIsWow64 = FALSE;
    PVOID OldWow64RedirectValue;
    UINT DriverFileSize;

    hModule = GetModuleHandleA("KERNEL32");
    fnIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress(hModule, "IsWow64Process");
    if (fnIsWow64Process)
    {
        fnIsWow64Process(GetCurrentProcess(), &bIsWow64);
        if (bIsWow64)
        {
            LPFN_DISABLEWOW64FSREDIRECTION fnDisableWow64FsRedirection;
            fnDisableWow64FsRedirection = (LPFN_DISABLEWOW64FSREDIRECTION)GetProcAddress(hModule, "Wow64DisableWow64FsRedirection");
            fnDisableWow64FsRedirection(&OldWow64RedirectValue);
        }
    }

    DriverFileSize = GetFileVersionInfoSizeA(pIdentifier->Driver, NULL);
    if (DriverFileSize > 0)
    {
        VS_FIXEDFILEINFO* FixedFileInfo = NULL;
        LPVOID pBlock = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, DriverFileSize);

        if (TRUE == GetFileVersionInfoA(pIdentifier->Driver, 0, DriverFileSize, pBlock))
        {
            if (TRUE == VerQueryValueA(pBlock, "\\", (LPVOID*)&FixedFileInfo, &DriverFileSize))
            {
                pIdentifier->DriverVersion.HighPart = FixedFileInfo->dwFileVersionMS;
                pIdentifier->DriverVersion.LowPart = FixedFileInfo->dwFileVersionLS;
            }
        }

        HeapFree(GetProcessHeap(), 0, pBlock);
    }

    if (bIsWow64)
    {
        LPFN_REVERTWOW64FSREDIRECTION fnRevertWow64FsRedirection;
        fnRevertWow64FsRedirection = (LPFN_REVERTWOW64FSREDIRECTION)GetProcAddress(hModule, "Wow64RevertWow64FsRedirection");
        fnRevertWow64FsRedirection(&OldWow64RedirectValue);
    }
}

__attribute__((used)) static void ParseField(LPCSTR lpszDeviceKey, LPDWORD pField, LPCSTR lpszSubString)
{
    const char* ResultStr;
    ResultStr = strstr(lpszDeviceKey, lpszSubString);
    if (ResultStr != NULL)
    {
        *pField = strtol(ResultStr + strlen(lpszSubString), NULL, 16);
    }
}

__attribute__((used)) static void GetDeviceId(LPCSTR lpszDeviceKey, D3DADAPTER_IDENTIFIER9* pIdentifier)
{
    ParseField(lpszDeviceKey, &pIdentifier->VendorId, "VEN_");
    ParseField(lpszDeviceKey, &pIdentifier->DeviceId, "DEV_");
    ParseField(lpszDeviceKey, &pIdentifier->SubSysId, "SUBSYS_");
    ParseField(lpszDeviceKey, &pIdentifier->Revision, "REV_");
}

__attribute__((used)) static void GenerateDeviceIdentifier(D3DADAPTER_IDENTIFIER9* pIdentifier)
{
    DWORD* dwIdentifier = (DWORD*)&pIdentifier->DeviceIdentifier;

    pIdentifier->DeviceIdentifier = CLSID_DirectDraw;

    dwIdentifier[0] ^= pIdentifier->VendorId;
    dwIdentifier[1] ^= pIdentifier->DeviceId;
    dwIdentifier[2] ^= pIdentifier->SubSysId;
    dwIdentifier[3] ^= pIdentifier->Revision;
    dwIdentifier[2] ^= pIdentifier->DriverVersion.LowPart;
    dwIdentifier[3] ^= pIdentifier->DriverVersion.HighPart;
}

BOOL GetAdapterInfo(LPCSTR lpszDeviceName, D3DADAPTER_IDENTIFIER9* pIdentifier)
{
    DISPLAY_DEVICEA DisplayDevice;
    DWORD AdapterIndex;
    BOOL FoundDisplayDevice;

    memset(&DisplayDevice, 0, sizeof(DISPLAY_DEVICEA));
    DisplayDevice.cb = sizeof(DISPLAY_DEVICEA);   

    AdapterIndex = 0;
    FoundDisplayDevice = FALSE;
    while (EnumDisplayDevicesA(NULL, AdapterIndex, &DisplayDevice, 0) != FALSE)
    {
        if (_stricmp(lpszDeviceName, DisplayDevice.DeviceName) == 0)
        {
            FoundDisplayDevice = TRUE;
            break;
        }

        ++AdapterIndex;
    }

    /* No matching display device found? */
    if (FALSE == FoundDisplayDevice)
        return FALSE;

    lstrcpynA(pIdentifier->Description, DisplayDevice.DeviceString, MAX_DEVICE_IDENTIFIER_STRING);
    lstrcpynA(pIdentifier->DeviceName, DisplayDevice.DeviceName, CCHDEVICENAME);

    if (GetDriverName(&DisplayDevice, pIdentifier) != FALSE)
        GetDriverVersion(&DisplayDevice, pIdentifier);

    GetDeviceId(DisplayDevice.DeviceID, pIdentifier);

    GenerateDeviceIdentifier(pIdentifier);

    return TRUE;
}

__attribute__((used)) static BOOL IsWindowsXPorLaterCompatible()
{
    OSVERSIONINFOA osvi;

    ZeroMemory(&osvi, sizeof(OSVERSIONINFOA));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOA);

    if (GetVersionExA(&osvi) != 0)
    {
        return ( (osvi.dwMajorVersion > 5) ||
               ( (osvi.dwMajorVersion == 5) && (osvi.dwMinorVersion >= 1) ));
    }

    return FALSE;
}

__attribute__((used)) static void CopyDriverCaps(const D3DCAPS9* pSrcCaps, D3DCAPS9* pDstCaps)
{
    *pDstCaps = *pSrcCaps;

    pDstCaps->Caps = pSrcCaps->Caps & D3D9_CAPS1;

    /* TODO: Fit in D3DCAPS2_CANCALIBRATEGAMMA somewhere here */
    if (IsWindowsXPorLaterCompatible())
        pDstCaps->Caps2 = pSrcCaps->Caps2 & D3D9_XP_OR_LATER_CAPS2;
    else
        pDstCaps->Caps2 = pSrcCaps->Caps2 & D3D9_PRE_XP_CAPS2;

    pDstCaps->Caps3 = pSrcCaps->Caps3 & D3D9_CAPS3;
    pDstCaps->DevCaps = pSrcCaps->DevCaps & D3D9_DEVCAPS;

    pDstCaps->PresentationIntervals = D3DPRESENT_INTERVAL_ONE;
    if (pSrcCaps->Caps2 & D3DCAPS2_PRESENT_INTERVAL_SEVERAL)
        pDstCaps->PresentationIntervals |= (D3DPRESENT_INTERVAL_TWO | D3DPRESENT_INTERVAL_THREE | D3DPRESENT_INTERVAL_FOUR);
    if (pSrcCaps->Caps2 & D3DCAPS2_PRESENT_INTERVAL_IMMEDIATE)
        pDstCaps->PresentationIntervals |= D3DPRESENT_INTERVAL_IMMEDIATE;

    pDstCaps->PrimitiveMiscCaps = pSrcCaps->PrimitiveMiscCaps & ~D3DPMISCCAPS_FOGINFVF;

    if (pSrcCaps->VertexProcessingCaps & D3DVTXPCAPS_FOGVERTEX)
    {
        pDstCaps->RasterCaps |= D3DPRASTERCAPS_FOGVERTEX;
        pDstCaps->VertexProcessingCaps &= ~D3DVTXPCAPS_FOGVERTEX;
    }

    if (pSrcCaps->MaxPointSize < 0.0f)
        pDstCaps->MaxPointSize = 1.0f;
}

HRESULT GetAdapterCaps(const LPDIRECT3D9_DISPLAYADAPTER pDisplayAdapter, D3DDEVTYPE DeviceType, D3DCAPS9* pDstCaps)
{
    HRESULT hResult = D3DERR_INVALIDDEVICE;
    D3DCAPS9* pDriverCaps = NULL;

    ZeroMemory(pDstCaps, sizeof(D3DCAPS9));

    switch (DeviceType)
    {
    case D3DDEVTYPE_HAL:
        pDriverCaps = &pDisplayAdapter->DriverCaps.DriverCaps9;
        hResult = D3D_OK;
        break;

    case D3DDEVTYPE_REF:
    case D3DDEVTYPE_SW:
    case D3DDEVTYPE_NULLREF:
        UNIMPLEMENTED;
        hResult = D3D_OK;
        break;

    default:
        DPRINT1("Unknown DeviceType argument");
        break;
    }

    if (pDriverCaps != NULL)
    {
        CopyDriverCaps(pDriverCaps, pDstCaps);
    }

    if (SUCCEEDED(hResult))
    {
        pDstCaps->DeviceType = DeviceType;
        pDstCaps->MasterAdapterOrdinal = pDisplayAdapter->MasterAdapterIndex;
        pDstCaps->AdapterOrdinalInGroup = pDisplayAdapter->AdapterIndexInGroup;
        pDstCaps->NumberOfAdaptersInGroup = pDisplayAdapter->NumAdaptersInGroup;
    }

    return hResult;
}

__attribute__((used)) static D3DFORMAT Get16BitD3DFormat(LPCSTR lpszDeviceName)
{
    HDC hDC;
    HBITMAP hBitmap;
    LPBITMAPINFO pBitmapInfo;
    D3DFORMAT Format = D3DFMT_R5G6B5;

    if (NULL == (hDC = CreateDCA(NULL, lpszDeviceName, NULL, NULL)))
    {
        return Format;
    }

    if (NULL == (hBitmap = CreateCompatibleBitmap(hDC, 1, 1)))
    {
        DeleteDC(hDC);
        return Format;
    }

    pBitmapInfo = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(BITMAPINFOHEADER) + 4 * sizeof(RGBQUAD));
    if (NULL == pBitmapInfo)
    {
        DeleteObject(hBitmap);
        DeleteDC(hDC);
        return Format;
    }

    pBitmapInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    if (GetDIBits(hDC, hBitmap, 0, 0, NULL, pBitmapInfo, DIB_RGB_COLORS) > 0)
    {
        if (pBitmapInfo->bmiHeader.biCompression == BI_BITFIELDS)
        {
            if (GetDIBits(hDC, hBitmap, 0, pBitmapInfo->bmiHeader.biHeight, NULL, pBitmapInfo, DIB_RGB_COLORS) > 0)
            {
                /* Check if the green field is 6 bits long */
                if (*(DWORD*)(&pBitmapInfo->bmiColors[1]) == 0x000003E0)
                {
                    Format = D3DFMT_X1R5G5B5;
                }
            }
        }
    }

    HeapFree(GetProcessHeap(), 0, pBitmapInfo);
    DeleteObject(hBitmap);
    DeleteDC(hDC);

    return Format;
}

BOOL GetAdapterMode(LPCSTR lpszDeviceName, D3DDISPLAYMODE* pMode)
{
    DEVMODEA DevMode;
    
    memset(&DevMode, 0, sizeof(DEVMODEA));
    DevMode.dmSize = sizeof(DEVMODEA);
    if (FALSE == EnumDisplaySettingsA(lpszDeviceName, ENUM_CURRENT_SETTINGS, &DevMode))
        return FALSE;

    pMode->Width = DevMode.dmPelsWidth;
    pMode->Height = DevMode.dmPelsHeight;
    pMode->RefreshRate = DevMode.dmDisplayFrequency;
    
    switch (DevMode.dmBitsPerPel)
    {
    case 8:
        pMode->Format = D3DFMT_P8;
        break;

    case 16:
        pMode->Format = Get16BitD3DFormat(lpszDeviceName);
        break;

    case 24:
        pMode->Format = D3DFMT_R8G8B8;
        break;

    case 32:
        pMode->Format = D3DFMT_X8R8G8B8;
        break;

    default:
        pMode->Format = D3DFMT_UNKNOWN;
        break;
    }

    return TRUE;
}

