#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int ut8 ;
typedef  scalar_t__ ut64 ;
typedef  int /*<<< orphan*/  buf2 ;
struct TYPE_4__ {int (* read_at ) (int /*<<< orphan*/ ,scalar_t__,int*,int) ;int /*<<< orphan*/  io; } ;
struct TYPE_5__ {TYPE_1__ iob; } ;
typedef  TYPE_1__ RIOBind ;
typedef  TYPE_2__ RAnal ;

/* Variables and functions */
 int /*<<< orphan*/  IS_PRINTABLE (int const) ; 
 int MINLEN ; 
 scalar_t__ UT32_MAX ; 
 int /*<<< orphan*/  memcmp (int const*,...) ; 
 scalar_t__ r_mem_get_num (int const*,int) ; 
 int stub1 (int /*<<< orphan*/ ,scalar_t__,int*,int) ; 

__attribute__((used)) static int is_string(const ut8 *buf, int size, int *len) {
	int i;
	if (size < 1) {
		return 0;
	}
	if (size > 3 && buf[0] && !buf[1] && buf[2] && !buf[3]) {
		*len = 1; // XXX: TODO: Measure wide string length
		return 2; // is wide
	}
	for (i = 0; i < size; i++) {
		if (!buf[i] && i > MINLEN) {
			*len = i;
			return 1;
		}
		if (buf[i] == 10 || buf[i] == 13 || buf[i] == 9) {
			continue;
		}
		if (buf[i] < 32 || buf[i] > 127) {
			// not ascii text
			return 0;
		}
		if (!IS_PRINTABLE (buf[i])) {
			*len = i;
			return 0;
		}
	}
	*len = i;
	return 1;
}

__attribute__((used)) static int is_number(const ut8 *buf, int size) {
	ut64 n = r_mem_get_num (buf, size);
	return (n < UT32_MAX)? (int)n: 0;
}

__attribute__((used)) static int is_null(const ut8 *buf, int size) {
	const char zero[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	return (!memcmp (buf, &zero, size))? 1: 0;
}

__attribute__((used)) static int is_invalid(const ut8 *buf, int size) {
	if (size < 1) {
		return 1;
	}
	if (size > 8) {
		size = 8;
	}
	return (!memcmp (buf, "\xff\xff\xff\xff\xff\xff\xff\xff", size))? 1: 0;
}

__attribute__((used)) static ut64 is_pointer(RAnal *anal, const ut8 *buf, int size) {
	ut64 n;
	ut8 buf2[32];
	RIOBind *iob = &anal->iob;
	if (size > sizeof (buf2)) {
		size = sizeof (buf2);
	}
	n = r_mem_get_num (buf, size);
	if (!n) {
		return 1; // null pointer
	}
#if USE_IS_VALID_OFFSET
	int r = iob->is_valid_offset (iob->io, n, 0);
	return r? n: 0LL;
#else
	// optimization to ignore very low and very high pointers
	// this makes disasm 5x faster, but can result in some false positives
	// we should compare with current offset, to avoid
	// short/long references. and discard invalid ones
	if (n < 0x1000) return 0;	// probably wrong
	if (n > 0xffffffffffffLL) return 0; // probably wrong

	if (iob->read_at (iob->io, n, buf2, size) != size) return 0;
	return is_invalid (buf2, size)? 0: n;
#endif
}

__attribute__((used)) static bool is_bin(const ut8 *buf, int size) {
	// TODO: add more magic signatures heres
	if ((size >= 4 && !memcmp (buf, "\xcf\xfa\xed\xfe", 4))) {
		return true;
	}
	if ((size >= 4 && !memcmp (buf, "\x7f\x45\x4c\x46", 4))) { // \x7fELF
		return true;
	}
	if ((size >= 2 && !memcmp (buf, "MZ", 2))) {
		return true;
	}
	return false;
}

