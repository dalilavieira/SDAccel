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
struct trace_seq {int len; char* buffer; } ;
struct tep_record {scalar_t__ data; } ;
struct tep_handle {int flags; scalar_t__ host_bigendian; scalar_t__ file_bigendian; int cpus; int long_size; int page_size; int latency_format; } ;
struct format_field {TYPE_1__* event; int /*<<< orphan*/  size; scalar_t__ offset; } ;
struct event_format {int dummy; } ;
typedef  int /*<<< orphan*/  states ;
struct TYPE_2__ {int /*<<< orphan*/  pevent; } ;

/* Variables and functions */
 int /*<<< orphan*/  memcpy (unsigned int*,unsigned char*,int) ; 
 struct format_field* tep_find_any_field (struct event_format*,char*) ; 
 scalar_t__ tep_get_field_val (struct trace_seq*,struct event_format*,char*,struct tep_record*,unsigned long long*,int) ; 
 int /*<<< orphan*/  tep_register_comm (int /*<<< orphan*/ ,char const*,int) ; 
 int /*<<< orphan*/  tep_register_event_handler (struct tep_handle*,int,char*,char*,int (*) (struct trace_seq*,struct tep_record*,struct event_format*,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tep_unregister_event_handler (struct tep_handle*,int,char*,char*,int (*) (struct trace_seq*,struct tep_record*,struct event_format*,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  trace_seq_printf (struct trace_seq*,char*,int,...) ; 
 int trace_seq_putc (struct trace_seq*,char const) ; 
 int /*<<< orphan*/  trace_seq_puts (struct trace_seq*,char*) ; 
 int /*<<< orphan*/  trace_seq_terminate (struct trace_seq*) ; 

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

__attribute__((used)) static void write_state(struct trace_seq *s, int val)
{
	const char states[] = "SDTtZXxW";
	int found = 0;
	int i;

	for (i = 0; i < (sizeof(states) - 1); i++) {
		if (!(val & (1 << i)))
			continue;

		if (found)
			trace_seq_putc(s, '|');

		found = 1;
		trace_seq_putc(s, states[i]);
	}

	if (!found)
		trace_seq_putc(s, 'R');
}

__attribute__((used)) static void write_and_save_comm(struct format_field *field,
				struct tep_record *record,
				struct trace_seq *s, int pid)
{
	const char *comm;
	int len;

	comm = (char *)(record->data + field->offset);
	len = s->len;
	trace_seq_printf(s, "%.*s",
			 field->size, comm);

	/* make sure the comm has a \0 at the end. */
	trace_seq_terminate(s);
	comm = &s->buffer[len];

	/* Help out the comm to ids. This will handle dups */
	tep_register_comm(field->event->pevent, comm, pid);
}

__attribute__((used)) static int sched_wakeup_handler(struct trace_seq *s,
				struct tep_record *record,
				struct event_format *event, void *context)
{
	struct format_field *field;
	unsigned long long val;

	if (tep_get_field_val(s, event, "pid", record, &val, 1))
		return trace_seq_putc(s, '!');

	field = tep_find_any_field(event, "comm");
	if (field) {
		write_and_save_comm(field, record, s, val);
		trace_seq_putc(s, ':');
	}
	trace_seq_printf(s, "%lld", val);

	if (tep_get_field_val(s, event, "prio", record, &val, 0) == 0)
		trace_seq_printf(s, " [%lld]", val);

	if (tep_get_field_val(s, event, "success", record, &val, 1) == 0)
		trace_seq_printf(s, " success=%lld", val);

	if (tep_get_field_val(s, event, "target_cpu", record, &val, 0) == 0)
		trace_seq_printf(s, " CPU:%03llu", val);

	return 0;
}

__attribute__((used)) static int sched_switch_handler(struct trace_seq *s,
				struct tep_record *record,
				struct event_format *event, void *context)
{
	struct format_field *field;
	unsigned long long val;

	if (tep_get_field_val(s, event, "prev_pid", record, &val, 1))
		return trace_seq_putc(s, '!');

	field = tep_find_any_field(event, "prev_comm");
	if (field) {
		write_and_save_comm(field, record, s, val);
		trace_seq_putc(s, ':');
	}
	trace_seq_printf(s, "%lld ", val);

	if (tep_get_field_val(s, event, "prev_prio", record, &val, 0) == 0)
		trace_seq_printf(s, "[%d] ", (int) val);

	if (tep_get_field_val(s,  event, "prev_state", record, &val, 0) == 0)
		write_state(s, val);

	trace_seq_puts(s, " ==> ");

	if (tep_get_field_val(s, event, "next_pid", record, &val, 1))
		return trace_seq_putc(s, '!');

	field = tep_find_any_field(event, "next_comm");
	if (field) {
		write_and_save_comm(field, record, s, val);
		trace_seq_putc(s, ':');
	}
	trace_seq_printf(s, "%lld", val);

	if (tep_get_field_val(s, event, "next_prio", record, &val, 0) == 0)
		trace_seq_printf(s, " [%d]", (int) val);

	return 0;
}

int TEP_PLUGIN_LOADER(struct tep_handle *pevent)
{
	tep_register_event_handler(pevent, -1, "sched", "sched_switch",
				   sched_switch_handler, NULL);

	tep_register_event_handler(pevent, -1, "sched", "sched_wakeup",
				   sched_wakeup_handler, NULL);

	tep_register_event_handler(pevent, -1, "sched", "sched_wakeup_new",
				   sched_wakeup_handler, NULL);
	return 0;
}

void TEP_PLUGIN_UNLOADER(struct tep_handle *pevent)
{
	tep_unregister_event_handler(pevent, -1, "sched", "sched_switch",
				     sched_switch_handler, NULL);

	tep_unregister_event_handler(pevent, -1, "sched", "sched_wakeup",
				     sched_wakeup_handler, NULL);

	tep_unregister_event_handler(pevent, -1, "sched", "sched_wakeup_new",
				     sched_wakeup_handler, NULL);
}

