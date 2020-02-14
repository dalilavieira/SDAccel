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
struct pcmcia_state {int vs_3v; scalar_t__ vs_Xv; } ;
struct TYPE_5__ {int flags; int Vcc; } ;
typedef  TYPE_2__ socket_state_t ;
struct TYPE_4__ {char* name; int /*<<< orphan*/  gpio; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GPIO107_VPAC270_PCMCIA_PPEN ; 
 int /*<<< orphan*/  GPIO11_VPAC270_PCMCIA_RESET ; 
 int /*<<< orphan*/  GPIO12_VPAC270_CF_RDY ; 
 int /*<<< orphan*/  GPIO16_VPAC270_CF_RESET ; 
 int /*<<< orphan*/  GPIO17_VPAC270_CF_CD ; 
 int /*<<< orphan*/  GPIO35_VPAC270_PCMCIA_RDY ; 
 int /*<<< orphan*/  GPIO84_VPAC270_PCMCIA_CD ; 
 size_t SOC_STAT_CD ; 
 size_t SOC_STAT_RDY ; 
 int SS_RESET ; 
 int /*<<< orphan*/  gpio_free_array (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int gpio_request_array (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  vpac270_cf_gpios ; 
 int /*<<< orphan*/  vpac270_pcmcia_gpios ; 

__attribute__((used)) static int vpac270_pcmcia_hw_init(struct soc_pcmcia_socket *skt)
{
	int ret;

	if (skt->nr == 0) {
		ret = gpio_request_array(vpac270_pcmcia_gpios,
				ARRAY_SIZE(vpac270_pcmcia_gpios));

		skt->stat[SOC_STAT_CD].gpio = GPIO84_VPAC270_PCMCIA_CD;
		skt->stat[SOC_STAT_CD].name = "PCMCIA CD";
		skt->stat[SOC_STAT_RDY].gpio = GPIO35_VPAC270_PCMCIA_RDY;
		skt->stat[SOC_STAT_RDY].name = "PCMCIA Ready";
	} else {
		ret = gpio_request_array(vpac270_cf_gpios,
				ARRAY_SIZE(vpac270_cf_gpios));

		skt->stat[SOC_STAT_CD].gpio = GPIO17_VPAC270_CF_CD;
		skt->stat[SOC_STAT_CD].name = "CF CD";
		skt->stat[SOC_STAT_RDY].gpio = GPIO12_VPAC270_CF_RDY;
		skt->stat[SOC_STAT_RDY].name = "CF Ready";
	}

	return ret;
}

__attribute__((used)) static void vpac270_pcmcia_hw_shutdown(struct soc_pcmcia_socket *skt)
{
	if (skt->nr == 0)
		gpio_free_array(vpac270_pcmcia_gpios,
					ARRAY_SIZE(vpac270_pcmcia_gpios));
	else
		gpio_free_array(vpac270_cf_gpios,
					ARRAY_SIZE(vpac270_cf_gpios));
}

__attribute__((used)) static void vpac270_pcmcia_socket_state(struct soc_pcmcia_socket *skt,
					struct pcmcia_state *state)
{
	state->vs_3v  = 1;
	state->vs_Xv  = 0;
}

__attribute__((used)) static int
vpac270_pcmcia_configure_socket(struct soc_pcmcia_socket *skt,
				const socket_state_t *state)
{
	if (skt->nr == 0) {
		gpio_set_value(GPIO11_VPAC270_PCMCIA_RESET,
			(state->flags & SS_RESET));
		gpio_set_value(GPIO107_VPAC270_PCMCIA_PPEN,
			!(state->Vcc == 33 || state->Vcc == 50));
	} else {
		gpio_set_value(GPIO16_VPAC270_CF_RESET,
			(state->flags & SS_RESET));
	}

	return 0;
}

