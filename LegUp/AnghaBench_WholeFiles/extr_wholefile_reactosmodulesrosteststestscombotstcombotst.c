#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  WPARAM ;
typedef  int /*<<< orphan*/  VOID ;
struct TYPE_7__ {int /*<<< orphan*/  Code; } ;
struct TYPE_6__ {unsigned int top; unsigned int bottom; unsigned int left; unsigned int right; } ;
typedef  TYPE_1__ RECT ;
typedef  scalar_t__ LRESULT ;
typedef  scalar_t__ LPARAM ;
typedef  int /*<<< orphan*/  HWND ;
typedef  int /*<<< orphan*/  HDC ;
typedef  int DWORD ;

/* Variables and functions */
 int BM_GETCHECK ; 
 scalar_t__ BST_CHECKED ; 
 int BS_AUTOCHECKBOX ; 
 int BS_PUSHBUTTON ; 
 int BUFFERLEN ; 
 int /*<<< orphan*/  Back1But ; 
 int /*<<< orphan*/  Back2But ; 
 int /*<<< orphan*/ * Buttons ; 
 int /*<<< orphan*/  ComboStyle ; 
 int /*<<< orphan*/  CreateWindow (char*,char const*,int,int /*<<< orphan*/ ,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CreateWindowEx (int /*<<< orphan*/ ,char*,char const*,int,int /*<<< orphan*/ ,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DestroyWindow (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetDC (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetStockObject (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetWindowRect (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  LongToHandle (int) ; 
 int MAXMESSAGEBUTTONS ; 
 int /*<<< orphan*/ * MessageButtons ; 
 int NUMBERBUTTONS ; 
 int NUMBERCHECKS ; 
 int /*<<< orphan*/  NextBut ; 
 int /*<<< orphan*/  ReleaseDC (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int ResultX ; 
 int ResultY ; 
 int /*<<< orphan*/  SW_HIDE ; 
 int /*<<< orphan*/  SW_SHOW ; 
 int /*<<< orphan*/  SYSTEM_FIXED_FONT ; 
 int /*<<< orphan*/  SelectObject (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ SendMessage (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  ShowWindow (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_3__* Styles ; 
 char* TextBuffer ; 
 int /*<<< orphan*/  TextOut (int /*<<< orphan*/ ,int,int,char*,int) ; 
 int /*<<< orphan*/  UlongToHandle (int) ; 
 int /*<<< orphan*/  ValidateRect (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int WS_CHILD ; 
 int WS_VISIBLE ; 
 int /*<<< orphan*/  g_hInst ; 
 int /*<<< orphan*/  g_hwnd ; 
 int /*<<< orphan*/  htoa (unsigned int,char*) ; 
 int /*<<< orphan*/  hwndEdit ; 
 int /*<<< orphan*/  xButPos ; 
 int yButPos ; 

void PrintTextXY(char* Text,int x,int y,int len, RECT rect)
    {
    HDC hdc;
    hdc = GetDC (g_hwnd);
    SelectObject (hdc, GetStockObject (SYSTEM_FIXED_FONT));

    TextOut (hdc, x,y,Text,len);
    ReleaseDC (g_hwnd, hdc);

    ValidateRect (g_hwnd, &rect);
    }

__attribute__((used)) static
VOID
HandlePrintReturnHex(HWND handle,DWORD Msg,WPARAM wParam,LPARAM lParam)
    {
    LRESULT ret;
    RECT rect;
    ret = SendMessage(handle,Msg,wParam,lParam);
    htoa((unsigned int)ret,&TextBuffer[8]);
    GetWindowRect(g_hwnd,&rect);
    PrintTextXY(TextBuffer,ResultX,ResultY,16,rect);
    }

__attribute__((used)) static
VOID
HandlePrintReturnStr(HWND handle,DWORD Msg,WPARAM wParam,LPARAM lParam)
    {
    LRESULT ret;
    RECT rect;

    TextBuffer[8] = (char)(BUFFERLEN - 8); /* Setting the max size to put chars in first byte */
    ret = SendMessage(handle,Msg,wParam,lParam);
    GetWindowRect(g_hwnd,&rect);
    PrintTextXY(TextBuffer,ResultX,ResultY,8+(int)ret,rect);
    }

__attribute__((used)) static
VOID
HandlePrintRect(HWND handle,DWORD Msg,WPARAM wParam,LPARAM lParam)
    {
    RECT rect = *(RECT*)lParam;
    TextBuffer[8] = (char)(BUFFERLEN - 8); /* Setting the max size to put chars in first byte */
    SendMessage(handle,Msg,wParam,lParam);

    htoa(rect.top,&TextBuffer[8]);
    TextBuffer[8+8] = ' ';
    htoa(rect.bottom,&TextBuffer[8+8+1]);
    TextBuffer[8+8+8+1] = ' ';
    htoa(rect.left,&TextBuffer[8+8+8+1+1]);
    TextBuffer[8+8+8+8+1+1] = ' ';
    htoa(rect.right,&TextBuffer[8+8+8+8+1+1+1]);

    GetWindowRect(g_hwnd,&rect);
    PrintTextXY(TextBuffer,ResultX,ResultY,8+4*9-1,rect);
    }

HWND
CreateCheckButton(const char* lpWindowName, DWORD xSize, DWORD id)
    {
    HWND h;
    h  = CreateWindowEx(0,
        "BUTTON",
        lpWindowName,
        WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
        xButPos, /*  x  */
        yButPos, /*  y  */
        xSize,   /* nWidth  */
        20,      /* nHeight */
        g_hwnd,
        UlongToHandle(id),
        g_hInst,
        NULL
        );
    yButPos += 21;
    return h;
    }

HWND
CreatePushButton(const char* lpWindowName, DWORD xSize, DWORD id,DWORD Style)
    {

    HWND h = CreateWindow("BUTTON",
        lpWindowName,
        WS_CHILD | BS_PUSHBUTTON | Style,
        xButPos, /* x */
        yButPos, /* y */
        xSize,   /* nWidth */
        20,      /* nHeight */
        g_hwnd,
        LongToHandle(id),
        g_hInst,
        NULL
        );

    yButPos += 21;
    return h;
    }

VOID
ReadNHide()
    {
    int i;
    ComboStyle = 0;
    for (i=0 ; i< NUMBERCHECKS ; i++)
        {
        if(BST_CHECKED == SendMessage(Buttons[i],BM_GETCHECK,0,0))
            ComboStyle |= Styles[i].Code;
        ShowWindow(Buttons[i],SW_HIDE);
        }

    for (; i< NUMBERBUTTONS ; i++)ShowWindow(Buttons[i],SW_HIDE);
    for (i=0 ; i< 26 ; i++) ShowWindow(MessageButtons[i],SW_SHOW);

    ShowWindow(Back1But,SW_SHOW);
    ShowWindow(NextBut,SW_SHOW);
    }

VOID
ForwardToSecondPage()
    {
    int i;
    for (i=0;i<26;i++)ShowWindow(MessageButtons[i],SW_HIDE);
    for(;i<MAXMESSAGEBUTTONS;i++)ShowWindow(MessageButtons[i],SW_SHOW);
    ShowWindow(Back2But,SW_SHOW);

    ShowWindow(Back1But,SW_HIDE);
    ShowWindow(NextBut,SW_HIDE);
    }

VOID
BackToFirstPage()
    {
    int i;
    for (i=0;i<26;i++)ShowWindow(MessageButtons[i],SW_SHOW);
    for(;i<MAXMESSAGEBUTTONS;i++)ShowWindow(MessageButtons[i],SW_HIDE);
    ShowWindow(Back2But,SW_HIDE);
    ShowWindow(Back1But,SW_SHOW);
    ShowWindow(NextBut,SW_SHOW);
    }

VOID
BackToInitialPage()
    {
    int i;
    DestroyWindow(hwndEdit);
    for (i=0 ; i< NUMBERBUTTONS ; i++) {ShowWindow(Buttons[i],SW_SHOW);}
for (i=0;i<26;i++)ShowWindow(MessageButtons[i],SW_HIDE);
ShowWindow(Back1But,SW_HIDE);
ShowWindow(NextBut,SW_HIDE);
    }

