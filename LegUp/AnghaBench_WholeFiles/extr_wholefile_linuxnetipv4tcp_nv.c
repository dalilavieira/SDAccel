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
struct TYPE_2__ {int tcpv_enabled; int tcpv_rttcnt; int tcpv_minrtt; scalar_t__ tcpv_rtt; } ;
union tcp_cc_info {TYPE_1__ vegas; } ;
typedef  scalar_t__ u8 ;
typedef  int u64 ;
typedef  scalar_t__ u32 ;
struct tcpvegas_info {int dummy; } ;
struct tcpnv {int nv_reset; scalar_t__ nv_no_cong_cnt; int nv_rtt_cnt; scalar_t__ nv_rtt_max_rate; scalar_t__ nv_rtt_start_seq; int nv_eval_call_cnt; scalar_t__ nv_last_snd_una; int nv_base_rtt; int nv_lower_bound_rtt; int nv_allow_cwnd_growth; int nv_min_rtt_reset_jiffies; scalar_t__ nv_min_rtt; scalar_t__ nv_min_rtt_new; int nv_min_cwnd; scalar_t__ cwnd_growth_factor; scalar_t__ nv_last_rtt; scalar_t__ nv_catchup; } ;
struct tcp_sock {scalar_t__ snd_una; scalar_t__ snd_cwnd; scalar_t__ snd_nxt; int mss_cache; scalar_t__ snd_ssthresh; } ;
struct sock {int dummy; } ;
struct inet_connection_sock {scalar_t__ icsk_ca_state; } ;
struct ack_sample {scalar_t__ rtt_us; scalar_t__ in_flight; } ;

