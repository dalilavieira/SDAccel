#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  cmd ;
struct TYPE_12__ {int /*<<< orphan*/  type; int /*<<< orphan*/  repo_id; int /*<<< orphan*/  worktree; } ;
typedef  TYPE_2__ WatchCommand ;
struct TYPE_13__ {int /*<<< orphan*/ * res_pipe; int /*<<< orphan*/ * cmd_pipe; int /*<<< orphan*/  job_func; TYPE_1__* seaf; } ;
struct TYPE_11__ {int /*<<< orphan*/  job_mgr; } ;
typedef  TYPE_3__ SeafWTMonitor ;

/* Variables and functions */
 int /*<<< orphan*/  CMD_ADD_WATCH ; 
 int /*<<< orphan*/  CMD_DELETE_WATCH ; 
 int /*<<< orphan*/  CMD_REFRESH_WATCH ; 
 int /*<<< orphan*/  SEAF_PATH_MAX ; 
 int /*<<< orphan*/  errno ; 
 int /*<<< orphan*/  g_strlcpy (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,char const*,int) ; 
 int /*<<< orphan*/  memset (TYPE_2__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  seaf_debug (char*,char const*) ; 
 scalar_t__ seaf_job_manager_schedule_job (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,TYPE_3__*) ; 
 scalar_t__ seaf_pipe (int /*<<< orphan*/ *) ; 
 int seaf_pipe_readn (int /*<<< orphan*/ ,int*,int) ; 
 int seaf_pipe_writen (int /*<<< orphan*/ ,TYPE_2__*,int) ; 
 int /*<<< orphan*/  seaf_warning (char*,...) ; 
 int /*<<< orphan*/  strerror (int /*<<< orphan*/ ) ; 

int
seaf_wt_monitor_start (SeafWTMonitor *monitor)
{
    if (seaf_pipe (monitor->cmd_pipe) < 0) {
        seaf_warning ("[wt mon] failed to create command pipe: %s.\n",
                      strerror(errno));
        return -1;
    }

    if (seaf_pipe (monitor->res_pipe) < 0) {
        seaf_warning ("[wt mon] failed to create result pipe: %s.\n",
                      strerror(errno));
        return -1;
    }

    if (seaf_job_manager_schedule_job (monitor->seaf->job_mgr,
                                       monitor->job_func,
                                       NULL, monitor) < 0) {
        seaf_warning ("[wt mon] failed to start monitor thread.\n");
        return -1;
    }

    return 0;
}

int
seaf_wt_monitor_watch_repo (SeafWTMonitor *monitor,
                            const char *repo_id,
                            const char *worktree)
{
    WatchCommand cmd;
    int res;

    memset (&cmd, 0, sizeof(cmd));
    memcpy (cmd.repo_id, repo_id, 37);
    cmd.type = CMD_ADD_WATCH;
    g_strlcpy (cmd.worktree, worktree, SEAF_PATH_MAX);

    int n = seaf_pipe_writen (monitor->cmd_pipe[1], &cmd, sizeof(cmd));
    
    if (n != sizeof(cmd)) {
        seaf_warning ("[wt mon] fail to write command pipe.\n");
        return -1;
    }

    seaf_debug ("send a watch command, repo %s\n", repo_id);

    n = seaf_pipe_readn (monitor->res_pipe[0], &res, sizeof(int));
    if (n != sizeof(int)) {
        seaf_warning ("[wt mon] fail to read result pipe.\n");
        return -1;
    }

    return res;
}

int
seaf_wt_monitor_unwatch_repo (SeafWTMonitor *monitor, const char *repo_id)
{
    WatchCommand cmd;
    int res;

    memset (&cmd, 0, sizeof(cmd));
    memcpy (cmd.repo_id, repo_id, 37);
    cmd.type = CMD_DELETE_WATCH;

    int n = seaf_pipe_writen (monitor->cmd_pipe[1], &cmd, sizeof(cmd));

    if (n != sizeof(cmd)) {
        seaf_warning ("[wt mon] fail to write command pipe.\n");
        return -1;
    }

    seaf_debug ("send an unwatch command, repo %s\n", repo_id);

    n = seaf_pipe_readn (monitor->res_pipe[0], &res, sizeof(int));
    if (n != sizeof(int)) {
        seaf_warning ("[wt mon] fail to read result pipe.\n");
        return -1;
    }

    return res;
}

int
seaf_wt_monitor_refresh_repo (SeafWTMonitor *monitor, const char *repo_id)
{
    WatchCommand cmd;
    int res;

    memset (&cmd, 0, sizeof(cmd));
    memcpy (cmd.repo_id, repo_id, 37);
    cmd.type = CMD_REFRESH_WATCH;

    int n = seaf_pipe_writen (monitor->cmd_pipe[1], &cmd, sizeof(cmd));

    if (n != sizeof(cmd)) {
        seaf_warning ("[wt mon] fail to write command pipe.\n");
        return -1;
    }

    seaf_debug ("send a refresh command, repo %s\n", repo_id);

    n = seaf_pipe_readn (monitor->res_pipe[0], &res, sizeof(int));
    if (n != sizeof(int)) {
        seaf_warning ("[wt mon] fail to read result pipe.\n");
        return -1;
    }

    return res;
}

