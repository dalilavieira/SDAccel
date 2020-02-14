#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {void* low; void* high; } ;
struct TYPE_7__ {int /*<<< orphan*/  all; TYPE_1__ s; } ;
typedef  TYPE_3__ utwords ;
struct TYPE_6__ {int high; int low; } ;
struct TYPE_8__ {int /*<<< orphan*/  all; TYPE_2__ s; } ;
typedef  TYPE_4__ twords ;
typedef  int /*<<< orphan*/  tu_int ;
typedef  int /*<<< orphan*/  ti_int ;
typedef  int int64_t ;
typedef  double const int32_t ;
typedef  void* du_int ;
typedef  int di_int ;

/* Variables and functions */
 int INT64_C (int) ; 

__attribute__((used)) static __inline ti_int make_ti(di_int h, di_int l) {
    twords r;
    r.s.high = h;
    r.s.low = l;
    return r.all;
}

__attribute__((used)) static __inline tu_int make_tu(du_int h, du_int l) {
    utwords r;
    r.s.high = h;
    r.s.low = l;
    return r.all;
}

double
__floatdidf(di_int a)
{
	static const double twop52 = 4503599627370496.0; // 0x1.0p52
	static const double twop32 = 4294967296.0; // 0x1.0p32
	
	union { int64_t x; double d; } low = { .d = twop52 };
	
	const double high = (int32_t)(a >> 32) * twop32;
	low.x |= a & INT64_C(0x00000000ffffffff);
	
	const double result = (high - twop52) + low.d;
	return result;
}

