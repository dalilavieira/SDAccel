#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {TYPE_1__* DebugInfo; } ;
struct NBNameCache {scalar_t__ expireTime; scalar_t__ entryExpireTimeMS; scalar_t__ heap; struct NBNameCache* head; TYPE_2__ cs; struct NBNameCache* entry; struct NBNameCache* next; scalar_t__ name; } ;
typedef  char UCHAR ;
struct TYPE_6__ {scalar_t__* Spare; } ;
typedef  struct NBNameCache NBNameCacheNode ;
typedef  struct NBNameCache NBNameCacheEntry ;
typedef  scalar_t__ HANDLE ;
typedef  scalar_t__ DWORD_PTR ;
typedef  scalar_t__ DWORD ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  DeleteCriticalSection (TYPE_2__*) ; 
 int /*<<< orphan*/  EnterCriticalSection (TYPE_2__*) ; 
 int /*<<< orphan*/  FALSE ; 
 scalar_t__ GetProcessHeap () ; 
 scalar_t__ GetTickCount () ; 
 struct NBNameCache* HeapAlloc (scalar_t__,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  HeapFree (scalar_t__,int /*<<< orphan*/ ,struct NBNameCache*) ; 
 int /*<<< orphan*/  InitializeCriticalSection (TYPE_2__*) ; 
 int /*<<< orphan*/  LeaveCriticalSection (TYPE_2__*) ; 
 int NCBNAMSZ ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  memcmp (scalar_t__,char const*,int) ; 
 int /*<<< orphan*/  memcpy (char*,char const*,int) ; 

__attribute__((used)) static void NBNameCacheUnlinkNode(struct NBNameCache *cache,
 NBNameCacheNode **prev)
{
    if (cache && prev && *prev)
    {
        NBNameCacheNode *next = (*prev)->next;

        HeapFree(cache->heap, 0, (*prev)->entry);
        HeapFree(cache->heap, 0, *prev);
        *prev = next;
    }
}

__attribute__((used)) static NBNameCacheNode **NBNameCacheWalk(struct NBNameCache *cache,
 const char name[NCBNAMSZ])
{
    NBNameCacheNode **ret = NULL;

    if (cache && cache->head)
    {
        NBNameCacheNode **ptr;

        ptr = &cache->head;
        while (ptr && *ptr && (*ptr)->entry)
        {
            if (!memcmp((*ptr)->entry->name, name, NCBNAMSZ - 1))
                ret = ptr;
            else
            {
                if (GetTickCount() > (*ptr)->expireTime)
                    NBNameCacheUnlinkNode(cache, ptr);
            }
            if (*ptr)
                ptr = &(*ptr)->next;
        }
    }
    return ret;
}

struct NBNameCache *NBNameCacheCreate(HANDLE heap, DWORD entryExpireTimeMS)
{
    struct NBNameCache *cache;
    
    
    if (!heap)
        heap = GetProcessHeap();
    cache = HeapAlloc(heap, 0, sizeof(struct NBNameCache));
    if (cache)
    {
        cache->heap = heap;
        InitializeCriticalSection(&cache->cs);
        cache->cs.DebugInfo->Spare[0] = (DWORD_PTR)(__FILE__ ": NBNameCache.cs");
        cache->entryExpireTimeMS = entryExpireTimeMS;
        cache->head = NULL;
    }
    return cache;
}

BOOL NBNameCacheAddEntry(struct NBNameCache *cache, NBNameCacheEntry *entry)
{
    BOOL ret;

    if (cache && entry)
    {
        NBNameCacheNode **node;

        EnterCriticalSection(&cache->cs);
        node = NBNameCacheWalk(cache, (char*)entry->name);
        if (node)
        {
            (*node)->expireTime = GetTickCount() +
             cache->entryExpireTimeMS;
            HeapFree(cache->heap, 0, (*node)->entry);
            (*node)->entry = entry;
            ret = TRUE;
        }
        else
        {
            NBNameCacheNode *newNode = HeapAlloc(cache->heap, 0, sizeof(NBNameCacheNode));
            if (newNode)
            {
                newNode->expireTime = GetTickCount() +
                 cache->entryExpireTimeMS;
                newNode->entry = entry;
                newNode->next = cache->head;
                cache->head = newNode;
                ret = TRUE;
            }
            else
                ret = FALSE;
        }
        LeaveCriticalSection(&cache->cs);
    }
    else
        ret = FALSE;
    return ret;
}

const NBNameCacheEntry *NBNameCacheFindEntry(struct NBNameCache *cache,
 const UCHAR name[NCBNAMSZ])
{
    const NBNameCacheEntry *ret;
    UCHAR printName[NCBNAMSZ];

    memcpy(printName, name, NCBNAMSZ - 1);
    printName[NCBNAMSZ - 1] = '\0';
    if (cache)
    {
        NBNameCacheNode **node;

        EnterCriticalSection(&cache->cs);
        node = NBNameCacheWalk(cache, (const char *)name);
        if (node)
            ret = (*node)->entry;
        else
            ret = NULL;
        LeaveCriticalSection(&cache->cs);
    }
    else
        ret = NULL;
    return ret;
}

void NBNameCacheDestroy(struct NBNameCache *cache)
{
    if (cache)
    {
        cache->cs.DebugInfo->Spare[0] = 0;
        DeleteCriticalSection(&cache->cs);
        while (cache->head)
            NBNameCacheUnlinkNode(cache, &cache->head);
        HeapFree(cache->heap, 0, cache);
    }
}

