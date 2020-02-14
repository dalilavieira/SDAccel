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
 int /*<<< orphan*/  _MBGETH (int) ; 
 int /*<<< orphan*/  _MBGETL (int) ; 
 scalar_t__ _MBIS16 (int) ; 
 scalar_t__ _MBLMASK (int) ; 
 int /*<<< orphan*/  _ismbblead (unsigned int) ; 
 scalar_t__ _ismbclower (unsigned int) ; 
 unsigned char* _mbsinc (unsigned char*) ; 
 int _mbsnextc (unsigned char*) ; 
 unsigned int toupper (int) ; 

unsigned int _mbbtoupper(unsigned int c)
{
	if (!_ismbblead(c) )
		return toupper(c);

	return c;
}

unsigned int _mbctoupper(unsigned int c)
{
    return _ismbclower (c) ? c - 0x21 : c;
}

unsigned char *_mbset (unsigned char *string, int c)
{
    unsigned char *save = string;

    if (_MBIS16 (c)) {

	if (_MBLMASK (c) == 0) {
	    *string++ = '\0';
	    *string++ = '\0';
	}
	else {
	    *string++ = _MBGETH (c);
	    *string++ = _MBGETL (c);
	}

    }
    else {

	*string++ = c;

    }

    return save;
}

unsigned char *_mbsupr (unsigned char *string)
{
    int c;
    unsigned char *save = string;

    while ((c = _mbsnextc (string))) {

	if (_MBIS16 (c) == 0)
	    c = toupper (c);

	_mbset (string, c);

	string = _mbsinc (string);

    }

    return save;
}

