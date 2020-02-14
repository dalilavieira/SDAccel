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
typedef  int /*<<< orphan*/ * HANDLE ;
typedef  char* DWORD ;

/* Variables and functions */
 int /*<<< orphan*/  CloseHandle (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DBG_UNREFERENCED_LOCAL_VARIABLE (char) ; 
 scalar_t__ FALSE ; 
 int /*<<< orphan*/ * OpenProcess (int /*<<< orphan*/ ,scalar_t__,char*) ; 
 int /*<<< orphan*/  PROCESS_TERMINATE ; 
 scalar_t__ TerminateProcess (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ atol (char*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  stderr ; 

int
ExecuteKill(char * lpPid)
{
	HANDLE	hProcess;
	DWORD	dwProcessId;

	dwProcessId = (DWORD) atol(lpPid);
		fprintf( stderr, "Killing PID %ld...\n",dwProcessId);
	hProcess = OpenProcess(
			PROCESS_TERMINATE,
			FALSE,
			dwProcessId
			);
	if (NULL == hProcess)
	{
		fprintf( stderr, "Could not open the process with PID = %ld\n", dwProcessId);
		return 0;
	}
	if (FALSE == TerminateProcess(
			hProcess,
			0
			)
	) {
		fprintf( stderr, "Could not terminate the process with PID = %ld\n",	dwProcessId);
		return 0;
	}
	CloseHandle(hProcess);
	return 0;
}

int main(int argc, char *argv[])
{
  char tail;
  DBG_UNREFERENCED_LOCAL_VARIABLE(tail);

  if (argc < 2)
  {
      fprintf( stderr, "Usage: %s PID (Process ID) \n", argv[0] );
      return 1;
  }
  tail = ExecuteKill(argv[1]);
  return 0;
}

