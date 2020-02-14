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
typedef  int uint8_t ;
typedef  int uint64_t ;
typedef  unsigned long uint32_t ;
struct dc_state {int val; char* name; } ;

/* Variables and functions */
 int /*<<< orphan*/  A_BUS_L2_ERRORS ; 
 int /*<<< orphan*/  A_BUS_MEM_IO_ERRORS ; 
 int /*<<< orphan*/  A_SCD_BUS_ERR_STATUS ; 
 unsigned int CP0_CERRD_CAUSES ; 
#define  CP0_CERRD_COHERENCY 132 
 unsigned int CP0_CERRD_DATA_DBE ; 
 unsigned int CP0_CERRD_DATA_SBE ; 
#define  CP0_CERRD_DUPTAG 131 
 unsigned int CP0_CERRD_EXTERNAL ; 
#define  CP0_CERRD_FILLWB 130 
#define  CP0_CERRD_LOAD 129 
 unsigned int CP0_CERRD_MULTIPLE ; 
#define  CP0_CERRD_STORE 128 
 unsigned int CP0_CERRD_TAG_ADDRESS ; 
 unsigned int CP0_CERRD_TAG_STATE ; 
 unsigned int CP0_CERRD_TYPES ; 
 unsigned int CP0_CERRI_DATA_PARITY ; 
 unsigned int CP0_CERRI_EXTERNAL ; 
 unsigned int CP0_CERRI_TAG_PARITY ; 
 unsigned int CP0_ERRCTL_DCACHE ; 
 unsigned int CP0_ERRCTL_ICACHE ; 
 unsigned int CP0_ERRCTL_MULTIBUS ; 
 unsigned int CP0_ERRCTL_RECOVERABLE ; 
 int DC_TAG_VALID (unsigned char) ; 
 scalar_t__ G_SCD_BERR_DCODE (unsigned long) ; 
 scalar_t__ G_SCD_BERR_RID (unsigned long) ; 
 int G_SCD_BERR_TID (unsigned long) ; 
 int /*<<< orphan*/  IOADDR (int /*<<< orphan*/ ) ; 
 unsigned long csr_in32 (int /*<<< orphan*/ ) ; 
 struct dc_state* dc_states ; 
 int hweight8 (int) ; 
 int* mask_72_64 ; 
 int* parity ; 
 int /*<<< orphan*/  printk (char*,...) ; 

__attribute__((used)) static inline void breakout_errctl(unsigned int val)
{
	if (val & CP0_ERRCTL_RECOVERABLE)
		printk(" recoverable");
	if (val & CP0_ERRCTL_DCACHE)
		printk(" dcache");
	if (val & CP0_ERRCTL_ICACHE)
		printk(" icache");
	if (val & CP0_ERRCTL_MULTIBUS)
		printk(" multiple-buserr");
	printk("\n");
}

__attribute__((used)) static inline void breakout_cerri(unsigned int val)
{
	if (val & CP0_CERRI_TAG_PARITY)
		printk(" tag-parity");
	if (val & CP0_CERRI_DATA_PARITY)
		printk(" data-parity");
	if (val & CP0_CERRI_EXTERNAL)
		printk(" external");
	printk("\n");
}

__attribute__((used)) static inline void breakout_cerrd(unsigned int val)
{
	switch (val & CP0_CERRD_CAUSES) {
	case CP0_CERRD_LOAD:
		printk(" load,");
		break;
	case CP0_CERRD_STORE:
		printk(" store,");
		break;
	case CP0_CERRD_FILLWB:
		printk(" fill/wb,");
		break;
	case CP0_CERRD_COHERENCY:
		printk(" coherency,");
		break;
	case CP0_CERRD_DUPTAG:
		printk(" duptags,");
		break;
	default:
		printk(" NO CAUSE,");
		break;
	}
	if (!(val & CP0_CERRD_TYPES))
		printk(" NO TYPE");
	else {
		if (val & CP0_CERRD_MULTIPLE)
			printk(" multi-err");
		if (val & CP0_CERRD_TAG_STATE)
			printk(" tag-state");
		if (val & CP0_CERRD_TAG_ADDRESS)
			printk(" tag-address");
		if (val & CP0_CERRD_DATA_SBE)
			printk(" data-SBE");
		if (val & CP0_CERRD_DATA_DBE)
			printk(" data-DBE");
		if (val & CP0_CERRD_EXTERNAL)
			printk(" external");
	}
	printk("\n");
}

