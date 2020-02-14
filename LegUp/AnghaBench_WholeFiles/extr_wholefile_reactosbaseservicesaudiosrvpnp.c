#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_4__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  notification_filter ;
typedef  int /*<<< orphan*/  interface_data ;
typedef  int /*<<< orphan*/  device_data ;
typedef  int /*<<< orphan*/  WCHAR ;
typedef  int /*<<< orphan*/  VOID ;
struct TYPE_19__ {int /*<<< orphan*/  member_0; } ;
struct TYPE_18__ {int cbSize; int dbcc_size; TYPE_4__ dbcc_classguid; int /*<<< orphan*/  dbcc_devicetype; int /*<<< orphan*/  dbcc_name; int /*<<< orphan*/  DevicePath; } ;
struct TYPE_17__ {int cbSize; scalar_t__ Reserved; } ;
struct TYPE_16__ {int cbSize; scalar_t__ Reserved; } ;
typedef  TYPE_1__ SP_DEVINFO_DATA ;
typedef  int /*<<< orphan*/  SP_DEVICE_INTERFACE_DETAIL_DATA_W ;
typedef  int /*<<< orphan*/  SP_DEVICE_INTERFACE_DETAIL_DATA ;
typedef  TYPE_2__ SP_DEVICE_INTERFACE_DATA ;
typedef  int /*<<< orphan*/  PnP_AudioDevice ;
typedef  TYPE_3__* PSP_DEVICE_INTERFACE_DETAIL_DATA_W ;
typedef  scalar_t__ LPVOID ;
typedef  int /*<<< orphan*/  HDEVINFO ;
typedef  int /*<<< orphan*/  HANDLE ;
typedef  TYPE_4__ GUID ;
typedef  int DWORD ;
typedef  TYPE_3__ DEV_BROADCAST_DEVICEINTERFACE ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  AppendAudioDeviceToList (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * CreateDeviceDescriptor (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
#define  DBT_DEVICEARRIVAL 128 
 int /*<<< orphan*/  DBT_DEVTYP_DEVICEINTERFACE ; 
 int /*<<< orphan*/  DEVICE_NOTIFY_SERVICE_HANDLE ; 
 int DIGCF_DEVICEINTERFACE ; 
 int DIGCF_PRESENT ; 
 int /*<<< orphan*/  DestroyDeviceDescriptor (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  GetLastError () ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 scalar_t__ HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_3__*) ; 
 int MAX_PATH ; 
 int NO_ERROR ; 
 int /*<<< orphan*/ * RegisterDeviceNotificationW (int /*<<< orphan*/ ,TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  STATIC_KSCATEGORY_AUDIO ; 
 int /*<<< orphan*/  SetupDiDestroyDeviceInfoList (int /*<<< orphan*/ ) ; 
 scalar_t__ SetupDiEnumDeviceInterfaces (int /*<<< orphan*/ ,int /*<<< orphan*/ *,TYPE_4__ const*,int,TYPE_2__*) ; 
 int /*<<< orphan*/  SetupDiGetClassDevsExW (TYPE_4__ const*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SetupDiGetDeviceInterfaceDetailW (int /*<<< orphan*/ ,TYPE_2__*,TYPE_3__*,int,int /*<<< orphan*/ *,TYPE_1__*) ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  ZeroMemory (TYPE_3__*,int) ; 
 int /*<<< orphan*/ * device_notification_handle ; 
 int /*<<< orphan*/  logmsg (char*,...) ; 
 scalar_t__ service_status_handle ; 

BOOL
ProcessExistingDevices()
{
    SP_DEVICE_INTERFACE_DATA interface_data;
    SP_DEVINFO_DATA device_data;
    PSP_DEVICE_INTERFACE_DETAIL_DATA_W detail_data;
    HDEVINFO dev_info;
    DWORD length;
    int index = 0;

    const GUID category_guid = {STATIC_KSCATEGORY_AUDIO};

    dev_info = SetupDiGetClassDevsExW(&category_guid,
                                      NULL,
                                      NULL,
                                      DIGCF_PRESENT | DIGCF_DEVICEINTERFACE,
                                      NULL,
                                      NULL,
                                      NULL);

/*    printf("%s:\n", ClassString); */

    interface_data.cbSize = sizeof(interface_data);
    interface_data.Reserved = 0;

    /* Enumerate the devices within the category */
    index = 0;

    length = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA)
                + (MAX_PATH * sizeof(WCHAR));

    detail_data =
        (PSP_DEVICE_INTERFACE_DETAIL_DATA_W)HeapAlloc(GetProcessHeap(),
                                                      0,
                                                      length);

    if ( ! detail_data )
    {
        logmsg("ProcessExistingDevices() failed to allocate detail_data\n");
        return TRUE;
    }

    while (
    SetupDiEnumDeviceInterfaces(dev_info,
                                NULL,
                                &category_guid,
                                index,
                                &interface_data) )
    {
        PnP_AudioDevice* list_node;

        ZeroMemory(detail_data, length);

        /* NOTE: We don't actually use device_data... */
        detail_data->cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA_W);
        device_data.cbSize = sizeof(device_data);
        device_data.Reserved = 0;
        SetupDiGetDeviceInterfaceDetailW(dev_info,
                                         &interface_data,
                                         detail_data,
                                         length,
                                         NULL,
                                         &device_data);

        list_node = CreateDeviceDescriptor(detail_data->DevicePath, TRUE);
        AppendAudioDeviceToList(list_node);
        DestroyDeviceDescriptor(list_node);

        /* TODO: Cleanup the device we enumerated? */

        index ++;
    };

    HeapFree(GetProcessHeap(), 0, detail_data);

    SetupDiDestroyDeviceInfoList(dev_info);

    return TRUE;
}

DWORD
ProcessDeviceArrival(DEV_BROADCAST_DEVICEINTERFACE* device)
{
    PnP_AudioDevice* list_node;
    list_node = CreateDeviceDescriptor(device->dbcc_name, TRUE);
    AppendAudioDeviceToList(list_node);
    DestroyDeviceDescriptor(list_node);

    return NO_ERROR;
}

BOOL
RegisterForDeviceNotifications()
{
    DEV_BROADCAST_DEVICEINTERFACE notification_filter;

    const GUID wdmaud_guid = {STATIC_KSCATEGORY_AUDIO};

    ZeroMemory(&notification_filter, sizeof(notification_filter));
    notification_filter.dbcc_size = sizeof(DEV_BROADCAST_DEVICEINTERFACE);
    notification_filter.dbcc_devicetype = DBT_DEVTYP_DEVICEINTERFACE;
    notification_filter.dbcc_classguid = wdmaud_guid;

    device_notification_handle =
        RegisterDeviceNotificationW((HANDLE) service_status_handle,
                                    &notification_filter,
                                    DEVICE_NOTIFY_SERVICE_HANDLE
/* |
                                   DEVICE_NOTIFY_ALL_INTERFACE_CLASSES*/);

    if ( ! device_notification_handle )
    {
        logmsg("RegisterDeviceNotification() failed with error %d\n", GetLastError());
    }

    return ( device_notification_handle != NULL );
}

VOID UnregisterDeviceNotifications()
{
    /* TODO -- NOT IMPLEMENTED! */

    if ( device_notification_handle )
    {
        /* TODO */
        device_notification_handle = NULL;
    }
}

DWORD
HandleDeviceEvent(
    DWORD dwEventType,
    LPVOID lpEventData)
{
    switch ( dwEventType )
    {
        case DBT_DEVICEARRIVAL :
        {
            DEV_BROADCAST_DEVICEINTERFACE* incoming_device =
                (DEV_BROADCAST_DEVICEINTERFACE*) lpEventData;

            return ProcessDeviceArrival(incoming_device);
        }

        default :
        {
            break;
        }
    }

    return NO_ERROR;
}

