#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  si ;
typedef  int /*<<< orphan*/  shInputDll ;
typedef  int /*<<< orphan*/  _TCHAR ;
struct TYPE_11__ {int /*<<< orphan*/  hProcess; int /*<<< orphan*/  hThread; } ;
struct TYPE_10__ {int cbSize; char* lpVerb; char* lpFile; char* lpParameters; int /*<<< orphan*/ * hwnd; } ;
struct TYPE_9__ {int cb; int /*<<< orphan*/  wShowWindow; } ;
typedef  char TCHAR ;
typedef  TYPE_1__ STARTUPINFO ;
typedef  TYPE_2__ SHELLEXECUTEINFO ;
typedef  TYPE_3__ PROCESS_INFORMATION ;
typedef  int /*<<< orphan*/  MSG ;
typedef  char* LPTSTR ;
typedef  int /*<<< orphan*/  LPBYTE ;
typedef  int INT ;
typedef  int /*<<< orphan*/  HKEY ;
typedef  int /*<<< orphan*/  HANDLE ;
typedef  int /*<<< orphan*/  FILETIME ;
typedef  scalar_t__ DWORD ;
typedef  int BOOL ;

/* Variables and functions */
 scalar_t__ APP_ONLY ; 
 int /*<<< orphan*/  CharToOem (char*,char*) ; 
 int /*<<< orphan*/  CloseHandle (int /*<<< orphan*/ ) ; 
 scalar_t__ CreateProcess (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_1__*,TYPE_3__*) ; 
 int /*<<< orphan*/  DispatchMessage (int /*<<< orphan*/ *) ; 
 scalar_t__ ERROR_SUCCESS ; 
 int FALSE ; 
 int FOREGROUND_GREEN ; 
 int FOREGROUND_INTENSITY ; 
 int FOREGROUND_RED ; 
 int /*<<< orphan*/  GetStdHandle (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  HKEY_LOCAL_MACHINE ; 
 int /*<<< orphan*/  INFINITE ; 
 int MAX_PATH ; 
 int MB_ICONERROR ; 
 int MB_OK ; 
 int /*<<< orphan*/  MessageBox (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int) ; 
 scalar_t__ MsgWaitForMultipleObjects (int,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PM_REMOVE ; 
 scalar_t__ PeekMessage (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  QS_ALLEVENTS ; 
 scalar_t__ REG_DWORD ; 
 scalar_t__ REG_SZ ; 
 int /*<<< orphan*/  RegCloseKey (int /*<<< orphan*/ ) ; 
 scalar_t__ RegEnumKeyEx (int /*<<< orphan*/ ,int,char*,scalar_t__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ RegOpenKey (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *) ; 
 scalar_t__ RegQueryValueEx (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *,scalar_t__*,int /*<<< orphan*/ ,scalar_t__*) ; 
 scalar_t__ SHOW_ALL ; 
 int /*<<< orphan*/  STD_OUTPUT_HANDLE ; 
 int /*<<< orphan*/  SW_SHOW ; 
 int /*<<< orphan*/  SetConsoleTextAttribute (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  SetConsoleTitle (char*) ; 
 scalar_t__ ShellExecuteEx (TYPE_2__*) ; 
 int /*<<< orphan*/  TranslateMessage (int /*<<< orphan*/ *) ; 
 scalar_t__ UPD_ONLY ; 
 scalar_t__ WAIT_FAILED ; 
 scalar_t__ WAIT_OBJECT_0 ; 
 int /*<<< orphan*/  ZeroMemory (TYPE_1__*,int) ; 
 char* _T (char*) ; 
 int /*<<< orphan*/  _getch () ; 
 scalar_t__ _tcsncmp (int /*<<< orphan*/ *,char*,int) ; 
 int atoi (char*) ; 
 int /*<<< orphan*/  memset (TYPE_2__*,int,int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  scanf (char*,char*) ; 
 int /*<<< orphan*/  wsprintf (char*,char*,int,char*) ; 

void PrintHelp()
{
	printf(_T("Add or Remove Programs\n\
APPWIZ [/? /l] [/all /app /upd]\n\
  /?\t Help\n\
  /l\t Show list\n\
  /all\t Show programs and updates\n\
  /app\t Show programs only\n\
  /upd\t Show updates only\n"));
    _getch();
}

void RunGUIAppWiz()
{
    SHELLEXECUTEINFO shInputDll;

    memset(&shInputDll, 0x0, sizeof(SHELLEXECUTEINFO));
    shInputDll.cbSize = sizeof(shInputDll);
    shInputDll.hwnd = NULL;
    shInputDll.lpVerb = _T("open");
    shInputDll.lpFile = _T("RunDll32.exe");
    shInputDll.lpParameters = _T("shell32.dll,Control_RunDLL appwiz.cpl");

    if (ShellExecuteEx(&shInputDll) == 0)
    {
        MessageBox(NULL, _T("Can not start appwiz.cpl"), NULL, MB_OK | MB_ICONERROR);
    }
}

void CallUninstall(LPTSTR szUninstallString)
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    DWORD dwRet;
    MSG msg;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    si.wShowWindow = SW_SHOW;

    if (CreateProcess(NULL, szUninstallString, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
    {
        CloseHandle(pi.hThread);

        for (;;)
        {
            dwRet = MsgWaitForMultipleObjects(1, &pi.hProcess, FALSE, INFINITE, QS_ALLEVENTS);
            if (dwRet == WAIT_OBJECT_0 + 1)
            {
                 while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
                 {
                     TranslateMessage(&msg);
                     DispatchMessage(&msg);
                 }
            }
            else if (dwRet == WAIT_OBJECT_0 || dwRet == WAIT_FAILED)
                break;
        }
        CloseHandle(pi.hProcess);
    }
}

int ShowAppList(DWORD dwMode, INT iItem)
{
    HKEY hKey, hSubKey;
    DWORD dwSize, dwType, dwValue;
    TCHAR szName[MAX_PATH];
    TCHAR szParentKeyName[MAX_PATH];
    TCHAR szDisplayName[MAX_PATH];
    TCHAR szOutBuf[MAX_PATH];
    FILETIME FileTime;
    BOOL bIsUpdate = FALSE;
    BOOL bIsSystemComponent = FALSE;
    INT iIndex = 0, iColor = 0, iCount = 1;
    HANDLE hOutput;

    if (RegOpenKey(HKEY_LOCAL_MACHINE,
                   _T("Software\\Microsoft\\Windows\\CurrentVersion\\Uninstall"),
                   &hKey) != ERROR_SUCCESS)
    {
        printf(_T("ERROR: Can not open Uninstall key. Press any key for continue...\n"));
        _getch();
        return 0;
    }

    hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOutput, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    dwSize = MAX_PATH;
    while (RegEnumKeyEx(hKey, iIndex, szName, &dwSize, NULL, NULL, NULL, &FileTime) == ERROR_SUCCESS)
    {
        if (RegOpenKey(hKey, szName, &hSubKey) == ERROR_SUCCESS)
        {
            dwType = REG_DWORD;
            dwSize = sizeof(DWORD);

            if (RegQueryValueEx(hSubKey, _T("SystemComponent"),
                                NULL, &dwType,
                                (LPBYTE)&dwValue, &dwSize) == ERROR_SUCCESS)
            {
                bIsSystemComponent = (dwValue == 0x1);
            }
            else
            {
                bIsSystemComponent = FALSE;
            }

            dwType = REG_SZ;
            dwSize = MAX_PATH;

            bIsUpdate = (RegQueryValueEx(hSubKey, _T("ParentKeyName"),
                                         NULL, &dwType,
                                         (LPBYTE) szParentKeyName,
                                         &dwSize) == ERROR_SUCCESS);
            dwSize = MAX_PATH;
            if (RegQueryValueEx(hSubKey, _T("DisplayName"),
                                NULL, &dwType,
                                (LPBYTE) szDisplayName,
                                &dwSize) == ERROR_SUCCESS)
            {
                if (!bIsSystemComponent)
                {
                    if ((dwMode == SHOW_ALL) || ((dwMode == APP_ONLY) && (!bIsUpdate)) || ((dwMode == UPD_ONLY) && (bIsUpdate)))
                    {
                        if (iItem == -1)
                        {
                            wsprintf(szOutBuf, _T(" %d \t %s\n"), iCount, szDisplayName);
                            CharToOem(szOutBuf, szOutBuf);
                            printf("%s", szOutBuf);
                        }
                        else
                        {
                            dwType = REG_SZ;
                            dwSize = MAX_PATH;

                            if ((RegQueryValueEx(hSubKey, _T("UninstallString"), NULL, &dwType,
                                                (LPBYTE) szOutBuf, &dwSize) == ERROR_SUCCESS) && (iItem == iCount))
                            {
                                CallUninstall(szOutBuf);
                            }
                        }
                        iCount++;
                        iColor++;
                    }
                }
            }
        }

        if (iColor <= 5)
        {
            SetConsoleTextAttribute(hOutput, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        }
        else
        {
            SetConsoleTextAttribute(hOutput, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED);
            if (iColor >= 10) iColor = 0;
        }

        dwSize = MAX_PATH;
        iIndex++;
    }

    RegCloseKey(hSubKey);
    RegCloseKey(hKey);

    SetConsoleTextAttribute(hOutput, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("\n\nPlease enter application/update number and press ENTER for uninstall\nor press any key for Exit...\n");

    return 1;
}

int _tmain(int argc, _TCHAR* argv[])
{
    INT iNumber;
    TCHAR Char[4 + 1];

    SetConsoleTitle(_T("Application Wizard"));

    if (argc < 2)
    {
        RunGUIAppWiz();
        return 0;
    }

	if (_tcsncmp(argv[1], _T("/?"), 2) == 0)
	{
		PrintHelp();
		return 0;
	}

    if (_tcsncmp(argv[1], _T("/l"), 2) == 0)
    {
        if (argc < 3) goto ShowAll;
        if (_tcsncmp(argv[2], _T("/all"), 4) == 0)
        {
ShowAll:
            if (ShowAppList(SHOW_ALL, -1) == 0) return 0;
            scanf(_T("%s"), Char);

            iNumber = atoi(Char);

            if (iNumber == 0) return 0;
            ShowAppList(SHOW_ALL, iNumber);
        }
        else if (_tcsncmp(argv[2], _T("/app"), 4) == 0)
        {
            if (ShowAppList(APP_ONLY, -1) == 0) return 0;

            scanf(_T("%s"), Char);

            iNumber = atoi(Char);

            if (iNumber == 0) return 0;
            ShowAppList(APP_ONLY, iNumber);
        }
        else if (_tcsncmp(argv[2], _T("/upd"), 4) == 0)
        {
            if (ShowAppList(UPD_ONLY, -1) == 0) return 0;

            scanf(_T("%s"), Char);

            iNumber = atoi(Char);

            if (iNumber == 0) return 0;
            ShowAppList(UPD_ONLY, iNumber);
        }

        return 0;
    }

	return 0;
}