__attribute__((used)) static void check_bus_watcher(void)
{
	uint32_t status, l2_err, memio_err;
#ifdef DUMP_L2_ECC_TAG_ON_ERROR
	uint64_t l2_tag;
#endif

	/* Destructive read, clears register and interrupt */
	status = csr_in32(IOADDR(A_SCD_BUS_ERR_STATUS));
	/* Bit 31 is always on, but there's no #define for that */
	if (status & ~(1UL << 31)) {
		l2_err = csr_in32(IOADDR(A_BUS_L2_ERRORS));
#ifdef DUMP_L2_ECC_TAG_ON_ERROR
		l2_tag = in64(IOADDR(A_L2_ECC_TAG));
#endif
		memio_err = csr_in32(IOADDR(A_BUS_MEM_IO_ERRORS));
		printk("Bus watcher error counters: %08x %08x\n", l2_err, memio_err);
		printk("\nLast recorded signature:\n");
		printk("Request %02x from %d, answered by %d with Dcode %d\n",
		       (unsigned int)(G_SCD_BERR_TID(status) & 0x3f),
		       (int)(G_SCD_BERR_TID(status) >> 6),
		       (int)G_SCD_BERR_RID(status),
		       (int)G_SCD_BERR_DCODE(status));
#ifdef DUMP_L2_ECC_TAG_ON_ERROR
		printk("Last L2 tag w/ bad ECC: %016llx\n", l2_tag);
#endif
	} else {
		printk("Bus watcher indicates no error\n");
	}
}

__attribute__((used)) static char range_parity(uint64_t dword, int max, int min)
{
	char parity = 0;
	int i;
	dword >>= min;
	for (i=max-min; i>=0; i--) {
		if (dword & 0x1)
			parity = !parity;
		dword >>= 1;
	}
	return parity;
}

__attribute__((used)) static unsigned char inst_parity(uint32_t word)
{
	int i, j;
	char parity = 0;
	for (j=0; j<4; j++) {
		char byte_parity = 0;
		for (i=0; i<8; i++) {
			if (word & 0x80000000)
				byte_parity = !byte_parity;
			word <<= 1;
		}
		parity <<= 1;
		parity |= byte_parity;
	}
	return parity;
}

