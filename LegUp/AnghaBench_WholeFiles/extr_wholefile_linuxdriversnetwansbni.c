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
typedef  unsigned char u_char ;
typedef  unsigned char u8 ;
typedef  int /*<<< orphan*/  u32 ;
struct timer_list {scalar_t__ expires; } ;
struct sbni_in_stats {int dummy; } ;
struct sbni_flags {int slow_mode; size_t rxl; int fixed_rxl; int /*<<< orphan*/  rate; int /*<<< orphan*/  mac_addr; } ;
struct TYPE_2__ {int /*<<< orphan*/  rate; void* rxl; } ;
struct net_local {int state; int delta_rxl; int cur_rxl_index; scalar_t__ cur_rxl_rcvd; scalar_t__ prev_rxl_rcvd; size_t timeout_rxl; int /*<<< orphan*/  lock; TYPE_1__ csr1; struct sbni_flags in_stats; struct timer_list watchdog; struct net_device* second; struct net_device* watchdog_dev; scalar_t__ framelen; scalar_t__ tx_frameno; scalar_t__ wait_frameno; scalar_t__ outpos; scalar_t__ inppos; int /*<<< orphan*/  timer_ticks; } ;
struct net_device_stats {int dummy; } ;
struct net_device {int base_addr; scalar_t__ irq; int flags; int /*<<< orphan*/  dev_addr; int /*<<< orphan*/  name; struct sbni_flags stats; } ;
struct ifreq {int /*<<< orphan*/  ifr_ifru; int /*<<< orphan*/  ifr_data; } ;

/* Variables and functions */
 unsigned char BU_EMP ; 
 int /*<<< orphan*/  CAP_NET_ADMIN ; 
 int /*<<< orphan*/  CHANGE_LEVEL_START_TICKS ; 
 int /*<<< orphan*/  CRC32 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int CSR0 ; 
 int CSR1 ; 
 size_t DEF_RXL ; 
 size_t DEF_RXL_DELTA ; 
 int EAGAIN ; 
 int EBUSY ; 
 int EFAULT ; 
 int ENODEV ; 
 unsigned char EN_INT ; 
 int EOPNOTSUPP ; 
 int EPERM ; 
 int FL_NEED_RESEND ; 
 int FL_PREV_OK ; 
 int FL_SECONDARY ; 
 int FL_SLOW_MODE ; 
 int FL_WAIT_ACK ; 
 int IFF_UP ; 
 int /*<<< orphan*/  IRQF_SHARED ; 
 unsigned char PR_RES ; 
 int SBNI_MAX_NUM_CARDS ; 
 scalar_t__ SBNI_TIMEOUT ; 
