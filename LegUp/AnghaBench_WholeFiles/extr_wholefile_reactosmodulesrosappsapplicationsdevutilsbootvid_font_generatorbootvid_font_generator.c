#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int USHORT ;
struct TYPE_4__ {int biSize; int biHeight; int biBitCount; int biPlanes; int /*<<< orphan*/  biWidth; } ;
struct TYPE_5__ {TYPE_1__ bmiHeader; } ;
typedef  int /*<<< orphan*/  RGBQUAD ;
typedef  TYPE_2__* PBITMAPINFO ;
typedef  char* LPSTR ;
typedef  int INT ;
typedef  int /*<<< orphan*/ * HFONT ;
typedef  int /*<<< orphan*/ * HDC ;
typedef  int /*<<< orphan*/ * HBITMAP ;
typedef  int /*<<< orphan*/  DWORD ;
typedef  int /*<<< orphan*/  CHAR ;
typedef  int /*<<< orphan*/  BmpInfo ;
typedef  int /*<<< orphan*/  BYTE ;
typedef  int /*<<< orphan*/  BOOL ;
typedef  int /*<<< orphan*/  BITMAPINFOHEADER ;
typedef  int /*<<< orphan*/  BITMAPINFO ;

/* Variables and functions */
 int /*<<< orphan*/  ANSI_CHARSET ; 
 int /*<<< orphan*/  CLIP_DEFAULT_PRECIS ; 
 int /*<<< orphan*/ * CreateCompatibleBitmap (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/ * CreateCompatibleDC (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * CreateFontA (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  DeleteDC (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DeleteObject (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  FIXED_PITCH ; 
 char* FONT_NAME_DEF ; 
 int FONT_SIZE_DEF ; 
 int /*<<< orphan*/  FW_NORMAL ; 
 int /*<<< orphan*/  GetDIBits (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetDeviceCaps (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetLastError () ; 
 int HEIGHT ; 
 int /*<<< orphan*/  LOGPIXELSY ; 
 int MulDiv (int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  NONANTIALIASED_QUALITY ; 
 int /*<<< orphan*/  OUT_DEFAULT_PRECIS ; 
 int /*<<< orphan*/  RGB (int,int,int) ; 
 int /*<<< orphan*/ * SelectObject (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SetBkColor (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SetTextColor (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  TextOutA (int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  WIDTH ; 
 int X_OFFSET_DEF ; 
 int Y_OFFSET_DEF ; 
 int /*<<< orphan*/  ZeroMemory (int /*<<< orphan*/ **,int) ; 
 int atoi (char*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  stdout ; 
 scalar_t__ strncmp (char*,char*,int) ; 

__attribute__((used)) static void DumpCharacterFontData(DWORD BmpBits[])
{
    static int iBegin = 0;
    int i;

    fprintf(stdout, "    ");

    for (i = 0; i < HEIGHT; i++)
        fprintf(stdout, "0x%02lX, ", BmpBits[i]);

    fprintf(stdout, " // %d\n", iBegin);
    iBegin += HEIGHT;
}

__attribute__((used)) static BOOL PlotCharacter(HDC hDC, HFONT hFont, INT XOffset, INT YOffset, CHAR Character, DWORD BmpBits[])
{
    BOOL bReturnValue = FALSE;
    HBITMAP hOldBmp;
    HFONT hOldFont;
    HBITMAP hBmp = NULL;
    BYTE BmpInfo[sizeof(BITMAPINFO) + sizeof(RGBQUAD)];
    PBITMAPINFO pBmpInfo = (PBITMAPINFO)&BmpInfo;

    hBmp = CreateCompatibleBitmap(hDC, WIDTH, HEIGHT);
    if (!hBmp)
    {
        fprintf(stderr, "CreateCompatibleBitmap failed with error %lu!\n", GetLastError());
        goto Cleanup;
    }

    hOldBmp  = SelectObject(hDC, hBmp);
    hOldFont = SelectObject(hDC, hFont);
    SetBkColor(hDC, RGB(0, 0, 0));
    SetTextColor(hDC, RGB(255, 255, 255));
    TextOutA(hDC, XOffset, YOffset, &Character, 1);

    /*
     * Use enough memory for BITMAPINFO and one additional color in the color table.
     * BITMAPINFO already contains a color table entry for a single color and
     * GetDIBits needs space for two colors (black and white).
     */
    ZeroMemory(&BmpInfo, sizeof(BmpInfo));
    pBmpInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    pBmpInfo->bmiHeader.biHeight = -HEIGHT;
    pBmpInfo->bmiHeader.biWidth = WIDTH;
    pBmpInfo->bmiHeader.biBitCount = 1;
    pBmpInfo->bmiHeader.biPlanes = 1;

    bReturnValue = TRUE;

    if (!GetDIBits(hDC, hBmp, 0, HEIGHT, BmpBits, pBmpInfo, 0))
    {
        fprintf(stderr, "GetDIBits failed with error %lu!\n", GetLastError());
        bReturnValue = FALSE;
    }

    SelectObject(hDC, hOldBmp);
    SelectObject(hDC, hOldFont);

Cleanup:
    if (hBmp)
        DeleteObject(hBmp);

    return bReturnValue;
}

__attribute__((used)) static void DumpFont(LPSTR FontName, INT FontSize, INT XOffset, INT YOffset)
{
    int iHeight;
    HDC hDC = NULL;
    HFONT hFont = NULL;

    DWORD BmpBits[HEIGHT];
    USHORT c;

    hDC = CreateCompatibleDC(NULL);
    if (!hDC)
    {
        fprintf(stderr, "CreateCompatibleDC failed with error %lu!\n", GetLastError());
        goto Cleanup;
    }

    iHeight = -MulDiv(FontSize, GetDeviceCaps(hDC, LOGPIXELSY), 72);
    hFont = CreateFontA(iHeight, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
                        ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                        NONANTIALIASED_QUALITY, FIXED_PITCH, FontName);
    if (!hFont)
    {
        fprintf(stderr, "CreateFont failed with error %lu!\n", GetLastError());
        goto Cleanup;
    }

    for (c = 0; c < 256; c++)
    {
        PlotCharacter(hDC, hFont, XOffset, YOffset, (CHAR)c, BmpBits);

#ifdef DUMP_CHAR_ON_SCREEN
        DumpCharacterOnScreen(BmpBits);
        fprintf(stdout, "\nPress any key to continue...\n");
        _getch();
        system("cls");
#else
        DumpCharacterFontData(BmpBits);
#endif
    }

Cleanup:
    if (hFont)
        DeleteObject(hFont);

    if (hDC)
        DeleteDC(hDC);
}

int main(int argc, char** argv)
{
    /* Validate the arguments */
    if (argc > 5 || (argc >= 2 && strncmp(argv[1], "/?", 2) == 0))
    {
        fprintf(stdout,
                "Usage: %s \"font name\" [font size] [X-offset] [Y-offset]\n"
                "Default font name is: \"%s\"\n"
                "Default font size is: %i\n"
                "Default X-offset  is: %i\n"
                "Default Y-offset  is: %i\n",
                argv[0],
                FONT_NAME_DEF, FONT_SIZE_DEF, X_OFFSET_DEF, Y_OFFSET_DEF);

        return -1;
    }

    DumpFont((argc <= 1) ? FONT_NAME_DEF : argv[1],
             (argc <= 2) ? FONT_SIZE_DEF : atoi(argv[2]),
             (argc <= 3) ?  X_OFFSET_DEF : atoi(argv[3]),
             (argc <= 4) ?  Y_OFFSET_DEF : atoi(argv[4]));
    return 0;
}

