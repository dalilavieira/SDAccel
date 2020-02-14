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
struct i24 {long long i24; } ;
typedef  long long int8_t ;
typedef  long long int64_t ;
typedef  long long int32_t ;
typedef  long long int16_t ;
typedef  void* boolean_t ;
typedef  void* (* argsep_func_t ) (char) ;
typedef  int /*<<< orphan*/  DTEntry ;

/* Variables and functions */
 scalar_t__ DTGetProperty (int /*<<< orphan*/ ,char const*,void**,unsigned int*) ; 
 scalar_t__ DTLookupEntry (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *) ; 
 void* FALSE ; 
 scalar_t__ IODTGetDefault (char const*,void*,unsigned int) ; 
#define  NUM 129 
 char* PE_boot_args () ; 
#define  STR 128 
 void* TRUE ; 
static  int argnumcpy (long long,void*,unsigned int) ; 
static  int argstrcpy (char*,char*) ; 
static  int argstrcpy2 (char*,char*,unsigned int) ; 
static  int getval (char*,long long*,void* (*) (char),void*) ; 
static  void* isargsep (char) ; 
 scalar_t__ kSuccess ; 
 int /*<<< orphan*/  memcpy (void*,void**,unsigned int) ; 
 uintptr_t strlen (char const*) ; 
 scalar_t__ strncmp (char*,char const*,uintptr_t) ; 

__attribute__((used)) static boolean_t
PE_parse_boot_argn_internal(
	const char *arg_string,
	void *      arg_ptr,
	int         max_len,
	boolean_t   force_string)
{
	char *args;
	char *cp, c;
	uintptr_t i;
	long long val = 0;
	boolean_t arg_boolean;
	boolean_t arg_found;

	args = PE_boot_args();
	if (*args == '\0') return FALSE;

#ifdef CONFIG_EMBEDDED
	if (max_len == -1) return FALSE;
#endif

	arg_found = FALSE;

	while(*args && isargsep(*args)) args++;

	while (*args)
	{
		if (*args == '-')
			arg_boolean = TRUE;
		else
			arg_boolean = FALSE;

		cp = args;
		while (!isargsep (*cp) && *cp != '=')
			cp++;
		if (*cp != '=' && !arg_boolean)
			goto gotit;

		c = *cp;

		i = cp-args;
		if (strncmp(args, arg_string, i) ||
		    (i!=strlen(arg_string)))
			goto gotit;

		if (arg_boolean) {
			if (!force_string) {
				if (max_len > 0) {
					argnumcpy(1, arg_ptr, max_len);/* max_len of 0 performs no copy at all*/
					arg_found = TRUE;
				}
				else if (max_len == 0) {	
					arg_found = TRUE;
				}
			}
			break;
		} else {
			while (*cp && isargsep (*cp))
				cp++;
			if (*cp == '=' && c != '=') {
				args = cp+1;
				goto gotit;
			}
			if ('_' == *arg_string) /* Force a string copy if the argument name begins with an underscore */
			{
				if (max_len > 0) {
					int hacklen = 17 > max_len ? 17 : max_len;
					argstrcpy2 (++cp, (char *)arg_ptr, hacklen - 1); /* Hack - terminate after 16 characters */
					arg_found = TRUE;
				}
				else if (max_len == 0) {
					arg_found = TRUE;
				}
				break;
			}
			switch ((force_string && *cp == '=') ? STR : getval(cp, &val, isargsep, FALSE))
			{
				case NUM:
					if (max_len > 0) {
						argnumcpy(val, arg_ptr, max_len);
						arg_found = TRUE;
					}
					else if (max_len == 0) {
						arg_found = TRUE;
					}
					break;
				case STR:
					if (max_len > 0) {
						argstrcpy2(++cp, (char *)arg_ptr, max_len - 1);/*max_len of 0 performs no copy at all*/
						arg_found = TRUE;
					}
					else if (max_len == 0) {
						arg_found = TRUE;
					}
#if !CONFIG_EMBEDDED
					else if (max_len == -1) { /* unreachable on embedded */
						argstrcpy(++cp, (char *)arg_ptr);
						arg_found = TRUE;
					}
#endif
					break;
			}
			goto gotit;
		}
gotit:
		/* Skip over current arg */
		while(!isargsep(*args)) args++;

		/* Skip leading white space (catch end of args) */
		while(*args && isargsep(*args)) args++;
	}

	return(arg_found);
}

boolean_t
PE_parse_boot_argn(
	const char	*arg_string,
	void		*arg_ptr,
	int			max_len)
{
	return PE_parse_boot_argn_internal(arg_string, arg_ptr, max_len, FALSE);
}

boolean_t
PE_parse_boot_arg_str(
	const char	*arg_string,
	char		*arg_ptr,
	int			strlen)
{
	return PE_parse_boot_argn_internal(arg_string, arg_ptr, strlen, TRUE);
}

__attribute__((used)) static boolean_t
isargsep(char c)
{
	if (c == ' ' || c == '\0' || c == '\t')
		return (TRUE);
	else
		return (FALSE);
}

__attribute__((used)) static boolean_t
israngesep(char c)
{
	if (isargsep(c) || c == '_' || c == ',')
		return (TRUE);
	else
		return (FALSE);
}

