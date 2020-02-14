#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
struct TYPE_15__ {char* lockgroup_name; scalar_t__ lock_spin_cnt; scalar_t__ lock_spin_util_cnt; scalar_t__ lock_mtx_cnt; scalar_t__ lock_mtx_util_cnt; scalar_t__ lock_rw_cnt; scalar_t__ lock_rw_util_cnt; scalar_t__ lock_rw_wait_cnt; scalar_t__ lock_rw_miss_cnt; scalar_t__ lock_mtx_held_cnt; scalar_t__ lock_mtx_wait_cnt; scalar_t__ lock_mtx_miss_cnt; scalar_t__ lock_spin_miss_cnt; } ;
typedef  TYPE_1__ lockgroup_info_t ;
typedef  scalar_t__ kern_return_t ;

/* Variables and functions */
 int /*<<< orphan*/  EXIT_FAILURE ; 
 scalar_t__ KERN_SUCCESS ; 
 TYPE_1__* calloc (int,int) ; 
 int count ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int gDebug ; 
 void get_lockgroup_deltas () ; 
 int /*<<< orphan*/  host_control ; 
 scalar_t__ host_lockgroup_info (int /*<<< orphan*/ ,TYPE_1__**,int*) ; 
 TYPE_1__* lockgroup_deltas ; 
 TYPE_1__* lockgroup_info ; 
 TYPE_1__* lockgroup_start ; 
 int /*<<< orphan*/  mach_error (char*,scalar_t__) ; 
 int /*<<< orphan*/  mach_host_self () ; 
 int /*<<< orphan*/  memcpy (TYPE_1__*,TYPE_1__*,int) ; 
 char* pgmname ; 
 void prime_lockgroup_deltas () ; 
 void print_all_mutex (TYPE_1__*) ; 
 void print_all_rw (TYPE_1__*) ; 
 void print_all_spin (TYPE_1__*) ; 
 void print_mutex (int,TYPE_1__*) ; 
 void print_mutex_hdr () ; 
 void print_rw (int,TYPE_1__*) ; 
 void print_rw_hdr () ; 
 void print_spin (int,TYPE_1__*) ; 
 void print_spin_hdr () ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  setlinebuf (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sleep (int) ; 
 int sscanf (char*,char*,int*) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  stdout ; 
 int /*<<< orphan*/  strcmp (char*,char*) ; 
 int /*<<< orphan*/ * strstr (char*,char*) ; 
 void usage () ; 

int
main(int argc, char **argv)
{
	kern_return_t		kr;
	int 			arg2;
	unsigned int 		i;
	int 			found;

	setlinebuf(stdout);

	pgmname = argv[0];
	gDebug = (NULL != strstr(argv[0], "debug"));

	host_control = mach_host_self();  

	kr = host_lockgroup_info(host_control, &lockgroup_info, &count);

	if (kr != KERN_SUCCESS)
	{
		mach_error("host_statistics", kr);
		exit (EXIT_FAILURE);
	}
	if (gDebug) {
		printf("count = %d\n", count);
		for (i = 0; i < count; i++) {
			printf("%s\n",lockgroup_info[i].lockgroup_name);
		}
	}

	switch (argc) {
	case 2:
		if (strcmp(argv[1], "all") == 0) {
			print_spin_hdr();
			print_all_spin(lockgroup_info);
			print_mutex_hdr();
			print_all_mutex(lockgroup_info);
			print_rw_hdr();
			print_all_rw(lockgroup_info);
		}
		else if (strcmp(argv[1], "spin") == 0) {
			print_spin_hdr();
			print_all_spin(lockgroup_info);
		}
		else if (strcmp(argv[1], "mutex") == 0) {
			print_mutex_hdr();
			print_all_mutex(lockgroup_info);
		}
		else if (strcmp(argv[1], "rw") == 0) {
			print_rw_hdr();
			print_all_rw(lockgroup_info);
		}
		else {
			found = 0;
			for (i = 0;i < count;i++) {
				if (strcmp(argv[1], lockgroup_info[i].lockgroup_name) == 0) {
					found = 1;
					print_spin_hdr();
					print_spin(i, lockgroup_info);
					print_mutex_hdr();
					print_mutex(i, lockgroup_info);
					print_rw_hdr();
					print_rw(i, lockgroup_info);
					break;
				}
			}
			if (found == 0) 
			{ usage(); }
		}
		break;	
	case 3:
		if (sscanf(argv[2], "%d", &arg2) != 1) {
			usage();
		}
		if (arg2 < 0) {
			usage();
		}
		prime_lockgroup_deltas();
		if (strcmp(argv[1], "all") == 0) {

			while (1) {
				sleep(arg2);
				get_lockgroup_deltas();
				print_spin_hdr();
				print_all_spin(lockgroup_deltas);
				print_mutex_hdr();
				print_all_mutex(lockgroup_deltas);
				print_rw_hdr();
				print_all_rw(lockgroup_deltas);
			}
		}
		else if (strcmp(argv[1], "spin") == 0) {

			while (1) {
				sleep(arg2);
				get_lockgroup_deltas();
				print_spin_hdr();
				print_all_spin(lockgroup_deltas);
			}
		}
		else if (strcmp(argv[1], "mutex") == 0) {

			while (1) {
				sleep(arg2);
				get_lockgroup_deltas();
				print_mutex_hdr();
				print_all_mutex(lockgroup_deltas);
			}
		}
		else if (strcmp(argv[1], "rw") == 0) {

			while (1) {
				sleep(arg2);
				get_lockgroup_deltas();
				print_rw_hdr();
				print_all_rw(lockgroup_deltas);
			}
		}
		else {

			found = 0;
			for (i = 0;i < count;i++) {
				if (strcmp(argv[1], lockgroup_info[i].lockgroup_name) == 0) {
					found = 1;
					while (1) {
						sleep(arg2);
						get_lockgroup_deltas();
						print_spin_hdr();
						print_spin(i, lockgroup_deltas);
						print_mutex_hdr();
						print_mutex(i, lockgroup_deltas);
						print_rw_hdr();
						print_rw(i, lockgroup_deltas);
					}
				}
			}
			if (found == 0)
			{ usage(); }
		}
		break;
	case 4:
		if (strcmp(argv[3], "abs") != 0)
		{ usage(); }
		if (sscanf(argv[2], "%d", &arg2) != 1)
		{ usage(); }
		if (strcmp(argv[1], "all") == 0) {
			while (1)
			{
				print_spin_hdr();
				print_all_spin(lockgroup_info);
				print_mutex_hdr();
				print_all_mutex(lockgroup_info);
				print_rw_hdr();
				print_all_rw(lockgroup_info);
				sleep(arg2);
			}
		}
		else if (strcmp(argv[1], "spin") == 0) {
			while (1)
			{print_all_spin(lockgroup_info);
				sleep(arg2);
			}
		}
		else if (strcmp(argv[1], "mutex") == 0) {
			print_mutex_hdr();
			while (1)
			{print_all_mutex(lockgroup_info);
				sleep(arg2);
			}
		}
		else if (strcmp(argv[1], "rw") == 0) {
			print_rw_hdr();
			while (1)
			{print_all_rw(lockgroup_info);
				sleep(arg2);
			}
		}
		else {
			found = 0;
			for (i = 0;i < count;i++) {
				if (strcmp(argv[1], lockgroup_info[i].lockgroup_name) == 0) {
					found = 1;
					while (1)
					{
						print_spin_hdr();
						print_spin(i, lockgroup_info);
						print_mutex_hdr();
						print_mutex(i, lockgroup_info);
						print_rw_hdr();
						print_rw(i, lockgroup_info);
						sleep(arg2);
					}
				}
			}
			if (found == 0)
			{ usage(); }
		}
		break;
	default:
		usage();
		break;
	}	

	exit(0);
}

void 
usage()
{
	fprintf(stderr, "Usage: %s [all, spin, mutex, rw, <lock group name>] {<repeat interval>} {abs}\n", pgmname);
	exit(EXIT_FAILURE);
}

void
print_spin_hdr(void)
{
	printf("    Spinlock acquires           misses   Name\n");
}

void
print_spin(int requested, lockgroup_info_t *lockgroup)
{
	lockgroup_info_t	*curptr = &lockgroup[requested];

	if (curptr->lock_spin_cnt != 0 && curptr->lock_spin_util_cnt != 0) {
		printf("%16lld ", curptr->lock_spin_util_cnt);
		printf("%16lld   ", curptr->lock_spin_miss_cnt);
		printf("%-14s\n", curptr->lockgroup_name);
	}
}

void
print_all_spin(lockgroup_info_t *lockgroup)
{
	unsigned int		i;

	for (i = 0;i < count;i++)
		print_spin(i, lockgroup);
        printf("\n");
}

void
print_mutex_hdr(void)
{
#if defined(__i386__) || defined(__x86_64__)
	printf("Mutex lock attempts  Misses      Waits Direct Waits Name\n");
#else
        printf("     mutex locks           misses            waits   name\n");
#endif
}

void
print_mutex(int requested, lockgroup_info_t *lockgroup)
{
	lockgroup_info_t	*curptr = &lockgroup[requested];

	if (curptr->lock_mtx_cnt != 0 && curptr->lock_mtx_util_cnt != 0) {
		printf("%16lld ", curptr->lock_mtx_util_cnt);
#if defined(__i386__) || defined(__x86_64__)
		printf("%10lld %10lld %10lld   ", curptr->lock_mtx_miss_cnt,  curptr->lock_mtx_wait_cnt, curptr->lock_mtx_held_cnt);
#else
		printf("%16lld %16lld   ", curptr->lock_mtx_miss_cnt,  curptr->lock_mtx_wait_cnt);
#endif
		printf("%-14s\n", curptr->lockgroup_name);
	}
}

void
print_all_mutex(lockgroup_info_t *lockgroup)
{
	unsigned int		i;

	for (i = 0;i < count;i++)
		print_mutex(i, lockgroup);
        printf("\n");

}

void
print_rw_hdr(void)
{
	printf("        RW locks           Misses            Waits   Name\n");
}

void
print_rw(int requested, lockgroup_info_t *lockgroup)
{
	lockgroup_info_t	*curptr = &lockgroup[requested];

	if (curptr->lock_rw_cnt != 0 && curptr->lock_rw_util_cnt != 0) {
		printf("%16lld ", curptr->lock_rw_util_cnt);
		printf("%16lld %16lld   ", curptr->lock_rw_miss_cnt,  curptr->lock_rw_wait_cnt);
		printf("%-14s\n", curptr->lockgroup_name);
	}
}

void
print_all_rw(lockgroup_info_t *lockgroup)
{
	unsigned int		i;

	for (i = 0;i < count;i++)
		print_rw(i, lockgroup);
        printf("\n");

}

void
prime_lockgroup_deltas(void)
{
	lockgroup_start = calloc(count, sizeof(lockgroup_info_t));
	if (lockgroup_start == NULL) {
		fprintf(stderr, "Can't allocate memory for lockgroup info\n");
		exit (EXIT_FAILURE);
	}
	memcpy(lockgroup_start, lockgroup_info, count * sizeof(lockgroup_info_t));

	lockgroup_deltas = calloc(count,  sizeof(lockgroup_info_t));
	if (lockgroup_deltas == NULL) {
		fprintf(stderr, "Can't allocate memory for lockgroup info\n");
		exit (EXIT_FAILURE);
	}
}

void
get_lockgroup_deltas(void)
{
	kern_return_t 			kr;
	unsigned int			i;

	kr = host_lockgroup_info(host_control, &lockgroup_info, &count);

	if (kr != KERN_SUCCESS)
	{
		mach_error("host_statistics", kr);
		exit (EXIT_FAILURE);
	}

	memcpy(lockgroup_deltas, lockgroup_info, count * sizeof(lockgroup_info_t));
	for (i = 0; i < count; i++) {
		lockgroup_deltas[i].lock_spin_util_cnt =
		    lockgroup_info[i].lock_spin_util_cnt -
		    lockgroup_start[i].lock_spin_util_cnt;
		lockgroup_deltas[i].lock_spin_miss_cnt =
		    lockgroup_info[i].lock_spin_miss_cnt -
		    lockgroup_start[i].lock_spin_miss_cnt;
		lockgroup_deltas[i].lock_mtx_util_cnt =
		    lockgroup_info[i].lock_mtx_util_cnt -
		    lockgroup_start[i].lock_mtx_util_cnt;
		lockgroup_deltas[i].lock_mtx_miss_cnt =
		    lockgroup_info[i].lock_mtx_miss_cnt -
		    lockgroup_start[i].lock_mtx_miss_cnt;
		lockgroup_deltas[i].lock_mtx_wait_cnt =
		    lockgroup_info[i].lock_mtx_wait_cnt -
		    lockgroup_start[i].lock_mtx_wait_cnt;
		lockgroup_deltas[i].lock_mtx_held_cnt =
		    lockgroup_info[i].lock_mtx_held_cnt -
		    lockgroup_start[i].lock_mtx_held_cnt;
		lockgroup_deltas[i].lock_rw_util_cnt =
		    lockgroup_info[i].lock_rw_util_cnt -
		    lockgroup_start[i].lock_rw_util_cnt;
		lockgroup_deltas[i].lock_rw_miss_cnt =
		    lockgroup_info[i].lock_rw_miss_cnt -
		    lockgroup_start[i].lock_rw_miss_cnt;
		lockgroup_deltas[i].lock_rw_wait_cnt =
		    lockgroup_info[i].lock_rw_wait_cnt -
		    lockgroup_start[i].lock_rw_wait_cnt;
	}
	memcpy(lockgroup_start, lockgroup_info, count * sizeof(lockgroup_info_t));
}

