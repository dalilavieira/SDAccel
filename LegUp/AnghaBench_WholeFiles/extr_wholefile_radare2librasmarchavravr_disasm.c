#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int uint16_t ;
struct TYPE_8__ {int* operands; TYPE_4__* instruction; int /*<<< orphan*/ * alternateInstruction; int /*<<< orphan*/  address; } ;
typedef  TYPE_1__ disassembledInstruction ;
struct TYPE_9__ {int opcode; int /*<<< orphan*/  address; } ;
typedef  TYPE_2__ assembledInstruction ;
struct TYPE_10__ {int numOperands; int* operandMasks; scalar_t__* operandTypes; int opcodeMask; int /*<<< orphan*/  mnemonic; } ;

/* Variables and functions */
 scalar_t__ AVR_LONG_INSTRUCTION_FOUND ; 
 scalar_t__ AVR_LONG_INSTRUCTION_PRINT ; 
 int AVR_Long_Address ; 
 scalar_t__ AVR_Long_Instruction ; 
 int AVR_MAX_NUM_OPERANDS ; 
 int AVR_TOTAL_INSTRUCTIONS ; 
 int ERROR_INVALID_ARGUMENTS ; 
#define  OPERAND_BRANCH_ADDRESS 133 
#define  OPERAND_COMPLEMENTED_DATA 132 
 scalar_t__ OPERAND_LONG_ABSOLUTE_ADDRESS ; 
#define  OPERAND_REGISTER_EVEN_PAIR 131 
#define  OPERAND_REGISTER_EVEN_PAIR_STARTR24 130 
 scalar_t__ OPERAND_REGISTER_GHOST ; 
#define  OPERAND_REGISTER_STARTR16 129 
#define  OPERAND_RELATIVE_ADDRESS 128 
static  int disassembleOperands (TYPE_1__*) ; 
static  int extractDataFromMask (int,int) ; 
 TYPE_4__* instructionSet ; 
 TYPE_1__ longInstruction ; 
