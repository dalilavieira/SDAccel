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
struct envvars_map {scalar_t__ len; int /*<<< orphan*/  path; scalar_t__ var; } ;
typedef  int /*<<< orphan*/  WCHAR ;
typedef  scalar_t__ LPCSTR ;
typedef  int DWORD ;

/* Variables and functions */
 int /*<<< orphan*/  CP_ACP ; 
 scalar_t__ ExpandEnvironmentStringsW (scalar_t__,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 int /*<<< orphan*/ * HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int MultiByteToWideChar (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static inline WCHAR* heap_strdupAtoW(LPCSTR str)
{
    WCHAR *ret = NULL;

    if (str)
    {
        DWORD len = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, 0);
        ret = HeapAlloc(GetProcessHeap(), 0, len*sizeof(WCHAR));
        if (ret)
            MultiByteToWideChar(CP_ACP, 0, str, -1, ret, len);
    }

    return ret;
}

__attribute__((used)) static void init_envvars_map(struct envvars_map *map)
{
    while (map->var)
    {
        map->len = ExpandEnvironmentStringsW(map->var, map->path, sizeof(map->path)/sizeof(WCHAR));
        /* exclude null from length */
        if (map->len) map->len--;
        map++;
    }
}

