#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_2__ ;
typedef  struct TYPE_19__   TYPE_1__ ;
typedef  struct TYPE_18__   TYPE_11__ ;

/* Type definitions */
typedef  TYPE_1__* xnupost_test_t ;
typedef  scalar_t__ user_addr ;
typedef  scalar_t__ uint64_t ;
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  uint16_t ;
typedef  int /*<<< orphan*/  timebase ;
struct kcdata_descriptor {int dummy; } ;
typedef  int mach_vm_address_t ;
struct TYPE_20__ {int /*<<< orphan*/  member_1; int /*<<< orphan*/  member_0; } ;
typedef  TYPE_2__ mach_timebase_info_data_t ;
typedef  scalar_t__ kern_return_t ;
struct TYPE_19__ {TYPE_2__* xt_name; TYPE_2__ xt_end_time; TYPE_2__ xt_begin_time; TYPE_2__ xt_expected_retval; TYPE_2__ xt_retval; TYPE_2__ xt_test_num; TYPE_2__ xt_config; } ;
struct TYPE_18__ {int kcs_elem_offset; } ;

/* Variables and functions */
 int EACCES ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  KCDATA_BUFFER_BEGIN_XNUPOST_CONFIG ; 
 int /*<<< orphan*/  KCDATA_TYPE_TIMEBASE ; 
 int /*<<< orphan*/  KCFLAG_USE_COPYOUT ; 
 scalar_t__ KERN_NO_ACCESS ; 
 scalar_t__ KERN_RESOURCE_SHORTAGE ; 
 scalar_t__ KERN_SUCCESS ; 
 int MIN (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  OSVERSIZE ; 
 TYPE_2__* PE_boot_args () ; 
 int /*<<< orphan*/  STACKSHOT_KCTYPE_BOOTARGS ; 
 int /*<<< orphan*/  STACKSHOT_KCTYPE_OSVERSION ; 
 int /*<<< orphan*/  T_ASSERT_NOTNULL (scalar_t__*,char*) ; 
 int /*<<< orphan*/  T_LOG (char*) ; 
 int /*<<< orphan*/  XNUPOST_KCTYPE_TESTCONFIG ; 
 int /*<<< orphan*/  XNUPOST_TNAME_MAXLEN ; 
 TYPE_1__* bsd_post_tests ; 
 int bsd_post_tests_count ; 
 int /*<<< orphan*/  clock_timebase_info (TYPE_2__*) ; 
 scalar_t__ copyout (TYPE_2__*,int,int) ; 
 int /*<<< orphan*/  delay (int) ; 
 scalar_t__* kalloc (size_t) ; 
 TYPE_11__* kc_xnupost_test_def ; 
 int kc_xnupost_test_def_count ; 
 scalar_t__ kcdata_add_type_definition (struct kcdata_descriptor*,int /*<<< orphan*/ ,char*,TYPE_11__*,int) ; 
 scalar_t__ kcdata_get_memory_addr (struct kcdata_descriptor*,int /*<<< orphan*/ ,int,int*) ; 
 scalar_t__ kcdata_get_memory_addr_for_array (struct kcdata_descriptor*,int /*<<< orphan*/ ,int,int,int*) ; 
 scalar_t__ kcdata_memory_get_used_bytes (struct kcdata_descriptor*) ; 
 scalar_t__ kcdata_memory_static_init (struct kcdata_descriptor*,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int kcs_get_elem_size (TYPE_11__*) ; 
 scalar_t__ kernel_post_args ; 
 TYPE_1__* kernel_post_tests ; 
 int kernel_post_tests_count ; 
 int /*<<< orphan*/  kfree (scalar_t__*,size_t) ; 
 scalar_t__ last_loaded_timestamp ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 scalar_t__ strlen (TYPE_2__*) ; 
 int strnlen (TYPE_2__*,int /*<<< orphan*/ ) ; 
 TYPE_2__* version ; 
 int xnupost_list_tests (TYPE_1__*,int) ; 
 int /*<<< orphan*/  xnupost_reset_tests (TYPE_1__*,int) ; 
 int xnupost_run_tests (TYPE_1__*,int) ; 

int
bsd_list_tests()
{
	if (kernel_post_args == 0) {
		return 0;
	}

	uint64_t prev_load_time    = last_loaded_timestamp;
	int no_load_counter        = 5;
	int absolute_break_counter = 15;
	int delay_duration_usecs   = 300000; /* 0.3 second for kext loading to stabilize */

	while (no_load_counter > 0) {
		printf("bsd_list_tests:INFO waiting for %d usecs\n", delay_duration_usecs);
		printf("bsd_list_tests: prev: %llu current: %llu\n", prev_load_time, last_loaded_timestamp);

		delay(delay_duration_usecs);
		absolute_break_counter -= 1;

		if (absolute_break_counter <= 0) {
			printf("bsd_list_tests: WARNING: Waiting beyond normal time for stabilizing kext loading\n");
			break;
		}

		if (prev_load_time == last_loaded_timestamp) {
			no_load_counter -= 1;
			printf("bsd_list_tests: INFO: no new kexts loaded. remaining checks: %d\n", no_load_counter);
		}

		prev_load_time = last_loaded_timestamp;
	}

	return xnupost_list_tests(bsd_post_tests, bsd_post_tests_count);
}

int
bsd_do_post()
{
	return xnupost_run_tests(bsd_post_tests, bsd_post_tests_count);
}

kern_return_t
kalloc_test()
{
	uint64_t * data_ptr;
	size_t alloc_size;

	T_LOG("Running kalloc test.\n");

	alloc_size = sizeof(uint64_t);
	data_ptr = kalloc(alloc_size);
	T_ASSERT_NOTNULL(data_ptr, "kalloc sizeof(uint64_t) return not null");
	kfree(data_ptr, alloc_size);

	alloc_size = 3544;
	data_ptr = kalloc(alloc_size);
	T_ASSERT_NOTNULL(data_ptr, "kalloc 3544 return not null");
	kfree(data_ptr, alloc_size);

	return KERN_SUCCESS;
}

int
xnupost_copyout_test(xnupost_test_t t, mach_vm_address_t outaddr)
{
	/* code to copyout test config */
	int kret         = 0;
	uint32_t namelen = 0;

	kret = copyout(&t->xt_config, outaddr, sizeof(uint16_t));
	if (kret)
		return kret;
	outaddr += sizeof(uint16_t);

	kret = copyout(&t->xt_test_num, outaddr, sizeof(uint16_t));
	if (kret)
		return kret;
	outaddr += sizeof(uint16_t);

	kret = copyout(&t->xt_retval, outaddr, sizeof(uint32_t));
	if (kret)
		return kret;
	outaddr += sizeof(uint32_t);

	kret = copyout(&t->xt_expected_retval, outaddr, sizeof(uint32_t));
	if (kret)
		return kret;
	outaddr += sizeof(uint32_t);

	kret = copyout(&t->xt_begin_time, outaddr, sizeof(uint64_t));
	if (kret)
		return kret;
	outaddr += sizeof(uint64_t);

	kret = copyout(&t->xt_end_time, outaddr, sizeof(uint64_t));
	if (kret)
		return kret;
	outaddr += sizeof(uint64_t);

	namelen = strnlen(t->xt_name, XNUPOST_TNAME_MAXLEN);
	kret = copyout(t->xt_name, outaddr, namelen);
	if (kret)
		return kret;
	outaddr += namelen;

	return 0;
}

uint32_t
xnupost_get_estimated_testdata_size(void)
{
	uint32_t total_tests = bsd_post_tests_count + kernel_post_tests_count;
	uint32_t elem_size = kc_xnupost_test_def[kc_xnupost_test_def_count - 1].kcs_elem_offset +
	                     kcs_get_elem_size(&kc_xnupost_test_def[kc_xnupost_test_def_count - 1]);
	uint32_t retval = 1024; /* account for type definition and mach timebase */
	retval += 1024;         /* kernel version and boot-args string data */
	retval += (total_tests * elem_size);

	return retval;
}

int
xnupost_export_testdata(void * outp, uint32_t size, uint32_t * lenp)
{
	struct kcdata_descriptor kcd;
	mach_vm_address_t user_addr        = 0;
	mach_vm_address_t tmp_entry_addr   = 0;
	kern_return_t kret                 = 0;
	uint32_t i                         = 0;
	char kctype_name[32]               = "xnupost_test_config";
	mach_timebase_info_data_t timebase = {0, 0};
	uint32_t length_to_copy            = 0;

#define RET_IF_OP_FAIL                                                                                       \
	do {                                                                                                     \
		if (kret != KERN_SUCCESS) {                                                                          \
			return (kret == KERN_NO_ACCESS) ? EACCES : ((kret == KERN_RESOURCE_SHORTAGE) ? ENOMEM : EINVAL); \
		}                                                                                                    \
	} while (0)

	kret = kcdata_memory_static_init(&kcd, (mach_vm_address_t)outp, KCDATA_BUFFER_BEGIN_XNUPOST_CONFIG, size, KCFLAG_USE_COPYOUT);
	RET_IF_OP_FAIL;

	/* add mach timebase info */
	clock_timebase_info(&timebase);
	kret = kcdata_get_memory_addr(&kcd, KCDATA_TYPE_TIMEBASE, sizeof(timebase), &user_addr);
	RET_IF_OP_FAIL;
	kret = copyout(&timebase, user_addr, sizeof(timebase));
	RET_IF_OP_FAIL;

	/* save boot-args and osversion string */
	length_to_copy = MIN((uint32_t)(strlen(version) + 1), OSVERSIZE);
	kret           = kcdata_get_memory_addr(&kcd, STACKSHOT_KCTYPE_OSVERSION, length_to_copy, &user_addr);
	RET_IF_OP_FAIL;
	kret = copyout(&version[0], user_addr, length_to_copy);
	RET_IF_OP_FAIL;

	length_to_copy = MIN((uint32_t)(strlen(PE_boot_args()) + 1), OSVERSIZE);
	kret           = kcdata_get_memory_addr(&kcd, STACKSHOT_KCTYPE_BOOTARGS, length_to_copy, &user_addr);
	RET_IF_OP_FAIL;
	kret = copyout(PE_boot_args(), user_addr, length_to_copy);
	RET_IF_OP_FAIL;

	/* add type definition to buffer */
	kret = kcdata_add_type_definition(&kcd, XNUPOST_KCTYPE_TESTCONFIG, kctype_name, &kc_xnupost_test_def[0],
	                                  kc_xnupost_test_def_count);
	RET_IF_OP_FAIL;

	/* add the tests to buffer as array */
	uint32_t total_tests = bsd_post_tests_count + kernel_post_tests_count;
	uint32_t elem_size = kc_xnupost_test_def[kc_xnupost_test_def_count - 1].kcs_elem_offset +
	                     kcs_get_elem_size(&kc_xnupost_test_def[kc_xnupost_test_def_count - 1]);

	kret = kcdata_get_memory_addr_for_array(&kcd, XNUPOST_KCTYPE_TESTCONFIG, elem_size, total_tests, &user_addr);
	RET_IF_OP_FAIL;

	for (i = 0; i < bsd_post_tests_count; i++) {
		tmp_entry_addr = (mach_vm_address_t)((uint64_t)(user_addr) + (uint64_t)(i * elem_size));
		kret           = xnupost_copyout_test(&bsd_post_tests[i], tmp_entry_addr);
		RET_IF_OP_FAIL;
	}
	user_addr = (mach_vm_address_t)((uint64_t)(user_addr) + (uint64_t)(i * elem_size));

	for (i = 0; i < kernel_post_tests_count; i++) {
		tmp_entry_addr = (mach_vm_address_t)((uint64_t)(user_addr) + (uint64_t)(i * elem_size));
		kret           = xnupost_copyout_test(&kernel_post_tests[i], tmp_entry_addr);
		RET_IF_OP_FAIL;
	}

	if (kret == KERN_SUCCESS && lenp != NULL)
		*lenp = (uint32_t)kcdata_memory_get_used_bytes(&kcd);
	RET_IF_OP_FAIL;

#undef RET_IF_OP_FAIL
	return kret;
}

int
xnupost_reset_all_tests(void)
{
	xnupost_reset_tests(&bsd_post_tests[0], bsd_post_tests_count);
	xnupost_reset_tests(&kernel_post_tests[0], kernel_post_tests_count);
	return 0;
}

