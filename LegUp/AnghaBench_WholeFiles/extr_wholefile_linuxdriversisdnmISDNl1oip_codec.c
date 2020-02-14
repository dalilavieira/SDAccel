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
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;

/* Variables and functions */
 int ENOMEM ; 
 int* _4bit_to_alaw ; 
 int* _4bit_to_ulaw ; 
 int* alaw_to_4bit ; 
 int /*<<< orphan*/ * alaw_to_ulaw ; 
 int* table_com ; 
 int* table_dec ; 
 int* ulaw_to_4bit ; 
 int /*<<< orphan*/ * ulaw_to_alaw ; 
 int /*<<< orphan*/  vfree (int*) ; 
 int* vzalloc (int) ; 

int
l1oip_law_to_4bit(u8 *data, int len, u8 *result, u32 *state)
{
	int ii, i = 0, o = 0;

	if (!len)
		return 0;

	/* send saved byte and first input byte */
	if (*state) {
		*result++ = table_com[(((*state) << 8) & 0xff00) | (*data++)];
		len--;
		o++;
	}

	ii = len >> 1;

	while (i < ii) {
		*result++ = table_com[(data[0]<<8) | (data[1])];
		data += 2;
		i++;
		o++;
	}

	/* if len has an odd number, we save byte for next call */
	if (len & 1)
		*state = 0x100 + *data;
	else
		*state = 0;

	return o;
}

int
l1oip_4bit_to_law(u8 *data, int len, u8 *result)
{
	int i = 0;
	u16 r;

	while (i < len) {
		r = table_dec[*data++];
		*result++ = r >> 8;
		*result++ = r;
		i++;
	}

	return len << 1;
}

int
l1oip_alaw_to_ulaw(u8 *data, int len, u8 *result)
{
	int i = 0;

	while (i < len) {
		*result++ = alaw_to_ulaw[*data++];
		i++;
	}

	return len;
}

int
l1oip_ulaw_to_alaw(u8 *data, int len, u8 *result)
{
	int i = 0;

	while (i < len) {
		*result++ = ulaw_to_alaw[*data++];
		i++;
	}

	return len;
}

void
l1oip_4bit_free(void)
{
	vfree(table_dec);
	vfree(table_com);
	table_com = NULL;
	table_dec = NULL;
}

int
l1oip_4bit_alloc(int ulaw)
{
	int i1, i2, c, sample;

	/* in case, it is called again */
	if (table_dec)
		return 0;

	/* alloc conversion tables */
	table_com = vzalloc(65536);
	table_dec = vzalloc(512);
	if (!table_com || !table_dec) {
		l1oip_4bit_free();
		return -ENOMEM;
	}
	/* generate compression table */
	i1 = 0;
	while (i1 < 256) {
		if (ulaw)
			c = ulaw_to_4bit[i1];
		else
			c = alaw_to_4bit[i1];
		i2 = 0;
		while (i2 < 256) {
			table_com[(i1 << 8) | i2] |= (c << 4);
			table_com[(i2 << 8) | i1] |= c;
			i2++;
		}
		i1++;
	}

	/* generate decompression table */
	i1 = 0;
	while (i1 < 16) {
		if (ulaw)
			sample = _4bit_to_ulaw[i1];
		else
			sample = _4bit_to_alaw[i1];
		i2 = 0;
		while (i2 < 16) {
			table_dec[(i1 << 4) | i2] |= (sample << 8);
			table_dec[(i2 << 4) | i1] |= sample;
			i2++;
		}
		i1++;
	}

	return 0;
}

