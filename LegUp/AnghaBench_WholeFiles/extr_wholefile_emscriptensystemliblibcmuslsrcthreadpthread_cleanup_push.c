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
struct __ptcb {void (* __f ) (void*) ;void* __x; } ;

/* Variables and functions */
 int /*<<< orphan*/  __do_cleanup_pop (struct __ptcb*) ; 
 int /*<<< orphan*/  __do_cleanup_push (struct __ptcb*) ; 
 void stub1 (void*) ; 

__attribute__((used)) static void dummy(struct __ptcb *cb)
{
}

void _pthread_cleanup_push(struct __ptcb *cb, void (*f)(void *), void *x)
{
	cb->__f = f;
	cb->__x = x;
	__do_cleanup_push(cb);
}

void _pthread_cleanup_pop(struct __ptcb *cb, int run)
{
	__do_cleanup_pop(cb);
	if (run) cb->__f(cb->__x);
}

