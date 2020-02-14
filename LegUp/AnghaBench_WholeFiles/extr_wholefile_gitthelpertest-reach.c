#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct string_list {int nr; TYPE_4__* items; } ;
struct strbuf {int len; int* buf; } ;
struct repository {int dummy; } ;
struct ref_filter {int with_commit_tag_algo; } ;
struct object_id {int dummy; } ;
struct object_array {int dummy; } ;
struct object {int dummy; } ;
struct contains_cache {int dummy; } ;
struct commit_list {TYPE_3__* item; struct commit_list* next; } ;
struct TYPE_5__ {int const flags; } ;
struct commit {TYPE_1__ object; } ;
struct TYPE_8__ {char* string; } ;
struct TYPE_6__ {int flags; struct object_id oid; } ;
struct TYPE_7__ {TYPE_2__ object; } ;

/* Variables and functions */
 int /*<<< orphan*/  ALLOC_ARRAY (struct commit**,int) ; 
 int /*<<< orphan*/  ALLOC_GROW (struct commit**,int,int) ; 
 scalar_t__ EOF ; 
 struct object_array OBJECT_ARRAY_INIT ; 
 int /*<<< orphan*/  OBJ_COMMIT ; 
 struct strbuf STRBUF_INIT ; 
 struct string_list STRING_LIST_INIT_DUP ; 
 int /*<<< orphan*/  _ (char*) ; 
 int /*<<< orphan*/  add_object_array (struct object*,int /*<<< orphan*/ *,struct object_array*) ; 
 int can_all_from_reach (struct commit_list*,struct commit_list*,int) ; 
 int can_all_from_reach_with_flag (struct object_array*,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int commit_contains (struct ref_filter*,struct commit*,struct commit_list*,struct contains_cache*) ; 
 int /*<<< orphan*/  commit_list_insert (struct commit*,struct commit_list**) ; 
 struct object* deref_tag_noverify (struct object*) ; 
 int /*<<< orphan*/  die (char*,...) ; 
 int /*<<< orphan*/  exit (int) ; 
 struct commit_list* get_merge_bases_many (struct commit*,int,struct commit**) ; 
 scalar_t__ get_oid_committish (int*,struct object_id*) ; 
 struct commit_list* get_reachable_subset (struct commit**,int,struct commit**,int,int const) ; 
 int in_merge_bases (struct commit*,struct commit*) ; 
 int /*<<< orphan*/  init_contains_cache (struct contains_cache*) ; 
 int is_descendant_of (struct commit*,struct commit_list*) ; 
 struct commit* object_as_type (struct repository*,struct object*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  oid_to_hex (struct object_id*) ; 
 int /*<<< orphan*/  oidcpy (struct object_id*,struct object_id*) ; 
 struct object* parse_object (struct repository*,struct object_id*) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 struct commit_list* reduce_heads (struct commit_list*) ; 
 int ref_newer (struct object_id*,struct object_id*) ; 
 int /*<<< orphan*/  setup_git_directory () ; 
 int /*<<< orphan*/  stdin ; 
 scalar_t__ strbuf_getline (struct strbuf*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strbuf_release (struct strbuf*) ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 
 int /*<<< orphan*/  string_list_append (struct string_list*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  string_list_clear (struct string_list*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  string_list_sort (struct string_list*) ; 
 struct repository* the_repository ; 

__attribute__((used)) static void print_sorted_commit_ids(struct commit_list *list)
{
	int i;
	struct string_list s = STRING_LIST_INIT_DUP;

	while (list) {
		string_list_append(&s, oid_to_hex(&list->item->object.oid));
		list = list->next;
	}

	string_list_sort(&s);

	for (i = 0; i < s.nr; i++)
		printf("%s\n", s.items[i].string);

	string_list_clear(&s, 0);
}

int cmd__reach(int ac, const char **av)
{
	struct object_id oid_A, oid_B;
	struct commit *A, *B;
	struct commit_list *X, *Y;
	struct object_array X_obj = OBJECT_ARRAY_INIT;
	struct commit **X_array, **Y_array;
	int X_nr, X_alloc, Y_nr, Y_alloc;
	struct strbuf buf = STRBUF_INIT;
	struct repository *r = the_repository;

	setup_git_directory();

	if (ac < 2)
		exit(1);

	A = B = NULL;
	X = Y = NULL;
	X_nr = Y_nr = 0;
	X_alloc = Y_alloc = 16;
	ALLOC_ARRAY(X_array, X_alloc);
	ALLOC_ARRAY(Y_array, Y_alloc);

	while (strbuf_getline(&buf, stdin) != EOF) {
		struct object_id oid;
		struct object *orig;
		struct object *peeled;
		struct commit *c;
		if (buf.len < 3)
			continue;

		if (get_oid_committish(buf.buf + 2, &oid))
			die("failed to resolve %s", buf.buf + 2);

		orig = parse_object(r, &oid);
		peeled = deref_tag_noverify(orig);

		if (!peeled)
			die("failed to load commit for input %s resulting in oid %s\n",
			    buf.buf, oid_to_hex(&oid));

		c = object_as_type(r, peeled, OBJ_COMMIT, 0);

		if (!c)
			die("failed to load commit for input %s resulting in oid %s\n",
			    buf.buf, oid_to_hex(&oid));

		switch (buf.buf[0]) {
			case 'A':
				oidcpy(&oid_A, &oid);
				A = c;
				break;

			case 'B':
				oidcpy(&oid_B, &oid);
				B = c;
				break;

			case 'X':
				commit_list_insert(c, &X);
				ALLOC_GROW(X_array, X_nr + 1, X_alloc);
				X_array[X_nr++] = c;
				add_object_array(orig, NULL, &X_obj);
				break;

			case 'Y':
				commit_list_insert(c, &Y);
				ALLOC_GROW(Y_array, Y_nr + 1, Y_alloc);
				Y_array[Y_nr++] = c;
				break;

			default:
				die("unexpected start of line: %c", buf.buf[0]);
		}
	}
	strbuf_release(&buf);

	if (!strcmp(av[1], "ref_newer"))
		printf("%s(A,B):%d\n", av[1], ref_newer(&oid_A, &oid_B));
	else if (!strcmp(av[1], "in_merge_bases"))
		printf("%s(A,B):%d\n", av[1], in_merge_bases(A, B));
	else if (!strcmp(av[1], "is_descendant_of"))
		printf("%s(A,X):%d\n", av[1], is_descendant_of(A, X));
	else if (!strcmp(av[1], "get_merge_bases_many")) {
		struct commit_list *list = get_merge_bases_many(A, X_nr, X_array);
		printf("%s(A,X):\n", av[1]);
		print_sorted_commit_ids(list);
	} else if (!strcmp(av[1], "reduce_heads")) {
		struct commit_list *list = reduce_heads(X);
		printf("%s(X):\n", av[1]);
		print_sorted_commit_ids(list);
	} else if (!strcmp(av[1], "can_all_from_reach")) {
		printf("%s(X,Y):%d\n", av[1], can_all_from_reach(X, Y, 1));
	} else if (!strcmp(av[1], "can_all_from_reach_with_flag")) {
		struct commit_list *iter = Y;

		while (iter) {
			iter->item->object.flags |= 2;
			iter = iter->next;
		}

		printf("%s(X,_,_,0,0):%d\n", av[1], can_all_from_reach_with_flag(&X_obj, 2, 4, 0, 0));
	} else if (!strcmp(av[1], "commit_contains")) {
		struct ref_filter filter;
		struct contains_cache cache;
		init_contains_cache(&cache);

		if (ac > 2 && !strcmp(av[2], "--tag"))
			filter.with_commit_tag_algo = 1;
		else
			filter.with_commit_tag_algo = 0;

		printf("%s(_,A,X,_):%d\n", av[1], commit_contains(&filter, A, X, &cache));
	} else if (!strcmp(av[1], "get_reachable_subset")) {
		const int reachable_flag = 1;
		int i, count = 0;
		struct commit_list *current;
		struct commit_list *list = get_reachable_subset(X_array, X_nr,
								Y_array, Y_nr,
								reachable_flag);
		printf("get_reachable_subset(X,Y)\n");
		for (current = list; current; current = current->next) {
			if (!(list->item->object.flags & reachable_flag))
				die(_("commit %s is not marked reachable"),
				    oid_to_hex(&list->item->object.oid));
			count++;
		}
		for (i = 0; i < Y_nr; i++) {
			if (Y_array[i]->object.flags & reachable_flag)
				count--;
		}

		if (count < 0)
			die(_("too many commits marked reachable"));

		print_sorted_commit_ids(list);
	}

	exit(0);
}

