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
struct xt_mtdtor_param {struct xt_bpf_info_v1* matchinfo; } ;
struct xt_mtchk_param {struct xt_bpf_info_v1* matchinfo; } ;
struct xt_bpf_info_v1 {scalar_t__ bpf_program_num_elem; scalar_t__ mode; int fd; char* path; struct bpf_prog* filter; struct sock_filter* bpf_program; } ;
struct xt_bpf_info {scalar_t__ bpf_program_num_elem; scalar_t__ mode; int fd; char* path; struct bpf_prog* filter; struct sock_filter* bpf_program; } ;
struct xt_action_param {struct xt_bpf_info_v1* matchinfo; } ;
struct sock_fprog_kern {struct sock_filter* filter; scalar_t__ len; } ;
struct sock_filter {int dummy; } ;
struct sk_buff {int dummy; } ;
struct bpf_prog {int dummy; } ;
typedef  scalar_t__ __u16 ;

/* Variables and functions */
 int BPF_PROG_RUN (struct bpf_prog*,struct sk_buff const*) ; 
 int /*<<< orphan*/  BPF_PROG_TYPE_SOCKET_FILTER ; 
 int EINVAL ; 
 scalar_t__ IS_ERR (struct bpf_prog*) ; 
 int PTR_ERR (struct bpf_prog*) ; 
 int PTR_ERR_OR_ZERO (struct bpf_prog*) ; 
 scalar_t__ XT_BPF_MAX_NUM_INSTR ; 
 scalar_t__ XT_BPF_MODE_BYTECODE ; 
 scalar_t__ XT_BPF_MODE_FD_ELF ; 
 scalar_t__ XT_BPF_MODE_PATH_PINNED ; 
 scalar_t__ XT_BPF_PATH_MAX ; 
 scalar_t__ bpf_prog_create (struct bpf_prog**,struct sock_fprog_kern*) ; 
 int /*<<< orphan*/  bpf_prog_destroy (struct bpf_prog*) ; 
 struct bpf_prog* bpf_prog_get_type (int,int /*<<< orphan*/ ) ; 
 struct bpf_prog* bpf_prog_get_type_path (char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bpf_prog_run_save_cb (struct bpf_prog*,struct sk_buff*) ; 
 int /*<<< orphan*/  pr_info_ratelimited (char*) ; 
 scalar_t__ strnlen (char const*,scalar_t__) ; 

__attribute__((used)) static int __bpf_mt_check_bytecode(struct sock_filter *insns, __u16 len,
				   struct bpf_prog **ret)
{
	struct sock_fprog_kern program;

	if (len > XT_BPF_MAX_NUM_INSTR)
		return -EINVAL;

	program.len = len;
	program.filter = insns;

	if (bpf_prog_create(ret, &program)) {
		pr_info_ratelimited("check failed: parse error\n");
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int __bpf_mt_check_fd(int fd, struct bpf_prog **ret)
{
	struct bpf_prog *prog;

	prog = bpf_prog_get_type(fd, BPF_PROG_TYPE_SOCKET_FILTER);
	if (IS_ERR(prog))
		return PTR_ERR(prog);

	*ret = prog;
	return 0;
}

__attribute__((used)) static int __bpf_mt_check_path(const char *path, struct bpf_prog **ret)
{
	if (strnlen(path, XT_BPF_PATH_MAX) == XT_BPF_PATH_MAX)
		return -EINVAL;

	*ret = bpf_prog_get_type_path(path, BPF_PROG_TYPE_SOCKET_FILTER);
	return PTR_ERR_OR_ZERO(*ret);
}

__attribute__((used)) static int bpf_mt_check(const struct xt_mtchk_param *par)
{
	struct xt_bpf_info *info = par->matchinfo;

	return __bpf_mt_check_bytecode(info->bpf_program,
				       info->bpf_program_num_elem,
				       &info->filter);
}

__attribute__((used)) static int bpf_mt_check_v1(const struct xt_mtchk_param *par)
{
	struct xt_bpf_info_v1 *info = par->matchinfo;

	if (info->mode == XT_BPF_MODE_BYTECODE)
		return __bpf_mt_check_bytecode(info->bpf_program,
					       info->bpf_program_num_elem,
					       &info->filter);
	else if (info->mode == XT_BPF_MODE_FD_ELF)
		return __bpf_mt_check_fd(info->fd, &info->filter);
	else if (info->mode == XT_BPF_MODE_PATH_PINNED)
		return __bpf_mt_check_path(info->path, &info->filter);
	else
		return -EINVAL;
}

__attribute__((used)) static bool bpf_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
	const struct xt_bpf_info *info = par->matchinfo;

	return BPF_PROG_RUN(info->filter, skb);
}

__attribute__((used)) static bool bpf_mt_v1(const struct sk_buff *skb, struct xt_action_param *par)
{
	const struct xt_bpf_info_v1 *info = par->matchinfo;

	return !!bpf_prog_run_save_cb(info->filter, (struct sk_buff *) skb);
}

__attribute__((used)) static void bpf_mt_destroy(const struct xt_mtdtor_param *par)
{
	const struct xt_bpf_info *info = par->matchinfo;

	bpf_prog_destroy(info->filter);
}

__attribute__((used)) static void bpf_mt_destroy_v1(const struct xt_mtdtor_param *par)
{
	const struct xt_bpf_info_v1 *info = par->matchinfo;

	bpf_prog_destroy(info->filter);
}

