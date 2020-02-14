#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  WCHAR ;
typedef  int /*<<< orphan*/  VOID ;
typedef  int UINT ;
struct TYPE_4__ {int /*<<< orphan*/ * hEvent; } ;
typedef  int /*<<< orphan*/  TCHAR ;
typedef  int SIZE_T ;
typedef  char* LPWSTR ;
typedef  char* LPCWSTR ;
typedef  scalar_t__ HANDLE ;
typedef  int DWORD ;
typedef  scalar_t__ BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  CloseEventLog (scalar_t__) ; 
 int /*<<< orphan*/  CloseHandle (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * CreateFileW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 scalar_t__ ERROR_IO_PENDING ; 
 int /*<<< orphan*/  EVENTLOG_ERROR_TYPE ; 
 int /*<<< orphan*/  EVENTLOG_SUCCESS ; 
 int /*<<< orphan*/  EXCEPTION_INT_OVERFLOW ; 
 int /*<<< orphan*/  ExitProcess (int) ; 
 scalar_t__ FALSE ; 
 int FILE_ATTRIBUTE_NORMAL ; 
 int FILE_FLAG_OVERLAPPED ; 
 int /*<<< orphan*/  FILE_SHARE_READ ; 
 int FORMAT_MESSAGE_ALLOCATE_BUFFER ; 
 int FORMAT_MESSAGE_FROM_SYSTEM ; 
 int /*<<< orphan*/  FlushFileBuffers (int /*<<< orphan*/ *) ; 
 int FormatMessageW (int,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  GENERIC_WRITE ; 
 scalar_t__ GetLastError () ; 
 scalar_t__ GetOverlappedResult (int /*<<< orphan*/ *,TYPE_1__*,int*,scalar_t__) ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 char* HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  INFINITE ; 
 int /*<<< orphan*/ * INVALID_HANDLE_VALUE ; 
 int /*<<< orphan*/  LANG_NEUTRAL ; 
 int LOG_ERROR ; 
 int LOG_EVENTLOG ; 
 int /*<<< orphan*/  LocalFree (char*) ; 
 int /*<<< orphan*/  MAKELANGID (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int MAXDWORD ; 
 int /*<<< orphan*/  OPEN_ALWAYS ; 
 int /*<<< orphan*/  RaiseException (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ RegisterEventSourceW (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ReportEventW (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,char**,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SUBLANG_DEFAULT ; 
 scalar_t__ TRUE ; 
#define  WAIT_OBJECT_0 128 
 int WaitForSingleObject (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ WriteFile (int /*<<< orphan*/ *,char*,int,int*,TYPE_1__*) ; 
 int /*<<< orphan*/  _snwprintf (char*,int,char*,char*,...) ; 
 int /*<<< orphan*/ * hLogFile ; 
 int /*<<< orphan*/  lpEventSource ; 
 TYPE_1__ olWrite ; 
 int /*<<< orphan*/  szLogFileName ; 
 int wcslen (char*) ; 

__attribute__((used)) static VOID
LogToEventLog(LPCWSTR lpMsg,
              DWORD errNum,
              DWORD exitCode,
              UINT flags)
{
    HANDLE hEventLog;

    hEventLog = RegisterEventSourceW(NULL, lpEventSource);
    if (hEventLog)
    {
        ReportEventW(hEventLog,
                     (flags & LOG_ERROR) ? EVENTLOG_ERROR_TYPE : EVENTLOG_SUCCESS,
                     0,
                     0,
                     NULL,
                     1,
                     0,
                     &lpMsg,
                     NULL);

        CloseEventLog(hEventLog);
    }
}

__attribute__((used)) static BOOL
OpenLogFile()
{
    hLogFile = CreateFileW(szLogFileName,
                           GENERIC_WRITE,
                           FILE_SHARE_READ,
                           NULL,
                           OPEN_ALWAYS,
                           FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED,
                           NULL);
    if (hLogFile  == INVALID_HANDLE_VALUE)
    {
        hLogFile = NULL;
        return FALSE;
    }

    return TRUE;
}

__attribute__((used)) static VOID
LogToFile(LPCWSTR lpMsg,
          DWORD errNum,
          DWORD exitCode,
          UINT flags)
{
    LPWSTR lpFullMsg = NULL;
    SIZE_T msgLen;

    msgLen = wcslen(lpMsg) + 1;

    if (flags & LOG_ERROR)
    {
        LPWSTR lpSysMsg;
        DWORD eMsgLen;

        eMsgLen = FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
                                 NULL,
                                 errNum,
                                 MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                                 (LPWSTR)&lpSysMsg,
                                 0,
                                 NULL);

        msgLen = msgLen + eMsgLen + 40;

        lpFullMsg = HeapAlloc(GetProcessHeap(),
                              0,
                              msgLen * sizeof(TCHAR));
        if (lpFullMsg)
        {
            _snwprintf(lpFullMsg,
                       msgLen,
                       L"%s : %s\tErrNum = %lu ExitCode = %lu\r\n",
                       lpMsg,
                       lpSysMsg,
                       errNum,
                       exitCode);
        }

        LocalFree(lpSysMsg);

    }
    else
    {
        msgLen += 2;

        lpFullMsg = HeapAlloc(GetProcessHeap(),
                              0,
                              msgLen * sizeof(TCHAR));
        if (lpFullMsg)
        {
            _snwprintf(lpFullMsg,
                       msgLen,
                      L"%s\r\n",
                      lpMsg);
        }
    }

    /* Make sure the length in bytes doesn't overflow a DWORD */
    msgLen = wcslen(lpFullMsg);
    if (msgLen > (MAXDWORD / sizeof(WCHAR)))
    {
        RaiseException(EXCEPTION_INT_OVERFLOW, 0, 0, NULL);
    }

    if (lpFullMsg)
    {
        DWORD bytesWritten;
        DWORD dwRet;
        BOOL bRet;

        bRet = WriteFile(hLogFile,
                         lpFullMsg,
                         (DWORD)msgLen * sizeof(WCHAR),
                         &bytesWritten,
                         &olWrite);
        if (!bRet)
        {
            if (GetLastError() != ERROR_IO_PENDING)
            {
                bRet = FALSE;
            }
            else
            {
                // Write is pending
                dwRet = WaitForSingleObject(olWrite.hEvent, INFINITE);

                 switch (dwRet)
                 {
                    // event has been signaled
                    case WAIT_OBJECT_0:
                    {
                         bRet = GetOverlappedResult(hLogFile,
                                                    &olWrite,
                                                    &bytesWritten,
                                                    FALSE);
                         break;
                    }

                    default:
                         // An error has occurred in WaitForSingleObject.
                         // This usually indicates a problem with the
                         // OVERLAPPED structure's event handle.
                         bRet = FALSE;
                         break;
                 }
            }
        }

        if (!bRet || bytesWritten == 0)
        {
            LogToEventLog(L"Failed to write to log file",
                          GetLastError(),
                          0,
                          LOG_EVENTLOG | LOG_ERROR);
        }

        HeapFree(GetProcessHeap(),
                 0,
                 lpFullMsg);
    }

    if (exitCode > 0)
        ExitProcess(exitCode);
}

VOID
LogEvent(LPCWSTR lpMsg,
         DWORD errNum,
         DWORD exitCode,
         UINT flags)
{
#ifdef DEBUG
    if (flags & LOG_FILE || flags & LOG_ERROR)
        LogToFile(lpMsg, errNum, exitCode, flags);
#endif
    if (flags & LOG_EVENTLOG)
        LogToEventLog(lpMsg, errNum, exitCode, flags);
}

BOOL
InitLogging()
{
#ifdef DEBUG
    BOOL bRet = FALSE;

    if (!GetEnvironmentVariableW(L"SystemDrive", szLogFileName, ARRAYSIZE(szLogFileName)))
    {
        StringCchCopyW(szLogFileName, ARRAYSIZE(szLogFileName), L"C:");
    }
    StringCchCatW(szLogFileName, ARRAYSIZE(szLogFileName), L"\\tcpsvcs_log.log");

    ZeroMemory(&olWrite, sizeof(OVERLAPPED));
    olWrite.Offset = 0xFFFFFFFF;
    olWrite.OffsetHigh = 0xFFFFFFFF;
    olWrite.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
    if (olWrite.hEvent)
    {
        DeleteFileW(szLogFileName);

        if (OpenLogFile())
        {
            WCHAR wcBom = 0xFEFF;
            DWORD bytesWritten;

            bRet = WriteFile(hLogFile,
                             &wcBom,
                             sizeof(WCHAR),
                             &bytesWritten,
                             &olWrite);
            if (!bRet)
            {
                if (GetLastError() != ERROR_IO_PENDING)
                {
                    LogToEventLog(L"Failed to write to log file",
                                  GetLastError(),
                                  0,
                                  LOG_EVENTLOG | LOG_ERROR);
                }
                else
                {
                    bRet = TRUE;
                }
            }
        }
    }

    return bRet;
#else
    return TRUE;
#endif
}

VOID
UninitLogging()
{
    if (hLogFile)
    {
        FlushFileBuffers(hLogFile);
        CloseHandle(hLogFile);
    }

    if (olWrite.hEvent)
    {
        CloseHandle(olWrite.hEvent);
    }
}

