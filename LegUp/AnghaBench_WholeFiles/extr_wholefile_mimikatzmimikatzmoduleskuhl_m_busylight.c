#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_32__   TYPE_8__ ;
typedef  struct TYPE_31__   TYPE_7__ ;
typedef  struct TYPE_30__   TYPE_6__ ;
typedef  struct TYPE_29__   TYPE_5__ ;
typedef  struct TYPE_28__   TYPE_4__ ;
typedef  struct TYPE_27__   TYPE_3__ ;
typedef  struct TYPE_26__   TYPE_2__ ;
typedef  struct TYPE_25__   TYPE_22__ ;
typedef  struct TYPE_24__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  wchar_t ;
struct TYPE_32__ {int member_0; int member_1; int member_2; int red; int green; int blue; } ;
struct TYPE_25__ {int red; int green; int blue; } ;
struct TYPE_27__ {int /*<<< orphan*/  member_2; int /*<<< orphan*/  member_1; int /*<<< orphan*/  member_0; } ;
struct TYPE_31__ {int member_1; int member_3; TYPE_22__ color; int /*<<< orphan*/  AudioByte; int /*<<< orphan*/  member_5; int /*<<< orphan*/  member_4; TYPE_3__ member_2; int /*<<< orphan*/  member_0; } ;
struct TYPE_30__ {int /*<<< orphan*/  swrelease; int /*<<< orphan*/  Mfg_Date; int /*<<< orphan*/  Mfg_ID; int /*<<< orphan*/  Serial; int /*<<< orphan*/  Model; int /*<<< orphan*/  CostumerId; int /*<<< orphan*/  ProductId; int /*<<< orphan*/  status; } ;
struct TYPE_24__ {int /*<<< orphan*/  VersionNumber; int /*<<< orphan*/  ProductID; int /*<<< orphan*/  VendorID; } ;
struct TYPE_29__ {int id; TYPE_2__* deviceId; struct TYPE_29__* next; int /*<<< orphan*/  dWorkerThread; int /*<<< orphan*/  hWorkerThread; int /*<<< orphan*/  dKeepAliveThread; int /*<<< orphan*/  hKeepAliveThread; scalar_t__ hBusy; TYPE_1__ hidAttributes; int /*<<< orphan*/  DevicePath; } ;
struct TYPE_28__ {scalar_t__ blue; scalar_t__ green; scalar_t__ red; } ;
struct TYPE_26__ {int Capabilities; int /*<<< orphan*/  Description; } ;
typedef  int /*<<< orphan*/  PCWCHAR ;
typedef  TYPE_4__* PCBUSYLIGHT_COLOR ;
typedef  TYPE_5__* PBUSYLIGHT_DEVICE ;
typedef  int /*<<< orphan*/  NTSTATUS ;
typedef  int DWORD ;
typedef  int BYTE ;
typedef  TYPE_6__ BUSYLIGHT_INFO ;
typedef  TYPE_7__ BUSYLIGHT_COMMAND_STEP ;
typedef  TYPE_8__ BUSYLIGHT_COLOR ;
typedef  int BOOL ;

