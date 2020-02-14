#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_82__   TYPE_9__ ;
typedef  struct TYPE_81__   TYPE_8__ ;
typedef  struct TYPE_80__   TYPE_7__ ;
typedef  struct TYPE_79__   TYPE_6__ ;
typedef  struct TYPE_78__   TYPE_5__ ;
typedef  struct TYPE_77__   TYPE_50__ ;
typedef  struct TYPE_76__   TYPE_4__ ;
typedef  struct TYPE_75__   TYPE_3__ ;
typedef  struct TYPE_74__   TYPE_2__ ;
typedef  struct TYPE_73__   TYPE_29__ ;
typedef  struct TYPE_72__   TYPE_25__ ;
typedef  struct TYPE_71__   TYPE_23__ ;
typedef  struct TYPE_70__   TYPE_21__ ;
typedef  struct TYPE_69__   TYPE_20__ ;
typedef  struct TYPE_68__   TYPE_1__ ;
typedef  struct TYPE_67__   TYPE_19__ ;
typedef  struct TYPE_66__   TYPE_18__ ;
typedef  struct TYPE_65__   TYPE_17__ ;
typedef  struct TYPE_64__   TYPE_13__ ;
typedef  struct TYPE_63__   TYPE_12__ ;
typedef  struct TYPE_62__   TYPE_11__ ;
typedef  struct TYPE_61__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  WCHAR ;
struct TYPE_63__ {int Length; int MaximumLength; void* Buffer; } ;
typedef  TYPE_12__ UNICODE_STRING ;
typedef  scalar_t__ ULONG_PTR ;
typedef  scalar_t__ ULONGLONG ;
typedef  scalar_t__ ULONG ;
struct TYPE_81__ {scalar_t__ QuadPart; } ;
struct TYPE_82__ {TYPE_8__ FileSize; } ;
struct TYPE_80__ {scalar_t__ LowPart; int HighPart; } ;
struct TYPE_72__ {scalar_t__ QuadPart; scalar_t__ LowPart; TYPE_7__ u; } ;
struct TYPE_78__ {scalar_t__ Length; TYPE_25__ ByteOffset; } ;
struct TYPE_74__ {scalar_t__ Length; TYPE_25__ ByteOffset; } ;
struct TYPE_79__ {TYPE_5__ Write; TYPE_2__ Read; } ;
struct TYPE_77__ {scalar_t__ DeviceObject; } ;
struct TYPE_76__ {scalar_t__ SectorSize; } ;
struct TYPE_75__ {int /*<<< orphan*/  MinorVersion; int /*<<< orphan*/  MajorVersion; } ;
struct TYPE_73__ {TYPE_3__ NtfsInfo; } ;
struct TYPE_71__ {TYPE_13__* DeviceExtension; } ;
struct TYPE_61__ {scalar_t__ QuadPart; } ;
struct TYPE_70__ {int Flags; TYPE_10__ CurrentByteOffset; scalar_t__ FsContext; } ;
struct TYPE_69__ {int Flags; TYPE_6__ Parameters; } ;
struct TYPE_68__ {scalar_t__ BytesPerSector; } ;
struct TYPE_62__ {scalar_t__ Information; int /*<<< orphan*/  Status; } ;
struct TYPE_67__ {int Flags; TYPE_11__ IoStatus; int /*<<< orphan*/ * MdlAddress; int /*<<< orphan*/ * UserBuffer; } ;
struct TYPE_66__ {int /*<<< orphan*/  pRecord; } ;
struct TYPE_65__ {scalar_t__ Type; int NameLength; scalar_t__ NameOffset; } ;
struct TYPE_64__ {scalar_t__ Stream; scalar_t__ PathName; scalar_t__ ObjectName; int Flags; scalar_t__ DirectoryFileReferenceNumber; int NameLength; scalar_t__ DeviceObject; int /*<<< orphan*/  PriorityBoost; TYPE_19__* Irp; TYPE_20__* Stack; TYPE_9__ RFCB; int /*<<< orphan*/  MainResource; int /*<<< orphan*/  PagingIoResource; int /*<<< orphan*/  DirResource; TYPE_21__* FileObject; TYPE_4__* StorageDevice; TYPE_29__* Vcb; int /*<<< orphan*/  FileRecLookasideList; void* Name; int /*<<< orphan*/  MFTIndex; TYPE_1__ NtfsInfo; } ;
typedef  void* PWCHAR ;
typedef  TYPE_13__* PVOID ;
typedef  scalar_t__* PULONG ;
typedef  TYPE_13__* PUCHAR ;
typedef  TYPE_13__* PNTFS_IRP_CONTEXT ;
typedef  TYPE_13__* PNTFS_FCB ;
typedef  TYPE_17__* PNTFS_ATTR_RECORD ;
typedef  TYPE_18__* PNTFS_ATTR_CONTEXT ;
typedef  TYPE_19__* PIRP ;
typedef  TYPE_20__* PIO_STACK_LOCATION ;
typedef  int /*<<< orphan*/ * PFILE_RECORD_HEADER ;
typedef  TYPE_21__* PFILE_OBJECT ;
typedef  TYPE_13__* PFILENAME_ATTRIBUTE ;
typedef  int /*<<< orphan*/ * PERESOURCE ;
typedef  TYPE_23__* PDEVICE_OBJECT ;
typedef  TYPE_13__* PDEVICE_EXTENSION ;
typedef  int /*<<< orphan*/ * PCHAR ;
typedef  int /*<<< orphan*/  NTSTATUS ;
typedef  TYPE_25__ LARGE_INTEGER ;
typedef  int /*<<< orphan*/  FIND_ATTR_CONTXT ;
typedef  scalar_t__ BOOLEAN ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (TYPE_13__*) ; 
 scalar_t__ AttributeAllocatedLength (int /*<<< orphan*/ ) ; 
 scalar_t__ AttributeData ; 
 scalar_t__ AttributeDataLength (int /*<<< orphan*/ ) ; 
 scalar_t__ BooleanFlagOn (int,scalar_t__) ; 
 int /*<<< orphan*/  DPRINT (char*,...) ; 
 int /*<<< orphan*/  DPRINT1 (char*,...) ; 
 int /*<<< orphan*/  ExAcquireResourceExclusiveLite (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/ * ExAllocateFromNPagedLookasideList (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * ExAllocatePoolWithTag (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ExFreePoolWithTag (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ExFreeToNPagedLookasideList (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ExReleaseResourceLite (int /*<<< orphan*/ *) ; 
 scalar_t__ FALSE ; 
 int FCB_IS_VOLUME ; 
 int FILE_NO_INTERMEDIATE_BUFFERING ; 
 scalar_t__ FILE_WRITE_TO_END_OF_FILE ; 
 int FO_SYNCHRONOUS_IO ; 
 int /*<<< orphan*/  FindAttribute (TYPE_13__*,int /*<<< orphan*/ *,scalar_t__,scalar_t__,int /*<<< orphan*/ ,TYPE_18__**,scalar_t__*) ; 
 int /*<<< orphan*/  FindCloseAttribute (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FindFirstAttribute (int /*<<< orphan*/ *,TYPE_13__*,int /*<<< orphan*/ *,scalar_t__,TYPE_17__**) ; 
 int /*<<< orphan*/  FindNextAttribute (int /*<<< orphan*/ *,TYPE_17__**) ; 
 TYPE_13__* GetBestFileNameFromRecord (TYPE_29__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  IO_DISK_INCREMENT ; 
 scalar_t__ IRPCONTEXT_CANWAIT ; 
 scalar_t__ IRP_NOCACHE ; 
 scalar_t__ IRP_PAGING_IO ; 
 int /*<<< orphan*/  IoReadAccess ; 
 scalar_t__ NTFS_MFT_MASK ; 
 scalar_t__ NT_SUCCESS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NonPagedPool ; 
 scalar_t__ NtfsFCBIsCompressed (TYPE_13__*) ; 
 void* NtfsGetUserBuffer (TYPE_19__*,scalar_t__) ; 
 TYPE_50__* NtfsGlobalData ; 
 int /*<<< orphan*/  NtfsLockUserBuffer (TYPE_19__*,scalar_t__,int /*<<< orphan*/ ) ; 
 scalar_t__ ROUND_DOWN (scalar_t__,scalar_t__) ; 
 scalar_t__ ROUND_UP (scalar_t__,scalar_t__) ; 
 scalar_t__ ReadAttribute (TYPE_13__*,TYPE_18__*,scalar_t__,int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  ReadFileRecord (TYPE_13__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ReleaseAttributeContext (TYPE_18__*) ; 
 int /*<<< orphan*/  RtlCopyMemory (TYPE_13__*,int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  RtlZeroMemory (TYPE_13__*,scalar_t__) ; 
 scalar_t__ SL_CASE_SENSITIVE ; 
 int /*<<< orphan*/  STATUS_ACCESS_DENIED ; 
 int /*<<< orphan*/  STATUS_CANT_WAIT ; 
 int /*<<< orphan*/  STATUS_END_OF_FILE ; 
 int /*<<< orphan*/  STATUS_INSUFFICIENT_RESOURCES ; 
 int /*<<< orphan*/  STATUS_INVALID_DEVICE_REQUEST ; 
 int /*<<< orphan*/  STATUS_INVALID_PARAMETER ; 
 int /*<<< orphan*/  STATUS_NOT_IMPLEMENTED ; 
 int /*<<< orphan*/  STATUS_SUCCESS ; 
 int /*<<< orphan*/  STATUS_UNEXPECTED_IO_ERROR ; 
 int /*<<< orphan*/  SetAttributeDataLength (TYPE_21__*,TYPE_13__*,TYPE_18__*,scalar_t__,int /*<<< orphan*/ *,TYPE_25__*) ; 
 int /*<<< orphan*/  TAG_NTFS ; 
 scalar_t__ TRUE ; 
 int /*<<< orphan*/  UNIMPLEMENTED ; 
 int /*<<< orphan*/  UpdateFileNameRecord (TYPE_29__*,scalar_t__,TYPE_12__*,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  WriteAttribute (TYPE_13__*,TYPE_18__*,scalar_t__,TYPE_13__* const,scalar_t__,scalar_t__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wcslen (scalar_t__) ; 

__attribute__((used)) static
NTSTATUS
NtfsReadFile(PDEVICE_EXTENSION DeviceExt,
             PFILE_OBJECT FileObject,
             PUCHAR Buffer,
             ULONG Length,
             ULONG ReadOffset,
             ULONG IrpFlags,
             PULONG LengthRead)
{
    NTSTATUS Status = STATUS_SUCCESS;
    PNTFS_FCB Fcb;
    PFILE_RECORD_HEADER FileRecord;
    PNTFS_ATTR_CONTEXT DataContext;
    ULONG RealLength;
    ULONG RealReadOffset;
    ULONG RealLengthRead;
    ULONG ToRead;
    BOOLEAN AllocatedBuffer = FALSE;
    PCHAR ReadBuffer = (PCHAR)Buffer;
    ULONGLONG StreamSize;

    DPRINT1("NtfsReadFile(%p, %p, %p, %lu, %lu, %lx, %p)\n", DeviceExt, FileObject, Buffer, Length, ReadOffset, IrpFlags, LengthRead);

    *LengthRead = 0;

    if (Length == 0)
    {
        DPRINT1("Null read!\n");
        return STATUS_SUCCESS;
    }

    Fcb = (PNTFS_FCB)FileObject->FsContext;

    if (NtfsFCBIsCompressed(Fcb))
    {
        DPRINT1("Compressed file!\n");
        UNIMPLEMENTED;
        return STATUS_NOT_IMPLEMENTED;
    }

    FileRecord = ExAllocateFromNPagedLookasideList(&DeviceExt->FileRecLookasideList);
    if (FileRecord == NULL)
    {
        DPRINT1("Not enough memory!\n");
        return STATUS_INSUFFICIENT_RESOURCES;
    }

    Status = ReadFileRecord(DeviceExt, Fcb->MFTIndex, FileRecord);
    if (!NT_SUCCESS(Status))
    {
        DPRINT1("Can't find record!\n");
        ExFreeToNPagedLookasideList(&DeviceExt->FileRecLookasideList, FileRecord);
        return Status;
    }


    Status = FindAttribute(DeviceExt, FileRecord, AttributeData, Fcb->Stream, wcslen(Fcb->Stream), &DataContext, NULL);
    if (!NT_SUCCESS(Status))
    {
        NTSTATUS BrowseStatus;
        FIND_ATTR_CONTXT Context;
        PNTFS_ATTR_RECORD Attribute;

        DPRINT1("No '%S' data stream associated with file!\n", Fcb->Stream);

        BrowseStatus = FindFirstAttribute(&Context, DeviceExt, FileRecord, FALSE, &Attribute);
        while (NT_SUCCESS(BrowseStatus))
        {
            if (Attribute->Type == AttributeData)
            {
                UNICODE_STRING Name;

                Name.Length = Attribute->NameLength * sizeof(WCHAR);
                Name.MaximumLength = Name.Length;
                Name.Buffer = (PWCHAR)((ULONG_PTR)Attribute + Attribute->NameOffset);
                DPRINT1("Data stream: '%wZ' available\n", &Name);
            }

            BrowseStatus = FindNextAttribute(&Context, &Attribute);
        }
        FindCloseAttribute(&Context);

        ReleaseAttributeContext(DataContext);
        ExFreeToNPagedLookasideList(&DeviceExt->FileRecLookasideList, FileRecord);
        return Status;
    }

    StreamSize = AttributeDataLength(DataContext->pRecord);
    if (ReadOffset >= StreamSize)
    {
        DPRINT1("Reading beyond stream end!\n");
        ReleaseAttributeContext(DataContext);
        ExFreeToNPagedLookasideList(&DeviceExt->FileRecLookasideList, FileRecord);
        return STATUS_END_OF_FILE;
    }

    ToRead = Length;
    if (ReadOffset + Length > StreamSize)
        ToRead = StreamSize - ReadOffset;

    RealReadOffset = ReadOffset;
    RealLength = ToRead;

    if ((ReadOffset % DeviceExt->NtfsInfo.BytesPerSector) != 0 || (ToRead % DeviceExt->NtfsInfo.BytesPerSector) != 0)
    {
        RealReadOffset = ROUND_DOWN(ReadOffset, DeviceExt->NtfsInfo.BytesPerSector);
        RealLength = ROUND_UP(ToRead, DeviceExt->NtfsInfo.BytesPerSector);
        /* do we need to extend RealLength by one sector? */
        if (RealLength + RealReadOffset < ReadOffset + Length)
        {
            if (RealReadOffset + RealLength + DeviceExt->NtfsInfo.BytesPerSector <= AttributeAllocatedLength(DataContext->pRecord))
                RealLength += DeviceExt->NtfsInfo.BytesPerSector;
        }


        ReadBuffer = ExAllocatePoolWithTag(NonPagedPool, RealLength, TAG_NTFS);
        if (ReadBuffer == NULL)
        {
            DPRINT1("Not enough memory!\n");
            ReleaseAttributeContext(DataContext);
            ExFreeToNPagedLookasideList(&DeviceExt->FileRecLookasideList, FileRecord);
            return STATUS_INSUFFICIENT_RESOURCES;
        }
        AllocatedBuffer = TRUE;
    }

    DPRINT("Effective read: %lu at %lu for stream '%S'\n", RealLength, RealReadOffset, Fcb->Stream);
    RealLengthRead = ReadAttribute(DeviceExt, DataContext, RealReadOffset, (PCHAR)ReadBuffer, RealLength);
    if (RealLengthRead == 0)
    {
        DPRINT1("Read failure!\n");
        ReleaseAttributeContext(DataContext);
        ExFreeToNPagedLookasideList(&DeviceExt->FileRecLookasideList, FileRecord);
        if (AllocatedBuffer)
        {
            ExFreePoolWithTag(ReadBuffer, TAG_NTFS);
        }
        return Status;
    }

    ReleaseAttributeContext(DataContext);
    ExFreeToNPagedLookasideList(&DeviceExt->FileRecLookasideList, FileRecord);

    *LengthRead = ToRead;

    DPRINT("%lu got read\n", *LengthRead);

    if (AllocatedBuffer)
    {
        RtlCopyMemory(Buffer, ReadBuffer + (ReadOffset - RealReadOffset), ToRead);
    }

    if (ToRead != Length)
    {
        RtlZeroMemory(Buffer + ToRead, Length - ToRead);
    }

    if (AllocatedBuffer)
    {
        ExFreePoolWithTag(ReadBuffer, TAG_NTFS);
    }

    return STATUS_SUCCESS;
}

NTSTATUS
NtfsRead(PNTFS_IRP_CONTEXT IrpContext)
{
    PDEVICE_EXTENSION DeviceExt;
    PIO_STACK_LOCATION Stack;
    PFILE_OBJECT FileObject;
    PVOID Buffer;
    ULONG ReadLength;
    LARGE_INTEGER ReadOffset;
    ULONG ReturnedReadLength = 0;
    NTSTATUS Status = STATUS_SUCCESS;
    PIRP Irp;
    PDEVICE_OBJECT DeviceObject;

    DPRINT("NtfsRead(IrpContext %p)\n", IrpContext);

    DeviceObject = IrpContext->DeviceObject;
    Irp = IrpContext->Irp;
    Stack = IrpContext->Stack;
    FileObject = IrpContext->FileObject;

    DeviceExt = DeviceObject->DeviceExtension;
    ReadLength = Stack->Parameters.Read.Length;
    ReadOffset = Stack->Parameters.Read.ByteOffset;
    Buffer = NtfsGetUserBuffer(Irp, BooleanFlagOn(Irp->Flags, IRP_PAGING_IO));

    Status = NtfsReadFile(DeviceExt,
                          FileObject,
                          Buffer,
                          ReadLength,
                          ReadOffset.u.LowPart,
                          Irp->Flags,
                          &ReturnedReadLength);
    if (NT_SUCCESS(Status))
    {
        if (FileObject->Flags & FO_SYNCHRONOUS_IO)
        {
            FileObject->CurrentByteOffset.QuadPart =
                ReadOffset.QuadPart + ReturnedReadLength;
        }

        Irp->IoStatus.Information = ReturnedReadLength;
    }
    else
    {
        Irp->IoStatus.Information = 0;
    }

    return Status;
}

NTSTATUS NtfsWriteFile(PDEVICE_EXTENSION DeviceExt,
                       PFILE_OBJECT FileObject,
                       const PUCHAR Buffer,
                       ULONG Length,
                       ULONG WriteOffset,
                       ULONG IrpFlags,
                       BOOLEAN CaseSensitive,
                       PULONG LengthWritten)
{
    NTSTATUS Status = STATUS_NOT_IMPLEMENTED;
    PNTFS_FCB Fcb;
    PFILE_RECORD_HEADER FileRecord;
    PNTFS_ATTR_CONTEXT DataContext;
    ULONG AttributeOffset;
    ULONGLONG StreamSize;

    DPRINT("NtfsWriteFile(%p, %p, %p, %lu, %lu, %x, %s, %p)\n",
           DeviceExt,
           FileObject,
           Buffer,
           Length,
           WriteOffset,
           IrpFlags,
           (CaseSensitive ? "TRUE" : "FALSE"),
           LengthWritten);

    *LengthWritten = 0;

    ASSERT(DeviceExt);

    if (Length == 0)
    {
        if (Buffer == NULL)
            return STATUS_SUCCESS;
        else
            return STATUS_INVALID_PARAMETER;
    }

    // get the File control block
    Fcb = (PNTFS_FCB)FileObject->FsContext;
    ASSERT(Fcb);

    DPRINT("Fcb->PathName: %wS\n", Fcb->PathName);
    DPRINT("Fcb->ObjectName: %wS\n", Fcb->ObjectName);

    // we don't yet handle compression
    if (NtfsFCBIsCompressed(Fcb))
    {
        DPRINT("Compressed file!\n");
        UNIMPLEMENTED;
        return STATUS_NOT_IMPLEMENTED;
    }

    // allocate non-paged memory for the FILE_RECORD_HEADER
    FileRecord = ExAllocateFromNPagedLookasideList(&DeviceExt->FileRecLookasideList);
    if (FileRecord == NULL)
    {
        DPRINT1("Not enough memory! Can't write %wS!\n", Fcb->PathName);
        return STATUS_INSUFFICIENT_RESOURCES;
    }

    // read the FILE_RECORD_HEADER from the drive (or cache)
    DPRINT("Reading file record...\n");
    Status = ReadFileRecord(DeviceExt, Fcb->MFTIndex, FileRecord);
    if (!NT_SUCCESS(Status))
    {
        // We couldn't get the file's record. Free the memory and return the error
        DPRINT1("Can't find record for %wS!\n", Fcb->ObjectName);
        ExFreeToNPagedLookasideList(&DeviceExt->FileRecLookasideList, FileRecord);
        return Status;
    }

    DPRINT("Found record for %wS\n", Fcb->ObjectName);

    // Find the attribute with the data stream for our file
    DPRINT("Finding Data Attribute...\n");
    Status = FindAttribute(DeviceExt, FileRecord, AttributeData, Fcb->Stream, wcslen(Fcb->Stream), &DataContext,
                           &AttributeOffset);

    // Did we fail to find the attribute?
    if (!NT_SUCCESS(Status))
    {
        NTSTATUS BrowseStatus;
        FIND_ATTR_CONTXT Context;
        PNTFS_ATTR_RECORD Attribute;

        DPRINT1("No '%S' data stream associated with file!\n", Fcb->Stream);

        // Couldn't find the requested data stream; print a list of streams available
        BrowseStatus = FindFirstAttribute(&Context, DeviceExt, FileRecord, FALSE, &Attribute);
        while (NT_SUCCESS(BrowseStatus))
        {
            if (Attribute->Type == AttributeData)
            {
                UNICODE_STRING Name;

                Name.Length = Attribute->NameLength * sizeof(WCHAR);
                Name.MaximumLength = Name.Length;
                Name.Buffer = (PWCHAR)((ULONG_PTR)Attribute + Attribute->NameOffset);
                DPRINT1("Data stream: '%wZ' available\n", &Name);
            }

            BrowseStatus = FindNextAttribute(&Context, &Attribute);
        }
        FindCloseAttribute(&Context);

        ReleaseAttributeContext(DataContext);
        ExFreeToNPagedLookasideList(&DeviceExt->FileRecLookasideList, FileRecord);
        return Status;
    }

    // Get the size of the stream on disk
    StreamSize = AttributeDataLength(DataContext->pRecord);

    DPRINT("WriteOffset: %lu\tStreamSize: %I64u\n", WriteOffset, StreamSize);

    // Are we trying to write beyond the end of the stream?
    if (WriteOffset + Length > StreamSize)
    {
        // is increasing the stream size allowed?
        if (!(Fcb->Flags & FCB_IS_VOLUME) &&
            !(IrpFlags & IRP_PAGING_IO))
        {
            LARGE_INTEGER DataSize;
            ULONGLONG AllocationSize;
            PFILENAME_ATTRIBUTE fileNameAttribute;
            ULONGLONG ParentMFTId;
            UNICODE_STRING filename;

            DataSize.QuadPart = WriteOffset + Length;

            // set the attribute data length
            Status = SetAttributeDataLength(FileObject, Fcb, DataContext, AttributeOffset, FileRecord, &DataSize);
            if (!NT_SUCCESS(Status))
            {
                ReleaseAttributeContext(DataContext);
                ExFreeToNPagedLookasideList(&DeviceExt->FileRecLookasideList, FileRecord);
                *LengthWritten = 0;
                return Status;
            }

            AllocationSize = AttributeAllocatedLength(DataContext->pRecord);

            // now we need to update this file's size in every directory index entry that references it
            // TODO: put this code in its own function and adapt it to work with every filename / hardlink
            // stored in the file record.
            fileNameAttribute = GetBestFileNameFromRecord(Fcb->Vcb, FileRecord);
            ASSERT(fileNameAttribute);

            ParentMFTId = fileNameAttribute->DirectoryFileReferenceNumber & NTFS_MFT_MASK;

            filename.Buffer = fileNameAttribute->Name;
            filename.Length = fileNameAttribute->NameLength * sizeof(WCHAR);
            filename.MaximumLength = filename.Length;

            Status = UpdateFileNameRecord(Fcb->Vcb,
                                          ParentMFTId,
                                          &filename,
                                          FALSE,
                                          DataSize.QuadPart,
                                          AllocationSize,
                                          CaseSensitive);

        }
        else
        {
            // TODO - just fail for now
            ReleaseAttributeContext(DataContext);
            ExFreeToNPagedLookasideList(&DeviceExt->FileRecLookasideList, FileRecord);
            *LengthWritten = 0;
            return STATUS_ACCESS_DENIED;
        }
    }

    DPRINT("Length: %lu\tWriteOffset: %lu\tStreamSize: %I64u\n", Length, WriteOffset, StreamSize);

    // Write the data to the attribute
    Status = WriteAttribute(DeviceExt, DataContext, WriteOffset, Buffer, Length, LengthWritten, FileRecord);

    // Did the write fail?
    if (!NT_SUCCESS(Status))
    {
        DPRINT1("Write failure!\n");
        ReleaseAttributeContext(DataContext);
        ExFreeToNPagedLookasideList(&DeviceExt->FileRecLookasideList, FileRecord);

        return Status;
    }

    // This should never happen:
    if (*LengthWritten != Length)
    {
        DPRINT1("\a\tNTFS DRIVER ERROR: length written (%lu) differs from requested (%lu), but no error was indicated!\n",
            *LengthWritten, Length);
        Status = STATUS_UNEXPECTED_IO_ERROR;
    }

    ReleaseAttributeContext(DataContext);
    ExFreeToNPagedLookasideList(&DeviceExt->FileRecLookasideList, FileRecord);

    return Status;
}

NTSTATUS
NtfsWrite(PNTFS_IRP_CONTEXT IrpContext)
{
    PNTFS_FCB Fcb;
    PERESOURCE Resource = NULL;
    LARGE_INTEGER ByteOffset;
    PUCHAR Buffer;
    NTSTATUS Status = STATUS_SUCCESS;
    ULONG Length = 0;
    ULONG ReturnedWriteLength = 0;
    PDEVICE_OBJECT DeviceObject = NULL;
    PDEVICE_EXTENSION DeviceExt = NULL;
    PFILE_OBJECT FileObject = NULL;
    PIRP Irp = NULL;
    ULONG BytesPerSector;

    DPRINT("NtfsWrite(IrpContext %p)\n", IrpContext);
    ASSERT(IrpContext);

    // get the I/O request packet
    Irp = IrpContext->Irp;

    // This request is not allowed on the main device object
    if (IrpContext->DeviceObject == NtfsGlobalData->DeviceObject)
    {
        DPRINT1("\t\t\t\tNtfsWrite is called with the main device object.\n");

        Irp->IoStatus.Information = 0;
        return STATUS_INVALID_DEVICE_REQUEST;
    }

    // get the File control block
    Fcb = (PNTFS_FCB)IrpContext->FileObject->FsContext;
    ASSERT(Fcb);

    DPRINT("About to write %wS\n", Fcb->ObjectName);
    DPRINT("NTFS Version: %d.%d\n", Fcb->Vcb->NtfsInfo.MajorVersion, Fcb->Vcb->NtfsInfo.MinorVersion);

    // setup some more locals
    FileObject = IrpContext->FileObject;
    DeviceObject = IrpContext->DeviceObject;
    DeviceExt = DeviceObject->DeviceExtension;
    BytesPerSector = DeviceExt->StorageDevice->SectorSize;
    Length = IrpContext->Stack->Parameters.Write.Length;

    // get the file offset we'll be writing to
    ByteOffset = IrpContext->Stack->Parameters.Write.ByteOffset;
    if (ByteOffset.u.LowPart == FILE_WRITE_TO_END_OF_FILE &&
        ByteOffset.u.HighPart == -1)
    {
        ByteOffset.QuadPart = Fcb->RFCB.FileSize.QuadPart;
    }

    DPRINT("ByteOffset: %I64u\tLength: %lu\tBytes per sector: %lu\n", ByteOffset.QuadPart,
        Length, BytesPerSector);

    if (ByteOffset.u.HighPart && !(Fcb->Flags & FCB_IS_VOLUME))
    {
        // TODO: Support large files
        DPRINT1("FIXME: Writing to large files is not yet supported at this time.\n");
        return STATUS_INVALID_PARAMETER;
    }

    // Is this a non-cached write? A non-buffered write?
    if (IrpContext->Irp->Flags & (IRP_PAGING_IO | IRP_NOCACHE) || (Fcb->Flags & FCB_IS_VOLUME) ||
        IrpContext->FileObject->Flags & FILE_NO_INTERMEDIATE_BUFFERING)
    {
        // non-cached and non-buffered writes must be sector aligned
        if (ByteOffset.u.LowPart % BytesPerSector != 0 || Length % BytesPerSector != 0)
        {
            DPRINT1("Non-cached writes and non-buffered writes must be sector aligned!\n");
            return STATUS_INVALID_PARAMETER;
        }
    }

    if (Length == 0)
    {
        DPRINT1("Null write!\n");

        IrpContext->Irp->IoStatus.Information = 0;

        // FIXME: Doesn't accurately detect when a user passes NULL to WriteFile() for the buffer
        if (Irp->UserBuffer == NULL && Irp->MdlAddress == NULL)
        {
            // FIXME: Update last write time
            return STATUS_SUCCESS;
        }

        return STATUS_INVALID_PARAMETER;
    }

    // get the Resource
    if (Fcb->Flags & FCB_IS_VOLUME)
    {
        Resource = &DeviceExt->DirResource;
    }
    else if (IrpContext->Irp->Flags & IRP_PAGING_IO)
    {
        Resource = &Fcb->PagingIoResource;
    }
    else
    {
        Resource = &Fcb->MainResource;
    }

    // acquire exclusive access to the Resource
    if (!ExAcquireResourceExclusiveLite(Resource, BooleanFlagOn(IrpContext->Flags, IRPCONTEXT_CANWAIT)))
    {
        return STATUS_CANT_WAIT;
    }

    /* From VfatWrite(). Todo: Handle file locks
    if (!(IrpContext->Irp->Flags & IRP_PAGING_IO) &&
    FsRtlAreThereCurrentFileLocks(&Fcb->FileLock))
    {
    if (!FsRtlCheckLockForWriteAccess(&Fcb->FileLock, IrpContext->Irp))
    {
    Status = STATUS_FILE_LOCK_CONFLICT;
    goto ByeBye;
    }
    }*/

    // Is this an async request to a file?
    if (!(IrpContext->Flags & IRPCONTEXT_CANWAIT) && !(Fcb->Flags & FCB_IS_VOLUME))
    {
        DPRINT1("FIXME: Async writes not supported in NTFS!\n");

        ExReleaseResourceLite(Resource);
        return STATUS_NOT_IMPLEMENTED;
    }

    // get the buffer of data the user is trying to write
    Buffer = NtfsGetUserBuffer(Irp, BooleanFlagOn(Irp->Flags, IRP_PAGING_IO));
    ASSERT(Buffer);

    // lock the buffer
    Status = NtfsLockUserBuffer(Irp, Length, IoReadAccess);

    // were we unable to lock the buffer?
    if (!NT_SUCCESS(Status))
    {
        DPRINT1("Unable to lock user buffer!\n");

        ExReleaseResourceLite(Resource);
        return Status;
    }

    DPRINT("Existing File Size(Fcb->RFCB.FileSize.QuadPart): %I64u\n", Fcb->RFCB.FileSize.QuadPart);
    DPRINT("About to write the data. Length: %lu\n", Length);

    // TODO: handle HighPart of ByteOffset (large files)

    // write the file
    Status = NtfsWriteFile(DeviceExt,
                           FileObject,
                           Buffer,
                           Length,
                           ByteOffset.LowPart,
                           Irp->Flags,
                           BooleanFlagOn(IrpContext->Stack->Flags, SL_CASE_SENSITIVE),
                           &ReturnedWriteLength);

    IrpContext->Irp->IoStatus.Status = Status;

    // was the write successful?
    if (NT_SUCCESS(Status))
    {
        // TODO: Update timestamps

        if (FileObject->Flags & FO_SYNCHRONOUS_IO)
        {
            // advance the file pointer
            FileObject->CurrentByteOffset.QuadPart = ByteOffset.QuadPart + ReturnedWriteLength;
        }

        IrpContext->PriorityBoost = IO_DISK_INCREMENT;
    }
    else
    {
        DPRINT1("Write not Succesful!\tReturned length: %lu\n", ReturnedWriteLength);
    }

    Irp->IoStatus.Information = ReturnedWriteLength;

    // Note: We leave the user buffer that we locked alone, it's up to the I/O manager to unlock and free it

    ExReleaseResourceLite(Resource);

    return Status;
}

