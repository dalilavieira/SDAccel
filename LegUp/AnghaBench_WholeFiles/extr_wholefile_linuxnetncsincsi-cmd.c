#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_24__   TYPE_9__ ;
typedef  struct TYPE_23__   TYPE_8__ ;
typedef  struct TYPE_22__   TYPE_7__ ;
typedef  struct TYPE_21__   TYPE_6__ ;
typedef  struct TYPE_20__   TYPE_5__ ;
typedef  struct TYPE_19__   TYPE_4__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;
typedef  struct TYPE_15__   TYPE_12__ ;
typedef  struct TYPE_14__   TYPE_11__ ;
typedef  struct TYPE_13__   TYPE_10__ ;

/* Type definitions */
typedef  int u32 ;
struct sk_buff {void* protocol; struct net_device* dev; } ;
struct net_device {int needed_tailroom; } ;
struct ncsi_request {int enabled; struct sk_buff* cmd; int /*<<< orphan*/  timer; int /*<<< orphan*/  id; } ;
struct ncsi_pkt_hdr {scalar_t__ type; scalar_t__* reserved1; void* length; int /*<<< orphan*/  channel; int /*<<< orphan*/  id; scalar_t__ reserved; int /*<<< orphan*/  revision; scalar_t__ mc_id; } ;
struct ncsi_dev {struct net_device* dev; } ;
struct ncsi_dev_priv {struct ncsi_dev ndev; } ;
struct TYPE_22__ {struct ncsi_pkt_hdr common; } ;
struct ncsi_cmd_svf_pkt {TYPE_7__ cmd; int /*<<< orphan*/  enable; int /*<<< orphan*/  index; void* vlan; } ;
struct TYPE_17__ {struct ncsi_pkt_hdr common; } ;
struct ncsi_cmd_sp_pkt {TYPE_2__ cmd; int /*<<< orphan*/  hw_arbitration; } ;
struct TYPE_15__ {struct ncsi_pkt_hdr common; } ;
struct ncsi_cmd_snfc_pkt {TYPE_12__ cmd; int /*<<< orphan*/  mode; } ;
struct TYPE_24__ {struct ncsi_pkt_hdr common; } ;
struct ncsi_cmd_sma_pkt {TYPE_9__ cmd; int /*<<< orphan*/  at_e; int /*<<< orphan*/  index; int /*<<< orphan*/ * mac; } ;
struct TYPE_21__ {struct ncsi_pkt_hdr common; } ;
struct ncsi_cmd_sl_pkt {TYPE_6__ cmd; void* oem_mode; void* mode; } ;
struct TYPE_19__ {struct ncsi_pkt_hdr common; } ;
struct ncsi_cmd_rc_pkt {TYPE_4__ cmd; } ;
struct ncsi_cmd_pkt_hdr {int dummy; } ;
struct TYPE_16__ {struct ncsi_pkt_hdr common; } ;
struct ncsi_cmd_pkt {TYPE_1__ cmd; } ;
struct ncsi_cmd_handler {scalar_t__ type; int (* handler ) (struct sk_buff*,struct ncsi_cmd_arg*) ;int payload; } ;
struct TYPE_23__ {struct ncsi_pkt_hdr common; } ;
struct ncsi_cmd_ev_pkt {TYPE_8__ cmd; int /*<<< orphan*/  mode; } ;
struct TYPE_14__ {struct ncsi_pkt_hdr common; } ;
struct ncsi_cmd_egmf_pkt {TYPE_11__ cmd; void* mode; } ;
struct TYPE_13__ {struct ncsi_pkt_hdr common; } ;
struct ncsi_cmd_ebf_pkt {TYPE_10__ cmd; void* mode; } ;
struct TYPE_18__ {struct ncsi_pkt_hdr common; } ;
struct ncsi_cmd_dc_pkt {TYPE_3__ cmd; int /*<<< orphan*/  ald; } ;
struct ncsi_cmd_arg {scalar_t__ type; int payload; int* dwords; int* words; int /*<<< orphan*/  id; struct ncsi_dev_priv* ndp; int /*<<< orphan*/  req_flags; int /*<<< orphan*/ * bytes; int /*<<< orphan*/  channel; int /*<<< orphan*/  package; } ;
struct TYPE_20__ {struct ncsi_pkt_hdr common; } ;
struct ncsi_cmd_ae_pkt {TYPE_5__ cmd; void* mode; int /*<<< orphan*/  mc_id; } ;
struct ethhdr {int /*<<< orphan*/  h_source; int /*<<< orphan*/  h_dest; void* h_proto; } ;
typedef  void* __be32 ;

