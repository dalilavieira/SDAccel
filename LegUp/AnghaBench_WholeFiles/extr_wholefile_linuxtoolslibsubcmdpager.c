#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct winsize {int ws_col; } ;
typedef  int /*<<< orphan*/  fd_set ;
struct TYPE_6__ {char const** argv; int in; void (* preexec_cb ) () ;} ;
struct TYPE_5__ {char const* pager_env; } ;

/* Variables and functions */
 int /*<<< orphan*/  FD_SET (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FD_ZERO (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TIOCGWINSZ ; 
 int /*<<< orphan*/  X_OK ; 
 scalar_t__ access (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  atexit (void (*) ()) ; 
 int atoi (char*) ; 
 int /*<<< orphan*/  close (int) ; 
 int /*<<< orphan*/  dup2 (int,int) ; 
 int /*<<< orphan*/  fflush (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  finish_command (TYPE_2__*) ; 
 void* getenv (char*) ; 
 scalar_t__ ioctl (int,int /*<<< orphan*/ ,struct winsize*) ; 
 scalar_t__ isatty (int) ; 
 char const** pager_argv ; 
 int pager_columns ; 
 TYPE_2__ pager_process ; 
 int /*<<< orphan*/  raise (int) ; 
 int /*<<< orphan*/  select (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  setenv (char*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sigchain_pop (int) ; 
 int /*<<< orphan*/  sigchain_push_common (void (*) (int)) ; 
 int spawned_pager ; 
 scalar_t__ start_command (TYPE_2__*) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  stdout ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 
 TYPE_1__ subcmd_config ; 

void pager_init(const char *pager_env)
{
	subcmd_config.pager_env = pager_env;
}

__attribute__((used)) static void pager_preexec(void)
{
	/*
	 * Work around bug in "less" by not starting it until we
	 * have real input
	 */
	fd_set in;
	fd_set exception;

	FD_ZERO(&in);
	FD_ZERO(&exception);
	FD_SET(0, &in);
	FD_SET(0, &exception);
	select(1, &in, NULL, &exception, NULL);

	setenv("LESS", "FRSX", 0);
}

__attribute__((used)) static void wait_for_pager(void)
{
	fflush(stdout);
	fflush(stderr);
	/* signal EOF to pager */
	close(1);
	close(2);
	finish_command(&pager_process);
}

__attribute__((used)) static void wait_for_pager_signal(int signo)
{
	wait_for_pager();
	sigchain_pop(signo);
	raise(signo);
}

void setup_pager(void)
{
	const char *pager = getenv(subcmd_config.pager_env);
	struct winsize sz;

	if (!isatty(1))
		return;
	if (ioctl(1, TIOCGWINSZ, &sz) == 0)
		pager_columns = sz.ws_col;
	if (!pager)
		pager = getenv("PAGER");
	if (!(pager || access("/usr/bin/pager", X_OK)))
		pager = "/usr/bin/pager";
	if (!(pager || access("/usr/bin/less", X_OK)))
		pager = "/usr/bin/less";
	if (!pager)
		pager = "cat";
	if (!*pager || !strcmp(pager, "cat"))
		return;

	spawned_pager = 1; /* means we are emitting to terminal */

	/* spawn the pager */
	pager_argv[2] = pager;
	pager_process.argv = pager_argv;
	pager_process.in = -1;
	pager_process.preexec_cb = pager_preexec;

	if (start_command(&pager_process))
		return;

	/* original process continues, but writes to the pipe */
	dup2(pager_process.in, 1);
	if (isatty(2))
		dup2(pager_process.in, 2);
	close(pager_process.in);

	/* this makes sure that the parent terminates after the pager */
	sigchain_push_common(wait_for_pager_signal);
	atexit(wait_for_pager);
}

int pager_in_use(void)
{
	return spawned_pager;
}

int pager_get_columns(void)
{
	char *s;

	s = getenv("COLUMNS");
	if (s)
		return atoi(s);

	return (pager_columns ? pager_columns : 80) - 2;
}

