#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {char const* name; } ;
struct TYPE_6__ {int bits; int* out; } ;
typedef  TYPE_1__ Bitbuf ;

/* Variables and functions */
 int NOPS ; 
 int /*<<< orphan*/  SKIPSPACES (char const*) ; 
 TYPE_2__* opcodes ; 
 int /*<<< orphan*/  strcmp (char const*,char const*) ; 

__attribute__((used)) static const char *skipspaces(const char *x) { SKIPSPACES(x); return x; }

__attribute__((used)) static int getreg(const char *s) {
	if (s[0]=='r' && s[2]=='\0') {
		int n = s[1]-'0';
		if (n<8) return n;
	}
	return -1;
}

__attribute__((used)) static int bitget(Bitbuf *bb, int bit) {
	if (bit>=bb->bits) return -1;
	return (bb->out[bit/8] & (1<<((bit%8))))? 1: 0;
}

__attribute__((used)) static void bitadd(Bitbuf *bb, unsigned int v, int n) {
	int i, b, bit;
	for (i=0; i<n; i++, bb->bits++) {
		b = (bb->bits+i)/8;
		bit = (bb->bits+i)%8;
//printf ("[%d].%d = %d\n", b, bit, v& (1<<(n-i-1)));
		if (!bit) bb->out[b] = 0;
//printf ("BIT (%d)\n", n-i-1);
		//if (v&(1<<(n-i-1))) bb->out[b] |= 1<<bit;
		if (v&(1<<(n-i-1))) bb->out[b] |= 1<<bit;
	//	printf ("%d", oz);
	}
	//printf ("\n");
}

__attribute__((used)) static int bitnum (Bitbuf *bb, int n, int c) {
	int i, ret = 0;
	if (n<bb->bits)
		for (i=0; i<c; i++)
			if (bitget (bb, n+i)>0)
				ret |= (1<<(c-i-1));
	return ret;
}

__attribute__((used)) static inline const char *opcode_str (int n) {
	if (n>=0 && n<NOPS)
		return opcodes[n].name;
	return NULL;
}

__attribute__((used)) static inline int opcode_num (const char *s) {
	int i;
	for (i=0; opcodes[i].name; i++)
		if (!strcmp (s, opcodes[i].name))
			return i;
	return -1;
}

