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
 int /*<<< orphan*/  _MBGETH (unsigned int) ; 
 int /*<<< orphan*/  _MBGETL (unsigned int) ; 
 scalar_t__ _MBHMASK (unsigned int) ; 
 int _ismbbalnum (unsigned int) ; 
 scalar_t__ _ismbbkana (unsigned int) ; 
 scalar_t__ _ismbblead (int /*<<< orphan*/ ) ; 
 scalar_t__ _ismbbtrail (int /*<<< orphan*/ ) ; 
 int _ismbclegal (unsigned int) ; 
 scalar_t__ _ismbclower (unsigned int) ; 
 scalar_t__ _ismbcupper (unsigned int) ; 
 scalar_t__ isprint (unsigned int) ; 

int _ismbcalnum( unsigned int c )
{
	if ((c & 0xFF00) != 0) {
		// true multibyte character
		return 0;
	}
	else
		return _ismbbalnum(c);

	return 0;
}

int _ismbcalpha( unsigned int c )
{
	return (_ismbcupper (c) || _ismbclower (c));
}

int _ismbcdigit( unsigned int c )
{
	return ((c) >= 0x824f && (c) <= 0x8258);
}

int _ismbcprint( unsigned int c )
{
    return (_MBHMASK (c) ? _ismbclegal (c) : (isprint (c) || _ismbbkana (c)));
}

int _ismbcsymbol( unsigned int c )
{
	return (c >= 0x8141 && c <= 0x817e) || (c >= 0x8180 && c <= 0x81ac);
}

int _ismbcspace( unsigned int c )
{
	return ((c) == 0x8140);
}

int _ismbclegal(unsigned int c)
{
	return (_ismbblead (_MBGETH (c)) && _ismbbtrail (_MBGETL (c)));
}

int _ismbcl0(unsigned int c)
{
  return (c >= 0x8140 && c <= 0x889e);
}

int _ismbcl1(unsigned int c)
{
  return (c >= 0x889f && c <= 0x9872);
}

int _ismbcl2(unsigned int c)
{
  return (c >= 0x989f && c <= 0xea9e);
}

int _ismbcgraph(unsigned int ch)
{
    //wchar_t wch = msvcrt_mbc_to_wc( ch );
    //return (get_char_typeW( wch ) & (C1_UPPER | C1_LOWER | C1_DIGIT | C1_PUNCT | C1_ALPHA));
    return 0;
}

int _ismbcpunct(unsigned int ch)
{
    //wchar_t wch = msvcrt_mbc_to_wc( ch );
    //return (get_char_typeW( wch ) & C1_PUNCT);
    return 0;
}

