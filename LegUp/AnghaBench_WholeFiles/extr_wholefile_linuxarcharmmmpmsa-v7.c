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
typedef  int /*<<< orphan*/  u32 ;

/* Variables and functions */
 int /*<<< orphan*/  DRACR ; 
 int /*<<< orphan*/  DRBAR ; 
 int /*<<< orphan*/  DRSR ; 
 int /*<<< orphan*/  IRACR ; 
 int /*<<< orphan*/  IRBAR ; 
 int /*<<< orphan*/  IRSR ; 
 int /*<<< orphan*/  RNGNR ; 
 int /*<<< orphan*/  read_sysreg (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  write_sysreg (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void rgnr_write(u32 v)
{
	write_sysreg(v, RNGNR);
}

__attribute__((used)) static inline void dracr_write(u32 v)
{
	write_sysreg(v, DRACR);
}

__attribute__((used)) static inline void drsr_write(u32 v)
{
	write_sysreg(v, DRSR);
}

__attribute__((used)) static inline void drbar_write(u32 v)
{
	write_sysreg(v, DRBAR);
}

__attribute__((used)) static inline u32 drbar_read(void)
{
	return read_sysreg(DRBAR);
}

__attribute__((used)) static inline void iracr_write(u32 v)
{
	write_sysreg(v, IRACR);
}

__attribute__((used)) static inline void irsr_write(u32 v)
{
	write_sysreg(v, IRSR);
}

__attribute__((used)) static inline void irbar_write(u32 v)
{
	write_sysreg(v, IRBAR);
}

__attribute__((used)) static inline u32 irbar_read(void)
{
	return read_sysreg(IRBAR);
}

