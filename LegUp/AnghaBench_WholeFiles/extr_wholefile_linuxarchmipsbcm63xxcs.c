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
typedef  unsigned int u32 ;

/* Variables and functions */
 int EINVAL ; 
 unsigned int MPI_CSBASE_BASE_MASK ; 
 int /*<<< orphan*/  MPI_CSBASE_REG (unsigned int) ; 
 unsigned int MPI_CSBASE_SIZE_SHIFT ; 
 unsigned int MPI_CSCTL_DATA16_MASK ; 
 unsigned int MPI_CSCTL_ENABLE_MASK ; 
 unsigned int MPI_CSCTL_ENDIANSWAP_MASK ; 
 unsigned int MPI_CSCTL_HOLD_MASK ; 
 unsigned int MPI_CSCTL_HOLD_SHIFT ; 
 int /*<<< orphan*/  MPI_CSCTL_REG (unsigned int) ; 
 unsigned int MPI_CSCTL_SETUP_MASK ; 
 unsigned int MPI_CSCTL_SETUP_SHIFT ; 
 unsigned int MPI_CSCTL_SYNCMODE_MASK ; 
 unsigned int MPI_CSCTL_TSIZE_MASK ; 
 unsigned int MPI_CSCTL_WAIT_MASK ; 
 unsigned int MPI_CSCTL_WAIT_SHIFT ; 
 unsigned int MPI_CS_PCMCIA_ATTR ; 
 unsigned int MPI_CS_PCMCIA_COMMON ; 
 unsigned int MPI_CS_PCMCIA_IO ; 
 int /*<<< orphan*/  bcm63xx_cs_lock ; 
 unsigned int bcm_mpi_readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bcm_mpi_writel (unsigned int,int /*<<< orphan*/ ) ; 
 unsigned int ilog2 (int) ; 
 unsigned int roundup_pow_of_two (unsigned int) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static int is_valid_cs(unsigned int cs)
{
	if (cs > 6)
		return 0;
	return 1;
}

int bcm63xx_set_cs_base(unsigned int cs, u32 base, unsigned int size)
{
	unsigned long flags;
	u32 val;

	if (!is_valid_cs(cs))
		return -EINVAL;

	/* sanity check on size */
	if (size != roundup_pow_of_two(size))
		return -EINVAL;

	if (size < 8 * 1024 || size > 256 * 1024 * 1024)
		return -EINVAL;

	val = (base & MPI_CSBASE_BASE_MASK);
	/* 8k => 0 - 256M => 15 */
	val |= (ilog2(size) - ilog2(8 * 1024)) << MPI_CSBASE_SIZE_SHIFT;

	spin_lock_irqsave(&bcm63xx_cs_lock, flags);
	bcm_mpi_writel(val, MPI_CSBASE_REG(cs));
	spin_unlock_irqrestore(&bcm63xx_cs_lock, flags);

	return 0;
}

int bcm63xx_set_cs_timing(unsigned int cs, unsigned int wait,
			   unsigned int setup, unsigned int hold)
{
	unsigned long flags;
	u32 val;

	if (!is_valid_cs(cs))
		return -EINVAL;

	spin_lock_irqsave(&bcm63xx_cs_lock, flags);
	val = bcm_mpi_readl(MPI_CSCTL_REG(cs));
	val &= ~(MPI_CSCTL_WAIT_MASK);
	val &= ~(MPI_CSCTL_SETUP_MASK);
	val &= ~(MPI_CSCTL_HOLD_MASK);
	val |= wait << MPI_CSCTL_WAIT_SHIFT;
	val |= setup << MPI_CSCTL_SETUP_SHIFT;
	val |= hold << MPI_CSCTL_HOLD_SHIFT;
	bcm_mpi_writel(val, MPI_CSCTL_REG(cs));
	spin_unlock_irqrestore(&bcm63xx_cs_lock, flags);

	return 0;
}

int bcm63xx_set_cs_param(unsigned int cs, u32 params)
{
	unsigned long flags;
	u32 val;

	if (!is_valid_cs(cs))
		return -EINVAL;

	/* none of this fields apply to pcmcia */
	if (cs == MPI_CS_PCMCIA_COMMON ||
	    cs == MPI_CS_PCMCIA_ATTR ||
	    cs == MPI_CS_PCMCIA_IO)
		return -EINVAL;

	spin_lock_irqsave(&bcm63xx_cs_lock, flags);
	val = bcm_mpi_readl(MPI_CSCTL_REG(cs));
	val &= ~(MPI_CSCTL_DATA16_MASK);
	val &= ~(MPI_CSCTL_SYNCMODE_MASK);
	val &= ~(MPI_CSCTL_TSIZE_MASK);
	val &= ~(MPI_CSCTL_ENDIANSWAP_MASK);
	val |= params;
	bcm_mpi_writel(val, MPI_CSCTL_REG(cs));
	spin_unlock_irqrestore(&bcm63xx_cs_lock, flags);

	return 0;
}

int bcm63xx_set_cs_status(unsigned int cs, int enable)
{
	unsigned long flags;
	u32 val;

	if (!is_valid_cs(cs))
		return -EINVAL;

	spin_lock_irqsave(&bcm63xx_cs_lock, flags);
	val = bcm_mpi_readl(MPI_CSCTL_REG(cs));
	if (enable)
		val |= MPI_CSCTL_ENABLE_MASK;
	else
		val &= ~MPI_CSCTL_ENABLE_MASK;
	bcm_mpi_writel(val, MPI_CSCTL_REG(cs));
	spin_unlock_irqrestore(&bcm63xx_cs_lock, flags);
	return 0;
}

