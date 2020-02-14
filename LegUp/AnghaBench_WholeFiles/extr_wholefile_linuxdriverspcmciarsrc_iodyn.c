#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct resource {int start; unsigned int flags; int end; } ;
struct pcmcia_socket {TYPE_1__* io; int /*<<< orphan*/  dev; } ;
struct pcmcia_align_data {int mask; int offset; } ;
typedef  int resource_size_t ;
struct TYPE_2__ {unsigned int InUse; struct resource* res; } ;

/* Variables and functions */
 int EBUSY ; 
 int EINVAL ; 
 unsigned int IORESOURCE_BITS ; 
 int /*<<< orphan*/  IORESOURCE_IO ; 
 int MAX_IO_WIN ; 
 scalar_t__ adjust_resource (struct resource*,unsigned int,scalar_t__) ; 
 int allocate_resource (int /*<<< orphan*/ *,struct resource*,int,unsigned long,unsigned long,int,int (*) (void*,struct resource const*,int,int),struct pcmcia_align_data*) ; 
 int /*<<< orphan*/  dev_name (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ioport_resource ; 
 int /*<<< orphan*/  kfree (struct resource*) ; 
 struct resource* pcmcia_make_resource (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ resource_size (struct resource*) ; 

__attribute__((used)) static resource_size_t pcmcia_align(void *align_data,
				const struct resource *res,
				resource_size_t size, resource_size_t align)
{
	struct pcmcia_align_data *data = align_data;
	resource_size_t start;

	start = (res->start & ~data->mask) + data->offset;
	if (start < res->start)
		start += data->mask + 1;

#ifdef CONFIG_X86
	if (res->flags & IORESOURCE_IO) {
		if (start & 0x300)
			start = (start + 0x3ff) & ~0x3ff;
	}
#endif

#ifdef CONFIG_M68K
	if (res->flags & IORESOURCE_IO) {
		if ((res->start + size - 1) >= 1024)
			start = res->end;
	}
#endif

	return start;
}

__attribute__((used)) static struct resource *__iodyn_find_io_region(struct pcmcia_socket *s,
					unsigned long base, int num,
					unsigned long align)
{
	struct resource *res = pcmcia_make_resource(0, num, IORESOURCE_IO,
						dev_name(&s->dev));
	struct pcmcia_align_data data;
	unsigned long min = base;
	int ret;

	data.mask = align - 1;
	data.offset = base & data.mask;

#ifdef CONFIG_PCI
	if (s->cb_dev) {
		ret = pci_bus_alloc_resource(s->cb_dev->bus, res, num, 1,
					     min, 0, pcmcia_align, &data);
	} else
#endif
		ret = allocate_resource(&ioport_resource, res, num, min, ~0UL,
					1, pcmcia_align, &data);

	if (ret != 0) {
		kfree(res);
		res = NULL;
	}
	return res;
}

__attribute__((used)) static int iodyn_find_io(struct pcmcia_socket *s, unsigned int attr,
			unsigned int *base, unsigned int num,
			unsigned int align, struct resource **parent)
{
	int i, ret = 0;

	/* Check for an already-allocated window that must conflict with
	 * what was asked for.  It is a hack because it does not catch all
	 * potential conflicts, just the most obvious ones.
	 */
	for (i = 0; i < MAX_IO_WIN; i++) {
		if (!s->io[i].res)
			continue;

		if (!*base)
			continue;

		if ((s->io[i].res->start & (align-1)) == *base)
			return -EBUSY;
	}

	for (i = 0; i < MAX_IO_WIN; i++) {
		struct resource *res = s->io[i].res;
		unsigned int try;

		if (res && (res->flags & IORESOURCE_BITS) !=
			(attr & IORESOURCE_BITS))
			continue;

		if (!res) {
			if (align == 0)
				align = 0x10000;

			res = s->io[i].res = __iodyn_find_io_region(s, *base,
								num, align);
			if (!res)
				return -EINVAL;

			*base = res->start;
			s->io[i].res->flags =
				((res->flags & ~IORESOURCE_BITS) |
					(attr & IORESOURCE_BITS));
			s->io[i].InUse = num;
			*parent = res;
			return 0;
		}

		/* Try to extend top of window */
		try = res->end + 1;
		if ((*base == 0) || (*base == try)) {
			if (adjust_resource(s->io[i].res, res->start,
					    resource_size(res) + num))
				continue;
			*base = try;
			s->io[i].InUse += num;
			*parent = res;
			return 0;
		}

		/* Try to extend bottom of window */
		try = res->start - num;
		if ((*base == 0) || (*base == try)) {
			if (adjust_resource(s->io[i].res,
					    res->start - num,
					    resource_size(res) + num))
				continue;
			*base = try;
			s->io[i].InUse += num;
			*parent = res;
			return 0;
		}
	}

	return -EINVAL;
}

