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
typedef  int /*<<< orphan*/  unknown ;
struct promptdisk_params {int DiskPromptStyle; int* PathRequiredSize; int PathBufferSize; scalar_t__* FileSought; scalar_t__* PathBuffer; scalar_t__ DiskName; scalar_t__* PathToSource; scalar_t__ DialogTitle; } ;
typedef  int /*<<< orphan*/  ofn ;
typedef  int /*<<< orphan*/  message ;
typedef  int /*<<< orphan*/  format ;
typedef  int /*<<< orphan*/  __ms_va_list ;
typedef  scalar_t__ WCHAR ;
struct TYPE_4__ {int lStructSize; int Flags; int nMaxFile; scalar_t__* lpstrFile; int /*<<< orphan*/  hwndOwner; } ;
typedef  TYPE_1__ OPENFILENAMEW ;
typedef  int /*<<< orphan*/  LONG_PTR ;
typedef  int /*<<< orphan*/  HWND ;
typedef  scalar_t__ DWORD_PTR ;
typedef  int DWORD ;

/* Variables and functions */
 int /*<<< orphan*/  CP_ACP ; 
 int /*<<< orphan*/  DPROMPT_BUFFERTOOSMALL ; 
 int /*<<< orphan*/  DPROMPT_SUCCESS ; 
 int /*<<< orphan*/  DWLP_USER ; 
 int /*<<< orphan*/  EndDialog (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int FORMAT_MESSAGE_ARGUMENT_ARRAY ; 
 int FORMAT_MESSAGE_FROM_STRING ; 
 int /*<<< orphan*/  FormatMessageW (int,scalar_t__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  GetDlgItem (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ GetOpenFileNameW (TYPE_1__*) ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 int /*<<< orphan*/  GetWindowTextW (int /*<<< orphan*/ ,scalar_t__*,int) ; 
 void* HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__*) ; 
 int /*<<< orphan*/  IDC_COPYFROM ; 
 int /*<<< orphan*/  IDC_FILENEEDED ; 
 int /*<<< orphan*/  IDC_INFO ; 
 int /*<<< orphan*/  IDC_PATH ; 
 int /*<<< orphan*/  IDC_RUNDLG_BROWSE ; 
 int IDF_NOBROWSE ; 
 int IDF_OEMDISK ; 
 int /*<<< orphan*/  IDS_COPYFROM ; 
 int /*<<< orphan*/  IDS_INFO ; 
 int /*<<< orphan*/  IDS_PROMPTDISK ; 
 int /*<<< orphan*/  IDS_UNKNOWN ; 
 int /*<<< orphan*/  LoadStringW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__*,int) ; 
 int MAX_PATH ; 
 int MultiByteToWideChar (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*,int,scalar_t__*,int) ; 
 int /*<<< orphan*/  NO_ERROR ; 
 int OFN_FILEMUSTEXIST ; 
 int OFN_HIDEREADONLY ; 
 int OFN_PATHMUSTEXIST ; 
 int /*<<< orphan*/  SW_HIDE ; 
 int /*<<< orphan*/  SetDlgItemTextW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__*) ; 
 int /*<<< orphan*/  SetWindowLongPtrW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SetWindowTextW (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  ShowWindow (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TRACE (char*,int) ; 
 int /*<<< orphan*/  ZeroMemory (TYPE_1__*,int) ; 
 int debugstr_w (scalar_t__*) ; 
 int /*<<< orphan*/  hInstance ; 
 int /*<<< orphan*/  strcpyW (scalar_t__*,scalar_t__*) ; 
 int strlenW (scalar_t__*) ; 
 scalar_t__* strrchrW (scalar_t__*,char) ; 

__attribute__((used)) inline static WCHAR *strdupAtoW( const char *str )
{
    WCHAR *ret = NULL;
    if (str)
    {
        DWORD len = MultiByteToWideChar( CP_ACP, 0, str, -1, NULL, 0 );
        if ((ret = HeapAlloc( GetProcessHeap(), 0, len * sizeof(WCHAR) )))
            MultiByteToWideChar( CP_ACP, 0, str, -1, ret, len );
    }
    return ret;
}

__attribute__((used)) static void promptdisk_init(HWND hwnd, struct promptdisk_params *params)
{
    SetWindowLongPtrW(hwnd, DWLP_USER, (LONG_PTR)params);

    if(params->DialogTitle)
        SetWindowTextW(hwnd, params->DialogTitle);
    if(params->PathToSource)
        SetDlgItemTextW(hwnd, IDC_PATH, params->PathToSource);

    if(!(params->DiskPromptStyle & IDF_OEMDISK))
    {
        WCHAR message[256+2*MAX_PATH];
        WCHAR format[256];
        WCHAR unknown[256];
        DWORD_PTR args[2];
        LoadStringW(hInstance, IDS_PROMPTDISK, format,
            sizeof(format)/sizeof(format[0]));

        args[0] = (DWORD_PTR)params->FileSought;
        if(params->DiskName)
            args[1] = (DWORD_PTR)params->DiskName;
        else
        {
            LoadStringW(hInstance, IDS_UNKNOWN, unknown,
                sizeof(unknown)/sizeof(unknown[0]));
            args[1] = (DWORD_PTR)unknown;
        }
        FormatMessageW(FORMAT_MESSAGE_FROM_STRING|FORMAT_MESSAGE_ARGUMENT_ARRAY,
                       format, 0, 0, message, sizeof(message)/sizeof(*message),
                       (__ms_va_list*)args);
        SetDlgItemTextW(hwnd, IDC_FILENEEDED, message);

        LoadStringW(hInstance, IDS_INFO, message,
            sizeof(message)/sizeof(message[0]));
        SetDlgItemTextW(hwnd, IDC_INFO, message);
        LoadStringW(hInstance, IDS_COPYFROM, message,
            sizeof(message)/sizeof(message[0]));
        SetDlgItemTextW(hwnd, IDC_COPYFROM, message);
    }
    if(params->DiskPromptStyle & IDF_NOBROWSE)
        ShowWindow(GetDlgItem(hwnd, IDC_RUNDLG_BROWSE), SW_HIDE);
}

__attribute__((used)) static void promptdisk_ok(HWND hwnd, struct promptdisk_params *params)
{
    int requiredSize;
    WCHAR aux[MAX_PATH];
    GetWindowTextW(GetDlgItem(hwnd, IDC_PATH), aux, MAX_PATH);
    requiredSize = strlenW(aux)+1;

    if(params->PathRequiredSize)
    {
        *params->PathRequiredSize = requiredSize;
        TRACE("returning PathRequiredSize=%d\n",*params->PathRequiredSize);
    }
    if(!params->PathBuffer)
    {
        EndDialog(hwnd, NO_ERROR);
        return;
    }
    if(requiredSize > params->PathBufferSize)
    {
        EndDialog(hwnd, DPROMPT_BUFFERTOOSMALL);
        return;
    }
    strcpyW(params->PathBuffer, aux);
    TRACE("returning PathBuffer=%s\n", debugstr_w(params->PathBuffer));
    EndDialog(hwnd, DPROMPT_SUCCESS);
}

__attribute__((used)) static void promptdisk_browse(HWND hwnd, struct promptdisk_params *params)
{
    OPENFILENAMEW ofn;
    ZeroMemory(&ofn, sizeof(ofn));

    ofn.lStructSize = sizeof(ofn);
    ofn.Flags = OFN_HIDEREADONLY | OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
    ofn.hwndOwner = hwnd;
    ofn.nMaxFile = MAX_PATH;
    ofn.lpstrFile = HeapAlloc(GetProcessHeap(), 0, MAX_PATH*sizeof(WCHAR));
    strcpyW(ofn.lpstrFile, params->FileSought);

    if(GetOpenFileNameW(&ofn))
    {
        WCHAR* last_slash = strrchrW(ofn.lpstrFile, '\\');
        if (last_slash) *last_slash = 0;
        SetDlgItemTextW(hwnd, IDC_PATH, ofn.lpstrFile);
    }
    HeapFree(GetProcessHeap(), 0, ofn.lpstrFile);
}

