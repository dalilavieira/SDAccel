#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_6__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uiGroup ;
typedef  int /*<<< orphan*/  uiBox ;
struct TYPE_8__ {double X; double Y; } ;
typedef  TYPE_2__ uiAreaMouseEvent ;
struct TYPE_9__ {char Key; int /*<<< orphan*/  Up; } ;
typedef  TYPE_3__ uiAreaKeyEvent ;
typedef  int /*<<< orphan*/  uiAreaHandler ;
typedef  int /*<<< orphan*/  uiAreaDrawParams ;
typedef  int /*<<< orphan*/  uiArea ;
struct TYPE_7__ {void (* Draw ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;void (* MouseEvent ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_2__*) ;void (* MouseCrossed ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ;void (* DragBroken ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;int (* KeyEvent ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_3__*) ;} ;
struct TYPE_10__ {TYPE_1__ ah; } ;

/* Variables and functions */
 int /*<<< orphan*/ * area ; 
 TYPE_6__ handler ; 
 int /*<<< orphan*/ * label ; 
 int /*<<< orphan*/ * newGroup (char*) ; 
 int /*<<< orphan*/ * newVerticalBox () ; 
 int /*<<< orphan*/  printf (char*,int,int) ; 
 int /*<<< orphan*/  sprintf (char*,char*,double,double) ; 
 int /*<<< orphan*/  uiBoxAppend (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  uiCheckboxSetChecked (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  uiCheckboxSetText (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  uiControl (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiGroupSetChild (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * uiNewCheckbox (char*) ; 
 int /*<<< orphan*/ * uiNewScrollingArea (int /*<<< orphan*/ *,int,int) ; 

__attribute__((used)) static void handlerDraw(uiAreaHandler *a, uiArea *area, uiAreaDrawParams *p)
{
	// do nothing
}

__attribute__((used)) static void handlerMouseEvent(uiAreaHandler *a, uiArea *area, uiAreaMouseEvent *e)
{
	char pos[128];

	// wonderful, vanilla snprintf() isn't in visual studio 2013 - http://blogs.msdn.com/b/vcblog/archive/2013/07/19/c99-library-support-in-visual-studio-2013.aspx
	// we can't use _snprintf() in the test suite because that's msvc-only, so oops. sprintf() it is.
	sprintf(pos, "X %g Y %g", e->X, e->Y);
	uiCheckboxSetText(label, pos);
}

__attribute__((used)) static void handlerMouseCrossed(uiAreaHandler *ah, uiArea *a, int left)
{
printf("%d %d\n", left, !left);
	uiCheckboxSetChecked(label, !left);
}

__attribute__((used)) static void handlerDragBroken(uiAreaHandler *ah, uiArea *a)
{
	// do nothing
}

__attribute__((used)) static int handlerKeyEvent(uiAreaHandler *ah, uiArea *a, uiAreaKeyEvent *e)
{
	if (e->Key == 'h' && !e->Up) {
		// TODO hide the widget momentarily on the h key
		return 1;
	}
	return 0;
}

uiGroup *makePage7b(void)
{
	uiGroup *group;
	uiBox *box;

	handler.ah.Draw = handlerDraw;
	handler.ah.MouseEvent = handlerMouseEvent;
	handler.ah.MouseCrossed = handlerMouseCrossed;
	handler.ah.DragBroken = handlerDragBroken;
	handler.ah.KeyEvent = handlerKeyEvent;

	group = newGroup("Scrolling Mouse Test");

	box = newVerticalBox();
	uiGroupSetChild(group, uiControl(box));

	area = uiNewScrollingArea((uiAreaHandler *) (&handler), 5000, 5000);
	uiBoxAppend(box, uiControl(area), 1);

	label = uiNewCheckbox("");
	uiBoxAppend(box, uiControl(label), 0);

	return group;
}

