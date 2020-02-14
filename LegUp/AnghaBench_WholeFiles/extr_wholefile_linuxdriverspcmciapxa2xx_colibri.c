#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {void* pci_irq; } ;
struct soc_pcmcia_socket {TYPE_2__* stat; TYPE_1__ socket; } ;
struct pcmcia_state {int detect; int ready; int bvd1; int bvd2; int vs_3v; scalar_t__ vs_Xv; } ;
struct TYPE_11__ {int Vcc; int Vpp; int flags; } ;
typedef  TYPE_3__ socket_state_t ;
struct TYPE_12__ {int /*<<< orphan*/  gpio; } ;
struct TYPE_10__ {char* name; void* irq; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (TYPE_4__*) ; 
 size_t BVD1 ; 
 size_t BVD2 ; 
 size_t DETECT ; 
 size_t PPEN ; 
 size_t READY ; 
 size_t RESET ; 
 size_t SOC_STAT_CD ; 
 int SS_RESET ; 
 TYPE_4__* colibri_pcmcia_gpios ; 
 int /*<<< orphan*/  gpio_free_array (TYPE_4__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_get_value (int /*<<< orphan*/ ) ; 
 int gpio_request_array (TYPE_4__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 
 void* gpio_to_irq (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int colibri_pcmcia_hw_init(struct soc_pcmcia_socket *skt)
{
	int ret;

	ret = gpio_request_array(colibri_pcmcia_gpios,
				ARRAY_SIZE(colibri_pcmcia_gpios));
	if (ret)
		goto err1;

	skt->socket.pci_irq = gpio_to_irq(colibri_pcmcia_gpios[READY].gpio);
	skt->stat[SOC_STAT_CD].irq = gpio_to_irq(colibri_pcmcia_gpios[DETECT].gpio);
	skt->stat[SOC_STAT_CD].name = "PCMCIA CD";

err1:
	return ret;
}

__attribute__((used)) static void colibri_pcmcia_hw_shutdown(struct soc_pcmcia_socket *skt)
{
	gpio_free_array(colibri_pcmcia_gpios,
			ARRAY_SIZE(colibri_pcmcia_gpios));
}

__attribute__((used)) static void colibri_pcmcia_socket_state(struct soc_pcmcia_socket *skt,
					struct pcmcia_state *state)
{

	state->detect = !!gpio_get_value(colibri_pcmcia_gpios[DETECT].gpio);
	state->ready  = !!gpio_get_value(colibri_pcmcia_gpios[READY].gpio);
	state->bvd1   = !!gpio_get_value(colibri_pcmcia_gpios[BVD1].gpio);
	state->bvd2   = !!gpio_get_value(colibri_pcmcia_gpios[BVD2].gpio);
	state->vs_3v  = 1;
	state->vs_Xv  = 0;
}

__attribute__((used)) static int
colibri_pcmcia_configure_socket(struct soc_pcmcia_socket *skt,
				const socket_state_t *state)
{
	gpio_set_value(colibri_pcmcia_gpios[PPEN].gpio,
			!(state->Vcc == 33 && state->Vpp < 50));
	gpio_set_value(colibri_pcmcia_gpios[RESET].gpio,
			state->flags & SS_RESET);
	return 0;
}

