#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_5__ ;
typedef  struct TYPE_17__   TYPE_4__ ;
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ut8 ;
struct TYPE_18__ {TYPE_3__* desc; } ;
struct TYPE_15__ {TYPE_5__* io; } ;
struct TYPE_17__ {TYPE_2__ iob; } ;
struct TYPE_16__ {TYPE_1__* plugin; } ;
struct TYPE_14__ {scalar_t__ name; } ;
typedef  TYPE_3__ RIODesc ;
typedef  TYPE_4__ RDebug ;
typedef  int /*<<< orphan*/  RBreakpointItem ;
typedef  int /*<<< orphan*/  RBreakpoint ;

/* Variables and functions */
 int /*<<< orphan*/  eprintf (char*) ; 
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/  r_cons_flush () ; 
 int /*<<< orphan*/  r_cons_pipe_close (int) ; 
 int r_cons_pipe_open (char*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  r_file_rm (char*) ; 
 char* r_file_slurp (char*,int /*<<< orphan*/ *) ; 
 char* r_file_temp (char*) ; 
 int /*<<< orphan*/  r_io_system (TYPE_5__*,char*) ; 
 int /*<<< orphan*/  strcmp (char*,scalar_t__) ; 

__attribute__((used)) static int __rap_step(RDebug *dbg) {
	r_io_system (dbg->iob.io, "ds");
	return true;
}

__attribute__((used)) static int __rap_reg_read(RDebug *dbg, int type, ut8 *buf, int size) {
	r_io_system (dbg->iob.io, "dr");
	return 0;
}

__attribute__((used)) static int __rap_reg_write(RDebug *dbg, int type, const ut8 *buf, int size) {
	return false; // XXX Error check
}

__attribute__((used)) static int __rap_continue(RDebug *dbg, int pid, int tid, int sig) {
	r_io_system (dbg->iob.io, "dc");
	return true;
}

__attribute__((used)) static int __rap_wait(RDebug *dbg, int pid) {
	/* do nothing */
	return true;
}

__attribute__((used)) static int __rap_attach(RDebug *dbg, int pid) {
// XXX TODO PID must be a socket here !!1
	RIODesc *d = dbg->iob.io->desc;
	if (d && d->plugin && d->plugin->name) {
		if (!strcmp ("rap", d->plugin->name)) {
			eprintf ("SUCCESS: rap attach with inferior rap rio worked\n");
		} else {
			eprintf ("ERROR: Underlaying IO descriptor is not a rap one..\n");
		}
	}
	return true;
}

__attribute__((used)) static int __rap_detach(RDebug *dbg, int pid) {
// XXX TODO PID must be a socket here !!1
//	close (pid);
	//XXX Maybe we should continue here?
	return true;
}

__attribute__((used)) static char *__rap_reg_profile(RDebug *dbg) {
	char *out, *tf = r_file_temp ("rap.XXXXXX");
	int fd = r_cons_pipe_open (tf, 1, 0);
	r_io_system (dbg->iob.io, "drp");
	r_cons_flush ();
	r_cons_pipe_close (fd);
	out = r_file_slurp (tf, NULL);
	r_file_rm (tf);
	free (tf);
	return out;
}

__attribute__((used)) static int __rap_breakpoint (RBreakpoint *bp, RBreakpointItem *b, bool set) {
	//r_io_system (dbg->iob.io, "db");
	return false;
}

