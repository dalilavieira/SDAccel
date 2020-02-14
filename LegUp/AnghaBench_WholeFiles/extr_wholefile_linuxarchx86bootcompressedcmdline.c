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

__attribute__((used)) static inline int isdigit(int ch)
{
	return (ch >= '0') && (ch <= '9');
}

__attribute__((used)) static inline int isxdigit(int ch)
{
	if (isdigit(ch))
		return true;

	if ((ch >= 'a') && (ch <= 'f'))
		return true;

	return (ch >= 'A') && (ch <= 'F');
}

__attribute__((used)) static inline void debug_putstr(const char *s)
{ }

__attribute__((used)) static inline void debug_puthex(const char *s)
{ }

__attribute__((used)) static inline void choose_random_location(unsigned long input,
					  unsigned long input_size,
					  unsigned long *output,
					  unsigned long output_size,
					  unsigned long *virt_addr)
{
}

__attribute__((used)) static inline void initialize_identity_maps(void)
{ }

__attribute__((used)) static inline void add_identity_map(unsigned long start, unsigned long size)
{ }

__attribute__((used)) static inline void finalize_identity_maps(void)
{ }

__attribute__((used)) static inline void console_init(void)
{ }

