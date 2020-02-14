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
typedef  int uint32_t ;
struct TYPE_2__ {int* s6_addr16; } ;
struct sockaddr_in6 {int sin6_port; TYPE_1__ sin6_addr; int /*<<< orphan*/  sin6_family; } ;
struct sockaddr {int dummy; } ;
struct rlimit {int /*<<< orphan*/  member_1; int /*<<< orphan*/  member_0; } ;
struct bpf_map_info {int id; } ;
typedef  int /*<<< orphan*/  info ;
typedef  int /*<<< orphan*/  in6 ;
typedef  int /*<<< orphan*/  filename ;

/* Variables and functions */
 int /*<<< orphan*/  AF_INET6 ; 
 int A_OF_PORT_A ; 
 int /*<<< orphan*/  BPF_ANY ; 
 int /*<<< orphan*/  BPF_NOEXIST ; 
 scalar_t__ EBADF ; 
 int H_OF_PORT_A ; 
 int H_OF_PORT_H ; 
 int INLINE_RESULT_H ; 
 int NR_TESTS ; 
 int PORT_A ; 
 int PORT_H ; 
 int REG_RESULT_H ; 
 int /*<<< orphan*/  RLIMIT_MEMLOCK ; 
 int /*<<< orphan*/  RLIM_INFINITY ; 
 int /*<<< orphan*/  assert (int) ; 
 char* bpf_log_buf ; 
 int /*<<< orphan*/  bpf_map_delete_elem (int,int*) ; 
 int bpf_map_lookup_elem (int,int*,int*) ; 
 int bpf_map_update_elem (int,int*,int*,int /*<<< orphan*/ ) ; 
 int bpf_obj_get_info_by_fd (int,struct bpf_map_info*,int*) ; 
 int connect (int,struct sockaddr*,int) ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  exit (int) ; 
 scalar_t__ load_bpf_file (char*) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int rand () ; 
 int /*<<< orphan*/  setrlimit (int /*<<< orphan*/ ,struct rlimit*) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,char*) ; 
 char** test_names ; 

__attribute__((used)) static void check_map_id(int inner_map_fd, int map_in_map_fd, uint32_t key)
{
	struct bpf_map_info info = {};
	uint32_t info_len = sizeof(info);
	int ret, id;

	ret = bpf_obj_get_info_by_fd(inner_map_fd, &info, &info_len);
	assert(!ret);

	ret = bpf_map_lookup_elem(map_in_map_fd, &key, &id);
	assert(!ret);
	assert(id == info.id);
}

__attribute__((used)) static void populate_map(uint32_t port_key, int magic_result)
{
	int ret;

	ret = bpf_map_update_elem(PORT_A, &port_key, &magic_result, BPF_ANY);
	assert(!ret);

	ret = bpf_map_update_elem(PORT_H, &port_key, &magic_result,
				  BPF_NOEXIST);
	assert(!ret);

	ret = bpf_map_update_elem(A_OF_PORT_A, &port_key, &PORT_A, BPF_ANY);
	assert(!ret);
	check_map_id(PORT_A, A_OF_PORT_A, port_key);

	ret = bpf_map_update_elem(H_OF_PORT_A, &port_key, &PORT_A, BPF_NOEXIST);
	assert(!ret);
	check_map_id(PORT_A, H_OF_PORT_A, port_key);

	ret = bpf_map_update_elem(H_OF_PORT_H, &port_key, &PORT_H, BPF_NOEXIST);
	assert(!ret);
	check_map_id(PORT_H, H_OF_PORT_H, port_key);
}

__attribute__((used)) static void test_map_in_map(void)
{
	struct sockaddr_in6 in6 = { .sin6_family = AF_INET6 };
	uint32_t result_key = 0, port_key;
	int result, inline_result;
	int magic_result = 0xfaceb00c;
	int ret;
	int i;

	port_key = rand() & 0x00FF;
	populate_map(port_key, magic_result);

	in6.sin6_addr.s6_addr16[0] = 0xdead;
	in6.sin6_addr.s6_addr16[1] = 0xbeef;
	in6.sin6_port = port_key;

	for (i = 0; i < NR_TESTS; i++) {
		printf("%s: ", test_names[i]);

		in6.sin6_addr.s6_addr16[7] = i;
		ret = connect(-1, (struct sockaddr *)&in6, sizeof(in6));
		assert(ret == -1 && errno == EBADF);

		ret = bpf_map_lookup_elem(REG_RESULT_H, &result_key, &result);
		assert(!ret);

		ret = bpf_map_lookup_elem(INLINE_RESULT_H, &result_key,
					  &inline_result);
		assert(!ret);

		if (result != magic_result || inline_result != magic_result) {
			printf("Error. result:%d inline_result:%d\n",
			       result, inline_result);
			exit(1);
		}

		bpf_map_delete_elem(REG_RESULT_H, &result_key);
		bpf_map_delete_elem(INLINE_RESULT_H, &result_key);

		printf("Pass\n");
	}
}

int main(int argc, char **argv)
{
	struct rlimit r = {RLIM_INFINITY, RLIM_INFINITY};
	char filename[256];

	assert(!setrlimit(RLIMIT_MEMLOCK, &r));

	snprintf(filename, sizeof(filename), "%s_kern.o", argv[0]);

	if (load_bpf_file(filename)) {
		printf("%s", bpf_log_buf);
		return 1;
	}

	test_map_in_map();

	return 0;
}