__attribute__((used)) static int
argstrcpy(
	char *from,
	char *to)
{
	int i = 0;

	while (!isargsep(*from)) {
		i++;
		*to++ = *from++;
	}
	*to = 0;
	return(i);
}

__attribute__((used)) static int
argstrcpy2(
	char *from,
	char *to,
	unsigned maxlen)
{
	unsigned int i = 0;

	while (!isargsep(*from) && i < maxlen) {
		i++;
		*to++ = *from++;
	}
	*to = 0;
	return(i);
}

__attribute__((used)) static int argnumcpy(long long val, void *to, unsigned maxlen)
{
	switch (maxlen) {
		case 0:
			/* No write-back, caller just wants to know if arg was found */
			break;
		case 1:
			*(int8_t *)to = val;
			break;
		case 2:
			*(int16_t *)to = val;
			break;
		case 3:
			/* Unlikely in practice */
			((struct i24 *)to)->i24 = val;
			break;
		case 4:
			*(int32_t *)to = val;
			break;
		case 8:
			*(int64_t *)to = val;
			break;
		default:
			*(int32_t *)to = val;
			maxlen = 4;
			break;
	}

	return (int)maxlen;
}

__attribute__((used)) static int
getval(
	char *s,
	long long *val,
	argsep_func_t issep,
	boolean_t skip_equal_sign )
{
	unsigned long long radix, intval;
	unsigned char c;
	int sign = 1;
	boolean_t has_value = FALSE;

	if (*s == '=') {
		s++;
		has_value = TRUE;
	}

	if (has_value || skip_equal_sign) {
		if (*s == '-') {
			sign = -1;
			s++;
		}
		intval = *s++-'0';
		radix = 10;
		if (intval == 0) {
			switch(*s) {

			case 'x':
				radix = 16;
				s++;
				break;

			case 'b':
				radix = 2;
				s++;
				break;

			case '0': case '1': case '2': case '3':
			case '4': case '5': case '6': case '7':
				intval = *s-'0';
				s++;
				radix = 8;
				break;

			default:
				if (!issep(*s))
					return (STR);
			}
                } else if (intval >= radix) {
                    return (STR);
                }
		for(;;) {
                        c = *s++;
                        if (issep(c))
                            break;
                        if ((radix <= 10) &&
                            ((c >= '0') && (c <= ('9' - (10 - radix))))) {
                                c -= '0';
                        } else if ((radix == 16) &&
                                   ((c >= '0') && (c <= '9'))) {
				c -= '0';
                        } else if ((radix == 16) &&
                                   ((c >= 'a') && (c <= 'f'))) {
				c -= 'a' - 10;
                        } else if ((radix == 16) &&
                                   ((c >= 'A') && (c <= 'F'))) {
				c -= 'A' - 10;
                        } else if (c == 'k' || c == 'K') {
				sign *= 1024;
				break;
			} else if (c == 'm' || c == 'M') {
				sign *= 1024 * 1024;
                                break;
			} else if (c == 'g' || c == 'G') {
				sign *= 1024 * 1024 * 1024;
                                break;
			} else {
				return (STR);
                        }
			if (c >= radix)
				return (STR);
			intval *= radix;
			intval += c;
		}
                if (!issep(c) && !issep(*s))
                    return STR;
		*val = intval * sign;
		return (NUM);
	}
	*val = 1;
	return (NUM);
}

boolean_t
PE_imgsrc_mount_supported()
{
	return TRUE;
}

boolean_t
PE_get_default(
	const char	*property_name,
	void		*property_ptr,
	unsigned int max_property)
{
	DTEntry		dte;
	void		**property_data;
	unsigned int property_size;

	/*
	 * Look for the property using the PE DT support.
	 */
	if (kSuccess == DTLookupEntry(NULL, "/defaults", &dte)) {

		/*
		 * We have a /defaults node, look for the named property.
		 */
		if (kSuccess != DTGetProperty(dte, property_name, (void **)&property_data, &property_size))
			return FALSE;

		/*
		 * This would be a fine place to do smart argument size management for 32/64
		 * translation, but for now we'll insist that callers know how big their
		 * default values are.
		 */
		if (property_size > max_property)
			return FALSE;

		/*
		 * Copy back the precisely-sized result.
		 */
		memcpy(property_ptr, property_data, property_size);
		return TRUE;
	}

	/*
	 * Look for the property using I/O Kit's DT support.
	 */
	return IODTGetDefault(property_name, property_ptr, max_property) ? FALSE : TRUE;
}

boolean_t
get_range_bounds(char *c, int64_t *lower, int64_t *upper)
{
	if (c == NULL || lower == NULL || upper == NULL) {
		return FALSE;
	}

	if (NUM != getval(c, lower, israngesep, TRUE)) {
		return FALSE;
	}

	while (*c != '\0') {
		if (*c == '_') {
			break;
		}
		c++;
	}

	if (*c == '_') {
		c++;
		if (NUM != getval(c, upper, israngesep, TRUE)) {
			return FALSE;
		}
	} else {
		return FALSE;
	}
	return TRUE;
}

