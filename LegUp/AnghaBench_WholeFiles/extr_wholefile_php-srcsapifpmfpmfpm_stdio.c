#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct zlog_stream {int dummy; } ;
struct fpm_worker_pool_s {int dummy; } ;
struct fpm_event_s {int fd; } ;
struct fpm_child_s {int fd_stdout; int fd_stderr; TYPE_2__* wp; struct fpm_event_s ev_stderr; struct fpm_event_s ev_stdout; struct zlog_stream* log_stream; scalar_t__ pid; } ;
struct TYPE_8__ {int /*<<< orphan*/  error_log; scalar_t__ daemonize; } ;
struct TYPE_7__ {int error_log_fd; } ;
struct TYPE_6__ {TYPE_1__* config; } ;
struct TYPE_5__ {scalar_t__ catch_workers_output; int /*<<< orphan*/  name; int /*<<< orphan*/  decorate_workers_output; } ;

/* Variables and functions */
 scalar_t__ EAGAIN ; 
 scalar_t__ EWOULDBLOCK ; 
 int FD_CLOEXEC ; 
 int /*<<< orphan*/  FPM_EV_READ ; 
 int /*<<< orphan*/  F_GETFD ; 
 int /*<<< orphan*/  F_GETFL ; 
 int /*<<< orphan*/  F_SETFD ; 
 int /*<<< orphan*/  F_SETFL ; 
 int O_APPEND ; 
 int O_CREAT ; 
 int O_NONBLOCK ; 
 int /*<<< orphan*/  O_RDWR ; 
 int O_WRONLY ; 
 int STDERR_FILENO ; 
 int STDIN_FILENO ; 
 int STDOUT_FILENO ; 
 int S_IRUSR ; 
 int S_IWUSR ; 
 int /*<<< orphan*/  ZLOG_SYSERROR ; 
 int /*<<< orphan*/  ZLOG_TRUE ; 
 int /*<<< orphan*/  ZLOG_WARNING ; 
 int /*<<< orphan*/  close (int) ; 
 scalar_t__ dup2 (int,int) ; 
 scalar_t__ errno ; 
 int fcntl (int,int /*<<< orphan*/ ,...) ; 
 int* fd_stderr ; 
 int* fd_stdout ; 
 int /*<<< orphan*/  fpm_event_add (struct fpm_event_s*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fpm_event_del (struct fpm_event_s*) ; 
 int /*<<< orphan*/  fpm_event_set (struct fpm_event_s*,int,int /*<<< orphan*/ ,void (*) (struct fpm_event_s*,short,void*),struct fpm_child_s*) ; 
 TYPE_4__ fpm_global_config ; 
 TYPE_3__ fpm_globals ; 
 struct zlog_stream* malloc (int) ; 
 char* memchr (char*,char,int) ; 
 int /*<<< orphan*/  memmove (char*,char*,int) ; 
 int open (char*,int,...) ; 
 scalar_t__ pipe (int*) ; 
 int read (int,char*,int const) ; 
 int write (int,char*,int) ; 
 int /*<<< orphan*/  zlog (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  zlog_set_fd (int) ; 
 int /*<<< orphan*/  zlog_set_launched () ; 
 int /*<<< orphan*/  zlog_stream_finish (struct zlog_stream*) ; 
 int /*<<< orphan*/  zlog_stream_init_ex (struct zlog_stream*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  zlog_stream_set_decorating (struct zlog_stream*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  zlog_stream_set_msg_prefix (struct zlog_stream*,char*,int /*<<< orphan*/ ,int,char*) ; 
 int /*<<< orphan*/  zlog_stream_set_msg_quoting (struct zlog_stream*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  zlog_stream_set_msg_suffix (struct zlog_stream*,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  zlog_stream_set_wrapping (struct zlog_stream*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  zlog_stream_str (struct zlog_stream*,char*,int) ; 

__attribute__((used)) static inline int fd_set_blocked(int fd, int blocked) /* {{{ */
{
	int flags = fcntl(fd, F_GETFL);

	if (flags < 0) {
		return -1;
	}

	if (blocked) {
		flags &= ~O_NONBLOCK;
	} else {
		flags |= O_NONBLOCK;
	}
	return fcntl(fd, F_SETFL, flags);
}

int fpm_stdio_init_main() /* {{{ */
{
	int fd = open("/dev/null", O_RDWR);

	if (0 > fd) {
		zlog(ZLOG_SYSERROR, "failed to init stdio: open(\"/dev/null\")");
		return -1;
	}

	if (0 > dup2(fd, STDIN_FILENO) || 0 > dup2(fd, STDOUT_FILENO)) {
		zlog(ZLOG_SYSERROR, "failed to init stdio: dup2()");
		close(fd);
		return -1;
	}
	close(fd);
	return 0;
}

__attribute__((used)) static inline int fpm_use_error_log() {  /* {{{ */
	/*
	 * the error_log is NOT used when running in foreground
	 * and from a tty (user looking at output).
	 * So, error_log is used by
	 * - SysV init launch php-fpm as a daemon
	 * - Systemd launch php-fpm in foreground
	 */
#if HAVE_UNISTD_H
	if (fpm_global_config.daemonize || (!isatty(STDERR_FILENO) && !fpm_globals.force_stderr)) {
#else
	if (fpm_global_config.daemonize) {
#endif
		return 1;
	}
	return 0;
}

int fpm_stdio_init_final() /* {{{ */
{
	if (fpm_use_error_log()) {
		/* prevent duping if logging to syslog */
		if (fpm_globals.error_log_fd > 0 && fpm_globals.error_log_fd != STDERR_FILENO) {

			/* there might be messages to stderr from other parts of the code, we need to log them all */
			if (0 > dup2(fpm_globals.error_log_fd, STDERR_FILENO)) {
				zlog(ZLOG_SYSERROR, "failed to init stdio: dup2()");
				return -1;
			}
		}
#ifdef HAVE_SYSLOG_H
		else if (fpm_globals.error_log_fd == ZLOG_SYSLOG) {
			/* dup to /dev/null when using syslog */
			dup2(STDOUT_FILENO, STDERR_FILENO);
		}
#endif
	}
	zlog_set_launched();
	return 0;
}

int fpm_stdio_init_child(struct fpm_worker_pool_s *wp) /* {{{ */
{
#ifdef HAVE_SYSLOG_H
	if (fpm_globals.error_log_fd == ZLOG_SYSLOG) {
		closelog(); /* ensure to close syslog not to interrupt with PHP syslog code */
	} else
#endif

	/* Notice: child cannot use master error_log
	 * because not aware when being reopen
	 * else, should use if (!fpm_use_error_log())
	 */
	if (fpm_globals.error_log_fd > 0) {
		close(fpm_globals.error_log_fd);
	}
	fpm_globals.error_log_fd = -1;
	zlog_set_fd(-1);

	return 0;
}

int fpm_stdio_flush_child() /* {{{ */
{
	return write(STDERR_FILENO, "\0", 1);
}

__attribute__((used)) static void fpm_stdio_child_said(struct fpm_event_s *ev, short which, void *arg) /* {{{ */
{
	static const int max_buf_size = 1024;
	int fd = ev->fd;
	char buf[max_buf_size];
	struct fpm_child_s *child;
	int is_stdout;
	struct fpm_event_s *event;
	int fifo_in = 1, fifo_out = 1;
	int in_buf = 0;
	int read_fail = 0, finish_log_stream = 0, create_log_stream;
	int res;
	struct zlog_stream *log_stream;

	if (!arg) {
		return;
	}
	child = (struct fpm_child_s *)arg;

	is_stdout = (fd == child->fd_stdout);
	if (is_stdout) {
		event = &child->ev_stdout;
	} else {
		event = &child->ev_stderr;
	}

	create_log_stream = !child->log_stream;
	if (create_log_stream) {
		log_stream = child->log_stream = malloc(sizeof(struct zlog_stream));
		zlog_stream_init_ex(log_stream, ZLOG_WARNING, STDERR_FILENO);
		zlog_stream_set_decorating(log_stream, child->wp->config->decorate_workers_output);
		zlog_stream_set_wrapping(log_stream, ZLOG_TRUE);
		zlog_stream_set_msg_prefix(log_stream, "[pool %s] child %d said into %s: ",
				child->wp->config->name, (int) child->pid, is_stdout ? "stdout" : "stderr");
		zlog_stream_set_msg_quoting(log_stream, ZLOG_TRUE);
	} else {
		log_stream = child->log_stream;
	}

	while (fifo_in || fifo_out) {
		if (fifo_in) {
			res = read(fd, buf + in_buf, max_buf_size - 1 - in_buf);
			if (res <= 0) { /* no data */
				fifo_in = 0;
				if (res == 0 || (errno != EAGAIN && errno != EWOULDBLOCK)) {
					/* pipe is closed or error */
					read_fail = (res < 0) ? res : 1;
				}
			} else {
				in_buf += res;
				/* if buffer ends with \0, then the stream will be finished */
				if (!buf[in_buf - 1]) {
					finish_log_stream = 1;
					in_buf--;
				}
			}
		}

		if (fifo_out) {
			if (in_buf == 0) {
				fifo_out = 0;
			} else {
				char *nl;

				nl = memchr(buf, '\n', in_buf);
				if (nl) {
					/* we should print each new line int the new message */
					int out_len = nl - buf;
					zlog_stream_str(log_stream, buf, out_len);
					zlog_stream_finish(log_stream);
					/* skip new line */
					out_len++;
					/* move data in the buffer */
					memmove(buf, buf + out_len, in_buf - out_len);
					in_buf -= out_len;
				} else if (in_buf == max_buf_size - 1 || !fifo_in) {
					/* we should print if no more space in the buffer or no more data to come */
					zlog_stream_str(log_stream, buf, in_buf);
					in_buf = 0;
				}
			}
		}
	}

	if (read_fail) {
		if (create_log_stream) {
			zlog_stream_set_msg_suffix(log_stream, NULL, ", pipe is closed");
			zlog_stream_finish(log_stream);
		}
		if (read_fail < 0) {
			zlog(ZLOG_SYSERROR, "unable to read what child say");
		}

		fpm_event_del(event);

		if (is_stdout) {
			close(child->fd_stdout);
			child->fd_stdout = -1;
		} else {
			close(child->fd_stderr);
			child->fd_stderr = -1;
		}
	} else if (finish_log_stream) {
		zlog_stream_finish(log_stream);
	}
}

int fpm_stdio_prepare_pipes(struct fpm_child_s *child) /* {{{ */
{
	if (0 == child->wp->config->catch_workers_output) { /* not required */
		return 0;
	}

	if (0 > pipe(fd_stdout)) {
		zlog(ZLOG_SYSERROR, "failed to prepare the stdout pipe");
		return -1;
	}

	if (0 > pipe(fd_stderr)) {
		zlog(ZLOG_SYSERROR, "failed to prepare the stderr pipe");
		close(fd_stdout[0]);
		close(fd_stdout[1]);
		return -1;
	}

	if (0 > fd_set_blocked(fd_stdout[0], 0) || 0 > fd_set_blocked(fd_stderr[0], 0)) {
		zlog(ZLOG_SYSERROR, "failed to unblock pipes");
		close(fd_stdout[0]);
		close(fd_stdout[1]);
		close(fd_stderr[0]);
		close(fd_stderr[1]);
		return -1;
	}
	return 0;
}

int fpm_stdio_parent_use_pipes(struct fpm_child_s *child) /* {{{ */
{
	if (0 == child->wp->config->catch_workers_output) { /* not required */
		return 0;
	}

	close(fd_stdout[1]);
	close(fd_stderr[1]);

	child->fd_stdout = fd_stdout[0];
	child->fd_stderr = fd_stderr[0];

	fpm_event_set(&child->ev_stdout, child->fd_stdout, FPM_EV_READ, fpm_stdio_child_said, child);
	fpm_event_add(&child->ev_stdout, 0);

	fpm_event_set(&child->ev_stderr, child->fd_stderr, FPM_EV_READ, fpm_stdio_child_said, child);
	fpm_event_add(&child->ev_stderr, 0);
	return 0;
}

int fpm_stdio_discard_pipes(struct fpm_child_s *child) /* {{{ */
{
	if (0 == child->wp->config->catch_workers_output) { /* not required */
		return 0;
	}

	close(fd_stdout[1]);
	close(fd_stderr[1]);

	close(fd_stdout[0]);
	close(fd_stderr[0]);
	return 0;
}

void fpm_stdio_child_use_pipes(struct fpm_child_s *child) /* {{{ */
{
	if (child->wp->config->catch_workers_output) {
		dup2(fd_stdout[1], STDOUT_FILENO);
		dup2(fd_stderr[1], STDERR_FILENO);
		close(fd_stdout[0]); close(fd_stdout[1]);
		close(fd_stderr[0]); close(fd_stderr[1]);
	} else {
		/* stdout of parent is always /dev/null */
		dup2(STDOUT_FILENO, STDERR_FILENO);
	}
}

int fpm_stdio_open_error_log(int reopen) /* {{{ */
{
	int fd;

#ifdef HAVE_SYSLOG_H
	if (!strcasecmp(fpm_global_config.error_log, "syslog")) {
		php_openlog(fpm_global_config.syslog_ident, LOG_PID | LOG_CONS, fpm_global_config.syslog_facility);
		fpm_globals.error_log_fd = ZLOG_SYSLOG;
		if (fpm_use_error_log()) {
			zlog_set_fd(fpm_globals.error_log_fd);
		}
		return 0;
	}
#endif

	fd = open(fpm_global_config.error_log, O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);
	if (0 > fd) {
		zlog(ZLOG_SYSERROR, "failed to open error_log (%s)", fpm_global_config.error_log);
		return -1;
	}

	if (reopen) {
		if (fpm_use_error_log()) {
			dup2(fd, STDERR_FILENO);
		}

		dup2(fd, fpm_globals.error_log_fd);
		close(fd);
		fd = fpm_globals.error_log_fd; /* for FD_CLOSEXEC to work */
	} else {
		fpm_globals.error_log_fd = fd;
		if (fpm_use_error_log()) {
			zlog_set_fd(fpm_globals.error_log_fd);
		}
	}
	if (0 > fcntl(fd, F_SETFD, fcntl(fd, F_GETFD) | FD_CLOEXEC)) {
		zlog(ZLOG_WARNING, "failed to change attribute of error_log");
	}
	return 0;
}