/* Variables and functions */
 int ARRAYSIZE (TYPE_7__*) ; 
 int /*<<< orphan*/  BUSYLIGHT_CAP_LIGHT ; 
 TYPE_22__ BUSYLIGHT_COLOR_CYAN ; 
 int /*<<< orphan*/  BUSYLIGHT_MEDIA (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BUSYLIGHT_MEDIA_JINGLE_IM2 ; 
 int /*<<< orphan*/  BUSYLIGHT_MEDIA_MUTE ; 
 int /*<<< orphan*/  BUSYLIGHT_MEDIA_SOUND_OPENOFFICE ; 
 int /*<<< orphan*/  BUSYLIGHT_MEDIA_VOLUME_4_MEDIUM ; 
 int FALSE ; 
 int /*<<< orphan*/  GetKeyboardLayout (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PRINT_ERROR (char*) ; 
 int PtrToUlong (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  STATUS_SUCCESS ; 
 int TRUE ; 
 scalar_t__ isBusyLight ; 
 int /*<<< orphan*/  kprintf (char*,...) ; 
 TYPE_7__* kuhl_m_busylight_capabilities_to_String ; 
 TYPE_5__* kuhl_m_busylight_devices ; 
 TYPE_7__* kuhl_m_busylight_steps_KiwiHack ; 
 TYPE_7__* kuhl_m_busylight_steps_ReneCotyHack ; 
 scalar_t__ kull_m_busylight_device_read_infos (TYPE_5__*,TYPE_6__*) ; 
 int /*<<< orphan*/  kull_m_busylight_devices_free (TYPE_5__*,int) ; 
 scalar_t__ kull_m_busylight_devices_get (TYPE_5__**,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  kull_m_busylight_request_send (TYPE_5__*,TYPE_7__*,int,int) ; 
 int /*<<< orphan*/  kull_m_busylight_request_send_off (TYPE_5__*,int) ; 
 scalar_t__ kull_m_string_args_byName (int,int /*<<< orphan*/ **,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int wcstoul (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

NTSTATUS kuhl_m_busylight_init()
{
	PBUSYLIGHT_DEVICE cur;
	BOOL isKbFR = (PtrToUlong(GetKeyboardLayout(0)) >> 16) == 0x40c, isKiwi = FALSE;
	if(isBusyLight = kull_m_busylight_devices_get(&kuhl_m_busylight_devices, NULL, BUSYLIGHT_CAP_LIGHT, TRUE))
	{
		for(cur = kuhl_m_busylight_devices; cur; cur = cur->next)
		{
			isKiwi = ((!(cur->id % 2) && isKbFR) || ((cur->id % 2) && !isKbFR));
			kull_m_busylight_request_send(cur, isKiwi ? kuhl_m_busylight_steps_KiwiHack : kuhl_m_busylight_steps_ReneCotyHack, isKiwi ? ARRAYSIZE(kuhl_m_busylight_steps_KiwiHack) : ARRAYSIZE(kuhl_m_busylight_steps_ReneCotyHack), FALSE);
		}
	}
	return STATUS_SUCCESS;
}

NTSTATUS kuhl_m_busylight_clean()
{
	kull_m_busylight_devices_free(kuhl_m_busylight_devices, TRUE);
	return STATUS_SUCCESS;
}

NTSTATUS kuhl_m_busylight_off(int argc, wchar_t * argv[])
{
	if(isBusyLight)
		kull_m_busylight_request_send_off(kuhl_m_busylight_devices, TRUE);
	else PRINT_ERROR(L"No BusyLight\n");
	return STATUS_SUCCESS;
}

NTSTATUS kuhl_m_busylight_status(int argc, wchar_t * argv[])
{
	PBUSYLIGHT_DEVICE cur;
	DWORD i;
	BUSYLIGHT_INFO info;

	if(isBusyLight)
	{
		kprintf(L"BusyLight detected\n");
		for(cur = kuhl_m_busylight_devices; cur; cur = cur->next)
		{
			kprintf(L"\n[%3u] %s\n"
				L"  Vendor: 0x%04x, Product: 0x%04x, Version: 0x%04x\n"
				L"  Description   : %s\n"
				L"  Capabilities  : 0x%02x ( "
				, cur->id, cur->DevicePath, cur->hidAttributes.VendorID, cur->hidAttributes.ProductID, cur->hidAttributes.VersionNumber, cur->deviceId->Description, cur->deviceId->Capabilities);
			for(i = 0; i < ARRAYSIZE(kuhl_m_busylight_capabilities_to_String); i++)
			{
				if((cur->deviceId->Capabilities >> i) & 1)
					kprintf(L"%s, ", kuhl_m_busylight_capabilities_to_String[i]);
			}
			kprintf(L")\n");

			kprintf(L"  Device Handle: 0x%p\n", cur->hBusy);
			if(cur->hBusy)
			{
				if(kull_m_busylight_device_read_infos(cur, &info))
				{
					kprintf(L"    Status     : 0x%02x\n", info.status);
					kprintf(L"    ProductId  : %S\n", info.ProductId);
					kprintf(L"    CostumerId : %S\n", info.CostumerId);
					kprintf(L"    Model      : %S\n", info.Model);
					kprintf(L"    Serial     : %S\n", info.Serial);
					kprintf(L"    Mfg_ID     : %S\n", info.Mfg_ID);
					kprintf(L"    Mfg_Date   : %S\n", info.Mfg_Date);
					kprintf(L"    swrelease  : %S\n", info.swrelease);
				}
			}
			kprintf(L"  KeepAlive Thread: 0x%p (%u ms)\n"
					L"  Worker Thread   : 0x%p (%u ms)\n"
					, cur->hKeepAliveThread, cur->dKeepAliveThread, cur->hWorkerThread, cur->dWorkerThread);
		}
	}
	else PRINT_ERROR(L"No BusyLight\n");
	return STATUS_SUCCESS;
}

NTSTATUS kuhl_m_busylight_list(int argc, wchar_t * argv[])
{
	PBUSYLIGHT_DEVICE cur;
	DWORD i;

	if(isBusyLight)
	{
		for(cur = kuhl_m_busylight_devices; cur; cur = cur->next)
		{
			kprintf(L"[%3u] %s ( ", cur->id, cur->deviceId->Description);
			for(i = 0; i < ARRAYSIZE(kuhl_m_busylight_capabilities_to_String); i++)
			{
				if((cur->deviceId->Capabilities >> i) & 1)
					kprintf(L"%s, ", kuhl_m_busylight_capabilities_to_String[i]);
			}
			kprintf(L")\n");
		}
	}
	else PRINT_ERROR(L"No BusyLight\n");
	return STATUS_SUCCESS;
}

NTSTATUS kuhl_m_busylight_single(int argc, wchar_t * argv[])
{
	PCWCHAR szColor;
	DWORD dwColor;
	BUSYLIGHT_COMMAND_STEP mdl = {0, 1, {0, 0, 0}, 1, 0, BUSYLIGHT_MEDIA_MUTE};
	
	mdl.color = BUSYLIGHT_COLOR_CYAN;
	if(isBusyLight)
	{
		mdl.AudioByte = BUSYLIGHT_MEDIA(kull_m_string_args_byName(argc, argv, L"sound", NULL, NULL) ? BUSYLIGHT_MEDIA_SOUND_OPENOFFICE : BUSYLIGHT_MEDIA_JINGLE_IM2, BUSYLIGHT_MEDIA_VOLUME_4_MEDIUM);
		if(kull_m_string_args_byName(argc, argv, L"color", &szColor, NULL))
		{
			dwColor = wcstoul(szColor, NULL, 0);
			mdl.color.red   = (BYTE) ((dwColor & 0x00ff0000) >> 16);
			mdl.color.green = (BYTE) ((dwColor & 0x0000ff00) >> 8);
			mdl.color.blue  = (BYTE) (dwColor & 0x000000ff);
		}
		kull_m_busylight_request_send(kuhl_m_busylight_devices, &mdl, 1, TRUE);
	}
	else PRINT_ERROR(L"No BusyLight\n");
	return STATUS_SUCCESS;
}

BUSYLIGHT_COLOR adaptColor(PCBUSYLIGHT_COLOR color, BYTE percent)
{
	BUSYLIGHT_COLOR rColor = {
		(BYTE) (((DWORD) color->red * percent) / 100),
		(BYTE) (((DWORD) color->green * percent) / 100),
		(BYTE) (((DWORD) color->blue * percent) / 100)
	};
	if(!rColor.red && percent && color->red)
		rColor.red = 1;
	if(!rColor.green && percent && color->green)
		rColor.green = 1;
	if(!rColor.blue && percent && color->blue)
		rColor.blue = 1;
	return rColor;
}

