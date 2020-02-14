#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  posix_spawnattr_t ;
struct TYPE_8__ {size_t used; TYPE_1__* action; } ;
typedef  TYPE_2__ posix_spawn_file_actions_t ;
typedef  int pid_t ;
struct TYPE_7__ {int filedes; int newfiledes; } ;

/* Variables and functions */
 int EINVAL ; 
 size_t MAX_FILE_ACTIONS ; 
 int /*<<< orphan*/  _exit (int) ; 
 int dup2 (int,int) ; 
 int errno ; 
 int /*<<< orphan*/  execvpe (char const*,char* const*,char* const*) ; 
 int fork () ; 

int posix_spawn_file_actions_adddup2(posix_spawn_file_actions_t *fa, int fd, int newfd)
{
    if (fa->used >= MAX_FILE_ACTIONS)
        return -1;
    fa->action[fa->used].filedes = fd;
    fa->action[fa->used].newfiledes = newfd;
    fa->used++;
    return 0;
}

int posix_spawn_file_actions_init(posix_spawn_file_actions_t *fa)
{
    fa->used = 0;
    return 0;
}

int posix_spawn_file_actions_destroy(posix_spawn_file_actions_t *fa)
{
    return 0;
}

int posix_spawnp(pid_t *pid, const char *file,
    const posix_spawn_file_actions_t *fa,
    const posix_spawnattr_t *attrp,
    char *const argv[], char *const envp[])
{
    pid_t p;

    if (attrp != NULL)
        return EINVAL;

    p = fork();
    if (p == -1)
        return errno;

    if (p == 0) {
        for (int i = 0; i < fa->used; i++) {
            int err = dup2(fa->action[i].filedes, fa->action[i].newfiledes);
            if (err == -1)
                goto fail;
        }
        execvpe(file, argv, envp);
fail:
        _exit(127);
    }

    *pid = p;
    return 0;
}

