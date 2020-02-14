#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
typedef  int UINT ;
struct TYPE_14__ {int /*<<< orphan*/  dwInstance; int /*<<< orphan*/  hWave; int /*<<< orphan*/  dwCallback; } ;
struct TYPE_13__ {int flags; int /*<<< orphan*/  kernel_device_handle; int /*<<< orphan*/  app_user_data; int /*<<< orphan*/  mme_wave_handle; int /*<<< orphan*/  callback; } ;
typedef  TYPE_1__ SessionInfo ;
typedef  int /*<<< orphan*/  PVOID ;
typedef  scalar_t__ MMRESULT ;
typedef  TYPE_2__* LPWAVEOPENDESC ;
typedef  int /*<<< orphan*/  LPVOID ;
typedef  int /*<<< orphan*/  HANDLE ;
typedef  scalar_t__ DeviceType ;
typedef  TYPE_1__* DWORD_PTR ;
typedef  int DWORD ;
typedef  scalar_t__ BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (TYPE_1__*) ; 
 scalar_t__ CallSessionThread (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CloseHandle (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CloseKernelDevice (int /*<<< orphan*/ ) ; 
 scalar_t__ CreateSession (scalar_t__,int,TYPE_1__**) ; 
 int /*<<< orphan*/  DPRINT (char*,...) ; 
 int /*<<< orphan*/  DestroySession (TYPE_1__*) ; 
 scalar_t__ DeviceIoControl (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int*,int /*<<< orphan*/ *) ; 
#define  ERROR_ACCESS_DENIED 135 
#define  ERROR_BUSY 134 
#define  ERROR_INSUFFICIENT_BUFFER 133 
#define  ERROR_INVALID_FUNCTION 132 
#define  ERROR_IO_PENDING 131 
#define  ERROR_NOT_ENOUGH_MEMORY 130 
#define  ERROR_NOT_SUPPORTED 129 
 int /*<<< orphan*/  GENERIC_READ ; 
 int GetLastError () ; 
 int IOCTL_MIDI_GET_CAPABILITIES ; 
 int IOCTL_WAVE_GET_CAPABILITIES ; 
 scalar_t__ IsAuxDevice (scalar_t__) ; 
 scalar_t__ IsMidiDevice (scalar_t__) ; 
 scalar_t__ IsWaveDevice (scalar_t__) ; 
 int MIM_OPEN ; 
 scalar_t__ MMSYSERR_ALLOCATED ; 
 scalar_t__ MMSYSERR_BADDEVICEID ; 
 scalar_t__ MMSYSERR_ERROR ; 
 scalar_t__ MMSYSERR_INVALPARAM ; 
 scalar_t__ MMSYSERR_NOERROR ; 
 scalar_t__ MMSYSERR_NOMEM ; 
 scalar_t__ MMSYSERR_NOTSUPPORTED ; 
 int MOM_OPEN ; 
 scalar_t__ MidiInDevice ; 
 scalar_t__ MidiOutDevice ; 
#define  NO_ERROR 128 
 int /*<<< orphan*/  NotifyClient (TYPE_1__*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ OpenKernelDevice (scalar_t__,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ StartSessionThread (TYPE_1__*) ; 
 int WIM_OPEN ; 
 int /*<<< orphan*/  WODM_CLOSE ; 
 int WOM_OPEN ; 
 scalar_t__ WaveInDevice ; 
 scalar_t__ WaveOutDevice ; 

MMRESULT
ErrorToMmResult(UINT error_code)
{
    switch ( error_code )
    {
        case NO_ERROR :
        case ERROR_IO_PENDING :
            return MMSYSERR_NOERROR;

        case ERROR_BUSY :
            return MMSYSERR_ALLOCATED;

        case ERROR_NOT_SUPPORTED :
        case ERROR_INVALID_FUNCTION :
            return MMSYSERR_NOTSUPPORTED;

        case ERROR_NOT_ENOUGH_MEMORY :
            return MMSYSERR_NOMEM;

        case ERROR_ACCESS_DENIED :
            return MMSYSERR_BADDEVICEID;

        case ERROR_INSUFFICIENT_BUFFER :
            return MMSYSERR_INVALPARAM;
    };

    /* If all else fails, it's just a plain old error */

    return MMSYSERR_ERROR;
}

DWORD
GetDeviceCount(DeviceType device_type)
{
    UINT index = 0;
    HANDLE handle;

    /* Cycle through devices until an error occurs */

    while ( OpenKernelDevice(device_type, index, GENERIC_READ, &handle) == MMSYSERR_NOERROR )
    {
        CloseHandle(handle);
        index ++;
    }

    DPRINT("Found %d devices of type %d\n", index, device_type);

    return index;
}

DWORD
GetDeviceCapabilities(
    DeviceType device_type,
    UINT device_id,
    DWORD_PTR capabilities,
    DWORD capabilities_size)
{
    MMRESULT result;
    DWORD ioctl;
    HANDLE handle;
    DWORD bytes_returned;
    BOOL device_io_result;

    ASSERT(capabilities);

    /* Choose the right IOCTL for the job */

    if ( IsWaveDevice(device_type) )
        ioctl = IOCTL_WAVE_GET_CAPABILITIES;
    else if ( IsMidiDevice(device_type) )
        ioctl = IOCTL_MIDI_GET_CAPABILITIES;
    else if ( IsAuxDevice(device_type) )
        return MMSYSERR_NOTSUPPORTED; /* TODO */
    else
        return MMSYSERR_NOTSUPPORTED;

    result = OpenKernelDevice(device_type,
                              device_id,
                              GENERIC_READ,
                              &handle);

    if ( result != MMSYSERR_NOERROR )
    {
        DPRINT("Failed to open kernel device\n");
        return result;
    }

    device_io_result = DeviceIoControl(handle,
                                       ioctl,
                                       NULL,
                                       0,
                                       (LPVOID) capabilities,
                                       capabilities_size,
                                       &bytes_returned,
                                       NULL);

    /* Translate result */

    if ( device_io_result )
        result = MMSYSERR_NOERROR;
    else
        result = ErrorToMmResult(GetLastError());

    /* Clean up and return */

    CloseKernelDevice(handle);

    return result;
}

DWORD
OpenDevice(
    DeviceType device_type,
    UINT device_id,
    PVOID open_descriptor,
    DWORD flags,
    DWORD_PTR private_handle)
{
    SessionInfo* session_info;
    MMRESULT result;
    DWORD message;

    /* This will automatically check for duplicate sessions */
    result = CreateSession(device_type, device_id, &session_info);

    if ( result != MMSYSERR_NOERROR )
    {
        DPRINT("Couldn't allocate session info\n");
        return result;
    }

    result = OpenKernelDevice(device_type,
                              device_id,
                              GENERIC_READ,
                              &session_info->kernel_device_handle);

    if ( result != MMSYSERR_NOERROR )
    {
        DPRINT("Failed to open kernel device\n");
        DestroySession(session_info);
        return result;
    }

    /* Set common session data */

    session_info->flags = flags;

    /* Set wave/MIDI specific data */

    if ( IsWaveDevice(device_type) )
    {
        LPWAVEOPENDESC wave_open_desc = (LPWAVEOPENDESC) open_descriptor;
        session_info->callback = wave_open_desc->dwCallback;
        session_info->mme_wave_handle = wave_open_desc->hWave;
        session_info->app_user_data = wave_open_desc->dwInstance;
    }
    else
    {
        DPRINT("Only wave devices are supported at present!\n");
        DestroySession(session_info);
        return MMSYSERR_NOTSUPPORTED;
    }

    /* Start the processing thread */

    result = StartSessionThread(session_info);

    if ( result != MMSYSERR_NOERROR )
    {
        DestroySession(session_info);
        return result;
    }

    /* Store the session info */

    *((SessionInfo**)private_handle) = session_info;

    /* Send the right message */

    message = (device_type == WaveOutDevice) ? WOM_OPEN :
              (device_type == WaveInDevice) ? WIM_OPEN :
              (device_type == MidiOutDevice) ? MOM_OPEN :
              (device_type == MidiInDevice) ? MIM_OPEN : 0xFFFFFFFF;

    NotifyClient(session_info, message, 0, 0);

    return MMSYSERR_NOERROR;
}

DWORD
CloseDevice(
    DWORD_PTR private_handle)
{
    MMRESULT result;
    SessionInfo* session_info = (SessionInfo*) private_handle;
    /* TODO: Maybe this is best off inside the playback thread? */

    ASSERT(session_info);

    result = CallSessionThread(session_info, WODM_CLOSE, 0);

    if ( result == MMSYSERR_NOERROR )
    {
        /* TODO: Wait for it to be safe to terminate */

        CloseKernelDevice(session_info->kernel_device_handle);

        DestroySession(session_info);
    }

    return result;
}

