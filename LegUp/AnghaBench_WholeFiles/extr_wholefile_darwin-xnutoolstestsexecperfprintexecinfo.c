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
typedef  char const** uint64_t ;
struct TYPE_5__ {scalar_t__ all_image_info_addr; } ;
typedef  TYPE_1__ task_dyld_info_data_t ;
struct dyld_all_image_infos {scalar_t__ sharedCacheSlide; scalar_t__ dyldImageLoadAddress; } ;
typedef  int /*<<< orphan*/  stackaddr ;
typedef  int /*<<< orphan*/  mach_msg_type_number_t ;
typedef  scalar_t__ kern_return_t ;
struct TYPE_7__ {int cputype; int cpusubtype; } ;
struct TYPE_6__ {char* name; char* description; } ;
typedef  TYPE_2__ NXArchInfo ;

/* Variables and functions */
 int CPU_SUBTYPE_MASK ; 
 scalar_t__ KERN_SUCCESS ; 
 TYPE_2__* NXGetArchInfoFromCpuType (int,int) ; 
 int /*<<< orphan*/  TASK_DYLD_INFO ; 
 int /*<<< orphan*/  TASK_DYLD_INFO_COUNT ; 
 TYPE_3__ _mh_execute_header ; 
 int /*<<< orphan*/  err (int,char*) ; 
 int /*<<< orphan*/  errx (int,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mach_error_string (scalar_t__) ; 
 int /*<<< orphan*/  mach_task_self () ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int strlen (char const*) ; 
 int sysctlbyname (char*,char const***,size_t*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ task_info (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*,int /*<<< orphan*/ *) ; 

__attribute__((constructor))
void init(int argc, const char *argv[], const char *envp[], const char *appl[], void *vars __attribute__((unused))) {
	int i;

	printf("argv = %p\n", argv);
	for (i=0; argv[i]; i++) {
		printf("argv[%2d] = %p %.100s%s\n", i, argv[i], argv[i], strlen(argv[i]) > 100 ? "..." : "");
	}
	printf("envp = %p\n", envp);
	for (i=0; envp[i]; i++) {
		printf("envp[%2d] = %p %.100s%s\n", i, envp[i], envp[i], strlen(envp[i]) > 100 ? "..." : "");
	}
	printf("appl = %p\n", appl);
	for (i=0; appl[i]; i++) {
		printf("appl[%2d] = %p %.100s%s\n", i, appl[i], appl[i], strlen(appl[i]) > 100 ? "..." : "");
	}
}

void printexecinfo(void)
{
	int ret;
	uint64_t stackaddr;
	size_t len = sizeof(stackaddr);
	const NXArchInfo *arch = NXGetArchInfoFromCpuType(_mh_execute_header.cputype, _mh_execute_header.cpusubtype & ~CPU_SUBTYPE_MASK);

	printf("executable load address = 0x%016llx\n", (uint64_t)(uintptr_t)&_mh_execute_header);
	printf("executable cputype 0x%08x cpusubtype 0x%08x (%s:%s)\n",
		   _mh_execute_header.cputype,
		   _mh_execute_header.cpusubtype,
		   arch ? arch->name : "unknown",
		   arch ? arch->description : "unknown");

	ret = sysctlbyname("kern.usrstack64", &stackaddr, &len, NULL, 0);
	if (ret == -1)
		err(1, "sysctlbyname");

	printf("          stack address = 0x%016llx\n", stackaddr);
}

void printdyldinfo(void)
{
	task_dyld_info_data_t info;
	mach_msg_type_number_t size = TASK_DYLD_INFO_COUNT;
	kern_return_t kret;
	struct dyld_all_image_infos *all_image_infos;
	
	kret = task_info(mach_task_self(), TASK_DYLD_INFO,
					 (void *)&info, &size);
	if (kret != KERN_SUCCESS)
		errx(1, "task_info: %s", mach_error_string(kret));

	all_image_infos = (struct dyld_all_image_infos *)(uintptr_t)info.all_image_info_addr;

	printf("      dyld load address = 0x%016llx\n", (uint64_t)(uintptr_t)all_image_infos->dyldImageLoadAddress);
	printf("     shared cache slide = 0x%016llx\n", (uint64_t)(uintptr_t)all_image_infos->sharedCacheSlide);

}

int main(int argc, char *argv[]) {

	printexecinfo();
	printdyldinfo();

	return 0;
}

