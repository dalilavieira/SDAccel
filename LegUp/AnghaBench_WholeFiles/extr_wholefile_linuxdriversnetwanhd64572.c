#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_7__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int u16 ;
struct net_device {int dummy; } ;
struct TYPE_10__ {int chan; TYPE_2__* card; } ;
typedef  TYPE_1__ port_t ;
typedef  int /*<<< orphan*/  pkt_desc ;
struct TYPE_12__ {TYPE_1__* priv; } ;
struct TYPE_11__ {int rx_ring_buffers; int tx_ring_buffers; } ;

/* Variables and functions */
 int /*<<< orphan*/  IER0 ; 
 TYPE_7__* dev_to_hdlc (struct net_device*) ; 
 int sca_inl (int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  sca_outl (int,int /*<<< orphan*/ ,TYPE_2__*) ; 

__attribute__((used)) static inline port_t* dev_to_port(struct net_device *dev)
{
	return dev_to_hdlc(dev)->priv;
}

__attribute__((used)) static inline void enable_intr(port_t *port)
{
	/* enable DMIB and MSCI RXINTA interrupts */
	sca_outl(sca_inl(IER0, port->card) |
		 (port->chan ? 0x08002200 : 0x00080022), IER0, port->card);
}

__attribute__((used)) static inline void disable_intr(port_t *port)
{
	sca_outl(sca_inl(IER0, port->card) &
		 (port->chan ? 0x00FF00FF : 0xFF00FF00), IER0, port->card);
}

__attribute__((used)) static inline u16 desc_abs_number(port_t *port, u16 desc, int transmit)
{
	u16 rx_buffs = port->card->rx_ring_buffers;
	u16 tx_buffs = port->card->tx_ring_buffers;

	desc %= (transmit ? tx_buffs : rx_buffs); // called with "X + 1" etc.
	return port->chan * (rx_buffs + tx_buffs) + transmit * rx_buffs + desc;
}

__attribute__((used)) static inline u16 desc_offset(port_t *port, u16 desc, int transmit)
{
	/* Descriptor offset always fits in 16 bits */
	return desc_abs_number(port, desc, transmit) * sizeof(pkt_desc);
}

