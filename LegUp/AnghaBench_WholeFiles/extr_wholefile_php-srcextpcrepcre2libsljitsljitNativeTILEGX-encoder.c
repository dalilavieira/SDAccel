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
typedef  size_t tilegx_pipeline ;
typedef  scalar_t__ tilegx_mnemonic ;
typedef  int tilegx_bundle_bits ;
struct tilegx_spr {int number; char const* name; } ;
typedef  struct tilegx_operand {int (* extract ) (int) ;scalar_t__ type; scalar_t__ num_bits; scalar_t__ is_signed; } const tilegx_operand ;
typedef  struct tilegx_opcode {int num_operands; size_t** operands; scalar_t__ mnemonic; char* name; int /*<<< orphan*/  can_bundle; } const tilegx_opcode ;
struct tilegx_decoded_instruction {long long* operand_values; struct tilegx_operand const** operands; struct tilegx_opcode const* opcode; } ;

/* Variables and functions */
 int TILEGX_BUNDLE_MODE_MASK ; 
 int TILEGX_BUNDLE_SIZE_IN_BYTES ; 
 int TILEGX_MAX_INSTRUCTIONS_PER_BUNDLE ; 
 scalar_t__ TILEGX_OPC_FNOP ; 
 unsigned short TILEGX_OPC_NONE ; 
 scalar_t__ TILEGX_OPC_NOP ; 
