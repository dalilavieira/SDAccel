#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int caps; } ;

/* Variables and functions */
 int CPUPOWER_CAP_HAS_TURBO_RATIO ; 
 int CPUPOWER_CAP_PERF_BIAS ; 
 unsigned int MSR_IA32_ENERGY_PERF_BIAS ; 
 unsigned int MSR_NEHALEM_TURBO_RATIO_LIMIT ; 
 int /*<<< orphan*/  O_RDONLY ; 
 int /*<<< orphan*/  O_WRONLY ; 
 int /*<<< orphan*/  SEEK_CUR ; 
 int /*<<< orphan*/  close (int) ; 
 TYPE_1__ cpupower_cpu_info ; 
 int lseek (int,unsigned int,int /*<<< orphan*/ ) ; 
 int open (char*,int /*<<< orphan*/ ) ; 
 int read (int,unsigned long long*,int) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 int write (int,unsigned long long*,int) ; 

int read_msr(int cpu, unsigned int idx, unsigned long long *val)
{
	int fd;
	char msr_file_name[64];

	sprintf(msr_file_name, "/dev/cpu/%d/msr", cpu);
	fd = open(msr_file_name, O_RDONLY);
	if (fd < 0)
		return -1;
	if (lseek(fd, idx, SEEK_CUR) == -1)
		goto err;
	if (read(fd, val, sizeof *val) != sizeof *val)
		goto err;
	close(fd);
	return 0;
 err:
	close(fd);
	return -1;
}

int write_msr(int cpu, unsigned int idx, unsigned long long val)
{
	int fd;
	char msr_file_name[64];

	sprintf(msr_file_name, "/dev/cpu/%d/msr", cpu);
	fd = open(msr_file_name, O_WRONLY);
	if (fd < 0)
		return -1;
	if (lseek(fd, idx, SEEK_CUR) == -1)
		goto err;
	if (write(fd, &val, sizeof val) != sizeof val)
		goto err;
	close(fd);
	return 0;
 err:
	close(fd);
	return -1;
}

int msr_intel_get_perf_bias(unsigned int cpu)
{
	unsigned long long val;
	int ret;

	if (!(cpupower_cpu_info.caps & CPUPOWER_CAP_PERF_BIAS))
		return -1;

	ret = read_msr(cpu, MSR_IA32_ENERGY_PERF_BIAS, &val);
	if (ret)
		return ret;
	return val;
}

int msr_intel_set_perf_bias(unsigned int cpu, unsigned int val)
{
	int ret;

	if (!(cpupower_cpu_info.caps & CPUPOWER_CAP_PERF_BIAS))
		return -1;

	ret = write_msr(cpu, MSR_IA32_ENERGY_PERF_BIAS, val);
	if (ret)
		return ret;
	return 0;
}

unsigned long long msr_intel_get_turbo_ratio(unsigned int cpu)
{
	unsigned long long val;
	int ret;

	if (!(cpupower_cpu_info.caps & CPUPOWER_CAP_HAS_TURBO_RATIO))
		return -1;

	ret = read_msr(cpu, MSR_NEHALEM_TURBO_RATIO_LIMIT, &val);
	if (ret)
		return ret;
	return val;
}

