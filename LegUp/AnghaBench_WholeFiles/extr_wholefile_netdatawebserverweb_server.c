#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct web_client {int acl; int port_acl; char* origin; char* cookie1; char* cookie2; int /*<<< orphan*/ * user_agent; int /*<<< orphan*/  ifd; int /*<<< orphan*/  id; int /*<<< orphan*/  client_port; int /*<<< orphan*/  client_ip; } ;
typedef  int WEB_SERVER_MODE ;
struct TYPE_3__ {int* fds_acl_flags; int /*<<< orphan*/ * fds_names; scalar_t__ opened; } ;
typedef  int /*<<< orphan*/  BUFFER ;

/* Variables and functions */
 int D_WEB_CLIENT ; 
 int /*<<< orphan*/  IPPROTO_TCP ; 
 int /*<<< orphan*/  SOL_SOCKET ; 
 int /*<<< orphan*/  SO_KEEPALIVE ; 
 int /*<<< orphan*/  TCP_NODELAY ; 
 int WEB_CLIENT_ACL_BADGE ; 
 int WEB_CLIENT_ACL_DASHBOARD ; 
 int WEB_CLIENT_ACL_MGMT ; 
 int WEB_CLIENT_ACL_NETDATACONF ; 
 int WEB_CLIENT_ACL_NOCHECK ; 
 int WEB_CLIENT_ACL_NONE ; 
 int WEB_CLIENT_ACL_REGISTRY ; 
 int WEB_CLIENT_ACL_STREAMING ; 
