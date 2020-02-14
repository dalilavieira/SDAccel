#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_4__ ;
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint16_t ;
struct RClass {int dummy; } ;
struct TYPE_16__ {int wcnt; TYPE_4__* dbg; int /*<<< orphan*/ * words; } ;
typedef  TYPE_2__ mrdb_state ;
struct TYPE_17__ {TYPE_1__* c; int /*<<< orphan*/  eException_class; } ;
typedef  TYPE_3__ mrb_state ;
struct TYPE_18__ {scalar_t__ xm; scalar_t__ xphase; int /*<<< orphan*/  prvci; int /*<<< orphan*/  ccnt; } ;
typedef  TYPE_4__ mrb_debug_context ;
typedef  int /*<<< orphan*/  dbgcmd_state ;
struct TYPE_15__ {int /*<<< orphan*/  ci; } ;

/* Variables and functions */
 int /*<<< orphan*/  DBGST_CONTINUE ; 
 int /*<<< orphan*/  DBGST_RESTART ; 
 scalar_t__ DBG_INIT ; 
 scalar_t__ DBG_NEXT ; 
 scalar_t__ DBG_PHASE_AFTER_RUN ; 
 scalar_t__ DBG_PHASE_RUNNING ; 
 void* DBG_QUIT ; 
 void* DBG_RUN ; 
 scalar_t__ DBG_STEP ; 
 struct RClass* mrb_define_class (TYPE_3__*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_raise (TYPE_3__*,struct RClass*,char*) ; 
 int /*<<< orphan*/  puts (char*) ; 
 int /*<<< orphan*/  sscanf (int /*<<< orphan*/ ,char*,int*) ; 

dbgcmd_state
dbgcmd_run(mrb_state *mrb, mrdb_state *mrdb)
{
  mrb_debug_context *dbg = mrdb->dbg;

  if (dbg->xm == DBG_INIT){
    dbg->xm = DBG_RUN;
  }
  else {
    dbg->xm = DBG_QUIT;
    if (dbg->xphase == DBG_PHASE_RUNNING){
      struct RClass *exc;
      puts("Start it from the beginning.");
      exc = mrb_define_class(mrb, "DebuggerRestart", mrb->eException_class);
      mrb_raise(mrb, exc, "Restart mrdb.");
    }
  }

  return DBGST_RESTART;
}

dbgcmd_state
dbgcmd_continue(mrb_state *mrb, mrdb_state *mrdb)
{
  mrb_debug_context *dbg = mrdb->dbg;
  int ccnt = 1;

  if (mrdb->wcnt > 1){
    sscanf(mrdb->words[1], "%d", &ccnt);
  }
  dbg->ccnt = (uint16_t)(ccnt > 0 ? ccnt : 1);  /* count of continue */

  if (dbg->xphase == DBG_PHASE_AFTER_RUN){
    puts("The program is not running.");
    dbg->xm = DBG_QUIT;
  }
  else {
    dbg->xm = DBG_RUN;
  }
  return DBGST_CONTINUE;
}

dbgcmd_state
dbgcmd_step(mrb_state *mrb, mrdb_state *mrdb)
{
  mrdb->dbg->xm = DBG_STEP;
  return DBGST_CONTINUE;
}

dbgcmd_state
dbgcmd_next(mrb_state *mrb, mrdb_state *mrdb)
{
  mrdb->dbg->xm = DBG_NEXT;
  mrdb->dbg->prvci = mrb->c->ci;
  return DBGST_CONTINUE;
}

