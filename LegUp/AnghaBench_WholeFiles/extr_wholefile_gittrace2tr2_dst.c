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
struct tr2_dst {int need_close; int fd; int initialized; char const* env_var_name; } ;
struct strbuf {int /*<<< orphan*/  len; int /*<<< orphan*/  buf; } ;
struct sockaddr_un {int /*<<< orphan*/  sun_path; int /*<<< orphan*/  sun_family; } ;
struct sockaddr {int dummy; } ;
typedef  int /*<<< orphan*/  sa ;

/* Variables and functions */
 int /*<<< orphan*/  AF_UNIX ; 
 int EPROTOTYPE ; 
 int O_APPEND ; 
 int O_CREAT ; 
 int O_WRONLY ; 
 int /*<<< orphan*/  PREFIX_AF_UNIX ; 
 int /*<<< orphan*/  PREFIX_AF_UNIX_DGRAM ; 
 int /*<<< orphan*/  PREFIX_AF_UNIX_STREAM ; 
 int SOCK_DGRAM ; 
 int SOCK_STREAM ; 
 int STDERR_FILENO ; 
 struct strbuf STRBUF_INIT ; 
 unsigned int TR2_DST_UDS_TRY_DGRAM ; 
 unsigned int TR2_DST_UDS_TRY_STREAM ; 
 char const* TR2_ENVVAR_DST_DEBUG ; 
 scalar_t__ atoi (char const*) ; 
 int /*<<< orphan*/  close (int) ; 
 int connect (int,struct sockaddr*,int) ; 
 int errno ; 
 char* getenv (char const*) ; 
 scalar_t__ is_absolute_path (char const*) ; 
 scalar_t__ isdigit (char const) ; 
 int open (char const*,int,int) ; 
 scalar_t__ skip_prefix (char const*,int /*<<< orphan*/ ,char const**) ; 
 int socket (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 scalar_t__ starts_with (char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strbuf_addf (struct strbuf*,char*,char const*,char const*) ; 
 int /*<<< orphan*/  strbuf_complete_line (struct strbuf*) ; 
 int /*<<< orphan*/  strbuf_release (struct strbuf*) ; 
 int /*<<< orphan*/  strcasecmp (char const*,char*) ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 
 char const* strerror (int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char const*,int) ; 
 int strlen (char const*) ; 
 int /*<<< orphan*/  warning (char*,char const*,...) ; 
 scalar_t__ write (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int tr2_dst_want_warning(void)
{
	static int tr2env_dst_debug = -1;

	if (tr2env_dst_debug == -1) {
		const char *env_value = getenv(TR2_ENVVAR_DST_DEBUG);
		if (!env_value || !*env_value)
			tr2env_dst_debug = 0;
		else
			tr2env_dst_debug = atoi(env_value) > 0;
	}

	return tr2env_dst_debug;
}

void tr2_dst_trace_disable(struct tr2_dst *dst)
{
	if (dst->need_close)
		close(dst->fd);
	dst->fd = 0;
	dst->initialized = 1;
	dst->need_close = 0;
}

__attribute__((used)) static int tr2_dst_try_path(struct tr2_dst *dst, const char *tgt_value)
{
	int fd = open(tgt_value, O_WRONLY | O_APPEND | O_CREAT, 0666);
	if (fd == -1) {
		if (tr2_dst_want_warning())
			warning("trace2: could not open '%s' for '%s' tracing: %s",
				tgt_value, dst->env_var_name, strerror(errno));

		tr2_dst_trace_disable(dst);
		return 0;
	}

	dst->fd = fd;
	dst->need_close = 1;
	dst->initialized = 1;

	return dst->fd;
}

__attribute__((used)) static int tr2_dst_try_uds_connect(const char *path, int sock_type, int *out_fd)
{
	int fd;
	struct sockaddr_un sa;

	fd = socket(AF_UNIX, sock_type, 0);
	if (fd == -1)
		return errno;

	sa.sun_family = AF_UNIX;
	strlcpy(sa.sun_path, path, sizeof(sa.sun_path));

	if (connect(fd, (struct sockaddr *)&sa, sizeof(sa)) == -1) {
		int e = errno;
		close(fd);
		return e;
	}

	*out_fd = fd;
	return 0;
}

__attribute__((used)) static int tr2_dst_try_unix_domain_socket(struct tr2_dst *dst,
					  const char *tgt_value)
{
	unsigned int uds_try = 0;
	int fd;
	int e;
	const char *path = NULL;

	/*
	 * Allow "af_unix:[<type>:]<absolute_path>"
	 *
	 * Trace2 always writes complete individual messages (without
	 * chunking), so we can talk to either DGRAM or STREAM type sockets.
	 *
	 * Allow the user to explicitly request the socket type.
	 *
	 * If they omit the socket type, try one and then the other.
	 */

	if (skip_prefix(tgt_value, PREFIX_AF_UNIX_STREAM, &path))
		uds_try |= TR2_DST_UDS_TRY_STREAM;

	else if (skip_prefix(tgt_value, PREFIX_AF_UNIX_DGRAM, &path))
		uds_try |= TR2_DST_UDS_TRY_DGRAM;

	else if (skip_prefix(tgt_value, PREFIX_AF_UNIX, &path))
		uds_try |= TR2_DST_UDS_TRY_STREAM | TR2_DST_UDS_TRY_DGRAM;

	if (!path || !*path) {
		if (tr2_dst_want_warning())
			warning("trace2: invalid AF_UNIX value '%s' for '%s' tracing",
				tgt_value, dst->env_var_name);

		tr2_dst_trace_disable(dst);
		return 0;
	}

	if (!is_absolute_path(path) ||
	    strlen(path) >= sizeof(((struct sockaddr_un *)0)->sun_path)) {
		if (tr2_dst_want_warning())
			warning("trace2: invalid AF_UNIX path '%s' for '%s' tracing",
				path, dst->env_var_name);

		tr2_dst_trace_disable(dst);
		return 0;
	}

	if (uds_try & TR2_DST_UDS_TRY_STREAM) {
		e = tr2_dst_try_uds_connect(path, SOCK_STREAM, &fd);
		if (!e)
			goto connected;
		if (e != EPROTOTYPE)
			goto error;
	}
	if (uds_try & TR2_DST_UDS_TRY_DGRAM) {
		e = tr2_dst_try_uds_connect(path, SOCK_DGRAM, &fd);
		if (!e)
			goto connected;
	}

error:
	if (tr2_dst_want_warning())
		warning("trace2: could not connect to socket '%s' for '%s' tracing: %s",
			path, dst->env_var_name, strerror(e));

	tr2_dst_trace_disable(dst);
	return 0;

connected:
	dst->fd = fd;
	dst->need_close = 1;
	dst->initialized = 1;

	return dst->fd;
}

__attribute__((used)) static void tr2_dst_malformed_warning(struct tr2_dst *dst,
				      const char *tgt_value)
{
	struct strbuf buf = STRBUF_INIT;

	strbuf_addf(&buf, "trace2: unknown value for '%s': '%s'",
		    dst->env_var_name, tgt_value);
	warning("%s", buf.buf);

	strbuf_release(&buf);
}

int tr2_dst_get_trace_fd(struct tr2_dst *dst)
{
	const char *tgt_value;

	/* don't open twice */
	if (dst->initialized)
		return dst->fd;

	dst->initialized = 1;

	tgt_value = getenv(dst->env_var_name);

	if (!tgt_value || !strcmp(tgt_value, "") || !strcmp(tgt_value, "0") ||
	    !strcasecmp(tgt_value, "false")) {
		dst->fd = 0;
		return dst->fd;
	}

	if (!strcmp(tgt_value, "1") || !strcasecmp(tgt_value, "true")) {
		dst->fd = STDERR_FILENO;
		return dst->fd;
	}

	if (strlen(tgt_value) == 1 && isdigit(*tgt_value)) {
		dst->fd = atoi(tgt_value);
		return dst->fd;
	}

	if (is_absolute_path(tgt_value))
		return tr2_dst_try_path(dst, tgt_value);

#ifndef NO_UNIX_SOCKETS
	if (starts_with(tgt_value, PREFIX_AF_UNIX))
		return tr2_dst_try_unix_domain_socket(dst, tgt_value);
#endif

	/* Always warn about malformed values. */
	tr2_dst_malformed_warning(dst, tgt_value);
	tr2_dst_trace_disable(dst);
	return 0;
}

int tr2_dst_trace_want(struct tr2_dst *dst)
{
	return !!tr2_dst_get_trace_fd(dst);
}

void tr2_dst_write_line(struct tr2_dst *dst, struct strbuf *buf_line)
{
	int fd = tr2_dst_get_trace_fd(dst);

	strbuf_complete_line(buf_line); /* ensure final NL on buffer */

	/*
	 * We do not use write_in_full() because we do not want
	 * a short-write to try again.  We are using O_APPEND mode
	 * files and the kernel handles the atomic seek+write. If
	 * another thread or git process is concurrently writing to
	 * this fd or file, our remainder-write may not be contiguous
	 * with our initial write of this message.  And that will
	 * confuse readers.  So just don't bother.
	 *
	 * It is assumed that TRACE2 messages are short enough that
	 * the system can write them in 1 attempt and we won't see
	 * a short-write.
	 *
	 * If we get an IO error, just close the trace dst.
	 */
	if (write(fd, buf_line->buf, buf_line->len) >= 0)
		return;

	if (tr2_dst_want_warning())
		warning("unable to write trace to '%s': %s", dst->env_var_name,
			strerror(errno));
	tr2_dst_trace_disable(dst);
}

