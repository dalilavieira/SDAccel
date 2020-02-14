#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_6__ ;
typedef  struct TYPE_17__   TYPE_5__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uiEntry ;
typedef  int /*<<< orphan*/  uiDrawTextLayout ;
struct TYPE_15__ {double Leading; double Ascent; double Descent; } ;
typedef  TYPE_1__ uiDrawTextFontMetrics ;
struct TYPE_16__ {int Thickness; double R; double G; double B; double A; char* Family; double Size; void* Stretch; void* Italic; void* Weight; int /*<<< orphan*/  MiterLimit; int /*<<< orphan*/  Join; int /*<<< orphan*/  Cap; int /*<<< orphan*/  Type; } ;
typedef  TYPE_2__ uiDrawTextFontDescriptor ;
typedef  int /*<<< orphan*/  uiDrawTextFont ;
typedef  TYPE_2__ uiDrawStrokeParams ;
typedef  int /*<<< orphan*/  uiDrawPath ;
typedef  int /*<<< orphan*/  uiDrawContext ;
typedef  TYPE_2__ uiDrawBrush ;
typedef  int /*<<< orphan*/  uiButton ;
typedef  int /*<<< orphan*/  uiBox ;
typedef  int /*<<< orphan*/  uiAreaMouseEvent ;
typedef  int /*<<< orphan*/  uiAreaKeyEvent ;
typedef  int /*<<< orphan*/  uiAreaHandler ;
struct TYPE_17__ {int /*<<< orphan*/ * Context; } ;
typedef  TYPE_5__ uiAreaDrawParams ;
typedef  int /*<<< orphan*/  uiArea ;
struct TYPE_18__ {void (* Draw ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_5__*) ;void (* MouseEvent ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;void (* MouseCrossed ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ;void (* DragBroken ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;int (* KeyEvent ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;} ;

/* Variables and functions */
 int /*<<< orphan*/ * addLeading ; 
 double atof (char*) ; 
 int /*<<< orphan*/  memset (TYPE_2__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/ * newHorizontalBox () ; 
 int /*<<< orphan*/ * newVerticalBox () ; 
 int /*<<< orphan*/  printf (char*,double,double) ; 
 int /*<<< orphan*/ * textApply ; 
 int /*<<< orphan*/ * textArea ; 
 TYPE_6__ textAreaHandler ; 
 int /*<<< orphan*/ * textFont ; 
 int /*<<< orphan*/ * textItalic ; 
 int /*<<< orphan*/ * textSize ; 
 int /*<<< orphan*/ * textSmallCaps ; 
 int /*<<< orphan*/ * textStretch ; 
 int /*<<< orphan*/ * textString ; 
 int /*<<< orphan*/ * textWeight ; 
 int /*<<< orphan*/ * textWidth ; 
 int /*<<< orphan*/  uiAreaQueueRedrawAll (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiBoxAppend (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  uiButtonOnClicked (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,void*),int /*<<< orphan*/ *) ; 
 scalar_t__ uiCheckboxChecked (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiCheckboxSetChecked (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  uiComboboxAppend (int /*<<< orphan*/ *,char*) ; 
 void* uiComboboxSelected (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiComboboxSetSelected (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiControl (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiDrawBrushTypeSolid ; 
 int /*<<< orphan*/  uiDrawClip (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiDrawDefaultMiterLimit ; 
 int /*<<< orphan*/  uiDrawFillModeWinding ; 
 int /*<<< orphan*/  uiDrawFreePath (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiDrawFreeTextFont (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiDrawFreeTextLayout (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiDrawLineCapFlat ; 
 int /*<<< orphan*/  uiDrawLineJoinMiter ; 
 int /*<<< orphan*/ * uiDrawLoadClosestFont (TYPE_2__*) ; 
 int /*<<< orphan*/ * uiDrawNewPath (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * uiDrawNewTextLayout (char*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  uiDrawPathAddRectangle (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  uiDrawPathEnd (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiDrawPathLineTo (int /*<<< orphan*/ *,int,double) ; 
 int /*<<< orphan*/  uiDrawPathNewFigure (int /*<<< orphan*/ *,int,double) ; 
 int /*<<< orphan*/  uiDrawRestore (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiDrawSave (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiDrawStroke (int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_2__*,TYPE_2__*) ; 
 int /*<<< orphan*/  uiDrawText (int /*<<< orphan*/ *,int,double,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiDrawTextFontGetMetrics (int /*<<< orphan*/ *,TYPE_1__*) ; 
 int /*<<< orphan*/  uiDrawTextItalicNormal ; 
 int /*<<< orphan*/  uiDrawTextLayoutExtents (int /*<<< orphan*/ *,double*,double*) ; 
 int /*<<< orphan*/  uiDrawTextStretchNormal ; 
 int /*<<< orphan*/  uiDrawTextWeightNormal ; 
 int /*<<< orphan*/  uiEntrySetText (int /*<<< orphan*/ *,char*) ; 
 char* uiEntryText (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiFreeText (char*) ; 
 int /*<<< orphan*/ * uiNewArea (TYPE_6__*) ; 
 int /*<<< orphan*/ * uiNewButton (char*) ; 
 int /*<<< orphan*/ * uiNewCheckbox (char*) ; 
 int /*<<< orphan*/ * uiNewCombobox () ; 
 int /*<<< orphan*/ * uiNewEntry () ; 

__attribute__((used)) static double entryDouble(uiEntry *e)
{
	char *s;
	double d;

	s = uiEntryText(e);
	d = atof(s);
	uiFreeText(s);
	return d;
}

__attribute__((used)) static void drawGuides(uiDrawContext *c, uiDrawTextFontMetrics *m)
{
	uiDrawPath *p;
	uiDrawBrush b;
	uiDrawStrokeParams sp;
	double leading;
	double y;

	leading = 0;
	if (uiCheckboxChecked(addLeading))
		leading = m->Leading;

	memset(&b, 0, sizeof (uiDrawBrush));
	b.Type = uiDrawBrushTypeSolid;
	memset(&sp, 0, sizeof (uiDrawStrokeParams));
	sp.Cap = uiDrawLineCapFlat;
	sp.Join = uiDrawLineJoinMiter;
	sp.MiterLimit = uiDrawDefaultMiterLimit;
	sp.Thickness = 2;

	uiDrawSave(c);

	p = uiDrawNewPath(uiDrawFillModeWinding);
	y = 10;
	uiDrawPathNewFigure(p, 8, y);
	y += m->Ascent;
	uiDrawPathLineTo(p, 8, y);
	uiDrawPathEnd(p);
	b.R = 0.94;
	b.G = 0.5;
	b.B = 0.5;
	b.A = 1.0;
	uiDrawStroke(c, p, &b, &sp);
	uiDrawFreePath(p);

	p = uiDrawNewPath(uiDrawFillModeWinding);
	uiDrawPathNewFigure(p, 8, y);
	y += m->Descent;
	uiDrawPathLineTo(p, 8, y);
	uiDrawPathEnd(p);
	b.R = 0.12;
	b.G = 0.56;
	b.B = 1.0;
	b.A = 1.0;
	uiDrawStroke(c, p, &b, &sp);
	uiDrawFreePath(p);

	// and again for the second line
	p = uiDrawNewPath(uiDrawFillModeWinding);
	y += leading;
	uiDrawPathNewFigure(p, 8, y);
	y += m->Ascent;
	uiDrawPathLineTo(p, 8, y);
	uiDrawPathEnd(p);
	b.R = 0.94;
	b.G = 0.5;
	b.B = 0.5;
	b.A = 0.75;
	uiDrawStroke(c, p, &b, &sp);
	uiDrawFreePath(p);

	p = uiDrawNewPath(uiDrawFillModeWinding);
	uiDrawPathNewFigure(p, 8, y);
	y += m->Descent;
	uiDrawPathLineTo(p, 8, y);
	uiDrawPathEnd(p);
	b.R = 0.12;
	b.G = 0.56;
	b.B = 1.0;
	b.A = 0.75;
	uiDrawStroke(c, p, &b, &sp);
	uiDrawFreePath(p);

	// and a box to text layout top-left corners
	p = uiDrawNewPath(uiDrawFillModeWinding);
	uiDrawPathAddRectangle(p, 0, 0, 10, 10);
	uiDrawPathEnd(p);
	uiDrawClip(c, p);
	b.R = 0.85;
	b.G = 0.65;
	b.B = 0.13;
	b.A = 1.0;
	uiDrawStroke(c, p, &b, &sp);
	uiDrawFreePath(p);

	uiDrawRestore(c);
}

__attribute__((used)) static void handlerDraw(uiAreaHandler *a, uiArea *area, uiAreaDrawParams *dp)
{
	uiDrawTextFontDescriptor desc;
	uiDrawTextFont *font;
	char *s;
	char *family;		// make compiler happy
	uiDrawTextLayout *layout;
	uiDrawTextFontMetrics metrics;
	double ypos;
	double width;
	double height;

	memset(&desc, 0, sizeof (uiDrawTextFontDescriptor));
	family = uiEntryText(textFont);
	desc.Family = family;
	desc.Size = entryDouble(textSize);
	desc.Weight = uiComboboxSelected(textWeight);
	desc.Italic = uiComboboxSelected(textItalic);
	desc.Stretch = uiComboboxSelected(textStretch);
	font = uiDrawLoadClosestFont(&desc);
	uiFreeText(family);
	uiDrawTextFontGetMetrics(font, &metrics);

	width = entryDouble(textWidth);

	drawGuides(dp->Context, &metrics);

	s = uiEntryText(textString);
	layout = uiDrawNewTextLayout(s, font, width);
	uiFreeText(s);
	if (uiCheckboxChecked(textSmallCaps))
		;	// TODO
	ypos = 10;
	uiDrawText(dp->Context, 10, ypos, layout);
	// TODO make these optional?
	uiDrawTextLayoutExtents(layout, &width, &height);
	uiDrawFreeTextLayout(layout);

	layout = uiDrawNewTextLayout("This is a second line", font, -1);
	if (/*TODO reuse width*/entryDouble(textWidth) < 0) {
		double ad;

		ad = metrics.Ascent + metrics.Descent;
		printf("ad:%g extent:%g\n", ad, height);
	}
	ypos += height;
	if (uiCheckboxChecked(addLeading))
		ypos += metrics.Leading;
	uiDrawText(dp->Context, 10, ypos, layout);
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

__attribute__((used)) static void onTextApply(uiButton *b, void *data)
{
	uiAreaQueueRedrawAll(textArea);
}

uiBox *makePage9(void)
{
	uiBox *page9;
	uiBox *vbox;
	uiBox *hbox;

	page9 = newVerticalBox();
	vbox = page9;

	hbox = newHorizontalBox();
	uiBoxAppend(vbox, uiControl(hbox), 0);

	textString = uiNewEntry();
	// TODO make it placeholder
	uiEntrySetText(textString, "Enter text here");
	uiBoxAppend(hbox, uiControl(textString), 1);

	textFont = uiNewEntry();
	uiEntrySetText(textFont, "Arial");
	uiBoxAppend(hbox, uiControl(textFont), 1);

	textSize = uiNewEntry();
	uiEntrySetText(textSize, "10");
	uiBoxAppend(hbox, uiControl(textSize), 1);

	hbox = newHorizontalBox();
	uiBoxAppend(vbox, uiControl(hbox), 0);

	textWeight = uiNewCombobox();
	uiComboboxAppend(textWeight, "Thin");
	uiComboboxAppend(textWeight, "Ultra Light");
	uiComboboxAppend(textWeight, "Light");
	uiComboboxAppend(textWeight, "Book");
	uiComboboxAppend(textWeight, "Normal");
	uiComboboxAppend(textWeight, "Medium");
	uiComboboxAppend(textWeight, "Semi Bold");
	uiComboboxAppend(textWeight, "Bold");
	uiComboboxAppend(textWeight, "Ultra Bold");
	uiComboboxAppend(textWeight, "Heavy");
	uiComboboxAppend(textWeight, "Ultra Heavy");
	uiComboboxSetSelected(textWeight, uiDrawTextWeightNormal);
	uiBoxAppend(hbox, uiControl(textWeight), 1);

	textItalic = uiNewCombobox();
	uiComboboxAppend(textItalic, "Normal");
	uiComboboxAppend(textItalic, "Oblique");
	uiComboboxAppend(textItalic, "Italic");
	uiComboboxSetSelected(textItalic, uiDrawTextItalicNormal);
	uiBoxAppend(hbox, uiControl(textItalic), 1);

	textSmallCaps = uiNewCheckbox("Small Caps");
	uiBoxAppend(hbox, uiControl(textSmallCaps), 1);

	hbox = newHorizontalBox();
	uiBoxAppend(vbox, uiControl(hbox), 0);

	textStretch = uiNewCombobox();
	uiComboboxAppend(textStretch, "Ultra Condensed");
	uiComboboxAppend(textStretch, "Extra Condensed");
	uiComboboxAppend(textStretch, "Condensed");
	uiComboboxAppend(textStretch, "Semi Condensed");
	uiComboboxAppend(textStretch, "Normal");
	uiComboboxAppend(textStretch, "Semi Expanded");
	uiComboboxAppend(textStretch, "Expanded");
	uiComboboxAppend(textStretch, "Extra Expanded");
	uiComboboxAppend(textStretch, "Ultra Expanded");
	uiComboboxSetSelected(textStretch, uiDrawTextStretchNormal);
	uiBoxAppend(hbox, uiControl(textStretch), 1);

	textWidth = uiNewEntry();
	uiEntrySetText(textWidth, "-1");
	uiBoxAppend(hbox, uiControl(textWidth), 1);

	hbox = newHorizontalBox();
	uiBoxAppend(vbox, uiControl(hbox), 0);

	textApply = uiNewButton("Apply");
	uiButtonOnClicked(textApply, onTextApply, NULL);
	uiBoxAppend(hbox, uiControl(textApply), 1);

	addLeading = uiNewCheckbox("Add Leading");
	uiCheckboxSetChecked(addLeading, 1);
	uiBoxAppend(hbox, uiControl(addLeading), 0);

	textAreaHandler.Draw = handlerDraw;
	textAreaHandler.MouseEvent = handlerMouseEvent;
	textAreaHandler.MouseCrossed = handlerMouseCrossed;
	textAreaHandler.DragBroken = handlerDragBroken;
	textAreaHandler.KeyEvent = handlerKeyEvent;
	textArea = uiNewArea(&textAreaHandler);
	uiBoxAppend(vbox, uiControl(textArea), 1);

	return page9;
}

