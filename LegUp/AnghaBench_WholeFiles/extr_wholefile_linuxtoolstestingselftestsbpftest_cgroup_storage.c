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
typedef  int /*<<< orphan*/  value ;
struct rlimit {scalar_t__ rlim_max; scalar_t__ rlim_cur; } ;
struct bpf_insn {int imm; } ;
struct bpf_cgroup_storage_key {int dummy; } ;
typedef  int /*<<< orphan*/  prog ;
typedef  int /*<<< orphan*/  key ;

/* Variables and functions */
 struct bpf_insn BPF_ALU64_IMM (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  BPF_AND ; 
 int BPF_CALL ; 
 int /*<<< orphan*/  BPF_CGROUP_INET_EGRESS ; 
 int /*<<< orphan*/  BPF_DW ; 
 struct bpf_insn BPF_EXIT_INSN () ; 
 int /*<<< orphan*/  BPF_FUNC_get_local_storage ; 
 int BPF_JMP ; 
 struct bpf_insn BPF_LDX_MEM (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct bpf_insn BPF_LD_MAP_FD (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BPF_LOG_BUF_SIZE ; 
 int /*<<< orphan*/  BPF_MAP_TYPE_CGROUP_STORAGE ; 
 struct bpf_insn BPF_MOV64_IMM (int /*<<< orphan*/ ,int) ; 
 struct bpf_insn BPF_MOV64_REG (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BPF_PROG_TYPE_CGROUP_SKB ; 
 struct bpf_insn BPF_RAW_INSN (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BPF_REG_0 ; 
 int /*<<< orphan*/  BPF_REG_1 ; 
 int /*<<< orphan*/  BPF_REG_2 ; 
 struct bpf_insn BPF_STX_XADD (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BPF_W ; 
 int EXIT_FAILURE ; 
 int /*<<< orphan*/  RLIMIT_MEMLOCK ; 
 scalar_t__ RLIM_INFINITY ; 
 int /*<<< orphan*/  TEST_CGROUP ; 
 int /*<<< orphan*/  assert (int) ; 
 int bpf_create_map (int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int bpf_load_program (int /*<<< orphan*/ ,struct bpf_insn*,size_t,char*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 char* bpf_log_buf ; 
 scalar_t__ bpf_map_get_next_key (int,int /*<<< orphan*/ *,struct bpf_cgroup_storage_key*) ; 
 scalar_t__ bpf_map_lookup_elem (int,struct bpf_cgroup_storage_key*,unsigned long long*) ; 
 scalar_t__ bpf_map_update_elem (int,struct bpf_cgroup_storage_key*,unsigned long long*,int /*<<< orphan*/ ) ; 
 scalar_t__ bpf_prog_attach (int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cleanup_cgroup_environment () ; 
 int create_and_get_cgroup (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  errno ; 
 int /*<<< orphan*/  getrlimit (int /*<<< orphan*/ ,struct rlimit*) ; 
 scalar_t__ join_cgroup (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  perror (char*) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 scalar_t__ setrlimit (int /*<<< orphan*/ ,struct rlimit*) ; 
 scalar_t__ setup_cgroup_environment () ; 
 char* strerror (int /*<<< orphan*/ ) ; 
 int system (char*) ; 

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

int main(int argc, char **argv)
{
	struct bpf_insn prog[] = {
		BPF_LD_MAP_FD(BPF_REG_1, 0), /* map fd */
		BPF_MOV64_IMM(BPF_REG_2, 0), /* flags, not used */
		BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0,
			     BPF_FUNC_get_local_storage),
		BPF_MOV64_IMM(BPF_REG_1, 1),
		BPF_STX_XADD(BPF_DW, BPF_REG_0, BPF_REG_1, 0),
		BPF_LDX_MEM(BPF_W, BPF_REG_1, BPF_REG_0, 0),
		BPF_ALU64_IMM(BPF_AND, BPF_REG_1, 0x1),
		BPF_MOV64_REG(BPF_REG_0, BPF_REG_1),
		BPF_EXIT_INSN(),
	};
	size_t insns_cnt = sizeof(prog) / sizeof(struct bpf_insn);
	int error = EXIT_FAILURE;
	int map_fd, prog_fd, cgroup_fd;
	struct bpf_cgroup_storage_key key;
	unsigned long long value;

	map_fd = bpf_create_map(BPF_MAP_TYPE_CGROUP_STORAGE, sizeof(key),
				sizeof(value), 0, 0);
	if (map_fd < 0) {
		printf("Failed to create map: %s\n", strerror(errno));
		goto out;
	}

	prog[0].imm = map_fd;
	prog_fd = bpf_load_program(BPF_PROG_TYPE_CGROUP_SKB,
				   prog, insns_cnt, "GPL", 0,
				   bpf_log_buf, BPF_LOG_BUF_SIZE);
	if (prog_fd < 0) {
		printf("Failed to load bpf program: %s\n", bpf_log_buf);
		goto out;
	}

	if (setup_cgroup_environment()) {
		printf("Failed to setup cgroup environment\n");
		goto err;
	}

	/* Create a cgroup, get fd, and join it */
	cgroup_fd = create_and_get_cgroup(TEST_CGROUP);
	if (!cgroup_fd) {
		printf("Failed to create test cgroup\n");
		goto err;
	}

	if (join_cgroup(TEST_CGROUP)) {
		printf("Failed to join cgroup\n");
		goto err;
	}

	/* Attach the bpf program */
	if (bpf_prog_attach(prog_fd, cgroup_fd, BPF_CGROUP_INET_EGRESS, 0)) {
		printf("Failed to attach bpf program\n");
		goto err;
	}

	if (bpf_map_get_next_key(map_fd, NULL, &key)) {
		printf("Failed to get the first key in cgroup storage\n");
		goto err;
	}

	if (bpf_map_lookup_elem(map_fd, &key, &value)) {
		printf("Failed to lookup cgroup storage\n");
		goto err;
	}

	/* Every second packet should be dropped */
	assert(system("ping localhost -c 1 -W 1 -q > /dev/null") == 0);
	assert(system("ping localhost -c 1 -W 1 -q > /dev/null"));
	assert(system("ping localhost -c 1 -W 1 -q > /dev/null") == 0);

	/* Check the counter in the cgroup local storage */
	if (bpf_map_lookup_elem(map_fd, &key, &value)) {
		printf("Failed to lookup cgroup storage\n");
		goto err;
	}

	if (value != 3) {
		printf("Unexpected data in the cgroup storage: %llu\n", value);
		goto err;
	}

	/* Bump the counter in the cgroup local storage */
	value++;
	if (bpf_map_update_elem(map_fd, &key, &value, 0)) {
		printf("Failed to update the data in the cgroup storage\n");
		goto err;
	}

	/* Every second packet should be dropped */
	assert(system("ping localhost -c 1 -W 1 -q > /dev/null") == 0);
	assert(system("ping localhost -c 1 -W 1 -q > /dev/null"));
	assert(system("ping localhost -c 1 -W 1 -q > /dev/null") == 0);

	/* Check the final value of the counter in the cgroup local storage */
	if (bpf_map_lookup_elem(map_fd, &key, &value)) {
		printf("Failed to lookup the cgroup storage\n");
		goto err;
	}

	if (value != 7) {
		printf("Unexpected data in the cgroup storage: %llu\n", value);
		goto err;
	}

	error = 0;
	printf("test_cgroup_storage:PASS\n");

err:
	cleanup_cgroup_environment();

out:
	return error;
}

