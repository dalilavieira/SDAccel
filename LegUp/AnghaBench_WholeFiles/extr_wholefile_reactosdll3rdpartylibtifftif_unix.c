#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  va_list ;
typedef  scalar_t__ uint64 ;
typedef  int /*<<< orphan*/  toff_t ;
typedef  scalar_t__ tmsize_t ;
typedef  void* thandle_t ;
struct TYPE_8__ {int fd; void* h; } ;
typedef  TYPE_1__ fd_as_handle_union_t ;
struct TYPE_9__ {scalar_t__ st_size; } ;
typedef  TYPE_2__ _TIFF_stat_s ;
typedef  scalar_t__ _TIFF_off_t ;
struct TYPE_10__ {int tif_fd; } ;
typedef  int /*<<< orphan*/  TIFFIOSize_t ;
typedef  TYPE_3__ TIFF ;

/* Variables and functions */
 scalar_t__ EINVAL ; 
 TYPE_3__* TIFFClientOpen (char const*,char const*,void*,scalar_t__ (*) (void*,void*,scalar_t__),scalar_t__ (*) (void*,void*,scalar_t__),scalar_t__ (*) (void*,scalar_t__,int),int (*) (void*),scalar_t__ (*) (void*),int (*) (void*,void**,int /*<<< orphan*/ *),void (*) (void*,void*,int /*<<< orphan*/ )) ; 
 int /*<<< orphan*/  TIFFErrorExt (int /*<<< orphan*/ ,char const*,char*,char const*,...) ; 
 size_t TIFF_IO_MAX ; 
 scalar_t__ _TIFF_fstat_f (int,TYPE_2__*) ; 
 scalar_t__ _TIFF_lseek_f (int,scalar_t__,int) ; 
 int _TIFFgetMode (char const*,char const*) ; 
 void* calloc (size_t,size_t) ; 
 int close (int) ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  free (void*) ; 
 void* malloc (size_t) ; 
 int memcmp (void const*,void const*,size_t) ; 
 int /*<<< orphan*/  memcpy (void*,void const*,size_t) ; 
 int /*<<< orphan*/  memset (void*,int,size_t) ; 
 int open (char const*,int,int) ; 
 scalar_t__ read (int,char*,int /*<<< orphan*/ ) ; 
 void* realloc (void*,size_t) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/ * strerror (scalar_t__) ; 
 int /*<<< orphan*/  vfprintf (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ) ; 
 scalar_t__ write (int,char const*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static tmsize_t
_tiffReadProc(thandle_t fd, void* buf, tmsize_t size)
{
	fd_as_handle_union_t fdh;
        const size_t bytes_total = (size_t) size;
        size_t bytes_read;
        tmsize_t count = -1;
	if ((tmsize_t) bytes_total != size)
	{
		errno=EINVAL;
		return (tmsize_t) -1;
	}
	fdh.h = fd;
        for (bytes_read=0; bytes_read < bytes_total; bytes_read+=count)
        {
                char *buf_offset = (char *) buf+bytes_read;
                size_t io_size = bytes_total-bytes_read;
                if (io_size > TIFF_IO_MAX)
                        io_size = TIFF_IO_MAX;
                count=read(fdh.fd, buf_offset, (TIFFIOSize_t) io_size);
                if (count <= 0)
                        break;
        }
        if (count < 0)
                return (tmsize_t)-1;
        return (tmsize_t) bytes_read;
}

__attribute__((used)) static tmsize_t
_tiffWriteProc(thandle_t fd, void* buf, tmsize_t size)
{
	fd_as_handle_union_t fdh;
	const size_t bytes_total = (size_t) size;
        size_t bytes_written;
        tmsize_t count = -1;
	if ((tmsize_t) bytes_total != size)
	{
		errno=EINVAL;
		return (tmsize_t) -1;
	}
	fdh.h = fd;
        for (bytes_written=0; bytes_written < bytes_total; bytes_written+=count)
        {
                const char *buf_offset = (char *) buf+bytes_written;
                size_t io_size = bytes_total-bytes_written;
                if (io_size > TIFF_IO_MAX)
                        io_size = TIFF_IO_MAX;
                count=write(fdh.fd, buf_offset, (TIFFIOSize_t) io_size);
                if (count <= 0)
                        break;
        }
        if (count < 0)
                return (tmsize_t)-1;
        return (tmsize_t) bytes_written;
	/* return ((tmsize_t) write(fdh.fd, buf, bytes_total)); */
}

__attribute__((used)) static uint64
_tiffSeekProc(thandle_t fd, uint64 off, int whence)
{
	fd_as_handle_union_t fdh;
	_TIFF_off_t off_io = (_TIFF_off_t) off;
	if ((uint64) off_io != off)
	{
		errno=EINVAL;
		return (uint64) -1; /* this is really gross */
	}
	fdh.h = fd;
	return((uint64)_TIFF_lseek_f(fdh.fd,off_io,whence));
}

__attribute__((used)) static int
_tiffCloseProc(thandle_t fd)
{
	fd_as_handle_union_t fdh;
	fdh.h = fd;
	return(close(fdh.fd));
}

__attribute__((used)) static uint64
_tiffSizeProc(thandle_t fd)
{
	_TIFF_stat_s sb;
	fd_as_handle_union_t fdh;
	fdh.h = fd;
	if (_TIFF_fstat_f(fdh.fd,&sb)<0)
		return(0);
	else
		return((uint64)sb.st_size);
}

__attribute__((used)) static int
_tiffMapProc(thandle_t fd, void** pbase, toff_t* psize)
{
	(void) fd; (void) pbase; (void) psize;
	return (0);
}

__attribute__((used)) static void
_tiffUnmapProc(thandle_t fd, void* base, toff_t size)
{
	(void) fd; (void) base; (void) size;
}

TIFF*
TIFFFdOpen(int fd, const char* name, const char* mode)
{
	TIFF* tif;

	fd_as_handle_union_t fdh;
	fdh.fd = fd;
	tif = TIFFClientOpen(name, mode,
	    fdh.h,
	    _tiffReadProc, _tiffWriteProc,
	    _tiffSeekProc, _tiffCloseProc, _tiffSizeProc,
	    _tiffMapProc, _tiffUnmapProc);
	if (tif)
		tif->tif_fd = fd;
	return (tif);
}

TIFF*
TIFFOpen(const char* name, const char* mode)
{
	static const char module[] = "TIFFOpen";
	int m, fd;
	TIFF* tif;

	m = _TIFFgetMode(mode, module);
	if (m == -1)
		return ((TIFF*)0);

/* for cygwin and mingw */
#ifdef O_BINARY
	m |= O_BINARY;
#endif

	fd = open(name, m, 0666);
	if (fd < 0) {
		if (errno > 0 && strerror(errno) != NULL ) {
			TIFFErrorExt(0, module, "%s: %s", name, strerror(errno) );
		} else {
			TIFFErrorExt(0, module, "%s: Cannot open", name);
		}
		return ((TIFF *)0);
	}

	tif = TIFFFdOpen((int)fd, name, mode);
	if(!tif)
		close(fd);
	return tif;
}

void*
_TIFFmalloc(tmsize_t s)
{
        if (s == 0)
                return ((void *) NULL);

	return (malloc((size_t) s));
}

void* _TIFFcalloc(tmsize_t nmemb, tmsize_t siz)
{
    if( nmemb == 0 || siz == 0 )
        return ((void *) NULL);

    return calloc((size_t) nmemb, (size_t)siz);
}

void
_TIFFfree(void* p)
{
	free(p);
}

void*
_TIFFrealloc(void* p, tmsize_t s)
{
	return (realloc(p, (size_t) s));
}

void
_TIFFmemset(void* p, int v, tmsize_t c)
{
	memset(p, v, (size_t) c);
}

void
_TIFFmemcpy(void* d, const void* s, tmsize_t c)
{
	memcpy(d, s, (size_t) c);
}

int
_TIFFmemcmp(const void* p1, const void* p2, tmsize_t c)
{
	return (memcmp(p1, p2, (size_t) c));
}

__attribute__((used)) static void
unixWarningHandler(const char* module, const char* fmt, va_list ap)
{
	if (module != NULL)
		fprintf(stderr, "%s: ", module);
	fprintf(stderr, "Warning, ");
	vfprintf(stderr, fmt, ap);
	fprintf(stderr, ".\n");
}

__attribute__((used)) static void
unixErrorHandler(const char* module, const char* fmt, va_list ap)
{
	if (module != NULL)
		fprintf(stderr, "%s: ", module);
	vfprintf(stderr, fmt, ap);
	fprintf(stderr, ".\n");
}

