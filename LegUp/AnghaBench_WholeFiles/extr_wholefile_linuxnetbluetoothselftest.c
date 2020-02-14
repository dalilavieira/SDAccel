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
struct smp_ltk {int type; scalar_t__ authenticated; } ;

/* Variables and functions */
 int /*<<< orphan*/  BT_SECURITY_FIPS ; 
 int /*<<< orphan*/  BT_SECURITY_HIGH ; 
 int /*<<< orphan*/  BT_SECURITY_MEDIUM ; 
#define  SMP_LTK_P256 129 
#define  SMP_LTK_P256_DEBUG 128 

__attribute__((used)) static inline bool smp_ltk_is_sc(struct smp_ltk *key)
{
	switch (key->type) {
	case SMP_LTK_P256:
	case SMP_LTK_P256_DEBUG:
		return true;
	}

	return false;
}

__attribute__((used)) static inline u8 smp_ltk_sec_level(struct smp_ltk *key)
{
	if (key->authenticated) {
		if (smp_ltk_is_sc(key))
			return BT_SECURITY_FIPS;
		else
			return BT_SECURITY_HIGH;
	}

	return BT_SECURITY_MEDIUM;
}

__attribute__((used)) static inline int bt_selftest_smp(void)
{
	return 0;
}

__attribute__((used)) static inline int bt_selftest(void)
{
	return 0;
}

__attribute__((used)) static inline int test_ecdh(void)
{
	return 0;
}

