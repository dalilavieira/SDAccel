#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  zbar_timer_t ;
struct TYPE_4__ {int started; int /*<<< orphan*/ * activity; int /*<<< orphan*/ * notify; scalar_t__ running; } ;
typedef  TYPE_1__ zbar_thread_t ;
typedef  int /*<<< orphan*/  zbar_thread_proc_t ;
typedef  int /*<<< orphan*/  zbar_mutex_t ;
typedef  int /*<<< orphan*/ * zbar_event_t ;
typedef  int /*<<< orphan*/ * HANDLE ;

/* Variables and functions */
 int /*<<< orphan*/  CloseHandle (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * CreateEvent (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * CreateThread (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,void*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SetEvent (int /*<<< orphan*/ *) ; 
 int WAIT_TIMEOUT ; 
 int WaitForSingleObject (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  _zbar_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  _zbar_mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  _zbar_timer_check (int /*<<< orphan*/ *) ; 

int _zbar_event_init (zbar_event_t *event)
{
    *event = CreateEvent(NULL, 0, 0, NULL);
    return((*event) ? 0 : -1);
}

void _zbar_event_destroy (zbar_event_t *event)
{
    if(*event) {
        CloseHandle(*event);
        *event = NULL;
    }
}

void _zbar_event_trigger (zbar_event_t *event)
{
    SetEvent(*event);
}

int _zbar_event_wait (zbar_event_t *event,
                      zbar_mutex_t *lock,
                      zbar_timer_t *timeout)
{
    if(lock)
        _zbar_mutex_unlock(lock);
    int rc = WaitForSingleObject(*event, _zbar_timer_check(timeout));
    if(lock)
        _zbar_mutex_lock(lock);

    if(!rc)
        return(1); /* got event */
    if(rc == WAIT_TIMEOUT)
        return(0); /* timed out */
    return(-1); /* error (FIXME save info) */
}

int _zbar_thread_start (zbar_thread_t *thr,
                        zbar_thread_proc_t *proc,
                        void *arg,
                        zbar_mutex_t *lock)
{
    if(thr->started || thr->running)
        return(-1/*FIXME*/);
    thr->started = 1;
    _zbar_event_init(&thr->notify);
    _zbar_event_init(&thr->activity);

    HANDLE hthr = CreateThread(NULL, 0, proc, arg, 0, NULL);
    int rc = (!hthr ||
              _zbar_event_wait(&thr->activity, NULL, NULL) < 0 ||
              !thr->running);
    CloseHandle(hthr);
    if(rc) {
        thr->started = 0;
        _zbar_event_destroy(&thr->notify);
        _zbar_event_destroy(&thr->activity);
        return(-1/*FIXME*/);
    }
    return(0);
}

int _zbar_thread_stop (zbar_thread_t *thr,
                       zbar_mutex_t *lock)
{
    if(thr->started) {
        thr->started = 0;
        _zbar_event_trigger(&thr->notify);
        while(thr->running)
            /* FIXME time out and abandon? */
            _zbar_event_wait(&thr->activity, lock, NULL);
        _zbar_event_destroy(&thr->notify);
        _zbar_event_destroy(&thr->activity);
    }
    return(0);
}

