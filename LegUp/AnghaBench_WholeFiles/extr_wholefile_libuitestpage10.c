#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uiFontButton ;
typedef  int /*<<< orphan*/  uiEntry ;
typedef  int /*<<< orphan*/  uiDrawTextLayout ;
typedef  int /*<<< orphan*/  uiDrawTextFont ;
typedef  int /*<<< orphan*/  uiColorButton ;
typedef  int /*<<< orphan*/  uiCheckbox ;
typedef  int /*<<< orphan*/  uiBox ;
typedef  int /*<<< orphan*/  uiAreaMouseEvent ;
typedef  int /*<<< orphan*/  uiAreaKeyEvent ;
typedef  int /*<<< orphan*/  uiAreaHandler ;
struct TYPE_5__ {int /*<<< orphan*/  Context; } ;
typedef  TYPE_1__ uiAreaDrawParams ;
typedef  int /*<<< orphan*/  uiArea ;
struct TYPE_6__ {void (* Draw ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_1__*) ;void (* MouseEvent ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;void (* MouseCrossed ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ;void (* DragBroken ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;int (* KeyEvent ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;} ;

/* Variables and functions */
 double atof (char*) ; 
 int /*<<< orphan*/ * newHorizontalBox () ; 
 int /*<<< orphan*/ * newVerticalBox () ; 
 int /*<<< orphan*/ * noZ ; 
 int /*<<< orphan*/ * textApply ; 
 int /*<<< orphan*/ * textArea ; 
 TYPE_2__ textAreaHandler ; 
 int /*<<< orphan*/ * textColorButton ; 
 int /*<<< orphan*/ * textFontButton ; 
 int /*<<< orphan*/ * textString ; 
 int /*<<< orphan*/ * textWidth ; 
 int /*<<< orphan*/  uiAreaQueueRedrawAll (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiBoxAppend (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  uiCheckboxChecked (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiCheckboxOnToggled (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiColorButtonColor (int /*<<< orphan*/ *,double*,double*,double*,double*) ; 
 int /*<<< orphan*/  uiColorButtonOnChanged (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiControl (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiDrawFreeTextFont (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiDrawFreeTextLayout (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * uiDrawNewTextLayout (char*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  uiDrawText (int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiDrawTextLayoutExtents (int /*<<< orphan*/ *,double*,double*) ; 
 int /*<<< orphan*/  uiDrawTextLayoutSetColor (int /*<<< orphan*/ *,int,int,double,double,int,double) ; 
 int /*<<< orphan*/  uiEntrySetText (int /*<<< orphan*/ *,char*) ; 
 char* uiEntryText (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * uiFontButtonFont (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiFontButtonOnChanged (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiFreeText (char*) ; 
 int /*<<< orphan*/ * uiNewArea (TYPE_2__*) ; 
 int /*<<< orphan*/ * uiNewButton (char*) ; 
 int /*<<< orphan*/ * uiNewCheckbox (char*) ; 
 int /*<<< orphan*/ * uiNewColorButton () ; 
 int /*<<< orphan*/ * uiNewEntry () ; 
 int /*<<< orphan*/ * uiNewFontButton () ; 

__attribute__((used)) static double entryDouble(uiEntry *e)
{
	char *s;
	double d;

	s = uiEntryText(e);
	d = atof(s);
	uiFreeText(s);
	return d;
}

__attribute__((used)) static void handlerDraw(uiAreaHandler *a, uiArea *area, uiAreaDrawParams *dp)
{
	uiDrawTextFont *font;
	uiDrawTextLayout *layout;
	double r, g, b, al;
	char surrogates[1 + 4 + 1 + 1];
	char composed[2 + 2 + 2 + 3 + 2 + 1];
	double width, height;

	font = uiFontButtonFont(textFontButton);

	layout = uiDrawNewTextLayout("One two three four", font, -1);
	uiDrawTextLayoutSetColor(layout,
		4, 7,
		1, 0, 0, 1);
	uiDrawTextLayoutSetColor(layout,
		8, 14,
		1, 0, 0.5, 0.5);
	uiColorButtonColor(textColorButton, &r, &g, &b, &al);
	uiDrawTextLayoutSetColor(layout,
		14, 18,
		r, g, b, al);
	uiDrawText(dp->Context, 10, 10, layout);
	uiDrawTextLayoutExtents(layout, &width, &height);
	uiDrawFreeTextLayout(layout);

	surrogates[0] = 'x';
	surrogates[1] = 0xF0;		// surrogates D800 DF08
	surrogates[2] = 0x90;
	surrogates[3] = 0x8C;
	surrogates[4] = 0x88;
	surrogates[5] = 'y';
	surrogates[6] = '\0';

	layout = uiDrawNewTextLayout(surrogates, font, -1);
	uiDrawTextLayoutSetColor(layout,
		1, 2,
		1, 0, 0.5, 0.5);
	uiDrawText(dp->Context, 10, 10 + height, layout);
	uiDrawFreeTextLayout(layout);

	composed[0] = 'z';
	composed[1] = 'z';
	composed[2] = 0xC3;		// 2
	composed[3] = 0xA9;
	composed[4] = 'z';
	composed[5] = 'z';
	composed[6] = 0x65;		// 5
	composed[7] = 0xCC;
	composed[8] = 0x81;
	composed[9] = 'z';
	composed[10] = 'z';
	composed[11] = '\0';

	layout = uiDrawNewTextLayout(composed, font, -1);
	uiDrawTextLayoutSetColor(layout,
		2, 3,
		1, 0, 0.5, 0.5);
	uiDrawTextLayoutSetColor(layout,
		5, 6,
		1, 0, 0.5, 0.5);
	if (!uiCheckboxChecked(noZ))
		uiDrawTextLayoutSetColor(layout,
			6, 7,
			0.5, 0, 1, 0.5);
	uiDrawText(dp->Context, 10, 10 + height + height, layout);
	uiDrawFreeTextLayout(layout);

	uiDrawFreeTextFont(font);
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
	// do nothing
	return 0;
}

__attribute__((used)) static void onFontChanged(uiFontButton *b, void *data)
{
	uiAreaQueueRedrawAll(textArea);
}

__attribute__((used)) static void onColorChanged(uiColorButton *b, void *data)
{
	uiAreaQueueRedrawAll(textArea);
}

__attribute__((used)) static void onNoZ(uiCheckbox *b, void *data)
{
	uiAreaQueueRedrawAll(textArea);
}

uiBox *makePage10(void)
{
	uiBox *page10;
	uiBox *vbox;
	uiBox *hbox;

	page10 = newVerticalBox();
	vbox = page10;

	hbox = newHorizontalBox();
	uiBoxAppend(vbox, uiControl(hbox), 0);

	textString = uiNewEntry();
	// TODO make it placeholder
	uiEntrySetText(textString, "Enter text here");
	uiBoxAppend(hbox, uiControl(textString), 1);

	textFontButton = uiNewFontButton();
	uiFontButtonOnChanged(textFontButton, onFontChanged, NULL);
	uiBoxAppend(hbox, uiControl(textFontButton), 1);

	textColorButton = uiNewColorButton();
	uiColorButtonOnChanged(textColorButton, onColorChanged, NULL);
	uiBoxAppend(hbox, uiControl(textColorButton), 1);

	hbox = newHorizontalBox();
	uiBoxAppend(vbox, uiControl(hbox), 0);

	textApply = uiNewButton("Apply");
	uiBoxAppend(hbox, uiControl(textApply), 1);

	textWidth = uiNewEntry();
	uiEntrySetText(textWidth, "-1");
	uiBoxAppend(hbox, uiControl(textWidth), 1);

	noZ = uiNewCheckbox("No Z Color");
	uiCheckboxOnToggled(noZ, onNoZ, NULL);
	uiBoxAppend(hbox, uiControl(noZ), 0);

	textAreaHandler.Draw = handlerDraw;
	textAreaHandler.MouseEvent = handlerMouseEvent;
	textAreaHandler.MouseCrossed = handlerMouseCrossed;
	textAreaHandler.DragBroken = handlerDragBroken;
	textAreaHandler.KeyEvent = handlerKeyEvent;
	textArea = uiNewArea(&textAreaHandler);
	uiBoxAppend(vbox, uiControl(textArea), 1);

	// dummy objects to test single-activation
	hbox = newHorizontalBox();
	uiBoxAppend(vbox, uiControl(hbox), 0);
	uiBoxAppend(hbox, uiControl(uiNewFontButton()), 1);
	uiBoxAppend(hbox, uiControl(uiNewColorButton()), 1);

	return page10;
}

