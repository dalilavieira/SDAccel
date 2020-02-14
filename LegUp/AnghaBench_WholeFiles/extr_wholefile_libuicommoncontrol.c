#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_36__   TYPE_1__ ;

/* Type definitions */
typedef  void* uint32_t ;
struct TYPE_36__ {uintptr_t (* Handle ) (TYPE_1__*) ;int (* Toplevel ) (TYPE_1__*) ;int (* Visible ) (TYPE_1__*) ;int (* Enabled ) (TYPE_1__*) ;void* TypeSignature; void* OSSignature; int /*<<< orphan*/  Signature; int /*<<< orphan*/  (* Disable ) (TYPE_1__*) ;int /*<<< orphan*/  (* Enable ) (TYPE_1__*) ;int /*<<< orphan*/  (* Hide ) (TYPE_1__*) ;int /*<<< orphan*/  (* Show ) (TYPE_1__*) ;int /*<<< orphan*/  (* SetParent ) (TYPE_1__*,TYPE_1__*) ;TYPE_1__* (* Parent ) (TYPE_1__*) ;int /*<<< orphan*/  (* Destroy ) (TYPE_1__*) ;} ;
typedef  TYPE_1__ uiControl ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (TYPE_1__*) ; 
 int /*<<< orphan*/  stub10 (TYPE_1__*) ; 
 int /*<<< orphan*/  stub11 (TYPE_1__*) ; 
 uintptr_t stub2 (TYPE_1__*) ; 
 TYPE_1__* stub3 (TYPE_1__*) ; 
 int /*<<< orphan*/  stub4 (TYPE_1__*,TYPE_1__*) ; 
 int stub5 (TYPE_1__*) ; 
 int stub6 (TYPE_1__*) ; 
 int /*<<< orphan*/  stub7 (TYPE_1__*) ; 
 int /*<<< orphan*/  stub8 (TYPE_1__*) ; 
 int stub9 (TYPE_1__*) ; 
 scalar_t__ uiprivAlloc (size_t,char const*) ; 
 int /*<<< orphan*/  uiprivControlSignature ; 
 int /*<<< orphan*/  uiprivFree (TYPE_1__*) ; 
 int /*<<< orphan*/  uiprivImplBug (char*,TYPE_1__*) ; 
 int /*<<< orphan*/  uiprivUserBug (char*,TYPE_1__*,...) ; 

void uiControlDestroy(uiControl *c)
{
	(*(c->Destroy))(c);
}

uintptr_t uiControlHandle(uiControl *c)
{
	return (*(c->Handle))(c);
}

uiControl *uiControlParent(uiControl *c)
{
	return (*(c->Parent))(c);
}

void uiControlSetParent(uiControl *c, uiControl *parent)
{
	(*(c->SetParent))(c, parent);
}

int uiControlToplevel(uiControl *c)
{
	return (*(c->Toplevel))(c);
}

int uiControlVisible(uiControl *c)
{
	return (*(c->Visible))(c);
}

void uiControlShow(uiControl *c)
{
	(*(c->Show))(c);
}

void uiControlHide(uiControl *c)
{
	(*(c->Hide))(c);
}

int uiControlEnabled(uiControl *c)
{
	return (*(c->Enabled))(c);
}

void uiControlEnable(uiControl *c)
{
	(*(c->Enable))(c);
}

void uiControlDisable(uiControl *c)
{
	(*(c->Disable))(c);
}

uiControl *uiAllocControl(size_t size, uint32_t OSsig, uint32_t typesig, const char *typenamestr)
{
	uiControl *c;

	c = (uiControl *) uiprivAlloc(size, typenamestr);
	c->Signature = uiprivControlSignature;
	c->OSSignature = OSsig;
	c->TypeSignature = typesig;
	return c;
}

void uiFreeControl(uiControl *c)
{
	if (uiControlParent(c) != NULL)
		uiprivUserBug("You cannot destroy a uiControl while it still has a parent. (control: %p)", c);
	uiprivFree(c);
}

void uiControlVerifySetParent(uiControl *c, uiControl *parent)
{
	uiControl *curParent;

	if (uiControlToplevel(c))
		uiprivUserBug("You cannot give a toplevel uiControl a parent. (control: %p)", c);
	curParent = uiControlParent(c);
	if (parent != NULL && curParent != NULL)
		uiprivUserBug("You cannot give a uiControl a parent while it already has one. (control: %p; current parent: %p; new parent: %p)", c, curParent, parent);
	if (parent == NULL && curParent == NULL)
		uiprivImplBug("attempt to double unparent uiControl %p", c);
}

int uiControlEnabledToUser(uiControl *c)
{
	while (c != NULL) {
		if (!uiControlEnabled(c))
			return 0;
		c = uiControlParent(c);
	}
	return 1;
}

