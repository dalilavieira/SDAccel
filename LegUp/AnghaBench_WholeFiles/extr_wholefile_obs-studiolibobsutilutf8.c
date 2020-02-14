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
typedef  int wchar_t ;

/* Variables and functions */
 int UTF8_IGNORE_ERROR ; 
 int UTF8_SKIP_BOM ; 
 int _BOM ; 
 unsigned char _NXT ; 
 unsigned char _SEQ2 ; 
 unsigned char _SEQ3 ; 
 unsigned char _SEQ4 ; 
 unsigned char _SEQ5 ; 
 unsigned char _SEQ6 ; 

__attribute__((used)) static int wchar_forbidden(wchar_t sym)
{
	/* Surrogate pairs */
	if (sym >= 0xd800 && sym <= 0xdfff)
		return -1;

	return 0;
}

__attribute__((used)) static int utf8_forbidden(unsigned char octet)
{
	switch (octet) {
	case 0xc0:
	case 0xc1:
	case 0xf5:
	case 0xff:
		return -1;
	}

	return 0;
}

size_t utf8_to_wchar(const char *in, size_t insize, wchar_t *out,
		size_t outsize, int flags)
{
	unsigned char *p, *lim;
	wchar_t *wlim, high;
	size_t n, total, i, n_bits;

	if (in == NULL || (outsize == 0 && out != NULL))
		return 0;

	total = 0;
	p = (unsigned char *)in;
	lim = (insize != 0) ? (p + insize) : (unsigned char*)-1;
	wlim = out + outsize;

	for (; p < lim; p += n) {
		if (!*p)
			break;

		if (utf8_forbidden(*p) != 0 &&
		    (flags & UTF8_IGNORE_ERROR) == 0)
			return 0;

		/*
		 * Get number of bytes for one wide character.
		 */
		n = 1;	/* default: 1 byte. Used when skipping bytes. */
		if ((*p & 0x80) == 0)
			high = (wchar_t)*p;
		else if ((*p & 0xe0) == _SEQ2) {
			n = 2;
			high = (wchar_t)(*p & 0x1f);
		} else if ((*p & 0xf0) == _SEQ3) {
			n = 3;
			high = (wchar_t)(*p & 0x0f);
		} else if ((*p & 0xf8) == _SEQ4) {
			n = 4;
			high = (wchar_t)(*p & 0x07);
		} else if ((*p & 0xfc) == _SEQ5) {
			n = 5;
			high = (wchar_t)(*p & 0x03);
		} else if ((*p & 0xfe) == _SEQ6) {
			n = 6;
			high = (wchar_t)(*p & 0x01);
		} else {
			if ((flags & UTF8_IGNORE_ERROR) == 0)
				return 0;
			continue;
		}

		/* does the sequence header tell us truth about length? */
		if ((size_t)(lim - p) <= n - 1) {
			if ((flags & UTF8_IGNORE_ERROR) == 0)
				return 0;
			n = 1;
			continue;	/* skip */
		}

		/*
		 * Validate sequence.
		 * All symbols must have higher bits set to 10xxxxxx
		 */
		if (n > 1) {
			for (i = 1; i < n; i++) {
				if ((p[i] & 0xc0) != _NXT)
					break;
			}
			if (i != n) {
				if ((flags & UTF8_IGNORE_ERROR) == 0)
					return 0;
				n = 1;
				continue;	/* skip */
			}
		}

		total++;

		if (out == NULL)
			continue;

		if (out >= wlim)
			return 0;		/* no space left */

		*out = 0;
		n_bits = 0;
		for (i = 1; i < n; i++) {
			*out |= (wchar_t)(p[n - i] & 0x3f) << n_bits;
			n_bits += 6;		/* 6 low bits in every byte */
		}
		*out |= high << n_bits;

		if (wchar_forbidden(*out) != 0) {
			if ((flags & UTF8_IGNORE_ERROR) == 0)
				return 0;	/* forbidden character */
			else {
				total--;
				out--;
			}
		} else if (*out == _BOM && (flags & UTF8_SKIP_BOM) != 0) {
			total--;
			out--;
		}

		out++;
	}

	return total;
}

