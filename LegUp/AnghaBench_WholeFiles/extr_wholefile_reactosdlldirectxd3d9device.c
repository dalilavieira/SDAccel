#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_24__   TYPE_7__ ;
typedef  struct TYPE_23__   TYPE_6__ ;
typedef  struct TYPE_22__   TYPE_5__ ;
typedef  struct TYPE_21__   TYPE_4__ ;
typedef  struct TYPE_20__   TYPE_3__ ;
typedef  struct TYPE_19__   TYPE_2__ ;
typedef  struct TYPE_18__   TYPE_1__ ;
typedef  struct TYPE_17__   TYPE_15__ ;
typedef  struct TYPE_16__   TYPE_14__ ;

/* Type definitions */
struct IDirect3DDevice9 {int dummy; } ;
typedef  int /*<<< orphan*/  UINT ;
struct TYPE_24__ {int MaxSimultaneousTextures; TYPE_5__* pBaseDevice; int /*<<< orphan*/  pTextureHeap; } ;
struct TYPE_23__ {TYPE_14__* DisplayAdapters; } ;
struct TYPE_22__ {int lRefCnt; int AdjustedBehaviourFlags; int BehaviourFlags; int NumAdaptersInDevice; int dwDXVersion; int* AdapterIndexInGroup; int /*<<< orphan*/ * pSwapChains; int /*<<< orphan*/ * pSwapChains2; TYPE_3__* CurrentDisplayMode; TYPE_15__* DeviceData; int /*<<< orphan*/  hWnd; int /*<<< orphan*/  DeviceType; TYPE_6__* pDirect3D9; int /*<<< orphan*/  CriticalSection; int /*<<< orphan*/ * lpVtbl; int /*<<< orphan*/ * pUnknown; int /*<<< orphan*/  dwProcessId; TYPE_7__* pResourceManager; } ;
struct TYPE_21__ {int /*<<< orphan*/  RawDisplayFormat; int /*<<< orphan*/  dwRefreshRate; int /*<<< orphan*/  dwDisplayHeight; int /*<<< orphan*/  dwDisplayWidth; } ;
struct TYPE_20__ {int /*<<< orphan*/  Format; int /*<<< orphan*/  RefreshRate; int /*<<< orphan*/  Height; int /*<<< orphan*/  Width; } ;
struct TYPE_18__ {int /*<<< orphan*/  MaxSimultaneousTextures; } ;
struct TYPE_19__ {TYPE_1__ DriverCaps9; } ;
struct TYPE_17__ {TYPE_2__ DriverCaps; } ;
struct TYPE_16__ {TYPE_4__ DriverCaps; } ;
typedef  int /*<<< orphan*/  LPVOID ;
typedef  TYPE_5__* LPDIRECT3DDEVICE9_INT ;
typedef  TYPE_6__* LPDIRECT3D9_INT ;
typedef  int /*<<< orphan*/  IUnknown ;
typedef  int /*<<< orphan*/  HWND ;
typedef  int /*<<< orphan*/  HRESULT ;
typedef  int DWORD ;
typedef  int /*<<< orphan*/  D3DPRESENT_PARAMETERS ;
typedef  int /*<<< orphan*/  D3DDEVTYPE ;
typedef  TYPE_7__ D3D9ResourceManager ;
typedef  int /*<<< orphan*/  D3D9HALDEVICE ;

