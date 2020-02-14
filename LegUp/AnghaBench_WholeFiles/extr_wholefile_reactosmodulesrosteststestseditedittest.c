#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  wchar_t ;
typedef  int /*<<< orphan*/  WPARAM ;
typedef  int /*<<< orphan*/  VOID ;
typedef  scalar_t__ ULONG_PTR ;
struct TYPE_3__ {int top; int bottom; int left; int right; } ;
typedef  scalar_t__ LPVOID ;
typedef  long LPARAM ;
typedef  int /*<<< orphan*/  HWND ;
typedef  int /*<<< orphan*/  HMENU ;
typedef  int /*<<< orphan*/  HLOCAL ;
typedef  int /*<<< orphan*/  HDC ;
typedef  scalar_t__ HANDLE ;
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
 int /*<<< orphan*/  CreateWindow (char*,char const*,int,int /*<<< orphan*/ ,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CreateWindowEx (int /*<<< orphan*/ ,char*,char const*,int,int /*<<< orphan*/ ,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DestroyWindow (int /*<<< orphan*/ ) ; 
 int EM_GETHANDLE ; 
 int EM_SETHANDLE ; 
 int /*<<< orphan*/  EditStyle ; 
 int /*<<< orphan*/ * EditStyles ; 
 int /*<<< orphan*/  GetDC (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetStockObject (int /*<<< orphan*/ ) ; 
 int LMEM_MOVEABLE ; 
 int LMEM_ZEROINIT ; 
 scalar_t__ LocalAlloc (int,int) ; 
 int /*<<< orphan*/  LocalFree (int /*<<< orphan*/ ) ; 
 scalar_t__ LocalHandle (scalar_t__) ; 
 scalar_t__ LocalLock (scalar_t__) ; 
 int /*<<< orphan*/  LocalUnlock (scalar_t__) ; 
 int MAXMESSAGEBUTTONS ; 
 int /*<<< orphan*/ * MessageButtons ; 
 int NUMBERBUTTONS ; 
 int /*<<< orphan*/  NewText ; 
 int /*<<< orphan*/  NewTextW ; 
 int /*<<< orphan*/  NextBut ; 
 int /*<<< orphan*/  ReleaseDC (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int ResultX ; 
 int ResultY ; 
 int /*<<< orphan*/  SW_HIDE ; 
 int /*<<< orphan*/  SW_SHOW ; 
 int /*<<< orphan*/  SYSTEM_FIXED_FONT ; 
 int /*<<< orphan*/  SelectObject (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ SendMessage (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,long) ; 
 int /*<<< orphan*/  ShowWindow (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 char* TextBuffer ; 
 int /*<<< orphan*/  TextOut (int /*<<< orphan*/ ,int,int,char*,int) ; 
 int /*<<< orphan*/  UlongToHandle (int) ; 
 scalar_t__ UnicodeUsed ; 
 int /*<<< orphan*/  ValidateRect (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int WS_CHILD ; 
 int WS_VISIBLE ; 
 int /*<<< orphan*/  g_hInst ; 
 int /*<<< orphan*/  g_hwnd ; 
 int /*<<< orphan*/  htoa (int,char*) ; 
 int /*<<< orphan*/  hwndEdit ; 
 TYPE_1__ rect ; 
 int /*<<< orphan*/  strcpy_ (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strcpyw_ (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xButPos ; 
 int yButPos ; 

VOID
PrintTextXY(char* Text,int x,int y,int len)
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
      int ret;
      ret = SendMessage(handle,Msg,wParam,lParam);
      htoa(ret,&TextBuffer[8]);
      PrintTextXY(TextBuffer,ResultX,ResultY,16);
    }

__attribute__((used)) static
VOID
HandleSetHandlePrintHex(HWND handle,DWORD Msg,WPARAM wParam,LPARAM lParam)
    {
      LPVOID pMem;
      HANDLE hNewBuffer;
      int ret;

      LocalFree((HLOCAL)SendMessage(handle, EM_GETHANDLE, 0, 0L));
      if (UnicodeUsed)
          {
            hNewBuffer = LocalAlloc(LMEM_MOVEABLE | LMEM_ZEROINIT, 100);
            pMem = LocalLock(hNewBuffer);
            strcpyw_((wchar_t*)pMem,NewTextW);
          }
      else
          {
            hNewBuffer = LocalAlloc(LMEM_MOVEABLE | LMEM_ZEROINIT,50);
            pMem = LocalLock(hNewBuffer);
            strcpy_((char*)pMem,NewText);
          }

      LocalUnlock(pMem);
      hNewBuffer = LocalHandle(pMem);

	  /* Updates the buffer and displays new buffer */
      ret =  SendMessage(handle, EM_SETHANDLE, (WPARAM)hNewBuffer, 0L);

      htoa(ret,&TextBuffer[8]);
      PrintTextXY(TextBuffer,ResultX,ResultY,16);
    }

__attribute__((used)) static
VOID
HandlePrintReturnStr(HWND handle,DWORD Msg,WPARAM wParam,LPARAM lParam)
    {
      int ret;
      TextBuffer[8] = (char)(BUFFERLEN - 8); /* Setting the max size to put chars in first byte */
      ret = SendMessage(handle,Msg,wParam,lParam);
      PrintTextXY(TextBuffer,ResultX,ResultY,8+ret);
    }

__attribute__((used)) static
VOID
HandlePrintRect(HWND handle,DWORD Msg,WPARAM wParam,LPARAM lParam)
    {
      TextBuffer[8] = (char)(BUFFERLEN - 8); /* Setting the max size to put chars in first byte */
      SendMessage(handle,Msg,wParam,lParam);

      htoa(rect.top,&TextBuffer[8]);
      TextBuffer[8+8] = ' ';
      htoa(rect.bottom,&TextBuffer[8+8+1]);
      TextBuffer[8+8+8+1] = ' ';
      htoa(rect.left,&TextBuffer[8+8+8+1+1]);
      TextBuffer[8+8+8+8+1+1] = ' ';
      htoa(rect.right,&TextBuffer[8+8+8+8+1+1+1]);

      PrintTextXY(TextBuffer,ResultX,ResultY,8+4*9-1);
    }

__attribute__((used)) static
VOID
HandlePrintPasswdChar(HWND handle,DWORD Msg,WPARAM wParam,LPARAM lParam)
    {
      HDC hdc;
      int ret = SendMessage(handle,Msg,wParam,lParam);

      int s;

      if (ret)
          {
            s = 1;
            TextBuffer[8] = (char)(ret);
          }
      else
          {
            TextBuffer[8]  = 'N';
            TextBuffer[9]  = 'U';
            TextBuffer[10] = 'L';
            TextBuffer[11] = 'L';
            s = 4;
          }

      hdc = GetDC (g_hwnd);
      SelectObject (hdc, GetStockObject (SYSTEM_FIXED_FONT));

      TextOut (hdc,ResultX ,ResultY,TextBuffer,8+s);
      ReleaseDC (g_hwnd, hdc);
      ValidateRect (g_hwnd, &rect);
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
					      xButPos, // x
		                  yButPos, // y
		                  xSize,   // nWidth
		                  20,      // nHeight
					      g_hwnd,
                          (HMENU)(ULONG_PTR) id,
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
        EditStyle = 0;
        for (i=0 ; i< 19 ; i++)
        {
        if(BST_CHECKED == SendMessage(Buttons[i],BM_GETCHECK,0,0))
        EditStyle |= EditStyles[i];
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

