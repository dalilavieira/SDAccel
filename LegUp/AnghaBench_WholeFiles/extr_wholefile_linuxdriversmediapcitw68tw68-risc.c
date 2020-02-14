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
struct tw68_buf {int size; int dma; void** cpu; void** jmp; } ;
struct scatterlist {int dummy; } ;
struct pci_dev {int dummy; } ;
typedef  void* __le32 ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int ENOMEM ; 
 unsigned int PAGE_SIZE ; 
 unsigned int RISC_INLINE ; 
 int RISC_JUMP ; 
 unsigned int RISC_LINESTART ; 
 int RISC_SYNCE ; 
 int RISC_SYNCO ; 
 unsigned int UNSET ; 
 void* cpu_to_le32 (int) ; 
 void** pci_alloc_consistent (struct pci_dev*,int,int*) ; 
 int sg_dma_address (struct scatterlist*) ; 
 unsigned int sg_dma_len (struct scatterlist*) ; 
 struct scatterlist* sg_next (struct scatterlist*) ; 

__attribute__((used)) static __le32 *tw68_risc_field(__le32 *rp, struct scatterlist *sglist,
			    unsigned int offset, u32 sync_line,
			    unsigned int bpl, unsigned int padding,
			    unsigned int lines, bool jump)
{
	struct scatterlist *sg;
	unsigned int line, todo, done;

	if (jump) {
		*(rp++) = cpu_to_le32(RISC_JUMP);
		*(rp++) = 0;
	}

	/* sync instruction */
	if (sync_line == 1)
		*(rp++) = cpu_to_le32(RISC_SYNCO);
	else
		*(rp++) = cpu_to_le32(RISC_SYNCE);
	*(rp++) = 0;

	/* scan lines */
	sg = sglist;
	for (line = 0; line < lines; line++) {
		/* calculate next starting position */
		while (offset && offset >= sg_dma_len(sg)) {
			offset -= sg_dma_len(sg);
			sg = sg_next(sg);
		}
		if (bpl <= sg_dma_len(sg) - offset) {
			/* fits into current chunk */
			*(rp++) = cpu_to_le32(RISC_LINESTART |
					      /* (offset<<12) |*/  bpl);
			*(rp++) = cpu_to_le32(sg_dma_address(sg) + offset);
			offset += bpl;
		} else {
			/*
			 * scanline needs to be split.  Put the start in
			 * whatever memory remains using RISC_LINESTART,
			 * then the remainder into following addresses
			 * given by the scatter-gather list.
			 */
			todo = bpl;	/* one full line to be done */
			/* first fragment */
			done = (sg_dma_len(sg) - offset);
			*(rp++) = cpu_to_le32(RISC_LINESTART |
						(7 << 24) |
						done);
			*(rp++) = cpu_to_le32(sg_dma_address(sg) + offset);
			todo -= done;
			sg = sg_next(sg);
			/* succeeding fragments have no offset */
			while (todo > sg_dma_len(sg)) {
				*(rp++) = cpu_to_le32(RISC_INLINE |
						(done << 12) |
						sg_dma_len(sg));
				*(rp++) = cpu_to_le32(sg_dma_address(sg));
				todo -= sg_dma_len(sg);
				sg = sg_next(sg);
				done += sg_dma_len(sg);
			}
			if (todo) {
				/* final chunk - offset 0, count 'todo' */
				*(rp++) = cpu_to_le32(RISC_INLINE |
							(done << 12) |
							todo);
				*(rp++) = cpu_to_le32(sg_dma_address(sg));
			}
			offset = todo;
		}
		offset += padding;
	}

	return rp;
}

int tw68_risc_buffer(struct pci_dev *pci,
			struct tw68_buf *buf,
			struct scatterlist *sglist,
			unsigned int top_offset,
			unsigned int bottom_offset,
			unsigned int bpl,
			unsigned int padding,
			unsigned int lines)
{
	u32 instructions, fields;
	__le32 *rp;

	fields = 0;
	if (UNSET != top_offset)
		fields++;
	if (UNSET != bottom_offset)
		fields++;
	/*
	 * estimate risc mem: worst case is one write per page border +
	 * one write per scan line + syncs + 2 jumps (all 2 dwords).
	 * Padding can cause next bpl to start close to a page border.
	 * First DMA region may be smaller than PAGE_SIZE
	 */
	instructions  = fields * (1 + (((bpl + padding) * lines) /
			 PAGE_SIZE) + lines) + 4;
	buf->size = instructions * 8;
	buf->cpu = pci_alloc_consistent(pci, buf->size, &buf->dma);
	if (buf->cpu == NULL)
		return -ENOMEM;

	/* write risc instructions */
	rp = buf->cpu;
	if (UNSET != top_offset)	/* generates SYNCO */
		rp = tw68_risc_field(rp, sglist, top_offset, 1,
				     bpl, padding, lines, true);
	if (UNSET != bottom_offset)	/* generates SYNCE */
		rp = tw68_risc_field(rp, sglist, bottom_offset, 2,
				     bpl, padding, lines, top_offset == UNSET);

	/* save pointer to jmp instruction address */
	buf->jmp = rp;
	buf->cpu[1] = cpu_to_le32(buf->dma + 8);
	/* assure risc buffer hasn't overflowed */
	BUG_ON((buf->jmp - buf->cpu + 2) * sizeof(buf->cpu[0]) > buf->size);
	return 0;
}