static  int lookupInstruction (int,int) ; 
 int /*<<< orphan*/  strcmp (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static int disassembleInstruction(disassembledInstruction *dInstruction, const assembledInstruction aInstruction) {
	int insidx, i;
	
	if (!dInstruction)
		return ERROR_INVALID_ARGUMENTS;
	
	
	/* Look up the instruction */
	insidx = lookupInstruction(aInstruction.opcode, 0);
	if (insidx == AVR_TOTAL_INSTRUCTIONS) {
		// invalid instruction
		return 0;
	}

	/*** AVR SPECIFIC */
	/* If a long instruction was found in the last instruction disassembly,
	 * extract the rest of the address, and indicate that it is to be printed */
	if (AVR_Long_Instruction == AVR_LONG_INSTRUCTION_FOUND) {
		AVR_Long_Instruction = AVR_LONG_INSTRUCTION_PRINT;
		AVR_Long_Address |= aInstruction.opcode;
		/* We must multiply by two, because every instruction is 2 bytes,
		 * so in order to jump/call to the right address (which increments by
		 * two for every instruction), we must multiply this distance by two. */
		//printf ("ii=%d\n", insidx);
                if(!strcmp(longInstruction.instruction->mnemonic,"call")||
                   !strcmp(longInstruction.instruction->mnemonic,"jmp"))
	        {
			AVR_Long_Address *= 2;
                }
		*dInstruction = longInstruction;
		return 0;
	/* If a long instruction was printed in the last instruction disassembly,
	 * reset the AVR_Call_Instruction variable back to zero. */
	} else if (AVR_Long_Instruction == AVR_LONG_INSTRUCTION_PRINT) {
		AVR_Long_Instruction = 0;
	}

	/* Copy over the address, and reference to the instruction, set
	 * the equivilant-encoded but different instruction to NULL for now. */
	dInstruction->address = aInstruction.address;
	dInstruction->instruction = &instructionSet[insidx];
	dInstruction->alternateInstruction = NULL;
	
	/* Copy out each operand, extracting the operand data from the original
	 * opcode using the operand mask. */
	for (i = 0; i < instructionSet[insidx].numOperands; i++) {
		dInstruction->operands[i] = extractDataFromMask(aInstruction.opcode, dInstruction->instruction->operandMasks[i]);
		/*** AVR SPECIFIC */
		/* If this is an instruction with a long absolute operand, indicate that a long instruction has been found,
		 * and extract the first part of the long address. */
		if (dInstruction->instruction->operandTypes[i] == OPERAND_LONG_ABSOLUTE_ADDRESS) {
			AVR_Long_Instruction = AVR_LONG_INSTRUCTION_FOUND;
			AVR_Long_Address = dInstruction->operands[i] << 16;
			longInstruction = *dInstruction;
		}
	}
	
	/* Disassemble operands */
	if (disassembleOperands(dInstruction) < 0)
		return ERROR_INVALID_ARGUMENTS; /* Only possible error for disassembleOperands() */

	if (AVR_Long_Instruction == AVR_LONG_INSTRUCTION_FOUND) {
		/* If we found a long instruction (32-bit one),
		 * Copy this instruction over to our special longInstruction variable, that
		 * will exist even after we move onto the next 16-bits */
		longInstruction = *dInstruction;
	}

	return 0;
}

__attribute__((used)) static uint16_t extractDataFromMask(uint16_t data, uint16_t mask) {
	int i, j;
	uint16_t result = 0;
	
	/* i counts through every bit of the data,
	 * j counts through every bit of the data we're copying out. */
	for (i = 0, j = 0; i < 16; i++) {
		/* If the mask has a bit in this position */
		if (mask & (1<<i)) {
			/* If there is a data bit with this mask bit,
			 * then toggle that bit in the extracted data (result).
			 * Notice that it uses its own bit counter j. */
			if (((mask & (1<<i)) & data) != 0)
				result |= (1<<j);
			/* Increment the extracted data bit count. */
			j++;
		}
	}
	
	return result;
}

__attribute__((used)) static int lookupInstruction(uint16_t opcode, int offset) {
	uint16_t opcodeSearch, operandTemp;
	int insidx, ghostRegisterConfirmed, i, j;
	
	for (insidx = offset; insidx < AVR_TOTAL_INSTRUCTIONS; insidx++) {
		opcodeSearch = opcode;
		/* If we have a ghost register operand (OPERAND_REGISTER_GHOST),
		 * we need to confirm that all of the other register operands are the same */
		ghostRegisterConfirmed = 1;
		/* We want to mask out all of the operands. We don't count up to
		 * instructionSet[insidx].numOperands because some instructions,
		 * such as clr R16, are actually encoded with two operands (so as eor R16,R16),
		 * and we want to screen out both operands to get the most simplest form of 
		 * the instruction. */ 
		for (i = 0; i < AVR_MAX_NUM_OPERANDS; i++) {
			if (instructionSet[insidx].operandTypes[i] == OPERAND_REGISTER_GHOST) {
				/* Grab the first operand */
				operandTemp = extractDataFromMask(opcode, instructionSet[insidx].operandMasks[0]);
				/* Compare the remaining operands to the first */
				for (j = 1; j < AVR_MAX_NUM_OPERANDS; j++) {
					if (extractDataFromMask(opcode, instructionSet[insidx].operandMasks[i]) !=
							operandTemp)
						ghostRegisterConfirmed = 0;
				}
			} 
			opcodeSearch &= ~(instructionSet[insidx].operandMasks[i]);
		}
		/* If we encountered a ghost register and were unable confirm that
		 * all register operands were equal (in this case ghostRegisterConfirmed
		 * would have changed), then move the match-search onto the next instruction. */
		if (ghostRegisterConfirmed == 0)
			continue;

		if (opcodeSearch == instructionSet[insidx].opcodeMask) 
			break;
	}
	/* It's impossible not to find an instruction, because the last instruction ".DW",
	 * specifies a word of data at the addresses, instead of an instruction. 
	 * Its operand 2 mask, 0x0000, will set opcode search to 0x0000, and this will always
	 * match with the opcodeMask of 0x0000. */
	return insidx;
}

__attribute__((used)) static int disassembleOperands(disassembledInstruction *dInstruction) {
	int i;
	
	/* This should never happen */
	if (!dInstruction)
		return ERROR_INVALID_ARGUMENTS;
	if (!dInstruction->instruction)
		return ERROR_INVALID_ARGUMENTS;
	
	/* For each operand, decode its original value. */
	for (i = 0; i < dInstruction->instruction->numOperands; i++) {
		switch (dInstruction->instruction->operandTypes[i]) {
		case OPERAND_BRANCH_ADDRESS:
			/* K is 7 bits, so maximum value it can store is 127 decimal.
			 * However, a branch's operand, -64 <= k <= +63,
			 * can go 64 back (-64) or 63 forward (+63). Range: 64+63 = 127.
			 * In order to preserve the negative, the branch distance
			 * is stored in two's complement form.*/
			/* First we multiply by two, because every instruction is 2 bytes,
			 * so in order to branch to the right address (which increments by
			 * two for every instruction), we must multiply this distance
			 * by two. */
			/* Next, we check for the signed bit (MSB), which would indicate a
			 * negative. If the number is signed, we would reverse the two's
			 * complement (invert bits, add 1, and then only use the 7 bits that 
			 * matter), otherwise, the number represents a positive distance and
			 * no bit manipulation is necessary. */
			dInstruction->operands[i] <<= 1;
			if (dInstruction->operands[i] & 0x80) {
				/* We can't just print out the signed operand because the type's capacity
				 * is 16 bits, and the operand data's signedness only starts at 0x80.
				 * Therefore we must convert to the positive value and then make the entire
				 * short negative. */
				dInstruction->operands[i] = (~dInstruction->operands[i]+1)&0x7F;
				dInstruction->operands[i] = -dInstruction->operands[i]+2;
			} else {
				dInstruction->operands[i] += 2;
			}
			break;
		case OPERAND_RELATIVE_ADDRESS:
			/* k is 12 bits, so maximum value it can store is 4095 decimal.
			 * However, a relative jump/call's operand, -2K <= k < +2K,
			 * can go 2048 back (-2048) or 2047 forward (+2047). Range: 2048+2047 = 4095.
			 * In order to preserve the negative, the jump/call distance
			 * is stored in two's complement form.*/
			/* First we multiply by two, because every instruction is 2 bytes,
			 * so in order to jump/call to the right address (which increments by
			 * two for every instruction), we must multiply this distance
			 * by two. */
			/* Next, we check for the signed bit (MSB), which would indicate a
			 * negative. If the number is signed, we would reverse the two's
			 * complement (invert bits, add 1, and then only use the 12 bits that 
			 * matter), otherwise, the number represents a positive distance and
			 * no bit manipulation is necessary. */
			dInstruction->operands[i] <<= 1;
			if (dInstruction->operands[i] & 0x1000) {
				/* We can't just print out the signed operand because the type's capacity
				 * is 16 bits, and the operand data's signedness only starts at 0x1000.
				 * Therefore we must convert to the positive value and then make the entire
				 * short negative. */
				short val = ((~dInstruction->operands[i]) ) & 0xFFF;
				//dInstruction->operands[i] = (~dInstruction->operands[i])&0xFFF;
				dInstruction->operands[i] = -val + 1;
				//dInstruction->operands[i] += 2;
			} else {
				dInstruction->operands[i] += 2;
			}
			break;
		case OPERAND_REGISTER_STARTR16:
			dInstruction->operands[i] = 16 + dInstruction->operands[i] ;
			break;
		case OPERAND_REGISTER_EVEN_PAIR:
			dInstruction->operands[i] = dInstruction->operands[i] * 2;
			break;
		case OPERAND_REGISTER_EVEN_PAIR_STARTR24:
			dInstruction->operands[i] = 24 + (dInstruction->operands[i] * 2);
			break;
		case OPERAND_COMPLEMENTED_DATA:
			dInstruction->operands[i] = ~dInstruction->operands[i] & 0xFF;
			break;
		default:
			break;
		}
	}
	return 0;
}

