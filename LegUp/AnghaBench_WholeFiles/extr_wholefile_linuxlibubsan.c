#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  val_str ;
typedef  unsigned long u_max ;
typedef  unsigned long u64 ;
struct source_location {int line; int column; int /*<<< orphan*/  file_name; int /*<<< orphan*/  reported; } ;
struct vla_bound_data {struct type_descriptor* type; struct source_location location; } ;
struct unreachable_data {struct source_location location; } ;
struct type_mismatch_data_v1 {unsigned long log_alignment; size_t type_check_kind; TYPE_1__* type; struct source_location location; } ;
struct type_mismatch_data_common {size_t type_check_kind; unsigned long alignment; TYPE_1__* type; struct source_location* location; } ;
struct type_mismatch_data {unsigned long alignment; size_t type_check_kind; TYPE_1__* type; struct source_location location; } ;
struct type_descriptor {scalar_t__ type_kind; int type_info; void* type_name; } ;
struct shift_out_of_bounds_data {struct source_location location; struct type_descriptor* lhs_type; struct type_descriptor* rhs_type; } ;
struct overflow_data {struct type_descriptor* type; struct source_location location; } ;
struct out_of_bounds_data {TYPE_2__* array_type; struct type_descriptor* index_type; struct source_location location; } ;
struct invalid_value_data {struct type_descriptor* type; struct source_location location; } ;
typedef  unsigned int s_max ;
typedef  unsigned int s64 ;
typedef  int /*<<< orphan*/  rhs_val_str ;
typedef  int /*<<< orphan*/  rhs_str ;
typedef  int /*<<< orphan*/  old_val_str ;
typedef  int /*<<< orphan*/  lhs_val_str ;
typedef  int /*<<< orphan*/  lhs_str ;
typedef  int /*<<< orphan*/  index_str ;
typedef  int /*<<< orphan*/  bound_str ;
struct TYPE_6__ {scalar_t__ in_ubsan; } ;
struct TYPE_5__ {void* type_name; } ;
struct TYPE_4__ {void* type_name; } ;

/* Variables and functions */
 int COLUMN_MASK ; 
 int /*<<< orphan*/  IS_ALIGNED (unsigned long,unsigned long) ; 
 int LINE_MASK ; 
 int /*<<< orphan*/  REPORTED_BIT ; 
 int VALUE_LENGTH ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 TYPE_3__* current ; 
 int /*<<< orphan*/  dump_stack () ; 
 int /*<<< orphan*/  panic (char*) ; 
 int /*<<< orphan*/  pr_err (char*,...) ; 
 int /*<<< orphan*/  report_lock ; 
 int /*<<< orphan*/  scnprintf (char*,size_t,char*,unsigned long) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int test_and_set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 char** type_check_kinds ; 
 scalar_t__ type_kind_int ; 

__attribute__((used)) static bool was_reported(struct source_location *location)
{
	return test_and_set_bit(REPORTED_BIT, &location->reported);
}

__attribute__((used)) static void print_source_location(const char *prefix,
				struct source_location *loc)
{
	pr_err("%s %s:%d:%d\n", prefix, loc->file_name,
		loc->line & LINE_MASK, loc->column & COLUMN_MASK);
}

__attribute__((used)) static bool suppress_report(struct source_location *loc)
{
	return current->in_ubsan || was_reported(loc);
}

__attribute__((used)) static bool type_is_int(struct type_descriptor *type)
{
	return type->type_kind == type_kind_int;
}

__attribute__((used)) static bool type_is_signed(struct type_descriptor *type)
{
	WARN_ON(!type_is_int(type));
	return  type->type_info & 1;
}

__attribute__((used)) static unsigned type_bit_width(struct type_descriptor *type)
{
	return 1 << (type->type_info >> 1);
}

__attribute__((used)) static bool is_inline_int(struct type_descriptor *type)
{
	unsigned inline_bits = sizeof(unsigned long)*8;
	unsigned bits = type_bit_width(type);

	WARN_ON(!type_is_int(type));

	return bits <= inline_bits;
}

__attribute__((used)) static s_max get_signed_val(struct type_descriptor *type, unsigned long val)
{
	if (is_inline_int(type)) {
		unsigned extra_bits = sizeof(s_max)*8 - type_bit_width(type);
		return ((s_max)val) << extra_bits >> extra_bits;
	}

	if (type_bit_width(type) == 64)
		return *(s64 *)val;

	return *(s_max *)val;
}

__attribute__((used)) static bool val_is_negative(struct type_descriptor *type, unsigned long val)
{
	return type_is_signed(type) && get_signed_val(type, val) < 0;
}

__attribute__((used)) static u_max get_unsigned_val(struct type_descriptor *type, unsigned long val)
{
	if (is_inline_int(type))
		return val;

	if (type_bit_width(type) == 64)
		return *(u64 *)val;

	return *(u_max *)val;
}

