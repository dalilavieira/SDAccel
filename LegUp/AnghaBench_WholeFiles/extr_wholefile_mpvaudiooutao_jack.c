#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct priv {int num_ports; int activated; int /*<<< orphan*/  client; TYPE_2__* opts; int /*<<< orphan*/ * ports; int /*<<< orphan*/  buffer_size; int /*<<< orphan*/  graph_latency_max; } ;
struct mp_chmap_sel {int /*<<< orphan*/  member_0; } ;
struct TYPE_8__ {int num; } ;
struct ao {struct priv* priv; TYPE_4__ channels; scalar_t__ samplerate; int /*<<< orphan*/  format; int /*<<< orphan*/  global; } ;
typedef  int /*<<< orphan*/  pname ;
typedef  int /*<<< orphan*/  jack_options_t ;
typedef  double jack_nframes_t ;
struct TYPE_6__ {double max; } ;
typedef  TYPE_1__ jack_latency_range_t ;
typedef  double int64_t ;
struct TYPE_7__ {char* port; int stdlayout; int /*<<< orphan*/  client_name; int /*<<< orphan*/  autostart; scalar_t__ connect; } ;

/* Variables and functions */
 int /*<<< orphan*/  AF_FORMAT_FLOATP ; 
 char* JACK_DEFAULT_AUDIO_TYPE ; 
 int /*<<< orphan*/  JackNoStartServer ; 
 int /*<<< orphan*/  JackNullOption ; 
 int /*<<< orphan*/  JackPlaybackLatency ; 
 int JackPortIsInput ; 
 int /*<<< orphan*/  JackPortIsOutput ; 
 int JackPortIsPhysical ; 
 int /*<<< orphan*/  MP_FATAL (struct ao*,char*) ; 
 int MP_NUM_CHANNELS ; 
 int /*<<< orphan*/  ao_chmap_sel_adjust (struct ao*,struct mp_chmap_sel*,TYPE_4__*) ; 
 int /*<<< orphan*/  ao_chmap_sel_get_def (struct ao*,struct mp_chmap_sel*,TYPE_4__*,int) ; 
 int /*<<< orphan*/  ao_jack_conf ; 
 int /*<<< orphan*/  ao_read_data (struct ao*,void**,double,double) ; 
 double atomic_load (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_store (int /*<<< orphan*/ *,double) ; 
 int /*<<< orphan*/  free (char const**) ; 
 scalar_t__ jack_activate (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  jack_client_close (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  jack_client_open (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ jack_connect (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*) ; 
 char** jack_get_ports (int /*<<< orphan*/ ,char*,char const*,int) ; 
 scalar_t__ jack_get_sample_rate (int /*<<< orphan*/ ) ; 
 void* jack_port_get_buffer (int /*<<< orphan*/ ,double) ; 
 int /*<<< orphan*/  jack_port_get_latency_range (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  jack_port_name (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  jack_port_register (int /*<<< orphan*/ ,char*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  jack_set_buffer_size_callback (int /*<<< orphan*/ ,int (*) (double,void*),struct ao*) ; 
 int /*<<< orphan*/  jack_set_graph_order_callback (int /*<<< orphan*/ ,int (*) (void*),struct ao*) ; 
 int /*<<< orphan*/  jack_set_process_callback (int /*<<< orphan*/ ,int (*) (double,void*),struct ao*) ; 
 int /*<<< orphan*/  mp_chmap_sel_add_any (struct mp_chmap_sel*) ; 
 int /*<<< orphan*/  mp_chmap_sel_add_waveext (struct mp_chmap_sel*) ; 
 TYPE_2__* mp_get_config_group (struct ao*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 double mp_time_us () ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,int) ; 

__attribute__((used)) static int graph_order_cb(void *arg)
{
    struct ao *ao = arg;
    struct priv *p = ao->priv;

    jack_latency_range_t jack_latency_range;
    jack_port_get_latency_range(p->ports[0], JackPlaybackLatency,
                                &jack_latency_range);
    atomic_store(&p->graph_latency_max, jack_latency_range.max);

    return 0;
}

__attribute__((used)) static int buffer_size_cb(jack_nframes_t nframes, void *arg)
{
    struct ao *ao = arg;
    struct priv *p = ao->priv;

    atomic_store(&p->buffer_size, nframes);

    return 0;
}

__attribute__((used)) static int process(jack_nframes_t nframes, void *arg)
{
    struct ao *ao = arg;
    struct priv *p = ao->priv;

    void *buffers[MP_NUM_CHANNELS];

    for (int i = 0; i < p->num_ports; i++)
        buffers[i] = jack_port_get_buffer(p->ports[i], nframes);

    jack_nframes_t jack_latency =
        atomic_load(&p->graph_latency_max) + atomic_load(&p->buffer_size);

    int64_t end_time = mp_time_us();
    end_time += (jack_latency + nframes) / (double)ao->samplerate * 1000000.0;

    ao_read_data(ao, buffers, nframes, end_time);

    return 0;
}

__attribute__((used)) static int
connect_to_outports(struct ao *ao)
{
    struct priv *p = ao->priv;

    char *port_name = (p->opts->port && p->opts->port[0]) ? p->opts->port : NULL;
    const char **matching_ports = NULL;
    int port_flags = JackPortIsInput;
    int i;

    if (!port_name)
        port_flags |= JackPortIsPhysical;

    const char *port_type = JACK_DEFAULT_AUDIO_TYPE; // exclude MIDI ports
    matching_ports = jack_get_ports(p->client, port_name, port_type, port_flags);

    if (!matching_ports || !matching_ports[0]) {
        MP_FATAL(ao, "no ports to connect to\n");
        goto err_get_ports;
    }

    for (i = 0; i < p->num_ports && matching_ports[i]; i++) {
        if (jack_connect(p->client, jack_port_name(p->ports[i]),
                         matching_ports[i]))
        {
            MP_FATAL(ao, "connecting failed\n");
            goto err_connect;
        }
    }

    free(matching_ports);
    return 0;

err_connect:
    free(matching_ports);
err_get_ports:
    return -1;
}

__attribute__((used)) static int
create_ports(struct ao *ao, int nports)
{
    struct priv *p = ao->priv;
    char pname[30];
    int i;

    for (i = 0; i < nports; i++) {
        snprintf(pname, sizeof(pname), "out_%d", i);
        p->ports[i] = jack_port_register(p->client, pname, JACK_DEFAULT_AUDIO_TYPE,
                                         JackPortIsOutput, 0);

        if (!p->ports[i]) {
            MP_FATAL(ao, "not enough ports available\n");
            goto err_port_register;
        }
    }

    p->num_ports = nports;
    return 0;

err_port_register:
    return -1;
}

__attribute__((used)) static void resume(struct ao *ao)
{
    struct priv *p = ao->priv;
    if (!p->activated) {
        p->activated = true;

        if (jack_activate(p->client))
            MP_FATAL(ao, "activate failed\n");

        if (p->opts->connect)
            connect_to_outports(ao);
    }
}

__attribute__((used)) static int init(struct ao *ao)
{
    struct priv *p = ao->priv;
    struct mp_chmap_sel sel = {0};
    jack_options_t open_options;

    p->opts = mp_get_config_group(ao, ao->global, &ao_jack_conf);

    ao->format = AF_FORMAT_FLOATP;

    switch (p->opts->stdlayout) {
    case 0:
        mp_chmap_sel_add_waveext(&sel);
        break;

    default:
        mp_chmap_sel_add_any(&sel);
    }

    if (!ao_chmap_sel_adjust(ao, &sel, &ao->channels))
        goto err_chmap;

    open_options = JackNullOption;
    if (!p->opts->autostart)
        open_options |= JackNoStartServer;

    p->client = jack_client_open(p->opts->client_name, open_options, NULL);
    if (!p->client) {
        MP_FATAL(ao, "cannot open server\n");
        goto err_client_open;
    }

    if (create_ports(ao, ao->channels.num))
        goto err_create_ports;

    jack_set_process_callback(p->client, process, ao);

    ao->samplerate = jack_get_sample_rate(p->client);

    jack_set_buffer_size_callback(p->client, buffer_size_cb, ao);
    jack_set_graph_order_callback(p->client, graph_order_cb, ao);

    if (!ao_chmap_sel_get_def(ao, &sel, &ao->channels, p->num_ports))
        goto err_chmap_sel_get_def;

    return 0;

err_chmap_sel_get_def:
err_create_ports:
    jack_client_close(p->client);
err_client_open:
err_chmap:
    return -1;
}

__attribute__((used)) static void uninit(struct ao *ao)
{
    struct priv *p = ao->priv;

    jack_client_close(p->client);
}

