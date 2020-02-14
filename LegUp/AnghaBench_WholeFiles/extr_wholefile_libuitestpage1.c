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
typedef  int /*<<< orphan*/  uiWindow ;
typedef  int /*<<< orphan*/  uiLabel ;
typedef  int /*<<< orphan*/  uiEntry ;
typedef  int /*<<< orphan*/  uiCheckbox ;
typedef  int /*<<< orphan*/  uiButton ;
typedef  int /*<<< orphan*/  uiBox ;

/* Variables and functions */
 void disableControl (int /*<<< orphan*/ *,void*) ; 
 void enableControl (int /*<<< orphan*/ *,void*) ; 
 int /*<<< orphan*/ * entry ; 
 void getButtonText (int /*<<< orphan*/ *,void*) ; 
 void getCheckboxText (int /*<<< orphan*/ *,void*) ; 
 void getGroupText (int /*<<< orphan*/ *,void*) ; 
 void getLabelText (int /*<<< orphan*/ *,void*) ; 
 void getWindowText (int /*<<< orphan*/ *,void*) ; 
 void hideControl (int /*<<< orphan*/ *,void*) ; 
 int /*<<< orphan*/ * newHorizontalBox () ; 
 int /*<<< orphan*/ * newVerticalBox () ; 
 int /*<<< orphan*/ * page1 ; 
 int /*<<< orphan*/ * page2group ; 
 int /*<<< orphan*/  printf (char*) ; 
 int /*<<< orphan*/  querySpaced (char*) ; 
 void setButtonText (int /*<<< orphan*/ *,void*) ; 
 void setCheckboxText (int /*<<< orphan*/ *,void*) ; 
 void setGroupText (int /*<<< orphan*/ *,void*) ; 
 void setLabelText (int /*<<< orphan*/ *,void*) ; 
 int /*<<< orphan*/  setSpaced (int /*<<< orphan*/ ) ; 
 void setWindowText (int /*<<< orphan*/ *,void*) ; 
 void showControl (int /*<<< orphan*/ *,void*) ; 
 int /*<<< orphan*/ * spaced ; 
 int /*<<< orphan*/  uiBoxAppend (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  uiButtonOnClicked (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiCheckboxChecked (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiCheckboxOnToggled (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiCheckboxSetChecked (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiControl (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiEntryOnChanged (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiEntrySetText (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/ * uiNewButton (char*) ; 
 int /*<<< orphan*/ * uiNewCheckbox (char*) ; 
 int /*<<< orphan*/ * uiNewEntry () ; 
 int /*<<< orphan*/ * uiNewLabel (char*) ; 

__attribute__((used)) static void onChanged(uiEntry *e, void *data)
{
	printf("onChanged()\n");
}

__attribute__((used)) static void toggleSpaced(uiCheckbox *c, void *data)
{
	setSpaced(uiCheckboxChecked(spaced));
}

__attribute__((used)) static void forceSpaced(uiButton *b, void *data)
{
	uiCheckboxSetChecked(spaced, data != NULL);
}

__attribute__((used)) static void showSpaced(uiButton *b, void *data)
{
	char s[12];

	querySpaced(s);
	uiEntrySetText(entry, s);
}

void makePage1(uiWindow *w)
{
	uiButton *getButton, *setButton;
	uiBox *hbox;
	uiBox *testBox;
	uiLabel *label;

	page1 = newVerticalBox();

	entry = uiNewEntry();
	uiEntryOnChanged(entry, onChanged, NULL);
	uiBoxAppend(page1, uiControl(entry), 0);

	spaced = uiNewCheckbox("Spaced");
	uiCheckboxOnToggled(spaced, toggleSpaced, NULL);
	label = uiNewLabel("Label");

	hbox = newHorizontalBox();
	getButton = uiNewButton("Get Window Text");
	uiButtonOnClicked(getButton, getWindowText, w);
	setButton = uiNewButton("Set Window Text");
	uiButtonOnClicked(setButton, setWindowText, w);
	uiBoxAppend(hbox, uiControl(getButton), 1);
	uiBoxAppend(hbox, uiControl(setButton), 1);
	uiBoxAppend(page1, uiControl(hbox), 0);

	hbox = newHorizontalBox();
	getButton = uiNewButton("Get Button Text");
	uiButtonOnClicked(getButton, getButtonText, getButton);
	setButton = uiNewButton("Set Button Text");
	uiButtonOnClicked(setButton, setButtonText, getButton);
	uiBoxAppend(hbox, uiControl(getButton), 1);
	uiBoxAppend(hbox, uiControl(setButton), 1);
	uiBoxAppend(page1, uiControl(hbox), 0);

	hbox = newHorizontalBox();
	getButton = uiNewButton("Get Checkbox Text");
	uiButtonOnClicked(getButton, getCheckboxText, spaced);
	setButton = uiNewButton("Set Checkbox Text");
	uiButtonOnClicked(setButton, setCheckboxText, spaced);
	uiBoxAppend(hbox, uiControl(getButton), 1);
	uiBoxAppend(hbox, uiControl(setButton), 1);
	uiBoxAppend(page1, uiControl(hbox), 0);

	hbox = newHorizontalBox();
	getButton = uiNewButton("Get Label Text");
	uiButtonOnClicked(getButton, getLabelText, label);
	setButton = uiNewButton("Set Label Text");
	uiButtonOnClicked(setButton, setLabelText, label);
	uiBoxAppend(hbox, uiControl(getButton), 1);
	uiBoxAppend(hbox, uiControl(setButton), 1);
	uiBoxAppend(page1, uiControl(hbox), 0);

	hbox = newHorizontalBox();
	getButton = uiNewButton("Get Group Text");
	uiButtonOnClicked(getButton, getGroupText, page2group);
	setButton = uiNewButton("Set Group Text");
	uiButtonOnClicked(setButton, setGroupText, page2group);
	uiBoxAppend(hbox, uiControl(getButton), 1);
	uiBoxAppend(hbox, uiControl(setButton), 1);
	uiBoxAppend(page1, uiControl(hbox), 0);

	hbox = newHorizontalBox();
	uiBoxAppend(hbox, uiControl(spaced), 1);
	getButton = uiNewButton("On");
	uiButtonOnClicked(getButton, forceSpaced, getButton);
	uiBoxAppend(hbox, uiControl(getButton), 0);
	getButton = uiNewButton("Off");
	uiButtonOnClicked(getButton, forceSpaced, NULL);
	uiBoxAppend(hbox, uiControl(getButton), 0);
	getButton = uiNewButton("Show");
	uiButtonOnClicked(getButton, showSpaced, NULL);
	uiBoxAppend(hbox, uiControl(getButton), 0);
	uiBoxAppend(page1, uiControl(hbox), 0);

	testBox = newHorizontalBox();
	setButton = uiNewButton("Button");
	uiBoxAppend(testBox, uiControl(setButton), 1);
	getButton = uiNewButton("Show");
	uiButtonOnClicked(getButton, showControl, setButton);
	uiBoxAppend(testBox, uiControl(getButton), 0);
	getButton = uiNewButton("Hide");
	uiButtonOnClicked(getButton, hideControl, setButton);
	uiBoxAppend(testBox, uiControl(getButton), 0);
	getButton = uiNewButton("Enable");
	uiButtonOnClicked(getButton, enableControl, setButton);
	uiBoxAppend(testBox, uiControl(getButton), 0);
	getButton = uiNewButton("Disable");
	uiButtonOnClicked(getButton, disableControl, setButton);
	uiBoxAppend(testBox, uiControl(getButton), 0);
	uiBoxAppend(page1, uiControl(testBox), 0);

	hbox = newHorizontalBox();
	getButton = uiNewButton("Show Box");
	uiButtonOnClicked(getButton, showControl, testBox);
	uiBoxAppend(hbox, uiControl(getButton), 1);
	getButton = uiNewButton("Hide Box");
	uiButtonOnClicked(getButton, hideControl, testBox);
	uiBoxAppend(hbox, uiControl(getButton), 1);
	getButton = uiNewButton("Enable Box");
	uiButtonOnClicked(getButton, enableControl, testBox);
	uiBoxAppend(hbox, uiControl(getButton), 1);
	getButton = uiNewButton("Disable Box");
	uiButtonOnClicked(getButton, disableControl, testBox);
	uiBoxAppend(hbox, uiControl(getButton), 1);
	uiBoxAppend(page1, uiControl(hbox), 0);

	uiBoxAppend(page1, uiControl(label), 0);
}

