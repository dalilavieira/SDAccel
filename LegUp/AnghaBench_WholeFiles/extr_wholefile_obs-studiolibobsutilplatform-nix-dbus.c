#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  char wchar_t ;
struct service_info {char* uninhibit; int /*<<< orphan*/  name; int /*<<< orphan*/  path; } ;
struct dbus_sleep_info {int type; scalar_t__ id; int /*<<< orphan*/  c; int /*<<< orphan*/ * pending; struct service_info const* service; } ;
typedef  enum service_type { ____Placeholder_service_type } service_type ;
typedef  int dbus_uint32_t ;
typedef  scalar_t__ dbus_bool_t ;
struct TYPE_4__ {int /*<<< orphan*/  message; } ;
typedef  int /*<<< orphan*/  DBusMessage ;
typedef  TYPE_1__ DBusError ;

/* Variables and functions */
 int /*<<< orphan*/  DBUS_BUS_SESSION ; 
 int /*<<< orphan*/  DBUS_TYPE_INVALID ; 
 int /*<<< orphan*/  DBUS_TYPE_STRING ; 
 int /*<<< orphan*/  DBUS_TYPE_UINT32 ; 
#define  GNOME_SM 129 
 int /*<<< orphan*/  LOG_DEBUG ; 
 int /*<<< orphan*/  LOG_ERROR ; 
#define  MATE_SM 128 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  bfree (struct dbus_sleep_info*) ; 
 int /*<<< orphan*/  blog (int /*<<< orphan*/ ,char*,...) ; 
 void* bmalloc (size_t) ; 
 scalar_t__ bmemdup (char const*,size_t) ; 
 int /*<<< orphan*/  dbus_bus_get_private (int /*<<< orphan*/ ,TYPE_1__*) ; 
 scalar_t__ dbus_bus_name_has_owner (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dbus_connection_close (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dbus_connection_flush (int /*<<< orphan*/ ) ; 
 scalar_t__ dbus_connection_send (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ dbus_connection_send_with_reply (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ **,int) ; 
 int /*<<< orphan*/  dbus_connection_unref (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dbus_error_init (TYPE_1__*) ; 
 scalar_t__ dbus_message_append_args (int /*<<< orphan*/ *,int /*<<< orphan*/ ,...) ; 
 scalar_t__ dbus_message_get_args (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * dbus_message_new_method_call (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  dbus_message_unref (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dbus_pending_call_block (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dbus_pending_call_cancel (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * dbus_pending_call_steal_reply (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dbus_pending_call_unref (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memset (void*,int /*<<< orphan*/ ,size_t) ; 
 size_t num_services ; 
 struct service_info* services ; 
 size_t strlen (char const*) ; 
 size_t wcslen (char const*) ; 

__attribute__((used)) static inline void *bzalloc(size_t size)
{
	void *mem = bmalloc(size);
	if (mem)
		memset(mem, 0, size);
	return mem;
}

__attribute__((used)) static inline char *bstrdup_n(const char *str, size_t n)
{
	char *dup;
	if (!str)
		return NULL;

	dup = (char*)bmemdup(str, n+1);
	dup[n] = 0;

	return dup;
}

__attribute__((used)) static inline wchar_t *bwstrdup_n(const wchar_t *str, size_t n)
{
	wchar_t *dup;
	if (!str)
		return NULL;

	dup = (wchar_t*)bmemdup(str, (n+1) * sizeof(wchar_t));
	dup[n] = 0;

	return dup;
}

__attribute__((used)) static inline char *bstrdup(const char *str)
{
	if (!str)
		return NULL;

	return bstrdup_n(str, strlen(str));
}

__attribute__((used)) static inline wchar_t *bwstrdup(const wchar_t *str)
{
	if (!str)
		return NULL;

	return bwstrdup_n(str, wcslen(str));
}

void dbus_sleep_info_destroy(struct dbus_sleep_info *info)
{
	if (info) {
		if (info->pending) {
			dbus_pending_call_cancel(info->pending);
			dbus_pending_call_unref(info->pending);
		}

		dbus_connection_close(info->c);
		dbus_connection_unref(info->c);
		bfree(info);
	}
}

struct dbus_sleep_info *dbus_sleep_info_create(void)
{
	struct dbus_sleep_info *info = bzalloc(sizeof(*info));
	DBusError err;

	dbus_error_init(&err);

	info->c = dbus_bus_get_private(DBUS_BUS_SESSION, &err);
	if (!info->c) {
		blog(LOG_ERROR, "Could not create dbus connection: %s",
				err.message);
		bfree(info);
		return NULL;
	}

	for (size_t i = 0; i < num_services; i++) {
		const struct service_info *service = &services[i];

		if (!service->name)
			continue;

		if (dbus_bus_name_has_owner(info->c, service->name, NULL)) {
			blog(LOG_DEBUG, "Found dbus service: %s",
					service->name);
			info->service = service;
			info->type = (enum service_type)i;
			return info;
		}
	}

	dbus_sleep_info_destroy(info);
	return NULL;
}

void dbus_inhibit_sleep(struct dbus_sleep_info *info, const char *reason,
		bool active)
{
	DBusMessage *reply;
	const char *method;
	dbus_bool_t success;

	if (info->pending) {

		dbus_pending_call_block(info->pending);
		reply = dbus_pending_call_steal_reply(info->pending);
		dbus_pending_call_unref(info->pending);
		info->pending = NULL;

		if (reply) {
			success = dbus_message_get_args(reply, NULL,
					DBUS_TYPE_UINT32, &info->id,
					DBUS_TYPE_INVALID);
			if (!success)
				info->id = 0;
			dbus_message_unref(reply);
		}
	}

	if (active == !!info->id)
		return;

	method = active ? "Inhibit" : info->service->uninhibit;

	reply = dbus_message_new_method_call(info->service->name,
			info->service->path, info->service->name, method);
	if (reply == NULL) {
		blog(LOG_ERROR, "dbus_message_new_method_call failed");
		return;
	}

	if (active) {
		const char *program = "libobs";
		dbus_uint32_t flags = 0xC;
		dbus_uint32_t xid = 0;

		assert(info->id == 0);

		switch (info->type) {
		case MATE_SM:
		case GNOME_SM:
			success = dbus_message_append_args(reply,
					DBUS_TYPE_STRING, &program,
					DBUS_TYPE_UINT32, &xid,
					DBUS_TYPE_STRING, &reason,
					DBUS_TYPE_UINT32, &flags,
					DBUS_TYPE_INVALID);
			break;
		default:
			success = dbus_message_append_args(reply,
					DBUS_TYPE_STRING, &program,
					DBUS_TYPE_STRING, &reason,
					DBUS_TYPE_INVALID);
		}

		if (success) {
			success = dbus_connection_send_with_reply(info->c,
					reply, &info->pending, -1);
			if (!success)
				info->pending = NULL;
		}
	} else {
		assert(info->id != 0);
		success = dbus_message_append_args(reply,
				DBUS_TYPE_UINT32, &info->id,
				DBUS_TYPE_INVALID);
		if (success)
			success = dbus_connection_send(info->c, reply, NULL);
		if (!success)
			info->id = 0;
	}

	dbus_connection_flush(info->c);
	dbus_message_unref(reply);
}

