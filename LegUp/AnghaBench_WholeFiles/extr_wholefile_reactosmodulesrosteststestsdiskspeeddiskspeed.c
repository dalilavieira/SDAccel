#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_23__   TYPE_6__ ;
typedef  struct TYPE_22__   TYPE_5__ ;
typedef  struct TYPE_21__   TYPE_4__ ;
typedef  struct TYPE_20__   TYPE_3__ ;
typedef  struct TYPE_19__   TYPE_2__ ;
typedef  struct TYPE_18__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ULONG ;
struct TYPE_23__ {int Offset; } ;
struct TYPE_22__ {char* VendorId; } ;
struct TYPE_21__ {int NumberOfBuses; TYPE_1__* BusData; } ;
struct TYPE_20__ {scalar_t__ PathId; scalar_t__ TargetId; scalar_t__ Lun; scalar_t__ NextInquiryDataOffset; int /*<<< orphan*/  InquiryData; } ;
struct TYPE_19__ {scalar_t__ PathId; scalar_t__ TargetId; scalar_t__ Lun; } ;
struct TYPE_18__ {int InquiryDataOffset; } ;
typedef  int /*<<< orphan*/  ScsiAddress ;
typedef  TYPE_2__ SCSI_ADDRESS ;
typedef  TYPE_3__* PSCSI_INQUIRY_DATA ;
typedef  TYPE_4__* PSCSI_ADAPTER_BUS_INFO ;
typedef  TYPE_5__* PINQUIRYDATA ;
typedef  TYPE_6__* PBYTE ;
typedef  TYPE_6__ OVERLAPPED ;
typedef  TYPE_5__ INQUIRYDATA ;
typedef  scalar_t__ HANDLE ;
typedef  int DWORD ;
typedef  char CHAR ;
typedef  int /*<<< orphan*/  Buffer ;
typedef  TYPE_2__ BYTE ;
typedef  scalar_t__ BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  CloseHandle (scalar_t__) ; 
 scalar_t__ CreateFile (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ DeviceIoControl (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,TYPE_2__*,int,int*,scalar_t__) ; 
 scalar_t__ FALSE ; 
 int /*<<< orphan*/  FILE_SHARE_READ ; 
 int /*<<< orphan*/  GENERIC_READ ; 
 int GetTickCount () ; 
 scalar_t__ INVALID_HANDLE_VALUE ; 
 int /*<<< orphan*/  IOCTL_SCSI_GET_ADDRESS ; 
 int /*<<< orphan*/  IOCTL_SCSI_GET_INQUIRY_DATA ; 
 int /*<<< orphan*/  MEM_COMMIT ; 
 int /*<<< orphan*/  MEM_RELEASE ; 
 int /*<<< orphan*/  OPEN_EXISTING ; 
 int /*<<< orphan*/  PAGE_READWRITE ; 
 scalar_t__ ReadFile (scalar_t__,TYPE_6__*,int,int*,TYPE_6__*) ; 
 scalar_t__ TRUE ; 
 TYPE_6__* VirtualAlloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  VirtualFree (TYPE_6__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (TYPE_5__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  memset (TYPE_6__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int /*<<< orphan*/ ) ; 

BOOL GetInquiryData(HANDLE hDevice, PINQUIRYDATA InquiryData)
{
  BOOL Result;
  DWORD dwReturned;
  SCSI_ADDRESS ScsiAddress;
  PSCSI_ADAPTER_BUS_INFO AdapterInfo;
  PSCSI_INQUIRY_DATA InquiryBuffer;
  BYTE Buffer[4096];
  int i;

  Result = DeviceIoControl(hDevice,
	                   IOCTL_SCSI_GET_ADDRESS,
			   NULL,
			   0,
			   &ScsiAddress,
			   sizeof(ScsiAddress),
			   &dwReturned,
			   FALSE);
  if (Result == FALSE)
    {
      return FALSE;
    }
  Result = DeviceIoControl(hDevice,
	                   IOCTL_SCSI_GET_INQUIRY_DATA,
			   NULL,
			   0,
			   Buffer,
			   sizeof(Buffer),
			   &dwReturned,
			   FALSE);
  if (Result)
    {
      AdapterInfo = (PSCSI_ADAPTER_BUS_INFO)Buffer;
      for (i = 0; i < AdapterInfo->NumberOfBuses; i++)
	{
	  InquiryBuffer = (PSCSI_INQUIRY_DATA) (Buffer + AdapterInfo->BusData[i].InquiryDataOffset);
	  if (AdapterInfo->BusData[i].InquiryDataOffset)
	    {
	       while (1)
	         {
		   if (InquiryBuffer->PathId == ScsiAddress.PathId &&
		       InquiryBuffer->TargetId == ScsiAddress.TargetId &&
		       InquiryBuffer->Lun == ScsiAddress.Lun)
		     {
		       memcpy(InquiryData, InquiryBuffer->InquiryData, sizeof(INQUIRYDATA));
		       return TRUE;
		     }
		   if (InquiryBuffer->NextInquiryDataOffset == 0)
		     {
		       break;
		     }
		   InquiryBuffer = (PSCSI_INQUIRY_DATA) (Buffer + InquiryBuffer->NextInquiryDataOffset);
		 }
	    }
	}
    }
  return FALSE;
}

int main(void)
{
    HANDLE hDevice;
    OVERLAPPED ov;

    PBYTE Buffer = NULL ;
    DWORD Start;
    DWORD dwReturned;
    DWORD dwReadTotal;
    DWORD Size;
    BOOL Result;
    ULONG Drive;
    CHAR Name[20];

    INQUIRYDATA InquiryData;


    Drive = 0;
    while (1)
      {
        sprintf(Name, "\\\\.\\PHYSICALDRIVE%ld", Drive);
	hDevice = CreateFile(Name,
	                     GENERIC_READ,
			     FILE_SHARE_READ,
			     NULL,
			     OPEN_EXISTING,
			     0,
			     NULL);
	if (hDevice == INVALID_HANDLE_VALUE)
	  {
	    if (Drive > 0)
	      {
	        VirtualFree(Buffer, 512 * 1024, MEM_RELEASE);
	      }
	    else
	      {
	        printf("Cannot open '%s'\n", Name);
	      }
	    break;
	  }
        if (Drive == 0)
	  {
            printf("Transfer Size (kB)           1     2     4     8    16    32    64   128   256\n");
            printf("Transfer Rate (MB/s)\n");
            printf("-------------------------------------------------------------------------------\n");

	    Buffer = VirtualAlloc(NULL, 512 * 1024, MEM_COMMIT, PAGE_READWRITE);
	  }
        Result = GetInquiryData(hDevice, &InquiryData);
        if (Result)
	  {
            printf("%.24s ", InquiryData.VendorId);
	  }
	else
	  {
	    printf("Disk %ld                   ", Drive + 1);
	  }
        Size = 1024;
        memset(&ov, 0, sizeof(OVERLAPPED));
	while (Size <= 256 * 1024)
	  {
	    memset(Buffer, 0, Size);
	    dwReadTotal = 0;

            Start = GetTickCount() + 2000;
	    while (Start > GetTickCount())
	      {
	        Result = ReadFile(hDevice, Buffer, Size, &dwReturned, &ov);
		if (Result)
		  {
		    dwReadTotal += dwReturned;
		    ov.Offset += dwReturned;
		  }
	      }
	    dwReadTotal /= 2048;
            printf("%3ld.%ld ", dwReadTotal / 1024, (dwReadTotal % 1024) * 10 / 1024);
	    Size *= 2;
	  }
        printf("\n");
	CloseHandle(hDevice);
	Drive++;
      }
    printf("\n");


    return 0;
}

