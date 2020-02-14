#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  VOID ;
struct TYPE_10__ {int /*<<< orphan*/  dwServiceType; } ;
struct TYPE_12__ {TYPE_1__ ServiceStatus; int /*<<< orphan*/ * lpServiceName; int /*<<< orphan*/ * lpDisplayName; } ;
struct TYPE_11__ {int /*<<< orphan*/ * hDependsImageList; int /*<<< orphan*/  hDependsTreeView2; int /*<<< orphan*/  hDependsWnd; } ;
typedef  scalar_t__ SC_HANDLE ;
typedef  TYPE_2__* PDEPENDDATA ;
typedef  int /*<<< orphan*/ * LPWSTR ;
typedef  TYPE_3__* LPENUM_SERVICE_STATUSW ;
typedef  TYPE_3__* LPENUM_SERVICE_STATUS ;
typedef  size_t* LPDWORD ;
typedef  int /*<<< orphan*/ * HTREEITEM ;
typedef  scalar_t__ HANDLE ;
typedef  size_t DWORD ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  AddItemToTreeView (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AllocAndLoadString (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CloseServiceHandle (scalar_t__) ; 
 scalar_t__ ERROR_MORE_DATA ; 
 int /*<<< orphan*/  EnableWindow (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  EnumDependentServices (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,size_t*,size_t*) ; 
 scalar_t__ EnumDependentServicesW (scalar_t__,int /*<<< orphan*/ ,TYPE_3__*,size_t,size_t*,size_t*) ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  GetDlgItem (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ GetLastError () ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 scalar_t__ HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  IDC_DEPEND_TREE2 ; 
 int /*<<< orphan*/  IDS_NO_DEPENDS ; 
 int /*<<< orphan*/  ImageList_Destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  LocalFree (int /*<<< orphan*/ *) ; 
 scalar_t__ OpenSCManagerW (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ OpenServiceW (scalar_t__,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ProcessHeap ; 
 int /*<<< orphan*/  SC_MANAGER_ALL_ACCESS ; 
 int SERVICE_ENUMERATE_DEPENDENTS ; 
 int SERVICE_QUERY_CONFIG ; 
 int SERVICE_QUERY_STATUS ; 
 int /*<<< orphan*/  SERVICE_STATE_ALL ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  TVSIL_NORMAL ; 
 int /*<<< orphan*/  TreeView_SetImageList (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hInstance ; 

BOOL
TV2_HasDependantServices(LPWSTR lpServiceName)
{
    HANDLE hSCManager;
    HANDLE hService;
    DWORD dwBytesNeeded, dwCount;
    BOOL bRet = FALSE;

    hSCManager = OpenSCManagerW(NULL,
                                NULL,
                                SC_MANAGER_ALL_ACCESS);
    if (hSCManager)
    {
        hService = OpenServiceW(hSCManager,
                                lpServiceName,
                                SERVICE_QUERY_STATUS | SERVICE_ENUMERATE_DEPENDENTS);
        if (hService)
        {
            /* Does this have any dependencies? */
            if (!EnumDependentServices(hService,
                                       SERVICE_STATE_ALL,
                                       NULL,
                                       0,
                                       &dwBytesNeeded,
                                       &dwCount))
            {
                 if (GetLastError() == ERROR_MORE_DATA)
                 {
                     /* It does, return TRUE */
                     bRet = TRUE;
                 }
            }

            CloseServiceHandle(hService);
        }

        CloseServiceHandle(hSCManager);
    }

    return bRet;
}

LPENUM_SERVICE_STATUS
TV2_GetDependants(LPWSTR lpServiceName,
                  LPDWORD lpdwCount)
{
    SC_HANDLE hSCManager;
    SC_HANDLE hService;
    LPENUM_SERVICE_STATUSW lpDependencies = NULL;
    DWORD dwBytesNeeded;
    DWORD dwCount;

    /* Set the first items in each tree view */
    hSCManager = OpenSCManagerW(NULL,
                                NULL,
                                SC_MANAGER_ALL_ACCESS);
    if (hSCManager)
    {
        hService = OpenServiceW(hSCManager,
                                lpServiceName,
                                SERVICE_QUERY_STATUS | SERVICE_ENUMERATE_DEPENDENTS | SERVICE_QUERY_CONFIG);
        if (hService)
        {
            /* Does this have any dependencies? */
            if (!EnumDependentServicesW(hService,
                                        SERVICE_STATE_ALL,
                                        NULL,
                                        0,
                                        &dwBytesNeeded,
                                        &dwCount) &&
                GetLastError() == ERROR_MORE_DATA)
            {
                lpDependencies = (LPENUM_SERVICE_STATUSW)HeapAlloc(GetProcessHeap(),
                                                                  0,
                                                                  dwBytesNeeded);
                if (lpDependencies)
                {
                    /* Get the list of dependents */
                    if (EnumDependentServicesW(hService,
                                               SERVICE_STATE_ALL,
                                               lpDependencies,
                                               dwBytesNeeded,
                                               &dwBytesNeeded,
                                               &dwCount))
                    {
                        /* Set the count */
                        *lpdwCount = dwCount;
                    }
                    else
                    {
                        HeapFree(ProcessHeap,
                                 0,
                                 lpDependencies);

                        lpDependencies = NULL;
                    }
                }
            }

            CloseServiceHandle(hService);
        }

        CloseServiceHandle(hSCManager);
    }

    return lpDependencies;
}

VOID
TV2_AddDependantsToTree(PDEPENDDATA pDependData,
                        HTREEITEM hParent,
                        LPWSTR lpServiceName)
{

    LPENUM_SERVICE_STATUSW lpServiceStatus;
    LPWSTR lpNoDepends;
    DWORD count, i;
    BOOL bHasChildren;

    /* Get a list of service dependents */
    lpServiceStatus = TV2_GetDependants(lpServiceName, &count);
    if (lpServiceStatus)
    {
        for (i = 0; i < count; i++)
        {
            /* Does this item need a +/- box? */
            bHasChildren = TV2_HasDependantServices(lpServiceStatus[i].lpServiceName);

            /* Add it */
            AddItemToTreeView(pDependData->hDependsTreeView2,
                              hParent,
                              lpServiceStatus[i].lpDisplayName,
                              lpServiceStatus[i].lpServiceName,
                              lpServiceStatus[i].ServiceStatus.dwServiceType,
                              bHasChildren);
        }

        HeapFree(GetProcessHeap(),
                 0,
                 lpServiceStatus);
    }
    else
    {
        /* If there is no parent, set the tree to 'no dependencies' */
        if (!hParent)
        {
            /* Load the 'No dependencies' string */
            AllocAndLoadString(&lpNoDepends, hInstance, IDS_NO_DEPENDS);

            AddItemToTreeView(pDependData->hDependsTreeView2,
                              NULL,
                              lpNoDepends,
                              NULL,
                              0,
                              FALSE);

            LocalFree(lpNoDepends);

            /* Disable the window */
            EnableWindow(pDependData->hDependsTreeView2, FALSE);
        }
    }
}

BOOL
TV2_Initialize(PDEPENDDATA pDependData,
               LPWSTR lpServiceName)
{
    BOOL bRet = FALSE;

    /* Associate the imagelist with TV2 */
    pDependData->hDependsTreeView2 = GetDlgItem(pDependData->hDependsWnd, IDC_DEPEND_TREE2);
    if (!pDependData->hDependsTreeView2)
    {
        ImageList_Destroy(pDependData->hDependsImageList);
        pDependData->hDependsImageList = NULL;
        return FALSE;
    }
    (void)TreeView_SetImageList(pDependData->hDependsTreeView2,
                                pDependData->hDependsImageList,
                                TVSIL_NORMAL);

    /* Set the first items in the control */
    TV2_AddDependantsToTree(pDependData, NULL, lpServiceName);

    return bRet;
}

