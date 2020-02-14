#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_65__   TYPE_7__ ;
typedef  struct TYPE_64__   TYPE_6__ ;
typedef  struct TYPE_63__   TYPE_4__ ;
typedef  struct TYPE_62__   TYPE_2__ ;
typedef  struct TYPE_61__   TYPE_1__ ;

/* Type definitions */
typedef  int time_t ;
struct tm {int tm_isdst; scalar_t__ tm_mon; int tm_mday; int tm_year; int tm_hour; int tm_min; int mode; char ftype; int ftime; char* perm; char* owner; char* group; char* fname; char* linkto; void* fsize; void* gid; void* uid; } ;
struct passwd {char* pw_dir; } ;
struct dirent {char* d_name; } ;
struct Stat {int st_mtime; scalar_t__ st_size; int /*<<< orphan*/  st_mode; } ;
typedef  char* string ;
typedef  int /*<<< orphan*/  savedcwd ;
typedef  int /*<<< orphan*/  pattern2 ;
typedef  int /*<<< orphan*/  patPrefix ;
typedef  int /*<<< orphan*/  mode_t ;
typedef  char* longstring ;
typedef  void* longest_int ;
typedef  int /*<<< orphan*/  linkto ;
typedef  int /*<<< orphan*/  line ;
typedef  int /*<<< orphan*/  hdir ;
typedef  int /*<<< orphan*/  gfile ;
typedef  int /*<<< orphan*/  fname ;
typedef  int /*<<< orphan*/  cwd ;
typedef  int /*<<< orphan*/  curcwd ;
struct TYPE_65__ {int serverType; char const* magic; int errNo; } ;
struct TYPE_64__ {size_t relnameLen; char* relname; char* lname; char* rlinkto; int mdtm; char type; char* plug; void* size; int /*<<< orphan*/ * rname; } ;
struct TYPE_63__ {size_t maxFileLen; size_t maxPlugLen; } ;
struct TYPE_62__ {TYPE_1__* first; TYPE_1__* last; } ;
struct TYPE_61__ {char* line; struct TYPE_61__* next; } ;
typedef  struct tm* MLstItemPtr ;
typedef  struct tm MLstItem ;
typedef  TYPE_1__* LinePtr ;
typedef  TYPE_2__* LineListPtr ;
typedef  TYPE_2__ LineList ;
typedef  TYPE_4__* FileInfoListPtr ;
typedef  TYPE_4__ FileInfoList ;
typedef  TYPE_6__ FileInfo ;
typedef  int /*<<< orphan*/  FTPSigProc ;
typedef  int (* FTPFtwProc ) (TYPE_7__* const,char*,int /*<<< orphan*/ ) ;
typedef  TYPE_7__* FTPCIPtr ;
typedef  int /*<<< orphan*/  FILE ;
typedef  int /*<<< orphan*/  DIR ;

