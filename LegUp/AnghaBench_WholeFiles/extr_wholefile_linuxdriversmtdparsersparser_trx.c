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
typedef  size_t uint8_t ;
typedef  scalar_t__ uint32_t ;
typedef  size_t u64 ;
typedef  int /*<<< orphan*/  trx ;
struct trx_header {scalar_t__ magic; size_t* offset; } ;
struct mtd_partition {char* name; size_t offset; size_t size; } ;
struct mtd_part_parser_data {int dummy; } ;
struct mtd_info {size_t size; } ;
typedef  int /*<<< orphan*/  buf ;

/* Variables and functions */
 int ENOENT ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ TRX_MAGIC ; 
 int /*<<< orphan*/  TRX_PARSER_MAX_PARTS ; 
 scalar_t__ UBI_EC_MAGIC ; 
 struct mtd_partition* kcalloc (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct mtd_partition*) ; 
 int /*<<< orphan*/  mtd_is_bitflip (int) ; 
 int mtd_read (struct mtd_info*,size_t,int,size_t*,size_t*) ; 
 int /*<<< orphan*/  pr_err (char*,int,...) ; 

__attribute__((used)) static const char *parser_trx_data_part_name(struct mtd_info *master,
					     size_t offset)
{
	uint32_t buf;
	size_t bytes_read;
	int err;

	err  = mtd_read(master, offset, sizeof(buf), &bytes_read,
			(uint8_t *)&buf);
	if (err && !mtd_is_bitflip(err)) {
		pr_err("mtd_read error while parsing (offset: 0x%zX): %d\n",
			offset, err);
		goto out_default;
	}

	if (buf == UBI_EC_MAGIC)
		return "ubi";

out_default:
	return "rootfs";
}

__attribute__((used)) static int parser_trx_parse(struct mtd_info *mtd,
			    const struct mtd_partition **pparts,
			    struct mtd_part_parser_data *data)
{
	struct mtd_partition *parts;
	struct mtd_partition *part;
	struct trx_header trx;
	size_t bytes_read;
	uint8_t curr_part = 0, i = 0;
	int err;

	parts = kcalloc(TRX_PARSER_MAX_PARTS, sizeof(struct mtd_partition),
			GFP_KERNEL);
	if (!parts)
		return -ENOMEM;

	err = mtd_read(mtd, 0, sizeof(trx), &bytes_read, (uint8_t *)&trx);
	if (err) {
		pr_err("MTD reading error: %d\n", err);
		kfree(parts);
		return err;
	}

	if (trx.magic != TRX_MAGIC) {
		kfree(parts);
		return -ENOENT;
	}

	/* We have LZMA loader if there is address in offset[2] */
	if (trx.offset[2]) {
		part = &parts[curr_part++];
		part->name = "loader";
		part->offset = trx.offset[i];
		i++;
	}

	if (trx.offset[i]) {
		part = &parts[curr_part++];
		part->name = "linux";
		part->offset = trx.offset[i];
		i++;
	}

	if (trx.offset[i]) {
		part = &parts[curr_part++];
		part->name = parser_trx_data_part_name(mtd, trx.offset[i]);
		part->offset = trx.offset[i];
		i++;
	}

	/*
	 * Assume that every partition ends at the beginning of the one it is
	 * followed by.
	 */
	for (i = 0; i < curr_part; i++) {
		u64 next_part_offset = (i < curr_part - 1) ?
				       parts[i + 1].offset : mtd->size;

		parts[i].size = next_part_offset - parts[i].offset;
	}

	*pparts = parts;
	return i;
}

