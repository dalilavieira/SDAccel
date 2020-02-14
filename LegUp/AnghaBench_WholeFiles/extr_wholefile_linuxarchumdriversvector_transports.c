#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  scalar_t__ uint64_t ;
typedef  scalar_t__ uint32_t ;
struct virtio_net_hdr {scalar_t__ gso_type; int flags; } ;
struct vector_private {int req_size; int (* form_header ) (int /*<<< orphan*/ *,struct sk_buff*,struct vector_private*) ;int (* verify_header ) (int /*<<< orphan*/ *,struct sk_buff*,struct vector_private*) ;int header_size; int rx_header_size; struct arglist* parsed; TYPE_2__* fds; TYPE_3__* dev; struct uml_l2tpv3_data* transport_data; } ;
struct TYPE_5__ {int /*<<< orphan*/  header; int /*<<< orphan*/  arptype; } ;
struct uml_l2tpv3_data {int udp; int session_offset; scalar_t__ tx_session; int cookie; int cookie_is_64; int cookie_offset; scalar_t__ tx_cookie; int has_counter; int counter_offset; int pin_counter; unsigned long counter; int key; int key_offset; scalar_t__ tx_key; int has_sequence; int sequence_offset; int pin_sequence; unsigned long sequence; int ipv6; scalar_t__ rx_cookie; scalar_t__ rx_session; scalar_t__ rx_key; int checksum_offset; TYPE_1__ expected_header; } ;
struct uml_gre_data {int udp; int session_offset; scalar_t__ tx_session; int cookie; int cookie_is_64; int cookie_offset; scalar_t__ tx_cookie; int has_counter; int counter_offset; int pin_counter; unsigned long counter; int key; int key_offset; scalar_t__ tx_key; int has_sequence; int sequence_offset; int pin_sequence; unsigned long sequence; int ipv6; scalar_t__ rx_cookie; scalar_t__ rx_session; scalar_t__ rx_key; int checksum_offset; TYPE_1__ expected_header; } ;
struct sk_buff {int dummy; } ;
struct iphdr {int dummy; } ;
struct arglist {int dummy; } ;
struct TYPE_7__ {int hw_features; int features; } ;
struct TYPE_6__ {int /*<<< orphan*/  tx_fd; int /*<<< orphan*/  rx_fd; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GRE_IRB ; 
 int /*<<< orphan*/  GRE_MODE_KEY ; 
 int /*<<< orphan*/  GRE_MODE_SEQUENCE ; 
 char* GSO_ERROR ; 
 unsigned long L2TPV3_DATA_PACKET ; 
 int NETIF_F_GRO ; 
 int NETIF_F_GSO ; 
 int NETIF_F_HW_CSUM ; 
 int NETIF_F_RXCSUM ; 
 int NETIF_F_TSO ; 
 int /*<<< orphan*/  TRANS_GRE ; 
 int /*<<< orphan*/  TRANS_GRE_LEN ; 
 int /*<<< orphan*/  TRANS_L2TPV3 ; 
 int /*<<< orphan*/  TRANS_L2TPV3_LEN ; 
 int /*<<< orphan*/  TRANS_RAW ; 
 int /*<<< orphan*/  TRANS_RAW_LEN ; 
 int /*<<< orphan*/  TRANS_TAP ; 
 int /*<<< orphan*/  TRANS_TAP_LEN ; 
 int VIRTIO_NET_HDR_F_DATA_VALID ; 
 scalar_t__ VIRTIO_NET_HDR_GSO_NONE ; 
 scalar_t__ cpu_to_be32 (unsigned long) ; 
 void* cpu_to_be64 (unsigned long) ; 
 void* kmalloc (int,int /*<<< orphan*/ ) ; 
 scalar_t__ kstrtoint (char*,int /*<<< orphan*/ ,unsigned int*) ; 
 scalar_t__ kstrtoul (char*,int /*<<< orphan*/ ,unsigned long*) ; 
 scalar_t__ net_ratelimit () ; 
 int /*<<< orphan*/  netdev_err (TYPE_3__*,char*,...) ; 
 int /*<<< orphan*/  netdev_info (TYPE_3__*,char*) ; 
 scalar_t__ strncmp (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ uml_raw_enable_vnet_headers (int /*<<< orphan*/ ) ; 
 scalar_t__ uml_tap_enable_vnet_headers (int /*<<< orphan*/ ) ; 
 char* uml_vector_fetch_arg (struct arglist*,char*) ; 
 int /*<<< orphan*/  virtio_legacy_is_little_endian () ; 
 int /*<<< orphan*/  virtio_net_hdr_from_skb (struct sk_buff*,struct virtio_net_hdr*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  virtio_net_hdr_to_skb (struct sk_buff*,struct virtio_net_hdr*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int l2tpv3_form_header(uint8_t *header,
	struct sk_buff *skb, struct vector_private *vp)
{
	struct uml_l2tpv3_data *td = vp->transport_data;
	uint32_t *counter;

	if (td->udp)
		*(uint32_t *) header = cpu_to_be32(L2TPV3_DATA_PACKET);
	(*(uint32_t *) (header + td->session_offset)) = td->tx_session;

	if (td->cookie) {
		if (td->cookie_is_64)
			(*(uint64_t *)(header + td->cookie_offset)) =
				td->tx_cookie;
		else
			(*(uint32_t *)(header + td->cookie_offset)) =
				td->tx_cookie;
	}
	if (td->has_counter) {
		counter = (uint32_t *)(header + td->counter_offset);
		if (td->pin_counter) {
			*counter = 0;
		} else {
			td->counter++;
			*counter = cpu_to_be32(td->counter);
		}
	}
	return 0;
}

__attribute__((used)) static int gre_form_header(uint8_t *header,
		struct sk_buff *skb, struct vector_private *vp)
{
	struct uml_gre_data *td = vp->transport_data;
	uint32_t *sequence;
	*((uint32_t *) header) = *((uint32_t *) &td->expected_header);
	if (td->key)
		(*(uint32_t *) (header + td->key_offset)) = td->tx_key;
	if (td->has_sequence) {
		sequence = (uint32_t *)(header + td->sequence_offset);
		if (td->pin_sequence)
			*sequence = 0;
		else
			*sequence = cpu_to_be32(++td->sequence);
	}
	return 0;
}

__attribute__((used)) static int raw_form_header(uint8_t *header,
		struct sk_buff *skb, struct vector_private *vp)
{
	struct virtio_net_hdr *vheader = (struct virtio_net_hdr *) header;

	virtio_net_hdr_from_skb(
		skb,
		vheader,
		virtio_legacy_is_little_endian(),
		false,
		0
	);

	return 0;
}

__attribute__((used)) static int l2tpv3_verify_header(
	uint8_t *header, struct sk_buff *skb, struct vector_private *vp)
{
	struct uml_l2tpv3_data *td = vp->transport_data;
	uint32_t *session;
	uint64_t cookie;

	if ((!td->udp) && (!td->ipv6))
		header += sizeof(struct iphdr) /* fix for ipv4 raw */;

	/* we do not do a strict check for "data" packets as per
	 * the RFC spec because the pure IP spec does not have
	 * that anyway.
	 */

	if (td->cookie) {
		if (td->cookie_is_64)
			cookie = *(uint64_t *)(header + td->cookie_offset);
		else
			cookie = *(uint32_t *)(header + td->cookie_offset);
		if (cookie != td->rx_cookie) {
			if (net_ratelimit())
				netdev_err(vp->dev, "uml_l2tpv3: unknown cookie id");
			return -1;
		}
	}
	session = (uint32_t *) (header + td->session_offset);
	if (*session != td->rx_session) {
		if (net_ratelimit())
			netdev_err(vp->dev, "uml_l2tpv3: session mismatch");
		return -1;
	}
	return 0;
}

__attribute__((used)) static int gre_verify_header(
	uint8_t *header, struct sk_buff *skb, struct vector_private *vp)
{

	uint32_t key;
	struct uml_gre_data *td = vp->transport_data;

	if (!td->ipv6)
		header += sizeof(struct iphdr) /* fix for ipv4 raw */;

	if (*((uint32_t *) header) != *((uint32_t *) &td->expected_header)) {
		if (net_ratelimit())
			netdev_err(vp->dev, "header type disagreement, expecting %0x, got %0x",
				*((uint32_t *) &td->expected_header),
				*((uint32_t *) header)
			);
		return -1;
	}

	if (td->key) {
		key = (*(uint32_t *)(header + td->key_offset));
		if (key != td->rx_key) {
			if (net_ratelimit())
				netdev_err(vp->dev, "unknown key id %0x, expecting %0x",
						key, td->rx_key);
			return -1;
		}
	}
	return 0;
}

__attribute__((used)) static int raw_verify_header(
	uint8_t *header, struct sk_buff *skb, struct vector_private *vp)
{
	struct virtio_net_hdr *vheader = (struct virtio_net_hdr *) header;

	if ((vheader->gso_type != VIRTIO_NET_HDR_GSO_NONE) &&
		(vp->req_size != 65536)) {
		if (net_ratelimit())
			netdev_err(
				vp->dev,
				GSO_ERROR
		);
	}
	if ((vheader->flags & VIRTIO_NET_HDR_F_DATA_VALID) > 0)
		return 1;

	virtio_net_hdr_to_skb(skb, vheader, virtio_legacy_is_little_endian());
	return 0;
}

__attribute__((used)) static bool get_uint_param(
	struct arglist *def, char *param, unsigned int *result)
{
	char *arg = uml_vector_fetch_arg(def, param);

	if (arg != NULL) {
		if (kstrtoint(arg, 0, result) == 0)
			return true;
	}
	return false;
}

__attribute__((used)) static bool get_ulong_param(
	struct arglist *def, char *param, unsigned long *result)
{
	char *arg = uml_vector_fetch_arg(def, param);

	if (arg != NULL) {
		if (kstrtoul(arg, 0, result) == 0)
			return true;
		return true;
	}
	return false;
}

__attribute__((used)) static int build_gre_transport_data(struct vector_private *vp)
{
	struct uml_gre_data *td;
	int temp_int;
	int temp_rx;
	int temp_tx;

	vp->transport_data = kmalloc(sizeof(struct uml_gre_data), GFP_KERNEL);
	if (vp->transport_data == NULL)
		return -ENOMEM;
	td = vp->transport_data;
	td->sequence = 0;

	td->expected_header.arptype = GRE_IRB;
	td->expected_header.header = 0;

	vp->form_header = &gre_form_header;
	vp->verify_header = &gre_verify_header;
	vp->header_size = 4;
	td->key_offset = 4;
	td->sequence_offset = 4;
	td->checksum_offset = 4;

	td->ipv6 = false;
	if (get_uint_param(vp->parsed, "v6", &temp_int)) {
		if (temp_int > 0)
			td->ipv6 = true;
	}
	td->key = false;
	if (get_uint_param(vp->parsed, "rx_key", &temp_rx)) {
		if (get_uint_param(vp->parsed, "tx_key", &temp_tx)) {
			td->key = true;
			td->expected_header.header |= GRE_MODE_KEY;
			td->rx_key = cpu_to_be32(temp_rx);
			td->tx_key = cpu_to_be32(temp_tx);
			vp->header_size += 4;
			td->sequence_offset += 4;
		} else {
			return -EINVAL;
		}
	}

	td->sequence = false;
	if (get_uint_param(vp->parsed, "sequence", &temp_int)) {
		if (temp_int > 0) {
			vp->header_size += 4;
			td->has_sequence = true;
			td->expected_header.header |= GRE_MODE_SEQUENCE;
			if (get_uint_param(
				vp->parsed, "pin_sequence", &temp_int)) {
				if (temp_int > 0)
					td->pin_sequence = true;
			}
		}
	}
	vp->rx_header_size = vp->header_size;
	if (!td->ipv6)
		vp->rx_header_size += sizeof(struct iphdr);
	return 0;
}

__attribute__((used)) static int build_l2tpv3_transport_data(struct vector_private *vp)
{

	struct uml_l2tpv3_data *td;
	int temp_int, temp_rxs, temp_txs;
	unsigned long temp_rx;
	unsigned long temp_tx;

	vp->transport_data = kmalloc(
		sizeof(struct uml_l2tpv3_data), GFP_KERNEL);

	if (vp->transport_data == NULL)
		return -ENOMEM;

	td = vp->transport_data;

	vp->form_header = &l2tpv3_form_header;
	vp->verify_header = &l2tpv3_verify_header;
	td->counter = 0;

	vp->header_size = 4;
	td->session_offset = 0;
	td->cookie_offset = 4;
	td->counter_offset = 4;


	td->ipv6 = false;
	if (get_uint_param(vp->parsed, "v6", &temp_int)) {
		if (temp_int > 0)
			td->ipv6 = true;
	}

	if (get_uint_param(vp->parsed, "rx_session", &temp_rxs)) {
		if (get_uint_param(vp->parsed, "tx_session", &temp_txs)) {
			td->tx_session = cpu_to_be32(temp_txs);
			td->rx_session = cpu_to_be32(temp_rxs);
		} else {
			return -EINVAL;
		}
	} else {
		return -EINVAL;
	}

	td->cookie_is_64  = false;
	if (get_uint_param(vp->parsed, "cookie64", &temp_int)) {
		if (temp_int > 0)
			td->cookie_is_64  = true;
	}
	td->cookie = false;
	if (get_ulong_param(vp->parsed, "rx_cookie", &temp_rx)) {
		if (get_ulong_param(vp->parsed, "tx_cookie", &temp_tx)) {
			td->cookie = true;
			if (td->cookie_is_64) {
				td->rx_cookie = cpu_to_be64(temp_rx);
				td->tx_cookie = cpu_to_be64(temp_tx);
				vp->header_size += 8;
				td->counter_offset += 8;
			} else {
				td->rx_cookie = cpu_to_be32(temp_rx);
				td->tx_cookie = cpu_to_be32(temp_tx);
				vp->header_size += 4;
				td->counter_offset += 4;
			}
		} else {
			return -EINVAL;
		}
	}

	td->has_counter = false;
	if (get_uint_param(vp->parsed, "counter", &temp_int)) {
		if (temp_int > 0) {
			td->has_counter = true;
			vp->header_size += 4;
			if (get_uint_param(
				vp->parsed, "pin_counter", &temp_int)) {
				if (temp_int > 0)
					td->pin_counter = true;
			}
		}
	}

	if (get_uint_param(vp->parsed, "udp", &temp_int)) {
		if (temp_int > 0) {
			td->udp = true;
			vp->header_size += 4;
			td->counter_offset += 4;
			td->session_offset += 4;
			td->cookie_offset += 4;
		}
	}

	vp->rx_header_size = vp->header_size;
	if ((!td->ipv6) && (!td->udp))
		vp->rx_header_size += sizeof(struct iphdr);

	return 0;
}

__attribute__((used)) static int build_raw_transport_data(struct vector_private *vp)
{
	if (uml_raw_enable_vnet_headers(vp->fds->rx_fd)) {
		if (!uml_raw_enable_vnet_headers(vp->fds->tx_fd))
			return -1;
		vp->form_header = &raw_form_header;
		vp->verify_header = &raw_verify_header;
		vp->header_size = sizeof(struct virtio_net_hdr);
		vp->rx_header_size = sizeof(struct virtio_net_hdr);
		vp->dev->hw_features |= (NETIF_F_TSO | NETIF_F_GRO);
		vp->dev->features |=
			(NETIF_F_RXCSUM | NETIF_F_HW_CSUM |
				NETIF_F_TSO | NETIF_F_GRO);
		netdev_info(
			vp->dev,
			"raw: using vnet headers for tso and tx/rx checksum"
		);
	}
	return 0;
}

__attribute__((used)) static int build_tap_transport_data(struct vector_private *vp)
{
	if (uml_raw_enable_vnet_headers(vp->fds->rx_fd)) {
		vp->form_header = &raw_form_header;
		vp->verify_header = &raw_verify_header;
		vp->header_size = sizeof(struct virtio_net_hdr);
		vp->rx_header_size = sizeof(struct virtio_net_hdr);
		vp->dev->hw_features |=
			(NETIF_F_TSO | NETIF_F_GSO | NETIF_F_GRO);
		vp->dev->features |=
			(NETIF_F_RXCSUM | NETIF_F_HW_CSUM |
				NETIF_F_TSO | NETIF_F_GSO | NETIF_F_GRO);
		netdev_info(
			vp->dev,
			"tap/raw: using vnet headers for tso and tx/rx checksum"
		);
	} else {
		return 0; /* do not try to enable tap too if raw failed */
	}
	if (uml_tap_enable_vnet_headers(vp->fds->tx_fd))
		return 0;
	return -1;
}

int build_transport_data(struct vector_private *vp)
{
	char *transport = uml_vector_fetch_arg(vp->parsed, "transport");

	if (strncmp(transport, TRANS_GRE, TRANS_GRE_LEN) == 0)
		return build_gre_transport_data(vp);
	if (strncmp(transport, TRANS_L2TPV3, TRANS_L2TPV3_LEN) == 0)
		return build_l2tpv3_transport_data(vp);
	if (strncmp(transport, TRANS_RAW, TRANS_RAW_LEN) == 0)
		return build_raw_transport_data(vp);
	if (strncmp(transport, TRANS_TAP, TRANS_TAP_LEN) == 0)
		return build_tap_transport_data(vp);
	return 0;
}

