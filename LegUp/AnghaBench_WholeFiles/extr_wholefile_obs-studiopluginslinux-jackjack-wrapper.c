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
typedef  int uint_fast32_t ;
typedef  int /*<<< orphan*/  uint8_t ;
struct obs_source_audio {int speakers; scalar_t__ timestamp; int /*<<< orphan*/  frames; int /*<<< orphan*/ ** data; int /*<<< orphan*/  format; int /*<<< orphan*/  samples_per_sec; } ;
struct jack_data {int channels; int /*<<< orphan*/  jack_mutex; int /*<<< orphan*/ * jack_client; int /*<<< orphan*/ ** jack_ports; int /*<<< orphan*/  device; scalar_t__ start_jack_server; int /*<<< orphan*/  source; } ;
typedef  int /*<<< orphan*/  port_name ;
typedef  int /*<<< orphan*/  jack_port_t ;
typedef  int /*<<< orphan*/  jack_options_t ;
typedef  int /*<<< orphan*/  jack_nframes_t ;
typedef  int /*<<< orphan*/  jack_default_audio_sample_t ;
typedef  int int_fast32_t ;
typedef  enum speaker_layout { ____Placeholder_speaker_layout } speaker_layout ;

/* Variables and functions */
 int /*<<< orphan*/  AUDIO_FORMAT_FLOAT_PLANAR ; 
 int /*<<< orphan*/  JACK_DEFAULT_AUDIO_TYPE ; 
 int /*<<< orphan*/  JackNoStartServer ; 
 int /*<<< orphan*/  JackNullOption ; 
 int /*<<< orphan*/  JackPortIsInput ; 
 int /*<<< orphan*/  LOG_ERROR ; 
 int SPEAKERS_2POINT1 ; 
 int SPEAKERS_4POINT1 ; 
 int SPEAKERS_5POINT1 ; 
 int SPEAKERS_7POINT1 ; 
 int SPEAKERS_MONO ; 
 int SPEAKERS_STEREO ; 
 int SPEAKERS_UNKNOWN ; 
 int /*<<< orphan*/  bfree (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  blog (int /*<<< orphan*/ ,char*,...) ; 
 scalar_t__ bzalloc (int) ; 
 scalar_t__ jack_activate (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  jack_client_close (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * jack_client_open (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ jack_frames_to_time (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  jack_get_sample_rate (int /*<<< orphan*/ *) ; 
 scalar_t__ jack_port_get_buffer (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * jack_port_register (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  jack_port_unregister (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ jack_set_process_callback (int /*<<< orphan*/ *,int (*) (int /*<<< orphan*/ ,void*),struct jack_data*) ; 
 int /*<<< orphan*/  obs_source_output_audio (int /*<<< orphan*/ ,struct obs_source_audio*) ; 
 scalar_t__ os_gettime_ns () ; 
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,unsigned int) ; 

__attribute__((used)) static enum speaker_layout jack_channels_to_obs_speakers(uint_fast32_t channels)
{
	switch(channels) {
	case 1: return SPEAKERS_MONO;
	case 2: return SPEAKERS_STEREO;
	case 3: return SPEAKERS_2POINT1;
	case 5: return SPEAKERS_4POINT1;
	case 6: return SPEAKERS_5POINT1;
	/* What should we do with 7 channels? */
	/* case 7: return SPEAKERS_...; */
	case 8: return SPEAKERS_7POINT1;
	}

	return SPEAKERS_UNKNOWN;
}

int jack_process_callback(jack_nframes_t nframes, void* arg)
{
	struct jack_data* data = (struct jack_data*)arg;
	if (data == 0)
		return 0;

	pthread_mutex_lock(&data->jack_mutex);

	struct obs_source_audio out;
	out.speakers        = jack_channels_to_obs_speakers(data->channels);
	out.samples_per_sec = jack_get_sample_rate (data->jack_client);
	/* format is always 32 bit float for jack */
	out.format          = AUDIO_FORMAT_FLOAT_PLANAR;

	for (unsigned int i = 0; i < data->channels; ++i) {
		jack_default_audio_sample_t *jack_buffer =
			(jack_default_audio_sample_t *)jack_port_get_buffer(
				data->jack_ports[i], nframes);
		out.data[i] = (uint8_t *)jack_buffer;
	}

	out.frames    = nframes;
	out.timestamp = os_gettime_ns() -
				jack_frames_to_time(data->jack_client, nframes);

	obs_source_output_audio(data->source, &out);
	pthread_mutex_unlock(&data->jack_mutex);
	return 0;
}

int_fast32_t jack_init(struct jack_data* data)
{
	pthread_mutex_lock(&data->jack_mutex);

	if (data->jack_client != NULL)
		goto good;

	jack_options_t jack_option = data->start_jack_server ?
		JackNullOption : JackNoStartServer;

	data->jack_client = jack_client_open(data->device, jack_option, 0);
	if (data->jack_client == NULL) {
		blog(LOG_ERROR,
			"jack_client_open Error:"
			"Could not create JACK client! %s",
			data->device);
		goto error;
	}

	data->jack_ports = (jack_port_t**)bzalloc(
		sizeof(jack_port_t*) * data->channels);
	for (unsigned int i = 0; i < data->channels; ++i) {
		char port_name[10] = {'\0'};
		snprintf(port_name, sizeof(port_name), "in_%u", i+1);

		data->jack_ports[i] = jack_port_register(data->jack_client,
			port_name, JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0);
		if (data->jack_ports[i] == NULL) {
			blog(LOG_ERROR,
				"jack_port_register Error:"
				"Could not create JACK port! %s",
				port_name);
			goto error;
		}
	}

	if (jack_set_process_callback(data->jack_client,
			jack_process_callback, data) != 0) {
		blog(LOG_ERROR, "jack_set_process_callback Error");
		goto error;
	}

	if (jack_activate(data->jack_client) != 0) {
		blog(LOG_ERROR,
			"jack_activate Error:"
			"Could not activate JACK client!");
		goto error;
	}

good:
	pthread_mutex_unlock(&data->jack_mutex);
	return 0;

error:
	pthread_mutex_unlock(&data->jack_mutex);
	return 1;
}

void deactivate_jack(struct jack_data* data)
{
	pthread_mutex_lock(&data->jack_mutex);

	if (data->jack_client) {
		if (data->jack_ports != NULL) {
			for (int i = 0; i < data->channels; ++i) {
				if (data->jack_ports[i] != NULL)
					jack_port_unregister(data->jack_client,
						data->jack_ports[i]);
			}
			bfree(data->jack_ports);
			data->jack_ports = NULL;
		}
		jack_client_close(data->jack_client);
		data->jack_client = NULL;
	}
	pthread_mutex_unlock(&data->jack_mutex);
}

