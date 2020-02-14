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
struct jitterentropy {int /*<<< orphan*/  jent_lock; int /*<<< orphan*/ * entropy_collector; } ;
struct crypto_tfm {int dummy; } ;
struct crypto_rng {int dummy; } ;
typedef  scalar_t__ __u64 ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 struct jitterentropy* crypto_rng_ctx (struct crypto_rng*) ; 
 struct jitterentropy* crypto_tfm_ctx (struct crypto_tfm*) ; 
 int fips_enabled ; 
 int /*<<< orphan*/ * jent_entropy_collector_alloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  jent_entropy_collector_free (int /*<<< orphan*/ *) ; 
 int jent_read_entropy (int /*<<< orphan*/ *,int /*<<< orphan*/ *,unsigned int) ; 
 scalar_t__ ktime_get_ns () ; 
 void* kzalloc (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kzfree (void*) ; 
 int /*<<< orphan*/  memcpy (void*,void const*,unsigned int) ; 
 int /*<<< orphan*/  panic (char*,char*) ; 
 scalar_t__ random_get_entropy () ; 
 scalar_t__ rol64 (scalar_t__,unsigned int) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

__u64 jent_rol64(__u64 word, unsigned int shift)
{
	return rol64(word, shift);
}

void *jent_zalloc(unsigned int len)
{
	return kzalloc(len, GFP_KERNEL);
}

void jent_zfree(void *ptr)
{
	kzfree(ptr);
}

int jent_fips_enabled(void)
{
	return fips_enabled;
}

void jent_panic(char *s)
{
	panic("%s", s);
}

void jent_memcpy(void *dest, const void *src, unsigned int n)
{
	memcpy(dest, src, n);
}

void jent_get_nstime(__u64 *out)
{
	__u64 tmp = 0;

	tmp = random_get_entropy();

	/*
	 * If random_get_entropy does not return a value, i.e. it is not
	 * implemented for a given architecture, use a clock source.
	 * hoping that there are timers we can work with.
	 */
	if (tmp == 0)
		tmp = ktime_get_ns();

	*out = tmp;
}

__attribute__((used)) static int jent_kcapi_init(struct crypto_tfm *tfm)
{
	struct jitterentropy *rng = crypto_tfm_ctx(tfm);
	int ret = 0;

	rng->entropy_collector = jent_entropy_collector_alloc(1, 0);
	if (!rng->entropy_collector)
		ret = -ENOMEM;

	spin_lock_init(&rng->jent_lock);
	return ret;
}

__attribute__((used)) static void jent_kcapi_cleanup(struct crypto_tfm *tfm)
{
	struct jitterentropy *rng = crypto_tfm_ctx(tfm);

	spin_lock(&rng->jent_lock);
	if (rng->entropy_collector)
		jent_entropy_collector_free(rng->entropy_collector);
	rng->entropy_collector = NULL;
	spin_unlock(&rng->jent_lock);
}

__attribute__((used)) static int jent_kcapi_random(struct crypto_rng *tfm,
			     const u8 *src, unsigned int slen,
			     u8 *rdata, unsigned int dlen)
{
	struct jitterentropy *rng = crypto_rng_ctx(tfm);
	int ret = 0;

	spin_lock(&rng->jent_lock);
	ret = jent_read_entropy(rng->entropy_collector, rdata, dlen);
	spin_unlock(&rng->jent_lock);

	return ret;
}

__attribute__((used)) static int jent_kcapi_reset(struct crypto_rng *tfm,
			    const u8 *seed, unsigned int slen)
{
	return 0;
}