#define  WEB_SERVER_MODE_NONE 129 
#define  WEB_SERVER_MODE_STATIC_THREADED 128 
 TYPE_1__ api_sockets ; 
 int /*<<< orphan*/ * buffer_create (int) ; 
 int /*<<< orphan*/  buffer_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  buffer_reset (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  buffer_strcat (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  buffer_tostring (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  debug (int,char*,int,int /*<<< orphan*/ ,...) ; 
 int debug_flags ; 
 int /*<<< orphan*/  fatal (char*) ; 
 int /*<<< orphan*/  freez (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gettid () ; 
 int listen_sockets_setup (TYPE_1__*) ; 
 int /*<<< orphan*/  log_access (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*) ; 
 scalar_t__ setsockopt (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int) ; 
 scalar_t__ simple_pattern_matches (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  web_allow_badges_from ; 
 int /*<<< orphan*/  web_allow_dashboard_from ; 
 int /*<<< orphan*/  web_allow_mgmt_from ; 
 int /*<<< orphan*/  web_allow_netdataconf_from ; 
 int /*<<< orphan*/  web_allow_registry_from ; 
 int /*<<< orphan*/  web_allow_streaming_from ; 
 int /*<<< orphan*/  web_client_cache_verify (int /*<<< orphan*/ ) ; 
 scalar_t__ web_client_check_tcp (struct web_client*) ; 
 int /*<<< orphan*/  web_client_enable_wait_receive (struct web_client*) ; 

WEB_SERVER_MODE web_server_mode_id(const char *mode) {
    if(!strcmp(mode, "none"))
        return WEB_SERVER_MODE_NONE;
    else
        return WEB_SERVER_MODE_STATIC_THREADED;

}

const char *web_server_mode_name(WEB_SERVER_MODE id) {
    switch(id) {
        case WEB_SERVER_MODE_NONE:
            return "none";
        default:
        case WEB_SERVER_MODE_STATIC_THREADED:
            return "static-threaded";
    }
}

void debug_sockets() {
	BUFFER *wb = buffer_create(256 * sizeof(char));
	int i;

	for(i = 0 ; i < (int)api_sockets.opened ; i++) {
		buffer_strcat(wb, (api_sockets.fds_acl_flags[i] & WEB_CLIENT_ACL_NOCHECK)?"NONE ":"");
		buffer_strcat(wb, (api_sockets.fds_acl_flags[i] & WEB_CLIENT_ACL_DASHBOARD)?"dashboard ":"");
		buffer_strcat(wb, (api_sockets.fds_acl_flags[i] & WEB_CLIENT_ACL_REGISTRY)?"registry ":"");
		buffer_strcat(wb, (api_sockets.fds_acl_flags[i] & WEB_CLIENT_ACL_BADGE)?"badges ":"");
		buffer_strcat(wb, (api_sockets.fds_acl_flags[i] & WEB_CLIENT_ACL_MGMT)?"management ":"");
		buffer_strcat(wb, (api_sockets.fds_acl_flags[i] & WEB_CLIENT_ACL_STREAMING)?"streaming ":"");
		buffer_strcat(wb, (api_sockets.fds_acl_flags[i] & WEB_CLIENT_ACL_NETDATACONF)?"netdata.conf ":"");
		debug(D_WEB_CLIENT, "Socket fd %d name '%s' acl_flags: %s",
			  i,
			  api_sockets.fds_names[i],
			  buffer_tostring(wb));
		buffer_reset(wb);
	}
	buffer_free(wb);
}

void api_listen_sockets_setup(void) {
	int socks = listen_sockets_setup(&api_sockets);

	if(!socks)
		fatal("LISTENER: Cannot listen on any API socket. Exiting...");

	if(unlikely(debug_flags & D_WEB_CLIENT))
		debug_sockets();

	return;
}

void web_client_update_acl_matches(struct web_client *w) {
    w->acl = WEB_CLIENT_ACL_NONE;

    if(!web_allow_dashboard_from || simple_pattern_matches(web_allow_dashboard_from, w->client_ip))
        w->acl |= WEB_CLIENT_ACL_DASHBOARD;

    if(!web_allow_registry_from || simple_pattern_matches(web_allow_registry_from, w->client_ip))
        w->acl |= WEB_CLIENT_ACL_REGISTRY;

    if(!web_allow_badges_from || simple_pattern_matches(web_allow_badges_from, w->client_ip))
        w->acl |= WEB_CLIENT_ACL_BADGE;

    if(!web_allow_mgmt_from || simple_pattern_matches(web_allow_mgmt_from, w->client_ip))
        w->acl |= WEB_CLIENT_ACL_MGMT;

    if(!web_allow_streaming_from || simple_pattern_matches(web_allow_streaming_from, w->client_ip))
        w->acl |= WEB_CLIENT_ACL_STREAMING;

    if(!web_allow_netdataconf_from || simple_pattern_matches(web_allow_netdataconf_from, w->client_ip))
        w->acl |= WEB_CLIENT_ACL_NETDATACONF;

    w->acl &= w->port_acl;
}

void web_server_log_connection(struct web_client *w, const char *msg) {
    log_access("%llu: %d '[%s]:%s' '%s'", w->id, gettid(), w->client_ip, w->client_port, msg);
}

void web_client_initialize_connection(struct web_client *w) {
    int flag = 1;

    if(unlikely(web_client_check_tcp(w) && setsockopt(w->ifd, IPPROTO_TCP, TCP_NODELAY, (char *) &flag, sizeof(int)) != 0))
        debug(D_WEB_CLIENT, "%llu: failed to enable TCP_NODELAY on socket fd %d.", w->id, w->ifd);

    flag = 1;
    if(unlikely(setsockopt(w->ifd, SOL_SOCKET, SO_KEEPALIVE, (char *) &flag, sizeof(int)) != 0))
        debug(D_WEB_CLIENT, "%llu: failed to enable SO_KEEPALIVE on socket fd %d.", w->id, w->ifd);

    web_client_update_acl_matches(w);

    w->origin[0] = '*'; w->origin[1] = '\0';
    w->cookie1[0] = '\0'; w->cookie2[0] = '\0';
    freez(w->user_agent); w->user_agent = NULL;

    web_client_enable_wait_receive(w);

    web_server_log_connection(w, "CONNECTED");

    web_client_cache_verify(0);
}

