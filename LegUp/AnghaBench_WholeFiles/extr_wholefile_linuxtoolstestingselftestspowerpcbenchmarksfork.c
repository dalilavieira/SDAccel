#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  pthread_t ;
typedef  int /*<<< orphan*/  pthread_attr_t ;
typedef  int pid_t ;
typedef  int /*<<< orphan*/  cpuset ;
typedef  int /*<<< orphan*/  cpu_set_t ;
struct TYPE_3__ {int /*<<< orphan*/  flag; } ;

/* Variables and functions */
 int /*<<< orphan*/  CPU_SET (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CPU_ZERO (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SIGALRM ; 
 int /*<<< orphan*/  SIGUSR1 ; 
 int /*<<< orphan*/  _exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  alarm (int) ; 
 void* atoi (char*) ; 
 int chdir (char*) ; 
 int cpu ; 
 scalar_t__ do_exec ; 
 scalar_t__ do_fork ; 
 scalar_t__ do_vfork ; 
 int errno ; 
 char* exec_file ; 
 scalar_t__ exec_target ; 
 int execve (char*,char* const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  exit (int) ; 
 int fork () ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*) ; 
 char getopt_long (int,char**,char*,TYPE_1__*,int*) ; 
 int /*<<< orphan*/  getpid () ; 
 unsigned long iterations ; 
 unsigned long iterations_prev ; 
 int /*<<< orphan*/  kill (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 char* optarg ; 
 int optind ; 
 TYPE_1__* options ; 
 int /*<<< orphan*/  perror (char*) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int pthread_attr_init (int /*<<< orphan*/ *) ; 
 int pthread_attr_setaffinity_np (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *) ; 
 int pthread_create (int /*<<< orphan*/ *,int /*<<< orphan*/ *,void* (*) (void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_exit (int /*<<< orphan*/ *) ; 
 int pthread_join (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ sched_setaffinity (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  setpgid (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  signal (int /*<<< orphan*/ ,void (*) (int)) ; 
 int /*<<< orphan*/  sleep (int) ; 
 int /*<<< orphan*/  stderr ; 
 char* strdup (char*) ; 
 int strlen (char*) ; 
 scalar_t__ timeout ; 
 int vfork () ; 
 int waitpid (int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void set_cpu(int cpu)
{
	cpu_set_t cpuset;

	if (cpu == -1)
		return;

	CPU_ZERO(&cpuset);
	CPU_SET(cpu, &cpuset);

	if (sched_setaffinity(0, sizeof(cpuset), &cpuset)) {
		perror("sched_setaffinity");
		exit(1);
	}
}

__attribute__((used)) static void start_process_on(void *(*fn)(void *), void *arg, int cpu)
{
	int pid;

	pid = fork();
	if (pid == -1) {
		perror("fork");
		exit(1);
	}

	if (pid)
		return;

	set_cpu(cpu);

	fn(arg);

	exit(0);
}

__attribute__((used)) static void run_exec(void)
{
	char *const argv[] = { "./exec_target", NULL };

	if (execve("./exec_target", argv, NULL) == -1) {
		perror("execve");
		exit(1);
	}
}

__attribute__((used)) static void bench_fork(void)
{
	while (1) {
		pid_t pid = fork();
		if (pid == -1) {
			perror("fork");
			exit(1);
		}
		if (pid == 0) {
			if (do_exec)
				run_exec();
			_exit(0);
		}
		pid = waitpid(pid, NULL, 0);
		if (pid == -1) {
			perror("waitpid");
			exit(1);
		}
		iterations++;
	}
}

__attribute__((used)) static void bench_vfork(void)
{
	while (1) {
		pid_t pid = vfork();
		if (pid == -1) {
			perror("fork");
			exit(1);
		}
		if (pid == 0) {
			if (do_exec)
				run_exec();
			_exit(0);
		}
		pid = waitpid(pid, NULL, 0);
		if (pid == -1) {
			perror("waitpid");
			exit(1);
		}
		iterations++;
	}
}

__attribute__((used)) static void *null_fn(void *arg)
{
	pthread_exit(NULL);
}

__attribute__((used)) static void bench_thread(void)
{
	pthread_t tid;
	cpu_set_t cpuset;
	pthread_attr_t attr;
	int rc;

	rc = pthread_attr_init(&attr);
	if (rc) {
		errno = rc;
		perror("pthread_attr_init");
		exit(1);
	}

	if (cpu != -1) {
		CPU_ZERO(&cpuset);
		CPU_SET(cpu, &cpuset);

		rc = pthread_attr_setaffinity_np(&attr, sizeof(cpu_set_t), &cpuset);
		if (rc) {
			errno = rc;
			perror("pthread_attr_setaffinity_np");
			exit(1);
		}
	}

	while (1) {
		rc = pthread_create(&tid, &attr, null_fn, NULL);
		if (rc) {
			errno = rc;
			perror("pthread_create");
			exit(1);
		}
		rc = pthread_join(tid, NULL);
		if (rc) {
			errno = rc;
			perror("pthread_join");
			exit(1);
		}
		iterations++;
	}
}

__attribute__((used)) static void sigalrm_handler(int junk)
{
	unsigned long i = iterations;

	printf("%ld\n", i - iterations_prev);
	iterations_prev = i;

	if (--timeout == 0)
		kill(0, SIGUSR1);

	alarm(1);
}

__attribute__((used)) static void sigusr1_handler(int junk)
{
	exit(0);
}

__attribute__((used)) static void *bench_proc(void *arg)
{
	signal(SIGALRM, sigalrm_handler);
	alarm(1);

	if (do_fork)
		bench_fork();
	else if (do_vfork)
		bench_vfork();
	else
		bench_thread();

	return NULL;
}

__attribute__((used)) static void usage(void)
{
	fprintf(stderr, "Usage: fork <options> CPU\n\n");
	fprintf(stderr, "\t\t--fork\tUse fork() (default threads)\n");
	fprintf(stderr, "\t\t--vfork\tUse vfork() (default threads)\n");
	fprintf(stderr, "\t\t--exec\tAlso exec() (default no exec)\n");
	fprintf(stderr, "\t\t--timeout=X\tDuration in seconds to run (default 30)\n");
	fprintf(stderr, "\t\t--exec-target\tInternal option for exec workload\n");
}

int main(int argc, char *argv[])
{
	signed char c;

	while (1) {
		int option_index = 0;

		c = getopt_long(argc, argv, "", options, &option_index);

		if (c == -1)
			break;

		switch (c) {
		case 0:
			if (options[option_index].flag != 0)
				break;

			usage();
			exit(1);
			break;

		case 's':
			timeout = atoi(optarg);
			break;

		default:
			usage();
			exit(1);
		}
	}

	if (do_fork && do_vfork) {
		usage();
		exit(1);
	}
	if (do_exec && !do_fork && !do_vfork) {
		usage();
		exit(1);
	}

	if (do_exec) {
		char *dirname = strdup(argv[0]);
		int i;
		i = strlen(dirname) - 1;
		while (i) {
			if (dirname[i] == '/') {
				dirname[i] = '\0';
				if (chdir(dirname) == -1) {
					perror("chdir");
					exit(1);
				}
				break;
			}
			i--;
		}
	}

	if (exec_target) {
		exit(0);
	}

	if (((argc - optind) != 1)) {
		cpu = -1;
	} else {
		cpu = atoi(argv[optind++]);
	}

	if (do_exec)
		exec_file = argv[0];

	set_cpu(cpu);

	printf("Using ");
	if (do_fork)
		printf("fork");
	else if (do_vfork)
		printf("vfork");
	else
		printf("clone");

	if (do_exec)
		printf(" + exec");

	printf(" on cpu %d\n", cpu);

	/* Create a new process group so we can signal everyone for exit */
	setpgid(getpid(), getpid());

	signal(SIGUSR1, sigusr1_handler);

	start_process_on(bench_proc, NULL, cpu);

	while (1)
		sleep(3600);

	return 0;
}

