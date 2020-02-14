#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_6__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct process_id {int dummy; } ;
struct TYPE_7__ {scalar_t__ ip; scalar_t__ port; scalar_t__ pid; scalar_t__ utime; } ;
typedef  TYPE_1__ npid_t ;
struct TYPE_8__ {unsigned int ip; int port; scalar_t__ utime; scalar_t__ pid; } ;

/* Variables and functions */
 TYPE_6__ PID ; 
 scalar_t__ getpid () ; 
 int /*<<< orphan*/  memcmp (TYPE_1__*,TYPE_1__*,int) ; 
 scalar_t__ time (int /*<<< orphan*/ ) ; 

void init_common_PID (void) {
  if (!PID.pid) {
    PID.pid = getpid ();
  }
  if (!PID.utime) {
    PID.utime = time (0);
  }
}

void init_client_PID (unsigned ip) {
  if (ip && ip != 0x7f000001) {
    PID.ip = ip;
  }
  // PID.port = 0;
  init_common_PID ();
}

void init_server_PID (unsigned ip, int port) {
  if (ip && ip != 0x7f000001) {
    PID.ip = ip;
  }
  if (!PID.port) {
    PID.port = port;
  }
  init_common_PID ();
}

int matches_pid (npid_t *X, npid_t *Y) {
  if (!memcmp (X, Y, sizeof (struct process_id))) {
    return 2;
  } else if ((!Y->ip || X->ip == Y->ip) && (!Y->port || X->port == Y->port) && (!Y->pid || X->pid == Y->pid) && (!Y->utime || X->utime == Y->utime)) {
    return 1;
  } else {
    return 0;
  }
}

