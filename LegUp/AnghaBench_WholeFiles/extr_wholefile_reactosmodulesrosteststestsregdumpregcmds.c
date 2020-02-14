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
typedef  char TCHAR ;
typedef  int REGEDIT_ACTION ;
typedef  char* LPSTR ;
typedef  char CHAR ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
#define  ACTION_ADD 130 
#define  ACTION_DELETE 129 
#define  ACTION_EXPORT 128 
 int ACTION_UNDEF ; 
 int ACTION_VIEW ; 
 int /*<<< orphan*/  FALSE ; 
 int KEY_MAX_LEN ; 
 int MAX_PATH ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  delete_registry_key (char*) ; 
 int /*<<< orphan*/  export_registry_key (char*,char*) ; 
 int /*<<< orphan*/  get_file_name (char**,char*,int) ; 
 int /*<<< orphan*/  import_registry_file (char*) ; 
 scalar_t__ isalpha (char) ; 
 scalar_t__ isspace (char) ; 
 int /*<<< orphan*/  perror (char*) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 char toupper (char) ; 
 char* usage ; 

void error_unknown_switch(char chu, char *s)
{
    if (isalpha(chu)) {
        printf("Undefined switch /%c!\n", chu);
    } else {
        printf("Alphabetic character is expected after '%c' "
               "in switch specification\n", *(s - 1));
    }
    //exit(1);
}

BOOL PerformRegAction(REGEDIT_ACTION action, LPSTR s)
{
    TCHAR filename[MAX_PATH];
    TCHAR reg_key_name[KEY_MAX_LEN];

    switch (action) {
    case ACTION_ADD:
        get_file_name(&s, filename, MAX_PATH);
        if (!filename[0]) {
            printf("No file name is specified\n%s", usage);
            return FALSE;
            //exit(1);
        }
        while (filename[0]) {
            if (!import_registry_file(filename)) {
                perror("");
                printf("Can't open file \"%s\"\n", filename);
                return FALSE;
                //exit(1);
            }
            get_file_name(&s, filename, MAX_PATH);
        }
        break;
    case ACTION_DELETE:
        get_file_name(&s, reg_key_name, KEY_MAX_LEN);
        if (!reg_key_name[0]) {
            printf("No registry key is specified for removal\n%s", usage);
            return FALSE;
            //exit(1);
        }
        delete_registry_key(reg_key_name);
        break;
    case ACTION_EXPORT:
        filename[0] = '\0';
        get_file_name(&s, filename, MAX_PATH);
        if (!filename[0]) {
            printf("No file name is specified\n%s", usage);
            return FALSE;
            //exit(1);
        }
        if (s[0]) {
            get_file_name(&s, reg_key_name, KEY_MAX_LEN);
            export_registry_key(filename, reg_key_name);
        } else {
            export_registry_key(filename, NULL);
        }
        break;
    default:
        printf("Unhandled action!\n");
        return FALSE;
    }
    return TRUE;
}

BOOL ProcessCmdLine(LPSTR lpCmdLine)
{
    REGEDIT_ACTION action = ACTION_UNDEF;
    LPSTR s = lpCmdLine;        /* command line pointer */
    CHAR ch = *s;               /* current character */

    while (ch && ((ch == '-') || (ch == '/'))) {
        char chu;
        char ch2;

        s++;
        ch = *s;
        ch2 = *(s+1);
        chu = toupper(ch);
        if (!ch2 || isspace(ch2)) {
            if (chu == 'S' || chu == 'V') {
                /* ignore these switches */
            } else {
                switch (chu) {
                case 'D':
                    action = ACTION_DELETE;
                    break;
                case 'E':
                    action = ACTION_EXPORT;
                    break;
                case 'V':
                    action = ACTION_VIEW;
                    break;
                case '?':
                    printf(usage);
                    return FALSE;
                    //exit(0);
                    break;
                default:
                    error_unknown_switch(chu, s);
                    return FALSE;
                    break;
                }
            }
            s++;
        } else {
            if (ch2 == ':') {
                switch (chu) {
                case 'L':
                    /* fall through */
                case 'R':
                    s += 2;
                    while (*s && !isspace(*s)) {
                        s++;
                    }
                    break;
                default:
                    error_unknown_switch(chu, s);
                    return FALSE;
                    break;
                }
            } else {
                /* this is a file name, starting from '/' */
                s--;
                break;
            }
        }
        /* skip spaces to the next parameter */
        ch = *s;
        while (ch && isspace(ch)) {
            s++;
            ch = *s;
        }
    }
    if (action == ACTION_UNDEF) {
        action = ACTION_ADD;
    }
    return PerformRegAction(action, s);
}

