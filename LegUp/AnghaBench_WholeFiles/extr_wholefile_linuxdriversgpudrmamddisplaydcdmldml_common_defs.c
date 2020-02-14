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
 scalar_t__ dcn_bw_ceil2 (double,double) ; 
 scalar_t__ dcn_bw_floor2 (double,double) ; 
 scalar_t__ dcn_bw_log (double,double) ; 
 scalar_t__ dcn_bw_max2 (double,double) ; 
 scalar_t__ dcn_bw_min2 (double,double) ; 
 scalar_t__ dcn_bw_mod (double,int) ; 
 scalar_t__ dcn_bw_pow (double,int) ; 
 double dml_round (double) ; 

__attribute__((used)) static inline double dml_min(double a, double b)
{
	return (double) dcn_bw_min2(a, b);
}

__attribute__((used)) static inline double dml_min3(double a, double b, double c)
{
	return dml_min(dml_min(a, b), c);
}

__attribute__((used)) static inline double dml_min4(double a, double b, double c, double d)
{
	return dml_min(dml_min(a, b), dml_min(c, d));
}

__attribute__((used)) static inline double dml_max(double a, double b)
{
	return (double) dcn_bw_max2(a, b);
}

__attribute__((used)) static inline double dml_max3(double a, double b, double c)
{
	return dml_max(dml_max(a, b), c);
}

__attribute__((used)) static inline double dml_max4(double a, double b, double c, double d)
{
	return dml_max(dml_max(a, b), dml_max(c, d));
}

__attribute__((used)) static inline double dml_max5(double a, double b, double c, double d, double e)
{
	return dml_max(dml_max4(a, b, c, d), e);
}

__attribute__((used)) static inline double dml_ceil(double a, double granularity)
{
	return (double) dcn_bw_ceil2(a, granularity);
}

__attribute__((used)) static inline double dml_floor(double a, double granularity)
{
	return (double) dcn_bw_floor2(a, granularity);
}

__attribute__((used)) static inline int dml_log2(double x)
{
	return dml_round((double)dcn_bw_log(x, 2));
}

__attribute__((used)) static inline double dml_pow(double a, int exp)
{
	return (double) dcn_bw_pow(a, exp);
}

__attribute__((used)) static inline double dml_fmod(double f, int val)
{
	return (double) dcn_bw_mod(f, val);
}

__attribute__((used)) static inline double dml_ceil_2(double f)
{
	return (double) dcn_bw_ceil2(f, 2);
}

__attribute__((used)) static inline double dml_ceil_ex(double x, double granularity)
{
	return (double) dcn_bw_ceil2(x, granularity);
}

__attribute__((used)) static inline double dml_floor_ex(double x, double granularity)
{
	return (double) dcn_bw_floor2(x, granularity);
}

__attribute__((used)) static inline double dml_log(double x, double base)
{
	return (double) dcn_bw_log(x, base);
}

__attribute__((used)) static inline unsigned int dml_round_to_multiple(unsigned int num,
						 unsigned int multiple,
						 bool up)
{
	unsigned int remainder;

	if (multiple == 0)
		return num;

	remainder = num % multiple;

	if (remainder == 0)
		return num;

	if (up)
		return (num + multiple - remainder);
	else
		return (num - remainder);
}

double dml_round(double a)
{
	double round_pt = 0.5;
	double ceil = dml_ceil(a, 1);
	double floor = dml_floor(a, 1);

	if (a - floor >= round_pt)
		return ceil;
	else
		return floor;
}

