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
struct timespec {unsigned long long tv_sec; unsigned long long tv_nsec; } ;
struct target {int /*<<< orphan*/  uses_mmap; scalar_t__ per_thread; scalar_t__ default_per_cpu; scalar_t__ system_wide; scalar_t__ cpu_list; scalar_t__ uid_str; scalar_t__ pid; scalar_t__ tid; } ;
struct perf_event_attr {int dummy; } ;
typedef  int /*<<< orphan*/  pid_t ;
struct TYPE_2__ {scalar_t__ build_options; } ;

/* Variables and functions */
 int /*<<< orphan*/  CLOCK_MONOTONIC ; 
 int /*<<< orphan*/  HAVE_AUXTRACE_SUPPORT ; 
 int /*<<< orphan*/  HAVE_DWARF_GETLOCATIONS_SUPPORT ; 
 int /*<<< orphan*/  HAVE_DWARF_SUPPORT ; 
 int /*<<< orphan*/  HAVE_GLIBC_SUPPORT ; 
 int /*<<< orphan*/  HAVE_GTK2_SUPPORT ; 
 int /*<<< orphan*/  HAVE_LIBAUDIT_SUPPORT ; 
 int /*<<< orphan*/  HAVE_LIBBFD_SUPPORT ; 
 int /*<<< orphan*/  HAVE_LIBBPF_SUPPORT ; 
 int /*<<< orphan*/  HAVE_LIBCRYPTO_SUPPORT ; 
 int /*<<< orphan*/  HAVE_LIBELF_SUPPORT ; 
 int /*<<< orphan*/  HAVE_LIBNUMA_SUPPORT ; 
 int /*<<< orphan*/  HAVE_LIBPERL_SUPPORT ; 
 int /*<<< orphan*/  HAVE_LIBPYTHON_SUPPORT ; 
 int /*<<< orphan*/  HAVE_LIBUNWIND_SUPPORT ; 
 int /*<<< orphan*/  HAVE_LZMA_SUPPORT ; 
 int /*<<< orphan*/  HAVE_SLANG_SUPPORT ; 
 int /*<<< orphan*/  HAVE_SYSCALL_TABLE_SUPPORT ; 
 int /*<<< orphan*/  HAVE_ZLIB_SUPPORT ; 
 int /*<<< orphan*/  PARSE_OPT_STOP_AT_NON_OPTION ; 
 int /*<<< orphan*/  PERF_COLOR_GREEN ; 
 int /*<<< orphan*/  PERF_COLOR_RED ; 
 int /*<<< orphan*/  STATUS (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  __NR_perf_event_open ; 
 scalar_t__ bpf ; 
 void* calloc (int,size_t) ; 
 int /*<<< orphan*/  clock_gettime (int /*<<< orphan*/ ,struct timespec*) ; 
 int /*<<< orphan*/  color_fprintf (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,char const*) ; 
 scalar_t__ dwarf ; 
 scalar_t__ dwarf_getlocations ; 
 scalar_t__ get_cpuid ; 
 scalar_t__ glibc ; 
 scalar_t__ gtk2 ; 
 scalar_t__ libaudit ; 
 scalar_t__ libbfd ; 
 scalar_t__ libcrypto ; 
 scalar_t__ libdw ; 
 scalar_t__ libelf ; 
 scalar_t__ libnuma ; 
 scalar_t__ libperl ; 
 scalar_t__ libpython ; 
 scalar_t__ libslang ; 
 scalar_t__ libunwind ; 
 scalar_t__ lzma ; 
 scalar_t__ numa_num_possible_cpus ; 
 int parse_options (int,char const**,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 char* perf_version_string ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  stdout ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 
 int syscall (int /*<<< orphan*/ ,struct perf_event_attr*,int /*<<< orphan*/ ,int,int,unsigned long) ; 
 scalar_t__ syscall_table ; 
 scalar_t__ unwind ; 
 TYPE_1__ version ; 
 int /*<<< orphan*/  version_options ; 
 int /*<<< orphan*/  version_usage ; 
 int version_verbose ; 
 scalar_t__ zlib ; 

__attribute__((used)) static inline void *zalloc(size_t size)
{
	return calloc(1, size);
}

__attribute__((used)) static inline int
sys_perf_event_open(struct perf_event_attr *attr,
		      pid_t pid, int cpu, int group_fd,
		      unsigned long flags)
{
	int fd;

	fd = syscall(__NR_perf_event_open, attr, pid, cpu,
		     group_fd, flags);

#ifdef HAVE_ATTR_TEST
	if (unlikely(test_attr__enabled))
		test_attr__open(attr, pid, cpu, fd, group_fd, flags);
#endif
	return fd;
}

__attribute__((used)) static inline unsigned long long rdclock(void)
{
	struct timespec ts;

	clock_gettime(CLOCK_MONOTONIC, &ts);
	return ts.tv_sec * 1000000000ULL + ts.tv_nsec;
}

__attribute__((used)) static inline bool target__has_task(struct target *target)
{
	return target->tid || target->pid || target->uid_str;
}

__attribute__((used)) static inline bool target__has_cpu(struct target *target)
{
	return target->system_wide || target->cpu_list;
}

__attribute__((used)) static inline bool target__none(struct target *target)
{
	return !target__has_task(target) && !target__has_cpu(target);
}

__attribute__((used)) static inline bool target__has_per_thread(struct target *target)
{
	return target->system_wide && target->per_thread;
}

__attribute__((used)) static inline bool target__uses_dummy_map(struct target *target)
{
	bool use_dummy = false;

	if (target->default_per_cpu)
		use_dummy = target->per_thread ? true : false;
	else if (target__has_task(target) ||
	         (!target__has_cpu(target) && !target->uses_mmap))
		use_dummy = true;
	else if (target__has_per_thread(target))
		use_dummy = true;

	return use_dummy;
}

__attribute__((used)) static void on_off_print(const char *status)
{
	printf("[ ");

	if (!strcmp(status, "OFF"))
		color_fprintf(stdout, PERF_COLOR_RED, "%-3s", status);
	else
		color_fprintf(stdout, PERF_COLOR_GREEN, "%-3s", status);

	printf(" ]");
}

__attribute__((used)) static void status_print(const char *name, const char *macro,
			 const char *status)
{
	printf("%22s: ", name);
	on_off_print(status);
	printf("  # %s\n", macro);
}

__attribute__((used)) static void library_status(void)
{
	STATUS(HAVE_DWARF_SUPPORT, dwarf);
	STATUS(HAVE_DWARF_GETLOCATIONS_SUPPORT, dwarf_getlocations);
	STATUS(HAVE_GLIBC_SUPPORT, glibc);
	STATUS(HAVE_GTK2_SUPPORT, gtk2);
#ifndef HAVE_SYSCALL_TABLE_SUPPORT
	STATUS(HAVE_LIBAUDIT_SUPPORT, libaudit);
#endif
	STATUS(HAVE_SYSCALL_TABLE_SUPPORT, syscall_table);
	STATUS(HAVE_LIBBFD_SUPPORT, libbfd);
	STATUS(HAVE_LIBELF_SUPPORT, libelf);
	STATUS(HAVE_LIBNUMA_SUPPORT, libnuma);
	STATUS(HAVE_LIBNUMA_SUPPORT, numa_num_possible_cpus);
	STATUS(HAVE_LIBPERL_SUPPORT, libperl);
	STATUS(HAVE_LIBPYTHON_SUPPORT, libpython);
	STATUS(HAVE_SLANG_SUPPORT, libslang);
	STATUS(HAVE_LIBCRYPTO_SUPPORT, libcrypto);
	STATUS(HAVE_LIBUNWIND_SUPPORT, libunwind);
	STATUS(HAVE_DWARF_SUPPORT, libdw-dwarf-unwind);
	STATUS(HAVE_ZLIB_SUPPORT, zlib);
	STATUS(HAVE_LZMA_SUPPORT, lzma);
	STATUS(HAVE_AUXTRACE_SUPPORT, get_cpuid);
	STATUS(HAVE_LIBBPF_SUPPORT, bpf);
}

int cmd_version(int argc, const char **argv)
{
	argc = parse_options(argc, argv, version_options, version_usage,
			     PARSE_OPT_STOP_AT_NON_OPTION);

	printf("perf version %s\n", perf_version_string);

	if (version.build_options || version_verbose == 1)
		library_status();

	return 0;
}

