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
struct seq_file {scalar_t__ private; } ;
struct fit_type_map_t {int type; char const* name; } ;
typedef  int /*<<< orphan*/  banner ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 unsigned char FIT_ENTRY_PAL_A ; 
 unsigned char FIT_ENTRY_PAL_B ; 
 scalar_t__ FIT_ENTRY_SAL_A ; 
 unsigned char FIT_ENTRY_UNUSED ; 
 int /*<<< orphan*/  FIT_MAJOR (unsigned long) ; 
 int /*<<< orphan*/  FIT_MINOR (unsigned long) ; 
 scalar_t__ FIT_TYPE (unsigned long) ; 
 int PAGE_SIZE ; 
 struct fit_type_map_t* fit_entry_types ; 
 int ia64_sn_get_fit_compt (unsigned long,int,unsigned long*,char*,int) ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,...) ; 

__attribute__((used)) static const char *fit_type_name(unsigned char type)
{
	struct fit_type_map_t const *mapp;

	for (mapp = fit_entry_types; mapp->type != 0xff; mapp++)
		if (type == mapp->type)
			return mapp->name;

	if ((type > FIT_ENTRY_PAL_A) && (type < FIT_ENTRY_UNUSED))
		return "OEM type";
	if ((type > FIT_ENTRY_PAL_B) && (type < FIT_ENTRY_PAL_A))
		return "Reserved";

	return "Unknown type";
}

__attribute__((used)) static int
get_fit_entry(unsigned long nasid, int index, unsigned long *fentry,
	      char *banner, int banlen)
{
	return ia64_sn_get_fit_compt(nasid, index, fentry, banner, banlen);
}

__attribute__((used)) static void dump_fit_entry(struct seq_file *m, unsigned long *fentry)
{
	unsigned type;

	type = FIT_TYPE(fentry[1]);
	seq_printf(m, "%02x %-25s %x.%02x %016lx %u\n",
		   type,
		   fit_type_name(type),
		   FIT_MAJOR(fentry[1]), FIT_MINOR(fentry[1]),
		   fentry[0],
		   /* mult by sixteen to get size in bytes */
		   (unsigned)(fentry[1] & 0xffffff) * 16);
}

__attribute__((used)) static int proc_fit_show(struct seq_file *m, void *v)
{
	unsigned long nasid = (unsigned long)m->private;
	unsigned long fentry[2];
	int index;

	for (index=0;;index++) {
		BUG_ON(index * 60 > PAGE_SIZE);
		if (get_fit_entry(nasid, index, fentry, NULL, 0))
			break;
		dump_fit_entry(m, fentry);
	}
	return 0;
}

__attribute__((used)) static int proc_version_show(struct seq_file *m, void *v)
{
	unsigned long nasid = (unsigned long)m->private;
	unsigned long fentry[2];
	char banner[128];
	int index;

	for (index = 0; ; index++) {
		if (get_fit_entry(nasid, index, fentry, banner,
				  sizeof(banner)))
			return 0;
		if (FIT_TYPE(fentry[1]) == FIT_ENTRY_SAL_A)
			break;
	}

	seq_printf(m, "%x.%02x\n", FIT_MAJOR(fentry[1]), FIT_MINOR(fentry[1]));

	if (banner[0])
		seq_printf(m, "%s\n", banner);
	return 0;
}

