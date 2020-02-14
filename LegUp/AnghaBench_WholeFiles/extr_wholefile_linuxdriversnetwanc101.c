#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_7__ ;
typedef  struct TYPE_18__   TYPE_2__ ;
typedef  struct TYPE_17__   TYPE_1__ ;
typedef  struct TYPE_16__   TYPE_13__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u16 ;
struct net_device {int dummy; } ;
struct TYPE_17__ {struct net_device* dev; } ;
typedef  TYPE_1__ port_t ;
typedef  int /*<<< orphan*/  pkt_desc ;
struct TYPE_18__ {int page; scalar_t__ win0base; } ;
typedef  TYPE_2__ card_t ;
struct TYPE_19__ {int tx_ring_buffers; int rx_ring_buffers; } ;
struct TYPE_16__ {TYPE_1__* priv; } ;

/* Variables and functions */
 scalar_t__ C101_PAGE ; 
 int DSR_EOM ; 
 int /*<<< orphan*/  DSR_TX (int) ; 
 int /*<<< orphan*/  ISR0 ; 
 int /*<<< orphan*/  ISR1 ; 
 int SCA_INTR_DMAC_RX (int) ; 
 int SCA_INTR_DMAC_TX (int) ; 
 int SCA_INTR_MSCI (int) ; 
 TYPE_13__* dev_to_hdlc (struct net_device*) ; 
 int log_node (TYPE_1__*) ; 
 TYPE_7__* port_to_card (TYPE_1__*) ; 
 int sca_in (int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  writeb (int,scalar_t__) ; 

__attribute__((used)) static inline u8 sca_get_page(card_t *card)
{
	return card->page;
}

__attribute__((used)) static inline void openwin(card_t *card, u8 page)
{
	card->page = page;
	writeb(page, card->win0base + C101_PAGE);
}

__attribute__((used)) static inline struct net_device *port_to_dev(port_t *port)
{
	return port->dev;
}

__attribute__((used)) static inline int sca_intr_status(card_t *card)
{
	u8 result = 0;
	u8 isr0 = sca_in(ISR0, card);
	u8 isr1 = sca_in(ISR1, card);

	if (isr1 & 0x03) result |= SCA_INTR_DMAC_RX(0);
	if (isr1 & 0x0C) result |= SCA_INTR_DMAC_TX(0);
	if (isr1 & 0x30) result |= SCA_INTR_DMAC_RX(1);
	if (isr1 & 0xC0) result |= SCA_INTR_DMAC_TX(1);
	if (isr0 & 0x0F) result |= SCA_INTR_MSCI(0);
	if (isr0 & 0xF0) result |= SCA_INTR_MSCI(1);

	if (!(result & SCA_INTR_DMAC_TX(0)))
		if (sca_in(DSR_TX(0), card) & DSR_EOM)
			result |= SCA_INTR_DMAC_TX(0);
	if (!(result & SCA_INTR_DMAC_TX(1)))
		if (sca_in(DSR_TX(1), card) & DSR_EOM)
			result |= SCA_INTR_DMAC_TX(1);

	return result;
}

__attribute__((used)) static inline port_t* dev_to_port(struct net_device *dev)
{
	return dev_to_hdlc(dev)->priv;
}

__attribute__((used)) static inline u16 next_desc(port_t *port, u16 desc, int transmit)
{
	return (desc + 1) % (transmit ? port_to_card(port)->tx_ring_buffers
			     : port_to_card(port)->rx_ring_buffers);
}

__attribute__((used)) static inline u16 desc_abs_number(port_t *port, u16 desc, int transmit)
{
	u16 rx_buffs = port_to_card(port)->rx_ring_buffers;
	u16 tx_buffs = port_to_card(port)->tx_ring_buffers;

	desc %= (transmit ? tx_buffs : rx_buffs); // called with "X + 1" etc.
	return log_node(port) * (rx_buffs + tx_buffs) +
		transmit * rx_buffs + desc;
}

__attribute__((used)) static inline u16 desc_offset(port_t *port, u16 desc, int transmit)
{
	/* Descriptor offset always fits in 16 bits */
	return desc_abs_number(port, desc, transmit) * sizeof(pkt_desc);
}

