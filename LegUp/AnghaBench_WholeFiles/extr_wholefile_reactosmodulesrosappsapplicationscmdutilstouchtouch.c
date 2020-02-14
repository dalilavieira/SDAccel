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
typedef  int /*<<< orphan*/  u_char ;
typedef  int time_t ;
struct utimbuf {int actime; int modtime; } ;
struct tm {int tm_year; int tm_isdst; void* tm_min; void* tm_hour; void* tm_mday; void* tm_mon; void* tm_sec; } ;
struct stat {int st_atime; int st_mtime; scalar_t__ st_size; int /*<<< orphan*/  st_mode; } ;
typedef  int /*<<< orphan*/  off_t ;
typedef  int /*<<< orphan*/  byte ;

/* Variables and functions */
 void* ATOI2 (char*) ; 
 int /*<<< orphan*/  DEFFILEMODE ; 
 int EOF ; 
 int O_CREAT ; 
 int O_RDWR ; 
 int O_WRONLY ; 
 int /*<<< orphan*/  SEEK_SET ; 
 int /*<<< orphan*/  S_ISDIR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  S_ISREG (int /*<<< orphan*/ ) ; 
 char* __progname ; 
 scalar_t__ _chmod (char*,int /*<<< orphan*/ ) ; 
 scalar_t__ _chsize (int,int /*<<< orphan*/ ) ; 
 scalar_t__ _close (int) ; 
 int _lseek (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int _open (char*,int,int /*<<< orphan*/ ) ; 
 int _read (int,int /*<<< orphan*/ *,int) ; 
 int _write (int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  err (int,char*,...) ; 
 int /*<<< orphan*/  errx (int,char*) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*) ; 
 scalar_t__ fstat (int,struct stat*) ; 
 int getopt (int,char**,char*) ; 
 struct tm* localtime (int*) ; 
 int mktime (struct tm*) ; 
 char* optarg ; 
 scalar_t__ optind ; 
 int rw (char*,struct stat*,int) ; 
 scalar_t__ stat (char*,struct stat*) ; 
 int /*<<< orphan*/  stderr ; 
 void stime_arg1 (char*,int*) ; 
 void stime_arg2 (char*,int,int*) ; 
 void stime_file (char*,int*) ; 
 char* strchr (char*,char) ; 
 int /*<<< orphan*/  strerror (int /*<<< orphan*/ ) ; 
 int strlen (char*) ; 
 int /*<<< orphan*/  strtol (char*,char**,int) ; 
 int /*<<< orphan*/  time (int*) ; 
 void usage () ; 
 int /*<<< orphan*/  utime (char*,struct utimbuf*) ; 
 int /*<<< orphan*/  warn (char*,char*) ; 
 int /*<<< orphan*/  warnx (char*,char*,int /*<<< orphan*/ ) ; 

int
main(int argc, char *argv[])
{
	struct stat sb;
	time_t tv[2];
	int aflag, cflag, fflag, mflag, ch, fd, len, rval, timeset;
	char *p;
	struct utimbuf utb;

	__progname = argv[0];

	aflag = cflag = fflag = mflag = timeset = 0;
	time(&tv[0]);

	while ((ch = getopt(argc, argv, "acfmr:t:")) != EOF)
		switch(ch) {
		case 'a':
			aflag = 1;
			break;
		case 'c':
			cflag = 1;
			break;
		case 'f':
			fflag = 1;
			break;
		case 'm':
			mflag = 1;
			break;
		case 'r':
			timeset = 1;
			stime_file(optarg, tv);
			break;
		case 't':
			timeset = 1;
			stime_arg1(optarg, tv);
			break;
		case '?':
		default:
			usage();
		}
	argc -= optind;
	argv += optind;

	/* Default is both -a and -m. */
	if (aflag == 0 && mflag == 0)
		aflag = mflag = 1;

	/*
	 * If no -r or -t flag, at least two operands, the first of which
	 * is an 8 or 10 digit number, use the obsolete time specification.
	 */
	if (!timeset && argc > 1) {
		(void)strtol(argv[0], &p, 10);
		len = p - argv[0];
		if (*p == '\0' && (len == 8 || len == 10)) {
			timeset = 1;
			stime_arg2(argv[0], len == 10, tv);
		}
	}

	/* Otherwise use the current time of day. */
	if (!timeset)
		tv[1] = tv[0];

	if (*argv == NULL)
		usage();

	for (rval = 0; *argv; ++argv) {
		/* See if the file exists. */
		if (stat(*argv, &sb)) {
			if (!cflag) {
				/* Create the file. */
				fd = _open(*argv,
				    O_WRONLY | O_CREAT, DEFFILEMODE);
				if (fd == -1 || fstat(fd, &sb) || _close(fd)) {
					rval = 1;
					warn("%s", *argv);
					continue;
				}

				/* If using the current time, we're done. */
				if (!timeset)
					continue;
			} else
				continue;
		}

		if (!aflag)
			tv[0] = sb.st_atime;
		if (!mflag)
			tv[1] = sb.st_mtime;

		/* Try utime. */
		utb.actime = tv[0];
		utb.modtime = tv[1];
		if (!utime(*argv, &utb))
			continue;

		/* If the user specified a time, nothing else we can do. */
		if (timeset) {
			rval = 1;
			warn("%s", *argv);
		}

		/*
		 * System V and POSIX 1003.1 require that a NULL argument
		 * set the access/modification times to the current time.
		 * The permission checks are different, too, in that the
		 * ability to write the file is sufficient.  Take a shot.
		 */
		 if (!utime(*argv, NULL))
			continue;

		/* Try reading/writing. */
		if (rw(*argv, &sb, fflag))
			rval = 1;
	}
	return rval;
}

void
stime_arg1(char *arg, time_t *tvp)
{
	struct tm *t;
	int yearset;
	char *p;
					/* Start with the current time. */
	if ((t = localtime(&tvp[0])) == NULL)
		err(1, "localtime");
					/* [[CC]YY]MMDDhhmm[.SS] */
	if ((p = strchr(arg, '.')) == NULL)
		t->tm_sec = 0;		/* Seconds defaults to 0. */
	else {
		if (strlen(p + 1) != 2)
			goto terr;
		*p++ = '\0';
		t->tm_sec = ATOI2(p);
	}

	yearset = 0;
	switch(strlen(arg)) {
	case 12:			/* CCYYMMDDhhmm */
		t->tm_year = ATOI2(arg);
		t->tm_year *= 1000;
		yearset = 1;
		/* FALLTHOUGH */
	case 10:			/* YYMMDDhhmm */
		if (yearset) {
			yearset = ATOI2(arg);
			t->tm_year += yearset;
		} else {
			yearset = ATOI2(arg);
			if (yearset < 69)
				t->tm_year = yearset + 2000;
			else
				t->tm_year = yearset + 1900;
		}
		t->tm_year -= 1900;	/* Convert to UNIX time. */
		/* FALLTHROUGH */
	case 8:				/* MMDDhhmm */
		t->tm_mon = ATOI2(arg);
		--t->tm_mon;		/* Convert from 01-12 to 00-11 */
		t->tm_mday = ATOI2(arg);
		t->tm_hour = ATOI2(arg);
		t->tm_min = ATOI2(arg);
		break;
	default:
		goto terr;
	}

	t->tm_isdst = -1;		/* Figure out DST. */
	tvp[0] = tvp[1] = mktime(t);
	if (tvp[0] == -1)
terr:		errx(1,
	"out of range or illegal time specification: [[CC]YY]MMDDhhmm[.SS]");
}

void
stime_arg2(char *arg, int year, time_t *tvp)
{
	struct tm *t;
					/* Start with the current time. */
	if ((t = localtime(&tvp[0])) == NULL)
		err(1, "localtime");

	t->tm_mon = ATOI2(arg);		/* MMDDhhmm[yy] */
	--t->tm_mon;			/* Convert from 01-12 to 00-11 */
	t->tm_mday = ATOI2(arg);
	t->tm_hour = ATOI2(arg);
	t->tm_min = ATOI2(arg);
	if (year)
		t->tm_year = ATOI2(arg);

	t->tm_isdst = -1;		/* Figure out DST. */
	tvp[0] = tvp[1] = mktime(t);
	if (tvp[0] == -1)
		errx(1,
	"out of range or illegal time specification: MMDDhhmm[yy]");
}

void
stime_file(char *fname, time_t *tvp)
{
	struct stat sb;

	if (stat(fname, &sb))
		err(1, "%s", fname);
	tvp[0] = sb.st_atime;
	tvp[1] = sb.st_mtime;
}

int
rw(char *fname, struct stat *sbp, int force)
{
	int fd, needed_chmod, rval;
	u_char byte;

	/* Try regular files and directories. */
	if (!S_ISREG(sbp->st_mode) && !S_ISDIR(sbp->st_mode)) {
		warnx("%s: %s", fname, strerror(0));
		return (1);
	}

	needed_chmod = rval = 0;
	if ((fd = _open(fname, O_RDWR, 0)) == -1) {
		if (!force || _chmod(fname, DEFFILEMODE))
			goto err;
		if ((fd = _open(fname, O_RDWR, 0)) == -1)
			goto err;
		needed_chmod = 1;
	}

	if (sbp->st_size != 0) {
		if (_read(fd, &byte, sizeof(byte)) != sizeof(byte))
			goto err;
		if (_lseek(fd, (off_t)0, SEEK_SET) == -1)
			goto err;
		if (_write(fd, &byte, sizeof(byte)) != sizeof(byte))
			goto err;
	} else {
		if (_write(fd, &byte, sizeof(byte)) != sizeof(byte)) {
err:			rval = 1;
			warn("%s", fname);
/*		} else if (ftruncate(fd, (off_t)0)) {*/
		} else if (_chsize(fd, (off_t)0)) {
			rval = 1;
			warn("%s: file modified", fname);
		}
	}

	if (_close(fd) && rval != 1) {
		rval = 1;
		warn("%s", fname);
	}
	if (needed_chmod && _chmod(fname, sbp->st_mode) && rval != 1) {
		rval = 1;
		warn("%s: permissions modified", fname);
	}
	return (rval);
}

void
usage()
{
	(void)fprintf(stderr,
	    "usage: touch [-acfm] [-r file] [-t time] file ...\n");
	exit(1);
}

