#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_44__   TYPE_7__ ;
typedef  struct TYPE_43__   TYPE_6__ ;
typedef  struct TYPE_42__   TYPE_4__ ;
typedef  struct TYPE_41__   TYPE_3__ ;
typedef  struct TYPE_40__   TYPE_2__ ;
typedef  struct TYPE_39__   TYPE_1__ ;
typedef  struct TYPE_38__   TYPE_12__ ;
typedef  struct TYPE_37__   TYPE_11__ ;
typedef  struct TYPE_36__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ULONG ;
struct TYPE_44__ {struct TYPE_44__* Flink; } ;
struct TYPE_40__ {int value; int fract; } ;
struct TYPE_39__ {int value; int fract; } ;
struct TYPE_43__ {TYPE_2__ y; TYPE_1__ x; } ;
struct TYPE_42__ {int /*<<< orphan*/  FullName; int /*<<< orphan*/  FontFamily; scalar_t__ OutlineRequiredSize; } ;
struct TYPE_41__ {int RefCount; TYPE_4__ UserLanguage; TYPE_4__ EnglishUS; struct TYPE_41__* Memory; TYPE_11__* Face; struct TYPE_41__* Buffer; scalar_t__ IsMapping; int /*<<< orphan*/  ListEntry; scalar_t__ BitmapGlyph; int /*<<< orphan*/  BufferSize; } ;
struct TYPE_38__ {scalar_t__ fract; scalar_t__ value; } ;
struct TYPE_37__ {char* family_name; } ;
struct TYPE_36__ {int x; int y; } ;
typedef  int /*<<< orphan*/  SHARED_MEM ;
typedef  int /*<<< orphan*/  SHARED_FACE ;
typedef  TYPE_3__* PSHARED_MEM ;
typedef  TYPE_4__* PSHARED_FACE_CACHE ;
typedef  TYPE_3__* PSHARED_FACE ;
typedef  TYPE_6__ POINTFX ;
typedef  TYPE_7__* PLIST_ENTRY ;
typedef  TYPE_3__* PFONT_CACHE_ENTRY ;
typedef  TYPE_3__* PBYTE ;
typedef  TYPE_10__ FT_Vector ;
typedef  int /*<<< orphan*/  FT_Glyph ;
typedef  int /*<<< orphan*/  FT_Fixed ;
typedef  TYPE_11__* FT_Face ;
typedef  short FLOAT ;
typedef  TYPE_12__ FIXED ;
typedef  scalar_t__ BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  ASSERT_FREETYPE_LOCK_HELD () ; 
 TYPE_3__* CONTAINING_RECORD (TYPE_7__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DPRINT (char*,...) ; 
 TYPE_3__* ExAllocatePoolWithTag (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ExFreePoolWithTag (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FONT_CACHE_ENTRY ; 
 int /*<<< orphan*/  FT_Done_Face (TYPE_11__*) ; 
 int /*<<< orphan*/  FT_Done_Glyph (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IntLockFreeType () ; 
 int /*<<< orphan*/  IntUnLockFreeType () ; 
 int /*<<< orphan*/  ListEntry ; 
 scalar_t__ MAX_FONT_CACHE ; 
 int /*<<< orphan*/  MmUnmapViewInSystemSpace (TYPE_3__*) ; 
 int /*<<< orphan*/  PagedPool ; 
 int /*<<< orphan*/  RemoveEntryList (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  RtlFreeUnicodeString (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  RtlInitUnicodeString (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TAG_FONT ; 
 TYPE_7__ g_FontCacheListHead ; 
 scalar_t__ g_FontCacheNumEntries ; 

__attribute__((used)) static void
SharedMem_AddRef(PSHARED_MEM Ptr)
{
    ASSERT_FREETYPE_LOCK_HELD();

    ++Ptr->RefCount;
}

__attribute__((used)) static void
SharedFaceCache_Init(PSHARED_FACE_CACHE Cache)
{
    Cache->OutlineRequiredSize = 0;
    RtlInitUnicodeString(&Cache->FontFamily, NULL);
    RtlInitUnicodeString(&Cache->FullName, NULL);
}

__attribute__((used)) static PSHARED_FACE
SharedFace_Create(FT_Face Face, PSHARED_MEM Memory)
{
    PSHARED_FACE Ptr;
    Ptr = ExAllocatePoolWithTag(PagedPool, sizeof(SHARED_FACE), TAG_FONT);
    if (Ptr)
    {
        Ptr->Face = Face;
        Ptr->RefCount = 1;
        Ptr->Memory = Memory;
        SharedFaceCache_Init(&Ptr->EnglishUS);
        SharedFaceCache_Init(&Ptr->UserLanguage);

        SharedMem_AddRef(Memory);
        DPRINT("Creating SharedFace for %s\n", Face->family_name ? Face->family_name : "<NULL>");
    }
    return Ptr;
}

__attribute__((used)) static PSHARED_MEM
SharedMem_Create(PBYTE Buffer, ULONG BufferSize, BOOL IsMapping)
{
    PSHARED_MEM Ptr;
    Ptr = ExAllocatePoolWithTag(PagedPool, sizeof(SHARED_MEM), TAG_FONT);
    if (Ptr)
    {
        Ptr->Buffer = Buffer;
        Ptr->BufferSize = BufferSize;
        Ptr->RefCount = 1;
        Ptr->IsMapping = IsMapping;
        DPRINT("Creating SharedMem for %p (%i, %p)\n", Buffer, IsMapping, Ptr);
    }
    return Ptr;
}

__attribute__((used)) static void
SharedFace_AddRef(PSHARED_FACE Ptr)
{
    ASSERT_FREETYPE_LOCK_HELD();

    ++Ptr->RefCount;
}

__attribute__((used)) static void
RemoveCachedEntry(PFONT_CACHE_ENTRY Entry)
{
    ASSERT_FREETYPE_LOCK_HELD();

    FT_Done_Glyph((FT_Glyph)Entry->BitmapGlyph);
    RemoveEntryList(&Entry->ListEntry);
    ExFreePoolWithTag(Entry, TAG_FONT);
    g_FontCacheNumEntries--;
    ASSERT(g_FontCacheNumEntries <= MAX_FONT_CACHE);
}

__attribute__((used)) static void
RemoveCacheEntries(FT_Face Face)
{
    PLIST_ENTRY CurrentEntry, NextEntry;
    PFONT_CACHE_ENTRY FontEntry;

    ASSERT_FREETYPE_LOCK_HELD();

    for (CurrentEntry = g_FontCacheListHead.Flink;
         CurrentEntry != &g_FontCacheListHead;
         CurrentEntry = NextEntry)
    {
        FontEntry = CONTAINING_RECORD(CurrentEntry, FONT_CACHE_ENTRY, ListEntry);
        NextEntry = CurrentEntry->Flink;

        if (FontEntry->Face == Face)
        {
            RemoveCachedEntry(FontEntry);
        }
    }
}

__attribute__((used)) static void SharedMem_Release(PSHARED_MEM Ptr)
{
    ASSERT_FREETYPE_LOCK_HELD();
    ASSERT(Ptr->RefCount > 0);

    if (Ptr->RefCount <= 0)
        return;

    --Ptr->RefCount;
    if (Ptr->RefCount == 0)
    {
        DPRINT("Releasing SharedMem for %p (%i, %p)\n", Ptr->Buffer, Ptr->IsMapping, Ptr);
        if (Ptr->IsMapping)
            MmUnmapViewInSystemSpace(Ptr->Buffer);
        else
            ExFreePoolWithTag(Ptr->Buffer, TAG_FONT);
        ExFreePoolWithTag(Ptr, TAG_FONT);
    }
}

__attribute__((used)) static void
SharedFaceCache_Release(PSHARED_FACE_CACHE Cache)
{
    RtlFreeUnicodeString(&Cache->FontFamily);
    RtlFreeUnicodeString(&Cache->FullName);
}

__attribute__((used)) static void
SharedFace_Release(PSHARED_FACE Ptr)
{
    IntLockFreeType();
    ASSERT(Ptr->RefCount > 0);

    if (Ptr->RefCount <= 0)
        return;

    --Ptr->RefCount;
    if (Ptr->RefCount == 0)
    {
        DPRINT("Releasing SharedFace for %s\n", Ptr->Face->family_name ? Ptr->Face->family_name : "<NULL>");
        RemoveCacheEntries(Ptr->Face);
        FT_Done_Face(Ptr->Face);
        SharedMem_Release(Ptr->Memory);
        SharedFaceCache_Release(&Ptr->EnglishUS);
        SharedFaceCache_Release(&Ptr->UserLanguage);
        ExFreePoolWithTag(Ptr, TAG_FONT);
    }
    IntUnLockFreeType();
}

__attribute__((used)) static __inline void FTVectorToPOINTFX(FT_Vector *vec, POINTFX *pt)
{
    pt->x.value = vec->x >> 6;
    pt->x.fract = (vec->x & 0x3f) << 10;
    pt->x.fract |= ((pt->x.fract >> 6) | (pt->x.fract >> 12));
    pt->y.value = vec->y >> 6;
    pt->y.fract = (vec->y & 0x3f) << 10;
    pt->y.fract |= ((pt->y.fract >> 6) | (pt->y.fract >> 12));
}

__attribute__((used)) static __inline FT_Fixed FT_FixedFromFloat(FLOAT f)
{
    short value = f;
    unsigned short fract = (f - value) * 0xFFFF;
    return (FT_Fixed)((long)value << 16 | (unsigned long)fract);
}

__attribute__((used)) static __inline FT_Fixed FT_FixedFromFIXED(FIXED f)
{
    return (FT_Fixed)((long)f.value << 16 | (unsigned long)f.fract);
}

