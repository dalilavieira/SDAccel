#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int ULONG ;
struct TYPE_8__ {scalar_t__ Characteristics; int /*<<< orphan*/  DeviceType; } ;
struct TYPE_6__ {scalar_t__ QuadPart; } ;
struct TYPE_5__ {scalar_t__ QuadPart; } ;
struct TYPE_7__ {int NumberOfLinks; void* Directory; void* DeletePending; TYPE_2__ EndOfFile; TYPE_1__ AllocationSize; } ;
typedef  int SIZE_T ;
typedef  int /*<<< orphan*/ * PVOID ;
typedef  int PUCHAR ;
typedef  int* PSIZE_T ;
typedef  TYPE_3__* PFILE_STANDARD_INFORMATION ;
typedef  TYPE_4__* PFILE_FS_DEVICE_INFORMATION ;
typedef  int /*<<< orphan*/  NTSTATUS ;
typedef  scalar_t__ FS_INFORMATION_CLASS ;
typedef  int /*<<< orphan*/  FILE_STANDARD_INFORMATION ;
typedef  scalar_t__ FILE_INFORMATION_CLASS ;
typedef  int /*<<< orphan*/  FILE_FS_DEVICE_INFORMATION ;

/* Variables and functions */
 int /*<<< orphan*/  DPRINT1 (char*,int) ; 
 void* FALSE ; 
 int /*<<< orphan*/  FILE_DEVICE_NULL ; 
 scalar_t__ FileFsDeviceInformation ; 
 scalar_t__ FileStandardInformation ; 
