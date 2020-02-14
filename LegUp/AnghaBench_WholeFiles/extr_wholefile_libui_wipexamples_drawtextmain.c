#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uiWindow ;
typedef  int /*<<< orphan*/  uiInitOptions ;
typedef  int /*<<< orphan*/  uiCombobox ;
typedef  int /*<<< orphan*/  uiAreaMouseEvent ;
typedef  int /*<<< orphan*/  uiAreaKeyEvent ;
typedef  int /*<<< orphan*/  uiAreaHandler ;
typedef  int /*<<< orphan*/  uiAreaDrawParams ;
typedef  int /*<<< orphan*/  uiArea ;
struct TYPE_9__ {int (* key ) (int /*<<< orphan*/ *) ;int /*<<< orphan*/  panel; int /*<<< orphan*/  name; int /*<<< orphan*/  (* mouse ) (int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* draw ) (int /*<<< orphan*/ *) ;} ;
struct TYPE_8__ {void (* Draw ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;void (* MouseEvent ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;void (* MouseCrossed ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ;void (* DragBroken ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;int (* KeyEvent ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  area ; 
 int /*<<< orphan*/  box ; 
 size_t curExample ; 
 int /*<<< orphan*/  exampleList ; 
 TYPE_2__** examples ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char const*) ; 
 TYPE_1__ handler ; 
 int /*<<< orphan*/  mainwin ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 TYPE_2__* mkAttributesExample () ; 
 TYPE_2__* mkBasicExample () ; 
 TYPE_2__* mkEmptyStringExample () ; 
 TYPE_2__* mkHitTestExample () ; 
 void redraw () ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub2 (int /*<<< orphan*/ *) ; 
 int stub3 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiAreaQueueRedrawAll (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiBoxAppend (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  uiComboboxAppend (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiComboboxOnSelected (int /*<<< orphan*/ ,void (*) (int /*<<< orphan*/ *,void*),int /*<<< orphan*/ *) ; 
 size_t uiComboboxSelected (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiComboboxSetSelected (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiControl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiControlDestroy (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiControlHide (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiControlShow (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiFreeInitError (char const*) ; 
 char* uiInit (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiMain () ; 
 int /*<<< orphan*/  uiNewArea (TYPE_1__*) ; 
 int /*<<< orphan*/  uiNewCombobox () ; 
 int /*<<< orphan*/  uiNewVerticalBox () ; 
 int /*<<< orphan*/  uiNewWindow (char*,int,int,int) ; 
 int /*<<< orphan*/  uiOnShouldQuit (int (*) (void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiQuit () ; 
 int /*<<< orphan*/  uiUninit () ; 
 int /*<<< orphan*/  uiWindowOnClosing (int /*<<< orphan*/ ,int (*) (int /*<<< orphan*/ *,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiWindowSetChild (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void onExampleChanged(uiCombobox *c, void *data)
{
	uiControlHide(examples[curExample]->panel);
	curExample = uiComboboxSelected(exampleList);
	uiControlShow(examples[curExample]->panel);
	redraw();
}

void redraw(void)
{
	uiAreaQueueRedrawAll(area);
}

__attribute__((used)) static void handlerDraw(uiAreaHandler *a, uiArea *area, uiAreaDrawParams *p)
{
	examples[curExample]->draw(p);
}

__attribute__((used)) static void handlerMouseEvent(uiAreaHandler *a, uiArea *area, uiAreaMouseEvent *e)
{
	if (examples[curExample]->mouse != NULL)
		examples[curExample]->mouse(e);
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
	if (examples[curExample]->key != NULL)
		return examples[curExample]->key(e);
	return 0;
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
	int n;

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

	mainwin = uiNewWindow("libui Text-Drawing Example", 640, 480, 1);
	uiWindowOnClosing(mainwin, onClosing, NULL);

	box = uiNewVerticalBox();
	uiWindowSetChild(mainwin, uiControl(box));

	exampleList = uiNewCombobox();
	uiBoxAppend(box, uiControl(exampleList), 0);

	area = uiNewArea(&handler);
	uiBoxAppend(box, uiControl(area), 1);

	n = 0;
	examples[n] = mkBasicExample();
	uiComboboxAppend(exampleList, examples[n]->name);
	uiControlHide(examples[n]->panel);
	uiBoxAppend(box, examples[n]->panel, 0);
	n++;
	examples[n] = mkHitTestExample();
	uiComboboxAppend(exampleList, examples[n]->name);
	uiControlHide(examples[n]->panel);
	uiBoxAppend(box, examples[n]->panel, 0);
	n++;
	examples[n] = mkAttributesExample();
	uiComboboxAppend(exampleList, examples[n]->name);
	uiControlHide(examples[n]->panel);
	uiBoxAppend(box, examples[n]->panel, 0);
	n++;
	examples[n] = mkEmptyStringExample();
	uiComboboxAppend(exampleList, examples[n]->name);
	uiControlHide(examples[n]->panel);
	uiBoxAppend(box, examples[n]->panel, 0);
	n++;
	// and set things up for the initial state
	uiComboboxSetSelected(exampleList, 0);
	uiComboboxOnSelected(exampleList, onExampleChanged, NULL);
	// and set up the first one
	onExampleChanged(NULL, NULL);

	uiControlShow(uiControl(mainwin));
	uiMain();

	// TODO free examples

	uiUninit();
	return 0;
}