__attribute__((used)) static uint32_t extract_ic(unsigned short addr, int data)
{
	unsigned short way;
	int valid;
	uint32_t taghi, taglolo, taglohi;
	unsigned long long taglo, va;
	uint64_t tlo_tmp;
	uint8_t lru;
	int res = 0;

	printk("Icache index 0x%04x  ", addr);
	for (way = 0; way < 4; way++) {
		/* Index-load-tag-I */
		__asm__ __volatile__ (
		"	.set	push		\n\t"
		"	.set	noreorder	\n\t"
		"	.set	mips64		\n\t"
		"	.set	noat		\n\t"
		"	cache	4, 0(%3)	\n\t"
		"	mfc0	%0, $29		\n\t"
		"	dmfc0	$1, $28		\n\t"
		"	dsrl32	%1, $1, 0	\n\t"
		"	sll	%2, $1, 0	\n\t"
		"	.set	pop"
		: "=r" (taghi), "=r" (taglohi), "=r" (taglolo)
		: "r" ((way << 13) | addr));

		taglo = ((unsigned long long)taglohi << 32) | taglolo;
		if (way == 0) {
			lru = (taghi >> 14) & 0xff;
			printk("[Bank %d Set 0x%02x]  LRU > %d %d %d %d > MRU\n",
				    ((addr >> 5) & 0x3), /* bank */
				    ((addr >> 7) & 0x3f), /* index */
				    (lru & 0x3),
				    ((lru >> 2) & 0x3),
				    ((lru >> 4) & 0x3),
				    ((lru >> 6) & 0x3));
		}
		va = (taglo & 0xC0000FFFFFFFE000ULL) | addr;
		if ((taglo & (1 << 31)) && (((taglo >> 62) & 0x3) == 3))
			va |= 0x3FFFF00000000000ULL;
		valid = ((taghi >> 29) & 1);
		if (valid) {
			tlo_tmp = taglo & 0xfff3ff;
			if (((taglo >> 10) & 1) ^ range_parity(tlo_tmp, 23, 0)) {
				printk("   ** bad parity in VTag0/G/ASID\n");
				res |= CP0_CERRI_TAG_PARITY;
			}
			if (((taglo >> 11) & 1) ^ range_parity(taglo, 63, 24)) {
				printk("   ** bad parity in R/VTag1\n");
				res |= CP0_CERRI_TAG_PARITY;
			}
		}
		if (valid ^ ((taghi >> 27) & 1)) {
			printk("   ** bad parity for valid bit\n");
			res |= CP0_CERRI_TAG_PARITY;
		}
		printk(" %d  [VA %016llx]  [Vld? %d]  raw tags: %08X-%016llX\n",
			    way, va, valid, taghi, taglo);

		if (data) {
			uint32_t datahi, insta, instb;
			uint8_t predecode;
			int offset;

			/* (hit all banks and ways) */
			for (offset = 0; offset < 4; offset++) {
				/* Index-load-data-I */
				__asm__ __volatile__ (
				"	.set	push\n\t"
				"	.set	noreorder\n\t"
				"	.set	mips64\n\t"
				"	.set	noat\n\t"
				"	cache	6, 0(%3)  \n\t"
				"	mfc0	%0, $29, 1\n\t"
				"	dmfc0  $1, $28, 1\n\t"
				"	dsrl32 %1, $1, 0 \n\t"
				"	sll    %2, $1, 0 \n\t"
				"	.set	pop	    \n"
				: "=r" (datahi), "=r" (insta), "=r" (instb)
				: "r" ((way << 13) | addr | (offset << 3)));
				predecode = (datahi >> 8) & 0xff;
				if (((datahi >> 16) & 1) != (uint32_t)range_parity(predecode, 7, 0)) {
					printk("   ** bad parity in predecode\n");
					res |= CP0_CERRI_DATA_PARITY;
				}
				/* XXXKW should/could check predecode bits themselves */
				if (((datahi >> 4) & 0xf) ^ inst_parity(insta)) {
					printk("   ** bad parity in instruction a\n");
					res |= CP0_CERRI_DATA_PARITY;
				}
				if ((datahi & 0xf) ^ inst_parity(instb)) {
					printk("   ** bad parity in instruction b\n");
					res |= CP0_CERRI_DATA_PARITY;
				}
				printk("  %05X-%08X%08X", datahi, insta, instb);
			}
			printk("\n");
		}
	}
	return res;
}

__attribute__((used)) static uint8_t dc_ecc(uint64_t dword)
{
	uint64_t t;
	uint32_t w;
	uint8_t	 p;
	int	 i;

	p = 0;
	for (i = 7; i >= 0; i--)
	{
		p <<= 1;
		t = dword & mask_72_64[i];
		w = (uint32_t)(t >> 32);
		p ^= (parity[w>>24] ^ parity[(w>>16) & 0xFF]
		      ^ parity[(w>>8) & 0xFF] ^ parity[w & 0xFF]);
		w = (uint32_t)(t & 0xFFFFFFFF);
		p ^= (parity[w>>24] ^ parity[(w>>16) & 0xFF]
		      ^ parity[(w>>8) & 0xFF] ^ parity[w & 0xFF]);
	}
	return p;
}

__attribute__((used)) static char *dc_state_str(unsigned char state)
{
	struct dc_state *dsc = dc_states;
	while (dsc->val != 0xff) {
		if (dsc->val == state)
			break;
		dsc++;
	}
	return dsc->name;
}

