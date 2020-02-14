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
typedef  int WCHAR ;
typedef  int REGEDIT_ACTION ;
typedef  int* LPWSTR ;
typedef  char* LPCWSTR ;
typedef  int /*<<< orphan*/  FILE ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
#define  ACTION_ADD 132 
#define  ACTION_DELETE 131 
#define  ACTION_EXPORT 130 
 int ACTION_UNDEF ; 
 int /*<<< orphan*/  COUNT_OF (int*) ; 
 int /*<<< orphan*/  FALSE ; 
#define  IDCANCEL 129 
#define  IDNO 128 
 int /*<<< orphan*/  IDS_IMPORT_ERROR ; 
 int /*<<< orphan*/  IDS_IMPORT_OK ; 
 int /*<<< orphan*/  IDS_IMPORT_PROMPT ; 
 int InfoMessageBox (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,...) ; 
 int KEY_MAX_LEN ; 
 int /*<<< orphan*/  LoadStringW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int /*<<< orphan*/ ) ; 
 int MAX_PATH ; 
 int MB_ICONERROR ; 
 int MB_ICONINFORMATION ; 
 int MB_ICONWARNING ; 
 int MB_OK ; 
 int MB_YESNOCANCEL ; 
 int /*<<< orphan*/  REG_FORMAT_4 ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/ * _wfopen (int*,char*) ; 
 int /*<<< orphan*/  delete_registry_key (int*) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  export_registry_key (int*,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fwprintf (int /*<<< orphan*/ ,char*,char*,...) ; 
 int /*<<< orphan*/  hInst ; 
 int /*<<< orphan*/  import_registry_file (int /*<<< orphan*/ *) ; 
 scalar_t__ iswalpha (int) ; 
 scalar_t__ iswspace (int) ; 
 int /*<<< orphan*/  memcpy (int*,int*,size_t) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/ * szTitle ; 
 int towupper (int) ; 
 char* usage ; 

LPCWSTR getAppName(void)
{
    return L"regedit";
}

void get_file_name(LPWSTR *command_line, LPWSTR file_name)
{
    WCHAR *s = *command_line;
    size_t pos = 0; /* position of pointer "s" in *command_line */
    file_name[0] = 0;

    if (!s[0])
    {
        return;
    }

    if (s[0] == L'"')
    {
        s++;
        (*command_line)++;
        while(s[0] != L'"')
        {
            if (!s[0])
            {
                fwprintf(stderr, L"%s: Unexpected end of file name!\n", getAppName());
                exit(1);
            }
            s++;
            pos++;
        }
    }
    else
    {
        while(s[0] && !iswspace(s[0]))
        {
            s++;
            pos++;
        }
    }
    memcpy(file_name, *command_line, pos * sizeof(WCHAR));
    /* remove the last backslash */
    if (file_name[pos - 1] == L'\\')
    {
        file_name[pos - 1] = L'\0';
    }
    else
    {
        file_name[pos] = L'\0';
    }

    if (s[0])
    {
        s++;
        pos++;
    }
    while(s[0] && iswspace(s[0]))
    {
        s++;
        pos++;
    }
    (*command_line) += pos;
}

BOOL PerformRegAction(REGEDIT_ACTION action, LPWSTR s, BOOL silent)
{
    switch (action)
    {
        case ACTION_ADD:
        {
            WCHAR szText[512];
            WCHAR filename[MAX_PATH];
            FILE *fp;

            get_file_name(&s, filename);
            if (!filename[0])
            {
                InfoMessageBox(NULL, MB_OK | MB_ICONINFORMATION, NULL, L"No file name is specified.");
                InfoMessageBox(NULL, MB_OK | MB_ICONINFORMATION, szTitle, usage);
                exit(4);
            }

            while (filename[0])
            {
                /* Request import confirmation */
                if (!silent)
                {
                    int choice;

                    LoadStringW(hInst, IDS_IMPORT_PROMPT, szText, COUNT_OF(szText));

                    choice = InfoMessageBox(NULL, MB_YESNOCANCEL | MB_ICONWARNING, szTitle, szText, filename);

                    switch (choice)
                    {
                        case IDNO:
                            goto cont;
                        case IDCANCEL:
                            /* The cancel case is useful if the user is importing more than one registry file
                            at a time, and wants to back out anytime during the import process. This way, the
                            user doesn't have to resort to ending the regedit process abruptly just to cancel
                            the operation. */
                            return TRUE;
                        default:
                            break;
                    }
                }

                /* Open the file */
                fp = _wfopen(filename, L"r");

                /* Import it */
                if (fp == NULL || !import_registry_file(fp))
                {
                    /* Error opening the file */
                    if (!silent)
                    {
                        LoadStringW(hInst, IDS_IMPORT_ERROR, szText, COUNT_OF(szText));
                        InfoMessageBox(NULL, MB_OK | MB_ICONERROR, szTitle, szText, filename);
                    }
                }
                else
                {
                    /* Show successful import */
                    if (!silent)
                    {
                        LoadStringW(hInst, IDS_IMPORT_OK, szText, COUNT_OF(szText));
                        InfoMessageBox(NULL, MB_OK | MB_ICONINFORMATION, szTitle, szText, filename);
                    }
                }

                /* Close the file */
                if (fp) fclose(fp);

cont:
                get_file_name(&s, filename);
            }
            break;
        }

        case ACTION_DELETE:
        {
            WCHAR reg_key_name[KEY_MAX_LEN];
            get_file_name(&s, reg_key_name);
            if (!reg_key_name[0])
            {
                InfoMessageBox(NULL, MB_OK | MB_ICONINFORMATION, NULL, L"No registry key is specified for removal.");
                InfoMessageBox(NULL, MB_OK | MB_ICONINFORMATION, szTitle, usage);
                exit(6);
            }
            delete_registry_key(reg_key_name);
            break;
        }

        case ACTION_EXPORT:
        {
            WCHAR filename[MAX_PATH];

            filename[0] = L'\0';
            get_file_name(&s, filename);
            if (!filename[0])
            {
                InfoMessageBox(NULL, MB_OK | MB_ICONINFORMATION, NULL, L"No file name is specified.");
                InfoMessageBox(NULL, MB_OK | MB_ICONINFORMATION, szTitle, usage);
                exit(7);
            }

            if (s[0])
            {
                WCHAR reg_key_name[KEY_MAX_LEN];
                get_file_name(&s, reg_key_name);
                export_registry_key(filename, reg_key_name, REG_FORMAT_4);
            }
            else
            {
                export_registry_key(filename, NULL, REG_FORMAT_4);
            }
            break;
        }

        default:
            fwprintf(stderr, L"%s: Unhandled action!\n", getAppName());
            exit(8);
            break;
    }

    return TRUE;
}

__attribute__((used)) static void error_unknown_switch(WCHAR chu, LPWSTR s)
{
    if (iswalpha(chu))
    {
        fwprintf(stderr, L"%s: Undefined switch /%c!\n", getAppName(), chu);
    }
    else
    {
        fwprintf(stderr, L"%s: Alphabetic character is expected after '%c' "
                          L"in switch specification\n", getAppName(), *(s - 1));
    }
    exit(1);
}

BOOL ProcessCmdLine(LPWSTR lpCmdLine)
{
    BOOL silent = FALSE;
    REGEDIT_ACTION action = ACTION_UNDEF;
    LPWSTR s = lpCmdLine;       /* command line pointer */
    WCHAR ch = *s;              /* current character */

    while (ch && ((ch == L'-') || (ch == L'/')))
    {
        WCHAR chu;
        WCHAR ch2;

        s++;
        ch = *s;
        ch2 = *(s + 1);
        chu = towupper(ch);
        if (!ch2 || iswspace(ch2))
        {
            if (chu == L'S')
            {
                /* Silence dialogs */
                silent = TRUE;
            }
            else if (chu == L'V')
            {
                /* Ignore this switch */
            }
            else
            {
                switch (chu)
                {
                    case L'D':
                        action = ACTION_DELETE;
                        break;
                    case L'E':
                        action = ACTION_EXPORT;
                        break;
                    case L'?':
                        InfoMessageBox(NULL, MB_OK | MB_ICONINFORMATION, szTitle, usage);
                        exit(3);
                        break;
                    default:
                        error_unknown_switch(chu, s);
                        break;
                }
            }
            s++;
        }
        else
        {
            if (ch2 == L':')
            {
                switch (chu)
                {
                    case L'L':
                        /* fall through */
                    case L'R':
                        s += 2;
                        while (*s && !iswspace(*s))
                        {
                            s++;
                        }
                        break;
                    default:
                        error_unknown_switch(chu, s);
                        break;
                }
            }
            else
            {
                /* this is a file name, starting from '/' */
                s--;
                break;
            }
        }
        /* skip spaces to the next parameter */
        ch = *s;
        while (ch && iswspace(ch))
        {
            s++;
            ch = *s;
        }
    }

    if (*s && action == ACTION_UNDEF)
        action = ACTION_ADD;

    if (action != ACTION_UNDEF)
        return PerformRegAction(action, s, silent);
    else
        return FALSE;
}

