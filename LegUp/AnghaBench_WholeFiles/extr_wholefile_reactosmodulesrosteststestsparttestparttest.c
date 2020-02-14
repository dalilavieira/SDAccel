#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  WCHAR ;
typedef  int /*<<< orphan*/  UNICODE_STRING ;
typedef  int ULONG ;
struct TYPE_11__ {int Signature1; int BytesPerSector; int FATCount; int Media; int SectorsPerCluster; scalar_t__* Unused0; scalar_t__* Unused3; scalar_t__ MasterBootRecordMagic; int /*<<< orphan*/  OEMID; } ;
typedef  TYPE_1__* PVOID ;
typedef  TYPE_1__* PNTFSBootSector ;
typedef  TYPE_1__* PMASTER_BOOT_RECORD ;
typedef  TYPE_1__* PFATBootSector ;
typedef  int /*<<< orphan*/  OBJECT_ATTRIBUTES ;
typedef  int /*<<< orphan*/  NTSTATUS ;
typedef  int /*<<< orphan*/  IO_STATUS_BLOCK ;
typedef  int /*<<< orphan*/  HANDLE ;
typedef  void* BOOL ;

/* Variables and functions */
 scalar_t__ BOOT_RECORD_SIGNATURE ; 
 int /*<<< orphan*/  DiskFormat ; 
 void* FALSE ; 
 int FILE_SHARE_DELETE ; 
 int FILE_SHARE_READ ; 
 int FILE_SHARE_WRITE ; 
 int /*<<< orphan*/  FILE_SYNCHRONOUS_IO_NONALERT ; 
 int GENERIC_READ ; 
 int /*<<< orphan*/  InitializeObjectAttributes (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int MAX_PATH ; 
 int /*<<< orphan*/  NT_SUCCESS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NtClose (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NtOpenFile (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NtReadFile (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  OBJ_CASE_INSENSITIVE ; 
 int RtlCompareMemory (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  RtlInitUnicodeString (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SECTOR_SIZE ; 
 int SYNCHRONIZE ; 
 void* TRUE ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  free (TYPE_1__*) ; 
 TYPE_1__* malloc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  swprintf (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

BOOL CheckAgainstFAT(PFATBootSector Sector)
{
    if (Sector->Signature1 != 0xaa55)
    {
        return FALSE;
    }

    if (Sector->BytesPerSector != 512 &&
        Sector->BytesPerSector != 1024 &&
        Sector->BytesPerSector != 2048 &&
        Sector->BytesPerSector != 4096)
    {
        return FALSE;
    }

    if (Sector->FATCount != 1 &&
        Sector->FATCount != 2)
    {
        return FALSE;
    }

    if (Sector->Media != 0xf0 &&
        Sector->Media != 0xf8 &&
        Sector->Media != 0xf9 &&
        Sector->Media != 0xfa &&
        Sector->Media != 0xfb &&
        Sector->Media != 0xfc &&
        Sector->Media != 0xfd &&
        Sector->Media != 0xfe &&
        Sector->Media != 0xff)
    {
        return FALSE;
    }

    if (Sector->SectorsPerCluster != 1 &&
        Sector->SectorsPerCluster != 2 &&
        Sector->SectorsPerCluster != 4 &&
        Sector->SectorsPerCluster != 8 &&
        Sector->SectorsPerCluster != 16 &&
        Sector->SectorsPerCluster != 32 &&
        Sector->SectorsPerCluster != 64 &&
        Sector->SectorsPerCluster != 128)
    {
        return FALSE;
    }

    if (Sector->BytesPerSector * Sector->SectorsPerCluster > 32 * 1024)
    {
        return FALSE;
    }

    return TRUE;
}

BOOL CheckAgainstNTFS(PNTFSBootSector Sector)
{
    ULONG k;
    ULONG ClusterSize;

    /* OEMID: this field must be NTFS */
    if (RtlCompareMemory(Sector->OEMID, "NTFS    ", 8) != 8)
    {
        return FALSE;
    }

    /* Unused0: this field must be COMPLETELY null */
    for (k = 0; k < 7; k++)
    {
        if (Sector->Unused0[k] != 0)
        {
            return FALSE;
        }
    }

    /* Unused3: this field must be COMPLETELY null */
    for (k = 0; k < 4; k++)
    {
        if (Sector->Unused3[k] != 0)
        {
            return FALSE;
        }
    }

    /* Check cluster size */
    ClusterSize = Sector->BytesPerSector * Sector->SectorsPerCluster;
    if (ClusterSize != 512 && ClusterSize != 1024 && 
        ClusterSize != 2048 && ClusterSize != 4096 &&
        ClusterSize != 8192 && ClusterSize != 16384 &&
        ClusterSize != 32768 && ClusterSize != 65536)
    {
        return FALSE;
    }

    return TRUE;
}

BOOL CheckAgainstMBR(PMASTER_BOOT_RECORD Sector)
{
    if (Sector->MasterBootRecordMagic != BOOT_RECORD_SIGNATURE)
    {
        return FALSE;
    }

    return TRUE;
}

int main(int argc, char ** argv)
{
    HANDLE FileHandle;
    NTSTATUS Status;
    OBJECT_ATTRIBUTES ObjectAttributes;
    IO_STATUS_BLOCK IoStatusBlock;
    WCHAR Buffer[MAX_PATH];
    UNICODE_STRING Name;
    PVOID Sector;

    Sector = malloc(SECTOR_SIZE);
    if (Sector == NULL)
    {
        fprintf(stderr, "Failed allocating memory!\n");
        return 0;
    }

    /* We first open disk */
    swprintf(Buffer, DiskFormat, 0, 0);
    RtlInitUnicodeString(&Name, Buffer);
    InitializeObjectAttributes(&ObjectAttributes,
                               &Name,
                               OBJ_CASE_INSENSITIVE,
                               NULL,
                               NULL);

    Status = NtOpenFile(&FileHandle,
                        GENERIC_READ | SYNCHRONIZE,
                        &ObjectAttributes,
                        &IoStatusBlock,
                        0,
                        FILE_SYNCHRONOUS_IO_NONALERT);
    if (!NT_SUCCESS(Status))
    {
        free(Sector);
        fprintf(stderr, "Failed opening disk! %lx\n", Status);
        return 0;
    }

    /* Read first sector of the disk */
    Status = NtReadFile(FileHandle,
                        NULL,
                        NULL,
                        NULL,
                        &IoStatusBlock,
                        Sector,
                        SECTOR_SIZE,
                        NULL,
                        NULL);
    NtClose(FileHandle);
    if (!NT_SUCCESS(Status))
    {
        free(Sector);
        fprintf(stderr, "Failed reading sector 0! %lx\n", Status);
        return 0;
    }

    /* Is it FAT? */
    if (CheckAgainstFAT(Sector))
    {
        printf("Sector 0 seems to be FAT boot sector\n");
    }
    /* Is it NTFS? */
    else if (CheckAgainstNTFS(Sector))
    {
        printf("Sector 0 seems to be NTFS boot sector\n");
    }
    /* Is it MBR? */
    else if (CheckAgainstMBR(Sector))
    {
        printf("Sector 0 might be MBR\n");
    }
    /* We don't support anything else */
    else
    {
        printf("Sector 0 not recognized\n");
    }

    /* Redo it with first partition */
    swprintf(Buffer, DiskFormat, 0, 1);
    RtlInitUnicodeString(&Name, Buffer);
    InitializeObjectAttributes(&ObjectAttributes,
                               &Name,
                               OBJ_CASE_INSENSITIVE,
                               NULL,
                               NULL);

    Status = NtOpenFile(&FileHandle,
                        GENERIC_READ | SYNCHRONIZE,
                        &ObjectAttributes,
                        &IoStatusBlock,
                        FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
                        FILE_SYNCHRONOUS_IO_NONALERT);
    if (!NT_SUCCESS(Status))
    {
        free(Sector);
        fprintf(stderr, "Failed opening partition! %lx\n", Status);
        return 0;
    }

    /* Read first sector of the partition */
    Status = NtReadFile(FileHandle,
                        NULL,
                        NULL,
                        NULL,
                        &IoStatusBlock,
                        Sector,
                        SECTOR_SIZE,
                        NULL,
                        NULL);
    if (!NT_SUCCESS(Status))
    {
        free(Sector);
        fprintf(stderr, "Failed reading first sector of the partition! %lx\n", Status);
        return 0;
    }

    /* Is it FAT? */
    if (CheckAgainstFAT(Sector))
    {
        printf("Seems to be a FAT partittion\n");
    }
    /* Is it NTFS? */
    else if (CheckAgainstNTFS(Sector))
    {
        printf("Seems to be a NTFS partition\n");
    }
    /* Is it MBR? */
    else if (CheckAgainstMBR(Sector))
    {
        printf("Seems to be MBR\n");
    }
    /* We don't support anything else */
    else
    {
        printf("Not recognized\n");
    }

    free(Sector);

    return 0;
}

