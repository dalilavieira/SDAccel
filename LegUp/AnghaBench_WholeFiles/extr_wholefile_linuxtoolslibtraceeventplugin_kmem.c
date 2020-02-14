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
struct trace_seq {int dummy; } ;
struct tep_record {void* data; } ;
struct tep_handle {int flags; scalar_t__ host_bigendian; scalar_t__ file_bigendian; int cpus; int long_size; int page_size; int latency_format; } ;
struct format_field {int dummy; } ;
struct event_format {int /*<<< orphan*/  pevent; } ;

/* Variables and functions */
 int /*<<< orphan*/  memcpy (unsigned int*,unsigned char*,int) ; 
 struct format_field* tep_find_field (struct event_format*,char*) ; 
 char* tep_find_function (int /*<<< orphan*/ ,unsigned long long) ; 
 unsigned long long tep_find_function_address (int /*<<< orphan*/ ,unsigned long long) ; 
 scalar_t__ tep_read_number_field (struct format_field*,void*,unsigned long long*) ; 
 int /*<<< orphan*/  tep_register_event_handler (struct tep_handle*,int,char*,char*,int (*) (struct trace_seq*,struct tep_record*,struct event_format*,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tep_unregister_event_handler (struct tep_handle*,int,char*,char*,int (*) (struct trace_seq*,struct tep_record*,struct event_format*,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  trace_seq_printf (struct trace_seq*,char*,char const*,int) ; 

__attribute__((used)) static inline void tep_set_flag(struct tep_handle *pevent, int flag)
{
	pevent->flags |= flag;
}

__attribute__((used)) static inline unsigned short
__data2host2(struct tep_handle *pevent, unsigned short data)
{
	unsigned short swap;

	if (pevent->host_bigendian == pevent->file_bigendian)
		return data;

	swap = ((data & 0xffULL) << 8) |
		((data & (0xffULL << 8)) >> 8);

	return swap;
}

__attribute__((used)) static inline unsigned int
__data2host4(struct tep_handle *pevent, unsigned int data)
{
	unsigned int swap;

	if (pevent->host_bigendian == pevent->file_bigendian)
		return data;

	swap = ((data & 0xffULL) << 24) |
		((data & (0xffULL << 8)) << 8) |
		((data & (0xffULL << 16)) >> 8) |
		((data & (0xffULL << 24)) >> 24);

	return swap;
}

__attribute__((used)) static inline unsigned long long
__data2host8(struct tep_handle *pevent, unsigned long long data)
{
	unsigned long long swap;

	if (pevent->host_bigendian == pevent->file_bigendian)
		return data;

	swap = ((data & 0xffULL) << 56) |
		((data & (0xffULL << 8)) << 40) |
		((data & (0xffULL << 16)) << 24) |
		((data & (0xffULL << 24)) << 8) |
		((data & (0xffULL << 32)) >> 8) |
		((data & (0xffULL << 40)) >> 24) |
		((data & (0xffULL << 48)) >> 40) |
		((data & (0xffULL << 56)) >> 56);

	return swap;
}

__attribute__((used)) static inline int tep_host_bigendian(void)
{
	unsigned char str[] = { 0x1, 0x2, 0x3, 0x4 };
	unsigned int val;

	memcpy(&val, str, 4);
	return val == 0x01020304;
}

__attribute__((used)) static inline int tep_get_cpus(struct tep_handle *pevent)
{
	return pevent->cpus;
}

__attribute__((used)) static inline void tep_set_cpus(struct tep_handle *pevent, int cpus)
{
	pevent->cpus = cpus;
}

__attribute__((used)) static inline int tep_get_long_size(struct tep_handle *pevent)
{
	return pevent->long_size;
}

__attribute__((used)) static inline void tep_set_long_size(struct tep_handle *pevent, int long_size)
{
	pevent->long_size = long_size;
}

__attribute__((used)) static inline int tep_get_page_size(struct tep_handle *pevent)
{
	return pevent->page_size;
}

__attribute__((used)) static inline void tep_set_page_size(struct tep_handle *pevent, int _page_size)
{
	pevent->page_size = _page_size;
}

__attribute__((used)) static inline int tep_is_file_bigendian(struct tep_handle *pevent)
{
	return pevent->file_bigendian;
}

__attribute__((used)) static inline void tep_set_file_bigendian(struct tep_handle *pevent, int endian)
{
	pevent->file_bigendian = endian;
}

__attribute__((used)) static inline int tep_is_host_bigendian(struct tep_handle *pevent)
{
	return pevent->host_bigendian;
}

__attribute__((used)) static inline void tep_set_host_bigendian(struct tep_handle *pevent, int endian)
{
	pevent->host_bigendian = endian;
}

__attribute__((used)) static inline int tep_is_latency_format(struct tep_handle *pevent)
{
	return pevent->latency_format;
}

__attribute__((used)) static inline void tep_set_latency_format(struct tep_handle *pevent, int lat)
{
	pevent->latency_format = lat;
}

__attribute__((used)) static int call_site_handler(struct trace_seq *s, struct tep_record *record,
			     struct event_format *event, void *context)
{
	struct format_field *field;
	unsigned long long val, addr;
	void *data = record->data;
	const char *func;

	field = tep_find_field(event, "call_site");
	if (!field)
		return 1;

	if (tep_read_number_field(field, data, &val))
		return 1;

	func = tep_find_function(event->pevent, val);
	if (!func)
		return 1;

	addr = tep_find_function_address(event->pevent, val);

	trace_seq_printf(s, "(%s+0x%x) ", func, (int)(val - addr));
	return 1;
}

int TEP_PLUGIN_LOADER(struct tep_handle *pevent)
{
	tep_register_event_handler(pevent, -1, "kmem", "kfree",
				   call_site_handler, NULL);

	tep_register_event_handler(pevent, -1, "kmem", "kmalloc",
				   call_site_handler, NULL);

	tep_register_event_handler(pevent, -1, "kmem", "kmalloc_node",
				   call_site_handler, NULL);

	tep_register_event_handler(pevent, -1, "kmem", "kmem_cache_alloc",
				   call_site_handler, NULL);

	tep_register_event_handler(pevent, -1, "kmem",
				   "kmem_cache_alloc_node",
				   call_site_handler, NULL);

	tep_register_event_handler(pevent, -1, "kmem", "kmem_cache_free",
				   call_site_handler, NULL);
	return 0;
}

void TEP_PLUGIN_UNLOADER(struct tep_handle *pevent)
{
	tep_unregister_event_handler(pevent, -1, "kmem", "kfree",
				     call_site_handler, NULL);

	tep_unregister_event_handler(pevent, -1, "kmem", "kmalloc",
				     call_site_handler, NULL);

	tep_unregister_event_handler(pevent, -1, "kmem", "kmalloc_node",
				     call_site_handler, NULL);

	tep_unregister_event_handler(pevent, -1, "kmem", "kmem_cache_alloc",
				     call_site_handler, NULL);

	tep_unregister_event_handler(pevent, -1, "kmem",
				     "kmem_cache_alloc_node",
				     call_site_handler, NULL);

	tep_unregister_event_handler(pevent, -1, "kmem", "kmem_cache_free",
				     call_site_handler, NULL);
}

