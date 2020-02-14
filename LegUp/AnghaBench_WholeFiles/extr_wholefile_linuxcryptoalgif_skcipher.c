#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u32 ;
struct socket {struct sock* sk; } ;
struct sock {void (* sk_destruct ) (struct sock*) ;} ;
struct page {int dummy; } ;
struct msghdr {scalar_t__ msg_iocb; } ;
struct TYPE_4__ {int /*<<< orphan*/  skcipher_req; } ;
struct TYPE_5__ {int /*<<< orphan*/  sg; } ;
struct TYPE_6__ {TYPE_2__ sgl; } ;
struct af_alg_async_req {int tsgl_entries; size_t outlen; TYPE_1__ cra_u; scalar_t__ iocb; TYPE_3__ first_rsgl; int /*<<< orphan*/ * tsgl; } ;
struct crypto_skcipher {size_t used; unsigned int len; struct af_alg_async_req wait; scalar_t__ enc; scalar_t__ merge; scalar_t__ more; int /*<<< orphan*/  rcvused; int /*<<< orphan*/  tsgl_list; void* iv; } ;
struct alg_sock {int refcnt; struct crypto_skcipher* private; struct sock* parent; } ;
struct af_alg_ctx {size_t used; unsigned int len; struct af_alg_async_req wait; scalar_t__ enc; scalar_t__ merge; scalar_t__ more; int /*<<< orphan*/  rcvused; int /*<<< orphan*/  tsgl_list; void* iv; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int CRYPTO_TFM_NEED_KEY ; 
 int CRYPTO_TFM_REQ_MAY_BACKLOG ; 
 int CRYPTO_TFM_REQ_MAY_SLEEP ; 
 int EBUSY ; 
 int EINPROGRESS ; 
 int EIOCBQUEUED ; 
 int ENOKEY ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 scalar_t__ IS_ERR (struct af_alg_async_req*) ; 
 int PTR_ERR (struct af_alg_async_req*) ; 
 int /*<<< orphan*/  SINGLE_DEPTH_NESTING ; 
 struct af_alg_async_req* af_alg_alloc_areq (struct sock*,scalar_t__) ; 
 int /*<<< orphan*/  af_alg_async_cb ; 
 int af_alg_count_tsgl (struct sock*,size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  af_alg_free_resources (struct af_alg_async_req*) ; 
 int af_alg_get_rsgl (struct sock*,struct msghdr*,int,struct af_alg_async_req*,int,size_t*) ; 
 int /*<<< orphan*/  af_alg_pull_tsgl (struct sock*,size_t,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  af_alg_release_parent (struct sock*) ; 
 int af_alg_sendmsg (struct socket*,struct msghdr*,size_t,unsigned int) ; 
 int af_alg_sendpage (struct socket*,struct page*,int,size_t,int) ; 
 int af_alg_wait_for_data (struct sock*,int) ; 
 int /*<<< orphan*/  af_alg_wmem_wakeup (struct sock*) ; 
 struct alg_sock* alg_sk (struct sock*) ; 
 unsigned int array_size (int,int) ; 
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 void* crypto_alloc_skcipher (char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  crypto_free_skcipher (void*) ; 
 int /*<<< orphan*/  crypto_init_wait (struct af_alg_async_req*) ; 
 int /*<<< orphan*/  crypto_req_done ; 
 unsigned int crypto_skcipher_blocksize (struct crypto_skcipher*) ; 
 int crypto_skcipher_decrypt (int /*<<< orphan*/ *) ; 
 int crypto_skcipher_encrypt (int /*<<< orphan*/ *) ; 
 int crypto_skcipher_get_flags (struct crypto_skcipher*) ; 
 unsigned int crypto_skcipher_ivsize (struct crypto_skcipher*) ; 
 scalar_t__ crypto_skcipher_reqsize (struct crypto_skcipher*) ; 
 int crypto_skcipher_setkey (void*,int /*<<< orphan*/  const*,unsigned int) ; 
 int crypto_wait_req (int,struct af_alg_async_req*) ; 
 int /*<<< orphan*/  is_sync_kiocb (scalar_t__) ; 
 int /*<<< orphan*/  lock_sock (struct sock*) ; 
 int /*<<< orphan*/  lock_sock_nested (struct sock*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (void*,int /*<<< orphan*/ ,unsigned int) ; 
 scalar_t__ msg_data_left (struct msghdr*) ; 
 int /*<<< orphan*/  release_sock (struct sock*) ; 
 int /*<<< orphan*/  sg_init_table (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  skcipher_request_set_callback (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,struct af_alg_async_req*) ; 
 int /*<<< orphan*/  skcipher_request_set_crypt (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,size_t,void*) ; 
 int /*<<< orphan*/  skcipher_request_set_tfm (int /*<<< orphan*/ *,struct crypto_skcipher*) ; 
 int /*<<< orphan*/  sock_hold (struct sock*) ; 
 int /*<<< orphan*/  sock_kfree_s (struct sock*,struct crypto_skcipher*,unsigned int) ; 
 void* sock_kmalloc (struct sock*,unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sock_kzfree_s (struct sock*,void*,unsigned int) ; 
 int /*<<< orphan*/  sock_put (struct sock*) ; 

__attribute__((used)) static int skcipher_sendmsg(struct socket *sock, struct msghdr *msg,
			    size_t size)
{
	struct sock *sk = sock->sk;
	struct alg_sock *ask = alg_sk(sk);
	struct sock *psk = ask->parent;
	struct alg_sock *pask = alg_sk(psk);
	struct crypto_skcipher *tfm = pask->private;
	unsigned ivsize = crypto_skcipher_ivsize(tfm);

	return af_alg_sendmsg(sock, msg, size, ivsize);
}

__attribute__((used)) static int _skcipher_recvmsg(struct socket *sock, struct msghdr *msg,
			     size_t ignored, int flags)
{
	struct sock *sk = sock->sk;
	struct alg_sock *ask = alg_sk(sk);
	struct sock *psk = ask->parent;
	struct alg_sock *pask = alg_sk(psk);
	struct af_alg_ctx *ctx = ask->private;
	struct crypto_skcipher *tfm = pask->private;
	unsigned int bs = crypto_skcipher_blocksize(tfm);
	struct af_alg_async_req *areq;
	int err = 0;
	size_t len = 0;

	if (!ctx->used) {
		err = af_alg_wait_for_data(sk, flags);
		if (err)
			return err;
	}

	/* Allocate cipher request for current operation. */
	areq = af_alg_alloc_areq(sk, sizeof(struct af_alg_async_req) +
				     crypto_skcipher_reqsize(tfm));
	if (IS_ERR(areq))
		return PTR_ERR(areq);

	/* convert iovecs of output buffers into RX SGL */
	err = af_alg_get_rsgl(sk, msg, flags, areq, -1, &len);
	if (err)
		goto free;

	/* Process only as much RX buffers for which we have TX data */
	if (len > ctx->used)
		len = ctx->used;

	/*
	 * If more buffers are to be expected to be processed, process only
	 * full block size buffers.
	 */
	if (ctx->more || len < ctx->used)
		len -= len % bs;

	/*
	 * Create a per request TX SGL for this request which tracks the
	 * SG entries from the global TX SGL.
	 */
	areq->tsgl_entries = af_alg_count_tsgl(sk, len, 0);
	if (!areq->tsgl_entries)
		areq->tsgl_entries = 1;
	areq->tsgl = sock_kmalloc(sk, array_size(sizeof(*areq->tsgl),
						 areq->tsgl_entries),
				  GFP_KERNEL);
	if (!areq->tsgl) {
		err = -ENOMEM;
		goto free;
	}
	sg_init_table(areq->tsgl, areq->tsgl_entries);
	af_alg_pull_tsgl(sk, len, areq->tsgl, 0);

	/* Initialize the crypto operation */
	skcipher_request_set_tfm(&areq->cra_u.skcipher_req, tfm);
	skcipher_request_set_crypt(&areq->cra_u.skcipher_req, areq->tsgl,
				   areq->first_rsgl.sgl.sg, len, ctx->iv);

	if (msg->msg_iocb && !is_sync_kiocb(msg->msg_iocb)) {
		/* AIO operation */
		sock_hold(sk);
		areq->iocb = msg->msg_iocb;

		/* Remember output size that will be generated. */
		areq->outlen = len;

		skcipher_request_set_callback(&areq->cra_u.skcipher_req,
					      CRYPTO_TFM_REQ_MAY_SLEEP,
					      af_alg_async_cb, areq);
		err = ctx->enc ?
			crypto_skcipher_encrypt(&areq->cra_u.skcipher_req) :
			crypto_skcipher_decrypt(&areq->cra_u.skcipher_req);

		/* AIO operation in progress */
		if (err == -EINPROGRESS || err == -EBUSY)
			return -EIOCBQUEUED;

		sock_put(sk);
	} else {
		/* Synchronous operation */
		skcipher_request_set_callback(&areq->cra_u.skcipher_req,
					      CRYPTO_TFM_REQ_MAY_SLEEP |
					      CRYPTO_TFM_REQ_MAY_BACKLOG,
					      crypto_req_done, &ctx->wait);
		err = crypto_wait_req(ctx->enc ?
			crypto_skcipher_encrypt(&areq->cra_u.skcipher_req) :
			crypto_skcipher_decrypt(&areq->cra_u.skcipher_req),
						 &ctx->wait);
	}


free:
	af_alg_free_resources(areq);

	return err ? err : len;
}

__attribute__((used)) static int skcipher_recvmsg(struct socket *sock, struct msghdr *msg,
			    size_t ignored, int flags)
{
	struct sock *sk = sock->sk;
	int ret = 0;

	lock_sock(sk);
	while (msg_data_left(msg)) {
		int err = _skcipher_recvmsg(sock, msg, ignored, flags);

		/*
		 * This error covers -EIOCBQUEUED which implies that we can
		 * only handle one AIO request. If the caller wants to have
		 * multiple AIO requests in parallel, he must make multiple
		 * separate AIO calls.
		 *
		 * Also return the error if no data has been processed so far.
		 */
		if (err <= 0) {
			if (err == -EIOCBQUEUED || !ret)
				ret = err;
			goto out;
		}

		ret += err;
	}

out:
	af_alg_wmem_wakeup(sk);
	release_sock(sk);
	return ret;
}

__attribute__((used)) static int skcipher_check_key(struct socket *sock)
{
	int err = 0;
	struct sock *psk;
	struct alg_sock *pask;
	struct crypto_skcipher *tfm;
	struct sock *sk = sock->sk;
	struct alg_sock *ask = alg_sk(sk);

	lock_sock(sk);
	if (ask->refcnt)
		goto unlock_child;

	psk = ask->parent;
	pask = alg_sk(ask->parent);
	tfm = pask->private;

	err = -ENOKEY;
	lock_sock_nested(psk, SINGLE_DEPTH_NESTING);
	if (crypto_skcipher_get_flags(tfm) & CRYPTO_TFM_NEED_KEY)
		goto unlock;

	if (!pask->refcnt++)
		sock_hold(psk);

	ask->refcnt = 1;
	sock_put(psk);

	err = 0;

unlock:
	release_sock(psk);
unlock_child:
	release_sock(sk);

	return err;
}

__attribute__((used)) static int skcipher_sendmsg_nokey(struct socket *sock, struct msghdr *msg,
				  size_t size)
{
	int err;

	err = skcipher_check_key(sock);
	if (err)
		return err;

	return skcipher_sendmsg(sock, msg, size);
}

__attribute__((used)) static ssize_t skcipher_sendpage_nokey(struct socket *sock, struct page *page,
				       int offset, size_t size, int flags)
{
	int err;

	err = skcipher_check_key(sock);
	if (err)
		return err;

	return af_alg_sendpage(sock, page, offset, size, flags);
}

__attribute__((used)) static int skcipher_recvmsg_nokey(struct socket *sock, struct msghdr *msg,
				  size_t ignored, int flags)
{
	int err;

	err = skcipher_check_key(sock);
	if (err)
		return err;

	return skcipher_recvmsg(sock, msg, ignored, flags);
}

__attribute__((used)) static void *skcipher_bind(const char *name, u32 type, u32 mask)
{
	return crypto_alloc_skcipher(name, type, mask);
}

__attribute__((used)) static void skcipher_release(void *private)
{
	crypto_free_skcipher(private);
}

__attribute__((used)) static int skcipher_setkey(void *private, const u8 *key, unsigned int keylen)
{
	return crypto_skcipher_setkey(private, key, keylen);
}

__attribute__((used)) static void skcipher_sock_destruct(struct sock *sk)
{
	struct alg_sock *ask = alg_sk(sk);
	struct af_alg_ctx *ctx = ask->private;
	struct sock *psk = ask->parent;
	struct alg_sock *pask = alg_sk(psk);
	struct crypto_skcipher *tfm = pask->private;

	af_alg_pull_tsgl(sk, ctx->used, NULL, 0);
	sock_kzfree_s(sk, ctx->iv, crypto_skcipher_ivsize(tfm));
	sock_kfree_s(sk, ctx, ctx->len);
	af_alg_release_parent(sk);
}

__attribute__((used)) static int skcipher_accept_parent_nokey(void *private, struct sock *sk)
{
	struct af_alg_ctx *ctx;
	struct alg_sock *ask = alg_sk(sk);
	struct crypto_skcipher *tfm = private;
	unsigned int len = sizeof(*ctx);

	ctx = sock_kmalloc(sk, len, GFP_KERNEL);
	if (!ctx)
		return -ENOMEM;

	ctx->iv = sock_kmalloc(sk, crypto_skcipher_ivsize(tfm),
			       GFP_KERNEL);
	if (!ctx->iv) {
		sock_kfree_s(sk, ctx, len);
		return -ENOMEM;
	}

	memset(ctx->iv, 0, crypto_skcipher_ivsize(tfm));

	INIT_LIST_HEAD(&ctx->tsgl_list);
	ctx->len = len;
	ctx->used = 0;
	atomic_set(&ctx->rcvused, 0);
	ctx->more = 0;
	ctx->merge = 0;
	ctx->enc = 0;
	crypto_init_wait(&ctx->wait);

	ask->private = ctx;

	sk->sk_destruct = skcipher_sock_destruct;

	return 0;
}

__attribute__((used)) static int skcipher_accept_parent(void *private, struct sock *sk)
{
	struct crypto_skcipher *tfm = private;

	if (crypto_skcipher_get_flags(tfm) & CRYPTO_TFM_NEED_KEY)
		return -ENOKEY;

	return skcipher_accept_parent_nokey(private, sk);
}

