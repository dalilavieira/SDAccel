#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int ut8 ;
typedef  int ut32 ;
typedef  int ut16 ;
struct TYPE_3__ {unsigned int length; int /*<<< orphan*/  syntax; } ;
typedef  TYPE_1__ tms320_dasm_t ;

/* Variables and functions */
 char* c55plus_decode (int /*<<< orphan*/ ,unsigned int*) ; 
 int /*<<< orphan*/  free (char*) ; 
 int* ins_buff ; 
 int ins_buff_len ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,char*) ; 
 size_t strlen (char*) ; 
 char tolower (unsigned char) ; 

__attribute__((used)) static inline ut16 le16(ut16 v)
{
	ut16 value = v;
#if __BYTE_ORDER__ != __ORDER_LITTLE_ENDIAN__
	ut8 * pv = (void *)&v;
	value = (pv[0] << 8) | pv[1];
#endif
	return value;
}

__attribute__((used)) static inline ut32 le24(ut32 v)
{
	ut32 value = v;
#if __BYTE_ORDER__ != __ORDER_LITTLE_ENDIAN__
	ut8 * pv = (void *)&v;
	value = (pv[0] << 16) | (pv[1] << 8) | pv[2];
#endif
	return value;
}

__attribute__((used)) static inline ut32 le32(ut32 v)
{
	ut32 value = v;
#if __BYTE_ORDER__ != __ORDER_LITTLE_ENDIAN__
	ut8 * pv = (void *)&v;
	value = (pv[0] << 24) | (pv[1] << 16) | (pv[2] << 8) | pv[3];
#endif
	return value;
}

__attribute__((used)) static inline ut16 be16(ut16 v)
{
	ut16 value = v;
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
	ut8 * pv = (void *)&v;
	value = (pv[0] << 8) | pv[1];
#endif
	return value;
}

__attribute__((used)) static inline ut32 be24(ut32 v)
{
	ut32 value = v;
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
	ut8 * pv = (void *)&v;
	value = (pv[0] << 16) | (pv[1] << 8) | pv[2];
#endif
	return value;
}

__attribute__((used)) static inline ut32 be32(ut32 v)
{
	ut32 value = v;
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
	ut8 * pv = (void *)&v;
	value = (pv[0] << 24) | (pv[1] << 16) | (pv[2] << 8) | pv[3];
#endif
	return value;
}

int c55x_plus_disassemble(tms320_dasm_t *dasm, const ut8 *buf, int len) {
	unsigned int next_ins_pos;
	char *ins_decoded;
	size_t i, ins_decoded_len;

	ins_buff = (ut8 *)buf;
	ins_buff_len = (ut32)len;

	next_ins_pos = 0;

	// decode instruction
	ins_decoded = c55plus_decode(0, &next_ins_pos);
	dasm->length = next_ins_pos;
	if (!ins_decoded) {
		return 0;
	}

	// opcode length
	dasm->length = next_ins_pos;
	ins_decoded_len = strlen(ins_decoded);
	for (i = 0; i < ins_decoded_len; i++) {
		{
			ins_decoded[i] = tolower ((unsigned char)ins_decoded[i]);
		}
	}
	snprintf (dasm->syntax, sizeof(dasm->syntax), "%s", ins_decoded);
	free (ins_decoded);
	
	return next_ins_pos;
}

