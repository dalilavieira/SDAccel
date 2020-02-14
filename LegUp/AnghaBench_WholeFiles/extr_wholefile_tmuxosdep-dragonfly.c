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
typedef  size_t u_int ;
struct stat {scalar_t__ st_rdev; } ;
struct kinfo_proc {scalar_t__ kp_pid; scalar_t__ kp_tdev; int /*<<< orphan*/  kp_comm; } ;
struct event_base {int dummy; } ;

/* Variables and functions */
 int CTL_KERN ; 
 scalar_t__ ENOMEM ; 
 int KERN_PROC ; 
 int KERN_PROC_PGRP ; 
 scalar_t__ errno ; 
 struct event_base* event_init () ; 
 int /*<<< orphan*/  free (struct kinfo_proc*) ; 
 scalar_t__ is_runnable (struct kinfo_proc*) ; 
 scalar_t__ is_stopped (struct kinfo_proc*) ; 
 int /*<<< orphan*/  nitems (int*) ; 
 struct kinfo_proc* realloc (struct kinfo_proc*,size_t) ; 
 int stat (char*,struct stat*) ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 char* strdup (int /*<<< orphan*/ ) ; 
 int sysctl (int*,int /*<<< orphan*/ ,struct kinfo_proc*,size_t*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int tcgetpgrp (int) ; 

struct kinfo_proc *
cmp_procs(struct kinfo_proc *p1, struct kinfo_proc *p2)
{
	if (is_runnable(p1) && !is_runnable(p2))
		return (p1);
	if (!is_runnable(p1) && is_runnable(p2))
		return (p2);

	if (is_stopped(p1) && !is_stopped(p2))
		return (p1);
	if (!is_stopped(p1) && is_stopped(p2))
		return (p2);

	if (strcmp(p1->kp_comm, p2->kp_comm) < 0)
		return (p1);
	if (strcmp(p1->kp_comm, p2->kp_comm) > 0)
		return (p2);

	if (p1->kp_pid > p2->kp_pid)
		return (p1);
	return (p2);
}

char *
osdep_get_name(int fd, char *tty)
{
	int		 mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PGRP, 0 };
	struct stat	 sb;
	size_t		 len;
	struct kinfo_proc *buf, *newbuf, *bestp;
	u_int		 i;
	char		*name;

	buf = NULL;

	if (stat(tty, &sb) == -1)
		return (NULL);
	if ((mib[3] = tcgetpgrp(fd)) == -1)
		return (NULL);

retry:
	if (sysctl(mib, nitems(mib), NULL, &len, NULL, 0) == -1)
		return (NULL);
	len = (len * 5) / 4;

	if ((newbuf = realloc(buf, len)) == NULL)
		goto error;
	buf = newbuf;

	if (sysctl(mib, nitems(mib), buf, &len, NULL, 0) == -1) {
		if (errno == ENOMEM)
			goto retry;
		goto error;
	}

	bestp = NULL;
	for (i = 0; i < len / sizeof (struct kinfo_proc); i++) {
		if (buf[i].kp_tdev != sb.st_rdev)
			continue;
		if (bestp == NULL)
			bestp = &buf[i];
		else
			bestp = cmp_procs(&buf[i], bestp);
	}

	name = NULL;
	if (bestp != NULL)
		name = strdup(bestp->kp_comm);

	free(buf);
	return (name);

error:
	free(buf);
	return (NULL);
}

char *
osdep_get_cwd(int fd)
{
	return (NULL);
}

struct event_base *
osdep_event_init(void)
{
	return (event_init());
}

