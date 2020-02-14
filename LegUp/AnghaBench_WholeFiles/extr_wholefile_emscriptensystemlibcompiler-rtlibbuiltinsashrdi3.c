#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {void* low; void* high; } ;
struct TYPE_10__ {int /*<<< orphan*/  all; TYPE_2__ s; } ;
typedef  TYPE_4__ utwords ;
struct TYPE_7__ {void* low; void* high; } ;
struct TYPE_11__ {int /*<<< orphan*/  all; TYPE_1__ s; } ;
typedef  TYPE_5__ twords ;
typedef  int /*<<< orphan*/  tu_int ;
typedef  int /*<<< orphan*/  ti_int ;
typedef  int const si_int ;
struct TYPE_9__ {int high; int low; } ;
struct TYPE_12__ {void* all; TYPE_3__ s; } ;
typedef  TYPE_6__ dwords ;
typedef  void* du_int ;
typedef  void* di_int ;

/* Variables and functions */
 int CHAR_BIT ; 

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

di_int
__ashrdi3(di_int a, si_int b)
{
    const int bits_in_word = (int)(sizeof(si_int) * CHAR_BIT);
    dwords input;
    dwords result;
    input.all = a;
    if (b & bits_in_word)  /* bits_in_word <= b < bits_in_dword */
    {
        /* result.s.high = input.s.high < 0 ? -1 : 0 */
        result.s.high = input.s.high >> (bits_in_word - 1);
        result.s.low = input.s.high >> (b - bits_in_word);
    }
    else  /* 0 <= b < bits_in_word */
    {
        if (b == 0)
            return a;
        result.s.high  = input.s.high >> b;
        result.s.low = (input.s.high << (bits_in_word - b)) | (input.s.low >> b);
    }
    return result.all;
}

