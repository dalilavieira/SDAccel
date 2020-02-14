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
typedef  scalar_t__* PHANDLE ;
typedef  int /*<<< orphan*/  LPCWCHAR ;
typedef  int /*<<< orphan*/  LPCVOID ;
typedef  int /*<<< orphan*/ * LPBYTE ;
typedef  scalar_t__ HANDLE ;
typedef  int DWORD ;
typedef  int /*<<< orphan*/  BYTE ;
typedef  int BOOL ;

/* Variables and functions */
 int CloseHandle (scalar_t__) ; 
 scalar_t__ ConnectNamedPipe (scalar_t__,int /*<<< orphan*/ *) ; 
 scalar_t__ CreateFile (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ CreateNamedPipe (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DisconnectNamedPipe (scalar_t__) ; 
 scalar_t__ ERROR_MORE_DATA ; 
 scalar_t__ ERROR_PIPE_CONNECTED ; 
 scalar_t__ ERROR_PIPE_NOT_CONNECTED ; 
 int FALSE ; 
 int FlushFileBuffers (scalar_t__) ; 
 int GENERIC_READ ; 
 int GENERIC_WRITE ; 
 scalar_t__ GetLastError () ; 
 scalar_t__ GetNamedPipeInfo (scalar_t__,int*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ INVALID_HANDLE_VALUE ; 
 int /*<<< orphan*/  LPTR ; 
 scalar_t__ LocalAlloc (int /*<<< orphan*/ ,int) ; 
 scalar_t__ LocalFree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  NMPWAIT_USE_DEFAULT_WAIT ; 
 int /*<<< orphan*/  OPEN_EXISTING ; 
 int /*<<< orphan*/  PIPE_ACCESS_DUPLEX ; 
 int PIPE_READMODE_MESSAGE ; 
 int PIPE_SERVER_END ; 
 int PIPE_TYPE_MESSAGE ; 
 int PIPE_WAIT ; 
 int /*<<< orphan*/  PRINT_ERROR_AUTO (char*) ; 
 int ReadFile (scalar_t__,int /*<<< orphan*/ *,int,int*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  RtlCopyMemory (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int SetNamedPipeHandleState (scalar_t__,int*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ WaitNamedPipe (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ WriteFile (scalar_t__,int /*<<< orphan*/ ,int,int*,int /*<<< orphan*/ *) ; 

BOOL kull_m_pipe_server(LPCWCHAR pipeName, HANDLE *phPipe)
{
	BOOL status = FALSE;
	*phPipe = CreateNamedPipe(pipeName,  PIPE_ACCESS_DUPLEX, PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT, 1, 0, 0, NMPWAIT_USE_DEFAULT_WAIT, NULL);
	if(!(status = (*phPipe && (*phPipe != INVALID_HANDLE_VALUE))))
		PRINT_ERROR_AUTO(L"CreateNamedPipe");
	return status;
}

BOOL kull_m_pipe_server_connect(HANDLE hPipe)
{
	BOOL status = FALSE;
	if(!(status = (ConnectNamedPipe(hPipe, NULL) || (GetLastError() == ERROR_PIPE_CONNECTED))))
		PRINT_ERROR_AUTO(L"ConnectNamedPipe");
	return status;
}

BOOL kull_m_pipe_client(LPCWCHAR pipeName, PHANDLE phPipe)
{
	BOOL status = FALSE;
	DWORD dwMode = PIPE_READMODE_MESSAGE | PIPE_WAIT;
	if(WaitNamedPipe(pipeName, NMPWAIT_USE_DEFAULT_WAIT))
	{
		*phPipe = CreateFile(pipeName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
		if(*phPipe && (*phPipe != INVALID_HANDLE_VALUE))
		{
			if(!(status = SetNamedPipeHandleState(*phPipe, &dwMode, NULL, NULL)))
				PRINT_ERROR_AUTO(L"SetNamedPipeHandleState");
		}
		else PRINT_ERROR_AUTO(L"CreateFile");
	}
	else PRINT_ERROR_AUTO(L"WaitNamedPipe");
	return status;
}

BOOL kull_m_pipe_read(HANDLE hPipe, LPBYTE *buffer, DWORD *size)
{
	BOOL status = FALSE;
	DWORD szReaded, szBuffer = 0;
	BYTE * tmpBuffer = NULL; DWORD szTmpBuffer = 0;

	*size = 0;
	*buffer = NULL;
	do
	{
		if(*buffer)
		{
			tmpBuffer = *buffer;
			szTmpBuffer = szBuffer;
		}
	
		szBuffer += 2048;
		if(*buffer = (BYTE *) LocalAlloc(LPTR, szBuffer))
		{
			if(tmpBuffer)
			{
				RtlCopyMemory(*buffer, tmpBuffer, szTmpBuffer);
				tmpBuffer = (BYTE *) LocalFree(tmpBuffer);
			}

			if(status = ReadFile(hPipe, *buffer + szTmpBuffer, 2048, &szReaded, NULL))
			{
				*size = szTmpBuffer + szReaded;
				break;
			}
		}
	} while(GetLastError() == ERROR_MORE_DATA);

	if(!status)
	{
		PRINT_ERROR_AUTO(L"ReadFile");
		*buffer = (BYTE *) LocalFree(*buffer);
		*size = 0;
	}
	return status;
}

BOOL kull_m_pipe_write(HANDLE hPipe, LPCVOID buffer, DWORD size)
{
	BOOL status = FALSE;
	DWORD nbWritten;
	if(WriteFile(hPipe, buffer, size, &nbWritten, NULL) && (size == nbWritten))
	{
		if(!(status = FlushFileBuffers(hPipe)))
			PRINT_ERROR_AUTO(L"FlushFileBuffers");
	}
	else PRINT_ERROR_AUTO(L"WriteFile");
	return status;
}

BOOL kull_m_pipe_close(PHANDLE phPipe)
{
	BOOL status = FALSE;
	DWORD flags = 0;
	if(*phPipe && (*phPipe != INVALID_HANDLE_VALUE))
	{
		if(GetNamedPipeInfo(*phPipe, &flags, NULL, NULL, NULL) || (GetLastError() == ERROR_PIPE_NOT_CONNECTED))
		{
			if(flags & PIPE_SERVER_END)
			{
				if(!DisconnectNamedPipe(*phPipe))
					PRINT_ERROR_AUTO(L"DisconnectNamedPipe");
			}
			if(status = CloseHandle(*phPipe))
				*phPipe = INVALID_HANDLE_VALUE;
			else PRINT_ERROR_AUTO(L"CloseHandle");
		}
		else PRINT_ERROR_AUTO(L"GetNamedPipeInfo");
	}
	return status;
}

