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
struct mg_q_msg {int type; int const member_0; void (* member_1 ) (struct mg_mgr*,void*) ;void* member_2; int /*<<< orphan*/  arg; int /*<<< orphan*/  (* cb ) (struct mg_mgr*,int /*<<< orphan*/ ) ;} ;
struct mg_mgr {int dummy; } ;
typedef  int /*<<< orphan*/  (* mg_init_cb ) (struct mg_mgr*) ;

/* Variables and functions */
#define  MG_Q_MSG_CB 128 
 int /*<<< orphan*/  OSI_NO_WAIT ; 
 scalar_t__ OSI_OK ; 
 int /*<<< orphan*/  mg_mgr_init (struct mg_mgr*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mg_mgr_poll (struct mg_mgr*,int) ; 
static  void mg_task (void*) ; 
 scalar_t__ osi_MsgQCreate (int /*<<< orphan*/ *,char*,int,int) ; 
 scalar_t__ osi_MsgQRead (int /*<<< orphan*/ *,struct mg_q_msg*,int) ; 
 int /*<<< orphan*/  osi_MsgQWrite (int /*<<< orphan*/ *,struct mg_q_msg*,int /*<<< orphan*/ ) ; 
 scalar_t__ osi_TaskCreate (void (*) (void*),char const*,int,void*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  s_mg_q ; 
 int /*<<< orphan*/  stub1 (struct mg_mgr*,int /*<<< orphan*/ ) ; 

bool mg_start_task(int priority, int stack_size, mg_init_cb mg_init) {
  if (osi_MsgQCreate(&s_mg_q, "MG", sizeof(struct mg_q_msg), 16) != OSI_OK) {
    return false;
  }
  if (osi_TaskCreate(mg_task, (const signed char *) "MG", stack_size,
                     (void *) mg_init, priority, NULL) != OSI_OK) {
    return false;
  }
  return true;
}

__attribute__((used)) static void mg_task(void *arg) {
  struct mg_mgr mgr;
  mg_init_cb mg_init = (mg_init_cb) arg;
  mg_mgr_init(&mgr, NULL);
  mg_init(&mgr);
  while (1) {
    struct mg_q_msg msg;
    mg_mgr_poll(&mgr, 1);
    if (osi_MsgQRead(&s_mg_q, &msg, 1) != OSI_OK) continue;
    switch (msg.type) {
      case MG_Q_MSG_CB: {
        msg.cb(&mgr, msg.arg);
      }
    }
  }
}

void mg_run_in_task(void (*cb)(struct mg_mgr *mgr, void *arg), void *cb_arg) {
  struct mg_q_msg msg = {MG_Q_MSG_CB, cb, cb_arg};
  osi_MsgQWrite(&s_mg_q, &msg, OSI_NO_WAIT);
}

