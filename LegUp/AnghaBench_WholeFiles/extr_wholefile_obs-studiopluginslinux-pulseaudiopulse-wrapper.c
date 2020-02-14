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
typedef  int /*<<< orphan*/  pa_stream ;
typedef  int /*<<< orphan*/  pa_source_info_cb_t ;
typedef  int /*<<< orphan*/  pa_sink_info_cb_t ;
typedef  int /*<<< orphan*/  pa_server_info_cb_t ;
typedef  int /*<<< orphan*/  pa_sample_spec ;
typedef  int /*<<< orphan*/  pa_proplist ;
typedef  int /*<<< orphan*/  pa_operation ;
typedef  void pa_context ;
typedef  int /*<<< orphan*/  pa_channel_map ;
typedef  int int_fast32_t ;

/* Variables and functions */
 int /*<<< orphan*/  PA_CONTEXT_IS_GOOD (scalar_t__) ; 
 int /*<<< orphan*/  PA_CONTEXT_NOAUTOSPAWN ; 
 scalar_t__ PA_CONTEXT_READY ; 
 scalar_t__ PA_OPERATION_RUNNING ; 
 int /*<<< orphan*/  PA_PROP_APPLICATION_ICON_NAME ; 
 int /*<<< orphan*/  PA_PROP_APPLICATION_NAME ; 
 int /*<<< orphan*/  PA_PROP_MEDIA_ROLE ; 
 int /*<<< orphan*/  UNUSED_PARAMETER (void*) ; 
 int /*<<< orphan*/  pa_context_connect (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pa_context_disconnect (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * pa_context_get_server_info (int /*<<< orphan*/ *,int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/ * pa_context_get_sink_info_list (int /*<<< orphan*/ *,int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/ * pa_context_get_source_info_by_name (int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/ * pa_context_get_source_info_list (int /*<<< orphan*/ *,int /*<<< orphan*/ ,void*) ; 
 scalar_t__ pa_context_get_state (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * pa_context_new_with_proplist (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pa_context_set_state_callback (int /*<<< orphan*/ *,void (*) (void*,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pa_context_unref (int /*<<< orphan*/ *) ; 
 scalar_t__ pa_operation_get_state (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pa_operation_unref (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pa_proplist_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * pa_proplist_new () ; 
 int /*<<< orphan*/  pa_proplist_sets (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/ * pa_stream_new_with_proplist (int /*<<< orphan*/ *,char const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pa_threaded_mainloop_accept (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pa_threaded_mainloop_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pa_threaded_mainloop_get_api (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pa_threaded_mainloop_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * pa_threaded_mainloop_new () ; 
 int /*<<< orphan*/  pa_threaded_mainloop_signal (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  pa_threaded_mainloop_start (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pa_threaded_mainloop_stop (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pa_threaded_mainloop_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pa_threaded_mainloop_wait (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * pulse_context ; 
 void pulse_lock () ; 
 int /*<<< orphan*/ * pulse_mainloop ; 
 int /*<<< orphan*/  pulse_mutex ; 
 scalar_t__ pulse_refs ; 
 void pulse_signal (int) ; 
 void pulse_unlock () ; 
 void pulse_wait () ; 

__attribute__((used)) static void pulse_context_state_changed(pa_context *c, void *userdata)
{
	UNUSED_PARAMETER(userdata);
	UNUSED_PARAMETER(c);

	pulse_signal(0);
}

__attribute__((used)) static pa_proplist *pulse_properties()
{
	pa_proplist *p = pa_proplist_new();

	pa_proplist_sets(p, PA_PROP_APPLICATION_NAME, "OBS");
	pa_proplist_sets(p, PA_PROP_APPLICATION_ICON_NAME, "obs");
	pa_proplist_sets(p, PA_PROP_MEDIA_ROLE, "production");

	return p;
}

__attribute__((used)) static void pulse_init_context()
{
	pulse_lock();

	pa_proplist *p = pulse_properties();
	pulse_context = pa_context_new_with_proplist(
		pa_threaded_mainloop_get_api(pulse_mainloop), "OBS", p);

	pa_context_set_state_callback(pulse_context,
		pulse_context_state_changed, NULL);

	pa_context_connect(pulse_context, NULL, PA_CONTEXT_NOAUTOSPAWN, NULL);
	pa_proplist_free(p);

	pulse_unlock();
}

__attribute__((used)) static int_fast32_t pulse_context_ready()
{
	pulse_lock();

	if (!PA_CONTEXT_IS_GOOD(pa_context_get_state(pulse_context))) {
		pulse_unlock();
		return -1;
	}

	while (pa_context_get_state(pulse_context) != PA_CONTEXT_READY)
		pulse_wait();

	pulse_unlock();
	return 0;
}

int_fast32_t pulse_init()
{
	pthread_mutex_lock(&pulse_mutex);

	if (pulse_refs == 0) {
		pulse_mainloop = pa_threaded_mainloop_new();
		pa_threaded_mainloop_start(pulse_mainloop);

		pulse_init_context();
	}

	pulse_refs++;

	pthread_mutex_unlock(&pulse_mutex);

	return 0;
}

void pulse_unref()
{
	pthread_mutex_lock(&pulse_mutex);

	if (--pulse_refs == 0) {
		pulse_lock();
		if (pulse_context != NULL) {
			pa_context_disconnect(pulse_context);
			pa_context_unref(pulse_context);
			pulse_context = NULL;
		}
		pulse_unlock();

		if (pulse_mainloop != NULL) {
			pa_threaded_mainloop_stop(pulse_mainloop);
			pa_threaded_mainloop_free(pulse_mainloop);
			pulse_mainloop = NULL;
		}
	}

	pthread_mutex_unlock(&pulse_mutex);
}

void pulse_lock()
{
	pa_threaded_mainloop_lock(pulse_mainloop);
}

void pulse_unlock()
{
	pa_threaded_mainloop_unlock(pulse_mainloop);
}

void pulse_wait()
{
	pa_threaded_mainloop_wait(pulse_mainloop);
}

void pulse_signal(int wait_for_accept)
{
	pa_threaded_mainloop_signal(pulse_mainloop, wait_for_accept);
}

void pulse_accept()
{
	pa_threaded_mainloop_accept(pulse_mainloop);
}

int_fast32_t pulse_get_source_info_list(pa_source_info_cb_t cb, void* userdata)
{
	if (pulse_context_ready() < 0)
		return -1;

	pulse_lock();

	pa_operation *op = pa_context_get_source_info_list(
		pulse_context, cb, userdata);
	if (!op) {
		pulse_unlock();
		return -1;
	}
	while (pa_operation_get_state(op) == PA_OPERATION_RUNNING)
		pulse_wait();
	pa_operation_unref(op);

	pulse_unlock();

	return 0;
}

int_fast32_t pulse_get_sink_info_list(pa_sink_info_cb_t cb, void *userdata)
{
	if (pulse_context_ready() < 0)
		return -1;

	pulse_lock();

	pa_operation *op = pa_context_get_sink_info_list(
		pulse_context, cb, userdata);
	if (!op) {
		pulse_unlock();
		return -1;
	}
	while (pa_operation_get_state(op) == PA_OPERATION_RUNNING)
		pulse_wait();
	pa_operation_unref(op);

	pulse_unlock();

	return 0;
}

int_fast32_t pulse_get_source_info(pa_source_info_cb_t cb, const char *name,
	void *userdata)
{
	if (pulse_context_ready() < 0)
		return -1;

	pulse_lock();

	pa_operation *op = pa_context_get_source_info_by_name(
		pulse_context, name, cb, userdata);
	if (!op) {
		pulse_unlock();
		return -1;
	}
	while (pa_operation_get_state(op) == PA_OPERATION_RUNNING)
		pulse_wait();
	pa_operation_unref(op);

	pulse_unlock();

	return 0;
}

int_fast32_t pulse_get_server_info(pa_server_info_cb_t cb, void* userdata)
{
	if (pulse_context_ready() < 0)
		return -1;

	pulse_lock();

	pa_operation *op = pa_context_get_server_info(
		pulse_context, cb, userdata);
	if (!op) {
		pulse_unlock();
		return -1;
	}
	while (pa_operation_get_state(op) == PA_OPERATION_RUNNING)
		pulse_wait();
	pa_operation_unref(op);

	pulse_unlock();
	return 0;
}

pa_stream* pulse_stream_new(const char* name, const pa_sample_spec* ss,
	const pa_channel_map* map)
{
	if (pulse_context_ready() < 0)
		return NULL;

	pulse_lock();

	pa_proplist *p = pulse_properties();
	pa_stream *s = pa_stream_new_with_proplist(
		pulse_context, name, ss, map, p);
	pa_proplist_free(p);

	pulse_unlock();
	return s;
}

