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
 int __get_cmd640_reg (int) ; 
 int /*<<< orphan*/  __put_cmd640_reg (int,int) ; 
 int cmd640_key ; 
 int /*<<< orphan*/  cmd640_lock ; 
 int inb (int) ; 
 int inb_p (int) ; 
 int inl (int) ; 
 int /*<<< orphan*/  outb (int,int) ; 
 int /*<<< orphan*/  outb_p (int,int) ; 
 int /*<<< orphan*/  outl (int,int) ; 
 int /*<<< orphan*/  outl_p (int,int) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static void put_cmd640_reg_pci1(u16 reg, u8 val)
{
	outl_p((reg & 0xfc) | cmd640_key, 0xcf8);
	outb_p(val, (reg & 3) | 0xcfc);
}

__attribute__((used)) static u8 get_cmd640_reg_pci1(u16 reg)
{
	outl_p((reg & 0xfc) | cmd640_key, 0xcf8);
	return inb_p((reg & 3) | 0xcfc);
}

__attribute__((used)) static void put_cmd640_reg_pci2(u16 reg, u8 val)
{
	outb_p(0x10, 0xcf8);
	outb_p(val, cmd640_key + reg);
	outb_p(0, 0xcf8);
}

__attribute__((used)) static u8 get_cmd640_reg_pci2(u16 reg)
{
	u8 b;

	outb_p(0x10, 0xcf8);
	b = inb_p(cmd640_key + reg);
	outb_p(0, 0xcf8);
	return b;
}

__attribute__((used)) static void put_cmd640_reg_vlb(u16 reg, u8 val)
{
	outb_p(reg, cmd640_key);
	outb_p(val, cmd640_key + 4);
}

__attribute__((used)) static u8 get_cmd640_reg_vlb(u16 reg)
{
	outb_p(reg, cmd640_key);
	return inb_p(cmd640_key + 4);
}

__attribute__((used)) static u8 get_cmd640_reg(u16 reg)
{
	unsigned long flags;
	u8 b;

	spin_lock_irqsave(&cmd640_lock, flags);
	b = __get_cmd640_reg(reg);
	spin_unlock_irqrestore(&cmd640_lock, flags);
	return b;
}

__attribute__((used)) static void put_cmd640_reg(u16 reg, u8 val)
{
	unsigned long flags;

	spin_lock_irqsave(&cmd640_lock, flags);
	__put_cmd640_reg(reg, val);
	spin_unlock_irqrestore(&cmd640_lock, flags);
}

__attribute__((used)) static int pci_conf1(void)
{
	unsigned long flags;
	u32 tmp;

	spin_lock_irqsave(&cmd640_lock, flags);
	outb(0x01, 0xCFB);
	tmp = inl(0xCF8);
	outl(0x80000000, 0xCF8);
	if (inl(0xCF8) == 0x80000000) {
		outl(tmp, 0xCF8);
		spin_unlock_irqrestore(&cmd640_lock, flags);
		return 1;
	}
	outl(tmp, 0xCF8);
	spin_unlock_irqrestore(&cmd640_lock, flags);
	return 0;
}

__attribute__((used)) static int pci_conf2(void)
{
	unsigned long flags;

	spin_lock_irqsave(&cmd640_lock, flags);
	outb(0x00, 0xCFB);
	outb(0x00, 0xCF8);
	outb(0x00, 0xCFA);
	if (inb(0xCF8) == 0x00 && inb(0xCF8) == 0x00) {
		spin_unlock_irqrestore(&cmd640_lock, flags);
		return 1;
	}
	spin_unlock_irqrestore(&cmd640_lock, flags);
	return 0;
}

