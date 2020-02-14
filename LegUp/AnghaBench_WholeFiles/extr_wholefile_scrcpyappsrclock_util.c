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
typedef  int /*<<< orphan*/  SDL_mutex ;
typedef  int /*<<< orphan*/  SDL_cond ;

/* Variables and functions */
 int /*<<< orphan*/  LOGC (char*) ; 
 scalar_t__ SDL_CondSignal (int /*<<< orphan*/ *) ; 
 scalar_t__ SDL_CondWait (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ SDL_LockMutex (int /*<<< orphan*/ *) ; 
 scalar_t__ SDL_UnlockMutex (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  abort () ; 

void
mutex_lock(SDL_mutex *mutex) {
    if (SDL_LockMutex(mutex)) {
        LOGC("Could not lock mutex");
        abort();
    }
}

void
mutex_unlock(SDL_mutex *mutex) {
    if (SDL_UnlockMutex(mutex)) {
        LOGC("Could not unlock mutex");
        abort();
    }
}

void
cond_wait(SDL_cond *cond, SDL_mutex *mutex) {
    if (SDL_CondWait(cond, mutex)) {
        LOGC("Could not wait on condition");
        abort();
    }
}

void
cond_signal(SDL_cond *cond) {
    if (SDL_CondSignal(cond)) {
        LOGC("Could not signal a condition");
        abort();
    }
}

