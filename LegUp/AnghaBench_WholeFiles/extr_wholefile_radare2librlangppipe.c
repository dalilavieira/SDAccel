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
typedef  int /*<<< orphan*/  RLang ;

/* Variables and functions */
 int /*<<< orphan*/  free (char*) ; 
static  int lang_pipe_run (int /*<<< orphan*/ *,char const*,int) ; 
 char* r_str_newf (char*,int) ; 
 int /*<<< orphan*/  r_sys_setenv (char const*,char*) ; 

__attribute__((used)) static int lang_pipe_file(RLang *lang, const char *file) {
	return lang_pipe_run (lang, file, -1);
}

__attribute__((used)) static void env(const char *s, int f) {
	char *a = r_str_newf ("%d", f);
	r_sys_setenv (s, a);
//	eprintf ("%s %s\n", s, a);
	free (a);
}

__attribute__((used)) static int lang_pipe_run(RLang *lang, const char *code, int len) {
#if __UNIX__
	int safe_in = dup (0);
	int child, ret;
	int input[2];
	int output[2];

	if (pipe (input) != 0) {
		eprintf ("r_lang_pipe: pipe failed on input\n");
		if (safe_in != -1) {
			close (safe_in);
		}
		return false;
	}
	if (pipe (output) != 0) {
		eprintf ("r_lang_pipe: pipe failed on output\n");
		if (safe_in != -1) {
			close (safe_in);
		}
		return false;
	}
	
	env ("R2PIPE_IN", input[0]);
	env ("R2PIPE_OUT", output[1]);

	child = r_sys_fork ();
	if (child == -1) {
		/* error */
		perror ("pipe run");
	} else if (!child) {
		/* children */
		r_sandbox_system (code, 1);
		write (input[1], "", 1);
		close (input[0]);
		close (input[1]);
		close (output[0]);
		close (output[1]);
		exit (0);
		return false;
	} else {
		/* parent */
		char *res, buf[1024];
		/* Close pipe ends not required in the parent */
		close (output[1]);
		close (input[0]);
		r_cons_break_push (NULL, NULL);
		for (;;) {
			if (r_cons_is_breaked ()) {
				break;
			}
			memset (buf, 0, sizeof (buf));
			void *bed = r_cons_sleep_begin ();
			ret = read (output[0], buf, sizeof (buf) - 1);
			r_cons_sleep_end (bed);
			if (ret < 1 || !buf[0]) {
				break;
			}
			buf[sizeof (buf) - 1] = 0;
			res = lang->cmd_str ((RCore*)lang->user, buf);
			//eprintf ("%d %s\n", ret, buf);
			if (res) {
				write (input[1], res, strlen (res) + 1);
				free (res);
			} else {
				eprintf ("r_lang_pipe: NULL reply for (%s)\n", buf);
				write (input[1], "", 1); // NULL byte
			}
		}
		r_cons_break_pop ();
		/* workaround to avoid stdin closed */
		if (safe_in != -1) {
			close (safe_in);
		}
		safe_in = open (ttyname(0), O_RDONLY);
		if (safe_in != -1) {
			dup2 (safe_in, 0);
		} else {
			eprintf ("Cannot open ttyname(0) %s\n", ttyname(0));
		}
	}

	close (input[0]);
	close (input[1]);
	close (output[0]);
	close (output[1]);
	if (safe_in != -1) {
		close (safe_in);
	}
	waitpid (child, NULL, WNOHANG);
	return true;
#else
#if __WINDOWS__
	char *r2pipe_var = r_str_newf ("R2PIPE_IN%x", _getpid ());
	char *r2pipe_paz = r_str_newf ("\\\\.\\pipe\\%s", r2pipe_var);
	LPTSTR r2pipe_var_ = r_sys_conv_utf8_to_win (r2pipe_var);
	LPTSTR r2pipe_paz_ = r_sys_conv_utf8_to_win (r2pipe_paz);

	SetEnvironmentVariable (TEXT ("R2PIPE_PATH"), r2pipe_var_);
	hPipeInOut = CreateNamedPipe (r2pipe_paz_,
			PIPE_ACCESS_DUPLEX,
			PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT, PIPE_UNLIMITED_INSTANCES,
			PIPE_BUF_SIZE,
			PIPE_BUF_SIZE,
			0, NULL);
	hproc = myCreateChildProcess (code);
	if (hproc) {
		/* a separate thread is created that sets bStopPipeLoop once hproc terminates. */
		bStopPipeLoop = FALSE;
		CloseHandle (CreateThread (NULL, 0, WaitForProcThread, NULL, 0, NULL));
		/* lang_pipe_run_win has to run in the command thread to prevent deadlock. */
		lang_pipe_run_win (lang);
		DeleteFile (r2pipe_paz_);
		CloseHandle (hPipeInOut);
	}
	free (r2pipe_var);
	free (r2pipe_paz);
	free (r2pipe_var_);
	free (r2pipe_paz_);
	return hproc != NULL;
#endif
#endif
}

