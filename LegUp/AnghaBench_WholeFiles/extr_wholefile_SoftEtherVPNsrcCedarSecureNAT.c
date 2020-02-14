#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_39__   TYPE_9__ ;
typedef  struct TYPE_38__   TYPE_7__ ;
typedef  struct TYPE_37__   TYPE_6__ ;
typedef  struct TYPE_36__   TYPE_5__ ;
typedef  struct TYPE_35__   TYPE_4__ ;
typedef  struct TYPE_34__   TYPE_3__ ;
typedef  struct TYPE_33__   TYPE_2__ ;
typedef  struct TYPE_32__   TYPE_20__ ;
typedef  struct TYPE_31__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  VH_OPTION ;
struct TYPE_39__ {TYPE_1__* NativeNat; TYPE_7__* Cancel; } ;
struct TYPE_38__ {int /*<<< orphan*/  ref; } ;
struct TYPE_37__ {TYPE_3__* Session; int /*<<< orphan*/  Protocol; } ;
struct TYPE_36__ {int /*<<< orphan*/  Cedar; int /*<<< orphan*/  ref; } ;
struct TYPE_35__ {int NoBroadcastLimiter; } ;
struct TYPE_34__ {int SecureNATMode; int /*<<< orphan*/  Hub; TYPE_7__* Cancel1; int /*<<< orphan*/  ref; int /*<<< orphan*/  Username; int /*<<< orphan*/  Name; TYPE_2__* SecureNAT; } ;
struct TYPE_33__ {TYPE_20__* Nat; int /*<<< orphan*/  lock; TYPE_5__* Hub; int /*<<< orphan*/  Cedar; TYPE_3__* Session; } ;
struct TYPE_32__ {TYPE_9__* Virtual; } ;
struct TYPE_31__ {int /*<<< orphan*/  CancelLock; TYPE_7__* Cancel; } ;
typedef  int /*<<< orphan*/  THREAD ;
typedef  TYPE_2__ SNAT ;
typedef  TYPE_3__ SESSION ;
typedef  TYPE_4__ POLICY ;
typedef  TYPE_5__ HUB ;
typedef  TYPE_6__ CONNECTION ;
typedef  TYPE_7__ CANCEL ;

/* Variables and functions */
 int /*<<< orphan*/  AddRef (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CONNECTION_HUB_SECURE_NAT ; 
 TYPE_4__* ClonePolicy (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CopyStr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Debug (char*) ; 
 int /*<<< orphan*/  DeleteLock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Free (TYPE_2__*) ; 
 int /*<<< orphan*/  GetDefaultPolicy () ; 
 int /*<<< orphan*/  HLog (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  Lock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NewLock () ; 
 TYPE_6__* NewServerConnection (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 TYPE_3__* NewServerSession (int /*<<< orphan*/ ,TYPE_6__*,TYPE_5__*,int /*<<< orphan*/ ,TYPE_4__*) ; 
 int /*<<< orphan*/ * NewThread (void (*) (int /*<<< orphan*/ *,void*),TYPE_2__*) ; 
 int /*<<< orphan*/  NiFreeNat (TYPE_20__*) ; 
 TYPE_20__* NiNewNatEx (TYPE_2__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  NoticeThreadInit (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ReleaseCancel (TYPE_7__*) ; 
 int /*<<< orphan*/  ReleaseConnection (TYPE_6__*) ; 
 int /*<<< orphan*/  ReleaseHub (TYPE_5__*) ; 
 int /*<<< orphan*/  ReleaseSession (TYPE_3__*) ; 
 int /*<<< orphan*/  ReleaseThread (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SNAT_USER_NAME ; 
 int /*<<< orphan*/  SNAT_USER_NAME_PRINT ; 
 int /*<<< orphan*/  SessionMain (TYPE_3__*) ; 
 int /*<<< orphan*/  StopSession (TYPE_3__*) ; 
 int /*<<< orphan*/  Unlock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  VirtualInit (TYPE_9__*) ; 
 int /*<<< orphan*/  Virtual_Free (TYPE_9__*) ; 
 int /*<<< orphan*/  WaitThreadInit (int /*<<< orphan*/ *) ; 
 TYPE_2__* ZeroMalloc (int) ; 

void SnSecureNATThread(THREAD *t, void *param)
{
	SNAT *s;
	CONNECTION *c;
	SESSION *se;
	POLICY *policy;
	HUB *h;
	// Validate arguments
	if (t == NULL || param == NULL)
	{
		return;
	}

	s = (SNAT *)param;
	// Create a server connection
	c = NewServerConnection(s->Cedar, NULL, t);
	c->Protocol = CONNECTION_HUB_SECURE_NAT;

	// Apply the default policy
	policy = ClonePolicy(GetDefaultPolicy());

	// Not to limit the number of broadcast
	policy->NoBroadcastLimiter = true;

	h = s->Hub;
	AddRef(h->ref);

	// create a server session
	se = NewServerSession(s->Cedar, c, s->Hub, SNAT_USER_NAME, policy);
	se->SecureNATMode = true;
	se->SecureNAT = s;
	c->Session = se;
	ReleaseConnection(c);

	HLog(se->Hub, "LH_NAT_START", se->Name);

	// User name
	se->Username = CopyStr(SNAT_USER_NAME_PRINT);

	s->Session = se;
	AddRef(se->ref);

	// Notification initialization completion
	NoticeThreadInit(t);

	ReleaseCancel(s->Nat->Virtual->Cancel);
	s->Nat->Virtual->Cancel = se->Cancel1;
	AddRef(se->Cancel1->ref);

	if (s->Nat->Virtual->NativeNat != NULL)
	{
		CANCEL *old_cancel = NULL;

		Lock(s->Nat->Virtual->NativeNat->CancelLock);
		{
			if (s->Nat->Virtual->NativeNat->Cancel != NULL)
			{
				old_cancel = s->Nat->Virtual->NativeNat->Cancel;

				s->Nat->Virtual->NativeNat->Cancel = se->Cancel1;

				AddRef(se->Cancel1->ref);
			}
		}
		Unlock(s->Nat->Virtual->NativeNat->CancelLock);

		if (old_cancel != NULL)
		{
			ReleaseCancel(old_cancel);
		}
	}

	// Main function of the session
	Debug("SecureNAT Start.\n");
	SessionMain(se);
	Debug("SecureNAT Stop.\n");

	HLog(se->Hub, "LH_NAT_STOP");

	ReleaseHub(h);

	ReleaseSession(se);
}

void SnFreeSecureNAT(SNAT *s)
{
	// Validate arguments
	if (s == NULL)
	{
		return;
	}

	// Stop the session 
	StopSession(s->Session);
	ReleaseSession(s->Session);

	// Virtual machine release
	Virtual_Free(s->Nat->Virtual);

	// NAT release
	NiFreeNat(s->Nat);

	DeleteLock(s->lock);

	Free(s);
}

SNAT *SnNewSecureNAT(HUB *h, VH_OPTION *o)
{
	SNAT *s;
	THREAD *t;
	// Validate arguments
	if (h == NULL || o == NULL)
	{
		return NULL;
	}

	s = ZeroMalloc(sizeof(SNAT));
	s->Cedar = h->Cedar;
	s->Hub = h;
	s->lock = NewLock();

	// Create a NAT
	s->Nat = NiNewNatEx(s, o);

	// Initialize the virtual machine
	VirtualInit(s->Nat->Virtual);

	// Create a thread
	t = NewThread(SnSecureNATThread, s);
	WaitThreadInit(t);
	ReleaseThread(t);

	return s;
}

