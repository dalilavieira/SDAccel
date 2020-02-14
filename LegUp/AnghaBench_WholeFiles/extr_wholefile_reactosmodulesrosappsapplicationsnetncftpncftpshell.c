#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_25__   TYPE_2__ ;
typedef  struct TYPE_24__   TYPE_1__ ;
typedef  struct TYPE_23__   TYPE_10__ ;

/* Type definitions */
typedef  scalar_t__ time_t ;
typedef  int /*<<< orphan*/  qsort_proc_t ;
typedef  int /*<<< orphan*/  prompt ;
typedef  int /*<<< orphan*/  bsearch_proc_t ;
typedef  int /*<<< orphan*/  ai ;
struct TYPE_25__ {char** cargv; int cargc; char* argbuf; int* noglobargv; } ;
struct TYPE_24__ {char const* const name; char* help; char* usage; int flags; int minargs; int maxargs; int /*<<< orphan*/  (* proc ) (int,char**,TYPE_1__*,TYPE_2__* const) ;} ;
struct TYPE_23__ {scalar_t__ connected; scalar_t__ cancelXfer; int /*<<< orphan*/  host; } ;
typedef  TYPE_1__* CommandPtr ;
typedef  int /*<<< orphan*/  Command ;
typedef  TYPE_2__* ArgvInfoPtr ;
typedef  TYPE_2__ ArgvInfo ;

