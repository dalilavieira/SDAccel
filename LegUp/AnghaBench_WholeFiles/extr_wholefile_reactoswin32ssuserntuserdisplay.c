#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  VOID ;
struct TYPE_6__ {void* y; void* x; } ;
struct TYPE_7__ {int /*<<< orphan*/  dmFields; TYPE_1__ dmPosition; void* dmDisplayFixedOutput; void* dmDisplayOrientation; void* dmPanningHeight; void* dmPanningWidth; void* dmDisplayFrequency; void* dmDisplayFlags; void* dmPelsHeight; void* dmPelsWidth; void* dmBitsPerPel; } ;
typedef  TYPE_2__* PDEVMODEW ;
typedef  int /*<<< orphan*/  HKEY ;
typedef  void* DWORD ;
typedef  int /*<<< orphan*/  DEVMODEW ;

/* Variables and functions */
 int /*<<< orphan*/  DM_BITSPERPEL ; 
 int /*<<< orphan*/  DM_DISPLAYFIXEDOUTPUT ; 
 int /*<<< orphan*/  DM_DISPLAYFLAGS ; 
 int /*<<< orphan*/  DM_DISPLAYFREQUENCY ; 
 int /*<<< orphan*/  DM_DISPLAYORIENTATION ; 
 int /*<<< orphan*/  DM_PANNINGHEIGHT ; 
 int /*<<< orphan*/  DM_PANNINGWIDTH ; 
 int /*<<< orphan*/  DM_PELSHEIGHT ; 
 int /*<<< orphan*/  DM_PELSWIDTH ; 
 int /*<<< orphan*/  DM_POSITION ; 
 scalar_t__ RegReadDWORD (int /*<<< orphan*/ ,char*,void**) ; 
 int /*<<< orphan*/  RegWriteDWORD (int /*<<< orphan*/ ,char*,void*) ; 
 int /*<<< orphan*/  RtlZeroMemory (TYPE_2__*,int) ; 

VOID
RegWriteDisplaySettings(HKEY hkey, PDEVMODEW pdm)
{
    RegWriteDWORD(hkey, L"DefaultSettings.BitsPerPel", pdm->dmBitsPerPel);
    RegWriteDWORD(hkey, L"DefaultSettings.XResolution", pdm->dmPelsWidth);
    RegWriteDWORD(hkey, L"DefaultSettings.YResolution", pdm->dmPelsHeight);
    RegWriteDWORD(hkey, L"DefaultSettings.Flags", pdm->dmDisplayFlags);
    RegWriteDWORD(hkey, L"DefaultSettings.VRefresh", pdm->dmDisplayFrequency);
    RegWriteDWORD(hkey, L"DefaultSettings.XPanning", pdm->dmPanningWidth);
    RegWriteDWORD(hkey, L"DefaultSettings.YPanning", pdm->dmPanningHeight);
    RegWriteDWORD(hkey, L"DefaultSettings.Orientation", pdm->dmDisplayOrientation);
    RegWriteDWORD(hkey, L"DefaultSettings.FixedOutput", pdm->dmDisplayFixedOutput);
    RegWriteDWORD(hkey, L"Attach.RelativeX", pdm->dmPosition.x);
    RegWriteDWORD(hkey, L"Attach.RelativeY", pdm->dmPosition.y);
//    RegWriteDWORD(hkey, L"Attach.ToDesktop, pdm->dmBitsPerPel", pdm->);
}

VOID
RegReadDisplaySettings(HKEY hkey, PDEVMODEW pdm)
{
    DWORD dwValue;

    /* Zero out the structure */
    RtlZeroMemory(pdm, sizeof(DEVMODEW));

/* Helper macro */
#define READ(field, str, flag) \
    if (RegReadDWORD(hkey, L##str, &dwValue)) \
    { \
        pdm->field = dwValue; \
        pdm->dmFields |= flag; \
    }

    /* Read all present settings */
    READ(dmBitsPerPel, "DefaultSettings.BitsPerPel", DM_BITSPERPEL);
    READ(dmPelsWidth, "DefaultSettings.XResolution", DM_PELSWIDTH);
    READ(dmPelsHeight, "DefaultSettings.YResolution", DM_PELSHEIGHT);
    READ(dmDisplayFlags, "DefaultSettings.Flags", DM_DISPLAYFLAGS);
    READ(dmDisplayFrequency, "DefaultSettings.VRefresh", DM_DISPLAYFREQUENCY);
    READ(dmPanningWidth, "DefaultSettings.XPanning", DM_PANNINGWIDTH);
    READ(dmPanningHeight, "DefaultSettings.YPanning", DM_PANNINGHEIGHT);
    READ(dmDisplayOrientation, "DefaultSettings.Orientation", DM_DISPLAYORIENTATION);
    READ(dmDisplayFixedOutput, "DefaultSettings.FixedOutput", DM_DISPLAYFIXEDOUTPUT);
    READ(dmPosition.x, "Attach.RelativeX", DM_POSITION);
    READ(dmPosition.y, "Attach.RelativeY", DM_POSITION);
}

