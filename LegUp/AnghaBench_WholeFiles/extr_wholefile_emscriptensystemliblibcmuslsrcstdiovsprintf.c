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
typedef  int /*<<< orphan*/  va_list ;

/* Variables and functions */
 int /*<<< orphan*/  INT_MAX ; 
 int __small_vsnprintf (char*,int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ) ; 
 int vsniprintf (char*,int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ) ; 
 int vsnprintf (char*,int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ) ; 

int vsprintf(char *restrict s, const char *restrict fmt, va_list ap)
{
	return vsnprintf(s, INT_MAX, fmt, ap);
}

int vsiprintf(char *restrict s, const char *restrict fmt, va_list ap)
{
	return vsniprintf(s, INT_MAX, fmt, ap);
}

int __small_vsprintf(char *restrict s, const char *restrict fmt, va_list ap)
{
	return __small_vsnprintf(s, INT_MAX, fmt, ap);
}

