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
typedef  size_t ssize_t ;
typedef  int loff_t ;

/* Variables and functions */
 unsigned char ioread8 (int) ; 
 int /*<<< orphan*/  iowrite8 (unsigned char,int) ; 
 int /*<<< orphan*/  memcpy_fromio (char*,int,size_t) ; 
 int /*<<< orphan*/  memcpy_toio (int,char*,size_t) ; 
 int mmio_nvram_len ; 
 int /*<<< orphan*/  mmio_nvram_lock ; 
 int mmio_nvram_start ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static ssize_t mmio_nvram_read(char *buf, size_t count, loff_t *index)
{
	unsigned long flags;

	if (*index >= mmio_nvram_len)
		return 0;
	if (*index + count > mmio_nvram_len)
		count = mmio_nvram_len - *index;

	spin_lock_irqsave(&mmio_nvram_lock, flags);

	memcpy_fromio(buf, mmio_nvram_start + *index, count);

	spin_unlock_irqrestore(&mmio_nvram_lock, flags);
	
	*index += count;
	return count;
}

__attribute__((used)) static unsigned char mmio_nvram_read_val(int addr)
{
	unsigned long flags;
	unsigned char val;

	if (addr >= mmio_nvram_len)
		return 0xff;

	spin_lock_irqsave(&mmio_nvram_lock, flags);

	val = ioread8(mmio_nvram_start + addr);

	spin_unlock_irqrestore(&mmio_nvram_lock, flags);

	return val;
}

__attribute__((used)) static ssize_t mmio_nvram_write(char *buf, size_t count, loff_t *index)
{
	unsigned long flags;

	if (*index >= mmio_nvram_len)
		return 0;
	if (*index + count > mmio_nvram_len)
		count = mmio_nvram_len - *index;

	spin_lock_irqsave(&mmio_nvram_lock, flags);

	memcpy_toio(mmio_nvram_start + *index, buf, count);

	spin_unlock_irqrestore(&mmio_nvram_lock, flags);
	
	*index += count;
	return count;
}

__attribute__((used)) static void mmio_nvram_write_val(int addr, unsigned char val)
{
	unsigned long flags;

	if (addr < mmio_nvram_len) {
		spin_lock_irqsave(&mmio_nvram_lock, flags);

		iowrite8(val, mmio_nvram_start + addr);

		spin_unlock_irqrestore(&mmio_nvram_lock, flags);
	}
}

__attribute__((used)) static ssize_t mmio_nvram_get_size(void)
{
	return mmio_nvram_len;
}

