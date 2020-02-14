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
struct fp_ext {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  fp_monadic_check (struct fp_ext*,struct fp_ext*) ; 
 int /*<<< orphan*/  uprint (char*) ; 

struct fp_ext *
fp_fsin(struct fp_ext *dest, struct fp_ext *src)
{
	uprint("fsin\n");

	fp_monadic_check(dest, src);

	return dest;
}

struct fp_ext *
fp_fcos(struct fp_ext *dest, struct fp_ext *src)
{
	uprint("fcos\n");

	fp_monadic_check(dest, src);

	return dest;
}

struct fp_ext *
fp_ftan(struct fp_ext *dest, struct fp_ext *src)
{
	uprint("ftan\n");

	fp_monadic_check(dest, src);

	return dest;
}

struct fp_ext *
fp_fasin(struct fp_ext *dest, struct fp_ext *src)
{
	uprint("fasin\n");

	fp_monadic_check(dest, src);

	return dest;
}

struct fp_ext *
fp_facos(struct fp_ext *dest, struct fp_ext *src)
{
	uprint("facos\n");

	fp_monadic_check(dest, src);

	return dest;
}

struct fp_ext *
fp_fatan(struct fp_ext *dest, struct fp_ext *src)
{
	uprint("fatan\n");

	fp_monadic_check(dest, src);

	return dest;
}

struct fp_ext *
fp_fsinh(struct fp_ext *dest, struct fp_ext *src)
{
	uprint("fsinh\n");

	fp_monadic_check(dest, src);

	return dest;
}

struct fp_ext *
fp_fcosh(struct fp_ext *dest, struct fp_ext *src)
{
	uprint("fcosh\n");

	fp_monadic_check(dest, src);

	return dest;
}

struct fp_ext *
fp_ftanh(struct fp_ext *dest, struct fp_ext *src)
{
	uprint("ftanh\n");

	fp_monadic_check(dest, src);

	return dest;
}

struct fp_ext *
fp_fatanh(struct fp_ext *dest, struct fp_ext *src)
{
	uprint("fatanh\n");

	fp_monadic_check(dest, src);

	return dest;
}

struct fp_ext *
fp_fsincos0(struct fp_ext *dest, struct fp_ext *src)
{
	uprint("fsincos0\n");

	return dest;
}

struct fp_ext *
fp_fsincos1(struct fp_ext *dest, struct fp_ext *src)
{
	uprint("fsincos1\n");

	return dest;
}

struct fp_ext *
fp_fsincos2(struct fp_ext *dest, struct fp_ext *src)
{
	uprint("fsincos2\n");

	return dest;
}

struct fp_ext *
fp_fsincos3(struct fp_ext *dest, struct fp_ext *src)
{
	uprint("fsincos3\n");

	return dest;
}

struct fp_ext *
fp_fsincos4(struct fp_ext *dest, struct fp_ext *src)
{
	uprint("fsincos4\n");

	return dest;
}

struct fp_ext *
fp_fsincos5(struct fp_ext *dest, struct fp_ext *src)
{
	uprint("fsincos5\n");

	return dest;
}

struct fp_ext *
fp_fsincos6(struct fp_ext *dest, struct fp_ext *src)
{
	uprint("fsincos6\n");

	return dest;
}

struct fp_ext *
fp_fsincos7(struct fp_ext *dest, struct fp_ext *src)
{
	uprint("fsincos7\n");

	return dest;
}