#define  SIOCDEVGETINSTATS 131 
#define  SIOCDEVGHWSTATE 130 
#define  SIOCDEVRESINSTATS 129 
#define  SIOCDEVSHWSTATE 128 
 int VALID_DECODER ; 
 int /*<<< orphan*/  add_timer (struct timer_list*) ; 
 int /*<<< orphan*/  capable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  copy_to_user (int /*<<< orphan*/ ,struct sbni_flags*,int) ; 
 int /*<<< orphan*/  del_timer (struct timer_list*) ; 
 int /*<<< orphan*/  drop_xmit_queue (struct net_device*) ; 
 int /*<<< orphan*/  free_irq (scalar_t__,struct net_device*) ; 
 unsigned char inb (int) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  memset (struct sbni_flags*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  netdev_err (struct net_device*,char*,scalar_t__) ; 
 int /*<<< orphan*/  netdev_notice (struct net_device*,char*,int /*<<< orphan*/ ) ; 
 struct net_local* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  netif_start_queue (struct net_device*) ; 
 int /*<<< orphan*/  netif_stop_queue (struct net_device*) ; 
 int /*<<< orphan*/  outb (unsigned char,int) ; 
 scalar_t__ request_irq (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct net_device*) ; 
 void** rxl_tab ; 
 struct net_device** sbni_cards ; 
 int /*<<< orphan*/  sbni_interrupt ; 
 int /*<<< orphan*/  sbni_watchdog ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 size_t* timeout_rxl_tab ; 
 int /*<<< orphan*/  timer_setup (struct timer_list*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
card_start( struct net_device  *dev )
{
	struct net_local  *nl = netdev_priv(dev);

	nl->timer_ticks = CHANGE_LEVEL_START_TICKS;
	nl->state &= ~(FL_WAIT_ACK | FL_NEED_RESEND);
	nl->state |= FL_PREV_OK;

	nl->inppos = nl->outpos = 0;
	nl->wait_frameno = 0;
	nl->tx_frameno	 = 0;
	nl->framelen	 = 0;

	outb( *(u_char *)&nl->csr1 | PR_RES, dev->base_addr + CSR1 );
	outb( EN_INT, dev->base_addr + CSR0 );
}

__attribute__((used)) static void
change_level( struct net_device  *dev )
{
	struct net_local  *nl = netdev_priv(dev);

	if( nl->delta_rxl == 0 )	/* do not auto-negotiate RxL */
		return;

	if( nl->cur_rxl_index == 0 )
		nl->delta_rxl = 1;
	else if( nl->cur_rxl_index == 15 )
		nl->delta_rxl = -1;
	else if( nl->cur_rxl_rcvd < nl->prev_rxl_rcvd )
		nl->delta_rxl = -nl->delta_rxl;

	nl->csr1.rxl = rxl_tab[ nl->cur_rxl_index += nl->delta_rxl ];
	inb( dev->base_addr + CSR0 );	/* needs for PCI cards */
	outb( *(u8 *)&nl->csr1, dev->base_addr + CSR1 );

	nl->prev_rxl_rcvd = nl->cur_rxl_rcvd;
	nl->cur_rxl_rcvd  = 0;
}

__attribute__((used)) static void
timeout_change_level( struct net_device  *dev )
{
	struct net_local  *nl = netdev_priv(dev);

	nl->cur_rxl_index = timeout_rxl_tab[ nl->timeout_rxl ];
	if( ++nl->timeout_rxl >= 4 )
		nl->timeout_rxl = 0;

	nl->csr1.rxl = rxl_tab[ nl->cur_rxl_index ];
	inb( dev->base_addr + CSR0 );
	outb( *(unsigned char *)&nl->csr1, dev->base_addr + CSR1 );

	nl->prev_rxl_rcvd = nl->cur_rxl_rcvd;
	nl->cur_rxl_rcvd  = 0;
}

__attribute__((used)) static int
sbni_open( struct net_device  *dev )
{
	struct net_local	*nl = netdev_priv(dev);
	struct timer_list	*w  = &nl->watchdog;

	/*
	 * For double ISA adapters within "common irq" mode, we have to
	 * determine whether primary or secondary channel is initialized,
	 * and set the irq handler only in first case.
	 */
	if( dev->base_addr < 0x400 ) {		/* ISA only */
		struct net_device  **p = sbni_cards;
		for( ;  *p  &&  p < sbni_cards + SBNI_MAX_NUM_CARDS;  ++p )
			if( (*p)->irq == dev->irq &&
			    ((*p)->base_addr == dev->base_addr + 4 ||
			     (*p)->base_addr == dev->base_addr - 4) &&
			    (*p)->flags & IFF_UP ) {

				((struct net_local *) (netdev_priv(*p)))
					->second = dev;
				netdev_notice(dev, "using shared irq with %s\n",
					      (*p)->name);
				nl->state |= FL_SECONDARY;
				goto  handler_attached;
			}
	}

	if( request_irq(dev->irq, sbni_interrupt, IRQF_SHARED, dev->name, dev) ) {
		netdev_err(dev, "unable to get IRQ %d\n", dev->irq);
		return  -EAGAIN;
	}

handler_attached:

	spin_lock( &nl->lock );
	memset( &dev->stats, 0, sizeof(struct net_device_stats) );
	memset( &nl->in_stats, 0, sizeof(struct sbni_in_stats) );

	card_start( dev );

	netif_start_queue( dev );

	/* set timer watchdog */
	nl->watchdog_dev = dev;
	timer_setup(w, sbni_watchdog, 0);
	w->expires	= jiffies + SBNI_TIMEOUT;
	add_timer( w );
   
	spin_unlock( &nl->lock );
	return 0;
}

__attribute__((used)) static int
sbni_close( struct net_device  *dev )
{
	struct net_local  *nl = netdev_priv(dev);

	if( nl->second  &&  nl->second->flags & IFF_UP ) {
		netdev_notice(dev, "Secondary channel (%s) is active!\n",
			      nl->second->name);
		return  -EBUSY;
	}

#ifdef CONFIG_SBNI_MULTILINE
	if( nl->state & FL_SLAVE )
		emancipate( dev );
	else
		while( nl->link )	/* it's master device! */
			emancipate( nl->link );
#endif

	spin_lock( &nl->lock );

	nl->second = NULL;
	drop_xmit_queue( dev );	
	netif_stop_queue( dev );
   
	del_timer( &nl->watchdog );

	outb( 0, dev->base_addr + CSR0 );

	if( !(nl->state & FL_SECONDARY) )
		free_irq( dev->irq, dev );
	nl->state &= FL_SECONDARY;

	spin_unlock( &nl->lock );
	return 0;
}

__attribute__((used)) static int
sbni_card_probe( unsigned long  ioaddr )
{
	unsigned char  csr0;

	csr0 = inb( ioaddr + CSR0 );
	if( csr0 != 0xff  &&  csr0 != 0x00 ) {
		csr0 &= ~EN_INT;
		if( csr0 & BU_EMP )
			csr0 |= EN_INT;
      
		if( VALID_DECODER & (1 << (csr0 >> 4)) )
			return  0;
	}
   
	return  -ENODEV;
}

__attribute__((used)) static int
sbni_ioctl( struct net_device  *dev,  struct ifreq  *ifr,  int  cmd )
{
	struct net_local  *nl = netdev_priv(dev);
	struct sbni_flags  flags;
	int  error = 0;

#ifdef CONFIG_SBNI_MULTILINE
	struct net_device  *slave_dev;
	char  slave_name[ 8 ];
#endif
  
	switch( cmd ) {
	case  SIOCDEVGETINSTATS :
		if (copy_to_user( ifr->ifr_data, &nl->in_stats,
					sizeof(struct sbni_in_stats) ))
			error = -EFAULT;
		break;

	case  SIOCDEVRESINSTATS :
		if (!capable(CAP_NET_ADMIN))
			return  -EPERM;
		memset( &nl->in_stats, 0, sizeof(struct sbni_in_stats) );
		break;

	case  SIOCDEVGHWSTATE :
		flags.mac_addr	= *(u32 *)(dev->dev_addr + 3);
		flags.rate	= nl->csr1.rate;
		flags.slow_mode	= (nl->state & FL_SLOW_MODE) != 0;
		flags.rxl	= nl->cur_rxl_index;
		flags.fixed_rxl	= nl->delta_rxl == 0;

		if (copy_to_user( ifr->ifr_data, &flags, sizeof flags ))
			error = -EFAULT;
		break;

	case  SIOCDEVSHWSTATE :
		if (!capable(CAP_NET_ADMIN))
			return  -EPERM;

		spin_lock( &nl->lock );
		flags = *(struct sbni_flags*) &ifr->ifr_ifru;
		if( flags.fixed_rxl )
			nl->delta_rxl = 0,
			nl->cur_rxl_index = flags.rxl;
		else
			nl->delta_rxl = DEF_RXL_DELTA,
			nl->cur_rxl_index = DEF_RXL;

		nl->csr1.rxl = rxl_tab[ nl->cur_rxl_index ];
		nl->csr1.rate = flags.rate;
		outb( *(u8 *)&nl->csr1 | PR_RES, dev->base_addr + CSR1 );
		spin_unlock( &nl->lock );
		break;

#ifdef CONFIG_SBNI_MULTILINE

	case  SIOCDEVENSLAVE :
		if (!capable(CAP_NET_ADMIN))
			return  -EPERM;

		if (copy_from_user( slave_name, ifr->ifr_data, sizeof slave_name ))
			return -EFAULT;
		slave_dev = dev_get_by_name(&init_net, slave_name );
		if( !slave_dev  ||  !(slave_dev->flags & IFF_UP) ) {
			netdev_err(dev, "trying to enslave non-active device %s\n",
				   slave_name);
			if (slave_dev)
				dev_put(slave_dev);
			return  -EPERM;
		}

		return  enslave( dev, slave_dev );

	case  SIOCDEVEMANSIPATE :
		if (!capable(CAP_NET_ADMIN))
			return  -EPERM;

		return  emancipate( dev );

#endif	/* CONFIG_SBNI_MULTILINE */

	default :
		return  -EOPNOTSUPP;
	}

	return  error;
}

__attribute__((used)) static void
set_multicast_list( struct net_device  *dev )
{
	return;		/* sbni always operate in promiscuos mode */
}

__attribute__((used)) static u32
calc_crc32( u32  crc,  u8  *p,  u32  len )
{
	while( len-- )
		crc = CRC32( *p++, crc );

	return  crc;
}

