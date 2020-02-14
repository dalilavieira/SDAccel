#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct sk_buff {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/  dev; } ;
struct ncsi_dev_priv {int flags; TYPE_1__ ndev; int /*<<< orphan*/  lock; int /*<<< orphan*/  channel_queue; } ;
struct ncsi_channel_mode {unsigned long* data; } ;
struct ncsi_channel {char* id; int state; int /*<<< orphan*/  lock; struct ncsi_channel_mode* modes; int /*<<< orphan*/  link; } ;
struct TYPE_4__ {scalar_t__ revision; int /*<<< orphan*/  channel; int /*<<< orphan*/  length; } ;
struct ncsi_aen_pkt_hdr {scalar_t__ type; TYPE_2__ common; } ;
struct ncsi_aen_lsc_pkt {scalar_t__ status; scalar_t__ oem_status; } ;
struct ncsi_aen_hncdsc_pkt {scalar_t__ status; } ;
struct ncsi_aen_handler {scalar_t__ type; unsigned short payload; int (* handler ) (struct ncsi_dev_priv*,struct ncsi_aen_pkt_hdr*) ;} ;
typedef  scalar_t__ __be32 ;

/* Variables and functions */
 int ARRAY_SIZE (struct ncsi_aen_handler*) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOENT ; 
 int NCSI_CHANNEL_ACTIVE ; 
 int NCSI_CHANNEL_INACTIVE ; 
 int NCSI_CHANNEL_INVISIBLE ; 
 int NCSI_DEV_HWA ; 
 int NCSI_DEV_RESHUFFLE ; 
 size_t NCSI_MODE_LINK ; 
 scalar_t__ NCSI_PKT_REVISION ; 
 int /*<<< orphan*/  consume_skb (struct sk_buff*) ; 
 scalar_t__ htonl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  list_add_tail_rcu (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  list_empty (int /*<<< orphan*/ *) ; 
 struct ncsi_aen_handler* ncsi_aen_handlers ; 
 int /*<<< orphan*/  ncsi_calculate_checksum (unsigned char*,int) ; 
 int /*<<< orphan*/  ncsi_find_package_and_channel (struct ncsi_dev_priv*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct ncsi_channel**) ; 
 int ncsi_process_next_channel (struct ncsi_dev_priv*) ; 
 int /*<<< orphan*/  ncsi_stop_channel_monitor (struct ncsi_channel*) ; 
 int /*<<< orphan*/  netdev_dbg (int /*<<< orphan*/ ,char*,char*,char*) ; 
 int /*<<< orphan*/  netdev_err (int /*<<< orphan*/ ,char*,scalar_t__,int) ; 
 int /*<<< orphan*/  netdev_warn (int /*<<< orphan*/ ,char*,scalar_t__) ; 
 scalar_t__ ntohl (scalar_t__) ; 
 unsigned short const ntohs (int /*<<< orphan*/ ) ; 
 scalar_t__ skb_network_header (struct sk_buff*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int stub1 (struct ncsi_dev_priv*,struct ncsi_aen_pkt_hdr*) ; 

__attribute__((used)) static int ncsi_validate_aen_pkt(struct ncsi_aen_pkt_hdr *h,
				 const unsigned short payload)
{
	u32 checksum;
	__be32 *pchecksum;

	if (h->common.revision != NCSI_PKT_REVISION)
		return -EINVAL;
	if (ntohs(h->common.length) != payload)
		return -EINVAL;

	/* Validate checksum, which might be zeroes if the
	 * sender doesn't support checksum according to NCSI
	 * specification.
	 */
	pchecksum = (__be32 *)((void *)(h + 1) + payload - 4);
	if (ntohl(*pchecksum) == 0)
		return 0;

	checksum = ncsi_calculate_checksum((unsigned char *)h,
					   sizeof(*h) + payload - 4);
	if (*pchecksum != htonl(checksum))
		return -EINVAL;

	return 0;
}

__attribute__((used)) static int ncsi_aen_handler_lsc(struct ncsi_dev_priv *ndp,
				struct ncsi_aen_pkt_hdr *h)
{
	struct ncsi_aen_lsc_pkt *lsc;
	struct ncsi_channel *nc;
	struct ncsi_channel_mode *ncm;
	bool chained;
	int state;
	unsigned long old_data, data;
	unsigned long flags;

	/* Find the NCSI channel */
	ncsi_find_package_and_channel(ndp, h->common.channel, NULL, &nc);
	if (!nc)
		return -ENODEV;

	/* Update the link status */
	lsc = (struct ncsi_aen_lsc_pkt *)h;

	spin_lock_irqsave(&nc->lock, flags);
	ncm = &nc->modes[NCSI_MODE_LINK];
	old_data = ncm->data[2];
	data = ntohl(lsc->status);
	ncm->data[2] = data;
	ncm->data[4] = ntohl(lsc->oem_status);

	netdev_dbg(ndp->ndev.dev, "NCSI: LSC AEN - channel %u state %s\n",
		   nc->id, data & 0x1 ? "up" : "down");

	chained = !list_empty(&nc->link);
	state = nc->state;
	spin_unlock_irqrestore(&nc->lock, flags);

	if (!((old_data ^ data) & 0x1) || chained)
		return 0;
	if (!(state == NCSI_CHANNEL_INACTIVE && (data & 0x1)) &&
	    !(state == NCSI_CHANNEL_ACTIVE && !(data & 0x1)))
		return 0;

	if (!(ndp->flags & NCSI_DEV_HWA) &&
	    state == NCSI_CHANNEL_ACTIVE)
		ndp->flags |= NCSI_DEV_RESHUFFLE;

	ncsi_stop_channel_monitor(nc);
	spin_lock_irqsave(&ndp->lock, flags);
	list_add_tail_rcu(&nc->link, &ndp->channel_queue);
	spin_unlock_irqrestore(&ndp->lock, flags);

	return ncsi_process_next_channel(ndp);
}

__attribute__((used)) static int ncsi_aen_handler_cr(struct ncsi_dev_priv *ndp,
			       struct ncsi_aen_pkt_hdr *h)
{
	struct ncsi_channel *nc;
	unsigned long flags;

	/* Find the NCSI channel */
	ncsi_find_package_and_channel(ndp, h->common.channel, NULL, &nc);
	if (!nc)
		return -ENODEV;

	spin_lock_irqsave(&nc->lock, flags);
	if (!list_empty(&nc->link) ||
	    nc->state != NCSI_CHANNEL_ACTIVE) {
		spin_unlock_irqrestore(&nc->lock, flags);
		return 0;
	}
	spin_unlock_irqrestore(&nc->lock, flags);

	ncsi_stop_channel_monitor(nc);
	spin_lock_irqsave(&nc->lock, flags);
	nc->state = NCSI_CHANNEL_INVISIBLE;
	spin_unlock_irqrestore(&nc->lock, flags);

	spin_lock_irqsave(&ndp->lock, flags);
	nc->state = NCSI_CHANNEL_INACTIVE;
	list_add_tail_rcu(&nc->link, &ndp->channel_queue);
	spin_unlock_irqrestore(&ndp->lock, flags);

	return ncsi_process_next_channel(ndp);
}

__attribute__((used)) static int ncsi_aen_handler_hncdsc(struct ncsi_dev_priv *ndp,
				   struct ncsi_aen_pkt_hdr *h)
{
	struct ncsi_channel *nc;
	struct ncsi_channel_mode *ncm;
	struct ncsi_aen_hncdsc_pkt *hncdsc;
	unsigned long flags;

	/* Find the NCSI channel */
	ncsi_find_package_and_channel(ndp, h->common.channel, NULL, &nc);
	if (!nc)
		return -ENODEV;

	spin_lock_irqsave(&nc->lock, flags);
	ncm = &nc->modes[NCSI_MODE_LINK];
	hncdsc = (struct ncsi_aen_hncdsc_pkt *)h;
	ncm->data[3] = ntohl(hncdsc->status);
	spin_unlock_irqrestore(&nc->lock, flags);
	netdev_dbg(ndp->ndev.dev,
		   "NCSI: host driver %srunning on channel %u\n",
		   ncm->data[3] & 0x1 ? "" : "not ", nc->id);

	return 0;
}

int ncsi_aen_handler(struct ncsi_dev_priv *ndp, struct sk_buff *skb)
{
	struct ncsi_aen_pkt_hdr *h;
	struct ncsi_aen_handler *nah = NULL;
	int i, ret;

	/* Find the handler */
	h = (struct ncsi_aen_pkt_hdr *)skb_network_header(skb);
	for (i = 0; i < ARRAY_SIZE(ncsi_aen_handlers); i++) {
		if (ncsi_aen_handlers[i].type == h->type) {
			nah = &ncsi_aen_handlers[i];
			break;
		}
	}

	if (!nah) {
		netdev_warn(ndp->ndev.dev, "Invalid AEN (0x%x) received\n",
			    h->type);
		return -ENOENT;
	}

	ret = ncsi_validate_aen_pkt(h, nah->payload);
	if (ret) {
		netdev_warn(ndp->ndev.dev,
			    "NCSI: 'bad' packet ignored for AEN type 0x%x\n",
			    h->type);
		goto out;
	}

	ret = nah->handler(ndp, h);
	if (ret)
		netdev_err(ndp->ndev.dev,
			   "NCSI: Handler for AEN type 0x%x returned %d\n",
			   h->type, ret);
out:
	consume_skb(skb);
	return ret;
}

