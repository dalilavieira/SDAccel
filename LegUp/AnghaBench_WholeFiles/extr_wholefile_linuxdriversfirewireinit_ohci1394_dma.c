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
struct ohci {scalar_t__ registers; } ;

/* Variables and functions */
 int /*<<< orphan*/  readl (scalar_t__) ; 
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static inline void reg_write(const struct ohci *ohci, int offset, u32 data)
{
	writel(data, ohci->registers + offset);
}

__attribute__((used)) static inline u32 reg_read(const struct ohci *ohci, int offset)
{
	return readl(ohci->registers + offset);
}

