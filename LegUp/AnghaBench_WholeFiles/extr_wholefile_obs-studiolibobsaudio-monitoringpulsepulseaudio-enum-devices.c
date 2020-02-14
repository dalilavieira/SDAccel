#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct enum_cb {int cont; int (* cb ) (void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;void* data; } ;
typedef  void (* pa_source_info_cb_t ) (int /*<<< orphan*/ *,TYPE_1__ const*,int,void*) ;
struct TYPE_5__ {scalar_t__ monitor_of_sink; int /*<<< orphan*/  name; int /*<<< orphan*/  description; } ;
typedef  TYPE_1__ pa_source_info ;
typedef  int /*<<< orphan*/  pa_context ;
typedef  int (* obs_enum_audio_device_cb ) (void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;

/* Variables and functions */
 scalar_t__ PA_INVALID_INDEX ; 
 int /*<<< orphan*/  UNUSED_PARAMETER (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bfree (struct enum_cb*) ; 
 struct enum_cb* bzalloc (int) ; 
 int /*<<< orphan*/  pulseaudio_get_source_info_list (void (*) (int /*<<< orphan*/ *,TYPE_1__ const*,int,void*),void*) ; 
 int /*<<< orphan*/  pulseaudio_init () ; 
 int /*<<< orphan*/  pulseaudio_signal (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pulseaudio_unref () ; 
 int stub1 (void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void pulseaudio_output_info(pa_context *c, const pa_source_info *i,
		int eol, void *userdata)
{
	UNUSED_PARAMETER(c);
	if (eol != 0 || i->monitor_of_sink == PA_INVALID_INDEX)
		goto skip;

	struct enum_cb *ecb = (struct enum_cb *) userdata;
	if (ecb->cont)
		ecb->cont = ecb->cb(ecb->data, i->description, i->name);

skip:
	pulseaudio_signal(0);
}

void obs_enum_audio_monitoring_devices(obs_enum_audio_device_cb cb,
		void *data)
{
	struct enum_cb *ecb = bzalloc(sizeof(struct enum_cb));
	ecb->cb = cb;
	ecb->data = data;
	ecb->cont = 1;

	pulseaudio_init();
	pa_source_info_cb_t pa_cb = pulseaudio_output_info;
	pulseaudio_get_source_info_list(pa_cb, (void *) ecb);
	pulseaudio_unref();

	bfree(ecb);
}

