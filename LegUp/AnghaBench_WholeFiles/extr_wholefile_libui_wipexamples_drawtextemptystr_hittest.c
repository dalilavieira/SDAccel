#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_7__ ;
typedef  struct TYPE_17__   TYPE_5__ ;
typedef  struct TYPE_16__   TYPE_4__ ;
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uiFontButton ;
struct TYPE_13__ {int X; int Y; scalar_t__ Height; scalar_t__ Width; } ;
typedef  TYPE_1__ uiDrawTextLayoutLineMetrics ;
typedef  int /*<<< orphan*/  uiDrawTextLayout ;
typedef  scalar_t__ uiDrawTextAlign ;
typedef  int /*<<< orphan*/  uiDrawPath ;
typedef  int /*<<< orphan*/  uiCombobox ;
typedef  int /*<<< orphan*/  uiCheckbox ;
typedef  int /*<<< orphan*/  uiBox ;
struct TYPE_14__ {int Down; scalar_t__ Y; scalar_t__ X; scalar_t__ AreaWidth; } ;
typedef  TYPE_2__ uiAreaMouseEvent ;
struct TYPE_15__ {scalar_t__ Key; int ExtKey; scalar_t__ Up; } ;
typedef  TYPE_3__ uiAreaKeyEvent ;
struct TYPE_16__ {int /*<<< orphan*/  Context; scalar_t__ AreaWidth; scalar_t__ AreaHeight; } ;
typedef  TYPE_4__ uiAreaDrawParams ;
struct example {char* name; void (* draw ) (TYPE_4__*) ;void (* mouse ) (TYPE_2__*) ;int (* key ) (TYPE_3__*) ;int /*<<< orphan*/  panel; } ;
struct TYPE_18__ {scalar_t__ Align; TYPE_5__* DefaultFont; int /*<<< orphan*/  String; scalar_t__ Width; } ;
struct TYPE_17__ {scalar_t__ Family; double Size; scalar_t__ Stretch; scalar_t__ Italic; scalar_t__ Weight; } ;

