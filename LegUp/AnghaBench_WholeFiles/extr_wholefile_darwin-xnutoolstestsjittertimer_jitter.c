#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int uint64_t ;
typedef  int uint32_t ;
struct TYPE_5__ {int period; int constraint; int computation; int /*<<< orphan*/  preemptible; } ;
typedef  TYPE_1__ thread_time_constraint_policy_data_t ;
typedef  int /*<<< orphan*/  thread_policy_t ;
struct TYPE_6__ {int /*<<< orphan*/  timeshare; } ;
typedef  TYPE_2__ thread_extended_policy_data_t ;
struct second_thread_args {void* wakeup_semaphore; void* return_semaphore; int iterations; int pol; double* wakeup_second_jitter_arr; int too_much; unsigned long long last_poke_time; int cpuno; scalar_t__ woke_on_same_cpu; } ;
typedef  void* semaphore_t ;
typedef  int /*<<< orphan*/  pthread_t ;
typedef  int my_policy_type_t ;
typedef  int kern_return_t ;
typedef  scalar_t__ boolean_t ;
struct TYPE_7__ {int denom; int numer; } ;

/* Variables and functions */
 int COMPUTATION_NANOS ; 
 int CONSTRAINT_NANOS ; 
 int DBG_FUNC_NONE ; 
 int DEFAULT_MAX_SLEEP_NS ; 
 scalar_t__ FALSE ; 
 scalar_t__ INT64_MAX ; 
 int KERN_SUCCESS ; 
