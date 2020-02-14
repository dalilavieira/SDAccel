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
struct delta_dev {int /*<<< orphan*/  dev; } ;
struct delta_ctx {int /*<<< orphan*/  name; struct delta_dev* dev; int /*<<< orphan*/  sys_errors; } ;
struct delta_buf {int size; char const* name; unsigned long attrs; int /*<<< orphan*/  paddr; void* vaddr; } ;
typedef  enum v4l2_field { ____Placeholder_v4l2_field } v4l2_field ;
typedef  int /*<<< orphan*/  dma_addr_t ;

/* Variables and functions */
 int DELTA_FRAME_BSY ; 
 int DELTA_FRAME_DEC ; 
 int DELTA_FRAME_M2M ; 
 int DELTA_FRAME_OUT ; 
 int DELTA_FRAME_RDY ; 
 int DELTA_FRAME_REF ; 
 unsigned long DMA_ATTR_WRITE_COMBINE ; 
 int ENOMEM ; 
 int GFP_KERNEL ; 
 int V4L2_BUF_FLAG_BFRAME ; 
 int V4L2_BUF_FLAG_KEYFRAME ; 
 int V4L2_BUF_FLAG_LAST ; 
 int V4L2_BUF_FLAG_PFRAME ; 
 int V4L2_FIELD_BOTTOM ; 
 int V4L2_FIELD_INTERLACED ; 
 int V4L2_FIELD_INTERLACED_BT ; 
 int V4L2_FIELD_INTERLACED_TB ; 
 int V4L2_FIELD_NONE ; 
 int V4L2_FIELD_TOP ; 
 int __GFP_NOWARN ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int,void*,int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,char const*,int) ; 
 void* dma_alloc_attrs (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int,unsigned long) ; 
 int /*<<< orphan*/  dma_free_attrs (int /*<<< orphan*/ ,int,void*,int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  snprintf (char*,unsigned int,char*,char*,char*,char*,char*,char*,char*) ; 

__attribute__((used)) static inline char *frame_type_str(u32 flags)
{
	if (flags & V4L2_BUF_FLAG_KEYFRAME)
		return "I";
	if (flags & V4L2_BUF_FLAG_PFRAME)
		return "P";
	if (flags & V4L2_BUF_FLAG_BFRAME)
		return "B";
	if (flags & V4L2_BUF_FLAG_LAST)
		return "EOS";
	return "?";
}

__attribute__((used)) static inline char *frame_field_str(enum v4l2_field field)
{
	if (field == V4L2_FIELD_NONE)
		return "-";
	if (field == V4L2_FIELD_TOP)
		return "T";
	if (field == V4L2_FIELD_BOTTOM)
		return "B";
	if (field == V4L2_FIELD_INTERLACED)
		return "I";
	if (field == V4L2_FIELD_INTERLACED_TB)
		return "TB";
	if (field == V4L2_FIELD_INTERLACED_BT)
		return "BT";
	return "?";
}

__attribute__((used)) static inline char *frame_state_str(u32 state, char *str, unsigned int len)
{
	snprintf(str, len, "%s %s %s %s %s %s",
		 (state & DELTA_FRAME_REF)  ? "ref" : "   ",
		 (state & DELTA_FRAME_BSY)  ? "bsy" : "   ",
		 (state & DELTA_FRAME_DEC)  ? "dec" : "   ",
		 (state & DELTA_FRAME_OUT)  ? "out" : "   ",
		 (state & DELTA_FRAME_M2M)  ? "m2m" : "   ",
		 (state & DELTA_FRAME_RDY)  ? "rdy" : "   ");
	return str;
}

int hw_alloc(struct delta_ctx *ctx, u32 size, const char *name,
	     struct delta_buf *buf)
{
	struct delta_dev *delta = ctx->dev;
	dma_addr_t dma_addr;
	void *addr;
	unsigned long attrs = DMA_ATTR_WRITE_COMBINE;

	addr = dma_alloc_attrs(delta->dev, size, &dma_addr,
			       GFP_KERNEL | __GFP_NOWARN, attrs);
	if (!addr) {
		dev_err(delta->dev,
			"%s hw_alloc:dma_alloc_coherent failed for %s (size=%d)\n",
			ctx->name, name, size);
		ctx->sys_errors++;
		return -ENOMEM;
	}

	buf->size = size;
	buf->paddr = dma_addr;
	buf->vaddr = addr;
	buf->name = name;
	buf->attrs = attrs;

	dev_dbg(delta->dev,
		"%s allocate %d bytes of HW memory @(virt=0x%p, phy=0x%pad): %s\n",
		ctx->name, size, buf->vaddr, &buf->paddr, buf->name);

	return 0;
}

void hw_free(struct delta_ctx *ctx, struct delta_buf *buf)
{
	struct delta_dev *delta = ctx->dev;

	dev_dbg(delta->dev,
		"%s     free %d bytes of HW memory @(virt=0x%p, phy=0x%pad): %s\n",
		ctx->name, buf->size, buf->vaddr, &buf->paddr, buf->name);

	dma_free_attrs(delta->dev, buf->size,
		       buf->vaddr, buf->paddr, buf->attrs);
}

