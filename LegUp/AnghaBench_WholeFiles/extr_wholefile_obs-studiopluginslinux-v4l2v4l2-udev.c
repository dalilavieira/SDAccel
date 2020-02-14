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
struct udev_monitor {int dummy; } ;
struct udev_device {int dummy; } ;
struct udev {int dummy; } ;
struct timeval {int tv_sec; scalar_t__ tv_usec; } ;
struct calldata {int dummy; } ;
typedef  int /*<<< orphan*/  signal_handler_t ;
typedef  int /*<<< orphan*/  fd_set ;
typedef  enum udev_action { ____Placeholder_udev_action } udev_action ;

/* Variables and functions */
 scalar_t__ EAGAIN ; 
 int /*<<< orphan*/  FD_SET (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FD_ZERO (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  OS_EVENT_TYPE_MANUAL ; 
#define  UDEV_ACTION_ADDED 129 
#define  UDEV_ACTION_REMOVED 128 
 int UDEV_ACTION_UNKNOWN ; 
 int /*<<< orphan*/  UNUSED_PARAMETER (void*) ; 
 int /*<<< orphan*/  calldata_free (struct calldata*) ; 
 int /*<<< orphan*/  calldata_init (struct calldata*) ; 
 int /*<<< orphan*/  calldata_set_string (struct calldata*,char*,char const*) ; 
 int /*<<< orphan*/  os_event_destroy (int /*<<< orphan*/ ) ; 
 scalar_t__ os_event_init (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  os_event_signal (int /*<<< orphan*/ ) ; 
 scalar_t__ os_event_try (int /*<<< orphan*/ ) ; 
 scalar_t__ pthread_create (int /*<<< orphan*/ *,int /*<<< orphan*/ *,void* (*) (void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_join (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ select (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct timeval*) ; 
 int /*<<< orphan*/  signal_handler_add_array (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * signal_handler_create () ; 
 int /*<<< orphan*/  signal_handler_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  signal_handler_signal (int /*<<< orphan*/ *,char*,struct calldata*) ; 
 int /*<<< orphan*/  strncmp (char*,char const*,int) ; 
 char* udev_device_get_action (struct udev_device*) ; 
 char* udev_device_get_devnode (struct udev_device*) ; 
 int /*<<< orphan*/  udev_device_unref (struct udev_device*) ; 
 int /*<<< orphan*/  udev_event ; 
 scalar_t__ udev_monitor_enable_receiving (struct udev_monitor*) ; 
 int /*<<< orphan*/  udev_monitor_filter_add_match_subsystem_devtype (struct udev_monitor*,char*,int /*<<< orphan*/ *) ; 
 int udev_monitor_get_fd (struct udev_monitor*) ; 
 struct udev_monitor* udev_monitor_new_from_netlink (struct udev*,char*) ; 
 struct udev_device* udev_monitor_receive_device (struct udev_monitor*) ; 
 int /*<<< orphan*/  udev_monitor_unref (struct udev_monitor*) ; 
 int /*<<< orphan*/  udev_mutex ; 
 struct udev* udev_new () ; 
 scalar_t__ udev_refs ; 
 int /*<<< orphan*/ * udev_signalhandler ; 
 int /*<<< orphan*/  udev_signals ; 
 int /*<<< orphan*/  udev_thread ; 
 int /*<<< orphan*/  udev_unref (struct udev*) ; 

__attribute__((used)) static enum udev_action udev_action_to_enum(const char *action)
{
	if (!action)
		return UDEV_ACTION_UNKNOWN;

	if (!strncmp("add", action, 3))
		return UDEV_ACTION_ADDED;
	if (!strncmp("remove", action, 6))
		return UDEV_ACTION_REMOVED;

	return UDEV_ACTION_UNKNOWN;
}

__attribute__((used)) static inline void udev_signal_event(struct udev_device *dev)
{
	const char *node;
	enum udev_action action;
	struct calldata data;

	pthread_mutex_lock(&udev_mutex);

	node   = udev_device_get_devnode(dev);
	action = udev_action_to_enum(udev_device_get_action(dev));

	calldata_init(&data);

	calldata_set_string(&data, "device", node);

	switch (action) {
	case UDEV_ACTION_ADDED:
		signal_handler_signal(udev_signalhandler,
				"device_added", &data);
		break;
	case UDEV_ACTION_REMOVED:
		signal_handler_signal(udev_signalhandler,
				"device_removed", &data);
		break;
	default:
		break;
	}

	calldata_free(&data);

	pthread_mutex_unlock(&udev_mutex);
}

__attribute__((used)) static void *udev_event_thread(void *vptr)
{
	UNUSED_PARAMETER(vptr);

	int fd;
	fd_set fds;
	struct timeval tv;
	struct udev *udev;
	struct udev_monitor *mon;
	struct udev_device *dev;

	/* set up udev monitoring */
	udev = udev_new();
	mon  = udev_monitor_new_from_netlink(udev, "udev");
	udev_monitor_filter_add_match_subsystem_devtype(
			mon, "video4linux", NULL);
	if (udev_monitor_enable_receiving(mon) < 0)
		return NULL;

	/* set up fds */
	fd = udev_monitor_get_fd(mon);

	while (os_event_try(udev_event) == EAGAIN) {
		FD_ZERO(&fds);
		FD_SET(fd, &fds);
		tv.tv_sec  = 1;
		tv.tv_usec = 0;

		if (select(fd + 1, &fds, NULL, NULL, &tv) <= 0)
			continue;

		dev = udev_monitor_receive_device(mon);
		if (!dev)
			continue;

		udev_signal_event(dev);

		udev_device_unref(dev);
	}

	udev_monitor_unref(mon);
	udev_unref(udev);

	return NULL;
}

void v4l2_init_udev(void)
{
	pthread_mutex_lock(&udev_mutex);

	/* set up udev */
	if (udev_refs == 0) {
		if (os_event_init(&udev_event, OS_EVENT_TYPE_MANUAL) != 0)
			goto fail;
		if (pthread_create(&udev_thread, NULL, udev_event_thread,
				NULL) != 0)
			goto fail;

		udev_signalhandler = signal_handler_create();
		if (!udev_signalhandler)
			goto fail;
		signal_handler_add_array(udev_signalhandler, udev_signals);

	}
	udev_refs++;

fail:
	pthread_mutex_unlock(&udev_mutex);
}

void v4l2_unref_udev(void)
{
	pthread_mutex_lock(&udev_mutex);

	/* unref udev monitor */
	if (udev_refs && --udev_refs == 0) {
		os_event_signal(udev_event);
		pthread_join(udev_thread, NULL);
		os_event_destroy(udev_event);

		if (udev_signalhandler)
			signal_handler_destroy(udev_signalhandler);
		udev_signalhandler = NULL;
	}

	pthread_mutex_unlock(&udev_mutex);
}

signal_handler_t *v4l2_get_udev_signalhandler(void)
{
	return udev_signalhandler;
}

