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
typedef  int unichar ;
typedef  int mp_uint_t ;

/* Variables and functions */
 int FL_ALPHA ; 
 int FL_DIGIT ; 
 int FL_LOWER ; 
 int FL_SPACE ; 
 int FL_UPPER ; 
 int FL_XDIGIT ; 
 int* attr ; 

bool unichar_isspace(unichar c) {
    return c < 128 && (attr[c] & FL_SPACE) != 0;
}

bool unichar_isalpha(unichar c) {
    return c < 128 && (attr[c] & FL_ALPHA) != 0;
}

bool unichar_isdigit(unichar c) {
    return c < 128 && (attr[c] & FL_DIGIT) != 0;
}

bool unichar_isxdigit(unichar c) {
    return c < 128 && (attr[c] & FL_XDIGIT) != 0;
}

bool unichar_isident(unichar c) {
    return c < 128 && ((attr[c] & (FL_ALPHA | FL_DIGIT)) != 0 || c == '_');
}

bool unichar_isupper(unichar c) {
    return c < 128 && (attr[c] & FL_UPPER) != 0;
}

bool unichar_islower(unichar c) {
    return c < 128 && (attr[c] & FL_LOWER) != 0;
}

unichar unichar_tolower(unichar c) {
    if (unichar_isupper(c)) {
        return c + 0x20;
    }
    return c;
}

unichar unichar_toupper(unichar c) {
    if (unichar_islower(c)) {
        return c - 0x20;
    }
    return c;
}

mp_uint_t unichar_xdigit_value(unichar c) {
    // c is assumed to be hex digit
    mp_uint_t n = c - '0';
    if (n > 9) {
        n &= ~('a' - 'A');
        n -= ('A' - ('9' + 1));
    }
    return n;
}

