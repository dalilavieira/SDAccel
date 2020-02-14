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
struct shash_desc {scalar_t__ flags; int /*<<< orphan*/  tfm; } ;
typedef  int /*<<< orphan*/  __u16 ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  crc_t10dif_generic (int /*<<< orphan*/ ,unsigned char const*,size_t) ; 
 int /*<<< orphan*/  crct10dif_fallback ; 
 int /*<<< orphan*/  crct10dif_tfm ; 
 int crypto_shash_update (struct shash_desc*,unsigned char const*,size_t) ; 
 scalar_t__ static_key_false (int /*<<< orphan*/ *) ; 

__u16 crc_t10dif_update(__u16 crc, const unsigned char *buffer, size_t len)
{
	struct {
		struct shash_desc shash;
		char ctx[2];
	} desc;
	int err;

	if (static_key_false(&crct10dif_fallback))
		return crc_t10dif_generic(crc, buffer, len);

	desc.shash.tfm = crct10dif_tfm;
	desc.shash.flags = 0;
	*(__u16 *)desc.ctx = crc;

	err = crypto_shash_update(&desc.shash, buffer, len);
	BUG_ON(err);

	return *(__u16 *)desc.ctx;
}

__u16 crc_t10dif(const unsigned char *buffer, size_t len)
{
	return crc_t10dif_update(0, buffer, len);
}

