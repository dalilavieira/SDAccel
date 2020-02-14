#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ut8 ;
typedef  int /*<<< orphan*/  ut64 ;
struct TYPE_8__ {int /*<<< orphan*/ * data; } ;
typedef  TYPE_1__ RIODesc ;
typedef  int /*<<< orphan*/  RIO ;
typedef  int /*<<< orphan*/  RBuffer ;

/* Variables and functions */
 int /*<<< orphan*/  r_buf_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * r_buf_new () ; 
 int r_buf_read (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  r_buf_seek (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int r_buf_write (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int) ; 
 TYPE_1__* r_io_desc_new (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char const*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  r_io_plugin_rbuf ; 
 int /*<<< orphan*/  strncmp (char const*,char*,int) ; 

__attribute__((used)) static int __write(RIO *io, RIODesc *fd, const ut8 *buf, int count) {
	if (!fd || !buf || count < 0 || !fd->data) {
		return -1;
	}
	RBuffer *b = fd->data;
	return r_buf_write (b, buf, count);
}

__attribute__((used)) static int __read(RIO *io, RIODesc *fd, ut8 *buf, int count) {
	RBuffer *b = fd->data;
	return r_buf_read (b, buf, count);
}

__attribute__((used)) static int __close(RIODesc *fd) {
	RBuffer *b = fd->data;
	r_buf_free (b);
	return 0;
}

__attribute__((used)) static ut64 __lseek(RIO* io, RIODesc *fd, ut64 offset, int whence) {
	RBuffer *buf = fd->data;
	return r_buf_seek (buf, offset, whence);
}

__attribute__((used)) static bool __check(RIO *io, const char *pathname, bool many) {
	return (!strncmp (pathname, "rbuf://", 7));
}

__attribute__((used)) static RIODesc *__open(RIO *io, const char *pathname, int rw, int mode) {
	RIODesc *desc;
	RBuffer *buf = r_buf_new ();
	if (buf && (desc = r_io_desc_new (io, &r_io_plugin_rbuf, pathname, 7, 0, buf))) {
		return desc;
	}
	r_buf_free (buf);
	return NULL;
}

