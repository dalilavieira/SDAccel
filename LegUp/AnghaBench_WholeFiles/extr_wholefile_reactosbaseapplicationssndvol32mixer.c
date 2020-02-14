#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_57__   TYPE_8__ ;
typedef  struct TYPE_56__   TYPE_1__ ;
typedef  struct TYPE_55__   TYPE_15__ ;
typedef  struct TYPE_54__   TYPE_13__ ;
typedef  struct TYPE_53__   TYPE_11__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  VOID ;
typedef  size_t UINT ;
struct TYPE_57__ {int cControls; scalar_t__ dwLineID; int cbStruct; size_t cConnections; size_t dwDestination; size_t dwSource; size_t szName; size_t szShortName; int /*<<< orphan*/  dwComponentType; } ;
struct TYPE_55__ {size_t cDestinations; size_t szPname; } ;
struct TYPE_56__ {scalar_t__ MixersCount; size_t MixerId; int fdwControl; int dwControlType; size_t DisplayControls; scalar_t__ hmx; TYPE_8__ Info; struct TYPE_56__* Next; struct TYPE_56__* Connections; struct TYPE_56__* Lines; TYPE_15__ Caps; scalar_t__ hWndNotification; struct TYPE_56__* Controls; int /*<<< orphan*/  szName; } ;
struct TYPE_54__ {int cbStruct; void* paDetails; scalar_t__ cbDetails; scalar_t__ cMultipleItems; scalar_t__ cChannels; scalar_t__ dwControlID; } ;
struct TYPE_53__ {int cbStruct; scalar_t__ dwLineID; size_t cControls; int cbmxctrl; TYPE_1__* pamxctrl; } ;
typedef  int /*<<< orphan*/  TCHAR ;
typedef  TYPE_1__ SND_MIXER_DESTINATION ;
typedef  TYPE_1__ SND_MIXER_CONNECTION ;
typedef  int /*<<< orphan*/  SND_MIXER ;
typedef  int /*<<< orphan*/  PVOID ;
typedef  size_t* PUINT ;
typedef  TYPE_1__* PSND_MIXER_DESTINATION ;
typedef  TYPE_1__* PSND_MIXER_CONNECTION ;
typedef  TYPE_1__* PSND_MIXER ;
typedef  int /*<<< orphan*/  (* PFNSNDMIXENUMPRODUCTS ) (TYPE_1__*,size_t,size_t,int /*<<< orphan*/ ) ;
typedef  int /*<<< orphan*/  (* PFNSNDMIXENUMLINES ) (TYPE_1__*,TYPE_8__*,size_t,int /*<<< orphan*/ ) ;
typedef  int /*<<< orphan*/  (* PFNSNDMIXENUMCONNECTIONS ) (TYPE_1__*,scalar_t__,TYPE_8__*,int /*<<< orphan*/ ) ;
typedef  scalar_t__ MMRESULT ;
typedef  TYPE_11__ MIXERLINECONTROLS ;
typedef  TYPE_8__ MIXERLINE ;
typedef  TYPE_13__ MIXERCONTROLDETAILS ;
typedef  TYPE_1__ MIXERCONTROL ;
typedef  TYPE_15__ MIXERCAPS ;
typedef  int /*<<< orphan*/  LineInfo ;
typedef  int /*<<< orphan*/  LineControls ;
typedef  int /*<<< orphan*/  LPWSTR ;
typedef  void* LPVOID ;
typedef  int /*<<< orphan*/ * LPTSTR ;
typedef  TYPE_8__* LPMIXERLINE ;
typedef  TYPE_1__* LPMIXERCONTROL ;
typedef  size_t INT ;
typedef  scalar_t__ HWND ;
typedef  int /*<<< orphan*/  HMIXEROBJ ;
typedef  int /*<<< orphan*/ * HMIXER ;
typedef  int /*<<< orphan*/  DWORD_PTR ;
typedef  scalar_t__ DWORD ;
typedef  int /*<<< orphan*/  Caps ;
typedef  void* BOOL ;

