#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ (* iterate_fields_func ) (int /*<<< orphan*/ *,char*,void*) ;
typedef  int /*<<< orphan*/  default_install ;
typedef  char WCHAR ;
typedef  int UINT ;
struct TYPE_16__ {char* working_dir; char const* install_sec; char* inf_filename; char* inf_path; scalar_t__ hinf; int flags; void* need_reboot; } ;
struct TYPE_15__ {char* szDispName; char* szVersion; char* szCompID; char* szGUID; char* szLocale; char* szStub; scalar_t__ dwIsInstalled; void* bRollback; } ;
struct TYPE_14__ {char* inf_name; char* section_name; char* dir; } ;
typedef  TYPE_1__ SETUPCOMMAND_PARAMSW ;
typedef  int /*<<< orphan*/ * PVOID ;
typedef  int* PINT ;
typedef  TYPE_2__ PERUSERSECTIONW ;
typedef  char const* PCWSTR ;
typedef  char* LPWSTR ;
typedef  char* LPCWSTR ;
typedef  int INT ;
typedef  int /*<<< orphan*/  INFCONTEXT ;
typedef  scalar_t__ HRESULT ;
typedef  scalar_t__ HMODULE ;
typedef  int /*<<< orphan*/ * HINF ;
typedef  int DWORD ;
typedef  void* BOOL ;
typedef  TYPE_3__ ADVInfo ;

