#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_3__ ;
typedef  struct TYPE_18__   TYPE_2__ ;
typedef  struct TYPE_17__   TYPE_1__ ;

/* Type definitions */
typedef  int WORD ;
struct TYPE_19__ {TYPE_2__* message; } ;
struct TYPE_18__ {int width; int height; int** message; int random_reg1; int counter; int msgindex; } ;
struct TYPE_17__ {int right; int left; int bottom; int top; } ;
typedef  int /*<<< orphan*/  TCHAR ;
typedef  TYPE_1__ RECT ;
typedef  TYPE_2__ MATRIX_MESSAGE ;
typedef  TYPE_3__ MATRIX ;
typedef  int /*<<< orphan*/ * HWND ;
typedef  scalar_t__ HFONT ;
typedef  int /*<<< orphan*/  HDC ;
typedef  scalar_t__ HBITMAP ;
typedef  scalar_t__ HANDLE ;
typedef  scalar_t__ BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  ANSI_CHARSET ; 
 int /*<<< orphan*/  ANTIALIASED_QUALITY ; 
 int /*<<< orphan*/  CLIP_DEFAULT_PRECIS ; 
 scalar_t__ CreateBitmap (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CreateCompatibleDC (int /*<<< orphan*/ ) ; 
 scalar_t__ CreateFont (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DEFAULT_PITCH ; 
 int DT_CALCRECT ; 
 int DT_CENTER ; 
 int DT_VCENTER ; 
 int DT_WORDBREAK ; 
 int /*<<< orphan*/  DeleteDC (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DeleteObject (scalar_t__) ; 
 int /*<<< orphan*/  DrawGlyph (TYPE_3__*,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DrawText (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,TYPE_1__*,int) ; 
 int /*<<< orphan*/  FW_BOLD ; 
 int /*<<< orphan*/  FW_NORMAL ; 
 int /*<<< orphan*/  FillRect (int /*<<< orphan*/ ,TYPE_1__*,int /*<<< orphan*/ ) ; 
 int GLYPH_HEIGHT ; 
 int GLYPH_REDRAW ; 
 int GLYPH_WIDTH ; 
 int /*<<< orphan*/  GetDC (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  GetDeviceCaps (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ GetPixel (int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  GetStockObject (int /*<<< orphan*/ ) ; 
 scalar_t__ GetTickCount () ; 
 int /*<<< orphan*/  LOGPIXELSY ; 
 int /*<<< orphan*/  MAXMSG_HEIGHT ; 
 int /*<<< orphan*/  MAXMSG_WIDTH ; 
 int /*<<< orphan*/  MAX_INTENSITY ; 
 int MSGSPEED_MAX ; 
 int MSGSPEED_MIN ; 
 int MulDiv (int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  OUT_DEFAULT_PRECIS ; 
 int /*<<< orphan*/  OffsetRect (TYPE_1__*,int,int) ; 
 int /*<<< orphan*/  RandomGlyph (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ReleaseDC (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ SelectObject (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  SetRect (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WHITE_BRUSH ; 
 int crc_rand () ; 
 scalar_t__ g_fFontBold ; 
 scalar_t__ g_fRandomizeMessages ; 
 scalar_t__ g_hFont ; 
 int g_nFontSize ; 
 int g_nMessageSpeed ; 
 int g_nNumMessages ; 
 int /*<<< orphan*/ * g_szFontName ; 
 int /*<<< orphan*/ ** g_szMessages ; 
 TYPE_2__* malloc (int) ; 
 void* min (int,int /*<<< orphan*/ ) ; 

WORD crc_msgrand(WORD reg)
{
	const WORD mask = 0xb400;

	if(reg & 1)
		reg = (reg >> 1) ^ mask;
	else
		reg = (reg >> 1);

	return reg;
}

void SetMatrixMessage(MATRIX_MESSAGE *msg, HFONT hFont, TCHAR *text)
{
	HDC		hdc;
	RECT	rect;
	int		x, y;

	HDC		hdcMessage;
	HBITMAP hbmMessage;

	HANDLE	hOldFont, hOldBmp;

	//
	// Create a monochrome off-screen buffer
	//
	hdc = GetDC(NULL);

	hdcMessage = CreateCompatibleDC(hdc);
	hbmMessage = CreateBitmap(MAXMSG_WIDTH, MAXMSG_HEIGHT, 1, 1, 0);
	hOldBmp    = SelectObject(hdcMessage, hbmMessage);

	ReleaseDC(NULL, hdc);

	//
	// Draw text into bitmap
	//
	SetRect(&rect, 0, 0, msg->width, MAXMSG_HEIGHT);
	FillRect(hdcMessage, &rect, GetStockObject(WHITE_BRUSH));

	hOldFont = SelectObject(hdcMessage, g_hFont);
	DrawText(hdcMessage, text, -1, &rect, DT_CENTER|DT_VCENTER|DT_WORDBREAK|DT_CALCRECT);

	OffsetRect(&rect, (msg->width-(rect.right-rect.left))/2, (msg->height-(rect.bottom-rect.top))/2);
	DrawText(hdcMessage, text, -1, &rect, DT_CENTER|DT_VCENTER|DT_WORDBREAK);

	//
	// Convert bitmap into an array of cells for easy drawing
	//
	for(y = 0; y < msg->height; y++)
	{
		for(x = 0; x < msg->width; x++)
		{
			msg->message[x][y] = GetPixel(hdcMessage, x, y) ? 0 : 1;
		}
	}

	//
	//	Cleanup
	//
	SelectObject(hdcMessage, hOldFont);
	SelectObject(hdcMessage, hOldBmp);

	DeleteDC(hdcMessage);
	DeleteObject(hbmMessage);
}

void DrawMatrixMessage(MATRIX *matrix, MATRIX_MESSAGE *msg, HDC hdc)
{
	int x, y;

	for(x = 0; x < msg->width; x++)
		for(y = 0; y < msg->height; y++)
			if((msg->message[x][y] & 0x8000) &&
			   (msg->message[x][y] & 0x00FF))
			{
				DrawGlyph(matrix, hdc, x * GLYPH_WIDTH, y * GLYPH_HEIGHT, RandomGlyph(MAX_INTENSITY));
			}
}

void RevealMatrixMessage(MATRIX_MESSAGE *msg, int amount)
{
	while(amount--)
	{
		int pos;

		msg->random_reg1 = crc_msgrand(msg->random_reg1);
		pos = msg->random_reg1 & 0xffff;

		msg->message[pos / 256][pos % 256] |= GLYPH_REDRAW;
	}
}

void ClearMatrixMessage(MATRIX_MESSAGE *msg)
{
	int x, y;

	for(x = 0; x < msg->width; x++)
		for(y = 0; y < msg->height; y++)
			msg->message[x][y] = 0;
}

int MessageSpeed()
{
	return (MSGSPEED_MAX-MSGSPEED_MIN) - (g_nMessageSpeed-MSGSPEED_MIN) + MSGSPEED_MIN;
}

void DoMatrixMessage(HDC hdc, MATRIX *matrix)
{
	MATRIX_MESSAGE *msg = matrix->message;

	int RealSpeed = MessageSpeed();

	if(g_nNumMessages > 0)
	{
		// nothing to do yet..
		if(msg->counter++ < 0)
			return;

		// has counter reached limit..clear the message
		if(msg->counter++ == RealSpeed / 2 + (RealSpeed/4))
			ClearMatrixMessage(msg);

		// reset counter + display a new message
		if(msg->counter >= RealSpeed)
		{
			// mark all message-cells as being "invisible" so the
			// message gets cleared by the matrix decoding naturally

			if(g_fRandomizeMessages)
				msg->msgindex = crc_rand() % g_nNumMessages;
			else
				msg->msgindex = (msg->msgindex + 1) % g_nNumMessages;

			// make a new message..initially invisible
			SetMatrixMessage(msg, 0, g_szMessages[msg->msgindex]);

			msg->counter = -(int)(crc_rand() % MSGSPEED_MAX);
		}
		// reveal the next part of the message
		else if(msg->counter < RealSpeed / 2)
		{
			int w = (g_nMessageSpeed - MSGSPEED_MIN);
			w = (1 << 16) + ((w<<16) / MSGSPEED_MAX);
			w = (w * 3 * g_nMessageSpeed) >> 16;

			RevealMatrixMessage(msg, w + 100);
		}

		//
		// draw whatever part of the message is visible at this time
		//
		DrawMatrixMessage(matrix, msg, hdc);
	}
}

void SetMessageFont(HWND hwnd, TCHAR *szFontName, int nPointSize, BOOL fBold)
{
	int		lfHeight;
	HDC		hdc;
	HFONT	hFont;

	hdc = GetDC(hwnd);

	lfHeight = -MulDiv(nPointSize, GetDeviceCaps(hdc, LOGPIXELSY), 72);

	ReleaseDC(hwnd, hdc);

	hFont = CreateFont(lfHeight, 0, 0, 0, fBold ? FW_BOLD: FW_NORMAL, 0, 0, 0,
		ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		ANTIALIASED_QUALITY, DEFAULT_PITCH, szFontName);

	if(hFont != 0)
	{
		if(g_hFont != 0)
			DeleteObject(g_hFont);

		g_hFont = hFont;
	}
}

MATRIX_MESSAGE *InitMatrixMessage(HWND hwnd, int width, int height)
{
	MATRIX_MESSAGE *msg;

	if((msg = malloc(sizeof(MATRIX_MESSAGE))) == 0)
		return 0;

	ClearMatrixMessage(msg);

	msg->msgindex = 0;
	msg->width    = min(width, MAXMSG_WIDTH);
	msg->height   = min(height, MAXMSG_HEIGHT);
	msg->counter  = -(int)(crc_rand() % MSGSPEED_MIN + MSGSPEED_MIN);

	msg->random_reg1 = (WORD)GetTickCount();

	SetMessageFont(hwnd, g_szFontName, g_nFontSize, g_fFontBold);

	SetMatrixMessage(msg, 0, g_szMessages[0]);

	return msg;
}

