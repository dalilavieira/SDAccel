#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct addrinfo {int ai_socktype; scalar_t__ ai_addrlen; int /*<<< orphan*/  ai_addr; int /*<<< orphan*/  ai_protocol; int /*<<< orphan*/  ai_family; struct addrinfo* ai_next; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  socklen_t ;
struct TYPE_11__ {int (* init ) (int /*<<< orphan*/ **,char const*,char const*) ;int /*<<< orphan*/  member_0; } ;
typedef  TYPE_2__ git_stream_registration ;
typedef  int /*<<< orphan*/  git_stream ;
struct TYPE_10__ {int (* connect ) (int /*<<< orphan*/ *) ;int (* write ) (int /*<<< orphan*/ *,char const*,size_t,int) ;int (* read ) (int /*<<< orphan*/ *,void*,size_t) ;int (* close ) (int /*<<< orphan*/ *) ;void (* free ) (int /*<<< orphan*/ *) ;int /*<<< orphan*/  version; } ;
struct TYPE_12__ {scalar_t__ s; TYPE_1__ parent; struct TYPE_12__* port; struct TYPE_12__* host; } ;
typedef  TYPE_3__ git_socket_stream ;
typedef  scalar_t__ GIT_SOCKET ;

/* Variables and functions */
 int /*<<< orphan*/  AF_UNSPEC ; 
 int GIT_ENOTFOUND ; 
 int /*<<< orphan*/  GIT_ERROR_CHECK_ALLOC (TYPE_3__*) ; 
 int /*<<< orphan*/  GIT_ERROR_NET ; 
 int /*<<< orphan*/  GIT_ERROR_OS ; 
 int /*<<< orphan*/  GIT_STREAM_STANDARD ; 
 int /*<<< orphan*/  GIT_STREAM_VERSION ; 
 scalar_t__ INVALID_SOCKET ; 
 int SOCK_CLOEXEC ; 
 int SOCK_STREAM ; 
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 
 int close (scalar_t__) ; 
 scalar_t__ connect (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ errno ; 
 TYPE_3__* git__calloc (int,int) ; 
 int /*<<< orphan*/  git__free (TYPE_3__*) ; 
 void* git__strdup (char const*) ; 
 int /*<<< orphan*/  git_error_set (int /*<<< orphan*/ ,char*,...) ; 
 int git_stream_registry_lookup (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct addrinfo*,int,int) ; 
 int /*<<< orphan*/  p_freeaddrinfo (struct addrinfo*) ; 
 int /*<<< orphan*/  p_gai_strerror (int) ; 
 int p_getaddrinfo (TYPE_3__*,TYPE_3__*,struct addrinfo*,struct addrinfo**) ; 
 int p_recv (scalar_t__,void*,size_t,int /*<<< orphan*/ ) ; 
 int p_send (scalar_t__,char const*,size_t,int) ; 
 scalar_t__ socket (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strerror (scalar_t__) ; 

__attribute__((used)) static void net_set_error(const char *str)
{
	git_error_set(GIT_ERROR_NET, "%s: %s", str, strerror(errno));
}

__attribute__((used)) static int close_socket(GIT_SOCKET s)
{
	if (s == INVALID_SOCKET)
		return 0;

#ifdef GIT_WIN32
	if (SOCKET_ERROR == closesocket(s))
		return -1;

	if (0 != WSACleanup()) {
		git_error_set(GIT_ERROR_OS, "winsock cleanup failed");
		return -1;
	}

	return 0;
#else
	return close(s);
#endif

}

__attribute__((used)) static int socket_connect(git_stream *stream)
{
	struct addrinfo *info = NULL, *p;
	struct addrinfo hints;
	git_socket_stream *st = (git_socket_stream *) stream;
	GIT_SOCKET s = INVALID_SOCKET;
	int ret;

#ifdef GIT_WIN32
	/* on win32, the WSA context needs to be initialized
	 * before any socket calls can be performed */
	WSADATA wsd;

	if (WSAStartup(MAKEWORD(2,2), &wsd) != 0) {
		git_error_set(GIT_ERROR_OS, "winsock init failed");
		return -1;
	}

	if (LOBYTE(wsd.wVersion) != 2 || HIBYTE(wsd.wVersion) != 2) {
		WSACleanup();
		git_error_set(GIT_ERROR_OS, "winsock init failed");
		return -1;
	}
#endif

	memset(&hints, 0x0, sizeof(struct addrinfo));
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_family = AF_UNSPEC;

	if ((ret = p_getaddrinfo(st->host, st->port, &hints, &info)) != 0) {
		git_error_set(GIT_ERROR_NET,
			   "failed to resolve address for %s: %s", st->host, p_gai_strerror(ret));
		return -1;
	}

	for (p = info; p != NULL; p = p->ai_next) {
		s = socket(p->ai_family, p->ai_socktype | SOCK_CLOEXEC, p->ai_protocol);

		if (s == INVALID_SOCKET)
			continue;

		if (connect(s, p->ai_addr, (socklen_t)p->ai_addrlen) == 0)
			break;

		/* If we can't connect, try the next one */
		close_socket(s);
		s = INVALID_SOCKET;
	}

	/* Oops, we couldn't connect to any address */
	if (s == INVALID_SOCKET && p == NULL) {
		git_error_set(GIT_ERROR_OS, "failed to connect to %s", st->host);
		p_freeaddrinfo(info);
		return -1;
	}

	st->s = s;
	p_freeaddrinfo(info);
	return 0;
}

__attribute__((used)) static ssize_t socket_write(git_stream *stream, const char *data, size_t len, int flags)
{
	git_socket_stream *st = (git_socket_stream *) stream;
	ssize_t written;

	errno = 0;

	if ((written = p_send(st->s, data, len, flags)) < 0) {
		net_set_error("Error sending data");
		return -1;
	}

	return written;
}

__attribute__((used)) static ssize_t socket_read(git_stream *stream, void *data, size_t len)
{
	ssize_t ret;
	git_socket_stream *st = (git_socket_stream *) stream;

	if ((ret = p_recv(st->s, data, len, 0)) < 0)
		net_set_error("Error receiving socket data");

	return ret;
}

__attribute__((used)) static int socket_close(git_stream *stream)
{
	git_socket_stream *st = (git_socket_stream *) stream;
	int error;

	error = close_socket(st->s);
	st->s = INVALID_SOCKET;

	return error;
}

__attribute__((used)) static void socket_free(git_stream *stream)
{
	git_socket_stream *st = (git_socket_stream *) stream;

	git__free(st->host);
	git__free(st->port);
	git__free(st);
}

__attribute__((used)) static int default_socket_stream_new(
	git_stream **out,
	const char *host,
	const char *port)
{
	git_socket_stream *st;

	assert(out && host && port);

	st = git__calloc(1, sizeof(git_socket_stream));
	GIT_ERROR_CHECK_ALLOC(st);

	st->host = git__strdup(host);
	GIT_ERROR_CHECK_ALLOC(st->host);

	if (port) {
		st->port = git__strdup(port);
		GIT_ERROR_CHECK_ALLOC(st->port);
	}

	st->parent.version = GIT_STREAM_VERSION;
	st->parent.connect = socket_connect;
	st->parent.write = socket_write;
	st->parent.read = socket_read;
	st->parent.close = socket_close;
	st->parent.free = socket_free;
	st->s = INVALID_SOCKET;

	*out = (git_stream *) st;
	return 0;
}

int git_socket_stream_new(
	git_stream **out,
	const char *host,
	const char *port)
{
	int (*init)(git_stream **, const char *, const char *) = NULL;
	git_stream_registration custom = {0};
	int error;

	assert(out && host && port);

	if ((error = git_stream_registry_lookup(&custom, GIT_STREAM_STANDARD)) == 0)
		init = custom.init;
	else if (error == GIT_ENOTFOUND)
		init = default_socket_stream_new;
	else
		return error;

	if (!init) {
		git_error_set(GIT_ERROR_NET, "there is no socket stream available");
		return -1;
	}

	return init(out, host, port);
}

