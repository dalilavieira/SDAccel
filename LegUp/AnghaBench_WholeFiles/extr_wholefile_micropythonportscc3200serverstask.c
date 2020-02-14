#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint32_t ;
typedef  int int16_t ;
struct TYPE_2__ {int do_enable; int enabled; int do_disable; int do_reset; int do_wlan_cycle_power; scalar_t__ timeout; } ;

/* Variables and functions */
 int SERVERS_CYCLE_TIME_MS ; 
 int /*<<< orphan*/  SERVERS_DEF_PASS ; 
 int /*<<< orphan*/  SERVERS_DEF_USER ; 
 scalar_t__ SERVERS_MIN_TIMEOUT_MS ; 
 scalar_t__ SERVERS_USER_PASS_LEN_MAX ; 
 int /*<<< orphan*/  ftp_disable () ; 
 int /*<<< orphan*/  ftp_enable () ; 
 int /*<<< orphan*/  ftp_init () ; 
 int /*<<< orphan*/  ftp_reset () ; 
 int /*<<< orphan*/  ftp_run () ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,char*,scalar_t__) ; 
 int /*<<< orphan*/  modusocket_close_all_user_sockets () ; 
 int /*<<< orphan*/  modusocket_enter_sleep () ; 
 int /*<<< orphan*/  modusocket_socket_delete (int) ; 
 int /*<<< orphan*/  mp_hal_delay_ms (int) ; 
 int /*<<< orphan*/  mp_raise_ValueError (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpexception_value_invalid_arguments ; 
 int /*<<< orphan*/  pybwdt_srv_alive () ; 
 int /*<<< orphan*/  pybwdt_srv_sleeping (int) ; 
 int servers_are_enabled () ; 
 TYPE_1__ servers_data ; 
 int /*<<< orphan*/  servers_pass ; 
 int /*<<< orphan*/  servers_user ; 
 int /*<<< orphan*/  sl_Close (int) ; 
 int sleep_sockets ; 
 int /*<<< orphan*/  strcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ strlen (char*) ; 
 int /*<<< orphan*/  telnet_disable () ; 
 int /*<<< orphan*/  telnet_enable () ; 
 int /*<<< orphan*/  telnet_init () ; 
 int /*<<< orphan*/  telnet_reset () ; 
 int /*<<< orphan*/  telnet_run () ; 
 int /*<<< orphan*/  wlan_off_on () ; 

void TASK_Servers (void *pvParameters) {

    bool cycle = false;

    strcpy (servers_user, SERVERS_DEF_USER);
    strcpy (servers_pass, SERVERS_DEF_PASS);

    telnet_init();
    ftp_init();

    for ( ;; ) {

        if (servers_data.do_enable) {
            // enable network services
            telnet_enable();
            ftp_enable();
            // now set/clear the flags
            servers_data.enabled = true;
            servers_data.do_enable = false;
        }
        else if (servers_data.do_disable) {
            // disable network services
            telnet_disable();
            ftp_disable();
            // now clear the flags
            servers_data.do_disable = false;
            servers_data.enabled = false;
        }
        else if (servers_data.do_reset) {
            // resetting the servers is needed to prevent half-open sockets
            servers_data.do_reset = false;
            if (servers_data.enabled) {
                telnet_reset();
                ftp_reset();
            }
            // and we should also close all user sockets. We do it here
            // for convinience and to save on code size.
            modusocket_close_all_user_sockets();
        }

        if (cycle) {
            telnet_run();
        }
        else {
            ftp_run();
        }

        if (sleep_sockets) {
            pybwdt_srv_sleeping(true);
            modusocket_enter_sleep();
            pybwdt_srv_sleeping(false);
            mp_hal_delay_ms(SERVERS_CYCLE_TIME_MS * 2);
            if (servers_data.do_wlan_cycle_power) {
                servers_data.do_wlan_cycle_power = false;
                wlan_off_on();
            }
            sleep_sockets = false;

        }

        // set the alive flag for the wdt
        pybwdt_srv_alive();

        // move to the next cycle
        cycle = cycle ? false : true;
        mp_hal_delay_ms(SERVERS_CYCLE_TIME_MS);
    }
}

void servers_start (void) {
    servers_data.do_enable = true;
    mp_hal_delay_ms(SERVERS_CYCLE_TIME_MS * 3);
}

void servers_stop (void) {
    servers_data.do_disable = true;
    do {
        mp_hal_delay_ms(SERVERS_CYCLE_TIME_MS);
    } while (servers_are_enabled());
    mp_hal_delay_ms(SERVERS_CYCLE_TIME_MS * 3);
}

void servers_reset (void) {
    servers_data.do_reset = true;
}

void servers_wlan_cycle_power (void) {
    servers_data.do_wlan_cycle_power = true;
}

bool servers_are_enabled (void) {
    return servers_data.enabled;
}

void server_sleep_sockets (void) {
    sleep_sockets = true;
    mp_hal_delay_ms(SERVERS_CYCLE_TIME_MS + 1);
}

void servers_close_socket (int16_t *sd) {
    if (*sd > 0) {
        modusocket_socket_delete(*sd);
        sl_Close(*sd);
        *sd = -1;
    }
}

void servers_set_login (char *user, char *pass) {
    if (strlen(user) > SERVERS_USER_PASS_LEN_MAX || strlen(pass) > SERVERS_USER_PASS_LEN_MAX) {
        mp_raise_ValueError(mpexception_value_invalid_arguments);
    }
    memcpy(servers_user, user, SERVERS_USER_PASS_LEN_MAX);
    memcpy(servers_pass, pass, SERVERS_USER_PASS_LEN_MAX);
}

void servers_set_timeout (uint32_t timeout) {
    if (timeout < SERVERS_MIN_TIMEOUT_MS) {
        // timeout is too low
        mp_raise_ValueError(mpexception_value_invalid_arguments);
    }
    servers_data.timeout = timeout;
}

uint32_t servers_get_timeout (void) {
    return servers_data.timeout;
}

