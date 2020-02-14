#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_29__   TYPE_6__ ;
typedef  struct TYPE_28__   TYPE_5__ ;
typedef  struct TYPE_27__   TYPE_4__ ;
typedef  struct TYPE_26__   TYPE_3__ ;
typedef  struct TYPE_25__   TYPE_2__ ;
typedef  struct TYPE_24__   TYPE_21__ ;
typedef  struct TYPE_23__   TYPE_1__ ;

/* Type definitions */
struct TYPE_23__ {char* name; char* description; } ;
typedef  TYPE_1__ pa_source_info ;
struct TYPE_25__ {char* name; char* description; } ;
typedef  TYPE_2__ pa_sink_info ;
struct TYPE_26__ {char const* default_sink_name; char const* default_source_name; } ;
typedef  TYPE_3__ pa_server_info ;
typedef  int /*<<< orphan*/  pa_operation ;
typedef  int /*<<< orphan*/  pa_mainloop_api ;
typedef  int /*<<< orphan*/  pa_mainloop ;
typedef  int /*<<< orphan*/  pa_context ;
typedef  enum pa_operation_state { ____Placeholder_pa_operation_state } pa_operation_state ;
typedef  enum PulseAudioContextState { ____Placeholder_PulseAudioContextState } PulseAudioContextState ;
struct TYPE_29__ {void* device_name; void* device_description; } ;
struct TYPE_28__ {int nb_devices; int default_device; TYPE_21__** devices; } ;
struct TYPE_27__ {int error_code; int output; TYPE_6__* default_device; TYPE_5__* devices; int /*<<< orphan*/  member_0; } ;
struct TYPE_24__ {int /*<<< orphan*/  device_name; } ;
typedef  TYPE_4__ PulseAudioDeviceList ;
typedef  TYPE_5__ AVDeviceInfoList ;
typedef  TYPE_6__ AVDeviceInfo ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 void* AVERROR_EXTERNAL ; 
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  ENOMEM ; 
#define  PA_CONTEXT_FAILED 130 
#define  PA_CONTEXT_READY 129 
#define  PA_CONTEXT_TERMINATED 128 
 int PA_OPERATION_DONE ; 
 int PA_OPERATION_RUNNING ; 
 int PULSE_CONTEXT_FINISHED ; 
 int PULSE_CONTEXT_INITIALIZING ; 
 int PULSE_CONTEXT_READY ; 
 int /*<<< orphan*/  av_assert0 (int /*<<< orphan*/ **) ; 
 int av_dynarray_add_nofree (TYPE_21__***,int*,TYPE_6__*) ; 
 int /*<<< orphan*/  av_free (TYPE_6__*) ; 
 int /*<<< orphan*/  av_freep (void**) ; 
 TYPE_6__* av_mallocz (int) ; 
 void* av_strdup (char const*) ; 
 scalar_t__ pa_context_connect (int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pa_context_disconnect (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * pa_context_get_server_info (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,TYPE_3__ const*,void*),TYPE_4__*) ; 
 int /*<<< orphan*/ * pa_context_get_sink_info_list (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,TYPE_2__ const*,int,void*),TYPE_4__*) ; 
 int /*<<< orphan*/ * pa_context_get_source_info_list (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,TYPE_1__ const*,int,void*),TYPE_4__*) ; 
 int pa_context_get_state (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * pa_context_new (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  pa_context_set_state_callback (int /*<<< orphan*/ *,...) ; 
 int /*<<< orphan*/  pa_context_unref (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pa_mainloop_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * pa_mainloop_get_api (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pa_mainloop_iterate (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * pa_mainloop_new () ; 
 int pa_operation_get_state (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pa_operation_unref (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  strcmp (int /*<<< orphan*/ ,TYPE_6__*) ; 

__attribute__((used)) static void pa_state_cb(pa_context *c, void *userdata)
{
    enum PulseAudioContextState *context_state = userdata;

    switch  (pa_context_get_state(c)) {
    case PA_CONTEXT_FAILED:
    case PA_CONTEXT_TERMINATED:
        *context_state = PULSE_CONTEXT_FINISHED;
        break;
    case PA_CONTEXT_READY:
        *context_state = PULSE_CONTEXT_READY;
        break;
    default:
        break;
    }
}

void ff_pulse_audio_disconnect_context(pa_mainloop **pa_ml, pa_context **pa_ctx)
{
    av_assert0(pa_ml);
    av_assert0(pa_ctx);

    if (*pa_ctx) {
        pa_context_set_state_callback(*pa_ctx, NULL, NULL);
        pa_context_disconnect(*pa_ctx);
        pa_context_unref(*pa_ctx);
    }
    if (*pa_ml)
        pa_mainloop_free(*pa_ml);
    *pa_ml = NULL;
    *pa_ctx = NULL;
}

int ff_pulse_audio_connect_context(pa_mainloop **pa_ml, pa_context **pa_ctx,
                                   const char *server, const char *description)
{
    int ret;
    pa_mainloop_api *pa_mlapi = NULL;
    enum PulseAudioContextState context_state = PULSE_CONTEXT_INITIALIZING;

    av_assert0(pa_ml);
    av_assert0(pa_ctx);

    *pa_ml = NULL;
    *pa_ctx = NULL;

    if (!(*pa_ml = pa_mainloop_new()))
        return AVERROR(ENOMEM);
    if (!(pa_mlapi = pa_mainloop_get_api(*pa_ml))) {
        ret = AVERROR_EXTERNAL;
        goto fail;
    }
    if (!(*pa_ctx = pa_context_new(pa_mlapi, description))) {
        ret = AVERROR(ENOMEM);
        goto fail;
    }
    pa_context_set_state_callback(*pa_ctx, pa_state_cb, &context_state);
    if (pa_context_connect(*pa_ctx, server, 0, NULL) < 0) {
        ret = AVERROR_EXTERNAL;
        goto fail;
    }

    while (context_state == PULSE_CONTEXT_INITIALIZING)
        pa_mainloop_iterate(*pa_ml, 1, NULL);
    if (context_state == PULSE_CONTEXT_FINISHED) {
        ret = AVERROR_EXTERNAL;
        goto fail;
    }
    return 0;

  fail:
    ff_pulse_audio_disconnect_context(pa_ml, pa_ctx);
    return ret;
}

__attribute__((used)) static void pulse_add_detected_device(PulseAudioDeviceList *info,
                                      const char *name, const char *description)
{
    int ret;
    AVDeviceInfo *new_device = NULL;

    if (info->error_code)
        return;

    new_device = av_mallocz(sizeof(AVDeviceInfo));
    if (!new_device) {
        info->error_code = AVERROR(ENOMEM);
        return;
    }

    new_device->device_description = av_strdup(description);
    new_device->device_name = av_strdup(name);

    if (!new_device->device_description || !new_device->device_name) {
        info->error_code = AVERROR(ENOMEM);
        goto fail;
    }

    if ((ret = av_dynarray_add_nofree(&info->devices->devices,
                                      &info->devices->nb_devices, new_device)) < 0) {
        info->error_code = ret;
        goto fail;
    }
    return;

  fail:
    av_freep(&new_device->device_description);
    av_freep(&new_device->device_name);
    av_free(new_device);

}

__attribute__((used)) static void pulse_audio_source_device_cb(pa_context *c, const pa_source_info *dev,
                                         int eol, void *userdata)
{
    if (!eol)
        pulse_add_detected_device(userdata, dev->name, dev->description);
}

__attribute__((used)) static void pulse_audio_sink_device_cb(pa_context *c, const pa_sink_info *dev,
                                       int eol, void *userdata)
{
    if (!eol)
        pulse_add_detected_device(userdata, dev->name, dev->description);
}

__attribute__((used)) static void pulse_server_info_cb(pa_context *c, const pa_server_info *i, void *userdata)
{
    PulseAudioDeviceList *info = userdata;
    if (info->output)
        info->default_device = av_strdup(i->default_sink_name);
    else
        info->default_device = av_strdup(i->default_source_name);
    if (!info->default_device)
        info->error_code = AVERROR(ENOMEM);
}

int ff_pulse_audio_get_devices(AVDeviceInfoList *devices, const char *server, int output)
{
    pa_mainloop *pa_ml = NULL;
    pa_operation *pa_op = NULL;
    pa_context *pa_ctx = NULL;
    enum pa_operation_state op_state;
    PulseAudioDeviceList dev_list = { 0 };
    int i;

    dev_list.output = output;
    dev_list.devices = devices;
    if (!devices)
        return AVERROR(EINVAL);
    devices->nb_devices = 0;
    devices->devices = NULL;

    if ((dev_list.error_code = ff_pulse_audio_connect_context(&pa_ml, &pa_ctx, server, "Query devices")) < 0)
        goto fail;

    if (output)
        pa_op = pa_context_get_sink_info_list(pa_ctx, pulse_audio_sink_device_cb, &dev_list);
    else
        pa_op = pa_context_get_source_info_list(pa_ctx, pulse_audio_source_device_cb, &dev_list);
    while ((op_state = pa_operation_get_state(pa_op)) == PA_OPERATION_RUNNING)
        pa_mainloop_iterate(pa_ml, 1, NULL);
    if (op_state != PA_OPERATION_DONE)
        dev_list.error_code = AVERROR_EXTERNAL;
    pa_operation_unref(pa_op);
    if (dev_list.error_code < 0)
        goto fail;

    pa_op = pa_context_get_server_info(pa_ctx, pulse_server_info_cb, &dev_list);
    while ((op_state = pa_operation_get_state(pa_op)) == PA_OPERATION_RUNNING)
        pa_mainloop_iterate(pa_ml, 1, NULL);
    if (op_state != PA_OPERATION_DONE)
        dev_list.error_code = AVERROR_EXTERNAL;
    pa_operation_unref(pa_op);
    if (dev_list.error_code < 0)
        goto fail;

    devices->default_device = -1;
    for (i = 0; i < devices->nb_devices; i++) {
        if (!strcmp(devices->devices[i]->device_name, dev_list.default_device)) {
            devices->default_device = i;
            break;
        }
    }

  fail:
    av_free(dev_list.default_device);
    ff_pulse_audio_disconnect_context(&pa_ml, &pa_ctx);
    return dev_list.error_code;
}

