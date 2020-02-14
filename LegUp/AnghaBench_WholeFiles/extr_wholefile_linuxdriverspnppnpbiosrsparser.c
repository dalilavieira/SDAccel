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
struct resource {unsigned long start; } ;
struct pnp_option {int flags; } ;
struct pnp_id {int dummy; } ;
struct pnp_dev {unsigned int num_dependent_sets; char* name; int /*<<< orphan*/  dev; } ;
struct pnp_bios_node {int dummy; } ;

/* Variables and functions */
 int IORESOURCE_DISABLED ; 
 int /*<<< orphan*/  IORESOURCE_DMA ; 
 int /*<<< orphan*/  IORESOURCE_IO ; 
 int /*<<< orphan*/  IORESOURCE_IRQ ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 unsigned char LARGE_TAG ; 
#define  LARGE_TAG_ANSISTR 139 
#define  LARGE_TAG_FIXEDMEM32 138 
#define  LARGE_TAG_MEM 137 
#define  LARGE_TAG_MEM32 136 
#define  LARGE_TAG_VENDOR 135 
 int PNP_EISA_ID_MASK ; 
 int PNP_NAME_LEN ; 
 int PNP_OPTION_DEPENDENT ; 
 unsigned int PNP_OPTION_PRIORITY_MASK ; 
 unsigned int PNP_OPTION_PRIORITY_SHIFT ; 
 unsigned int PNP_OPTION_SET_MASK ; 
 unsigned int PNP_OPTION_SET_SHIFT ; 
 int PNP_RES_PRIORITY_FUNCTIONAL ; 
 int PNP_RES_PRIORITY_INVALID ; 
