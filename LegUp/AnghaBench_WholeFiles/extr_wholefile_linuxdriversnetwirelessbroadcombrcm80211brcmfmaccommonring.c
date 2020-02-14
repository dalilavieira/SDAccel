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
typedef  scalar_t__ u16 ;
struct sk_buff {scalar_t__ protocol; int len; } ;
struct brcmf_pub {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  usr_subtype; int /*<<< orphan*/ * oui; } ;
struct brcmf_event {TYPE_1__ hdr; } ;
struct brcmf_commonring {int (* cr_ring_bell ) (void*) ;int (* cr_update_rptr ) (void*) ;int (* cr_update_wptr ) (void*) ;int (* cr_write_rptr ) (void*) ;int (* cr_write_wptr ) (void*) ;void* cr_ctx; int inited; scalar_t__ f_ptr; scalar_t__ w_ptr; scalar_t__ r_ptr; int /*<<< orphan*/  lock; void* buf_addr; scalar_t__ item_len; scalar_t__ depth; } ;

/* Variables and functions */
 scalar_t__ BCMILCP_BCM_SUBTYPE_EVENT ; 
 int /*<<< orphan*/  BRCM_OUI ; 
 int ETH_HLEN ; 
 int /*<<< orphan*/  ETH_P_LINK_CTL ; 
 int /*<<< orphan*/  brcmf_fweh_process_event (struct brcmf_pub*,struct brcmf_event*,int) ; 
 scalar_t__ cpu_to_be16 (int /*<<< orphan*/ ) ; 
 scalar_t__ get_unaligned_be16 (int /*<<< orphan*/ *) ; 
 scalar_t__ memcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 scalar_t__ skb_mac_header (struct sk_buff*) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int stub1 (void*) ; 
 int stub2 (void*) ; 

__attribute__((used)) static inline void brcmf_fweh_process_skb(struct brcmf_pub *drvr,
					  struct sk_buff *skb)
{
	struct brcmf_event *event_packet;
	u16 usr_stype;

	/* only process events when protocol matches */
	if (skb->protocol != cpu_to_be16(ETH_P_LINK_CTL))
		return;

	if ((skb->len + ETH_HLEN) < sizeof(*event_packet))
		return;

	/* check for BRCM oui match */
	event_packet = (struct brcmf_event *)skb_mac_header(skb);
	if (memcmp(BRCM_OUI, &event_packet->hdr.oui[0],
		   sizeof(event_packet->hdr.oui)))
		return;

	/* final match on usr_subtype */
	usr_stype = get_unaligned_be16(&event_packet->hdr.usr_subtype);
	if (usr_stype != BCMILCP_BCM_SUBTYPE_EVENT)
		return;

	brcmf_fweh_process_event(drvr, event_packet, skb->len + ETH_HLEN);
}

void brcmf_commonring_register_cb(struct brcmf_commonring *commonring,
				  int (*cr_ring_bell)(void *ctx),
				  int (*cr_update_rptr)(void *ctx),
				  int (*cr_update_wptr)(void *ctx),
				  int (*cr_write_rptr)(void *ctx),
				  int (*cr_write_wptr)(void *ctx), void *ctx)
{
	commonring->cr_ring_bell = cr_ring_bell;
	commonring->cr_update_rptr = cr_update_rptr;
	commonring->cr_update_wptr = cr_update_wptr;
	commonring->cr_write_rptr = cr_write_rptr;
	commonring->cr_write_wptr = cr_write_wptr;
	commonring->cr_ctx = ctx;
}

void brcmf_commonring_config(struct brcmf_commonring *commonring, u16 depth,
			     u16 item_len, void *buf_addr)
{
	commonring->depth = depth;
	commonring->item_len = item_len;
	commonring->buf_addr = buf_addr;
	if (!commonring->inited) {
		spin_lock_init(&commonring->lock);
		commonring->inited = true;
	}
	commonring->r_ptr = 0;
	if (commonring->cr_write_rptr)
		commonring->cr_write_rptr(commonring->cr_ctx);
	commonring->w_ptr = 0;
	if (commonring->cr_write_wptr)
		commonring->cr_write_wptr(commonring->cr_ctx);
	commonring->f_ptr = 0;
}