/* Variables and functions */
 int /*<<< orphan*/  AlignedAlloc (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  AlignedFree (int /*<<< orphan*/ ) ; 
 scalar_t__ CreateD3D9DeviceData (TYPE_14__*,TYPE_15__*) ; 
 int /*<<< orphan*/  CreateDirect3DSwapChain9 (int /*<<< orphan*/ ,TYPE_5__*,int) ; 
 int /*<<< orphan*/  D3DDEVTYPE_HAL ; 
 int /*<<< orphan*/  D3D_OK ; 
 int /*<<< orphan*/  DDERR_GENERIC ; 
 int /*<<< orphan*/  DDERR_OUTOFMEMORY ; 
 int /*<<< orphan*/  DPRINT1 (char*,...) ; 
 int /*<<< orphan*/  Direct3DDevice9HAL_Vtbl ; 
 int /*<<< orphan*/  Direct3DSwapChain9_Init (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ FAILED (int /*<<< orphan*/ ) ; 
 scalar_t__ FALSE ; 
 int /*<<< orphan*/  GetCurrentThreadId () ; 
 int /*<<< orphan*/  InitializeCriticalSection (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  RT_BUILTIN ; 
 int max (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static HRESULT InitD3D9ResourceManager(D3D9ResourceManager* pThisResourceManager, LPDIRECT3DDEVICE9_INT pDirect3DDevice9)
{
    DWORD MaxSimultaneousTextures;

    MaxSimultaneousTextures = max(1, pDirect3DDevice9->DeviceData[0].DriverCaps.DriverCaps9.MaxSimultaneousTextures);

    if (FAILED(AlignedAlloc((LPVOID *)&pThisResourceManager->pTextureHeap, sizeof(DWORD) + MaxSimultaneousTextures * sizeof(int) * 3)))
    {
        DPRINT1("Could not allocate texture heap");
        return DDERR_OUTOFMEMORY;
    }

    // TODO: Init texture heap

    pThisResourceManager->MaxSimultaneousTextures = MaxSimultaneousTextures;
    pThisResourceManager->pBaseDevice = pDirect3DDevice9;

    return D3D_OK;
}

HRESULT InitD3D9BaseDevice(LPDIRECT3DDEVICE9_INT pThisBaseDevice, LPDIRECT3D9_INT pDirect3D9,
                           UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviourFlags,
                           D3DPRESENT_PARAMETERS* pPresentationParameters, DWORD NumAdaptersToCreate)
{
    D3D9ResourceManager* pResourceManager;
    DWORD i;

    // Insert Reset/Ctor here

    if (FAILED(AlignedAlloc((LPVOID *)&pResourceManager, sizeof(D3D9ResourceManager))) ||
        FAILED(InitD3D9ResourceManager(pResourceManager, pThisBaseDevice)))
    {
        DPRINT1("Could not create resource manager");
        return DDERR_OUTOFMEMORY;
    }

    pThisBaseDevice->pResourceManager = pResourceManager;

    pThisBaseDevice->lpVtbl = &Direct3DDevice9HAL_Vtbl;
    pThisBaseDevice->lRefCnt = 1;
    pThisBaseDevice->dwProcessId = GetCurrentThreadId();
    pThisBaseDevice->pUnknown = (IUnknown*) &pThisBaseDevice->lpVtbl;
    InitializeCriticalSection(&pThisBaseDevice->CriticalSection);

    pThisBaseDevice->pDirect3D9 = pDirect3D9;
    pThisBaseDevice->DeviceType = DeviceType;
    pThisBaseDevice->hWnd = hFocusWindow;
    pThisBaseDevice->AdjustedBehaviourFlags = BehaviourFlags;
    pThisBaseDevice->BehaviourFlags = BehaviourFlags;
    pThisBaseDevice->NumAdaptersInDevice = NumAdaptersToCreate;

    // TODO: Query driver for correct DX version
    pThisBaseDevice->dwDXVersion = 9;

    for (i = 0; i < NumAdaptersToCreate; i++)
    {
        if (FALSE == CreateD3D9DeviceData(&pDirect3D9->DisplayAdapters[i], &pThisBaseDevice->DeviceData[i]))
        {
            DPRINT1("Failed to get device data for adapter: %d", i);
            return DDERR_GENERIC;
        }

        pThisBaseDevice->AdapterIndexInGroup[i] = i;
        pThisBaseDevice->CurrentDisplayMode[i].Width = pDirect3D9->DisplayAdapters[i].DriverCaps.dwDisplayWidth;
        pThisBaseDevice->CurrentDisplayMode[i].Height = pDirect3D9->DisplayAdapters[i].DriverCaps.dwDisplayHeight;
        pThisBaseDevice->CurrentDisplayMode[i].RefreshRate = pDirect3D9->DisplayAdapters[i].DriverCaps.dwRefreshRate;
        pThisBaseDevice->CurrentDisplayMode[i].Format = pDirect3D9->DisplayAdapters[i].DriverCaps.RawDisplayFormat;

        pThisBaseDevice->pSwapChains[i] = CreateDirect3DSwapChain9(RT_BUILTIN, pThisBaseDevice, i);
        pThisBaseDevice->pSwapChains2[i] = pThisBaseDevice->pSwapChains[i];

        if (FAILED(Direct3DSwapChain9_Init(pThisBaseDevice->pSwapChains[i], pPresentationParameters)))
        {
            DPRINT1("Failed to init swap chain: %d", i);
            return DDERR_GENERIC;
        }
    }

    return D3D_OK;
}

HRESULT CreateD3D9HalDevice(LPDIRECT3D9_INT pDirect3D9, UINT Adapter,
                            HWND hFocusWindow, DWORD BehaviourFlags,
                            D3DPRESENT_PARAMETERS* pPresentationParameters,
                            DWORD NumAdaptersToCreate,
                            struct IDirect3DDevice9** ppReturnedDeviceInterface)
{
    HRESULT Ret;

    if (FAILED(AlignedAlloc((LPVOID *)ppReturnedDeviceInterface, sizeof(D3D9HALDEVICE))))
    {
        DPRINT1("Not enough memory to create HAL device");
        return DDERR_OUTOFMEMORY;
    }

    Ret = InitD3D9BaseDevice((LPDIRECT3DDEVICE9_INT)*ppReturnedDeviceInterface, pDirect3D9, Adapter,
                             D3DDEVTYPE_HAL, hFocusWindow, BehaviourFlags,
                             pPresentationParameters, NumAdaptersToCreate);

    if (FAILED(Ret))
    {
        AlignedFree((LPVOID)*ppReturnedDeviceInterface);
        return Ret;
    }

    return D3D_OK;
}

