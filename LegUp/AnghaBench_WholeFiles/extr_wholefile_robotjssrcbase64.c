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
typedef  size_t uint8_t ;
typedef  int int8_t ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int) ; 
 int* b64_decode_table ; 
 size_t* b64_encode_table ; 
 size_t* malloc (size_t const) ; 

uint8_t *base64decode(const uint8_t *src, const size_t buflen, size_t *retlen)
{
	int8_t digit, lastdigit;
	size_t i, j;
	uint8_t *decoded;
	const size_t maxlen = ((buflen + 3) / 4) * 3;

	/* Sanity check */
	assert(src != NULL);

	digit = lastdigit = j = 0;
	decoded = malloc(maxlen + 1);
	if (decoded == NULL) return NULL;
	for (i = 0; i < buflen; ++i) {
		if ((digit = b64_decode_table[src[i]]) != -1) {
			/* Decode block */
			switch (i % 4) {
				case 1:
					decoded[j++] = ((lastdigit << 2) | ((digit & 0x30) >> 4));
					break;
				case 2:
					decoded[j++] = (((lastdigit & 0xF) << 4) | ((digit & 0x3C) >> 2));
					break;
				case 3:
					decoded[j++] = (((lastdigit & 0x03) << 6) | digit);
					break;
			}
			lastdigit = digit;
		}
	}

	if (retlen != NULL) *retlen = j;
	decoded[j] = '\0';
	return decoded; /* Must be free()'d by caller */
}

uint8_t *base64encode(const uint8_t *src, const size_t buflen, size_t *retlen)
{
	size_t i, j;
	const size_t maxlen = (((buflen + 3) & ~3)) * 4;
	uint8_t *encoded = malloc(maxlen + 1);
	if (encoded == NULL) return NULL;

	/* Sanity check */
	assert(src != NULL);
	assert(buflen > 0);

	j = 0;
	for (i = 0; i < buflen + 1; ++i) {
		/* Encode block */
		switch (i % 3) {
			case 0:
				encoded[j++] = b64_encode_table[src[i] >> 2];
				encoded[j++] = b64_encode_table[((src[i] & 0x03) << 4) |
				                                ((src[i + 1] & 0xF0) >> 4)];
				break;
			case 1:
				encoded[j++] = b64_encode_table[((src[i] & 0x0F) << 2) |
				                                ((src[i + 1] & 0xC0) >> 6)];
				break;
			case 2:
				encoded[j++] = b64_encode_table[(src[i] & 0x3F)];
				break;
		}
	}

	/* Add padding if necessary */
	if ((j % 4) != 0) {
		const size_t with_padding = ((j + 3) & ~3); /* Align to 4 bytes */
		do {
			encoded[j++] = '=';
		} while (j < with_padding);
	}

	assert(j <= maxlen);

	if (retlen != NULL) *retlen = j;
	encoded[j] = '\0';
	return encoded; /* Must be free()'d by caller */
}

