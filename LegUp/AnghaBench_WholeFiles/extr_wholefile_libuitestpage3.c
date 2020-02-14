#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  uiButton ;
typedef  int /*<<< orphan*/  uiBox ;

/* Variables and functions */
 int /*<<< orphan*/ * newVerticalBox () ; 
 int /*<<< orphan*/ * newhbox () ; 
 int /*<<< orphan*/ * newvbox () ; 
 int /*<<< orphan*/ * stub1 () ; 
 int /*<<< orphan*/ * stub2 () ; 
 int /*<<< orphan*/ * stub3 () ; 
 int /*<<< orphan*/  uiBoxAppend (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  uiBoxSetPadded (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  uiControl (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiControlHide (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * uiNewButton (char*) ; 

__attribute__((used)) static uiBox *makeSet(int omit, int hidden, int stretch)
{
	uiBox *hbox;
	uiButton *buttons[4];

	// don't use newHorizontalBox()
	// the point of this test is to test hidden controls and padded
	hbox = (*newhbox)();
	uiBoxSetPadded(hbox, 1);
	if (omit != 0) {
		buttons[0] = uiNewButton("First");
		uiBoxAppend(hbox, uiControl(buttons[0]), stretch);
	}
	if (omit != 1) {
		buttons[1] = uiNewButton("Second");
		uiBoxAppend(hbox, uiControl(buttons[1]), stretch);
	}
	if (omit != 2) {
		buttons[2] = uiNewButton("Third");
		uiBoxAppend(hbox, uiControl(buttons[2]), stretch);
	}
	if (omit != 3) {
		buttons[3] = uiNewButton("Fourth");
		uiBoxAppend(hbox, uiControl(buttons[3]), stretch);
	}
	if (hidden != -1)
		uiControlHide(uiControl(buttons[hidden]));
	return hbox;
}

uiBox *makePage3(void)
{
	uiBox *page3;
	uiBox *hbox;
	uiBox *hbox2;
	uiBox *vbox;
	int hidden;

	page3 = newVerticalBox();

	// first the non-stretchy type
	for (hidden = 0; hidden < 4; hidden++) {
		// these two must stay unpadded as well, otherwise the test isn't meaningful
		hbox2 = (*newhbox)();
		vbox = (*newvbox)();
		// reference set
		hbox = makeSet(hidden, -1, 0);
		uiBoxAppend(vbox, uiControl(hbox), 0);
		// real thing
		hbox = makeSet(-1, hidden, 0);
		uiBoxAppend(vbox, uiControl(hbox), 0);
		// pack vbox in
		uiBoxAppend(hbox2, uiControl(vbox), 0);
		// and have a button in there for showing right margins
		uiBoxAppend(hbox2, uiControl(uiNewButton("Right Margin Test")), 1);
		uiBoxAppend(page3, uiControl(hbox2), 0);
	}

	// then the stretchy type
	for (hidden = 0; hidden < 4; hidden++) {
		hbox = makeSet(-1, hidden, 1);
		uiBoxAppend(page3, uiControl(hbox), 0);
	}

	return page3;
}

