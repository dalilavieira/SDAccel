#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_33__   TYPE_6__ ;
typedef  struct TYPE_32__   TYPE_5__ ;
typedef  struct TYPE_31__   TYPE_4__ ;
typedef  struct TYPE_30__   TYPE_3__ ;
typedef  struct TYPE_29__   TYPE_2__ ;
typedef  struct TYPE_28__   TYPE_1__ ;

/* Type definitions */
struct TYPE_28__ {unsigned long pc; int /*<<< orphan*/  methodID; scalar_t__ discrim; int /*<<< orphan*/  line_number; } ;
typedef  TYPE_1__ jvmti_line_info_t ;
struct TYPE_29__ {size_t start_location; int /*<<< orphan*/  line_number; } ;
typedef  TYPE_2__ jvmtiLineNumberEntry ;
typedef  scalar_t__ jvmtiError ;
typedef  TYPE_3__* jvmtiEnv ;
struct TYPE_31__ {scalar_t__ kind; struct TYPE_31__* next; } ;
typedef  TYPE_4__ jvmtiCompiledMethodLoadRecordHeader ;
struct TYPE_32__ {int numpcs; TYPE_6__* pcinfo; } ;
typedef  TYPE_5__ jvmtiCompiledMethodLoadInlineRecord ;
typedef  int /*<<< orphan*/  jmethodID ;
typedef  size_t jint ;
typedef  int /*<<< orphan*/  jclass ;
struct TYPE_33__ {size_t* bcis; int /*<<< orphan*/ * methods; void* pc; } ;
struct TYPE_30__ {scalar_t__ (* GetErrorName ) (TYPE_3__**,scalar_t__,char**) ;scalar_t__ (* GetLineNumberTable ) (TYPE_3__**,int /*<<< orphan*/ ,size_t*,TYPE_2__**) ;scalar_t__ (* GetMethodDeclaringClass ) (TYPE_3__**,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ;scalar_t__ (* GetSourceFileName ) (TYPE_3__**,int /*<<< orphan*/ ,char**) ;scalar_t__ (* GetClassSignature ) (TYPE_3__**,int /*<<< orphan*/ ,char**,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* Deallocate ) (TYPE_3__**,unsigned char*) ;} ;
typedef  TYPE_6__ PCStackInfo ;

/* Variables and functions */
 scalar_t__ JVMTI_CMLR_INLINE_INFO ; 
 scalar_t__ JVMTI_ERROR_NONE ; 
 scalar_t__ JVMTI_ERROR_NOT_FOUND ; 
 scalar_t__ JVMTI_ERROR_NULL_POINTER ; 
 scalar_t__ JVMTI_ERROR_OUT_OF_MEMORY ; 
 int PATH_MAX ; 
 void* malloc (size_t) ; 
 int /*<<< orphan*/  strcpy (char*,char*) ; 
 int strlen (char const*) ; 
 int /*<<< orphan*/  strncpy (char*,char const*,size_t) ; 
 char* strrchr (char const*,char) ; 
 scalar_t__ stub1 (TYPE_3__**,scalar_t__,char**) ; 
 int /*<<< orphan*/  stub10 (TYPE_3__**,unsigned char*) ; 
 int /*<<< orphan*/  stub11 (TYPE_3__**,unsigned char*) ; 
 int /*<<< orphan*/  stub2 (TYPE_3__**,unsigned char*) ; 
 scalar_t__ stub3 (TYPE_3__**,int /*<<< orphan*/ ,size_t*,TYPE_2__**) ; 
 int /*<<< orphan*/  stub4 (TYPE_3__**,unsigned char*) ; 
 size_t stub5 (TYPE_3__**,int /*<<< orphan*/ ,size_t*,TYPE_2__**) ; 
 int /*<<< orphan*/  stub6 (TYPE_3__**,unsigned char*) ; 
 scalar_t__ stub7 (TYPE_3__**,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ stub8 (TYPE_3__**,int /*<<< orphan*/ ,char**) ; 
 scalar_t__ stub9 (TYPE_3__**,int /*<<< orphan*/ ,char**,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  warnx (char*,char const*,scalar_t__) ; 

__attribute__((used)) static void print_error(jvmtiEnv *jvmti, const char *msg, jvmtiError ret)
{
	char *err_msg = NULL;
	jvmtiError err;
	err = (*jvmti)->GetErrorName(jvmti, ret, &err_msg);
	if (err == JVMTI_ERROR_NONE) {
		warnx("%s failed with %s", msg, err_msg);
		(*jvmti)->Deallocate(jvmti, (unsigned char *)err_msg);
	} else {
		warnx("%s failed with an unknown error %d", msg, ret);
	}
}

__attribute__((used)) static jvmtiError
do_get_line_numbers(jvmtiEnv *jvmti, void *pc, jmethodID m, jint bci,
		    jvmti_line_info_t *tab, jint *nr)
{
	jint i, lines = 0;
	jint nr_lines = 0;
	jvmtiLineNumberEntry *loc_tab = NULL;
	jvmtiError ret;

	ret = (*jvmti)->GetLineNumberTable(jvmti, m, &nr_lines, &loc_tab);
	if (ret != JVMTI_ERROR_NONE) {
		print_error(jvmti, "GetLineNumberTable", ret);
		return ret;
	}

	for (i = 0; i < nr_lines; i++) {
		if (loc_tab[i].start_location < bci) {
			tab[lines].pc = (unsigned long)pc;
			tab[lines].line_number = loc_tab[i].line_number;
			tab[lines].discrim = 0; /* not yet used */
			tab[lines].methodID = m;
			lines++;
		} else {
			break;
		}
	}
	(*jvmti)->Deallocate(jvmti, (unsigned char *)loc_tab);
	*nr = lines;
	return JVMTI_ERROR_NONE;
}

__attribute__((used)) static jvmtiError
get_line_numbers(jvmtiEnv *jvmti, const void *compile_info, jvmti_line_info_t **tab, int *nr_lines)
{
	const jvmtiCompiledMethodLoadRecordHeader *hdr;
	jvmtiCompiledMethodLoadInlineRecord *rec;
	jvmtiLineNumberEntry *lne = NULL;
	PCStackInfo *c;
	jint nr, ret;
	int nr_total = 0;
	int i, lines_total = 0;

	if (!(tab && nr_lines))
		return JVMTI_ERROR_NULL_POINTER;

	/*
	 * Phase 1 -- get the number of lines necessary
	 */
	for (hdr = compile_info; hdr != NULL; hdr = hdr->next) {
		if (hdr->kind == JVMTI_CMLR_INLINE_INFO) {
			rec = (jvmtiCompiledMethodLoadInlineRecord *)hdr;
			for (i = 0; i < rec->numpcs; i++) {
				c = rec->pcinfo + i;
				nr = 0;
				/*
				 * unfortunately, need a tab to get the number of lines!
				 */
				ret = (*jvmti)->GetLineNumberTable(jvmti, c->methods[0], &nr, &lne);
				if (ret == JVMTI_ERROR_NONE) {
					/* free what was allocated for nothing */
					(*jvmti)->Deallocate(jvmti, (unsigned char *)lne);
					nr_total += (int)nr;
				} else {
					print_error(jvmti, "GetLineNumberTable", ret);
				}
			}
		}
	}

	if (nr_total == 0)
		return JVMTI_ERROR_NOT_FOUND;

	/*
	 * Phase 2 -- allocate big enough line table
	 */
	*tab = malloc(nr_total * sizeof(**tab));
	if (!*tab)
		return JVMTI_ERROR_OUT_OF_MEMORY;

	for (hdr = compile_info; hdr != NULL; hdr = hdr->next) {
		if (hdr->kind == JVMTI_CMLR_INLINE_INFO) {
			rec = (jvmtiCompiledMethodLoadInlineRecord *)hdr;
			for (i = 0; i < rec->numpcs; i++) {
				c = rec->pcinfo + i;
				nr = 0;
				ret = do_get_line_numbers(jvmti, c->pc,
							  c->methods[0],
							  c->bcis[0],
							  *tab + lines_total,
							  &nr);
				if (ret == JVMTI_ERROR_NONE)
					lines_total += nr;
			}
		}
	}
	*nr_lines = lines_total;
	return JVMTI_ERROR_NONE;
}

__attribute__((used)) static void
copy_class_filename(const char * class_sign, const char * file_name, char * result, size_t max_length)
{
	/*
	* Assume path name is class hierarchy, this is a common practice with Java programs
	*/
	if (*class_sign == 'L') {
		int j, i = 0;
		char *p = strrchr(class_sign, '/');
		if (p) {
			/* drop the 'L' prefix and copy up to the final '/' */
			for (i = 0; i < (p - class_sign); i++)
				result[i] = class_sign[i+1];
		}
		/*
		* append file name, we use loops and not string ops to avoid modifying
		* class_sign which is used later for the symbol name
		*/
		for (j = 0; i < (max_length - 1) && file_name && j < strlen(file_name); j++, i++)
			result[i] = file_name[j];

		result[i] = '\0';
	} else {
		/* fallback case */
		size_t file_name_len = strlen(file_name);
		strncpy(result, file_name, file_name_len < max_length ? file_name_len : max_length);
	}
}

__attribute__((used)) static jvmtiError
get_source_filename(jvmtiEnv *jvmti, jmethodID methodID, char ** buffer)
{
	jvmtiError ret;
	jclass decl_class;
	char *file_name = NULL;
	char *class_sign = NULL;
	char fn[PATH_MAX];
	size_t len;

	ret = (*jvmti)->GetMethodDeclaringClass(jvmti, methodID, &decl_class);
	if (ret != JVMTI_ERROR_NONE) {
		print_error(jvmti, "GetMethodDeclaringClass", ret);
		return ret;
	}

	ret = (*jvmti)->GetSourceFileName(jvmti, decl_class, &file_name);
	if (ret != JVMTI_ERROR_NONE) {
		print_error(jvmti, "GetSourceFileName", ret);
		return ret;
	}

	ret = (*jvmti)->GetClassSignature(jvmti, decl_class, &class_sign, NULL);
	if (ret != JVMTI_ERROR_NONE) {
		print_error(jvmti, "GetClassSignature", ret);
		goto free_file_name_error;
	}

	copy_class_filename(class_sign, file_name, fn, PATH_MAX);
	len = strlen(fn);
	*buffer = malloc((len + 1) * sizeof(char));
	if (!*buffer) {
		print_error(jvmti, "GetClassSignature", ret);
		ret = JVMTI_ERROR_OUT_OF_MEMORY;
		goto free_class_sign_error;
	}
	strcpy(*buffer, fn);
	ret = JVMTI_ERROR_NONE;

free_class_sign_error:
	(*jvmti)->Deallocate(jvmti, (unsigned char *)class_sign);
free_file_name_error:
	(*jvmti)->Deallocate(jvmti, (unsigned char *)file_name);

	return ret;
}

__attribute__((used)) static jvmtiError
fill_source_filenames(jvmtiEnv *jvmti, int nr_lines,
		      const jvmti_line_info_t * line_tab,
		      char ** file_names)
{
	int index;
	jvmtiError ret;

	for (index = 0; index < nr_lines; ++index) {
		ret = get_source_filename(jvmti, line_tab[index].methodID, &(file_names[index]));
		if (ret != JVMTI_ERROR_NONE)
			return ret;
	}

	return JVMTI_ERROR_NONE;
}

