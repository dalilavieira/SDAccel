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
typedef  int uint32_t ;
struct swaybar_tray {TYPE_2__* items; int /*<<< orphan*/  basedirs; int /*<<< orphan*/  themes; int /*<<< orphan*/ * bus; void* watcher_kde; void* watcher_xdg; int /*<<< orphan*/  host_kde; int /*<<< orphan*/  host_xdg; int /*<<< orphan*/  fd; struct swaybar* bar; } ;
struct swaybar_output {int scale; TYPE_1__* bar; scalar_t__ height; int /*<<< orphan*/  name; int /*<<< orphan*/  identifier; } ;
struct swaybar_config {int tray_padding; scalar_t__ tray_outputs; } ;
struct swaybar {int dummy; } ;
typedef  int /*<<< orphan*/  sd_bus_message ;
typedef  int /*<<< orphan*/  sd_bus_error ;
typedef  int /*<<< orphan*/  sd_bus ;
typedef  int /*<<< orphan*/  cairo_t ;
struct TYPE_5__ {int length; int /*<<< orphan*/ * items; } ;
struct TYPE_4__ {struct swaybar_tray* tray; struct swaybar_config* config; } ;

/* Variables and functions */
 int /*<<< orphan*/  SWAY_DEBUG ; 
 int /*<<< orphan*/  SWAY_ERROR ; 
 struct swaybar_tray* calloc (int,int) ; 
 TYPE_2__* create_list () ; 
 void* create_watcher (char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  destroy_sni (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  destroy_watcher (void*) ; 
 int /*<<< orphan*/  finish_host (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  finish_themes (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free (struct swaybar_tray*) ; 
 int /*<<< orphan*/  init_host (int /*<<< orphan*/ *,char*,struct swaybar_tray*) ; 
 int /*<<< orphan*/  init_themes (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  list_free (TYPE_2__*) ; 
 int list_seq_find (scalar_t__,int (*) (void const*,void const*),struct swaybar_output*) ; 
 int render_sni (int /*<<< orphan*/ *,struct swaybar_output*,double*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sd_bus_flush_close_unref (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sd_bus_get_fd (int /*<<< orphan*/ *) ; 
 int sd_bus_match_signal (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*,char*,char*,char*,int (*) (int /*<<< orphan*/ *,void*,int /*<<< orphan*/ *),struct swaybar_tray*) ; 
 int sd_bus_message_read (int /*<<< orphan*/ *,char*,char**,char**,char**) ; 
 int sd_bus_open_user (int /*<<< orphan*/ **) ; 
 int sd_bus_process (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int strcmp (void const*,char*) ; 
 int /*<<< orphan*/  strerror (int) ; 
 int /*<<< orphan*/  sway_log (int /*<<< orphan*/ ,char*,...) ; 

__attribute__((used)) static int handle_lost_watcher(sd_bus_message *msg,
		void *data, sd_bus_error *error) {
	char *service, *old_owner, *new_owner;
	int ret = sd_bus_message_read(msg, "sss", &service, &old_owner, &new_owner);
	if (ret < 0) {
		sway_log(SWAY_ERROR, "Failed to parse owner change message: %s", strerror(-ret));
		return ret;
	}

	if (!*new_owner) {
		struct swaybar_tray *tray = data;
		if (strcmp(service, "org.freedesktop.StatusNotifierWatcher") == 0) {
			tray->watcher_xdg = create_watcher("freedesktop", tray->bus);
		} else if (strcmp(service, "org.kde.StatusNotifierWatcher") == 0) {
			tray->watcher_kde = create_watcher("kde", tray->bus);
		}
	}

	return 0;
}

struct swaybar_tray *create_tray(struct swaybar *bar) {
	sway_log(SWAY_DEBUG, "Initializing tray");

	sd_bus *bus;
	int ret = sd_bus_open_user(&bus);
	if (ret < 0) {
		sway_log(SWAY_ERROR, "Failed to connect to user bus: %s", strerror(-ret));
		return NULL;
	}

	struct swaybar_tray *tray = calloc(1, sizeof(struct swaybar_tray));
	if (!tray) {
		return NULL;
	}
	tray->bar = bar;
	tray->bus = bus;
	tray->fd = sd_bus_get_fd(tray->bus);

	tray->watcher_xdg = create_watcher("freedesktop", tray->bus);
	tray->watcher_kde = create_watcher("kde", tray->bus);

	ret = sd_bus_match_signal(bus, NULL, "org.freedesktop.DBus",
			"/org/freedesktop/DBus", "org.freedesktop.DBus",
			"NameOwnerChanged", handle_lost_watcher, tray);
	if (ret < 0) {
		sway_log(SWAY_ERROR, "Failed to subscribe to unregistering events: %s",
				strerror(-ret));
	}

	tray->items = create_list();

	init_host(&tray->host_xdg, "freedesktop", tray);
	init_host(&tray->host_kde, "kde", tray);

	init_themes(&tray->themes, &tray->basedirs);

	return tray;
}

void destroy_tray(struct swaybar_tray *tray) {
	if (!tray) {
		return;
	}
	finish_host(&tray->host_xdg);
	finish_host(&tray->host_kde);
	for (int i = 0; i < tray->items->length; ++i) {
		destroy_sni(tray->items->items[i]);
	}
	list_free(tray->items);
	destroy_watcher(tray->watcher_xdg);
	destroy_watcher(tray->watcher_kde);
	sd_bus_flush_close_unref(tray->bus);
	finish_themes(tray->themes, tray->basedirs);
	free(tray);
}

void tray_in(int fd, short mask, void *data) {
	sd_bus *bus = data;
	int ret;
	while ((ret = sd_bus_process(bus, NULL)) > 0) {
		// This space intentionally left blank
	}
	if (ret < 0) {
		sway_log(SWAY_ERROR, "Failed to process bus: %s", strerror(-ret));
	}
}

__attribute__((used)) static int cmp_output(const void *item, const void *cmp_to) {
	const struct swaybar_output *output = cmp_to;
	if (output->identifier && strcmp(item, output->identifier) == 0) {
		return 0;
	}
	return strcmp(item, output->name);
}

uint32_t render_tray(cairo_t *cairo, struct swaybar_output *output, double *x) {
	struct swaybar_config *config = output->bar->config;
	if (config->tray_outputs) {
		if (list_seq_find(config->tray_outputs, cmp_output, output) == -1) {
			return 0;
		}
	} // else display on all

	if ((int) output->height*output->scale <= 2*config->tray_padding) {
		return 2*config->tray_padding + 1;
	}

	uint32_t max_height = 0;
	struct swaybar_tray *tray = output->bar->tray;
	for (int i = 0; i < tray->items->length; ++i) {
		uint32_t h = render_sni(cairo, output, x, tray->items->items[i]);
		max_height = h > max_height ? h : max_height;
	}

	return max_height;
}