/* Variables and functions */
 int /*<<< orphan*/  ADN_DEL_IF_EMPTY ; 
 scalar_t__ ADV_HRESULT (scalar_t__) ; 
 int ARRAY_SIZE (char*) ; 
 int /*<<< orphan*/  CP_ACP ; 
 char const* CheckAdminRights ; 
 char* DelDirs ; 
 scalar_t__ DelNodeW (char*,int /*<<< orphan*/ ) ; 
 scalar_t__ ERROR_INSUFFICIENT_BUFFER ; 
 scalar_t__ E_FAIL ; 
 scalar_t__ E_OUTOFMEMORY ; 
 scalar_t__ FAILED (scalar_t__) ; 
 void* FALSE ; 
 int /*<<< orphan*/  FreeLibrary (scalar_t__) ; 
 int /*<<< orphan*/  GetCurrentDirectoryW (int,char*) ; 
 scalar_t__ GetFileAttributesW (char*) ; 
 scalar_t__ GetLastError () ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 int /*<<< orphan*/  GetWindowsDirectoryW (char*,int) ; 
 int /*<<< orphan*/ * HKEY_LOCAL_MACHINE ; 
 void* HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  INF_STYLE_WIN4 ; 
 scalar_t__ INVALID_FILE_ATTRIBUTES ; 
 scalar_t__ INVALID_HANDLE_VALUE ; 
 scalar_t__ IsNTAdmin (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  LOAD_WITH_ALTERED_SEARCH_PATH ; 
 scalar_t__ LoadLibraryExW (char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int MAX_INF_STRING_LENGTH ; 
 int MAX_PATH ; 
 int /*<<< orphan*/  OleInitialize (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  OleUninitialize () ; 
 char* PerUserInstall ; 
 int RSC_FLAG_INF ; 
 char* RegisterOCXs ; 
 char* RunPostSetupCommands ; 
 char* RunPreSetupCommands ; 
 int SPINST_FILES ; 
 int SPINST_INIFILES ; 
 int SPINST_REGISTRY ; 
 int SPINST_REGSVR ; 
 int /*<<< orphan*/  SP_COPY_NEWER ; 
 scalar_t__ S_OK ; 
 scalar_t__ SetPerUserSecValuesW (TYPE_2__*) ; 
 int /*<<< orphan*/  SetupCloseInfFile (scalar_t__) ; 
 int /*<<< orphan*/ * SetupDefaultQueueCallbackW ; 
 void* SetupFindFirstLineW (int /*<<< orphan*/ *,char const*,char const*,int /*<<< orphan*/ *) ; 
 void* SetupFindNextLine (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 void* SetupFindNextMatchLineW (int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ *) ; 
 int SetupGetFieldCount (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SetupGetIntField (int /*<<< orphan*/ *,int,int*) ; 
 int /*<<< orphan*/  SetupGetLineTextW (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char const*,char const*,char*,int,int*) ; 
 scalar_t__ SetupGetStringFieldW (int /*<<< orphan*/ *,int,char*,int,int*) ; 
 int /*<<< orphan*/ * SetupInitDefaultQueueCallbackEx (int /*<<< orphan*/ *,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 void* SetupInstallFromInfSectionW (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char const*,int,int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * SetupOpenInfFileW (char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SetupTermDefaultQueueCallback (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TRACE (char*,TYPE_1__ const*) ; 
 void* TRUE ; 
 size_t WideCharToMultiByte (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*,int,char*,size_t,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ZeroMemory (TYPE_3__*,int) ; 
 scalar_t__ do_ocx_reg (scalar_t__,void*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 char* heap_alloc (size_t) ; 
 scalar_t__ launch_exe (char*,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lstrcatW (char*,char const*) ; 
 int /*<<< orphan*/  lstrcpyW (char*,char*) ; 
 int /*<<< orphan*/  lstrcpynW (char*,char*,int) ; 
 int lstrlenW (char*) ; 
 int /*<<< orphan*/  set_ldids (scalar_t__,char*,char*) ; 
 char* strchrW (char*,char) ; 
 char* strrchrW (char*,char) ; 

__attribute__((used)) static inline char *heap_strdupWtoA(const WCHAR *str)
{
    char *ret = NULL;

    if(str) {
        size_t size = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
        ret = heap_alloc(size);
        if(ret)
            WideCharToMultiByte(CP_ACP, 0, str, -1, ret, size, NULL, NULL);
    }

    return ret;
}

__attribute__((used)) static HRESULT del_dirs_callback(HINF hinf, PCWSTR field, const void *arg)
{
    INFCONTEXT context;
    HRESULT hr = S_OK;
    DWORD size;

    BOOL ok = SetupFindFirstLineW(hinf, field, NULL, &context);
    
    for (; ok; ok = SetupFindNextLine(&context, &context))
    {
        WCHAR directory[MAX_INF_STRING_LENGTH];

        if (!SetupGetLineTextW(&context, NULL, NULL, NULL, directory,
                               MAX_INF_STRING_LENGTH, &size))
            continue;

        if (DelNodeW(directory, ADN_DEL_IF_EMPTY) != S_OK)
            hr = E_FAIL;
    }

    return hr;
}

__attribute__((used)) static HRESULT per_user_install_callback(HINF hinf, PCWSTR field, const void *arg)
{
    PERUSERSECTIONW per_user;
    INFCONTEXT context;
    DWORD size;

    static const WCHAR disp_name[] = {'D','i','s','p','l','a','y','N','a','m','e',0};
    static const WCHAR version[] = {'V','e','r','s','i','o','n',0};
    static const WCHAR is_installed[] = {'I','s','I','n','s','t','a','l','l','e','d',0};
    static const WCHAR comp_id[] = {'C','o','m','p','o','n','e','n','t','I','D',0};
    static const WCHAR guid[] = {'G','U','I','D',0};
    static const WCHAR locale[] = {'L','o','c','a','l','e',0};
    static const WCHAR stub_path[] = {'S','t','u','b','P','a','t','h',0};

    per_user.bRollback = FALSE;
    per_user.dwIsInstalled = 0;

    SetupGetLineTextW(NULL, hinf, field, disp_name, per_user.szDispName, ARRAY_SIZE(per_user.szDispName), &size);

    SetupGetLineTextW(NULL, hinf, field, version, per_user.szVersion, ARRAY_SIZE(per_user.szVersion), &size);

    if (SetupFindFirstLineW(hinf, field, is_installed, &context))
    {
        SetupGetIntField(&context, 1, (PINT)&per_user.dwIsInstalled);
    }

    SetupGetLineTextW(NULL, hinf, field, comp_id, per_user.szCompID, ARRAY_SIZE(per_user.szCompID), &size);

    SetupGetLineTextW(NULL, hinf, field, guid, per_user.szGUID, ARRAY_SIZE(per_user.szGUID), &size);

    SetupGetLineTextW(NULL, hinf, field, locale, per_user.szLocale, ARRAY_SIZE(per_user.szLocale), &size);

    SetupGetLineTextW(NULL, hinf, field, stub_path, per_user.szStub, ARRAY_SIZE(per_user.szStub), &size);

    return SetPerUserSecValuesW(&per_user);
}

__attribute__((used)) static HRESULT register_ocxs_callback(HINF hinf, PCWSTR field, const void *arg)
{
    HMODULE hm;
    INFCONTEXT context;
    HRESULT hr = S_OK;

    BOOL ok = SetupFindFirstLineW(hinf, field, NULL, &context);
    
    for (; ok; ok = SetupFindNextLine(&context, &context))
    {
        WCHAR buffer[MAX_INF_STRING_LENGTH];

        /* get OCX filename */
        if (!SetupGetStringFieldW(&context, 1, buffer, ARRAY_SIZE(buffer), NULL))
            continue;

        hm = LoadLibraryExW(buffer, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
        if (hm)
        {
            if (do_ocx_reg(hm, TRUE, NULL, NULL) != S_OK)
                hr = E_FAIL;

            FreeLibrary(hm);
        }
        else
            hr = E_FAIL;

        if (FAILED(hr))
        {
            /* FIXME: display a message box */
            break;
        }
    }

    return hr;
}

__attribute__((used)) static HRESULT run_setup_commands_callback(HINF hinf, PCWSTR field, const void *arg)
{
    const ADVInfo *info = (const ADVInfo *)arg;
    INFCONTEXT context;
    HRESULT hr = S_OK;
    DWORD size;

    BOOL ok = SetupFindFirstLineW(hinf, field, NULL, &context);

    for (; ok; ok = SetupFindNextLine(&context, &context))
    {
        WCHAR buffer[MAX_INF_STRING_LENGTH];

        if (!SetupGetLineTextW(&context, NULL, NULL, NULL, buffer,
                               MAX_INF_STRING_LENGTH, &size))
            continue;

        if (launch_exe(buffer, info->working_dir, NULL) != S_OK)
            hr = E_FAIL;
    }

    return hr;
}

LPWSTR get_parameter(LPWSTR *params, WCHAR separator, BOOL quoted)
{
    LPWSTR token = *params;

    if (!*params)
        return NULL;

    if (quoted && *token == '"')
    {
        WCHAR *end = strchrW(token + 1, '"');
        if (end)
        {
            *end = 0;
            *params = end + 1;
            token = token + 1;
        }
    }

    *params = strchrW(*params, separator);
    if (*params)
        *(*params)++ = '\0';

    if (!*token)
        return NULL;

    return token;
}

__attribute__((used)) static BOOL is_full_path(LPCWSTR path)
{
    const int MIN_PATH_LEN = 3;

    if (!path || lstrlenW(path) < MIN_PATH_LEN)
        return FALSE;

    if ((path[1] == ':' && path[2] == '\\') || (path[0] == '\\' && path[1] == '\\'))
        return TRUE;

    return FALSE;
}

__attribute__((used)) static WCHAR *get_field_string(INFCONTEXT *context, DWORD index, WCHAR *buffer,
                               const WCHAR *static_buffer, DWORD *size)
{
    DWORD required;

    if (SetupGetStringFieldW(context, index, buffer, *size, &required)) return buffer;

    if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
    {
        /* now grow the buffer */
        if (buffer != static_buffer) HeapFree(GetProcessHeap(), 0, buffer);
        if (!(buffer = HeapAlloc(GetProcessHeap(), 0, required*sizeof(WCHAR)))) return NULL;
        *size = required;
        if (SetupGetStringFieldW(context, index, buffer, *size, &required)) return buffer;
    }

    if (buffer != static_buffer) HeapFree(GetProcessHeap(), 0, buffer);
    return NULL;
}

__attribute__((used)) static HRESULT iterate_section_fields(HINF hinf, PCWSTR section, PCWSTR key,
                                      iterate_fields_func callback, void *arg)
{
    WCHAR static_buffer[200];
    WCHAR *buffer = static_buffer;
    DWORD size = ARRAY_SIZE(static_buffer);
    INFCONTEXT context;
    HRESULT hr = E_FAIL;

    BOOL ok = SetupFindFirstLineW(hinf, section, key, &context);
    while (ok)
    {
        UINT i, count = SetupGetFieldCount(&context);

        for (i = 1; i <= count; i++)
        {
            if (!(buffer = get_field_string(&context, i, buffer, static_buffer, &size)))
                goto done;

            if ((hr = callback(hinf, buffer, arg)) != S_OK)
                goto done;
        }

        ok = SetupFindNextMatchLineW(&context, key, &context);
    }

    hr = S_OK;

 done:
    if (buffer != static_buffer) HeapFree(GetProcessHeap(), 0, buffer);
    return hr;
}

__attribute__((used)) static HRESULT check_admin_rights(const ADVInfo *info)
{
    INT check;
    INFCONTEXT context;
    HRESULT hr = S_OK;

    if (!SetupFindFirstLineW(info->hinf, info->install_sec,
                             CheckAdminRights, &context))
        return S_OK;

    if (!SetupGetIntField(&context, 1, &check))
        return S_OK;

    if (check == 1)
        hr = IsNTAdmin(0, NULL) ? S_OK : E_FAIL;

    return hr;
}

__attribute__((used)) static HRESULT spapi_install(const ADVInfo *info)
{
    BOOL ret;
    HRESULT res;
    PVOID context;

    context = SetupInitDefaultQueueCallbackEx(NULL, INVALID_HANDLE_VALUE, 0, 0, NULL);
    if (!context)
        return ADV_HRESULT(GetLastError());

    ret = SetupInstallFromInfSectionW(NULL, info->hinf, info->install_sec,
                                      SPINST_FILES, NULL, info->working_dir,
                                      SP_COPY_NEWER, SetupDefaultQueueCallbackW,
                                      context, NULL, NULL);
    if (!ret)
    {
        res = ADV_HRESULT(GetLastError());
        SetupTermDefaultQueueCallback(context);

        return res;
    }

    SetupTermDefaultQueueCallback(context);

    ret = SetupInstallFromInfSectionW(NULL, info->hinf, info->install_sec,
                                      SPINST_INIFILES | SPINST_REGISTRY | SPINST_REGSVR,
                                      HKEY_LOCAL_MACHINE, NULL, 0,
                                      NULL, NULL, NULL, NULL);
    if (!ret)
        return ADV_HRESULT(GetLastError());

    return S_OK;
}

__attribute__((used)) static HRESULT adv_install(ADVInfo *info)
{
    HRESULT hr;

    hr = check_admin_rights(info);
    if (hr != S_OK)
        return hr;

    hr = iterate_section_fields(info->hinf, info->install_sec, RunPreSetupCommands,
                                run_setup_commands_callback, info);
    if (hr != S_OK)
        return hr;

    OleInitialize(NULL);
    hr = iterate_section_fields(info->hinf, info->install_sec,
                                RegisterOCXs, register_ocxs_callback, NULL);
    OleUninitialize();
    if (hr != S_OK)
        return hr;

    hr = iterate_section_fields(info->hinf, info->install_sec,
                                PerUserInstall, per_user_install_callback, info);
    if (hr != S_OK)
        return hr;

    hr = iterate_section_fields(info->hinf, info->install_sec, RunPostSetupCommands,
                                run_setup_commands_callback, info);
    if (hr != S_OK)
        return hr;

    hr = iterate_section_fields(info->hinf, info->install_sec,
                                DelDirs, del_dirs_callback, info);
    if (hr != S_OK)
        return hr;

    return hr;
}

__attribute__((used)) static HRESULT get_working_dir(ADVInfo *info, LPCWSTR inf_filename, LPCWSTR working_dir)
{
    WCHAR path[MAX_PATH];
    LPCWSTR ptr;
    DWORD len;

    static const WCHAR backslash[] = {'\\',0};
    static const WCHAR inf_dir[] = {'\\','I','N','F',0};

    if ((ptr = strrchrW(inf_filename, '\\')))
    {
        len = ptr - inf_filename + 1;
        ptr = inf_filename;
    }
    else if (working_dir && *working_dir)
    {
        len = lstrlenW(working_dir) + 1;
        ptr = working_dir;
    }
    else
    {
        GetCurrentDirectoryW(MAX_PATH, path);
        lstrcatW(path, backslash);
        lstrcatW(path, inf_filename);

        /* check if the INF file is in the current directory */
        if (GetFileAttributesW(path) != INVALID_FILE_ATTRIBUTES)
        {
            GetCurrentDirectoryW(MAX_PATH, path);
        }
        else
        {
            /* default to the windows\inf directory if all else fails */
            GetWindowsDirectoryW(path, MAX_PATH);
            lstrcatW(path, inf_dir);
        }

        len = lstrlenW(path) + 1;
        ptr = path;
    }

    info->working_dir = HeapAlloc(GetProcessHeap(), 0, len * sizeof(WCHAR));
    if (!info->working_dir)
        return E_OUTOFMEMORY;

    lstrcpynW(info->working_dir, ptr, len);

    return S_OK;
}

__attribute__((used)) static HRESULT install_init(LPCWSTR inf_filename, LPCWSTR install_sec,
                            LPCWSTR working_dir, DWORD flags, ADVInfo *info)
{
    DWORD len;
    HRESULT hr;
    LPCWSTR ptr, path;

    static const WCHAR backslash[] = {'\\',0};
    static const WCHAR default_install[] = {
        'D','e','f','a','u','l','t','I','n','s','t','a','l','l',0
    };

    if (!(ptr = strrchrW(inf_filename, '\\')))
        ptr = inf_filename;

    len = lstrlenW(ptr);

    info->inf_filename = HeapAlloc(GetProcessHeap(), 0, (len + 1) * sizeof(WCHAR));
    if (!info->inf_filename)
        return E_OUTOFMEMORY;

    lstrcpyW(info->inf_filename, ptr);

    /* FIXME: determine the proper platform to install (NTx86, etc) */
    if (!install_sec || !*install_sec)
    {
        len = sizeof(default_install) - 1;
        ptr = default_install;
    }
    else
    {
        len = lstrlenW(install_sec);
        ptr = install_sec;
    }

    info->install_sec = HeapAlloc(GetProcessHeap(), 0, (len + 1) * sizeof(WCHAR));
    if (!info->install_sec)
        return E_OUTOFMEMORY;

    lstrcpyW(info->install_sec, ptr);

    hr = get_working_dir(info, inf_filename, working_dir);
    if (FAILED(hr))
        return hr;

    len = lstrlenW(info->working_dir) + lstrlenW(info->inf_filename) + 2;
    info->inf_path = HeapAlloc(GetProcessHeap(), 0, len * sizeof(WCHAR));
    if (!info->inf_path)
        return E_OUTOFMEMORY;

    lstrcpyW(info->inf_path, info->working_dir);
    lstrcatW(info->inf_path, backslash);
    lstrcatW(info->inf_path, info->inf_filename);

    /* RunSetupCommand opens unmodifed filename parameter */
    if (flags & RSC_FLAG_INF)
        path = inf_filename;
    else
        path = info->inf_path;

    info->hinf = SetupOpenInfFileW(path, NULL, INF_STYLE_WIN4, NULL);
    if (info->hinf == INVALID_HANDLE_VALUE)
        return ADV_HRESULT(GetLastError());

    set_ldids(info->hinf, info->install_sec, info->working_dir);

    /* FIXME: check that the INF is advanced */

    info->flags = flags;
    info->need_reboot = FALSE;

    return S_OK;
}

__attribute__((used)) static void install_release(const ADVInfo *info)
{
    SetupCloseInfFile(info->hinf);

    HeapFree(GetProcessHeap(), 0, info->inf_path);
    HeapFree(GetProcessHeap(), 0, info->inf_filename);
    HeapFree(GetProcessHeap(), 0, info->install_sec);
    HeapFree(GetProcessHeap(), 0, info->working_dir);
}

__attribute__((used)) static HRESULT DoInfInstallW(const SETUPCOMMAND_PARAMSW *setup)
{
    ADVInfo info;
    HRESULT hr;

    TRACE("(%p)\n", setup);

    ZeroMemory(&info, sizeof(ADVInfo));

    hr = install_init(setup->inf_name, setup->section_name, setup->dir, 0, &info);
    if (hr != S_OK)
        goto done;

    hr = spapi_install(&info);
    if (hr != S_OK)
        goto done;

    hr = adv_install(&info);

done:
    install_release(&info);

    return S_OK;
}

