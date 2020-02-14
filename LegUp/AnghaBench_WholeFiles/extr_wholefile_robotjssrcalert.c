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
typedef  int /*<<< orphan*/  pid_t ;
typedef  int /*<<< orphan*/  MSG_PROGS ;

/* Variables and functions */
 int EXEC_FAILED ; 
 int FORK_FAILED ; 
 int IDOK ; 
 int /*<<< orphan*/  MB_OK ; 
 int /*<<< orphan*/  MB_OKCANCEL ; 
 int MessageBox (int /*<<< orphan*/ *,char const*,char const*,int /*<<< orphan*/ ) ; 
 int TASK_SUCCESS ; 
 int WEXITSTATUS (int) ; 
 int /*<<< orphan*/  WIFEXITED (int) ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  execvp (char const*,char* const*) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fork () ; 
 int /*<<< orphan*/  perror (char*) ; 
static  int runTask (char const*,char* const*,int*) ; 
 int /*<<< orphan*/  wait (int*) ; 

int showAlert(const char *title, const char *msg, const char *defaultButton,
              const char *cancelButton)
{
#if defined(IS_MACOSX)
	CFStringRef alertHeader = CFStringCreateWithUTF8String(title);
	CFStringRef alertMessage = CFStringCreateWithUTF8String(msg);
	CFStringRef defaultButtonTitle = CFStringCreateWithUTF8String(defaultButton);
	CFStringRef cancelButtonTitle = CFStringCreateWithUTF8String(cancelButton);
	CFOptionFlags responseFlags;
	SInt32 err = CFUserNotificationDisplayAlert(0.0,
	                                            kCFUserNotificationNoteAlertLevel,
	                                            NULL,
	                                            NULL,
	                                            NULL,
	                                            alertHeader,
	                                            alertMessage,
	                                            defaultButtonTitle,
	                                            cancelButtonTitle,
	                                            NULL,
	                                            &responseFlags);
	if (alertHeader != NULL) CFRelease(alertHeader);
	if (alertMessage != NULL) CFRelease(alertMessage);
	if (defaultButtonTitle != NULL) CFRelease(defaultButtonTitle);
	if (cancelButtonTitle != NULL) CFRelease(cancelButtonTitle);

	if (err != 0) return -1;
	return (responseFlags == kCFUserNotificationDefaultResponse) ? 0 : 1;
#elif defined(USE_X11)
	/* Note that args[0] is set by the xmessage() function. */
	const char *args[10] = {NULL, msg, "-title", title, "-center"};
	int response, ret;
	char *buttonList = NULL; /* To be free()'d. */

	if (defaultButton == NULL) defaultButton = "OK";

	if (cancelButton == NULL) {
		asprintf(&buttonList, "%s:2", defaultButton);
	} else {
		asprintf(&buttonList, "%s:2,%s:3", defaultButton, cancelButton);
	}

	if (buttonList == NULL) return -1; /* asprintf() failed. */
	args[5] = "-buttons";
	args[6] = buttonList;
	args[7] = "-default";
	args[8] = defaultButton;
	args[9] = NULL;

	ret = xmessage((char **)args, &response);
	if (buttonList != NULL) {
		free(buttonList);
		buttonList = NULL;
	}

	if (ret != TASK_SUCCESS) {
		if (ret == EXEC_FAILED) {
			fputs("xmessage or equivalent not found.\n", stderr);
		}
		return -1;
	}

	return (response == 2) ? 0 : 1;
#else
	/* TODO: Display custom buttons instead of the pre-defined "OK"
	 * and "Cancel". */
	int response = MessageBox(NULL, msg, title,
	                          (cancelButton == NULL) ? MB_OK : MB_OKCANCEL);
	return (response == IDOK) ? 0 : 1;
#endif
}

__attribute__((used)) static int xmessage(char *argv[], int *exit_status)
{
	static const char * const MSG_PROGS[] = {"gmessage", "gxmessage",
	                                         "kmessage", "xmessage"};
	static int PREV_MSG_INDEX = -1;
	#define MSG_PROGS_LEN (sizeof(MSG_PROGS) / sizeof(MSG_PROGS[0]))

	char *prog = NULL;
	int ret;

	/* Save some fork()'ing and attempt to use last program if possible. */
	if (PREV_MSG_INDEX >= 0) {
		assert(PREV_MSG_INDEX < MSG_PROGS_LEN);

		prog = argv[0] = (char *)MSG_PROGS[PREV_MSG_INDEX];
		ret = runTask(prog, argv, exit_status);
	} else {
		/* Otherwise, try running each xmessage alternative until one works or
		 * we run out of options. */
		size_t i;
		for (i = 0; i < MSG_PROGS_LEN; ++i) {
			prog = argv[0] = (char *)MSG_PROGS[i];
			ret = runTask(prog, argv, exit_status);
			if (ret != EXEC_FAILED) break;
		}

		if (ret == TASK_SUCCESS) PREV_MSG_INDEX = i;
	}

	return ret;
}

__attribute__((used)) static int runTask(const char *taskname, char * const argv[], int *exit_status)
{
	pid_t pid;
	int status;

	switch (pid = fork()) {
		case -1: /* Failed to fork */
			perror("fork");
			return FORK_FAILED; /* Failed to fork. */
		case 0: /* Child process */
			execvp(taskname, argv);
			exit(42); /* Failed to run task. */
		default: /* Parent process */
			wait(&status); /* Block execution until finished. */

			if (!WIFEXITED(status) || (status = WEXITSTATUS(status)) == 42) {
				return EXEC_FAILED; /* Task failed to run. */
			}
			if (exit_status != NULL) *exit_status = status;
			return TASK_SUCCESS; /* Success! */
	}
}