/* Variables and functions */
 int /*<<< orphan*/  AddFileInfo (TYPE_4__*,TYPE_6__*) ; 
 int /*<<< orphan*/  AddLine (TYPE_2__*,char const*) ; 
 int /*<<< orphan*/  ComputeRNames (TYPE_4__*,char* const,int,int) ; 
 int /*<<< orphan*/  ConcatFileInfoList (TYPE_4__*,TYPE_4__*) ; 
 int /*<<< orphan*/  ConcatFileToFileInfoList (TYPE_4__*,char* const) ; 
 int /*<<< orphan*/  DisposeFileInfoListContents (TYPE_4__*) ; 
 int /*<<< orphan*/  DisposeLineListContents (TYPE_2__*) ; 
 int /*<<< orphan*/  Error (TYPE_7__*,int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/ * FGets (char*,int,int /*<<< orphan*/ *) ; 
 int FTPChdir (TYPE_7__* const,char* const) ; 
 int FTPGetCWD (TYPE_7__* const,char*,int) ; 
 int FTPIsDir (TYPE_7__* const,char const* const) ; 
 int FTPListToMemory2 (TYPE_7__*,char const*,TYPE_2__*,char const*,int,int*) ; 
 scalar_t__ GLOBCHARSINSTR (char const*) ; 
 int /*<<< orphan*/  GetHomeDir (char*,int) ; 
 scalar_t__ ISTREQ (char*,char*) ; 
 scalar_t__ ISTRNEQ (char*,char*,int) ; 
 int /*<<< orphan*/  InitFileInfoList (TYPE_4__*) ; 
 int /*<<< orphan*/  InitLineList (TYPE_2__*) ; 
 scalar_t__ IsLocalPathDelim (char) ; 
 char* LOCAL_PATH_DELIM_STR ; 
 scalar_t__ Lstat (char*,struct Stat*) ; 
 int /*<<< orphan*/  NcSignal (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PrintF (TYPE_7__*,char*,char*) ; 
 TYPE_1__* RemoveLine (TYPE_2__*,TYPE_1__*) ; 
 int /*<<< orphan*/  SIGPIPE ; 
 scalar_t__ SIG_IGN ; 
 scalar_t__ STREQ (char*,char*) ; 
 int /*<<< orphan*/  STRNCAT (char*,char*) ; 
 char* STRNCPY (char*,char const*) ; 
 scalar_t__ S_ISDIR (int /*<<< orphan*/ ) ; 
 scalar_t__ S_ISREG (int /*<<< orphan*/ ) ; 
 char* StrDup (char*) ; 
 char* StrFindLocalPathDelim (char*) ; 
 char* StrRFindLocalPathDelim (char*) ; 
 int /*<<< orphan*/  Strncat (char*,char*,size_t) ; 
 int /*<<< orphan*/  Strncpy (char*,char const* const,size_t) ; 
 char* Strnpcat (char*,char*,size_t) ; 
 int UnMDTMDate (char*) ; 
 void* atoi (char*) ; 
 int /*<<< orphan*/  closedir (int /*<<< orphan*/ *) ; 
 struct passwd* getpwnam (char*) ; 
 scalar_t__ isalnum (int) ; 
 scalar_t__ isdigit (int) ; 
 scalar_t__ islower (int) ; 
 scalar_t__ ispunct (int) ; 
 scalar_t__ isspace (char) ; 
 scalar_t__ isupper (int) ; 
 int /*<<< orphan*/  kDoPerror ; 
 int kErrBadLineList ; 
 int kErrBadMagic ; 
 int kErrBadParameter ; 
 void* kErrCannotGoToPrevDir ; 
 int kErrGlobFailed ; 
 int kErrGlobNoMatch ; 
 int kErrNotADirectory ; 
 int kErrRecursionLimitReached ; 
 int /*<<< orphan*/  kFtwDir ; 
 int /*<<< orphan*/  kFtwFile ; 
 char* kGlobChars ; 
 int kGlobYes ; 
 char* kLibraryMagic ; 
 int kModTimeUnknown ; 
 int kNoErr ; 
 int kServerTypeMicrosoftFTP ; 
 void* kSizeUnknown ; 
 struct tm* localtime (int*) ; 
 scalar_t__ malloc (int) ; 
 int /*<<< orphan*/  memcpy (char*,char const* const,size_t) ; 
 int /*<<< orphan*/  memset (struct tm* const,int /*<<< orphan*/ ,int) ; 
 int mktime (struct tm*) ; 
 int /*<<< orphan*/ * opendir (char*) ; 
 int /*<<< orphan*/  pclose (int /*<<< orphan*/ *) ; 
 scalar_t__ popen (char*,char*) ; 
 struct dirent* readdir (int /*<<< orphan*/ *) ; 
 char** rwx ; 
 int /*<<< orphan*/  sprintf (char const*,char*,char const*,char const*,...) ; 
 int /*<<< orphan*/  sscanf (char*,char*,long*) ; 
 char* strchr (char*,char) ; 
 scalar_t__ strcmp (char const*,char*) ; 
 int /*<<< orphan*/  strcpy (char*,char*) ; 
 int strlen (char const* const) ; 
 scalar_t__ strncmp (char*,char*,int) ; 
 int /*<<< orphan*/ * strrchr (char*,char) ; 
 char* strstr (char*,char*) ; 
 int stub1 (TYPE_7__* const,char*,int /*<<< orphan*/ ) ; 
 int stub2 (TYPE_7__* const,char*,int /*<<< orphan*/ ) ; 
 int stub3 (TYPE_7__* const,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  time (int*) ; 

__attribute__((used)) static void
RemoteGlobCollapse(const char *pattern, LineListPtr fileList)
{
	LinePtr lp, nextLine;
	string patPrefix;
	string cur, prev;
	char *endp, *cp, *dp;
	const char *pp;
	int wasGlobChar;
	size_t plen;

	/* Copy all characters before the first glob-char. */
	dp = patPrefix;
	endp = dp + sizeof(patPrefix) - 1;
	wasGlobChar = 0;
	for (cp = (char *) pattern; dp < endp; ) {
		for (pp=kGlobChars; *pp != '\0'; pp++) {
			if (*pp == *cp) {
				wasGlobChar = 1;
				break;
			}
		}
		if (wasGlobChar)
			break;
		*dp++ = *cp++;
	}
	*dp = '\0';
	plen = (size_t) (dp - patPrefix);

	*prev = '\0';
	for (lp=fileList->first; lp != NULL; lp = nextLine) {
		nextLine = lp->next;
		if (strncmp(lp->line, patPrefix, plen) == 0) {
			(void) STRNCPY(cur, lp->line + plen);
			cp = strchr(cur, '/');
			if (cp == NULL)
				cp = strchr(cur, '\\');
			if (cp != NULL)
				*cp = '\0';
			if ((*prev != '\0') && (STREQ(cur, prev))) {
				nextLine = RemoveLine(fileList, lp);
			} else {
				(void) STRNCPY(prev, cur);
				/* We are playing with a dynamically
				 * allocated string, but since the
				 * following expression is guaranteed
				 * to be the same or shorter, we won't
				 * overwrite the bounds.
				 */
				(void) sprintf(lp->line, "%s%s", patPrefix, cur);
			}
		}
	}
}

__attribute__((used)) static int
LsMonthNameToNum(char *cp)
{
	int mon;	/* 0..11 */

	switch (*cp++) {
		case 'A':
			mon = (*cp == 'u') ? 7 : 3;
			break;
		case 'D':
			mon = 11;
			break;
		case 'F':
			mon = 1;
			break;
		default:
		case 'J':
			if (*cp++ == 'u')
				mon = (*cp == 'l') ? 6 : 5;
			else
				mon = 0;
			break;
		case 'M':
			mon = (*++cp == 'r') ? 2 : 4;
			break;
		case 'N':
			mon = 10;
			break;
		case 'O':
			mon = 9;
			break;
		case 'S':
			mon = 8;
	}
	return (mon);
}

__attribute__((used)) static int
UnDosLine(	char *const line,
		const char *const curdir,
		size_t curdirlen,
		char *fname,
		size_t fnamesize,
		int *ftype,
		longest_int *fsize,
		time_t *ftime)
{
	char *cp;
	int hour, year;
	char *filestart;
	char *sizestart;
	struct tm ftm;

	/*
	 *
0123456789012345678901234567890123456789012345678901234567890123456789
04-27-99  10:32PM               270158 Game booklet.pdf
03-11-99  10:03PM       <DIR>          Get A3d Banner

We also try to parse the format from CMD.EXE, which is similar:

03/22/2001  06:23p              62,325 cls.pdf

	 *
	 */
	cp = line;
	if (
		isdigit((int) cp[0])
		&& isdigit((int) cp[1])
		&& ispunct((int) cp[2])
		&& isdigit((int) cp[3])
		&& isdigit((int) cp[4])
		&& ispunct((int) cp[5])
		&& isdigit((int) cp[6])
		&& isdigit((int) cp[7])
	) {
		(void) memset(&ftm, 0, sizeof(struct tm));
		ftm.tm_isdst = -1;
		cp[2] = '\0';
		ftm.tm_mon = atoi(cp + 0);
		if (ftm.tm_mon > 0)
			ftm.tm_mon -= 1;
		cp[5] = '\0';
		ftm.tm_mday = atoi(cp + 3);
		if ((isdigit((int) cp[8])) && (isdigit((int) cp[9]))) {
			/* Four-digit year */
			cp[10] = '\0';
			year = atoi(cp + 6);
			if (year > 1900)
				year -= 1900;
			ftm.tm_year = year;	/* years since 1900 */
			cp += 11;
		} else {
			/* Two-digit year */
			cp[8] = '\0';
			year = atoi(cp + 6);
			if (year < 98)
				year += 100;
			ftm.tm_year = year;	/* years since 1900 */
			cp += 9;
		}

		for (;;) {
			if (*cp == '\0')
				return (-1);
			if (isdigit(*cp))
				break;
			cp++;
		}

		cp[2] = '\0';
		hour = atoi(cp);
		if (((cp[5] == 'P') || (cp[5] == 'p')) && (hour < 12))
			hour += 12;
		else if (((cp[5] == 'A') || (cp[5] == 'a')) && (hour == 12))
			hour -= 12;
		ftm.tm_hour = hour;
		cp[5] = '\0';
		ftm.tm_min = atoi(cp + 3);
		*ftime = mktime(&ftm);
		if (*ftype == (time_t) -1)
			return (-1);

		cp += 6;
		*ftype = '-';
		for (;;) {
			if (*cp == '\0')
				return (-1);
			if ((*cp == '<') && (cp[1] == 'D')) {
				/* found <DIR> */
				*ftype = 'd';
				cp += 5;
				break;	/* size field will end up being empty string */
			} else if ((*cp == '<') && (cp[1] == 'J')) {
				/* found <JUNCTION>
				 *
				 * Will we ever really see this?
				 * IIS from Win2000sp1 sends <DIR>
				 * for FTP, but CMD.EXE prints
				 * <JUNCTION>.
				 */
				*ftype = 'd';
				cp += 10;
				break;
			} else if (isdigit(*cp)) {
				break;
			} else {
				cp++;
			}
		}

		sizestart = cp;
		for (;;) {
			if (*cp == '\0')
				return (-1);
#ifdef HAVE_MEMMOVE
			if (*cp == ',') {
				/* Yuck -- US Locale dependency */
				memmove(cp, cp + 1, strlen(cp + 1) + 1);
			}
#endif
			if (!isdigit(*cp)) {
				*cp++ = '\0';
				break;
			}
			cp++;
		}

		if (fsize != NULL) {
#if defined(HAVE_LONG_LONG) && defined(SCANF_LONG_LONG)
			if (*ftype == 'd')
				*fsize = 0;
			else
				(void) sscanf(sizestart, SCANF_LONG_LONG, fsize);
#elif defined(HAVE_LONG_LONG) && defined(HAVE_STRTOQ)
			if (*ftype == 'd')
				*fsize = 0;
			else
				*fsize = (longest_int) strtoq(sizestart, NULL, 0);
#else
			*fsize = (longest_int) 0;
			if (*ftype != 'd') {
				long fsize2 = 0L;

				(void) sscanf(sizestart, "%ld", &fsize2);
				*fsize = (longest_int) fsize2;
			}
#endif
		}

		for (;;) {
			if (*cp == '\0')
				return (-1);
			if (!isspace(*cp)) {
				break;
			}
			cp++;
		}

		filestart = cp;
		if (curdirlen == 0) {
			(void) Strncpy(fname, filestart, fnamesize);
		} else {
			(void) Strncpy(fname, curdir, fnamesize);
			(void) Strncat(fname, filestart, fnamesize);
		}

		return (0);
	}
	return (-1);
}

__attribute__((used)) static int
UnLslRLine(	char *const line,
		const char *const curdir,
		size_t curdirlen,
		char *fname,
		size_t fnamesize,
		char *linkto,
		size_t linktosize,
		int *ftype,
		longest_int *fsize,
		time_t *ftime,
		time_t now,
		int thisyear,
		int *plugend)
{
	char *cp;
	int mon = 0, dd = 0, hr = 0, min = 0, year = 0;
	char *monstart, *ddstart, *hrstart, *minstart, *yearstart;
	char *linktostart, *filestart = NULL;
	char *sizestart;
	char *pe;
	struct tm ftm;

	/*
	 * Look for the digit just before the space
	 * before the month name.
	 *
-rw-rw----   1 gleason  sysdev      33404 Mar 24 01:29 RCmd.o
-rw-rw-r--   1 gleason  sysdevzz     1829 Jul  7  1996 README
-rw-rw-r--   1 gleason  sysdevzz     1829 Jul 7   1996 README
-rw-rw-r--   1 gleason  sysdevzz     1829 Jul  7 1996  README
-rw-rw-r--   1 gleason  sysdevzz     1829 Jul 7  1996  README
         *
	 *------------------------------^
	 *                              0123456789012345
	 *------plugend--------^
	 *                     9876543210
	 *
	 */
	for (cp = line; *cp != '\0'; cp++) {
		if (	(isdigit((int) *cp))
			&& (isspace((int) cp[1]))
			&& (isupper((int) cp[2]))
			&& (islower((int) cp[3]))
		/*	&& (islower((int) cp[4])) */
			&& (isspace((int) cp[5]))
			&& (
((isdigit((int) cp[6])) && (isdigit((int) cp[7])))
|| ((isdigit((int) cp[6])) && (isspace((int) cp[7])))
|| ((isspace((int) cp[6])) && (isdigit((int) cp[7])))
			)
			&& (isspace((int) cp[8]))
		) {
			monstart = cp + 2;
			ddstart = cp + 6;
			if (	((isspace((int) cp[9])) || (isdigit((int) cp[9])))
				&& (isdigit((int) cp[10]))
				&& (isdigit((int) cp[11]))
				&& (isdigit((int) cp[12]))
				&& ((isdigit((int) cp[13])) || (isspace((int) cp[13])))
			) {
				/* "Mon DD  YYYY" form */
				yearstart = cp + 9;
				if (isspace((int) *yearstart))
					yearstart++;
				hrstart = NULL;
				minstart = NULL;
				filestart = cp + 15;
				cp[1] = '\0';	/* end size */
				cp[5] = '\0';	/* end mon */
				cp[8] = '\0';	/* end dd */
				cp[14] = '\0';	/* end year */
				mon = LsMonthNameToNum(monstart);
				dd = atoi(ddstart);
				hr = 23;
				min = 59;
				year = atoi(yearstart);

				pe = cp;
				while (isdigit((int) *pe))
					pe--;
				while (isspace((int) *pe))
					pe--;
				*plugend = (int) (pe - line) + 1;
				break;
			} else if (	/*
					 * Windows NT does not 0 pad.
					(isdigit((int) cp[9])) &&
					 */
				(isdigit((int) cp[10]))
				&& (cp[11] == ':')
				&& (isdigit((int) cp[12]))
				&& (isdigit((int) cp[13]))
			) {
				/* "Mon DD HH:MM" form */
				yearstart = NULL;
				hrstart = cp + 9;
				minstart = cp + 12;
				filestart = cp + 15;
				cp[1] = '\0';	/* end size */
				cp[5] = '\0';	/* end mon */
				cp[8] = '\0';	/* end dd */
				cp[11] = '\0';	/* end hr */
				cp[14] = '\0';	/* end min */
				mon = LsMonthNameToNum(monstart);
				dd = atoi(ddstart);
				hr = atoi(hrstart);
				min = atoi(minstart);
				year = 0;

				pe = cp;
				while (isdigit((int) *pe))
					pe--;
				while (isspace((int) *pe))
					pe--;
				*plugend = (int) (pe - line) + 1;
				break;
			}
		}
	}

	if (*cp == '\0')
		return (-1);

	linktostart = strstr(filestart, " -> ");
	if (linktostart != NULL) {
		*linktostart = '\0';
		linktostart += 4;
		(void) Strncpy(linkto, linktostart, linktosize);
	} else {
		*linkto = '\0';
	}

	if (curdirlen == 0) {
		(void) Strncpy(fname, filestart, fnamesize);
	} else {
		(void) Strncpy(fname, curdir, fnamesize);
		(void) Strncat(fname, filestart, fnamesize);
	}

	if (ftime != NULL) {
		(void) memset(&ftm, 0, sizeof(struct tm));
		ftm.tm_mon = mon;
		ftm.tm_mday = dd;
		ftm.tm_hour = hr;
		ftm.tm_min = min;
		ftm.tm_isdst = -1;
		if (year == 0) {
			/* We guess the year, based on what the
			 * current year is.  We know the file
			 * on the remote server is either less
			 * than six months old or less than
			 * one hour into the future.
			 */
			ftm.tm_year = thisyear - 1900;
			*ftime = mktime(&ftm);
			if (*ftime == (time_t) -1) {
				/* panic */
			} else if (*ftime > (now + (15552000L + 86400L))) {
				--ftm.tm_year;
				*ftime = mktime(&ftm);
			} else if (*ftime < (now - (15552000L + 86400L))) {
				++ftm.tm_year;
				*ftime = mktime(&ftm);
			}
		} else {
			ftm.tm_year = year - 1900;
			*ftime = mktime(&ftm);
		}
	}

	if (fsize != NULL) {
		while ((cp > line) && (isdigit((int) *cp)))
			--cp;
		sizestart = cp + 1;
#if defined(HAVE_LONG_LONG) && defined(SCANF_LONG_LONG)
		(void) sscanf(sizestart, SCANF_LONG_LONG, fsize);
#elif defined(HAVE_LONG_LONG) && defined(HAVE_STRTOQ)
		*fsize = (longest_int) strtoq(sizestart, NULL, 0);
#else
		{
			long fsize2 = 0L;

			(void) sscanf(sizestart, "%ld", &fsize2);
			*fsize = (longest_int) fsize2;
		}
#endif
	}

	switch (line[0]) {
		case 'd':
		case 'l':
			*ftype = (int) line[0];
			break;
		case 'b':
		case 'c':
		case 's':
			*ftype = (int) line[0];
			return (-1);
		default:
			*ftype = '-';
	}

	return (0);
}

int
UnLslR(FileInfoListPtr filp, LineListPtr llp, int serverType)
{
	char curdir[256];
	char line[256];
	int hadblankline = 0;
	int len;
	size_t curdirlen = 0;
	char fname[256];
	char linkto[256];
	char *cp;
	longest_int fsize;
	int ftype;
	time_t ftime, now;
	int thisyear;
	struct tm *nowtm;
	int rc;
	LinePtr lp;
	FileInfo fi;
	int linesread = 0;
	int linesconverted = 0;
	size_t maxFileLen = 0;
	size_t maxPlugLen = 0;
	size_t fileLen;
	int plugend;

	(void) time(&now);
	nowtm = localtime(&now);
	if (nowtm == NULL)
		thisyear = 1970;	/* should never happen */
	else
		thisyear = nowtm->tm_year + 1900;

	curdir[0] = '\0';

	InitFileInfoList(filp);
	for (lp = llp->first; lp != NULL; lp = lp->next) {
		len = (int) strlen(STRNCPY(line, lp->line));
		if ((line[0] == 't') && (strncmp(line, "total", 5) == 0)) {
			/* total XX line? */
			if (line[len - 1] != ':') {
				hadblankline = 0;
				continue;
			}
			/* else it was a subdir named total */
		} else {
			for (cp = line; ; cp++) {
				if ((*cp == '\0') || (!isspace((int) *cp)))
					break;
			}
			if (*cp == '\0') {
				/* Entire line was blank. */
				/* separator line between dirs */
				hadblankline = 1;
				continue;
			}
		}

		if ((hadblankline != 0) && (line[len - 1] == ':')) {
			/* newdir */
			hadblankline = 0;
			if ((line[0] == '.') && (line[1] == '/')) {
				line[len - 1] = '/';
				(void) memcpy(curdir, line + 2, (size_t) len + 1 - 2);
				curdirlen = (size_t) (len - 2);
			} else if ((line[0] == '.') && (line[1] == '\\')) {
				line[len - 1] = '\\';
				(void) memcpy(curdir, line + 2, (size_t) len + 1 - 2);
				curdirlen = (size_t) (len - 2);
			} else {
				line[len - 1] = '/';
				(void) memcpy(curdir, line, (size_t) len + 1);
				curdirlen = (size_t) len;
			}
			continue;
		}

		linesread++;
		rc = UnLslRLine(line, curdir, curdirlen, fname, sizeof(fname), linkto, sizeof(linkto), &ftype, &fsize, &ftime, now, thisyear, &plugend);
		if ((rc < 0) && (serverType == kServerTypeMicrosoftFTP)) {
			rc = UnDosLine(line, curdir, curdirlen, fname, sizeof(fname), &ftype, &fsize, &ftime);
			if (rc == 0) {
				*linkto = '\0';
				plugend = 0;
			}
		}
		if (rc == 0) {
			linesconverted++;
			fileLen = strlen(fname);
			if (fileLen > maxFileLen)
				maxFileLen = fileLen;
			fi.relnameLen = fileLen;
			fi.relname = StrDup(fname);
			fi.rname = NULL;
			fi.lname = NULL;
			fi.rlinkto = (linkto[0] == '\0') ? NULL : StrDup(linkto);
			fi.mdtm = ftime;
			fi.size = (longest_int) fsize;
			fi.type = ftype;
			if (plugend > 0) {
				fi.plug = (char *) malloc((size_t) plugend + 1);
				if (fi.plug != NULL) {
					(void) memcpy(fi.plug, line, (size_t) plugend);
					fi.plug[plugend] = '\0';
					if ((size_t) plugend > maxPlugLen)
						maxPlugLen = (size_t) plugend;
				}
			} else {
				fi.plug = (char *) malloc(32);
				if (fi.plug != NULL) {
					strcpy(fi.plug, "----------   1 ftpuser  ftpusers");
					fi.plug[0] = (char) ftype;
					if (30 > maxPlugLen)
						maxPlugLen = (size_t) 30;
				}
			}
			(void) AddFileInfo(filp, &fi);
		}

		hadblankline = 0;
	}

	filp->maxFileLen = maxFileLen;
	filp->maxPlugLen = maxPlugLen;
	if (linesread == 0)
		return (0);
	return ((linesconverted > 0) ? linesconverted : (-1));
}

int
UnMlsT(const char *const line0, const MLstItemPtr mlip)
{
	char *cp, *val, *fact;
	int ec;
	size_t len;
	char line[1024];

	memset(mlip, 0, sizeof(MLstItem));
	mlip->mode = -1;
	mlip->fsize = kSizeUnknown;
	mlip->ftype = '-';
	mlip->ftime = kModTimeUnknown;

	len = strlen(line0);
	if (len > (sizeof(line) - 1))
		return (-1);	/* Line too long, sorry. */
	/* This should be re-coded so does not need to make a
	 * copy of the buffer; it could be done in place.
	 */
	memcpy(line, line0, len + 1);

	/* Skip leading whitespace. */
	for (cp = line; *cp != '\0'; cp++) {
		if (! isspace(*cp))
			break;
	}

	while (*cp != '\0') {
		for (fact = cp; ; cp++) {
			if ((*cp == '\0') || (*cp == ' ')) {
				/* protocol violation */
				return (-1);
			}
			if (*cp == '=') {
				/* End of fact name. */
				*cp++ = '\0';
				break;
			}
		}
		for (val = cp; ; cp++) {
			if (*cp == '\0') {
				/* protocol violation */
				return (-1);
			}
			if (*cp == ' ') {
				ec = ' ';
				*cp++ = '\0';
				break;
			} else if (*cp == ';') {
				if (cp[1] == ' ') {
					ec = ' ';
					*cp++ = '\0';
					*cp++ = '\0';
				} else {
					ec = ';';
					*cp++ = '\0';
				}
				break;
			}
		}
		if (ISTRNEQ(fact, "OS.", 3))
			fact += 3;
		if (ISTREQ(fact, "type")) {
			if (ISTREQ(val, "file")) {
				mlip->ftype = '-';
			} else if (ISTREQ(val, "dir")) {
				mlip->ftype = 'd';
			} else if (ISTREQ(val, "cdir")) {
				/* not supported: current directory */
				return (-2);
			} else if (ISTREQ(val, "pdir")) {
				/* not supported: parent directory */
				return (-2);
			} else {
				/* ? */
				return (-1);
			}
		} else if (ISTREQ(fact, "UNIX.mode")) {
			if (val[0] == '0')
				sscanf(val, "%o", &mlip->mode);
			else
				sscanf(val, "%i", &mlip->mode);
			if (mlip->mode != (-1))
				mlip->mode &= 00777;
		} else if (ISTREQ(fact, "perm")) {
			STRNCPY(mlip->perm, val);
		} else if (ISTREQ(fact, "size")) {
#if defined(HAVE_LONG_LONG) && defined(SCANF_LONG_LONG)
			(void) sscanf(val, SCANF_LONG_LONG, &mlip->fsize);
#elif defined(HAVE_LONG_LONG) && defined(HAVE_STRTOQ)
			mlip->fsize = (longest_int) strtoq(val, NULL, 0);
#else
			{
				long fsize2 = 0L;

				(void) sscanf(val, "%ld", &fsize2);
				mlip->fsize = (longest_int) fsize2;
			}
#endif
		} else if (ISTREQ(fact, "modify")) {
			mlip->ftime = UnMDTMDate(val);
		} else if (ISTREQ(fact, "UNIX.owner")) {
			STRNCPY(mlip->owner, val);
		} else if (ISTREQ(fact, "UNIX.group")) {
			STRNCPY(mlip->group, val);
		} else if (ISTREQ(fact, "UNIX.uid")) {
			mlip->uid = atoi(val);
		} else if (ISTREQ(fact, "UNIX.gid")) {
			mlip->gid = atoi(val);
		} else if (ISTREQ(fact, "perm")) {
			STRNCPY(mlip->perm, val);
		}

		/* End of facts? */
		if (ec == ' ')
			break;
	}

	len = strlen(cp);
	if (len > (sizeof(mlip->fname) - 1)) {
		/* Filename too long */
		return (-1);
	}
	memcpy(mlip->fname, cp, len);

	/* also set linkto here if used */

	return (0);
}

int
UnMlsD(FileInfoListPtr filp, LineListPtr llp)
{
	MLstItem mli;
	char plug[64];
	char og[32];
	int rc;
	LinePtr lp;
	FileInfo fi;
	int linesread = 0;
	int linesconverted = 0;
	int linesignored = 0;
	size_t maxFileLen = 0;
	size_t maxPlugLen = 0;
	size_t fileLen, plugLen;
	int m1, m2, m3;
	const char *cm1, *cm2, *cm3;

	InitFileInfoList(filp);
	for (lp = llp->first; lp != NULL; lp = lp->next) {
		linesread++;
		rc = UnMlsT(lp->line, &mli);
		if (rc == 0) {
			linesconverted++;
			fileLen = strlen(mli.fname);
			if (fileLen > maxFileLen)
				maxFileLen = fileLen;
			fi.relnameLen = fileLen;
			fi.relname = StrDup(mli.fname);
			fi.rname = NULL;
			fi.lname = NULL;
			fi.rlinkto = (mli.linkto[0] == '\0') ? NULL : StrDup(mli.linkto);
			fi.mdtm = mli.ftime;
			fi.size = (longest_int) mli.fsize;
			fi.type = mli.ftype;
			plug[0] = (char) mli.ftype;
			plug[1] = '\0';
			m1 = 0;
			m2 = 0;
			m3 = -1;
			if (mli.mode != (-1)) {
				m1 = (mli.mode & 00700) >> 6;
				m2 = (mli.mode & 00070) >> 3;
				m3 = (mli.mode & 00007);
			}
			if (mli.perm[0] != '\0') {
				m3 = 0;
				if (fi.type == 'd') {
					if (strchr(mli.perm, 'e') != NULL) {
						/* execute -> execute */
						m3 |= 00001;
					}
					if (strchr(mli.perm, 'c') != NULL) {
						/* create -> write */
						m3 |= 00002;
					}
					if (strchr(mli.perm, 'l') != NULL) {
						/* list -> read */
						m3 |= 00004;
					}
				} else {
					if (strchr(mli.perm, 'w') != NULL) {
						/* write -> write */
						m3 |= 00002;
					}
					if (strchr(mli.perm, 'r') != NULL) {
						/* read -> read */
						m3 |= 00004;
					}
				}
			}
			if (m3 != (-1)) {
				cm1 = rwx[m1];
				cm2 = rwx[m2];
				cm3 = rwx[m3];
				sprintf(plug + 1, "%s%s%s", cm1, cm2, cm3);
			}
			if (mli.owner[0] != '\0') {
				if (mli.group[0] != '\0') {
#ifdef HAVE_SNPRINTF
					snprintf(og, sizeof(og) - 1,
#else
					sprintf(og,
#endif	/* HAVE_SNPRINTF */
						"   %-8.8s %s",
						mli.owner, mli.group
					);
					STRNCAT(plug, og);
				} else {
					STRNCAT(plug, "   ");
					STRNCAT(plug, mli.owner);
				}
			}
			fi.plug = StrDup(plug);
			if (fi.plug != NULL) {
				plugLen = strlen(plug);
				if (plugLen > maxPlugLen)
					maxPlugLen = plugLen;
			}
			(void) AddFileInfo(filp, &fi);
		} else if (rc == (-2)) {
			linesignored++;
		}
	}

	filp->maxFileLen = maxFileLen;
	filp->maxPlugLen = maxPlugLen;
	if (linesread == 0)
		return (0);
	linesconverted += linesignored;
	return ((linesconverted > 0) ? linesconverted : (-1));
}

int
FTPRemoteRecursiveFileList1(FTPCIPtr cip, char *const rdir, FileInfoListPtr files)
{
	LineList dirContents;
	FileInfoList fil;
	char cwd[512];
	int result;

	if ((result = FTPGetCWD(cip, cwd, sizeof(cwd))) < 0)
		return (result);

	InitFileInfoList(files);

	if (rdir == NULL)
		return (-1);

	if (FTPChdir(cip, rdir) < 0) {
		/* Probably not a directory.
		 * Just add it as a plain file
		 * to the list.
		 */
		(void) ConcatFileToFileInfoList(files, rdir);
		return (kNoErr);
	}

	/* Paths collected must be relative. */
	if ((result = FTPListToMemory2(cip, "", &dirContents, "-lRa", 1, (int *) 0)) < 0) {
		if ((result = FTPChdir(cip, cwd)) < 0) {
			return (result);
		}
	}

	(void) UnLslR(&fil, &dirContents, cip->serverType);
	DisposeLineListContents(&dirContents);
	/* Could sort it to breadth-first here. */
	/* (void) SortRecursiveFileList(&fil); */
	(void) ComputeRNames(&fil, rdir, 1, 1);
	(void) ConcatFileInfoList(files, &fil);
	DisposeFileInfoListContents(&fil);

	if ((result = FTPChdir(cip, cwd)) < 0) {
		return (result);
	}
	return (kNoErr);
}

int
FTPRemoteRecursiveFileList(FTPCIPtr cip, LineListPtr fileList, FileInfoListPtr files)
{
	LinePtr filePtr, nextFilePtr;
	LineList dirContents;
	FileInfoList fil;
	char cwd[512];
	int result;
	char *rdir;

	if ((result = FTPGetCWD(cip, cwd, sizeof(cwd))) < 0)
		return (result);

	InitFileInfoList(files);

	for (filePtr = fileList->first;
		filePtr != NULL;
		filePtr = nextFilePtr)
	{
		nextFilePtr = filePtr->next;

		rdir = filePtr->line;
		if (rdir == NULL)
			continue;

		if (FTPChdir(cip, rdir) < 0) {
			/* Probably not a directory.
			 * Just add it as a plain file
			 * to the list.
			 */
			(void) ConcatFileToFileInfoList(files, rdir);
			continue;
		}

		/* Paths collected must be relative. */
		if ((result = FTPListToMemory2(cip, "", &dirContents, "-lRa", 1, (int *) 0)) < 0) {
			goto goback;
		}

		(void) UnLslR(&fil, &dirContents, cip->serverType);
		DisposeLineListContents(&dirContents);
		(void) ComputeRNames(&fil, rdir, 1, 1);
		(void) ConcatFileInfoList(files, &fil);
		DisposeFileInfoListContents(&fil);

goback:
		if ((result = FTPChdir(cip, cwd)) < 0) {
			return (result);
		}
	}
	return (kNoErr);
}

__attribute__((used)) static void
Traverse(FTPCIPtr cip, char *fullpath, struct Stat *st, char *relpath, FileInfoListPtr filp)
{
	char *dname;
	struct dirent *dirp;
	mode_t m;
	DIR *dp;
	char *cp;
	char *c2;
	FileInfo fi;

	if (relpath[0] != '\0') {
		fi.relname = StrDup(relpath);
		fi.rname = NULL;
		fi.lname = StrDup(fullpath);
		fi.rlinkto = NULL;
		fi.plug = NULL;
		fi.mdtm = st->st_mtime;
		fi.size = (longest_int) st->st_size;
		fi.type = 'd';
		(void) AddFileInfo(filp, &fi);
	}

	/* Handle directory entry first. */
	cp = fullpath + strlen(fullpath);
	*cp++ = '/';
	*cp = '\0';

	c2 = relpath + strlen(relpath);
	*c2++ = '/';
	*c2 = '\0';

	if ((dp = opendir(fullpath)) == NULL) {
		cp[-1] = '\0';
		c2[-1] = '\0';
		Error(cip, kDoPerror, "could not opendir %s.\n", fullpath);
		return;
	}

	while ((dirp = readdir(dp)) != NULL) {
		dname = dirp->d_name;
		if ((dname[0] == '.') && ((dname[1] == '\0') || ((dname[1] == '.') && (dname[2] == '\0'))))
			continue;	/* skip "." and ".." directories. */

		(void) strcpy(cp, dirp->d_name);	/* append name after slash */
		(void) strcpy(c2, dirp->d_name);
		if (Lstat(fullpath, st) < 0) {
			Error(cip, kDoPerror, "could not stat %s.\n", fullpath);
			continue;
		}

		fi.relname = StrDup(relpath + (((relpath[0] == '/') || (relpath[0] == '\\')) ? 1 : 0));
		fi.rname = NULL;
		fi.lname = StrDup(fullpath);
		fi.mdtm = st->st_mtime;
		fi.size = (longest_int) st->st_size;
		fi.rlinkto = NULL;
		fi.plug = NULL;

		m = st->st_mode;
		if (S_ISREG(m) != 0) {
			/* file */
			fi.type = '-';
			(void) AddFileInfo(filp, &fi);
		} else if (S_ISDIR(m)) {
			Traverse(cip, fullpath, st, relpath, filp);
#ifdef S_ISLNK
		} else if (S_ISLNK(m)) {
			fi.type = 'l';
			fi.rlinkto = calloc(128, 1);
			if (fi.rlinkto != NULL) {
				if (readlink(fullpath, fi.rlinkto, 127) < 0) {
					free(fi.rlinkto);
				} else {
					(void) AddFileInfo(filp, &fi);
				}
			}
#endif	/* S_ISLNK */
		}
	}
	cp[-1] = '\0';
	c2[-1] = '\0';

	(void) closedir(dp);
}

int
FTPLocalRecursiveFileList2(FTPCIPtr cip, LineListPtr fileList, FileInfoListPtr files, int erelative)
{
	LinePtr filePtr, nextFilePtr;
#if defined(WIN32) || defined(_WINDOWS)
	char fullpath[_MAX_PATH + 1];
	char relpath[_MAX_PATH + 1];
#else
	char fullpath[512];
	char relpath[512];
#endif
	struct Stat st;
	FileInfo fi;
	char *cp;

	InitFileInfoList(files);

	for (filePtr = fileList->first;
		filePtr != NULL;
		filePtr = nextFilePtr)
	{
		nextFilePtr = filePtr->next;

		(void) STRNCPY(fullpath, filePtr->line);	/* initialize fullpath */
		if ((erelative != 0) || (strcmp(filePtr->line, ".") == 0) || (filePtr->line[0] == '\0'))
			(void) STRNCPY(relpath, "");
		else if ((cp = StrRFindLocalPathDelim(filePtr->line)) == NULL)
			(void) STRNCPY(relpath, filePtr->line);
		else
			(void) STRNCPY(relpath, cp + 1);
		if (Lstat(fullpath, &st) < 0) {
			Error(cip, kDoPerror, "could not stat %s.\n", fullpath);
			continue;
		}

		if (S_ISDIR(st.st_mode) == 0) {
			fi.relname = StrDup(relpath);
			fi.rname = NULL;
			fi.lname = StrDup(fullpath);
			fi.mdtm = st.st_mtime;
			fi.size = (longest_int) st.st_size;
			fi.rlinkto = NULL;
			fi.plug = NULL;
			fi.type = '-';
			(void) AddFileInfo(files, &fi);
			continue;			/* wasn't a directory */
		}

		/* Paths collected must be relative. */
		Traverse(cip, fullpath, &st, relpath, files);
	}
	return (kNoErr);
}

int
FTPLocalRecursiveFileList(FTPCIPtr cip, LineListPtr fileList, FileInfoListPtr files)
{
	return (FTPLocalRecursiveFileList2(cip, fileList, files, 0));
}

int
FTPRemoteGlob(FTPCIPtr cip, LineListPtr fileList, const char *pattern, int doGlob)
{
	char *cp;
	const char *lsflags;
	LinePtr lp;
	int result;

	if (cip == NULL)
		return (kErrBadParameter);
	if (strcmp(cip->magic, kLibraryMagic))
		return (kErrBadMagic);

	if (fileList == NULL)
		return (kErrBadParameter);
	InitLineList(fileList);

	if ((pattern == NULL) || (pattern[0] == '\0'))
		return (kErrBadParameter);

	/* Note that we do attempt to use glob characters even if the remote
	 * host isn't UNIX.  Most non-UNIX remote FTP servers look for UNIX
	 * style wildcards.
	 */
	if ((doGlob == 1) && (GLOBCHARSINSTR(pattern))) {
		/* Use NLST, which lists files one per line. */
		lsflags = "";

		/* Optimize for "NLST *" case which is same as "NLST". */
		if (strcmp(pattern, "*") == 0) {
			pattern = "";
		} else if (strcmp(pattern, "**") == 0) {
			/* Hack; Lets you try "NLST -a" if you're daring. */
			pattern = "";
			lsflags = "-a";
		}

		if ((result = FTPListToMemory2(cip, pattern, fileList, lsflags, 0, (int *) 0)) < 0) {
			if (*lsflags == '\0')
				return (result);
			/* Try again, without "-a" */
			lsflags = "";
			if ((result = FTPListToMemory2(cip, pattern, fileList, lsflags, 0, (int *) 0)) < 0) {
				return (result);
			}
		}
		if (fileList->first == NULL) {
			cip->errNo = kErrGlobNoMatch;
			return (kErrGlobNoMatch);
		}
		if (fileList->first == fileList->last) {
#define glberr(a) (ISTRNEQ(cp, a, strlen(a)))
			/* If we have only one item in the list, see if it really was
			 * an error message we would recognize.
			 */
			cp = strchr(fileList->first->line, ':');
			if (cp != NULL) {
				if (glberr(": No such file or directory")) {
					(void) RemoveLine(fileList, fileList->first);
					cip->errNo = kErrGlobFailed;
					return (kErrGlobFailed);
				} else if (glberr(": No match")) {
					cip->errNo = kErrGlobNoMatch;
					return (kErrGlobNoMatch);
				}
			}
		}
		RemoteGlobCollapse(pattern, fileList);
		for (lp=fileList->first; lp != NULL; lp = lp->next)
			PrintF(cip, "  Rglob [%s]\n", lp->line);
	} else {
		/* Or, if there were no globbing characters in 'pattern', then the
		 * pattern is really just a filename.  So for this case the
		 * file list is really just a single file.
		 */
		fileList->first = fileList->last = NULL;
		(void) AddLine(fileList, pattern);
	}
	return (kNoErr);
}

__attribute__((used)) static void
ExpandTilde(char *pattern, size_t siz)
{
	string pat;
	char *cp, *rest, *firstent;
#if defined(WIN32) || defined(_WINDOWS)
#else
	struct passwd *pw;
#endif
	string hdir;

	if ((pattern[0] == '~') &&
	(isalnum((int) pattern[1]) || IsLocalPathDelim(pattern[1]) || (pattern[1] == '\0'))) {
		(void) STRNCPY(pat, pattern);
		if ((cp = StrFindLocalPathDelim(pat)) != NULL) {
			*cp = 0;
			rest = cp + 1;	/* Remember stuff after the ~/ part. */
		} else {
			rest = NULL;	/* Was just a ~ or ~username.  */
		}
		if (pat[1] == '\0') {
			/* Was just a ~ or ~/rest type.  */
			GetHomeDir(hdir, sizeof(hdir));
			firstent = hdir;
		} else {
#if defined(WIN32) || defined(_WINDOWS)
			return;
#else
			/* Was just a ~username or ~username/rest type.  */
			pw = getpwnam(pat + 1);
			if (pw != NULL)
				firstent = pw->pw_dir;
			else
				return;		/* Bad user -- leave it alone. */
#endif
		}

		(void) Strncpy(pattern, firstent, siz);
		if (rest != NULL) {
			(void) Strncat(pattern, LOCAL_PATH_DELIM_STR, siz);
			(void) Strncat(pattern, rest, siz);
		}
	}
}

__attribute__((used)) static int
LazyUnixLocalGlob(FTPCIPtr cip, LineListPtr fileList, const char *const pattern)
{
	string cmd;
	longstring gfile;
	FILE *fp;
	FTPSigProc sp;

	/* Do it the easy way and have the shell do the dirty
	 * work for us.
	 */
#ifdef HAVE_SNPRINTF
	(void) snprintf(cmd, sizeof(cmd) - 1, "%s -c \"%s %s %s\"", "/bin/sh", "/bin/ls",
		"-d", pattern);
	cmd[sizeof(cmd) - 1] = '\0';
#else
	(void) sprintf(cmd, "%s -c \"%s %s %s\"", "/bin/sh", "/bin/ls",
		"-d", pattern);
#endif

	fp = (FILE *) popen(cmd, "r");
	if (fp == NULL) {
		Error(cip, kDoPerror, "Could not Lglob: [%s]\n", cmd);
		cip->errNo = kErrGlobFailed;
		return (kErrGlobFailed);
	}
	sp = NcSignal(SIGPIPE, (FTPSigProc) SIG_IGN);
	while (FGets(gfile, sizeof(gfile), (FILE *) fp) != NULL) {
		PrintF(cip, "  Lglob [%s]\n", gfile);
		(void) AddLine(fileList, gfile);
	}
	(void) pclose(fp);
	(void) NcSignal(SIGPIPE, sp);
	return (kNoErr);
}

int
FTPLocalGlob(FTPCIPtr cip, LineListPtr fileList, const char *pattern, int doGlob)
{
	string pattern2;
	int result;

	if (cip == NULL)
		return (kErrBadParameter);
	if (strcmp(cip->magic, kLibraryMagic))
		return (kErrBadMagic);

	if (fileList == NULL)
		return (kErrBadParameter);
	InitLineList(fileList);

	if ((pattern == NULL) || (pattern[0] == '\0'))
		return (kErrBadParameter);

	(void) STRNCPY(pattern2, pattern);	/* Don't nuke the original. */

	/* Pre-process for ~'s. */
	ExpandTilde(pattern2, sizeof(pattern2));
	InitLineList(fileList);
	result = kNoErr;

	if ((doGlob == 1) && (GLOBCHARSINSTR(pattern2))) {
#if defined(WIN32) || defined(_WINDOWS)
		result = WinLocalGlob(cip, fileList, pattern2);
#else
		result = LazyUnixLocalGlob(cip, fileList, pattern2);
#endif
	} else {
		/* Or, if there were no globbing characters in 'pattern', then
		 * the pattern is really just a single pathname.
		 */
		(void) AddLine(fileList, pattern2);
	}

	return (result);
}

__attribute__((used)) static int
FTPFtwL2(const FTPCIPtr cip, char *dir, char *end, size_t dirsize, FTPFtwProc proc, int maxdepth)
{
	LineList fileList;
	LinePtr filePtr;
	char *file, *cp;
	int result;

	if (maxdepth <= 0) {
		result = cip->errNo = kErrRecursionLimitReached;
		return (result);
	}

	result = FTPRemoteGlob(cip, &fileList, "**", kGlobYes);
	if (result != kNoErr) {
		if (result == kErrGlobNoMatch)
			result = kNoErr;	/* empty directory is okay. */
		return (result);
	}

	for (filePtr = fileList.first;
		filePtr != NULL;
		filePtr = filePtr->next)
	{
		file = filePtr->line;
		if (file == NULL) {
			cip->errNo = kErrBadLineList;
			break;
		}

		if ((file[0] == '.') && ((file[1] == '\0') || ((file[1] == '.') && (file[2] == '\0'))))
			continue;	/* Skip . and .. */

		result = FTPIsDir(cip, file);
		if (result < 0) {
			/* error */
			/* could be just a stat error, so continue */
			continue;
		} else if (result == 1) {
			/* directory */
			cp = Strnpcat(dir, file, dirsize);
			result = (*proc)(cip, dir, kFtwDir);
			if (result != kNoErr)
				break;

			if ((strchr(dir, '/') == NULL) && (strrchr(dir, '\\') != NULL))
				*cp++ = '\\';
			else
				*cp++ = '/';
			*cp = '\0';

			result = FTPChdir(cip, file);
			if (result == kNoErr) {
				result = FTPFtwL2(cip, dir, cp, dirsize, proc, maxdepth - 1);
				if (result != kNoErr)
					break;
				if (FTPChdir(cip, "..") < 0) {
					result = kErrCannotGoToPrevDir;
					cip->errNo = kErrCannotGoToPrevDir;
					break;
				}
			}

			*end = '\0';
			if (result != 0)
				break;
		} else {
			/* file */
			cp = Strnpcat(dir, file, dirsize);
			result = (*proc)(cip, dir, kFtwFile);
			*end = '\0';
			if (result != 0)
				break;
		}
	}
	DisposeLineListContents(&fileList);

	return (result);
}

int
FTPFtw(const FTPCIPtr cip, const char *const dir, FTPFtwProc proc, int maxdepth)
{
	int result, result2;
	char *cp;
	char savedcwd[1024];
	char curcwd[2048];

	result = FTPIsDir(cip, dir);
	if (result < 0) {
		/* error */
		return result;
	} else if (result == 0) {
		result = cip->errNo = kErrNotADirectory;
		return (result);
	}

	/* Preserve old working directory. */
	(void) FTPGetCWD(cip, savedcwd, sizeof(savedcwd));

	result = FTPChdir(cip, dir);
	if (result != kNoErr) {
		return (result);
	}

	/* Get full working directory we just changed to. */
	result = FTPGetCWD(cip, curcwd, sizeof(curcwd) - 3);
	if (result != kNoErr) {
		if (FTPChdir(cip, savedcwd) != kNoErr) {
			result = kErrCannotGoToPrevDir;
			cip->errNo = kErrCannotGoToPrevDir;
		}
		return (result);
	}

	result2 = (*proc)(cip, curcwd, kFtwDir);
	if (result2 == kNoErr) {
		cp = curcwd + strlen(curcwd);

		if ((strchr(curcwd, '/') == NULL) && (strrchr(curcwd, '\\') != NULL))
			*cp++ = '\\';
		else
			*cp++ = '/';
		*cp = '\0';
		result = FTPFtwL2(cip, curcwd, cp, sizeof(curcwd), proc, maxdepth - 1);
	}


	if (FTPChdir(cip, savedcwd) != kNoErr) {
		/* Could not cd back to the original user directory -- bad. */
		result = kErrCannotGoToPrevDir;
		cip->errNo = kErrCannotGoToPrevDir;
		return (result);
	}

	if ((result2 != kNoErr) && (result == kNoErr))
		result = result2;

	return (result);
}

