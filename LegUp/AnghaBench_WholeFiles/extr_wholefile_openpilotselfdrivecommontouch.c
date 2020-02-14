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
struct pollfd {scalar_t__ fd; int events; int revents; } ;
struct input_event {int type; int code; int value; } ;
struct dirent {int /*<<< orphan*/  d_name; } ;
typedef  int /*<<< orphan*/  event ;
typedef  int /*<<< orphan*/  ev_bits ;
struct TYPE_5__ {int fd; int last_x; int last_y; } ;
typedef  TYPE_1__ TouchState ;
typedef  int /*<<< orphan*/  DIR ;

/* Variables and functions */
 int ABS_MT_POSITION_X ; 
 int ABS_MT_POSITION_Y ; 
 int /*<<< orphan*/  EVIOCGBIT (int,int) ; 
#define  EV_ABS 128 
 int KEY_MAX ; 
 int /*<<< orphan*/  O_RDONLY ; 
 int POLLIN ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  close (int) ; 
 int /*<<< orphan*/  closedir (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dirfd (int /*<<< orphan*/ *) ; 
 int ioctl (int,int /*<<< orphan*/ ,unsigned char*) ; 
 int openat (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * opendir (char*) ; 
 int poll (struct pollfd*,int,int) ; 
 int read (scalar_t__,struct input_event*,int) ; 
 struct dirent* readdir (int /*<<< orphan*/ *) ; 
 scalar_t__ strncmp (int /*<<< orphan*/ ,char*,int) ; 

__attribute__((used)) static int find_dev() {
  int err;

  int ret = -1;

  DIR *dir = opendir("/dev/input");
  assert(dir);
  struct dirent* de = NULL;
  while ((de = readdir(dir))) {
    if (strncmp(de->d_name, "event", 5)) continue;

    int fd = openat(dirfd(dir), de->d_name, O_RDONLY);
    assert(fd >= 0);

    unsigned char ev_bits[KEY_MAX / 8 + 1];
    err = ioctl(fd, EVIOCGBIT(EV_ABS, sizeof(ev_bits)), ev_bits);
    assert(err >= 0);

    const int x_key = ABS_MT_POSITION_X / 8;
    const int y_key = ABS_MT_POSITION_Y / 8;
    if ((ev_bits[x_key] & (ABS_MT_POSITION_X - x_key)) &&
        (ev_bits[y_key] & (ABS_MT_POSITION_Y - y_key))) {
      ret = fd;
      break;
    }
    close(fd);
  }
  closedir(dir);

  return ret;
}

void touch_init(TouchState *s) {
  s->fd = find_dev();
  assert(s->fd >= 0);
}

int touch_poll(TouchState *s, int* out_x, int* out_y, int timeout) {
  assert(out_x && out_y);
  bool up = false;
  while (true) {
    struct pollfd polls[] = {{
      .fd = s->fd,
      .events = POLLIN,
    }};
    int err = poll(polls, 1, timeout);
    if (err < 0) {
      return -1;
    }
    if (!(polls[0].revents & POLLIN)) {
      break;
    }

    struct input_event event;
    err = read(polls[0].fd, &event, sizeof(event));
    if (err < sizeof(event)) {
      return -1;
    }

    switch (event.type) { 
    case EV_ABS:
      if (event.code == ABS_MT_POSITION_X) {
        s->last_x = event.value;
      } else if (event.code == ABS_MT_POSITION_Y) {
        s->last_y = event.value;
      }
      up = true;
      break;
    default:
      break;
    }
  }
  if (up) {
    // adjust for flippening
    *out_x = s->last_y;
    *out_y = 1080 - s->last_x;
  }
  return up;
}

int touch_read(TouchState *s, int* out_x, int* out_y) {
  assert(out_x && out_y);
  struct input_event event;
  int err = read(s->fd, &event, sizeof(event));
  if (err < sizeof(event)) {
    return -1;
  }
  bool up = false;
  switch (event.type) { 
  case EV_ABS:
    if (event.code == ABS_MT_POSITION_X) {
      s->last_x = event.value;
    } else if (event.code == ABS_MT_POSITION_Y) {
      s->last_y = event.value;
    }
    up = true;
    break;
  default:
    break;
  }
  if (up) {
    // adjust for flippening
    *out_x = s->last_y;
    *out_y = 1080 - s->last_x;
  }
  return up;
}

