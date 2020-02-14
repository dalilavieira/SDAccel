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
typedef  int uint64_t ;
typedef  int /*<<< orphan*/  pthread_t ;
typedef  int /*<<< orphan*/  cpuset ;
typedef  int /*<<< orphan*/  cpu_set_t ;

/* Variables and functions */
 int /*<<< orphan*/  CPU_SET (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CPU_ZERO (int /*<<< orphan*/ *) ; 
 int EXIT_FAILURE ; 
 int /*<<< orphan*/  SKIP_IF (int) ; 
 int /*<<< orphan*/  SPRN_TEXASR ; 
 int /*<<< orphan*/  SPRN_TFHAR ; 
 int /*<<< orphan*/  SPRN_TFIAR ; 
 int TEXASR_FS ; 
 int TM_CAUSE_FAC_UNAV ; 
 int TM_CAUSE_PERSISTENT ; 
 int TM_CAUSE_SYSCALL ; 
 int /*<<< orphan*/  _SC_NPROCESSORS_ONLN ; 
 int __builtin_get_texasru () ; 
 int atoi (char*) ; 
 int /*<<< orphan*/  free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * malloc (int) ; 
 void* mfspr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtspr (int /*<<< orphan*/ ,unsigned long) ; 
 int num_loops ; 
 scalar_t__ passed ; 
 int /*<<< orphan*/  printf (char*) ; 
 scalar_t__ pthread_create (int /*<<< orphan*/ *,int /*<<< orphan*/ *,void*,void*) ; 
 scalar_t__ pthread_join (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sched_setaffinity (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 scalar_t__ strcmp (char*,char*) ; 
 int sysconf (int /*<<< orphan*/ ) ; 
 int test_harness (int (*) (),char*) ; 

__attribute__((used)) static inline bool have_htm(void)
{
#ifdef PPC_FEATURE2_HTM
	return have_hwcap2(PPC_FEATURE2_HTM);
#else
	printf("PPC_FEATURE2_HTM not defined, can't check AT_HWCAP2\n");
	return false;
#endif
}

__attribute__((used)) static inline bool have_htm_nosc(void)
{
#ifdef PPC_FEATURE2_HTM_NOSC
	return have_hwcap2(PPC_FEATURE2_HTM_NOSC);
#else
	printf("PPC_FEATURE2_HTM_NOSC not defined, can't check AT_HWCAP2\n");
	return false;
#endif
}

__attribute__((used)) static inline long failure_code(void)
{
	return __builtin_get_texasru() >> 24;
}

__attribute__((used)) static inline bool failure_is_persistent(void)
{
	return (failure_code() & TM_CAUSE_PERSISTENT) == TM_CAUSE_PERSISTENT;
}

__attribute__((used)) static inline bool failure_is_syscall(void)
{
	return (failure_code() & TM_CAUSE_SYSCALL) == TM_CAUSE_SYSCALL;
}

__attribute__((used)) static inline bool failure_is_unavailable(void)
{
	return (failure_code() & TM_CAUSE_FAC_UNAV) == TM_CAUSE_FAC_UNAV;
}

__attribute__((used)) static inline bool failure_is_nesting(void)
{
	return (__builtin_get_texasru() & 0x400000);
}

__attribute__((used)) static inline int tcheck(void)
{
	long cr;
	asm volatile ("tcheck 0" : "=r"(cr) : : "cr0");
	return (cr >> 28) & 4;
}

__attribute__((used)) static inline bool tcheck_doomed(void)
{
	return tcheck() & 8;
}

__attribute__((used)) static inline bool tcheck_active(void)
{
	return tcheck() & 4;
}

__attribute__((used)) static inline bool tcheck_suspended(void)
{
	return tcheck() & 2;
}

__attribute__((used)) static inline bool tcheck_transactional(void)
{
	return tcheck() & 6;
}

void tfiar_tfhar(void *in)
{
	int i, cpu;
	unsigned long tfhar, tfhar_rd, tfiar, tfiar_rd;
	cpu_set_t cpuset;

	CPU_ZERO(&cpuset);
	cpu = (unsigned long)in >> 1;
	CPU_SET(cpu, &cpuset);
	sched_setaffinity(0, sizeof(cpuset), &cpuset);

	/* TFIAR: Last bit has to be high so userspace can read register */
	tfiar = ((unsigned long)in) + 1;
	tfiar += 2;
	mtspr(SPRN_TFIAR, tfiar);

	/* TFHAR: Last two bits are reserved */
	tfhar = ((unsigned long)in);
	tfhar &= ~0x3UL;
	tfhar += 4;
	mtspr(SPRN_TFHAR, tfhar);

	for (i = 0; i < num_loops; i++)	{
		tfhar_rd = mfspr(SPRN_TFHAR);
		tfiar_rd = mfspr(SPRN_TFIAR);
		if ( (tfhar != tfhar_rd) || (tfiar != tfiar_rd) ) {
			passed = 0;
			return;
		}
	}
	return;
}

void texasr(void *in)
{
	unsigned long i;
	uint64_t result = 0;

	for (i = 0; i < num_loops; i++) {
		asm __volatile__(
			"tbegin.;"
			"beq    3f ;"
			"tabort. 0 ;"
			"tend.;"

			/* Abort handler */
			"3: ;"
			::: "memory");

                /* Check the TEXASR */
                result = mfspr(SPRN_TEXASR);
		if ((result & TEXASR_FS) == 0) {
			passed = 0;
			return;
		}
	}
	return;
}

int test_tmspr()
{
	pthread_t	*thread;
	int	   	thread_num;
	unsigned long	i;

	SKIP_IF(!have_htm());

	/* To cause some context switching */
	thread_num = 10 * sysconf(_SC_NPROCESSORS_ONLN);

	thread = malloc(thread_num * sizeof(pthread_t));
	if (thread == NULL)
		return EXIT_FAILURE;

	/* Test TFIAR and TFHAR */
	for (i = 0; i < thread_num; i += 2) {
		if (pthread_create(&thread[i], NULL, (void *)tfiar_tfhar,
				   (void *)i))
			return EXIT_FAILURE;
	}
	/* Test TEXASR */
	for (i = 1; i < thread_num; i += 2) {
		if (pthread_create(&thread[i], NULL, (void *)texasr, (void *)i))
			return EXIT_FAILURE;
	}

	for (i = 0; i < thread_num; i++) {
		if (pthread_join(thread[i], NULL) != 0)
			return EXIT_FAILURE;
	}

	free(thread);

	if (passed)
		return 0;
	else
		return 1;
}

int main(int argc, char *argv[])
{
	if (argc > 1) {
		if (strcmp(argv[1], "-h") == 0) {
			printf("Syntax:\t [<num loops>]\n");
			return 0;
		} else {
			num_loops = atoi(argv[1]);
		}
	}
	return test_harness(test_tmspr, "tm_tmspr");
}

