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
typedef  union socket_address {int dummy; } socket_address ;
typedef  int /*<<< orphan*/  time_t ;
struct mg_mgr {struct mg_connection* active_connections; } ;
struct mg_iface {struct mg_mgr* mgr; } ;
struct mg_connection {struct mg_connection* next; int /*<<< orphan*/  flags; int /*<<< orphan*/  sock; } ;
typedef  int /*<<< orphan*/  sock_t ;

/* Variables and functions */
 int /*<<< orphan*/  INVALID_SOCKET ; 
 int /*<<< orphan*/  MG_F_CLOSE_IMMEDIATELY ; 
 int /*<<< orphan*/  mg_if_poll (struct mg_connection*,double) ; 
 double mg_time () ; 

__attribute__((used)) static void mg_null_if_connect_tcp(struct mg_connection *c,
                                   const union socket_address *sa) {
  c->flags |= MG_F_CLOSE_IMMEDIATELY;
  (void) sa;
}

__attribute__((used)) static void mg_null_if_connect_udp(struct mg_connection *c) {
  c->flags |= MG_F_CLOSE_IMMEDIATELY;
}

__attribute__((used)) static int mg_null_if_listen_tcp(struct mg_connection *c,
                                 union socket_address *sa) {
  (void) c;
  (void) sa;
  return -1;
}

__attribute__((used)) static int mg_null_if_listen_udp(struct mg_connection *c,
                                 union socket_address *sa) {
  (void) c;
  (void) sa;
  return -1;
}

__attribute__((used)) static int mg_null_if_tcp_send(struct mg_connection *c, const void *buf,
                               size_t len) {
  (void) c;
  (void) buf;
  (void) len;
  return -1;
}

__attribute__((used)) static int mg_null_if_udp_send(struct mg_connection *c, const void *buf,
                               size_t len) {
  (void) c;
  (void) buf;
  (void) len;
  return -1;
}

int mg_null_if_tcp_recv(struct mg_connection *c, void *buf, size_t len) {
  (void) c;
  (void) buf;
  (void) len;
  return -1;
}

int mg_null_if_udp_recv(struct mg_connection *c, void *buf, size_t len,
                        union socket_address *sa, size_t *sa_len) {
  (void) c;
  (void) buf;
  (void) len;
  (void) sa;
  (void) sa_len;
  return -1;
}

__attribute__((used)) static int mg_null_if_create_conn(struct mg_connection *c) {
  (void) c;
  return 1;
}

__attribute__((used)) static void mg_null_if_destroy_conn(struct mg_connection *c) {
  (void) c;
}

__attribute__((used)) static void mg_null_if_sock_set(struct mg_connection *c, sock_t sock) {
  (void) c;
  (void) sock;
}

__attribute__((used)) static void mg_null_if_init(struct mg_iface *iface) {
  (void) iface;
}

__attribute__((used)) static void mg_null_if_free(struct mg_iface *iface) {
  (void) iface;
}

__attribute__((used)) static void mg_null_if_add_conn(struct mg_connection *c) {
  c->sock = INVALID_SOCKET;
  c->flags |= MG_F_CLOSE_IMMEDIATELY;
}

__attribute__((used)) static void mg_null_if_remove_conn(struct mg_connection *c) {
  (void) c;
}

__attribute__((used)) static time_t mg_null_if_poll(struct mg_iface *iface, int timeout_ms) {
  struct mg_mgr *mgr = iface->mgr;
  struct mg_connection *nc, *tmp;
  double now = mg_time();
  /* We basically just run timers and poll. */
  for (nc = mgr->active_connections; nc != NULL; nc = tmp) {
    tmp = nc->next;
    mg_if_poll(nc, now);
  }
  (void) timeout_ms;
  return (time_t) now;
}

__attribute__((used)) static void mg_null_if_get_conn_addr(struct mg_connection *c, int remote,
                                     union socket_address *sa) {
  (void) c;
  (void) remote;
  (void) sa;
}

