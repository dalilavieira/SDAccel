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
typedef  unsigned int uint32_t ;

/* Variables and functions */
 unsigned int MCPU ; 
 unsigned int MSR_IA32_PERF_STATUS ; 
 int /*<<< orphan*/  O_RDONLY ; 
 int /*<<< orphan*/  SEEK_CUR ; 
 int /*<<< orphan*/  close (int) ; 
 int lseek (int,unsigned int,int /*<<< orphan*/ ) ; 
 int open (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int read (int,unsigned long long*,int) ; 
 int /*<<< orphan*/  sprintf (char*,char*,unsigned int) ; 
 unsigned int strtoul (char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int rdmsr(unsigned int cpu, unsigned int msr,
		 unsigned int *lo, unsigned int *hi)
{
	int fd;
	char file[20];
	unsigned long long val;
	int retval = -1;

	*lo = *hi = 0;

	if (cpu > MCPU)
		goto err1;

	sprintf(file, "/dev/cpu/%d/msr", cpu);
	fd = open(file, O_RDONLY);

	if (fd < 0)
		goto err1;

	if (lseek(fd, msr, SEEK_CUR) == -1)
		goto err2;

	if (read(fd, &val, 8) != 8)
		goto err2;

	*lo = (uint32_t )(val & 0xffffffffull);
	*hi = (uint32_t )(val>>32 & 0xffffffffull);

	retval = 0;
err2:
	close(fd);
err1:
	return retval;
}

__attribute__((used)) static void decode (unsigned int msr)
{
	unsigned int multiplier;
	unsigned int mv;

	multiplier = ((msr >> 8) & 0xFF);

	mv = (((msr & 0xFF) * 16) + 700);

	printf("0x%x means multiplier %d @ %d mV\n", msr, multiplier, mv);
}

__attribute__((used)) static int decode_live(unsigned int cpu)
{
	unsigned int lo, hi;
	int err;

	err = rdmsr(cpu, MSR_IA32_PERF_STATUS, &lo, &hi);

	if (err) {
		printf("can't get MSR_IA32_PERF_STATUS for cpu %d\n", cpu);
		printf("Possible trouble: you don't run an Enhanced SpeedStep capable cpu\n");
		printf("or you are not root, or the msr driver is not present\n");
		return 1;
	}

	decode(lo);

	return 0;
}

int main (int argc, char **argv)
{
	unsigned int cpu, mode = 0;

	if (argc < 2)
		cpu = 0;
	else {
		cpu = strtoul(argv[1], NULL, 0);
		if (cpu >= MCPU)
			mode = 1;
	}

	if (mode)
		decode(cpu);
	else
		decode_live(cpu);

	return 0;
}

