#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8 ;
typedef  size_t uint32 ;
struct TYPE_11__ {TYPE_1__* rdpdr_device; } ;
struct TYPE_10__ {int handle; scalar_t__ local_path; void* pdevice_data; int /*<<< orphan*/  device_type; scalar_t__ name; } ;
typedef  int /*<<< orphan*/  STREAM ;
typedef  TYPE_2__ RDPCLIENT ;
typedef  int /*<<< orphan*/  PARALLEL_DEVICE ;
typedef  int NTSTATUS ;
typedef  int NTHANDLE ;

/* Variables and functions */
 int /*<<< orphan*/  DEVICE_TYPE_PARALLEL ; 
#define  EAGAIN 131 
#define  EIO 130 
#define  ENOSPC 129 
 size_t FILE_DEVICE_PARALLEL ; 
 int /*<<< orphan*/  F_SETFL ; 
#define  IOCTL_PAR_QUERY_RAW_DEVICE_ID 128 
 int /*<<< orphan*/  O_NONBLOCK ; 
 int /*<<< orphan*/  O_RDWR ; 
 size_t RDPDR_MAX_DEVICES ; 
 int STATUS_ACCESS_DENIED ; 
 int STATUS_DEVICE_OFF_LINE ; 
 int STATUS_DEVICE_PAPER_EMPTY ; 
 int STATUS_DEVICE_POWERED_OFF ; 
 int STATUS_INVALID_PARAMETER ; 
 int STATUS_SUCCESS ; 
 int /*<<< orphan*/  close (int) ; 
 int errno ; 
 int fcntl (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int get_device_index (TYPE_2__*,int) ; 
 char* next_arg (char*,char) ; 
 int open (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  perror (char*) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 size_t read (int,int /*<<< orphan*/ *,size_t) ; 
 int /*<<< orphan*/  strcpy (scalar_t__,char*) ; 
 int strlen (char*) ; 
 int /*<<< orphan*/  toupper_str (scalar_t__) ; 
 int /*<<< orphan*/  unimpl (char*,size_t) ; 
 int write (int,int /*<<< orphan*/ *,size_t) ; 
 scalar_t__ xmalloc (int) ; 

int
parallel_enum_devices(RDPCLIENT * This, uint32 * id, char *optarg)
{
	PARALLEL_DEVICE *ppar_info;

	char *pos = optarg;
	char *pos2;
	int count = 0;

	/* skip the first colon */
	optarg++;
	while ((pos = next_arg(optarg, ',')) && *id < RDPDR_MAX_DEVICES)
	{
		ppar_info = (PARALLEL_DEVICE *) xmalloc(sizeof(PARALLEL_DEVICE));

		pos2 = next_arg(optarg, '=');
		strcpy(This->rdpdr_device[*id].name, optarg);

		toupper_str(This->rdpdr_device[*id].name);

		This->rdpdr_device[*id].local_path = xmalloc(strlen(pos2) + 1);
		strcpy(This->rdpdr_device[*id].local_path, pos2);
		printf("PARALLEL %s to %s\n", optarg, pos2);

		/* set device type */
		This->rdpdr_device[*id].device_type = DEVICE_TYPE_PARALLEL;
		This->rdpdr_device[*id].pdevice_data = (void *) ppar_info;
		This->rdpdr_device[*id].handle = 0;
		count++;
		(*id)++;

		optarg = pos;
	}
	return count;
}

__attribute__((used)) static NTSTATUS
parallel_create(RDPCLIENT * This, uint32 device_id, uint32 access, uint32 share_mode, uint32 disposition,
		uint32 flags, char *filename, NTHANDLE * handle)
{
	int parallel_fd;

	parallel_fd = open(This->rdpdr_device[device_id].local_path, O_RDWR);
	if (parallel_fd == -1)
	{
		perror("open");
		return STATUS_ACCESS_DENIED;
	}

	/* all read and writes should be non blocking */
	if (fcntl(parallel_fd, F_SETFL, O_NONBLOCK) == -1)
		perror("fcntl");

#if defined(LPABORT)
	/* Retry on errors */
	ioctl(parallel_fd, LPABORT, (int) 1);
#endif

	This->rdpdr_device[device_id].handle = parallel_fd;

	*handle = parallel_fd;

	return STATUS_SUCCESS;
}

__attribute__((used)) static NTSTATUS
parallel_close(RDPCLIENT * This, NTHANDLE handle)
{
	int i = get_device_index(This, handle);
	if (i >= 0)
		This->rdpdr_device[i].handle = 0;
	close(handle);
	return STATUS_SUCCESS;
}

__attribute__((used)) static NTSTATUS
parallel_read(RDPCLIENT * This, NTHANDLE handle, uint8 * data, uint32 length, uint32 offset, uint32 * result)
{
	*result = read(handle, data, length);
	return STATUS_SUCCESS;
}

__attribute__((used)) static NTSTATUS
parallel_write(RDPCLIENT * This, NTHANDLE handle, uint8 * data, uint32 length, uint32 offset, uint32 * result)
{
	int rc = STATUS_SUCCESS;

	int n = write(handle, data, length);
	if (n < 0)
	{
#if defined(LPGETSTATUS)
		int status;
#endif

		*result = 0;
		switch (errno)
		{
			case EAGAIN:
				rc = STATUS_DEVICE_OFF_LINE;
			case ENOSPC:
				rc = STATUS_DEVICE_PAPER_EMPTY;
			case EIO:
				rc = STATUS_DEVICE_OFF_LINE;
			default:
				rc = STATUS_DEVICE_POWERED_OFF;
		}
#if defined(LPGETSTATUS)
		if (ioctl(handle, LPGETSTATUS, &status) == 0)
		{
			/* coming soon: take care for the printer status */
			printf("parallel_write: status = %d, errno = %d\n", status, errno);
		}
#endif
	}
	*result = n;
	return rc;
}

__attribute__((used)) static NTSTATUS
parallel_device_control(RDPCLIENT * This, NTHANDLE handle, uint32 request, STREAM in, STREAM out)
{
	if ((request >> 16) != FILE_DEVICE_PARALLEL)
		return STATUS_INVALID_PARAMETER;

	/* extract operation */
	request >>= 2;
	request &= 0xfff;

	printf("PARALLEL IOCTL %d: ", request);

	switch (request)
	{
		case IOCTL_PAR_QUERY_RAW_DEVICE_ID:

		default:

			printf("\n");
			unimpl("UNKNOWN IOCTL %d\n", request);
	}
	return STATUS_SUCCESS;
}

