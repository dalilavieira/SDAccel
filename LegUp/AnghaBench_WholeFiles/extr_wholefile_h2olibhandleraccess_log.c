#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct stat {int st_mode; } ;
struct TYPE_11__ {void (* dispose ) (TYPE_1__*) ;void (* log_access ) (TYPE_1__*,int /*<<< orphan*/ *) ;} ;
struct st_h2o_access_logger_t {TYPE_1__ super; TYPE_2__* fh; } ;
struct sockaddr_un {int /*<<< orphan*/  sun_path; int /*<<< orphan*/  sun_family; } ;
struct sockaddr {int dummy; } ;
typedef  int /*<<< orphan*/  sa ;
typedef  int pid_t ;
typedef  int /*<<< orphan*/  h2o_req_t ;
typedef  int /*<<< orphan*/  h2o_pathconf_t ;
typedef  TYPE_1__ h2o_logger_t ;
typedef  int /*<<< orphan*/  h2o_logconf_t ;
struct TYPE_12__ {int fd; int /*<<< orphan*/ * logconf; } ;
typedef  TYPE_2__ h2o_access_log_filehandle_t ;
typedef  int /*<<< orphan*/  buf ;

/* Variables and functions */
 int /*<<< orphan*/  AF_UNIX ; 
 int /*<<< orphan*/  FD_CLOEXEC ; 
 int /*<<< orphan*/  F_SETFD ; 
 int O_APPEND ; 
 int O_CLOEXEC ; 
 int O_CREAT ; 
 int O_WRONLY ; 
 int /*<<< orphan*/  SOCK_STREAM ; 
 int S_IFMT ; 
 int S_IFSOCK ; 
 int /*<<< orphan*/  close (int) ; 
 int connect (int,struct sockaddr*,int) ; 
 int /*<<< orphan*/  errno ; 
 int fcntl (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free (char*) ; 
 scalar_t__ h2o_create_logger (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  h2o_error_printf (char*,char const*,...) ; 
 char* h2o_log_request (int /*<<< orphan*/ *,int /*<<< orphan*/ *,size_t*,char*) ; 
 int /*<<< orphan*/ * h2o_logconf_compile (char const*,int,char*) ; 
 int /*<<< orphan*/  h2o_logconf_dispose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  h2o_mem_addref_shared (TYPE_2__*) ; 
 TYPE_2__* h2o_mem_alloc_shared (int /*<<< orphan*/ *,int,void (*) (void*)) ; 
 int /*<<< orphan*/  h2o_mem_release_shared (TYPE_2__*) ; 
 int /*<<< orphan*/  h2o_perror (char*) ; 
 int h2o_spawnp (char*,char**,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct sockaddr_un*,int /*<<< orphan*/ ,int) ; 
 int open (char const*,int,int) ; 
 scalar_t__ pipe (int*) ; 
 int socket (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int stat (char const*,struct stat*) ; 
 int /*<<< orphan*/  strcpy (int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  strerror (int /*<<< orphan*/ ) ; 
 int strlen (char const*) ; 
 int /*<<< orphan*/  write (int,char*,size_t) ; 

__attribute__((used)) static void log_access(h2o_logger_t *_self, h2o_req_t *req)
{
    struct st_h2o_access_logger_t *self = (struct st_h2o_access_logger_t *)_self;
    h2o_access_log_filehandle_t *fh = self->fh;
    char *logline, buf[4096];
    size_t len;

    /* stringify */
    len = sizeof(buf);
    logline = h2o_log_request(fh->logconf, req, &len, buf);

    /* emit */
    write(fh->fd, logline, len);

    /* free memory */
    if (logline != buf)
        free(logline);
}

__attribute__((used)) static void on_dispose_handle(void *_fh)
{
    h2o_access_log_filehandle_t *fh = _fh;

    h2o_logconf_dispose(fh->logconf);
    close(fh->fd);
}

int h2o_access_log_open_log(const char *path)
{
    int fd;

    if (path[0] == '|') {
        int pipefds[2];
        pid_t pid;
        char *argv[4] = {"/bin/sh", "-c", (char *)(path + 1), NULL};
        /* create pipe */
        if (pipe(pipefds) != 0) {
            h2o_perror("pipe failed");
            return -1;
        }
        if (fcntl(pipefds[1], F_SETFD, FD_CLOEXEC) == -1) {
            h2o_perror("failed to set FD_CLOEXEC on pipefds[1]");
            return -1;
        }
        /* spawn the logger */
        int mapped_fds[] = {pipefds[0], 0, /* map pipefds[0] to stdin */
                            -1};
        if ((pid = h2o_spawnp(argv[0], argv, mapped_fds, 0)) == -1) {
            h2o_error_printf("failed to open logger: %s:%s\n", path + 1, strerror(errno));
            return -1;
        }
        /* close the read side of the pipefds and return the write side */
        close(pipefds[0]);
        fd = pipefds[1];
    } else {
        struct stat st;
        int ret;

        ret = stat(path, &st);
        if (ret == 0 && (st.st_mode & S_IFMT) == S_IFSOCK) {
            struct sockaddr_un sa;
            if (strlen(path) >= sizeof(sa.sun_path)) {
                h2o_error_printf("path:%s is too long as a unix socket name", path);
                return -1;
            }
            if ((fd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
                h2o_error_printf("failed to create socket for log file:%s:%s\n", path, strerror(errno));
                return -1;
            }
            memset(&sa, 0, sizeof(sa));
            sa.sun_family = AF_UNIX;
            strcpy(sa.sun_path, path);
            if (connect(fd, (struct sockaddr *)&sa, sizeof(sa)) == -1) {
                h2o_error_printf("failed to connect socket for log file:%s:%s\n", path, strerror(errno));
                close(fd);
                return -1;
            }

        } else {
            if ((fd = open(path, O_CREAT | O_WRONLY | O_APPEND | O_CLOEXEC, 0644)) == -1) {
                h2o_error_printf("failed to open log file:%s:%s\n", path, strerror(errno));
                return -1;
            }
        }
    }

    return fd;
}

h2o_access_log_filehandle_t *h2o_access_log_open_handle(const char *path, const char *fmt, int escape)
{
    h2o_logconf_t *logconf;
    int fd;
    h2o_access_log_filehandle_t *fh;
    char errbuf[256];

    /* default to combined log format */
    if (fmt == NULL)
        fmt = "%h %l %u %t \"%r\" %s %b \"%{Referer}i\" \"%{User-agent}i\"";
    if ((logconf = h2o_logconf_compile(fmt, escape, errbuf)) == NULL) {
        h2o_error_printf("%s\n", errbuf);
        return NULL;
    }

    /* open log file */
    if ((fd = h2o_access_log_open_log(path)) == -1) {
        h2o_logconf_dispose(logconf);
        return NULL;
    }

    fh = h2o_mem_alloc_shared(NULL, sizeof(*fh), on_dispose_handle);
    fh->logconf = logconf;
    fh->fd = fd;
    return fh;
}

__attribute__((used)) static void dispose(h2o_logger_t *_self)
{
    struct st_h2o_access_logger_t *self = (void *)_self;

    h2o_mem_release_shared(self->fh);
}

h2o_logger_t *h2o_access_log_register(h2o_pathconf_t *pathconf, h2o_access_log_filehandle_t *fh)
{
    struct st_h2o_access_logger_t *self = (void *)h2o_create_logger(pathconf, sizeof(*self));

    self->super.dispose = dispose;
    self->super.log_access = log_access;
    self->fh = fh;
    h2o_mem_addref_shared(fh);

    return &self->super;
}

