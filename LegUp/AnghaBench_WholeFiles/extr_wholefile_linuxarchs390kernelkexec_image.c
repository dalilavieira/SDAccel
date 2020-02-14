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
struct s390_load_data {char* kernel_buf; int /*<<< orphan*/  member_0; int /*<<< orphan*/  memsz; } ;
struct kimage {scalar_t__ type; } ;
struct kexec_buf {char* buffer; int bufsz; int mem; int memsz; struct kimage* image; } ;
struct TYPE_2__ {int start; } ;

/* Variables and functions */
 void* ERR_PTR (int) ; 
 scalar_t__ KEXEC_TYPE_CRASH ; 
 int STARTUP_NORMAL_OFFSET ; 
 TYPE_1__ crashk_res ; 
 int kexec_add_buffer (struct kexec_buf*) ; 
 int kexec_file_add_initrd (struct kimage*,struct s390_load_data*,char*,unsigned long) ; 
 int kexec_file_add_purgatory (struct kimage*,struct s390_load_data*) ; 
 void* kexec_file_update_kernel (struct kimage*,struct s390_load_data*) ; 

__attribute__((used)) static int kexec_file_add_image_kernel(struct kimage *image,
				       struct s390_load_data *data,
				       char *kernel, unsigned long kernel_len)
{
	struct kexec_buf buf;
	int ret;

	buf.image = image;

	buf.buffer = kernel + STARTUP_NORMAL_OFFSET;
	buf.bufsz = kernel_len - STARTUP_NORMAL_OFFSET;

	buf.mem = STARTUP_NORMAL_OFFSET;
	if (image->type == KEXEC_TYPE_CRASH)
		buf.mem += crashk_res.start;
	buf.memsz = buf.bufsz;

	ret = kexec_add_buffer(&buf);

	data->kernel_buf = kernel;
	data->memsz += buf.memsz + STARTUP_NORMAL_OFFSET;

	return ret;
}

__attribute__((used)) static void *s390_image_load(struct kimage *image,
			     char *kernel, unsigned long kernel_len,
			     char *initrd, unsigned long initrd_len,
			     char *cmdline, unsigned long cmdline_len)
{
	struct s390_load_data data = {0};
	int ret;

	ret = kexec_file_add_image_kernel(image, &data, kernel, kernel_len);
	if (ret)
		return ERR_PTR(ret);

	if (initrd) {
		ret = kexec_file_add_initrd(image, &data, initrd, initrd_len);
		if (ret)
			return ERR_PTR(ret);
	}

	ret = kexec_file_add_purgatory(image, &data);
	if (ret)
		return ERR_PTR(ret);

	return kexec_file_update_kernel(image, &data);
}

__attribute__((used)) static int s390_image_probe(const char *buf, unsigned long len)
{
	/* Can't reliably tell if an image is valid.  Therefore give the
	 * user whatever he wants.
	 */
	return 0;
}

