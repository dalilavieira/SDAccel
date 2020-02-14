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
struct mac_policy_conf {char* mpc_name; char* mpc_fullname; } ;
typedef  int /*<<< orphan*/  errno_t ;

/* Variables and functions */
 int CHECK_POLICY_BACKTRACE ; 
 int CHECK_POLICY_FAIL ; 
 int CHECK_POLICY_PANIC ; 
 int CHECK_POLICY_PERIODIC ; 
 int CLASS_PERIOD_LIMIT ; 
 int CLASS_PERIOD_MULT ; 
 int EPERM ; 
 int /*<<< orphan*/  OSReportWithBacktrace (char*,int,int) ; 
 int /*<<< orphan*/  current_thread () ; 
 int get_thread_lock_count (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mac_policy_register (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  panic (char*,int) ; 
 int policy_check_event ; 
 int policy_check_next ; 
 int policy_check_period ; 
 int /*<<< orphan*/  policy_conf ; 
 int policy_flags ; 
 int /*<<< orphan*/  policy_handle ; 
 int /*<<< orphan*/  printf (char*,char*,...) ; 

__attribute__((used)) static void
hook_policy_init(struct mac_policy_conf *mpc)
{
	printf("Policy '%s' = '%s' ready\n", mpc->mpc_name, mpc->mpc_fullname);
}

__attribute__((used)) static void
hook_policy_initbsd(struct mac_policy_conf *mpc)
{
	/* called with policy_grab_exclusive mutex held; exempt */
	printf("hook_policy_initbsd: %s\n", mpc->mpc_name);
}

__attribute__((used)) static int
common_hook(void)
{
	int	i;
	int	rv = 0;

	if ((i = get_thread_lock_count(current_thread())) != 0) {
		/*
		 * fail the MACF check if we hold a lock; this assumes a
		 * a non-void (authorization) MACF hook.
		 */
		if (policy_flags & CHECK_POLICY_FAIL)
			rv = EPERM;

		/*
		 * display a backtrace if we hold a lock and we are not
		 * going to panic
		 */
		if ((policy_flags & (CHECK_POLICY_BACKTRACE | CHECK_POLICY_PANIC)) == CHECK_POLICY_BACKTRACE) {
			if (policy_flags & CHECK_POLICY_PERIODIC) {
			    /* at exponentially increasing intervals */
			    if (!(policy_check_event % policy_check_period)) {
				if (policy_check_event <= policy_check_next || policy_check_period == CLASS_PERIOD_LIMIT) {
					/*
					 * According to Derek, we could
					 * technically get a symbolicated name
					 * here, if we refactered some code
					 * and set the "keepsyms=1" boot
					 * argument...
					 */
					OSReportWithBacktrace("calling MACF hook with mutex count %d (event %d) ", i, policy_check_event);
				}
			    } else {
				if (policy_check_period < CLASS_PERIOD_LIMIT) {
					policy_check_next *= CLASS_PERIOD_MULT;
					policy_check_period *= CLASS_PERIOD_MULT;
				}
			    }
			} else {
				/* always */
				OSReportWithBacktrace("calling MACF hook with mutex count %d (event %d) ", i, policy_check_event);
			}
		}

		/* Panic */
		if (policy_flags & CHECK_POLICY_PANIC)
			panic("calling MACF hook with mutex count %d\n", i);

		/* count for non-fatal tracing */
		policy_check_event++;
	}

	return rv;
}

errno_t
check_policy_init(int flags)
{
	/* Only instantiate the module if we have been asked to do checking */
	if (!flags)
		return 0;

	policy_flags = flags;

	return mac_policy_register(&policy_conf, &policy_handle, NULL);
}

