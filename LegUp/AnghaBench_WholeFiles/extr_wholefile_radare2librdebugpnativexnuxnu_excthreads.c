#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_49__   TYPE_9__ ;
typedef  struct TYPE_48__   TYPE_8__ ;
typedef  struct TYPE_47__   TYPE_7__ ;
typedef  struct TYPE_46__   TYPE_6__ ;
typedef  struct TYPE_45__   TYPE_5__ ;
typedef  struct TYPE_44__   TYPE_4__ ;
typedef  struct TYPE_43__   TYPE_3__ ;
typedef  struct TYPE_42__   TYPE_34__ ;
typedef  struct TYPE_41__   TYPE_30__ ;
typedef  struct TYPE_40__   TYPE_2__ ;
typedef  struct TYPE_39__   TYPE_1__ ;
typedef  struct TYPE_38__   TYPE_13__ ;
typedef  struct TYPE_37__   TYPE_12__ ;
typedef  struct TYPE_36__   TYPE_11__ ;
typedef  struct TYPE_35__   TYPE_10__ ;

/* Type definitions */
struct TYPE_48__ {int /*<<< orphan*/  gpr; } ;
typedef  TYPE_8__ xnu_thread_t ;
typedef  scalar_t__ task_t ;
struct TYPE_35__ {int msgh_bits; scalar_t__ msgh_remote_port; int msgh_size; scalar_t__ msgh_local_port; int msgh_id; } ;
struct TYPE_42__ {scalar_t__ mig_encoding; scalar_t__ int_rep; scalar_t__ char_rep; scalar_t__ float_rep; } ;
struct TYPE_49__ {int RetCode; TYPE_10__ Head; TYPE_34__ NDR; } ;
typedef  TYPE_9__ mig_reply_error_t ;
typedef  void* mach_port_t ;
typedef  int /*<<< orphan*/  mach_msg_type_number_t ;
typedef  int mach_msg_size_t ;
typedef  int /*<<< orphan*/  mach_msg_port_descriptor_t ;
typedef  TYPE_10__ mach_msg_header_t ;
typedef  int /*<<< orphan*/  mach_msg_body_t ;
typedef  int /*<<< orphan*/  mach_exception_data_t ;
typedef  int kern_return_t ;
typedef  int /*<<< orphan*/  exception_type_t ;
struct TYPE_43__ {scalar_t__ name; } ;
struct TYPE_40__ {scalar_t__ name; } ;
struct TYPE_39__ {scalar_t__ mig_vers; scalar_t__ if_vers; scalar_t__ mig_encoding; scalar_t__ int_rep; scalar_t__ char_rep; scalar_t__ float_rep; } ;
struct TYPE_36__ {int exception; TYPE_10__ hdr; TYPE_3__ thread; TYPE_2__ task; TYPE_1__ NDR; } ;
typedef  TYPE_11__ exc_msg ;
struct TYPE_46__ {int __rflags; } ;
struct TYPE_44__ {int __eflags; } ;
struct TYPE_47__ {TYPE_6__ ts64; TYPE_4__ ts32; } ;
struct TYPE_45__ {scalar_t__ flavor; } ;
struct TYPE_41__ {int count; scalar_t__ exception_port; int /*<<< orphan*/ * flavors; int /*<<< orphan*/ * behaviors; int /*<<< orphan*/ * ports; int /*<<< orphan*/ * masks; } ;
struct TYPE_38__ {int pid; int /*<<< orphan*/  stopaddr; } ;
struct TYPE_37__ {TYPE_7__ uts; TYPE_5__ tsh; } ;
typedef  TYPE_12__ R_REG_T ;
typedef  TYPE_13__ RDebug ;
typedef  int /*<<< orphan*/  NDR_record_t ;

/* Variables and functions */
 int EXCEPTION_DEFAULT ; 
