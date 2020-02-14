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
typedef  char WCHAR ;
typedef  char* PWSTR ;
typedef  char* PCWSTR ;
typedef  char* LPWSTR ;
typedef  int /*<<< orphan*/ * LPCWSTR ;
typedef  int /*<<< orphan*/  LPBYTE ;
typedef  int /*<<< orphan*/  INFCONTEXT ;
typedef  int /*<<< orphan*/ * HKEY ;
typedef  int /*<<< orphan*/ * HINF ;
typedef  int DWORD ;

/* Variables and functions */
 int /*<<< orphan*/  CP_ACP ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  FIXME (char*) ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 int /*<<< orphan*/ * HKEY_CURRENT_USER ; 
 int /*<<< orphan*/ * HKEY_LOCAL_MACHINE ; 
 char* HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int MAX_FIELD_LENGTH ; 
 int MAX_PATH ; 
 int PREFIX_LEN ; 
 int /*<<< orphan*/  RegCloseKey (int /*<<< orphan*/ *) ; 
 scalar_t__ RegOpenKeyW (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ **) ; 
 scalar_t__ RegQueryValueExW (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  SetupFindFirstLineW (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ SetupFindNextLine (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SetupGetLineTextW (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,char const*,char*,int,int*) ; 
 int /*<<< orphan*/  SetupGetStringFieldW (int /*<<< orphan*/ *,int,char*,int,int*) ; 
 int /*<<< orphan*/  SetupSetDirectoryIdW (int /*<<< orphan*/ *,int,char*) ; 
 size_t WideCharToMultiByte (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*,int,char*,size_t,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int atolW (char*) ; 
 char* get_parameter (char**,char,int /*<<< orphan*/ ) ; 
 char* heap_alloc (size_t) ; 
 int /*<<< orphan*/  lstrcmpW (char*,char const*) ; 
 int /*<<< orphan*/  lstrcmpiW (char*,char const*) ; 
 int /*<<< orphan*/  lstrcpynW (char*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  memmove (char*,char*,int) ; 
 char* strchrW (char*,char) ; 

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

__attribute__((used)) static void strip_quotes(WCHAR *buffer, DWORD *size)
{
    if (buffer[0] == '\'' && (*size > 1) && buffer[*size-2]=='\'')
    {
        *size -= 2;
        buffer[*size] = 0x00;
        memmove(buffer, buffer + 1, *size * sizeof(WCHAR));
    }
}

__attribute__((used)) static void get_dest_dir(HINF hInf, PCWSTR pszSection, PWSTR pszBuffer, DWORD dwSize)
{
    INFCONTEXT context;
    WCHAR key[MAX_PATH + 2], value[MAX_PATH + 2];
    WCHAR prefix[PREFIX_LEN + 2];
    HKEY root, subkey = 0;
    DWORD size;

    static const WCHAR hklm[] = {'H','K','L','M',0};
    static const WCHAR hkcu[] = {'H','K','C','U',0};

    /* load the destination parameters */
    SetupFindFirstLineW(hInf, pszSection, NULL, &context);
    SetupGetStringFieldW(&context, 1, prefix, PREFIX_LEN + 2, &size);
    strip_quotes(prefix, &size);
    SetupGetStringFieldW(&context, 2, key, MAX_PATH + 2, &size);
    strip_quotes(key, &size);
    SetupGetStringFieldW(&context, 3, value, MAX_PATH + 2, &size);
    strip_quotes(value, &size);

    if (!lstrcmpW(prefix, hklm))
        root = HKEY_LOCAL_MACHINE;
    else if (!lstrcmpW(prefix, hkcu))
        root = HKEY_CURRENT_USER;
    else
        root = NULL;

    size = dwSize * sizeof(WCHAR);

    /* fallback to the default destination dir if reg fails */
    if (RegOpenKeyW(root, key, &subkey) ||
        RegQueryValueExW(subkey, value, NULL, NULL, (LPBYTE)pszBuffer, &size))
    {
        SetupGetStringFieldW(&context, 5, pszBuffer, dwSize, &size);
        strip_quotes(pszBuffer, &size);
    }

    if (subkey) RegCloseKey(subkey);
}

void set_ldids(HINF hInf, LPCWSTR pszInstallSection, LPCWSTR pszWorkingDir)
{
    WCHAR field[MAX_FIELD_LENGTH];
    WCHAR line[MAX_FIELD_LENGTH];
    WCHAR dest[MAX_PATH];
    INFCONTEXT context;
    DWORD size;
    int ldid;

    static const WCHAR source_dir[] = {'S','o','u','r','c','e','D','i','r',0};

    static const WCHAR custDestW[] = {
        'C','u','s','t','o','m','D','e','s','t','i','n','a','t','i','o','n',0
    };

    if (!SetupGetLineTextW(NULL, hInf, pszInstallSection, custDestW,
                           field, MAX_FIELD_LENGTH, &size))
        return;

    if (!SetupFindFirstLineW(hInf, field, NULL, &context))
        return;

    do
    {
        LPWSTR value, ptr, key, key_copy = NULL;
        DWORD flags = 0;

        SetupGetLineTextW(&context, NULL, NULL, NULL,
                          line, MAX_FIELD_LENGTH, &size);

        /* SetupGetLineTextW returns the value if there is only one key, but
         * returns the whole line if there is more than one key
         */
        if (!(value = strchrW(line, '=')))
        {
            SetupGetStringFieldW(&context, 0, NULL, 0, &size);
            key = HeapAlloc(GetProcessHeap(), 0, size * sizeof(WCHAR));
            key_copy = key;
            SetupGetStringFieldW(&context, 0, key, size, &size);
            value = line;
        }
        else
        {
            key = line;
            *(value++) = '\0';
        }

        /* remove leading whitespace from the value */
        while (*value == ' ')
            value++;

        /* Extract the flags */
        ptr = strchrW(value, ',');
        if (ptr) {
            *ptr = '\0';
            flags = atolW(ptr+1);
        }

        /* set dest to pszWorkingDir if key is SourceDir */
        if (pszWorkingDir && !lstrcmpiW(value, source_dir))
            lstrcpynW(dest, pszWorkingDir, MAX_PATH);
        else
            get_dest_dir(hInf, value, dest, MAX_PATH);

        /* If prompting required, provide dialog to request path */
        if (flags & 0x04)
            FIXME("Need to support changing paths - default will be used\n");

        /* set all ldids to dest */
        while ((ptr = get_parameter(&key, ',', FALSE)))
        {
            ldid = atolW(ptr);
            SetupSetDirectoryIdW(hInf, ldid, dest);
        }
        HeapFree(GetProcessHeap(), 0, key_copy);
    } while (SetupFindNextLine(&context, &context));
}

