#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint32_t ;
struct TYPE_5__ {scalar_t__ timeout_ms; } ;
struct TYPE_6__ {TYPE_1__ sock_base; } ;
typedef  TYPE_2__ mod_network_socket_obj_t ;
typedef  scalar_t__ int16_t ;
struct TYPE_7__ {scalar_t__ sd; int user; } ;
typedef  int /*<<< orphan*/  SlFdSet_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int MOD_NETWORK_MAX_SOCKETS ; 
 int MP_ETIMEDOUT ; 
 scalar_t__ OSI_OK ; 
 int SL_EAGAIN ; 
 int /*<<< orphan*/  SL_FD_SET (scalar_t__,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SL_OS_WAIT_FOREVER ; 
 scalar_t__ SOCKET_TIMEOUT_QUANTA_MS ; 
 int convert_sl_errno (int) ; 
 int /*<<< orphan*/  modusocket_LockObj ; 
 TYPE_3__* modusocket_sockets ; 
 int /*<<< orphan*/  mp_hal_delay_ms (scalar_t__) ; 
 int /*<<< orphan*/  sl_Close (scalar_t__) ; 
 scalar_t__ sl_LockObjCreate (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  sl_LockObjLock (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sl_LockObjUnlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sl_Select (scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

int check_timedout(mod_network_socket_obj_t *s, int ret, uint32_t *timeout_ms, int *_errno) {
    if (*timeout_ms == 0 || ret != SL_EAGAIN) {
        if (s->sock_base.timeout_ms > 0 && ret == SL_EAGAIN) {
            *_errno = MP_ETIMEDOUT;
        } else {
            *_errno = convert_sl_errno(ret);
        }
        return -1;
    }
    mp_hal_delay_ms(SOCKET_TIMEOUT_QUANTA_MS);
    if (*timeout_ms < SOCKET_TIMEOUT_QUANTA_MS) {
        *timeout_ms = 0;
    } else {
        *timeout_ms -= SOCKET_TIMEOUT_QUANTA_MS;
    }
    return 0;
}

__attribute__ ((section (".boot")))
void modusocket_pre_init (void) {
    // create the wlan lock
    ASSERT(OSI_OK == sl_LockObjCreate(&modusocket_LockObj, "SockLock"));
    sl_LockObjUnlock (&modusocket_LockObj);
}

void modusocket_socket_add (int16_t sd, bool user) {
    sl_LockObjLock (&modusocket_LockObj, SL_OS_WAIT_FOREVER);
    for (int i = 0; i < MOD_NETWORK_MAX_SOCKETS; i++) {
        if (modusocket_sockets[i].sd < 0) {
            modusocket_sockets[i].sd = sd;
            modusocket_sockets[i].user = user;
            break;
        }
    }
    sl_LockObjUnlock (&modusocket_LockObj);
}

void modusocket_socket_delete (int16_t sd) {
    sl_LockObjLock (&modusocket_LockObj, SL_OS_WAIT_FOREVER);
    for (int i = 0; i < MOD_NETWORK_MAX_SOCKETS; i++) {
        if (modusocket_sockets[i].sd == sd) {
            modusocket_sockets[i].sd = -1;
            break;
        }
    }
    sl_LockObjUnlock (&modusocket_LockObj);
}

void modusocket_enter_sleep (void) {
    SlFdSet_t socketset;
    int16_t maxfd = 0;

    for (int i = 0; i < MOD_NETWORK_MAX_SOCKETS; i++) {
        int16_t sd;
        if ((sd = modusocket_sockets[i].sd) >= 0) {
            SL_FD_SET(sd, &socketset);
            maxfd = (maxfd > sd) ? maxfd : sd;
        }
    }

    if (maxfd > 0) {
        // wait for any of the sockets to become ready...
        sl_Select(maxfd + 1, &socketset, NULL, NULL, NULL);
    }
}

void modusocket_close_all_user_sockets (void) {
    sl_LockObjLock (&modusocket_LockObj, SL_OS_WAIT_FOREVER);
    for (int i = 0; i < MOD_NETWORK_MAX_SOCKETS; i++) {
        if (modusocket_sockets[i].sd >= 0 && modusocket_sockets[i].user) {
            sl_Close(modusocket_sockets[i].sd);
            modusocket_sockets[i].sd = -1;
        }
    }
    sl_LockObjUnlock (&modusocket_LockObj);
}

