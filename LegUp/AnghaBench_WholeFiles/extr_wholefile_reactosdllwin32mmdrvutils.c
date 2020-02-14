#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  WCHAR ;
typedef  int /*<<< orphan*/  VOID ;
typedef  int UINT ;
struct TYPE_4__ {int DeviceType; struct TYPE_4__* Next; int /*<<< orphan*/ * DeviceInstanceData; int /*<<< orphan*/  Name; scalar_t__ CardIndex; } ;
typedef  scalar_t__ SHORT ;
typedef  int /*<<< orphan*/ ***** PHANDLE ;
typedef  TYPE_1__* PDEVICE_LIST ;
typedef  scalar_t__ MMRESULT ;
typedef  int /*<<< orphan*/ * LPWSTR ;
typedef  int /*<<< orphan*/  LPVOID ;
typedef  int /*<<< orphan*/  LPSTR ;
typedef  int /*<<< orphan*/ **** HANDLE ;
typedef  scalar_t__ DWORD ;
typedef  int /*<<< orphan*/  DEVICE_LIST ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 scalar_t__ AUX_DEVICE_NAME_U ; 
#define  AuxDevice 140 
 int /*<<< orphan*/  CloseHandle (int /*<<< orphan*/ ****) ; 
 int /*<<< orphan*/ **** CreateFile (int /*<<< orphan*/ *,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DPRINT (char*,...) ; 
 TYPE_1__* DeviceList ; 
#define  ERROR_ACCESS_DENIED 139 
#define  ERROR_BUSY 138 
#define  ERROR_INSUFFICIENT_BUFFER 137 
#define  ERROR_INVALID_FUNCTION 136 
#define  ERROR_IO_PENDING 135 
#define  ERROR_NOT_ENOUGH_MEMORY 134 
#define  ERROR_NOT_SUPPORTED 133 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  FILE_FLAG_OVERLAPPED ; 
 int /*<<< orphan*/  FILE_SHARE_WRITE ; 
 scalar_t__ GENERIC_READ ; 
 int GetLastError () ; 
 int /*<<< orphan*/  Heap ; 
 scalar_t__ HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ ***** INVALID_HANDLE_VALUE ; 
 scalar_t__ MIDI_IN_DEVICE_NAME_U ; 
 scalar_t__ MIDI_OUT_DEVICE_NAME_U ; 
 scalar_t__ MMSYSERR_ALLOCATED ; 
 scalar_t__ MMSYSERR_BADDEVICEID ; 
 scalar_t__ MMSYSERR_ERROR ; 
 scalar_t__ MMSYSERR_INVALPARAM ; 
 scalar_t__ MMSYSERR_NOERROR ; 
 scalar_t__ MMSYSERR_NOMEM ; 
 scalar_t__ MMSYSERR_NOTSUPPORTED ; 
#define  MidiInDevice 132 
#define  MidiOutDevice 131 
#define  NO_ERROR 130 
 int /*<<< orphan*/  OPEN_EXISTING ; 
 scalar_t__ SOUND_MAX_DEVICES ; 
 int SOUND_MAX_DEVICE_NAME ; 
 int /*<<< orphan*/  SetLastError (int const) ; 
 int /*<<< orphan*/  TRUE ; 
 scalar_t__ WAVE_IN_DEVICE_NAME_U ; 
 scalar_t__ WAVE_OUT_DEVICE_NAME_U ; 
#define  WaveInDevice 129 
#define  WaveOutDevice 128 
 int /*<<< orphan*/  lstrcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int lstrlen (int /*<<< orphan*/ *) ; 
 scalar_t__ strlen (char*) ; 
 int /*<<< orphan*/  wsprintf (int /*<<< orphan*/ *,char*,scalar_t__,...) ; 

DWORD TranslateStatus(void)
{
    switch(GetLastError())
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
            
        default :
            return MMSYSERR_ERROR;
    };
}

MMRESULT OpenDevice(UINT DeviceType, DWORD ID, PHANDLE pDeviceHandle,
                    DWORD Access)
{
    DPRINT("OpenDevice()\n");
    WCHAR DeviceName[SOUND_MAX_DEVICE_NAME];
    *pDeviceHandle = INVALID_HANDLE_VALUE;

    if (ID > SOUND_MAX_DEVICES)
        return MMSYSERR_BADDEVICEID;

    switch(DeviceType)
    {
        case WaveOutDevice :
            wsprintf(DeviceName, L"\\\\.%ls%d", WAVE_OUT_DEVICE_NAME_U + strlen("\\Device"), ID);
            break;
        case WaveInDevice :
            wsprintf(DeviceName, L"\\\\.%ls%d", WAVE_IN_DEVICE_NAME_U + strlen("\\Device"), ID);
            break;
        case MidiOutDevice :
            wsprintf(DeviceName, L"\\\\.%ls%d", MIDI_OUT_DEVICE_NAME_U + strlen("\\Device"), ID);
            break;
        case MidiInDevice :
            wsprintf(DeviceName, L"\\\\.%ls%d", MIDI_IN_DEVICE_NAME_U + strlen("\\Device"), ID);
            break;
		case AuxDevice :
			 wsprintf(DeviceName, L"\\\\.%ls%d", AUX_DEVICE_NAME_U + strlen("\\Device"), ID);
			 break;
        default : 
            DPRINT("No Auido Device Found");
            return MMSYSERR_BADDEVICEID; /* Maybe we should change error code */
    };

    DPRINT("Attempting to open %S\n", DeviceName);

    *pDeviceHandle = CreateFile(DeviceName, Access, FILE_SHARE_WRITE, NULL,
                                OPEN_EXISTING, Access != GENERIC_READ ? FILE_FLAG_OVERLAPPED : 0,
                                NULL);

    DPRINT("DeviceHandle == 0x%x\n", (int)*pDeviceHandle);

    if (pDeviceHandle == INVALID_HANDLE_VALUE)
        return TranslateStatus();

    return MMSYSERR_NOERROR;
}