/* Variables and functions */
 int ARRAY_SIZE (struct ncsi_cmd_handler*) ; 
 int ENOENT ; 
 int ENOMEM ; 
 int ETH_P_NCSI ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int HZ ; 
 int LL_RESERVED_SPACE (struct net_device*) ; 
 int /*<<< orphan*/  NCSI_PKT_REVISION ; 
 int /*<<< orphan*/  NCSI_TO_CHANNEL (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct sk_buff* alloc_skb (int,int /*<<< orphan*/ ) ; 
 int dev_queue_xmit (struct sk_buff*) ; 
 int /*<<< orphan*/  eth_broadcast_addr (int /*<<< orphan*/ ) ; 
 void* htonl (int) ; 
 void* htons (int) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  mod_timer (int /*<<< orphan*/ *,scalar_t__) ; 
 struct ncsi_request* ncsi_alloc_request (struct ncsi_dev_priv*,int /*<<< orphan*/ ) ; 
 struct ncsi_cmd_handler* ncsi_cmd_handlers ; 
 int /*<<< orphan*/  ncsi_free_request (struct ncsi_request*) ; 
 int /*<<< orphan*/  netdev_err (struct net_device*,char*,scalar_t__) ; 
 int /*<<< orphan*/  skb_get (struct sk_buff*) ; 
 struct ethhdr* skb_push (struct sk_buff*,int) ; 
 void* skb_put_zero (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_reserve (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_reset_network_header (struct sk_buff*) ; 
 int stub1 (struct sk_buff*,struct ncsi_cmd_arg*) ; 

u32 ncsi_calculate_checksum(unsigned char *data, int len)
{
	u32 checksum = 0;
	int i;

	for (i = 0; i < len; i += 2)
		checksum += (((u32)data[i] << 8) | data[i + 1]);

	checksum = (~checksum + 1);
	return checksum;
}

__attribute__((used)) static void ncsi_cmd_build_header(struct ncsi_pkt_hdr *h,
				  struct ncsi_cmd_arg *nca)
{
	u32 checksum;
	__be32 *pchecksum;

	h->mc_id        = 0;
	h->revision     = NCSI_PKT_REVISION;
	h->reserved     = 0;
	h->id           = nca->id;
	h->type         = nca->type;
	h->channel      = NCSI_TO_CHANNEL(nca->package,
					  nca->channel);
	h->length       = htons(nca->payload);
	h->reserved1[0] = 0;
	h->reserved1[1] = 0;

	/* Fill with calculated checksum */
	checksum = ncsi_calculate_checksum((unsigned char *)h,
					   sizeof(*h) + nca->payload);
	pchecksum = (__be32 *)((void *)h + sizeof(struct ncsi_pkt_hdr) +
		    nca->payload);
	*pchecksum = htonl(checksum);
}

__attribute__((used)) static int ncsi_cmd_handler_default(struct sk_buff *skb,
				    struct ncsi_cmd_arg *nca)
{
	struct ncsi_cmd_pkt *cmd;

	cmd = skb_put_zero(skb, sizeof(*cmd));
	ncsi_cmd_build_header(&cmd->cmd.common, nca);

	return 0;
}

__attribute__((used)) static int ncsi_cmd_handler_sp(struct sk_buff *skb,
			       struct ncsi_cmd_arg *nca)
{
	struct ncsi_cmd_sp_pkt *cmd;

	cmd = skb_put_zero(skb, sizeof(*cmd));
	cmd->hw_arbitration = nca->bytes[0];
	ncsi_cmd_build_header(&cmd->cmd.common, nca);

	return 0;
}

__attribute__((used)) static int ncsi_cmd_handler_dc(struct sk_buff *skb,
			       struct ncsi_cmd_arg *nca)
{
	struct ncsi_cmd_dc_pkt *cmd;

	cmd = skb_put_zero(skb, sizeof(*cmd));
	cmd->ald = nca->bytes[0];
	ncsi_cmd_build_header(&cmd->cmd.common, nca);

	return 0;
}

__attribute__((used)) static int ncsi_cmd_handler_rc(struct sk_buff *skb,
			       struct ncsi_cmd_arg *nca)
{
	struct ncsi_cmd_rc_pkt *cmd;

	cmd = skb_put_zero(skb, sizeof(*cmd));
	ncsi_cmd_build_header(&cmd->cmd.common, nca);

	return 0;
}

__attribute__((used)) static int ncsi_cmd_handler_ae(struct sk_buff *skb,
			       struct ncsi_cmd_arg *nca)
{
	struct ncsi_cmd_ae_pkt *cmd;

	cmd = skb_put_zero(skb, sizeof(*cmd));
	cmd->mc_id = nca->bytes[0];
	cmd->mode = htonl(nca->dwords[1]);
	ncsi_cmd_build_header(&cmd->cmd.common, nca);

	return 0;
}

__attribute__((used)) static int ncsi_cmd_handler_sl(struct sk_buff *skb,
			       struct ncsi_cmd_arg *nca)
{
	struct ncsi_cmd_sl_pkt *cmd;

	cmd = skb_put_zero(skb, sizeof(*cmd));
	cmd->mode = htonl(nca->dwords[0]);
	cmd->oem_mode = htonl(nca->dwords[1]);
	ncsi_cmd_build_header(&cmd->cmd.common, nca);

	return 0;
}

__attribute__((used)) static int ncsi_cmd_handler_svf(struct sk_buff *skb,
				struct ncsi_cmd_arg *nca)
{
	struct ncsi_cmd_svf_pkt *cmd;

	cmd = skb_put_zero(skb, sizeof(*cmd));
	cmd->vlan = htons(nca->words[1]);
	cmd->index = nca->bytes[6];
	cmd->enable = nca->bytes[7];
	ncsi_cmd_build_header(&cmd->cmd.common, nca);

	return 0;
}

__attribute__((used)) static int ncsi_cmd_handler_ev(struct sk_buff *skb,
			       struct ncsi_cmd_arg *nca)
{
	struct ncsi_cmd_ev_pkt *cmd;

	cmd = skb_put_zero(skb, sizeof(*cmd));
	cmd->mode = nca->bytes[3];
	ncsi_cmd_build_header(&cmd->cmd.common, nca);

	return 0;
}

__attribute__((used)) static int ncsi_cmd_handler_sma(struct sk_buff *skb,
				struct ncsi_cmd_arg *nca)
{
	struct ncsi_cmd_sma_pkt *cmd;
	int i;

	cmd = skb_put_zero(skb, sizeof(*cmd));
	for (i = 0; i < 6; i++)
		cmd->mac[i] = nca->bytes[i];
	cmd->index = nca->bytes[6];
	cmd->at_e = nca->bytes[7];
	ncsi_cmd_build_header(&cmd->cmd.common, nca);

	return 0;
}

__attribute__((used)) static int ncsi_cmd_handler_ebf(struct sk_buff *skb,
				struct ncsi_cmd_arg *nca)
{
	struct ncsi_cmd_ebf_pkt *cmd;

	cmd = skb_put_zero(skb, sizeof(*cmd));
	cmd->mode = htonl(nca->dwords[0]);
	ncsi_cmd_build_header(&cmd->cmd.common, nca);

	return 0;
}

__attribute__((used)) static int ncsi_cmd_handler_egmf(struct sk_buff *skb,
				 struct ncsi_cmd_arg *nca)
{
	struct ncsi_cmd_egmf_pkt *cmd;

	cmd = skb_put_zero(skb, sizeof(*cmd));
	cmd->mode = htonl(nca->dwords[0]);
	ncsi_cmd_build_header(&cmd->cmd.common, nca);

	return 0;
}

__attribute__((used)) static int ncsi_cmd_handler_snfc(struct sk_buff *skb,
				 struct ncsi_cmd_arg *nca)
{
	struct ncsi_cmd_snfc_pkt *cmd;

	cmd = skb_put_zero(skb, sizeof(*cmd));
	cmd->mode = nca->bytes[0];
	ncsi_cmd_build_header(&cmd->cmd.common, nca);

	return 0;
}

__attribute__((used)) static struct ncsi_request *ncsi_alloc_command(struct ncsi_cmd_arg *nca)
{
	struct ncsi_dev_priv *ndp = nca->ndp;
	struct ncsi_dev *nd = &ndp->ndev;
	struct net_device *dev = nd->dev;
	int hlen = LL_RESERVED_SPACE(dev);
	int tlen = dev->needed_tailroom;
	int len = hlen + tlen;
	struct sk_buff *skb;
	struct ncsi_request *nr;

	nr = ncsi_alloc_request(ndp, nca->req_flags);
	if (!nr)
		return NULL;

	/* NCSI command packet has 16-bytes header, payload, 4 bytes checksum.
	 * The packet needs padding if its payload is less than 26 bytes to
	 * meet 64 bytes minimal ethernet frame length.
	 */
	len += sizeof(struct ncsi_cmd_pkt_hdr) + 4;
	if (nca->payload < 26)
		len += 26;
	else
		len += nca->payload;

	/* Allocate skb */
	skb = alloc_skb(len, GFP_ATOMIC);
	if (!skb) {
		ncsi_free_request(nr);
		return NULL;
	}

	nr->cmd = skb;
	skb_reserve(skb, hlen);
	skb_reset_network_header(skb);

	skb->dev = dev;
	skb->protocol = htons(ETH_P_NCSI);

	return nr;
}

int ncsi_xmit_cmd(struct ncsi_cmd_arg *nca)
{
	struct ncsi_request *nr;
	struct ethhdr *eh;
	struct ncsi_cmd_handler *nch = NULL;
	int i, ret;

	/* Search for the handler */
	for (i = 0; i < ARRAY_SIZE(ncsi_cmd_handlers); i++) {
		if (ncsi_cmd_handlers[i].type == nca->type) {
			if (ncsi_cmd_handlers[i].handler)
				nch = &ncsi_cmd_handlers[i];
			else
				nch = NULL;

			break;
		}
	}

	if (!nch) {
		netdev_err(nca->ndp->ndev.dev,
			   "Cannot send packet with type 0x%02x\n", nca->type);
		return -ENOENT;
	}

	/* Get packet payload length and allocate the request */
	nca->payload = nch->payload;
	nr = ncsi_alloc_command(nca);
	if (!nr)
		return -ENOMEM;

	/* Prepare the packet */
	nca->id = nr->id;
	ret = nch->handler(nr->cmd, nca);
	if (ret) {
		ncsi_free_request(nr);
		return ret;
	}

	/* Fill the ethernet header */
	eh = skb_push(nr->cmd, sizeof(*eh));
	eh->h_proto = htons(ETH_P_NCSI);
	eth_broadcast_addr(eh->h_dest);
	eth_broadcast_addr(eh->h_source);

	/* Start the timer for the request that might not have
	 * corresponding response. Given NCSI is an internal
	 * connection a 1 second delay should be sufficient.
	 */
	nr->enabled = true;
	mod_timer(&nr->timer, jiffies + 1 * HZ);

	/* Send NCSI packet */
	skb_get(nr->cmd);
	ret = dev_queue_xmit(nr->cmd);
	if (ret < 0) {
		ncsi_free_request(nr);
		return ret;
	}

	return 0;
}

