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
struct mg_mgr {int num_ifaces; struct mg_connection* active_connections; struct mg_iface** ifaces; } ;
struct mg_iface_vtable {int dummy; } ;
struct mg_iface {struct mg_iface_vtable const* vtable; int /*<<< orphan*/ * data; struct mg_mgr* mgr; } ;
struct mg_connection {double ev_timer_time; struct mg_connection* next; } ;

/* Variables and functions */
 scalar_t__ MG_CALLOC (int,int) ; 

struct mg_iface *mg_if_create_iface(const struct mg_iface_vtable *vtable,
                                    struct mg_mgr *mgr) {
  struct mg_iface *iface = (struct mg_iface *) MG_CALLOC(1, sizeof(*iface));
  iface->mgr = mgr;
  iface->data = NULL;
  iface->vtable = vtable;
  return iface;
}

struct mg_iface *mg_find_iface(struct mg_mgr *mgr,
                               const struct mg_iface_vtable *vtable,
                               struct mg_iface *from) {
  int i = 0;
  if (from != NULL) {
    for (i = 0; i < mgr->num_ifaces; i++) {
      if (mgr->ifaces[i] == from) {
        i++;
        break;
      }
    }
  }

  for (; i < mgr->num_ifaces; i++) {
    if (mgr->ifaces[i]->vtable == vtable) {
      return mgr->ifaces[i];
    }
  }
  return NULL;
}

double mg_mgr_min_timer(const struct mg_mgr *mgr) {
  double min_timer = 0;
  struct mg_connection *nc;
  for (nc = mgr->active_connections; nc != NULL; nc = nc->next) {
    if (nc->ev_timer_time <= 0) continue;
    if (min_timer == 0 || nc->ev_timer_time < min_timer) {
      min_timer = nc->ev_timer_time;
    }
  }
  return min_timer;
}

