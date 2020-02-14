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
typedef  unsigned int u32 ;
struct tcp_sock {unsigned int snd_cwnd; scalar_t__ snd_ssthresh; } ;
struct sock {int dummy; } ;
struct inet_connection_sock {scalar_t__ icsk_ca_state; } ;
struct bictcp {unsigned int cnt; unsigned int last_max_cwnd; unsigned int last_cwnd; void* last_time; scalar_t__ epoch_start; int delayed_ack; } ;
struct ack_sample {int pkts_acked; } ;
typedef  int s32 ;
typedef  unsigned int __u32 ;

/* Variables and functions */
 int ACK_RATIO_SHIFT ; 
 unsigned int BICTCP_B ; 
 int BICTCP_BETA_SCALE ; 
 int HZ ; 
 scalar_t__ TCP_CA_Loss ; 
 scalar_t__ TCP_CA_Open ; 
 int beta ; 
 scalar_t__ fast_convergence ; 
 struct inet_connection_sock* inet_csk (struct sock*) ; 
 struct bictcp* inet_csk_ca (struct sock*) ; 
 scalar_t__ initial_ssthresh ; 
 unsigned int low_window ; 
 unsigned int max (int,unsigned int) ; 
 unsigned int max_increment ; 
 unsigned int smooth_part ; 
 int /*<<< orphan*/  tcp_cong_avoid_ai (struct tcp_sock*,int,int) ; 
 scalar_t__ tcp_in_slow_start (struct tcp_sock*) ; 
 int /*<<< orphan*/  tcp_is_cwnd_limited (struct sock*) ; 
 void* tcp_jiffies32 ; 
 struct tcp_sock* tcp_sk (struct sock*) ; 
 int /*<<< orphan*/  tcp_slow_start (struct tcp_sock*,unsigned int) ; 

__attribute__((used)) static inline void bictcp_reset(struct bictcp *ca)
{
	ca->cnt = 0;
	ca->last_max_cwnd = 0;
	ca->last_cwnd = 0;
	ca->last_time = 0;
	ca->epoch_start = 0;
	ca->delayed_ack = 2 << ACK_RATIO_SHIFT;
}

__attribute__((used)) static void bictcp_init(struct sock *sk)
{
	struct bictcp *ca = inet_csk_ca(sk);

	bictcp_reset(ca);

	if (initial_ssthresh)
		tcp_sk(sk)->snd_ssthresh = initial_ssthresh;
}

__attribute__((used)) static inline void bictcp_update(struct bictcp *ca, u32 cwnd)
{
	if (ca->last_cwnd == cwnd &&
	    (s32)(tcp_jiffies32 - ca->last_time) <= HZ / 32)
		return;

	ca->last_cwnd = cwnd;
	ca->last_time = tcp_jiffies32;

	if (ca->epoch_start == 0) /* record the beginning of an epoch */
		ca->epoch_start = tcp_jiffies32;

	/* start off normal */
	if (cwnd <= low_window) {
		ca->cnt = cwnd;
		return;
	}

	/* binary increase */
	if (cwnd < ca->last_max_cwnd) {
		__u32	dist = (ca->last_max_cwnd - cwnd)
			/ BICTCP_B;

		if (dist > max_increment)
			/* linear increase */
			ca->cnt = cwnd / max_increment;
		else if (dist <= 1U)
			/* binary search increase */
			ca->cnt = (cwnd * smooth_part) / BICTCP_B;
		else
			/* binary search increase */
			ca->cnt = cwnd / dist;
	} else {
		/* slow start AMD linear increase */
		if (cwnd < ca->last_max_cwnd + BICTCP_B)
			/* slow start */
			ca->cnt = (cwnd * smooth_part) / BICTCP_B;
		else if (cwnd < ca->last_max_cwnd + max_increment*(BICTCP_B-1))
			/* slow start */
			ca->cnt = (cwnd * (BICTCP_B-1))
				/ (cwnd - ca->last_max_cwnd);
		else
			/* linear increase */
			ca->cnt = cwnd / max_increment;
	}

	/* if in slow start or link utilization is very low */
	if (ca->last_max_cwnd == 0) {
		if (ca->cnt > 20) /* increase cwnd 5% per RTT */
			ca->cnt = 20;
	}

	ca->cnt = (ca->cnt << ACK_RATIO_SHIFT) / ca->delayed_ack;
	if (ca->cnt == 0)			/* cannot be zero */
		ca->cnt = 1;
}

__attribute__((used)) static void bictcp_cong_avoid(struct sock *sk, u32 ack, u32 acked)
{
	struct tcp_sock *tp = tcp_sk(sk);
	struct bictcp *ca = inet_csk_ca(sk);

	if (!tcp_is_cwnd_limited(sk))
		return;

	if (tcp_in_slow_start(tp))
		tcp_slow_start(tp, acked);
	else {
		bictcp_update(ca, tp->snd_cwnd);
		tcp_cong_avoid_ai(tp, ca->cnt, 1);
	}
}

__attribute__((used)) static u32 bictcp_recalc_ssthresh(struct sock *sk)
{
	const struct tcp_sock *tp = tcp_sk(sk);
	struct bictcp *ca = inet_csk_ca(sk);

	ca->epoch_start = 0;	/* end of epoch */

	/* Wmax and fast convergence */
	if (tp->snd_cwnd < ca->last_max_cwnd && fast_convergence)
		ca->last_max_cwnd = (tp->snd_cwnd * (BICTCP_BETA_SCALE + beta))
			/ (2 * BICTCP_BETA_SCALE);
	else
		ca->last_max_cwnd = tp->snd_cwnd;

	if (tp->snd_cwnd <= low_window)
		return max(tp->snd_cwnd >> 1U, 2U);
	else
		return max((tp->snd_cwnd * beta) / BICTCP_BETA_SCALE, 2U);
}

__attribute__((used)) static void bictcp_state(struct sock *sk, u8 new_state)
{
	if (new_state == TCP_CA_Loss)
		bictcp_reset(inet_csk_ca(sk));
}

__attribute__((used)) static void bictcp_acked(struct sock *sk, const struct ack_sample *sample)
{
	const struct inet_connection_sock *icsk = inet_csk(sk);

	if (icsk->icsk_ca_state == TCP_CA_Open) {
		struct bictcp *ca = inet_csk_ca(sk);

		ca->delayed_ack += sample->pkts_acked -
			(ca->delayed_ack >> ACK_RATIO_SHIFT);
	}
}

