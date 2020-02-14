#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ sys_prot_t ;
typedef  int /*<<< orphan*/  mp_uint_t ;
struct TYPE_5__ {scalar_t__ callback; } ;
typedef  TYPE_1__ lwip_socket_obj_t ;
struct TYPE_6__ {void (* poll ) (void*) ;void* poll_arg; } ;

/* Variables and functions */
 int /*<<< orphan*/  MICROPY_BEGIN_ATOMIC_SECTION () ; 
 int /*<<< orphan*/  MICROPY_END_ATOMIC_SECTION (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MP_OBJ_FROM_PTR (TYPE_1__*) ; 
 scalar_t__ MP_OBJ_NULL ; 
 TYPE_2__ lwip_poll_list ; 
 int /*<<< orphan*/  mp_call_function_1_protected (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mp_hal_delay_ms (int) ; 

__attribute__((used)) static inline void poll_sockets(void) {
#ifdef MICROPY_EVENT_POLL_HOOK
    MICROPY_EVENT_POLL_HOOK;
#else
    mp_hal_delay_ms(1);
#endif
}

__attribute__((used)) static inline void exec_user_callback(lwip_socket_obj_t *socket) {
    if (socket->callback != MP_OBJ_NULL) {
        mp_call_function_1_protected(socket->callback, MP_OBJ_FROM_PTR(socket));
    }
}

sys_prot_t sys_arch_protect() {
    return (sys_prot_t)MICROPY_BEGIN_ATOMIC_SECTION();
}

void sys_arch_unprotect(sys_prot_t state) {
    MICROPY_END_ATOMIC_SECTION((mp_uint_t)state);
}

void mod_lwip_register_poll(void (* poll)(void *arg), void *poll_arg) {
    lwip_poll_list.poll = poll;
    lwip_poll_list.poll_arg = poll_arg;
}

void mod_lwip_deregister_poll(void (* poll)(void *arg), void *poll_arg) {
    lwip_poll_list.poll = NULL;
}

