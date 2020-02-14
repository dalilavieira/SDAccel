#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ ULONG_PTR ;
typedef  int ULONG ;
struct TYPE_8__ {int /*<<< orphan*/  Information; int /*<<< orphan*/  Status; } ;
struct TYPE_7__ {int QuadPart; } ;
typedef  char* PVOID ;
typedef  int /*<<< orphan*/ * PULONG ;
typedef  TYPE_1__* PLARGE_INTEGER ;
typedef  int /*<<< orphan*/  OBJECT_ATTRIBUTES ;
typedef  int /*<<< orphan*/  NTSTATUS ;
typedef  TYPE_1__ LARGE_INTEGER ;
typedef  TYPE_3__ IO_STATUS_BLOCK ;
typedef  scalar_t__ HANDLE ;
typedef  int /*<<< orphan*/  DWORD ;
typedef  int /*<<< orphan*/  CHAR ;
typedef  scalar_t__ BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  CloseHandle (scalar_t__) ; 
 scalar_t__ CreateFile (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  EVENT_ALL_ACCESS ; 
 scalar_t__ FALSE ; 
 int FILE_SHARE_READ ; 
 int FILE_SHARE_WRITE ; 
 int /*<<< orphan*/  GENERIC_READ ; 
 scalar_t__ INVALID_HANDLE_VALUE ; 
 int /*<<< orphan*/  InitializeObjectAttributes (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  NT_SUCCESS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NtClose (scalar_t__) ; 
 int /*<<< orphan*/  NtCreateEvent (scalar_t__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  NtReadFile (scalar_t__,scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_3__*,char*,int,TYPE_1__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  NtWaitForSingleObject (scalar_t__,scalar_t__,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  OPEN_EXISTING ; 
 int /*<<< orphan*/  STATUS_END_OF_FILE ; 
 int /*<<< orphan*/  STATUS_PENDING ; 
 scalar_t__ TRUE ; 
 int /*<<< orphan*/  free (char*) ; 
 scalar_t__ isprint (unsigned char) ; 
 scalar_t__ malloc (int) ; 
 int /*<<< orphan*/  memset (char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  strcat (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  strcpy (int /*<<< orphan*/ *,char*) ; 

void HexDump(char *buffer, ULONG size)
{
  ULONG offset = 0;
  unsigned char *ptr;

  while (offset < (size & ~15))
    {
      ptr = (unsigned char*)((ULONG_PTR)buffer + offset);
      printf("%08lx  %02hx %02hx %02hx %02hx %02hx %02hx %02hx %02hx-%02hx %02hx %02hx %02hx %02hx %02hx %02hx %02hx",
	     offset,
	     ptr[0],
	     ptr[1],
	     ptr[2],
	     ptr[3],
	     ptr[4],
	     ptr[5],
	     ptr[6],
	     ptr[7],
	     ptr[8],
	     ptr[9],
	     ptr[10],
	     ptr[11],
	     ptr[12],
	     ptr[13],
	     ptr[14],
	     ptr[15]);

      printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
	     isprint(ptr[0])?ptr[0]:'.',
	     isprint(ptr[1])?ptr[1]:'.',
	     isprint(ptr[2])?ptr[2]:'.',
	     isprint(ptr[3])?ptr[3]:'.',
	     isprint(ptr[4])?ptr[4]:'.',
	     isprint(ptr[5])?ptr[5]:'.',
	     isprint(ptr[6])?ptr[6]:'.',
	     isprint(ptr[7])?ptr[7]:'.',
	     isprint(ptr[8])?ptr[8]:'.',
	     isprint(ptr[9])?ptr[9]:'.',
	     isprint(ptr[10])?ptr[10]:'.',
	     isprint(ptr[11])?ptr[11]:'.',
	     isprint(ptr[12])?ptr[12]:'.',
	     isprint(ptr[13])?ptr[13]:'.',
	     isprint(ptr[14])?ptr[14]:'.',
	     isprint(ptr[15])?ptr[15]:'.');

      offset += 16;
    }

  ptr = (unsigned char*)((ULONG_PTR)buffer + offset);
  if (offset < size)
    {
      printf("%08lx ", offset);
      while (offset < size)
	{
	  printf(" %02hx", *ptr);
	  offset++;
	  ptr++;
	}
    }

  printf("\n\n");
}

BOOL
ReadBlock(HANDLE FileHandle,
	  PVOID Buffer,
	  PLARGE_INTEGER Offset,
	  ULONG Length,
	  PULONG BytesRead)
{
  IO_STATUS_BLOCK IoStatusBlock;
  OBJECT_ATTRIBUTES ObjectAttributes;
  NTSTATUS Status;
  HANDLE EventHandle;

  InitializeObjectAttributes(&ObjectAttributes,
			     NULL, 0, NULL, NULL);

  Status = NtCreateEvent(&EventHandle,
			 EVENT_ALL_ACCESS,
			 &ObjectAttributes,
			 TRUE,
			 FALSE);
  if (!NT_SUCCESS(Status))
    {
      printf("NtCreateEvent() failed\n");
      return(FALSE);
    }

  Status = NtReadFile(FileHandle,
		      EventHandle,
		      NULL,
		      NULL,
		      &IoStatusBlock,
		      Buffer,
		      Length,
		      Offset,
		      NULL);
  if (Status == STATUS_PENDING)
    {
      NtWaitForSingleObject(EventHandle, FALSE, NULL);
      Status = IoStatusBlock.Status;
    }

  NtClose(EventHandle);

  if (Status != STATUS_PENDING && BytesRead != NULL)
    {
      *BytesRead = IoStatusBlock.Information;
    }
  if (!NT_SUCCESS(Status) && Status != STATUS_END_OF_FILE)
    {
      printf("ReadBlock() failed (Status: %lx)\n", Status);
      return(FALSE);
    }

  return(TRUE);
}

int main (int argc, char *argv[])
{
  HANDLE hDisk;
  DWORD dwRead;
  char *Buffer;
  CHAR Filename[80];
  LARGE_INTEGER FilePosition;

  if (argc != 2)
    {
      printf("Usage: isotest [Drive:]\n");
      return 0;
    }

  strcpy(Filename, "\\\\.\\");
  strcat(Filename, argv[1]);

  hDisk = CreateFile(Filename,
		     GENERIC_READ,
		     FILE_SHARE_READ | FILE_SHARE_WRITE,
		     NULL,
		     OPEN_EXISTING,
		     0,
		     NULL);
  if (hDisk == INVALID_HANDLE_VALUE)
    {
      printf("CreateFile(): Invalid disk handle!\n");
      return 0;
    }

  Buffer = (char*)malloc(2048);
  if (Buffer == NULL)
    {
      CloseHandle(hDisk);
      printf("Out of memory!\n");
      return 0;
    }
  memset(Buffer, 0, 2048);


  FilePosition.QuadPart = 16 * 2048;
#if 0
  SetLastError(NO_ERROR);
  SetFilePointer(hDisk,
		 FilePosition.u.LowPart,
		 &FilePosition.u.HighPart,
		 FILE_BEGIN);
  if (GetLastError() != NO_ERROR)
    {
      CloseHandle(hDisk);
      free(Buffer);
      printf("SetFilePointer() failed!\n");
      return 0;
    }

  if (ReadFile(hDisk,
	       Buffer,
	       2048,
	       &dwRead,
	       NULL) == FALSE)
    {
      CloseHandle(hDisk);
      free(Buffer);
      printf("ReadFile() failed!\n");
      return 0;
    }
#endif

  if (ReadBlock(hDisk,
		Buffer,
		&FilePosition,
		2048,
		&dwRead) == FALSE)
    {
      CloseHandle(hDisk);
      free(Buffer);
#if 0
      printf("ReadBlock() failed!\n");
#endif
      return 0;
    }

  HexDump(Buffer, 128);

  CloseHandle(hDisk);

  free(Buffer);

  return 0;
}