__attribute__((used)) static uint32_t extract_dc(unsigned short addr, int data)
{
	int valid, way;
	unsigned char state;
	uint32_t taghi, taglolo, taglohi;
	unsigned long long taglo, pa;
	uint8_t ecc, lru;
	int res = 0;

	printk("Dcache index 0x%04x  ", addr);
	for (way = 0; way < 4; way++) {
		__asm__ __volatile__ (
		"	.set	push\n\t"
		"	.set	noreorder\n\t"
		"	.set	mips64\n\t"
		"	.set	noat\n\t"
		"	cache	5, 0(%3)\n\t"	/* Index-load-tag-D */
		"	mfc0	%0, $29, 2\n\t"
		"	dmfc0	$1, $28, 2\n\t"
		"	dsrl32	%1, $1, 0\n\t"
		"	sll	%2, $1, 0\n\t"
		"	.set	pop"
		: "=r" (taghi), "=r" (taglohi), "=r" (taglolo)
		: "r" ((way << 13) | addr));

		taglo = ((unsigned long long)taglohi << 32) | taglolo;
		pa = (taglo & 0xFFFFFFE000ULL) | addr;
		if (way == 0) {
			lru = (taghi >> 14) & 0xff;
			printk("[Bank %d Set 0x%02x]  LRU > %d %d %d %d > MRU\n",
				    ((addr >> 11) & 0x2) | ((addr >> 5) & 1), /* bank */
				    ((addr >> 6) & 0x3f), /* index */
				    (lru & 0x3),
				    ((lru >> 2) & 0x3),
				    ((lru >> 4) & 0x3),
				    ((lru >> 6) & 0x3));
		}
		state = (taghi >> 25) & 0x1f;
		valid = DC_TAG_VALID(state);
		printk(" %d  [PA %010llx]  [state %s (%02x)]  raw tags: %08X-%016llX\n",
			    way, pa, dc_state_str(state), state, taghi, taglo);
		if (valid) {
			if (((taglo >> 11) & 1) ^ range_parity(taglo, 39, 26)) {
				printk("   ** bad parity in PTag1\n");
				res |= CP0_CERRD_TAG_ADDRESS;
			}
			if (((taglo >> 10) & 1) ^ range_parity(taglo, 25, 13)) {
				printk("   ** bad parity in PTag0\n");
				res |= CP0_CERRD_TAG_ADDRESS;
			}
		} else {
			res |= CP0_CERRD_TAG_STATE;
		}

		if (data) {
			uint32_t datalohi, datalolo, datahi;
			unsigned long long datalo;
			int offset;
			char bad_ecc = 0;

			for (offset = 0; offset < 4; offset++) {
				/* Index-load-data-D */
				__asm__ __volatile__ (
				"	.set	push\n\t"
				"	.set	noreorder\n\t"
				"	.set	mips64\n\t"
				"	.set	noat\n\t"
				"	cache	7, 0(%3)\n\t" /* Index-load-data-D */
				"	mfc0	%0, $29, 3\n\t"
				"	dmfc0	$1, $28, 3\n\t"
				"	dsrl32	%1, $1, 0 \n\t"
				"	sll	%2, $1, 0 \n\t"
				"	.set	pop"
				: "=r" (datahi), "=r" (datalohi), "=r" (datalolo)
				: "r" ((way << 13) | addr | (offset << 3)));
				datalo = ((unsigned long long)datalohi << 32) | datalolo;
				ecc = dc_ecc(datalo);
				if (ecc != datahi) {
					int bits;
					bad_ecc |= 1 << (3-offset);
					ecc ^= datahi;
					bits = hweight8(ecc);
					res |= (bits == 1) ? CP0_CERRD_DATA_SBE : CP0_CERRD_DATA_DBE;
				}
				printk("  %02X-%016llX", datahi, datalo);
			}
			printk("\n");
			if (bad_ecc)
				printk("  dwords w/ bad ECC: %d %d %d %d\n",
				       !!(bad_ecc & 8), !!(bad_ecc & 4),
				       !!(bad_ecc & 2), !!(bad_ecc & 1));
		}
	}
	return res;
}