/* Variables and functions */
 int CALLBACK_WINDOW ; 
 int /*<<< orphan*/  DPRINT (char*,...) ; 
 void* FALSE ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 int /*<<< orphan*/  HEAP_ZERO_MEMORY ; 
 scalar_t__ HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int MIXERCONTROL_CONTROLF_DISABLED ; 
#define  MIXERCONTROL_CT_CLASS_FADER 129 
 int MIXERCONTROL_CT_CLASS_MASK ; 
#define  MIXERCONTROL_CT_CLASS_SWITCH 128 
 int MIXER_GETCONTROLDETAILSF_VALUE ; 
 int /*<<< orphan*/  MIXER_GETLINECONTROLSF_ALL ; 
 int /*<<< orphan*/  MIXER_GETLINEINFOF_DESTINATION ; 
 int /*<<< orphan*/  MIXER_GETLINEINFOF_SOURCE ; 
 int MIXER_OBJECTF_HMIXER ; 
 int MIXER_OBJECTF_MIXER ; 
 int MIXER_SETCONTROLDETAILSF_VALUE ; 
 scalar_t__ MMSYSERR_NOERROR ; 
 void* NO_MIXER_SELECTED ; 
 int /*<<< orphan*/  SndMixerClose (TYPE_1__*) ; 
 void* SndMixerIsDisplayControl (TYPE_1__*,TYPE_1__*) ; 
 void* SndMixerSelect (TYPE_1__*,size_t) ; 
 void* TRUE ; 
 int /*<<< orphan*/  _T (char) ; 
 scalar_t__ lstrlen (size_t) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,size_t,size_t) ; 
 int /*<<< orphan*/  mixerClose (int /*<<< orphan*/ *) ; 
 scalar_t__ mixerGetControlDetails (int /*<<< orphan*/ ,TYPE_13__*,int) ; 
 scalar_t__ mixerGetDevCaps (size_t,TYPE_15__*,int) ; 
 scalar_t__ mixerGetLineControls (int /*<<< orphan*/ ,TYPE_11__*,int /*<<< orphan*/ ) ; 
 scalar_t__ mixerGetLineInfo (int /*<<< orphan*/ ,TYPE_8__*,int /*<<< orphan*/ ) ; 
 scalar_t__ mixerGetNumDevs () ; 
 scalar_t__ mixerOpen (int /*<<< orphan*/ **,size_t,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 scalar_t__ mixerSetControlDetails (int /*<<< orphan*/ ,TYPE_13__*,int) ; 
 scalar_t__ wcsicmp (size_t,int /*<<< orphan*/ ) ; 

__attribute__((used)) static VOID
ClearMixerCache(PSND_MIXER Mixer)
{
    PSND_MIXER_DESTINATION Line, NextLine;
    PSND_MIXER_CONNECTION Con, NextCon;

    for (Line = Mixer->Lines; Line != NULL; Line = NextLine)
    {
        if (Line->Controls != NULL)
        {
            HeapFree(GetProcessHeap(),
                     0,
                     Line->Controls);
        }

        for (Con = Line->Connections; Con != NULL; Con = NextCon)
        {
            if (Con->Controls != NULL)
            {
                HeapFree(GetProcessHeap(),
                         0,
                         Con->Controls);
            }

            NextCon = Con->Next;
            HeapFree(GetProcessHeap(),
                     0,
                     Con);
        }

        NextLine = Line->Next;
        HeapFree(GetProcessHeap(),
                 0,
                 Line);
    }
    Mixer->Lines = NULL;
}

PSND_MIXER
SndMixerCreate(HWND hWndNotification, UINT MixerId)
{
    PSND_MIXER Mixer = (PSND_MIXER) HeapAlloc(GetProcessHeap(),
                                 HEAP_ZERO_MEMORY,
                                 sizeof(SND_MIXER));
    if (Mixer != NULL)
    {
        Mixer->hWndNotification = hWndNotification;
        Mixer->MixersCount = mixerGetNumDevs();
        Mixer->MixerId = NO_MIXER_SELECTED;

        if (Mixer->MixersCount > 0)
        {
            /* select the first mixer by default */
            SndMixerSelect(Mixer, MixerId);
        }
    }

    return Mixer;
}

VOID
SndMixerDestroy(PSND_MIXER Mixer)
{
    ClearMixerCache(Mixer);
    SndMixerClose(Mixer);
    HeapFree(GetProcessHeap(),
             0,
             Mixer);
}

VOID
SndMixerClose(PSND_MIXER Mixer)
{
    if (Mixer->hmx != NULL)
    {
      mixerClose(Mixer->hmx);
      Mixer->hmx = NULL;
      Mixer->MixerId = NO_MIXER_SELECTED;
    }
}

BOOL
SndMixerQueryControls(PSND_MIXER Mixer,
                      PUINT DisplayControls,
                      LPMIXERLINE LineInfo,
                      LPMIXERCONTROL *Controls)
{
    if (LineInfo->cControls > 0)
    {
        *Controls = (MIXERCONTROL*) HeapAlloc(GetProcessHeap(),
                              HEAP_ZERO_MEMORY,
                              LineInfo->cControls * sizeof(MIXERCONTROL));
        if (*Controls != NULL)
        {
            MIXERLINECONTROLS LineControls;
            MMRESULT Result;
            UINT j;

            LineControls.cbStruct = sizeof(LineControls);
            LineControls.dwLineID = LineInfo->dwLineID;
            LineControls.cControls = LineInfo->cControls;
            LineControls.cbmxctrl = sizeof(MIXERCONTROL);
            LineControls.pamxctrl = (MIXERCONTROL*)(*Controls);

            Result = mixerGetLineControls((HMIXEROBJ)Mixer->hmx,
                                          &LineControls,
                                          MIXER_GETLINECONTROLSF_ALL);
            if (Result == MMSYSERR_NOERROR)
            {
                for (j = 0; j < LineControls.cControls; j++)
                {
                    if (SndMixerIsDisplayControl(Mixer,
                                                 &(*Controls)[j]))
                    {
                        (*DisplayControls)++;
                    }

                    DPRINT("Line control: %ws (0x%x, 0x%x)\n", (*Controls)[j].szName, (*Controls)[j].fdwControl, (*Controls)[j].dwControlType);
                }

                return TRUE;
            }
            else
            {
                HeapFree(GetProcessHeap(),
                         0,
                         *Controls);
                *Controls = NULL;
                DPRINT("Failed to get line (ID: 0x%x) controls: %d\n", LineInfo->dwLineID, Result);
            }
        }
        else
        {
            DPRINT("Failed to allocate memory for %d line (ID: 0x%x) controls!\n", LineInfo->dwLineID, LineInfo->cControls);
        }

        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

__attribute__((used)) static BOOL
SndMixerQueryConnections(PSND_MIXER Mixer,
                         PSND_MIXER_DESTINATION Line)
{
    UINT i, DispControls;
    MIXERLINE LineInfo;
    MMRESULT Result;
    BOOL Ret = TRUE;

    LineInfo.cbStruct = sizeof(LineInfo);
    for (i = Line->Info.cConnections; i > 0; i--)
    {
        LineInfo.dwDestination = Line->Info.dwDestination;
        LineInfo.dwSource = i - 1;
        Result = mixerGetLineInfo((HMIXEROBJ)Mixer->hmx,
                                  &LineInfo,
                                  MIXER_GETLINEINFOF_SOURCE);
        if (Result == MMSYSERR_NOERROR)
        {
            LPMIXERCONTROL Controls = NULL;
            PSND_MIXER_CONNECTION Con;

            DPRINT("++ Source: %ws\n", LineInfo.szName);

            DispControls = 0;

            if (!SndMixerQueryControls(Mixer,
                                       &DispControls,
                                       &LineInfo,
                                       &Controls))
            {
                DPRINT("Failed to query connection controls\n");
                Ret = FALSE;
                break;
            }

            Con = (SND_MIXER_CONNECTION*) HeapAlloc(GetProcessHeap(),
                            HEAP_ZERO_MEMORY,
                            sizeof(SND_MIXER_CONNECTION));
            if (Con != NULL)
            {
                Con->Info = LineInfo;
                Con->Controls = Controls;
                Con->DisplayControls = DispControls;
                Con->Next = Line->Connections;
                Line->Connections = Con;
            }
            else
            {
                HeapFree(GetProcessHeap(),
                         0,
                         Controls);
            }
        }
        else
        {
            DPRINT("Failed to get connection information: %d\n", Result);
            Ret = FALSE;
            break;
        }
    }

    return Ret;
}

__attribute__((used)) static BOOL
SndMixerQueryDestinations(PSND_MIXER Mixer)
{
    UINT i;
    BOOL Ret = TRUE;

    for (i = Mixer->Caps.cDestinations; i > 0; i--)
    {
        PSND_MIXER_DESTINATION Line;

        Line = (SND_MIXER_DESTINATION*) HeapAlloc(GetProcessHeap(),
                         HEAP_ZERO_MEMORY,
                         sizeof(SND_MIXER_DESTINATION));
        if (Line != NULL)
        {
            Line->Info.cbStruct = sizeof(Line->Info);
            Line->Info.dwDestination = i - 1;
            if (mixerGetLineInfo((HMIXEROBJ)Mixer->hmx,
                                 &Line->Info,
                                 MIXER_GETLINEINFOF_DESTINATION) == MMSYSERR_NOERROR)
            {
                DPRINT("+ Destination: %ws (0x%x, %d)\n", Line->Info.szName, Line->Info.dwLineID, Line->Info.dwComponentType);

                if (!SndMixerQueryControls(Mixer,
                                           &Line->DisplayControls,
                                           &Line->Info,
                                           &Line->Controls))
                {
                    DPRINT("Failed to query mixer controls!\n");
                    Ret = FALSE;
                    break;
                }

                if (!SndMixerQueryConnections(Mixer, Line))
                {
                    DPRINT("Failed to query mixer connections!\n");
                    Ret = FALSE;
                    break;
                }

                Line->Next = Mixer->Lines;
                Mixer->Lines = Line;
            }
            else
            {
                DPRINT("Failed to get line information for id %d!\n", i);
                HeapFree(GetProcessHeap(),
                         0,
                         Line);
                Ret = FALSE;
                break;
            }
        }
        else
        {
            DPRINT("Allocation of SND_MIXER_DEST structure for id %d failed!\n", i);
            Ret = FALSE;
            break;
        }
    }

    return Ret;
}

BOOL
SndMixerSelect(PSND_MIXER Mixer,
               UINT MixerId)
{
    if (MixerId >= Mixer->MixersCount)
    {
        return FALSE;
    }

    SndMixerClose(Mixer);

    if (mixerOpen(&Mixer->hmx,
                  MixerId,
                  (DWORD_PTR)Mixer->hWndNotification,
                  0,
                  CALLBACK_WINDOW | MIXER_OBJECTF_MIXER) == MMSYSERR_NOERROR ||
        mixerOpen(&Mixer->hmx,
                  MixerId,
                  (DWORD_PTR)Mixer->hWndNotification,
                  0,
                  CALLBACK_WINDOW) == MMSYSERR_NOERROR ||
        mixerOpen(&Mixer->hmx,
                  MixerId,
                  0,
                  0,
                  0) == MMSYSERR_NOERROR)
    {
        if (mixerGetDevCaps(MixerId,
                            &Mixer->Caps,
                            sizeof(Mixer->Caps)) == MMSYSERR_NOERROR)
        {
            BOOL Ret = FALSE;

            Mixer->MixerId = MixerId;

            ClearMixerCache(Mixer);

            Ret = SndMixerQueryDestinations(Mixer);

            if (!Ret)
            {
                ClearMixerCache(Mixer);
            }

            return Ret;
        }
        else
        {
            mixerClose(Mixer->hmx);
        }
    }

    Mixer->hmx = NULL;
    Mixer->MixerId = NO_MIXER_SELECTED;
    return FALSE;
}

UINT
SndMixerGetSelection(PSND_MIXER Mixer)
{
    return Mixer->MixerId;
}

INT
SndMixerGetProductName(PSND_MIXER Mixer,
                       LPTSTR lpBuffer,
                       UINT uSize)
{
    if (Mixer->hmx)
    {
        UINT lnsz = (UINT) lstrlen(Mixer->Caps.szPname);
        if(lnsz + 1 > uSize)
        {
            return lnsz + 1;
        }
        else
        {
            memcpy(lpBuffer, Mixer->Caps.szPname, lnsz * sizeof(TCHAR));
            lpBuffer[lnsz] = _T('\0');
            return lnsz;
        }
    }

    return -1;
}

INT
SndMixerGetLineName(PSND_MIXER Mixer,
                    DWORD LineID,
                    LPTSTR lpBuffer,
                    UINT uSize,
                    BOOL LongName)
{
    if (Mixer->hmx)
    {
        UINT lnsz;
        PSND_MIXER_DESTINATION Line;
        LPMIXERLINE lpl = NULL;

        for (Line = Mixer->Lines; Line != NULL; Line = Line->Next)
        {
            if (Line->Info.dwLineID == LineID)
            {
                lpl = &Line->Info;
                break;
            }
        }

        if (lpl != NULL)
        {
            lnsz = (UINT) lstrlen(LongName ? lpl->szName : lpl->szShortName);
            if(lnsz + 1 > uSize)
            {
                return lnsz + 1;
            }
            else
            {
                memcpy(lpBuffer, LongName ? lpl->szName : lpl->szShortName, lnsz * sizeof(TCHAR));
                lpBuffer[lnsz] = _T('\0');
                return lnsz;
            }
        }
    }

    return -1;
}

BOOL
SndMixerEnumProducts(PSND_MIXER Mixer,
                     PFNSNDMIXENUMPRODUCTS EnumProc,
                     PVOID Context)
{
    MIXERCAPS Caps;
    HMIXER hMixer;
    UINT i;
    BOOL Ret = TRUE;

    for (i = 0; i < Mixer->MixersCount; i++)
    {
        if (mixerOpen(&hMixer,
                      i,
                      0,
                      0,
                      0) == MMSYSERR_NOERROR)
        {
            if (mixerGetDevCaps(i,
                                &Caps,
                                sizeof(Caps)) == MMSYSERR_NOERROR)
            {
                if (!EnumProc(Mixer,
                              i,
                              Caps.szPname,
                              Context))
                {
                    mixerClose(hMixer);
                    Ret = FALSE;
                    break;
                }
            }
            else
            {
                DPRINT("Failed to get device capabilities for mixer id %d!\n", i);
            }
            mixerClose(hMixer);
        }
    }

    return Ret;
}

INT
SndMixerSetVolumeControlDetails(PSND_MIXER Mixer, DWORD dwControlID, DWORD cChannels, DWORD cbDetails, LPVOID paDetails)
{
    MIXERCONTROLDETAILS MixerDetails;

    if (Mixer->hmx)
    {
        MixerDetails.cbStruct = sizeof(MIXERCONTROLDETAILS);
        MixerDetails.dwControlID = dwControlID;
        MixerDetails.cChannels = cChannels;
        MixerDetails.cMultipleItems = 0;
        MixerDetails.cbDetails = cbDetails;
        MixerDetails.paDetails = paDetails;

        if (mixerSetControlDetails((HMIXEROBJ)Mixer->hmx, &MixerDetails, MIXER_SETCONTROLDETAILSF_VALUE | MIXER_OBJECTF_HMIXER) == MMSYSERR_NOERROR)
        {
            return 1;
        }
    }

    return -1;
}

INT
SndMixerGetVolumeControlDetails(PSND_MIXER Mixer, DWORD dwControlID, DWORD cChannels, DWORD cbDetails, LPVOID paDetails)
{
    MIXERCONTROLDETAILS MixerDetails;

    if (Mixer->hmx)
    {
        MixerDetails.cbStruct = sizeof(MIXERCONTROLDETAILS);
        MixerDetails.dwControlID = dwControlID;
        MixerDetails.cChannels = cChannels;
        MixerDetails.cMultipleItems = 0;
        MixerDetails.cbDetails = cbDetails;
        MixerDetails.paDetails = paDetails;

        if (mixerGetControlDetails((HMIXEROBJ)Mixer->hmx, &MixerDetails, MIXER_GETCONTROLDETAILSF_VALUE | MIXER_OBJECTF_HMIXER) == MMSYSERR_NOERROR)
        {
            return 1;
        }
    }
    return -1;
}

INT
SndMixerGetDestinationCount(PSND_MIXER Mixer)
{
    return (Mixer->hmx ? (INT)Mixer->Caps.cDestinations : -1);
}

BOOL
SndMixerEnumLines(PSND_MIXER Mixer,
                  PFNSNDMIXENUMLINES EnumProc,
                  PVOID Context)
{
    if (Mixer->hmx)
    {
        PSND_MIXER_DESTINATION Line;

        for (Line = Mixer->Lines; Line != NULL; Line = Line->Next)
        {
            if (!EnumProc(Mixer,
                          &Line->Info,
                          Line->DisplayControls,
                          Context))
            {
                return FALSE;
            }
        }

        return TRUE;
    }

    return FALSE;
}

BOOL
SndMixerEnumConnections(PSND_MIXER Mixer,
                        DWORD LineID,
                        PFNSNDMIXENUMCONNECTIONS EnumProc,
                        PVOID Context)
{
    if (Mixer->hmx)
    {
        PSND_MIXER_DESTINATION Line;

        for (Line = Mixer->Lines; Line != NULL; Line = Line->Next)
        {
            if (Line->Info.dwLineID == LineID)
            {
                PSND_MIXER_CONNECTION Connection;

                if (Line->DisplayControls != 0)
                {
                    if (!EnumProc(Mixer,
                                  LineID,
                                  &Line->Info,
                                  Context))
                    {
                        return FALSE;
                    }
                }

                for (Connection = Line->Connections; Connection != NULL; Connection = Connection->Next)
                {
                    if (!EnumProc(Mixer,
                                  LineID,
                                  &Connection->Info,
                                  Context))
                    {
                        return FALSE;
                    }
                }

                return TRUE;
            }
        }
    }

    return FALSE;
}

BOOL
SndMixerIsDisplayControl(PSND_MIXER Mixer,
                         LPMIXERCONTROL Control)
{
    if (Mixer->hmx && !(Control->fdwControl & MIXERCONTROL_CONTROLF_DISABLED))
    {
        switch (Control->dwControlType & MIXERCONTROL_CT_CLASS_MASK)
        {
            case MIXERCONTROL_CT_CLASS_FADER:
            case MIXERCONTROL_CT_CLASS_SWITCH:
                return TRUE;
        }
    }

    return FALSE;
}

LPMIXERLINE
SndMixerGetLineByName(PSND_MIXER Mixer,
                      DWORD LineID,
                      LPWSTR LineName)
{
    PSND_MIXER_DESTINATION Line;
    PSND_MIXER_CONNECTION Connection;

    if (Mixer->hmx == 0)
        return NULL;

    for (Line = Mixer->Lines; Line != NULL; Line = Line->Next)
    {
        if (Line->Info.dwLineID == LineID)
        {
            if (Line->DisplayControls != 0)
            {
                if (wcsicmp(Line->Info.szName, LineName) == 0)
                {
                    return &Line->Info;
                }
            }

            for (Connection = Line->Connections; Connection != NULL; Connection = Connection->Next)
            {
                if (wcsicmp(Connection->Info.szName, LineName) == 0)
                {
                    return &Connection->Info;
                }
            }

            return NULL;
        }
    }

    return NULL;
}

