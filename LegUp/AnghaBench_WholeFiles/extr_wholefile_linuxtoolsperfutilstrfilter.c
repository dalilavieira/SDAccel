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
struct strfilter_node {char const* p; struct strfilter_node* root; struct strfilter_node* r; struct strfilter_node* l; } ;
struct strfilter {char const* p; struct strfilter* root; struct strfilter* r; struct strfilter* l; } ;
typedef  int /*<<< orphan*/  root ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GIT_ALPHA ; 
 char* OP_and ; 
 char* OP_not ; 
 char* OP_or ; 
 int /*<<< orphan*/  __fallthrough ; 
 char* asprintf_expr_inout_ints (char const*,int,size_t,int*) ; 
 void* calloc (int,size_t) ; 
 int /*<<< orphan*/  free (struct strfilter_node*) ; 
 int /*<<< orphan*/  is_operator (char const) ; 
 int /*<<< orphan*/  is_separator (char const) ; 
 scalar_t__ isspace (char const) ; 
 char* ltrim (int /*<<< orphan*/ ) ; 
 char* malloc (int) ; 
 int /*<<< orphan*/  memset (struct strfilter_node*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  rtrim (char*) ; 
 scalar_t__ sane_istest (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strcpy (char*,char*) ; 
static  int strfilter_node__sprint (struct strfilter_node*,char*) ; 
 int strglobmatch (char const*,int*) ; 
 int strlen (char*) ; 
 char const* strndup (char const*,int) ; 
 int /*<<< orphan*/ * strpbrk (char const*,char*) ; 
 int /*<<< orphan*/  zfree (char**) ; 

__attribute__((used)) static inline void *zalloc(size_t size)
{
	return calloc(1, size);
}

__attribute__((used)) static inline bool strisglob(const char *str)
{
	return strpbrk(str, "*?[") != NULL;
}

__attribute__((used)) static inline char *trim(char *s)
{
	return ltrim(rtrim(s));
}

__attribute__((used)) static inline char *asprintf_expr_in_ints(const char *var, size_t nints, int *ints)
{
	return asprintf_expr_inout_ints(var, true, nints, ints);
}

__attribute__((used)) static inline char *asprintf_expr_not_in_ints(const char *var, size_t nints, int *ints)
{
	return asprintf_expr_inout_ints(var, false, nints, ints);
}

__attribute__((used)) static inline int sane_case(int x, int high)
{
	if (sane_istest(x, GIT_ALPHA))
		x = (x & ~0x20) | high;
	return x;
}

__attribute__((used)) static void strfilter_node__delete(struct strfilter_node *node)
{
	if (node) {
		if (node->p && !is_operator(*node->p))
			zfree((char **)&node->p);
		strfilter_node__delete(node->l);
		strfilter_node__delete(node->r);
		free(node);
	}
}

void strfilter__delete(struct strfilter *filter)
{
	if (filter) {
		strfilter_node__delete(filter->root);
		free(filter);
	}
}

__attribute__((used)) static const char *get_token(const char *s, const char **e)
{
	const char *p;

	while (isspace(*s))	/* Skip spaces */
		s++;

	if (*s == '\0') {
		p = s;
		goto end;
	}

	p = s + 1;
	if (!is_separator(*s)) {
		/* End search */
retry:
		while (*p && !is_separator(*p) && !isspace(*p))
			p++;
		/* Escape and special case: '!' is also used in glob pattern */
		if (*(p - 1) == '\\' || (*p == '!' && *(p - 1) == '[')) {
			p++;
			goto retry;
		}
	}
end:
	*e = p;
	return s;
}

__attribute__((used)) static struct strfilter_node *strfilter_node__alloc(const char *op,
						    struct strfilter_node *l,
						    struct strfilter_node *r)
{
	struct strfilter_node *node = zalloc(sizeof(*node));

	if (node) {
		node->p = op;
		node->l = l;
		node->r = r;
	}

	return node;
}

__attribute__((used)) static struct strfilter_node *strfilter_node__new(const char *s,
						  const char **ep)
{
	struct strfilter_node root, *cur, *last_op;
	const char *e;

	if (!s)
		return NULL;

	memset(&root, 0, sizeof(root));
	last_op = cur = &root;

	s = get_token(s, &e);
	while (*s != '\0' && *s != ')') {
		switch (*s) {
		case '&':	/* Exchg last OP->r with AND */
			if (!cur->r || !last_op->r)
				goto error;
			cur = strfilter_node__alloc(OP_and, last_op->r, NULL);
			if (!cur)
				goto nomem;
			last_op->r = cur;
			last_op = cur;
			break;
		case '|':	/* Exchg the root with OR */
			if (!cur->r || !root.r)
				goto error;
			cur = strfilter_node__alloc(OP_or, root.r, NULL);
			if (!cur)
				goto nomem;
			root.r = cur;
			last_op = cur;
			break;
		case '!':	/* Add NOT as a leaf node */
			if (cur->r)
				goto error;
			cur->r = strfilter_node__alloc(OP_not, NULL, NULL);
			if (!cur->r)
				goto nomem;
			cur = cur->r;
			break;
		case '(':	/* Recursively parses inside the parenthesis */
			if (cur->r)
				goto error;
			cur->r = strfilter_node__new(s + 1, &s);
			if (!s)
				goto nomem;
			if (!cur->r || *s != ')')
				goto error;
			e = s + 1;
			break;
		default:
			if (cur->r)
				goto error;
			cur->r = strfilter_node__alloc(NULL, NULL, NULL);
			if (!cur->r)
				goto nomem;
			cur->r->p = strndup(s, e - s);
			if (!cur->r->p)
				goto nomem;
		}
		s = get_token(e, &e);
	}
	if (!cur->r)
		goto error;
	*ep = s;
	return root.r;
nomem:
	s = NULL;
error:
	*ep = s;
	strfilter_node__delete(root.r);
	return NULL;
}

struct strfilter *strfilter__new(const char *rules, const char **err)
{
	struct strfilter *filter = zalloc(sizeof(*filter));
	const char *ep = NULL;

	if (filter)
		filter->root = strfilter_node__new(rules, &ep);

	if (!filter || !filter->root || *ep != '\0') {
		if (err)
			*err = ep;
		strfilter__delete(filter);
		filter = NULL;
	}

	return filter;
}

__attribute__((used)) static int strfilter__append(struct strfilter *filter, bool _or,
			     const char *rules, const char **err)
{
	struct strfilter_node *right, *root;
	const char *ep = NULL;

	if (!filter || !rules)
		return -EINVAL;

	right = strfilter_node__new(rules, &ep);
	if (!right || *ep != '\0') {
		if (err)
			*err = ep;
		goto error;
	}
	root = strfilter_node__alloc(_or ? OP_or : OP_and, filter->root, right);
	if (!root) {
		ep = NULL;
		goto error;
	}

	filter->root = root;
	return 0;

error:
	strfilter_node__delete(right);
	return ep ? -EINVAL : -ENOMEM;
}

int strfilter__or(struct strfilter *filter, const char *rules, const char **err)
{
	return strfilter__append(filter, true, rules, err);
}

int strfilter__and(struct strfilter *filter, const char *rules,
		   const char **err)
{
	return strfilter__append(filter, false, rules, err);
}

__attribute__((used)) static bool strfilter_node__compare(struct strfilter_node *node,
				    const char *str)
{
	if (!node || !node->p)
		return false;

	switch (*node->p) {
	case '|':	/* OR */
		return strfilter_node__compare(node->l, str) ||
			strfilter_node__compare(node->r, str);
	case '&':	/* AND */
		return strfilter_node__compare(node->l, str) &&
			strfilter_node__compare(node->r, str);
	case '!':	/* NOT */
		return !strfilter_node__compare(node->r, str);
	default:
		return strglobmatch(str, node->p);
	}
}

__attribute__((used)) static int strfilter_node__sprint_pt(struct strfilter_node *node, char *buf)
{
	int len;
	int pt = node->r ? 2 : 0;	/* don't need to check node->l */

	if (buf && pt)
		*buf++ = '(';
	len = strfilter_node__sprint(node, buf);
	if (len < 0)
		return len;
	if (buf && pt)
		*(buf + len) = ')';
	return len + pt;
}

__attribute__((used)) static int strfilter_node__sprint(struct strfilter_node *node, char *buf)
{
	int len = 0, rlen;

	if (!node || !node->p)
		return -EINVAL;

	switch (*node->p) {
	case '|':
	case '&':
		len = strfilter_node__sprint_pt(node->l, buf);
		if (len < 0)
			return len;
		__fallthrough;
	case '!':
		if (buf) {
			*(buf + len++) = *node->p;
			buf += len;
		} else
			len++;
		rlen = strfilter_node__sprint_pt(node->r, buf);
		if (rlen < 0)
			return rlen;
		len += rlen;
		break;
	default:
		len = strlen(node->p);
		if (buf)
			strcpy(buf, node->p);
	}

	return len;
}

char *strfilter__string(struct strfilter *filter)
{
	int len;
	char *ret = NULL;

	len = strfilter_node__sprint(filter->root, NULL);
	if (len < 0)
		return NULL;

	ret = malloc(len + 1);
	if (ret)
		strfilter_node__sprint(filter->root, ret);

	return ret;
}