BOOL AddDeviceToList(PDEVICE_LIST* pList, DWORD DeviceType, DWORD CardIndex,
                     LPWSTR Name)
{
    PDEVICE_LIST pNewDevice;

    DPRINT("AddDeviceToList()\n");

    pNewDevice = (PDEVICE_LIST) HeapAlloc(Heap, 0,
        sizeof(DEVICE_LIST) + lstrlen(Name) * sizeof(WCHAR));

    if ( !pNewDevice )
    {
        SetLastError(ERROR_NOT_ENOUGH_MEMORY);
        return FALSE;
    }
    
    pNewDevice->DeviceType = DeviceType;
    pNewDevice->CardIndex = CardIndex;
    lstrcpy(pNewDevice->Name, Name);
    pNewDevice->DeviceInstanceData = NULL;
    pNewDevice->Next = *pList;
    *pList = pNewDevice;
    
    DPRINT("Success!\n");

    return TRUE;
}

VOID FreeDeviceList()
{
    PDEVICE_LIST pDevice;

    DPRINT("FreeDeviceList()\n");
    
    while (DeviceList)
    {
        pDevice = DeviceList;
        DeviceList = pDevice->Next;

        if (pDevice->DeviceInstanceData)
            HeapFree(Heap, 0, (LPVOID)pDevice->DeviceInstanceData);

        HeapFree(Heap, 0, (LPSTR)pDevice);
    }
}

MMRESULT FindDevices()
{
//    DWORD Index;
//    HKEY DriverKey;

    DPRINT("Finding devices\n");
    
//    DriverKey = OpenParametersKey();
//  see drvutil.c of MS DDK for how this SHOULD be done...

  
    SHORT i;
    HANDLE h;
    WCHAR DeviceName[SOUND_MAX_DEVICE_NAME]; 

    for (i=0; OpenDevice(WaveOutDevice, i, &h, GENERIC_READ) == MMSYSERR_NOERROR; i++) 
    { 
        wsprintf(DeviceName, L"WaveOut%d\0", i);
        CloseHandle(h);
        AddDeviceToList(&DeviceList, WaveOutDevice, 0, DeviceName);
    }

    for (i=0; OpenDevice(WaveInDevice, i, &h, GENERIC_READ) == MMSYSERR_NOERROR; i++) 
    { 
        wsprintf(DeviceName, L"WaveIn%d\0", i);
        CloseHandle(h);
        AddDeviceToList(&DeviceList, WaveInDevice, 0, DeviceName);
    }

    for (i=0; OpenDevice(MidiOutDevice, i, &h, GENERIC_READ) == MMSYSERR_NOERROR; i++) 
    { 
        wsprintf(DeviceName, L"MidiOut%d\0", i);
        CloseHandle(h);
        AddDeviceToList(&DeviceList, MidiOutDevice, 0, DeviceName);
    }

    for (i=0; OpenDevice(MidiInDevice, i, &h, GENERIC_READ) == MMSYSERR_NOERROR; i++) 
    { 
        wsprintf(DeviceName, L"MidiIn%d\0", i);
        CloseHandle(h);
        AddDeviceToList(&DeviceList, MidiInDevice, 0, DeviceName);
    }

    for (i=0; OpenDevice(AuxDevice, i, &h, GENERIC_READ) == MMSYSERR_NOERROR; i++) 
    { 
        wsprintf(DeviceName, L"Aux%d\0", i);
        CloseHandle(h);
        AddDeviceToList(&DeviceList, AuxDevice, 0, DeviceName);
    }


    // MIDI Out 0: MPU-401 UART
    // AddDeviceToList(&DeviceList, MidiOutDevice, 0, L"MidiOut0");
    // Wave Out 0: Sound Blaster 16 (ok?)
    // AddDeviceToList(&DeviceList, WaveOutDevice, 0, L"WaveOut0");

    return MMSYSERR_NOERROR; // ok?
}

DWORD GetDeviceCount(UINT DeviceType)
{
    int i;
    PDEVICE_LIST List;

    for (List = DeviceList, i = 0; List != NULL; List = List->Next)
        if (List->DeviceType == DeviceType)
            i ++;

    return i;
}

