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
typedef  scalar_t__ u8 ;
typedef  int u64 ;
typedef  scalar_t__ u32 ;
struct veno {int doing_veno_now; int minrtt; int basertt; int inc; int cntrtt; int diff; } ;
struct tcp_sock {int snd_cwnd; int snd_cwnd_cnt; int snd_cwnd_clamp; } ;
struct sock {int dummy; } ;
struct ack_sample {scalar_t__ rtt_us; } ;
typedef  enum tcp_ca_event { ____Placeholder_tcp_ca_event } tcp_ca_event ;

/* Variables and functions */
 int CA_EVENT_CWND_RESTART ; 
 int CA_EVENT_TX_START ; 
 scalar_t__ TCP_CA_Open ; 
 int V_PARAM_SHIFT ; 
 scalar_t__ beta ; 
 int /*<<< orphan*/  do_div (int,scalar_t__) ; 
 struct veno* inet_csk_ca (struct sock*) ; 
 scalar_t__ max (unsigned int,unsigned int) ; 
 int min (int,scalar_t__) ; 
 int /*<<< orphan*/  tcp_cong_avoid_ai (struct tcp_sock*,int,int) ; 
 scalar_t__ tcp_in_slow_start (struct tcp_sock*) ; 
 int /*<<< orphan*/  tcp_is_cwnd_limited (struct sock*) ; 
 int /*<<< orphan*/  tcp_reno_cong_avoid (struct sock*,scalar_t__,scalar_t__) ; 
 void* tcp_sk (struct sock*) ; 
 int /*<<< orphan*/  tcp_slow_start (struct tcp_sock*,scalar_t__) ; 

__attribute__((used)) static inline void veno_enable(struct sock *sk)
{
	struct veno *veno = inet_csk_ca(sk);

	/* turn on Veno */
	veno->doing_veno_now = 1;

	veno->minrtt = 0x7fffffff;
}

__attribute__((used)) static inline void veno_disable(struct sock *sk)
{
	struct veno *veno = inet_csk_ca(sk);

	/* turn off Veno */
	veno->doing_veno_now = 0;
}

__attribute__((used)) static void tcp_veno_init(struct sock *sk)
{
	struct veno *veno = inet_csk_ca(sk);

	veno->basertt = 0x7fffffff;
	veno->inc = 1;
	veno_enable(sk);
}

__attribute__((used)) static void tcp_veno_pkts_acked(struct sock *sk,
				const struct ack_sample *sample)
{
	struct veno *veno = inet_csk_ca(sk);
	u32 vrtt;

	if (sample->rtt_us < 0)
		return;

	/* Never allow zero rtt or baseRTT */
	vrtt = sample->rtt_us + 1;

	/* Filter to find propagation delay: */
	if (vrtt < veno->basertt)
		veno->basertt = vrtt;

	/* Find the min rtt during the last rtt to find
	 * the current prop. delay + queuing delay:
	 */
	veno->minrtt = min(veno->minrtt, vrtt);
	veno->cntrtt++;
}

__attribute__((used)) static void tcp_veno_state(struct sock *sk, u8 ca_state)
{
	if (ca_state == TCP_CA_Open)
		veno_enable(sk);
	else
		veno_disable(sk);
}

__attribute__((used)) static void tcp_veno_cwnd_event(struct sock *sk, enum tcp_ca_event event)
{
	if (event == CA_EVENT_CWND_RESTART || event == CA_EVENT_TX_START)
		tcp_veno_init(sk);
}

__attribute__((used)) static void tcp_veno_cong_avoid(struct sock *sk, u32 ack, u32 acked)
{
	struct tcp_sock *tp = tcp_sk(sk);
	struct veno *veno = inet_csk_ca(sk);

	if (!veno->doing_veno_now) {
		tcp_reno_cong_avoid(sk, ack, acked);
		return;
	}

	/* limited by applications */
	if (!tcp_is_cwnd_limited(sk))
		return;

	/* We do the Veno calculations only if we got enough rtt samples */
	if (veno->cntrtt <= 2) {
		/* We don't have enough rtt samples to do the Veno
		 * calculation, so we'll behave like Reno.
		 */
		tcp_reno_cong_avoid(sk, ack, acked);
	} else {
		u64 target_cwnd;
		u32 rtt;

		/* We have enough rtt samples, so, using the Veno
		 * algorithm, we determine the state of the network.
		 */

		rtt = veno->minrtt;

		target_cwnd = (u64)tp->snd_cwnd * veno->basertt;
		target_cwnd <<= V_PARAM_SHIFT;
		do_div(target_cwnd, rtt);

		veno->diff = (tp->snd_cwnd << V_PARAM_SHIFT) - target_cwnd;

		if (tcp_in_slow_start(tp)) {
			/* Slow start.  */
			tcp_slow_start(tp, acked);
		} else {
			/* Congestion avoidance. */
			if (veno->diff < beta) {
				/* In the "non-congestive state", increase cwnd
				 *  every rtt.
				 */
				tcp_cong_avoid_ai(tp, tp->snd_cwnd, 1);
			} else {
				/* In the "congestive state", increase cwnd
				 * every other rtt.
				 */
				if (tp->snd_cwnd_cnt >= tp->snd_cwnd) {
					if (veno->inc &&
					    tp->snd_cwnd < tp->snd_cwnd_clamp) {
						tp->snd_cwnd++;
						veno->inc = 0;
					} else
						veno->inc = 1;
					tp->snd_cwnd_cnt = 0;
				} else
					tp->snd_cwnd_cnt++;
			}
		}
		if (tp->snd_cwnd < 2)
			tp->snd_cwnd = 2;
		else if (tp->snd_cwnd > tp->snd_cwnd_clamp)
			tp->snd_cwnd = tp->snd_cwnd_clamp;
	}
	/* Wipe the slate clean for the next rtt. */
	/* veno->cntrtt = 0; */
	veno->minrtt = 0x7fffffff;
}

__attribute__((used)) static u32 tcp_veno_ssthresh(struct sock *sk)
{
	const struct tcp_sock *tp = tcp_sk(sk);
	struct veno *veno = inet_csk_ca(sk);

	if (veno->diff < beta)
		/* in "non-congestive state", cut cwnd by 1/5 */
		return max(tp->snd_cwnd * 4 / 5, 2U);
	else
		/* in "congestive state", cut cwnd by 1/2 */
		return max(tp->snd_cwnd >> 1U, 2U);
}

