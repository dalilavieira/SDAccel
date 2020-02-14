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

/* Variables and functions */
 unsigned short Ctrl_HNibRead ; 
 unsigned short Ctrl_HNibWrite ; 
 unsigned short Ctrl_IRQEN ; 
 unsigned short Ctrl_LNibRead ; 
 unsigned short Ctrl_LNibWrite ; 
 unsigned char EOC ; 
 unsigned char HNib ; 
 unsigned char MAR ; 
 scalar_t__ PAR_CONTROL ; 
 scalar_t__ PAR_DATA ; 
 short PAR_STATUS ; 
 unsigned char RdAddr ; 
 unsigned char WrAddr ; 
 int /*<<< orphan*/  outb (unsigned short,scalar_t__) ; 

__attribute__((used)) static inline unsigned char inbyte(unsigned short port)
{
	unsigned char _v;

	__asm__ __volatile__ ("inb %w1,%b0" : "=a" (_v) : "d" (port));
	return _v;
}

__attribute__((used)) static inline unsigned char read_nibble(short port, unsigned char offset)
{
	unsigned char retval;

	outb(EOC+offset, port + PAR_DATA);
	outb(RdAddr+offset, port + PAR_DATA);
	inbyte(port + PAR_STATUS);	/* Settling time delay */
	retval = inbyte(port + PAR_STATUS);
	outb(EOC+offset, port + PAR_DATA);

	return retval;
}

__attribute__((used)) static inline unsigned char read_byte_mode0(short ioaddr)
{
	unsigned char low_nib;

	outb(Ctrl_LNibRead, ioaddr + PAR_CONTROL);
	inbyte(ioaddr + PAR_STATUS);
	low_nib = (inbyte(ioaddr + PAR_STATUS) >> 3) & 0x0f;
	outb(Ctrl_HNibRead, ioaddr + PAR_CONTROL);
	inbyte(ioaddr + PAR_STATUS);	/* Settling time delay -- needed!  */
	inbyte(ioaddr + PAR_STATUS);	/* Settling time delay -- needed!  */
	return low_nib | ((inbyte(ioaddr + PAR_STATUS) << 1) & 0xf0);
}

__attribute__((used)) static inline unsigned char read_byte_mode2(short ioaddr)
{
	unsigned char low_nib;

	outb(Ctrl_LNibRead, ioaddr + PAR_CONTROL);
	inbyte(ioaddr + PAR_STATUS);
	low_nib = (inbyte(ioaddr + PAR_STATUS) >> 3) & 0x0f;
	outb(Ctrl_HNibRead, ioaddr + PAR_CONTROL);
	inbyte(ioaddr + PAR_STATUS);	/* Settling time delay -- needed!  */
	return low_nib | ((inbyte(ioaddr + PAR_STATUS) << 1) & 0xf0);
}

__attribute__((used)) static inline unsigned char read_byte_mode4(short ioaddr)
{
	unsigned char low_nib;

	outb(RdAddr | MAR, ioaddr + PAR_DATA);
	low_nib = (inbyte(ioaddr + PAR_STATUS) >> 3) & 0x0f;
	outb(RdAddr | HNib | MAR, ioaddr + PAR_DATA);
	return low_nib | ((inbyte(ioaddr + PAR_STATUS) << 1) & 0xf0);
}

__attribute__((used)) static inline unsigned char read_byte_mode6(short ioaddr)
{
	unsigned char low_nib;

	outb(RdAddr | MAR, ioaddr + PAR_DATA);
	inbyte(ioaddr + PAR_STATUS);
	low_nib = (inbyte(ioaddr + PAR_STATUS) >> 3) & 0x0f;
	outb(RdAddr | HNib | MAR, ioaddr + PAR_DATA);
	inbyte(ioaddr + PAR_STATUS);
	return low_nib | ((inbyte(ioaddr + PAR_STATUS) << 1) & 0xf0);
}

__attribute__((used)) static inline void
write_reg(short port, unsigned char reg, unsigned char value)
{
	unsigned char outval;

	outb(EOC | reg, port + PAR_DATA);
	outval = WrAddr | reg;
	outb(outval, port + PAR_DATA);
	outb(outval, port + PAR_DATA);	/* Double write for PS/2. */

	outval &= 0xf0;
	outval |= value;
	outb(outval, port + PAR_DATA);
	outval &= 0x1f;
	outb(outval, port + PAR_DATA);
	outb(outval, port + PAR_DATA);

	outb(EOC | outval, port + PAR_DATA);
}

__attribute__((used)) static inline void
write_reg_high(short port, unsigned char reg, unsigned char value)
{
	unsigned char outval = EOC | HNib | reg;

	outb(outval, port + PAR_DATA);
	outval &= WrAddr | HNib | 0x0f;
	outb(outval, port + PAR_DATA);
	outb(outval, port + PAR_DATA);	/* Double write for PS/2. */

	outval = WrAddr | HNib | value;
	outb(outval, port + PAR_DATA);
	outval &= HNib | 0x0f;		/* HNib | value */
	outb(outval, port + PAR_DATA);
	outb(outval, port + PAR_DATA);

	outb(EOC | HNib | outval, port + PAR_DATA);
}

__attribute__((used)) static inline void
write_reg_byte(short port, unsigned char reg, unsigned char value)
{
	unsigned char outval;

	outb(EOC | reg, port + PAR_DATA); /* Reset the address register. */
	outval = WrAddr | reg;
	outb(outval, port + PAR_DATA);
	outb(outval, port + PAR_DATA);	/* Double write for PS/2. */

	outb((outval & 0xf0) | (value & 0x0f), port + PAR_DATA);
	outb(value & 0x0f, port + PAR_DATA);
	value >>= 4;
	outb(value, port + PAR_DATA);
	outb(0x10 | value, port + PAR_DATA);
	outb(0x10 | value, port + PAR_DATA);

	outb(EOC  | value, port + PAR_DATA); /* Reset the address register. */
}

__attribute__((used)) static inline void write_byte_mode0(short ioaddr, unsigned char value)
{
	outb(value & 0x0f, ioaddr + PAR_DATA);
	outb((value>>4) | 0x10, ioaddr + PAR_DATA);
}

__attribute__((used)) static inline void write_byte_mode1(short ioaddr, unsigned char value)
{
	outb(value & 0x0f, ioaddr + PAR_DATA);
	outb(Ctrl_IRQEN | Ctrl_LNibWrite, ioaddr + PAR_CONTROL);
	outb((value>>4) | 0x10, ioaddr + PAR_DATA);
	outb(Ctrl_IRQEN | Ctrl_HNibWrite, ioaddr + PAR_CONTROL);
}

__attribute__((used)) static inline void write_word_mode0(short ioaddr, unsigned short value)
{
	outb(value & 0x0f, ioaddr + PAR_DATA);
	value >>= 4;
	outb((value & 0x0f) | 0x10, ioaddr + PAR_DATA);
	value >>= 4;
	outb(value & 0x0f, ioaddr + PAR_DATA);
	value >>= 4;
	outb((value & 0x0f) | 0x10, ioaddr + PAR_DATA);
}

