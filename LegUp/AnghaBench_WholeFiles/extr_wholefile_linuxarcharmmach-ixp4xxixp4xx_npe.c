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
typedef  int u32 ;
struct npe {TYPE_1__* regs; } ;
struct TYPE_2__ {int /*<<< orphan*/  exec_status_cmd; int /*<<< orphan*/  exec_data; int /*<<< orphan*/  exec_addr; } ;

/* Variables and functions */
 int CMD_NPE_CLR_PIPE ; 
 int CMD_NPE_START ; 
 int CMD_NPE_STOP ; 
 int CMD_RD_ECS_REG ; 
 int CMD_WR_ECS_REG ; 
 int ECS_DBG_CTXT_REG_0 ; 
 int ECS_PRI_1_CTXT_REG_0 ; 
 int ECS_PRI_2_CTXT_REG_0 ; 
 int ECS_REG_0_ACTIVE ; 
 int STAT_RUN ; 
 int __raw_readl (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  __raw_writel (int,int /*<<< orphan*/ *) ; 

int npe_running(struct npe *npe)
{
	return (__raw_readl(&npe->regs->exec_status_cmd) & STAT_RUN) != 0;
}

__attribute__((used)) static void npe_cmd_write(struct npe *npe, u32 addr, int cmd, u32 data)
{
	__raw_writel(data, &npe->regs->exec_data);
	__raw_writel(addr, &npe->regs->exec_addr);
	__raw_writel(cmd, &npe->regs->exec_status_cmd);
}

__attribute__((used)) static u32 npe_cmd_read(struct npe *npe, u32 addr, int cmd)
{
	__raw_writel(addr, &npe->regs->exec_addr);
	__raw_writel(cmd, &npe->regs->exec_status_cmd);
	/* Iintroduce extra read cycles after issuing read command to NPE
	   so that we read the register after the NPE has updated it.
	   This is to overcome race condition between XScale and NPE */
	__raw_readl(&npe->regs->exec_data);
	__raw_readl(&npe->regs->exec_data);
	return __raw_readl(&npe->regs->exec_data);
}

__attribute__((used)) static void npe_clear_active(struct npe *npe, u32 reg)
{
	u32 val = npe_cmd_read(npe, reg, CMD_RD_ECS_REG);
	npe_cmd_write(npe, reg, CMD_WR_ECS_REG, val & ~ECS_REG_0_ACTIVE);
}

__attribute__((used)) static void npe_start(struct npe *npe)
{
	/* ensure only Background Context Stack Level is active */
	npe_clear_active(npe, ECS_PRI_1_CTXT_REG_0);
	npe_clear_active(npe, ECS_PRI_2_CTXT_REG_0);
	npe_clear_active(npe, ECS_DBG_CTXT_REG_0);

	__raw_writel(CMD_NPE_CLR_PIPE, &npe->regs->exec_status_cmd);
	__raw_writel(CMD_NPE_START, &npe->regs->exec_status_cmd);
}

__attribute__((used)) static void npe_stop(struct npe *npe)
{
	__raw_writel(CMD_NPE_STOP, &npe->regs->exec_status_cmd);
	__raw_writel(CMD_NPE_CLR_PIPE, &npe->regs->exec_status_cmd); /*FIXME?*/
}

