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
typedef  scalar_t__ ulong ;
typedef  scalar_t__ uint ;
typedef  int /*<<< orphan*/  u_char ;
struct mtd_info {struct ms02nv_private* priv; } ;
struct ms02nv_private {int uaddr; } ;
typedef  scalar_t__ ms02nv_uint ;
typedef  int loff_t ;

/* Variables and functions */
 scalar_t__ CKSEG1ADDR (scalar_t__) ; 
 size_t MS02NV_CSR ; 
 scalar_t__ MS02NV_DIAG ; 
 scalar_t__ MS02NV_DIAG_SIZE_MASK ; 
 scalar_t__ MS02NV_DIAG_SIZE_SHIFT ; 
 scalar_t__ MS02NV_ID ; 
 scalar_t__ MS02NV_MAGIC ; 
 int get_dbe (scalar_t__,scalar_t__*) ; 
 int /*<<< orphan*/  memcpy (int,int,size_t) ; 

__attribute__((used)) static int ms02nv_read(struct mtd_info *mtd, loff_t from,
			size_t len, size_t *retlen, u_char *buf)
{
	struct ms02nv_private *mp = mtd->priv;

	memcpy(buf, mp->uaddr + from, len);
	*retlen = len;
	return 0;
}

__attribute__((used)) static int ms02nv_write(struct mtd_info *mtd, loff_t to,
			size_t len, size_t *retlen, const u_char *buf)
{
	struct ms02nv_private *mp = mtd->priv;

	memcpy(mp->uaddr + to, buf, len);
	*retlen = len;
	return 0;
}

__attribute__((used)) static inline uint ms02nv_probe_one(ulong addr)
{
	ms02nv_uint *ms02nv_diagp;
	ms02nv_uint *ms02nv_magicp;
	uint ms02nv_diag;
	uint ms02nv_magic;
	size_t size;

	int err;

	/*
	 * The firmware writes MS02NV_ID at MS02NV_MAGIC and also
	 * a diagnostic status at MS02NV_DIAG.
	 */
	ms02nv_diagp = (ms02nv_uint *)(CKSEG1ADDR(addr + MS02NV_DIAG));
	ms02nv_magicp = (ms02nv_uint *)(CKSEG1ADDR(addr + MS02NV_MAGIC));
	err = get_dbe(ms02nv_magic, ms02nv_magicp);
	if (err)
		return 0;
	if (ms02nv_magic != MS02NV_ID)
		return 0;

	ms02nv_diag = *ms02nv_diagp;
	size = (ms02nv_diag & MS02NV_DIAG_SIZE_MASK) << MS02NV_DIAG_SIZE_SHIFT;
	if (size > MS02NV_CSR)
		size = MS02NV_CSR;

	return size;
}

