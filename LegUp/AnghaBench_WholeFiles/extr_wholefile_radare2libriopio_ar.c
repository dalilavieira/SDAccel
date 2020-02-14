#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_27__   TYPE_3__ ;
typedef  struct TYPE_26__   TYPE_2__ ;
typedef  struct TYPE_25__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ut8 ;
typedef  int ut64 ;
struct TYPE_27__ {int base_priv; } ;
struct TYPE_26__ {int off; } ;
struct TYPE_25__ {TYPE_3__* data; } ;
typedef  int /*<<< orphan*/  RList ;
typedef  TYPE_1__ RIODesc ;
typedef  TYPE_2__ RIO ;
typedef  TYPE_3__ RBuffer ;

/* Variables and functions */
#define  SEEK_CUR 130 
#define  SEEK_END 129 
#define  SEEK_SET 128 
 int ar_close (TYPE_3__*) ; 
 TYPE_3__* ar_open_file (char*,char*) ; 
 int ar_read_at (TYPE_3__*,int,int /*<<< orphan*/ *,int) ; 
 int ar_write_at (TYPE_3__*,int,void*,int) ; 
 int /*<<< orphan*/  eprintf (char*) ; 
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/  r_buf_seek (TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 int r_buf_size (TYPE_3__*) ; 
 int r_buf_tell (TYPE_3__*) ; 
 TYPE_1__* r_io_desc_new (TYPE_2__*,int /*<<< orphan*/ *,char*,int,int,TYPE_3__*) ; 
 int /*<<< orphan*/  r_io_plugin_ar ; 
 char* strdup (char const*) ; 
 int /*<<< orphan*/  strncmp (char*,char const*,int) ; 
 char* strstr (char*,char*) ; 

__attribute__((used)) static bool r_io_ar_plugin_open(RIO *io, const char *file, bool many) {
	return !strncmp ("ar://", file, 5) || !strncmp ("lib://", file, 6);
}

__attribute__((used)) static RIODesc *r_io_ar_open(RIO *io, const char *file, int rw, int mode) {
	RIODesc *res = NULL;
	char *url = strdup (file);
	char *arname = strstr (url, "://") + 3;
	char *filename = strstr (arname, "//");
	if (filename) {
		*filename = 0;
		filename += 2;
	}

	RBuffer *b = ar_open_file (arname, filename);
	if (b) {
		res = r_io_desc_new (io, &r_io_plugin_ar, filename, rw, mode, b);
	}
	free (url);
	return res;
}

__attribute__((used)) static RList *r_io_ar_open_many(RIO *io, const char *file, int rw, int mode) {
	eprintf ("Not implemented\n");
	return NULL;
}

__attribute__((used)) static ut64 r_io_ar_lseek(RIO *io, RIODesc *fd, ut64 offset, int whence) {
	RBuffer *b;
	ut64 seek_val = 0;

	if (!fd || !fd->data) {
		return -1;
	}

	b = fd->data;
	seek_val = r_buf_tell (b);

	switch (whence) {
	case SEEK_SET:
		seek_val = (r_buf_size (b) < offset)? r_buf_size (b) : offset;
		io->off = seek_val;
		r_buf_seek (b, b->base_priv + seek_val, 0);
		return seek_val;
	case SEEK_CUR:
		seek_val = (r_buf_size (b) < offset)? r_buf_size (b) : offset;
		io->off = seek_val;
		r_buf_seek (b, b->base_priv + seek_val, 0);
		return seek_val;
	case SEEK_END:
		seek_val = r_buf_size (b);
		io->off = seek_val;
		r_buf_seek (b, b->base_priv + seek_val, 0);
		return seek_val;
	}
	return seek_val;
}

__attribute__((used)) static int r_io_ar_read(RIO *io, RIODesc *fd, ut8 *buf, int count) {
	RBuffer *b;
	if (!fd || !fd->data || !buf) {
		return -1;
	}
	b = fd->data;
	return ar_read_at (b, io->off, buf, count);
}

__attribute__((used)) static int r_io_ar_write(RIO *io, RIODesc *fd, const ut8 *buf, int count) {
	RBuffer *b = NULL;
	if (!fd || !fd->data || !buf) {
		return -1;
	}
	return ar_write_at (b, io->off, (void *) buf, count);
}

__attribute__((used)) static int r_io_ar_close(RIODesc *fd) {
	RBuffer *b = NULL;
	if (!fd || !fd->data) {
		return -1;
	}
	b = fd->data;
	return ar_close (b);
}

