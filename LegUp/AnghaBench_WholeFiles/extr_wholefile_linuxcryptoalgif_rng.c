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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u32 ;
struct socket {struct sock* sk; } ;
struct sock {void (* sk_destruct ) (struct sock*) ;} ;
struct rng_ctx {unsigned int len; void* drng; } ;
struct msghdr {int dummy; } ;
struct alg_sock {struct rng_ctx* private; } ;

/* Variables and functions */
 int EFAULT ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int MAXSIZE ; 
 int /*<<< orphan*/  af_alg_release_parent (struct sock*) ; 
 struct alg_sock* alg_sk (struct sock*) ; 
 void* crypto_alloc_rng (char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  crypto_free_rng (void*) ; 
 int crypto_rng_get_bytes (void*,int /*<<< orphan*/ *,size_t) ; 
 int crypto_rng_reset (void*,int /*<<< orphan*/  const*,unsigned int) ; 
 int memcpy_to_msg (struct msghdr*,int /*<<< orphan*/ *,size_t) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  memzero_explicit (int /*<<< orphan*/ *,size_t) ; 
 int /*<<< orphan*/  sock_kfree_s (struct sock*,struct rng_ctx*,unsigned int) ; 
 struct rng_ctx* sock_kmalloc (struct sock*,unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int rng_recvmsg(struct socket *sock, struct msghdr *msg, size_t len,
		       int flags)
{
	struct sock *sk = sock->sk;
	struct alg_sock *ask = alg_sk(sk);
	struct rng_ctx *ctx = ask->private;
	int err = -EFAULT;
	int genlen = 0;
	u8 result[MAXSIZE];

	if (len == 0)
		return 0;
	if (len > MAXSIZE)
		len = MAXSIZE;

	/*
	 * although not strictly needed, this is a precaution against coding
	 * errors
	 */
	memset(result, 0, len);

	/*
	 * The enforcement of a proper seeding of an RNG is done within an
	 * RNG implementation. Some RNGs (DRBG, krng) do not need specific
	 * seeding as they automatically seed. The X9.31 DRNG will return
	 * an error if it was not seeded properly.
	 */
	genlen = crypto_rng_get_bytes(ctx->drng, result, len);
	if (genlen < 0)
		return genlen;

	err = memcpy_to_msg(msg, result, len);
	memzero_explicit(result, len);

	return err ? err : len;
}

__attribute__((used)) static void *rng_bind(const char *name, u32 type, u32 mask)
{
	return crypto_alloc_rng(name, type, mask);
}

__attribute__((used)) static void rng_release(void *private)
{
	crypto_free_rng(private);
}

__attribute__((used)) static void rng_sock_destruct(struct sock *sk)
{
	struct alg_sock *ask = alg_sk(sk);
	struct rng_ctx *ctx = ask->private;

	sock_kfree_s(sk, ctx, ctx->len);
	af_alg_release_parent(sk);
}

__attribute__((used)) static int rng_accept_parent(void *private, struct sock *sk)
{
	struct rng_ctx *ctx;
	struct alg_sock *ask = alg_sk(sk);
	unsigned int len = sizeof(*ctx);

	ctx = sock_kmalloc(sk, len, GFP_KERNEL);
	if (!ctx)
		return -ENOMEM;

	ctx->len = len;

	/*
	 * No seeding done at that point -- if multiple accepts are
	 * done on one RNG instance, each resulting FD points to the same
	 * state of the RNG.
	 */

	ctx->drng = private;
	ask->private = ctx;
	sk->sk_destruct = rng_sock_destruct;

	return 0;
}

__attribute__((used)) static int rng_setkey(void *private, const u8 *seed, unsigned int seedlen)
{
	/*
	 * Check whether seedlen is of sufficient size is done in RNG
	 * implementations.
	 */
	return crypto_rng_reset(private, seed, seedlen);
}

