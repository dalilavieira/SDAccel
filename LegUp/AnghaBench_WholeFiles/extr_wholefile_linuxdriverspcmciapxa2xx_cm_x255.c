#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct soc_pcmcia_socket {scalar_t__ nr; TYPE_1__* stat; } ;
struct pcmcia_state {scalar_t__ vs_Xv; scalar_t__ vs_3v; } ;
struct TYPE_5__ {int flags; } ;
typedef  TYPE_2__ socket_state_t ;
struct TYPE_4__ {char* name; int /*<<< orphan*/  gpio; } ;

/* Variables and functions */
 int /*<<< orphan*/  GPIO_PCMCIA_RESET ; 
 int /*<<< orphan*/  GPIO_PCMCIA_S0_CD_VALID ; 
 int /*<<< orphan*/  GPIO_PCMCIA_S0_RDYINT ; 
 int /*<<< orphan*/  GPIO_PCMCIA_S1_CD_VALID ; 
 int /*<<< orphan*/  GPIO_PCMCIA_S1_RDYINT ; 
 int /*<<< orphan*/  GPIO_PCMCIA_SKTSEL ; 
 size_t SOC_STAT_CD ; 
 size_t SOC_STAT_RDY ; 
 int SS_RESET ; 
 int /*<<< orphan*/  gpio_direction_output (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_free (int /*<<< orphan*/ ) ; 
 int gpio_request (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static int cmx255_pcmcia_hw_init(struct soc_pcmcia_socket *skt)
{
	int ret = gpio_request(GPIO_PCMCIA_RESET, "PCCard reset");
	if (ret)
		return ret;
	gpio_direction_output(GPIO_PCMCIA_RESET, 0);

	if (skt->nr == 0) {
		skt->stat[SOC_STAT_CD].gpio = GPIO_PCMCIA_S0_CD_VALID;
		skt->stat[SOC_STAT_CD].name = "PCMCIA0 CD";
		skt->stat[SOC_STAT_RDY].gpio = GPIO_PCMCIA_S0_RDYINT;
		skt->stat[SOC_STAT_RDY].name = "PCMCIA0 RDY";
	} else {
		skt->stat[SOC_STAT_CD].gpio = GPIO_PCMCIA_S1_CD_VALID;
		skt->stat[SOC_STAT_CD].name = "PCMCIA1 CD";
		skt->stat[SOC_STAT_RDY].gpio = GPIO_PCMCIA_S1_RDYINT;
		skt->stat[SOC_STAT_RDY].name = "PCMCIA1 RDY";
	}

	return 0;
}

__attribute__((used)) static void cmx255_pcmcia_shutdown(struct soc_pcmcia_socket *skt)
{
	gpio_free(GPIO_PCMCIA_RESET);
}

__attribute__((used)) static void cmx255_pcmcia_socket_state(struct soc_pcmcia_socket *skt,
				       struct pcmcia_state *state)
{
	state->vs_3v  = 0;
	state->vs_Xv  = 0;
}

__attribute__((used)) static int cmx255_pcmcia_configure_socket(struct soc_pcmcia_socket *skt,
					  const socket_state_t *state)
{
	switch (skt->nr) {
	case 0:
		if (state->flags & SS_RESET) {
			gpio_set_value(GPIO_PCMCIA_SKTSEL, 0);
			udelay(1);
			gpio_set_value(GPIO_PCMCIA_RESET, 1);
			udelay(10);
			gpio_set_value(GPIO_PCMCIA_RESET, 0);
		}
		break;
	case 1:
		if (state->flags & SS_RESET) {
			gpio_set_value(GPIO_PCMCIA_SKTSEL, 1);
			udelay(1);
			gpio_set_value(GPIO_PCMCIA_RESET, 1);
			udelay(10);
			gpio_set_value(GPIO_PCMCIA_RESET, 0);
		}
		break;
	}

	return 0;
}