/* Variables and functions */
 int /*<<< orphan*/  AddHistory (char*) ; 
 int /*<<< orphan*/  CloseHost () ; 
 int /*<<< orphan*/  FTPShutdownHost (TYPE_10__*) ; 
 int /*<<< orphan*/  MakePrompt (char*,int) ; 
 int /*<<< orphan*/  NcSignal (int,void (*) (int)) ; 
 char* Readline (char*) ; 
 int SIGALRM ; 
 int SIGINT ; 
 int SIGPIPE ; 
 int /*<<< orphan*/  SetXtermTitle (char*,...) ; 
 int /*<<< orphan*/  Trace (int /*<<< orphan*/ ,char*,...) ; 
 scalar_t__ bsearch (char const* const,TYPE_1__*,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/  gBackToTopJmp ; 
 int gCancelCtrl ; 
 int /*<<< orphan*/  gCancelJmp ; 
 TYPE_1__* gCommands ; 
 TYPE_10__ gConn ; 
 int gDoneApplication ; 
 int /*<<< orphan*/  gEventNumber ; 
 int gGotSig ; 
 int gMayBackToTopJmp ; 
 scalar_t__ gMayCancelJmp ; 
 int gNumCommands ; 
 int gRunningCommand ; 
 scalar_t__ isspace (int) ; 
 TYPE_1__* kAmbiguousCommand ; 
 scalar_t__ kBeepAfterCmdTime ; 
 int kCmdMustBeConnected ; 
 int kCmdMustBeDisconnected ; 
 int /*<<< orphan*/  kGlobChars ; 
 TYPE_1__* kNoCommand ; 
 int kNoMax ; 
 int kNoMin ; 
 int /*<<< orphan*/  longjmp (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  memset (TYPE_2__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  qsort (TYPE_1__*,int,int,int /*<<< orphan*/ ) ; 
 int setjmp (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sleep (int) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/ * strchr (int /*<<< orphan*/ ,int) ; 
 int strcmp (char const* const,char const* const) ; 
 int /*<<< orphan*/  stub1 (int,char**,TYPE_1__*,TYPE_2__* const) ; 
 int /*<<< orphan*/  time (scalar_t__*) ; 

__attribute__((used)) static int
CommandSortCmp(const CommandPtr a, const CommandPtr b)
{
	return (strcmp((*a).name, (*b).name));
}

void
InitCommandList(void)
{
	qsort(gCommands, gNumCommands, sizeof(Command), (qsort_proc_t) CommandSortCmp);
}

__attribute__((used)) static int
CommandExactSearchCmp(const char *const key, const CommandPtr b)
{
	return (strcmp(key, (*b).name));
}

__attribute__((used)) static int
CommandSubSearchCmp(const char *const key, const CommandPtr a)
{
	register const char *kcp, *cp;
	int d;

	for (cp = (*a).name, kcp = key; ; ) {
		if (*kcp == 0)
			break;
		d = *kcp++ - *cp++;
		if (d)
			return d;
	}
	return (0);
}

CommandPtr
GetCommandByIndex(const int i)
{
	if ((i < 0) || (i >= (int) gNumCommands))
		return (kNoCommand);
	return (&gCommands[i]);
}

CommandPtr
GetCommandByName(const char *const name, int wantExactMatch)
{
	CommandPtr canp, canp2;

	/* First check for an exact match.  Otherwise if you if asked for
	 * 'cd', it would match both 'cd' and 'cdup' and return an
	 * ambiguous name error, despite having the exact name for 'cd.'
	 */
	canp = (CommandPtr) bsearch(name, gCommands, gNumCommands, sizeof(Command), (bsearch_proc_t) CommandExactSearchCmp);

	if (canp == kNoCommand && !wantExactMatch) {
		/* Now see if the user typed an abbreviation unique enough
		 * to match only one name in the list.
		 */
		canp = (CommandPtr) bsearch(name, gCommands, gNumCommands, sizeof(Command), (bsearch_proc_t) CommandSubSearchCmp);

		if (canp != kNoCommand) {
			/* Check the entry above us and see if the name we're looking
			 * for would match that, too.
			 */
			if (canp != &gCommands[0]) {
				canp2 = canp - 1;
				if (CommandSubSearchCmp(name, canp2) == 0)
					return kAmbiguousCommand;
			}
			/* Check the entry below us and see if the name we're looking
			 * for would match that one.
			 */
			if (canp != &gCommands[gNumCommands - 1]) {
				canp2 = canp + 1;
				if (CommandSubSearchCmp(name, canp2) == 0)
					return kAmbiguousCommand;
			}
		}
	}
	return canp;
}

void
PrintCmdHelp(CommandPtr c)
{
	(void) printf("%s: %s.\n", c->name, c->help);
}

void
PrintCmdUsage(CommandPtr c)
{
	if (c->usage != NULL)
		(void) printf("Usage: %s %s\n", c->name, c->usage);
}

int
MakeArgv(char *line, int *cargc, const char **cargv, int cargcmax, char *dbuf, size_t dbufsize, int *noglobargv, int readlineHacks)
{
	int c;
	int retval;
	char *dlim;
	char *dcp;
	char *scp;
	char *arg;

	*cargc = 0;
	scp = line;
	dlim = dbuf + dbufsize - 1;
	dcp = dbuf;

	for (*cargc = 0; *cargc < cargcmax; ) {
		/* Eat preceding junk. */
		for ( ; ; scp++) {
			c = *scp;
			if (c == '\0')
				goto done;
			if (isspace(c))
				continue;
			if ((c == ';') || (c == '\n')) {
				scp++;
				goto done;
			}
			break;
		}

		arg = dcp;
		cargv[*cargc] = arg;
		noglobargv[*cargc] = 0;
		(*cargc)++;

		/* Special hack so that "!cmd" is always split into "!" "cmd" */
		if ((*cargc == 1) && (*scp == '!')) {
			if (scp[1] == '!') {
				scp[1] = '\0';
			} else if ((scp[1] != '\0') && (!isspace((int) scp[1]))) {
				cargv[0] = "!";
				scp++;
				arg = dcp;
				cargv[*cargc] = arg;
				noglobargv[*cargc] = 0;
				(*cargc)++;
			}
		}

		/* Add characters to the new argument. */
		for ( ; ; ) {
			c = *scp;
			if (c == '\0')
				break;
			if (isspace(c))
				break;
			if ((c == ';') || (c == '\n')) {
				break;
			}

			scp++;

			if (c == '\'') {
				for ( ; ; ) {
					c = *scp++;
					if (c == '\0') {
						if (readlineHacks != 0)
							break;
						/* Syntax error */
						(void) fprintf(stderr, "Error: Unbalanced quotes.\n");
						return (-1);
					}
					if (c == '\'')
						break;

					/* Add char. */
					if (dcp >= dlim)
						goto toolong;
					*dcp++ = c;

					if (strchr(kGlobChars, c) != NULL) {
						/* User quoted glob characters,
						 * so mark this argument for
						 * noglob.
						 */
						noglobargv[*cargc - 1] = 1;
					}
				}
			} else if (c == '"') {
				for ( ; ; ) {
					c = *scp++;
					if (c == '\0') {
						if (readlineHacks != 0)
							break;
						/* Syntax error */
						(void) fprintf(stderr, "Error: Unbalanced quotes.\n");
						return (-1);
					}
					if (c == '"')
						break;

					/* Add char. */
					if (dcp >= dlim)
						goto toolong;
					*dcp++ = c;

					if (strchr(kGlobChars, c) != NULL) {
						/* User quoted glob characters,
						 * so mark this argument for
						 * noglob.
						 */
						noglobargv[*cargc - 1] = 1;
					}
				}
			} else
#if defined(WIN32) || defined(_WINDOWS)
				if (c == '|') {
#else
				if (c == '\\') {
#endif
				/* Add next character, verbatim. */
				c = *scp++;
				if (c == '\0')
					break;

				/* Add char. */
				if (dcp >= dlim)
					goto toolong;
				*dcp++ = c;
			} else {
				/* Add char. */
				if (dcp >= dlim)
					goto toolong;
				*dcp++ = c;
			}
		}

		*dcp++ = '\0';
	}

	(void) fprintf(stderr, "Error: Argument list too long.\n");
	*cargc = 0;
	cargv[*cargc] = NULL;
	return (-1);

done:
	retval = (int) (scp - line);
	cargv[*cargc] = NULL;
	return (retval);

toolong:
	(void) fprintf(stderr, "Error: Line too long.\n");
	*cargc = 0;
	cargv[*cargc] = NULL;
	return (-1);
}

__attribute__((used)) static int
DoCommand(const ArgvInfoPtr aip)
{
	CommandPtr cmdp;
	int flags;
	int cargc, cargcm1;

	cmdp = GetCommandByName(aip->cargv[0], 0);
	if (cmdp == kAmbiguousCommand) {
		(void) printf("%s: ambiguous command name.\n", aip->cargv[0]);
		return (-1);
	} else if (cmdp == kNoCommand) {
		(void) printf("%s: no such command.\n", aip->cargv[0]);
		return (-1);
	}

	cargc = aip->cargc;
	cargcm1 = cargc - 1;
	flags = cmdp->flags;

	if (((flags & kCmdMustBeConnected) != 0) && (gConn.connected == 0)) {
		(void) printf("%s: must be connected to do that.\n", aip->cargv[0]);
	} else if (((flags & kCmdMustBeDisconnected) != 0) && (gConn.connected != 0)) {
		(void) printf("%s: must be disconnected to do that.\n", aip->cargv[0]);
	} else if ((cmdp->minargs != kNoMin) && (cmdp->minargs > cargcm1)) {
		PrintCmdUsage(cmdp);
	} else if ((cmdp->maxargs != kNoMax) && (cmdp->maxargs < cargcm1)) {
		PrintCmdUsage(cmdp);
	} else {
		(*cmdp->proc)(cargc, aip->cargv, cmdp, aip);
	}
	return (0);
}

void
XferCanceller(int sigNum)
{
	gGotSig = sigNum;
	if (gConn.cancelXfer > 0) {
#if defined(WIN32) || defined(_WINDOWS)
		signal(SIGINT, SIG_DFL);
#else
		/* User already tried it once, they
		 * must think it's locked up.
		 *
		 * Jump back to the top, and
		 * close down the current session.
		 */
		gCancelCtrl = 1;
		if (gMayBackToTopJmp > 0) {
#ifdef HAVE_SIGSETJMP
			siglongjmp(gBackToTopJmp, 1);
#else	/* HAVE_SIGSETJMP */
			longjmp(gBackToTopJmp, 1);
#endif	/* HAVE_SIGSETJMP */
		}
#endif
	}
	gConn.cancelXfer++;
}

void
BackToTop(int sigNum)
{
	gGotSig = sigNum;
	if (sigNum == SIGPIPE) {
		if (gRunningCommand == 1) {
			(void) fprintf(stderr, "Unexpected broken pipe.\n");
			gRunningCommand = 0;
		} else {
			SetXtermTitle("RESTORE");
			exit(1);
		}
	} else if (sigNum == SIGINT) {
		if (gRunningCommand == 0)
			gDoneApplication = 1;
	}
	if (gMayBackToTopJmp > 0) {
#ifdef HAVE_SIGSETJMP
		siglongjmp(gBackToTopJmp, 1);
#else	/* HAVE_SIGSETJMP */
		longjmp(gBackToTopJmp, 1);
#endif	/* HAVE_SIGSETJMP */
	}
}

void
Cancel(int sigNum)
{
	if (gMayCancelJmp != 0) {
		gGotSig = sigNum;
		gMayCancelJmp = 0;
#ifdef HAVE_SIGSETJMP
		siglongjmp(gCancelJmp, 1);
#else	/* HAVE_SIGSETJMP */
		longjmp(gCancelJmp, 1);
#endif	/* HAVE_SIGSETJMP */
	}
}

void
CommandShell(void)
{
	int tUsed, bUsed;
	ArgvInfo ai;
	char prompt[64];
	char *lineRead;
#if defined(WIN32) || defined(_WINDOWS)
#else
	int sj;
#endif
	time_t cmdStart, cmdStop;

	/* Execution may jump back to this point to restart the shell. */
#if defined(WIN32) || defined(_WINDOWS)

#elif defined(HAVE_SIGSETJMP)
	sj = sigsetjmp(gBackToTopJmp, 1);
#else	/* HAVE_SIGSETJMP */
	sj = setjmp(gBackToTopJmp);
#endif	/* HAVE_SIGSETJMP */

#if defined(WIN32) || defined(_WINDOWS)
#else
	if (sj != 0) {
		Trace(0, "Caught signal %d, back at top.\n", gGotSig);
		if (gGotSig == SIGALRM) {
			(void) printf("\nRemote host was not responding, closing down the session.");
			FTPShutdownHost(&gConn);
		} else{
			(void) printf("\nInterrupted.\n");
			if (gCancelCtrl != 0) {
				gCancelCtrl = 0;
				(void) printf("Closing down the current FTP session: ");
				FTPShutdownHost(&gConn);
				(void) sleep(1);
				(void) printf("done.\n");
			}
		}
	}

	gMayBackToTopJmp = 1;
#endif


	++gEventNumber;

	while (gDoneApplication == 0) {
#if defined(WIN32) || defined(_WINDOWS)
#else
		(void) NcSignal(SIGINT, BackToTop);
		(void) NcSignal(SIGPIPE, BackToTop);
		(void) NcSignal(SIGALRM, BackToTop);
#endif

		MakePrompt(prompt, sizeof(prompt));

		if (gConn.connected == 0) {
			SetXtermTitle("DEFAULT");
		} else {
			SetXtermTitle("%s - NcFTP", gConn.host);
		}

		lineRead = Readline(prompt);
		if (lineRead == NULL) {
			/* EOF, Control-D */
			(void) printf("\n");
			break;
		}
		Trace(0, "> %s\n", lineRead);
		AddHistory(lineRead);
		for (tUsed = 0;;) {
			(void) memset(&ai, 0, sizeof(ai));
			bUsed = MakeArgv(lineRead + tUsed, &ai.cargc, ai.cargv,
				(int) (sizeof(ai.cargv) / sizeof(char *)),
				ai.argbuf, sizeof(ai.argbuf),
				ai.noglobargv, 0);
			if (bUsed <= 0)
				break;
			tUsed += bUsed;
			if (ai.cargc == 0)
				continue;
			gRunningCommand = 1;
			(void) time(&cmdStart);
			if (DoCommand(&ai) < 0) {
				(void) time(&cmdStop);
				gRunningCommand = 0;
				break;
			}
			(void) time(&cmdStop);
			gRunningCommand = 0;
			if ((cmdStop - cmdStart) > kBeepAfterCmdTime) {
				/* Let the user know that a time-consuming
				 * operation has completed.
				 */
#if defined(WIN32) || defined(_WINDOWS)
				MessageBeep(MB_OK);
#else
				(void) fprintf(stderr, "\007");
#endif
			}
			++gEventNumber;
		}

		free(lineRead);
	}

	CloseHost();
	gMayBackToTopJmp = 0;
}

