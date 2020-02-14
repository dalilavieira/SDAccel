#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_8__ ;
typedef  struct TYPE_19__   TYPE_7__ ;
typedef  struct TYPE_18__   TYPE_6__ ;
typedef  struct TYPE_17__   TYPE_5__ ;
typedef  struct TYPE_16__   TYPE_4__ ;
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;
typedef  struct TYPE_12__   TYPE_11__ ;

/* Type definitions */
typedef  scalar_t__ u32 ;
struct TYPE_19__ {int flags; scalar_t__ replay_window; } ;
struct TYPE_18__ {int /*<<< orphan*/  replay_window; int /*<<< orphan*/  replay; } ;
struct xfrm_replay_state_esn {scalar_t__ seq_hi; scalar_t__ seq; int replay_window; scalar_t__ oseq; unsigned int bitmap; unsigned int* bmp; scalar_t__ oseq_hi; int bmp_len; } ;
struct xfrm_state {scalar_t__ replay_maxdiff; int xflags; TYPE_8__* repl; TYPE_7__ props; struct xfrm_replay_state_esn* replay_esn; TYPE_6__ stats; TYPE_2__* type; scalar_t__ replay_maxage; int /*<<< orphan*/  rtimer; struct xfrm_replay_state_esn* preplay_esn; struct xfrm_replay_state_esn replay; struct xfrm_replay_state_esn preplay; } ;
struct xfrm_replay_state {int dummy; } ;
struct sk_buff {int dummy; } ;
struct net {int dummy; } ;
struct TYPE_13__ {int aevent; } ;
struct km_event {TYPE_1__ data; void* event; } ;
typedef  int /*<<< orphan*/  __u32 ;
typedef  int /*<<< orphan*/  __be32 ;
struct TYPE_20__ {int /*<<< orphan*/  (* notify ) (struct xfrm_state*,int const) ;} ;
struct TYPE_16__ {scalar_t__ hi; } ;
struct TYPE_15__ {scalar_t__ low; scalar_t__ hi; } ;
struct TYPE_17__ {TYPE_4__ input; TYPE_3__ output; } ;
struct TYPE_14__ {int flags; } ;
struct TYPE_12__ {TYPE_5__ seq; } ;

/* Variables and functions */
 int EINVAL ; 
 int EOVERFLOW ; 
 void* XFRM_MSG_NEWAE ; 
