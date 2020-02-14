#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_21__   TYPE_4__ ;
typedef  struct TYPE_20__   TYPE_3__ ;
typedef  struct TYPE_19__   TYPE_2__ ;
typedef  struct TYPE_18__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  WAVEFORMATEX ;
typedef  int /*<<< orphan*/  VOID ;
struct TYPE_21__ {scalar_t__ wFormatTag; int cbSize; } ;
struct TYPE_20__ {int dwFlags; struct TYPE_20__* lpNext; scalar_t__ reserved; scalar_t__ dwBytesRecorded; int /*<<< orphan*/  lpData; } ;
struct TYPE_18__ {int function; int result; int /*<<< orphan*/  ready_event; int /*<<< orphan*/  go_event; int /*<<< orphan*/  parameter; } ;
struct TYPE_19__ {scalar_t__ device_type; TYPE_1__ thread; TYPE_3__* wave_queue; int /*<<< orphan*/  kernel_device_handle; } ;
typedef  TYPE_2__ SessionInfo ;
typedef  TYPE_3__* PWAVEHDR ;
typedef  TYPE_4__* PWAVEFORMATEX ;
typedef  int /*<<< orphan*/  PVOID ;
typedef  int /*<<< orphan*/  PCMWAVEFORMAT ;
typedef  int /*<<< orphan*/  PBYTE ;
typedef  int MMRESULT ;
typedef  TYPE_3__* LPWAVEHDR ;
typedef  scalar_t__ LPVOID ;
typedef  int /*<<< orphan*/  HANDLE ;
typedef  int /*<<< orphan*/  DeviceType ;
typedef  scalar_t__ DWORD_PTR ;
typedef  int DWORD ;
typedef  int BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (TYPE_2__*) ; 
 int CallSessionThread (TYPE_2__*,int const,TYPE_3__*) ; 
 int /*<<< orphan*/  DPRINT (char*,...) ; 