/* Variables and functions */
 int /*<<< orphan*/  BPF_SOCK_OPS_BASE_RTT ; 
 int HZ ; 
 int INET_DIAG_VEGASINFO ; 
 void* NV_INIT_RTT ; 
 scalar_t__ NV_MIN_CWND ; 
 scalar_t__ NV_MIN_CWND_GROW ; 
 int NV_TSO_CWND_BOUND ; 
 scalar_t__ TCP_CA_CWR ; 
 scalar_t__ TCP_CA_Disorder ; 
 scalar_t__ TCP_CA_Loss ; 
 scalar_t__ TCP_CA_Open ; 
 scalar_t__ TCP_CA_Recovery ; 
 scalar_t__ TCP_INFINITE_SSTHRESH ; 
 scalar_t__ before (scalar_t__,scalar_t__) ; 
 scalar_t__ div64_u64 (int,unsigned long long) ; 
 int /*<<< orphan*/  do_div (int,int) ; 
 int /*<<< orphan*/  get_random_bytes (unsigned char*,int) ; 
 struct inet_connection_sock* inet_csk (struct sock*) ; 
 void* inet_csk_ca (struct sock*) ; 
 int jiffies ; 
 scalar_t__ max (unsigned int,scalar_t__) ; 
 int min (scalar_t__,int) ; 
 scalar_t__ nv_cong_dec_mult ; 
 scalar_t__ nv_cwnd_growth_rate_neg ; 
 scalar_t__ nv_cwnd_growth_rate_pos ; 
 int nv_dec_eval_min_calls ; 
 int nv_inc_eval_min_calls ; 
 int nv_loss_dec_factor ; 
 int nv_min_cwnd ; 
 scalar_t__ nv_pad ; 
 scalar_t__ nv_pad_buffer ; 
 int nv_reset_period ; 
 int nv_rtt_factor ; 
 int nv_rtt_min_cnt ; 
 int nv_ssthresh_eval_min_calls ; 
 scalar_t__ nv_ssthresh_factor ; 
 int nv_stop_rtt_cnt ; 
 int tcp_call_bpf (struct sock*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tcp_cong_avoid_ai (struct tcp_sock*,scalar_t__,scalar_t__) ; 
 scalar_t__ tcp_in_slow_start (struct tcp_sock*) ; 
 int /*<<< orphan*/  tcp_is_cwnd_limited (struct sock*) ; 
 void* tcp_sk (struct sock*) ; 
 scalar_t__ tcp_slow_start (struct tcp_sock*,scalar_t__) ; 
 scalar_t__ time_after_eq (unsigned long,int) ; 

__attribute__((used)) static inline void tcpnv_reset(struct tcpnv *ca, struct sock *sk)
{
	struct tcp_sock *tp = tcp_sk(sk);

	ca->nv_reset = 0;
	ca->nv_no_cong_cnt = 0;
	ca->nv_rtt_cnt = 0;
	ca->nv_last_rtt = 0;
	ca->nv_rtt_max_rate = 0;
	ca->nv_rtt_start_seq = tp->snd_una;
	ca->nv_eval_call_cnt = 0;
	ca->nv_last_snd_una = tp->snd_una;
}

__attribute__((used)) static void tcpnv_init(struct sock *sk)
{
	struct tcpnv *ca = inet_csk_ca(sk);
	int base_rtt;

	tcpnv_reset(ca, sk);

	/* See if base_rtt is available from socket_ops bpf program.
	 * It is meant to be used in environments, such as communication
	 * within a datacenter, where we have reasonable estimates of
	 * RTTs
	 */
	base_rtt = tcp_call_bpf(sk, BPF_SOCK_OPS_BASE_RTT, 0, NULL);
	if (base_rtt > 0) {
		ca->nv_base_rtt = base_rtt;
		ca->nv_lower_bound_rtt = (base_rtt * 205) >> 8; /* 80% */
	} else {
		ca->nv_base_rtt = 0;
		ca->nv_lower_bound_rtt = 0;
	}

	ca->nv_allow_cwnd_growth = 1;
	ca->nv_min_rtt_reset_jiffies = jiffies + 2 * HZ;
	ca->nv_min_rtt = NV_INIT_RTT;
	ca->nv_min_rtt_new = NV_INIT_RTT;
	ca->nv_min_cwnd = NV_MIN_CWND;
	ca->nv_catchup = 0;
	ca->cwnd_growth_factor = 0;
}

inline u32 nv_get_bounded_rtt(struct tcpnv *ca, u32 val)
{
	if (ca->nv_lower_bound_rtt > 0 && val < ca->nv_lower_bound_rtt)
		return ca->nv_lower_bound_rtt;
	else if (ca->nv_base_rtt > 0 && val > ca->nv_base_rtt)
		return ca->nv_base_rtt;
	else
		return val;
}

__attribute__((used)) static void tcpnv_cong_avoid(struct sock *sk, u32 ack, u32 acked)
{
	struct tcp_sock *tp = tcp_sk(sk);
	struct tcpnv *ca = inet_csk_ca(sk);
	u32 cnt;

	if (!tcp_is_cwnd_limited(sk))
		return;

	/* Only grow cwnd if NV has not detected congestion */
	if (!ca->nv_allow_cwnd_growth)
		return;

	if (tcp_in_slow_start(tp)) {
		acked = tcp_slow_start(tp, acked);
		if (!acked)
			return;
	}

	if (ca->cwnd_growth_factor < 0) {
		cnt = tp->snd_cwnd << -ca->cwnd_growth_factor;
		tcp_cong_avoid_ai(tp, cnt, acked);
	} else {
		cnt = max(4U, tp->snd_cwnd >> ca->cwnd_growth_factor);
		tcp_cong_avoid_ai(tp, cnt, acked);
	}
}

__attribute__((used)) static u32 tcpnv_recalc_ssthresh(struct sock *sk)
{
	const struct tcp_sock *tp = tcp_sk(sk);

	return max((tp->snd_cwnd * nv_loss_dec_factor) >> 10, 2U);
}

__attribute__((used)) static void tcpnv_state(struct sock *sk, u8 new_state)
{
	struct tcpnv *ca = inet_csk_ca(sk);

	if (new_state == TCP_CA_Open && ca->nv_reset) {
		tcpnv_reset(ca, sk);
	} else if (new_state == TCP_CA_Loss || new_state == TCP_CA_CWR ||
		new_state == TCP_CA_Recovery) {
		ca->nv_reset = 1;
		ca->nv_allow_cwnd_growth = 0;
		if (new_state == TCP_CA_Loss) {
			/* Reset cwnd growth factor to Reno value */
			if (ca->cwnd_growth_factor > 0)
				ca->cwnd_growth_factor = 0;
			/* Decrease growth rate if allowed */
			if (nv_cwnd_growth_rate_neg > 0 &&
			    ca->cwnd_growth_factor > -8)
				ca->cwnd_growth_factor--;
		}
	}
}

__attribute__((used)) static void tcpnv_acked(struct sock *sk, const struct ack_sample *sample)
{
	const struct inet_connection_sock *icsk = inet_csk(sk);
	struct tcp_sock *tp = tcp_sk(sk);
	struct tcpnv *ca = inet_csk_ca(sk);
	unsigned long now = jiffies;
	u64 rate64;
	u32 rate, max_win, cwnd_by_slope;
	u32 avg_rtt;
	u32 bytes_acked = 0;

	/* Some calls are for duplicates without timetamps */
	if (sample->rtt_us < 0)
		return;

	/* If not in TCP_CA_Open or TCP_CA_Disorder states, skip. */
	if (icsk->icsk_ca_state != TCP_CA_Open &&
	    icsk->icsk_ca_state != TCP_CA_Disorder)
		return;

	/* Stop cwnd growth if we were in catch up mode */
	if (ca->nv_catchup && tp->snd_cwnd >= nv_min_cwnd) {
		ca->nv_catchup = 0;
		ca->nv_allow_cwnd_growth = 0;
	}

	bytes_acked = tp->snd_una - ca->nv_last_snd_una;
	ca->nv_last_snd_una = tp->snd_una;

	if (sample->in_flight == 0)
		return;

	/* Calculate moving average of RTT */
	if (nv_rtt_factor > 0) {
		if (ca->nv_last_rtt > 0) {
			avg_rtt = (((u64)sample->rtt_us) * nv_rtt_factor +
				   ((u64)ca->nv_last_rtt)
				   * (256 - nv_rtt_factor)) >> 8;
		} else {
			avg_rtt = sample->rtt_us;
			ca->nv_min_rtt = avg_rtt << 1;
		}
		ca->nv_last_rtt = avg_rtt;
	} else {
		avg_rtt = sample->rtt_us;
	}

	/* rate in 100's bits per second */
	rate64 = ((u64)sample->in_flight) * 80000;
	do_div(rate64, avg_rtt ?: 1);
	rate = (u32)rate64;

	/* Remember the maximum rate seen during this RTT
	 * Note: It may be more than one RTT. This function should be
	 *       called at least nv_dec_eval_min_calls times.
	 */
	if (ca->nv_rtt_max_rate < rate)
		ca->nv_rtt_max_rate = rate;

	/* We have valid information, increment counter */
	if (ca->nv_eval_call_cnt < 255)
		ca->nv_eval_call_cnt++;

	/* Apply bounds to rtt. Only used to update min_rtt */
	avg_rtt = nv_get_bounded_rtt(ca, avg_rtt);

	/* update min rtt if necessary */
	if (avg_rtt < ca->nv_min_rtt)
		ca->nv_min_rtt = avg_rtt;

	/* update future min_rtt if necessary */
	if (avg_rtt < ca->nv_min_rtt_new)
		ca->nv_min_rtt_new = avg_rtt;

	/* nv_min_rtt is updated with the minimum (possibley averaged) rtt
	 * seen in the last sysctl_tcp_nv_reset_period seconds (i.e. a
	 * warm reset). This new nv_min_rtt will be continued to be updated
	 * and be used for another sysctl_tcp_nv_reset_period seconds,
	 * when it will be updated again.
	 * In practice we introduce some randomness, so the actual period used
	 * is chosen randomly from the range:
	 *   [sysctl_tcp_nv_reset_period*3/4, sysctl_tcp_nv_reset_period*5/4)
	 */
	if (time_after_eq(now, ca->nv_min_rtt_reset_jiffies)) {
		unsigned char rand;

		ca->nv_min_rtt = ca->nv_min_rtt_new;
		ca->nv_min_rtt_new = NV_INIT_RTT;
		get_random_bytes(&rand, 1);
		ca->nv_min_rtt_reset_jiffies =
			now + ((nv_reset_period * (384 + rand) * HZ) >> 9);
		/* Every so often we decrease ca->nv_min_cwnd in case previous
		 *  value is no longer accurate.
		 */
		ca->nv_min_cwnd = max(ca->nv_min_cwnd / 2, NV_MIN_CWND);
	}

	/* Once per RTT check if we need to do congestion avoidance */
	if (before(ca->nv_rtt_start_seq, tp->snd_una)) {
		ca->nv_rtt_start_seq = tp->snd_nxt;
		if (ca->nv_rtt_cnt < 0xff)
			/* Increase counter for RTTs without CA decision */
			ca->nv_rtt_cnt++;

		/* If this function is only called once within an RTT
		 * the cwnd is probably too small (in some cases due to
		 * tso, lro or interrupt coalescence), so we increase
		 * ca->nv_min_cwnd.
		 */
		if (ca->nv_eval_call_cnt == 1 &&
		    bytes_acked >= (ca->nv_min_cwnd - 1) * tp->mss_cache &&
		    ca->nv_min_cwnd < (NV_TSO_CWND_BOUND + 1)) {
			ca->nv_min_cwnd = min(ca->nv_min_cwnd
					      + NV_MIN_CWND_GROW,
					      NV_TSO_CWND_BOUND + 1);
			ca->nv_rtt_start_seq = tp->snd_nxt +
				ca->nv_min_cwnd * tp->mss_cache;
			ca->nv_eval_call_cnt = 0;
			ca->nv_allow_cwnd_growth = 1;
			return;
		}

		/* Find the ideal cwnd for current rate from slope
		 * slope = 80000.0 * mss / nv_min_rtt
		 * cwnd_by_slope = nv_rtt_max_rate / slope
		 */
		cwnd_by_slope = (u32)
			div64_u64(((u64)ca->nv_rtt_max_rate) * ca->nv_min_rtt,
				  80000ULL * tp->mss_cache);
		max_win = cwnd_by_slope + nv_pad;

		/* If cwnd > max_win, decrease cwnd
		 * if cwnd < max_win, grow cwnd
		 * else leave the same
		 */
		if (tp->snd_cwnd > max_win) {
			/* there is congestion, check that it is ok
			 * to make a CA decision
			 * 1. We should have at least nv_dec_eval_min_calls
			 *    data points before making a CA  decision
			 * 2. We only make a congesion decision after
			 *    nv_rtt_min_cnt RTTs
			 */
			if (ca->nv_rtt_cnt < nv_rtt_min_cnt) {
				return;
			} else if (tp->snd_ssthresh == TCP_INFINITE_SSTHRESH) {
				if (ca->nv_eval_call_cnt <
				    nv_ssthresh_eval_min_calls)
					return;
				/* otherwise we will decrease cwnd */
			} else if (ca->nv_eval_call_cnt <
				   nv_dec_eval_min_calls) {
				if (ca->nv_allow_cwnd_growth &&
				    ca->nv_rtt_cnt > nv_stop_rtt_cnt)
					ca->nv_allow_cwnd_growth = 0;
				return;
			}

			/* We have enough data to determine we are congested */
			ca->nv_allow_cwnd_growth = 0;
			tp->snd_ssthresh =
				(nv_ssthresh_factor * max_win) >> 3;
			if (tp->snd_cwnd - max_win > 2) {
				/* gap > 2, we do exponential cwnd decrease */
				int dec;

				dec = max(2U, ((tp->snd_cwnd - max_win) *
					       nv_cong_dec_mult) >> 7);
				tp->snd_cwnd -= dec;
			} else if (nv_cong_dec_mult > 0) {
				tp->snd_cwnd = max_win;
			}
			if (ca->cwnd_growth_factor > 0)
				ca->cwnd_growth_factor = 0;
			ca->nv_no_cong_cnt = 0;
		} else if (tp->snd_cwnd <= max_win - nv_pad_buffer) {
			/* There is no congestion, grow cwnd if allowed*/
			if (ca->nv_eval_call_cnt < nv_inc_eval_min_calls)
				return;

			ca->nv_allow_cwnd_growth = 1;
			ca->nv_no_cong_cnt++;
			if (ca->cwnd_growth_factor < 0 &&
			    nv_cwnd_growth_rate_neg > 0 &&
			    ca->nv_no_cong_cnt > nv_cwnd_growth_rate_neg) {
				ca->cwnd_growth_factor++;
				ca->nv_no_cong_cnt = 0;
			} else if (ca->cwnd_growth_factor >= 0 &&
				   nv_cwnd_growth_rate_pos > 0 &&
				   ca->nv_no_cong_cnt >
				   nv_cwnd_growth_rate_pos) {
				ca->cwnd_growth_factor++;
				ca->nv_no_cong_cnt = 0;
			}
		} else {
			/* cwnd is in-between, so do nothing */
			return;
		}

		/* update state */
		ca->nv_eval_call_cnt = 0;
		ca->nv_rtt_cnt = 0;
		ca->nv_rtt_max_rate = 0;

		/* Don't want to make cwnd < nv_min_cwnd
		 * (it wasn't before, if it is now is because nv
		 *  decreased it).
		 */
		if (tp->snd_cwnd < nv_min_cwnd)
			tp->snd_cwnd = nv_min_cwnd;
	}
}

__attribute__((used)) static size_t tcpnv_get_info(struct sock *sk, u32 ext, int *attr,
			     union tcp_cc_info *info)
{
	const struct tcpnv *ca = inet_csk_ca(sk);

	if (ext & (1 << (INET_DIAG_VEGASINFO - 1))) {
		info->vegas.tcpv_enabled = 1;
		info->vegas.tcpv_rttcnt = ca->nv_rtt_cnt;
		info->vegas.tcpv_rtt = ca->nv_last_rtt;
		info->vegas.tcpv_minrtt = ca->nv_min_rtt;

		*attr = INET_DIAG_VEGASINFO;
		return sizeof(struct tcpvegas_info);
	}
	return 0;
}

