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
typedef  int /*<<< orphan*/  uint16_t ;
typedef  scalar_t__ u_int32_t ;
typedef  scalar_t__ u_int ;
struct tcphdr {scalar_t__ th_ack; int th_flags; } ;
struct tcpcb {scalar_t__ t_rttcur; scalar_t__ snd_cwnd; scalar_t__ bg_ssthresh; scalar_t__ t_maxseg; scalar_t__ snd_max; scalar_t__ snd_una; scalar_t__ snd_ssthresh; scalar_t__ t_bytes_acked; scalar_t__ snd_wnd; scalar_t__ snd_nxt; scalar_t__ t_state; int t_flags; int t_unacksegs; } ;
typedef  scalar_t__ int32_t ;
struct TYPE_2__ {int /*<<< orphan*/  num_sockets; } ;
typedef  int /*<<< orphan*/  SInt32 ;

/* Variables and functions */
 int BYTES_ACKED (struct tcphdr*,struct tcpcb*) ; 
 int /*<<< orphan*/  OSDecrementAtomic (int /*<<< orphan*/  volatile*) ; 
 int /*<<< orphan*/  OSIncrementAtomic (int /*<<< orphan*/  volatile*) ; 
 scalar_t__ TCPS_ESTABLISHED ; 
 int TF_RXWIN0SENT ; 
 int TH_PUSH ; 
 scalar_t__ allowed_increase ; 
 scalar_t__ bg_ss_fltsz ; 
 scalar_t__ get_base_rtt (struct tcpcb*) ; 
 scalar_t__ lmin (int,scalar_t__) ; 
 scalar_t__ max (scalar_t__,scalar_t__) ; 
 int min (int,scalar_t__) ; 
 scalar_t__ target_qdelay ; 
 TYPE_1__ tcp_cc_ledbat ; 
 int /*<<< orphan*/  tcp_cc_resize_sndbuf (struct tcpcb*) ; 
 scalar_t__ tcp_do_rfc3465_lim2 ; 
 scalar_t__ tether_shift ; 

__attribute__((used)) static void update_cwnd(struct tcpcb *tp, uint32_t incr) {
	uint32_t max_allowed_cwnd = 0, flight_size = 0;
	uint32_t base_rtt;

	base_rtt = get_base_rtt(tp);

	/* If we do not have a good RTT measurement yet, increment
	 * congestion window by the default value.  
	 */
	if (base_rtt == 0 || tp->t_rttcur == 0) {
		tp->snd_cwnd += incr;
		goto check_max;
	}

	if (tp->t_rttcur <= (base_rtt + target_qdelay)) {
		/*
		 * Delay decreased or remained the same, we can increase
		 * the congestion window according to RFC 3465.
		 *
		 * Move background slow-start threshold to current
		 * congestion window so that the next time (after some idle
		 * period), we can attempt to do slow-start till here if there 
		 * is no increase in rtt
		 */
		if (tp->bg_ssthresh < tp->snd_cwnd)
			tp->bg_ssthresh = tp->snd_cwnd;
		tp->snd_cwnd += incr;	

	} else {
		/* In response to an increase in rtt, reduce the congestion 
		 * window by one-eighth. This will help to yield immediately 
		 * to a competing stream.
		 */
		uint32_t redwin;

		redwin = tp->snd_cwnd >> 3;  
		tp->snd_cwnd -= redwin;
		if (tp->snd_cwnd < bg_ss_fltsz * tp->t_maxseg)
			tp->snd_cwnd = bg_ss_fltsz * tp->t_maxseg;

		/* Lower background slow-start threshold so that the connection 
		 * will go into congestion avoidance phase
		 */
		if (tp->bg_ssthresh > tp->snd_cwnd)
			tp->bg_ssthresh = tp->snd_cwnd;
	}
check_max:
	/* Calculate the outstanding flight size and restrict the
	 * congestion window to a factor of flight size.
	 */
	flight_size = tp->snd_max - tp->snd_una;

	max_allowed_cwnd = (allowed_increase * tp->t_maxseg) 
		+ (flight_size << tether_shift);
	tp->snd_cwnd = min(tp->snd_cwnd, max_allowed_cwnd);
	return;
}

int tcp_ledbat_init(struct tcpcb *tp) {
#pragma unused(tp)
	OSIncrementAtomic((volatile SInt32 *)&tcp_cc_ledbat.num_sockets);
	return 0;
}

int tcp_ledbat_cleanup(struct tcpcb *tp) {
#pragma unused(tp)
	OSDecrementAtomic((volatile SInt32 *)&tcp_cc_ledbat.num_sockets);
	return 0;
}

void
tcp_ledbat_cwnd_init(struct tcpcb *tp) {
	tp->snd_cwnd = tp->t_maxseg * bg_ss_fltsz;
	tp->bg_ssthresh = tp->snd_ssthresh;
}

void
tcp_ledbat_congestion_avd(struct tcpcb *tp, struct tcphdr *th) {
	int acked = 0;
	u_int32_t incr = 0;

	acked = BYTES_ACKED(th, tp);
	tp->t_bytes_acked += acked;
	if (tp->t_bytes_acked > tp->snd_cwnd) {
		tp->t_bytes_acked -= tp->snd_cwnd;
		incr = tp->t_maxseg;
	}

	if (tp->snd_cwnd < tp->snd_wnd && incr > 0) {
		update_cwnd(tp, incr);
	}
}

