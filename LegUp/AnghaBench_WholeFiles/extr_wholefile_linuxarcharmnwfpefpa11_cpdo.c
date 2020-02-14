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
struct roundingData {scalar_t__ exception; int /*<<< orphan*/  precision; int /*<<< orphan*/  mode; } ;
typedef  int float64 ;
typedef  int float32 ;
typedef  int flag ;
typedef  scalar_t__ bits64 ;
typedef  scalar_t__ bits32 ;
struct TYPE_7__ {unsigned int* fType; TYPE_1__* fpreg; } ;
struct TYPE_6__ {int /*<<< orphan*/  fSingle; int /*<<< orphan*/  fDouble; } ;
typedef  TYPE_1__ FPREG ;
typedef  TYPE_2__ FPA11 ;

/* Variables and functions */
 int /*<<< orphan*/  CONSTANT_FM (unsigned int const) ; 
 unsigned int DoubleCPDO (struct roundingData*,unsigned int const,TYPE_1__*) ; 
 TYPE_2__* GET_FPA11 () ; 
 scalar_t__ MONADIC_INSTRUCTION (unsigned int const) ; 
 int /*<<< orphan*/  SetRoundingMode (unsigned int const) ; 
 int /*<<< orphan*/  SetRoundingPrecision (unsigned int const) ; 
 unsigned int SingleCPDO (struct roundingData*,unsigned int const,TYPE_1__*) ; 
 int /*<<< orphan*/  float32_to_float64 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  float64_to_float32 (struct roundingData*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  float_raise (scalar_t__) ; 
 unsigned int getDestinationSize (unsigned int const) ; 
 size_t getFd (unsigned int const) ; 
 unsigned int getFm (unsigned int const) ; 
 size_t getFn (unsigned int const) ; 
#define  typeDouble 129 
 unsigned int typeNone ; 
#define  typeSingle 128 

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

unsigned int EmulateCPDO(const unsigned int opcode)
{
	FPA11 *fpa11 = GET_FPA11();
	FPREG *rFd;
	unsigned int nType, nDest, nRc;
	struct roundingData roundData;

	/* Get the destination size.  If not valid let Linux perform
	   an invalid instruction trap. */
	nDest = getDestinationSize(opcode);
	if (typeNone == nDest)
		return 0;

	roundData.mode = SetRoundingMode(opcode);
	roundData.precision = SetRoundingPrecision(opcode);
	roundData.exception = 0;

	/* Compare the size of the operands in Fn and Fm.
	   Choose the largest size and perform operations in that size,
	   in order to make use of all the precision of the operands.
	   If Fm is a constant, we just grab a constant of a size
	   matching the size of the operand in Fn. */
	if (MONADIC_INSTRUCTION(opcode))
		nType = nDest;
	else
		nType = fpa11->fType[getFn(opcode)];

	if (!CONSTANT_FM(opcode)) {
		register unsigned int Fm = getFm(opcode);
		if (nType < fpa11->fType[Fm]) {
			nType = fpa11->fType[Fm];
		}
	}

	rFd = &fpa11->fpreg[getFd(opcode)];

	switch (nType) {
	case typeSingle:
		nRc = SingleCPDO(&roundData, opcode, rFd);
		break;
	case typeDouble:
		nRc = DoubleCPDO(&roundData, opcode, rFd);
		break;
#ifdef CONFIG_FPE_NWFPE_XP
	case typeExtended:
		nRc = ExtendedCPDO(&roundData, opcode, rFd);
		break;
#endif
	default:
		nRc = 0;
	}

	/* The CPDO functions used to always set the destination type
	   to be the same as their working size. */

	if (nRc != 0) {
		/* If the operation succeeded, check to see if the result in the
		   destination register is the correct size.  If not force it
		   to be. */

		fpa11->fType[getFd(opcode)] = nDest;

#ifdef CONFIG_FPE_NWFPE_XP
		if (nDest != nType) {
			switch (nDest) {
			case typeSingle:
				{
					if (typeDouble == nType)
						rFd->fSingle = float64_to_float32(&roundData, rFd->fDouble);
					else
						rFd->fSingle = floatx80_to_float32(&roundData, rFd->fExtended);
				}
				break;

			case typeDouble:
				{
					if (typeSingle == nType)
						rFd->fDouble = float32_to_float64(rFd->fSingle);
					else
						rFd->fDouble = floatx80_to_float64(&roundData, rFd->fExtended);
				}
				break;

			case typeExtended:
				{
					if (typeSingle == nType)
						rFd->fExtended = float32_to_floatx80(rFd->fSingle);
					else
						rFd->fExtended = float64_to_floatx80(rFd->fDouble);
				}
				break;
			}
		}
#else
		if (nDest != nType) {
			if (nDest == typeSingle)
				rFd->fSingle = float64_to_float32(&roundData, rFd->fDouble);
			else
				rFd->fDouble = float32_to_float64(rFd->fSingle);
		}
#endif
	}

	if (roundData.exception)
		float_raise(roundData.exception);

	return nRc;
}

