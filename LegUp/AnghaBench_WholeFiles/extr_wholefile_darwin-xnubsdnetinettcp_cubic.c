#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint32_t ;
typedef  int /*<<< orphan*/  uint16_t ;
typedef  scalar_t__ u_int64_t ;
typedef  scalar_t__ u_int32_t ;
struct tcphdr {scalar_t__ th_ack; } ;
struct tcpcb {scalar_t__ t_pipeack; scalar_t__ t_bytes_acked; int snd_ssthresh; scalar_t__ snd_cwnd; int snd_wnd; scalar_t__ t_maxseg; int snd_scale; scalar_t__ snd_nxt; scalar_t__ snd_max; int t_flagsext; scalar_t__ t_lossflightsize; scalar_t__ snd_una; scalar_t__ t_state; TYPE_3__* t_ccstate; TYPE_2__* t_inpcb; } ;
typedef  int int32_t ;
struct TYPE_8__ {int /*<<< orphan*/  num_sockets; } ;
struct TYPE_7__ {int cub_last_max; int cub_epoch_start; float cub_epoch_period; scalar_t__ cub_origin_point; scalar_t__ cub_target_win; scalar_t__ cub_tcp_win; scalar_t__ cub_tcp_bytes_acked; scalar_t__ cub_avg_lastmax; int cub_mean_dev; } ;
struct TYPE_6__ {TYPE_1__* inp_stat; } ;
struct TYPE_5__ {scalar_t__ txbytes; } ;
typedef  int /*<<< orphan*/  SInt32 ;

/* Variables and functions */
 scalar_t__ BYTES_ACKED (struct tcphdr*,struct tcpcb*) ; 
 int /*<<< orphan*/  IN_FASTRECOVERY (struct tcpcb*) ; 
 int /*<<< orphan*/  OSDecrementAtomic (int /*<<< orphan*/  volatile*) ; 
 int /*<<< orphan*/  OSIncrementAtomic (int /*<<< orphan*/  volatile*) ; 
 scalar_t__ SACK_ENABLED (struct tcpcb*) ; 
 scalar_t__ SEQ_LEQ (scalar_t__,scalar_t__) ; 
 scalar_t__ TCPS_ESTABLISHED ; 
 scalar_t__ TCP_CC_CWND_INIT_BYTES ; 
 scalar_t__ TCP_CUBIC_ENABLE_TCPMODE (struct tcpcb*) ; 
 int TCP_MAXWIN ; 
 int TCP_MAX_WINSHIFT ; 
 float TCP_RETRANSHZ ; 
 int TF_CWND_NONVALIDATED ; 
 int /*<<< orphan*/  VERIFY (int) ; 
 float cbrtf (float) ; 
 scalar_t__ current_task () ; 
 scalar_t__ get_base_rtt (struct tcpcb*) ; 
 scalar_t__ kernel_task ; 
 int max (scalar_t__,scalar_t__) ; 
 scalar_t__ min (scalar_t__,int) ; 
 TYPE_4__ tcp_cc_cubic ; 
 int /*<<< orphan*/  tcp_cc_cwnd_init_or_reset (struct tcpcb*) ; 
 int tcp_cc_delay_ack (struct tcpcb*,struct tcphdr*) ; 
 scalar_t__ tcp_cc_is_cwnd_nonvalidated (struct tcpcb*) ; 
 int /*<<< orphan*/  tcp_cc_resize_sndbuf (struct tcpcb*) ; 
 int /*<<< orphan*/  tcp_clear_pipeack_state (struct tcpcb*) ; 
 scalar_t__ tcp_cubic_backoff ; 
