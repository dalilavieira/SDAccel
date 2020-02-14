#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_47__   TYPE_9__ ;
typedef  struct TYPE_46__   TYPE_7__ ;
typedef  struct TYPE_45__   TYPE_6__ ;
typedef  struct TYPE_44__   TYPE_1__ ;
typedef  struct TYPE_43__   TYPE_11__ ;
typedef  struct TYPE_42__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  flags ;
typedef  TYPE_1__** ULONG ;
struct TYPE_47__ {TYPE_1__* pds; scalar_t__ ref; int /*<<< orphan*/ * lpVtbl; } ;
struct TYPE_46__ {TYPE_1__* pds; scalar_t__ ref; int /*<<< orphan*/ * lpVtbl; } ;
struct TYPE_45__ {TYPE_1__* pds; scalar_t__ ref; int /*<<< orphan*/ * lpVtbl; } ;
struct TYPE_44__ {int /*<<< orphan*/ * device; scalar_t__ ref; struct TYPE_44__* pDS8; struct TYPE_44__* pDS; struct TYPE_44__* pUnknown; } ;
struct TYPE_43__ {TYPE_1__* pds; scalar_t__ ref; int /*<<< orphan*/ * lpVtbl; } ;
struct TYPE_42__ {TYPE_1__* pds; scalar_t__ ref; int /*<<< orphan*/ * lpVtbl; } ;
typedef  int /*<<< orphan*/  REFIID ;
typedef  TYPE_1__* LPVOID ;
typedef  TYPE_1__* LPUNKNOWN ;
typedef  TYPE_1__* LPDIRECTSOUND8 ;
typedef  TYPE_1__* LPDIRECTSOUND ;
typedef  TYPE_6__ IDirectSound_IUnknown ;
typedef  TYPE_7__ IDirectSound_IDirectSound ;
typedef  TYPE_1__ IDirectSoundImpl ;
typedef  TYPE_9__ IDirectSound8_IUnknown ;
typedef  TYPE_10__ IDirectSound8_IDirectSound8 ;
typedef  TYPE_11__ IDirectSound8_IDirectSound ;
typedef  scalar_t__ HRESULT ;
typedef  int DWORD ;

/* Variables and functions */
 int /*<<< orphan*/  DSBCAPS_CTRL3D ; 
 int /*<<< orphan*/  DSBCAPS_CTRLFREQUENCY ; 
 int /*<<< orphan*/  DSBCAPS_CTRLPAN ; 
 int /*<<< orphan*/  DSBCAPS_CTRLPOSITIONNOTIFY ; 
 int /*<<< orphan*/  DSBCAPS_CTRLVOLUME ; 
 int /*<<< orphan*/  DSBCAPS_GETCURRENTPOSITION2 ; 
 int /*<<< orphan*/  DSBCAPS_GLOBALFOCUS ; 
 int /*<<< orphan*/  DSBCAPS_LOCHARDWARE ; 
 int /*<<< orphan*/  DSBCAPS_LOCSOFTWARE ; 
 int /*<<< orphan*/  DSBCAPS_MUTE3DATMAXDISTANCE ; 
 int /*<<< orphan*/  DSBCAPS_PRIMARYBUFFER ; 
 int /*<<< orphan*/  DSBCAPS_STATIC ; 
 int /*<<< orphan*/  DSBCAPS_STICKYFOCUS ; 
 int /*<<< orphan*/  DSCAPS_CERTIFIED ; 
 int /*<<< orphan*/  DSCAPS_CONTINUOUSRATE ; 
 int /*<<< orphan*/  DSCAPS_EMULDRIVER ; 
 int /*<<< orphan*/  DSCAPS_PRIMARY16BIT ; 
 int /*<<< orphan*/  DSCAPS_PRIMARY8BIT ; 
 int /*<<< orphan*/  DSCAPS_PRIMARYMONO ; 
 int /*<<< orphan*/  DSCAPS_PRIMARYSTEREO ; 
 int /*<<< orphan*/  DSCAPS_SECONDARY16BIT ; 
 int /*<<< orphan*/  DSCAPS_SECONDARY8BIT ; 
 int /*<<< orphan*/  DSCAPS_SECONDARYMONO ; 
 int /*<<< orphan*/  DSCAPS_SECONDARYSTEREO ; 
 scalar_t__ DSERR_INVALIDPARAM ; 
 scalar_t__ DSERR_OUTOFMEMORY ; 
