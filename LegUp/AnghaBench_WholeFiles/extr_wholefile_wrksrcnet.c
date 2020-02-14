#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  status ;
typedef  scalar_t__ ssize_t ;
struct TYPE_7__ {int /*<<< orphan*/  fd; int /*<<< orphan*/  buf; } ;
typedef  TYPE_1__ connection ;

/* Variables and functions */
#define  EAGAIN 128 
 int /*<<< orphan*/  ERROR ; 
 int /*<<< orphan*/  FIONREAD ; 
 int /*<<< orphan*/  OK ; 
 int /*<<< orphan*/  RETRY ; 
 int errno ; 
 int ioctl (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 scalar_t__ read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 scalar_t__ write (int /*<<< orphan*/ ,char*,size_t) ; 

status sock_connect(connection *c, char *host) {
    return OK;
}

status sock_close(connection *c) {
    return OK;
}

status sock_read(connection *c, size_t *n) {
    ssize_t r = read(c->fd, c->buf, sizeof(c->buf));
    *n = (size_t) r;
    return r >= 0 ? OK : ERROR;
}

status sock_write(connection *c, char *buf, size_t len, size_t *n) {
    ssize_t r;
    if ((r = write(c->fd, buf, len)) == -1) {
        switch (errno) {
            case EAGAIN: return RETRY;
            default:     return ERROR;
        }
    }
    *n = (size_t) r;
    return OK;
}

size_t sock_readable(connection *c) {
    int n, rc;
    rc = ioctl(c->fd, FIONREAD, &n);
    return rc == -1 ? 0 : n;
}