#define  MY_POLICY_FIXEDPRI 130 
#define  MY_POLICY_REALTIME 129 
#define  MY_POLICY_TIMESHARE 128 
 int /*<<< orphan*/  OSMemoryBarrier () ; 
 int /*<<< orphan*/  SYNC_POLICY_FIFO ; 
 int /*<<< orphan*/  THREAD_EXTENDED_POLICY ; 
 int /*<<< orphan*/  THREAD_EXTENDED_POLICY_COUNT ; 
 int /*<<< orphan*/  THREAD_TIME_CONSTRAINT_POLICY ; 
 int /*<<< orphan*/  THREAD_TIME_CONSTRAINT_POLICY_COUNT ; 
 scalar_t__ TRUE ; 
 void* _os_cpu_number () ; 
 int /*<<< orphan*/  assert (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  atoi (char*) ; 
 int /*<<< orphan*/  err (int,char*) ; 
 int /*<<< orphan*/  errx (int,char*,...) ; 
 int /*<<< orphan*/  exit (int) ; 
 scalar_t__ fabs (double) ; 
 int /*<<< orphan*/  fail ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*) ; 
 TYPE_3__ g_mti ; 
 char getopt (int,char**,char*) ; 
 int /*<<< orphan*/  getpid () ; 
 int /*<<< orphan*/  kdebug_trace (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* mach_absolute_time () ; 
 int /*<<< orphan*/  mach_task_self () ; 
 int /*<<< orphan*/  mach_thread_self () ; 
 int /*<<< orphan*/  mach_timebase_info (TYPE_3__*) ; 
 int mach_wait_until (int) ; 
 scalar_t__ malloc (int) ; 
 char* optarg ; 
 scalar_t__ opterr ; 
 scalar_t__ optind ; 
 scalar_t__ pow (double,int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int proc_disable_wakemon (int /*<<< orphan*/ ) ; 
 int pthread_create (int /*<<< orphan*/ *,int /*<<< orphan*/ *,void* (*) (void*),struct second_thread_args*) ; 
 int pthread_join (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  putchar (char) ; 
 scalar_t__ random () ; 
 void* second_thread (void*) ; 
 int semaphore_create (int /*<<< orphan*/ ,void**,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int semaphore_signal (void*) ; 
 int semaphore_wait (void*) ; 
 int /*<<< orphan*/  sleep (int) ; 
 double sqrt (double) ; 
 int /*<<< orphan*/  srandom (unsigned int) ; 
 int /*<<< orphan*/  stderr ; 
 scalar_t__ strcmp (char const*,char*) ; 
 int strtoull (char*,int /*<<< orphan*/ *,int) ; 
 int thread_policy_set (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 unsigned int time (int /*<<< orphan*/ *) ; 

void
print_usage()
{
	printf("Usage: jitter [-w] [-s <random seed>] [-n <min sleep, ns>] [-m <max sleep, ns>] <realtime | timeshare | fixed> <num iterations> <traceworthy jitter, ns>\n");
}

my_policy_type_t
parse_thread_policy(const char *str)
{
	if (strcmp(str, "timeshare") == 0) {
		return MY_POLICY_TIMESHARE;
	} else if (strcmp(str, "realtime") == 0) {
		return MY_POLICY_REALTIME;
	} else if (strcmp(str, "fixed") == 0) {
		return MY_POLICY_FIXEDPRI;
	} else {
		printf("Invalid thread policy %s\n", str);
		exit(1);
	}
}

int
thread_setup(my_policy_type_t pol)
{
	int res;

	switch (pol) {
		case MY_POLICY_TIMESHARE:
		{
			return 0;
		}
		case MY_POLICY_REALTIME: 
		{
			thread_time_constraint_policy_data_t pol;

			/* Hard-coded realtime parameters (similar to what Digi uses) */
			pol.period = 100000;
			pol.constraint =  CONSTRAINT_NANOS * g_mti.denom / g_mti.numer;
			pol.computation = COMPUTATION_NANOS * g_mti.denom / g_mti.numer;
			pol.preemptible = 0; /* Ignored by OS */

			res = thread_policy_set(mach_thread_self(), THREAD_TIME_CONSTRAINT_POLICY, (thread_policy_t) &pol, THREAD_TIME_CONSTRAINT_POLICY_COUNT);
			assert(res == 0, fail);
			break;
		}
		case MY_POLICY_FIXEDPRI: 
		{
			thread_extended_policy_data_t pol;
			pol.timeshare = 0;

			res = thread_policy_set(mach_thread_self(), THREAD_EXTENDED_POLICY, (thread_policy_t) &pol, THREAD_EXTENDED_POLICY_COUNT);
			assert(res == 0, fail);
			break;
		}
		default:
		{
			printf("invalid policy type\n");
			return 1;
		}
	}

	return 0;
fail:
	return 1;
}

uint64_t 
get_random_sleep_length_abs_ns(uint64_t min_sleep_ns, uint64_t max_sleep_ns)
{
	uint64_t tmp;

	tmp = (uint32_t)random();
	tmp <<= 32;
	tmp |= (uint32_t)random();

	/* Now use the random number to sleep amount within the window */
	tmp %= (max_sleep_ns - min_sleep_ns);

	return min_sleep_ns + tmp;
}

void 
compute_stats(double *values, uint64_t count, double *average_magnitudep, double *maxp, double *minp, double *stddevp)
{
	uint64_t i;
	double _sum = 0;
	double _max = 0;
	double _min = (double)INT64_MAX;
	double _avg = 0;
	double _dev = 0;

	for (i = 0; i < count; i++) {
		_sum += fabs(values[i]);
		_max = values[i] > _max ? values[i] : _max;
		_min = values[i] < _min ? values[i] : _min;
	}

	_avg = _sum / (double)count;
	
	_dev = 0;
	for (i = 0; i < count; i++) {
		_dev += pow((values[i] - _avg), 2);
	}
	
	_dev /= count;
	_dev = sqrt(_dev);

	*average_magnitudep = _avg;
	*maxp = _max;
	*minp = _min;
	*stddevp = _dev;
}

void
print_stats_us(const char *label, double avg, double max, double min, double stddev)
{
	printf("Max %s: %.1lfus\n", label, max / 1000.0 * (((double)g_mti.numer) / ((double)g_mti.denom)));
	printf("Min %s: %.1lfus\n", label, min / 1000.0 * (((double)g_mti.numer) / ((double)g_mti.denom)));
	printf("Avg magnitude of %s: %.1lfus\n", label, avg / 1000.0 * (((double)g_mti.numer) / ((double)g_mti.denom)));
	printf("Stddev: %.1lfus\n", stddev / 1000.0 * (((double)g_mti.numer) / ((double)g_mti.denom)));
	putchar('\n');
}

void
print_stats_fract(const char *label, double avg, double max, double min, double stddev)
{
	printf("Max %s jitter: %.1lf%%\n", label, max * 100);
	printf("Min %s jitter: %.1lf%%\n", label, min * 100);
	printf("Avg %s jitter: %.1lf%%\n", label, avg * 100);
	printf("Stddev: %.1lf%%\n", stddev * 100);
	putchar('\n');	
}

int
main(int argc, char **argv)
{
	uint64_t iterations, i;
	double *jitter_arr, *fraction_arr;
	double *wakeup_second_jitter_arr;
	uint64_t target_time;
	uint64_t sleep_length_abs;
	uint64_t min_sleep_ns = 0;
	uint64_t max_sleep_ns = DEFAULT_MAX_SLEEP_NS;
	uint64_t wake_time;
	unsigned random_seed;
	boolean_t need_seed = TRUE;
	char ch;
	int res;
	kern_return_t kret;
	my_policy_type_t pol;
	boolean_t wakeup_second_thread = FALSE;
	semaphore_t wakeup_semaphore, return_semaphore;

	double avg, stddev, max, min;
	double avg_fract, stddev_fract, max_fract, min_fract;
	uint64_t too_much;

	struct second_thread_args secargs;
	pthread_t secthread;

	mach_timebase_info(&g_mti);

	/* Seed random */
	opterr = 0;
	while ((ch = getopt(argc, argv, "m:n:hs:w")) != -1 && ch != '?') {
		switch (ch) {
			case 's':
				/* Specified seed for random)() */
				random_seed = (unsigned)atoi(optarg);
				srandom(random_seed);
				need_seed = FALSE;
				break;
			case 'm':
				/* How long per timer? */
				max_sleep_ns = strtoull(optarg, NULL, 10);	
				break;
			case 'n':
				/* How long per timer? */
				min_sleep_ns = strtoull(optarg, NULL, 10);	
				break;
			case 'w':
				/* After each timed wait, wakeup another thread */
				wakeup_second_thread = TRUE;
				break;
			case 'h':
				print_usage();
				exit(0);
				break;
			default:
				fprintf(stderr, "Got unexpected result from getopt().\n");
				exit(1);
				break;
		}
	}

	argc -= optind;
	argv += optind;

	if (argc != 3) {
		print_usage();
		exit(1);
	}

	if (min_sleep_ns >= max_sleep_ns) {
		print_usage();
		exit(1);
	}

	if (need_seed) {
		srandom(time(NULL));
	}

	/* What scheduling policy? */
	pol = parse_thread_policy(argv[0]);

	/* How many timers? */
	iterations = strtoull(argv[1], NULL, 10);

	/* How much jitter is so extreme that we should cut a trace point */
	too_much = strtoull(argv[2], NULL, 10);
	
	/* Array for data */
	jitter_arr = (double*)malloc(sizeof(*jitter_arr) * iterations);
	if (jitter_arr == NULL) {
		printf("Couldn't allocate array to store results.\n");
		exit(1);
	}

	fraction_arr = (double*)malloc(sizeof(*fraction_arr) * iterations);
	if (fraction_arr == NULL) {
		printf("Couldn't allocate array to store results.\n");
		exit(1);
	}

	if (wakeup_second_thread) {
		/* Array for data */
		wakeup_second_jitter_arr = (double*)malloc(sizeof(*jitter_arr) * iterations);
		if (wakeup_second_jitter_arr == NULL) {
			printf("Couldn't allocate array to store results.\n");
			exit(1);
		}

		kret = semaphore_create(mach_task_self(), &wakeup_semaphore, SYNC_POLICY_FIFO, 0);
		if (kret != KERN_SUCCESS) {
			printf("Couldn't allocate semaphore %d\n", kret);
			exit(1);
		}

		kret = semaphore_create(mach_task_self(), &return_semaphore, SYNC_POLICY_FIFO, 0);
		if (kret != KERN_SUCCESS) {
			printf("Couldn't allocate semaphore %d\n", kret);
			exit(1);
		}


		secargs.wakeup_semaphore = wakeup_semaphore;
		secargs.return_semaphore = return_semaphore;
		secargs.iterations = iterations;
		secargs.pol = pol;
		secargs.wakeup_second_jitter_arr = wakeup_second_jitter_arr;
		secargs.woke_on_same_cpu = 0;
		secargs.too_much = too_much;
		secargs.last_poke_time = 0ULL;
		secargs.cpuno = 0;

		res = pthread_create(&secthread, NULL, second_thread, &secargs);
		if (res) {
			err(1, "pthread_create");
		}

		sleep(1); /* Time for other thread to start up */
	}

	/* Set scheduling policy */
	res = thread_setup(pol);
	if (res != 0) {
		printf("Couldn't set thread policy.\n");
		exit(1);
	}

	/*
	 * Disable the wake monitor.  If we are
	 * performing a large number of
	 * iterations, the wake monitor may
	 * cause this process to get suspended,
	 * thus causing a large jitter value.
	 */
	if (proc_disable_wakemon(getpid()) != KERN_SUCCESS) {
		printf("Couldn't disable wake monitor.\n");
		/* For now, do not exit; this call could be locked down */
	}

	/* 
	 * Repeatedly pick a random timer length and 
	 * try to sleep exactly that long 
	 */
	for (i = 0; i < iterations; i++) {
		sleep_length_abs = (uint64_t) (get_random_sleep_length_abs_ns(min_sleep_ns, max_sleep_ns) * (((double)g_mti.denom) / ((double)g_mti.numer)));
		target_time = mach_absolute_time() + sleep_length_abs;
		
		/* Sleep */
		kret = mach_wait_until(target_time);
		wake_time = mach_absolute_time();
	
		jitter_arr[i] = (double)(wake_time - target_time);
		fraction_arr[i] = jitter_arr[i] / ((double)sleep_length_abs);
		
		/* Too much: cut a tracepoint for a debugger */
		if (jitter_arr[i] >= too_much) {
			kdebug_trace(0xeeeee0 | DBG_FUNC_NONE, 0, 0, 0, 0);
		}

		if (wakeup_second_thread) {
			secargs.last_poke_time = mach_absolute_time();
			secargs.cpuno = _os_cpu_number();
			OSMemoryBarrier();
			kret = semaphore_signal(wakeup_semaphore);
			if (kret != KERN_SUCCESS) {
				errx(1, "semaphore_signal");
			}

			kret = semaphore_wait(return_semaphore);
			if (kret != KERN_SUCCESS) {
				errx(1, "semaphore_wait");
			}

		}
	}

	/*
	 * Compute statistics and output results. 
	 */
	compute_stats(jitter_arr, iterations, &avg, &max, &min, &stddev);
	compute_stats(fraction_arr, iterations, &avg_fract, &max_fract, &min_fract, &stddev_fract);

	putchar('\n');
	print_stats_us("jitter", avg, max, min, stddev);
	print_stats_fract("%", avg_fract, max_fract, min_fract, stddev_fract);

	if (wakeup_second_thread) {

		res = pthread_join(secthread, NULL);
		if (res) {
			err(1, "pthread_join");
		}

		compute_stats(wakeup_second_jitter_arr, iterations, &avg, &max, &min, &stddev);
		
		putchar('\n');
		print_stats_us("second jitter", avg, max, min, stddev);

		putchar('\n');
		printf("%llu/%llu (%.1f%%) wakeups on same CPU\n", secargs.woke_on_same_cpu, iterations,
			   100.0*((double)secargs.woke_on_same_cpu)/iterations);
	}

	return 0;
}

void *
second_thread(void *args)
{
	struct second_thread_args *secargs = (struct second_thread_args *)args;
	int res;
	uint64_t i;
	kern_return_t kret;
	uint64_t wake_time;
	int cpuno;

	/* Set scheduling policy */
	res = thread_setup(secargs->pol);
	if (res != 0) {
		printf("Couldn't set thread policy.\n");
		exit(1);
	}

	/* 
	 * Repeatedly pick a random timer length and 
	 * try to sleep exactly that long 
	 */
	for (i = 0; i < secargs->iterations; i++) {

		/* Wake up when poked by main thread */
		kret = semaphore_wait(secargs->wakeup_semaphore);
		if (kret != KERN_SUCCESS) {
			errx(1, "semaphore_wait %d", kret);
		}

		wake_time = mach_absolute_time();
		cpuno = _os_cpu_number();
		if (wake_time < secargs->last_poke_time) {
			/* Woke in past, unsynchronized mach_absolute_time()? */
			
			errx(1, "woke in past %llu (%d) < %llu (%d)", wake_time, cpuno, secargs->last_poke_time, secargs->cpuno);
		}

		if (cpuno == secargs->cpuno) {
			secargs->woke_on_same_cpu++;
		}

		secargs->wakeup_second_jitter_arr[i] = (double)(wake_time - secargs->last_poke_time);
		
		/* Too much: cut a tracepoint for a debugger */
		if (secargs->wakeup_second_jitter_arr[i] >= secargs->too_much) {
			kdebug_trace(0xeeeee4 | DBG_FUNC_NONE, 0, 0, 0, 0);
		}

		kret = semaphore_signal(secargs->return_semaphore);
		if (kret != KERN_SUCCESS) {
			errx(1, "semaphore_signal %d", kret);
		}

	}

	return NULL;
}

