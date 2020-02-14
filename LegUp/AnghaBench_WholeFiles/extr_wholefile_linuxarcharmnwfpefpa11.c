#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  union fp_state {int dummy; } fp_state ;
typedef  int int8 ;
typedef  int float64 ;
typedef  int float32 ;
typedef  int flag ;
typedef  scalar_t__ bits64 ;
typedef  scalar_t__ bits32 ;
struct TYPE_4__ {int fpsr; int initflag; int /*<<< orphan*/ * fType; } ;
typedef  TYPE_1__ FPA11 ;

/* Variables and functions */
 int BIT_AC ; 
 unsigned int EmulateCPDO (unsigned int) ; 
 unsigned int EmulateCPDT (unsigned int) ; 
 unsigned int EmulateCPRT (unsigned int) ; 
 int FP_EMULATOR ; 
 TYPE_1__* GET_FPA11 () ; 
 unsigned int const MASK_ROUNDING_MODE ; 
#define  ROUND_TO_MINUS_INFINITY 131 
#define  ROUND_TO_NEAREST 130 
#define  ROUND_TO_PLUS_INFINITY 129 
#define  ROUND_TO_ZERO 128 
 int float_round_down ; 
 int float_round_nearest_even ; 
 int float_round_to_zero ; 
 int float_round_up ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  typeNone ; 

__attribute__((used)) static inline flag extractFloat32Sign(float32 a)
{
	return a >> 31;
}

__attribute__((used)) static inline flag float32_eq_nocheck(float32 a, float32 b)
{
	return (a == b) || ((bits32) ((a | b) << 1) == 0);
}

__attribute__((used)) static inline flag float32_lt_nocheck(float32 a, float32 b)
{
	flag aSign, bSign;

	aSign = extractFloat32Sign(a);
	bSign = extractFloat32Sign(b);
	if (aSign != bSign)
		return aSign && ((bits32) ((a | b) << 1) != 0);
	return (a != b) && (aSign ^ (a < b));
}

__attribute__((used)) static inline flag extractFloat64Sign(float64 a)
{
	return a >> 63;
}

__attribute__((used)) static inline flag float64_eq_nocheck(float64 a, float64 b)
{
	return (a == b) || ((bits64) ((a | b) << 1) == 0);
}

__attribute__((used)) static inline flag float64_lt_nocheck(float64 a, float64 b)
{
	flag aSign, bSign;

	aSign = extractFloat64Sign(a);
	bSign = extractFloat64Sign(b);
	if (aSign != bSign)
		return aSign && ((bits64) ((a | b) << 1) != 0);
	return (a != b) && (aSign ^ (a < b));
}

__attribute__((used)) static void resetFPA11(void)
{
	int i;
	FPA11 *fpa11 = GET_FPA11();

	/* initialize the register type array */
	for (i = 0; i <= 7; i++) {
		fpa11->fType[i] = typeNone;
	}

	/* FPSR: set system id to FP_EMULATOR, set AC, clear all other bits */
	fpa11->fpsr = FP_EMULATOR | BIT_AC;
}

int8 SetRoundingMode(const unsigned int opcode)
{
	switch (opcode & MASK_ROUNDING_MODE) {
	default:
	case ROUND_TO_NEAREST:
		return float_round_nearest_even;

	case ROUND_TO_PLUS_INFINITY:
		return float_round_up;

	case ROUND_TO_MINUS_INFINITY:
		return float_round_down;

	case ROUND_TO_ZERO:
		return float_round_to_zero;
	}
}

int8 SetRoundingPrecision(const unsigned int opcode)
{
#ifdef CONFIG_FPE_NWFPE_XP
	switch (opcode & MASK_ROUNDING_PRECISION) {
	case ROUND_SINGLE:
		return 32;

	case ROUND_DOUBLE:
		return 64;

	case ROUND_EXTENDED:
		return 80;

	default:
		return 80;
	}
#endif
	return 80;
}

void nwfpe_init_fpa(union fp_state *fp)
{
	FPA11 *fpa11 = (FPA11 *)fp;
#ifdef NWFPE_DEBUG
	printk("NWFPE: setting up state.\n");
#endif
 	memset(fpa11, 0, sizeof(FPA11));
	resetFPA11();
	fpa11->initflag = 1;
}

unsigned int EmulateAll(unsigned int opcode)
{
	unsigned int code;

#ifdef NWFPE_DEBUG
	printk("NWFPE: emulating opcode %08x\n", opcode);
#endif
	code = opcode & 0x00000f00;
	if (code == 0x00000100 || code == 0x00000200) {
		/* For coprocessor 1 or 2 (FPA11) */
		code = opcode & 0x0e000000;
		if (code == 0x0e000000) {
			if (opcode & 0x00000010) {
				/* Emulate conversion opcodes. */
				/* Emulate register transfer opcodes. */
				/* Emulate comparison opcodes. */
				return EmulateCPRT(opcode);
			} else {
				/* Emulate monadic arithmetic opcodes. */
				/* Emulate dyadic arithmetic opcodes. */
				return EmulateCPDO(opcode);
			}
		} else if (code == 0x0c000000) {
			/* Emulate load/store opcodes. */
			/* Emulate load/store multiple opcodes. */
			return EmulateCPDT(opcode);
		}
	}

	/* Invalid instruction detected.  Return FALSE. */
	return 0;
}

