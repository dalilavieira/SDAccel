#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct sdio_func {int num; unsigned int max_blksize; unsigned int cur_blksize; TYPE_3__* card; void* tmpbuf; int /*<<< orphan*/  enable_timeout; } ;
struct mmc_request {int dummy; } ;
struct mmc_host {unsigned int max_blk_size; unsigned int max_blk_count; int pm_caps; int pm_flags; TYPE_1__* ops; } ;
typedef  int mmc_pm_flag_t ;
typedef  int /*<<< orphan*/  __le32 ;
typedef  int /*<<< orphan*/  __le16 ;
struct TYPE_10__ {scalar_t__ multi_block; } ;
struct TYPE_11__ {struct mmc_host* host; TYPE_2__ cccr; } ;
struct TYPE_9__ {int /*<<< orphan*/  (* post_req ) (struct mmc_host*,struct mmc_request*,int) ;int /*<<< orphan*/  (* pre_req ) (struct mmc_host*,struct mmc_request*) ;} ;

/* Variables and functions */
 int EINVAL ; 
 int EIO ; 
 int ETIME ; 
 int SDIO_CCCR_ABORT ; 
 unsigned int SDIO_CCCR_IOEx ; 
 unsigned int SDIO_CCCR_IORx ; 
 int SDIO_CCCR_SUSPEND ; 
 unsigned int SDIO_FBR_BASE (int) ; 
 unsigned int SDIO_FBR_BLKSIZE ; 
 int SD_IO_RW_DIRECT ; 
 int SD_IO_RW_EXTENDED ; 
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  __mmc_claim_host (struct mmc_host*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cpu_to_le16 (int) ; 
 int /*<<< orphan*/  cpu_to_le32 (int) ; 
 unsigned long jiffies ; 
 int le16_to_cpup (int /*<<< orphan*/ *) ; 
 int le32_to_cpup (int /*<<< orphan*/ *) ; 
 unsigned int min (unsigned int,unsigned int) ; 
 unsigned int mmc_align_data_size (TYPE_3__*,unsigned int) ; 
 scalar_t__ mmc_blksz_for_byte_mode (TYPE_3__*) ; 
 scalar_t__ mmc_card_broken_byte_mode_512 (TYPE_3__*) ; 
 int /*<<< orphan*/  mmc_card_lenient_fn0 (TYPE_3__*) ; 
 int mmc_io_rw_direct (TYPE_3__*,int,int,unsigned int,unsigned char,...) ; 
 int mmc_io_rw_extended (TYPE_3__*,int,int,unsigned int,int,int*,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  mmc_release_host (struct mmc_host*) ; 
 unsigned long msecs_to_jiffies (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msleep (unsigned int) ; 
 int /*<<< orphan*/  pr_debug (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sdio_func_id (struct sdio_func*) ; 
 int /*<<< orphan*/  stub1 (struct mmc_host*,struct mmc_request*) ; 
 int /*<<< orphan*/  stub2 (struct mmc_host*,struct mmc_request*,int) ; 
 scalar_t__ time_after (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  usleep_range (unsigned int,unsigned int) ; 

__attribute__((used)) static inline bool sdio_is_io_busy(u32 opcode, u32 arg)
{
	u32 addr;

	addr = (arg >> 9) & 0x1FFFF;

	return (opcode == SD_IO_RW_EXTENDED ||
		(opcode == SD_IO_RW_DIRECT &&
		!(addr == SDIO_CCCR_ABORT || addr == SDIO_CCCR_SUSPEND)));
}

__attribute__((used)) static inline void mmc_delay(unsigned int ms)
{
	if (ms <= 20)
		usleep_range(ms * 1000, ms * 1250);
	else
		msleep(ms);
}

__attribute__((used)) static inline void mmc_register_pm_notifier(struct mmc_host *host) { }

__attribute__((used)) static inline void mmc_unregister_pm_notifier(struct mmc_host *host) { }

__attribute__((used)) static inline void mmc_claim_host(struct mmc_host *host)
{
	__mmc_claim_host(host, NULL, NULL);
}

__attribute__((used)) static inline void mmc_pre_req(struct mmc_host *host, struct mmc_request *mrq)
{
	if (host->ops->pre_req)
		host->ops->pre_req(host, mrq);
}

__attribute__((used)) static inline void mmc_post_req(struct mmc_host *host, struct mmc_request *mrq,
				int err)
{
	if (host->ops->post_req)
		host->ops->post_req(host, mrq, err);
}

void sdio_release_host(struct sdio_func *func)
{
	if (WARN_ON(!func))
		return;

	mmc_release_host(func->card->host);
}

int sdio_enable_func(struct sdio_func *func)
{
	int ret;
	unsigned char reg;
	unsigned long timeout;

	if (!func)
		return -EINVAL;

	pr_debug("SDIO: Enabling device %s...\n", sdio_func_id(func));

	ret = mmc_io_rw_direct(func->card, 0, 0, SDIO_CCCR_IOEx, 0, &reg);
	if (ret)
		goto err;

	reg |= 1 << func->num;

	ret = mmc_io_rw_direct(func->card, 1, 0, SDIO_CCCR_IOEx, reg, NULL);
	if (ret)
		goto err;

	timeout = jiffies + msecs_to_jiffies(func->enable_timeout);

	while (1) {
		ret = mmc_io_rw_direct(func->card, 0, 0, SDIO_CCCR_IORx, 0, &reg);
		if (ret)
			goto err;
		if (reg & (1 << func->num))
			break;
		ret = -ETIME;
		if (time_after(jiffies, timeout))
			goto err;
	}

	pr_debug("SDIO: Enabled device %s\n", sdio_func_id(func));

	return 0;

err:
	pr_debug("SDIO: Failed to enable device %s\n", sdio_func_id(func));
	return ret;
}

int sdio_disable_func(struct sdio_func *func)
{
	int ret;
	unsigned char reg;

	if (!func)
		return -EINVAL;

	pr_debug("SDIO: Disabling device %s...\n", sdio_func_id(func));

	ret = mmc_io_rw_direct(func->card, 0, 0, SDIO_CCCR_IOEx, 0, &reg);
	if (ret)
		goto err;

	reg &= ~(1 << func->num);

	ret = mmc_io_rw_direct(func->card, 1, 0, SDIO_CCCR_IOEx, reg, NULL);
	if (ret)
		goto err;

	pr_debug("SDIO: Disabled device %s\n", sdio_func_id(func));

	return 0;

err:
	pr_debug("SDIO: Failed to disable device %s\n", sdio_func_id(func));
	return -EIO;
}

int sdio_set_block_size(struct sdio_func *func, unsigned blksz)
{
	int ret;

	if (blksz > func->card->host->max_blk_size)
		return -EINVAL;

	if (blksz == 0) {
		blksz = min(func->max_blksize, func->card->host->max_blk_size);
		blksz = min(blksz, 512u);
	}

	ret = mmc_io_rw_direct(func->card, 1, 0,
		SDIO_FBR_BASE(func->num) + SDIO_FBR_BLKSIZE,
		blksz & 0xff, NULL);
	if (ret)
		return ret;
	ret = mmc_io_rw_direct(func->card, 1, 0,
		SDIO_FBR_BASE(func->num) + SDIO_FBR_BLKSIZE + 1,
		(blksz >> 8) & 0xff, NULL);
	if (ret)
		return ret;
	func->cur_blksize = blksz;
	return 0;
}

__attribute__((used)) static inline unsigned int sdio_max_byte_size(struct sdio_func *func)
{
	unsigned mval =	func->card->host->max_blk_size;

	if (mmc_blksz_for_byte_mode(func->card))
		mval = min(mval, func->cur_blksize);
	else
		mval = min(mval, func->max_blksize);

	if (mmc_card_broken_byte_mode_512(func->card))
		return min(mval, 511u);

	return min(mval, 512u); /* maximum size for byte mode */
}

unsigned int sdio_align_size(struct sdio_func *func, unsigned int sz)
{
	unsigned int orig_sz;
	unsigned int blk_sz, byte_sz;
	unsigned chunk_sz;

	orig_sz = sz;

	/*
	 * Do a first check with the controller, in case it
	 * wants to increase the size up to a point where it
	 * might need more than one block.
	 */
	sz = mmc_align_data_size(func->card, sz);

	/*
	 * If we can still do this with just a byte transfer, then
	 * we're done.
	 */
	if (sz <= sdio_max_byte_size(func))
		return sz;

	if (func->card->cccr.multi_block) {
		/*
		 * Check if the transfer is already block aligned
		 */
		if ((sz % func->cur_blksize) == 0)
			return sz;

		/*
		 * Realign it so that it can be done with one request,
		 * and recheck if the controller still likes it.
		 */
		blk_sz = ((sz + func->cur_blksize - 1) /
			func->cur_blksize) * func->cur_blksize;
		blk_sz = mmc_align_data_size(func->card, blk_sz);

		/*
		 * This value is only good if it is still just
		 * one request.
		 */
		if ((blk_sz % func->cur_blksize) == 0)
			return blk_sz;

		/*
		 * We failed to do one request, but at least try to
		 * pad the remainder properly.
		 */
		byte_sz = mmc_align_data_size(func->card,
				sz % func->cur_blksize);
		if (byte_sz <= sdio_max_byte_size(func)) {
			blk_sz = sz / func->cur_blksize;
			return blk_sz * func->cur_blksize + byte_sz;
		}
	} else {
		/*
		 * We need multiple requests, so first check that the
		 * controller can handle the chunk size;
		 */
		chunk_sz = mmc_align_data_size(func->card,
				sdio_max_byte_size(func));
		if (chunk_sz == sdio_max_byte_size(func)) {
			/*
			 * Fix up the size of the remainder (if any)
			 */
			byte_sz = orig_sz % chunk_sz;
			if (byte_sz) {
				byte_sz = mmc_align_data_size(func->card,
						byte_sz);
			}

			return (orig_sz / chunk_sz) * chunk_sz + byte_sz;
		}
	}

	/*
	 * The controller is simply incapable of transferring the size
	 * we want in decent manner, so just return the original size.
	 */
	return orig_sz;
}

__attribute__((used)) static int sdio_io_rw_ext_helper(struct sdio_func *func, int write,
	unsigned addr, int incr_addr, u8 *buf, unsigned size)
{
	unsigned remainder = size;
	unsigned max_blocks;
	int ret;

	if (!func || (func->num > 7))
		return -EINVAL;

	/* Do the bulk of the transfer using block mode (if supported). */
	if (func->card->cccr.multi_block && (size > sdio_max_byte_size(func))) {
		/* Blocks per command is limited by host count, host transfer
		 * size and the maximum for IO_RW_EXTENDED of 511 blocks. */
		max_blocks = min(func->card->host->max_blk_count, 511u);

		while (remainder >= func->cur_blksize) {
			unsigned blocks;

			blocks = remainder / func->cur_blksize;
			if (blocks > max_blocks)
				blocks = max_blocks;
			size = blocks * func->cur_blksize;

			ret = mmc_io_rw_extended(func->card, write,
				func->num, addr, incr_addr, buf,
				blocks, func->cur_blksize);
			if (ret)
				return ret;

			remainder -= size;
			buf += size;
			if (incr_addr)
				addr += size;
		}
	}

	/* Write the remainder using byte mode. */
	while (remainder > 0) {
		size = min(remainder, sdio_max_byte_size(func));

		/* Indicate byte mode by setting "blocks" = 0 */
		ret = mmc_io_rw_extended(func->card, write, func->num, addr,
			 incr_addr, buf, 0, size);
		if (ret)
			return ret;

		remainder -= size;
		buf += size;
		if (incr_addr)
			addr += size;
	}
	return 0;
}

u8 sdio_readb(struct sdio_func *func, unsigned int addr, int *err_ret)
{
	int ret;
	u8 val;

	if (!func) {
		if (err_ret)
			*err_ret = -EINVAL;
		return 0xFF;
	}

	ret = mmc_io_rw_direct(func->card, 0, func->num, addr, 0, &val);
	if (err_ret)
		*err_ret = ret;
	if (ret)
		return 0xFF;

	return val;
}

void sdio_writeb(struct sdio_func *func, u8 b, unsigned int addr, int *err_ret)
{
	int ret;

	if (!func) {
		if (err_ret)
			*err_ret = -EINVAL;
		return;
	}

	ret = mmc_io_rw_direct(func->card, 1, func->num, addr, b, NULL);
	if (err_ret)
		*err_ret = ret;
}

u8 sdio_writeb_readb(struct sdio_func *func, u8 write_byte,
	unsigned int addr, int *err_ret)
{
	int ret;
	u8 val;

	ret = mmc_io_rw_direct(func->card, 1, func->num, addr,
			write_byte, &val);
	if (err_ret)
		*err_ret = ret;
	if (ret)
		return 0xff;

	return val;
}

int sdio_memcpy_fromio(struct sdio_func *func, void *dst,
	unsigned int addr, int count)
{
	return sdio_io_rw_ext_helper(func, 0, addr, 1, dst, count);
}

int sdio_memcpy_toio(struct sdio_func *func, unsigned int addr,
	void *src, int count)
{
	return sdio_io_rw_ext_helper(func, 1, addr, 1, src, count);
}

int sdio_readsb(struct sdio_func *func, void *dst, unsigned int addr,
	int count)
{
	return sdio_io_rw_ext_helper(func, 0, addr, 0, dst, count);
}

int sdio_writesb(struct sdio_func *func, unsigned int addr, void *src,
	int count)
{
	return sdio_io_rw_ext_helper(func, 1, addr, 0, src, count);
}

u16 sdio_readw(struct sdio_func *func, unsigned int addr, int *err_ret)
{
	int ret;

	ret = sdio_memcpy_fromio(func, func->tmpbuf, addr, 2);
	if (err_ret)
		*err_ret = ret;
	if (ret)
		return 0xFFFF;

	return le16_to_cpup((__le16 *)func->tmpbuf);
}

void sdio_writew(struct sdio_func *func, u16 b, unsigned int addr, int *err_ret)
{
	int ret;

	*(__le16 *)func->tmpbuf = cpu_to_le16(b);

	ret = sdio_memcpy_toio(func, addr, func->tmpbuf, 2);
	if (err_ret)
		*err_ret = ret;
}

u32 sdio_readl(struct sdio_func *func, unsigned int addr, int *err_ret)
{
	int ret;

	ret = sdio_memcpy_fromio(func, func->tmpbuf, addr, 4);
	if (err_ret)
		*err_ret = ret;
	if (ret)
		return 0xFFFFFFFF;

	return le32_to_cpup((__le32 *)func->tmpbuf);
}

void sdio_writel(struct sdio_func *func, u32 b, unsigned int addr, int *err_ret)
{
	int ret;

	*(__le32 *)func->tmpbuf = cpu_to_le32(b);

	ret = sdio_memcpy_toio(func, addr, func->tmpbuf, 4);
	if (err_ret)
		*err_ret = ret;
}

unsigned char sdio_f0_readb(struct sdio_func *func, unsigned int addr,
	int *err_ret)
{
	int ret;
	unsigned char val;

	if (!func) {
		if (err_ret)
			*err_ret = -EINVAL;
		return 0xFF;
	}

	ret = mmc_io_rw_direct(func->card, 0, 0, addr, 0, &val);
	if (err_ret)
		*err_ret = ret;
	if (ret)
		return 0xFF;

	return val;
}

void sdio_f0_writeb(struct sdio_func *func, unsigned char b, unsigned int addr,
	int *err_ret)
{
	int ret;

	if (!func) {
		if (err_ret)
			*err_ret = -EINVAL;
		return;
	}

	if ((addr < 0xF0 || addr > 0xFF) && (!mmc_card_lenient_fn0(func->card))) {
		if (err_ret)
			*err_ret = -EINVAL;
		return;
	}

	ret = mmc_io_rw_direct(func->card, 1, 0, addr, b, NULL);
	if (err_ret)
		*err_ret = ret;
}

mmc_pm_flag_t sdio_get_host_pm_caps(struct sdio_func *func)
{
	if (!func)
		return 0;

	return func->card->host->pm_caps;
}

int sdio_set_host_pm_flags(struct sdio_func *func, mmc_pm_flag_t flags)
{
	struct mmc_host *host;

	if (!func)
		return -EINVAL;

	host = func->card->host;

	if (flags & ~host->pm_caps)
		return -EINVAL;

	/* function suspend methods are serialized, hence no lock needed */
	host->pm_flags |= flags;
	return 0;
}

