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
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  uint16_t ;
typedef  int u_int ;
struct tcphdr {int th_ack; } ;
struct tcpcb {scalar_t__ snd_cwnd; scalar_t__ snd_wnd; int t_bytes_acked; scalar_t__ t_maxseg; int snd_ssthresh; scalar_t__ snd_nxt; scalar_t__ snd_max; int snd_scale; scalar_t__ t_state; } ;
typedef  int int32_t ;
struct TYPE_2__ {int /*<<< orphan*/  num_sockets; } ;
typedef  int /*<<< orphan*/  SInt32 ;

/* Variables and functions */
 int BYTES_ACKED (struct tcphdr*,struct tcpcb*) ; 
 int /*<<< orphan*/  OSDecrementAtomic (int /*<<< orphan*/  volatile*) ; 
 int /*<<< orphan*/  OSIncrementAtomic (int /*<<< orphan*/  volatile*) ; 
 scalar_t__ TCPS_ESTABLISHED ; 
 int TCP_CC_CWND_INIT_BYTES ; 
 int TCP_MAXWIN ; 
 int lmin (int,int) ; 
 void* max (int,int) ; 
 int min (int,int) ; 
 int /*<<< orphan*/  tcp_cc_cwnd_init_or_reset (struct tcpcb*) ; 
 int tcp_cc_delay_ack (struct tcpcb*,struct tcphdr*) ; 
 TYPE_1__ tcp_cc_newreno ; 
 int /*<<< orphan*/  tcp_cc_resize_sndbuf (struct tcpcb*) ; 
 scalar_t__ tcp_do_rfc3465 ; 
 scalar_t__ tcp_do_rfc3465_lim2 ; 

int tcp_newreno_init(struct tcpcb *tp) {
#pragma unused(tp)
	OSIncrementAtomic((volatile SInt32 *)&tcp_cc_newreno.num_sockets);
	return 0;
}

int tcp_newreno_cleanup(struct tcpcb *tp) {
#pragma unused(tp)
	OSDecrementAtomic((volatile SInt32 *)&tcp_cc_newreno.num_sockets);
	return 0;
}

void
tcp_newreno_cwnd_init_or_reset(struct tcpcb *tp) {
	tcp_cc_cwnd_init_or_reset(tp);
}

void
tcp_newreno_congestion_avd(struct tcpcb *tp, struct tcphdr *th) {
	uint32_t acked = 0;
	acked = BYTES_ACKED(th, tp);
	/*
	 * Grow the congestion window, if the
	 * connection is cwnd bound.
	 */
	if (tp->snd_cwnd < tp->snd_wnd) {
		tp->t_bytes_acked += acked;
		if (tp->t_bytes_acked > tp->snd_cwnd) {
			tp->t_bytes_acked -= tp->snd_cwnd;
			tp->snd_cwnd += tp->t_maxseg;
		}
	}
}

void
tcp_newreno_ack_rcvd(struct tcpcb *tp, struct tcphdr *th) {
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
	if (tcp_do_rfc3465) {

		if (cw >= tp->snd_ssthresh) {
			tp->t_bytes_acked += acked;
			if (tp->t_bytes_acked >= cw) {
				/* Time to increase the window. */
				tp->t_bytes_acked -= cw;
			} else {
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
			uint32_t abc_lim;
			abc_lim = (tcp_do_rfc3465_lim2 &&
				tp->snd_nxt == tp->snd_max) ? incr * 2 
				: incr;

			incr = lmin(acked, abc_lim);
		}
	} else {
		/*
		 * If the window gives us less than ssthresh packets
		 * in flight, open exponentially (segsz per packet).
		 * Otherwise open linearly: segsz per window
		 * (segsz^2 / cwnd per packet).
		 */

		if (cw >= tp->snd_ssthresh)
			incr = max((incr * incr / cw), 1);
	}
	tp->snd_cwnd = min(cw+incr, TCP_MAXWIN<<tp->snd_scale);
}

void
tcp_newreno_pre_fr(struct tcpcb *tp) {

	uint32_t win;

	win = min(tp->snd_wnd, tp->snd_cwnd) / 
		2 / tp->t_maxseg;
	if ( win < 2 )
		win = 2;
	tp->snd_ssthresh = win * tp->t_maxseg; 
	tcp_cc_resize_sndbuf(tp);

}

void
tcp_newreno_post_fr(struct tcpcb *tp, struct tcphdr *th) {
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
tcp_newreno_after_timeout(struct tcpcb *tp) {
	/*
	 * Close the congestion window down to one segment
	 * (we'll open it by one segment for each ack we get).
	 * Since we probably have a window's worth of unacked
	 * data accumulated, this "slow start" keeps us from
	 * dumping all that data as back-to-back packets (which
	 * might overwhelm an intermediate gateway).
	 *
	 * There are two phases to the opening: Initially we
	 * open by one mss on each ack.  This makes the window
	 * size increase exponentially with time.  If the
	 * window is larger than the path can handle, this
	 * exponential growth results in dropped packet(s)
	 * almost immediately.  To get more time between
	 * drops but still "push" the network to take advantage
	 * of improving conditions, we switch from exponential
	 * to linear window opening at some threshhold size.
	 * For a threshhold, we use half the current window
	 * size, truncated to a multiple of the mss.
	 *
	 * (the minimum cwnd that will give us exponential
	 * growth is 2 mss.  We don't allow the threshhold
	 * to go below this.)
	 */
	if (tp->t_state >=  TCPS_ESTABLISHED) {
		u_int win = min(tp->snd_wnd, tp->snd_cwnd) / 2 / tp->t_maxseg;
		if (win < 2)
			win = 2;
		tp->snd_ssthresh = win * tp->t_maxseg;

		tp->snd_cwnd = tp->t_maxseg;
		tcp_cc_resize_sndbuf(tp);
	}
}

int
tcp_newreno_delay_ack(struct tcpcb *tp, struct tcphdr *th) {
	return (tcp_cc_delay_ack(tp, th));
}

void
tcp_newreno_switch_cc(struct tcpcb *tp, uint16_t old_index) {
#pragma unused(old_index)

	uint32_t cwnd = min(tp->snd_wnd, tp->snd_cwnd);
	if (tp->snd_cwnd >= tp->snd_ssthresh) {
		cwnd = cwnd / tp->t_maxseg;
	} else { 
		cwnd = cwnd / 2 / tp->t_maxseg;
	}
	tp->snd_cwnd = max(TCP_CC_CWND_INIT_BYTES, cwnd * tp->t_maxseg);

	/* Start counting bytes for RFC 3465 again */
	tp->t_bytes_acked = 0;

	OSIncrementAtomic((volatile SInt32 *)&tcp_cc_newreno.num_sockets);
}