#define  DRVM_TERMINATE 140 
 int DeviceIoControl (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int*,int /*<<< orphan*/ *) ; 
 int FALSE ; 
 int /*<<< orphan*/  GetCurrentThread () ; 
 int GetDeviceData (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  INFINITE ; 
 int /*<<< orphan*/  IOCTL_WAVE_GET_PITCH ; 
 int /*<<< orphan*/  IOCTL_WAVE_GET_PLAYBACK_RATE ; 
 int /*<<< orphan*/  IOCTL_WAVE_SET_FORMAT ; 
 int /*<<< orphan*/  IOCTL_WAVE_SET_PITCH ; 
 int /*<<< orphan*/  IOCTL_WAVE_SET_PLAYBACK_RATE ; 
 int MMSYSERR_ERROR ; 
 int MMSYSERR_INVALPARAM ; 
 int MMSYSERR_NOERROR ; 
 int /*<<< orphan*/  NotifyClient (TYPE_2__*,int,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PerformWaveIO (TYPE_2__*) ; 
 int SetDeviceData (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  SetEvent (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SetThreadPriority (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  THREAD_PRIORITY_TIME_CRITICAL ; 
 int /*<<< orphan*/  TRUE ; 
 scalar_t__ WAIT_IO_COMPLETION ; 
 int WAVERR_BADFORMAT ; 
 int WAVERR_STILLPLAYING ; 
 int WAVERR_UNPREPARED ; 
 scalar_t__ WAVE_FORMAT_PCM ; 
 int WHDR_DONE ; 
 int WHDR_INQUEUE ; 
 int WHDR_PREPARED ; 
 int WIM_DATA ; 
#define  WODM_CLOSE 139 
#define  WODM_GETPITCH 138 
#define  WODM_GETPLAYBACKRATE 137 
#define  WODM_GETPOS 136 
#define  WODM_GETVOLUME 135 
#define  WODM_PAUSE 134 
#define  WODM_RESET 133 
#define  WODM_RESTART 132 
#define  WODM_SETPITCH 131 
#define  WODM_SETPLAYBACKRATE 130 
#define  WODM_SETVOLUME 129 
#define  WODM_WRITE 128 
 int WOM_DONE ; 
 scalar_t__ WaitForSingleObjectEx (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ WaveOutDevice ; 

MMRESULT
QueueWaveBuffer(
    SessionInfo* session_info,
    LPWAVEHDR wave_header)
{
    PWAVEHDR queue_node, previous_node;
    DPRINT("Queueing wave buffer\n");

    if ( ! wave_header )
    {
        return MMSYSERR_INVALPARAM;
    }

    if ( ! wave_header->lpData )
    {
        return MMSYSERR_INVALPARAM;
    }

    /* Headers must be prepared first */
    if ( ! ( wave_header->dwFlags & WHDR_PREPARED ) )
    {
        DPRINT("I was given a header which hasn't been prepared yet!\n");
        return WAVERR_UNPREPARED;
    }

    /* ...and they must not already be in the playing queue! */
    if ( wave_header->dwFlags & WHDR_INQUEUE )
    {
        DPRINT("I was given a header for a buffer which is already playing\n");
        return WAVERR_STILLPLAYING;
    }

    /* Initialize */
    wave_header->dwBytesRecorded = 0;

    /* Clear the DONE bit, and mark the buffer as queued */
    wave_header->dwFlags &= ~WHDR_DONE;
    wave_header->dwFlags |= WHDR_INQUEUE;

    /* Save our handle in the header */
    wave_header->reserved = (DWORD_PTR) session_info;

    /* Locate the end of the queue */
    previous_node = NULL;
    queue_node = session_info->wave_queue;

    while ( queue_node )
    {
        previous_node = queue_node;
        queue_node = queue_node->lpNext;
    }

    /* Go back a step to obtain the previous node (non-NULL) */
    queue_node = previous_node;

    /* Append our buffer here, and terminate the queue */
    queue_node->lpNext = wave_header;
    wave_header->lpNext = NULL;

    /* When no buffers are playing there's no play queue so we start one */
#if 0
    if ( ! session_info->next_buffer )
    {
        session_info->buffer_position = 0;
        session_info->next_buffer = wave_header;
    }
#endif

    /* Pass to the driver - happens automatically during playback */
//    return PerformWaveIO(session_info);
    return MMSYSERR_NOERROR;
}

VOID
ReturnCompletedBuffers(SessionInfo* session_info)
{
    PWAVEHDR header = NULL;

    /* Set the current header and test to ensure it's not NULL */
    while ( ( header = session_info->wave_queue ) )
    {
        if ( header->dwFlags & WHDR_DONE )
        {
            DWORD message;

            /* Mark as done, and unqueued */
            header->dwFlags &= ~WHDR_INQUEUE;
            header->dwFlags |= WHDR_DONE;

            /* Trim it from the start of the queue */
            session_info->wave_queue = header->lpNext;

            /* Choose appropriate notification */
            message = (session_info->device_type == WaveOutDevice) ? WOM_DONE :
                                                                     WIM_DATA;

            DPRINT("Notifying client that buffer 0x%p is done\n", header);

            /* Notify the client */
            NotifyClient(session_info, message, (DWORD_PTR) header, 0);
        }
    }

    /* TODO: Perform I/O as a new buffer may have arrived */
}

DWORD
ProcessSessionThreadRequest(SessionInfo* session_info)
{
    MMRESULT result = MMSYSERR_NOERROR;

    switch ( session_info->thread.function )
    {
        case WODM_WRITE :
        {
            result = QueueWaveBuffer(session_info,
                                     (LPWAVEHDR) session_info->thread.parameter);
            break;
        }

        case WODM_RESET :
        {
            /* TODO */
            break;
        }

        case WODM_PAUSE :
        {
            /* TODO */
            break;
        }

        case WODM_RESTART :
        {
            /* TODO */
            break;
        }

        case WODM_GETPOS :
        {
            /* TODO */
            break;
        }

        case WODM_SETPITCH :
        {
            result = SetDeviceData(session_info->kernel_device_handle,
                                   IOCTL_WAVE_SET_PITCH,
                                   (PBYTE) session_info->thread.parameter,
                                   sizeof(DWORD));
            break;
        }

        case WODM_GETPITCH :
        {
            result = GetDeviceData(session_info->kernel_device_handle,
                                   IOCTL_WAVE_GET_PITCH,
                                   (PBYTE) session_info->thread.parameter,
                                   sizeof(DWORD));
            break;
        }

        case WODM_SETVOLUME :
        {
            break;
        }

        case WODM_GETVOLUME :
        {
#if 0
            result = GetDeviceData(session_info->kernel_device_handle,
                                   IOCTL_WAVE_GET_VOLUME,
                                   (PBYTE) session_info->thread.parameter,);
#endif
            break;
        }

        case WODM_SETPLAYBACKRATE :
        {
            result = SetDeviceData(session_info->kernel_device_handle,
                                   IOCTL_WAVE_SET_PLAYBACK_RATE,
                                   (PBYTE) session_info->thread.parameter,
                                   sizeof(DWORD));
            break;
        }

        case WODM_GETPLAYBACKRATE :
        {
            result = GetDeviceData(session_info->kernel_device_handle,
                                   IOCTL_WAVE_GET_PLAYBACK_RATE,
                                   (PBYTE) session_info->thread.parameter,
                                   sizeof(DWORD));
            break;
        }

        case WODM_CLOSE :
        {
            DPRINT("Thread was asked if OK to close device\n");

            if ( session_info->wave_queue != NULL )
                result = WAVERR_STILLPLAYING;
            else
                result = MMSYSERR_NOERROR;

            break;
        }

        case DRVM_TERMINATE :
        {
            DPRINT("Terminating thread...\n");
            result = MMSYSERR_NOERROR;
            break;
        }

        default :
        {
            DPRINT("INVALID FUNCTION\n");
            result = MMSYSERR_ERROR;
            break;
        }
    }

    /* We're done with the function now */

    return result;
}

DWORD
WaveThread(LPVOID parameter)
{
    MMRESULT result = MMSYSERR_ERROR;
    SessionInfo* session_info = (SessionInfo*) parameter;
    BOOL terminate = FALSE;

    /* All your CPU time are belong to us */
    SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL);

    DPRINT("Wave processing thread setting ready state\n");

    SetEvent(session_info->thread.ready_event);

    while ( ! terminate )
    {
        /* Wait for GO event, or IO completion notification */
        while ( WaitForSingleObjectEx(session_info->thread.go_event,
                                      INFINITE,
                                      TRUE) == WAIT_IO_COMPLETION )
        {
            /* A buffer has been finished with - pass back to the client */
            ReturnCompletedBuffers(session_info);
        }

        DPRINT("Wave processing thread woken up\n");

        /* Set the terminate flag if that's what the caller wants */
        terminate = (session_info->thread.function == DRVM_TERMINATE);

        /* Process the request */
        DPRINT("Processing thread request\n");
        result = ProcessSessionThreadRequest(session_info);

        /* Store the result code */
        session_info->thread.result = result;

        /* Submit new buffers and continue existing ones */
        DPRINT("Performing wave I/O\n");
        PerformWaveIO(session_info);

        /* Now we're ready for more action */
        DPRINT("Wave processing thread sleeping\n");
        SetEvent(session_info->thread.ready_event);
    }

    return 0;
}

DWORD
GetWaveFormatExSize(PWAVEFORMATEX format)
{
    if ( format->wFormatTag == WAVE_FORMAT_PCM )
        return sizeof(PCMWAVEFORMAT);
    else
        return sizeof(WAVEFORMATEX) + format->cbSize;
}

DWORD
QueryWaveFormat(
    DeviceType device_type,
    PVOID lpFormat)
{
    /* TODO */
    return WAVERR_BADFORMAT;
}

BOOL
SetWaveFormat(
    HANDLE device_handle,
    PWAVEFORMATEX format)
{
    DWORD bytes_returned;
    DWORD size;

    size = GetWaveFormatExSize(format);

    DPRINT("SetWaveFormat\n");

    return DeviceIoControl(device_handle,
                           IOCTL_WAVE_SET_FORMAT,
                           (PVOID) format,
                           size,
                           NULL,
                           0,
                           &bytes_returned,
                           NULL);
}

DWORD
WriteWaveBuffer(
    DWORD_PTR private_handle,
    PWAVEHDR wave_header,
    DWORD wave_header_size)
{
    SessionInfo* session_info = (SessionInfo*) private_handle;
    ASSERT(session_info);

    /* Let the processing thread know that it has work to do */
    return CallSessionThread(session_info, WODM_WRITE, wave_header);
}

