#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_27__   TYPE_4__ ;
typedef  struct TYPE_26__   TYPE_3__ ;
typedef  struct TYPE_25__   TYPE_2__ ;
typedef  struct TYPE_24__   TYPE_1__ ;

/* Type definitions */
typedef  char WCHAR ;
struct TYPE_27__ {scalar_t__ message; int /*<<< orphan*/  wParam; } ;
struct TYPE_26__ {int dwOSVersionInfoSize; char* szCSDVersion; int dwPlatformId; int dwMajorVersion; int dwMinorVersion; int wSuiteMask; int dwBuildNumber; int /*<<< orphan*/  wProductType; } ;
struct TYPE_25__ {unsigned int Repeats; scalar_t__ Seconds; int /*<<< orphan*/  Wnd; } ;
struct TYPE_24__ {unsigned int (* Init ) (void**,TYPE_2__*,unsigned int) ;char* Label; int /*<<< orphan*/  (* Cleanup ) (void*,TYPE_2__*) ;int /*<<< orphan*/  (* PassCleanup ) (void*,TYPE_2__*) ;int /*<<< orphan*/  (* Proc ) (void*,TYPE_2__*,unsigned int) ;} ;
typedef  int /*<<< orphan*/  Status ;
typedef  TYPE_1__* PTEST ;
typedef  TYPE_2__* PPERF_INFO ;
typedef  int /*<<< orphan*/  OSVERSIONINFOW ;
typedef  TYPE_3__ OSVERSIONINFOEXW ;
typedef  int /*<<< orphan*/  OSVERSIONINFO ;
typedef  TYPE_4__ MSG ;
typedef  char* LPWSTR ;
typedef  char* LPCWSTR ;
typedef  int /*<<< orphan*/  LPBYTE ;
typedef  int /*<<< orphan*/  LONG ;
typedef  int /*<<< orphan*/  HWND ;
typedef  int /*<<< orphan*/  HKEY ;
typedef  int /*<<< orphan*/ * HDC ;
typedef  int DWORD ;
typedef  scalar_t__ BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  BITSPIXEL ; 
 int /*<<< orphan*/  DispatchMessageW (TYPE_4__*) ; 
 int /*<<< orphan*/  ERROR_SUCCESS ; 
 scalar_t__ FALSE ; 
 int /*<<< orphan*/ * GetDC (int /*<<< orphan*/ *) ; 
 int GetDeviceCaps (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int GetTickCount () ; 
 scalar_t__ GetVersionExW (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  HKEY_LOCAL_MACHINE ; 
 int /*<<< orphan*/  HORZRES ; 
 int /*<<< orphan*/  InvalidateRect (int /*<<< orphan*/ ,int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  KERNEL_VERSION_BUILD_STR ; 
 int /*<<< orphan*/  KERNEL_VERSION_STR ; 
 int /*<<< orphan*/  KEY_QUERY_VALUE ; 
 int /*<<< orphan*/  LabelWnd ; 
 int /*<<< orphan*/  PLANES ; 
 int /*<<< orphan*/  PM_REMOVE ; 
 scalar_t__ PeekMessageW (TYPE_4__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RegCloseKey (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RegOpenKeyExW (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  RegQueryValueExW (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  ReleaseDC (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SetWindowTextW (int /*<<< orphan*/ ,char*) ; 
 scalar_t__ TRUE ; 
 int /*<<< orphan*/  TranslateMessage (TYPE_4__*) ; 
 int /*<<< orphan*/  UpdateWindow (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  VERTRES ; 
 int /*<<< orphan*/  VER_NT_DOMAIN_CONTROLLER ; 
 int /*<<< orphan*/  VER_NT_SERVER ; 
 int /*<<< orphan*/  VER_NT_WORKSTATION ; 
#define  VER_PLATFORM_WIN32_NT 130 
#define  VER_PLATFORM_WIN32_WINDOWS 129 
#define  VER_PLATFORM_WIN32s 128 
 int VER_SUITE_BLADE ; 
 int VER_SUITE_DATACENTER ; 
 int VER_SUITE_ENTERPRISE ; 
 int VER_SUITE_PERSONAL ; 
 scalar_t__ WM_QUIT ; 
 int /*<<< orphan*/  ZeroMemory (TYPE_3__*,int) ; 
 int /*<<< orphan*/  _snwprintf (char*,int,char*,int,char*,char*) ; 
 scalar_t__ _wcsnicmp (char*,char*,int) ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lstrcmpiW (char*,char*) ; 
 unsigned int stub1 (void**,TYPE_2__*,unsigned int) ; 
 int /*<<< orphan*/  stub2 (void*,TYPE_2__*,unsigned int) ; 
 int /*<<< orphan*/  stub3 (void*,TYPE_2__*) ; 
 int /*<<< orphan*/  stub4 (void*,TYPE_2__*) ; 
 unsigned int stub5 (void**,TYPE_2__*,unsigned int) ; 
 int /*<<< orphan*/  stub6 (void*,TYPE_2__*,unsigned int) ; 
 int /*<<< orphan*/  stub7 (void*,TYPE_2__*) ; 
 int /*<<< orphan*/  stub8 (void*,TYPE_2__*) ; 
 int wcslen (char*) ; 
 int /*<<< orphan*/  wprintf (char*,...) ; 

unsigned
NullInit(void **Context, PPERF_INFO PerfInfo, unsigned Reps)
{
  *Context = NULL;

  return Reps;
}

void
NullCleanup(void *Context, PPERF_INFO PerfInfo)
{
}

__attribute__((used)) static void
ProcessMessages(void)
{
  MSG Msg;

  while (PeekMessageW(&Msg, NULL, 0, 0, PM_REMOVE))
    {
      if (WM_QUIT == Msg.message)
        {
          exit(Msg.wParam);
        }
      TranslateMessage(&Msg);
      DispatchMessageW(&Msg);
    }
}

__attribute__((used)) static void
ClearWindow(PPERF_INFO PerfInfo)
{
  InvalidateRect(PerfInfo->Wnd, NULL, TRUE);
  UpdateWindow(PerfInfo->Wnd);
}

__attribute__((used)) static unsigned
CalibrateTest(PTEST Test, PPERF_INFO PerfInfo)
{
#define GOAL    2500   /* Try to get up to 2.5 seconds                 */
#define ENOUGH  2000   /* But settle for 2.0 seconds                   */
#define TICK      10   /* Assume clock not faster than .01 seconds     */

  unsigned Reps, DidReps;        /* Reps desired, reps performed                 */
  unsigned Exponent;
  void *Context;
  DWORD StartTick;
  DWORD Duration;

  /* Attempt to get an idea how long each rep lasts by getting enough
     reps to last more than ENOUGH.  Then scale that up to the number of
     seconds desired.

     If init call to test ever fails, return False and test will be skipped.
  */

  Reps = 1;
  for (;;)
    {
      ClearWindow(PerfInfo);
      DidReps = (*Test->Init)(&Context, PerfInfo, Reps);
      ProcessMessages();
      if (0 == DidReps)
        {
          return 0;
        }
      StartTick = GetTickCount();
      (*Test->Proc)(Context, PerfInfo, Reps);
      Duration = GetTickCount() - StartTick;
      (*Test->PassCleanup) (Context, PerfInfo);
      (*Test->Cleanup)(Context, PerfInfo);
      ProcessMessages();

      if (DidReps != Reps)
        {
          /* The test can't do the number of reps as we asked for.
             Give up */
          return DidReps;
        }
      /* Did we go long enough? */
      if (ENOUGH <= Duration)
        {
          break;
        }

      /* Don't let too short a clock make new reps wildly high */
      if (Duration <= TICK)
        {
          Reps *= 10;
        }
      else
        {
          /* Try to get up to GOAL seconds. */
          Reps = (int)(GOAL * (double) Reps / (double) Duration) + 1;
        }
    }

  Reps = (int) ((double) PerfInfo->Seconds * 1000.0 * (double) Reps / (double) Duration) + 1;

  /* Now round reps up to 1 digit accuracy, so we don't get stupid-looking
     numbers of repetitions. */
  Reps--;
  Exponent = 1;
  while (9 < Reps)
    {
      Reps /= 10;
      Exponent *= 10;
    }
  Reps = (Reps + 1) * Exponent;

  return Reps;
}

__attribute__((used)) static void
DisplayStatus(HWND Label, LPCWSTR Message, LPCWSTR Test, int Try)
{
  WCHAR Status[128];

  _snwprintf(Status, sizeof(Status) / sizeof(Status[0]), L"%d %s %s", Try, Message, Test);
  SetWindowTextW(Label, Status);
  InvalidateRect(Label, NULL, TRUE);
  UpdateWindow(Label);
}

__attribute__((used)) static double
RoundTo3Digits(double d)
{
  /* It's kind of silly to print out things like ``193658.4/sec'' so just
     junk all but 3 most significant digits. */

  double exponent, sign;

  exponent = 1.0;
  /* the code below won't work if d should happen to be non-positive. */
  if (d < 0.0)
    {
      d = -d;
      sign = -1.0;
    }
  else
    {
      sign = 1.0;
    }

  if (1000.0 <= d)
    {
      do
        {
          exponent *= 10.0;
        }
      while (1000.0 <= d / exponent);
      d = (double)((int)(d / exponent + 0.5));
      d *= exponent;
    }
  else
    {
      if (0.0 != d)
        {
          while (d * exponent < 100.0)
            {
              exponent *= 10.0;
            }
        }
      d = (double)((int)(d * exponent + 0.5));
      d /= exponent;
    }

  return d * sign;
}

__attribute__((used)) static void
ReportTimes(DWORD Time, int Reps, LPCWSTR Label, BOOL Average)
{
  double MSecsPerObj, ObjsPerSec;

  if (0 != Time)
    {
      MSecsPerObj = (double) Time / (double) Reps;
      ObjsPerSec = (double) Reps * 1000.0 / (double) Time;

      /* Round obj/sec to 3 significant digits.  Leave msec untouched, to
         allow averaging results from several repetitions. */
      ObjsPerSec =  RoundTo3Digits(ObjsPerSec);

      wprintf(L"%7d %s @ %8.4f msec (%8.1f/sec): %s\n",
              Reps, Average ? L"trep" : L"reps", MSecsPerObj, ObjsPerSec, Label);
    }
  else
    {
      wprintf(L"%6d %sreps @ 0.0 msec (unmeasurably fast): %s\n",
              Reps, Average ? L"t" : L"", Label);
    }

}

__attribute__((used)) static void
ProcessTest(PTEST Test, PPERF_INFO PerfInfo)
{
  unsigned Reps;
  unsigned Repeat;
  void *Context;
  DWORD StartTick;
  DWORD Time, TotalTime;

  DisplayStatus(LabelWnd, L"Calibrating", Test->Label, 0);
  Reps = CalibrateTest(Test, PerfInfo);
  if (0 == Reps)
    {
      return;
    }

  Reps = Test->Init(&Context, PerfInfo, Reps);
  if (0 == Reps)
    {
      return;
    }
  TotalTime = 0;
  for (Repeat = 0; Repeat < PerfInfo->Repeats; Repeat++)
    {
      DisplayStatus(LabelWnd, L"Testing", Test->Label, Repeat + 1);
      ClearWindow(PerfInfo);
      StartTick = GetTickCount();
      (*Test->Proc)(Context, PerfInfo, Reps);
      Time = GetTickCount() - StartTick;
      ProcessMessages();
      TotalTime += Time;
      ReportTimes(Time, Reps, Test->Label, FALSE);
      (*Test->PassCleanup)(Context, PerfInfo);
      ProcessMessages();
    }
  (*Test->Cleanup)(Context, PerfInfo);
  ReportTimes(TotalTime, Repeat * Reps, Test->Label, TRUE);
  ProcessMessages();
}

__attribute__((used)) static void
PrintOSVersion(void)
{
#define BUFSIZE 160
  OSVERSIONINFOEXW VersionInfo;
  BOOL OsVersionInfoEx;
  HKEY hKey;
  WCHAR ProductType[BUFSIZE];
  DWORD BufLen;
  LONG Ret;
  unsigned RosVersionLen;
  LPWSTR RosVersion;

  /* Try calling GetVersionEx using the OSVERSIONINFOEX structure.
   * If that fails, try using the OSVERSIONINFO structure. */

  ZeroMemory(&VersionInfo, sizeof(OSVERSIONINFOEXW));
  VersionInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEXW);

  OsVersionInfoEx = GetVersionExW((OSVERSIONINFOW *) &VersionInfo);
  if (! OsVersionInfoEx)
    {
      VersionInfo.dwOSVersionInfoSize = sizeof (OSVERSIONINFO);
      if (! GetVersionExW((OSVERSIONINFOW *) &VersionInfo))
        {
          return;
        }
    }

  RosVersion = VersionInfo.szCSDVersion + wcslen(VersionInfo.szCSDVersion) + 1;
  RosVersionLen = sizeof(VersionInfo.szCSDVersion) / sizeof(VersionInfo.szCSDVersion[0]) -
                  (RosVersion - VersionInfo.szCSDVersion);
  if (7 <= RosVersionLen && 0 == _wcsnicmp(RosVersion, L"ReactOS", 7))
    {
      wprintf(L"Running on %s\n", RosVersion);
      return;
    }

  switch (VersionInfo.dwPlatformId)
    {
      /* Test for the Windows NT product family. */
      case VER_PLATFORM_WIN32_NT:

        /* Test for the specific product. */
        if (5 == VersionInfo.dwMajorVersion && 2 == VersionInfo.dwMinorVersion)
          {
            wprintf(L"Running on Microsoft Windows Server 2003, ");
          }
        else if (5 == VersionInfo.dwMajorVersion && 1 == VersionInfo.dwMinorVersion)
          {
            wprintf(L"Running on Microsoft Windows XP ");
          }
        else if (5 == VersionInfo.dwMajorVersion && 0 == VersionInfo.dwMinorVersion)
          {
            wprintf(L"Running on Microsoft Windows 2000 ");
          }
        else if (VersionInfo.dwMajorVersion <= 4 )
          {
            wprintf(L"Running on Microsoft Windows NT ");
          }

        /* Test for specific product on Windows NT 4.0 SP6 and later. */
        if (OsVersionInfoEx)
          {
            /* Test for the workstation type. */
            if (VER_NT_WORKSTATION == VersionInfo.wProductType)
              {
                if (4 == VersionInfo.dwMajorVersion)
                  {
                    wprintf(L"Workstation 4.0 ");
                  }
                else if (0 != (VersionInfo.wSuiteMask & VER_SUITE_PERSONAL))
                  {
                    wprintf(L"Home Edition ");
                  }
                else
                  {
                    wprintf(L"Professional ");
                  }
              }

            /* Test for the server type. */
            else if (VER_NT_SERVER == VersionInfo.wProductType  ||
                     VER_NT_DOMAIN_CONTROLLER == VersionInfo.wProductType)
              {
                if (5 == VersionInfo.dwMajorVersion && 2 == VersionInfo.dwMinorVersion)
                  {
                    if (0 != (VersionInfo.wSuiteMask & VER_SUITE_DATACENTER))
                      {
                        wprintf(L"Datacenter Edition ");
                      }
                    else if (0 != (VersionInfo.wSuiteMask & VER_SUITE_ENTERPRISE))
                      {
                        wprintf(L"Enterprise Edition ");
                      }
                    else if (VER_SUITE_BLADE == VersionInfo.wSuiteMask)
                      {
                        wprintf(L"Web Edition ");
                      }
                    else
                      {
                        wprintf(L"Standard Edition ");
                      }
                  }

                else if (5 == VersionInfo.dwMajorVersion && 0 == VersionInfo.dwMinorVersion)
                  {
                    if (0 != (VersionInfo.wSuiteMask & VER_SUITE_DATACENTER))
                      {
                        wprintf(L"Datacenter Server ");
                      }
                    else if (0 != (VersionInfo.wSuiteMask & VER_SUITE_ENTERPRISE))
                      {
                        wprintf(L"Advanced Server " );
                      }
                    else
                      {
                        wprintf(L"Server " );
                      }
                  }

                else  /* Windows NT 4.0 */
                  {
                    if (0 != (VersionInfo.wSuiteMask & VER_SUITE_ENTERPRISE))
                      {
                        wprintf(L"Server 4.0, Enterprise Edition ");
                      }
                    else
                      {
                        wprintf(L"Server 4.0 ");
                      }
                  }
              }
          }
        else  /* Test for specific product on Windows NT 4.0 SP5 and earlier */
          {
            BufLen = BUFSIZE;

            Ret = RegOpenKeyExW(HKEY_LOCAL_MACHINE,
                                L"SYSTEM\\CurrentControlSet\\Control\\ProductOptions",
                                0, KEY_QUERY_VALUE, &hKey);
            if (ERROR_SUCCESS != Ret)
              {
                return;
              }

            Ret = RegQueryValueExW(hKey, L"ProductType", NULL, NULL,
                                   (LPBYTE) ProductType, &BufLen);
            if (ERROR_SUCCESS != Ret || BUFSIZE < BufLen)
              {
                return;
              }

            RegCloseKey(hKey);

            if (0 == lstrcmpiW(L"WINNT", ProductType))
              {
                wprintf(L"Workstation ");
              }
            else if (0 == lstrcmpiW(L"LANMANNT", ProductType))
              {
                wprintf(L"Server ");
              }
            else if (0 == lstrcmpiW(L"SERVERNT", ProductType))
              {
                wprintf(L"Advanced Server ");
              }

            wprintf(L"%d.%d ", VersionInfo.dwMajorVersion, VersionInfo.dwMinorVersion);
          }

        /* Display service pack (if any) and build number. */

        if (4 == VersionInfo.dwMajorVersion &&
            0 == lstrcmpiW(VersionInfo.szCSDVersion, L"Service Pack 6"))
          {
            /* Test for SP6 versus SP6a. */
            Ret = RegOpenKeyExW(HKEY_LOCAL_MACHINE,
                                L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Hotfix\\Q246009",
                                0, KEY_QUERY_VALUE, &hKey);
            if (ERROR_SUCCESS == Ret)
              {
                wprintf(L"Service Pack 6a (Build %d)\n", VersionInfo.dwBuildNumber & 0xFFFF);
              }
            else /* Windows NT 4.0 prior to SP6a */
              {
                wprintf(L"%s (Build %d)\n",
                        VersionInfo.szCSDVersion,
                        VersionInfo.dwBuildNumber & 0xFFFF);
              }

            RegCloseKey(hKey);
          }
        else /* not Windows NT 4.0 */
          {
            wprintf(L"%s (Build %d)\n",
                    VersionInfo.szCSDVersion,
                    VersionInfo.dwBuildNumber & 0xFFFF);
          }


        break;

      /* Test for the Windows Me/98/95. A bit silly since we're using Unicode... */
      case VER_PLATFORM_WIN32_WINDOWS:

        if (4 == VersionInfo.dwMajorVersion && 0 == VersionInfo.dwMinorVersion)
          {
            wprintf(L"Running on Microsoft Windows 95 ");
            if (L'C' == VersionInfo.szCSDVersion[1] || L'B' == VersionInfo.szCSDVersion[1])
              {
                wprintf(L"OSR2");
              }
          }

        else if (4 == VersionInfo.dwMajorVersion && 10 == VersionInfo.dwMinorVersion)
          {
            wprintf(L"Running on Microsoft Windows 98 ");
            if (L'A' == VersionInfo.szCSDVersion[1])
              {
                wprintf(L"SE");
              }
          }

        else if (4 == VersionInfo.dwMajorVersion && 90 == VersionInfo.dwMinorVersion)
          {
            wprintf(L"Running on Microsoft Windows Millennium Edition");
          }
        wprintf(L"\n");
        break;

      case VER_PLATFORM_WIN32s: /* Even silier... */

        wprintf(L"Running on Microsoft Win32s\n");
        break;
    }
}

__attribute__((used)) static void
PrintAppVersion(void)
{
  wprintf(L"RosPerf %S (Build %S)\n", KERNEL_VERSION_STR, KERNEL_VERSION_BUILD_STR);
}

__attribute__((used)) static void
PrintDisplayInfo(void)
{
  HDC Dc;

  Dc = GetDC(NULL);
  if (NULL == Dc)
    {
      return;
    }

  wprintf(L"Display settings %d * %d * %d\n", GetDeviceCaps(Dc, HORZRES),
          GetDeviceCaps(Dc, VERTRES), GetDeviceCaps(Dc, BITSPIXEL) * GetDeviceCaps(Dc, PLANES));

  ReleaseDC(NULL, Dc);
}

__attribute__((used)) static void
PrintStartupInfo(void)
{
  PrintAppVersion();
  PrintOSVersion();
  PrintDisplayInfo();
}