#define  EXC_ARITHMETIC 133 
#define  EXC_BAD_ACCESS 132 
#define  EXC_BAD_INSTRUCTION 131 
#define  EXC_BREAKPOINT 130 
#define  EXC_EMULATION 129 
 int /*<<< orphan*/  EXC_MASK_ALL ; 
#define  EXC_SOFTWARE 128 
 int KERN_FAILURE ; 
 int KERN_SUCCESS ; 
 int MACH_EXCEPTION_CODES ; 
 int MACH_MSGH_BITS (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int MACH_MSGH_BITS_COMPLEX ; 
 int /*<<< orphan*/  MACH_MSGH_BITS_REMOTE (int) ; 
 int MACH_MSG_SUCCESS ; 
 int /*<<< orphan*/  MACH_MSG_TIMEOUT_NONE ; 
 int /*<<< orphan*/  MACH_MSG_TYPE_MAKE_SEND ; 
 int /*<<< orphan*/  MACH_MSG_TYPE_MAKE_SEND_ONCE ; 
 int /*<<< orphan*/  MACH_NOTIFY_DEAD_NAME ; 
 void* MACH_PORT_NULL ; 
 int /*<<< orphan*/  MACH_PORT_RIGHT_RECEIVE ; 
 int /*<<< orphan*/  MACH_PORT_VALID (void*) ; 
 int MACH_RCV_INTERRUPT ; 
 int MACH_RCV_INTERRUPTED ; 
 int MACH_RCV_MSG ; 
 int MACH_SEND_INTERRUPT ; 
 int MACH_SEND_MSG ; 
 scalar_t__ NDR_PROTOCOL_2_0 ; 
 TYPE_34__ NDR_record ; 
 int /*<<< orphan*/  PT_ATTACHEXC ; 
 int /*<<< orphan*/  RETURN_ON_MACH_ERROR (char*,int) ; 
 int R_DEBUG_REASON_BREAKPOINT ; 
 int R_DEBUG_REASON_DEAD ; 
 int R_DEBUG_REASON_ILLEGAL ; 
 int R_DEBUG_REASON_MACH_RCV_INTERRUPTED ; 
 int R_DEBUG_REASON_SEGFAULT ; 
 int R_DEBUG_REASON_UNKNOWN ; 
 int /*<<< orphan*/  THREAD_STATE_NONE ; 
 int /*<<< orphan*/  eprintf (char*) ; 
 TYPE_30__ ex ; 
 int mach_msg (TYPE_10__*,int,int,int,void*,int /*<<< orphan*/ ,void*) ; 
 int mach_port_allocate (void*,int /*<<< orphan*/ ,void**) ; 
 int mach_port_deallocate (void*,scalar_t__) ; 
 int mach_port_insert_right (void*,void*,void*,int /*<<< orphan*/ ) ; 
 int mach_port_request_notification (void*,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*,int /*<<< orphan*/ ,void**) ; 
 void* mach_task_self () ; 
 scalar_t__ pid_to_task (int) ; 
 int /*<<< orphan*/  r_debug_ptrace (TYPE_13__*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  r_debug_reg_get (TYPE_13__*,char*) ; 
 int task_set_exception_ports (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int task_suspend (scalar_t__) ; 
 int task_swap_exception_ports (scalar_t__,int /*<<< orphan*/ ,void*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ x86_THREAD_STATE32 ; 
 scalar_t__ x86_THREAD_STATE64 ; 
 int xnu_thread_get_gpr (TYPE_13__*,TYPE_8__*) ; 
 int /*<<< orphan*/  xnu_thread_set_gpr (TYPE_13__*,TYPE_8__*) ; 

__attribute__((used)) static bool modify_trace_bit(RDebug *dbg, xnu_thread_t *th, int enable) {
	R_REG_T *state;
	int ret;
	ret = xnu_thread_get_gpr (dbg, th);
	if (!ret) {
		eprintf ("error to get gpr registers in trace bit intel\n");
		return false;
	}
	state = (R_REG_T *)&th->gpr;
	if (state->tsh.flavor == x86_THREAD_STATE32) {
		state->uts.ts32.__eflags = (state->uts.ts32.__eflags & \
					~0x100UL) | (enable ? 0x100UL : 0);
	} else if (state->tsh.flavor == x86_THREAD_STATE64) {
		state->uts.ts64.__rflags = (state->uts.ts64.__rflags & \
					~0x100UL) | (enable ? 0x100UL : 0);
	} else {
		eprintf ("Invalid bit size\n");
		return false;
	}
	if (!xnu_thread_set_gpr (dbg, th)) {
		eprintf ("error xnu_thread_set_gpr in modify_trace_bit intel\n");
		return false;
	}
	return true;
}

__attribute__((used)) static bool xnu_restore_exception_ports (int pid) {
	kern_return_t kr;
	int i;
	task_t task = pid_to_task (pid);
	if (!task)
		return false;
	for (i = 0; i < ex.count; i++) {
		kr = task_set_exception_ports (task, ex.masks[i], ex.ports[i],
					       ex.behaviors[i], ex.flavors[i]);
		if (kr != KERN_SUCCESS) {
			eprintf ("fail to restore exception ports\n");
			return false;
		}
	}
	kr = mach_port_deallocate (mach_task_self (), ex.exception_port);
	if (kr != KERN_SUCCESS) {
		eprintf ("failed to deallocate exception port\n");
		return false;
	}
	return true;
}

__attribute__((used)) static void encode_reply(mig_reply_error_t *reply, mach_msg_header_t *hdr, int code) {
	mach_msg_header_t *rh = &reply->Head;
	rh->msgh_bits = MACH_MSGH_BITS (MACH_MSGH_BITS_REMOTE(hdr->msgh_bits), 0);
	rh->msgh_remote_port = hdr->msgh_remote_port;
	rh->msgh_size = (mach_msg_size_t) sizeof (mig_reply_error_t);
	rh->msgh_local_port = MACH_PORT_NULL;
	rh->msgh_id = hdr->msgh_id + 100;
	reply->NDR = NDR_record;
	reply->RetCode = code;
}

__attribute__((used)) static bool validate_mach_message (RDebug *dbg, exc_msg *msg) {
	kern_return_t kr;
#if __POWERPC__
	return false;
#else
	/*check if the message is for us*/
	if (msg->hdr.msgh_local_port != ex.exception_port) {
		return false;
	}
	/*gdb from apple check this so why not us*/
	if (!(msg->hdr.msgh_bits & MACH_MSGH_BITS_COMPLEX)) {
		return false;
	}
	/*mach exception we are interested*/
	//XXX for i386 this id seems to be different
	if (msg->hdr.msgh_id > 2405 || msg->hdr.msgh_id < 2401) {
		return false;
	}
	/* check descriptors.  */
	if (msg->hdr.msgh_size <
	    sizeof (mach_msg_header_t) + sizeof (mach_msg_body_t) +
		    2 * sizeof (mach_msg_port_descriptor_t) +
		    sizeof (NDR_record_t) + sizeof (exception_type_t) +
		    sizeof (mach_msg_type_number_t) +
		    sizeof (mach_exception_data_t))
		return false;
	/* check data representation.  */
	if (msg->NDR.mig_vers != NDR_PROTOCOL_2_0 ||
	    msg->NDR.if_vers != NDR_PROTOCOL_2_0 ||
	    msg->NDR.mig_encoding != NDR_record.mig_encoding ||
	    msg->NDR.int_rep != NDR_record.int_rep ||
	    msg->NDR.char_rep != NDR_record.char_rep ||
	    msg->NDR.float_rep != NDR_record.float_rep) {
		return false;
	}
	if (pid_to_task (dbg->pid) != msg->task.name) {
		//we receive a exception from an unknown process this could
		//happen if the child fork, as the created process will inherit
		//its exception port
		/*we got new rights to the task, get rid of it.*/
		kr = mach_port_deallocate (mach_task_self (), msg->task.name);
		if (kr != KERN_SUCCESS) {
			eprintf ("validate_mach_message: failed to deallocate task port\n");
		}
		kr = mach_port_deallocate (mach_task_self (), msg->thread.name);
		if (kr != KERN_SUCCESS) {
			eprintf ("validate_mach_message2: failed to deallocated task port\n");
		}
		return false;
	}
	return true;
#endif
}

__attribute__((used)) static bool handle_dead_notify (RDebug *dbg, exc_msg *msg) {
	if (msg->hdr.msgh_id == 0x48) {
		dbg->pid = -1;
		return true;
	}
	return false;
}

__attribute__((used)) static int handle_exception_message (RDebug *dbg, exc_msg *msg, int *ret_code) {
	int ret = R_DEBUG_REASON_UNKNOWN;
	kern_return_t kr;
	*ret_code = KERN_SUCCESS;
	switch (msg->exception) {
	case EXC_BAD_ACCESS:
		ret = R_DEBUG_REASON_SEGFAULT;
		*ret_code = KERN_FAILURE;
		kr = task_suspend (msg->task.name);
		if (kr != KERN_SUCCESS) {
			eprintf ("failed to suspend task bad access\n");
		}
		eprintf ("EXC_BAD_ACCESS\n");
		break;
	case EXC_BAD_INSTRUCTION:
		ret = R_DEBUG_REASON_ILLEGAL;
		*ret_code = KERN_FAILURE;
		kr = task_suspend (msg->task.name);
		if (kr != KERN_SUCCESS) {
			eprintf ("failed to suspend task bad instruction\n");
		}
		eprintf ("EXC_BAD_INSTRUCTION\n");
		break;
	case EXC_ARITHMETIC:
		eprintf ("EXC_ARITHMETIC\n");
		break;
	case EXC_EMULATION:
		eprintf ("EXC_EMULATION\n");
		break;
	case EXC_SOFTWARE:
		eprintf ("EXC_SOFTWARE\n");
		break;
	case EXC_BREAKPOINT:
		kr = task_suspend (msg->task.name);
		if (kr != KERN_SUCCESS) {
			eprintf ("failed to suspend task breakpoint\n");
		}
		ret = R_DEBUG_REASON_BREAKPOINT;
		break;
	default:
		eprintf ("UNKNOWN\n");
		break;
	}
	kr = mach_port_deallocate (mach_task_self (), msg->task.name);
	if (kr != KERN_SUCCESS) {
		eprintf ("failed to deallocate task port\n");
	}
	kr = mach_port_deallocate (mach_task_self (), msg->thread.name);
	if (kr != KERN_SUCCESS) {
		eprintf ("failed to deallocated task port\n");
	}
	return ret;
}

__attribute__((used)) static int __xnu_wait (RDebug *dbg, int pid) {
	// here comes the important thing
	kern_return_t kr;
	int ret_code, reason = R_DEBUG_REASON_UNKNOWN;
	mig_reply_error_t reply;
	bool ret;
	exc_msg msg;
	if (!dbg) {
		return reason;
	}
	msg.hdr.msgh_local_port = ex.exception_port;
	msg.hdr.msgh_size = sizeof (exc_msg);
	for (;;) {
		kr = mach_msg (
			&msg.hdr,
			MACH_RCV_MSG | MACH_RCV_INTERRUPT, 0,
			sizeof (exc_msg), ex.exception_port,
			MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
		if (kr == MACH_RCV_INTERRUPTED) {
			reason = R_DEBUG_REASON_MACH_RCV_INTERRUPTED;
			break;
		} else if (kr != MACH_MSG_SUCCESS) {
			eprintf ("message didn't succeded\n");
			break;
		}
		ret = validate_mach_message (dbg, &msg);
		if (!ret) {
			ret = handle_dead_notify (dbg, &msg);
			if (ret) {
				reason = R_DEBUG_REASON_DEAD;
				break;
			}
		}
		if (!ret) {
			encode_reply (&reply, &msg.hdr, KERN_FAILURE);
			kr = mach_msg (&reply.Head, MACH_SEND_MSG | MACH_SEND_INTERRUPT,
					reply.Head.msgh_size, 0,
					MACH_PORT_NULL, MACH_MSG_TIMEOUT_NONE,
					MACH_PORT_NULL);
			if (reply.Head.msgh_remote_port != 0 && kr != MACH_MSG_SUCCESS) {
				kr = mach_port_deallocate(mach_task_self (), reply.Head.msgh_remote_port);
				if (kr != KERN_SUCCESS) {
					eprintf ("failed to deallocate reply port\n");
				}
			}
			continue;
		}

		reason = handle_exception_message (dbg, &msg, &ret_code);
		encode_reply (&reply, &msg.hdr, ret_code);
		kr = mach_msg (&reply.Head, MACH_SEND_MSG | MACH_SEND_INTERRUPT,
				reply.Head.msgh_size, 0,
				MACH_PORT_NULL, 0,
				MACH_PORT_NULL);
		if (reply.Head.msgh_remote_port != 0 && kr != MACH_MSG_SUCCESS) {
			kr = mach_port_deallocate(mach_task_self (), reply.Head.msgh_remote_port);
			if (kr != KERN_SUCCESS)
				eprintf ("failed to deallocate reply port\n");
		}
		break; // to avoid infinite loops
	}
	dbg->stopaddr = r_debug_reg_get (dbg, "PC");
	return reason;
}

bool xnu_create_exception_thread(RDebug *dbg) {
#if __POWERPC__
	return false;
#else
	kern_return_t kr;
	mach_port_t exception_port = MACH_PORT_NULL;
	mach_port_t req_port;
        // Got the mach port for the current process
	mach_port_t task_self = mach_task_self ();
	task_t task = pid_to_task (dbg->pid);
	if (!task) {
		eprintf ("error to get task for the debuggee process"
			" xnu_start_exception_thread\n");
		return false;
	}
	r_debug_ptrace (dbg, PT_ATTACHEXC, dbg->pid, 0, 0);
	if (!MACH_PORT_VALID (task_self)) {
		eprintf ("error to get the task for the current process"
			" xnu_start_exception_thread\n");
		return false;
	}
        // Allocate an exception port that we will use to track our child process
        kr = mach_port_allocate (task_self, MACH_PORT_RIGHT_RECEIVE,
				&exception_port);
	RETURN_ON_MACH_ERROR ("error to allocate mach_port exception\n", false);
        // Add the ability to send messages on the new exception port
	kr = mach_port_insert_right (task_self, exception_port, exception_port,
				     MACH_MSG_TYPE_MAKE_SEND);
	RETURN_ON_MACH_ERROR ("error to allocate insert right\n", false);
	// Atomically swap out (and save) the child process's exception ports
	// for the one we just created. We'll want to receive all exceptions.
	ex.count = (sizeof (ex.ports) / sizeof (*ex.ports));
	kr = task_swap_exception_ports (task, EXC_MASK_ALL, exception_port,
		EXCEPTION_DEFAULT | MACH_EXCEPTION_CODES, THREAD_STATE_NONE,
		ex.masks, &ex.count, ex.ports, ex.behaviors, ex.flavors);
	RETURN_ON_MACH_ERROR ("failed to swap exception ports\n", false);
	//get notification when process die
	kr = mach_port_request_notification (task_self, task, MACH_NOTIFY_DEAD_NAME,
		 0, exception_port, MACH_MSG_TYPE_MAKE_SEND_ONCE, &req_port);
	if (kr != KERN_SUCCESS) {
		eprintf ("Termination notification request failed\n");
	}
	ex.exception_port = exception_port;
	return true;
#endif
}

