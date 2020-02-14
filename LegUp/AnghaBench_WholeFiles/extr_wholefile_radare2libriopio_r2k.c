#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_26__   TYPE_7__ ;
typedef  struct TYPE_25__   TYPE_2__ ;
typedef  struct TYPE_24__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ut8 ;
typedef  scalar_t__ ut64 ;
struct TYPE_26__ {int beid; int wp; scalar_t__ pid; } ;
struct TYPE_25__ {int /*<<< orphan*/  (* cb_printf ) (char*) ;scalar_t__ off; } ;
struct TYPE_24__ {scalar_t__ data; } ;
typedef  TYPE_1__ RIODesc ;
typedef  TYPE_2__ RIO ;

/* Variables and functions */
 int /*<<< orphan*/  IOCTL_READ_KERNEL_MEMORY ; 
 int /*<<< orphan*/  IOCTL_READ_PHYSICAL_ADDR ; 
 int /*<<< orphan*/  IOCTL_READ_PROCESS_ADDR ; 
 int /*<<< orphan*/  IOCTL_WRITE_KERNEL_MEMORY ; 
 int /*<<< orphan*/  IOCTL_WRITE_PHYSICAL_ADDR ; 
 int /*<<< orphan*/  IOCTL_WRITE_PROCESS_ADDR ; 
 int /*<<< orphan*/  O_RDONLY ; 
 int R_PERM_WX ; 
 int ReadMemory (TYPE_2__*,TYPE_1__*,int /*<<< orphan*/ ,scalar_t__,scalar_t__,int /*<<< orphan*/ *,int) ; 
 scalar_t__ UT64_MAX ; 
 int WriteMemory (TYPE_2__*,TYPE_1__*,int /*<<< orphan*/ ,scalar_t__,scalar_t__,int /*<<< orphan*/  const*,int) ; 
 int /*<<< orphan*/  close (int) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int,int) ; 
 int open (char*,int /*<<< orphan*/ ) ; 
 TYPE_7__ r2k_struct ; 
 TYPE_1__* r_io_desc_new (TYPE_2__*,int /*<<< orphan*/ *,char const*,int,int,void*) ; 
 int /*<<< orphan*/  r_io_plugin_r2k ; 
 int /*<<< orphan*/  run_ioctl_command (TYPE_2__*,TYPE_1__*,char const*) ; 
 int /*<<< orphan*/  strncmp (char const*,char*,int) ; 
 int /*<<< orphan*/  stub1 (char*) ; 
 int /*<<< orphan*/  stub2 (char*) ; 
 int /*<<< orphan*/  stub3 (char*) ; 

int r2k__write(RIO *io, RIODesc *fd, const ut8 *buf, int count) {
#if __WINDOWS__
	//eprintf("writing to: 0x%"PFMT64x" len: %x\n",io->off, count);
	return WriteKernelMemory (io->off, buf, count);
#elif defined (__linux__) && !defined (__GNU__)
	switch (r2k_struct.beid) {
	case 0:
		return WriteMemory (io, fd, IOCTL_WRITE_KERNEL_MEMORY, r2k_struct.pid, io->off, buf, count);
	case 1:
		return WriteMemory (io, fd, IOCTL_WRITE_PROCESS_ADDR, r2k_struct.pid, io->off, buf, count);
	case 2:
		return WriteMemory (io, fd, IOCTL_WRITE_PHYSICAL_ADDR, r2k_struct.pid, io->off, buf, count);
	default:
		io->cb_printf ("ERROR: Undefined beid in r2k__write.\n");
		return -1;
	}
#else
	io->cb_printf ("TODO: r2k not implemented for this plataform.\n");
	return -1;
#endif
}

__attribute__((used)) static int r2k__read(RIO *io, RIODesc *fd, ut8 *buf, int count) {
#if __WINDOWS__
	return ReadKernelMemory (io->off, buf, count);
#elif defined (__linux__) && !defined (__GNU__)
	switch (r2k_struct.beid) {
	case 0:
		return ReadMemory (io, fd, IOCTL_READ_KERNEL_MEMORY, r2k_struct.pid, io->off, buf, count);
	case 1:
		return ReadMemory (io, fd, IOCTL_READ_PROCESS_ADDR, r2k_struct.pid, io->off, buf, count);
	case 2:
		return ReadMemory (io, fd, IOCTL_READ_PHYSICAL_ADDR, r2k_struct.pid, io->off, buf, count);
	default:
		io->cb_printf ("ERROR: Undefined beid in r2k__read.\n");
		memset (buf, 0xff, count);
		return count;
	}
#else
	io->cb_printf ("TODO: r2k not implemented for this plataform.\n");
	memset (buf, 0xff, count);
	return count;
#endif
}

__attribute__((used)) static int r2k__close(RIODesc *fd) {
#if __WINDOWS__
	if (gHandleDriver) {
		CloseHandle (gHandleDriver);
		StartStopService (TEXT ("r2k"),TRUE);
	}
#elif defined (__linux__) && !defined (__GNU__)
	if (fd) {
		close ((int)(size_t)fd->data);
	}
#else
	eprintf ("TODO: r2k not implemented for this plataform.\n");
#endif
	return 0;
}

__attribute__((used)) static ut64 r2k__lseek(RIO *io, RIODesc *fd, ut64 offset, int whence) {
	return (!whence) ? offset : whence == 1
		? io->off + offset : UT64_MAX;
}

__attribute__((used)) static bool r2k__plugin_open(RIO *io, const char *pathname, bool many) {
	return (!strncmp (pathname, "r2k://", 6));
}

__attribute__((used)) static char *r2k__system(RIO *io, RIODesc *fd, const char *cmd) {
	if (!strncmp (cmd, "mod", 3)) {
#if __WINDOWS__
		GetSystemModules (io);
#endif
	} else {
#if defined (__linux__) && !defined (__GNU__)
		(void)run_ioctl_command (io, fd, cmd);
		return NULL;
#else
		eprintf ("Try: '=!mod'\n    '.=!mod'\n");
#endif
	}
	return NULL;
}

__attribute__((used)) static RIODesc *r2k__open(RIO *io, const char *pathname, int rw, int mode) {
	if (!strncmp (pathname, "r2k://", 6)) {
		rw |= R_PERM_WX;
#if __WINDOWS__
		RIOW32 *w32 = R_NEW0 (RIOW32);
		if (Init (&pathname[6]) == FALSE) {
			eprintf ("r2k__open: Error cant init driver: %s\n", &pathname[6]);
			free (w32);
			return NULL;
		}
		//return r_io_desc_new (&r_io_plugin_r2k, -1, pathname, rw, mode, w32);
		return r_io_desc_new (io, &r_io_plugin_r2k, pathname, rw, mode, w32);
#elif defined (__linux__) && !defined (__GNU__)
		int fd = open ("/dev/r2k", O_RDONLY);
		if (fd == -1) {
			io->cb_printf ("r2k__open: Error in opening /dev/r2k.");
			return NULL;
		}

		r2k_struct.beid = 0;
		r2k_struct.pid = 0;
		r2k_struct.wp = 1;
		return r_io_desc_new (io, &r_io_plugin_r2k, pathname, rw, mode, (void *)(size_t)fd);
#else
		io->cb_printf ("Not supported on this platform\n");
#endif
	}
	return NULL;
}

