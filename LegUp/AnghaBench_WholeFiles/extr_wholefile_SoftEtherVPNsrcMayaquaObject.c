#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_28__   TYPE_3__ ;
typedef  struct TYPE_27__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  msg ;
typedef  int /*<<< orphan*/  c ;
typedef  scalar_t__ UINT64 ;
typedef  scalar_t__ UINT ;
struct TYPE_28__ {int Unlocked; scalar_t__ Timeout; int /*<<< orphan*/ * Lock; } ;
struct TYPE_27__ {int Ready; scalar_t__ c; struct TYPE_27__* ref; int /*<<< orphan*/ * lock; } ;
typedef  int /*<<< orphan*/  THREAD ;
typedef  TYPE_1__ REF ;
typedef  int /*<<< orphan*/  LOCK ;
typedef  TYPE_1__ EVENT ;
typedef  TYPE_3__ DEADCHECK ;
typedef  TYPE_1__ COUNTER ;

/* Variables and functions */
 int /*<<< orphan*/  AbortExitEx (char*) ; 
 void CleanupEvent (TYPE_1__*) ; 
 int /*<<< orphan*/  Format (char*,int,char*,char*) ; 
 int /*<<< orphan*/  Free (TYPE_1__*) ; 
 scalar_t__ INFINITE ; 
 int /*<<< orphan*/  KS_ADDREF_COUNT ; 
 int /*<<< orphan*/  KS_CURRENT_COUNT ; 
 int /*<<< orphan*/  KS_CURRENT_LOCKED_COUNT ; 
 int /*<<< orphan*/  KS_CURRENT_LOCK_COUNT ; 
 int /*<<< orphan*/  KS_CURRENT_REFED_COUNT ; 
 int /*<<< orphan*/  KS_CURRENT_REF_COUNT ; 
 int /*<<< orphan*/  KS_DEC (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  KS_DEC_COUNT ; 
 int /*<<< orphan*/  KS_DELETELOCK_COUNT ; 
 int /*<<< orphan*/  KS_DELETE_COUNTER_COUNT ; 
 int /*<<< orphan*/  KS_FREEEVENT_COUNT ; 
 int /*<<< orphan*/  KS_FREEREF_COUNT ; 
 int /*<<< orphan*/  KS_INC (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  KS_INC_COUNT ; 
 int /*<<< orphan*/  KS_LOCK_COUNT ; 
 int /*<<< orphan*/  KS_NEWEVENT_COUNT ; 
 int /*<<< orphan*/  KS_NEWLOCK_COUNT ; 
 int /*<<< orphan*/  KS_NEWREF_COUNT ; 
 int /*<<< orphan*/  KS_NEW_COUNTER_COUNT ; 
 int /*<<< orphan*/  KS_RELEASE_COUNT ; 
 int /*<<< orphan*/  KS_SUB (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  KS_UNLOCK_COUNT ; 
 int /*<<< orphan*/  KS_WAIT_COUNT ; 
 int /*<<< orphan*/  Lock (int /*<<< orphan*/ *) ; 
 int MAX_PATH ; 
 scalar_t__ MIN (scalar_t__,int) ; 
 TYPE_1__* Malloc (int) ; 
 int /*<<< orphan*/ * NewThread (void (*) (int /*<<< orphan*/ *,void*),TYPE_3__*) ; 
 int /*<<< orphan*/  NoticeThreadInit (int /*<<< orphan*/ *) ; 
 scalar_t__ OBJECT_ALLOC_FAIL_SLEEP_TIME ; 
 scalar_t__ OBJECT_ALLOC__MAX_RETRY ; 
 int /*<<< orphan*/  OSDeleteLock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  OSFreeEvent (TYPE_1__*) ; 
 int /*<<< orphan*/  OSInitEvent (TYPE_1__*) ; 
 int OSLock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * OSNewLock () ; 
 int /*<<< orphan*/  OSSetEvent (TYPE_1__*) ; 
 int /*<<< orphan*/  OSUnlock (int /*<<< orphan*/ *) ; 
 int OSWaitEvent (TYPE_1__*,scalar_t__) ; 
 int /*<<< orphan*/  ReleaseThread (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SleepThread (scalar_t__) ; 
 scalar_t__ Tick64 () ; 
 int /*<<< orphan*/  Unlock (int /*<<< orphan*/ *) ; 
 int WaitThread (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  WaitThreadInit (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  Zero (TYPE_3__*,int) ; 

void CheckDeadLockThread(THREAD *t, void *param)
{
	DEADCHECK *c = (DEADCHECK *)param;

	if (t == NULL || c == NULL)
	{
		return;
	}

	NoticeThreadInit(t);

	Lock(c->Lock);
	Unlock(c->Lock);
	c->Unlocked = true;
}

void CheckDeadLock(LOCK *lock, UINT timeout, char *name)
{
	DEADCHECK c;
	THREAD *t;
	char msg[MAX_PATH];

	if (lock == NULL)
	{
		return;
	}
	if (name == NULL)
	{
		name = "Unknown";
	}

	Format(msg, sizeof(msg), "error: CheckDeadLock() Failed: %s\n", name);

	Zero(&c, sizeof(c));
	c.Lock = lock;
	c.Timeout = timeout;
	c.Unlocked = false;

	t = NewThread(CheckDeadLockThread, &c);
	WaitThreadInit(t);
	if (WaitThread(t, timeout) == false)
	{
		if (c.Unlocked == false)
		{
			// Deadlock occured
			AbortExitEx(msg);
		}
		else
		{
			WaitThread(t, INFINITE);
		}
	}

	ReleaseThread(t);
}

LOCK *NewLockMain()
{
	LOCK *lock;
	UINT retry = 0;

	while (true)
	{
		if ((retry++) > OBJECT_ALLOC__MAX_RETRY)
		{
			AbortExitEx("error: OSNewLock() failed.\n\n");
		}
		lock = OSNewLock();
		if (lock != NULL)
		{
			break;
		}
		SleepThread(OBJECT_ALLOC_FAIL_SLEEP_TIME);
	}

	return lock;
}

LOCK *NewLock()
{
	LOCK *lock = NewLockMain();

	// KS
	KS_INC(KS_NEWLOCK_COUNT);
	KS_INC(KS_CURRENT_LOCK_COUNT);

	return lock;
}

void DeleteLock(LOCK *lock)
{
	// Validate arguments
	if (lock == NULL)
	{
		return;
	}

	// KS
	KS_INC(KS_DELETELOCK_COUNT);
	KS_DEC(KS_CURRENT_LOCK_COUNT);

	OSDeleteLock(lock);
}

bool LockInner(LOCK *lock)
{
	// Validate arguments
	if (lock == NULL)
	{
		return false;
	}

	// KS
	KS_INC(KS_LOCK_COUNT);
	KS_INC(KS_CURRENT_LOCKED_COUNT);

	return OSLock(lock);
}

void UnlockInner(LOCK *lock)
{
	// Validate arguments
	if (lock == NULL)
	{
		return;
	}

	// KS
	KS_INC(KS_UNLOCK_COUNT);
	KS_DEC(KS_CURRENT_LOCKED_COUNT);

	OSUnlock(lock);
}

COUNTER *NewCounter()
{
	COUNTER *c;

	// Memory allocation
	c = Malloc(sizeof(COUNTER));

	// Initialization
	c->Ready = true;
	c->c = 0;

	// Lock created
	c->lock = NewLock();

	// KS
	KS_INC(KS_NEW_COUNTER_COUNT);

	return c;
}

void DeleteCounter(COUNTER *c)
{
	// Validate arguments
	if (c == NULL)
	{
		return;
	}

	// KS
	KS_INC(KS_DELETE_COUNTER_COUNT);
	KS_SUB(KS_CURRENT_COUNT, c->c);

	DeleteLock(c->lock);
	Free(c);
}

UINT Count(COUNTER *c)
{
	UINT ret;
	// Validate arguments
	if (c == NULL)
	{
		return 0;
	}
	if (c->Ready == false)
	{
		return 0;
	}

	Lock(c->lock);
	{
		ret = c->c;
	}
	Unlock(c->lock);

	return ret;
}

UINT Inc(COUNTER *c)
{
	UINT ret;
	// Validate arguments
	if (c == NULL)
	{
		return 0;
	}
	if (c->Ready == false)
	{
		return 0;
	}

	Lock(c->lock);
	{
		c->c++;
		ret = c->c;
	}
	Unlock(c->lock);

	// KS
	KS_INC(KS_INC_COUNT);
	KS_INC(KS_CURRENT_COUNT);

	return ret;
}

UINT Dec(COUNTER *c)
{
	UINT ret;
	// Validate arguments
	if (c == NULL)
	{
		return 0;
	}
	if (c->Ready == false)
	{
		return 0;
	}

	Lock(c->lock);
	{
		if (c->c != 0)
		{
			c->c--;
			ret = c->c;
		}
		else
		{
			ret = 0;
		}
	}
	Unlock(c->lock);

	// KS
	KS_INC(KS_DEC_COUNT);
	KS_DEC(KS_CURRENT_COUNT);

	return ret;
}

UINT Release(REF *ref)
{
	UINT c;
	// Validate arguments
	if (ref == NULL)
	{
		return 0;
	}

	// KS
	KS_INC(KS_RELEASE_COUNT);
	KS_DEC(KS_CURRENT_REFED_COUNT);

	c = Dec(ref->c);
	if (c == 0)
	{
		// KS
		KS_DEC(KS_CURRENT_REF_COUNT);
		KS_INC(KS_FREEREF_COUNT);

		DeleteCounter(ref->c);
		ref->c = 0;
		Free(ref);
	}
	return c;
}

UINT AddRef(REF *ref)
{
	UINT c;
	// Validate arguments
	if (ref == NULL)
	{
		return 0;
	}

	c = Inc(ref->c);

	// KS
	KS_INC(KS_ADDREF_COUNT);
	KS_INC(KS_CURRENT_REFED_COUNT);

	return c;
}

REF *NewRef()
{
	REF *ref;

	// Memory allocation
	ref = Malloc(sizeof(REF));

	// Create a Counter
	ref->c = NewCounter();

	// Increment only once
	Inc(ref->c);

	// KS
	KS_INC(KS_NEWREF_COUNT);
	KS_INC(KS_CURRENT_REF_COUNT);
	KS_INC(KS_ADDREF_COUNT);
	KS_INC(KS_CURRENT_REFED_COUNT);

	return ref;
}

EVENT *NewEvent()
{
	// Memory allocation
	EVENT *e = Malloc(sizeof(EVENT));

	// Reference counter
	e->ref = NewRef();

	// Event initialization
	OSInitEvent(e);

	// KS
	KS_INC(KS_NEWEVENT_COUNT);

	return e;
}

void ReleaseEvent(EVENT *e)
{
	// Validate arguments
	if (e == NULL)
	{
		return;
	}

	if (Release(e->ref) == 0)
	{
		CleanupEvent(e);
	}
}

void CleanupEvent(EVENT *e)
{
	// Validate arguments
	if (e == NULL)
	{
		return;
	}

	// Release event
	OSFreeEvent(e);

	// Memory release
	Free(e);

	// KS
	KS_INC(KS_FREEEVENT_COUNT);
}

void Set(EVENT *e)
{
	// Validate arguments
	if (e == NULL)
	{
		return;
	}

	OSSetEvent(e);
}

bool Wait(EVENT *e, UINT timeout)
{
	// Validate arguments
	if (e == NULL)
	{
		return false;
	}

	// KS
	KS_INC(KS_WAIT_COUNT);

	return OSWaitEvent(e, timeout);
}

bool WaitEx(EVENT *e, UINT timeout, volatile bool *cancel)
{
	bool dummy_bool = false;
	UINT64 start, giveup;
	// Validate arguments
	if (cancel == NULL)
	{
		cancel = &dummy_bool;
	}

	start = Tick64();

	if (timeout == INFINITE || timeout == 0x7FFFFFFF)
	{
		giveup = 0;
	}
	else
	{
		giveup = start + (UINT64)timeout;
	}

	while (true)
	{
		UINT64 now = Tick64();
		UINT interval_to_giveup = (UINT)(giveup - now);
		if (giveup == 0)
		{
			interval_to_giveup = INFINITE;
		}
		else
		{
			if (now >= giveup)
			{
				// Time-out occurs
				return false;
			}
		}

		interval_to_giveup = MIN(interval_to_giveup, 25);

		if (*cancel)
		{
			// Cancel flag is set to true. Time-out occurs
			return false;
		}

		if (e != NULL)
		{
			if (Wait(e, interval_to_giveup))
			{
				// Event is set
				return true;
			}
		}
		else
		{
			SleepThread(interval_to_giveup);
		}
	}
}

