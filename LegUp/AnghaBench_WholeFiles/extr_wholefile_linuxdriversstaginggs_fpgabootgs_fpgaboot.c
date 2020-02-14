#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  char u8 ;
typedef  int u16 ;
struct fpgaimage {char* filename; char* part; char* date; char* time; int lendata; char* fpgadata; int /*<<< orphan*/  dmethod; TYPE_1__* fw_entry; } ;
typedef  enum wbus { ____Placeholder_wbus } wbus ;
typedef  enum fmt_image { ____Placeholder_fmt_image } fmt_image ;
struct TYPE_7__ {int /*<<< orphan*/  dev; } ;
struct TYPE_6__ {scalar_t__ data; } ;

/* Variables and functions */
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int MAX_STR ; 
 int MAX_WAIT_DONE ; 
 int PTR_ERR_OR_ZERO (TYPE_3__*) ; 
 int /*<<< orphan*/  bits_magic ; 
 int bus_2byte ; 
#define  f_bit 128 
 char* file ; 
 TYPE_3__* firmware_pdev ; 
 int get_unaligned_be16 (char*) ; 
 int get_unaligned_be32 (char*) ; 
 int /*<<< orphan*/  kfree (struct fpgaimage*) ; 
 struct fpgaimage* kmalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  m_systemmap ; 
 int memcmp (char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  memcpy (char*,char*,int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 TYPE_3__* platform_device_register_simple (char*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_err (char*,...) ; 
 int /*<<< orphan*/  pr_info (char*,...) ; 
 int /*<<< orphan*/  release_firmware (TYPE_1__*) ; 
 int request_firmware (TYPE_1__**,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xl_csi_b (int /*<<< orphan*/ ) ; 
 scalar_t__ xl_get_done_b () ; 
 int /*<<< orphan*/  xl_get_init_b () ; 
 int /*<<< orphan*/  xl_program_b (int) ; 
 int /*<<< orphan*/  xl_rdwr_b (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xl_shift_bytes_out (int,char*) ; 
 int /*<<< orphan*/  xl_shift_cclk (int) ; 
 int /*<<< orphan*/  xl_supported_prog_bus_width (int) ; 

__attribute__((used)) static void read_bitstream(u8 *bitdata, u8 *buf, int *offset, int rdsize)
{
	memcpy(buf, bitdata + *offset, rdsize);
	*offset += rdsize;
}

__attribute__((used)) static int readinfo_bitstream(u8 *bitdata, u8 *buf, int size, int *offset)
{
	u8 tbuf[2];
	u16 len;

	/* read section char */
	read_bitstream(bitdata, tbuf, offset, 1);

	/* read length */
	read_bitstream(bitdata, tbuf, offset, 2);

	len = get_unaligned_be16(tbuf);
	if (len >= size) {
		pr_err("error: readinfo buffer too small\n");
		return -EINVAL;
	}

	read_bitstream(bitdata, buf, offset, len);
	buf[len] = '\0';

	return 0;
}

__attribute__((used)) static int readlength_bitstream(u8 *bitdata, int *lendata, int *offset)
{
	u8 tbuf[4];

	/* read section char */
	read_bitstream(bitdata, tbuf, offset, 1);

	/* make sure it is section 'e' */
	if (tbuf[0] != 'e') {
		pr_err("error: length section is not 'e', but %c\n", tbuf[0]);
		return -EINVAL;
	}

	/* read 4bytes length */
	read_bitstream(bitdata, tbuf, offset, 4);

	*lendata = get_unaligned_be32(tbuf);

	return 0;
}

__attribute__((used)) static int readmagic_bitstream(u8 *bitdata, int *offset)
{
	u8 buf[13];
	int r;

	read_bitstream(bitdata, buf, offset, 13);
	r = memcmp(buf, bits_magic, 13);
	if (r) {
		pr_err("error: corrupted header\n");
		return -EINVAL;
	}
	pr_info("bitstream file magic number Ok\n");

	*offset = 13;	/* magic length */

	return 0;
}

__attribute__((used)) static enum fmt_image get_imageformat(void)
{
	return f_bit;
}

__attribute__((used)) static void gs_print_header(struct fpgaimage *fimage)
{
	pr_info("file: %s\n", fimage->filename);
	pr_info("part: %s\n", fimage->part);
	pr_info("date: %s\n", fimage->date);
	pr_info("time: %s\n", fimage->time);
	pr_info("lendata: %d\n", fimage->lendata);
}

__attribute__((used)) static int gs_read_bitstream(struct fpgaimage *fimage)
{
	u8 *bitdata;
	int offset;
	int err;

	offset = 0;
	bitdata = (u8 *)fimage->fw_entry->data;

	err = readmagic_bitstream(bitdata, &offset);
	if (err)
		return err;

	err = readinfo_bitstream(bitdata, fimage->filename, MAX_STR, &offset);
	if (err)
		return err;
	err = readinfo_bitstream(bitdata, fimage->part, MAX_STR, &offset);
	if (err)
		return err;
	err = readinfo_bitstream(bitdata, fimage->date, MAX_STR, &offset);
	if (err)
		return err;
	err = readinfo_bitstream(bitdata, fimage->time, MAX_STR, &offset);
	if (err)
		return err;

	err = readlength_bitstream(bitdata, &fimage->lendata, &offset);
	if (err)
		return err;

	fimage->fpgadata = bitdata + offset;

	return 0;
}

__attribute__((used)) static int gs_read_image(struct fpgaimage *fimage)
{
	int img_fmt;
	int err;

	img_fmt = get_imageformat();

	switch (img_fmt) {
	case f_bit:
		pr_info("image is bitstream format\n");
		err = gs_read_bitstream(fimage);
		if (err)
			return err;
		break;
	default:
		pr_err("unsupported fpga image format\n");
		return -EINVAL;
	}

	gs_print_header(fimage);

	return 0;
}

__attribute__((used)) static int gs_load_image(struct fpgaimage *fimage, char *fw_file)
{
	int err;

	pr_info("load fpgaimage %s\n", fw_file);

	err = request_firmware(&fimage->fw_entry, fw_file, &firmware_pdev->dev);
	if (err != 0) {
		pr_err("firmware %s is missing, cannot continue.\n", fw_file);
		return err;
	}

	return 0;
}

__attribute__((used)) static int gs_download_image(struct fpgaimage *fimage, enum wbus bus_bytes)
{
	u8 *bitdata;
	int size, i, cnt;

	cnt = 0;
	bitdata = (u8 *)fimage->fpgadata;
	size = fimage->lendata;

#ifdef DEBUG_FPGA
	print_hex_dump_bytes("bitfile sample: ", DUMP_PREFIX_OFFSET,
			     bitdata, 0x100);
#endif /* DEBUG_FPGA */
	if (!xl_supported_prog_bus_width(bus_bytes)) {
		pr_err("unsupported program bus width %d\n",
		       bus_bytes);
		return -EINVAL;
	}

	/* Bring csi_b, rdwr_b Low and program_b High */
	xl_program_b(1);
	xl_rdwr_b(0);
	xl_csi_b(0);

	/* Configuration reset */
	xl_program_b(0);
	msleep(20);
	xl_program_b(1);

	/* Wait for Device Initialization */
	while (xl_get_init_b() == 0)
		;

	pr_info("device init done\n");

	for (i = 0; i < size; i += bus_bytes)
		xl_shift_bytes_out(bus_bytes, bitdata + i);

	pr_info("program done\n");

	/* Check INIT_B */
	if (xl_get_init_b() == 0) {
		pr_err("init_b 0\n");
		return -EIO;
	}

	while (xl_get_done_b() == 0) {
		if (cnt++ > MAX_WAIT_DONE) {
			pr_err("init_B %d\n", xl_get_init_b());
			break;
		}
	}

	if (cnt > MAX_WAIT_DONE) {
		pr_err("fpga download fail\n");
		return -EIO;
	}

	pr_info("download fpgaimage\n");

	/* Compensate for Special Startup Conditions */
	xl_shift_cclk(8);

	return 0;
}

__attribute__((used)) static int gs_release_image(struct fpgaimage *fimage)
{
	release_firmware(fimage->fw_entry);
	pr_info("release fpgaimage\n");

	return 0;
}

__attribute__((used)) static int gs_set_download_method(struct fpgaimage *fimage)
{
	pr_info("set program method\n");

	fimage->dmethod = m_systemmap;

	pr_info("systemmap program method\n");

	return 0;
}

__attribute__((used)) static int init_driver(void)
{
	firmware_pdev = platform_device_register_simple("fpgaboot", -1,
							NULL, 0);
	return PTR_ERR_OR_ZERO(firmware_pdev);
}

__attribute__((used)) static int gs_fpgaboot(void)
{
	int err;
	struct fpgaimage	*fimage;

	fimage = kmalloc(sizeof(*fimage), GFP_KERNEL);
	if (!fimage)
		return -ENOMEM;

	err = gs_load_image(fimage, file);
	if (err) {
		pr_err("gs_load_image error\n");
		goto err_out1;
	}

	err = gs_read_image(fimage);
	if (err) {
		pr_err("gs_read_image error\n");
		goto err_out2;
	}

	err = gs_set_download_method(fimage);
	if (err) {
		pr_err("gs_set_download_method error\n");
		goto err_out2;
	}

	err = gs_download_image(fimage, bus_2byte);
	if (err) {
		pr_err("gs_download_image error\n");
		goto err_out2;
	}

	err = gs_release_image(fimage);
	if (err) {
		pr_err("gs_release_image error\n");
		goto err_out1;
	}

	kfree(fimage);
	return 0;

err_out2:
	err = gs_release_image(fimage);
	if (err)
		pr_err("gs_release_image error\n");
err_out1:
	kfree(fimage);

	return err;
}