#define  TILEGX_OP_TYPE_ADDRESS 131 
#define  TILEGX_OP_TYPE_IMMEDIATE 130 
#define  TILEGX_OP_TYPE_REGISTER 129 
#define  TILEGX_OP_TYPE_SPR 128 
 int TILEGX_PIPELINE_X0 ; 
 int TILEGX_PIPELINE_X1 ; 
 int TILEGX_PIPELINE_Y0 ; 
 int TILEGX_PIPELINE_Y2 ; 
 int /*<<< orphan*/  abort () ; 
 void* bsearch (void const*,void const*,int /*<<< orphan*/ ,int,int (*) (void const*,void const*)) ; 
 int /*<<< orphan*/  memcpy (void*,void*,int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int stub1 (int) ; 
 unsigned short** tilegx_bundle_decoder_fsms ; 
 int /*<<< orphan*/  tilegx_num_sprs ; 
 struct tilegx_opcode const* tilegx_opcodes ; 
 struct tilegx_operand const* tilegx_operands ; 
 char** tilegx_register_names ; 
 scalar_t__ tilegx_sprs ; 

__attribute__((used)) static __inline unsigned int
get_BFEnd_X0(tilegx_bundle_bits num)
{
  const unsigned int n = (unsigned int)num;
  return (((n >> 12)) & 0x3f);
}

__attribute__((used)) static __inline unsigned int
get_BFOpcodeExtension_X0(tilegx_bundle_bits num)
{
  const unsigned int n = (unsigned int)num;
  return (((n >> 24)) & 0xf);
}

__attribute__((used)) static __inline unsigned int
get_BFStart_X0(tilegx_bundle_bits num)
{
  const unsigned int n = (unsigned int)num;
  return (((n >> 18)) & 0x3f);
}

__attribute__((used)) static __inline unsigned int
get_BrOff_X1(tilegx_bundle_bits n)
{
  return (((unsigned int)(n >> 31)) & 0x0000003f) |
         (((unsigned int)(n >> 37)) & 0x0001ffc0);
}

__attribute__((used)) static __inline unsigned int
get_BrType_X1(tilegx_bundle_bits n)
{
  return (((unsigned int)(n >> 54)) & 0x1f);
}

__attribute__((used)) static __inline unsigned int
get_Dest_Imm8_X1(tilegx_bundle_bits n)
{
  return (((unsigned int)(n >> 31)) & 0x0000003f) |
         (((unsigned int)(n >> 43)) & 0x000000c0);
}

__attribute__((used)) static __inline unsigned int
get_Dest_X0(tilegx_bundle_bits num)
{
  const unsigned int n = (unsigned int)num;
  return (((n >> 0)) & 0x3f);
}

__attribute__((used)) static __inline unsigned int
get_Dest_X1(tilegx_bundle_bits n)
{
  return (((unsigned int)(n >> 31)) & 0x3f);
}

__attribute__((used)) static __inline unsigned int
get_Dest_Y0(tilegx_bundle_bits num)
{
  const unsigned int n = (unsigned int)num;
  return (((n >> 0)) & 0x3f);
}

__attribute__((used)) static __inline unsigned int
get_Dest_Y1(tilegx_bundle_bits n)
{
  return (((unsigned int)(n >> 31)) & 0x3f);
}

__attribute__((used)) static __inline unsigned int
get_Imm16_X0(tilegx_bundle_bits num)
{
  const unsigned int n = (unsigned int)num;
  return (((n >> 12)) & 0xffff);
}

__attribute__((used)) static __inline unsigned int
get_Imm16_X1(tilegx_bundle_bits n)
{
  return (((unsigned int)(n >> 43)) & 0xffff);
}

__attribute__((used)) static __inline unsigned int
get_Imm8OpcodeExtension_X0(tilegx_bundle_bits num)
{
  const unsigned int n = (unsigned int)num;
  return (((n >> 20)) & 0xff);
}

__attribute__((used)) static __inline unsigned int
get_Imm8OpcodeExtension_X1(tilegx_bundle_bits n)
{
  return (((unsigned int)(n >> 51)) & 0xff);
}

__attribute__((used)) static __inline unsigned int
get_Imm8_X0(tilegx_bundle_bits num)
{
  const unsigned int n = (unsigned int)num;
  return (((n >> 12)) & 0xff);
}

__attribute__((used)) static __inline unsigned int
get_Imm8_X1(tilegx_bundle_bits n)
{
  return (((unsigned int)(n >> 43)) & 0xff);
}

__attribute__((used)) static __inline unsigned int
get_Imm8_Y0(tilegx_bundle_bits num)
{
  const unsigned int n = (unsigned int)num;
  return (((n >> 12)) & 0xff);
}

__attribute__((used)) static __inline unsigned int
get_Imm8_Y1(tilegx_bundle_bits n)
{
  return (((unsigned int)(n >> 43)) & 0xff);
}

__attribute__((used)) static __inline unsigned int
get_JumpOff_X1(tilegx_bundle_bits n)
{
  return (((unsigned int)(n >> 31)) & 0x7ffffff);
}

__attribute__((used)) static __inline unsigned int
get_JumpOpcodeExtension_X1(tilegx_bundle_bits n)
{
  return (((unsigned int)(n >> 58)) & 0x1);
}

__attribute__((used)) static __inline unsigned int
get_MF_Imm14_X1(tilegx_bundle_bits n)
{
  return (((unsigned int)(n >> 37)) & 0x3fff);
}

__attribute__((used)) static __inline unsigned int
get_MT_Imm14_X1(tilegx_bundle_bits n)
{
  return (((unsigned int)(n >> 31)) & 0x0000003f) |
         (((unsigned int)(n >> 37)) & 0x00003fc0);
}

__attribute__((used)) static __inline unsigned int
get_Mode(tilegx_bundle_bits n)
{
  return (((unsigned int)(n >> 62)) & 0x3);
}

__attribute__((used)) static __inline unsigned int
get_Opcode_X0(tilegx_bundle_bits num)
{
  const unsigned int n = (unsigned int)num;
  return (((n >> 28)) & 0x7);
}

__attribute__((used)) static __inline unsigned int
get_Opcode_X1(tilegx_bundle_bits n)
{
  return (((unsigned int)(n >> 59)) & 0x7);
}

__attribute__((used)) static __inline unsigned int
get_Opcode_Y0(tilegx_bundle_bits num)
{
  const unsigned int n = (unsigned int)num;
  return (((n >> 27)) & 0xf);
}

__attribute__((used)) static __inline unsigned int
get_Opcode_Y1(tilegx_bundle_bits n)
{
  return (((unsigned int)(n >> 58)) & 0xf);
}

__attribute__((used)) static __inline unsigned int
get_Opcode_Y2(tilegx_bundle_bits n)
{
  return (((n >> 26)) & 0x00000001) |
         (((unsigned int)(n >> 56)) & 0x00000002);
}

__attribute__((used)) static __inline unsigned int
get_RRROpcodeExtension_X0(tilegx_bundle_bits num)
{
  const unsigned int n = (unsigned int)num;
  return (((n >> 18)) & 0x3ff);
}

__attribute__((used)) static __inline unsigned int
get_RRROpcodeExtension_X1(tilegx_bundle_bits n)
{
  return (((unsigned int)(n >> 49)) & 0x3ff);
}

__attribute__((used)) static __inline unsigned int
get_RRROpcodeExtension_Y0(tilegx_bundle_bits num)
{
  const unsigned int n = (unsigned int)num;
  return (((n >> 18)) & 0x3);
}

__attribute__((used)) static __inline unsigned int
get_RRROpcodeExtension_Y1(tilegx_bundle_bits n)
{
  return (((unsigned int)(n >> 49)) & 0x3);
}

__attribute__((used)) static __inline unsigned int
get_ShAmt_X0(tilegx_bundle_bits num)
{
  const unsigned int n = (unsigned int)num;
  return (((n >> 12)) & 0x3f);
}

__attribute__((used)) static __inline unsigned int
get_ShAmt_X1(tilegx_bundle_bits n)
{
  return (((unsigned int)(n >> 43)) & 0x3f);
}

__attribute__((used)) static __inline unsigned int
get_ShAmt_Y0(tilegx_bundle_bits num)
{
  const unsigned int n = (unsigned int)num;
  return (((n >> 12)) & 0x3f);
}

__attribute__((used)) static __inline unsigned int
get_ShAmt_Y1(tilegx_bundle_bits n)
{
  return (((unsigned int)(n >> 43)) & 0x3f);
}

__attribute__((used)) static __inline unsigned int
get_ShiftOpcodeExtension_X0(tilegx_bundle_bits num)
{
  const unsigned int n = (unsigned int)num;
  return (((n >> 18)) & 0x3ff);
}

__attribute__((used)) static __inline unsigned int
get_ShiftOpcodeExtension_X1(tilegx_bundle_bits n)
{
  return (((unsigned int)(n >> 49)) & 0x3ff);
}

__attribute__((used)) static __inline unsigned int
get_ShiftOpcodeExtension_Y0(tilegx_bundle_bits num)
{
  const unsigned int n = (unsigned int)num;
  return (((n >> 18)) & 0x3);
}

__attribute__((used)) static __inline unsigned int
get_ShiftOpcodeExtension_Y1(tilegx_bundle_bits n)
{
  return (((unsigned int)(n >> 49)) & 0x3);
}

__attribute__((used)) static __inline unsigned int
get_SrcA_X0(tilegx_bundle_bits num)
{
  const unsigned int n = (unsigned int)num;
  return (((n >> 6)) & 0x3f);
}

__attribute__((used)) static __inline unsigned int
get_SrcA_X1(tilegx_bundle_bits n)
{
  return (((unsigned int)(n >> 37)) & 0x3f);
}

__attribute__((used)) static __inline unsigned int
get_SrcA_Y0(tilegx_bundle_bits num)
{
  const unsigned int n = (unsigned int)num;
  return (((n >> 6)) & 0x3f);
}

__attribute__((used)) static __inline unsigned int
get_SrcA_Y1(tilegx_bundle_bits n)
{
  return (((unsigned int)(n >> 37)) & 0x3f);
}

__attribute__((used)) static __inline unsigned int
get_SrcA_Y2(tilegx_bundle_bits num)
{
  const unsigned int n = (unsigned int)num;
  return (((n >> 20)) & 0x3f);
}

__attribute__((used)) static __inline unsigned int
get_SrcBDest_Y2(tilegx_bundle_bits n)
{
  return (((unsigned int)(n >> 51)) & 0x3f);
}

__attribute__((used)) static __inline unsigned int
get_SrcB_X0(tilegx_bundle_bits num)
{
  const unsigned int n = (unsigned int)num;
  return (((n >> 12)) & 0x3f);
}

__attribute__((used)) static __inline unsigned int
get_SrcB_X1(tilegx_bundle_bits n)
{
  return (((unsigned int)(n >> 43)) & 0x3f);
}

__attribute__((used)) static __inline unsigned int
get_SrcB_Y0(tilegx_bundle_bits num)
{
  const unsigned int n = (unsigned int)num;
  return (((n >> 12)) & 0x3f);
}

__attribute__((used)) static __inline unsigned int
get_SrcB_Y1(tilegx_bundle_bits n)
{
  return (((unsigned int)(n >> 43)) & 0x3f);
}

__attribute__((used)) static __inline unsigned int
get_UnaryOpcodeExtension_X0(tilegx_bundle_bits num)
{
  const unsigned int n = (unsigned int)num;
  return (((n >> 12)) & 0x3f);
}

__attribute__((used)) static __inline unsigned int
get_UnaryOpcodeExtension_X1(tilegx_bundle_bits n)
{
  return (((unsigned int)(n >> 43)) & 0x3f);
}

__attribute__((used)) static __inline unsigned int
get_UnaryOpcodeExtension_Y0(tilegx_bundle_bits num)
{
  const unsigned int n = (unsigned int)num;
  return (((n >> 12)) & 0x3f);
}

__attribute__((used)) static __inline unsigned int
get_UnaryOpcodeExtension_Y1(tilegx_bundle_bits n)
{
  return (((unsigned int)(n >> 43)) & 0x3f);
}

__attribute__((used)) static __inline int
sign_extend(int n, int num_bits)
{
  int shift = (int)(sizeof(int) * 8 - num_bits);
  return (n << shift) >> shift;
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_BFEnd_X0(int num)
{
  const unsigned int n = (unsigned int)num;
  return ((n & 0x3f) << 12);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_BFOpcodeExtension_X0(int num)
{
  const unsigned int n = (unsigned int)num;
  return ((n & 0xf) << 24);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_BFStart_X0(int num)
{
  const unsigned int n = (unsigned int)num;
  return ((n & 0x3f) << 18);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_BrOff_X1(int num)
{
  const unsigned int n = (unsigned int)num;
  return (((tilegx_bundle_bits)(n & 0x0000003f)) << 31) |
         (((tilegx_bundle_bits)(n & 0x0001ffc0)) << 37);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_BrType_X1(int num)
{
  const unsigned int n = (unsigned int)num;
  return (((tilegx_bundle_bits)(n & 0x1f)) << 54);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_Dest_Imm8_X1(int num)
{
  const unsigned int n = (unsigned int)num;
  return (((tilegx_bundle_bits)(n & 0x0000003f)) << 31) |
         (((tilegx_bundle_bits)(n & 0x000000c0)) << 43);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_Dest_X0(int num)
{
  const unsigned int n = (unsigned int)num;
  return ((n & 0x3f) << 0);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_Dest_X1(int num)
{
  const unsigned int n = (unsigned int)num;
  return (((tilegx_bundle_bits)(n & 0x3f)) << 31);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_Dest_Y0(int num)
{
  const unsigned int n = (unsigned int)num;
  return ((n & 0x3f) << 0);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_Dest_Y1(int num)
{
  const unsigned int n = (unsigned int)num;
  return (((tilegx_bundle_bits)(n & 0x3f)) << 31);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_Imm16_X0(int num)
{
  const unsigned int n = (unsigned int)num;
  return ((n & 0xffff) << 12);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_Imm16_X1(int num)
{
  const unsigned int n = (unsigned int)num;
  return (((tilegx_bundle_bits)(n & 0xffff)) << 43);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_Imm8OpcodeExtension_X0(int num)
{
  const unsigned int n = (unsigned int)num;
  return ((n & 0xff) << 20);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_Imm8OpcodeExtension_X1(int num)
{
  const unsigned int n = (unsigned int)num;
  return (((tilegx_bundle_bits)(n & 0xff)) << 51);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_Imm8_X0(int num)
{
  const unsigned int n = (unsigned int)num;
  return ((n & 0xff) << 12);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_Imm8_X1(int num)
{
  const unsigned int n = (unsigned int)num;
  return (((tilegx_bundle_bits)(n & 0xff)) << 43);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_Imm8_Y0(int num)
{
  const unsigned int n = (unsigned int)num;
  return ((n & 0xff) << 12);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_Imm8_Y1(int num)
{
  const unsigned int n = (unsigned int)num;
  return (((tilegx_bundle_bits)(n & 0xff)) << 43);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_JumpOff_X1(int num)
{
  const unsigned int n = (unsigned int)num;
  return (((tilegx_bundle_bits)(n & 0x7ffffff)) << 31);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_JumpOpcodeExtension_X1(int num)
{
  const unsigned int n = (unsigned int)num;
  return (((tilegx_bundle_bits)(n & 0x1)) << 58);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_MF_Imm14_X1(int num)
{
  const unsigned int n = (unsigned int)num;
  return (((tilegx_bundle_bits)(n & 0x3fff)) << 37);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_MT_Imm14_X1(int num)
{
  const unsigned int n = (unsigned int)num;
  return (((tilegx_bundle_bits)(n & 0x0000003f)) << 31) |
         (((tilegx_bundle_bits)(n & 0x00003fc0)) << 37);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_Mode(int num)
{
  const unsigned int n = (unsigned int)num;
  return (((tilegx_bundle_bits)(n & 0x3)) << 62);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_Opcode_X0(int num)
{
  const unsigned int n = (unsigned int)num;
  return ((n & 0x7) << 28);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_Opcode_X1(int num)
{
  const unsigned int n = (unsigned int)num;
  return (((tilegx_bundle_bits)(n & 0x7)) << 59);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_Opcode_Y0(int num)
{
  const unsigned int n = (unsigned int)num;
  return ((n & 0xf) << 27);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_Opcode_Y1(int num)
{
  const unsigned int n = (unsigned int)num;
  return (((tilegx_bundle_bits)(n & 0xf)) << 58);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_Opcode_Y2(int num)
{
  const unsigned int n = (unsigned int)num;
  return ((n & 0x00000001) << 26) |
         (((tilegx_bundle_bits)(n & 0x00000002)) << 56);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_RRROpcodeExtension_X0(int num)
{
  const unsigned int n = (unsigned int)num;
  return ((n & 0x3ff) << 18);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_RRROpcodeExtension_X1(int num)
{
  const unsigned int n = (unsigned int)num;
  return (((tilegx_bundle_bits)(n & 0x3ff)) << 49);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_RRROpcodeExtension_Y0(int num)
{
  const unsigned int n = (unsigned int)num;
  return ((n & 0x3) << 18);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_RRROpcodeExtension_Y1(int num)
{
  const unsigned int n = (unsigned int)num;
  return (((tilegx_bundle_bits)(n & 0x3)) << 49);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_ShAmt_X0(int num)
{
  const unsigned int n = (unsigned int)num;
  return ((n & 0x3f) << 12);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_ShAmt_X1(int num)
{
  const unsigned int n = (unsigned int)num;
  return (((tilegx_bundle_bits)(n & 0x3f)) << 43);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_ShAmt_Y0(int num)
{
  const unsigned int n = (unsigned int)num;
  return ((n & 0x3f) << 12);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_ShAmt_Y1(int num)
{
  const unsigned int n = (unsigned int)num;
  return (((tilegx_bundle_bits)(n & 0x3f)) << 43);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_ShiftOpcodeExtension_X0(int num)
{
  const unsigned int n = (unsigned int)num;
  return ((n & 0x3ff) << 18);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_ShiftOpcodeExtension_X1(int num)
{
  const unsigned int n = (unsigned int)num;
  return (((tilegx_bundle_bits)(n & 0x3ff)) << 49);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_ShiftOpcodeExtension_Y0(int num)
{
  const unsigned int n = (unsigned int)num;
  return ((n & 0x3) << 18);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_ShiftOpcodeExtension_Y1(int num)
{
  const unsigned int n = (unsigned int)num;
  return (((tilegx_bundle_bits)(n & 0x3)) << 49);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_SrcA_X0(int num)
{
  const unsigned int n = (unsigned int)num;
  return ((n & 0x3f) << 6);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_SrcA_X1(int num)
{
  const unsigned int n = (unsigned int)num;
  return (((tilegx_bundle_bits)(n & 0x3f)) << 37);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_SrcA_Y0(int num)
{
  const unsigned int n = (unsigned int)num;
  return ((n & 0x3f) << 6);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_SrcA_Y1(int num)
{
  const unsigned int n = (unsigned int)num;
  return (((tilegx_bundle_bits)(n & 0x3f)) << 37);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_SrcA_Y2(int num)
{
  const unsigned int n = (unsigned int)num;
  return ((n & 0x3f) << 20);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_SrcBDest_Y2(int num)
{
  const unsigned int n = (unsigned int)num;
  return (((tilegx_bundle_bits)(n & 0x3f)) << 51);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_SrcB_X0(int num)
{
  const unsigned int n = (unsigned int)num;
  return ((n & 0x3f) << 12);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_SrcB_X1(int num)
{
  const unsigned int n = (unsigned int)num;
  return (((tilegx_bundle_bits)(n & 0x3f)) << 43);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_SrcB_Y0(int num)
{
  const unsigned int n = (unsigned int)num;
  return ((n & 0x3f) << 12);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_SrcB_Y1(int num)
{
  const unsigned int n = (unsigned int)num;
  return (((tilegx_bundle_bits)(n & 0x3f)) << 43);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_UnaryOpcodeExtension_X0(int num)
{
  const unsigned int n = (unsigned int)num;
  return ((n & 0x3f) << 12);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_UnaryOpcodeExtension_X1(int num)
{
  const unsigned int n = (unsigned int)num;
  return (((tilegx_bundle_bits)(n & 0x3f)) << 43);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_UnaryOpcodeExtension_Y0(int num)
{
  const unsigned int n = (unsigned int)num;
  return ((n & 0x3f) << 12);
}

__attribute__((used)) static __inline tilegx_bundle_bits
create_UnaryOpcodeExtension_Y1(int num)
{
  const unsigned int n = (unsigned int)num;
  return (((tilegx_bundle_bits)(n & 0x3f)) << 43);
}

const struct tilegx_opcode *
find_opcode(tilegx_bundle_bits bits, tilegx_pipeline pipe)
{
  const unsigned short *table = tilegx_bundle_decoder_fsms[pipe];
  int index = 0;

  while (1)
  {
    unsigned short bitspec = table[index];
    unsigned int bitfield =
      ((unsigned int)(bits >> (bitspec & 63))) & (bitspec >> 6);

    unsigned short next = table[index + 1 + bitfield];
    if (next <= TILEGX_OPC_NONE)
      return &tilegx_opcodes[next];

    index = next - TILEGX_OPC_NONE;
  }
}

int
parse_insn_tilegx(tilegx_bundle_bits bits,
                  unsigned long long pc,
                  struct tilegx_decoded_instruction
                  decoded[TILEGX_MAX_INSTRUCTIONS_PER_BUNDLE])
{
  int num_instructions = 0;
  int pipe;

  int min_pipe, max_pipe;
  if ((bits & TILEGX_BUNDLE_MODE_MASK) == 0)
  {
    min_pipe = TILEGX_PIPELINE_X0;
    max_pipe = TILEGX_PIPELINE_X1;
  }
  else
  {
    min_pipe = TILEGX_PIPELINE_Y0;
    max_pipe = TILEGX_PIPELINE_Y2;
  }

  /* For each pipe, find an instruction that fits. */
  for (pipe = min_pipe; pipe <= max_pipe; pipe++)
  {
    const struct tilegx_opcode *opc;
    struct tilegx_decoded_instruction *d;
    int i;

    d = &decoded[num_instructions++];
    opc = find_opcode (bits, (tilegx_pipeline)pipe);
    d->opcode = opc;

    /* Decode each operand, sign extending, etc. as appropriate. */
    for (i = 0; i < opc->num_operands; i++)
    {
      const struct tilegx_operand *op =
        &tilegx_operands[opc->operands[pipe][i]];
      int raw_opval = op->extract (bits);
      long long opval;

      if (op->is_signed)
      {
        /* Sign-extend the operand. */
        int shift = (int)((sizeof(int) * 8) - op->num_bits);
        raw_opval = (raw_opval << shift) >> shift;
      }

      /* Adjust PC-relative scaled branch offsets. */
      if (op->type == TILEGX_OP_TYPE_ADDRESS)
        opval = (raw_opval * TILEGX_BUNDLE_SIZE_IN_BYTES) + pc;
      else
        opval = raw_opval;

      /* Record the final value. */
      d->operands[i] = op;
      d->operand_values[i] = opval;
    }
  }

  return num_instructions;
}

__attribute__((used)) static int
tilegx_spr_compare (const void *a_ptr, const void *b_ptr)
{
  const struct tilegx_spr *a = (const struct tilegx_spr *) a_ptr;
  const struct tilegx_spr *b = (const struct tilegx_spr *) b_ptr;
  return (a->number - b->number);
}

const char *
get_tilegx_spr_name (int num)
{
  void *result;
  struct tilegx_spr key;

  key.number = num;
  result = bsearch((const void *) &key, (const void *) tilegx_sprs,
                   tilegx_num_sprs, sizeof (struct tilegx_spr),
                   tilegx_spr_compare);

  if (result == NULL)
  {
    return (NULL);
  }
  else
  {
    struct tilegx_spr *result_ptr = (struct tilegx_spr *) result;
    return (result_ptr->name);
  }
}

int
print_insn_tilegx (unsigned char * memaddr)
{
  struct tilegx_decoded_instruction
    decoded[TILEGX_MAX_INSTRUCTIONS_PER_BUNDLE];
  unsigned char opbuf[TILEGX_BUNDLE_SIZE_IN_BYTES];
  int i, num_instructions, num_printed;
  tilegx_mnemonic padding_mnemonic;

  memcpy((void *)opbuf, (void *)memaddr, TILEGX_BUNDLE_SIZE_IN_BYTES);

  /* Parse the instructions in the bundle. */
  num_instructions =
    parse_insn_tilegx (*(unsigned long long *)opbuf, (unsigned long long)memaddr, decoded);

  /* Print the instructions in the bundle. */
  printf("{ ");
  num_printed = 0;

  /* Determine which nop opcode is used for padding and should be skipped. */
  padding_mnemonic = TILEGX_OPC_FNOP;
  for (i = 0; i < num_instructions; i++)
  {
    if (!decoded[i].opcode->can_bundle)
    {
      /* Instructions that cannot be bundled are padded out with nops,
         rather than fnops. Displaying them is always clutter. */
      padding_mnemonic = TILEGX_OPC_NOP;
      break;
    }
  }

  for (i = 0; i < num_instructions; i++)
  {
    const struct tilegx_opcode *opcode = decoded[i].opcode;
    const char *name;
    int j;

    /* Do not print out fnops, unless everything is an fnop, in
       which case we will print out just the last one. */
    if (opcode->mnemonic == padding_mnemonic
        && (num_printed > 0 || i + 1 < num_instructions))
      continue;

    if (num_printed > 0)
      printf(" ; ");
    ++num_printed;

    name = opcode->name;
    if (name == NULL)
      name = "<invalid>";
    printf("%s", name);

    for (j = 0; j < opcode->num_operands; j++)
    {
      unsigned long long num;
      const struct tilegx_operand *op;
      const char *spr_name;

      if (j > 0)
        printf (",");
      printf (" ");

      num = decoded[i].operand_values[j];

      op = decoded[i].operands[j];
      switch (op->type)
      {
      case TILEGX_OP_TYPE_REGISTER:
        printf ("%s", tilegx_register_names[(int)num]);
        break;
      case TILEGX_OP_TYPE_SPR:
        spr_name = get_tilegx_spr_name(num);
        if (spr_name != NULL)
          printf ("%s", spr_name);
        else
          printf ("%d", (int)num);
        break;
      case TILEGX_OP_TYPE_IMMEDIATE:
        printf ("%d", (int)num);
        break;
      case TILEGX_OP_TYPE_ADDRESS:
        printf ("0x%016llx", num);
        break;
      default:
        abort ();
      }
    }
  }
  printf (" }\n");

  return TILEGX_BUNDLE_SIZE_IN_BYTES;
}

