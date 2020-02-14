#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  sa ;
typedef  int /*<<< orphan*/  new_name ;
struct TYPE_8__ {size_t capacity; size_t size; scalar_t__ read_data; int /*<<< orphan*/  handle; int /*<<< orphan*/  ready_event; } ;
typedef  TYPE_1__ ipc_pipe_server_t ;
struct TYPE_9__ {int nLength; int bInheritHandle; void* lpSecurityDescriptor; } ;
typedef  TYPE_2__ SECURITY_ATTRIBUTES ;
typedef  int DWORD ;

/* Variables and functions */
 int /*<<< orphan*/  CreateEvent (int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CreateNamedPipeA (char*,int const,int const,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_2__*) ; 
 scalar_t__ ERROR_IO_PENDING ; 
 int FILE_FLAG_OVERLAPPED ; 
 scalar_t__ GetLastError () ; 
 int /*<<< orphan*/  INVALID_HANDLE_VALUE ; 
 int /*<<< orphan*/  IPC_PIPE_BUF_SIZE ; 
 int /*<<< orphan*/  InitializeSecurityDescriptor (void*,int /*<<< orphan*/ ) ; 
 int PIPE_ACCESS_DUPLEX ; 
 int PIPE_READMODE_MESSAGE ; 
 int PIPE_TYPE_MESSAGE ; 
 int PIPE_WAIT ; 
 int /*<<< orphan*/  SECURITY_DESCRIPTOR_MIN_LENGTH ; 
 int /*<<< orphan*/  SECURITY_DESCRIPTOR_REVISION ; 
 int /*<<< orphan*/  SetSecurityDescriptorDacl (void*,int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  free (void*) ; 
 void* malloc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (scalar_t__,int /*<<< orphan*/ *,size_t) ; 
 scalar_t__ realloc (scalar_t__,size_t) ; 
 int /*<<< orphan*/  strcat_s (char*,int,char const*) ; 
 int /*<<< orphan*/  strcpy_s (char*,int,char*) ; 

__attribute__((used)) static inline bool ipc_pipe_internal_create_events(ipc_pipe_server_t *pipe)
{
	pipe->ready_event = CreateEvent(NULL, false, false, NULL);
	return !!pipe->ready_event;
}

__attribute__((used)) static inline void *create_full_access_security_descriptor()
{
	void *sd = malloc(SECURITY_DESCRIPTOR_MIN_LENGTH);
	if (!sd) {
		return NULL;
	}

	if (!InitializeSecurityDescriptor(sd, SECURITY_DESCRIPTOR_REVISION)) {
		goto error;
	}

	if (!SetSecurityDescriptorDacl(sd, true, NULL, false)) {
		goto error;
	}

	return sd;

error:
	free(sd);
	return NULL;
}

__attribute__((used)) static inline bool ipc_pipe_internal_create_pipe(ipc_pipe_server_t *pipe,
		const char *name)
{
	SECURITY_ATTRIBUTES sa;
	char new_name[512];
	void *sd;
	const DWORD access = PIPE_ACCESS_DUPLEX | FILE_FLAG_OVERLAPPED;
	const DWORD flags = PIPE_TYPE_MESSAGE     |
	                    PIPE_READMODE_MESSAGE |
	                    PIPE_WAIT;

	strcpy_s(new_name, sizeof(new_name), "\\\\.\\pipe\\");
	strcat_s(new_name, sizeof(new_name), name);

	sd = create_full_access_security_descriptor();
	if (!sd) {
		return false;
	}

	sa.nLength = sizeof(sa);
	sa.lpSecurityDescriptor = sd;
	sa.bInheritHandle = false;

	pipe->handle = CreateNamedPipeA(new_name, access, flags, 1,
			IPC_PIPE_BUF_SIZE, IPC_PIPE_BUF_SIZE, 0, &sa);
	free(sd);

	return pipe->handle != INVALID_HANDLE_VALUE;
}

__attribute__((used)) static inline void ipc_pipe_internal_ensure_capacity(ipc_pipe_server_t *pipe,
		size_t new_size)
{
	if (pipe->capacity >= new_size) {
		return;
	}

	pipe->read_data = realloc(pipe->read_data, new_size);
	pipe->capacity = new_size;
}

__attribute__((used)) static inline void ipc_pipe_internal_append_bytes(ipc_pipe_server_t *pipe,
		uint8_t *bytes, size_t size)
{
	size_t new_size = pipe->size + size;
	ipc_pipe_internal_ensure_capacity(pipe, new_size);
	memcpy(pipe->read_data + pipe->size, bytes, size);
	pipe->size = new_size;
}

__attribute__((used)) static inline bool ipc_pipe_internal_io_pending(void)
{
	return GetLastError() == ERROR_IO_PENDING;
}

