#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct thread_actctx_param {scalar_t__ thread_context; scalar_t__ handle; } ;
typedef  int /*<<< orphan*/  si ;
typedef  int /*<<< orphan*/  actctx ;
typedef  int /*<<< orphan*/  WCHAR ;
typedef  int /*<<< orphan*/  ULONG_PTR ;
struct TYPE_10__ {int cbSize; scalar_t__ dwFlags; scalar_t__ lpSource; scalar_t__ wProcessorArchitecture; scalar_t__ wLangId; scalar_t__ lpAssemblyDirectory; scalar_t__ lpResourceName; scalar_t__ lpApplicationName; scalar_t__ hModule; } ;
struct TYPE_9__ {scalar_t__ hThread; scalar_t__ hProcess; } ;
struct TYPE_8__ {int cb; int /*<<< orphan*/  member_0; } ;
typedef  TYPE_1__ STARTUPINFOA ;
typedef  TYPE_2__ PROCESS_INFORMATION ;
typedef  int LONG ;
typedef  scalar_t__ HANDLE ;
typedef  scalar_t__ DWORD ;
typedef  int BOOL ;
typedef  TYPE_3__ ACTCTXW ;

/* Variables and functions */
 int /*<<< orphan*/  CP_ACP ; 
 int /*<<< orphan*/  CREATE_ALWAYS ; 
 int CloseHandle (scalar_t__) ; 
 int /*<<< orphan*/ * CreateEventW (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ CreateFileW (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int CreateProcessA (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_1__*,TYPE_2__*) ; 
 scalar_t__ CreateRemoteThread (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct thread_actctx_param*,int /*<<< orphan*/ ,scalar_t__*) ; 
 scalar_t__ CreateThread (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct thread_actctx_param*,int /*<<< orphan*/ ,scalar_t__*) ; 
 int /*<<< orphan*/  DeleteFileA (char*) ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  FILE_ATTRIBUTE_NORMAL ; 
 int /*<<< orphan*/  GENERIC_WRITE ; 
 int /*<<< orphan*/  GetCurrentProcess () ; 
 scalar_t__ GetLastError () ; 
 scalar_t__ INVALID_HANDLE_VALUE ; 
 int InterlockedDecrement (int*) ; 
 int InterlockedIncrement (int*) ; 
 int MAX_PATH ; 
 int /*<<< orphan*/  MultiByteToWideChar (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*,int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ResetEvent (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SetEvent (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TRUE ; 
 scalar_t__ WAIT_OBJECT_0 ; 
 scalar_t__ WaitForSingleObject (scalar_t__,int) ; 
 int /*<<< orphan*/  WriteFile (scalar_t__,char const*,int /*<<< orphan*/ ,scalar_t__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  assert (int) ; 
 char* manifest_dep ; 
 char* manifest_main ; 
 int /*<<< orphan*/  memset (TYPE_3__*,int /*<<< orphan*/ ,int) ; 
 int num_synced ; 
 int /*<<< orphan*/  ok (int,char*,...) ; 
 int pActivateActCtx (scalar_t__,int /*<<< orphan*/ *) ; 
 scalar_t__ pCreateActCtxW (TYPE_3__*) ; 
 int pDeactivateActCtx (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int pGetCurrentActCtx (scalar_t__*) ; 
 int /*<<< orphan*/  pReleaseActCtx (scalar_t__) ; 
 int /*<<< orphan*/  sprintf (char*,char*,char*,char*,char const*) ; 
 int /*<<< orphan*/ * start_event ; 
 int /*<<< orphan*/ * stop_event ; 
 int /*<<< orphan*/  strlen (char const*) ; 
 int /*<<< orphan*/  thread_actctx_func ; 
 int /*<<< orphan*/  win_skip (char*) ; 
 int /*<<< orphan*/  winetest_get_mainargs (char***) ; 

__attribute__((used)) static HANDLE create_target_process(const char *arg)
{
    char **argv;
    char cmdline[MAX_PATH];
    PROCESS_INFORMATION pi;
    BOOL ret;
    STARTUPINFOA si = { 0 };
    si.cb = sizeof(si);

    winetest_get_mainargs( &argv );
    sprintf(cmdline, "%s %s %s", argv[0], argv[1], arg);
    ret = CreateProcessA(NULL, cmdline, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
    ok(ret, "error: %u\n", GetLastError());
    ret = CloseHandle(pi.hThread);
    ok(ret, "error %u\n", GetLastError());
    return pi.hProcess;
}

__attribute__((used)) static void init_thread_sync_helpers(void)
{
  start_event = CreateEventW(NULL, TRUE, FALSE, NULL);
  ok(start_event != NULL, "CreateEvent failed\n");
  stop_event = CreateEventW(NULL, TRUE, FALSE, NULL);
  ok(stop_event != NULL, "CreateEvent failed\n");
  num_synced = -1;
}

__attribute__((used)) static BOOL sync_threads_and_run_one(DWORD sync_id, DWORD my_id)
{
  LONG num = InterlockedIncrement(&num_synced);
  assert(-1 <= num && num <= 1);
  if (num == 1)
  {
      ResetEvent( stop_event );
      SetEvent( start_event );
  }
  else
  {
    DWORD ret = WaitForSingleObject(start_event, 10000);
    ok(ret == WAIT_OBJECT_0, "WaitForSingleObject failed %x\n",ret);
  }
  return sync_id == my_id;
}

__attribute__((used)) static void resync_after_run(void)
{
  LONG num = InterlockedDecrement(&num_synced);
  assert(-1 <= num && num <= 1);
  if (num == -1)
  {
      ResetEvent( start_event );
      SetEvent( stop_event );
  }
  else
  {
    DWORD ret = WaitForSingleObject(stop_event, 10000);
    ok(ret == WAIT_OBJECT_0, "WaitForSingleObject failed\n");
  }
}

__attribute__((used)) static void cleanup_thread_sync_helpers(void)
{
  CloseHandle(start_event);
  CloseHandle(stop_event);
}

__attribute__((used)) static void create_manifest_file(const char *filename, const char *manifest)
{
    WCHAR path[MAX_PATH];
    HANDLE file;
    DWORD size;

    MultiByteToWideChar( CP_ACP, 0, filename, -1, path, MAX_PATH );
    file = CreateFileW(path, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    ok(file != INVALID_HANDLE_VALUE, "CreateFile failed: %u\n", GetLastError());
    WriteFile(file, manifest, strlen(manifest), &size, NULL);
    CloseHandle(file);
}

__attribute__((used)) static HANDLE test_create(const char *file)
{
    WCHAR path[MAX_PATH];
    ACTCTXW actctx;
    HANDLE handle;

    MultiByteToWideChar(CP_ACP, 0, file, -1, path, MAX_PATH);
    memset(&actctx, 0, sizeof(ACTCTXW));
    actctx.cbSize = sizeof(ACTCTXW);
    actctx.lpSource = path;

    handle = pCreateActCtxW(&actctx);
    ok(handle != INVALID_HANDLE_VALUE, "failed to create context, error %u\n", GetLastError());

    ok(actctx.cbSize == sizeof(actctx), "cbSize=%d\n", actctx.cbSize);
    ok(actctx.dwFlags == 0, "dwFlags=%d\n", actctx.dwFlags);
    ok(actctx.lpSource == path, "lpSource=%p\n", actctx.lpSource);
    ok(actctx.wProcessorArchitecture == 0, "wProcessorArchitecture=%d\n", actctx.wProcessorArchitecture);
    ok(actctx.wLangId == 0, "wLangId=%d\n", actctx.wLangId);
    ok(actctx.lpAssemblyDirectory == NULL, "lpAssemblyDirectory=%p\n", actctx.lpAssemblyDirectory);
    ok(actctx.lpResourceName == NULL, "lpResourceName=%p\n", actctx.lpResourceName);
    ok(actctx.lpApplicationName == NULL, "lpApplicationName=%p\n", actctx.lpApplicationName);
    ok(actctx.hModule == NULL, "hModule=%p\n", actctx.hModule);

    return handle;
}

__attribute__((used)) static void test_thread_actctx(void)
{
    struct thread_actctx_param param;
    HANDLE thread, handle, context;
    ULONG_PTR cookie;
    DWORD tid, ret;
    BOOL b;

    if (!pActivateActCtx)
    {
        win_skip("skipping activation context tests\n");
        return;
    }

    create_manifest_file("testdep1.manifest", manifest_dep);
    create_manifest_file("main.manifest", manifest_main);

    context = test_create("main.manifest");
    DeleteFileA("testdep1.manifest");
    DeleteFileA("main.manifest");

    handle = (void*)0xdeadbeef;
    b = pGetCurrentActCtx(&handle);
    ok(b, "GetCurrentActCtx failed: %u\n", GetLastError());
    ok(handle == 0, "active context %p\n", handle);

    /* without active context */
    param.thread_context = (void*)0xdeadbeef;
    param.handle = NULL;
    thread = CreateThread(NULL, 0, thread_actctx_func, &param, 0, &tid);
    ok(thread != NULL, "failed, got %u\n", GetLastError());

    ret = WaitForSingleObject(thread, 1000);
    ok(ret == WAIT_OBJECT_0, "wait timeout\n");
    ok(param.thread_context == NULL, "got wrong thread context %p\n", param.thread_context);
    CloseHandle(thread);

    b = pActivateActCtx(context, &cookie);
    ok(b, "activation failed: %u\n", GetLastError());

    handle = 0;
    b = pGetCurrentActCtx(&handle);
    ok(b, "GetCurrentActCtx failed: %u\n", GetLastError());
    ok(handle != 0, "no active context\n");
    pReleaseActCtx(handle);

    param.handle = NULL;
    b = pGetCurrentActCtx(&param.handle);
    ok(b && param.handle != NULL, "failed to get context, %u\n", GetLastError());

    param.thread_context = (void*)0xdeadbeef;
    thread = CreateThread(NULL, 0, thread_actctx_func, &param, 0, &tid);
    ok(thread != NULL, "failed, got %u\n", GetLastError());

    ret = WaitForSingleObject(thread, 1000);
    ok(ret == WAIT_OBJECT_0, "wait timeout\n");
    ok(param.thread_context == context, "got wrong thread context %p, %p\n", param.thread_context, context);
    pReleaseActCtx(param.thread_context);
    CloseHandle(thread);

    /* similar test for CreateRemoteThread() */
    param.thread_context = (void*)0xdeadbeef;
    thread = CreateRemoteThread(GetCurrentProcess(), NULL, 0, thread_actctx_func, &param, 0, &tid);
    ok(thread != NULL, "failed, got %u\n", GetLastError());

    ret = WaitForSingleObject(thread, 1000);
    ok(ret == WAIT_OBJECT_0, "wait timeout\n");
    ok(param.thread_context == context, "got wrong thread context %p, %p\n", param.thread_context, context);
    pReleaseActCtx(param.thread_context);
    CloseHandle(thread);

    pReleaseActCtx(param.handle);

    b = pDeactivateActCtx(0, cookie);
    ok(b, "DeactivateActCtx failed: %u\n", GetLastError());
    pReleaseActCtx(context);
}

