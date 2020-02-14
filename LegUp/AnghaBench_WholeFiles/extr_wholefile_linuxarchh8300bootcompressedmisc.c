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
 scalar_t__ HEAP_SIZE ; 
 int /*<<< orphan*/  __decompress (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,void (*) (char*)) ; 
 int /*<<< orphan*/  _end ; 
 scalar_t__ free_mem_end_ptr ; 
 unsigned long free_mem_ptr ; 
 int /*<<< orphan*/  input_data ; 
 int /*<<< orphan*/  input_len ; 
 int /*<<< orphan*/  output ; 

void *memset(void *s, int c, size_t n)
{
	int i;
	char *ss = (char *)s;

	for (i = 0; i < n; i++)
		ss[i] = c;
	return s;
}

void *memcpy(void *dest, const void *src, size_t n)
{
	int i;
	char *d = (char *)dest, *s = (char *)src;

	for (i = 0; i < n; i++)
		d[i] = s[i];
	return dest;
}

__attribute__((used)) static void error(char *x)
{
	while (1)
		;	/* Halt */
}

void decompress_kernel(void)
{
	free_mem_ptr = (unsigned long)&_end;
	free_mem_end_ptr = free_mem_ptr + HEAP_SIZE;

	__decompress(input_data, input_len, NULL, NULL, output, 0, NULL, error);
}

