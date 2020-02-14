#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_8__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uiGroup ;
typedef  int /*<<< orphan*/  uiEntry ;
struct TYPE_10__ {double Thickness; scalar_t__ DashPhase; scalar_t__ NumDashes; int /*<<< orphan*/ * Dashes; int /*<<< orphan*/  MiterLimit; int /*<<< orphan*/  Join; int /*<<< orphan*/  Cap; } ;
typedef  TYPE_2__ uiDrawStrokeParams ;
typedef  int /*<<< orphan*/  uiDrawPath ;
struct TYPE_11__ {int A; scalar_t__ B; scalar_t__ G; scalar_t__ R; int /*<<< orphan*/  Type; } ;
typedef  TYPE_3__ uiDrawBrush ;
typedef  int /*<<< orphan*/  uiCheckbox ;
typedef  int /*<<< orphan*/  uiBox ;
typedef  int /*<<< orphan*/  uiAreaMouseEvent ;
typedef  int /*<<< orphan*/  uiAreaKeyEvent ;
typedef  int /*<<< orphan*/  uiAreaHandler ;
struct TYPE_12__ {int /*<<< orphan*/  Context; } ;
typedef  TYPE_4__ uiAreaDrawParams ;
typedef  int /*<<< orphan*/  uiArea ;
struct TYPE_9__ {void (* Draw ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_4__*) ;void (* MouseEvent ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;void (* MouseCrossed ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ;void (* DragBroken ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;int (* KeyEvent ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;} ;
struct TYPE_13__ {TYPE_1__ ah; } ;

/* Variables and functions */
 int /*<<< orphan*/ * area ; 
 double atof (char*) ; 
 TYPE_8__ handler ; 
 int /*<<< orphan*/ * negative ; 
 int /*<<< orphan*/ * newGroup (char*) ; 
 int /*<<< orphan*/ * newHorizontalBox () ; 
 int /*<<< orphan*/ * newVerticalBox () ; 
 int /*<<< orphan*/ * radians ; 
 int /*<<< orphan*/ * startAngle ; 
 int /*<<< orphan*/ * sweep ; 
 int /*<<< orphan*/  uiAreaQueueRedrawAll (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiBoxAppend (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 scalar_t__ uiCheckboxChecked (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiCheckboxOnToggled (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiControl (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiDrawBrushTypeSolid ; 
 int /*<<< orphan*/  uiDrawDefaultMiterLimit ; 
 int /*<<< orphan*/  uiDrawFillModeWinding ; 
 int /*<<< orphan*/  uiDrawFreePath (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiDrawLineCapFlat ; 
 int /*<<< orphan*/  uiDrawLineJoinMiter ; 
 int /*<<< orphan*/ * uiDrawNewPath (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiDrawPathArcTo (int /*<<< orphan*/ *,double,double,double,double,double,scalar_t__) ; 
 int /*<<< orphan*/  uiDrawPathEnd (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiDrawPathNewFigure (int /*<<< orphan*/ *,double,double) ; 
 int /*<<< orphan*/  uiDrawStroke (int /*<<< orphan*/ ,int /*<<< orphan*/ *,TYPE_3__*,TYPE_2__*) ; 
 int /*<<< orphan*/  uiEntryOnChanged (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,void*),int /*<<< orphan*/ *) ; 
 char* uiEntryText (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiFreeText (char*) ; 
 int /*<<< orphan*/  uiGroupSetChild (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * uiNewArea (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * uiNewCheckbox (char*) ; 
 int /*<<< orphan*/ * uiNewEntry () ; 
 int /*<<< orphan*/ * uiNewLabel (char*) ; 
 int uiPi ; 

__attribute__((used)) static void handlerDraw(uiAreaHandler *a, uiArea *area, uiAreaDrawParams *p)
{
	double xc = 128.0;
	double yc = 128.0;
	double radius = 100.0;
	uiDrawBrush source;
	uiDrawStrokeParams sp;
	uiDrawPath *path;
	char *startText;
	char *sweepText;
	double factor;

	source.Type = uiDrawBrushTypeSolid;
	source.R = 0;
	source.G = 0;
	source.B = 0;
	source.A = 1;
	sp.Cap = uiDrawLineCapFlat;
	sp.Join = uiDrawLineJoinMiter;
	sp.MiterLimit = uiDrawDefaultMiterLimit;
	sp.Dashes = NULL;
	sp.NumDashes = 0;
	sp.DashPhase = 0;

	startText = uiEntryText(startAngle);
	sweepText = uiEntryText(sweep);

	factor = uiPi / 180;
	if (uiCheckboxChecked(radians))
		factor = 1;

	sp.Thickness = 10.0;
	path = uiDrawNewPath(uiDrawFillModeWinding);
	uiDrawPathNewFigure(path, xc, yc);
	uiDrawPathArcTo(path,
		xc, yc,
		radius,
		atof(startText) * factor,
		atof(sweepText) * factor,
		uiCheckboxChecked(negative));
	uiDrawPathEnd(path);
	uiDrawStroke(p->Context, path, &source, &sp);
	uiDrawFreePath(path);

	uiFreeText(startText);
	uiFreeText(sweepText);
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
	return 0;
}

__attribute__((used)) static void entryChanged(uiEntry *e, void *data)
{
	uiAreaQueueRedrawAll(area);
}

__attribute__((used)) static void checkboxToggled(uiCheckbox *c, void *data)
{
	uiAreaQueueRedrawAll(area);
}

uiGroup *makePage7a(void)
{
	uiGroup *group;
	uiBox *box, *box2;

	handler.ah.Draw = handlerDraw;
	handler.ah.MouseEvent = handlerMouseEvent;
	handler.ah.MouseCrossed = handlerMouseCrossed;
	handler.ah.DragBroken = handlerDragBroken;
	handler.ah.KeyEvent = handlerKeyEvent;

	group = newGroup("Arc Test");

	box = newVerticalBox();
	uiGroupSetChild(group, uiControl(box));

	area = uiNewArea((uiAreaHandler *) (&handler));
	uiBoxAppend(box, uiControl(area), 1);

	box2 = newHorizontalBox();
	uiBoxAppend(box, uiControl(box2), 0);

	uiBoxAppend(box2, uiControl(uiNewLabel("Start Angle")), 0);
	startAngle = uiNewEntry();
	uiEntryOnChanged(startAngle, entryChanged, NULL);
	uiBoxAppend(box2, uiControl(startAngle), 1);

	box2 = newHorizontalBox();
	uiBoxAppend(box, uiControl(box2), 0);

	uiBoxAppend(box2, uiControl(uiNewLabel("Sweep")), 0);
	sweep = uiNewEntry();
	uiEntryOnChanged(sweep, entryChanged, NULL);
	uiBoxAppend(box2, uiControl(sweep), 1);

	negative = uiNewCheckbox("Negative");
	uiCheckboxOnToggled(negative, checkboxToggled, NULL);
	uiBoxAppend(box, uiControl(negative), 0);

	radians = uiNewCheckbox("Radians");
	uiCheckboxOnToggled(radians, checkboxToggled, NULL);
	uiBoxAppend(box, uiControl(radians), 0);

	return group;
}

