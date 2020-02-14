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
typedef  int u64 ;
typedef  scalar_t__ u32 ;
typedef  int u16 ;
struct TYPE_6__ {int /*<<< orphan*/  (* process ) (struct fm10k_hw*,struct fm10k_mbx_info*) ;} ;
struct fm10k_mbx_info {scalar_t__ state; int /*<<< orphan*/  timeout; TYPE_2__ ops; } ;
struct TYPE_7__ {int /*<<< orphan*/  (* request_lport_map ) (struct fm10k_hw*) ;} ;
struct fm10k_mac_info {scalar_t__ dglort_map; int max_msix_vectors; int tx_ready; int max_queues; int get_host_state; TYPE_3__ ops; } ;
struct fm10k_hw_stat {scalar_t__ base_l; scalar_t__ base_h; int /*<<< orphan*/  count; } ;
struct fm10k_hw_stats_q {scalar_t__ tx_stats_idx; scalar_t__ rx_stats_idx; struct fm10k_hw_stat rx_bytes; struct fm10k_hw_stat rx_packets; struct fm10k_hw_stat rx_drops; struct fm10k_hw_stat tx_bytes; struct fm10k_hw_stat tx_packets; } ;
struct TYPE_5__ {void* payload; void* speed; void* width; } ;
struct TYPE_8__ {void* payload; void* speed; void* width; } ;
struct fm10k_hw {struct fm10k_mac_info mac; struct fm10k_mbx_info mbx; int /*<<< orphan*/  hw_addr; TYPE_1__ bus; TYPE_4__ bus_caps; } ;
typedef  int /*<<< orphan*/  s32 ;

/* Variables and functions */
 int FM10K_48_BIT_MASK ; 
 scalar_t__ FM10K_DGLORTMAP_NONE ; 
 int /*<<< orphan*/  FM10K_ERR_REQUESTS_PENDING ; 
 int /*<<< orphan*/  FM10K_ERR_RESET_REQUESTED ; 
 int FM10K_MAX_MSIX_VECTORS ; 
 int /*<<< orphan*/  FM10K_PCIE_DEV_CAP ; 
 int FM10K_PCIE_DEV_CAP_PAYLOAD ; 
#define  FM10K_PCIE_DEV_CAP_PAYLOAD_128 140 
#define  FM10K_PCIE_DEV_CAP_PAYLOAD_256 139 
#define  FM10K_PCIE_DEV_CAP_PAYLOAD_512 138 
 int /*<<< orphan*/  FM10K_PCIE_DEV_CTRL ; 
 int FM10K_PCIE_DEV_CTRL_PAYLOAD ; 
#define  FM10K_PCIE_DEV_CTRL_PAYLOAD_128 137 
#define  FM10K_PCIE_DEV_CTRL_PAYLOAD_256 136 
#define  FM10K_PCIE_DEV_CTRL_PAYLOAD_512 135 
 int /*<<< orphan*/  FM10K_PCIE_LINK_CAP ; 
 int FM10K_PCIE_LINK_SPEED ; 
#define  FM10K_PCIE_LINK_SPEED_2500 134 
#define  FM10K_PCIE_LINK_SPEED_5000 133 
#define  FM10K_PCIE_LINK_SPEED_8000 132 
 int /*<<< orphan*/  FM10K_PCIE_LINK_STATUS ; 
 int FM10K_PCIE_LINK_WIDTH ; 
