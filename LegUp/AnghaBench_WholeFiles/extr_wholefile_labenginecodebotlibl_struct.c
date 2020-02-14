#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
struct TYPE_14__ {scalar_t__ type; char* string; int subtype; double floatvalue; long intvalue; } ;
typedef  TYPE_1__ token_t ;
struct TYPE_15__ {int /*<<< orphan*/  size; TYPE_3__* fields; } ;
typedef  TYPE_2__ structdef_t ;
typedef  int /*<<< orphan*/  source_t ;
typedef  int qboolean ;
struct TYPE_16__ {char* name; int type; double floatmin; double floatmax; int maxarray; int offset; TYPE_2__* substruct; } ;
typedef  TYPE_3__ fielddef_t ;
typedef  int /*<<< orphan*/  buf ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  Com_sprintf (char*,int,char*,float) ; 
 int FT_ARRAY ; 
 int FT_BOUNDED ; 
#define  FT_CHAR 132 
#define  FT_FLOAT 131 
#define  FT_INT 130 
#define  FT_STRING 129 
#define  FT_STRUCT 128 
 int FT_TYPE ; 
 int FT_UNSIGNED ; 
 int MAX_STRINGFIELD ; 
 long Maximum (long,double) ; 
 long Minimum (long,double) ; 
 scalar_t__ PC_CheckTokenString (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  PC_ExpectAnyToken (int /*<<< orphan*/ *,TYPE_1__*) ; 
 int /*<<< orphan*/  PC_ExpectTokenString (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  PC_ExpectTokenType (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  PC_UnreadLastToken (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SourceError (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  StripDoubleQuotes (char*) ; 
 int /*<<< orphan*/  StripSingleQuotes (char*) ; 
 int TT_FLOAT ; 
 scalar_t__ TT_LITERAL ; 
 scalar_t__ TT_NUMBER ; 
 scalar_t__ TT_PUNCTUATION ; 
 int /*<<< orphan*/  TT_STRING ; 
 scalar_t__ fprintf (int /*<<< orphan*/ *,char*,...) ; 
 int qfalse ; 
 int qtrue ; 
 scalar_t__ strcmp (char*,char*) ; 
 int strlen (char*) ; 
 int /*<<< orphan*/  strncpy (char*,char*,int) ; 

fielddef_t *FindField(fielddef_t *defs, char *name)
{
	int i;

	for (i = 0; defs[i].name; i++)
	{
		if (!strcmp(defs[i].name, name)) return &defs[i];
	} //end for
	return NULL;
}

qboolean ReadNumber(source_t *source, fielddef_t *fd, void *p)
{
	token_t token;
	int negative = qfalse;
	long int intval, intmin = 0, intmax = 0;
	double floatval;

	if (!PC_ExpectAnyToken(source, &token)) return 0;

	//check for minus sign
	if (token.type == TT_PUNCTUATION)
	{
		if (fd->type & FT_UNSIGNED)
		{
			SourceError(source, "expected unsigned value, found %s", token.string);
			return 0;
		} //end if
		//if not a minus sign
		if (strcmp(token.string, "-"))
		{
			SourceError(source, "unexpected punctuation %s", token.string);
			return 0;
		} //end if
		negative = qtrue;
		//read the number
		if (!PC_ExpectAnyToken(source, &token)) return 0;
	} //end if
	//check if it is a number
	if (token.type != TT_NUMBER)
	{
		SourceError(source, "expected number, found %s", token.string);
		return 0;
	} //end if
	//check for a float value
	if (token.subtype & TT_FLOAT)
	{
		if ((fd->type & FT_TYPE) != FT_FLOAT)
		{
			SourceError(source, "unexpected float");
			return 0;
		} //end if
		floatval = token.floatvalue;
		if (negative) floatval = -floatval;
		if (fd->type & FT_BOUNDED)
		{
			if (floatval < fd->floatmin || floatval > fd->floatmax)
			{
				SourceError(source, "float out of range [%f, %f]", fd->floatmin, fd->floatmax);
				return 0;
			} //end if
		} //end if
		*(float *) p = (float) floatval;
		return 1;
	} //end if
	//
	intval = token.intvalue;
	if (negative) intval = -intval;
	//check bounds
	if ((fd->type & FT_TYPE) == FT_CHAR)
	{
		if (fd->type & FT_UNSIGNED) {intmin = 0; intmax = 255;}
		else {intmin = -128; intmax = 127;}
	} //end if
	if ((fd->type & FT_TYPE) == FT_INT)
	{
		if (fd->type & FT_UNSIGNED) {intmin = 0; intmax = 65535;}
		else {intmin = -32768; intmax = 32767;}
	} //end else if
	if ((fd->type & FT_TYPE) == FT_CHAR || (fd->type & FT_TYPE) == FT_INT)
	{
		if (fd->type & FT_BOUNDED)
		{
			intmin = Maximum(intmin, fd->floatmin);
			intmax = Minimum(intmax, fd->floatmax);
		} //end if
		if (intval < intmin || intval > intmax)
		{
			SourceError(source, "value %ld out of range [%ld, %ld]", intval, intmin, intmax);
			return 0;
		} //end if
	} //end if
	else if ((fd->type & FT_TYPE) == FT_FLOAT)
	{
		if (fd->type & FT_BOUNDED)
		{
			if (intval < fd->floatmin || intval > fd->floatmax)
			{
				SourceError(source, "value %ld out of range [%f, %f]", intval, fd->floatmin, fd->floatmax);
				return 0;
			} //end if
		} //end if
	} //end else if
	//store the value
	if ((fd->type & FT_TYPE) == FT_CHAR)
	{
		if (fd->type & FT_UNSIGNED) *(unsigned char *) p = (unsigned char) intval;
		else *(char *) p = (char) intval;
	} //end if
	else if ((fd->type & FT_TYPE) == FT_INT)
	{
		if (fd->type & FT_UNSIGNED) *(unsigned int *) p = (unsigned int) intval;
		else *(int *) p = (int) intval;
	} //end else
	else if ((fd->type & FT_TYPE) == FT_FLOAT)
	{
		*(float *) p = (float) intval;
	} //end else
	return 1;
}

qboolean ReadChar(source_t *source, fielddef_t *fd, void *p)
{
	token_t token;

	if (!PC_ExpectAnyToken(source, &token)) return 0;

	//take literals into account
	if (token.type == TT_LITERAL)
	{
		StripSingleQuotes(token.string);
		*(char *) p = token.string[0];
	} //end if
	else
	{
		PC_UnreadLastToken(source);
		if (!ReadNumber(source, fd, p)) return 0;
	} //end if
	return 1;
}

int ReadString(source_t *source, fielddef_t *fd, void *p)
{
	token_t token;

	if (!PC_ExpectTokenType(source, TT_STRING, 0, &token)) return 0;
	//remove the double quotes
	StripDoubleQuotes(token.string);
	//copy the string
	strncpy((char *) p, token.string, MAX_STRINGFIELD-1);
	//make sure the string is closed with a zero
	((char *)p)[MAX_STRINGFIELD-1] = '\0';
	//
	return 1;
}

int ReadStructure(source_t *source, structdef_t *def, char *structure)
{
	token_t token;
	fielddef_t *fd;
	void *p;
	int num;

	if (!PC_ExpectTokenString(source, "{")) return 0;
	while(1)
	{
		if (!PC_ExpectAnyToken(source, &token)) return qfalse;
		//if end of structure
		if (!strcmp(token.string, "}")) break;
		//find the field with the name
		fd = FindField(def->fields, token.string);
		if (!fd)
		{
			SourceError(source, "unknown structure field %s", token.string);
			return qfalse;
		} //end if
		if (fd->type & FT_ARRAY)
		{
			num = fd->maxarray;
			if (!PC_ExpectTokenString(source, "{")) return qfalse;
		} //end if
		else
		{
			num = 1;
		} //end else
		p = (void *)(structure + fd->offset);
		while (num-- > 0)
		{
			if (fd->type & FT_ARRAY)
			{
				if (PC_CheckTokenString(source, "}")) break;
			} //end if
			switch(fd->type & FT_TYPE)
			{
				case FT_CHAR:
				{
					if (!ReadChar(source, fd, p)) return qfalse;
					p = (char *) p + sizeof(char);
					break;
				} //end case
				case FT_INT:
				{
					if (!ReadNumber(source, fd, p)) return qfalse;
					p = (char *) p + sizeof(int);
					break;
				} //end case
				case FT_FLOAT:
				{
					if (!ReadNumber(source, fd, p)) return qfalse;
					p = (char *) p + sizeof(float);
					break;
				} //end case
				case FT_STRING:
				{
					if (!ReadString(source, fd, p)) return qfalse;
					p = (char *) p + MAX_STRINGFIELD;
					break;
				} //end case
				case FT_STRUCT:
				{
					if (!fd->substruct)
					{
						SourceError(source, "BUG: no sub structure defined");
						return qfalse;
					} //end if
					ReadStructure(source, fd->substruct, (char *) p);
					p = (char *) p + fd->substruct->size;
					break;
				} //end case
			} //end switch
			if (fd->type & FT_ARRAY)
			{
				if (!PC_ExpectAnyToken(source, &token)) return qfalse;
				if (!strcmp(token.string, "}")) break;
				if (strcmp(token.string, ","))
				{
					SourceError(source, "expected a comma, found %s", token.string);
					return qfalse;
				} //end if
			} //end if
		} //end while
	} //end while
	return qtrue;
}

int WriteIndent(FILE *fp, int indent)
{
	while(indent-- > 0)
	{
		if (fprintf(fp, "\t") < 0) return qfalse;
	} //end while
	return qtrue;
}

int WriteFloat(FILE *fp, float value)
{
	char buf[128];
	int l;

#ifdef BSPC
	snprintf(buf, sizeof(buf), "%f", value);
#else
	Com_sprintf(buf, sizeof(buf), "%f", value);
#endif
	l = strlen(buf);
	//strip any trailing zeros
	while(l-- > 1)
	{
		if (buf[l] != '0' && buf[l] != '.') break;
		if (buf[l] == '.')
		{
			buf[l] = 0;
			break;
		} //end if
		buf[l] = 0;
	} //end while
	//write the float to file
	if (fprintf(fp, "%s", buf) < 0) return 0;
	return 1;
}

int WriteStructWithIndent(FILE *fp, structdef_t *def, char *structure, int indent)
{
	int i, num;
	void *p;
	fielddef_t *fd;

	if (!WriteIndent(fp, indent)) return qfalse;
	if (fprintf(fp, "{\r\n") < 0) return qfalse;

	indent++;
	for (i = 0; def->fields[i].name; i++)
	{
		fd = &def->fields[i];
		if (!WriteIndent(fp, indent)) return qfalse;
		if (fprintf(fp, "%s\t", fd->name) < 0) return qfalse;
		p = (void *)(structure + fd->offset);
		if (fd->type & FT_ARRAY)
		{
			num = fd->maxarray;
			if (fprintf(fp, "{") < 0) return qfalse;
		} //end if
		else
		{
			num = 1;
		} //end else
		while(num-- > 0)
		{
			switch(fd->type & FT_TYPE)
			{
				case FT_CHAR:
				{
					if (fprintf(fp, "%d", *(char *) p) < 0) return qfalse;
					p = (char *) p + sizeof(char);
					break;
				} //end case
				case FT_INT:
				{
					if (fprintf(fp, "%d", *(int *) p) < 0) return qfalse;
					p = (char *) p + sizeof(int);
					break;
				} //end case
				case FT_FLOAT:
				{
					if (!WriteFloat(fp, *(float *)p)) return qfalse;
					p = (char *) p + sizeof(float);
					break;
				} //end case
				case FT_STRING:
				{
					if (fprintf(fp, "\"%s\"", (char *) p) < 0) return qfalse;
					p = (char *) p + MAX_STRINGFIELD;
					break;
				} //end case
				case FT_STRUCT:
				{
					if (!WriteStructWithIndent(fp, fd->substruct, structure, indent)) return qfalse;
					p = (char *) p + fd->substruct->size;
					break;
				} //end case
			} //end switch
			if (fd->type & FT_ARRAY)
			{
				if (num > 0)
				{
					if (fprintf(fp, ",") < 0) return qfalse;
				} //end if
				else
				{
					if (fprintf(fp, "}") < 0) return qfalse;
				} //end else
			} //end if
		} //end while
		if (fprintf(fp, "\r\n") < 0) return qfalse;
	} //end for
	indent--;

	if (!WriteIndent(fp, indent)) return qfalse;
	if (fprintf(fp, "}\r\n") < 0) return qfalse;
	return qtrue;
}

int WriteStructure(FILE *fp, structdef_t *def, char *structure)
{
	return WriteStructWithIndent(fp, def, structure, 0);
}

