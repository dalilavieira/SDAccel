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
typedef  int u32 ;
struct seq_file {struct imr_device* private; } ;
struct imr_regs {void* rmask; void* wmask; int addr_lo; int addr_hi; } ;
struct imr_device {int reg_base; int max_imr; int init; int /*<<< orphan*/  lock; int /*<<< orphan*/  file; } ;
typedef  int phys_addr_t ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENOTSUPP ; 
 size_t IMR_ALIGN ; 
 int IMR_LOCK ; 
 int IMR_MASK ; 
 int IMR_NUM_REGS ; 
 void* IMR_READ_ACCESS_ALL ; 
 void* IMR_WRITE_ACCESS_ALL ; 
 int /*<<< orphan*/  MBI_REG_READ ; 
 int /*<<< orphan*/  MBI_REG_WRITE ; 
 int PTR_ERR_OR_ZERO (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  QRK_MBI_UNIT_MM ; 
 int /*<<< orphan*/  WARN (int,char*,int,int) ; 
 scalar_t__ WARN_ONCE (int,char*) ; 
 int /*<<< orphan*/  debugfs_create_file (char*,int,int /*<<< orphan*/ *,struct imr_device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  imr_dbgfs_state_fops ; 
 struct imr_device imr_dev ; 
 int imr_to_phys (int) ; 
 int iosf_mbi_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int iosf_mbi_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 void* phys_to_imr (int) ; 
 int /*<<< orphan*/  pr_debug (char*,int,int*,int*,size_t,...) ; 
 int /*<<< orphan*/  pr_err (char*,int*,size_t) ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,int,int*,int*,size_t,int,int,char*,char*) ; 

__attribute__((used)) static inline int imr_is_enabled(struct imr_regs *imr)
{
	return !(imr->rmask == IMR_READ_ACCESS_ALL &&
		 imr->wmask == IMR_WRITE_ACCESS_ALL &&
		 imr_to_phys(imr->addr_lo) == 0 &&
		 imr_to_phys(imr->addr_hi) == 0);
}

__attribute__((used)) static int imr_read(struct imr_device *idev, u32 imr_id, struct imr_regs *imr)
{
	u32 reg = imr_id * IMR_NUM_REGS + idev->reg_base;
	int ret;

	ret = iosf_mbi_read(QRK_MBI_UNIT_MM, MBI_REG_READ, reg++, &imr->addr_lo);
	if (ret)
		return ret;

	ret = iosf_mbi_read(QRK_MBI_UNIT_MM, MBI_REG_READ, reg++, &imr->addr_hi);
	if (ret)
		return ret;

	ret = iosf_mbi_read(QRK_MBI_UNIT_MM, MBI_REG_READ, reg++, &imr->rmask);
	if (ret)
		return ret;

	return iosf_mbi_read(QRK_MBI_UNIT_MM, MBI_REG_READ, reg++, &imr->wmask);
}

__attribute__((used)) static int imr_write(struct imr_device *idev, u32 imr_id, struct imr_regs *imr)
{
	unsigned long flags;
	u32 reg = imr_id * IMR_NUM_REGS + idev->reg_base;
	int ret;

	local_irq_save(flags);

	ret = iosf_mbi_write(QRK_MBI_UNIT_MM, MBI_REG_WRITE, reg++, imr->addr_lo);
	if (ret)
		goto failed;

	ret = iosf_mbi_write(QRK_MBI_UNIT_MM, MBI_REG_WRITE, reg++, imr->addr_hi);
	if (ret)
		goto failed;

	ret = iosf_mbi_write(QRK_MBI_UNIT_MM, MBI_REG_WRITE, reg++, imr->rmask);
	if (ret)
		goto failed;

	ret = iosf_mbi_write(QRK_MBI_UNIT_MM, MBI_REG_WRITE, reg++, imr->wmask);
	if (ret)
		goto failed;

	local_irq_restore(flags);
	return 0;
failed:
	/*
	 * If writing to the IOSF failed then we're in an unknown state,
	 * likely a very bad state. An IMR in an invalid state will almost
	 * certainly lead to a memory access violation.
	 */
	local_irq_restore(flags);
	WARN(ret, "IOSF-MBI write fail range 0x%08x-0x%08x unreliable\n",
	     imr_to_phys(imr->addr_lo), imr_to_phys(imr->addr_hi) + IMR_MASK);

	return ret;
}

__attribute__((used)) static int imr_dbgfs_state_show(struct seq_file *s, void *unused)
{
	phys_addr_t base;
	phys_addr_t end;
	int i;
	struct imr_device *idev = s->private;
	struct imr_regs imr;
	size_t size;
	int ret = -ENODEV;

	mutex_lock(&idev->lock);

	for (i = 0; i < idev->max_imr; i++) {

		ret = imr_read(idev, i, &imr);
		if (ret)
			break;

		/*
		 * Remember to add IMR_ALIGN bytes to size to indicate the
		 * inherent IMR_ALIGN size bytes contained in the masked away
		 * lower ten bits.
		 */
		if (imr_is_enabled(&imr)) {
			base = imr_to_phys(imr.addr_lo);
			end = imr_to_phys(imr.addr_hi) + IMR_MASK;
			size = end - base + 1;
		} else {
			base = 0;
			end = 0;
			size = 0;
		}
		seq_printf(s, "imr%02i: base=%pa, end=%pa, size=0x%08zx "
			   "rmask=0x%08x, wmask=0x%08x, %s, %s\n", i,
			   &base, &end, size, imr.rmask, imr.wmask,
			   imr_is_enabled(&imr) ? "enabled " : "disabled",
			   imr.addr_lo & IMR_LOCK ? "locked" : "unlocked");
	}

	mutex_unlock(&idev->lock);
	return ret;
}

__attribute__((used)) static int imr_debugfs_register(struct imr_device *idev)
{
	idev->file = debugfs_create_file("imr_state", 0444, NULL, idev,
					 &imr_dbgfs_state_fops);
	return PTR_ERR_OR_ZERO(idev->file);
}

__attribute__((used)) static int imr_check_params(phys_addr_t base, size_t size)
{
	if ((base & IMR_MASK) || (size & IMR_MASK)) {
		pr_err("base %pa size 0x%08zx must align to 1KiB\n",
			&base, size);
		return -EINVAL;
	}
	if (size == 0)
		return -EINVAL;

	return 0;
}

__attribute__((used)) static inline size_t imr_raw_size(size_t size)
{
	return size - IMR_ALIGN;
}

__attribute__((used)) static inline int imr_address_overlap(phys_addr_t addr, struct imr_regs *imr)
{
	return addr >= imr_to_phys(imr->addr_lo) && addr <= imr_to_phys(imr->addr_hi);
}

int imr_add_range(phys_addr_t base, size_t size,
		  unsigned int rmask, unsigned int wmask)
{
	phys_addr_t end;
	unsigned int i;
	struct imr_device *idev = &imr_dev;
	struct imr_regs imr;
	size_t raw_size;
	int reg;
	int ret;

	if (WARN_ONCE(idev->init == false, "driver not initialized"))
		return -ENODEV;

	ret = imr_check_params(base, size);
	if (ret)
		return ret;

	/* Tweak the size value. */
	raw_size = imr_raw_size(size);
	end = base + raw_size;

	/*
	 * Check for reserved IMR value common to firmware, kernel and grub
	 * indicating a disabled IMR.
	 */
	imr.addr_lo = phys_to_imr(base);
	imr.addr_hi = phys_to_imr(end);
	imr.rmask = rmask;
	imr.wmask = wmask;
	if (!imr_is_enabled(&imr))
		return -ENOTSUPP;

	mutex_lock(&idev->lock);

	/*
	 * Find a free IMR while checking for an existing overlapping range.
	 * Note there's no restriction in silicon to prevent IMR overlaps.
	 * For the sake of simplicity and ease in defining/debugging an IMR
	 * memory map we exclude IMR overlaps.
	 */
	reg = -1;
	for (i = 0; i < idev->max_imr; i++) {
		ret = imr_read(idev, i, &imr);
		if (ret)
			goto failed;

		/* Find overlap @ base or end of requested range. */
		ret = -EINVAL;
		if (imr_is_enabled(&imr)) {
			if (imr_address_overlap(base, &imr))
				goto failed;
			if (imr_address_overlap(end, &imr))
				goto failed;
		} else {
			reg = i;
		}
	}

	/* Error out if we have no free IMR entries. */
	if (reg == -1) {
		ret = -ENOMEM;
		goto failed;
	}

	pr_debug("add %d phys %pa-%pa size %zx mask 0x%08x wmask 0x%08x\n",
		 reg, &base, &end, raw_size, rmask, wmask);

	/* Enable IMR at specified range and access mask. */
	imr.addr_lo = phys_to_imr(base);
	imr.addr_hi = phys_to_imr(end);
	imr.rmask = rmask;
	imr.wmask = wmask;

	ret = imr_write(idev, reg, &imr);
	if (ret < 0) {
		/*
		 * In the highly unlikely event iosf_mbi_write failed
		 * attempt to rollback the IMR setup skipping the trapping
		 * of further IOSF write failures.
		 */
		imr.addr_lo = 0;
		imr.addr_hi = 0;
		imr.rmask = IMR_READ_ACCESS_ALL;
		imr.wmask = IMR_WRITE_ACCESS_ALL;
		imr_write(idev, reg, &imr);
	}
failed:
	mutex_unlock(&idev->lock);
	return ret;
}

__attribute__((used)) static int __imr_remove_range(int reg, phys_addr_t base, size_t size)
{
	phys_addr_t end;
	bool found = false;
	unsigned int i;
	struct imr_device *idev = &imr_dev;
	struct imr_regs imr;
	size_t raw_size;
	int ret = 0;

	if (WARN_ONCE(idev->init == false, "driver not initialized"))
		return -ENODEV;

	/*
	 * Validate address range if deleting by address, else we are
	 * deleting by index where base and size will be ignored.
	 */
	if (reg == -1) {
		ret = imr_check_params(base, size);
		if (ret)
			return ret;
	}

	/* Tweak the size value. */
	raw_size = imr_raw_size(size);
	end = base + raw_size;

	mutex_lock(&idev->lock);

	if (reg >= 0) {
		/* If a specific IMR is given try to use it. */
		ret = imr_read(idev, reg, &imr);
		if (ret)
			goto failed;

		if (!imr_is_enabled(&imr) || imr.addr_lo & IMR_LOCK) {
			ret = -ENODEV;
			goto failed;
		}
		found = true;
	} else {
		/* Search for match based on address range. */
		for (i = 0; i < idev->max_imr; i++) {
			ret = imr_read(idev, i, &imr);
			if (ret)
				goto failed;

			if (!imr_is_enabled(&imr) || imr.addr_lo & IMR_LOCK)
				continue;

			if ((imr_to_phys(imr.addr_lo) == base) &&
			    (imr_to_phys(imr.addr_hi) == end)) {
				found = true;
				reg = i;
				break;
			}
		}
	}

	if (!found) {
		ret = -ENODEV;
		goto failed;
	}

	pr_debug("remove %d phys %pa-%pa size %zx\n", reg, &base, &end, raw_size);

	/* Tear down the IMR. */
	imr.addr_lo = 0;
	imr.addr_hi = 0;
	imr.rmask = IMR_READ_ACCESS_ALL;
	imr.wmask = IMR_WRITE_ACCESS_ALL;

	ret = imr_write(idev, reg, &imr);

failed:
	mutex_unlock(&idev->lock);
	return ret;
}

int imr_remove_range(phys_addr_t base, size_t size)
{
	return __imr_remove_range(-1, base, size);
}

__attribute__((used)) static inline int imr_clear(int reg)
{
	return __imr_remove_range(reg, 0, 0);
}