__attribute__((used)) static void val_to_string(char *str, size_t size, struct type_descriptor *type,
	unsigned long value)
{
	if (type_is_int(type)) {
		if (type_bit_width(type) == 128) {
#if defined(CONFIG_ARCH_SUPPORTS_INT128) && defined(__SIZEOF_INT128__)
			u_max val = get_unsigned_val(type, value);

			scnprintf(str, size, "0x%08x%08x%08x%08x",
				(u32)(val >> 96),
				(u32)(val >> 64),
				(u32)(val >> 32),
				(u32)(val));
#else
			WARN_ON(1);
#endif
		} else if (type_is_signed(type)) {
			scnprintf(str, size, "%lld",
				(s64)get_signed_val(type, value));
		} else {
			scnprintf(str, size, "%llu",
				(u64)get_unsigned_val(type, value));
		}
	}
}

__attribute__((used)) static void ubsan_prologue(struct source_location *location,
			unsigned long *flags)
{
	current->in_ubsan++;
	spin_lock_irqsave(&report_lock, *flags);

	pr_err("========================================"
		"========================================\n");
	print_source_location("UBSAN: Undefined behaviour in", location);
}

__attribute__((used)) static void ubsan_epilogue(unsigned long *flags)
{
	dump_stack();
	pr_err("========================================"
		"========================================\n");
	spin_unlock_irqrestore(&report_lock, *flags);
	current->in_ubsan--;
}

__attribute__((used)) static void handle_overflow(struct overflow_data *data, unsigned long lhs,
			unsigned long rhs, char op)
{

	struct type_descriptor *type = data->type;
	unsigned long flags;
	char lhs_val_str[VALUE_LENGTH];
	char rhs_val_str[VALUE_LENGTH];

	if (suppress_report(&data->location))
		return;

	ubsan_prologue(&data->location, &flags);

	val_to_string(lhs_val_str, sizeof(lhs_val_str), type, lhs);
	val_to_string(rhs_val_str, sizeof(rhs_val_str), type, rhs);
	pr_err("%s integer overflow:\n",
		type_is_signed(type) ? "signed" : "unsigned");
	pr_err("%s %c %s cannot be represented in type %s\n",
		lhs_val_str,
		op,
		rhs_val_str,
		type->type_name);

	ubsan_epilogue(&flags);
}

void __ubsan_handle_add_overflow(struct overflow_data *data,
				unsigned long lhs,
				unsigned long rhs)
{

	handle_overflow(data, lhs, rhs, '+');
}

void __ubsan_handle_sub_overflow(struct overflow_data *data,
				unsigned long lhs,
				unsigned long rhs)
{
	handle_overflow(data, lhs, rhs, '-');
}

void __ubsan_handle_mul_overflow(struct overflow_data *data,
				unsigned long lhs,
				unsigned long rhs)
{
	handle_overflow(data, lhs, rhs, '*');
}

void __ubsan_handle_negate_overflow(struct overflow_data *data,
				unsigned long old_val)
{
	unsigned long flags;
	char old_val_str[VALUE_LENGTH];

	if (suppress_report(&data->location))
		return;

	ubsan_prologue(&data->location, &flags);

	val_to_string(old_val_str, sizeof(old_val_str), data->type, old_val);

	pr_err("negation of %s cannot be represented in type %s:\n",
		old_val_str, data->type->type_name);

	ubsan_epilogue(&flags);
}

void __ubsan_handle_divrem_overflow(struct overflow_data *data,
				unsigned long lhs,
				unsigned long rhs)
{
	unsigned long flags;
	char rhs_val_str[VALUE_LENGTH];

	if (suppress_report(&data->location))
		return;

	ubsan_prologue(&data->location, &flags);

	val_to_string(rhs_val_str, sizeof(rhs_val_str), data->type, rhs);

	if (type_is_signed(data->type) && get_signed_val(data->type, rhs) == -1)
		pr_err("division of %s by -1 cannot be represented in type %s\n",
			rhs_val_str, data->type->type_name);
	else
		pr_err("division by zero\n");

	ubsan_epilogue(&flags);
}

__attribute__((used)) static void handle_null_ptr_deref(struct type_mismatch_data_common *data)
{
	unsigned long flags;

	if (suppress_report(data->location))
		return;

	ubsan_prologue(data->location, &flags);

	pr_err("%s null pointer of type %s\n",
		type_check_kinds[data->type_check_kind],
		data->type->type_name);

	ubsan_epilogue(&flags);
}

__attribute__((used)) static void handle_misaligned_access(struct type_mismatch_data_common *data,
				unsigned long ptr)
{
	unsigned long flags;

	if (suppress_report(data->location))
		return;

	ubsan_prologue(data->location, &flags);

	pr_err("%s misaligned address %p for type %s\n",
		type_check_kinds[data->type_check_kind],
		(void *)ptr, data->type->type_name);
	pr_err("which requires %ld byte alignment\n", data->alignment);

	ubsan_epilogue(&flags);
}

