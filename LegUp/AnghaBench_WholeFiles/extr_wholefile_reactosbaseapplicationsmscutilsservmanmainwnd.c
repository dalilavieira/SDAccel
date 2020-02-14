#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_5__ ;
typedef  struct TYPE_16__   TYPE_4__ ;
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ WPARAM ;
typedef  scalar_t__ WORD ;
typedef  int /*<<< orphan*/  WCHAR ;
typedef  int /*<<< orphan*/  VOID ;
typedef  scalar_t__ UINT ;
struct TYPE_17__ {scalar_t__ dwStartType; } ;
struct TYPE_16__ {scalar_t__ CmdId; scalar_t__ HintId; } ;
struct TYPE_15__ {scalar_t__ SelectedItem; int /*<<< orphan*/ * hTool; int /*<<< orphan*/  hShortcutMenu; TYPE_2__* pCurrentService; scalar_t__ bIsUserAnAdmin; int /*<<< orphan*/  hMainWnd; int /*<<< orphan*/ * hStatus; int /*<<< orphan*/  hListView; scalar_t__ bInMenuLoop; } ;
struct TYPE_13__ {int dwControlsAccepted; int dwCurrentState; } ;
struct TYPE_14__ {int /*<<< orphan*/  lpServiceName; TYPE_1__ ServiceStatusProcess; } ;
typedef  TYPE_3__* PMAIN_WND_INFO ;
typedef  TYPE_4__ MENU_HINT ;
typedef  int /*<<< orphan*/  LPWSTR ;
typedef  TYPE_5__* LPQUERY_SERVICE_CONFIG ;
typedef  int /*<<< orphan*/  LPARAM ;
typedef  int /*<<< orphan*/  INT ;
typedef  int /*<<< orphan*/  HMENU ;
typedef  int DWORD ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 scalar_t__ AllocAndLoadString (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  EnableMenuItem (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  GetMenu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 TYPE_5__* GetServiceConfig (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetSubMenu (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_5__*) ; 
 int /*<<< orphan*/  IDS_NUM_SERVICES ; 
 scalar_t__ ID_DELETE ; 
 scalar_t__ ID_PAUSE ; 
 scalar_t__ ID_PROP ; 
 scalar_t__ ID_RESTART ; 
 scalar_t__ ID_START ; 
 scalar_t__ ID_STOP ; 
 int /*<<< orphan*/  ListView_GetItemCount (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LocalFree (int /*<<< orphan*/ ) ; 
 scalar_t__ MAKELONG (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MF_ENABLED ; 
 int /*<<< orphan*/  MF_GRAYED ; 
 scalar_t__ NO_ITEM_SELECTED ; 
 int /*<<< orphan*/  SB_SETTEXT ; 
 int /*<<< orphan*/  SB_SIMPLE ; 
 int /*<<< orphan*/  SB_SIMPLEID ; 
 int SERVICE_ACCEPT_PAUSE_CONTINUE ; 
 int SERVICE_ACCEPT_STOP ; 
 scalar_t__ SERVICE_DISABLED ; 
 int SERVICE_RUNNING ; 
 int SERVICE_STOPPED ; 
 int /*<<< orphan*/  SendMessage (int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  StatusBarLoadString (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  TBSTATE_ENABLED ; 
 int /*<<< orphan*/  TBSTATE_INDETERMINATE ; 
 int /*<<< orphan*/  TB_SETSTATE ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  _snwprintf (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hInstance ; 

__attribute__((used)) static BOOL
MainWndMenuHint(PMAIN_WND_INFO Info,
                WORD CmdId,
                const MENU_HINT *HintArray,
                DWORD HintsCount,
                UINT DefHintId)
{
    BOOL Found = FALSE;
    const MENU_HINT *LastHint;
    UINT HintId = DefHintId;

    LastHint = HintArray + HintsCount;
    while (HintArray != LastHint)
    {
        if (HintArray->CmdId == CmdId)
        {
            HintId = HintArray->HintId;
            Found = TRUE;
            break;
        }
        HintArray++;
    }

    StatusBarLoadString(Info->hStatus,
                        SB_SIMPLEID,
                        hInstance,
                        HintId);

    return Found;
}

__attribute__((used)) static VOID
UpdateMainStatusBar(PMAIN_WND_INFO Info)
{
    if (Info->hStatus != NULL)
    {
        SendMessage(Info->hStatus,
                    SB_SIMPLE,
                    (WPARAM)Info->bInMenuLoop,
                    0);
    }
}

VOID
UpdateServiceCount(PMAIN_WND_INFO Info)
{
    LPWSTR lpNumServices;

    if (AllocAndLoadString(&lpNumServices,
                           hInstance,
                           IDS_NUM_SERVICES))
    {
        WCHAR szNumServices[32];

        INT NumListedServ = ListView_GetItemCount(Info->hListView);

        _snwprintf(szNumServices,
                   31,
                   lpNumServices,
                   NumListedServ);

        SendMessage(Info->hStatus,
                    SB_SETTEXT,
                    0,
                    (LPARAM)szNumServices);

        LocalFree(lpNumServices);
    }
}

VOID SetMenuAndButtonStates(PMAIN_WND_INFO Info)
{
    HMENU hMainMenu;
    UINT i;

    /* get handle to menu */
    hMainMenu = GetMenu(Info->hMainWnd);

    /* set all to greyed */
    for (i = ID_START; i <= ID_RESTART; i++)
    {
        EnableMenuItem(hMainMenu, i, MF_GRAYED);
        EnableMenuItem(GetSubMenu(Info->hShortcutMenu, 0), i, MF_GRAYED);
        SendMessage(Info->hTool, TB_SETSTATE, i,
                    (LPARAM)MAKELONG(TBSTATE_INDETERMINATE, 0));
    }

    if (Info->SelectedItem != NO_ITEM_SELECTED)
    {
        LPQUERY_SERVICE_CONFIG lpServiceConfig = NULL;
        DWORD Flags, State;

        /* allow user to delete service */
        if (Info->bIsUserAnAdmin)
        {
            SendMessage(Info->hTool, TB_SETSTATE, ID_DELETE,
                       (LPARAM)MAKELONG(TBSTATE_ENABLED, 0));
            EnableMenuItem(hMainMenu, ID_DELETE, MF_ENABLED);
            EnableMenuItem(GetSubMenu(Info->hShortcutMenu, 0), ID_DELETE, MF_ENABLED);
        }

        Flags = Info->pCurrentService->ServiceStatusProcess.dwControlsAccepted;
        State = Info->pCurrentService->ServiceStatusProcess.dwCurrentState;

        lpServiceConfig = GetServiceConfig(Info->pCurrentService->lpServiceName);

        if (lpServiceConfig && lpServiceConfig->dwStartType != SERVICE_DISABLED)
        {
            if (State == SERVICE_STOPPED)
            {
                EnableMenuItem(hMainMenu, ID_START, MF_ENABLED);
                EnableMenuItem(GetSubMenu(Info->hShortcutMenu, 0), ID_START, MF_ENABLED);
                SendMessage(Info->hTool, TB_SETSTATE, ID_START,
                       (LPARAM)MAKELONG(TBSTATE_ENABLED, 0));
            }

            if ( (Flags & SERVICE_ACCEPT_STOP) && (State == SERVICE_RUNNING) )
            {
                EnableMenuItem(hMainMenu, ID_RESTART, MF_ENABLED);
                EnableMenuItem(GetSubMenu(Info->hShortcutMenu, 0), ID_RESTART, MF_ENABLED);
                SendMessage(Info->hTool, TB_SETSTATE, ID_RESTART,
                       (LPARAM)MAKELONG(TBSTATE_ENABLED, 0));
            }
        }

        if(lpServiceConfig)
            HeapFree(GetProcessHeap(), 0, lpServiceConfig);

        if ( (Flags & SERVICE_ACCEPT_STOP) && (State == SERVICE_RUNNING) )
        {
            EnableMenuItem(hMainMenu, ID_STOP, MF_ENABLED);
            EnableMenuItem(GetSubMenu(Info->hShortcutMenu, 0), ID_STOP, MF_ENABLED);
            SendMessage(Info->hTool, TB_SETSTATE, ID_STOP,
                   (LPARAM)MAKELONG(TBSTATE_ENABLED, 0));
        }

        if ( (Flags & SERVICE_ACCEPT_PAUSE_CONTINUE) && (State == SERVICE_RUNNING) )
        {
            EnableMenuItem(hMainMenu, ID_PAUSE, MF_ENABLED);
            EnableMenuItem(GetSubMenu(Info->hShortcutMenu, 0), ID_PAUSE, MF_ENABLED);
            SendMessage(Info->hTool, TB_SETSTATE, ID_PAUSE,
                   (LPARAM)MAKELONG(TBSTATE_ENABLED, 0));
        }
    }
    else
    {
        /* disable tools which rely on a selected service */
        EnableMenuItem(hMainMenu, ID_PROP, MF_GRAYED);
        EnableMenuItem(hMainMenu, ID_DELETE, MF_GRAYED);
        EnableMenuItem(GetSubMenu(Info->hShortcutMenu, 0), ID_PROP, MF_GRAYED);
        EnableMenuItem(GetSubMenu(Info->hShortcutMenu, 0), ID_DELETE, MF_GRAYED);
        SendMessage(Info->hTool, TB_SETSTATE, ID_PROP,
                   (LPARAM)MAKELONG(TBSTATE_INDETERMINATE, 0));
        SendMessage(Info->hTool, TB_SETSTATE, ID_DELETE,
                   (LPARAM)MAKELONG(TBSTATE_INDETERMINATE, 0));
    }

}