size_t wchar_to_utf8(const wchar_t *in, size_t insize, char *out,
		size_t outsize, int flags)
{
	wchar_t *w, *wlim, ch = 0;
	unsigned char *p, *lim, *oc;
	size_t total, n;

	if (in == NULL || (outsize == 0 && out != NULL))
		return 0;

	w = (wchar_t *)in;
	wlim = (insize != 0) ? (w + insize) : (wchar_t*)-1;
	p = (unsigned char *)out;
	lim = p + outsize;
	total = 0;

	for (; w < wlim; w++) {
		if (!*w)
			break;

		if (wchar_forbidden(*w) != 0) {
			if ((flags & UTF8_IGNORE_ERROR) == 0)
				return 0;
			else
				continue;
		}

		if (*w == _BOM && (flags & UTF8_SKIP_BOM) != 0)
			continue;

		if (*w < 0) {
			if ((flags & UTF8_IGNORE_ERROR) == 0)
				return 0;
			continue;
		} else if (*w <= 0x0000007f)
			n = 1;
		else if (*w <= 0x000007ff)
			n = 2;
		else if (*w <= 0x0000ffff)
			n = 3;
		else if (*w <= 0x001fffff)
			n = 4;
		else if (*w <= 0x03ffffff)
			n = 5;
		else /* if (*w <= 0x7fffffff) */
			n = 6;

		total += n;

		if (out == NULL)
			continue;

		if ((size_t)(lim - p) <= n - 1)
			return 0;		/* no space left */

		ch = *w;
		oc = (unsigned char *)&ch;
		switch (n) {
		case 1:
			*p = oc[0];
			break;

		case 2:
			p[1] = _NXT | (oc[0] & 0x3f);
			p[0] = _SEQ2 | (oc[0] >> 6) | ((oc[1] & 0x07) << 2);
			break;

		case 3:
			p[2] = _NXT | (oc[0] & 0x3f);
			p[1] = _NXT | (oc[0] >> 6) | ((oc[1] & 0x0f) << 2);
			p[0] = _SEQ3 | ((oc[1] & 0xf0) >> 4);
			break;

		case 4:
			p[3] = _NXT | (oc[0] & 0x3f);
			p[2] = _NXT | (oc[0] >> 6) | ((oc[1] & 0x0f) << 2);
			p[1] = _NXT | ((oc[1] & 0xf0) >> 4) |
			    ((oc[2] & 0x03) << 4);
			p[0] = _SEQ4 | ((oc[2] & 0x1f) >> 2);
			break;

		case 5:
			p[4] = _NXT | (oc[0] & 0x3f);
			p[3] = _NXT | (oc[0] >> 6) | ((oc[1] & 0x0f) << 2);
			p[2] = _NXT | ((oc[1] & 0xf0) >> 4) |
			    ((oc[2] & 0x03) << 4);
			p[1] = _NXT | (oc[2] >> 2);
			p[0] = _SEQ5 | (oc[3] & 0x03);
			break;

		case 6:
			p[5] = _NXT | (oc[0] & 0x3f);
			p[4] = _NXT | (oc[0] >> 6) | ((oc[1] & 0x0f) << 2);
			p[3] = _NXT | (oc[1] >> 4) | ((oc[2] & 0x03) << 4);
			p[2] = _NXT | (oc[2] >> 2);
			p[1] = _NXT | (oc[3] & 0x3f);
			p[0] = _SEQ6 | ((oc[3] & 0x40) >> 6);
			break;
		}

		/*
		 * NOTE: do not check here for forbidden UTF-8 characters.
		 * They cannot appear here because we do proper conversion.
		 */

		p += n;
	}

	return total;
}

