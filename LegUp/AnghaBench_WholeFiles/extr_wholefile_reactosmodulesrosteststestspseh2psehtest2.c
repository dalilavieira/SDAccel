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

extern
int return_arg(int arg)
{
	return arg;
}

extern
void no_op(void)
{
}

extern
int return_zero(void)
{
	return 0;
}

extern
int return_positive(void)
{
	return 1234;
}

extern
int return_negative(void)
{
	return -1234;
}

extern
int return_one(void)
{
	return 1;
}

extern
int return_minusone(void)
{
	return -1;
}

extern
int return_zero_2(void * p)
{
	return 0;
}

extern
int return_positive_2(void * p)
{
	return 1234;
}

extern
int return_negative_2(void * p)
{
	return -1234;
}

extern
int return_one_2(void * p)
{
	return 1;
}

extern
int return_minusone_2(void * p)
{
	return -1;
}

extern
int return_zero_3(int n)
{
	return 0;
}

extern
int return_positive_3(int n)
{
	return 1234;
}

extern
int return_negative_3(int n)
{
	return -1234;
}

extern
int return_one_3(int n)
{
	return 1;
}

extern
int return_minusone_3(int n)
{
	return -1;
}

extern
int return_zero_4(void * p, int n)
{
	return 0;
}

extern
int return_positive_4(void * p, int n)
{
	return 1234;
}

extern
int return_negative_4(void * p, int n)
{
	return -1234;
}

extern
int return_one_4(void * p, int n)
{
	return 1;
}

extern
int return_minusone_4(void * p, int n)
{
	return -1;
}

extern
void set_positive(int * p)
{
	*p = 1234;
}

