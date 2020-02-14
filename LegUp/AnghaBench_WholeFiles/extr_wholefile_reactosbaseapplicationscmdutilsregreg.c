#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  enum operations { ____Placeholder_operations } operations ;
typedef  int /*<<< orphan*/  __ms_va_list ;
typedef  char WCHAR ;
struct TYPE_3__ {scalar_t__ key; char* long_name; } ;
typedef  scalar_t__ LONG ;
typedef  scalar_t__ HKEY ;
typedef  scalar_t__ DWORD ;
typedef  char BYTE ;
typedef  void* BOOL ;

/* Variables and functions */
 scalar_t__ ARRAY_SIZE (TYPE_1__*) ; 
 int /*<<< orphan*/  ERR (char*) ; 
 scalar_t__ ERROR_FILE_NOT_FOUND ; 
 scalar_t__ ERROR_MORE_DATA ; 
 scalar_t__ ERROR_SUCCESS ; 
 void* FALSE ; 
 int FORMAT_MESSAGE_ALLOCATE_BUFFER ; 
 int FORMAT_MESSAGE_FROM_STRING ; 
 scalar_t__ FormatMessageW (int,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  GetConsoleOutputCP () ; 
 scalar_t__ GetLastError () ; 
 int /*<<< orphan*/  GetStdHandle (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  KEY_READ ; 
 int /*<<< orphan*/  LocalFree (char*) ; 
 int MAX_SUBKEY_LEN ; 
 scalar_t__ NO_ERROR ; 
#define  REG_ADD 137 
#define  REG_DELETE 136 
#define  REG_EXPORT 135 
#define  REG_IMPORT 134 
 int REG_INVALID ; 
#define  REG_QUERY 133 
 scalar_t__ REG_SZ ; 
 int /*<<< orphan*/  RegCloseKey (scalar_t__) ; 
 scalar_t__ RegEnumKeyExW (scalar_t__,scalar_t__,char*,scalar_t__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ RegEnumValueW (scalar_t__,scalar_t__,char*,scalar_t__*,int /*<<< orphan*/ *,scalar_t__*,char*,scalar_t__*) ; 
 scalar_t__ RegOpenKeyExW (scalar_t__,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__*) ; 
 scalar_t__ RegQueryValueExW (scalar_t__,char*,int /*<<< orphan*/ *,scalar_t__*,char*,scalar_t__*) ; 
 int /*<<< orphan*/  STD_OUTPUT_HANDLE ; 
#define  STRING_ADD_USAGE 132 
 int STRING_CANNOT_FIND ; 
#define  STRING_DELETE_USAGE 131 
#define  STRING_EXPORT_USAGE 130 
 int /*<<< orphan*/  STRING_FUNC_HELP ; 
#define  STRING_IMPORT_USAGE 129 
 int STRING_INVALID_CMDLINE ; 
 int /*<<< orphan*/  STRING_INVALID_OPTION ; 
 int STRING_INVALID_SYNTAX ; 
 int /*<<< orphan*/  STRING_INVALID_SYSTEM_KEY ; 
 int /*<<< orphan*/  STRING_MATCHES_FOUND ; 
#define  STRING_QUERY_USAGE 128 
 int STRING_REG_HELP ; 
 int STRING_USAGE ; 
 int /*<<< orphan*/  SetLastError (scalar_t__) ; 
 void* TRUE ; 
 int /*<<< orphan*/  WINE_FIXME (char*,scalar_t__,int /*<<< orphan*/ ) ; 
 scalar_t__ WideCharToMultiByte (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*,scalar_t__,char*,scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ WriteConsoleW (int /*<<< orphan*/ ,char const*,scalar_t__,scalar_t__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  WriteFile (int /*<<< orphan*/ ,char*,scalar_t__,scalar_t__*,void*) ; 
 char* build_subkey_path (char*,scalar_t__,char*,scalar_t__) ; 
 int /*<<< orphan*/  exit (int) ; 
 void* heap_alloc (size_t) ; 
 int /*<<< orphan*/  heap_free (char*) ; 
 void* heap_realloc (void*,size_t) ; 
 int /*<<< orphan*/  lstrcmpiW (char const*,char const*) ; 
 int /*<<< orphan*/  newlineW ; 
 int /*<<< orphan*/  num_values_found ; 
 int /*<<< orphan*/  output_message (int,...) ; 
 int /*<<< orphan*/  output_string (char*,...) ; 
 int /*<<< orphan*/  output_value (char*,scalar_t__,char*,scalar_t__) ; 
 scalar_t__ path_get_rootkey (char const*) ; 
 int reg_add (scalar_t__,char*,char*,void*,char*,char,char*,void*) ; 
 int reg_delete (scalar_t__,char*,char*,char*,void*,void*,void*) ; 
 int reg_export (int,char**) ; 
 int reg_import (char*) ; 
 TYPE_1__* root_rels ; 
 int /*<<< orphan*/  sane_path (char const*) ; 
 int /*<<< orphan*/  sprintfW (char*,char*,char*,char*) ; 
 char* strchrW (char const*,char) ; 
 int /*<<< orphan*/  strcpyW (char*,char*) ; 
 int strlenW (char const*) ; 
 int /*<<< orphan*/  struprW (char*) ; 
 int tolowerW (char) ; 
 char const toupperW (char const) ; 
 int /*<<< orphan*/  wine_dbgstr_w (char const*) ; 

void *heap_xalloc(size_t size)
{
    void *buf = heap_alloc(size);
    if (!buf)
    {
        ERR("Out of memory!\n");
        exit(1);
    }
    return buf;
}

void *heap_xrealloc(void *buf, size_t size)
{
    void *new_buf = heap_realloc(buf, size);

    if (!new_buf)
    {
        ERR("Out of memory!\n");
        exit(1);
    }

    return new_buf;
}

void output_writeconsole(const WCHAR *str, DWORD wlen)
{
    DWORD count, ret;

    ret = WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), str, wlen, &count, NULL);
    if (!ret)
    {
        DWORD len;
        char  *msgA;

        /* On Windows WriteConsoleW() fails if the output is redirected. So fall
         * back to WriteFile(), assuming the console encoding is still the right
         * one in that case.
         */
        len = WideCharToMultiByte(GetConsoleOutputCP(), 0, str, wlen, NULL, 0, NULL, NULL);
        msgA = heap_xalloc(len);

        WideCharToMultiByte(GetConsoleOutputCP(), 0, str, wlen, msgA, len, NULL, NULL);
        WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), msgA, len, &count, FALSE);
        heap_free(msgA);
    }
}

__attribute__((used)) static void output_formatstring(const WCHAR *fmt, __ms_va_list va_args)
{
    WCHAR *str;
    DWORD len;

    SetLastError(NO_ERROR);
    len = FormatMessageW(FORMAT_MESSAGE_FROM_STRING|FORMAT_MESSAGE_ALLOCATE_BUFFER,
                         fmt, 0, 0, (WCHAR *)&str, 0, &va_args);
    if (len == 0 && GetLastError() != NO_ERROR)
    {
        WINE_FIXME("Could not format string: le=%u, fmt=%s\n", GetLastError(), wine_dbgstr_w(fmt));
        return;
    }
    output_writeconsole(str, len);
    LocalFree(str);
}

__attribute__((used)) static int query_value(HKEY key, WCHAR *value_name, WCHAR *path, BOOL recurse)
{
    LONG rc;
    DWORD max_data_bytes = 2048, data_size;
    DWORD subkey_len;
    DWORD type, path_len, i;
    BYTE *data;
    WCHAR fmt[] = {'%','1','\n',0};
    WCHAR *subkey_name, *subkey_path;
    HKEY subkey;

    data = heap_xalloc(max_data_bytes);

    for (;;)
    {
        data_size = max_data_bytes;
        rc = RegQueryValueExW(key, value_name, NULL, &type, data, &data_size);
        if (rc == ERROR_MORE_DATA)
        {
            max_data_bytes = data_size;
            data = heap_xrealloc(data, max_data_bytes);
        }
        else break;
    }

    if (rc == ERROR_SUCCESS)
    {
        output_string(fmt, path);
        output_value(value_name, type, data, data_size);
        output_string(newlineW);
        num_values_found++;
    }

    heap_free(data);

    if (!recurse)
    {
        if (rc == ERROR_FILE_NOT_FOUND)
        {
            if (value_name && *value_name)
            {
                output_message(STRING_CANNOT_FIND);
                return 1;
            }
            output_string(fmt, path);
            output_value(NULL, REG_SZ, NULL, 0);
        }
        return 0;
    }

    subkey_name = heap_xalloc(MAX_SUBKEY_LEN * sizeof(WCHAR));

    path_len = strlenW(path);

    i = 0;
    for (;;)
    {
        subkey_len = MAX_SUBKEY_LEN;
        rc = RegEnumKeyExW(key, i, subkey_name, &subkey_len, NULL, NULL, NULL, NULL);
        if (rc == ERROR_SUCCESS)
        {
            subkey_path = build_subkey_path(path, path_len, subkey_name, subkey_len);
            if (!RegOpenKeyExW(key, subkey_name, 0, KEY_READ, &subkey))
            {
                query_value(subkey, value_name, subkey_path, recurse);
                RegCloseKey(subkey);
            }
            heap_free(subkey_path);
            i++;
        }
        else break;
    }

    heap_free(subkey_name);
    return 0;
}

__attribute__((used)) static int query_all(HKEY key, WCHAR *path, BOOL recurse)
{
    LONG rc;
    DWORD max_value_len = 256, value_len;
    DWORD max_data_bytes = 2048, data_size;
    DWORD subkey_len;
    DWORD i, type, path_len;
    WCHAR fmt[] = {'%','1','\n',0};
    WCHAR fmt_path[] = {'%','1','\\','%','2','\n',0};
    WCHAR *value_name, *subkey_name, *subkey_path;
    BYTE *data;
    HKEY subkey;

    output_string(fmt, path);

    value_name = heap_xalloc(max_value_len * sizeof(WCHAR));
    data = heap_xalloc(max_data_bytes);

    i = 0;
    for (;;)
    {
        value_len = max_value_len;
        data_size = max_data_bytes;
        rc = RegEnumValueW(key, i, value_name, &value_len, NULL, &type, data, &data_size);
        if (rc == ERROR_SUCCESS)
        {
            output_value(value_name, type, data, data_size);
            i++;
        }
        else if (rc == ERROR_MORE_DATA)
        {
            if (data_size > max_data_bytes)
            {
                max_data_bytes = data_size;
                data = heap_xrealloc(data, max_data_bytes);
            }
            else
            {
                max_value_len *= 2;
                value_name = heap_xrealloc(value_name, max_value_len * sizeof(WCHAR));
            }
        }
        else break;
    }

    heap_free(data);
    heap_free(value_name);

    if (i || recurse)
        output_string(newlineW);

    subkey_name = heap_xalloc(MAX_SUBKEY_LEN * sizeof(WCHAR));

    path_len = strlenW(path);

    i = 0;
    for (;;)
    {
        subkey_len = MAX_SUBKEY_LEN;
        rc = RegEnumKeyExW(key, i, subkey_name, &subkey_len, NULL, NULL, NULL, NULL);
        if (rc == ERROR_SUCCESS)
        {
            if (recurse)
            {
                subkey_path = build_subkey_path(path, path_len, subkey_name, subkey_len);
                if (!RegOpenKeyExW(key, subkey_name, 0, KEY_READ, &subkey))
                {
                    query_all(subkey, subkey_path, recurse);
                    RegCloseKey(subkey);
                }
                heap_free(subkey_path);
            }
            else output_string(fmt_path, path, subkey_name);
            i++;
        }
        else break;
    }

    heap_free(subkey_name);

    if (i && !recurse)
        output_string(newlineW);

    return 0;
}

__attribute__((used)) static int reg_query(HKEY root, WCHAR *path, WCHAR *key_name, WCHAR *value_name,
                     BOOL value_empty, BOOL recurse)
{
    HKEY key;
    int ret;

    if (RegOpenKeyExW(root, path, 0, KEY_READ, &key) != ERROR_SUCCESS)
    {
        output_message(STRING_CANNOT_FIND);
        return 1;
    }

    output_string(newlineW);

    if (value_name || value_empty)
    {
        ret = query_value(key, value_name, key_name, recurse);
        if (recurse)
            output_message(STRING_MATCHES_FOUND, num_values_found);
    }
    else
        ret = query_all(key, key_name, recurse);

    RegCloseKey(key);

    return ret;
}

__attribute__((used)) static WCHAR *get_long_key(HKEY root, WCHAR *path)
{
    DWORD i, array_size = ARRAY_SIZE(root_rels), len;
    WCHAR *long_key;
    WCHAR fmt[] = {'%','s','\\','%','s',0};

    for (i = 0; i < array_size; i++)
    {
        if (root == root_rels[i].key)
            break;
    }

    len = strlenW(root_rels[i].long_name);

    if (!path)
    {
        long_key = heap_xalloc((len + 1) * sizeof(WCHAR));
        strcpyW(long_key, root_rels[i].long_name);
        return long_key;
    }

    len += strlenW(path) + 1; /* add one for the backslash */
    long_key = heap_xalloc((len + 1) * sizeof(WCHAR));
    sprintfW(long_key, fmt, root_rels[i].long_name, path);
    return long_key;
}

BOOL parse_registry_key(const WCHAR *key, HKEY *root, WCHAR **path, WCHAR **long_key)
{
    if (!sane_path(key))
        return FALSE;

    *path = strchrW(key, '\\');
    if (*path) (*path)++;

    *root = path_get_rootkey(key);
    if (!*root)
    {
        if (*path) *(*path - 1) = 0;
        output_message(STRING_INVALID_SYSTEM_KEY, key);
        return FALSE;
    }

    *long_key = get_long_key(*root, *path);

    return TRUE;
}

__attribute__((used)) static BOOL is_switch(const WCHAR *s, const WCHAR c)
{
    if (strlenW(s) > 2)
        return FALSE;

    if ((s[0] == '/' || s[0] == '-') && (s[1] == c || s[1] == toupperW(c)))
        return TRUE;

    return FALSE;
}

__attribute__((used)) static BOOL is_help_switch(const WCHAR *s)
{
    if (is_switch(s, '?') || is_switch(s, 'h'))
        return TRUE;

    return FALSE;
}

__attribute__((used)) static enum operations get_operation(const WCHAR *str, int *op_help)
{
    struct op_info { const WCHAR *op; int id; int help_id; };

    static const WCHAR add[] = {'a','d','d',0};
    static const WCHAR delete[] = {'d','e','l','e','t','e',0};
    static const WCHAR import[] = {'i','m','p','o','r','t',0};
    static const WCHAR export[] = {'e','x','p','o','r','t',0};
    static const WCHAR query[] = {'q','u','e','r','y',0};

    static const struct op_info op_array[] =
    {
        { add,     REG_ADD,     STRING_ADD_USAGE },
        { delete,  REG_DELETE,  STRING_DELETE_USAGE },
        { import,  REG_IMPORT,  STRING_IMPORT_USAGE },
        { export,  REG_EXPORT,  STRING_EXPORT_USAGE },
        { query,   REG_QUERY,   STRING_QUERY_USAGE },
        { NULL,    -1,          0 }
    };

    const struct op_info *ptr;

    for (ptr = op_array; ptr->op; ptr++)
    {
        if (!lstrcmpiW(str, ptr->op))
        {
            *op_help = ptr->help_id;
            return ptr->id;
        }
    }

    return REG_INVALID;
}

int wmain(int argc, WCHAR *argvW[])
{
    int i, op, op_help, ret;
    BOOL show_op_help = FALSE;
    static const WCHAR switchVAW[] = {'v','a',0};
    static const WCHAR switchVEW[] = {'v','e',0};
    WCHAR *key_name, *path, *value_name = NULL, *type = NULL, *data = NULL, separator = '\0';
    BOOL value_empty = FALSE, value_all = FALSE, recurse = FALSE, force = FALSE;
    HKEY root;

    if (argc == 1)
    {
        output_message(STRING_INVALID_SYNTAX);
        output_message(STRING_REG_HELP);
        return 1;
    }

    if (is_help_switch(argvW[1]))
    {
        output_message(STRING_USAGE);
        return 0;
    }

    op = get_operation(argvW[1], &op_help);

    if (op == REG_INVALID)
    {
        output_message(STRING_INVALID_OPTION, argvW[1]);
        output_message(STRING_REG_HELP);
        return 1;
    }

    if (argc > 2)
        show_op_help = is_help_switch(argvW[2]);

    if (argc == 2 || ((show_op_help || op == REG_IMPORT) && argc > 3))
    {
        output_message(STRING_INVALID_SYNTAX);
        output_message(STRING_FUNC_HELP, struprW(argvW[1]));
        return 1;
    }
    else if (show_op_help)
    {
        output_message(op_help);
        return 0;
    }

    if (op == REG_IMPORT)
        return reg_import(argvW[2]);

    if (op == REG_EXPORT)
        return reg_export(argc, argvW);

    if (!parse_registry_key(argvW[2], &root, &path, &key_name))
        return 1;

    for (i = 3; i < argc; i++)
    {
        if (argvW[i][0] == '/' || argvW[i][0] == '-')
        {
            WCHAR *ptr = &argvW[i][1];

            if (!lstrcmpiW(ptr, switchVEW))
            {
                value_empty = TRUE;
                continue;
            }
            else if (!lstrcmpiW(ptr, switchVAW))
            {
                value_all = TRUE;
                continue;
            }
            else if (!ptr[0] || ptr[1])
            {
                output_message(STRING_INVALID_CMDLINE);
                return 1;
            }

            switch(tolowerW(argvW[i][1]))
            {
            case 'v':
                if (value_name || !(value_name = argvW[++i]))
                {
                    output_message(STRING_INVALID_CMDLINE);
                    return 1;
                }
                break;
            case 't':
                if (type || !(type = argvW[++i]))
                {
                    output_message(STRING_INVALID_CMDLINE);
                    return 1;
                }
                break;
            case 'd':
                if (data || !(data = argvW[++i]))
                {
                    output_message(STRING_INVALID_CMDLINE);
                    return 1;
                }
                break;
            case 's':
                if (op == REG_QUERY)
                {
                    recurse = TRUE;
                    break;
                }

                ptr = argvW[++i];
                if (!ptr || strlenW(ptr) != 1)
                {
                    output_message(STRING_INVALID_CMDLINE);
                    return 1;
                }
                separator = ptr[0];
                break;
            case 'f':
                force = TRUE;
                break;
            default:
                output_message(STRING_INVALID_CMDLINE);
                return 1;
            }
        }
    }

    if ((value_name && value_empty) || (value_name && value_all) || (value_empty && value_all))
    {
        output_message(STRING_INVALID_CMDLINE);
        return 1;
    }

    if (op == REG_ADD)
        ret = reg_add(root, path, value_name, value_empty, type, separator, data, force);
    else if (op == REG_DELETE)
        ret = reg_delete(root, path, key_name, value_name, value_empty, value_all, force);
    else
        ret = reg_query(root, path, key_name, value_name, value_empty, recurse);
    return ret;
}