#define  FM10K_PCIE_LINK_WIDTH_1 131 
#define  FM10K_PCIE_LINK_WIDTH_2 130 
#define  FM10K_PCIE_LINK_WIDTH_4 129 
#define  FM10K_PCIE_LINK_WIDTH_8 128 
 int /*<<< orphan*/  FM10K_PCI_MSIX_MSG_CTRL ; 
 int FM10K_PCI_MSIX_MSG_CTRL_TBL_SZ_MASK ; 
 scalar_t__ FM10K_QBRC_L (scalar_t__) ; 
 scalar_t__ FM10K_QBTC_L (scalar_t__) ; 
 scalar_t__ FM10K_QPRC (scalar_t__) ; 
 scalar_t__ FM10K_QPRDC (scalar_t__) ; 
 scalar_t__ FM10K_QPTC (scalar_t__) ; 
 int FM10K_QUEUE_DISABLE_TIMEOUT ; 
 scalar_t__ FM10K_REMOVED (int /*<<< orphan*/ ) ; 
 scalar_t__ FM10K_RXQCTL (scalar_t__) ; 
 scalar_t__ FM10K_RXQCTL_ENABLE ; 
 scalar_t__ FM10K_RXQCTL_ID_MASK ; 
 scalar_t__ FM10K_STATE_OPEN ; 
 scalar_t__ FM10K_STAT_VALID ; 
 scalar_t__ FM10K_TXDCTL (int) ; 
 scalar_t__ FM10K_TXDCTL_ENABLE ; 
 scalar_t__ FM10K_TXQCTL (scalar_t__) ; 
 scalar_t__ FM10K_TXQCTL_ID_MASK ; 
 void* fm10k_bus_payload_128 ; 
 void* fm10k_bus_payload_256 ; 
 void* fm10k_bus_payload_512 ; 
 void* fm10k_bus_payload_unknown ; 
 void* fm10k_bus_speed_2500 ; 
 void* fm10k_bus_speed_5000 ; 
 void* fm10k_bus_speed_8000 ; 
 void* fm10k_bus_speed_unknown ; 
 void* fm10k_bus_width_pcie_x1 ; 
 void* fm10k_bus_width_pcie_x2 ; 
 void* fm10k_bus_width_pcie_x4 ; 
 void* fm10k_bus_width_pcie_x8 ; 
 void* fm10k_bus_width_unknown ; 
 int fm10k_read_pci_cfg_word (struct fm10k_hw*,int /*<<< orphan*/ ) ; 
 scalar_t__ fm10k_read_reg (struct fm10k_hw*,scalar_t__) ; 
 int /*<<< orphan*/  fm10k_update_hw_base_32b (struct fm10k_hw_stat*,scalar_t__) ; 
 int /*<<< orphan*/  fm10k_write_flush (struct fm10k_hw*) ; 
 int /*<<< orphan*/  fm10k_write_reg (struct fm10k_hw*,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  stub1 (struct fm10k_hw*,struct fm10k_mbx_info*) ; 
 int /*<<< orphan*/  stub2 (struct fm10k_hw*) ; 
 int /*<<< orphan*/  udelay (int) ; 

s32 fm10k_get_bus_info_generic(struct fm10k_hw *hw)
{
	u16 link_cap, link_status, device_cap, device_control;

	/* Get the maximum link width and speed from PCIe config space */
	link_cap = fm10k_read_pci_cfg_word(hw, FM10K_PCIE_LINK_CAP);

	switch (link_cap & FM10K_PCIE_LINK_WIDTH) {
	case FM10K_PCIE_LINK_WIDTH_1:
		hw->bus_caps.width = fm10k_bus_width_pcie_x1;
		break;
	case FM10K_PCIE_LINK_WIDTH_2:
		hw->bus_caps.width = fm10k_bus_width_pcie_x2;
		break;
	case FM10K_PCIE_LINK_WIDTH_4:
		hw->bus_caps.width = fm10k_bus_width_pcie_x4;
		break;
	case FM10K_PCIE_LINK_WIDTH_8:
		hw->bus_caps.width = fm10k_bus_width_pcie_x8;
		break;
	default:
		hw->bus_caps.width = fm10k_bus_width_unknown;
		break;
	}

	switch (link_cap & FM10K_PCIE_LINK_SPEED) {
	case FM10K_PCIE_LINK_SPEED_2500:
		hw->bus_caps.speed = fm10k_bus_speed_2500;
		break;
	case FM10K_PCIE_LINK_SPEED_5000:
		hw->bus_caps.speed = fm10k_bus_speed_5000;
		break;
	case FM10K_PCIE_LINK_SPEED_8000:
		hw->bus_caps.speed = fm10k_bus_speed_8000;
		break;
	default:
		hw->bus_caps.speed = fm10k_bus_speed_unknown;
		break;
	}

	/* Get the PCIe maximum payload size for the PCIe function */
	device_cap = fm10k_read_pci_cfg_word(hw, FM10K_PCIE_DEV_CAP);

	switch (device_cap & FM10K_PCIE_DEV_CAP_PAYLOAD) {
	case FM10K_PCIE_DEV_CAP_PAYLOAD_128:
		hw->bus_caps.payload = fm10k_bus_payload_128;
		break;
	case FM10K_PCIE_DEV_CAP_PAYLOAD_256:
		hw->bus_caps.payload = fm10k_bus_payload_256;
		break;
	case FM10K_PCIE_DEV_CAP_PAYLOAD_512:
		hw->bus_caps.payload = fm10k_bus_payload_512;
		break;
	default:
		hw->bus_caps.payload = fm10k_bus_payload_unknown;
		break;
	}

	/* Get the negotiated link width and speed from PCIe config space */
	link_status = fm10k_read_pci_cfg_word(hw, FM10K_PCIE_LINK_STATUS);

	switch (link_status & FM10K_PCIE_LINK_WIDTH) {
	case FM10K_PCIE_LINK_WIDTH_1:
		hw->bus.width = fm10k_bus_width_pcie_x1;
		break;
	case FM10K_PCIE_LINK_WIDTH_2:
		hw->bus.width = fm10k_bus_width_pcie_x2;
		break;
	case FM10K_PCIE_LINK_WIDTH_4:
		hw->bus.width = fm10k_bus_width_pcie_x4;
		break;
	case FM10K_PCIE_LINK_WIDTH_8:
		hw->bus.width = fm10k_bus_width_pcie_x8;
		break;
	default:
		hw->bus.width = fm10k_bus_width_unknown;
		break;
	}

	switch (link_status & FM10K_PCIE_LINK_SPEED) {
	case FM10K_PCIE_LINK_SPEED_2500:
		hw->bus.speed = fm10k_bus_speed_2500;
		break;
	case FM10K_PCIE_LINK_SPEED_5000:
		hw->bus.speed = fm10k_bus_speed_5000;
		break;
	case FM10K_PCIE_LINK_SPEED_8000:
		hw->bus.speed = fm10k_bus_speed_8000;
		break;
	default:
		hw->bus.speed = fm10k_bus_speed_unknown;
		break;
	}

	/* Get the negotiated PCIe maximum payload size for the PCIe function */
	device_control = fm10k_read_pci_cfg_word(hw, FM10K_PCIE_DEV_CTRL);

	switch (device_control & FM10K_PCIE_DEV_CTRL_PAYLOAD) {
	case FM10K_PCIE_DEV_CTRL_PAYLOAD_128:
		hw->bus.payload = fm10k_bus_payload_128;
		break;
	case FM10K_PCIE_DEV_CTRL_PAYLOAD_256:
		hw->bus.payload = fm10k_bus_payload_256;
		break;
	case FM10K_PCIE_DEV_CTRL_PAYLOAD_512:
		hw->bus.payload = fm10k_bus_payload_512;
		break;
	default:
		hw->bus.payload = fm10k_bus_payload_unknown;
		break;
	}

	return 0;
}

__attribute__((used)) static u16 fm10k_get_pcie_msix_count_generic(struct fm10k_hw *hw)
{
	u16 msix_count;

	/* read in value from MSI-X capability register */
	msix_count = fm10k_read_pci_cfg_word(hw, FM10K_PCI_MSIX_MSG_CTRL);
	msix_count &= FM10K_PCI_MSIX_MSG_CTRL_TBL_SZ_MASK;

	/* MSI-X count is zero-based in HW */
	msix_count++;

	if (msix_count > FM10K_MAX_MSIX_VECTORS)
		msix_count = FM10K_MAX_MSIX_VECTORS;

	return msix_count;
}

s32 fm10k_get_invariants_generic(struct fm10k_hw *hw)
{
	struct fm10k_mac_info *mac = &hw->mac;

	/* initialize GLORT state to avoid any false hits */
	mac->dglort_map = FM10K_DGLORTMAP_NONE;

	/* record maximum number of MSI-X vectors */
	mac->max_msix_vectors = fm10k_get_pcie_msix_count_generic(hw);

	return 0;
}

s32 fm10k_start_hw_generic(struct fm10k_hw *hw)
{
	/* set flag indicating we are beginning Tx */
	hw->mac.tx_ready = true;

	return 0;
}

s32 fm10k_disable_queues_generic(struct fm10k_hw *hw, u16 q_cnt)
{
	u32 reg;
	u16 i, time;

	/* clear tx_ready to prevent any false hits for reset */
	hw->mac.tx_ready = false;

	if (FM10K_REMOVED(hw->hw_addr))
		return 0;

	/* clear the enable bit for all rings */
	for (i = 0; i < q_cnt; i++) {
		reg = fm10k_read_reg(hw, FM10K_TXDCTL(i));
		fm10k_write_reg(hw, FM10K_TXDCTL(i),
				reg & ~FM10K_TXDCTL_ENABLE);
		reg = fm10k_read_reg(hw, FM10K_RXQCTL(i));
		fm10k_write_reg(hw, FM10K_RXQCTL(i),
				reg & ~FM10K_RXQCTL_ENABLE);
	}

	fm10k_write_flush(hw);
	udelay(1);

	/* loop through all queues to verify that they are all disabled */
	for (i = 0, time = FM10K_QUEUE_DISABLE_TIMEOUT; time;) {
		/* if we are at end of rings all rings are disabled */
		if (i == q_cnt)
			return 0;

		/* if queue enables cleared, then move to next ring pair */
		reg = fm10k_read_reg(hw, FM10K_TXDCTL(i));
		if (!~reg || !(reg & FM10K_TXDCTL_ENABLE)) {
			reg = fm10k_read_reg(hw, FM10K_RXQCTL(i));
			if (!~reg || !(reg & FM10K_RXQCTL_ENABLE)) {
				i++;
				continue;
			}
		}

		/* decrement time and wait 1 usec */
		time--;
		if (time)
			udelay(1);
	}

	return FM10K_ERR_REQUESTS_PENDING;
}

s32 fm10k_stop_hw_generic(struct fm10k_hw *hw)
{
	return fm10k_disable_queues_generic(hw, hw->mac.max_queues);
}

u32 fm10k_read_hw_stats_32b(struct fm10k_hw *hw, u32 addr,
			    struct fm10k_hw_stat *stat)
{
	u32 delta = fm10k_read_reg(hw, addr) - stat->base_l;

	if (FM10K_REMOVED(hw->hw_addr))
		stat->base_h = 0;

	return delta;
}

__attribute__((used)) static u64 fm10k_read_hw_stats_48b(struct fm10k_hw *hw, u32 addr,
				   struct fm10k_hw_stat *stat)
{
	u32 count_l;
	u32 count_h;
	u32 count_tmp;
	u64 delta;

	count_h = fm10k_read_reg(hw, addr + 1);

	/* Check for overflow */
	do {
		count_tmp = count_h;
		count_l = fm10k_read_reg(hw, addr);
		count_h = fm10k_read_reg(hw, addr + 1);
	} while (count_h != count_tmp);

	delta = ((u64)(count_h - stat->base_h) << 32) + count_l;
	delta -= stat->base_l;

	return delta & FM10K_48_BIT_MASK;
}

__attribute__((used)) static void fm10k_update_hw_base_48b(struct fm10k_hw_stat *stat, u64 delta)
{
	if (!delta)
		return;

	/* update lower 32 bits */
	delta += stat->base_l;
	stat->base_l = (u32)delta;

	/* update upper 32 bits */
	stat->base_h += (u32)(delta >> 32);
}

__attribute__((used)) static void fm10k_update_hw_stats_tx_q(struct fm10k_hw *hw,
				       struct fm10k_hw_stats_q *q,
				       u32 idx)
{
	u32 id_tx, id_tx_prev, tx_packets;
	u64 tx_bytes = 0;

	/* Retrieve TX Owner Data */
	id_tx = fm10k_read_reg(hw, FM10K_TXQCTL(idx));

	/* Process TX Ring */
	do {
		tx_packets = fm10k_read_hw_stats_32b(hw, FM10K_QPTC(idx),
						     &q->tx_packets);

		if (tx_packets)
			tx_bytes = fm10k_read_hw_stats_48b(hw,
							   FM10K_QBTC_L(idx),
							   &q->tx_bytes);

		/* Re-Check Owner Data */
		id_tx_prev = id_tx;
		id_tx = fm10k_read_reg(hw, FM10K_TXQCTL(idx));
	} while ((id_tx ^ id_tx_prev) & FM10K_TXQCTL_ID_MASK);

	/* drop non-ID bits and set VALID ID bit */
	id_tx &= FM10K_TXQCTL_ID_MASK;
	id_tx |= FM10K_STAT_VALID;

	/* update packet counts */
	if (q->tx_stats_idx == id_tx) {
		q->tx_packets.count += tx_packets;
		q->tx_bytes.count += tx_bytes;
	}

	/* update bases and record ID */
	fm10k_update_hw_base_32b(&q->tx_packets, tx_packets);
	fm10k_update_hw_base_48b(&q->tx_bytes, tx_bytes);

	q->tx_stats_idx = id_tx;
}

__attribute__((used)) static void fm10k_update_hw_stats_rx_q(struct fm10k_hw *hw,
				       struct fm10k_hw_stats_q *q,
				       u32 idx)
{
	u32 id_rx, id_rx_prev, rx_packets, rx_drops;
	u64 rx_bytes = 0;

	/* Retrieve RX Owner Data */
	id_rx = fm10k_read_reg(hw, FM10K_RXQCTL(idx));

	/* Process RX Ring */
	do {
		rx_drops = fm10k_read_hw_stats_32b(hw, FM10K_QPRDC(idx),
						   &q->rx_drops);

		rx_packets = fm10k_read_hw_stats_32b(hw, FM10K_QPRC(idx),
						     &q->rx_packets);

		if (rx_packets)
			rx_bytes = fm10k_read_hw_stats_48b(hw,
							   FM10K_QBRC_L(idx),
							   &q->rx_bytes);

		/* Re-Check Owner Data */
		id_rx_prev = id_rx;
		id_rx = fm10k_read_reg(hw, FM10K_RXQCTL(idx));
	} while ((id_rx ^ id_rx_prev) & FM10K_RXQCTL_ID_MASK);

	/* drop non-ID bits and set VALID ID bit */
	id_rx &= FM10K_RXQCTL_ID_MASK;
	id_rx |= FM10K_STAT_VALID;

	/* update packet counts */
	if (q->rx_stats_idx == id_rx) {
		q->rx_drops.count += rx_drops;
		q->rx_packets.count += rx_packets;
		q->rx_bytes.count += rx_bytes;
	}

	/* update bases and record ID */
	fm10k_update_hw_base_32b(&q->rx_drops, rx_drops);
	fm10k_update_hw_base_32b(&q->rx_packets, rx_packets);
	fm10k_update_hw_base_48b(&q->rx_bytes, rx_bytes);

	q->rx_stats_idx = id_rx;
}

void fm10k_update_hw_stats_q(struct fm10k_hw *hw, struct fm10k_hw_stats_q *q,
			     u32 idx, u32 count)
{
	u32 i;

	for (i = 0; i < count; i++, idx++, q++) {
		fm10k_update_hw_stats_tx_q(hw, q, idx);
		fm10k_update_hw_stats_rx_q(hw, q, idx);
	}
}

void fm10k_unbind_hw_stats_q(struct fm10k_hw_stats_q *q, u32 idx, u32 count)
{
	u32 i;

	for (i = 0; i < count; i++, idx++, q++) {
		q->rx_stats_idx = 0;
		q->tx_stats_idx = 0;
	}
}

s32 fm10k_get_host_state_generic(struct fm10k_hw *hw, bool *host_ready)
{
	struct fm10k_mbx_info *mbx = &hw->mbx;
	struct fm10k_mac_info *mac = &hw->mac;
	s32 ret_val = 0;
	u32 txdctl = fm10k_read_reg(hw, FM10K_TXDCTL(0));

	/* process upstream mailbox in case interrupts were disabled */
	mbx->ops.process(hw, mbx);

	/* If Tx is no longer enabled link should come down */
	if (!(~txdctl) || !(txdctl & FM10K_TXDCTL_ENABLE))
		mac->get_host_state = true;

	/* exit if not checking for link, or link cannot be changed */
	if (!mac->get_host_state || !(~txdctl))
		goto out;

	/* if we somehow dropped the Tx enable we should reset */
	if (mac->tx_ready && !(txdctl & FM10K_TXDCTL_ENABLE)) {
		ret_val = FM10K_ERR_RESET_REQUESTED;
		goto out;
	}

	/* if Mailbox timed out we should request reset */
	if (!mbx->timeout) {
		ret_val = FM10K_ERR_RESET_REQUESTED;
		goto out;
	}

	/* verify Mailbox is still open */
	if (mbx->state != FM10K_STATE_OPEN)
		goto out;

	/* interface cannot receive traffic without logical ports */
	if (mac->dglort_map == FM10K_DGLORTMAP_NONE) {
		if (mac->ops.request_lport_map)
			ret_val = mac->ops.request_lport_map(hw);

		goto out;
	}

	/* if we passed all the tests above then the switch is ready and we no
	 * longer need to check for link
	 */
	mac->get_host_state = false;

out:
	*host_ready = !mac->get_host_state;
	return ret_val;
}