#define  XFRM_REPLAY_TIMEOUT 129 
#define  XFRM_REPLAY_UPDATE 128 
 TYPE_11__* XFRM_SKB_CB (struct sk_buff*) ; 
 int XFRM_STATE_ESN ; 
 int XFRM_TIME_DEFER ; 
 int XFRM_TYPE_REPLAY_PROT ; 
 scalar_t__ htonl (scalar_t__) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  km_state_notify (struct xfrm_state*,struct km_event*) ; 
 scalar_t__ likely (int) ; 
 int /*<<< orphan*/  memcmp (struct xfrm_replay_state_esn*,struct xfrm_replay_state_esn*,int) ; 
 int /*<<< orphan*/  memcpy (struct xfrm_replay_state_esn*,struct xfrm_replay_state_esn*,int) ; 
 int /*<<< orphan*/  mod_timer (int /*<<< orphan*/ *,scalar_t__) ; 
 scalar_t__ ntohl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (struct xfrm_state*,int const) ; 
 int /*<<< orphan*/  stub2 (struct xfrm_state*,int const) ; 
 int /*<<< orphan*/  stub3 (struct xfrm_state*,int const) ; 
 int /*<<< orphan*/  stub4 (struct xfrm_state*,int const) ; 
 int /*<<< orphan*/  stub5 (struct xfrm_state*,int const) ; 
 int /*<<< orphan*/  stub6 (struct xfrm_state*,int const) ; 
 scalar_t__ unlikely (int) ; 
 scalar_t__ xfrm_aevent_is_on (struct net*) ; 
 int /*<<< orphan*/  xfrm_audit_state_replay (struct xfrm_state*,struct sk_buff*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xfrm_audit_state_replay_overflow (struct xfrm_state*,struct sk_buff*) ; 
 int /*<<< orphan*/  xfrm_dev_state_advance_esn (struct xfrm_state*) ; 
 TYPE_8__ xfrm_replay_bmp ; 
 TYPE_8__ xfrm_replay_esn ; 
 TYPE_8__ xfrm_replay_legacy ; 
 int xfrm_replay_state_esn_len (struct xfrm_replay_state_esn*) ; 
 struct net* xs_net (struct xfrm_state*) ; 

u32 xfrm_replay_seqhi(struct xfrm_state *x, __be32 net_seq)
{
	u32 seq, seq_hi, bottom;
	struct xfrm_replay_state_esn *replay_esn = x->replay_esn;

	if (!(x->props.flags & XFRM_STATE_ESN))
		return 0;

	seq = ntohl(net_seq);
	seq_hi = replay_esn->seq_hi;
	bottom = replay_esn->seq - replay_esn->replay_window + 1;

	if (likely(replay_esn->seq >= replay_esn->replay_window - 1)) {
		/* A. same subspace */
		if (unlikely(seq < bottom))
			seq_hi++;
	} else {
		/* B. window spans two subspaces */
		if (unlikely(seq >= bottom))
			seq_hi--;
	}

	return seq_hi;
}

__attribute__((used)) static void xfrm_replay_notify(struct xfrm_state *x, int event)
{
	struct km_event c;
	/* we send notify messages in case
	 *  1. we updated on of the sequence numbers, and the seqno difference
	 *     is at least x->replay_maxdiff, in this case we also update the
	 *     timeout of our timer function
	 *  2. if x->replay_maxage has elapsed since last update,
	 *     and there were changes
	 *
	 *  The state structure must be locked!
	 */

	switch (event) {
	case XFRM_REPLAY_UPDATE:
		if (!x->replay_maxdiff ||
		    ((x->replay.seq - x->preplay.seq < x->replay_maxdiff) &&
		    (x->replay.oseq - x->preplay.oseq < x->replay_maxdiff))) {
			if (x->xflags & XFRM_TIME_DEFER)
				event = XFRM_REPLAY_TIMEOUT;
			else
				return;
		}

		break;

	case XFRM_REPLAY_TIMEOUT:
		if (memcmp(&x->replay, &x->preplay,
			   sizeof(struct xfrm_replay_state)) == 0) {
			x->xflags |= XFRM_TIME_DEFER;
			return;
		}

		break;
	}

	memcpy(&x->preplay, &x->replay, sizeof(struct xfrm_replay_state));
	c.event = XFRM_MSG_NEWAE;
	c.data.aevent = event;
	km_state_notify(x, &c);

	if (x->replay_maxage &&
	    !mod_timer(&x->rtimer, jiffies + x->replay_maxage))
		x->xflags &= ~XFRM_TIME_DEFER;
}

__attribute__((used)) static int xfrm_replay_overflow(struct xfrm_state *x, struct sk_buff *skb)
{
	int err = 0;
	struct net *net = xs_net(x);

	if (x->type->flags & XFRM_TYPE_REPLAY_PROT) {
		XFRM_SKB_CB(skb)->seq.output.low = ++x->replay.oseq;
		XFRM_SKB_CB(skb)->seq.output.hi = 0;
		if (unlikely(x->replay.oseq == 0)) {
			x->replay.oseq--;
			xfrm_audit_state_replay_overflow(x, skb);
			err = -EOVERFLOW;

			return err;
		}
		if (xfrm_aevent_is_on(net))
			x->repl->notify(x, XFRM_REPLAY_UPDATE);
	}

	return err;
}

__attribute__((used)) static int xfrm_replay_check(struct xfrm_state *x,
		      struct sk_buff *skb, __be32 net_seq)
{
	u32 diff;
	u32 seq = ntohl(net_seq);

	if (!x->props.replay_window)
		return 0;

	if (unlikely(seq == 0))
		goto err;

	if (likely(seq > x->replay.seq))
		return 0;

	diff = x->replay.seq - seq;
	if (diff >= x->props.replay_window) {
		x->stats.replay_window++;
		goto err;
	}

	if (x->replay.bitmap & (1U << diff)) {
		x->stats.replay++;
		goto err;
	}
	return 0;

err:
	xfrm_audit_state_replay(x, skb, net_seq);
	return -EINVAL;
}

__attribute__((used)) static void xfrm_replay_advance(struct xfrm_state *x, __be32 net_seq)
{
	u32 diff;
	u32 seq = ntohl(net_seq);

	if (!x->props.replay_window)
		return;

	if (seq > x->replay.seq) {
		diff = seq - x->replay.seq;
		if (diff < x->props.replay_window)
			x->replay.bitmap = ((x->replay.bitmap) << diff) | 1;
		else
			x->replay.bitmap = 1;
		x->replay.seq = seq;
	} else {
		diff = x->replay.seq - seq;
		x->replay.bitmap |= (1U << diff);
	}

	if (xfrm_aevent_is_on(xs_net(x)))
		x->repl->notify(x, XFRM_REPLAY_UPDATE);
}

__attribute__((used)) static int xfrm_replay_overflow_bmp(struct xfrm_state *x, struct sk_buff *skb)
{
	int err = 0;
	struct xfrm_replay_state_esn *replay_esn = x->replay_esn;
	struct net *net = xs_net(x);

	if (x->type->flags & XFRM_TYPE_REPLAY_PROT) {
		XFRM_SKB_CB(skb)->seq.output.low = ++replay_esn->oseq;
		XFRM_SKB_CB(skb)->seq.output.hi = 0;
		if (unlikely(replay_esn->oseq == 0)) {
			replay_esn->oseq--;
			xfrm_audit_state_replay_overflow(x, skb);
			err = -EOVERFLOW;

			return err;
		}
		if (xfrm_aevent_is_on(net))
			x->repl->notify(x, XFRM_REPLAY_UPDATE);
	}

	return err;
}

__attribute__((used)) static int xfrm_replay_check_bmp(struct xfrm_state *x,
				 struct sk_buff *skb, __be32 net_seq)
{
	unsigned int bitnr, nr;
	struct xfrm_replay_state_esn *replay_esn = x->replay_esn;
	u32 pos;
	u32 seq = ntohl(net_seq);
	u32 diff =  replay_esn->seq - seq;

	if (!replay_esn->replay_window)
		return 0;

	if (unlikely(seq == 0))
		goto err;

	if (likely(seq > replay_esn->seq))
		return 0;

	if (diff >= replay_esn->replay_window) {
		x->stats.replay_window++;
		goto err;
	}

	pos = (replay_esn->seq - 1) % replay_esn->replay_window;

	if (pos >= diff)
		bitnr = (pos - diff) % replay_esn->replay_window;
	else
		bitnr = replay_esn->replay_window - (diff - pos);

	nr = bitnr >> 5;
	bitnr = bitnr & 0x1F;
	if (replay_esn->bmp[nr] & (1U << bitnr))
		goto err_replay;

	return 0;

err_replay:
	x->stats.replay++;
err:
	xfrm_audit_state_replay(x, skb, net_seq);
	return -EINVAL;
}

__attribute__((used)) static void xfrm_replay_advance_bmp(struct xfrm_state *x, __be32 net_seq)
{
	unsigned int bitnr, nr, i;
	u32 diff;
	struct xfrm_replay_state_esn *replay_esn = x->replay_esn;
	u32 seq = ntohl(net_seq);
	u32 pos;

	if (!replay_esn->replay_window)
		return;

	pos = (replay_esn->seq - 1) % replay_esn->replay_window;

	if (seq > replay_esn->seq) {
		diff = seq - replay_esn->seq;

		if (diff < replay_esn->replay_window) {
			for (i = 1; i < diff; i++) {
				bitnr = (pos + i) % replay_esn->replay_window;
				nr = bitnr >> 5;
				bitnr = bitnr & 0x1F;
				replay_esn->bmp[nr] &=  ~(1U << bitnr);
			}
		} else {
			nr = (replay_esn->replay_window - 1) >> 5;
			for (i = 0; i <= nr; i++)
				replay_esn->bmp[i] = 0;
		}

		bitnr = (pos + diff) % replay_esn->replay_window;
		replay_esn->seq = seq;
	} else {
		diff = replay_esn->seq - seq;

		if (pos >= diff)
			bitnr = (pos - diff) % replay_esn->replay_window;
		else
			bitnr = replay_esn->replay_window - (diff - pos);
	}

	nr = bitnr >> 5;
	bitnr = bitnr & 0x1F;
	replay_esn->bmp[nr] |= (1U << bitnr);

	if (xfrm_aevent_is_on(xs_net(x)))
		x->repl->notify(x, XFRM_REPLAY_UPDATE);
}

__attribute__((used)) static void xfrm_replay_notify_bmp(struct xfrm_state *x, int event)
{
	struct km_event c;
	struct xfrm_replay_state_esn *replay_esn = x->replay_esn;
	struct xfrm_replay_state_esn *preplay_esn = x->preplay_esn;

	/* we send notify messages in case
	 *  1. we updated on of the sequence numbers, and the seqno difference
	 *     is at least x->replay_maxdiff, in this case we also update the
	 *     timeout of our timer function
	 *  2. if x->replay_maxage has elapsed since last update,
	 *     and there were changes
	 *
	 *  The state structure must be locked!
	 */

	switch (event) {
	case XFRM_REPLAY_UPDATE:
		if (!x->replay_maxdiff ||
		    ((replay_esn->seq - preplay_esn->seq < x->replay_maxdiff) &&
		    (replay_esn->oseq - preplay_esn->oseq
		     < x->replay_maxdiff))) {
			if (x->xflags & XFRM_TIME_DEFER)
				event = XFRM_REPLAY_TIMEOUT;
			else
				return;
		}

		break;

	case XFRM_REPLAY_TIMEOUT:
		if (memcmp(x->replay_esn, x->preplay_esn,
			   xfrm_replay_state_esn_len(replay_esn)) == 0) {
			x->xflags |= XFRM_TIME_DEFER;
			return;
		}

		break;
	}

	memcpy(x->preplay_esn, x->replay_esn,
	       xfrm_replay_state_esn_len(replay_esn));
	c.event = XFRM_MSG_NEWAE;
	c.data.aevent = event;
	km_state_notify(x, &c);

	if (x->replay_maxage &&
	    !mod_timer(&x->rtimer, jiffies + x->replay_maxage))
		x->xflags &= ~XFRM_TIME_DEFER;
}

__attribute__((used)) static void xfrm_replay_notify_esn(struct xfrm_state *x, int event)
{
	u32 seq_diff, oseq_diff;
	struct km_event c;
	struct xfrm_replay_state_esn *replay_esn = x->replay_esn;
	struct xfrm_replay_state_esn *preplay_esn = x->preplay_esn;

	/* we send notify messages in case
	 *  1. we updated on of the sequence numbers, and the seqno difference
	 *     is at least x->replay_maxdiff, in this case we also update the
	 *     timeout of our timer function
	 *  2. if x->replay_maxage has elapsed since last update,
	 *     and there were changes
	 *
	 *  The state structure must be locked!
	 */

	switch (event) {
	case XFRM_REPLAY_UPDATE:
		if (x->replay_maxdiff) {
			if (replay_esn->seq_hi == preplay_esn->seq_hi)
				seq_diff = replay_esn->seq - preplay_esn->seq;
			else
				seq_diff = ~preplay_esn->seq + replay_esn->seq
					   + 1;

			if (replay_esn->oseq_hi == preplay_esn->oseq_hi)
				oseq_diff = replay_esn->oseq
					    - preplay_esn->oseq;
			else
				oseq_diff = ~preplay_esn->oseq
					    + replay_esn->oseq + 1;

			if (seq_diff >= x->replay_maxdiff ||
			    oseq_diff >= x->replay_maxdiff)
				break;
		}

		if (x->xflags & XFRM_TIME_DEFER)
			event = XFRM_REPLAY_TIMEOUT;
		else
			return;

		break;

	case XFRM_REPLAY_TIMEOUT:
		if (memcmp(x->replay_esn, x->preplay_esn,
			   xfrm_replay_state_esn_len(replay_esn)) == 0) {
			x->xflags |= XFRM_TIME_DEFER;
			return;
		}

		break;
	}

	memcpy(x->preplay_esn, x->replay_esn,
	       xfrm_replay_state_esn_len(replay_esn));
	c.event = XFRM_MSG_NEWAE;
	c.data.aevent = event;
	km_state_notify(x, &c);

	if (x->replay_maxage &&
	    !mod_timer(&x->rtimer, jiffies + x->replay_maxage))
		x->xflags &= ~XFRM_TIME_DEFER;
}

__attribute__((used)) static int xfrm_replay_overflow_esn(struct xfrm_state *x, struct sk_buff *skb)
{
	int err = 0;
	struct xfrm_replay_state_esn *replay_esn = x->replay_esn;
	struct net *net = xs_net(x);

	if (x->type->flags & XFRM_TYPE_REPLAY_PROT) {
		XFRM_SKB_CB(skb)->seq.output.low = ++replay_esn->oseq;
		XFRM_SKB_CB(skb)->seq.output.hi = replay_esn->oseq_hi;

		if (unlikely(replay_esn->oseq == 0)) {
			XFRM_SKB_CB(skb)->seq.output.hi = ++replay_esn->oseq_hi;

			if (replay_esn->oseq_hi == 0) {
				replay_esn->oseq--;
				replay_esn->oseq_hi--;
				xfrm_audit_state_replay_overflow(x, skb);
				err = -EOVERFLOW;

				return err;
			}
		}
		if (xfrm_aevent_is_on(net))
			x->repl->notify(x, XFRM_REPLAY_UPDATE);
	}

	return err;
}

__attribute__((used)) static int xfrm_replay_check_esn(struct xfrm_state *x,
				 struct sk_buff *skb, __be32 net_seq)
{
	unsigned int bitnr, nr;
	u32 diff;
	struct xfrm_replay_state_esn *replay_esn = x->replay_esn;
	u32 pos;
	u32 seq = ntohl(net_seq);
	u32 wsize = replay_esn->replay_window;
	u32 top = replay_esn->seq;
	u32 bottom = top - wsize + 1;

	if (!wsize)
		return 0;

	if (unlikely(seq == 0 && replay_esn->seq_hi == 0 &&
		     (replay_esn->seq < replay_esn->replay_window - 1)))
		goto err;

	diff = top - seq;

	if (likely(top >= wsize - 1)) {
		/* A. same subspace */
		if (likely(seq > top) || seq < bottom)
			return 0;
	} else {
		/* B. window spans two subspaces */
		if (likely(seq > top && seq < bottom))
			return 0;
		if (seq >= bottom)
			diff = ~seq + top + 1;
	}

	if (diff >= replay_esn->replay_window) {
		x->stats.replay_window++;
		goto err;
	}

	pos = (replay_esn->seq - 1) % replay_esn->replay_window;

	if (pos >= diff)
		bitnr = (pos - diff) % replay_esn->replay_window;
	else
		bitnr = replay_esn->replay_window - (diff - pos);

	nr = bitnr >> 5;
	bitnr = bitnr & 0x1F;
	if (replay_esn->bmp[nr] & (1U << bitnr))
		goto err_replay;

	return 0;

err_replay:
	x->stats.replay++;
err:
	xfrm_audit_state_replay(x, skb, net_seq);
	return -EINVAL;
}

__attribute__((used)) static int xfrm_replay_recheck_esn(struct xfrm_state *x,
				   struct sk_buff *skb, __be32 net_seq)
{
	if (unlikely(XFRM_SKB_CB(skb)->seq.input.hi !=
		     htonl(xfrm_replay_seqhi(x, net_seq)))) {
			x->stats.replay_window++;
			return -EINVAL;
	}

	return xfrm_replay_check_esn(x, skb, net_seq);
}

__attribute__((used)) static void xfrm_replay_advance_esn(struct xfrm_state *x, __be32 net_seq)
{
	unsigned int bitnr, nr, i;
	int wrap;
	u32 diff, pos, seq, seq_hi;
	struct xfrm_replay_state_esn *replay_esn = x->replay_esn;

	if (!replay_esn->replay_window)
		return;

	seq = ntohl(net_seq);
	pos = (replay_esn->seq - 1) % replay_esn->replay_window;
	seq_hi = xfrm_replay_seqhi(x, net_seq);
	wrap = seq_hi - replay_esn->seq_hi;

	if ((!wrap && seq > replay_esn->seq) || wrap > 0) {
		if (likely(!wrap))
			diff = seq - replay_esn->seq;
		else
			diff = ~replay_esn->seq + seq + 1;

		if (diff < replay_esn->replay_window) {
			for (i = 1; i < diff; i++) {
				bitnr = (pos + i) % replay_esn->replay_window;
				nr = bitnr >> 5;
				bitnr = bitnr & 0x1F;
				replay_esn->bmp[nr] &=  ~(1U << bitnr);
			}
		} else {
			nr = (replay_esn->replay_window - 1) >> 5;
			for (i = 0; i <= nr; i++)
				replay_esn->bmp[i] = 0;
		}

		bitnr = (pos + diff) % replay_esn->replay_window;
		replay_esn->seq = seq;

		if (unlikely(wrap > 0))
			replay_esn->seq_hi++;
	} else {
		diff = replay_esn->seq - seq;

		if (pos >= diff)
			bitnr = (pos - diff) % replay_esn->replay_window;
		else
			bitnr = replay_esn->replay_window - (diff - pos);
	}

	xfrm_dev_state_advance_esn(x);

	nr = bitnr >> 5;
	bitnr = bitnr & 0x1F;
	replay_esn->bmp[nr] |= (1U << bitnr);

	if (xfrm_aevent_is_on(xs_net(x)))
		x->repl->notify(x, XFRM_REPLAY_UPDATE);
}

int xfrm_init_replay(struct xfrm_state *x)
{
	struct xfrm_replay_state_esn *replay_esn = x->replay_esn;

	if (replay_esn) {
		if (replay_esn->replay_window >
		    replay_esn->bmp_len * sizeof(__u32) * 8)
			return -EINVAL;

		if (x->props.flags & XFRM_STATE_ESN) {
			if (replay_esn->replay_window == 0)
				return -EINVAL;
			x->repl = &xfrm_replay_esn;
		} else {
			x->repl = &xfrm_replay_bmp;
		}
	} else {
		x->repl = &xfrm_replay_legacy;
	}

	return 0;
}

