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
typedef  scalar_t__ u32 ;
struct rpc_task {TYPE_2__* tk_rqstp; } ;
struct rpc_cred {int dummy; } ;
struct rpc_clnt {int dummy; } ;
struct rpc_auth_create_args {int dummy; } ;
struct rpc_auth {int /*<<< orphan*/  au_count; } ;
struct auth_cred {int dummy; } ;
typedef  scalar_t__ rpc_authflavor_t ;
typedef  int /*<<< orphan*/  __be32 ;
struct TYPE_4__ {TYPE_1__* rq_cred; } ;
struct TYPE_3__ {int /*<<< orphan*/  cr_flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  EIO ; 
 int /*<<< orphan*/ * ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RPCAUTH_CRED_UPTODATE ; 
 int RPCAUTH_LOOKUP_RCU ; 
 scalar_t__ RPC_AUTH_NULL ; 
 int /*<<< orphan*/  atomic_inc (int /*<<< orphan*/ *) ; 
 struct rpc_cred* get_rpccred (struct rpc_cred*) ; 
 void* htonl (scalar_t__) ; 
 scalar_t__ ntohl (int /*<<< orphan*/ ) ; 
 struct rpc_auth null_auth ; 
 struct rpc_cred null_cred ; 
 int /*<<< orphan*/  printk (char*,scalar_t__) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static struct rpc_auth *
nul_create(const struct rpc_auth_create_args *args, struct rpc_clnt *clnt)
{
	atomic_inc(&null_auth.au_count);
	return &null_auth;
}

__attribute__((used)) static void
nul_destroy(struct rpc_auth *auth)
{
}

__attribute__((used)) static struct rpc_cred *
nul_lookup_cred(struct rpc_auth *auth, struct auth_cred *acred, int flags)
{
	if (flags & RPCAUTH_LOOKUP_RCU)
		return &null_cred;
	return get_rpccred(&null_cred);
}

__attribute__((used)) static void
nul_destroy_cred(struct rpc_cred *cred)
{
}

__attribute__((used)) static int
nul_match(struct auth_cred *acred, struct rpc_cred *cred, int taskflags)
{
	return 1;
}

__attribute__((used)) static __be32 *
nul_marshal(struct rpc_task *task, __be32 *p)
{
	*p++ = htonl(RPC_AUTH_NULL);
	*p++ = 0;
	*p++ = htonl(RPC_AUTH_NULL);
	*p++ = 0;

	return p;
}

__attribute__((used)) static int
nul_refresh(struct rpc_task *task)
{
	set_bit(RPCAUTH_CRED_UPTODATE, &task->tk_rqstp->rq_cred->cr_flags);
	return 0;
}

__attribute__((used)) static __be32 *
nul_validate(struct rpc_task *task, __be32 *p)
{
	rpc_authflavor_t	flavor;
	u32			size;

	flavor = ntohl(*p++);
	if (flavor != RPC_AUTH_NULL) {
		printk("RPC: bad verf flavor: %u\n", flavor);
		return ERR_PTR(-EIO);
	}

	size = ntohl(*p++);
	if (size != 0) {
		printk("RPC: bad verf size: %u\n", size);
		return ERR_PTR(-EIO);
	}

	return p;
}

