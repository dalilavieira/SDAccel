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
typedef  int /*<<< orphan*/  pthread_t ;
typedef  int /*<<< orphan*/  pid_t ;

/* Variables and functions */
 scalar_t__ EINTR ; 
 int WEXITSTATUS (int) ; 
 scalar_t__ WIFEXITED (int) ; 
 scalar_t__ WIFSIGNALED (int) ; 
 scalar_t__ WIFSTOPPED (int) ; 
 int WSTOPSIG (int) ; 
 int WTERMSIG (int) ; 
 int atoi (char*) ; 
 scalar_t__ calloc (int,int) ; 
 int /*<<< orphan*/  environ ; 
 int /*<<< orphan*/  err (int,char*,...) ; 
 int /*<<< orphan*/  errc (int,int,char*,char*) ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  errx (int,char*,int) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char*) ; 
 char* getprogname () ; 
 char** newargv ; 
 int posix_spawn (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,char**,int /*<<< orphan*/ ) ; 
 int pthread_create (int /*<<< orphan*/ *,int /*<<< orphan*/ *,void* (*) (void*),void*) ; 
 int pthread_join (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stderr ; 
 void usage () ; 
 int waitpid (int /*<<< orphan*/ ,int*,int /*<<< orphan*/ ) ; 
 void* work (void*) ; 

int main(int argc, char *argv[]) {

    int i, count, threadcount;
    int ret;
    pthread_t *threads;

    if (argc < 4) {
        usage();
    }

    threadcount = atoi(argv[1]);
    count = atoi(argv[2]);
    
    newargv = &argv[3];

    threads = (pthread_t *)calloc(threadcount, sizeof(pthread_t));
    for (i=0; i < threadcount; i++) {
        ret = pthread_create(&threads[i], NULL, work, (void *)(intptr_t)count);
        if (ret) {
            err(1, "pthread_create");
        }
    }
    
    for (i=0; i < threadcount; i++) {
        ret = pthread_join(threads[i], NULL);
        if (ret) {
            err(1, "pthread_join");
        }
    }
    
    return 0;
}

void usage(void) {
    fprintf(stderr, "Usage: %s <threadcount> <count> <program> [<arg1> [<arg2> ...]]\n",
            getprogname());
    exit(1);
}

void *work(void *arg)
{
    int count = (int)(intptr_t)arg;
    int i;
    int ret;
    pid_t pid;

    for (i=0; i < count; i++) {
        ret = posix_spawn(&pid, newargv[0], NULL, NULL, newargv, environ);
        if (ret != 0) {
            errc(1, ret, "posix_spawn(%s)", newargv[0]);
        }
        
        while (-1 == waitpid(pid, &ret, 0)) {
            if (errno != EINTR) {
                err(1, "waitpid(%d)", pid);
            }
        }
        
        if (WIFSIGNALED(ret)) {
            errx(1, "process exited with signal %d", WTERMSIG(ret));
        } else if (WIFSTOPPED(ret)) {
            errx(1, "process stopped with signal %d", WSTOPSIG(ret));
        } else if (WIFEXITED(ret)) {
            if (WEXITSTATUS(ret) != 42) {
                errx(1, "process exited with unexpected exit code %d", WEXITSTATUS(ret));
            }
        } else {
            errx(1, "unknown exit condition %x", ret);
        }
    }

    return NULL;
}

