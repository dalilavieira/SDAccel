#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u_char ;
struct TYPE_7__ {int* default_val; } ;
struct TYPE_6__ {int value; int low; int high; int default_val; int multiplier; char* synth_fmt; int* out_str; scalar_t__ offset; } ;
struct TYPE_8__ {TYPE_2__ s; TYPE_1__ n; } ;
struct var_t {int var_id; TYPE_3__ u; } ;
struct st_var_header {size_t var_id; int var_type; char* name; int* p_val; struct var_t* data; } ;
struct punc_var_t {int var_id; } ;
typedef  enum var_id_t { ____Placeholder_var_id_t } var_id_t ;
struct TYPE_10__ {short mask; int* value; } ;
struct TYPE_9__ {int (* synth_adjust ) (struct st_var_header*) ;} ;

/* Variables and functions */
 int ALPHA ; 
 int A_CAP ; 
 int A_PUNC ; 
 int /*<<< orphan*/  BUG_ON (int) ; 
 int B_CAPSYM ; 
 int B_CTL ; 
 short B_NUM ; 
 int B_SYM ; 
 int E2BIG ; 
 int EINVAL ; 
 int ENODATA ; 
 int ERANGE ; 
 int ERESTART ; 
#define  E_DEC 135 
#define  E_DEFAULT 134 
#define  E_INC 133 
#define  E_NEW_DEFAULT 132 
#define  E_SET 131 
 scalar_t__ FIRST_SYNTH_VAR ; 
 int MAXVARLEN ; 
 int MAXVARS ; 
 int NUM ; 
 scalar_t__ PITCH ; 
 short PUNC ; 
 scalar_t__ PUNC_LEVEL ; 
 int SPACE ; 
#define  VAR_NUM 130 
#define  VAR_STRING 129 
#define  VAR_TIME 128 
 int WDLM ; 
 int msecs_to_jiffies (int) ; 
 struct punc_var_t* punc_vars ; 
 int simple_strtoul (int /*<<< orphan*/ ,char**,int) ; 
 int /*<<< orphan*/  skip_spaces (char*) ; 
 short* spk_chartab ; 
 char* spk_pitch_buff ; 
 TYPE_5__* spk_punc_info ; 
 int /*<<< orphan*/  spk_punc_mask ; 
 int /*<<< orphan*/ * spk_punc_masks ; 
 int spk_set_num_var (int,struct st_var_header*,int) ; 
 int spk_set_string_var (char const*,struct st_var_header*,int) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 scalar_t__ strcmp (char const*,char*) ; 
 int /*<<< orphan*/  strcpy (char*,char const*) ; 
 int stub1 (struct st_var_header*) ; 
 TYPE_4__* synth ; 
 int /*<<< orphan*/  synth_printf (char*,char*) ; 
 char tolower (char) ; 
 struct st_var_header* var_headers ; 
 struct st_var_header** var_ptrs ; 

int spk_chartab_get_value(char *keyword)
{
	int value = 0;

	if (!strcmp(keyword, "ALPHA"))
		value = ALPHA;
	else if (!strcmp(keyword, "B_CTL"))
		value = B_CTL;
	else if (!strcmp(keyword, "WDLM"))
		value = WDLM;
	else if (!strcmp(keyword, "A_PUNC"))
		value = A_PUNC;
	else if (!strcmp(keyword, "PUNC"))
		value = PUNC;
	else if (!strcmp(keyword, "NUM"))
		value = NUM;
	else if (!strcmp(keyword, "A_CAP"))
		value = A_CAP;
	else if (!strcmp(keyword, "B_CAPSYM"))
		value = B_CAPSYM;
	else if (!strcmp(keyword, "B_SYM"))
		value = B_SYM;
	return value;
}

void speakup_register_var(struct var_t *var)
{
	static char nothing[2] = "\0";
	int i;
	struct st_var_header *p_header;

	BUG_ON(!var || var->var_id < 0 || var->var_id >= MAXVARS);
	if (!var_ptrs[0]) {
		for (i = 0; i < MAXVARS; i++) {
			p_header = &var_headers[i];
			var_ptrs[p_header->var_id] = p_header;
			p_header->data = NULL;
		}
	}
	p_header = var_ptrs[var->var_id];
	if (p_header->data)
		return;
	p_header->data = var;
	switch (p_header->var_type) {
	case VAR_STRING:
		spk_set_string_var(nothing, p_header, 0);
		break;
	case VAR_NUM:
	case VAR_TIME:
		spk_set_num_var(0, p_header, E_DEFAULT);
		break;
	default:
		break;
	}
}

void speakup_unregister_var(enum var_id_t var_id)
{
	struct st_var_header *p_header;

	BUG_ON(var_id < 0 || var_id >= MAXVARS);
	p_header = var_ptrs[var_id];
	p_header->data = NULL;
}

struct st_var_header *spk_get_var_header(enum var_id_t var_id)
{
	struct st_var_header *p_header;

