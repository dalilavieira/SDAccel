#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
typedef  char WCHAR ;
typedef  int /*<<< orphan*/  VOID ;
struct TYPE_14__ {int /*<<< orphan*/  pszValue; int /*<<< orphan*/  pszName; } ;
struct TYPE_13__ {int cEntries; TYPE_4__* pse; } ;
struct TYPE_12__ {int cEntries; struct TYPE_12__* pse; struct TYPE_12__* pszValue; struct TYPE_12__* pszName; } ;
typedef  TYPE_1__ STRTABLEW ;
typedef  TYPE_2__ STRTABLEA ;
typedef  TYPE_1__ STRENTRYW ;
typedef  TYPE_4__ STRENTRYA ;
typedef  char* LPWSTR ;
typedef  int /*<<< orphan*/  HRSRC ;
typedef  int /*<<< orphan*/  HMODULE ;
typedef  int /*<<< orphan*/ * HGLOBAL ;
typedef  scalar_t__ HANDLE ;
typedef  scalar_t__ DWORD ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (char*) ; 
 int /*<<< orphan*/  CP_ACP ; 
 int /*<<< orphan*/  CREATE_ALWAYS ; 
 int /*<<< orphan*/  CloseHandle (scalar_t__) ; 
 scalar_t__ CreateFileW (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ERR (char*) ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  FILE_ATTRIBUTE_NORMAL ; 
 int /*<<< orphan*/  FindResourceW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FreeResource (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  GENERIC_WRITE ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 int /*<<< orphan*/  GetTempFileNameW (char*,char const*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  GetTempPathW (int /*<<< orphan*/ ,char*) ; 
 void* HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__*) ; 
 scalar_t__ INVALID_HANDLE_VALUE ; 
 int /*<<< orphan*/ * LoadResource (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * LockResource (int /*<<< orphan*/ *) ; 
 int MAX_PATH ; 
 scalar_t__ MultiByteToWideChar (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,TYPE_1__*,scalar_t__) ; 
 int /*<<< orphan*/  REGINST ; 
 scalar_t__ SizeofResource (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  WriteFile (scalar_t__,int /*<<< orphan*/ *,scalar_t__,scalar_t__*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static BOOL get_temp_ini_path(LPWSTR name)
{
    static const WCHAR prefix[] = {'a','v','p',0};
    WCHAR tmp_dir[MAX_PATH];

    if(!GetTempPathW(ARRAY_SIZE(tmp_dir), tmp_dir))
       return FALSE;

    if(!GetTempFileNameW(tmp_dir, prefix, 0, name))
        return FALSE;
    return TRUE;
}

__attribute__((used)) static BOOL create_tmp_ini_file(HMODULE hm, WCHAR *ini_file)
{
    HRSRC hrsrc;
    HGLOBAL hmem = NULL;
    DWORD rsrc_size, bytes_written;
    VOID *rsrc_data;
    HANDLE hf = INVALID_HANDLE_VALUE;

    if(!get_temp_ini_path(ini_file)) {
        ERR("Can't get temp ini file path\n");
        goto error;
    }

    if(!(hrsrc = FindResourceW(hm, REGINST, REGINST))) {
        ERR("Can't find REGINST resource\n");
        goto error;
    }

    rsrc_size = SizeofResource(hm, hrsrc);
    hmem = LoadResource(hm, hrsrc);
    rsrc_data = LockResource(hmem);

    if(!rsrc_data || !rsrc_size) {
        ERR("Can't load REGINST resource\n");
        goto error;
    }       

    if((hf = CreateFileW(ini_file, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
                         FILE_ATTRIBUTE_NORMAL, NULL)) == INVALID_HANDLE_VALUE) {
        ERR("Unable to create temp ini file\n");
        goto error;
    }
    if(!WriteFile(hf, rsrc_data, rsrc_size, &bytes_written, NULL) || rsrc_size != bytes_written) {
        ERR("Write failed\n");
        goto error;
    }
    FreeResource(hmem);
    CloseHandle(hf);
    return TRUE;
error:
    if(hmem) FreeResource(hmem);
    if(hf != INVALID_HANDLE_VALUE) CloseHandle(hf);
    return FALSE;
}

__attribute__((used)) static void strentry_atow(const STRENTRYA *aentry, STRENTRYW *wentry)
{
    DWORD name_len, val_len;

    name_len = MultiByteToWideChar(CP_ACP, 0, aentry->pszName, -1, NULL, 0);
    val_len = MultiByteToWideChar(CP_ACP, 0, aentry->pszValue, -1, NULL, 0);

    wentry->pszName = HeapAlloc(GetProcessHeap(), 0, name_len * sizeof(WCHAR));
    wentry->pszValue = HeapAlloc(GetProcessHeap(), 0, val_len * sizeof(WCHAR));

    MultiByteToWideChar(CP_ACP, 0, aentry->pszName, -1, wentry->pszName, name_len);
    MultiByteToWideChar(CP_ACP, 0, aentry->pszValue, -1, wentry->pszValue, val_len);
}

__attribute__((used)) static STRTABLEW *strtable_atow(const STRTABLEA *atable)
{
    STRTABLEW *wtable;
    DWORD j;

    wtable = HeapAlloc(GetProcessHeap(), 0, sizeof(STRTABLEW));
    wtable->pse = HeapAlloc(GetProcessHeap(), 0, atable->cEntries * sizeof(STRENTRYW));
    wtable->cEntries = atable->cEntries;

    for (j = 0; j < wtable->cEntries; j++)
        strentry_atow(&atable->pse[j], &wtable->pse[j]);

    return wtable;
}

__attribute__((used)) static void free_strtable(STRTABLEW *wtable)
{
    DWORD j;

    for (j = 0; j < wtable->cEntries; j++)
    {
        HeapFree(GetProcessHeap(), 0, wtable->pse[j].pszName);
        HeapFree(GetProcessHeap(), 0, wtable->pse[j].pszValue);
    }

    HeapFree(GetProcessHeap(), 0, wtable->pse);
    HeapFree(GetProcessHeap(), 0, wtable);
}