#define  IOCTL_KSEC_DECRYPT_CROSS_PROCESS 135 
#define  IOCTL_KSEC_DECRYPT_SAME_LOGON 134 
#define  IOCTL_KSEC_DECRYPT_SAME_PROCESS 133 
#define  IOCTL_KSEC_ENCRYPT_CROSS_PROCESS 132 
#define  IOCTL_KSEC_ENCRYPT_SAME_LOGON 131 
#define  IOCTL_KSEC_ENCRYPT_SAME_PROCESS 130 
#define  IOCTL_KSEC_RANDOM_FILL_BUFFER 129 
#define  IOCTL_KSEC_REGISTER_LSA_PROCESS 128 
 int /*<<< orphan*/  KsecDecryptMemory (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  KsecEncryptMemory (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  KsecGenRandom (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  RTL_ENCRYPT_OPTION_CROSS_PROCESS ; 
 int /*<<< orphan*/  RTL_ENCRYPT_OPTION_SAME_LOGON ; 
 int /*<<< orphan*/  RTL_ENCRYPT_OPTION_SAME_PROCESS ; 
 int /*<<< orphan*/  RtlSecureZeroMemory (int,int) ; 
 int /*<<< orphan*/  STATUS_INFO_LENGTH_MISMATCH ; 
 int /*<<< orphan*/  STATUS_INVALID_INFO_CLASS ; 
 int /*<<< orphan*/  STATUS_INVALID_PARAMETER ; 
 int /*<<< orphan*/  STATUS_SUCCESS ; 
 int /*<<< orphan*/  __debugbreak () ; 

__attribute__((used)) static
NTSTATUS
KsecQueryFileInformation(
    PVOID InfoBuffer,
    FILE_INFORMATION_CLASS FileInformationClass,
    PSIZE_T BufferLength)
{
    PFILE_STANDARD_INFORMATION StandardInformation;

    /* Only FileStandardInformation is supported */
    if (FileInformationClass != FileStandardInformation)
    {
        return STATUS_INVALID_INFO_CLASS;
    }

    /* Validate buffer size */
    if (*BufferLength < sizeof(FILE_STANDARD_INFORMATION))
    {
        *BufferLength = sizeof(FILE_STANDARD_INFORMATION);
        return STATUS_INFO_LENGTH_MISMATCH;
    }

    /* Fill the structure */
    StandardInformation = (PFILE_STANDARD_INFORMATION)InfoBuffer;
    StandardInformation->AllocationSize.QuadPart = 0;
    StandardInformation->EndOfFile.QuadPart = 0;
    StandardInformation->NumberOfLinks = 1;
    StandardInformation->DeletePending = FALSE;
    StandardInformation->Directory = FALSE;
    *BufferLength = sizeof(FILE_STANDARD_INFORMATION);

    return STATUS_SUCCESS;
}

__attribute__((used)) static
NTSTATUS
KsecQueryVolumeInformation(
    PVOID InfoBuffer,
    FS_INFORMATION_CLASS FsInformationClass,
    PSIZE_T BufferLength)
{
    PFILE_FS_DEVICE_INFORMATION DeviceInformation;

    /* Only FileFsDeviceInformation is supported */
    if (FsInformationClass != FileFsDeviceInformation)
    {
        return STATUS_INVALID_INFO_CLASS;
    }

    /* Validate buffer size */
    if (*BufferLength < sizeof(FILE_FS_DEVICE_INFORMATION))
    {
        *BufferLength = sizeof(FILE_FS_DEVICE_INFORMATION);
        return STATUS_INFO_LENGTH_MISMATCH;
    }

    /* Fill the structure */
    DeviceInformation = (PFILE_FS_DEVICE_INFORMATION)InfoBuffer;
    DeviceInformation->DeviceType = FILE_DEVICE_NULL;
    DeviceInformation->Characteristics = 0;
    *BufferLength = sizeof(FILE_FS_DEVICE_INFORMATION);

    return STATUS_SUCCESS;
}

__attribute__((used)) static
NTSTATUS
KsecDeviceControl(
    ULONG IoControlCode,
    PVOID Buffer,
    SIZE_T InputLength,
    PSIZE_T OutputLength)
{
    NTSTATUS Status;

    if ((IoControlCode == IOCTL_KSEC_RANDOM_FILL_BUFFER) ||
        (IoControlCode == IOCTL_KSEC_ENCRYPT_SAME_PROCESS) ||
        (IoControlCode == IOCTL_KSEC_DECRYPT_SAME_PROCESS) ||
        (IoControlCode == IOCTL_KSEC_ENCRYPT_CROSS_PROCESS) ||
        (IoControlCode == IOCTL_KSEC_DECRYPT_CROSS_PROCESS) ||
        (IoControlCode == IOCTL_KSEC_ENCRYPT_SAME_LOGON) ||
        (IoControlCode == IOCTL_KSEC_DECRYPT_SAME_LOGON))
    {
        /* Make sure we have a valid output buffer */
        if ((Buffer == NULL) || (OutputLength == NULL))
        {
            return STATUS_INVALID_PARAMETER;
        }

        /* Check if the input is smaller than the output */
        if (InputLength < *OutputLength)
        {
            /* We might have uninitialized memory, zero it out */
            RtlSecureZeroMemory((PUCHAR)Buffer + InputLength,
                                *OutputLength - InputLength);
        }
    }

    /* Check ioctl code */
    switch (IoControlCode)
    {
        case IOCTL_KSEC_REGISTER_LSA_PROCESS:

            Status = STATUS_SUCCESS;
            break;

        case IOCTL_KSEC_RANDOM_FILL_BUFFER:

            Status = KsecGenRandom(Buffer, *OutputLength);
            break;

        case IOCTL_KSEC_ENCRYPT_SAME_PROCESS:

            Status = KsecEncryptMemory(Buffer,
                                       *OutputLength,
                                       RTL_ENCRYPT_OPTION_SAME_PROCESS);
            break;

        case IOCTL_KSEC_DECRYPT_SAME_PROCESS:

            Status = KsecDecryptMemory(Buffer,
                                       *OutputLength,
                                       RTL_ENCRYPT_OPTION_SAME_PROCESS);
            break;

        case IOCTL_KSEC_ENCRYPT_CROSS_PROCESS:

            Status = KsecEncryptMemory(Buffer,
                                       *OutputLength,
                                       RTL_ENCRYPT_OPTION_CROSS_PROCESS);
            break;

        case IOCTL_KSEC_DECRYPT_CROSS_PROCESS:

            Status = KsecDecryptMemory(Buffer,
                                       *OutputLength,
                                       RTL_ENCRYPT_OPTION_CROSS_PROCESS);
            break;

        case IOCTL_KSEC_ENCRYPT_SAME_LOGON:

            Status = KsecEncryptMemory(Buffer,
                                       *OutputLength,
                                       RTL_ENCRYPT_OPTION_SAME_LOGON);
            break;

        case IOCTL_KSEC_DECRYPT_SAME_LOGON:

            Status = KsecDecryptMemory(Buffer,
                                       *OutputLength,
                                       RTL_ENCRYPT_OPTION_SAME_LOGON);
            break;

        default:
            DPRINT1("Unhandled control code 0x%lx\n", IoControlCode);
            __debugbreak();
            return STATUS_INVALID_PARAMETER;
    }

    return Status;
}