	if (var_id < 0 || var_id >= MAXVARS)
		return NULL;
	p_header = var_ptrs[var_id];
	if (!p_header->data)
		return NULL;
	return p_header;
}

struct st_var_header *spk_var_header_by_name(const char *name)
{
	int i;

	if (!name)
		return NULL;

	for (i = 0; i < MAXVARS; i++) {
		if (strcmp(name, var_ptrs[i]->name) == 0)
			return var_ptrs[i];
	}
	return NULL;
}

struct var_t *spk_get_var(enum var_id_t var_id)
{
	BUG_ON(var_id < 0 || var_id >= MAXVARS);
	BUG_ON(!var_ptrs[var_id]);
	return var_ptrs[var_id]->data;
}

struct punc_var_t *spk_get_punc_var(enum var_id_t var_id)
{
	struct punc_var_t *rv = NULL;
	struct punc_var_t *where;

	where = punc_vars;
	while ((where->var_id != -1) && (!rv)) {
		if (where->var_id == var_id)
			rv = where;
		else
			where++;
	}
	return rv;
}

int spk_set_num_var(int input, struct st_var_header *var, int how)
{
	int val;
	int *p_val = var->p_val;
	char buf[32];
	char *cp;
	struct var_t *var_data = var->data;

	if (!var_data)
		return -ENODATA;

	val = var_data->u.n.value;
	switch (how) {
	case E_NEW_DEFAULT:
		if (input < var_data->u.n.low || input > var_data->u.n.high)
			return -ERANGE;
		var_data->u.n.default_val = input;
		return 0;
	case E_DEFAULT:
		val = var_data->u.n.default_val;
		break;
	case E_SET:
		val = input;
		break;
	case E_INC:
		val += input;
		break;
	case E_DEC:
		val -= input;
		break;
	}

	if (val < var_data->u.n.low || val > var_data->u.n.high)
		return -ERANGE;

	var_data->u.n.value = val;
	if (var->var_type == VAR_TIME && p_val) {
		*p_val = msecs_to_jiffies(val);
		return 0;
	}
	if (p_val)
		*p_val = val;
	if (var->var_id == PUNC_LEVEL) {
		spk_punc_mask = spk_punc_masks[val];
		return 0;
	}
	if (var_data->u.n.multiplier != 0)
		val *= var_data->u.n.multiplier;
	val += var_data->u.n.offset;
	if (var->var_id < FIRST_SYNTH_VAR || !synth)
		return 0;
	if (synth->synth_adjust)
		return synth->synth_adjust(var);

	if (!var_data->u.n.synth_fmt)
		return 0;
	if (var->var_id == PITCH)
		cp = spk_pitch_buff;
	else
		cp = buf;
	if (!var_data->u.n.out_str)
		sprintf(cp, var_data->u.n.synth_fmt, (int)val);
	else
		sprintf(cp, var_data->u.n.synth_fmt, var_data->u.n.out_str[val]);
	synth_printf("%s", cp);
	return 0;
}

int spk_set_string_var(const char *page, struct st_var_header *var, int len)
{
	struct var_t *var_data = var->data;

	if (!var_data)
		return -ENODATA;
	if (len > MAXVARLEN)
		return -E2BIG;
	if (!len) {
		if (!var_data->u.s.default_val)
			return 0;
		if (!var->p_val)
			var->p_val = var_data->u.s.default_val;
		if (var->p_val != var_data->u.s.default_val)
			strcpy((char *)var->p_val, var_data->u.s.default_val);
		return -ERESTART;
	} else if (var->p_val) {
		strcpy((char *)var->p_val, page);
	} else {
		return -E2BIG;
	}
	return 0;
}

int spk_set_mask_bits(const char *input, const int which, const int how)
{
	u_char *cp;
	short mask = spk_punc_info[which].mask;

	if (how & 1) {
		for (cp = (u_char *)spk_punc_info[3].value; *cp; cp++)
			spk_chartab[*cp] &= ~mask;
	}
	cp = (u_char *)input;
	if (!cp) {
		cp = spk_punc_info[which].value;
	} else {
		for (; *cp; cp++) {
			if (*cp < SPACE)
				break;
			if (mask < PUNC) {
				if (!(spk_chartab[*cp] & PUNC))
					break;
			} else if (spk_chartab[*cp] & B_NUM) {
				break;
			}
		}
		if (*cp)
			return -EINVAL;
		cp = (u_char *)input;
	}
	if (how & 2) {
		for (; *cp; cp++)
			if (*cp > SPACE)
				spk_chartab[*cp] |= mask;
	} else {
		for (; *cp; cp++)
			if (*cp > SPACE)
				spk_chartab[*cp] &= ~mask;
	}
	return 0;
}

char *spk_strlwr(char *s)
{
	char *p;

	if (!s)
		return NULL;

	for (p = s; *p; p++)
		*p = tolower(*p);
	return s;
}

char *spk_s2uchar(char *start, char *dest)
{
	int val;

	val = simple_strtoul(skip_spaces(start), &start, 10);
	if (*start == ',')
		start++;
	*dest = (u_char)val;
	return start;
}

