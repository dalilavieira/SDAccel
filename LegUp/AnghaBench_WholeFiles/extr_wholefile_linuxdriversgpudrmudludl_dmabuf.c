#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct vm_area_struct {int dummy; } ;
struct sg_table {size_t size; unsigned int orig_nents; struct sg_table* import_attach; TYPE_1__* dmabuf; struct drm_device* dev; struct udl_drm_dmabuf_attachment* priv; struct scatterlist* sgl; int /*<<< orphan*/  nents; } ;
struct udl_gem_object {struct sg_table base; int /*<<< orphan*/  flags; int /*<<< orphan*/ * pages; struct sg_table* sg; } ;
struct udl_drm_dmabuf_attachment {scalar_t__ dir; int is_mapped; struct sg_table sgt; } ;
struct udl_device {int /*<<< orphan*/  gem_lock; } ;
struct scatterlist {int /*<<< orphan*/  offset; int /*<<< orphan*/  length; } ;
struct page {int dummy; } ;
struct drm_gem_object {size_t size; unsigned int orig_nents; struct drm_gem_object* import_attach; TYPE_1__* dmabuf; struct drm_device* dev; struct udl_drm_dmabuf_attachment* priv; struct scatterlist* sgl; int /*<<< orphan*/  nents; } ;
struct drm_device {int /*<<< orphan*/  dev; struct udl_device* dev_private; } ;
struct dma_buf_attachment {size_t size; unsigned int orig_nents; struct dma_buf_attachment* import_attach; TYPE_1__* dmabuf; struct drm_device* dev; struct udl_drm_dmabuf_attachment* priv; struct scatterlist* sgl; int /*<<< orphan*/  nents; } ;
struct dma_buf {size_t size; } ;
typedef  enum dma_data_direction { ____Placeholder_dma_data_direction } dma_data_direction ;
struct TYPE_6__ {size_t size; int flags; struct sg_table* priv; int /*<<< orphan*/ * ops; } ;
struct TYPE_5__ {int /*<<< orphan*/  size; int /*<<< orphan*/  priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  DEFINE_DMA_BUF_EXPORT_INFO (TYPE_2__) ; 
 int /*<<< orphan*/  DMA_BIDIRECTIONAL ; 
 scalar_t__ DMA_NONE ; 
 int /*<<< orphan*/  DRM_DEBUG_PRIME (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  DRM_ERROR (char*,...) ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 struct sg_table* ERR_CAST (struct sg_table*) ; 
 struct sg_table* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct sg_table*) ; 
 size_t PAGE_SIZE ; 
 int PTR_ERR (struct sg_table*) ; 
 int /*<<< orphan*/  UDL_BO_WC ; 
 int /*<<< orphan*/  dev_name (struct drm_device*) ; 
 struct sg_table* dma_buf_attach (struct dma_buf*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_buf_detach (struct dma_buf*,struct sg_table*) ; 
 struct sg_table* dma_buf_map_attachment (struct sg_table*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_buf_put (struct dma_buf*) ; 
 int /*<<< orphan*/  dma_buf_unmap_attachment (struct sg_table*,struct sg_table*,int /*<<< orphan*/ ) ; 
 int dma_map_sg (struct drm_device*,struct scatterlist*,unsigned int,int) ; 
 int /*<<< orphan*/  dma_unmap_sg (struct drm_device*,struct scatterlist*,int /*<<< orphan*/ ,scalar_t__) ; 
 struct dma_buf* drm_gem_dmabuf_export (struct drm_device*,TYPE_2__*) ; 
 struct sg_table* drm_prime_pages_to_sg (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  drm_prime_sg_to_page_addr_arrays (struct sg_table*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 TYPE_2__ exp_info ; 
 int /*<<< orphan*/  get_device (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  get_dma_buf (struct dma_buf*) ; 
 int /*<<< orphan*/  kfree (struct udl_drm_dmabuf_attachment*) ; 
 int /*<<< orphan*/ * kvmalloc_array (int,int,int /*<<< orphan*/ ) ; 
 struct udl_drm_dmabuf_attachment* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  put_device (int /*<<< orphan*/ ) ; 
 int sg_alloc_table (struct sg_table*,unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sg_free_table (struct sg_table*) ; 
 struct scatterlist* sg_next (struct scatterlist*) ; 
 int /*<<< orphan*/  sg_page (struct scatterlist*) ; 
 int /*<<< orphan*/  sg_set_page (struct scatterlist*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct udl_gem_object* to_udl_bo (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  udl_dmabuf_ops ; 
 struct udl_gem_object* udl_gem_alloc_object (struct drm_device*,int) ; 
 int udl_gem_get_pages (struct udl_gem_object*) ; 

__attribute__((used)) static int udl_attach_dma_buf(struct dma_buf *dmabuf,
			      struct dma_buf_attachment *attach)
{
	struct udl_drm_dmabuf_attachment *udl_attach;

	DRM_DEBUG_PRIME("[DEV:%s] size:%zd\n", dev_name(attach->dev),
			attach->dmabuf->size);

	udl_attach = kzalloc(sizeof(*udl_attach), GFP_KERNEL);
	if (!udl_attach)
		return -ENOMEM;

	udl_attach->dir = DMA_NONE;
	attach->priv = udl_attach;

	return 0;
}

__attribute__((used)) static void udl_detach_dma_buf(struct dma_buf *dmabuf,
			       struct dma_buf_attachment *attach)
{
	struct udl_drm_dmabuf_attachment *udl_attach = attach->priv;
	struct sg_table *sgt;

	if (!udl_attach)
		return;

	DRM_DEBUG_PRIME("[DEV:%s] size:%zd\n", dev_name(attach->dev),
			attach->dmabuf->size);

	sgt = &udl_attach->sgt;

	if (udl_attach->dir != DMA_NONE)
		dma_unmap_sg(attach->dev, sgt->sgl, sgt->nents,
				udl_attach->dir);

	sg_free_table(sgt);
	kfree(udl_attach);
	attach->priv = NULL;
}

__attribute__((used)) static struct sg_table *udl_map_dma_buf(struct dma_buf_attachment *attach,
					enum dma_data_direction dir)
{
	struct udl_drm_dmabuf_attachment *udl_attach = attach->priv;
	struct udl_gem_object *obj = to_udl_bo(attach->dmabuf->priv);
	struct drm_device *dev = obj->base.dev;
	struct udl_device *udl = dev->dev_private;
	struct scatterlist *rd, *wr;
	struct sg_table *sgt = NULL;
	unsigned int i;
	int page_count;
	int nents, ret;

	DRM_DEBUG_PRIME("[DEV:%s] size:%zd dir=%d\n", dev_name(attach->dev),
			attach->dmabuf->size, dir);

	/* just return current sgt if already requested. */
	if (udl_attach->dir == dir && udl_attach->is_mapped)
		return &udl_attach->sgt;

	if (!obj->pages) {
		ret = udl_gem_get_pages(obj);
		if (ret) {
			DRM_ERROR("failed to map pages.\n");
			return ERR_PTR(ret);
		}
	}

	page_count = obj->base.size / PAGE_SIZE;
	obj->sg = drm_prime_pages_to_sg(obj->pages, page_count);
	if (IS_ERR(obj->sg)) {
		DRM_ERROR("failed to allocate sgt.\n");
		return ERR_CAST(obj->sg);
	}

	sgt = &udl_attach->sgt;

	ret = sg_alloc_table(sgt, obj->sg->orig_nents, GFP_KERNEL);
	if (ret) {
		DRM_ERROR("failed to alloc sgt.\n");
		return ERR_PTR(-ENOMEM);
	}

	mutex_lock(&udl->gem_lock);

	rd = obj->sg->sgl;
	wr = sgt->sgl;
	for (i = 0; i < sgt->orig_nents; ++i) {
		sg_set_page(wr, sg_page(rd), rd->length, rd->offset);
		rd = sg_next(rd);
		wr = sg_next(wr);
	}

	if (dir != DMA_NONE) {
		nents = dma_map_sg(attach->dev, sgt->sgl, sgt->orig_nents, dir);
		if (!nents) {
			DRM_ERROR("failed to map sgl with iommu.\n");
			sg_free_table(sgt);
			sgt = ERR_PTR(-EIO);
			goto err_unlock;
		}
	}

	udl_attach->is_mapped = true;
	udl_attach->dir = dir;
	attach->priv = udl_attach;

err_unlock:
	mutex_unlock(&udl->gem_lock);
	return sgt;
}

__attribute__((used)) static void udl_unmap_dma_buf(struct dma_buf_attachment *attach,
			      struct sg_table *sgt,
			      enum dma_data_direction dir)
{
	/* Nothing to do. */
	DRM_DEBUG_PRIME("[DEV:%s] size:%zd dir:%d\n", dev_name(attach->dev),
			attach->dmabuf->size, dir);
}

__attribute__((used)) static void *udl_dmabuf_kmap(struct dma_buf *dma_buf, unsigned long page_num)
{
	/* TODO */

	return NULL;
}

__attribute__((used)) static void udl_dmabuf_kunmap(struct dma_buf *dma_buf,
			      unsigned long page_num, void *addr)
{
	/* TODO */
}

__attribute__((used)) static int udl_dmabuf_mmap(struct dma_buf *dma_buf,
			   struct vm_area_struct *vma)
{
	/* TODO */

	return -EINVAL;
}

struct dma_buf *udl_gem_prime_export(struct drm_device *dev,
				     struct drm_gem_object *obj, int flags)
{
	DEFINE_DMA_BUF_EXPORT_INFO(exp_info);

	exp_info.ops = &udl_dmabuf_ops;
	exp_info.size = obj->size;
	exp_info.flags = flags;
	exp_info.priv = obj;

	return drm_gem_dmabuf_export(dev, &exp_info);
}

__attribute__((used)) static int udl_prime_create(struct drm_device *dev,
			    size_t size,
			    struct sg_table *sg,
			    struct udl_gem_object **obj_p)
{
	struct udl_gem_object *obj;
	int npages;

	npages = size / PAGE_SIZE;

	*obj_p = NULL;
	obj = udl_gem_alloc_object(dev, npages * PAGE_SIZE);
	if (!obj)
		return -ENOMEM;

	obj->sg = sg;
	obj->pages = kvmalloc_array(npages, sizeof(struct page *), GFP_KERNEL);
	if (obj->pages == NULL) {
		DRM_ERROR("obj pages is NULL %d\n", npages);
		return -ENOMEM;
	}

	drm_prime_sg_to_page_addr_arrays(sg, obj->pages, NULL, npages);

	*obj_p = obj;
	return 0;
}

struct drm_gem_object *udl_gem_prime_import(struct drm_device *dev,
				struct dma_buf *dma_buf)
{
	struct dma_buf_attachment *attach;
	struct sg_table *sg;
	struct udl_gem_object *uobj;
	int ret;

	/* need to attach */
	get_device(dev->dev);
	attach = dma_buf_attach(dma_buf, dev->dev);
	if (IS_ERR(attach)) {
		put_device(dev->dev);
		return ERR_CAST(attach);
	}

	get_dma_buf(dma_buf);

	sg = dma_buf_map_attachment(attach, DMA_BIDIRECTIONAL);
	if (IS_ERR(sg)) {
		ret = PTR_ERR(sg);
		goto fail_detach;
	}

	ret = udl_prime_create(dev, dma_buf->size, sg, &uobj);
	if (ret)
		goto fail_unmap;

	uobj->base.import_attach = attach;
	uobj->flags = UDL_BO_WC;

	return &uobj->base;

fail_unmap:
	dma_buf_unmap_attachment(attach, sg, DMA_BIDIRECTIONAL);
fail_detach:
	dma_buf_detach(dma_buf, attach);
	dma_buf_put(dma_buf);
	put_device(dev->dev);
	return ERR_PTR(ret);
}

