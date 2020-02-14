#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  t ;
struct TYPE_11__ {scalar_t__ ss_family; } ;
struct TYPE_9__ {TYPE_3__ s_addr; } ;
struct sockaddr_in {int /*<<< orphan*/  member_0; TYPE_1__ sin_addr; } ;
struct in_addr {TYPE_3__ s_addr; } ;
struct hostent {scalar_t__ h_addrtype; int h_length; struct sockaddr_in** h_addr_list; } ;
typedef  int socklen_t ;
struct TYPE_10__ {scalar_t__ type; } ;
typedef  TYPE_2__ php_socket ;
typedef  TYPE_3__ php_sockaddr_storage ;

/* Variables and functions */
 scalar_t__ AF_INET ; 
 int /*<<< orphan*/  E_WARNING ; 
 scalar_t__ MAXFQDNLEN ; 
 int /*<<< orphan*/  PHP_SOCKET_ERROR (TYPE_2__*,char*,scalar_t__) ; 
 scalar_t__ h_errno ; 
 scalar_t__ inet_aton (char*,struct in_addr*) ; 
 int /*<<< orphan*/  memcpy (TYPE_3__*,struct sockaddr_in*,int) ; 
 int /*<<< orphan*/  php_error_docref (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 
 struct hostent* php_network_gethostbyname (char*) ; 
 scalar_t__ strlen (char*) ; 

int php_set_inet_addr(struct sockaddr_in *sin, char *string, php_socket *php_sock) /* {{{ */
{
	struct in_addr tmp;
	struct hostent *host_entry;

	if (inet_aton(string, &tmp)) {
		sin->sin_addr.s_addr = tmp.s_addr;
	} else {
		if (strlen(string) > MAXFQDNLEN || ! (host_entry = php_network_gethostbyname(string))) {
			/* Note: < -10000 indicates a host lookup error */
#ifdef PHP_WIN32
			PHP_SOCKET_ERROR(php_sock, "Host lookup failed", WSAGetLastError());
#else
			PHP_SOCKET_ERROR(php_sock, "Host lookup failed", (-10000 - h_errno));
#endif
			return 0;
		}
		if (host_entry->h_addrtype != AF_INET) {
			php_error_docref(NULL, E_WARNING, "Host lookup failed: Non AF_INET domain returned on AF_INET socket");
			return 0;
		}
		memcpy(&(sin->sin_addr.s_addr), host_entry->h_addr_list[0], host_entry->h_length);
	}

	return 1;
}

int php_set_inet46_addr(php_sockaddr_storage *ss, socklen_t *ss_len, char *string, php_socket *php_sock) /* {{{ */
{
	if (php_sock->type == AF_INET) {
		struct sockaddr_in t = {0};
		if (php_set_inet_addr(&t, string, php_sock)) {
			memcpy(ss, &t, sizeof t);
			ss->ss_family = AF_INET;
			*ss_len = sizeof(t);
			return 1;
		}
	}
#if HAVE_IPV6
	else if (php_sock->type == AF_INET6) {
		struct sockaddr_in6 t = {0};
		if (php_set_inet6_addr(&t, string, php_sock)) {
			memcpy(ss, &t, sizeof t);
			ss->ss_family = AF_INET6;
			*ss_len = sizeof(t);
			return 1;
		}
	}
#endif
	else {
		php_error_docref(NULL, E_WARNING,
			"IP address used in the context of an unexpected type of socket");
	}
	return 0;
}

