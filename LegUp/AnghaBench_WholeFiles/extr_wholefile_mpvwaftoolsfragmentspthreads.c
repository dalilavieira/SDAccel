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
typedef  int /*<<< orphan*/  pthread_t ;

/* Variables and functions */
 scalar_t__ pthread_create (int /*<<< orphan*/ *,int /*<<< orphan*/ ,void* (*) (void*),int /*<<< orphan*/ ) ; 

__attribute__((used)) static void *func(void *arg) { return arg; }

int main(void) {
    pthread_t tid;
    return pthread_create (&tid, 0, func, 0) != 0;
}

