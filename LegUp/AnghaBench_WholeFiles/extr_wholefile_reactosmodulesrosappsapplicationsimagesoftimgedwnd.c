#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_36__   TYPE_9__ ;
typedef  struct TYPE_35__   TYPE_8__ ;
typedef  struct TYPE_34__   TYPE_7__ ;
typedef  struct TYPE_33__   TYPE_6__ ;
typedef  struct TYPE_32__   TYPE_5__ ;
typedef  struct TYPE_31__   TYPE_4__ ;
typedef  struct TYPE_30__   TYPE_3__ ;
typedef  struct TYPE_29__   TYPE_2__ ;
typedef  struct TYPE_28__   TYPE_1__ ;
typedef  struct TYPE_27__   TYPE_11__ ;
typedef  struct TYPE_26__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  si ;
typedef  scalar_t__ WORD ;
typedef  int /*<<< orphan*/  VOID ;
struct TYPE_28__ {scalar_t__ top; scalar_t__ left; scalar_t__ bottom; scalar_t__ right; } ;
struct TYPE_36__ {TYPE_1__ rcPaint; } ;
struct TYPE_35__ {int Zoom; int /*<<< orphan*/ * hDCMem; int /*<<< orphan*/ * hBitmap; struct TYPE_35__* Next; TYPE_5__* MainWnd; TYPE_10__* pBits; TYPE_10__* pbmi; int /*<<< orphan*/  hSelf; TYPE_4__* OpenInfo; int /*<<< orphan*/  Height; int /*<<< orphan*/  Width; } ;
struct TYPE_34__ {scalar_t__ bottom; scalar_t__ right; } ;
struct TYPE_33__ {int cbSize; int fMask; int /*<<< orphan*/  nMax; scalar_t__ nPage; scalar_t__ nMin; } ;
struct TYPE_32__ {TYPE_8__* ImageEditors; } ;
struct TYPE_30__ {int /*<<< orphan*/  lpImagePath; } ;
struct TYPE_29__ {int /*<<< orphan*/  Height; int /*<<< orphan*/  Width; } ;
struct TYPE_31__ {scalar_t__ CreateNew; TYPE_3__ Open; TYPE_2__ New; } ;
struct TYPE_27__ {int /*<<< orphan*/  bmHeight; int /*<<< orphan*/  bmWidth; } ;
struct TYPE_26__ {scalar_t__ bfType; int bfOffBits; int bfSize; } ;
typedef  TYPE_6__ SCROLLINFO ;
typedef  TYPE_7__ RECT ;
typedef  TYPE_8__* PEDIT_WND_INFO ;
typedef  TYPE_9__* LPPAINTSTRUCT ;
typedef  int /*<<< orphan*/  HDC ;
typedef  int /*<<< orphan*/ * HBITMAP ;
typedef  scalar_t__ HANDLE ;
typedef  int DWORD ;
typedef  scalar_t__ BOOL ;
typedef  TYPE_10__ BITMAPFILEHEADER ;
typedef  TYPE_11__ BITMAP ;

