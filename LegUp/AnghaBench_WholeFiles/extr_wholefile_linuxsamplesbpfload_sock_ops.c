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

/* Variables and functions */
 int /*<<< orphan*/  BPF_CGROUP_SOCK_OPS ; 
 int /*<<< orphan*/  O_DIRECTORY ; 
 int /*<<< orphan*/  O_RDONLY ; 
 char* bpf_log_buf ; 
 int bpf_prog_attach (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int bpf_prog_detach (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  errno ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*) ; 
 scalar_t__ load_bpf_file (char*) ; 
 int open (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/ * prog_fd ; 
 int /*<<< orphan*/  read_trace_pipe () ; 
 int /*<<< orphan*/  sprintf (char*,char*,char*) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  strcmp (char*,char*) ; 
 int /*<<< orphan*/  strcpy (char*,char*) ; 
 char* strerror (int /*<<< orphan*/ ) ; 
 int strlen (char*) ; 

__attribute__((used)) static void usage(char *pname)
{
	printf("USAGE:\n  %s [-l] <cg-path> <prog filename>\n", pname);
	printf("\tLoad and attach a sock_ops program to the specified "
	       "cgroup\n");
	printf("\tIf \"-l\" is used, the program will continue to run\n");
	printf("\tprinting the BPF log buffer\n");
	printf("\tIf the specified filename does not end in \".o\", it\n");
	printf("\tappends \"_kern.o\" to the name\n");
	printf("\n");
	printf("  %s -r <cg-path>\n", pname);
	printf("\tDetaches the currently attached sock_ops program\n");
	printf("\tfrom the specified cgroup\n");
	printf("\n");
	exit(1);
}

int main(int argc, char **argv)
{
	int logFlag = 0;
	int error = 0;
	char *cg_path;
	char fn[500];
	char *prog;
	int cg_fd;

	if (argc < 3)
		usage(argv[0]);

	if (!strcmp(argv[1], "-r")) {
		cg_path = argv[2];
		cg_fd = open(cg_path, O_DIRECTORY, O_RDONLY);
		error = bpf_prog_detach(cg_fd, BPF_CGROUP_SOCK_OPS);
		if (error) {
			printf("ERROR: bpf_prog_detach: %d (%s)\n",
			       error, strerror(errno));
			return 2;
		}
		return 0;
	} else if (!strcmp(argv[1], "-h")) {
		usage(argv[0]);
	} else if (!strcmp(argv[1], "-l")) {
		logFlag = 1;
		if (argc < 4)
			usage(argv[0]);
	}

	prog = argv[argc - 1];
	cg_path = argv[argc - 2];
	if (strlen(prog) > 480) {
		fprintf(stderr, "ERROR: program name too long (> 480 chars)\n");
		return 3;
	}
	cg_fd = open(cg_path, O_DIRECTORY, O_RDONLY);

	if (!strcmp(prog + strlen(prog)-2, ".o"))
		strcpy(fn, prog);
	else
		sprintf(fn, "%s_kern.o", prog);
	if (logFlag)
		printf("loading bpf file:%s\n", fn);
	if (load_bpf_file(fn)) {
		printf("ERROR: load_bpf_file failed for: %s\n", fn);
		printf("%s", bpf_log_buf);
		return 4;
	}
	if (logFlag)
		printf("TCP BPF Loaded %s\n", fn);

	error = bpf_prog_attach(prog_fd[0], cg_fd, BPF_CGROUP_SOCK_OPS, 0);
	if (error) {
		printf("ERROR: bpf_prog_attach: %d (%s)\n",
		       error, strerror(errno));
		return 5;
	} else if (logFlag) {
		read_trace_pipe();
	}

	return error;
}

