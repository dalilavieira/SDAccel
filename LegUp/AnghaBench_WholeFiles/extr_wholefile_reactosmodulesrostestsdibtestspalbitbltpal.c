#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_6__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {int biSize; int biWidth; int biPlanes; int biBitCount; int biClrUsed; int biClrImportant; scalar_t__ biYPelsPerMeter; scalar_t__ biXPelsPerMeter; scalar_t__ biSizeImage; int /*<<< orphan*/  biCompression; int /*<<< orphan*/  biHeight; } ;
struct TYPE_14__ {TYPE_3__* bmiColors; TYPE_1__ bmiHeader; } ;
struct TYPE_13__ {int palVersion; int palNumEntries; TYPE_2__* palPalEntry; } ;
struct TYPE_12__ {int /*<<< orphan*/  bottom; int /*<<< orphan*/  right; } ;
struct TYPE_11__ {int rgbRed; int rgbGreen; int rgbBlue; scalar_t__ rgbReserved; } ;
struct TYPE_10__ {int peRed; int peGreen; int peBlue; int /*<<< orphan*/  peFlags; } ;
typedef  TYPE_3__ RGBQUAD ;
typedef  TYPE_4__ RECT ;
typedef  TYPE_5__ LOGPALETTE256 ;
typedef  int /*<<< orphan*/  LOGPALETTE ;
typedef  int /*<<< orphan*/ * HWND ;
typedef  int /*<<< orphan*/  HPALETTE ;
typedef  int /*<<< orphan*/  HDC ;
typedef  int /*<<< orphan*/  HBITMAP ;
typedef  int /*<<< orphan*/  BITMAPINFOHEADER ;
typedef  TYPE_6__ BITMAPINFO256 ;
typedef  int /*<<< orphan*/  BITMAPINFO ;

/* Variables and functions */
 int /*<<< orphan*/  BI_RGB ; 
 int /*<<< orphan*/  BitBlt (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CreateCompatibleDC (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CreateDIBSection (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,void**,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CreatePalette (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DIB_RGB_COLORS ; 
 int /*<<< orphan*/  DeleteDC (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DeleteObject (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/ * GetActiveWindow () ; 
 int /*<<< orphan*/  GetClientRect (int /*<<< orphan*/ *,TYPE_4__*) ; 
 int /*<<< orphan*/  GetDC (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  PC_NOCOLLAPSE ; 
 int /*<<< orphan*/  RealizePalette (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ReleaseDC (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SRCCOPY ; 
 int /*<<< orphan*/  SelectObject (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SelectPalette (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int W_HEIGHT ; 
 int W_WIDTH ; 
 int /*<<< orphan*/  abs (int) ; 
 unsigned int* dibits ; 

void GeneratePalette(RGBQUAD* p)
{
	int i;
	for(i=0;i<256;i++)
	{
		p[i].rgbRed = i;
		p[i].rgbGreen = i;
		p[i].rgbBlue = i;
		p[i].rgbReserved = 0;
	}
}

void DoBlt(HBITMAP hBM)
{
	HDC hDC,Context;
	HWND ActiveWindow;
	RECT dest;
	HBITMAP dflBmp;

	if((ActiveWindow = GetActiveWindow()) == NULL)
		return;

	hDC = GetDC(ActiveWindow);
	GetClientRect(ActiveWindow,&dest);

	Context = CreateCompatibleDC(0);
	dflBmp = SelectObject(Context, hBM);
	BitBlt(hDC, 0, 0, dest.right, dest.bottom, Context, 0, 0, SRCCOPY);
	SelectObject(Context, dflBmp);
	DeleteDC(Context);
	DeleteObject(dflBmp);
	ReleaseDC(ActiveWindow, hDC);
}

void UpdatePalette(HBITMAP hBM){
	int i,y;
	static unsigned int c=0;

	for(i=0;i<W_WIDTH;i++){
		for(y=0;y<=W_HEIGHT-1;y++)
			dibits[y*320+i] = c % 256;

		if (c > 512)
			c = 0;
		else
			c++; // It's operation of incrementing of c variable, not reference of a cool OO language :-)
	}

	DoBlt(hBM);
}

void InitBitmap(HBITMAP *hBM){
	HPALETTE PalHan;
	HWND ActiveWindow;
	HDC hDC;
	RGBQUAD palette[256];
	int i;
	BITMAPINFO256 bmInf;
	LOGPALETTE256 palInf;

	ActiveWindow = GetActiveWindow();
	hDC = GetDC(ActiveWindow);

	bmInf.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmInf.bmiHeader.biWidth = W_WIDTH;
	bmInf.bmiHeader.biHeight = -abs(W_HEIGHT);
	bmInf.bmiHeader.biPlanes = 1;
	bmInf.bmiHeader.biBitCount = 8;
	bmInf.bmiHeader.biCompression = BI_RGB;
	bmInf.bmiHeader.biSizeImage = 0;
	bmInf.bmiHeader.biXPelsPerMeter = 0;
	bmInf.bmiHeader.biYPelsPerMeter = 0;
	bmInf.bmiHeader.biClrUsed = 256;
	bmInf.bmiHeader.biClrImportant = 256;

	GeneratePalette(palette);

	for(i=0;i<256;i++)
		bmInf.bmiColors[i] = palette[i];

	palInf.palVersion = 0x300;
	palInf.palNumEntries = 256;
	for(i=0;i<256;i++){
		palInf.palPalEntry[i].peRed = palette[i].rgbRed;
		palInf.palPalEntry[i].peGreen = palette[i].rgbGreen;
		palInf.palPalEntry[i].peBlue = palette[i].rgbBlue;
		palInf.palPalEntry[i].peFlags = PC_NOCOLLAPSE;
	}

	// Create palette
	PalHan = CreatePalette((LOGPALETTE*)&palInf);

	// Select it into hDC
	SelectPalette(hDC,PalHan,FALSE);

	// Realize palette in hDC
	RealizePalette(hDC);

	// Delete handle to palette
	DeleteObject(PalHan);

	// Create dib section
	*hBM = CreateDIBSection(hDC,(BITMAPINFO*)&bmInf,
		DIB_RGB_COLORS,(void**)&dibits,0,0);

	// Release dc
	ReleaseDC(ActiveWindow,hDC);
}