/* Variables and functions */
 int /*<<< orphan*/  BitBlt (int /*<<< orphan*/ ,scalar_t__,scalar_t__,scalar_t__,scalar_t__,int /*<<< orphan*/ *,scalar_t__,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CloseHandle (scalar_t__) ; 
 int /*<<< orphan*/ * CreateCompatibleDC (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * CreateDIBSection (int /*<<< orphan*/ *,TYPE_10__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ CreateFile (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DIB_RGB_COLORS ; 
 int /*<<< orphan*/  DeleteDC (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DeleteObject (int /*<<< orphan*/ *) ; 
 scalar_t__ FALSE ; 
 int /*<<< orphan*/  FILE_FLAG_SEQUENTIAL_SCAN ; 
 int /*<<< orphan*/  FILE_SHARE_READ ; 
 int /*<<< orphan*/  GENERIC_READ ; 
 int /*<<< orphan*/  GetClientRect (int /*<<< orphan*/ ,TYPE_7__*) ; 
 int /*<<< orphan*/  GetDC (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetError (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetObject (int /*<<< orphan*/ *,int,TYPE_11__*) ; 
 TYPE_10__* HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_10__*) ; 
 int IMAGE_FRAME_SIZE ; 
 scalar_t__ INVALID_HANDLE_VALUE ; 
 int /*<<< orphan*/  InvalidateRect (int /*<<< orphan*/ ,int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  OPEN_EXISTING ; 
 int /*<<< orphan*/  ProcessHeap ; 
 scalar_t__ ReadFile (scalar_t__,TYPE_10__*,int,int*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ReleaseDC (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SB_HORZ ; 
 int /*<<< orphan*/  SB_VERT ; 
 int SIF_PAGE ; 
 int SIF_RANGE ; 
 int /*<<< orphan*/  SRCCOPY ; 
 int /*<<< orphan*/ * SelectObject (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SetScrollInfo (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_6__*,scalar_t__) ; 
 scalar_t__ TRUE ; 

__attribute__((used)) static VOID
EditWndUpdateScrollInfo(PEDIT_WND_INFO Info)
{
    SCROLLINFO si;
    RECT rcClient;

    GetClientRect(Info->hSelf,
                  &rcClient);

    si.cbSize = sizeof(si);
    si.fMask = SIF_PAGE | SIF_RANGE;
    si.nPage = rcClient.right - (2 * IMAGE_FRAME_SIZE);
    si.nMin = 0;
    si.nMax = Info->Width;

    SetScrollInfo(Info->hSelf,
                  SB_HORZ,
                  &si,
                  TRUE);

    si.nPage = rcClient.bottom - (2 * IMAGE_FRAME_SIZE);
    si.nMax = Info->Height;
    SetScrollInfo(Info->hSelf,
                  SB_VERT,
                  &si,
                  TRUE);
}

__attribute__((used)) static BOOL
LoadBlankCanvas(PEDIT_WND_INFO Info)
{
    /* FIXME: convert this to a DIB Section */
    /* set bitmap dimensions */
    Info->Width = Info->OpenInfo->New.Width;
    Info->Height = Info->OpenInfo->New.Height;

    return TRUE;
}

__attribute__((used)) static BOOL
LoadDIBImage(PEDIT_WND_INFO Info)
{
    BITMAPFILEHEADER bmfh;
    HANDLE hFile;
    BITMAP bitmap;
    DWORD BytesRead;
    BOOL bSuccess, bRet = FALSE;

    hFile = CreateFile(Info->OpenInfo->Open.lpImagePath,
                       GENERIC_READ,
                       FILE_SHARE_READ,
                       NULL,
                       OPEN_EXISTING,
                       FILE_FLAG_SEQUENTIAL_SCAN,
                       NULL);
    if (hFile == INVALID_HANDLE_VALUE)
        return bRet;

    bSuccess = ReadFile(hFile,
                        &bmfh,
                        sizeof(BITMAPFILEHEADER),
                        &BytesRead,
                        NULL);

    if (bSuccess && (BytesRead == sizeof(BITMAPFILEHEADER))
                 && (bmfh.bfType == *(WORD *)"BM"))
    {
        DWORD InfoSize = bmfh.bfOffBits - sizeof(BITMAPFILEHEADER);

        Info->pbmi = HeapAlloc(ProcessHeap,
                               0,
                               InfoSize);
        if (Info->pbmi)
        {
            bSuccess = ReadFile(hFile,
                                Info->pbmi,
                                InfoSize,
                                &BytesRead,
                                NULL);

            if (bSuccess && (BytesRead == InfoSize))
            {
                Info->hBitmap = CreateDIBSection(NULL,
                                                 Info->pbmi,
                                                 DIB_RGB_COLORS,
                                                 (VOID *)&Info->pBits,
                                                 NULL,
                                                 0);
                if (Info->hBitmap != NULL)
                {
                    ReadFile(hFile,
                             Info->pBits,
                             bmfh.bfSize - bmfh.bfOffBits,
                             &BytesRead,
                             NULL);

                    GetObject(Info->hBitmap,
                              sizeof(BITMAP),
                              &bitmap);

                    Info->Width = bitmap.bmWidth;
                    Info->Height = bitmap.bmHeight;

                    bRet = TRUE;
                }
            }
        }
    }
    else if (!bSuccess)
    {
        GetError(0);
    }

    CloseHandle(hFile);

    return bRet;
}

__attribute__((used)) static BOOL
InitEditWnd(PEDIT_WND_INFO Info)
{
    //BOOL bRet = FALSE;

    Info->Zoom = 100;

    if (Info->OpenInfo != NULL)
    {
        HDC hDC;

        if (Info->hDCMem)
        {
            DeleteObject(Info->hDCMem);
            Info->hDCMem = NULL;
        }

        hDC = GetDC(Info->hSelf);
        Info->hDCMem = CreateCompatibleDC(hDC);
        ReleaseDC(Info->hSelf, hDC);

        if (Info->OpenInfo->CreateNew)
        {
            LoadBlankCanvas(Info);
        }
        else
        {
            LoadDIBImage(Info);
        }

        Info->OpenInfo = NULL;
    }

    EditWndUpdateScrollInfo(Info);

    /* Add image editor to the list */
    Info->Next = Info->MainWnd->ImageEditors;
    Info->MainWnd->ImageEditors = Info;

    InvalidateRect(Info->hSelf,
                   NULL,
                   TRUE);

    /* FIXME - if returning FALSE, remove the image editor from the list! */
    return TRUE;
}

__attribute__((used)) static VOID
DestroyEditWnd(PEDIT_WND_INFO Info)
{
    PEDIT_WND_INFO *PrevEditor;
    PEDIT_WND_INFO Editor;

    DeleteDC(Info->hDCMem);

    /* FIXME - free resources and run down editor */
    HeapFree(ProcessHeap,
             0,
             Info->pbmi);
    HeapFree(ProcessHeap,
             0,
             Info->pBits);

    /* Remove the image editor from the list */
    PrevEditor = &Info->MainWnd->ImageEditors;
    Editor = Info->MainWnd->ImageEditors;
    do
    {
        if (Editor == Info)
        {
            *PrevEditor = Info->Next;
            break;
        }
        PrevEditor = &Editor->Next;
        Editor = Editor->Next;
    } while (Editor != NULL);
}

__attribute__((used)) static VOID
ImageEditWndRepaint(PEDIT_WND_INFO Info,
                    HDC hDC,
                    LPPAINTSTRUCT lpps)
{
    HBITMAP hOldBitmap;

    if (Info->hBitmap)
    {
        hOldBitmap = (HBITMAP) SelectObject(Info->hDCMem,
                                            Info->hBitmap);

        BitBlt(hDC,
               lpps->rcPaint.left,
               lpps->rcPaint.top,
               lpps->rcPaint.right - lpps->rcPaint.left,
               lpps->rcPaint.bottom - lpps->rcPaint.top,
               Info->hDCMem,
               lpps->rcPaint.left,
               lpps->rcPaint.top,
               SRCCOPY);

        Info->hBitmap = SelectObject(Info->hDCMem, hOldBitmap);
    }
}

