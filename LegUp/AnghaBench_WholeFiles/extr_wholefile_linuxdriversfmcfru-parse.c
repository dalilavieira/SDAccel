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
typedef  scalar_t__ uint8_t ;
struct fru_type_length {int dummy; } ;
struct fru_common_header {int dummy; } ;
struct fru_board_info_area {int area_len; struct fru_type_length* tl; } ;

/* Variables and functions */
 char* fru_alloc (scalar_t__) ; 
 struct fru_board_info_area* fru_get_board_area (struct fru_common_header*) ; 
 scalar_t__ fru_is_eof (struct fru_type_length*) ; 
 struct fru_type_length* fru_next_tl (struct fru_type_length*) ; 
 char* fru_strcpy (char*,struct fru_type_length*) ; 
 scalar_t__ fru_strlen (struct fru_type_length*) ; 

__attribute__((used)) static struct fru_type_length *
__fru_get_board_tl(struct fru_common_header *header, int nr)
{
	struct fru_board_info_area *bia;
	struct fru_type_length *tl;

	bia = fru_get_board_area(header);
	tl = bia->tl;
	while (nr > 0 && !fru_is_eof(tl)) {
		tl = fru_next_tl(tl);
		nr--;
	}
	if (fru_is_eof(tl))
		return NULL;
	return tl;
}

__attribute__((used)) static char *__fru_alloc_get_tl(struct fru_common_header *header, int nr)
{
	struct fru_type_length *tl;
	char *res;

	tl = __fru_get_board_tl(header, nr);
	if (!tl)
		return NULL;

	res = fru_alloc(fru_strlen(tl) + 1);
	if (!res)
		return NULL;
	return fru_strcpy(res, tl);
}

int fru_header_cksum_ok(struct fru_common_header *header)
{
	uint8_t *ptr = (void *)header;
	int i, sum;

	for (i = sum = 0; i < sizeof(*header); i++)
		sum += ptr[i];
	return (sum & 0xff) == 0;
}

int fru_bia_cksum_ok(struct fru_board_info_area *bia)
{
	uint8_t *ptr = (void *)bia;
	int i, sum;

	for (i = sum = 0; i < 8 * bia->area_len; i++)
		sum += ptr[i];
	return (sum & 0xff) == 0;
}

char *fru_get_board_manufacturer(struct fru_common_header *header)
{
	return __fru_alloc_get_tl(header, 0);
}

char *fru_get_product_name(struct fru_common_header *header)
{
	return __fru_alloc_get_tl(header, 1);
}

char *fru_get_serial_number(struct fru_common_header *header)
{
	return __fru_alloc_get_tl(header, 2);
}

char *fru_get_part_number(struct fru_common_header *header)
{
	return __fru_alloc_get_tl(header, 3);
}

