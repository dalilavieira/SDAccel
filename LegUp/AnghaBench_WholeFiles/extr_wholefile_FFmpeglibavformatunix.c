#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
struct sockaddr {int dummy; } ;
struct TYPE_11__ {int /*<<< orphan*/  sun_path; int /*<<< orphan*/  sun_family; } ;
struct TYPE_12__ {scalar_t__ type; int timeout; int fd; TYPE_1__ addr; scalar_t__ listen; } ;
typedef  TYPE_2__ UnixContext ;
struct TYPE_13__ {int rw_timeout; int flags; TYPE_2__* priv_data; } ;
typedef  TYPE_3__ URLContext ;

/* Variables and functions */
 int /*<<< orphan*/  AF_UNIX ; 
 int AVERROR_EOF ; 
 int AVIO_FLAG_NONBLOCK ; 
 scalar_t__ AVUNERROR (int) ; 
 scalar_t__ EADDRINUSE ; 
 int /*<<< orphan*/  MSG_NOSIGNAL ; 
 scalar_t__ SOCK_STREAM ; 
 int /*<<< orphan*/  av_strlcpy (int /*<<< orphan*/ ,char const*,int) ; 
 int /*<<< orphan*/  av_strstart (char const*,char*,char const**) ; 
 int /*<<< orphan*/  closesocket (int) ; 
 int ff_listen_bind (int,struct sockaddr*,int,int,TYPE_3__*) ; 
 int ff_listen_connect (int,struct sockaddr*,int,int,TYPE_3__*,int /*<<< orphan*/ ) ; 
 int ff_neterrno () ; 
 int ff_network_wait_fd (int,int) ; 
 int ff_socket (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ) ; 
 int recv (int,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int send (int,int /*<<< orphan*/  const*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  unlink (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int is_dos_path(const char *path)
{
#if HAVE_DOS_PATHS
    if (path[0] && path[1] == ':')
        return 1;
#endif
    return 0;
}

__attribute__((used)) static int unix_open(URLContext *h, const char *filename, int flags)
{
    UnixContext *s = h->priv_data;
    int fd, ret;

    av_strstart(filename, "unix:", &filename);
    s->addr.sun_family = AF_UNIX;
    av_strlcpy(s->addr.sun_path, filename, sizeof(s->addr.sun_path));

    if ((fd = ff_socket(AF_UNIX, s->type, 0)) < 0)
        return ff_neterrno();

    if (s->timeout < 0 && h->rw_timeout)
        s->timeout = h->rw_timeout / 1000;

    if (s->listen) {
        ret = ff_listen_bind(fd, (struct sockaddr *)&s->addr,
                             sizeof(s->addr), s->timeout, h);
        if (ret < 0)
            goto fail;
        fd = ret;
    } else {
        ret = ff_listen_connect(fd, (struct sockaddr *)&s->addr,
                                sizeof(s->addr), s->timeout, h, 0);
        if (ret < 0)
            goto fail;
    }

    s->fd = fd;

    return 0;

fail:
    if (s->listen && AVUNERROR(ret) != EADDRINUSE)
        unlink(s->addr.sun_path);
    if (fd >= 0)
        closesocket(fd);
    return ret;
}

__attribute__((used)) static int unix_read(URLContext *h, uint8_t *buf, int size)
{
    UnixContext *s = h->priv_data;
    int ret;

    if (!(h->flags & AVIO_FLAG_NONBLOCK)) {
        ret = ff_network_wait_fd(s->fd, 0);
        if (ret < 0)
            return ret;
    }
    ret = recv(s->fd, buf, size, 0);
    if (!ret && s->type == SOCK_STREAM)
        return AVERROR_EOF;
    return ret < 0 ? ff_neterrno() : ret;
}

__attribute__((used)) static int unix_write(URLContext *h, const uint8_t *buf, int size)
{
    UnixContext *s = h->priv_data;
    int ret;

    if (!(h->flags & AVIO_FLAG_NONBLOCK)) {
        ret = ff_network_wait_fd(s->fd, 1);
        if (ret < 0)
            return ret;
    }
    ret = send(s->fd, buf, size, MSG_NOSIGNAL);
    return ret < 0 ? ff_neterrno() : ret;
}

__attribute__((used)) static int unix_close(URLContext *h)
{
    UnixContext *s = h->priv_data;
    if (s->listen)
        unlink(s->addr.sun_path);
    closesocket(s->fd);
    return 0;
}

__attribute__((used)) static int unix_get_file_handle(URLContext *h)
{
    UnixContext *s = h->priv_data;
    return s->fd;
}

