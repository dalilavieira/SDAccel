#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  overlap ;
typedef  int /*<<< orphan*/  WCHAR ;
typedef  int /*<<< orphan*/  UINT ;
struct TYPE_5__ {scalar_t__ hEvent; } ;
typedef  int /*<<< orphan*/ * PWCHAR ;
typedef  int /*<<< orphan*/  PBYTE ;
typedef  TYPE_1__ OVERLAPPED ;
typedef  scalar_t__ MMRESULT ;
typedef  scalar_t__ HANDLE ;
typedef  int DeviceType ;
typedef  int /*<<< orphan*/  DWORD ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (scalar_t__*) ; 
 int /*<<< orphan*/  AUX_DEVICE_NAME ; 
#define  AuxDevice 132 
 int /*<<< orphan*/  CloseHandle (scalar_t__) ; 
 scalar_t__ CreateEvent (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ CreateFile (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DPRINT (char*,...) ; 
 int /*<<< orphan*/  DeviceIoControl (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,TYPE_1__*) ; 
 scalar_t__ ERROR_IO_PENDING ; 
 scalar_t__ ErrorToMmResult (scalar_t__) ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  FILE_FLAG_OVERLAPPED ; 
 int /*<<< orphan*/  FILE_SHARE_WRITE ; 
 int /*<<< orphan*/  GENERIC_READ ; 
 scalar_t__ GetLastError () ; 
 int /*<<< orphan*/  GetOverlappedResult (scalar_t__,TYPE_1__*,int /*<<< orphan*/ *,scalar_t__) ; 
 scalar_t__ INVALID_HANDLE_VALUE ; 
 int MAX_DEVICE_NAME_LENGTH ; 
 int /*<<< orphan*/  MIDI_IN_DEVICE_NAME ; 
 int /*<<< orphan*/  MIDI_OUT_DEVICE_NAME ; 
 scalar_t__ MMSYSERR_BADDEVICEID ; 
 scalar_t__ MMSYSERR_NOERROR ; 
 scalar_t__ MMSYSERR_NOMEM ; 
#define  MidiInDevice 131 
#define  MidiOutDevice 130 
 int /*<<< orphan*/  OPEN_EXISTING ; 
 int /*<<< orphan*/  SetEvent (scalar_t__) ; 
 scalar_t__ TRUE ; 
 scalar_t__ WAIT_IO_COMPLETION ; 
 int /*<<< orphan*/  WAVE_IN_DEVICE_NAME ; 
 int /*<<< orphan*/  WAVE_OUT_DEVICE_NAME ; 
 scalar_t__ WaitForSingleObjectEx (scalar_t__,int /*<<< orphan*/ ,scalar_t__) ; 
#define  WaveInDevice 129 
#define  WaveOutDevice 128 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 int strlen (char*) ; 
 int /*<<< orphan*/  wsprintf (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,...) ; 

MMRESULT
CobbleDeviceName(
    DeviceType device_type,
    UINT device_id,
    PWCHAR out_device_name)
{
    WCHAR base_device_name[MAX_DEVICE_NAME_LENGTH];

    /* Work out the base name from the device type */

    switch ( device_type )
    {
        case WaveOutDevice :
            wsprintf(base_device_name, L"%ls", WAVE_OUT_DEVICE_NAME);
            break;

        case WaveInDevice :
            wsprintf(base_device_name, L"%ls", WAVE_IN_DEVICE_NAME);
            break;

        case MidiOutDevice :
            wsprintf(base_device_name, L"%ls", MIDI_OUT_DEVICE_NAME);
            break;

        case MidiInDevice :
            wsprintf(base_device_name, L"%ls", MIDI_IN_DEVICE_NAME);
            break;

        case AuxDevice :
            wsprintf(base_device_name, L"%ls", AUX_DEVICE_NAME);
            break;

        default :
            return MMSYSERR_BADDEVICEID;
    };

    /* Now append the device number, removing the leading \Device */

    wsprintf(out_device_name,
             L"\\\\.%ls%d",
             base_device_name + strlen("\\Device"),
             device_id);

    return MMSYSERR_NOERROR;
}

MMRESULT
OpenKernelDevice(
    DeviceType device_type,
    UINT device_id,
    DWORD access,
    HANDLE* handle)
{
    MMRESULT result;
    WCHAR device_name[MAX_DEVICE_NAME_LENGTH];
    DWORD open_flags = 0;

    ASSERT(handle);

    /* Glue the base device name and the ID together */

    result = CobbleDeviceName(device_type, device_id, device_name);

    DPRINT("Opening kernel device %ls\n", device_name);

    if ( result != MMSYSERR_NOERROR )
        return result;

    /* We want overlapped I/O when writing */

    if ( access != GENERIC_READ )
        open_flags = FILE_FLAG_OVERLAPPED;

    /* Now try opening... */

    *handle = CreateFile(device_name,
                         access,
                         FILE_SHARE_WRITE,
                         NULL,
                         OPEN_EXISTING,
                         open_flags,
                         NULL);

    if ( *handle == INVALID_HANDLE_VALUE )
        return ErrorToMmResult(GetLastError());

    return MMSYSERR_NOERROR;
}

void
CloseKernelDevice(HANDLE device_handle)
{
    CloseHandle(device_handle);
}

MMRESULT
SetDeviceData(
    HANDLE device_handle,
    DWORD ioctl,
    PBYTE input_buffer,
    DWORD buffer_size)
{
    DPRINT("SetDeviceData\n");
    /* TODO */
    return 0;
}

MMRESULT
GetDeviceData(
    HANDLE device_handle,
    DWORD ioctl,
    PBYTE output_buffer,
    DWORD buffer_size)
{
    OVERLAPPED overlap;
    DWORD bytes_returned;
    BOOL success;
    DWORD transfer;

    DPRINT("GetDeviceData\n");

    memset(&overlap, 0, sizeof(overlap));

    overlap.hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);

    if ( ! overlap.hEvent )
        return MMSYSERR_NOMEM;

    success = DeviceIoControl(device_handle,
                              ioctl,
                              NULL,
                              0,
                              output_buffer,
                              buffer_size,
                              &bytes_returned,
                              &overlap);

    if ( ! success )
    {
        if ( GetLastError() == ERROR_IO_PENDING )
        {
            if ( ! GetOverlappedResult(device_handle, &overlap, &transfer, TRUE) )
            {
                CloseHandle(overlap.hEvent);
                return ErrorToMmResult(GetLastError());
            }
        }
        else
        {
            CloseHandle(overlap.hEvent);
            return ErrorToMmResult(GetLastError());
        }
    }

    while ( TRUE )
    {
        SetEvent(overlap.hEvent);

        if ( WaitForSingleObjectEx(overlap.hEvent, 0, TRUE) != WAIT_IO_COMPLETION )
        {
            break;
        }
    }

    CloseHandle(overlap.hEvent);

    return MMSYSERR_NOERROR;
}

