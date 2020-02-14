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
typedef  int /*<<< orphan*/  WCHAR ;
typedef  int DWORD ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 scalar_t__ CABINET_hInstance ; 
 int /*<<< orphan*/  CP_ACP ; 
 int /*<<< orphan*/  ERR (char*) ; 
 int /*<<< orphan*/  FALSE ; 
 scalar_t__ GetProcAddress (scalar_t__,char*) ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 int /*<<< orphan*/ * HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 scalar_t__ LoadLibraryA (char*) ; 
 int MultiByteToWideChar (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*,int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  TRUE ; 
 void* sc_FDICopy ; 
 void* sc_FDICreate ; 
 void* sc_FDIDestroy ; 

__attribute__((used)) inline static WCHAR *strdupAtoW( const char *str )
{
    WCHAR *ret = NULL;
    if (str)
    {
        DWORD len = MultiByteToWideChar( CP_ACP, 0, str, -1, NULL, 0 );
        if ((ret = HeapAlloc( GetProcessHeap(), 0, len * sizeof(WCHAR) )))
            MultiByteToWideChar( CP_ACP, 0, str, -1, ret, len );
    }
    return ret;
}

__attribute__((used)) static BOOL LoadCABINETDll(void)
{
  if (!CABINET_hInstance) {
    CABINET_hInstance = LoadLibraryA("cabinet.dll");
    if (CABINET_hInstance)  {
      sc_FDICreate = (void *)GetProcAddress(CABINET_hInstance, "FDICreate");
      sc_FDICopy = (void *)GetProcAddress(CABINET_hInstance, "FDICopy");
      sc_FDIDestroy = (void *)GetProcAddress(CABINET_hInstance, "FDIDestroy");
      return TRUE;
    } else {
      ERR("load cabinet dll failed.\n");
      return FALSE;
    }
  } else
    return TRUE;
}

