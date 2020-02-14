#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  enum target_signal { ____Placeholder_target_signal } target_signal ;
struct TYPE_3__ {int nto_sig; int gdb_sig; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 int NTO_SIGRTMAX ; 
 int NTO_SIGRTMIN ; 
#define  TARGET_SIGNAL_0 128 
 int TARGET_SIGNAL_REALTIME_41 ; 
 int TARGET_SIGNAL_UNKNOWN ; 
 TYPE_1__* sig_map ; 

enum target_signal
target_signal_from_host (int hostsig) {
	/* A switch statement would make sense but would require special kludges
     to deal with the cases where more than one signal has the same number.  */

	if (hostsig == 0)
		return TARGET_SIGNAL_0;

#if defined(SIGHUP)
	if (hostsig == SIGHUP)
		return TARGET_SIGNAL_HUP;
#endif
#if defined(SIGINT)
	if (hostsig == SIGINT)
		return TARGET_SIGNAL_INT;
#endif
#if defined(SIGQUIT)
	if (hostsig == SIGQUIT)
		return TARGET_SIGNAL_QUIT;
#endif
#if defined(SIGILL)
	if (hostsig == SIGILL)
		return TARGET_SIGNAL_ILL;
#endif
#if defined(SIGTRAP)
	if (hostsig == SIGTRAP)
		return TARGET_SIGNAL_TRAP;
#endif
#if defined(SIGABRT)
	if (hostsig == SIGABRT)
		return TARGET_SIGNAL_ABRT;
#endif
#if defined(SIGEMT)
	if (hostsig == SIGEMT)
		return TARGET_SIGNAL_EMT;
#endif
#if defined(SIGFPE)
	if (hostsig == SIGFPE)
		return TARGET_SIGNAL_FPE;
#endif
#if defined(SIGKILL)
	if (hostsig == SIGKILL)
		return TARGET_SIGNAL_KILL;
#endif
#if defined(SIGBUS)
	if (hostsig == SIGBUS)
		return TARGET_SIGNAL_BUS;
#endif
#if defined(SIGSEGV)
	if (hostsig == SIGSEGV)
		return TARGET_SIGNAL_SEGV;
#endif
#if defined(SIGSYS)
	if (hostsig == SIGSYS)
		return TARGET_SIGNAL_SYS;
#endif
#if defined(SIGPIPE)
	if (hostsig == SIGPIPE)
		return TARGET_SIGNAL_PIPE;
#endif
#if defined(SIGALRM)
	if (hostsig == SIGALRM)
		return TARGET_SIGNAL_ALRM;
#endif
#if defined(SIGTERM)
	if (hostsig == SIGTERM)
		return TARGET_SIGNAL_TERM;
#endif
#if defined(SIGUSR1)
	if (hostsig == SIGUSR1)
		return TARGET_SIGNAL_USR1;
#endif
#if defined(SIGUSR2)
	if (hostsig == SIGUSR2)
		return TARGET_SIGNAL_USR2;
#endif
#if defined(SIGCLD)
	if (hostsig == SIGCLD)
		return TARGET_SIGNAL_CHLD;
#endif
#if defined(SIGCHLD)
	if (hostsig == SIGCHLD)
		return TARGET_SIGNAL_CHLD;
#endif
#if defined(SIGPWR)
	if (hostsig == SIGPWR)
		return TARGET_SIGNAL_PWR;
#endif
#if defined(SIGWINCH)
	if (hostsig == SIGWINCH)
		return TARGET_SIGNAL_WINCH;
#endif
#if defined(SIGURG)
	if (hostsig == SIGURG)
		return TARGET_SIGNAL_URG;
#endif
#if defined(SIGIO)
	if (hostsig == SIGIO)
		return TARGET_SIGNAL_IO;
#endif
#if defined(SIGPOLL)
	if (hostsig == SIGPOLL)
		return TARGET_SIGNAL_POLL;
#endif
#if defined(SIGSTOP)
	if (hostsig == SIGSTOP)
		return TARGET_SIGNAL_STOP;
#endif
#if defined(SIGTSTP)
	if (hostsig == SIGTSTP)
		return TARGET_SIGNAL_TSTP;
#endif
#if defined(SIGCONT)
	if (hostsig == SIGCONT)
		return TARGET_SIGNAL_CONT;
#endif
#if defined(SIGTTIN)
	if (hostsig == SIGTTIN)
		return TARGET_SIGNAL_TTIN;
#endif
#if defined(SIGTTOU)
	if (hostsig == SIGTTOU)
		return TARGET_SIGNAL_TTOU;
#endif
#if defined(SIGVTALRM)
	if (hostsig == SIGVTALRM)
		return TARGET_SIGNAL_VTALRM;
#endif
#if defined(SIGPROF)
	if (hostsig == SIGPROF)
		return TARGET_SIGNAL_PROF;
#endif
#if defined(SIGXCPU)
	if (hostsig == SIGXCPU)
		return TARGET_SIGNAL_XCPU;
#endif
#if defined(SIGXFSZ)
	if (hostsig == SIGXFSZ)
		return TARGET_SIGNAL_XFSZ;
#endif
#if defined(SIGWIND)
	if (hostsig == SIGWIND)
		return TARGET_SIGNAL_WIND;
#endif
#if defined(SIGPHONE)
	if (hostsig == SIGPHONE)
		return TARGET_SIGNAL_PHONE;
#endif
#if defined(SIGLOST)
	if (hostsig == SIGLOST)
		return TARGET_SIGNAL_LOST;
#endif
#if defined(SIGWAITING)
	if (hostsig == SIGWAITING)
		return TARGET_SIGNAL_WAITING;
#endif
#if defined(SIGCANCEL)
	if (hostsig == SIGCANCEL)
		return TARGET_SIGNAL_CANCEL;
#endif
#if defined(SIGLWP)
	if (hostsig == SIGLWP)
		return TARGET_SIGNAL_LWP;
#endif
#if defined(SIGDANGER)
	if (hostsig == SIGDANGER)
		return TARGET_SIGNAL_DANGER;
#endif
#if defined(SIGGRANT)
	if (hostsig == SIGGRANT)
		return TARGET_SIGNAL_GRANT;
#endif
#if defined(SIGRETRACT)
	if (hostsig == SIGRETRACT)
		return TARGET_SIGNAL_RETRACT;
#endif
#if defined(SIGMSG)
	if (hostsig == SIGMSG)
		return TARGET_SIGNAL_MSG;
#endif
#if defined(SIGSOUND)
	if (hostsig == SIGSOUND)
		return TARGET_SIGNAL_SOUND;
#endif
#if defined(SIGSAK)
	if (hostsig == SIGSAK)
		return TARGET_SIGNAL_SAK;
#endif
#if defined(SIGPRIO)
	if (hostsig == SIGPRIO)
		return TARGET_SIGNAL_PRIO;
#endif

/* Mach exceptions.  Assumes that the values for EXC_ are positive! */
#if defined(EXC_BAD_ACCESS) && defined(_NSIG)
	if (hostsig == _NSIG + EXC_BAD_ACCESS)
		return TARGET_EXC_BAD_ACCESS;
#endif
#if defined(EXC_BAD_INSTRUCTION) && defined(_NSIG)
	if (hostsig == _NSIG + EXC_BAD_INSTRUCTION)
		return TARGET_EXC_BAD_INSTRUCTION;
#endif
#if defined(EXC_ARITHMETIC) && defined(_NSIG)
	if (hostsig == _NSIG + EXC_ARITHMETIC)
		return TARGET_EXC_ARITHMETIC;
#endif
#if defined(EXC_EMULATION) && defined(_NSIG)
	if (hostsig == _NSIG + EXC_EMULATION)
		return TARGET_EXC_EMULATION;
#endif
#if defined(EXC_SOFTWARE) && defined(_NSIG)
	if (hostsig == _NSIG + EXC_SOFTWARE)
		return TARGET_EXC_SOFTWARE;
#endif
#if defined(EXC_BREAKPOINT) && defined(_NSIG)
	if (hostsig == _NSIG + EXC_BREAKPOINT)
		return TARGET_EXC_BREAKPOINT;
#endif

#if defined(SIGINFO)
	if (hostsig == SIGINFO)
		return TARGET_SIGNAL_INFO;
#endif

#if defined(REALTIME_LO)
	if (hostsig >= REALTIME_LO && hostsig < REALTIME_HI) {
		/* This block of TARGET_SIGNAL_REALTIME value is in order.  */
		if (33 <= hostsig && hostsig <= 63)
			return (enum target_signal)(hostsig - 33 + (int)TARGET_SIGNAL_REALTIME_33);
		else if (hostsig == 32)
			return TARGET_SIGNAL_REALTIME_32;
		else if (64 <= hostsig && hostsig <= 127)
			return (enum target_signal)(hostsig - 64 + (int)TARGET_SIGNAL_REALTIME_64);
		else
			error ("GDB bug: target.c (target_signal_from_host): unrecognized real-time signal");
	}
#endif

	return TARGET_SIGNAL_UNKNOWN;
}

__attribute__((used)) static int
do_target_signal_to_host (enum target_signal oursig,
			  int *oursig_ok) {
	int retsig;
	/* Silence the 'not used' warning, for targets that
     do not support signals.  */
	(void)retsig;

	*oursig_ok = 1;
	switch (oursig) {
	case TARGET_SIGNAL_0:
		return 0;

#if defined(SIGHUP)
	case TARGET_SIGNAL_HUP:
		return SIGHUP;
#endif
#if defined(SIGINT)
	case TARGET_SIGNAL_INT:
		return SIGINT;
#endif
#if defined(SIGQUIT)
	case TARGET_SIGNAL_QUIT:
		return SIGQUIT;
#endif
#if defined(SIGILL)
	case TARGET_SIGNAL_ILL:
		return SIGILL;
#endif
#if defined(SIGTRAP)
	case TARGET_SIGNAL_TRAP:
		return SIGTRAP;
#endif
#if defined(SIGABRT)
	case TARGET_SIGNAL_ABRT:
		return SIGABRT;
#endif
#if defined(SIGEMT)
	case TARGET_SIGNAL_EMT:
		return SIGEMT;
#endif
#if defined(SIGFPE)
	case TARGET_SIGNAL_FPE:
		return SIGFPE;
#endif
#if defined(SIGKILL)
	case TARGET_SIGNAL_KILL:
		return SIGKILL;
#endif
#if defined(SIGBUS)
	case TARGET_SIGNAL_BUS:
		return SIGBUS;
#endif
#if defined(SIGSEGV)
	case TARGET_SIGNAL_SEGV:
		return SIGSEGV;
#endif
#if defined(SIGSYS)
	case TARGET_SIGNAL_SYS:
		return SIGSYS;
#endif
#if defined(SIGPIPE)
	case TARGET_SIGNAL_PIPE:
		return SIGPIPE;
#endif
#if defined(SIGALRM)
	case TARGET_SIGNAL_ALRM:
		return SIGALRM;
#endif
#if defined(SIGTERM)
	case TARGET_SIGNAL_TERM:
		return SIGTERM;
#endif
#if defined(SIGUSR1)
	case TARGET_SIGNAL_USR1:
		return SIGUSR1;
#endif
#if defined(SIGUSR2)
	case TARGET_SIGNAL_USR2:
		return SIGUSR2;
#endif
#if defined(SIGCHLD) || defined(SIGCLD)
	case TARGET_SIGNAL_CHLD:
#if defined(SIGCHLD)
		return SIGCHLD;
#else
		return SIGCLD;
#endif
#endif /* SIGCLD or SIGCHLD */
#if defined(SIGPWR)
	case TARGET_SIGNAL_PWR:
		return SIGPWR;
#endif
#if defined(SIGWINCH)
	case TARGET_SIGNAL_WINCH:
		return SIGWINCH;
#endif
#if defined(SIGURG)
	case TARGET_SIGNAL_URG:
		return SIGURG;
#endif
#if defined(SIGIO)
	case TARGET_SIGNAL_IO:
		return SIGIO;
#endif
#if defined(SIGPOLL)
	case TARGET_SIGNAL_POLL:
		return SIGPOLL;
#endif
#if defined(SIGSTOP)
	case TARGET_SIGNAL_STOP:
		return SIGSTOP;
#endif
#if defined(SIGTSTP)
	case TARGET_SIGNAL_TSTP:
		return SIGTSTP;
#endif
#if defined(SIGCONT)
	case TARGET_SIGNAL_CONT:
		return SIGCONT;
#endif
#if defined(SIGTTIN)
	case TARGET_SIGNAL_TTIN:
		return SIGTTIN;
#endif
#if defined(SIGTTOU)
	case TARGET_SIGNAL_TTOU:
		return SIGTTOU;
#endif
#if defined(SIGVTALRM)
	case TARGET_SIGNAL_VTALRM:
		return SIGVTALRM;
#endif
#if defined(SIGPROF)
	case TARGET_SIGNAL_PROF:
		return SIGPROF;
#endif
#if defined(SIGXCPU)
	case TARGET_SIGNAL_XCPU:
		return SIGXCPU;
#endif
#if defined(SIGXFSZ)
	case TARGET_SIGNAL_XFSZ:
		return SIGXFSZ;
#endif
#if defined(SIGWIND)
	case TARGET_SIGNAL_WIND:
		return SIGWIND;
#endif
#if defined(SIGPHONE)
	case TARGET_SIGNAL_PHONE:
		return SIGPHONE;
#endif
#if defined(SIGLOST)
	case TARGET_SIGNAL_LOST:
		return SIGLOST;
#endif
#if defined(SIGWAITING)
	case TARGET_SIGNAL_WAITING:
		return SIGWAITING;
#endif
#if defined(SIGCANCEL)
	case TARGET_SIGNAL_CANCEL:
		return SIGCANCEL;
#endif
#if defined(SIGLWP)
	case TARGET_SIGNAL_LWP:
		return SIGLWP;
#endif
#if defined(SIGDANGER)
	case TARGET_SIGNAL_DANGER:
		return SIGDANGER;
#endif
#if defined(SIGGRANT)
	case TARGET_SIGNAL_GRANT:
		return SIGGRANT;
#endif
#if defined(SIGRETRACT)
	case TARGET_SIGNAL_RETRACT:
		return SIGRETRACT;
#endif
#if defined(SIGMSG)
	case TARGET_SIGNAL_MSG:
		return SIGMSG;
#endif
#if defined(SIGSOUND)
	case TARGET_SIGNAL_SOUND:
		return SIGSOUND;
#endif
#if defined(SIGSAK)
	case TARGET_SIGNAL_SAK:
		return SIGSAK;
#endif
#if defined(SIGPRIO)
	case TARGET_SIGNAL_PRIO:
		return SIGPRIO;
#endif

/* Mach exceptions.  Assumes that the values for EXC_ are positive! */
#if defined(EXC_BAD_ACCESS) && defined(_NSIG)
	case TARGET_EXC_BAD_ACCESS:
		return _NSIG + EXC_BAD_ACCESS;
#endif
#if defined(EXC_BAD_INSTRUCTION) && defined(_NSIG)
	case TARGET_EXC_BAD_INSTRUCTION:
		return _NSIG + EXC_BAD_INSTRUCTION;
#endif
#if defined(EXC_ARITHMETIC) && defined(_NSIG)
	case TARGET_EXC_ARITHMETIC:
		return _NSIG + EXC_ARITHMETIC;
#endif
#if defined(EXC_EMULATION) && defined(_NSIG)
	case TARGET_EXC_EMULATION:
		return _NSIG + EXC_EMULATION;
#endif
#if defined(EXC_SOFTWARE) && defined(_NSIG)
	case TARGET_EXC_SOFTWARE:
		return _NSIG + EXC_SOFTWARE;
#endif
#if defined(EXC_BREAKPOINT) && defined(_NSIG)
	case TARGET_EXC_BREAKPOINT:
		return _NSIG + EXC_BREAKPOINT;
#endif

#if defined(SIGINFO)
	case TARGET_SIGNAL_INFO:
		return SIGINFO;
#endif

	default:
#if defined(REALTIME_LO)
		retsig = 0;

		if (oursig >= TARGET_SIGNAL_REALTIME_33 && oursig <= TARGET_SIGNAL_REALTIME_63) {
			/* This block of signals is continuous, and
             TARGET_SIGNAL_REALTIME_33 is 33 by definition.  */
			retsig = (int)oursig - (int)TARGET_SIGNAL_REALTIME_33 + 33;
		} else if (oursig == TARGET_SIGNAL_REALTIME_32) {
			/* TARGET_SIGNAL_REALTIME_32 isn't contiguous with
             TARGET_SIGNAL_REALTIME_33.  It is 32 by definition.  */
			retsig = 32;
		} else if (oursig >= TARGET_SIGNAL_REALTIME_64 && oursig <= TARGET_SIGNAL_REALTIME_127) {
			/* This block of signals is continuous, and
             TARGET_SIGNAL_REALTIME_64 is 64 by definition.  */
			retsig = (int)oursig - (int)TARGET_SIGNAL_REALTIME_64 + 64;
		}

		if (retsig >= REALTIME_LO && retsig < REALTIME_HI)
			return retsig;
#endif

		*oursig_ok = 0;
		return 0;
	}
}

int
target_signal_to_host (enum target_signal oursig) {
	int oursig_ok;
	int targ_signo = do_target_signal_to_host (oursig, &oursig_ok);
	if (!oursig_ok)
		return 0;
	else
		return targ_signo;
}

enum target_signal
target_signal_from_nto (int sig) {
	int i;
	if (sig == 0)
		return 0;

	for (i = 0; i != ARRAY_SIZE (sig_map); i++) {
		if (sig_map[i].nto_sig == sig)
			return sig_map[i].gdb_sig;
	}

	if (sig >= NTO_SIGRTMIN && sig <= NTO_SIGRTMAX)
		return TARGET_SIGNAL_REALTIME_41 + sig - NTO_SIGRTMIN;
	return target_signal_from_host (sig);
}

int
host_signal_from_nto (int sig) {
	return target_signal_to_host (target_signal_to_host (sig));
}

