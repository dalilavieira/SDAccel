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
 int /*<<< orphan*/  PRBAR ; 
 int /*<<< orphan*/  PRLAR ; 
 int /*<<< orphan*/  PRSEL ; 
 int /*<<< orphan*/  read_sysreg (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  write_sysreg (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline u32 prlar_read(void)
{
	return read_sysreg(PRLAR);
}

__attribute__((used)) static inline u32 prbar_read(void)
{
	return read_sysreg(PRBAR);
}

__attribute__((used)) static inline void prsel_write(u32 v)
{
	write_sysreg(v, PRSEL);
}

__attribute__((used)) static inline void prbar_write(u32 v)
{
	write_sysreg(v, PRBAR);
}

__attribute__((used)) static inline void prlar_write(u32 v)
{
	write_sysreg(v, PRLAR);
}

