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
typedef  char u8 ;
typedef  int /*<<< orphan*/  u64 ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  size_t ssize_t ;
typedef  int /*<<< orphan*/  hash ;
typedef  int /*<<< orphan*/  entropy ;
typedef  int /*<<< orphan*/  buf ;
typedef  char __u64 ;
struct TYPE_5__ {char* parm_block; int /*<<< orphan*/  byte_counter; scalar_t__ reseed_counter; } ;
struct TYPE_4__ {int /*<<< orphan*/  stream_bytes; } ;
struct TYPE_6__ {int /*<<< orphan*/  mutex; TYPE_2__ prngws; TYPE_1__ prnows; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  CPACF_KIMD_SHA_512 ; 
 int /*<<< orphan*/  CPACF_KMC_PRNG ; 
 size_t EINVAL ; 
 int ENOMEM ; 
 size_t ERESTARTSYS ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int PAGE_SIZE ; 
 int PRNG_GEN_ENTROPY_FAILED ; 
 scalar_t__ PRNG_MODE_SHA512 ; 
 scalar_t__ PRNG_MODE_TDES ; 
 unsigned int PRNG_RESEED_LIMIT_SHA512_LOWER ; 
 unsigned int PRNG_RESEED_LIMIT_TDES_LOWER ; 
 scalar_t__ __get_free_pages (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  cpacf_kimd (int /*<<< orphan*/ ,char*,char*,int) ; 
 int /*<<< orphan*/  cpacf_kmc (int /*<<< orphan*/ ,char*,char*,char*,int) ; 
 int /*<<< orphan*/  free_pages (unsigned long,int) ; 
 int /*<<< orphan*/  get_random_bytes (char*,int) ; 
 int /*<<< orphan*/  get_tod_clock_fast () ; 
 int /*<<< orphan*/  memcpy (char*,char*,int) ; 
 scalar_t__ mutex_lock_interruptible (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int prng_chunk_size ; 
 TYPE_3__* prng_data ; 
 int prng_errorflag ; 
 scalar_t__ prng_mode ; 
 int prng_reseed_limit ; 
 int /*<<< orphan*/  prng_sha512_reseed () ; 
 size_t snprintf (char*,int,char*,...) ; 
 int sscanf (char const*,char*,unsigned int*) ; 

__attribute__((used)) static int generate_entropy(u8 *ebuf, size_t nbytes)
{
	int n, ret = 0;
	u8 *pg, *h, hash[64];

	/* allocate 2 pages */
	pg = (u8 *) __get_free_pages(GFP_KERNEL, 1);
	if (!pg) {
		prng_errorflag = PRNG_GEN_ENTROPY_FAILED;
		return -ENOMEM;
	}

	while (nbytes) {
		/* fill pages with urandom bytes */
		get_random_bytes(pg, 2*PAGE_SIZE);
		/* exor pages with 1024 stckf values */
		for (n = 0; n < 2 * PAGE_SIZE / sizeof(u64); n++) {
			u64 *p = ((u64 *)pg) + n;
			*p ^= get_tod_clock_fast();
		}
		n = (nbytes < sizeof(hash)) ? nbytes : sizeof(hash);
		if (n < sizeof(hash))
			h = hash;
		else
			h = ebuf;
		/* hash over the filled pages */
		cpacf_kimd(CPACF_KIMD_SHA_512, h, pg, 2*PAGE_SIZE);
		if (n < sizeof(hash))
			memcpy(ebuf, hash, n);
		ret += n;
		ebuf += n;
		nbytes -= n;
	}

	free_pages((unsigned long)pg, 1);
	return ret;
}

__attribute__((used)) static void prng_tdes_add_entropy(void)
{
	__u64 entropy[4];
	unsigned int i;

	for (i = 0; i < 16; i++) {
		cpacf_kmc(CPACF_KMC_PRNG, prng_data->prngws.parm_block,
			  (char *) entropy, (char *) entropy,
			  sizeof(entropy));
		memcpy(prng_data->prngws.parm_block, entropy, sizeof(entropy));
	}
}

__attribute__((used)) static void prng_tdes_seed(int nbytes)
{
	char buf[16];
	int i = 0;

	BUG_ON(nbytes > sizeof(buf));

	get_random_bytes(buf, nbytes);

	/* Add the entropy */
	while (nbytes >= 8) {
		*((__u64 *)prng_data->prngws.parm_block) ^= *((__u64 *)(buf+i));
		prng_tdes_add_entropy();
		i += 8;
		nbytes -= 8;
	}
	prng_tdes_add_entropy();
	prng_data->prngws.reseed_counter = 0;
}

__attribute__((used)) static ssize_t prng_chunksize_show(struct device *dev,
				   struct device_attribute *attr,
				   char *buf)
{
	return snprintf(buf, PAGE_SIZE, "%u\n", prng_chunk_size);
}

__attribute__((used)) static ssize_t prng_counter_show(struct device *dev,
				 struct device_attribute *attr,
				 char *buf)
{
	u64 counter;

	if (mutex_lock_interruptible(&prng_data->mutex))
		return -ERESTARTSYS;
	if (prng_mode == PRNG_MODE_SHA512)
		counter = prng_data->prnows.stream_bytes;
	else
		counter = prng_data->prngws.byte_counter;
	mutex_unlock(&prng_data->mutex);

	return snprintf(buf, PAGE_SIZE, "%llu\n", counter);
}

__attribute__((used)) static ssize_t prng_errorflag_show(struct device *dev,
				   struct device_attribute *attr,
				   char *buf)
{
	return snprintf(buf, PAGE_SIZE, "%d\n", prng_errorflag);
}

__attribute__((used)) static ssize_t prng_mode_show(struct device *dev,
			      struct device_attribute *attr,
			      char *buf)
{
	if (prng_mode == PRNG_MODE_TDES)
		return snprintf(buf, PAGE_SIZE, "TDES\n");
	else
		return snprintf(buf, PAGE_SIZE, "SHA512\n");
}

__attribute__((used)) static ssize_t prng_reseed_store(struct device *dev,
				 struct device_attribute *attr,
				 const char *buf, size_t count)
{
	if (mutex_lock_interruptible(&prng_data->mutex))
		return -ERESTARTSYS;
	prng_sha512_reseed();
	mutex_unlock(&prng_data->mutex);

	return count;
}

__attribute__((used)) static ssize_t prng_reseed_limit_show(struct device *dev,
				      struct device_attribute *attr,
				      char *buf)
{
	return snprintf(buf, PAGE_SIZE, "%u\n", prng_reseed_limit);
}

__attribute__((used)) static ssize_t prng_reseed_limit_store(struct device *dev,
				       struct device_attribute *attr,
				       const char *buf, size_t count)
{
	unsigned limit;

	if (sscanf(buf, "%u\n", &limit) != 1)
		return -EINVAL;

	if (prng_mode == PRNG_MODE_SHA512) {
		if (limit < PRNG_RESEED_LIMIT_SHA512_LOWER)
			return -EINVAL;
	} else {
		if (limit < PRNG_RESEED_LIMIT_TDES_LOWER)
			return -EINVAL;
	}

	prng_reseed_limit = limit;

	return count;
}

__attribute__((used)) static ssize_t prng_strength_show(struct device *dev,
				  struct device_attribute *attr,
				  char *buf)
{
	return snprintf(buf, PAGE_SIZE, "256\n");
}

