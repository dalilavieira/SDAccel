#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ut8 ;
typedef  scalar_t__ ut64 ;
typedef  int /*<<< orphan*/  WindCtx ;
struct TYPE_16__ {scalar_t__ off; } ;
struct TYPE_15__ {int /*<<< orphan*/  data; } ;
typedef  TYPE_1__ RIODesc ;
typedef  TYPE_2__ RIO ;

/* Variables and functions */
#define  R_IO_SEEK_CUR 130 
#define  R_IO_SEEK_END 129 
#define  R_IO_SEEK_SET 128 
 scalar_t__ UT64_MAX ; 
 int /*<<< orphan*/  eprintf (char*,...) ; 
 void* iob_open (char const*) ; 
 int /*<<< orphan*/  iob_select (char*) ; 
 TYPE_1__* r_io_desc_new (TYPE_2__*,int /*<<< orphan*/ *,char const*,int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  r_io_plugin_windbg ; 
 int /*<<< orphan*/  strncmp (char const*,char*,int) ; 
 int /*<<< orphan*/  windbg_ctx_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * windbg_ctx_new (void*) ; 
 scalar_t__ windbg_get_target (int /*<<< orphan*/ ) ; 
 int windbg_read_at (int /*<<< orphan*/ ,int /*<<< orphan*/ *,scalar_t__,int) ; 
 int windbg_read_at_phys (int /*<<< orphan*/ ,int /*<<< orphan*/ *,scalar_t__,int) ; 
 int /*<<< orphan*/  windbg_va_to_pa (int /*<<< orphan*/ ,scalar_t__,scalar_t__*) ; 
 int windbg_write_at (int /*<<< orphan*/ ,int /*<<< orphan*/  const*,scalar_t__,int) ; 
 int windbg_write_at_phys (int /*<<< orphan*/ ,int /*<<< orphan*/  const*,scalar_t__,int) ; 

__attribute__((used)) static bool __plugin_open(RIO *io, const char *file, bool many) {
	return (!strncmp (file, "windbg://", 9));
}

__attribute__((used)) static RIODesc *__open(RIO *io, const char *file, int rw, int mode) {
	if (!__plugin_open (io, file, 0)) {
		return NULL;
	}

	if (!iob_select ("pipe")) {
		eprintf("Could not initialize the IO backend\n");
		return NULL;
	}

	void *io_ctx = iob_open (file + 9);
	if (!io_ctx) {
		eprintf ("Could not open the pipe\n");
		return NULL;
	}
	eprintf ("Opened pipe %s with fd %p\n", file + 9, io_ctx);

	WindCtx *ctx = windbg_ctx_new (io_ctx);
	if (!ctx) {
		eprintf ("Failed to initialize windbg context\n");
		return NULL;
	}
	return r_io_desc_new (io, &r_io_plugin_windbg, file, rw, mode, ctx);
}

__attribute__((used)) static int __write(RIO *io, RIODesc *fd, const ut8 *buf, int count) {
	if (!fd) {
		return -1;
	}
	if (windbg_get_target (fd->data)) {
		ut64 va;
		if (!windbg_va_to_pa (fd->data, io->off, &va)) {
			return -1;
		}
		return windbg_write_at_phys (fd->data, buf, va, count);
	}
	return windbg_write_at (fd->data, buf, io->off, count);
}

__attribute__((used)) static ut64 __lseek(RIO *io, RIODesc *fd, ut64 offset, int whence) {
	switch (whence) {
	case R_IO_SEEK_SET:
		return offset;
	case R_IO_SEEK_CUR:
		return io->off + offset;
	case R_IO_SEEK_END:
		return UT64_MAX;
	default:
		return offset;
	}
}

__attribute__((used)) static int __read(RIO *io, RIODesc *fd, ut8 *buf, int count) {
	if (!fd) {
		return -1;
	}

	if (windbg_get_target (fd->data)) {
		ut64 va;
		if (!windbg_va_to_pa (fd->data, io->off, &va)) {
			return -1;
		}
		return windbg_read_at_phys (fd->data, buf, va, count);
	}

	return windbg_read_at (fd->data, buf, io->off, count);
}

__attribute__((used)) static int __close(RIODesc *fd) {
	windbg_ctx_free (fd->data);
	return true;
}

