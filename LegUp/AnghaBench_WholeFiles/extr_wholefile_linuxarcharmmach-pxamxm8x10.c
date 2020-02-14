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

/* Variables and functions */
 int /*<<< orphan*/  mfp_config (unsigned long*,int) ; 
 unsigned long mfp_read (int) ; 
 int /*<<< orphan*/  mfp_write (int,unsigned long) ; 

__attribute__((used)) static inline unsigned long pxa3xx_mfp_read(int mfp)
{
	return mfp_read(mfp);
}

__attribute__((used)) static inline void pxa3xx_mfp_write(int mfp, unsigned long val)
{
	mfp_write(mfp, val);
}

__attribute__((used)) static inline void pxa3xx_mfp_config(unsigned long *mfp_cfg, int num)
{
	mfp_config(mfp_cfg, num);
}

__attribute__((used)) static inline void mxm_8x10_mmc_init(void) {}

__attribute__((used)) static inline void pxa2xx_clear_reset_status(unsigned int mask) {}

