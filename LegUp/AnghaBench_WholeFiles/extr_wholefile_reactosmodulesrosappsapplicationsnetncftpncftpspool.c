#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ time_t ;
struct tm {int dummy; } ;
struct stat {scalar_t__ st_mtime; } ;
typedef  int /*<<< orphan*/  spathname2 ;
typedef  int /*<<< orphan*/  spathname ;
typedef  int /*<<< orphan*/  sdir ;
typedef  scalar_t__ pid_t ;
typedef  int mode_t ;
typedef  int /*<<< orphan*/  ldir2 ;
typedef  int /*<<< orphan*/  f ;
typedef  int /*<<< orphan*/  dstr ;
struct TYPE_7__ {char* defaultAnonPassword; } ;
struct TYPE_6__ {scalar_t__ lip; } ;
typedef  int /*<<< orphan*/  FTPLibraryInfo ;
typedef  int /*<<< orphan*/  FTPConnectionInfo ;
typedef  TYPE_1__* FTPCIPtr ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  CloseControlConnection (TYPE_1__* const) ; 
 scalar_t__ EINTR ; 
 int /*<<< orphan*/  FOPEN_WRITE_TEXT ; 
 int /*<<< orphan*/  FTPGetLocalCWD (char*,int) ; 
 scalar_t__ MkDirs (char*,int) ; 
 int O_TRUNC ; 
 int O_WRONLY ; 
 int /*<<< orphan*/  OurDirectoryPath (char*,size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Strncat (char*,char*,size_t) ; 
 int /*<<< orphan*/  Strncpy (char*,char const* const,size_t) ; 
 int /*<<< orphan*/  ToBase64 (char*,char const* const,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  X_OK ; 
 char* YESNO (int) ; 
 scalar_t__ access (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  close (int) ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  execvp (char*,char**) ; 
 int /*<<< orphan*/  exit (int) ; 
 scalar_t__ fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (char*,int /*<<< orphan*/ ) ; 
 scalar_t__ fork () ; 
 scalar_t__ fprintf (int /*<<< orphan*/ *,char*,...) ; 
 int gHaveSpool ; 
 TYPE_2__ gLib ; 
 char* gOurDirectoryPath ; 
 int gSpoolSerial ; 
 scalar_t__ gUnprocessedJobs ; 
 scalar_t__ geteuid () ; 
 scalar_t__ getpid () ; 
 scalar_t__ kDefaultFTPPort ; 
 int /*<<< orphan*/  kPasswordMagic ; 
 int kPasswordMagicLen ; 
 int /*<<< orphan*/  kSpoolDir ; 
 int /*<<< orphan*/  kSpoolLog ; 
 struct tm* localtime (scalar_t__*) ; 
 int /*<<< orphan*/  memcpy (char*,int /*<<< orphan*/ ,int) ; 
 int open (char*,int,int) ; 
 int /*<<< orphan*/  perror (char*) ; 
 scalar_t__ pipe (int*) ; 
 scalar_t__ rename (char*,char*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int,...) ; 
 scalar_t__ stat (char*,struct stat*) ; 
 int /*<<< orphan*/ * stderr ; 
 scalar_t__ strcmp (char const* const,char*) ; 
 int /*<<< orphan*/  strftime (char*,int,char*,struct tm*) ; 
 int /*<<< orphan*/  strlen (char const* const) ; 
 scalar_t__ system (char*) ; 
 int /*<<< orphan*/  time (scalar_t__*) ; 
 int umask (int) ; 
 int /*<<< orphan*/  unlink (char*) ; 
 int /*<<< orphan*/  wait (int /*<<< orphan*/ *) ; 
 scalar_t__ write (int,char const*,int) ; 

void
TruncBatchLog(void)
{
	char f[256];
	struct stat st;
	time_t t;
	int fd;

	if (gOurDirectoryPath[0] != '\0') {
		time(&t);
		t -= 86400;
		(void) OurDirectoryPath(f, sizeof(f), kSpoolLog);
		if ((stat(f, &st) == 0) && (st.st_mtime < t)) {
			/* Truncate old log file.
			 * Do not remove it, since a process
			 * could still conceivably be going.
			 */
			fd = open(f, O_WRONLY|O_TRUNC, 00600);
			if (fd >= 0)
				close(fd);
		}
	}
}

int
MkSpoolDir(char *sdir, size_t size)
{
	struct stat st;
	*sdir = '\0';

	/* Don't create in root directory. */
	if (gOurDirectoryPath[0] != '\0') {
		(void) OurDirectoryPath(sdir, size, kSpoolDir);
		if ((stat(sdir, &st) < 0) && (MkDirs(sdir, 00700) < 0)) {
			perror(sdir);
			return (-1);
		} else {
			return (0);
		}
	}
	return (-1);
}

void
SpoolName(const char *const sdir, char *sp, size_t size, int flag, int serial, time_t when)
{
	char sname[64];
	char dstr[32];
	struct tm *ltp;

	if ((when == (time_t) 0) || (when == (time_t) -1))
		(void) time(&when);
	ltp = localtime(&when);
	if (ltp == NULL) {
		/* impossible */
		(void) Strncpy(dstr, "19700101-000000", size);
	} else {
		(void) strftime(dstr, sizeof(dstr), "%Y%m%d-%H%M%S", ltp);
	}
	(void) Strncpy(sp, sdir, size);
	(void) sprintf(sname, "/%c-%010u-%04x-%s",
		flag,
		(unsigned int) getpid(),
		(serial % (16 * 16 * 16 * 16)),
		dstr
	);
	(void) Strncat(sp, sname, size);
}

int
HaveSpool(void)
{
#if defined(WIN32) || defined(_WINDOWS)
	char ncftpbatch[260];

	if (gHaveSpool < 0) {
		gHaveSpool = 0;
		if (gOurInstallationPath[0] != '\0') {
			OurInstallationPath(ncftpbatch, sizeof(ncftpbatch), "ncftpbatch.exe");
			gHaveSpool = (_access(ncftpbatch, F_OK) == 0) ? 1 : 0;
		}
	}
#elif defined(BINDIR)
	char ncftpbatch[256];

	if (gHaveSpool < 0) {
		STRNCPY(ncftpbatch, BINDIR);
		STRNCAT(ncftpbatch, "/");
		STRNCAT(ncftpbatch, "ncftpbatch");
		gHaveSpool = (access(ncftpbatch, X_OK) == 0) ? 1 : 0;
	}
#else	/* BINDIR */
	if (gHaveSpool < 0) {
		if (geteuid() == 0) {
			gHaveSpool = (access("/usr/bin/ncftpbatch", X_OK) == 0) ? 1 : 0;
		} else {
			gHaveSpool = (system("ncftpbatch -X") == 0) ? 1 : 0;
		}
	}
#endif /* BINDIR */

	return (gHaveSpool);
}

int
CanSpool(void)
{
	char sdir[256];

	if (gOurDirectoryPath[0] == '\0') {
		return (-1);
	}
	if (MkSpoolDir(sdir, sizeof(sdir)) < 0)
		return (-1);
	return (0);
}

int
SpoolX(
	const char *const op,
	const char *const rfile,
	const char *const rdir,
	const char *const lfile,
	const char *const ldir,
	const char *const host,
	const char *const ip,
	const unsigned int port,
	const char *const user,
	const char *const passclear,
	int xtype,
	int recursive,
	int delete,
	int passive,
	const char *const precmd,
	const char *const perfilecmd,
	const char *const postcmd,
	time_t when)
{
	char sdir[256];
	char pass[160];
	char spathname[256];
	char spathname2[256];
	char ldir2[256];
	FILE *fp;
#if defined(WIN32) || defined(_WINDOWS)
#else
	mode_t um;
#endif

	if (MkSpoolDir(sdir, sizeof(sdir)) < 0)
		return (-1);

	gSpoolSerial++;
	SpoolName(sdir, spathname2, sizeof(spathname2), op[0], gSpoolSerial, when);
	SpoolName(sdir, spathname, sizeof(spathname), 'z', gSpoolSerial, when);
#if defined(WIN32) || defined(_WINDOWS)
	fp = fopen(spathname, FOPEN_WRITE_TEXT);
#else
	um = umask(077);
	fp = fopen(spathname, FOPEN_WRITE_TEXT);
	(void) umask(um);
#endif
	if (fp == NULL)
		return (-1);

	if (fprintf(fp, "# This is a NcFTP spool file entry.\n# Run the \"ncftpbatch\" program to process the spool directory.\n#\n") < 0)
		goto err;
	if (fprintf(fp, "op=%s\n", op) < 0)
		goto err;
	if (fprintf(fp, "hostname=%s\n", host) < 0)
		goto err;
	if ((ip != NULL) && (ip[0] != '\0') && (fprintf(fp, "host-ip=%s\n", ip) < 0))
		goto err;
	if ((port > 0) && (port != (unsigned int) kDefaultFTPPort) && (fprintf(fp, "port=%u\n", port) < 0))
		goto err;
	if ((user != NULL) && (user[0] != '\0') && (strcmp(user, "anonymous") != 0) && (fprintf(fp, "user=%s\n", user) < 0))
		goto err;
	if ((strcmp(user, "anonymous") != 0) && (passclear != NULL) && (passclear[0] != '\0')) {
		(void) memcpy(pass, kPasswordMagic, kPasswordMagicLen);
		ToBase64(pass + kPasswordMagicLen, passclear, strlen(passclear), 1);
		if (fprintf(fp, "pass=%s\n", pass) < 0)
			goto err;
	} else if ((strcmp(user, "anonymous") == 0) && (gLib.defaultAnonPassword[0] != '\0')) {
		if (fprintf(fp, "anon-pass=%s\n", gLib.defaultAnonPassword) < 0)
			goto err;
	}
	if (fprintf(fp, "xtype=%c\n", xtype) < 0)
		goto err;
	if ((recursive != 0) && (fprintf(fp, "recursive=%s\n", YESNO(recursive)) < 0))
		goto err;
	if ((delete != 0) && (fprintf(fp, "delete=%s\n", YESNO(delete)) < 0))
		goto err;
	if (fprintf(fp, "passive=%d\n", passive) < 0)
		goto err;
	if (fprintf(fp, "remote-dir=%s\n", rdir) < 0)
		goto err;
	if ((ldir == NULL) || (ldir[0] == '\0') || (strcmp(ldir, ".") == 0)) {
		/* Use current process' working directory. */
		FTPGetLocalCWD(ldir2, sizeof(ldir2));
		if (fprintf(fp, "local-dir=%s\n", ldir2) < 0)
			goto err;
	} else {
		if (fprintf(fp, "local-dir=%s\n", ldir) < 0)
			goto err;
	}
	if (fprintf(fp, "remote-file=%s\n", rfile) < 0)
		goto err;
	if (fprintf(fp, "local-file=%s\n", lfile) < 0)
		goto err;
	if ((precmd != NULL) && (precmd[0] != '\0') && (fprintf(fp, "pre-command=%s\n", precmd) < 0))
		goto err;
	if ((perfilecmd != NULL) && (perfilecmd[0] != '\0') && (fprintf(fp, "per-file-command=%s\n", perfilecmd) < 0))
		goto err;
	if ((postcmd != NULL) && (postcmd[0] != '\0') && (fprintf(fp, "post-command=%s\n", postcmd) < 0))
		goto err;

	if (fclose(fp) < 0)
		goto err2;

	/* Move the spool file into its "live" name. */
	if (rename(spathname, spathname2) < 0) {
		perror("rename spoolfile failed");
		goto err3;
	}
	gUnprocessedJobs++;
	return (0);

err:
	(void) fclose(fp);
err2:
	perror("write to spool file failed");
err3:
	(void) unlink(spathname);
	return (-1);
}

__attribute__((used)) static int
PWrite(int sfd, const char *const buf0, size_t size)
{
	int nleft;
	const char *buf = buf0;
	int nwrote;

	nleft = (int) size;
	for (;;) {
		nwrote = (int) write(sfd, buf, nleft);
		if (nwrote < 0) {
			if (errno != EINTR) {
				nwrote = (int) size - nleft;
				if (nwrote == 0)
					nwrote = -1;
				return (nwrote);
			} else {
				errno = 0;
				nwrote = 0;
				/* Try again. */
			}
		}
		nleft -= nwrote;
		if (nleft <= 0)
			break;
		buf += nwrote;
	}
	nwrote = (int) size - nleft;
	return (nwrote);
}

void
Jobs(void)
{
#if defined(WIN32) || defined(_WINDOWS)
	assert(0); // Not supported
#else
	char *argv[8];
	pid_t pid;
#ifdef BINDIR
	char ncftpbatch[256];

	STRNCPY(ncftpbatch, BINDIR);
	STRNCAT(ncftpbatch, "/");
	STRNCAT(ncftpbatch, "ncftpbatch");
#endif	/* BINDIR */

	pid = fork();
	if (pid < 0) {
		perror("fork");
	} else if (pid == 0) {
		argv[0] = (char *) "ncftpbatch";
		argv[1] = (char *) "-l";
		argv[2] = NULL;

#ifdef BINDIR
		(void) execv(ncftpbatch, argv);
		(void) fprintf(stderr, "Could not run %s.  Is it in installed as %s?\n", argv[0], ncftpbatch);
#else	/* BINDIR */
		(void) execvp(argv[0], argv);
		(void) fprintf(stderr, "Could not run %s.  Is it in your $PATH?\n", argv[0]);
#endif	/* BINDIR */
		perror(argv[0]);
		exit(1);
	} else {
#ifdef HAVE_WAITPID
		(void) waitpid(pid, NULL, 0);
#else
		(void) wait(NULL);
#endif
	}
#endif
}

void
RunBatch(int Xstruct, const FTPCIPtr cip)
{
#if defined(WIN32) || defined(_WINDOWS)
	char ncftpbatch[260];
	const char *prog;
	int winExecResult;

	if (gOurInstallationPath[0] == '\0') {
		(void) fprintf(stderr, "Cannot find path to %s.  Please re-run Setup.\n", "ncftpbatch.exe");
		return;
	}
	prog = ncftpbatch;
	OurInstallationPath(ncftpbatch, sizeof(ncftpbatch), "ncftpbatch.exe");

	winExecResult = WinExec(prog, SW_SHOWNORMAL);
	if (winExecResult <= 31) switch (winExecResult) {
		case ERROR_BAD_FORMAT:
			fprintf(stderr, "Could not run %s: %s\n", prog, "The .EXE file is invalid");
			return;
		case ERROR_FILE_NOT_FOUND:
			fprintf(stderr, "Could not run %s: %s\n", prog, "The specified file was not found.");
			return;
		case ERROR_PATH_NOT_FOUND:
			fprintf(stderr, "Could not run %s: %s\n", prog, "The specified path was not found.");
			return;
		default:
			fprintf(stderr, "Could not run %s: Unknown error #%d.\n", prog, winExecResult);
			return;
	}
#else
	int pfd[2];
	char pfdstr[32];
	char *argv[8];
	pid_t pid = 0;
#ifdef BINDIR
	char ncftpbatch[256];

	STRNCPY(ncftpbatch, BINDIR);
	STRNCAT(ncftpbatch, "/");
	STRNCAT(ncftpbatch, "ncftpbatch");
#endif	/* BINDIR */

	if (Xstruct != 0) {
		if (pipe(pfd) < 0) {
			perror("pipe");
		}

		(void) sprintf(pfdstr, "%d", pfd[0]);
		pid = fork();
		if (pid < 0) {
			(void) close(pfd[0]);
			(void) close(pfd[1]);
			perror("fork");
		} else if (pid == 0) {
			(void) close(pfd[1]);	/* Child closes write end. */
			argv[0] = (char *) "ncftpbatch";
#ifdef DEBUG_NCFTPBATCH
			argv[1] = (char *) "-SD";
#else
			argv[1] = (char *) "-d";
#endif
			argv[2] = (char *) "-|";
			argv[3] = pfdstr;
			argv[4] = NULL;

#ifdef BINDIR
			(void) execv(ncftpbatch, argv);
			(void) fprintf(stderr, "Could not run %s.  Is it in installed as %s?\n", argv[0], ncftpbatch);
#else	/* BINDIR */
			(void) execvp(argv[0], argv);
			(void) fprintf(stderr, "Could not run %s.  Is it in your $PATH?\n", argv[0]);
#endif	/* BINDIR */
			perror(argv[0]);
			exit(1);
		}
		(void) close(pfd[0]);	/* Parent closes read end. */
		(void) PWrite(pfd[1], (const char *) cip->lip, sizeof(FTPLibraryInfo));
		(void) PWrite(pfd[1], (const char *) cip, sizeof(FTPConnectionInfo));
		(void) close(pfd[1]);	/* Parent closes read end. */

		/* Close it now, or else this process would send
		 * the server a QUIT message.  This will cause it
		 * to think it already has.
		 */
		CloseControlConnection(cip);
	} else {
		pid = fork();
		if (pid < 0) {
			perror("fork");
		} else if (pid == 0) {
			argv[0] = (char *) "ncftpbatch";
			argv[1] = (char *) "-d";
			argv[2] = NULL;
#ifdef BINDIR
			(void) execv(ncftpbatch, argv);
			(void) fprintf(stderr, "Could not run %s.  Is it in installed as %s?\n", argv[0], ncftpbatch);
#else	/* BINDIR */
			(void) execvp(argv[0], argv);
			(void) fprintf(stderr, "Could not run %s.  Is it in your $PATH?\n", argv[0]);
#endif	/* BINDIR */
			perror(argv[0]);
			exit(1);
		}
	}

	if (pid > 1) {
#ifdef HAVE_WAITPID
		(void) waitpid(pid, NULL, 0);
#else
		(void) wait(NULL);
#endif
	}
#endif
}

void
RunBatchIfNeeded(const FTPCIPtr cip)
{
	if (gUnprocessedJobs > 0) {
#ifdef ncftp
		Trace(0, "Running ncftp_batch for %d job%s.\n", gUnprocessedJobs, gUnprocessedJobs > 0 ? "s" : "");
		gUnprocessedJobs = 0;
		RunBatch(1, cip);
#else
		gUnprocessedJobs = 0;
		RunBatch(0, cip);
#endif
	}
}

