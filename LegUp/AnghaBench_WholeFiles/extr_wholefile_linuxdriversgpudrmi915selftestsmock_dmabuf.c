#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct vm_area_struct {int dummy; } ;
struct sg_table {int npages; int /*<<< orphan*/ * pages; int /*<<< orphan*/  nents; struct scatterlist* sgl; struct sg_table* priv; } ;
struct scatterlist {int dummy; } ;
struct page {int dummy; } ;
struct mock_dmabuf {int npages; int /*<<< orphan*/ * pages; int /*<<< orphan*/  nents; struct scatterlist* sgl; struct mock_dmabuf* priv; } ;
struct dma_buf_attachment {int /*<<< orphan*/  dev; struct sg_table* dmabuf; } ;
struct dma_buf {int npages; int /*<<< orphan*/ * pages; int /*<<< orphan*/  nents; struct scatterlist* sgl; struct dma_buf* priv; } ;
typedef  enum dma_data_direction { ____Placeholder_dma_data_direction } dma_data_direction ;
struct TYPE_4__ {int size; struct sg_table* priv; int /*<<< orphan*/  flags; int /*<<< orphan*/ * ops; } ;

/* Variables and functions */
 int /*<<< orphan*/  DEFINE_DMA_BUF_EXPORT_INFO (TYPE_1__) ; 
 int ENODEV ; 
 int ENOMEM ; 
 struct sg_table* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct sg_table*) ; 
 int /*<<< orphan*/  O_CLOEXEC ; 
 int /*<<< orphan*/  PAGE_KERNEL ; 
 int PAGE_SIZE ; 
 int /*<<< orphan*/  alloc_page (int /*<<< orphan*/ ) ; 
 struct sg_table* dma_buf_export (TYPE_1__*) ; 
 int /*<<< orphan*/  dma_map_sg (int /*<<< orphan*/ ,struct scatterlist*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  dma_unmap_sg (int /*<<< orphan*/ ,struct scatterlist*,int /*<<< orphan*/ ,int) ; 
 TYPE_1__ exp_info ; 
 int /*<<< orphan*/  kfree (struct sg_table*) ; 
 struct sg_table* kmalloc (int,int /*<<< orphan*/ ) ; 
 void* kmap (int /*<<< orphan*/ ) ; 
 void kunmap (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mock_dmabuf_ops ; 
 int /*<<< orphan*/  put_page (int /*<<< orphan*/ ) ; 
 int sg_alloc_table (struct sg_table*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sg_free_table (struct sg_table*) ; 
 struct scatterlist* sg_next (struct scatterlist*) ; 
 int /*<<< orphan*/  sg_set_page (struct scatterlist*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 void* vm_map_ram (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vm_unmap_ram (void*,int) ; 

__attribute__((used)) static struct mock_dmabuf *to_mock(struct dma_buf *buf)
{
	return buf->priv;
}

__attribute__((used)) static struct sg_table *mock_map_dma_buf(struct dma_buf_attachment *attachment,
					 enum dma_data_direction dir)
{
	struct mock_dmabuf *mock = to_mock(attachment->dmabuf);
	struct sg_table *st;
	struct scatterlist *sg;
	int i, err;

	st = kmalloc(sizeof(*st), GFP_KERNEL);
	if (!st)
		return ERR_PTR(-ENOMEM);

	err = sg_alloc_table(st, mock->npages, GFP_KERNEL);
	if (err)
		goto err_free;

	sg = st->sgl;
	for (i = 0; i < mock->npages; i++) {
		sg_set_page(sg, mock->pages[i], PAGE_SIZE, 0);
		sg = sg_next(sg);
	}

	if (!dma_map_sg(attachment->dev, st->sgl, st->nents, dir)) {
		err = -ENOMEM;
		goto err_st;
	}

	return st;

err_st:
	sg_free_table(st);
err_free:
	kfree(st);
	return ERR_PTR(err);
}

__attribute__((used)) static void mock_unmap_dma_buf(struct dma_buf_attachment *attachment,
			       struct sg_table *st,
			       enum dma_data_direction dir)
{
	dma_unmap_sg(attachment->dev, st->sgl, st->nents, dir);
	sg_free_table(st);
	kfree(st);
}

__attribute__((used)) static void mock_dmabuf_release(struct dma_buf *dma_buf)
{
	struct mock_dmabuf *mock = to_mock(dma_buf);
	int i;

	for (i = 0; i < mock->npages; i++)
		put_page(mock->pages[i]);

	kfree(mock);
}

__attribute__((used)) static void *mock_dmabuf_vmap(struct dma_buf *dma_buf)
{
	struct mock_dmabuf *mock = to_mock(dma_buf);

	return vm_map_ram(mock->pages, mock->npages, 0, PAGE_KERNEL);
}

__attribute__((used)) static void mock_dmabuf_vunmap(struct dma_buf *dma_buf, void *vaddr)
{
	struct mock_dmabuf *mock = to_mock(dma_buf);

	vm_unmap_ram(vaddr, mock->npages);
}

__attribute__((used)) static void *mock_dmabuf_kmap(struct dma_buf *dma_buf, unsigned long page_num)
{
	struct mock_dmabuf *mock = to_mock(dma_buf);

	return kmap(mock->pages[page_num]);
}

__attribute__((used)) static void mock_dmabuf_kunmap(struct dma_buf *dma_buf, unsigned long page_num, void *addr)
{
	struct mock_dmabuf *mock = to_mock(dma_buf);

	return kunmap(mock->pages[page_num]);
}

__attribute__((used)) static int mock_dmabuf_mmap(struct dma_buf *dma_buf, struct vm_area_struct *vma)
{
	return -ENODEV;
}

__attribute__((used)) static struct dma_buf *mock_dmabuf(int npages)
{
	struct mock_dmabuf *mock;
	DEFINE_DMA_BUF_EXPORT_INFO(exp_info);
	struct dma_buf *dmabuf;
	int i;

	mock = kmalloc(sizeof(*mock) + npages * sizeof(struct page *),
		       GFP_KERNEL);
	if (!mock)
		return ERR_PTR(-ENOMEM);

	mock->npages = npages;
	for (i = 0; i < npages; i++) {
		mock->pages[i] = alloc_page(GFP_KERNEL);
		if (!mock->pages[i])
			goto err;
	}

	exp_info.ops = &mock_dmabuf_ops;
	exp_info.size = npages * PAGE_SIZE;
	exp_info.flags = O_CLOEXEC;
	exp_info.priv = mock;

	dmabuf = dma_buf_export(&exp_info);
	if (IS_ERR(dmabuf))
		goto err;

	return dmabuf;

err:
	while (i--)
		put_page(mock->pages[i]);
	kfree(mock);
	return ERR_PTR(-ENOMEM);
}

