#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {scalar_t__ hwtstamp; scalar_t__ swtstamp; scalar_t__ tstampns; scalar_t__ tstamp; } ;
struct TYPE_3__ {int so_timestamping; scalar_t__ so_timestampns; scalar_t__ so_timestamp; } ;
struct test_case {int mask; char* name; int enabled; char* friendly_name; TYPE_2__ expected; TYPE_1__ sockopt; } ;
struct options {int so_timestamp; int so_timestampns; int so_timestamping; } ;
typedef  int /*<<< orphan*/  on ;

/* Variables and functions */
 int ARRAY_SIZE (struct test_case*) ; 
 int /*<<< orphan*/  SOL_SOCKET ; 
 int /*<<< orphan*/  SO_REUSEADDR ; 
 int /*<<< orphan*/  SO_TIMESTAMP ; 
 int /*<<< orphan*/  SO_TIMESTAMPING ; 
 int /*<<< orphan*/  SO_TIMESTAMPNS ; 
 void* atoi (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  errno ; 
 int /*<<< orphan*/  error (int,int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  free (char*) ; 
 char getopt_long (int,char**,char*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  long_options ; 
 char* malloc (void*) ; 
 int /*<<< orphan*/  memset (char*,char,void*) ; 
 void* op_size ; 
 int /*<<< orphan*/  optarg ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 scalar_t__ run_test_case (struct test_case,struct test_case) ; 
 scalar_t__ setsockopt (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int) ; 
 struct test_case* socket_types ; 
 struct test_case* sof_flags ; 
 struct test_case* test_cases ; 
 int write (int,char*,void*) ; 

void print_test_case(struct test_case *t)
{
	int f = 0;

	printf("sockopts {");
	if (t->sockopt.so_timestamp)
		printf(" SO_TIMESTAMP ");
	if (t->sockopt.so_timestampns)
		printf(" SO_TIMESTAMPNS ");
	if (t->sockopt.so_timestamping) {
		printf(" SO_TIMESTAMPING: {");
		for (f = 0; f < ARRAY_SIZE(sof_flags); f++)
			if (t->sockopt.so_timestamping & sof_flags[f].mask)
				printf(" %s |", sof_flags[f].name);
		printf("}");
	}
	printf("} expected cmsgs: {");
	if (t->expected.tstamp)
		printf(" SCM_TIMESTAMP ");
	if (t->expected.tstampns)
		printf(" SCM_TIMESTAMPNS ");
	if (t->expected.swtstamp || t->expected.hwtstamp) {
		printf(" SCM_TIMESTAMPING {");
		if (t->expected.swtstamp)
			printf("0");
		if (t->expected.swtstamp && t->expected.hwtstamp)
			printf(",");
		if (t->expected.hwtstamp)
			printf("2");
		printf("}");
	}
	printf("}\n");
}

void do_send(int src)
{
	int r;
	char *buf = malloc(op_size);

	memset(buf, 'z', op_size);
	r = write(src, buf, op_size);
	if (r < 0)
		error(1, errno, "Failed to sendmsg");

	free(buf);
}

void config_so_flags(int rcv, struct options o)
{
	int on = 1;

	if (setsockopt(rcv, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0)
		error(1, errno, "Failed to enable SO_REUSEADDR");

	if (o.so_timestamp &&
	    setsockopt(rcv, SOL_SOCKET, SO_TIMESTAMP,
		       &o.so_timestamp, sizeof(o.so_timestamp)) < 0)
		error(1, errno, "Failed to enable SO_TIMESTAMP");

	if (o.so_timestampns &&
	    setsockopt(rcv, SOL_SOCKET, SO_TIMESTAMPNS,
		       &o.so_timestampns, sizeof(o.so_timestampns)) < 0)
		error(1, errno, "Failed to enable SO_TIMESTAMPNS");

	if (o.so_timestamping &&
	    setsockopt(rcv, SOL_SOCKET, SO_TIMESTAMPING,
		       &o.so_timestamping, sizeof(o.so_timestamping)) < 0)
		error(1, errno, "Failed to set SO_TIMESTAMPING");
}

int main(int argc, char **argv)
{
	bool all_protocols = true;
	bool all_tests = true;
	int arg_index = 0;
	int failures = 0;
	int s, t;
	char opt;

	while ((opt = getopt_long(argc, argv, "", long_options,
				  &arg_index)) != -1) {
		switch (opt) {
		case 'l':
			for (t = 0; t < ARRAY_SIZE(test_cases); t++) {
				printf("%d\t", t);
				print_test_case(&test_cases[t]);
			}
			return 0;
		case 'n':
			t = atoi(optarg);
			if (t >= ARRAY_SIZE(test_cases))
				error(1, 0, "Invalid test case: %d", t);
			all_tests = false;
			test_cases[t].enabled = true;
			break;
		case 's':
			op_size = atoi(optarg);
			break;
		case 't':
			all_protocols = false;
			socket_types[2].enabled = true;
			break;
		case 'u':
			all_protocols = false;
			socket_types[1].enabled = true;
			break;
		case 'i':
			all_protocols = false;
			socket_types[0].enabled = true;
			break;
		default:
			error(1, 0, "Failed to parse parameters.");
		}
	}

	for (s = 0; s < ARRAY_SIZE(socket_types); s++) {
		if (!all_protocols && !socket_types[s].enabled)
			continue;

		printf("Testing %s...\n", socket_types[s].friendly_name);
		for (t = 0; t < ARRAY_SIZE(test_cases); t++) {
			if (!all_tests && !test_cases[t].enabled)
				continue;

			printf("Starting testcase %d...\n", t);
			if (run_test_case(socket_types[s], test_cases[t])) {
				failures++;
				printf("FAILURE in test case ");
				print_test_case(&test_cases[t]);
			}
		}
	}
	if (!failures)
		printf("PASSED.\n");
	return failures;
}

