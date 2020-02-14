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
typedef  int u32 ;
typedef  int /*<<< orphan*/  testir ;
struct pollfd {int fd; int /*<<< orphan*/  events; } ;
struct lirc_scancode {int scancode; int rc_proto; } ;
struct bpf_object {int dummy; } ;
typedef  int /*<<< orphan*/  lsc ;
typedef  int /*<<< orphan*/  buff ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  BPF_LIRC_MODE2 ; 
 int /*<<< orphan*/  BPF_PROG_TYPE_LIRC_MODE2 ; 
 scalar_t__ ENOENT ; 
 int LIRC_MODE_SCANCODE ; 
 int /*<<< orphan*/  LIRC_SET_REC_MODE ; 
 int O_NONBLOCK ; 
 int O_RDWR ; 
 int /*<<< orphan*/  POLLIN ; 
 int bpf_prog_attach (int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int bpf_prog_detach2 (int,int,int /*<<< orphan*/ ) ; 
 int bpf_prog_load (char*,int /*<<< orphan*/ ,struct bpf_object**,int*) ; 
 int bpf_prog_query (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int*,int*) ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fgets (char*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (char const*,char*) ; 
 scalar_t__ ioctl (int,int /*<<< orphan*/ ,int*) ; 
 int open (char*,int) ; 
 int /*<<< orphan*/  poll (struct pollfd*,int,int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int read (int,struct lirc_scancode*,int) ; 
 int sscanf (char*,char*,unsigned int*,unsigned int*) ; 
 char* strerror (scalar_t__) ; 
 int strlen (char*) ; 
 int write (int,int*,int) ; 

__attribute__((used)) static inline unsigned int bpf_num_possible_cpus(void)
{
	static const char *fcpu = "/sys/devices/system/cpu/possible";
	unsigned int start, end, possible_cpus = 0;
	char buff[128];
	FILE *fp;
	int len, n, i, j = 0;

	fp = fopen(fcpu, "r");
	if (!fp) {
		printf("Failed to open %s: '%s'!\n", fcpu, strerror(errno));
		exit(1);
	}

	if (!fgets(buff, sizeof(buff), fp)) {
		printf("Failed to read %s!\n", fcpu);
		exit(1);
	}

	len = strlen(buff);
	for (i = 0; i <= len; i++) {
		if (buff[i] == ',' || buff[i] == '\0') {
			buff[i] = '\0';
			n = sscanf(&buff[j], "%u-%u", &start, &end);
			if (n <= 0) {
				printf("Failed to retrieve # possible CPUs!\n");
				exit(1);
			} else if (n == 1) {
				end = start;
			}
			possible_cpus += end - start + 1;
			j = i + 1;
		}
	}

	fclose(fp);

	return possible_cpus;
}

int main(int argc, char **argv)
{
	struct bpf_object *obj;
	int ret, lircfd, progfd, mode;
	int testir = 0x1dead;
	u32 prog_ids[10], prog_flags[10], prog_cnt;

	if (argc != 2) {
		printf("Usage: %s /dev/lircN\n", argv[0]);
		return 2;
	}

	ret = bpf_prog_load("test_lirc_mode2_kern.o",
			    BPF_PROG_TYPE_LIRC_MODE2, &obj, &progfd);
	if (ret) {
		printf("Failed to load bpf program\n");
		return 1;
	}

	lircfd = open(argv[1], O_RDWR | O_NONBLOCK);
	if (lircfd == -1) {
		printf("failed to open lirc device %s: %m\n", argv[1]);
		return 1;
	}

	/* Let's try detach it before it was ever attached */
	ret = bpf_prog_detach2(progfd, lircfd, BPF_LIRC_MODE2);
	if (ret != -1 || errno != ENOENT) {
		printf("bpf_prog_detach2 not attached should fail: %m\n");
		return 1;
	}

	mode = LIRC_MODE_SCANCODE;
	if (ioctl(lircfd, LIRC_SET_REC_MODE, &mode)) {
		printf("failed to set rec mode: %m\n");
		return 1;
	}

	prog_cnt = 10;
	ret = bpf_prog_query(lircfd, BPF_LIRC_MODE2, 0, prog_flags, prog_ids,
			     &prog_cnt);
	if (ret) {
		printf("Failed to query bpf programs on lirc device: %m\n");
		return 1;
	}

	if (prog_cnt != 0) {
		printf("Expected nothing to be attached\n");
		return 1;
	}

	ret = bpf_prog_attach(progfd, lircfd, BPF_LIRC_MODE2, 0);
	if (ret) {
		printf("Failed to attach bpf to lirc device: %m\n");
		return 1;
	}

	/* Write raw IR */
	ret = write(lircfd, &testir, sizeof(testir));
	if (ret != sizeof(testir)) {
		printf("Failed to send test IR message: %m\n");
		return 1;
	}

	struct pollfd pfd = { .fd = lircfd, .events = POLLIN };
	struct lirc_scancode lsc;

	poll(&pfd, 1, 100);

	/* Read decoded IR */
	ret = read(lircfd, &lsc, sizeof(lsc));
	if (ret != sizeof(lsc)) {
		printf("Failed to read decoded IR: %m\n");
		return 1;
	}

	if (lsc.scancode != 0xdead || lsc.rc_proto != 64) {
		printf("Incorrect scancode decoded\n");
		return 1;
	}

	prog_cnt = 10;
	ret = bpf_prog_query(lircfd, BPF_LIRC_MODE2, 0, prog_flags, prog_ids,
			     &prog_cnt);
	if (ret) {
		printf("Failed to query bpf programs on lirc device: %m\n");
		return 1;
	}

	if (prog_cnt != 1) {
		printf("Expected one program to be attached\n");
		return 1;
	}

	/* Let's try detaching it now it is actually attached */
	ret = bpf_prog_detach2(progfd, lircfd, BPF_LIRC_MODE2);
	if (ret) {
		printf("bpf_prog_detach2: returned %m\n");
		return 1;
	}

	return 0;
}

