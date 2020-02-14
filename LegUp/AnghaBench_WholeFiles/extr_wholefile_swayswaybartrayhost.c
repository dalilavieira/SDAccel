#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_6__ ;
typedef  struct TYPE_14__   TYPE_5__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
struct swaybar_tray {int /*<<< orphan*/  bar; TYPE_6__* items; } ;
struct swaybar_sni {char* watcher_id; } ;
struct swaybar_host {void const* watcher_interface; void const* service; TYPE_5__* tray; } ;
typedef  int /*<<< orphan*/  sd_bus_message ;
struct TYPE_13__ {char* message; } ;
typedef  TYPE_1__ sd_bus_error ;
struct TYPE_15__ {int /*<<< orphan*/ * items; } ;
struct TYPE_14__ {int /*<<< orphan*/  bus; } ;

/* Variables and functions */
 int /*<<< orphan*/  SWAY_ERROR ; 
 int /*<<< orphan*/  SWAY_INFO ; 
 struct swaybar_sni* create_sni (char*,struct swaybar_tray*) ; 
 int /*<<< orphan*/  destroy_sni (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free (void const*) ; 
 int /*<<< orphan*/  list_add (TYPE_6__*,struct swaybar_sni*) ; 
 int /*<<< orphan*/  list_del (TYPE_6__*,int) ; 
 int list_seq_find (TYPE_6__*,int (*) (void const*,void const*),char*) ; 
 int sd_bus_call_method_async (int /*<<< orphan*/ ,int /*<<< orphan*/ *,void const*,int /*<<< orphan*/ ,char*,char*,int (*) (int /*<<< orphan*/ *,void*,TYPE_1__*),TYPE_5__*,char*,void const*,...) ; 
 int sd_bus_error_get_errno (TYPE_1__*) ; 
 int sd_bus_message_enter_container (int /*<<< orphan*/ *,char,int /*<<< orphan*/ *) ; 
 TYPE_1__* sd_bus_message_get_error (int /*<<< orphan*/ *) ; 
 scalar_t__ sd_bus_message_is_method_error (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int sd_bus_message_read (int /*<<< orphan*/ *,char*,char**,...) ; 
 int sd_bus_message_read_strv (int /*<<< orphan*/ *,char***) ; 
 int /*<<< orphan*/  sd_bus_release_name (int /*<<< orphan*/ ,void const*) ; 
 int /*<<< orphan*/  set_bar_dirty (int /*<<< orphan*/ ) ; 
 scalar_t__ strcmp (char*,void const*) ; 
 char* strerror (int) ; 
 int /*<<< orphan*/  sway_log (int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  watcher_path ; 

__attribute__((used)) static int cmp_sni_id(const void *item, const void *cmp_to) {
	const struct swaybar_sni *sni = item;
	return strcmp(sni->watcher_id, cmp_to);
}

__attribute__((used)) static void add_sni(struct swaybar_tray *tray, char *id) {
	int idx = list_seq_find(tray->items, cmp_sni_id, id);
	if (idx == -1) {
		sway_log(SWAY_INFO, "Registering Status Notifier Item '%s'", id);
		struct swaybar_sni *sni = create_sni(id, tray);
		if (sni) {
			list_add(tray->items, sni);
		}
	}
}

__attribute__((used)) static int handle_sni_registered(sd_bus_message *msg, void *data,
		sd_bus_error *error) {
	char *id;
	int ret = sd_bus_message_read(msg, "s", &id);
	if (ret < 0) {
		sway_log(SWAY_ERROR, "Failed to parse register SNI message: %s", strerror(-ret));
	}

	struct swaybar_tray *tray = data;
	add_sni(tray, id);

	return ret;
}

__attribute__((used)) static int handle_sni_unregistered(sd_bus_message *msg, void *data,
		sd_bus_error *error) {
	char *id;
	int ret = sd_bus_message_read(msg, "s", &id);
	if (ret < 0) {
		sway_log(SWAY_ERROR, "Failed to parse unregister SNI message: %s", strerror(-ret));
	}

	struct swaybar_tray *tray = data;
	int idx = list_seq_find(tray->items, cmp_sni_id, id);
	if (idx != -1) {
		sway_log(SWAY_INFO, "Unregistering Status Notifier Item '%s'", id);
		destroy_sni(tray->items->items[idx]);
		list_del(tray->items, idx);
		set_bar_dirty(tray->bar);
	}
	return ret;
}

__attribute__((used)) static int get_registered_snis_callback(sd_bus_message *msg, void *data,
		sd_bus_error *error) {
	if (sd_bus_message_is_method_error(msg, NULL)) {
		sd_bus_error err = *sd_bus_message_get_error(msg);
		sway_log(SWAY_ERROR, "Failed to get registered SNIs: %s", err.message);
		return -sd_bus_error_get_errno(&err);
	}

	int ret = sd_bus_message_enter_container(msg, 'v', NULL);
	if (ret < 0) {
		sway_log(SWAY_ERROR, "Failed to read registered SNIs: %s", strerror(-ret));
		return ret;
	}

	char **ids;
	ret = sd_bus_message_read_strv(msg, &ids);
	if (ret < 0) {
		sway_log(SWAY_ERROR, "Failed to read registered SNIs: %s", strerror(-ret));
		return ret;
	}

	if (ids) {
		struct swaybar_tray *tray = data;
		for (char **id = ids; *id; ++id) {
			add_sni(tray, *id);
		}
	}

	return ret;
}

__attribute__((used)) static bool register_to_watcher(struct swaybar_host *host) {
	// this is called asynchronously in case the watcher is owned by this process
	int ret = sd_bus_call_method_async(host->tray->bus, NULL,
			host->watcher_interface, watcher_path, host->watcher_interface,
			"RegisterStatusNotifierHost", NULL, NULL, "s", host->service);
	if (ret < 0) {
		sway_log(SWAY_ERROR, "Failed to send register call: %s", strerror(-ret));
		return false;
	}

	ret = sd_bus_call_method_async(host->tray->bus, NULL,
			host->watcher_interface, watcher_path,
			"org.freedesktop.DBus.Properties", "Get",
			get_registered_snis_callback, host->tray, "ss",
			host->watcher_interface, "RegisteredStatusNotifierItems");
	if (ret < 0) {
		sway_log(SWAY_ERROR, "Failed to get registered SNIs: %s", strerror(-ret));
	}

	return ret >= 0;
}

__attribute__((used)) static int handle_new_watcher(sd_bus_message *msg,
		void *data, sd_bus_error *error) {
	char *service, *old_owner, *new_owner;
	int ret = sd_bus_message_read(msg, "sss", &service, &old_owner, &new_owner);
	if (ret < 0) {
		sway_log(SWAY_ERROR, "Failed to parse owner change message: %s", strerror(-ret));
		return ret;
	}

	if (!*old_owner) {
		struct swaybar_host *host = data;
		if (strcmp(service, host->watcher_interface) == 0) {
			register_to_watcher(host);
		}
	}

	return 0;
}

void finish_host(struct swaybar_host *host) {
	sd_bus_release_name(host->tray->bus, host->service);
	free(host->service);
	free(host->watcher_interface);
}

