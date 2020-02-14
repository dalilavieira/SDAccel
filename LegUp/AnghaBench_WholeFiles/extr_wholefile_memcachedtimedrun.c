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
struct sigaction {void (* sa_handler ) (int) ;scalar_t__ sa_flags; } ;
typedef  scalar_t__ pid_t ;

/* Variables and functions */
 int EX_OSERR ; 
 int EX_SOFTWARE ; 
 int SIGALRM ; 
 int SIGHUP ; 
 int SIGINT ; 
 int SIGKILL ; 
 int SIGPIPE ; 
 int SIGTERM ; 
 int WEXITSTATUS (int) ; 
 scalar_t__ WIFEXITED (int) ; 
 int WTERMSIG (int) ; 
 int /*<<< orphan*/  alarm (int) ; 
 int /*<<< orphan*/  assert (int) ; 
 int atoi (char*) ; 
 int caught_sig ; 
 int /*<<< orphan*/  execvp (char*,char**) ; 
 scalar_t__ fork () ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*) ; 
 scalar_t__ kill (scalar_t__,int) ; 
 int /*<<< orphan*/  perror (char*) ; 
 int /*<<< orphan*/  sigaction (int,struct sigaction*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stderr ; 
 scalar_t__ waitpid (scalar_t__,int*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void signal_handler(int which)
{
    caught_sig = which;
}

__attribute__((used)) static int wait_for_process(pid_t pid)
{
    int rv = EX_SOFTWARE;
    int status = 0;
    int i = 0;
    struct sigaction sig_handler;

    sig_handler.sa_handler = signal_handler;
    sig_handler.sa_flags = 0;

    sigaction(SIGALRM, &sig_handler, NULL);
    sigaction(SIGHUP, &sig_handler, NULL);
    sigaction(SIGINT, &sig_handler, NULL);
    sigaction(SIGTERM, &sig_handler, NULL);
    sigaction(SIGPIPE, &sig_handler, NULL);

    /* Loop forever waiting for the process to quit */
    for (i = 0; ;i++) {
        pid_t p = waitpid(pid, &status, 0);
        if (p == pid) {
            /* child exited.  Let's get out of here */
            rv = WIFEXITED(status) ?
                WEXITSTATUS(status) :
                (0x80 | WTERMSIG(status));
            break;
        } else {
            int sig = 0;
            switch (i) {
            case 0:
                /* On the first iteration, pass the signal through */
                sig = caught_sig > 0 ? caught_sig : SIGTERM;
                if (caught_sig == SIGALRM) {
                   fprintf(stderr, "Timeout.. killing the process\n");
                }
                break;
            case 1:
                sig = SIGTERM;
                break;
            default:
                sig = SIGKILL;
                break;
            }
            if (kill(pid, sig) < 0) {
                /* Kill failed.  Must have lost the process. :/ */
                perror("lost child when trying to kill");
            }
            /* Wait up to 5 seconds for the pid */
            alarm(5);
        }
    }
    return rv;
}

__attribute__((used)) static int spawn_and_wait(char **argv)
{
    int rv = EX_SOFTWARE;
    pid_t pid = fork();

    switch (pid) {
    case -1:
        perror("fork");
        rv = EX_OSERR;
        break; /* NOTREACHED */
    case 0:
        execvp(argv[0], argv);
        perror("exec");
        rv = EX_SOFTWARE;
        break; /* NOTREACHED */
    default:
        rv = wait_for_process(pid);
    }
    return rv;
}

int main(int argc, char **argv)
{
    int naptime = 0;
    assert(argc > 2);

    naptime = atoi(argv[1]);
    assert(naptime > 0 && naptime < 1800);

    alarm(naptime);

    return spawn_and_wait(argv+2);
}

