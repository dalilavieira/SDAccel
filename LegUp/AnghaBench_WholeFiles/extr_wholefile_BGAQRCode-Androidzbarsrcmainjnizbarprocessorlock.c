#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_2__ ;
typedef  struct TYPE_18__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  zbar_timer_t ;
struct TYPE_18__ {int lock_level; int /*<<< orphan*/  mutex; void* lock_owner; TYPE_2__* wait_next; scalar_t__ threaded; int /*<<< orphan*/  video; scalar_t__ streaming; TYPE_2__* wait_head; TYPE_2__* free_waiter; TYPE_2__* wait_tail; } ;
typedef  TYPE_1__ zbar_processor_t ;
typedef  int /*<<< orphan*/  zbar_image_t ;
struct TYPE_19__ {unsigned int events; int /*<<< orphan*/  notify; struct TYPE_19__* next; void* requester; } ;
typedef  TYPE_2__ proc_waiter_t ;

/* Variables and functions */
 unsigned int EVENTS_PENDING ; 
 unsigned int EVENT_CANCELED ; 
 int MAX_INPUT_BLOCK ; 
 int /*<<< orphan*/  _zbar_event_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  _zbar_event_trigger (int /*<<< orphan*/ *) ; 
 int _zbar_event_wait (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  _zbar_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  _zbar_mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  _zbar_process_image (TYPE_1__*,int /*<<< orphan*/ *) ; 
 int _zbar_processor_input_wait (TYPE_1__*,int /*<<< orphan*/ *,int) ; 
 int _zbar_thread_is_self (void*) ; 
 void* _zbar_thread_self () ; 
 int _zbar_timer_check (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  assert (int) ; 
 TYPE_2__* calloc (int,int) ; 
 int /*<<< orphan*/  zbar_image_destroy (int /*<<< orphan*/ *) ; 
 scalar_t__ zbar_video_get_fd (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * zbar_video_next_image (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline proc_waiter_t *proc_waiter_queue (zbar_processor_t *proc)
{
    proc_waiter_t *waiter = proc->free_waiter;
    if(waiter) {
        proc->free_waiter = waiter->next;
        waiter->events = 0;
    }
    else {
        waiter = calloc(1, sizeof(proc_waiter_t));
        _zbar_event_init(&waiter->notify);
    }

    waiter->next = NULL;
    waiter->requester = _zbar_thread_self();

    if(proc->wait_head)
        proc->wait_tail->next = waiter;
    else
        proc->wait_head = waiter;
    proc->wait_tail = waiter;
    return(waiter);
}

__attribute__((used)) static inline proc_waiter_t *proc_waiter_dequeue (zbar_processor_t *proc)
{
    proc_waiter_t *prev = proc->wait_next, *waiter;
    if(prev)
        waiter = prev->next;
    else
        waiter = proc->wait_head;
    while(waiter && (waiter->events & EVENTS_PENDING)) {
        prev = waiter;
        proc->wait_next = waiter;
        waiter = waiter->next;
    }

    if(waiter) {
        if(prev)
            prev->next = waiter->next;
        else
            proc->wait_head = waiter->next;
        if(!waiter->next)
            proc->wait_tail = prev;
        waiter->next = NULL;

        proc->lock_level = 1;
        proc->lock_owner = waiter->requester;
    }
    return(waiter);
}

__attribute__((used)) static inline void proc_waiter_release (zbar_processor_t *proc,
                                        proc_waiter_t *waiter)
{
    if(waiter) {
        waiter->next = proc->free_waiter;
        proc->free_waiter = waiter;
    }
}

int _zbar_processor_lock (zbar_processor_t *proc)
{
    if(!proc->lock_level) {
        proc->lock_owner = _zbar_thread_self();
        proc->lock_level = 1;
        return(0);
    }

    if(_zbar_thread_is_self(proc->lock_owner)) {
        proc->lock_level++;
        return(0);
    }

    proc_waiter_t *waiter = proc_waiter_queue(proc);
    _zbar_event_wait(&waiter->notify, &proc->mutex, NULL);

    assert(proc->lock_level == 1);
    assert(_zbar_thread_is_self(proc->lock_owner));

    proc_waiter_release(proc, waiter);
    return(0);
}

int _zbar_processor_unlock (zbar_processor_t *proc,
                            int all)
{
    assert(proc->lock_level > 0);
    assert(_zbar_thread_is_self(proc->lock_owner));

    if(all)
        proc->lock_level = 0;
    else
        proc->lock_level--;

    if(!proc->lock_level) {
        proc_waiter_t *waiter = proc_waiter_dequeue(proc);
        if(waiter)
            _zbar_event_trigger(&waiter->notify);
    }
    return(0);
}

void _zbar_processor_notify (zbar_processor_t *proc,
                             unsigned events)
{
    proc->wait_next = NULL;
    proc_waiter_t *waiter;
    for(waiter = proc->wait_head; waiter; waiter = waiter->next)
        waiter->events = ((waiter->events & ~events) |
                          (events & EVENT_CANCELED));

    if(!proc->lock_level) {
        waiter = proc_waiter_dequeue(proc);
        if(waiter)
            _zbar_event_trigger(&waiter->notify);
    }
}

__attribute__((used)) static inline int proc_wait_unthreaded (zbar_processor_t *proc,
                                        proc_waiter_t *waiter,
                                        zbar_timer_t *timeout)
{
    int blocking = proc->streaming && zbar_video_get_fd(proc->video) < 0;
    _zbar_mutex_unlock(&proc->mutex);

    int rc = 1;
    while(rc > 0 && (waiter->events & EVENTS_PENDING)) {
        /* FIXME lax w/the locking (though shouldn't matter...) */
        if(blocking) {
            zbar_image_t *img = zbar_video_next_image(proc->video);
            if(!img) {
                rc = -1;
                break;
            }

            /* FIXME reacquire API lock! (refactor w/video thread?) */
            _zbar_mutex_lock(&proc->mutex);
            _zbar_process_image(proc, img);
            zbar_image_destroy(img);
            _zbar_mutex_unlock(&proc->mutex);
        }
        int reltime = _zbar_timer_check(timeout);
        if(blocking && (reltime < 0 || reltime > MAX_INPUT_BLOCK))
            reltime = MAX_INPUT_BLOCK;
        rc = _zbar_processor_input_wait(proc, NULL, reltime);
    }
    _zbar_mutex_lock(&proc->mutex);
    return(rc);
}

int _zbar_processor_wait (zbar_processor_t *proc,
                          unsigned events,
                          zbar_timer_t *timeout)
{
    _zbar_mutex_lock(&proc->mutex);
    int save_level = proc->lock_level;
    proc_waiter_t *waiter = proc_waiter_queue(proc);
    waiter->events = events & EVENTS_PENDING;

    _zbar_processor_unlock(proc, 1);
    int rc;
    if(proc->threaded)
        rc = _zbar_event_wait(&waiter->notify, &proc->mutex, timeout);
    else
        rc = proc_wait_unthreaded(proc, waiter, timeout);

    if(rc <= 0 || !proc->threaded) {
        /* reacquire api lock */
        waiter->events &= EVENT_CANCELED;
        proc->wait_next = NULL;
        if(!proc->lock_level) {
            proc_waiter_t *w = proc_waiter_dequeue(proc);
            assert(w == waiter);
        }
        else
            _zbar_event_wait(&waiter->notify, &proc->mutex, NULL);
    }
    if(rc > 0 && (waiter->events & EVENT_CANCELED))
        rc = -1;

    assert(proc->lock_level == 1);
    assert(_zbar_thread_is_self(proc->lock_owner));

    proc->lock_level = save_level;
    proc_waiter_release(proc, waiter);
    _zbar_mutex_unlock(&proc->mutex);
    return(rc);
}

