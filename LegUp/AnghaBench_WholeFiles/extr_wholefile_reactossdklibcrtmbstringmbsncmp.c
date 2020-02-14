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
 int _ismbblead (unsigned char) ; 

int _mbsncmp(const unsigned char *str1, const unsigned char *str2, size_t n)
{
	unsigned char *s1 = (unsigned char *)str1;
	unsigned char *s2 = (unsigned char *)str2;

	unsigned short *short_s1, *short_s2;

	int l1, l2;

	if (n == 0)
		return 0;
	do {

		if (*s1 == 0)
			break;

		l1 = _ismbblead(*s1);
		l2 = _ismbblead(*s2);
		if ( !l1 &&  !l2  ) {

			if (*s1 != *s2)
				return *s1 - *s2;
			else {
				s1 += 1;
				s2 += 1;
				n--;
			}
		}
		else if ( l1 && l2 ){
			short_s1 = (unsigned short *)s1;
			short_s2 = (unsigned short *)s2;
			if ( *short_s1 != *short_s2 )
				return *short_s1 - *short_s2;
			else {
				s1 += 2;
				s2 += 2;
				n--;

			}
		}
		else
			return *s1 - *s2;
	} while (n > 0);
	return 0;
}

int _mbsnbcmp(const unsigned char *str1, const unsigned char *str2, size_t n)
{
	unsigned char *s1 = (unsigned char *)str1;
	unsigned char *s2 = (unsigned char *)str2;

	unsigned short *short_s1, *short_s2;

	int l1, l2;

	if (n == 0)
		return 0;
	do {

		if (*s1 == 0)
			break;

		l1 = _ismbblead(*s1);
		l2 = _ismbblead(*s2);
		if ( !l1 &&  !l2  ) {

			if (*s1 != *s2)
				return *s1 - *s2;
			else {
				s1 += 1;
				s2 += 1;
				n--;
			}
		}
		else if ( l1 && l2 ){
			short_s1 = (unsigned short *)s1;
			short_s2 = (unsigned short *)s2;
			if ( *short_s1 != *short_s2 )
				return *short_s1 - *short_s2;
			else {
				s1 += 2;
				s2 += 2;
				n-=2;

			}
		}
		else
			return *s1 - *s2;
	} while (n > 0);
	return 0;
}

