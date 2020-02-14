#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_6__ ;
typedef  struct TYPE_16__   TYPE_4__ ;
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  missedKeyword ;
typedef  int int_u ;
typedef  int /*<<< orphan*/  guicolor_T ;
typedef  char char_u ;
typedef  int UInt32 ;
struct TYPE_17__ {int num_cols; int char_width; int num_rows; int char_height; int col; int row; } ;
struct TYPE_16__ {scalar_t__ key_sym; char vim_code0; char vim_code1; } ;
struct TYPE_15__ {scalar_t__ what; } ;
struct TYPE_14__ {int red; int green; int blue; } ;
struct TYPE_13__ {int left; int top; int right; int bottom; } ;
typedef  int /*<<< orphan*/  StyleParameter ;
typedef  TYPE_1__ Rect ;
typedef  TYPE_2__ RGBColor ;
typedef  int /*<<< orphan*/  Ptr ;
typedef  scalar_t__ OSErr ;
typedef  scalar_t__ KeySym ;
typedef  int /*<<< orphan*/  FSSpec ;
typedef  TYPE_3__ EventRecord ;
typedef  int EventModifiers ;
typedef  int /*<<< orphan*/  DescType ;
typedef  int /*<<< orphan*/  AppleEvent ;
typedef  int /*<<< orphan*/  AEKeyword ;
typedef  int /*<<< orphan*/  AEDesc ;

