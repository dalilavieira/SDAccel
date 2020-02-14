#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_6__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct oletls {int /*<<< orphan*/  causality_id; int /*<<< orphan*/ * apt; } ;
struct apartment {int /*<<< orphan*/  oxid; } ;
struct TYPE_10__ {struct oletls* ReservedForOle; } ;
struct TYPE_9__ {int /*<<< orphan*/  tdSize; } ;
struct TYPE_8__ {TYPE_2__* ptd; } ;
typedef  int /*<<< orphan*/  OXID ;
typedef  int /*<<< orphan*/  HRESULT ;
typedef  int /*<<< orphan*/  GUID ;
typedef  TYPE_1__ FORMATETC ;
typedef  int /*<<< orphan*/  APARTMENT ;

/* Variables and functions */
 int /*<<< orphan*/  CoCreateGuid (int /*<<< orphan*/ *) ; 
 TYPE_2__* CoTaskMemAlloc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  E_OUTOFMEMORY ; 
 int /*<<< orphan*/  GUID_NULL ; 
 scalar_t__ IsEqualGUID (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 TYPE_6__* NtCurrentTeb () ; 
 int /*<<< orphan*/  S_OK ; 
 struct oletls* heap_alloc_zero (int) ; 
 int /*<<< orphan*/  memcpy (TYPE_2__*,TYPE_2__*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline HRESULT apartment_getoxid(const struct apartment *apt, OXID *oxid)
{
    *oxid = apt->oxid;
    return S_OK;
}

__attribute__((used)) static inline struct oletls *COM_CurrentInfo(void)
{
    if (!NtCurrentTeb()->ReservedForOle)
        NtCurrentTeb()->ReservedForOle = heap_alloc_zero(sizeof(struct oletls));

    return NtCurrentTeb()->ReservedForOle;
}

__attribute__((used)) static inline APARTMENT* COM_CurrentApt(void)
{  
    return COM_CurrentInfo()->apt;
}

__attribute__((used)) static inline GUID COM_CurrentCausalityId(void)
{
    struct oletls *info = COM_CurrentInfo();
    if (!info)
        return GUID_NULL;
    if (IsEqualGUID(&info->causality_id, &GUID_NULL))
        CoCreateGuid(&info->causality_id);
    return info->causality_id;
}

__attribute__((used)) static inline HRESULT copy_formatetc(FORMATETC *dst, const FORMATETC *src)
{
    *dst = *src;
    if (src->ptd)
    {
        dst->ptd = CoTaskMemAlloc( src->ptd->tdSize );
        if (!dst->ptd) return E_OUTOFMEMORY;
        memcpy( dst->ptd, src->ptd, src->ptd->tdSize );
    }
    return S_OK;
}