#define  SMALL_TAG_COMPATDEVID 134 
#define  SMALL_TAG_DMA 133 
#define  SMALL_TAG_END 132 
#define  SMALL_TAG_FIXEDPORT 131 
#define  SMALL_TAG_IRQ 130 
#define  SMALL_TAG_PORT 129 
#define  SMALL_TAG_VENDOR 128 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*,int,int) ; 
 int /*<<< orphan*/  pnp_add_dma_resource (struct pnp_dev*,int,int) ; 
 struct pnp_id* pnp_add_id (struct pnp_dev*,char*) ; 
 int /*<<< orphan*/  pnp_add_io_resource (struct pnp_dev*,int,int,int) ; 
 int /*<<< orphan*/  pnp_add_irq_resource (struct pnp_dev*,int,int) ; 
 int /*<<< orphan*/  pnp_add_mem_resource (struct pnp_dev*,int,int,int) ; 
 int /*<<< orphan*/  pnp_dbg (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  pnp_eisa_id_to_string (int,char*) ; 
 struct resource* pnp_get_resource (struct pnp_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pnp_init_resources (struct pnp_dev*) ; 
 scalar_t__ pnp_resource_enabled (struct resource*) ; 
 unsigned long resource_size (struct resource*) ; 
 int /*<<< orphan*/  strncpy (char*,unsigned char*,int) ; 

inline void pcibios_penalize_isa_irq(int irq, int active)
{
}

__attribute__((used)) static inline int pnp_option_is_dependent(struct pnp_option *option)
{
	return option->flags & PNP_OPTION_DEPENDENT ? 1 : 0;
}

__attribute__((used)) static inline unsigned int pnp_option_set(struct pnp_option *option)
{
	return (option->flags >> PNP_OPTION_SET_SHIFT) & PNP_OPTION_SET_MASK;
}

__attribute__((used)) static inline unsigned int pnp_option_priority(struct pnp_option *option)
{
	return (option->flags >> PNP_OPTION_PRIORITY_SHIFT) &
	    PNP_OPTION_PRIORITY_MASK;
}

__attribute__((used)) static inline unsigned int pnp_new_dependent_set(struct pnp_dev *dev,
						 int priority)
{
	unsigned int flags;

	if (priority > PNP_RES_PRIORITY_FUNCTIONAL) {
		dev_warn(&dev->dev, "invalid dependent option priority %d "
			 "clipped to %d", priority,
			 PNP_RES_PRIORITY_INVALID);
		priority = PNP_RES_PRIORITY_INVALID;
	}

	flags = PNP_OPTION_DEPENDENT |
	    ((dev->num_dependent_sets & PNP_OPTION_SET_MASK) <<
		PNP_OPTION_SET_SHIFT) |
	    ((priority & PNP_OPTION_PRIORITY_MASK) <<
		PNP_OPTION_PRIORITY_SHIFT);

	dev->num_dependent_sets++;

	return flags;
}

__attribute__((used)) static inline int pnpbios_interface_attach_device(struct pnp_bios_node * node) { return 0; }

__attribute__((used)) static inline int pnpbios_proc_init (void) { return 0; }

__attribute__((used)) static inline void pnpbios_proc_exit (void) { ; }

__attribute__((used)) static void pnpbios_parse_allocated_ioresource(struct pnp_dev *dev,
					       int start, int len)
{
	int flags = 0;
	int end = start + len - 1;

	if (len <= 0 || end >= 0x10003)
		flags |= IORESOURCE_DISABLED;

	pnp_add_io_resource(dev, start, end, flags);
}

__attribute__((used)) static void pnpbios_parse_allocated_memresource(struct pnp_dev *dev,
						int start, int len)
{
	int flags = 0;
	int end = start + len - 1;

	if (len <= 0)
		flags |= IORESOURCE_DISABLED;

	pnp_add_mem_resource(dev, start, end, flags);
}

__attribute__((used)) static unsigned char *pnpbios_parse_allocated_resource_data(struct pnp_dev *dev,
							    unsigned char *p,
							    unsigned char *end)
{
	unsigned int len, tag;
	int io, size, mask, i, flags;

	if (!p)
		return NULL;

	pnp_dbg(&dev->dev, "parse allocated resources\n");

	pnp_init_resources(dev);

	while ((char *)p < (char *)end) {

		/* determine the type of tag */
		if (p[0] & LARGE_TAG) {	/* large tag */
			len = (p[2] << 8) | p[1];
			tag = p[0];
		} else {	/* small tag */
			len = p[0] & 0x07;
			tag = ((p[0] >> 3) & 0x0f);
		}

		switch (tag) {

		case LARGE_TAG_MEM:
			if (len != 9)
				goto len_err;
			io = *(short *)&p[4];
			size = *(short *)&p[10];
			pnpbios_parse_allocated_memresource(dev, io, size);
			break;

		case LARGE_TAG_ANSISTR:
			/* ignore this for now */
			break;

		case LARGE_TAG_VENDOR:
			/* do nothing */
			break;

		case LARGE_TAG_MEM32:
			if (len != 17)
				goto len_err;
			io = *(int *)&p[4];
			size = *(int *)&p[16];
			pnpbios_parse_allocated_memresource(dev, io, size);
			break;

		case LARGE_TAG_FIXEDMEM32:
			if (len != 9)
				goto len_err;
			io = *(int *)&p[4];
			size = *(int *)&p[8];
			pnpbios_parse_allocated_memresource(dev, io, size);
			break;

		case SMALL_TAG_IRQ:
			if (len < 2 || len > 3)
				goto len_err;
			flags = 0;
			io = -1;
			mask = p[1] + p[2] * 256;
			for (i = 0; i < 16; i++, mask = mask >> 1)
				if (mask & 0x01)
					io = i;
			if (io != -1)
				pcibios_penalize_isa_irq(io, 1);
			else
				flags = IORESOURCE_DISABLED;
			pnp_add_irq_resource(dev, io, flags);
			break;

		case SMALL_TAG_DMA:
			if (len != 2)
				goto len_err;
			flags = 0;
			io = -1;
			mask = p[1];
			for (i = 0; i < 8; i++, mask = mask >> 1)
				if (mask & 0x01)
					io = i;
			if (io == -1)
				flags = IORESOURCE_DISABLED;
			pnp_add_dma_resource(dev, io, flags);
			break;

		case SMALL_TAG_PORT:
			if (len != 7)
				goto len_err;
			io = p[2] + p[3] * 256;
			size = p[7];
			pnpbios_parse_allocated_ioresource(dev, io, size);
			break;

		case SMALL_TAG_VENDOR:
			/* do nothing */
			break;

		case SMALL_TAG_FIXEDPORT:
			if (len != 3)
				goto len_err;
			io = p[1] + p[2] * 256;
			size = p[3];
			pnpbios_parse_allocated_ioresource(dev, io, size);
			break;

		case SMALL_TAG_END:
			p = p + 2;
			return (unsigned char *)p;
			break;

		default:	/* an unknown tag */
len_err:
			dev_err(&dev->dev, "unknown tag %#x length %d\n",
				tag, len);
			break;
		}

		/* continue to the next tag */
		if (p[0] & LARGE_TAG)
			p += len + 3;
		else
			p += len + 1;
	}

	dev_err(&dev->dev, "no end tag in resource structure\n");

	return NULL;
}

__attribute__((used)) static unsigned char *pnpbios_parse_compatible_ids(unsigned char *p,
						   unsigned char *end,
						   struct pnp_dev *dev)
{
	int len, tag;
	u32 eisa_id;
	char id[8];
	struct pnp_id *dev_id;

	if (!p)
		return NULL;

	while ((char *)p < (char *)end) {

		/* determine the type of tag */
		if (p[0] & LARGE_TAG) {	/* large tag */
			len = (p[2] << 8) | p[1];
			tag = p[0];
		} else {	/* small tag */
			len = p[0] & 0x07;
			tag = ((p[0] >> 3) & 0x0f);
		}

		switch (tag) {

		case LARGE_TAG_ANSISTR:
			strncpy(dev->name, p + 3,
				len >= PNP_NAME_LEN ? PNP_NAME_LEN - 2 : len);
			dev->name[len >=
				  PNP_NAME_LEN ? PNP_NAME_LEN - 1 : len] = '\0';
			break;

		case SMALL_TAG_COMPATDEVID:	/* compatible ID */
			if (len != 4)
				goto len_err;
			eisa_id = p[1] | p[2] << 8 | p[3] << 16 | p[4] << 24;
			pnp_eisa_id_to_string(eisa_id & PNP_EISA_ID_MASK, id);
			dev_id = pnp_add_id(dev, id);
			if (!dev_id)
				return NULL;
			break;

		case SMALL_TAG_END:
			p = p + 2;
			return (unsigned char *)p;
			break;

		default:	/* an unknown tag */
len_err:
			dev_err(&dev->dev, "unknown tag %#x length %d\n",
				tag, len);
			break;
		}

		/* continue to the next tag */
		if (p[0] & LARGE_TAG)
			p += len + 3;
		else
			p += len + 1;
	}

	dev_err(&dev->dev, "no end tag in resource structure\n");

	return NULL;
}

__attribute__((used)) static void pnpbios_encode_mem(struct pnp_dev *dev, unsigned char *p,
			       struct resource *res)
{
	unsigned long base;
	unsigned long len;

	if (pnp_resource_enabled(res)) {
		base = res->start;
		len = resource_size(res);
	} else {
		base = 0;
		len = 0;
	}

	p[4] = (base >> 8) & 0xff;
	p[5] = ((base >> 8) >> 8) & 0xff;
	p[6] = (base >> 8) & 0xff;
	p[7] = ((base >> 8) >> 8) & 0xff;
	p[10] = (len >> 8) & 0xff;
	p[11] = ((len >> 8) >> 8) & 0xff;

	pnp_dbg(&dev->dev, "  encode mem %#lx-%#lx\n", base, base + len - 1);
}

__attribute__((used)) static void pnpbios_encode_mem32(struct pnp_dev *dev, unsigned char *p,
				 struct resource *res)
{
	unsigned long base;
	unsigned long len;

	if (pnp_resource_enabled(res)) {
		base = res->start;
		len = resource_size(res);
	} else {
		base = 0;
		len = 0;
	}

	p[4] = base & 0xff;
	p[5] = (base >> 8) & 0xff;
	p[6] = (base >> 16) & 0xff;
	p[7] = (base >> 24) & 0xff;
	p[8] = base & 0xff;
	p[9] = (base >> 8) & 0xff;
	p[10] = (base >> 16) & 0xff;
	p[11] = (base >> 24) & 0xff;
	p[16] = len & 0xff;
	p[17] = (len >> 8) & 0xff;
	p[18] = (len >> 16) & 0xff;
	p[19] = (len >> 24) & 0xff;

	pnp_dbg(&dev->dev, "  encode mem32 %#lx-%#lx\n", base, base + len - 1);
}

__attribute__((used)) static void pnpbios_encode_fixed_mem32(struct pnp_dev *dev, unsigned char *p,
				       struct resource *res)
{
	unsigned long base;
	unsigned long len;

	if (pnp_resource_enabled(res)) {
		base = res->start;
		len = resource_size(res);
	} else {
		base = 0;
		len = 0;
	}

	p[4] = base & 0xff;
	p[5] = (base >> 8) & 0xff;
	p[6] = (base >> 16) & 0xff;
	p[7] = (base >> 24) & 0xff;
	p[8] = len & 0xff;
	p[9] = (len >> 8) & 0xff;
	p[10] = (len >> 16) & 0xff;
	p[11] = (len >> 24) & 0xff;

	pnp_dbg(&dev->dev, "  encode fixed_mem32 %#lx-%#lx\n", base,
		base + len - 1);
}

__attribute__((used)) static void pnpbios_encode_irq(struct pnp_dev *dev, unsigned char *p,
			       struct resource *res)
{
	unsigned long map;

	if (pnp_resource_enabled(res))
		map = 1 << res->start;
	else
		map = 0;

	p[1] = map & 0xff;
	p[2] = (map >> 8) & 0xff;

	pnp_dbg(&dev->dev, "  encode irq mask %#lx\n", map);
}

__attribute__((used)) static void pnpbios_encode_dma(struct pnp_dev *dev, unsigned char *p,
			       struct resource *res)
{
	unsigned long map;

	if (pnp_resource_enabled(res))
		map = 1 << res->start;
	else
		map = 0;

	p[1] = map & 0xff;

	pnp_dbg(&dev->dev, "  encode dma mask %#lx\n", map);
}

__attribute__((used)) static void pnpbios_encode_port(struct pnp_dev *dev, unsigned char *p,
				struct resource *res)
{
	unsigned long base;
	unsigned long len;

	if (pnp_resource_enabled(res)) {
		base = res->start;
		len = resource_size(res);
	} else {
		base = 0;
		len = 0;
	}

	p[2] = base & 0xff;
	p[3] = (base >> 8) & 0xff;
	p[4] = base & 0xff;
	p[5] = (base >> 8) & 0xff;
	p[7] = len & 0xff;

	pnp_dbg(&dev->dev, "  encode io %#lx-%#lx\n", base, base + len - 1);
}

__attribute__((used)) static void pnpbios_encode_fixed_port(struct pnp_dev *dev, unsigned char *p,
				      struct resource *res)
{
	unsigned long base = res->start;
	unsigned long len = resource_size(res);

	if (pnp_resource_enabled(res)) {
		base = res->start;
		len = resource_size(res);
	} else {
		base = 0;
		len = 0;
	}

	p[1] = base & 0xff;
	p[2] = (base >> 8) & 0xff;
	p[3] = len & 0xff;

	pnp_dbg(&dev->dev, "  encode fixed_io %#lx-%#lx\n", base,
		base + len - 1);
}

__attribute__((used)) static unsigned char *pnpbios_encode_allocated_resource_data(struct pnp_dev
								*dev,
							     unsigned char *p,
							     unsigned char *end)
{
	unsigned int len, tag;
	int port = 0, irq = 0, dma = 0, mem = 0;

	if (!p)
		return NULL;

	while ((char *)p < (char *)end) {

		/* determine the type of tag */
		if (p[0] & LARGE_TAG) {	/* large tag */
			len = (p[2] << 8) | p[1];
			tag = p[0];
		} else {	/* small tag */
			len = p[0] & 0x07;
			tag = ((p[0] >> 3) & 0x0f);
		}

		switch (tag) {

		case LARGE_TAG_MEM:
			if (len != 9)
				goto len_err;
			pnpbios_encode_mem(dev, p,
				pnp_get_resource(dev, IORESOURCE_MEM, mem));
			mem++;
			break;

		case LARGE_TAG_MEM32:
			if (len != 17)
				goto len_err;
			pnpbios_encode_mem32(dev, p,
				pnp_get_resource(dev, IORESOURCE_MEM, mem));
			mem++;
			break;

		case LARGE_TAG_FIXEDMEM32:
			if (len != 9)
				goto len_err;
			pnpbios_encode_fixed_mem32(dev, p,
				pnp_get_resource(dev, IORESOURCE_MEM, mem));
			mem++;
			break;

		case SMALL_TAG_IRQ:
			if (len < 2 || len > 3)
				goto len_err;
			pnpbios_encode_irq(dev, p,
				pnp_get_resource(dev, IORESOURCE_IRQ, irq));
			irq++;
			break;

		case SMALL_TAG_DMA:
			if (len != 2)
				goto len_err;
			pnpbios_encode_dma(dev, p,
				pnp_get_resource(dev, IORESOURCE_DMA, dma));
			dma++;
			break;

		case SMALL_TAG_PORT:
			if (len != 7)
				goto len_err;
			pnpbios_encode_port(dev, p,
				pnp_get_resource(dev, IORESOURCE_IO, port));
			port++;
			break;

		case SMALL_TAG_VENDOR:
			/* do nothing */
			break;

		case SMALL_TAG_FIXEDPORT:
			if (len != 3)
				goto len_err;
			pnpbios_encode_fixed_port(dev, p,
				pnp_get_resource(dev, IORESOURCE_IO, port));
			port++;
			break;

		case SMALL_TAG_END:
			p = p + 2;
			return (unsigned char *)p;
			break;

		default:	/* an unknown tag */
len_err:
			dev_err(&dev->dev, "unknown tag %#x length %d\n",
				tag, len);
			break;
		}

		/* continue to the next tag */
		if (p[0] & LARGE_TAG)
			p += len + 3;
		else
			p += len + 1;
	}

	dev_err(&dev->dev, "no end tag in resource structure\n");

	return NULL;
}

