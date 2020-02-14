#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_1__* pthread_t ;
struct TYPE_6__ {int /*<<< orphan*/  global_locale; } ;
struct TYPE_5__ {int /*<<< orphan*/ * locale; } ;

/* Variables and functions */
 TYPE_1__ __main_pthread ; 
 TYPE_3__ libc ; 

pthread_t pthread_self(void) {
    return &__main_pthread;
}

__attribute__((constructor))
void __emscripten_pthread_data_constructor(void) {
    pthread_self()->locale = &libc.global_locale;
}

