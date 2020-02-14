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
typedef  scalar_t__ uint64_t ;
struct TYPE_3__ {scalar_t__* dir; char* name; scalar_t__ sig_head; scalar_t__ sig_tail; int /*<<< orphan*/  (* func ) (char*,int*) ;} ;
typedef  TYPE_1__ case_t ;

/* Variables and functions */
 scalar_t__ __start_case_data ; 
 scalar_t__ __start_case_data_assessment ; 
 scalar_t__ __stop_case_data ; 
 scalar_t__ __stop_case_data_assessment ; 
 int /*<<< orphan*/  __test_case_setup () ; 
 int /*<<< orphan*/  __test_case_teardown () ; 
 int /*<<< orphan*/  chdir (char*) ; 
 int /*<<< orphan*/  fflush (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fileno (int /*<<< orphan*/ ) ; 
 char* getcwd (char*,int) ; 
 scalar_t__ isatty (int /*<<< orphan*/ ) ; 
 int printf (char*,...) ; 
 int /*<<< orphan*/  putchar (char) ; 
 int /*<<< orphan*/  stdout ; 
 scalar_t__ strcmp (scalar_t__*,char*) ; 
 size_t strlen (char const* const) ; 
 char* strstr (char*,char const*) ; 
 int /*<<< orphan*/  stub1 (char*,int*) ; 

__attribute__((used)) static int case_print_hi(char* str, const char* const hi)
{
	if (!hi)
		return printf("%s", str);
	const size_t hilen = strlen(hi);
	char* savestr = strstr(str, hi);
	int nchr = 0;
	while (savestr)
	{
		for (;str < savestr; ++str, ++nchr)
			putchar(str[0]);
		nchr += printf("\033[7m%s\033[0m", hi); // decorate with underline.
		str += hilen;
		savestr = strstr(str, hi);
	}
	nchr += printf("%s", str);
	return nchr;
}

__attribute__((used)) static void case_run(case_t* test_case, const char* const match_test, int i, int total, int* pass, int* skip, int* fail)
{
	// Change the current directory.
	if (test_case->dir && test_case->dir[0] != 0 && strcmp(test_case->dir, ".") != 0)
		chdir(test_case->dir);
	int clr = 0;
	if (isatty(fileno(stdout)))
	{
		clr += printf("\033[0;34m[%d/%d]\033[0;0m \033[1;33m[RUN]\033[0;0m ", i + 1, total);
		clr += case_print_hi(test_case->name, match_test);
		clr += printf(" ...");
	} else
		clr += printf("[%d/%d] [RUN] %s ...", i + 1, total, test_case->name);
	fflush(stdout);
	int result = 0;
	test_case->func(test_case->name, &result);
	if (result == 0)
	{
		(*pass)++;
		for (; clr > 0; --clr)
			printf("\b");
		if (isatty(fileno(stdout)))
		{
			printf("\r\033[0;34m[%d/%d]\033[0;0m \033[1;32m[PASS]\033[0;0m ", i + 1, total);
			case_print_hi(test_case->name, match_test);
			printf("    \n");
		} else
			printf("\r[%d/%d] [PASS] %s    \n", i + 1, total, test_case->name);
	} else if (result == -2) {
		(*skip)++;
		if (isatty(fileno(stdout)))
		{
			printf("\n\033[0;34m[%d/%d]\033[0;0m \033[1;32m[SKIP]\033[0;0m ", i + 1, total);
			case_print_hi(test_case->name, match_test);
			printf("\n");
		} else
			printf("\n[%d/%d] [SKIP] %s\n", i + 1, total, test_case->name);
	} else {
		(*fail)++;
		if (isatty(fileno(stdout)))
		{
			printf("\n\033[0;34m[%d/%d]\033[0;0m \033[1;31m[FAIL]\033[0;0m ", i + 1, total);
			case_print_hi(test_case->name, match_test);
			printf("\n");
		} else
			printf("\n[%d/%d] [FAIL] %s\n", i + 1, total, test_case->name);
	}
}

__attribute__((used)) static void case_conclude(int pass, int skip, int fail)
{
	if (isatty(fileno(stdout)))
	{
		if (skip > 0)
		{
			if (fail == 0)
				printf("\033[0;32mall test case(s) passed, %d test case(s) skipped, congratulations!\033[0;0m\n", skip);
			else
				printf("\033[0;31m%d of %d test case(s) passed, %d test case(s) skipped\033[0;0m\n", pass, fail + pass, skip);
		} else {
			if (fail == 0)
				printf("\033[0;32mall test case(s) passed, congratulations!\033[0;0m\n");
			else
				printf("\033[0;31m%d of %d test case(s) passed\033[0;0m\n", pass, fail + pass);
		}
	} else {
		if (skip > 0)
		{
			if (fail == 0)
				printf("all test case(s) passed, %d test case(s) skipped, congratulations!\n", skip);
			else
				printf("%d of %d test case(s) passed, %d test case(s) skipped\n", pass, fail + pass, skip);
		} else {
			if (fail == 0)
				printf("all test case(s) passed, congratulations!\n");
			else
				printf("%d of %d test case(s) passed\n", pass, fail + pass);
		}
	}
}

int main(int argc, char** argv)
{
	int case_size = (intptr_t)__stop_case_data_assessment - (intptr_t)__start_case_data_assessment;
	int test_size = (intptr_t)__stop_case_data - (intptr_t)__start_case_data;
	char buf[1024];
	char* cur_dir = getcwd(buf, 1024);
	static uint64_t the_sig = 0x883253372849284B;
	int scan_mode = (test_size % case_size != 0);
	const char* match_test = (argc == 2) ? argv[1] : 0;
	int i, total = 0;
	if (!scan_mode)
		total = test_size / case_size;
	for (i = 0; i < total; i++)
	{
		case_t* test_case = (case_t*)((unsigned char*)__start_case_data + i * case_size);
		// If it doesn't match well, fallback to scan mode.
		if (test_case->sig_head != the_sig || test_case->sig_tail != the_sig + 2)
		{
			scan_mode = 1;
			break;
		}
	}
	int len, pass = 0, skip = 0, fail = 0;
	// In scan mode, we will scan the whole section for a matching test case.
	if (scan_mode)
	{
		total = 0;
		len = (intptr_t)__stop_case_data - (intptr_t)__start_case_data - sizeof(case_t) + 1;
		for (i = 0; i < len; i++)
		{
			case_t* test_case = (case_t*)((unsigned char*)__start_case_data + i);
			if (test_case->sig_head == the_sig && test_case->sig_tail == the_sig + 2 &&
				(!match_test || strstr(test_case->name, match_test)))
				total++;
		}
	}
	if (__test_case_setup)
		__test_case_setup();
	if (scan_mode)
	{
		int j = 0;
		for (i = 0; i < len; i++)
		{
			case_t* test_case = (case_t*)((unsigned char*)__start_case_data + i);
			if (test_case->sig_head == the_sig && test_case->sig_tail == the_sig + 2 &&
				(!match_test || strstr(test_case->name, match_test)))
			{
				case_run(test_case, match_test, j++, total, &pass, &skip, &fail);
				chdir(cur_dir);
			}
		}
	} else {
		int matched_total = match_test ? 0 : total;
		if (match_test)
			for (i = 0; i < total; i++)
			{
				case_t* test_case = (case_t*)((unsigned char*)__start_case_data + i * case_size);
				if (strstr(test_case->name, match_test))
					matched_total++;
			}
		int j = 0;
		// Simple case, I don't need to scan the data section.
		for (i = 0; i < total; i++)
		{
			case_t* test_case = (case_t*)((unsigned char*)__start_case_data + i * case_size);
			if (!match_test || strstr(test_case->name, match_test))
				case_run(test_case, match_test, j++, matched_total, &pass, &skip, &fail);
			chdir(cur_dir);
		}
	}
	if (__test_case_teardown)
		__test_case_teardown();
	case_conclude(pass, skip, fail);
	return fail;
}