static  void tcp_cubic_clear_state (struct tcpcb*) ; 
 scalar_t__ tcp_cubic_coeff ; 
 int tcp_cubic_fast_convergence ; 
 scalar_t__ tcp_cubic_fast_convergence_factor ; 
 int tcp_cubic_tcp_friendliness ; 
 scalar_t__ tcp_cubic_use_minrtt ; 
 scalar_t__ tcp_do_rfc3465_lim2 ; 
 int tcp_now ; 
 scalar_t__ tcp_rxtseg_total_size (struct tcpcb*) ; 
 scalar_t__ timer_diff (int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int tcp_cubic_init(struct tcpcb *tp)
{
	OSIncrementAtomic((volatile SInt32 *)&tcp_cc_cubic.num_sockets);

	VERIFY(tp->t_ccstate != NULL);
	tcp_cubic_clear_state(tp);
	return (0);
}

__attribute__((used)) static int tcp_cubic_cleanup(struct tcpcb *tp)
{
#pragma unused(tp)
	OSDecrementAtomic((volatile SInt32 *)&tcp_cc_cubic.num_sockets);
	return (0);
}

__attribute__((used)) static void tcp_cubic_cwnd_init_or_reset(struct tcpcb *tp)
{
	VERIFY(tp->t_ccstate != NULL);	

	tcp_cubic_clear_state(tp);
	tcp_cc_cwnd_init_or_reset(tp);
	tp->t_pipeack = 0;
	tcp_clear_pipeack_state(tp);

	/* Start counting bytes for RFC 3465 again */
	tp->t_bytes_acked = 0;

	/*
	 * slow start threshold could get initialized to a lower value
	 * when there is a cached value in the route metrics. In this case,
	 * the connection can enter congestion avoidance without any packet
	 * loss and Cubic will enter steady-state too early. It is better
	 * to always probe to find the initial slow-start threshold.
	 */
	if (tp->t_inpcb->inp_stat->txbytes <= TCP_CC_CWND_INIT_BYTES
	    && tp->snd_ssthresh < (TCP_MAXWIN << TCP_MAX_WINSHIFT))
		tp->snd_ssthresh = TCP_MAXWIN << TCP_MAX_WINSHIFT;

	/* Initialize cubic last max to be same as ssthresh */
	tp->t_ccstate->cub_last_max = tp->snd_ssthresh;
}

__attribute__((used)) static uint32_t
tcp_cubic_update(struct tcpcb *tp, u_int32_t rtt)
{
	float K, var;
	u_int32_t elapsed_time, win;

	win = min(tp->snd_cwnd, tp->snd_wnd);
	if (tp->t_ccstate->cub_last_max == 0)
		tp->t_ccstate->cub_last_max = tp->snd_ssthresh;

	if (tp->t_ccstate->cub_epoch_start == 0) {
		/*
		 * This is the beginning of a new epoch, initialize some of
		 * the variables that we need to use for computing the 
		 * congestion window later.
		 */
		tp->t_ccstate->cub_epoch_start = tcp_now;
		if (tp->t_ccstate->cub_epoch_start == 0)
			tp->t_ccstate->cub_epoch_start = 1;
		if (win < tp->t_ccstate->cub_last_max) {

			VERIFY(current_task() == kernel_task);

			/*
			 * Compute cubic epoch period, this is the time
			 * period that the window will take to increase to
			 * last_max again after backoff due to loss.
			 */
			K = (tp->t_ccstate->cub_last_max - win)
			    / tp->t_maxseg / tcp_cubic_coeff;
			K = cbrtf(K);
			tp->t_ccstate->cub_epoch_period = K * TCP_RETRANSHZ;
			/* Origin point */
			tp->t_ccstate->cub_origin_point = 
				tp->t_ccstate->cub_last_max;
		} else {
			tp->t_ccstate->cub_epoch_period = 0;
			tp->t_ccstate->cub_origin_point = win;
		}
		tp->t_ccstate->cub_target_win = 0;
	}
	
	VERIFY(tp->t_ccstate->cub_origin_point > 0);	
	/*
	 * Compute the target window for the next RTT using smoothed RTT
	 * as an estimate for next RTT.
	 */
	elapsed_time = timer_diff(tcp_now, 0, 
		tp->t_ccstate->cub_epoch_start, 0);

	if (tcp_cubic_use_minrtt)
		elapsed_time += max(tcp_cubic_use_minrtt, rtt);
	else
		elapsed_time += rtt;
	var = (elapsed_time  - tp->t_ccstate->cub_epoch_period) / TCP_RETRANSHZ;
	var = var * var * var * (tcp_cubic_coeff * tp->t_maxseg);

	tp->t_ccstate->cub_target_win = (u_int32_t)(tp->t_ccstate->cub_origin_point + var);
	return (tp->t_ccstate->cub_target_win);
}

__attribute__((used)) static uint32_t
tcp_cubic_tcpwin(struct tcpcb *tp, struct tcphdr *th)
{
	if (tp->t_ccstate->cub_tcp_win == 0) {
		tp->t_ccstate->cub_tcp_win = min(tp->snd_cwnd, tp->snd_wnd);
		tp->t_ccstate->cub_tcp_bytes_acked = 0;
	} else {
		tp->t_ccstate->cub_tcp_bytes_acked +=
		    BYTES_ACKED(th, tp);
		if (tp->t_ccstate->cub_tcp_bytes_acked >=
		    tp->t_ccstate->cub_tcp_win) {
			tp->t_ccstate->cub_tcp_bytes_acked -=
			    tp->t_ccstate->cub_tcp_win;
			tp->t_ccstate->cub_tcp_win += tp->t_maxseg;
		}
	}	
	return (tp->t_ccstate->cub_tcp_win);
}

__attribute__((used)) static void
tcp_cubic_congestion_avd(struct tcpcb *tp, struct tcphdr *th)
{
	u_int32_t cubic_target_win, tcp_win, rtt;

	/* Do not increase congestion window in non-validated phase */
	if (tcp_cc_is_cwnd_nonvalidated(tp) != 0)
		return;

	tp->t_bytes_acked += BYTES_ACKED(th, tp);

	rtt = get_base_rtt(tp);
	/*
	 * First compute cubic window. If cubic variables are not
	 * initialized (after coming out of recovery), this call will
	 * initialize them.
	 */
	cubic_target_win = tcp_cubic_update(tp, rtt);

	/* Compute TCP window if a multiplicative decrease of 0.2 is used */
	tcp_win = tcp_cubic_tcpwin(tp, th);

	if (tp->snd_cwnd < tcp_win &&
	    (tcp_cubic_tcp_friendliness == 1 ||
	    TCP_CUBIC_ENABLE_TCPMODE(tp))) {
		/* this connection is in TCP-friendly region */
		if (tp->t_bytes_acked >= tp->snd_cwnd) {
			tp->t_bytes_acked -= tp->snd_cwnd;
			tp->snd_cwnd = min(tcp_win, TCP_MAXWIN << tp->snd_scale);
		}
	} else {
		if (cubic_target_win > tp->snd_cwnd) {
			/*
			 * The target win is computed for the next RTT.
			 * To reach this value, cwnd will have to be updated
			 * one segment at a time. Compute how many bytes 
			 * need to be acknowledged before we can increase 
			 * the cwnd by one segment.
			 */
			u_int64_t incr_win;
			incr_win = tp->snd_cwnd * tp->t_maxseg;
			incr_win /= (cubic_target_win - tp->snd_cwnd);
			if (incr_win > 0 &&
			    tp->t_bytes_acked >= incr_win) {
				tp->t_bytes_acked -= incr_win;
				tp->snd_cwnd = 
				    min((tp->snd_cwnd + tp->t_maxseg),
				    TCP_MAXWIN << tp->snd_scale);
			}
		}
	}
}

__attribute__((used)) static void
tcp_cubic_ack_rcvd(struct tcpcb *tp, struct tcphdr *th)
{
	/* Do not increase the congestion window in non-validated phase */
	if (tcp_cc_is_cwnd_nonvalidated(tp) != 0)
		return;

	if (tp->snd_cwnd >= tp->snd_ssthresh) {
		/* Congestion avoidance phase */
		tcp_cubic_congestion_avd(tp, th);
	} else {
		/*
		 * Use 2*SMSS as limit on increment as suggested
		 * by RFC 3465 section 2.3
		 */
		uint32_t acked, abc_lim, incr;

		acked = BYTES_ACKED(th, tp);
		abc_lim = (tcp_do_rfc3465_lim2 && 
			tp->snd_nxt == tp->snd_max) ?
			2 * tp->t_maxseg : tp->t_maxseg;
		incr = min(acked, abc_lim);

		tp->snd_cwnd += incr;
		tp->snd_cwnd = min(tp->snd_cwnd, 
			TCP_MAXWIN << tp->snd_scale);
	}
}

__attribute__((used)) static void
tcp_cubic_pre_fr(struct tcpcb *tp)
{
	u_int32_t win, avg;
	int32_t dev;
	tp->t_ccstate->cub_epoch_start = 0;
	tp->t_ccstate->cub_tcp_win = 0;
	tp->t_ccstate->cub_target_win = 0;
	tp->t_ccstate->cub_tcp_bytes_acked = 0;

	win = min(tp->snd_cwnd, tp->snd_wnd);
	if (tp->t_flagsext & TF_CWND_NONVALIDATED) {
		tp->t_lossflightsize = tp->snd_max - tp->snd_una;
		win = (max(tp->t_pipeack, tp->t_lossflightsize)) >> 1;
	} else {
		tp->t_lossflightsize = 0;
	}
	/*
	 * Note the congestion window at which packet loss occurred as
	 * cub_last_max.
	 *
	 * If the congestion window is less than the last max window when
	 * loss occurred, it indicates that capacity available in the 
	 * network has gone down. This can happen if a new flow has started
	 * and it is capturing some of the bandwidth. To reach convergence
	 * quickly, backoff a little more. Disable fast convergence to 
	 * disable this behavior.
	 */
	if (win < tp->t_ccstate->cub_last_max &&
		tcp_cubic_fast_convergence == 1)
		tp->t_ccstate->cub_last_max = (u_int32_t)(win *
			tcp_cubic_fast_convergence_factor);
	else
		tp->t_ccstate->cub_last_max = win;

	if (tp->t_ccstate->cub_last_max == 0) {
		/*
		 * If last_max is zero because snd_wnd is zero or for
		 * any other reason, initialize it to the amount of data
		 * in flight
		 */
		tp->t_ccstate->cub_last_max = tp->snd_max - tp->snd_una;
	}

	/*
	 * Compute average and mean absolute deviation of the
	 * window at which packet loss occurred.
	 */
	if (tp->t_ccstate->cub_avg_lastmax == 0) {
		tp->t_ccstate->cub_avg_lastmax = tp->t_ccstate->cub_last_max;
	} else {
		/*
		 * Average is computed by taking 63 parts of
		 * history and one part of the most recent value
		 */
		avg = tp->t_ccstate->cub_avg_lastmax;
		avg = (avg << 6) - avg;
		tp->t_ccstate->cub_avg_lastmax =
		    (avg + tp->t_ccstate->cub_last_max) >> 6; 
	}

	/* caluclate deviation from average */
	dev = tp->t_ccstate->cub_avg_lastmax - tp->t_ccstate->cub_last_max;

	/* Take the absolute value */
	if (dev < 0)
		dev = -dev;

	if (tp->t_ccstate->cub_mean_dev == 0) {
		tp->t_ccstate->cub_mean_dev = dev;
	} else {
		dev = dev + ((tp->t_ccstate->cub_mean_dev << 4)
		    - tp->t_ccstate->cub_mean_dev);
		tp->t_ccstate->cub_mean_dev = dev >> 4;
	}

	/* Backoff congestion window by tcp_cubic_backoff factor */
	win = (u_int32_t)(win - (win * tcp_cubic_backoff));
	win = (win / tp->t_maxseg);
	if (win < 2)
		win = 2;
	tp->snd_ssthresh = win * tp->t_maxseg;
	tcp_cc_resize_sndbuf(tp);
}

__attribute__((used)) static void
tcp_cubic_post_fr(struct tcpcb *tp, struct tcphdr *th)
{
	uint32_t flight_size = 0;

	if (SEQ_LEQ(th->th_ack, tp->snd_max))
		flight_size = tp->snd_max - th->th_ack;

	if (SACK_ENABLED(tp) && tp->t_lossflightsize > 0) {
		u_int32_t total_rxt_size = 0, ncwnd;
		/*
		 * When SACK is enabled, the number of retransmitted bytes
		 * can be counted more accurately.
		 */
		total_rxt_size = tcp_rxtseg_total_size(tp);
		ncwnd = max(tp->t_pipeack, tp->t_lossflightsize);
		if (total_rxt_size <= ncwnd) {
			ncwnd = ncwnd - total_rxt_size;
		}

		/*
		 * To avoid sending a large burst at the end of recovery
		 * set a max limit on ncwnd
		 */
		ncwnd = min(ncwnd, (tp->t_maxseg << 6));
		ncwnd = ncwnd >> 1;
		flight_size = max(ncwnd, flight_size);
	}
	/*
	 * Complete ack. The current window was inflated for fast recovery.
	 * It has to be deflated post recovery.
	 *
	 * Window inflation should have left us with approx snd_ssthresh 
	 * outstanding data. If the flight size is zero or one segment,
	 * make congestion window to be at least as big as 2 segments to
	 * avoid delayed acknowledgements. This is according to RFC 6582.
	 */
	if (flight_size < tp->snd_ssthresh)
		tp->snd_cwnd = max(flight_size, tp->t_maxseg) 
				+ tp->t_maxseg;
	else
		tp->snd_cwnd = tp->snd_ssthresh;
	tp->t_ccstate->cub_tcp_win = 0;
	tp->t_ccstate->cub_target_win = 0;
	tp->t_ccstate->cub_tcp_bytes_acked = 0;
}

__attribute__((used)) static void 
tcp_cubic_after_timeout(struct tcpcb *tp)
{
	VERIFY(tp->t_ccstate != NULL);

	/*
	 * Avoid adjusting congestion window due to SYN retransmissions.
	 * If more than one byte (SYN) is outstanding then it is still
	 * needed to adjust the window.
	 */
	if (tp->t_state < TCPS_ESTABLISHED &&
	    ((int)(tp->snd_max - tp->snd_una) <= 1))
		return;

	if (!IN_FASTRECOVERY(tp)) {
		tcp_cubic_clear_state(tp);
		tcp_cubic_pre_fr(tp);
	}

	/*
	 * Close the congestion window down to one segment as a retransmit
	 * timeout might indicate severe congestion.
	 */
	tp->snd_cwnd = tp->t_maxseg;
}

__attribute__((used)) static int
tcp_cubic_delay_ack(struct tcpcb *tp, struct tcphdr *th)
{
	return (tcp_cc_delay_ack(tp, th));
}

__attribute__((used)) static void
tcp_cubic_switch_cc(struct tcpcb *tp, uint16_t old_cc_index)
{
#pragma unused(old_cc_index)
	tcp_cubic_cwnd_init_or_reset(tp);

	OSIncrementAtomic((volatile SInt32 *)&tcp_cc_cubic.num_sockets);
}

__attribute__((used)) static inline void tcp_cubic_clear_state(struct tcpcb *tp)
{
	tp->t_ccstate->cub_last_max = 0;
	tp->t_ccstate->cub_epoch_start = 0;
	tp->t_ccstate->cub_origin_point = 0;
	tp->t_ccstate->cub_tcp_win = 0;
	tp->t_ccstate->cub_tcp_bytes_acked = 0;
	tp->t_ccstate->cub_epoch_period = 0;
	tp->t_ccstate->cub_target_win = 0;
}

