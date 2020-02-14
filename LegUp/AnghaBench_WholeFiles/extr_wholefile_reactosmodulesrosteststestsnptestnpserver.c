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
typedef  int /*<<< orphan*/  VOID ;
typedef  scalar_t__ LPVOID ;
typedef  int /*<<< orphan*/ * LPTSTR ;
typedef  scalar_t__* LPDWORD ;
typedef  scalar_t__ HANDLE ;
typedef  scalar_t__ DWORD ;
typedef  int /*<<< orphan*/  CHAR ;
typedef  int BOOL ;

/* Variables and functions */
 int BUFSIZE ; 
 int /*<<< orphan*/  CloseHandle (scalar_t__) ; 
 scalar_t__ ConnectNamedPipe (scalar_t__,int /*<<< orphan*/ *) ; 
 scalar_t__ CreateNamedPipe (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DisconnectNamedPipe (scalar_t__) ; 
 scalar_t__ ERROR_PIPE_CONNECTED ; 
 int /*<<< orphan*/  ExitProcess (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FlushFileBuffers (scalar_t__) ; 
 scalar_t__ GetLastError () ; 
 scalar_t__ INVALID_HANDLE_VALUE ; 
 int /*<<< orphan*/  PIPE_ACCESS_DUPLEX ; 
 int PIPE_READMODE_MESSAGE ; 
 int /*<<< orphan*/  PIPE_TIMEOUT ; 
 int PIPE_TYPE_MESSAGE ; 
 int /*<<< orphan*/  PIPE_UNLIMITED_INSTANCES ; 
 int PIPE_WAIT ; 
 int ReadFile (scalar_t__,int /*<<< orphan*/ *,int,scalar_t__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * TEXT (char*) ; 
 int TRUE ; 
 int WriteFile (scalar_t__,int /*<<< orphan*/ *,scalar_t__,scalar_t__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  printf (char*) ; 
 int /*<<< orphan*/  puts (int /*<<< orphan*/ *) ; 

VOID
GetAnswerToRequest(LPTSTR lpRequest,
		   LPTSTR lpReply,
		   LPDWORD lpcbReplyBytes)
{
}

VOID MyErrExit(LPTSTR Message)
{
//	MessageBox(NULL, Message, NULL, MB_OK);
   puts(Message);
   ExitProcess(0);
}

int main(int argc, char *argv[])
{
   BOOL fConnected;
   DWORD dwThreadId;
   HANDLE hPipe, hThread;
   LPTSTR lpszPipename = TEXT("\\\\.\\pipe\\mynamedpipe");

//   for (;;)
//     {
	hPipe = CreateNamedPipe(lpszPipename,
				PIPE_ACCESS_DUPLEX,
				PIPE_TYPE_MESSAGE |
				PIPE_READMODE_MESSAGE |
				PIPE_WAIT,
				PIPE_UNLIMITED_INSTANCES,
				BUFSIZE,
				BUFSIZE,
				PIPE_TIMEOUT,
				NULL);
	if (hPipe == INVALID_HANDLE_VALUE)
	  {
	     printf("CreateNamedPipe() failed\n");
	     return 0;
	  }

	fConnected = ConnectNamedPipe(hPipe,
				      NULL) ? TRUE : (GetLastError () ==
					    ERROR_PIPE_CONNECTED);
	if (fConnected)
	  {
	     printf("Pipe connected!\n");

	     DisconnectNamedPipe(hPipe);

#if 0
	     hThread = CreateThread(NULL,
				    0,
				    (LPTHREAD_START_ROUTINE) InstanceThread,
				    (LPVOID) hPipe,
				    0,
				    &dwThreadId);
	     if (hThread == NULL)
	       MyErrExit("CreateThread");
#endif
	  }
	else
	  {
//	     CloseHandle(hPipe);
	  }
//     }

   CloseHandle(hPipe);

   return 0;
}

VOID InstanceThread (LPVOID lpvParam)
{
   CHAR chRequest[BUFSIZE];
   CHAR chReply[BUFSIZE];
   DWORD cbBytesRead, cbReplyBytes, cbWritten;
   BOOL fSuccess;
   HANDLE hPipe;

   hPipe = (HANDLE)lpvParam;
   while (1)
     {
	fSuccess = ReadFile(hPipe,
			    chRequest,
			    BUFSIZE,
			    &cbBytesRead,
			    NULL);
	if (!fSuccess || cbBytesRead == 0)
	  break;

	GetAnswerToRequest(chRequest, chReply, &cbReplyBytes);

	fSuccess = WriteFile(hPipe,
			     chReply,
			     cbReplyBytes,
			     &cbWritten,
			     NULL);
	if (!fSuccess || cbReplyBytes != cbWritten)
	  break;
    }

   FlushFileBuffers(hPipe);
   DisconnectNamedPipe(hPipe);
   CloseHandle(hPipe);
}

