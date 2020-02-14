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
struct TYPE_2__ {int systemid; unsigned int mconfig1; unsigned int mconfig0; } ;

/* Variables and functions */
 unsigned int SGIMC_MCONFIG_BASEADDR ; 
 unsigned int SGIMC_MCONFIG_RMASK ; 
 int SGIMC_SYSID_MASKREV ; 
 TYPE_1__* sgimc ; 

__attribute__((used)) static inline unsigned long get_bank_addr(unsigned int memconfig)
{
	return (memconfig & SGIMC_MCONFIG_BASEADDR) << ((sgimc->systemid & SGIMC_SYSID_MASKREV) >= 5 ? 24 : 22);
}

__attribute__((used)) static inline unsigned long get_bank_size(unsigned int memconfig)
{
	return ((memconfig & SGIMC_MCONFIG_RMASK) + 0x0100) << ((sgimc->systemid & SGIMC_SYSID_MASKREV) >= 5 ? 16 : 14);
}

__attribute__((used)) static inline unsigned int get_bank_config(int bank)
{
	unsigned int res = bank > 1 ? sgimc->mconfig1 : sgimc->mconfig0;
	return bank % 2 ? res & 0xffff : res >> 16;
}