void
tcp_ledbat_ack_rcvd(struct tcpcb *tp, struct tcphdr *th) {
	/*
	 * RFC 3465 - Appropriate Byte Counting.
	 *
	 * If the window is currently less than ssthresh,
	 * open the window by the number of bytes ACKed by
	 * the last ACK, however clamp the window increase
	 * to an upper limit "L".
	 *
	 * In congestion avoidance phase, open the window by
	 * one segment each time "bytes_acked" grows to be
	 * greater than or equal to the congestion window.
	 */

	u_int cw = tp->snd_cwnd;
	u_int incr = tp->t_maxseg;
	int acked = 0;

	acked = BYTES_ACKED(th, tp);
	tp->t_bytes_acked += acked;
	if (cw >= tp->bg_ssthresh) {
		/* congestion-avoidance */
		if (tp->t_bytes_acked < cw) {
			/* No need to increase yet. */
			incr = 0;
		}
	} else {
		/*
		 * If the user explicitly enables RFC3465
		 * use 2*SMSS for the "L" param.  Otherwise
		 * use the more conservative 1*SMSS.
		 *
		 * (See RFC 3465 2.3 Choosing the Limit)
		 */
		u_int abc_lim;

		abc_lim = (tcp_do_rfc3465_lim2 &&
			tp->snd_nxt == tp->snd_max) ? incr * 2 : incr;

		incr = lmin(acked, abc_lim);
	}
	if (tp->t_bytes_acked >= cw)
		tp->t_bytes_acked -= cw;
	if (incr > 0) 
		update_cwnd(tp, incr);
}

void
tcp_ledbat_pre_fr(struct tcpcb *tp) {
	uint32_t win;

	win = min(tp->snd_wnd, tp->snd_cwnd) / 
		2 / tp->t_maxseg;
	if ( win < 2 )
		win = 2;
	tp->snd_ssthresh = win * tp->t_maxseg; 
	if (tp->bg_ssthresh > tp->snd_ssthresh)
		tp->bg_ssthresh = tp->snd_ssthresh;

	tcp_cc_resize_sndbuf(tp);
}

void
tcp_ledbat_post_fr(struct tcpcb *tp, struct tcphdr *th) {
	int32_t ss;

	ss = tp->snd_max - th->th_ack;

	/*
	 * Complete ack.  Inflate the congestion window to
	 * ssthresh and exit fast recovery.
	 *
	 * Window inflation should have left us with approx.
	 * snd_ssthresh outstanding data.  But in case we
	 * would be inclined to send a burst, better to do
	 * it via the slow start mechanism.
	 *
	 * If the flight size is zero, then make congestion 
	 * window to be worth at least 2 segments to avoid 
	 * delayed acknowledgement (draft-ietf-tcpm-rfc3782-bis-05).
	 */
	if (ss < (int32_t)tp->snd_ssthresh)
		tp->snd_cwnd = max(ss, tp->t_maxseg) + tp->t_maxseg;
	else
		tp->snd_cwnd = tp->snd_ssthresh;
	tp->t_bytes_acked = 0;
}

void
tcp_ledbat_after_idle(struct tcpcb *tp) {
	
	/* Reset the congestion window */
	tp->snd_cwnd = tp->t_maxseg * bg_ss_fltsz;
}

void
tcp_ledbat_after_timeout(struct tcpcb *tp) {
	if (tp->t_state >=  TCPS_ESTABLISHED) {
		u_int win = min(tp->snd_wnd, tp->snd_cwnd) / 2 / tp->t_maxseg;
		if (win < 2)
			win = 2;
		tp->snd_ssthresh = win * tp->t_maxseg;

		if (tp->bg_ssthresh > tp->snd_ssthresh)
			tp->bg_ssthresh = tp->snd_ssthresh;

		tp->snd_cwnd = tp->t_maxseg;
		tcp_cc_resize_sndbuf(tp);
	}
}

int
tcp_ledbat_delay_ack(struct tcpcb *tp, struct tcphdr *th) {
	if ((tp->t_flags & TF_RXWIN0SENT) == 0 &&
		(th->th_flags & TH_PUSH) == 0 && (tp->t_unacksegs == 1))
		return(1);
	return(0);
}

void
tcp_ledbat_switch_cc(struct tcpcb *tp, uint16_t old_cc_index) {
#pragma unused(old_cc_index)
	uint32_t cwnd;

	if (tp->bg_ssthresh == 0 || tp->bg_ssthresh > tp->snd_ssthresh)
		tp->bg_ssthresh = tp->snd_ssthresh;

	cwnd = min(tp->snd_wnd, tp->snd_cwnd);

	if (tp->snd_cwnd > tp->bg_ssthresh)
		cwnd = cwnd / tp->t_maxseg;
	else
		cwnd = cwnd / 2 / tp->t_maxseg;

	if (cwnd < bg_ss_fltsz)
		cwnd = bg_ss_fltsz;

	tp->snd_cwnd = cwnd * tp->t_maxseg;
	tp->t_bytes_acked = 0;

	OSIncrementAtomic((volatile SInt32 *)&tcp_cc_ledbat.num_sockets);
}