/* Variables and functions */
 int /*<<< orphan*/  attrstr ; 
 int /*<<< orphan*/ * caretLabel ; 
 int caretLine ; 
 scalar_t__ caretPos ; 
 TYPE_5__ defaultFont ; 
 scalar_t__ fillBrushes ; 
 int /*<<< orphan*/ * fontButton ; 
 scalar_t__ fontFamily ; 
 struct example hitTestExample ; 
 int margins ; 
 int /*<<< orphan*/ * panel ; 
 TYPE_7__ params ; 
 int /*<<< orphan*/  printf (char*,scalar_t__,double,int,int,int) ; 
 int /*<<< orphan*/  redraw () ; 
 int /*<<< orphan*/ * showLineBounds ; 
 int /*<<< orphan*/  sprintf (char*,char*,int,int) ; 
 int /*<<< orphan*/  text ; 
 int /*<<< orphan*/ * textAlign ; 
 size_t uiAttributedStringByteIndexToGrapheme (int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ uiAttributedStringGraphemeToByteIndex (int /*<<< orphan*/ ,size_t) ; 
 scalar_t__ uiAttributedStringLen (int /*<<< orphan*/ ) ; 
 size_t uiAttributedStringNumGraphemes (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiBoxAppend (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 scalar_t__ uiCheckboxChecked (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiCheckboxOnToggled (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiComboboxAppend (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  uiComboboxOnSelected (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,void*),int /*<<< orphan*/ *) ; 
 scalar_t__ uiComboboxSelected (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiControl (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiDrawCaret (int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ *,scalar_t__,int*) ; 
 int /*<<< orphan*/  uiDrawClip (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiDrawFill (int /*<<< orphan*/ ,int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  uiDrawFillModeWinding ; 
 int /*<<< orphan*/  uiDrawFreePath (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiDrawFreeTextLayout (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * uiDrawNewPath (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * uiDrawNewTextLayout (TYPE_7__*) ; 
 int /*<<< orphan*/  uiDrawPathAddRectangle (int /*<<< orphan*/ *,int,int,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  uiDrawPathEnd (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiDrawRestore (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiDrawSave (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiDrawText (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int) ; 
 scalar_t__ uiDrawTextAlignLeft ; 
 int /*<<< orphan*/  uiDrawTextLayoutHitTest (int /*<<< orphan*/ *,scalar_t__,scalar_t__,scalar_t__*,int*) ; 
 int /*<<< orphan*/  uiDrawTextLayoutLineGetMetrics (int /*<<< orphan*/ *,int,TYPE_1__*) ; 
 int uiDrawTextLayoutNumLines (int /*<<< orphan*/ *) ; 
#define  uiExtKeyDown 131 
#define  uiExtKeyLeft 130 
#define  uiExtKeyRight 129 
#define  uiExtKeyUp 128 
 int /*<<< orphan*/  uiFontButtonFont (int /*<<< orphan*/ *,TYPE_5__*) ; 
 int /*<<< orphan*/  uiFontButtonOnChanged (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiFreeText (scalar_t__) ; 
 int /*<<< orphan*/  uiLabelSetText (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  uiNewAttributedString (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * uiNewCheckbox (char const*) ; 
 int /*<<< orphan*/ * uiNewCombobox () ; 
 int /*<<< orphan*/ * uiNewFontButton () ; 
 int /*<<< orphan*/ * uiNewHorizontalBox () ; 
 int /*<<< orphan*/ * uiNewLabel (char*) ; 
 int /*<<< orphan*/ * uiNewVerticalBox () ; 
 int /*<<< orphan*/ * vbox ; 

__attribute__((used)) static void draw(uiAreaDrawParams *p)
{
	uiDrawPath *path;
	uiDrawTextLayout *layout;
	uiDrawTextLayoutLineMetrics m;

	// only clip the text, not the guides
	uiDrawSave(p->Context);

	path = uiDrawNewPath(uiDrawFillModeWinding);
	uiDrawPathAddRectangle(path, margins, margins,
		p->AreaWidth - 2 * margins,
		p->AreaHeight - 2 * margins);
	uiDrawPathEnd(path);
	uiDrawClip(p->Context, path);
	uiDrawFreePath(path);

	params.Width = p->AreaWidth - 2 * margins;
	layout = uiDrawNewTextLayout(&params);
	uiDrawText(p->Context, layout, margins, margins);

	uiDrawRestore(p->Context);

	if (caretLine == -1) {
		caretLine = uiDrawTextLayoutNumLines(layout) - 1;
		caretPos = uiAttributedStringLen(attrstr);
	}
	uiDrawCaret(p->Context, margins, margins,
		layout, caretPos, &caretLine);

	if (uiCheckboxChecked(showLineBounds)) {
		int i, n;
		int fill = 0;

		n = uiDrawTextLayoutNumLines(layout);
		for (i = 0; i < n; i++) {
			uiDrawTextLayoutLineGetMetrics(layout, i, &m);
			path = uiDrawNewPath(uiDrawFillModeWinding);
			uiDrawPathAddRectangle(path, margins + m.X, margins + m.Y,
				m.Width, m.Height);
			uiDrawPathEnd(path);
			uiDrawFill(p->Context, path, fillBrushes + fill);
			uiDrawFreePath(path);
			fill = (fill + 1) % 4;
		}
	}

	uiDrawFreeTextLayout(layout);
}

__attribute__((used)) static void mouse(uiAreaMouseEvent *e)
{
	uiDrawTextLayout *layout;
	char labelText[128];

	if (e->Down != 1)
		return;

	params.Width = e->AreaWidth - 2 * margins;
	layout = uiDrawNewTextLayout(&params);
	uiDrawTextLayoutHitTest(layout,
		e->X - margins, e->Y - margins,
		&caretPos, &caretLine);
	uiDrawFreeTextLayout(layout);

	// TODO move this into the draw handler so it is reflected by keyboard-based position changes
	// urgh %zd is not supported by MSVC with sprintf()
	// TODO get that part in test/ about having no other option
	sprintf(labelText, "pos %d line %d",
		(int) caretPos, caretLine);
	uiLabelSetText(caretLabel, labelText);

	redraw();
}

__attribute__((used)) static int key(uiAreaKeyEvent *e)
{
	size_t grapheme;

	if (e->Up)
		return 0;
	if (e->Key != 0)
		return 0;
	switch (e->ExtKey) {
	case uiExtKeyUp:
		// TODO
		return 1;
	case uiExtKeyDown:
		// TODO
		return 1;
	case uiExtKeyLeft:
		grapheme = uiAttributedStringByteIndexToGrapheme(attrstr, caretPos);
		if (grapheme == 0)
			return 0;
		grapheme--;
		caretPos = uiAttributedStringGraphemeToByteIndex(attrstr, grapheme);
		redraw();
		return 1;
	case uiExtKeyRight:
		grapheme = uiAttributedStringByteIndexToGrapheme(attrstr, caretPos);
		if (grapheme == uiAttributedStringNumGraphemes(attrstr))
			return 0;
		grapheme++;
		caretPos = uiAttributedStringGraphemeToByteIndex(attrstr, grapheme);
		redraw();
		return 1;
	}
	return 0;
}

__attribute__((used)) static void checkboxChecked(uiCheckbox *c, void *data)
{
	redraw();
}

__attribute__((used)) static void changeFont(uiFontButton *b, void *data)
{
	if (defaultFont.Family != fontFamily)
		uiFreeText(defaultFont.Family);
	// TODO rename defaultFont
	uiFontButtonFont(fontButton, &defaultFont);
	printf("{\n\tfamily: %s\n\tsize: %g\n\tweight: %d\n\titalic: %d\n\tstretch: %d\n}\n",
		defaultFont.Family,
		defaultFont.Size,
		(int) (defaultFont.Weight),
		(int) (defaultFont.Italic),
		(int) (defaultFont.Stretch));
	redraw();
}

__attribute__((used)) static void changeTextAlign(uiCombobox *c, void *data)
{
	// note the order of the items added below
	params.Align = (uiDrawTextAlign) uiComboboxSelected(textAlign);
	redraw();
}

__attribute__((used)) static uiCheckbox *newCheckbox(uiBox *box, const char *text)
{
	uiCheckbox *c;

	c = uiNewCheckbox(text);
	uiCheckboxOnToggled(c, checkboxChecked, NULL);
	uiBoxAppend(box, uiControl(c), 0);
	return c;
}

struct example *mkEmptyStringExample(void)
{
	panel = uiNewHorizontalBox();
	vbox = uiNewVerticalBox();
	// TODO the second vbox causes this not to stretch at least on OS X
	uiBoxAppend(panel, uiControl(vbox), 1);
	caretLabel = uiNewLabel("Caret information is shown here");
	uiBoxAppend(vbox, uiControl(caretLabel), 0);
	showLineBounds = newCheckbox(vbox, "Show Line Bounds (for debugging metrics)");
	vbox = uiNewVerticalBox();
	uiBoxAppend(panel, uiControl(vbox), 0);
	fontButton = uiNewFontButton();
	uiFontButtonOnChanged(fontButton, changeFont, NULL);
	// TODO set the font button to the current defaultFont
	uiBoxAppend(vbox, uiControl(fontButton), 0);
	textAlign = uiNewCombobox();
	// note that these are in the order in the enum
	uiComboboxAppend(textAlign, "Left");
	uiComboboxAppend(textAlign, "Center");
	uiComboboxAppend(textAlign, "Right");
	uiComboboxOnSelected(textAlign, changeTextAlign, NULL);
	uiBoxAppend(vbox, uiControl(textAlign), 0);

	hitTestExample.name = "Empty String";
	hitTestExample.panel = uiControl(panel);
	hitTestExample.draw = draw;
	hitTestExample.mouse = mouse;
	hitTestExample.key = key;

	attrstr = uiNewAttributedString(text);
	params.String = attrstr;
	params.DefaultFont = &defaultFont;
	params.Align = uiDrawTextAlignLeft;

	return &hitTestExample;
}

