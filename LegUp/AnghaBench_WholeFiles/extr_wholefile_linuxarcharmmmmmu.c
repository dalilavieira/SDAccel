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
struct mem_type {int dummy; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (struct mem_type const*) ; 
 unsigned int FSR_FS3_0 ; 
 unsigned int FSR_FS4 ; 
 struct mem_type const* mem_types ; 

__attribute__((used)) static inline int fsr_fs(unsigned int fsr)
{
	return (fsr & FSR_FS3_0) | (fsr & FSR_FS4) >> 6;
}

__attribute__((used)) static inline void tcm_init(void)
{
}

const struct mem_type *get_mem_type(unsigned int type)
{
	return type < ARRAY_SIZE(mem_types) ? &mem_types[type] : NULL;
}

