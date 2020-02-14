#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_5__ ;
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uiWindow ;
typedef  int /*<<< orphan*/  uiOpenTypeFeatures ;
struct TYPE_12__ {int /*<<< orphan*/  Align; int /*<<< orphan*/  Width; int /*<<< orphan*/ * DefaultFont; int /*<<< orphan*/ * String; } ;
typedef  TYPE_1__ uiInitOptions ;
typedef  int /*<<< orphan*/  uiGrid ;
typedef  int /*<<< orphan*/  uiFontButton ;
typedef  int /*<<< orphan*/  uiEntry ;
typedef  TYPE_1__ uiDrawTextLayoutParams ;
typedef  int /*<<< orphan*/  uiDrawTextLayout ;
typedef  int /*<<< orphan*/  uiDrawFontDescriptor ;
typedef  int /*<<< orphan*/  uiCheckbox ;
typedef  int /*<<< orphan*/  uiBox ;
struct TYPE_13__ {int /*<<< orphan*/ * Features; int /*<<< orphan*/  Type; } ;
typedef  TYPE_3__ uiAttributeSpec ;
typedef  int /*<<< orphan*/  uiAreaMouseEvent ;
typedef  int /*<<< orphan*/  uiAreaKeyEvent ;
typedef  int /*<<< orphan*/  uiAreaHandler ;
struct TYPE_14__ {int /*<<< orphan*/  Context; int /*<<< orphan*/  AreaWidth; } ;
typedef  TYPE_4__ uiAreaDrawParams ;
typedef  int /*<<< orphan*/  uiArea ;
struct TYPE_15__ {void (* Draw ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_4__*) ;void (* MouseEvent ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;void (* MouseCrossed ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ;void (* DragBroken ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;int (* KeyEvent ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;} ;

/* Variables and functions */
 int /*<<< orphan*/ * area ; 
 int /*<<< orphan*/ * attrstr ; 
 int /*<<< orphan*/ * fontButton ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char const*) ; 
 TYPE_5__ handler ; 
 int /*<<< orphan*/ * mainwin ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/ * nullFeatures ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/ * textEntry ; 
 int /*<<< orphan*/  uiAlignCenter ; 
 int /*<<< orphan*/  uiAlignFill ; 
 int /*<<< orphan*/  uiAreaQueueRedrawAll (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiAttributeFeatures ; 
 int /*<<< orphan*/  uiAttributedStringLen (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiAttributedStringSetAttribute (int /*<<< orphan*/ *,TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiBoxAppend (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiBoxSetPadded (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  uiCheckboxChecked (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiCheckboxOnToggled (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiControl (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiControlDestroy (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiControlHide (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiControlShow (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiDrawFreeTextLayout (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * uiDrawNewTextLayout (TYPE_1__*) ; 
 int /*<<< orphan*/  uiDrawText (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiDrawTextAlignLeft ; 
 int /*<<< orphan*/  uiEntryOnChanged (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiEntrySetText (int /*<<< orphan*/ *,char*) ; 
 char* uiEntryText (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiFontButtonFont (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiFontButtonOnChanged (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiFreeAttributedString (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiFreeInitError (char const*) ; 
 int /*<<< orphan*/  uiFreeOpenTypeFeatures (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiFreeText (char*) ; 
 int /*<<< orphan*/  uiGridAppend (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int,int,int,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiGridSetPadded (int /*<<< orphan*/ *,int) ; 
 char* uiInit (TYPE_1__*) ; 
 int /*<<< orphan*/  uiMain () ; 
 int /*<<< orphan*/ * uiNewArea (TYPE_5__*) ; 
 int /*<<< orphan*/ * uiNewAttributedString (char*) ; 
 int /*<<< orphan*/ * uiNewCheckbox (char*) ; 
 int /*<<< orphan*/ * uiNewEntry () ; 
 int /*<<< orphan*/ * uiNewFontButton () ; 
 int /*<<< orphan*/ * uiNewGrid () ; 
 int /*<<< orphan*/ * uiNewOpenTypeFeatures () ; 
 int /*<<< orphan*/ * uiNewVerticalBox () ; 
 int /*<<< orphan*/ * uiNewWindow (char*,int,int,int) ; 
 int /*<<< orphan*/  uiOnShouldQuit (int (*) (void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiQuit () ; 
 int /*<<< orphan*/  uiUninit () ; 
 int /*<<< orphan*/  uiWindowOnClosing (int /*<<< orphan*/ *,int (*) (int /*<<< orphan*/ *,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiWindowSetChild (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiWindowSetMargined (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static void remakeAttrStr(void)
{
	char *text;
	uiOpenTypeFeatures *otf;
	uiAttributeSpec spec;

	if (attrstr != NULL)
		uiFreeAttributedString(attrstr);

	text = uiEntryText(textEntry);
	attrstr = uiNewAttributedString(text);
	uiFreeText(text);

	if (!uiCheckboxChecked(nullFeatures)) {
		otf = uiNewOpenTypeFeatures();
		// TODO
		spec.Type = uiAttributeFeatures;
		spec.Features = otf;
		uiAttributedStringSetAttribute(attrstr, &spec,
			0, uiAttributedStringLen(attrstr));
		// and uiAttributedString copied otf
		uiFreeOpenTypeFeatures(otf);
	}

	uiAreaQueueRedrawAll(area);
}

__attribute__((used)) static void handlerDraw(uiAreaHandler *a, uiArea *area, uiAreaDrawParams *p)
{
	uiDrawTextLayout *layout;
	uiDrawTextLayoutParams lp;
	uiDrawFontDescriptor desc;

	memset(&lp, 0, sizeof (uiDrawTextLayoutParams));
	lp.String = attrstr;
	uiFontButtonFont(fontButton, &desc);
	lp.DefaultFont = &desc;
	lp.Width = p->AreaWidth;
	lp.Align = uiDrawTextAlignLeft;
	layout = uiDrawNewTextLayout(&lp);
	uiDrawText(p->Context, layout, 0, 0);
	uiDrawFreeTextLayout(layout);
}

__attribute__((used)) static void handlerMouseEvent(uiAreaHandler *a, uiArea *area, uiAreaMouseEvent *e)
{
	// do nothing
}

__attribute__((used)) static void handlerMouseCrossed(uiAreaHandler *ah, uiArea *a, int left)
{
	// do nothing
}

__attribute__((used)) static void handlerDragBroken(uiAreaHandler *ah, uiArea *a)
{
	// do nothing
}

__attribute__((used)) static int handlerKeyEvent(uiAreaHandler *ah, uiArea *a, uiAreaKeyEvent *e)
{
	// reject all keys
	return 0;
}

__attribute__((used)) static void onFontChanged(uiFontButton *b, void *data)
{
	remakeAttrStr();
}

__attribute__((used)) static void onTextChanged(uiEntry *e, void *data)
{
	remakeAttrStr();
}

__attribute__((used)) static void onNULLToggled(uiCheckbox *c, void *data)
{
	remakeAttrStr();
}

__attribute__((used)) static int onClosing(uiWindow *w, void *data)
{
	// TODO change the others to be like this? (the others destroy here rather than later)
	// TODO move this below uiQuit()?
	uiControlHide(uiControl(w));
	uiQuit();
	return 0;
}

__attribute__((used)) static int shouldQuit(void *data)
{
	uiControlDestroy(uiControl(mainwin));
	return 1;
}

int main(void)
{
	uiInitOptions o;
	const char *err;
	uiGrid *grid;
	uiBox *vbox;

	handler.Draw = handlerDraw;
	handler.MouseEvent = handlerMouseEvent;
	handler.MouseCrossed = handlerMouseCrossed;
	handler.DragBroken = handlerDragBroken;
	handler.KeyEvent = handlerKeyEvent;

	memset(&o, 0, sizeof (uiInitOptions));
	err = uiInit(&o);
	if (err != NULL) {
		fprintf(stderr, "error initializing ui: %s\n", err);
		uiFreeInitError(err);
		return 1;
	}

	uiOnShouldQuit(shouldQuit, NULL);

	// TODO 800x600? the size of the GTK+ example?
	mainwin = uiNewWindow("libui OpenType Features Example", 640, 480, 1);
	uiWindowSetMargined(mainwin, 1);
	uiWindowOnClosing(mainwin, onClosing, NULL);

	grid = uiNewGrid();
	uiGridSetPadded(grid, 1);
	uiWindowSetChild(mainwin, uiControl(grid));

	fontButton = uiNewFontButton();
	uiFontButtonOnChanged(fontButton, onFontChanged, NULL);
	uiGridAppend(grid, uiControl(fontButton),
		0, 0, 1, 1,
		// TODO are these Y values correct?
		0, uiAlignFill, 0, uiAlignCenter);

	textEntry = uiNewEntry();
	uiEntrySetText(textEntry, "afford afire aflight");
	uiEntryOnChanged(textEntry, onTextChanged, NULL);
	uiGridAppend(grid, uiControl(textEntry),
		1, 0, 1, 1,
		// TODO are these Y values correct too?
		// TODO add a baseline align? or a form align?
		1, uiAlignFill, 0, uiAlignCenter);

	vbox = uiNewVerticalBox();
	uiBoxSetPadded(vbox, 1);
	uiGridAppend(grid, uiControl(vbox),
		0, 1, 1, 1,
		0, uiAlignFill, 1, uiAlignFill);

	nullFeatures = uiNewCheckbox("NULL uiOpenTypeFeatures");
	uiCheckboxOnToggled(nullFeatures, onNULLToggled, NULL);
	uiBoxAppend(vbox, uiControl(nullFeatures), 0);

	// TODO separator (if other stuff isn't a tab)

	// TODO needed for this to be testable on os x without rewriting everything again
	{
		int x;

		for (x = 0; x < 10; x++)
			uiBoxAppend(vbox, uiControl(uiNewEntry()), 0);
	}

	// TODO other stuff

	area = uiNewArea(&handler);
	uiGridAppend(grid, uiControl(area),
		1, 1, 1, 1,
		1, uiAlignFill, 1, uiAlignFill);

	// and set up the initial draw
	remakeAttrStr();

	uiControlShow(uiControl(mainwin));
	uiMain();

	uiControlDestroy(uiControl(mainwin));
	uiFreeAttributedString(attrstr);
	uiUninit();
	return 0;
}