__attribute__((used)) static void handle_object_size_mismatch(struct type_mismatch_data_common *data,
					unsigned long ptr)
{
	unsigned long flags;

	if (suppress_report(data->location))
		return;

	ubsan_prologue(data->location, &flags);
	pr_err("%s address %p with insufficient space\n",
		type_check_kinds[data->type_check_kind],
		(void *) ptr);
	pr_err("for an object of type %s\n", data->type->type_name);
	ubsan_epilogue(&flags);
}

__attribute__((used)) static void ubsan_type_mismatch_common(struct type_mismatch_data_common *data,
				unsigned long ptr)
{

	if (!ptr)
		handle_null_ptr_deref(data);
	else if (data->alignment && !IS_ALIGNED(ptr, data->alignment))
		handle_misaligned_access(data, ptr);
	else
		handle_object_size_mismatch(data, ptr);
}

void __ubsan_handle_type_mismatch(struct type_mismatch_data *data,
				unsigned long ptr)
{
	struct type_mismatch_data_common common_data = {
		.location = &data->location,
		.type = data->type,
		.alignment = data->alignment,
		.type_check_kind = data->type_check_kind
	};

	ubsan_type_mismatch_common(&common_data, ptr);
}

void __ubsan_handle_type_mismatch_v1(struct type_mismatch_data_v1 *data,
				unsigned long ptr)
{

	struct type_mismatch_data_common common_data = {
		.location = &data->location,
		.type = data->type,
		.alignment = 1UL << data->log_alignment,
		.type_check_kind = data->type_check_kind
	};

	ubsan_type_mismatch_common(&common_data, ptr);
}

void __ubsan_handle_vla_bound_not_positive(struct vla_bound_data *data,
					unsigned long bound)
{
	unsigned long flags;
	char bound_str[VALUE_LENGTH];

	if (suppress_report(&data->location))
		return;

	ubsan_prologue(&data->location, &flags);

	val_to_string(bound_str, sizeof(bound_str), data->type, bound);
	pr_err("variable length array bound value %s <= 0\n", bound_str);

	ubsan_epilogue(&flags);
}

void __ubsan_handle_out_of_bounds(struct out_of_bounds_data *data,
				unsigned long index)
{
	unsigned long flags;
	char index_str[VALUE_LENGTH];

	if (suppress_report(&data->location))
		return;

	ubsan_prologue(&data->location, &flags);

	val_to_string(index_str, sizeof(index_str), data->index_type, index);
	pr_err("index %s is out of range for type %s\n", index_str,
		data->array_type->type_name);
	ubsan_epilogue(&flags);
}

void __ubsan_handle_shift_out_of_bounds(struct shift_out_of_bounds_data *data,
					unsigned long lhs, unsigned long rhs)
{
	unsigned long flags;
	struct type_descriptor *rhs_type = data->rhs_type;
	struct type_descriptor *lhs_type = data->lhs_type;
	char rhs_str[VALUE_LENGTH];
	char lhs_str[VALUE_LENGTH];

	if (suppress_report(&data->location))
		return;

	ubsan_prologue(&data->location, &flags);

	val_to_string(rhs_str, sizeof(rhs_str), rhs_type, rhs);
	val_to_string(lhs_str, sizeof(lhs_str), lhs_type, lhs);

	if (val_is_negative(rhs_type, rhs))
		pr_err("shift exponent %s is negative\n", rhs_str);

	else if (get_unsigned_val(rhs_type, rhs) >=
		type_bit_width(lhs_type))
		pr_err("shift exponent %s is too large for %u-bit type %s\n",
			rhs_str,
			type_bit_width(lhs_type),
			lhs_type->type_name);
	else if (val_is_negative(lhs_type, lhs))
		pr_err("left shift of negative value %s\n",
			lhs_str);
	else
		pr_err("left shift of %s by %s places cannot be"
			" represented in type %s\n",
			lhs_str, rhs_str,
			lhs_type->type_name);

	ubsan_epilogue(&flags);
}

void __ubsan_handle_builtin_unreachable(struct unreachable_data *data)
{
	unsigned long flags;

	ubsan_prologue(&data->location, &flags);
	pr_err("calling __builtin_unreachable()\n");
	ubsan_epilogue(&flags);
	panic("can't return from __builtin_unreachable()");
}

void __ubsan_handle_load_invalid_value(struct invalid_value_data *data,
				unsigned long val)
{
	unsigned long flags;
	char val_str[VALUE_LENGTH];

	if (suppress_report(&data->location))
		return;

	ubsan_prologue(&data->location, &flags);

	val_to_string(val_str, sizeof(val_str), data->type, val);

	pr_err("load of value %s is not a valid value for type %s\n",
		val_str, data->type->type_name);

	ubsan_epilogue(&flags);
}

