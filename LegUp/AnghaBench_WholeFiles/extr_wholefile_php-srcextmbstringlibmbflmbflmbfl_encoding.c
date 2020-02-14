#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {char* name; char* mime_name; char*** aliases; int no_encoding; } ;
typedef  TYPE_1__ mbfl_encoding ;
typedef  enum mbfl_no_encoding { ____Placeholder_mbfl_no_encoding } mbfl_no_encoding ;

/* Variables and functions */
 TYPE_1__ const** mbfl_encoding_ptr_list ; 
 int mbfl_no_encoding_invalid ; 
 scalar_t__ strcasecmp (char*,char const*) ; 

__attribute__((used)) static inline int mbfl_is_error(size_t len) {
	return len >= (size_t) -16;
}

const mbfl_encoding *
mbfl_name2encoding(const char *name)
{
	const mbfl_encoding *encoding;
	int i, j;

	if (name == NULL) {
		return NULL;
	}

 	i = 0;
 	while ((encoding = mbfl_encoding_ptr_list[i++]) != NULL){
		if (strcasecmp(encoding->name, name) == 0) {
			return encoding;
		}
	}

 	/* serch MIME charset name */
 	i = 0;
 	while ((encoding = mbfl_encoding_ptr_list[i++]) != NULL) {
		if (encoding->mime_name != NULL) {
			if (strcasecmp(encoding->mime_name, name) == 0) {
				return encoding;
			}
		}
	}

 	/* serch aliases */
 	i = 0;
 	while ((encoding = mbfl_encoding_ptr_list[i++]) != NULL) {
		if (encoding->aliases != NULL) {
 			j = 0;
 			while ((*encoding->aliases)[j] != NULL) {
				if (strcasecmp((*encoding->aliases)[j], name) == 0) {
					return encoding;
				}
				j++;
			}
		}
	}

	return NULL;
}

const mbfl_encoding *
mbfl_no2encoding(enum mbfl_no_encoding no_encoding)
{
	const mbfl_encoding *encoding;
	int i;

	i = 0;
	while ((encoding = mbfl_encoding_ptr_list[i++]) != NULL){
		if (encoding->no_encoding == no_encoding) {
			return encoding;
		}
	}

	return NULL;
}

enum mbfl_no_encoding
mbfl_name2no_encoding(const char *name)
{
	const mbfl_encoding *encoding;

	encoding = mbfl_name2encoding(name);
	if (encoding == NULL) {
		return mbfl_no_encoding_invalid;
	} else {
		return encoding->no_encoding;
	}
}

const char *
mbfl_no_encoding2name(enum mbfl_no_encoding no_encoding)
{
	const mbfl_encoding *encoding;

	encoding = mbfl_no2encoding(no_encoding);
	if (encoding == NULL) {
		return "";
	} else {
		return encoding->name;
	}
}

const mbfl_encoding **
mbfl_get_supported_encodings(void)
{
	return mbfl_encoding_ptr_list;
}

const char *
mbfl_no2preferred_mime_name(enum mbfl_no_encoding no_encoding)
{
	const mbfl_encoding *encoding;

	encoding = mbfl_no2encoding(no_encoding);
	if (encoding != NULL && encoding->mime_name != NULL && encoding->mime_name[0] != '\0') {
		return encoding->mime_name;
	} else {
		return NULL;
	}
}

int
mbfl_is_support_encoding(const char *name)
{
	const mbfl_encoding *encoding;

	encoding = mbfl_name2encoding(name);
	if (encoding == NULL) {
		return 0;
	} else {
		return 1;
	}
}

