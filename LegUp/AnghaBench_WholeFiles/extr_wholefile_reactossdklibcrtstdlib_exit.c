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

/* Variables and functions */
 int /*<<< orphan*/  ExitProcess (int) ; 
 int /*<<< orphan*/  LOCK_EXIT ; 
 int /*<<< orphan*/  UNLOCK_EXIT ; 
 int /*<<< orphan*/  WARN (char*,int) ; 
 int /*<<< orphan*/  __call_atexit () ; 

void _cexit( void )
{
  LOCK_EXIT;
  __call_atexit();
  UNLOCK_EXIT;
}

void _c_exit( void )
{
  /* All cleanup is done on DLL detach; Return to caller */
}

void _exit(int exitcode)
{
    ExitProcess(exitcode);
}

void exit(int exitcode)
{
#if 0
  HMODULE hmscoree;
  static const WCHAR mscoreeW[] = {'m','s','c','o','r','e','e',0};
  void (WINAPI *pCorExitProcess)(int);
#endif
  WARN("exit(%d) called\n",exitcode);
  _cexit();
#if 0 
  hmscoree = GetModuleHandleW(mscoreeW);

  if (hmscoree)
  {
    pCorExitProcess = (void*)GetProcAddress(hmscoree, "CorExitProcess");

    if (pCorExitProcess)
      pCorExitProcess(exitcode);
  }
#endif
  ExitProcess(exitcode);

}