#define  DSSCL_EXCLUSIVE 131 
#define  DSSCL_NORMAL 130 
#define  DSSCL_PRIORITY 129 
#define  DSSCL_WRITEPRIMARY 128 
 scalar_t__ DS_OK ; 
 int /*<<< orphan*/  DirectSound8_DirectSound8_Vtbl ; 
 int /*<<< orphan*/  DirectSound8_DirectSound_Vtbl ; 
 int /*<<< orphan*/  DirectSound8_Unknown_Vtbl ; 
 int /*<<< orphan*/  DirectSoundDevice_Release (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DirectSound_DirectSound_Vtbl ; 
 int /*<<< orphan*/  DirectSound_Unknown_Vtbl ; 
 int /*<<< orphan*/  ERR (char*) ; 
 scalar_t__ E_INVALIDARG ; 
 scalar_t__ E_NOINTERFACE ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 int /*<<< orphan*/  HEAP_ZERO_MEMORY ; 
 void* HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  IDirectSound8_IDirectSound8_AddRef (TYPE_1__*) ; 
static  scalar_t__ IDirectSound8_IDirectSound8_Create (TYPE_1__*,TYPE_1__**) ; 
 int /*<<< orphan*/  IDirectSound8_IDirectSound_AddRef (TYPE_1__*) ; 
static  scalar_t__ IDirectSound8_IDirectSound_Create (TYPE_1__*,TYPE_1__**) ; 
 int /*<<< orphan*/  IDirectSound8_IUnknown_AddRef (TYPE_1__*) ; 
static  scalar_t__ IDirectSound8_IUnknown_Create (TYPE_1__*,TYPE_1__**) ; 
 int /*<<< orphan*/  IDirectSound8_Release (TYPE_1__*) ; 
 int /*<<< orphan*/  IDirectSound_IDirectSound_AddRef (TYPE_1__*) ; 
static  scalar_t__ IDirectSound_IDirectSound_Create (TYPE_1__*,TYPE_1__**) ; 
 int /*<<< orphan*/  IDirectSound_IUnknown_AddRef (TYPE_1__*) ; 
static  scalar_t__ IDirectSound_IUnknown_Create (TYPE_1__*,TYPE_1__**) ; 
 int /*<<< orphan*/  IID_IDirectSound ; 
 int /*<<< orphan*/  IID_IDirectSound8 ; 
 int /*<<< orphan*/  IID_IUnknown ; 
 TYPE_1__** InterlockedDecrement (scalar_t__*) ; 
 TYPE_1__** InterlockedIncrement (scalar_t__*) ; 
 scalar_t__ IsEqualIID (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ S_OK ; 
 int /*<<< orphan*/  TRACE (char*,...) ; 
 int /*<<< orphan*/  WARN (char*,...) ; 
 TYPE_1__* debugstr_guid (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  setup_dsound_options () ; 
 char const* wine_dbg_sprintf (char*,int) ; 

const char * dumpCooperativeLevel(DWORD level)
{
#define LE(x) case x: return #x
    switch (level) {
        LE(DSSCL_NORMAL);
        LE(DSSCL_PRIORITY);
        LE(DSSCL_EXCLUSIVE);
        LE(DSSCL_WRITEPRIMARY);
    }
#undef LE
    return wine_dbg_sprintf("Unknown(%08x)", level);
}

__attribute__((used)) static void _dump_DSCAPS(DWORD xmask) {
    struct {
        DWORD   mask;
        const char    *name;
    } flags[] = {
#define FE(x) { x, #x },
        FE(DSCAPS_PRIMARYMONO)
        FE(DSCAPS_PRIMARYSTEREO)
        FE(DSCAPS_PRIMARY8BIT)
        FE(DSCAPS_PRIMARY16BIT)
        FE(DSCAPS_CONTINUOUSRATE)
        FE(DSCAPS_EMULDRIVER)
        FE(DSCAPS_CERTIFIED)
        FE(DSCAPS_SECONDARYMONO)
        FE(DSCAPS_SECONDARYSTEREO)
        FE(DSCAPS_SECONDARY8BIT)
        FE(DSCAPS_SECONDARY16BIT)
#undef FE
    };
    unsigned int     i;

    for (i=0;i<sizeof(flags)/sizeof(flags[0]);i++)
        if ((flags[i].mask & xmask) == flags[i].mask)
            TRACE("%s ",flags[i].name);
}

__attribute__((used)) static void _dump_DSBCAPS(DWORD xmask) {
    struct {
        DWORD   mask;
        const char    *name;
    } flags[] = {
#define FE(x) { x, #x },
        FE(DSBCAPS_PRIMARYBUFFER)
        FE(DSBCAPS_STATIC)
        FE(DSBCAPS_LOCHARDWARE)
        FE(DSBCAPS_LOCSOFTWARE)
        FE(DSBCAPS_CTRL3D)
        FE(DSBCAPS_CTRLFREQUENCY)
        FE(DSBCAPS_CTRLPAN)
        FE(DSBCAPS_CTRLVOLUME)
        FE(DSBCAPS_CTRLPOSITIONNOTIFY)
        FE(DSBCAPS_STICKYFOCUS)
        FE(DSBCAPS_GLOBALFOCUS)
        FE(DSBCAPS_GETCURRENTPOSITION2)
        FE(DSBCAPS_MUTE3DATMAXDISTANCE)
#undef FE
    };
    unsigned int     i;

    for (i=0;i<sizeof(flags)/sizeof(flags[0]);i++)
        if ((flags[i].mask & xmask) == flags[i].mask)
            TRACE("%s ",flags[i].name);
}

__attribute__((used)) static HRESULT DSOUND_QueryInterface(
    LPDIRECTSOUND8 iface,
    REFIID riid,
    LPVOID * ppobj)
{
    IDirectSoundImpl *This = (IDirectSoundImpl *)iface;
    TRACE("(%p,%s,%p)\n",This,debugstr_guid(riid),ppobj);

    if (ppobj == NULL) {
        WARN("invalid parameter\n");
        return E_INVALIDARG;
    }

    if (IsEqualIID(riid, &IID_IUnknown)) {
        if (!This->pUnknown) {
            IDirectSound_IUnknown_Create(iface, &This->pUnknown);
            if (!This->pUnknown) {
                WARN("IDirectSound_IUnknown_Create() failed\n");
                *ppobj = NULL;
                return E_NOINTERFACE;
            }
        }
        IDirectSound_IUnknown_AddRef(This->pUnknown);
        *ppobj = This->pUnknown;
        return S_OK;
    } else if (IsEqualIID(riid, &IID_IDirectSound)) {
        if (!This->pDS) {
            IDirectSound_IDirectSound_Create(iface, &This->pDS);
            if (!This->pDS) {
                WARN("IDirectSound_IDirectSound_Create() failed\n");
                *ppobj = NULL;
                return E_NOINTERFACE;
            }
        }
        IDirectSound_IDirectSound_AddRef(This->pDS);
        *ppobj = This->pDS;
        return S_OK;
    }

    *ppobj = NULL;
    WARN("Unknown IID %s\n",debugstr_guid(riid));
    return E_NOINTERFACE;
}

__attribute__((used)) static HRESULT DSOUND_QueryInterface8(
    LPDIRECTSOUND8 iface,
    REFIID riid,
    LPVOID * ppobj)
{
    IDirectSoundImpl *This = (IDirectSoundImpl *)iface;
    TRACE("(%p,%s,%p)\n",This,debugstr_guid(riid),ppobj);

    if (ppobj == NULL) {
        WARN("invalid parameter\n");
        return E_INVALIDARG;
    }

    if (IsEqualIID(riid, &IID_IUnknown)) {
        if (!This->pUnknown) {
            IDirectSound8_IUnknown_Create(iface, &This->pUnknown);
            if (!This->pUnknown) {
                WARN("IDirectSound8_IUnknown_Create() failed\n");
                *ppobj = NULL;
                return E_NOINTERFACE;
            }
        }
        IDirectSound8_IUnknown_AddRef(This->pUnknown);
        *ppobj = This->pUnknown;
        return S_OK;
    } else if (IsEqualIID(riid, &IID_IDirectSound)) {
        if (!This->pDS) {
            IDirectSound8_IDirectSound_Create(iface, &This->pDS);
            if (!This->pDS) {
                WARN("IDirectSound8_IDirectSound_Create() failed\n");
                *ppobj = NULL;
                return E_NOINTERFACE;
            }
        }
        IDirectSound8_IDirectSound_AddRef(This->pDS);
        *ppobj = This->pDS;
        return S_OK;
    } else if (IsEqualIID(riid, &IID_IDirectSound8)) {
        if (!This->pDS8) {
            IDirectSound8_IDirectSound8_Create(iface, &This->pDS8);
            if (!This->pDS8) {
                WARN("IDirectSound8_IDirectSound8_Create() failed\n");
                *ppobj = NULL;
                return E_NOINTERFACE;
            }
        }
        IDirectSound8_IDirectSound8_AddRef(This->pDS8);
        *ppobj = This->pDS8;
        return S_OK;
    }

    *ppobj = NULL;
    WARN("Unknown IID %s\n",debugstr_guid(riid));
    return E_NOINTERFACE;
}

__attribute__((used)) static ULONG IDirectSoundImpl_AddRef(
    LPDIRECTSOUND8 iface)
{
    IDirectSoundImpl *This = (IDirectSoundImpl *)iface;
    ULONG ref = InterlockedIncrement(&(This->ref));
    TRACE("(%p) ref was %d\n", This, ref - 1);
    return ref;
}

__attribute__((used)) static ULONG IDirectSoundImpl_Release(
    LPDIRECTSOUND8 iface)
{
    IDirectSoundImpl *This = (IDirectSoundImpl *)iface;
    ULONG ref = InterlockedDecrement(&(This->ref));
    TRACE("(%p) ref was %d\n", This, ref + 1);

    if (!ref) {
        if (This->device)
            DirectSoundDevice_Release(This->device);
        HeapFree(GetProcessHeap(),0,This);
        TRACE("(%p) released\n", This);
    }
    return ref;
}

__attribute__((used)) static HRESULT IDirectSoundImpl_Create(
    LPDIRECTSOUND8 * ppDS)
{
    IDirectSoundImpl* pDS;
    TRACE("(%p)\n",ppDS);

    /* Allocate memory */
    pDS = HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,sizeof(IDirectSoundImpl));
    if (pDS == NULL) {
        WARN("out of memory\n");
        *ppDS = NULL;
        return DSERR_OUTOFMEMORY;
    }

    pDS->ref    = 0;
    pDS->device = NULL;

    *ppDS = (LPDIRECTSOUND8)pDS;

    return DS_OK;
}

__attribute__((used)) static HRESULT IDirectSound_IUnknown_Create(
    LPDIRECTSOUND8 pds,
    LPUNKNOWN * ppunk)
{
    IDirectSound_IUnknown * pdsunk;
    TRACE("(%p,%p)\n",pds,ppunk);

    if (ppunk == NULL) {
        ERR("invalid parameter: ppunk == NULL\n");
        return DSERR_INVALIDPARAM;
    }

    if (pds == NULL) {
        ERR("invalid parameter: pds == NULL\n");
        *ppunk = NULL;
        return DSERR_INVALIDPARAM;
    }

    pdsunk = HeapAlloc(GetProcessHeap(),0,sizeof(*pdsunk));
    if (pdsunk == NULL) {
        WARN("out of memory\n");
        *ppunk = NULL;
        return DSERR_OUTOFMEMORY;
    }

    pdsunk->lpVtbl = &DirectSound_Unknown_Vtbl;
    pdsunk->ref = 0;
    pdsunk->pds = pds;

    IDirectSoundImpl_AddRef(pds);
    *ppunk = (LPUNKNOWN)pdsunk;

    return DS_OK;
}

__attribute__((used)) static HRESULT IDirectSound_IDirectSound_Create(
    LPDIRECTSOUND8  pds,
    LPDIRECTSOUND * ppds)
{
    IDirectSound_IDirectSound * pdsds;
    TRACE("(%p,%p)\n",pds,ppds);

    if (ppds == NULL) {
        ERR("invalid parameter: ppds == NULL\n");
        return DSERR_INVALIDPARAM;
    }

    if (pds == NULL) {
        ERR("invalid parameter: pds == NULL\n");
        *ppds = NULL;
        return DSERR_INVALIDPARAM;
    }

    pdsds = HeapAlloc(GetProcessHeap(),0,sizeof(*pdsds));
    if (pdsds == NULL) {
        WARN("out of memory\n");
        *ppds = NULL;
        return DSERR_OUTOFMEMORY;
    }

    pdsds->lpVtbl = &DirectSound_DirectSound_Vtbl;
    pdsds->ref = 0;
    pdsds->pds = pds;

    IDirectSoundImpl_AddRef(pds);
    *ppds = (LPDIRECTSOUND)pdsds;

    return DS_OK;
}

__attribute__((used)) static HRESULT IDirectSound8_IUnknown_Create(
    LPDIRECTSOUND8 pds,
    LPUNKNOWN * ppunk)
{
    IDirectSound8_IUnknown * pdsunk;
    TRACE("(%p,%p)\n",pds,ppunk);

    if (ppunk == NULL) {
        ERR("invalid parameter: ppunk == NULL\n");
        return DSERR_INVALIDPARAM;
    }

    if (pds == NULL) {
        ERR("invalid parameter: pds == NULL\n");
        *ppunk = NULL;
        return DSERR_INVALIDPARAM;
    }

    pdsunk = HeapAlloc(GetProcessHeap(),0,sizeof(*pdsunk));
    if (pdsunk == NULL) {
        WARN("out of memory\n");
        *ppunk = NULL;
        return DSERR_OUTOFMEMORY;
    }

    pdsunk->lpVtbl = &DirectSound8_Unknown_Vtbl;
    pdsunk->ref = 0;
    pdsunk->pds = pds;

    IDirectSoundImpl_AddRef(pds);
    *ppunk = (LPUNKNOWN)pdsunk;

    return DS_OK;
}

__attribute__((used)) static HRESULT IDirectSound8_IDirectSound_Create(
    LPDIRECTSOUND8 pds,
    LPDIRECTSOUND * ppds)
{
    IDirectSound8_IDirectSound * pdsds;
    TRACE("(%p,%p)\n",pds,ppds);

    if (ppds == NULL) {
        ERR("invalid parameter: ppds == NULL\n");
        return DSERR_INVALIDPARAM;
    }

    if (pds == NULL) {
        ERR("invalid parameter: pds == NULL\n");
        *ppds = NULL;
        return DSERR_INVALIDPARAM;
    }

    pdsds = HeapAlloc(GetProcessHeap(),0,sizeof(*pdsds));
    if (pdsds == NULL) {
        WARN("out of memory\n");
        *ppds = NULL;
        return DSERR_OUTOFMEMORY;
    }

    pdsds->lpVtbl = &DirectSound8_DirectSound_Vtbl;
    pdsds->ref = 0;
    pdsds->pds = pds;

    IDirectSoundImpl_AddRef(pds);
    *ppds = (LPDIRECTSOUND)pdsds;

    return DS_OK;
}

__attribute__((used)) static HRESULT IDirectSound8_IDirectSound8_Create(
    LPDIRECTSOUND8 pds,
    LPDIRECTSOUND8 * ppds)
{
    IDirectSound8_IDirectSound8 * pdsds;
    TRACE("(%p,%p)\n",pds,ppds);

    if (ppds == NULL) {
        ERR("invalid parameter: ppds == NULL\n");
        return DSERR_INVALIDPARAM;
    }

    if (pds == NULL) {
        ERR("invalid parameter: pds == NULL\n");
        *ppds = NULL;
        return DSERR_INVALIDPARAM;
    }

    pdsds = HeapAlloc(GetProcessHeap(),0,sizeof(*pdsds));
    if (pdsds == NULL) {
        WARN("out of memory\n");
        *ppds = NULL;
        return DSERR_OUTOFMEMORY;
    }

    pdsds->lpVtbl = &DirectSound8_DirectSound8_Vtbl;
    pdsds->ref = 0;
    pdsds->pds = pds;

    IDirectSoundImpl_AddRef(pds);
    *ppds = (LPDIRECTSOUND8)pdsds;

    return DS_OK;
}

HRESULT DSOUND_Create(
    REFIID riid,
    LPDIRECTSOUND *ppDS)
{
    LPDIRECTSOUND8 pDS;
    HRESULT hr;
    TRACE("(%s, %p)\n", debugstr_guid(riid), ppDS);

    if (!IsEqualIID(riid, &IID_IUnknown) &&
        !IsEqualIID(riid, &IID_IDirectSound)) {
        *ppDS = 0;
        return E_NOINTERFACE;
    }

    /* Get dsound configuration */
    setup_dsound_options();

    hr = IDirectSoundImpl_Create(&pDS);
    if (hr == DS_OK) {
        hr = IDirectSound_IDirectSound_Create(pDS, ppDS);
        if (*ppDS)
            IDirectSound_IDirectSound_AddRef(*ppDS);
        else {
            WARN("IDirectSound_IDirectSound_Create failed\n");
            IDirectSound8_Release(pDS);
        }
    } else {
        WARN("IDirectSoundImpl_Create failed\n");
        *ppDS = 0;
    }

    return hr;
}

