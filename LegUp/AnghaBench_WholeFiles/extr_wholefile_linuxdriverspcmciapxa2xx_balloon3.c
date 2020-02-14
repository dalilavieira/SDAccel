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
typedef  int uint16_t ;
struct TYPE_5__ {int /*<<< orphan*/  pci_irq; } ;
struct soc_pcmcia_socket {size_t nr; TYPE_2__* stat; TYPE_1__ socket; } ;
struct pcmcia_state {int ready; int bvd1; int vs_3v; scalar_t__ vs_Xv; scalar_t__ bvd2; } ;
struct TYPE_7__ {int flags; } ;
typedef  TYPE_3__ socket_state_t ;
struct TYPE_6__ {char* name; int /*<<< orphan*/  irq; int /*<<< orphan*/  gpio; } ;

/* Variables and functions */
 int /*<<< orphan*/  BALLOON3_BP_CF_NRDY_IRQ ; 
 int /*<<< orphan*/  BALLOON3_BP_NSTSCHG_IRQ ; 
 scalar_t__ BALLOON3_CF_CONTROL_REG ; 
 int /*<<< orphan*/  BALLOON3_CF_RESET ; 
 int /*<<< orphan*/  BALLOON3_CF_STATUS_REG ; 
 int BALLOON3_CF_nIRQ ; 
 int BALLOON3_CF_nSTSCHG_BVD1 ; 
 int /*<<< orphan*/  BALLOON3_FPGA_SETnCLR ; 
 int /*<<< orphan*/  BALLOON3_FPGA_VER ; 
 int /*<<< orphan*/  BALLOON3_GPIO_S0_CD ; 
 size_t SOC_STAT_BVD1 ; 
 size_t SOC_STAT_CD ; 
 int SS_RESET ; 
 int __raw_readw (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writew (int /*<<< orphan*/ ,scalar_t__) ; 
 int* balloon3_pcmcia_status ; 
 int /*<<< orphan*/  disable_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  enable_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_warn (char*,int) ; 

__attribute__((used)) static int balloon3_pcmcia_hw_init(struct soc_pcmcia_socket *skt)
{
	uint16_t ver;

	ver = __raw_readw(BALLOON3_FPGA_VER);
	if (ver < 0x4f08)
		pr_warn("The FPGA code, version 0x%04x, is too old. "
			"PCMCIA/CF support might be broken in this version!",
			ver);

	skt->socket.pci_irq = BALLOON3_BP_CF_NRDY_IRQ;
	skt->stat[SOC_STAT_CD].gpio = BALLOON3_GPIO_S0_CD;
	skt->stat[SOC_STAT_CD].name = "PCMCIA0 CD";
	skt->stat[SOC_STAT_BVD1].irq = BALLOON3_BP_NSTSCHG_IRQ;
	skt->stat[SOC_STAT_BVD1].name = "PCMCIA0 STSCHG";

	return 0;
}

__attribute__((used)) static void balloon3_pcmcia_socket_state(struct soc_pcmcia_socket *skt,
				    struct pcmcia_state *state)
{
	uint16_t status;
	int flip;

	/* This actually reads the STATUS register */
	status = __raw_readw(BALLOON3_CF_STATUS_REG);
	flip = (status ^ balloon3_pcmcia_status[skt->nr])
		& BALLOON3_CF_nSTSCHG_BVD1;
	/*
	 * Workaround for STSCHG which can't be deasserted:
	 * We therefore disable/enable corresponding IRQs
	 * as needed to avoid IRQ locks.
	 */
	if (flip) {
		balloon3_pcmcia_status[skt->nr] = status;
		if (status & BALLOON3_CF_nSTSCHG_BVD1)
			enable_irq(BALLOON3_BP_NSTSCHG_IRQ);
		else
			disable_irq(BALLOON3_BP_NSTSCHG_IRQ);
	}

	state->ready	= !!(status & BALLOON3_CF_nIRQ);
	state->bvd1	= !!(status & BALLOON3_CF_nSTSCHG_BVD1);
	state->bvd2	= 0;	/* not available */
	state->vs_3v	= 1;	/* Always true its a CF card */
	state->vs_Xv	= 0;	/* not available */
}

__attribute__((used)) static int balloon3_pcmcia_configure_socket(struct soc_pcmcia_socket *skt,
				       const socket_state_t *state)
{
	__raw_writew(BALLOON3_CF_RESET, BALLOON3_CF_CONTROL_REG +
			((state->flags & SS_RESET) ?
			BALLOON3_FPGA_SETnCLR : 0));
	return 0;
}

