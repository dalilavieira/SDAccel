#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uiWindow ;
typedef  int /*<<< orphan*/  uiOpenTypeFeatures ;
typedef  int /*<<< orphan*/  uiInitOptions ;
typedef  int /*<<< orphan*/  uiForm ;
typedef  int /*<<< orphan*/  uiFontDescriptor ;
typedef  int /*<<< orphan*/  uiFontButton ;
struct TYPE_7__ {scalar_t__ Align; int /*<<< orphan*/  Width; int /*<<< orphan*/ * DefaultFont; int /*<<< orphan*/  String; } ;
typedef  TYPE_1__ uiDrawTextLayoutParams ;
typedef  int /*<<< orphan*/  uiDrawTextLayout ;
typedef  scalar_t__ uiDrawTextAlign ;
typedef  int /*<<< orphan*/  uiCombobox ;
typedef  int /*<<< orphan*/  uiBox ;
typedef  int /*<<< orphan*/  uiAttribute ;
typedef  int /*<<< orphan*/  uiAreaMouseEvent ;
typedef  int /*<<< orphan*/  uiAreaKeyEvent ;
typedef  int /*<<< orphan*/  uiAreaHandler ;
struct TYPE_8__ {int /*<<< orphan*/  Context; int /*<<< orphan*/  AreaWidth; } ;
typedef  TYPE_2__ uiAreaDrawParams ;
typedef  int /*<<< orphan*/  uiArea ;
struct TYPE_9__ {void (* Draw ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_2__*) ;void (* MouseEvent ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;void (* MouseCrossed ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ;void (* DragBroken ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;int (* KeyEvent ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;} ;

/* Variables and functions */
 int /*<<< orphan*/ * alignment ; 
 int /*<<< orphan*/ * area ; 
 int /*<<< orphan*/  attrstr ; 
 int /*<<< orphan*/ * fontButton ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char const*) ; 
 TYPE_3__ handler ; 
 int /*<<< orphan*/ * mainwin ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stderr ; 
 size_t strlen (char const*) ; 
 int /*<<< orphan*/  uiAreaQueueRedrawAll (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiAttributedStringAppendUnattributed (int /*<<< orphan*/ ,char const*) ; 
 size_t uiAttributedStringLen (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiAttributedStringSetAttribute (int /*<<< orphan*/ ,int /*<<< orphan*/ *,size_t,size_t) ; 
 int /*<<< orphan*/  uiBoxAppend (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  uiBoxSetPadded (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  uiComboboxAppend (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  uiComboboxOnSelected (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,void*),int /*<<< orphan*/ *) ; 
 scalar_t__ uiComboboxSelected (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiComboboxSetSelected (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiControl (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiControlDestroy (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiControlShow (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiDrawFreeTextLayout (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * uiDrawNewTextLayout (TYPE_1__*) ; 
 int /*<<< orphan*/  uiDrawText (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiFontButtonFont (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiFontButtonOnChanged (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiFormAppend (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiFormSetPadded (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  uiFreeAttributedString (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiFreeFontButtonFont (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiFreeInitError (char const*) ; 
 int /*<<< orphan*/  uiFreeOpenTypeFeatures (int /*<<< orphan*/ *) ; 
 char* uiInit (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiMain () ; 
 int /*<<< orphan*/ * uiNewArea (TYPE_3__*) ; 
 int /*<<< orphan*/  uiNewAttributedString (char*) ; 
 int /*<<< orphan*/ * uiNewBackgroundAttribute (double,double,double,double) ; 
 int /*<<< orphan*/ * uiNewColorAttribute (double,double,double,double) ; 
 int /*<<< orphan*/ * uiNewCombobox () ; 
 int /*<<< orphan*/ * uiNewFamilyAttribute (char*) ; 
 int /*<<< orphan*/ * uiNewFeaturesAttribute (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * uiNewFontButton () ; 
 int /*<<< orphan*/ * uiNewForm () ; 
 int /*<<< orphan*/ * uiNewHorizontalBox () ; 
 int /*<<< orphan*/ * uiNewItalicAttribute (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * uiNewOpenTypeFeatures () ; 
 int /*<<< orphan*/ * uiNewSizeAttribute (int) ; 
 int /*<<< orphan*/ * uiNewStretchAttribute (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * uiNewUnderlineAttribute (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * uiNewUnderlineColorAttribute (int /*<<< orphan*/ ,double,double,double,double) ; 
 int /*<<< orphan*/ * uiNewVerticalBox () ; 
 int /*<<< orphan*/ * uiNewWeightAttribute (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * uiNewWindow (char*,int,int,int) ; 
 int /*<<< orphan*/  uiOnShouldQuit (int (*) (void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiOpenTypeFeaturesAdd (int /*<<< orphan*/ *,char,char,char,char,int) ; 
 int /*<<< orphan*/  uiQuit () ; 
 int /*<<< orphan*/  uiTextItalicItalic ; 
 int /*<<< orphan*/  uiTextStretchCondensed ; 
 int /*<<< orphan*/  uiTextWeightBold ; 
 int /*<<< orphan*/  uiUnderlineColorCustom ; 
 int /*<<< orphan*/  uiUnderlineColorSpelling ; 
 int /*<<< orphan*/  uiUnderlineDouble ; 
 int /*<<< orphan*/  uiUnderlineSingle ; 
 int /*<<< orphan*/  uiUnderlineSuggestion ; 
 int /*<<< orphan*/  uiUninit () ; 
 int /*<<< orphan*/  uiWindowOnClosing (int /*<<< orphan*/ *,int (*) (int /*<<< orphan*/ *,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiWindowSetChild (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiWindowSetMargined (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static void appendWithAttribute(const char *what, uiAttribute *attr, uiAttribute *attr2)
{
	size_t start, end;

	start = uiAttributedStringLen(attrstr);
	end = start + strlen(what);
	uiAttributedStringAppendUnattributed(attrstr, what);
	uiAttributedStringSetAttribute(attrstr, attr, start, end);
	if (attr2 != NULL)
		uiAttributedStringSetAttribute(attrstr, attr2, start, end);
}

__attribute__((used)) static void makeAttributedString(void)
{
	uiAttribute *attr, *attr2;
	uiOpenTypeFeatures *otf;

	attrstr = uiNewAttributedString(
		"Drawing strings with libui is done with the uiAttributedString and uiDrawTextLayout objects.\n"
		"uiAttributedString lets you have a variety of attributes: ");

	attr = uiNewFamilyAttribute("Courier New");
	appendWithAttribute("font family", attr, NULL);
	uiAttributedStringAppendUnattributed(attrstr, ", ");

	attr = uiNewSizeAttribute(18);
	appendWithAttribute("font size", attr, NULL);
	uiAttributedStringAppendUnattributed(attrstr, ", ");

	attr = uiNewWeightAttribute(uiTextWeightBold);
	appendWithAttribute("font weight", attr, NULL);
	uiAttributedStringAppendUnattributed(attrstr, ", ");

	attr = uiNewItalicAttribute(uiTextItalicItalic);
	appendWithAttribute("font italicness", attr, NULL);
	uiAttributedStringAppendUnattributed(attrstr, ", ");

	attr = uiNewStretchAttribute(uiTextStretchCondensed);
	appendWithAttribute("font stretch", attr, NULL);
	uiAttributedStringAppendUnattributed(attrstr, ", ");

	attr = uiNewColorAttribute(0.75, 0.25, 0.5, 0.75);
	appendWithAttribute("text color", attr, NULL);
	uiAttributedStringAppendUnattributed(attrstr, ", ");

	attr = uiNewBackgroundAttribute(0.5, 0.5, 0.25, 0.5);
	appendWithAttribute("text background color", attr, NULL);
	uiAttributedStringAppendUnattributed(attrstr, ", ");


	attr = uiNewUnderlineAttribute(uiUnderlineSingle);
	appendWithAttribute("underline style", attr, NULL);
	uiAttributedStringAppendUnattributed(attrstr, ", ");

	uiAttributedStringAppendUnattributed(attrstr, "and ");
	attr = uiNewUnderlineAttribute(uiUnderlineDouble);
	attr2 = uiNewUnderlineColorAttribute(uiUnderlineColorCustom, 1.0, 0.0, 0.5, 1.0);
	appendWithAttribute("underline color", attr, attr2);
	uiAttributedStringAppendUnattributed(attrstr, ". ");

	uiAttributedStringAppendUnattributed(attrstr, "Furthermore, there are attributes allowing for ");
	attr = uiNewUnderlineAttribute(uiUnderlineSuggestion);
	attr2 = uiNewUnderlineColorAttribute(uiUnderlineColorSpelling, 0, 0, 0, 0);
	appendWithAttribute("special underlines for indicating spelling errors", attr, attr2);
	uiAttributedStringAppendUnattributed(attrstr, " (and other types of errors) ");

	uiAttributedStringAppendUnattributed(attrstr, "and control over OpenType features such as ligatures (for instance, ");
	otf = uiNewOpenTypeFeatures();
	uiOpenTypeFeaturesAdd(otf, 'l', 'i', 'g', 'a', 0);
	attr = uiNewFeaturesAttribute(otf);
	appendWithAttribute("afford", attr, NULL);
	uiAttributedStringAppendUnattributed(attrstr, " vs. ");
	uiOpenTypeFeaturesAdd(otf, 'l', 'i', 'g', 'a', 1);
	attr = uiNewFeaturesAttribute(otf);
	appendWithAttribute("afford", attr, NULL);
	uiFreeOpenTypeFeatures(otf);
	uiAttributedStringAppendUnattributed(attrstr, ").\n");

	uiAttributedStringAppendUnattributed(attrstr, "Use the controls opposite to the text to control properties of the text.");
}

__attribute__((used)) static void handlerDraw(uiAreaHandler *a, uiArea *area, uiAreaDrawParams *p)
{
	uiDrawTextLayout *textLayout;
	uiFontDescriptor defaultFont;
	uiDrawTextLayoutParams params;

	params.String = attrstr;
	uiFontButtonFont(fontButton, &defaultFont);
	params.DefaultFont = &defaultFont;
	params.Width = p->AreaWidth;
	params.Align = (uiDrawTextAlign) uiComboboxSelected(alignment);
	textLayout = uiDrawNewTextLayout(&params);
	uiDrawText(p->Context, textLayout, 0, 0);
	uiDrawFreeTextLayout(textLayout);
	uiFreeFontButtonFont(&defaultFont);
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
	uiAreaQueueRedrawAll(area);
}

__attribute__((used)) static void onComboboxSelected(uiCombobox *b, void *data)
{
	uiAreaQueueRedrawAll(area);
}

__attribute__((used)) static int onClosing(uiWindow *w, void *data)
{
	uiControlDestroy(uiControl(mainwin));
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
	uiBox *hbox, *vbox;
	uiForm *form;

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

	makeAttributedString();

	mainwin = uiNewWindow("libui Text-Drawing Example", 640, 480, 1);
	uiWindowSetMargined(mainwin, 1);
	uiWindowOnClosing(mainwin, onClosing, NULL);

	hbox = uiNewHorizontalBox();
	uiBoxSetPadded(hbox, 1);
	uiWindowSetChild(mainwin, uiControl(hbox));

	vbox = uiNewVerticalBox();
	uiBoxSetPadded(vbox, 1);
	uiBoxAppend(hbox, uiControl(vbox), 0);

	fontButton = uiNewFontButton();
	uiFontButtonOnChanged(fontButton, onFontChanged, NULL);
	uiBoxAppend(vbox, uiControl(fontButton), 0);

	form = uiNewForm();
	uiFormSetPadded(form, 1);
	// TODO on OS X if this is set to 1 then the window can't resize; does the form not have the concept of stretchy trailing space?
	uiBoxAppend(vbox, uiControl(form), 0);

	alignment = uiNewCombobox();
	// note that the items match with the values of the uiDrawTextAlign values
	uiComboboxAppend(alignment, "Left");
	uiComboboxAppend(alignment, "Center");
	uiComboboxAppend(alignment, "Right");
	uiComboboxSetSelected(alignment, 0);		// start with left alignment
	uiComboboxOnSelected(alignment, onComboboxSelected, NULL);
	uiFormAppend(form, "Alignment", uiControl(alignment), 0);

	area = uiNewArea(&handler);
	uiBoxAppend(hbox, uiControl(area), 1);

	uiControlShow(uiControl(mainwin));
	uiMain();
	uiFreeAttributedString(attrstr);
	uiUninit();
	return 0;
}

