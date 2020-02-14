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
struct scp_struct {scalar_t__ sysbus; void* iscp; } ;
struct scb_struct {int dummy; } ;
struct priv {unsigned long base; char* memtop; struct scb_struct* scb; scalar_t__ reseted; struct iscp_struct* iscp; struct scp_struct* scp; } ;
struct net_device {unsigned long mem_start; int /*<<< orphan*/  name; int /*<<< orphan*/  irq; } ;
struct iscp_struct {int busy; void* scb_base; int /*<<< orphan*/  scb_offset; } ;

/* Variables and functions */
 int /*<<< orphan*/  DELAY (int) ; 
 unsigned long SCP_DEFAULT_ADDRESS ; 
 scalar_t__ SYSBUSVAL ; 
static  void alloc586 (struct net_device*) ; 
 struct iscp_struct* dvma_btov (unsigned long) ; 
 int /*<<< orphan*/  free_irq (int /*<<< orphan*/ ,struct net_device*) ; 
 int /*<<< orphan*/  init586 (struct net_device*) ; 
 int /*<<< orphan*/  make16 (struct scb_struct*) ; 
 void* make24 (struct iscp_struct*) ; 
 int /*<<< orphan*/  memset (char*,int /*<<< orphan*/ ,int) ; 
 struct priv* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  netif_start_queue (struct net_device*) ; 
 int /*<<< orphan*/  netif_stop_queue (struct net_device*) ; 
 int /*<<< orphan*/  printk (char*,int /*<<< orphan*/ ) ; 
 int request_irq (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct net_device*) ; 
 int /*<<< orphan*/  startrecv586 (struct net_device*) ; 
 int /*<<< orphan*/  sun3_82586_interrupt ; 
 int /*<<< orphan*/  sun3_attn586 () ; 
 int /*<<< orphan*/  sun3_disint () ; 
 int /*<<< orphan*/  sun3_enaint () ; 
 int /*<<< orphan*/  sun3_reset586 () ; 

__attribute__((used)) static int sun3_82586_close(struct net_device *dev)
{
	free_irq(dev->irq, dev);

	sun3_reset586(); /* the hard way to stop the receiver */

	netif_stop_queue(dev);

	return 0;
}

__attribute__((used)) static int sun3_82586_open(struct net_device *dev)
{
	int ret;

	sun3_disint();
	alloc586(dev);
	init586(dev);
	startrecv586(dev);
	sun3_enaint();

	ret = request_irq(dev->irq, sun3_82586_interrupt,0,dev->name,dev);
	if (ret)
	{
		sun3_reset586();
		return ret;
	}

	netif_start_queue(dev);

	return 0; /* most done by init */
}

__attribute__((used)) static int check586(struct net_device *dev,char *where,unsigned size)
{
	struct priv pb;
	struct priv *p = &pb;
	char *iscp_addr;
	int i;

	p->base = (unsigned long) dvma_btov(0);
	p->memtop = (char *)dvma_btov((unsigned long)where);
	p->scp = (struct scp_struct *)(p->base + SCP_DEFAULT_ADDRESS);
	memset((char *)p->scp,0, sizeof(struct scp_struct));
	for(i=0;i<sizeof(struct scp_struct);i++) /* memory was writeable? */
		if(((char *)p->scp)[i])
			return 0;
	p->scp->sysbus = SYSBUSVAL;				/* 1 = 8Bit-Bus, 0 = 16 Bit */
	if(p->scp->sysbus != SYSBUSVAL)
		return 0;

	iscp_addr = (char *)dvma_btov((unsigned long)where);

	p->iscp = (struct iscp_struct *) iscp_addr;
	memset((char *)p->iscp,0, sizeof(struct iscp_struct));

	p->scp->iscp = make24(p->iscp);
	p->iscp->busy = 1;

	sun3_reset586();
	sun3_attn586();
	DELAY(1);	/* wait a while... */

	if(p->iscp->busy) /* i82586 clears 'busy' after successful init */
		return 0;

	return 1;
}

__attribute__((used)) static void alloc586(struct net_device *dev)
{
	struct priv *p = netdev_priv(dev);

	sun3_reset586();
	DELAY(1);

	p->scp	= (struct scp_struct *)	(p->base + SCP_DEFAULT_ADDRESS);
	p->iscp	= (struct iscp_struct *) dvma_btov(dev->mem_start);
	p->scb  = (struct scb_struct *)  ((char *)p->iscp + sizeof(struct iscp_struct));

	memset((char *) p->iscp,0,sizeof(struct iscp_struct));
	memset((char *) p->scp ,0,sizeof(struct scp_struct));

	p->scp->iscp = make24(p->iscp);
	p->scp->sysbus = SYSBUSVAL;
	p->iscp->scb_offset = make16(p->scb);
	p->iscp->scb_base = make24(dvma_btov(dev->mem_start));

	p->iscp->busy = 1;
	sun3_reset586();
	sun3_attn586();

	DELAY(1);

	if(p->iscp->busy)
		printk("%s: Init-Problems (alloc).\n",dev->name);

	p->reseted = 0;

	memset((char *)p->scb,0,sizeof(struct scb_struct));
}

