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
typedef  scalar_t__ u32 ;
struct nvkm_enum {scalar_t__ value; scalar_t__ name; } ;
struct nvkm_bitfield {scalar_t__ mask; int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int snprintf (char*,int,char*,char*,int /*<<< orphan*/ ) ; 

const struct nvkm_enum *
nvkm_enum_find(const struct nvkm_enum *en, u32 value)
{
	while (en->name) {
		if (en->value == value)
			return en;
		en++;
	}

	return NULL;
}

void
nvkm_snprintbf(char *data, int size, const struct nvkm_bitfield *bf, u32 value)
{
	bool space = false;
	while (size >= 1 && bf->name) {
		if (value & bf->mask) {
			int this = snprintf(data, size, "%s%s",
					    space ? " " : "", bf->name);
			size -= this;
			data += this;
			space = true;
		}
		bf++;
	}
	data[0] = '\0';
}

