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
struct sockaddr_storage {int expected_attach_type; size_t insns_cnt; char* license; struct bpf_insn const* insns; int /*<<< orphan*/  prog_type; } ;
struct sockaddr_in6 {int sin6_family; int /*<<< orphan*/  sin6_addr; void* sin6_port; } ;
struct sockaddr_in {int sin_family; int /*<<< orphan*/  sin_addr; void* sin_port; } ;
struct sockaddr {int dummy; } ;
struct sock_test {char* descr; int expected_attach_type; scalar_t__ result; int attach_type; int domain; int type; char* ip; unsigned short port; struct bpf_insn const* insns; } ;
struct rlimit {scalar_t__ rlim_max; scalar_t__ rlim_cur; } ;
struct bpf_load_program_attr {int expected_attach_type; size_t insns_cnt; char* license; struct bpf_insn const* insns; int /*<<< orphan*/  prog_type; } ;
typedef  struct bpf_insn {scalar_t__ code; scalar_t__ imm; } const bpf_insn ;
typedef  int socklen_t ;
typedef  enum bpf_attach_type { ____Placeholder_bpf_attach_type } bpf_attach_type ;
typedef  int /*<<< orphan*/  buff ;
typedef  int /*<<< orphan*/  addr ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int AF_INET ; 
 int AF_INET6 ; 
 int ARRAY_SIZE (struct sock_test*) ; 
 scalar_t__ ATTACH_REJECT ; 
 scalar_t__ BIND_REJECT ; 
 int /*<<< orphan*/  BPF_F_ALLOW_OVERRIDE ; 
 int /*<<< orphan*/  BPF_LOG_BUF_SIZE ; 
 int /*<<< orphan*/  BPF_PROG_TYPE_CGROUP_SOCK ; 
 int /*<<< orphan*/  CG_PATH ; 
 scalar_t__ EPERM ; 
 scalar_t__ LOAD_REJECT ; 
 int MAX_INSNS ; 
 int /*<<< orphan*/  RLIMIT_MEMLOCK ; 
 scalar_t__ RLIM_INFINITY ; 
 scalar_t__ SUCCESS ; 
 int bind (int,struct sockaddr const*,int) ; 
 int bpf_load_program_xattr (struct sockaddr_storage*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bpf_log_buf ; 
 int bpf_prog_attach (int,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bpf_prog_detach (int,int) ; 
 int /*<<< orphan*/  cleanup_cgroup_environment () ; 
 int /*<<< orphan*/  close (int) ; 
 int create_and_get_cgroup (int /*<<< orphan*/ ) ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fgets (char*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (char const*,char*) ; 
 int /*<<< orphan*/  getrlimit (int /*<<< orphan*/ ,struct rlimit*) ; 
 void* htons (unsigned short) ; 
 int inet_pton (int,char const*,void*) ; 
 scalar_t__ join_cgroup (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct sockaddr_storage*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  perror (char*) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 scalar_t__ setrlimit (int /*<<< orphan*/ ,struct rlimit*) ; 
 scalar_t__ setup_cgroup_environment () ; 
 int socket (int,int,int /*<<< orphan*/ ) ; 
 int sscanf (char*,char*,unsigned int*,unsigned int*) ; 
 char* strerror (scalar_t__) ; 
 int strlen (char*) ; 
 struct sock_test* tests ; 

__attribute__((used)) static  __attribute__((constructor)) void bpf_rlimit_ctor(void)
{
	struct rlimit rlim_old, rlim_new = {
		.rlim_cur	= RLIM_INFINITY,
		.rlim_max	= RLIM_INFINITY,
	};

	getrlimit(RLIMIT_MEMLOCK, &rlim_old);
	/* For the sake of running the test cases, we temporarily
	 * set rlimit to infinity in order for kernel to focus on
	 * errors from actual test cases and not getting noise
	 * from hitting memlock limits. The limit is on per-process
	 * basis and not a global one, hence destructor not really
	 * needed here.
	 */
	if (setrlimit(RLIMIT_MEMLOCK, &rlim_new) < 0) {
		perror("Unable to lift memlock rlimit");
		/* Trying out lower limit, but expect potential test
		 * case failures from this!
		 */
		rlim_new.rlim_cur = rlim_old.rlim_cur + (1UL << 20);
		rlim_new.rlim_max = rlim_old.rlim_max + (1UL << 20);
		setrlimit(RLIMIT_MEMLOCK, &rlim_new);
	}
}

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

__attribute__((used)) static size_t probe_prog_length(const struct bpf_insn *fp)
{
	size_t len;

	for (len = MAX_INSNS - 1; len > 0; --len)
		if (fp[len].code != 0 || fp[len].imm != 0)
			break;
	return len + 1;
}

__attribute__((used)) static int load_sock_prog(const struct bpf_insn *prog,
			  enum bpf_attach_type attach_type)
{
	struct bpf_load_program_attr attr;

	memset(&attr, 0, sizeof(struct bpf_load_program_attr));
	attr.prog_type = BPF_PROG_TYPE_CGROUP_SOCK;
	attr.expected_attach_type = attach_type;
	attr.insns = prog;
	attr.insns_cnt = probe_prog_length(attr.insns);
	attr.license = "GPL";

	return bpf_load_program_xattr(&attr, bpf_log_buf, BPF_LOG_BUF_SIZE);
}

__attribute__((used)) static int attach_sock_prog(int cgfd, int progfd,
			    enum bpf_attach_type attach_type)
{
	return bpf_prog_attach(progfd, cgfd, attach_type, BPF_F_ALLOW_OVERRIDE);
}

__attribute__((used)) static int bind_sock(int domain, int type, const char *ip, unsigned short port)
{
	struct sockaddr_storage addr;
	struct sockaddr_in6 *addr6;
	struct sockaddr_in *addr4;
	int sockfd = -1;
	socklen_t len;
	int err = 0;

	sockfd = socket(domain, type, 0);
	if (sockfd < 0)
		goto err;

	memset(&addr, 0, sizeof(addr));

	if (domain == AF_INET) {
		len = sizeof(struct sockaddr_in);
		addr4 = (struct sockaddr_in *)&addr;
		addr4->sin_family = domain;
		addr4->sin_port = htons(port);
		if (inet_pton(domain, ip, (void *)&addr4->sin_addr) != 1)
			goto err;
	} else if (domain == AF_INET6) {
		len = sizeof(struct sockaddr_in6);
		addr6 = (struct sockaddr_in6 *)&addr;
		addr6->sin6_family = domain;
		addr6->sin6_port = htons(port);
		if (inet_pton(domain, ip, (void *)&addr6->sin6_addr) != 1)
			goto err;
	} else {
		goto err;
	}

	if (bind(sockfd, (const struct sockaddr *)&addr, len) == -1)
		goto err;

	goto out;
err:
	err = -1;
out:
	close(sockfd);
	return err;
}

__attribute__((used)) static int run_test_case(int cgfd, const struct sock_test *test)
{
	int progfd = -1;
	int err = 0;

	printf("Test case: %s .. ", test->descr);
	progfd = load_sock_prog(test->insns, test->expected_attach_type);
	if (progfd < 0) {
		if (test->result == LOAD_REJECT)
			goto out;
		else
			goto err;
	}

	if (attach_sock_prog(cgfd, progfd, test->attach_type) == -1) {
		if (test->result == ATTACH_REJECT)
			goto out;
		else
			goto err;
	}

	if (bind_sock(test->domain, test->type, test->ip, test->port) == -1) {
		/* sys_bind() may fail for different reasons, errno has to be
		 * checked to confirm that BPF program rejected it.
		 */
		if (test->result == BIND_REJECT && errno == EPERM)
			goto out;
		else
			goto err;
	}


	if (test->result != SUCCESS)
		goto err;

	goto out;
err:
	err = -1;
out:
	/* Detaching w/o checking return code: best effort attempt. */
	if (progfd != -1)
		bpf_prog_detach(cgfd, test->attach_type);
	close(progfd);
	printf("[%s]\n", err ? "FAIL" : "PASS");
	return err;
}

__attribute__((used)) static int run_tests(int cgfd)
{
	int passes = 0;
	int fails = 0;
	int i;

	for (i = 0; i < ARRAY_SIZE(tests); ++i) {
		if (run_test_case(cgfd, &tests[i]))
			++fails;
		else
			++passes;
	}
	printf("Summary: %d PASSED, %d FAILED\n", passes, fails);
	return fails ? -1 : 0;
}

int main(int argc, char **argv)
{
	int cgfd = -1;
	int err = 0;

	if (setup_cgroup_environment())
		goto err;

	cgfd = create_and_get_cgroup(CG_PATH);
	if (!cgfd)
		goto err;

	if (join_cgroup(CG_PATH))
		goto err;

	if (run_tests(cgfd))
		goto err;

	goto out;
err:
	err = -1;
out:
	close(cgfd);
	cleanup_cgroup_environment();
	return err;
}

