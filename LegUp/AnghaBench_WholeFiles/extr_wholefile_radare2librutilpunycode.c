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
typedef  int ut8 ;
typedef  int ut32 ;

/* Variables and functions */
 int BASE ; 
 int DAMP ; 
 scalar_t__ IS_DIGIT (int) ; 
 int SKEW ; 
 int TMAX ; 
 int TMIN ; 
 int UT32_MAX ; 
 int* calloc (int,int) ; 
 int /*<<< orphan*/  eprintf (char*) ; 
 int /*<<< orphan*/  free (int*) ; 
 int strlen (char const*) ; 

int utf32len (ut32 *input) {
	int i = 0;
	while (*(input + i)) {
		i++;
	}
	return i;
}

ut8 *utf32toutf8 (ut32 *input) {
	if (!input) {
		eprintf ("ERROR input is null\n");
		return NULL;
	}

	int i = 0;
	int j = 0;
	int len = utf32len (input);
	ut8 *result = calloc (4, len + 1);
	if (!result) {
		eprintf ("ERROR: out of memory\n");
		return NULL;
	}

	for (i = 0; i < len; i++) {
		if (input[i] < 0x80) {
			result[j] = input[i];
			j++;
		} else if (input[i] < 0x800) {
			result[j + 1] = 0x80 | (input[i] & 0x3f);
			result[j] = 0xc0 | ((input[i] >> 6) & 0x1f);
			j += 2;
		} else if (input[i] < 0x10000) {
			result[j + 2] = 0x80 | (input[i] & 0x3f);
			result[j + 1] = 0x80 | ((input[i] >> 6) & 0x3f);
			result[j] = 0xe0 | ((input[i] >> 12) & 0xf);
			j += 3;
		} else if (input[i] < 0x200000) {
			result[j + 3] = 0x80 | (input[i] & 0x3f);
			result[j + 2] = 0x80 | ((input[i] >> 6) & 0x3f);
			result[j + 1] = 0x80 | ((input[i] >> 12) & 0x3f);
			result[j] = 0xf0 | ((input[i] >> 18) & 0x7);
			j += 4;
		} else {
			eprintf ("ERROR in toutf8. Seems like input is invalid\n");
			free (result);
			return NULL;
		}
	}

	result[j] = 0;
	return result;
}

ut32 *utf8toutf32 (const ut8 *input) {
	if (!input) {
		eprintf ("ERROR input is null\n");
		return NULL;
	}

	int i = 0;
	int j = 0;
	int val = 0;
	int len = strlen ((const char *) input);
	ut32 *result = calloc (strlen ((const char *) input) + 1, 4);

	if (!result) {
		eprintf ("ERROR: out of memory\n");
		return NULL;
	}

	while (i < len) {
		if (input[i] >> 7 == 0) {
			val = input[i];
			i += 1;
		} else if (input[i] >> 5 == 0x6) {
			val = (((input[i] & 0x1f) << 6) & 0xfc0) |
			(input[i + 1] & 0x3f);
			i += 2;
		} else if (input[i] >> 4 == 0xe) {
			val = (((input[i] & 0xf) << 12) & 0xf000) |
			(((input[i + 1] & 0x3f) << 6) & 0xffc0) |
			(input[i + 2] & 0x3f);
			i += 3;
		} else if (input[i] >> 3 == 0x1e) {
			val = (((input[i] & 0xf) << 18) & 0x1c0000) |
			(((input[i + 1] & 0x3f) << 12) & 0x1ff000) |
			(((input[i + 2] & 0x3f) << 6) & 0x1fffc0) |
			(input[i + 3] & 0x3f);
			i += 4;
		} else {
			eprintf ("ERROR in toutf32. Seems like input is invalid.\n");
			free (result);
			return NULL;
		}
		result[j] = val;
		j++;
	}

	return result;
}

ut32 adapt_bias(ut32 delta, unsigned n_points, int is_first) {
	ut32 k = 0;
	delta /= is_first? DAMP: 2;
	delta += delta / n_points;

	while (delta > ((BASE - TMIN) * TMAX) / 2) {
		delta /= (BASE - TMIN);
		k += BASE;
	}

	return k + (((BASE - TMIN + 1) * delta) / (delta + SKEW));
}

char encode_digit(int c) {
//	assert (c >= 0 && c <= BASE - TMIN);
	if (c > 25) {
		return c + 22;
	}
	return c + 'a';
}

__attribute__((used)) static ut32 encode_var_int(const ut32 bias, const ut32 delta, char *dst) {
	ut32 i, k, q, t;
	i = 0;
	k = BASE;
	q = delta;

	while (true) {
		if (k <= bias) {
			t = TMIN;
		} else if (k >= bias + TMAX) {
			t = TMAX;
		} else {
			t = k - bias;
		}

		if (q < t) {
			break;
		}

		dst[i++] = encode_digit (t + (q - t) % (BASE - t));

		q = (q - t) / (BASE - t);
		k += BASE;
	}

	dst[i++] = encode_digit (q);

	return i;
}

__attribute__((used)) static ut32 decode_digit(ut32 v) {
	if (IS_DIGIT (v)) {
		return v - 22;
	}
	if (v >= 'a' && v <= 'z') {
		return v - 'a';
	}
	if (v >= 'A' && v <= 'Z') {
		return v - 'A';
	}
	return UT32_MAX;
}

