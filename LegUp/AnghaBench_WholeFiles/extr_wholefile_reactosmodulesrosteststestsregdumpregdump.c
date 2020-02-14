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
typedef  int /*<<< orphan*/  Buffer ;

/* Variables and functions */
 int /*<<< orphan*/  GetInput (char*,int) ; 
 int /*<<< orphan*/  ProcessCmdLine (char*) ; 
 int /*<<< orphan*/  RegKeyPrint (char) ; 
 int /*<<< orphan*/  _T (char*) ; 
 int /*<<< orphan*/  _tprintf (int /*<<< orphan*/ ) ; 
 char* default_cmd_line1 ; 
 char* default_cmd_line2 ; 
 char* default_cmd_line3 ; 
 char* default_cmd_line4 ; 
 char* default_cmd_line5 ; 
 char* default_cmd_line6 ; 
 char* default_cmd_line7 ; 
 char* default_cmd_line8 ; 
 char* default_cmd_line9 ; 
 int /*<<< orphan*/  dprintf (char*,...) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char const*) ; 
 int /*<<< orphan*/  printf (char*,char*) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  strcpy (char*,char*) ; 
 scalar_t__ strstr (char*,char*) ; 
 char toupper (char) ; 

void usage(const char* appName)
{
    fprintf(stderr, "%s: Dump registry key to console\n", appName);
    fprintf(stderr, "%s HKCR | HKCU | HKLM | HKU | HKCC | HKRR\n", appName);
}

void show_menu(void)
{
    _tprintf(_T("\nchoose test :\n"));
    _tprintf(_T("  0 = Exit\n"));
         printf("  1 = %s\n", default_cmd_line1);
         printf("  2 = %s\n", default_cmd_line2);
         printf("  3 = %s\n", default_cmd_line3);
         printf("  4 = %s\n", default_cmd_line4);
         printf("  5 = %s\n", default_cmd_line5);
         printf("  6 = %s\n", default_cmd_line6);
         printf("  7 = %s\n", default_cmd_line7);
         printf("  8 = %s\n", default_cmd_line8);
         printf("  9 = %s\n", default_cmd_line9);
/*
    _tprintf(_T("  1 = %s\n"), default_cmd_line1);
    _tprintf(_T("  2 = %s\n"), default_cmd_line2);
    _tprintf(_T("  3 = %s\n"), default_cmd_line3);
    _tprintf(_T("  4 = %s\n"), default_cmd_line4);
    _tprintf(_T("  5 = %s\n"), default_cmd_line5);
    _tprintf(_T("  6 = %s\n"), default_cmd_line6);
    _tprintf(_T("  7 = %s\n"), default_cmd_line7);
    _tprintf(_T("  8 = %s\n"), default_cmd_line8);
    _tprintf(_T("  9 = %s\n"), default_cmd_line9);
 */
//        _tprintf(_T("  A = HKEY_CLASSES_ROOT\n"));
//        _tprintf(_T("  B = HKEY_CURRENT_USER\n"));
//        _tprintf(_T("  C = HKEY_LOCAL_MACHINE\n"));
//        _tprintf(_T("  D = HKEY_USERS\n"));
//        _tprintf(_T("  E = HKEY_CURRENT_CONFIG\n"));
//        _tprintf(_T("  F = REGISTRY ROOT\n"));
}

int regdump(int argc, char* argv[])
{
    char Buffer[500];

    if (argc > 1) {
//      if (0 == _tcsstr(argv[1], _T("HKLM"))) {
        if (strstr(argv[1], "help")) {
            usage(argv[0]);
        } else if (strstr(argv[1], "HKCR")) {
            RegKeyPrint('1');
        } else if (strstr(argv[1], "HKCU")) {
            RegKeyPrint('2');
        } else if (strstr(argv[1], "HKLM")) {
            RegKeyPrint('3');
        } else if (strstr(argv[1], "HKU")) {
            RegKeyPrint('4');
        } else if (strstr(argv[1], "HKCC")) {
            RegKeyPrint('5');
        } else if (strstr(argv[1], "HKRR")) {
            RegKeyPrint('6');
        } else {
            dprintf("started with argc = %d, argv[1] = %s (unknown?)\n", argc, argv[1]);
        }
        return 0;
    }
    show_menu();
    while (1) {
        GetInput(Buffer, sizeof(Buffer));
        switch (toupper(Buffer[0])) {
        case '0':
            return(0);
        case '1':
            strcpy(Buffer, default_cmd_line1);
            goto doit;
        case '2':
            strcpy(Buffer, default_cmd_line2);
            goto doit;
        case '3':
            strcpy(Buffer, default_cmd_line3);
            goto doit;
        case '4':
            strcpy(Buffer, default_cmd_line4);
            goto doit;
        case '5':
            strcpy(Buffer, default_cmd_line5);
            goto doit;
        case '6':
            strcpy(Buffer, default_cmd_line6);
            goto doit;
        case '7':
            strcpy(Buffer, default_cmd_line7);
            goto doit;
        case '8':
            strcpy(Buffer, default_cmd_line8);
            goto doit;
        case '9':
            strcpy(Buffer, default_cmd_line9);
            goto doit;
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
            RegKeyPrint(toupper(Buffer[0]) - 'A' + 1);
            break;
        default: doit:
            if (!ProcessCmdLine(Buffer)) {
                dprintf("invalid input.\n");
                show_menu();
            } else {
                dprintf("done.\n");
            }
            break;
        }
    }
    return 0;
}

