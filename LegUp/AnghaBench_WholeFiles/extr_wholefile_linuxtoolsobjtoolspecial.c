#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct symbol {char* name; unsigned long offset; } ;
struct special_entry {int size; short feature; scalar_t__ sec; scalar_t__ new; scalar_t__ group; scalar_t__ orig; scalar_t__ new_len; scalar_t__ orig_len; int /*<<< orphan*/  jump_or_nop; } ;
struct special_alt {unsigned char orig_len; unsigned char new_len; int skip_orig; unsigned int new_off; int /*<<< orphan*/  list; int /*<<< orphan*/  new_sec; scalar_t__ orig_off; int /*<<< orphan*/  orig_sec; scalar_t__ group; int /*<<< orphan*/  jump_or_nop; } ;
struct section {char* name; int len; TYPE_1__* data; } ;
struct rela {scalar_t__ addend; TYPE_2__* sym; } ;
struct list_head {int dummy; } ;
struct elf {int dummy; } ;
struct TYPE_4__ {scalar_t__ type; int /*<<< orphan*/  sec; int /*<<< orphan*/  name; } ;
struct TYPE_3__ {scalar_t__ d_buf; } ;

/* Variables and functions */
 int /*<<< orphan*/  INIT_LIST_HEAD (struct list_head*) ; 
 scalar_t__ STT_SECTION ; 
 int /*<<< orphan*/  WARN (char*,...) ; 
 int /*<<< orphan*/  WARN_FUNC (char*,struct section*,scalar_t__,...) ; 
 unsigned short X86_FEATURE_POPCNT ; 
 struct special_entry* entries ; 
 struct symbol* find_containing_func (struct section*,unsigned long) ; 
 struct rela* find_rela_by_dest (struct section*,scalar_t__) ; 
 struct section* find_section_by_name (struct elf*,scalar_t__) ; 
 int /*<<< orphan*/  list_add_tail (int /*<<< orphan*/ *,struct list_head*) ; 
 void* malloc (int) ; 
 int /*<<< orphan*/  memset (struct special_alt*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  sprintf (char*,char*,char*,unsigned long) ; 
 int strlen (char*) ; 

__attribute__((used)) static inline char *offstr(struct section *sec, unsigned long offset)
{
	struct symbol *func;
	char *name, *str;
	unsigned long name_off;

	func = find_containing_func(sec, offset);
	if (func) {
		name = func->name;
		name_off = offset - func->offset;
	} else {
		name = sec->name;
		name_off = offset;
	}

	str = malloc(strlen(name) + 20);

	if (func)
		sprintf(str, "%s()+0x%lx", name, name_off);
	else
		sprintf(str, "%s+0x%lx", name, name_off);

	return str;
}

__attribute__((used)) static int get_alt_entry(struct elf *elf, struct special_entry *entry,
			 struct section *sec, int idx,
			 struct special_alt *alt)
{
	struct rela *orig_rela, *new_rela;
	unsigned long offset;

	offset = idx * entry->size;

	alt->group = entry->group;
	alt->jump_or_nop = entry->jump_or_nop;

	if (alt->group) {
		alt->orig_len = *(unsigned char *)(sec->data->d_buf + offset +
						   entry->orig_len);
		alt->new_len = *(unsigned char *)(sec->data->d_buf + offset +
						  entry->new_len);
	}

	if (entry->feature) {
		unsigned short feature;

		feature = *(unsigned short *)(sec->data->d_buf + offset +
					      entry->feature);

		/*
		 * It has been requested that we don't validate the !POPCNT
		 * feature path which is a "very very small percentage of
		 * machines".
		 */
		if (feature == X86_FEATURE_POPCNT)
			alt->skip_orig = true;
	}

	orig_rela = find_rela_by_dest(sec, offset + entry->orig);
	if (!orig_rela) {
		WARN_FUNC("can't find orig rela", sec, offset + entry->orig);
		return -1;
	}
	if (orig_rela->sym->type != STT_SECTION) {
		WARN_FUNC("don't know how to handle non-section rela symbol %s",
			   sec, offset + entry->orig, orig_rela->sym->name);
		return -1;
	}

	alt->orig_sec = orig_rela->sym->sec;
	alt->orig_off = orig_rela->addend;

	if (!entry->group || alt->new_len) {
		new_rela = find_rela_by_dest(sec, offset + entry->new);
		if (!new_rela) {
			WARN_FUNC("can't find new rela",
				  sec, offset + entry->new);
			return -1;
		}

		alt->new_sec = new_rela->sym->sec;
		alt->new_off = (unsigned int)new_rela->addend;

		/* _ASM_EXTABLE_EX hack */
		if (alt->new_off >= 0x7ffffff0)
			alt->new_off -= 0x7ffffff0;
	}

	return 0;
}

int special_get_alts(struct elf *elf, struct list_head *alts)
{
	struct special_entry *entry;
	struct section *sec;
	unsigned int nr_entries;
	struct special_alt *alt;
	int idx, ret;

	INIT_LIST_HEAD(alts);

	for (entry = entries; entry->sec; entry++) {
		sec = find_section_by_name(elf, entry->sec);
		if (!sec)
			continue;

		if (sec->len % entry->size != 0) {
			WARN("%s size not a multiple of %d",
			     sec->name, entry->size);
			return -1;
		}

		nr_entries = sec->len / entry->size;

		for (idx = 0; idx < nr_entries; idx++) {
			alt = malloc(sizeof(*alt));
			if (!alt) {
				WARN("malloc failed");
				return -1;
			}
			memset(alt, 0, sizeof(*alt));

			ret = get_alt_entry(elf, entry, sec, idx, alt);
			if (ret)
				return ret;

			list_add_tail(&alt->list, alts);
		}
	}

	return 0;
}