/* Variables and functions */
 scalar_t__ AECountItems (int /*<<< orphan*/ *,long*) ; 
 scalar_t__ AEGetAttributePtr (int /*<<< orphan*/  const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,long*) ; 
 scalar_t__ AEGetNthPtr (int /*<<< orphan*/ *,long,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,long*) ; 
 int Blue (int /*<<< orphan*/ ) ; 
 int Columns ; 
 int DRAW_BOLD ; 
 int DRAW_TRANSP ; 
 int DRAW_UNDERC ; 
 int DRAW_UNDERL ; 
 int /*<<< orphan*/  DrawText (char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  EraseRect (TYPE_1__*) ; 
 scalar_t__ EventAvail (int /*<<< orphan*/ ,TYPE_3__*) ; 
 int FAIL ; 
 int FILL_X (int) ; 
 int FILL_Y (int) ; 
 int /*<<< orphan*/  FrameRect (TYPE_1__*) ; 
 char* FullPathFromFSSpec_save (int /*<<< orphan*/ ) ; 
 int Green (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  InvertRect (TYPE_1__*) ; 
 int /*<<< orphan*/  LineTo (int,int) ; 
 int MOD_MASK_ALT ; 
 int MOD_MASK_CTRL ; 
 int MOD_MASK_SHIFT ; 
 int MOUSE_ALT ; 
 int MOUSE_CTRL ; 
 int MOUSE_SHIFT ; 
 int /*<<< orphan*/  MoveTo (int,int) ; 
 int OK ; 
 int /*<<< orphan*/  QDSwapTextFlags (int) ; 
 int /*<<< orphan*/  RGBBackColor (TYPE_2__*) ; 
 int /*<<< orphan*/  RGBForeColor (TYPE_2__*) ; 
 int Red (int /*<<< orphan*/ ) ; 
 int STRLEN (char*) ; 
 int /*<<< orphan*/  SysBeep (int) ; 
 int TEXT_X (int) ; 
 int TEXT_Y (int) ; 
 int TOLOWER_ASC (int) ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  TextFace (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TextMode (int /*<<< orphan*/ ) ; 
 char* alloc (long) ; 
 int /*<<< orphan*/  bold ; 
 int controlKey ; 
 scalar_t__ errAEDescNotFound ; 
 int /*<<< orphan*/  everyEvent ; 
 int gMacSystemVersion ; 
 TYPE_6__ gui ; 
 int /*<<< orphan*/  gui_mch_wait_for_chars (int /*<<< orphan*/ ) ; 
 scalar_t__ isdigit (int) ; 
 int kQDUseCGTextMetrics ; 
 int kQDUseCGTextRendering ; 
 int /*<<< orphan*/  keyMissedKeywordAttr ; 
 int /*<<< orphan*/  mch_memmove (char*,char*,int) ; 
 scalar_t__ noErr ; 
 int /*<<< orphan*/  normal ; 
 scalar_t__ nullEvent ; 
 int optionKey ; 
 scalar_t__ p_antialias ; 
 scalar_t__ p_linespace ; 
 int rightControlKey ; 
 int rightOptionKey ; 
 int rightShiftKey ; 
 int shiftKey ; 
 TYPE_2__ specialColor ; 
 TYPE_4__* special_keys ; 
 int /*<<< orphan*/  srcCopy ; 
 int /*<<< orphan*/  srcOr ; 
 int /*<<< orphan*/  typeFSS ; 
 int /*<<< orphan*/  typeKeyword ; 
 int /*<<< orphan*/  ui_delay (long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  underline ; 

char_u *
C2Pascal_save(char_u *Cstring)
{
    char_u  *PascalString;
    int	    len;

    if (Cstring == NULL)
	return NULL;

    len = STRLEN(Cstring);

    if (len > 255) /* Truncate if necessary */
	len = 255;

    PascalString = alloc(len + 1);
    if (PascalString != NULL)
    {
	mch_memmove(PascalString + 1, Cstring, len);
	PascalString[0] = len;
    }

    return PascalString;
}

char_u *
C2Pascal_save_and_remove_backslash(char_u *Cstring)
{
    char_u  *PascalString;
    int	    len;
    char_u  *p, *c;

    len = STRLEN(Cstring);

    if (len > 255) /* Truncate if necessary */
	len = 255;

    PascalString = alloc(len + 1);
    if (PascalString != NULL)
    {
	for (c = Cstring, p = PascalString+1, len = 0; (*c != 0) && (len < 255); c++)
	{
	    if ((*c == '\\') && (c[1] != 0))
	    {
		c++;
	    }
	    *p = *c;
	    p++;
	    len++;
	}
	PascalString[0] = len;
    }

    return PascalString;
}

int_u
EventModifiers2VimMouseModifiers(EventModifiers macModifiers)
{
    int_u vimModifiers = 0x00;

    if (macModifiers & (shiftKey | rightShiftKey))
	vimModifiers |= MOUSE_SHIFT;
    if (macModifiers & (controlKey | rightControlKey))
	vimModifiers |= MOUSE_CTRL;
    if (macModifiers & (optionKey | rightOptionKey))
	vimModifiers |= MOUSE_ALT;
#if 0
    /* Not yet supported */
    if (macModifiers & (cmdKey)) /* There's no rightCmdKey */
	vimModifiers |= MOUSE_CMD;
#endif
    return (vimModifiers);
}

__attribute__((used)) static int_u
EventModifiers2VimModifiers(EventModifiers macModifiers)
{
    int_u vimModifiers = 0x00;

    if (macModifiers & (shiftKey | rightShiftKey))
	vimModifiers |= MOD_MASK_SHIFT;
    if (macModifiers & (controlKey | rightControlKey))
	vimModifiers |= MOD_MASK_CTRL;
    if (macModifiers & (optionKey | rightOptionKey))
	vimModifiers |= MOD_MASK_ALT;
#ifdef USE_CMD_KEY
    if (macModifiers & (cmdKey)) /* There's no rightCmdKey */
	vimModifiers |= MOD_MASK_CMD;
#endif
    return (vimModifiers);
}

__attribute__((used)) static int
points_to_pixels(char_u *str, char_u **end, int vertical)
{
    int		pixels;
    int		points = 0;
    int		divisor = 0;

    while (*str)
    {
	if (*str == '.' && divisor == 0)
	{
	    /* Start keeping a divisor, for later */
	    divisor = 1;
	    continue;
	}

	if (!isdigit(*str))
	    break;

	points *= 10;
	points += *str - '0';
	divisor *= 10;

	++str;
    }

    if (divisor == 0)
	divisor = 1;

    pixels = points/divisor;
    *end = str;
    return pixels;
}

char_u **
new_fnames_from_AEDesc(AEDesc *theList, long *numFiles, OSErr *error)
{
    char_u	**fnames = NULL;
    OSErr	newError;
    long	fileCount;
    FSSpec	fileToOpen;
    long	actualSize;
    AEKeyword	dummyKeyword;
    DescType	dummyType;

    /* Get number of files in list */
    *error = AECountItems(theList, numFiles);
    if (*error)
	return fnames;

    /* Allocate the pointer list */
    fnames = (char_u **) alloc(*numFiles * sizeof(char_u *));

    /* Empty out the list */
    for (fileCount = 0; fileCount < *numFiles; fileCount++)
	fnames[fileCount] = NULL;

    /* Scan the list of FSSpec */
    for (fileCount = 1; fileCount <= *numFiles; fileCount++)
    {
	/* Get the alias for the nth file, convert to an FSSpec */
	newError = AEGetNthPtr(theList, fileCount, typeFSS,
				&dummyKeyword, &dummyType,
				(Ptr) &fileToOpen, sizeof(FSSpec), &actualSize);
	if (newError)
	{
	    /* Caller is able to clean up */
	    /* TODO: Should be clean up or not? For safety. */
	    return fnames;
	}

	/* Convert the FSSpec to a pathname */
	fnames[fileCount - 1] = FullPathFromFSSpec_save(fileToOpen);
    }

    return (fnames);
}

OSErr
HandleUnusedParms(const AppleEvent *theAEvent)
{
    OSErr	error;
    long	actualSize;
    DescType	dummyType;
    AEKeyword	missedKeyword;

    /* Get the "missed keyword" attribute from the AppleEvent. */
    error = AEGetAttributePtr(theAEvent, keyMissedKeywordAttr,
			      typeKeyword, &dummyType,
			      (Ptr)&missedKeyword, sizeof(missedKeyword),
			      &actualSize);

    /* If the descriptor isn't found, then we got the required parameters. */
    if (error == errAEDescNotFound)
    {
	error = noErr;
    }
    else
    {
#if 0
	/* Why is this removed? */
	error = errAEEventNotHandled;
#endif
    }

    return error;
}

__attribute__((used)) static int
hex_digit(int c)
{
    if (isdigit(c))
	return c - '0';
    c = TOLOWER_ASC(c);
    if (c >= 'a' && c <= 'f')
	return c - 'a' + 10;
    return -1000;
}

void
gui_mch_set_fg_color(guicolor_T color)
{
    RGBColor TheColor;

    TheColor.red = Red(color) * 0x0101;
    TheColor.green = Green(color) * 0x0101;
    TheColor.blue = Blue(color) * 0x0101;

    RGBForeColor(&TheColor);
}

void
gui_mch_set_bg_color(guicolor_T color)
{
    RGBColor TheColor;

    TheColor.red = Red(color) * 0x0101;
    TheColor.green = Green(color) * 0x0101;
    TheColor.blue = Blue(color) * 0x0101;

    RGBBackColor(&TheColor);
}

void
gui_mch_set_sp_color(guicolor_T color)
{
    specialColor.red = Red(color) * 0x0101;
    specialColor.green = Green(color) * 0x0101;
    specialColor.blue = Blue(color) * 0x0101;
}

__attribute__((used)) static void
draw_undercurl(int flags, int row, int col, int cells)
{
    int			x;
    int			offset;
    const static int	val[8] = {1, 0, 0, 0, 1, 2, 2, 2 };
    int			y = FILL_Y(row + 1) - 1;

    RGBForeColor(&specialColor);

    offset = val[FILL_X(col) % 8];
    MoveTo(FILL_X(col), y - offset);

    for (x = FILL_X(col); x < FILL_X(col + cells); ++x)
    {
	offset = val[x % 8];
	LineTo(x, y - offset);
    }
}

__attribute__((used)) static void
draw_string_QD(int row, int col, char_u *s, int len, int flags)
{
#ifdef FEAT_MBYTE
    char_u	*tofree = NULL;

    if (output_conv.vc_type != CONV_NONE)
    {
	tofree = string_convert(&output_conv, s, &len);
	if (tofree != NULL)
	    s = tofree;
    }
#endif

    /*
     * On OS X, try using Quartz-style text antialiasing.
     */
    if (gMacSystemVersion >= 0x1020)
    {
	/* Quartz antialiasing is available only in OS 10.2 and later. */
	UInt32 qd_flags = (p_antialias ?
			     kQDUseCGTextRendering | kQDUseCGTextMetrics : 0);
	QDSwapTextFlags(qd_flags);
    }

    /*
     * When antialiasing we're using srcOr mode, we have to clear the block
     * before drawing the text.
     * Also needed when 'linespace' is non-zero to remove the cursor and
     * underlining.
     * But not when drawing transparently.
     * The following is like calling gui_mch_clear_block(row, col, row, col +
     * len - 1), but without setting the bg color to gui.back_pixel.
     */
    if (((gMacSystemVersion >= 0x1020 && p_antialias) || p_linespace != 0)
	    && !(flags & DRAW_TRANSP))
    {
	Rect rc;

	rc.left = FILL_X(col);
	rc.top = FILL_Y(row);
#ifdef FEAT_MBYTE
	/* Multibyte computation taken from gui_w32.c */
	if (has_mbyte)
	{
	    /* Compute the length in display cells. */
	    rc.right = FILL_X(col + mb_string2cells(s, len));
	}
	else
#endif
	rc.right = FILL_X(col + len) + (col + len == Columns);
	rc.bottom = FILL_Y(row + 1);
	EraseRect(&rc);
    }

    if (gMacSystemVersion >= 0x1020 && p_antialias)
    {
	StyleParameter face;

	face = normal;
	if (flags & DRAW_BOLD)
	    face |= bold;
	if (flags & DRAW_UNDERL)
	    face |= underline;
	TextFace(face);

	/* Quartz antialiasing works only in srcOr transfer mode. */
	TextMode(srcOr);

	MoveTo(TEXT_X(col), TEXT_Y(row));
	DrawText((char*)s, 0, len);
    }
    else
    {
	/* Use old-style, non-antialiased QuickDraw text rendering. */
	TextMode(srcCopy);
	TextFace(normal);

    /*  SelectFont(hdc, gui.currFont); */

	if (flags & DRAW_TRANSP)
	{
	    TextMode(srcOr);
	}

	MoveTo(TEXT_X(col), TEXT_Y(row));
	DrawText((char *)s, 0, len);

	if (flags & DRAW_BOLD)
	{
	    TextMode(srcOr);
	    MoveTo(TEXT_X(col) + 1, TEXT_Y(row));
	    DrawText((char *)s, 0, len);
	}

	if (flags & DRAW_UNDERL)
	{
	    MoveTo(FILL_X(col), FILL_Y(row + 1) - 1);
	    LineTo(FILL_X(col + len) - 1, FILL_Y(row + 1) - 1);
	}
    }

    if (flags & DRAW_UNDERC)
	draw_undercurl(flags, row, col, len);

#ifdef FEAT_MBYTE
    vim_free(tofree);
#endif
}

void
gui_mch_draw_string(int row, int col, char_u *s, int len, int flags)
{
#if defined(USE_ATSUI_DRAWING)
    if (p_macatsui == 0 && p_macatsui_last != 0)
	/* switch from macatsui to nomacatsui */
	gui_mac_dispose_atsui_style();
    else if (p_macatsui != 0 && p_macatsui_last == 0)
	/* switch from nomacatsui to macatsui */
	gui_mac_create_atsui_style();

    if (p_macatsui)
	draw_string_ATSUI(row, col, s, len, flags);
    else
#endif
	draw_string_QD(row, col, s, len, flags);
}

int
gui_mch_haskey(char_u *name)
{
    int i;

    for (i = 0; special_keys[i].key_sym != (KeySym)0; i++)
	if (name[0] == special_keys[i].vim_code0 &&
					 name[1] == special_keys[i].vim_code1)
	    return OK;
    return FAIL;
}

void
gui_mch_beep(void)
{
    SysBeep(1); /* Should this be 0? (????) */
}

void
gui_mch_flash(int msec)
{
    /* Do a visual beep by reversing the foreground and background colors */
    Rect    rc;

    /*
     * Note: InvertRect() excludes right and bottom of rectangle.
     */
    rc.left = 0;
    rc.top = 0;
    rc.right = gui.num_cols * gui.char_width;
    rc.bottom = gui.num_rows * gui.char_height;
    InvertRect(&rc);

    ui_delay((long)msec, TRUE);		/* wait for some msec */

    InvertRect(&rc);
}

void
gui_mch_invert_rectangle(int r, int c, int nr, int nc)
{
    Rect	rc;

    /*
     * Note: InvertRect() excludes right and bottom of rectangle.
     */
    rc.left = FILL_X(c);
    rc.top = FILL_Y(r);
    rc.right = rc.left + nc * gui.char_width;
    rc.bottom = rc.top + nr * gui.char_height;
    InvertRect(&rc);
}

void
gui_mch_iconify(void)
{
    /* TODO: find out what could replace iconify
     *	     -window shade?
     *	     -hide application?
     */
}

void
gui_mch_set_foreground(void)
{
    /* TODO */
}

void
gui_mch_draw_hollow_cursor(guicolor_T color)
{
    Rect rc;

    /*
     * Note: FrameRect() excludes right and bottom of rectangle.
     */
    rc.left = FILL_X(gui.col);
    rc.top = FILL_Y(gui.row);
    rc.right = rc.left + gui.char_width;
#ifdef FEAT_MBYTE
    if (mb_lefthalve(gui.row, gui.col))
	rc.right += gui.char_width;
#endif
    rc.bottom = rc.top + gui.char_height;

    gui_mch_set_fg_color(color);

    FrameRect(&rc);
}

void
gui_mch_draw_part_cursor(int w, int h, guicolor_T color)
{
    Rect rc;

#ifdef FEAT_RIGHTLEFT
    /* vertical line should be on the right of current point */
    if (CURSOR_BAR_RIGHT)
	rc.left = FILL_X(gui.col + 1) - w;
    else
#endif
	rc.left = FILL_X(gui.col);
    rc.top = FILL_Y(gui.row) + gui.char_height - h;
    rc.right = rc.left + w;
    rc.bottom = rc.top + h;

    gui_mch_set_fg_color(color);

    FrameRect(&rc);
//    PaintRect(&rc);
}

void
gui_mch_update(void)
{
    /* TODO: find what to do
     *	     maybe call gui_mch_wait_for_chars (0)
     *	     more like look at EventQueue then
     *	     call heart of gui_mch_wait_for_chars;
     *
     *	if (eventther)
     *	    gui_mac_handle_event(&event);
     */
    EventRecord theEvent;

    if (EventAvail(everyEvent, &theEvent))
	if (theEvent.what != nullEvent)
	    gui_mch_wait_for_chars(0);
}

