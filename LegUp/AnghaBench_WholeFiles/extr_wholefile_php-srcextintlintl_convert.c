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
typedef  int /*<<< orphan*/  zend_string ;
typedef  size_t int32_t ;
typedef  scalar_t__ UErrorCode ;
typedef  scalar_t__ UChar ;

/* Variables and functions */
 size_t INT32_MAX ; 
 scalar_t__ U_BUFFER_OVERFLOW_ERROR ; 
 scalar_t__ U_FAILURE (scalar_t__) ; 
 scalar_t__ U_STRING_NOT_TERMINATED_WARNING ; 
 scalar_t__ U_ZERO_ERROR ; 
 scalar_t__* ZSTR_VAL (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  efree (scalar_t__*) ; 
 scalar_t__* eumalloc (size_t) ; 
 int /*<<< orphan*/  u_strFromUTF8 (scalar_t__*,size_t,size_t*,char const*,size_t,scalar_t__*) ; 
 int /*<<< orphan*/  u_strToUTF8 (scalar_t__*,size_t,size_t*,scalar_t__ const*,size_t,scalar_t__*) ; 
 int /*<<< orphan*/ * zend_string_alloc (size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  zend_string_efree (int /*<<< orphan*/ *) ; 

void intl_convert_utf8_to_utf16(
	UChar**     target, int32_t* target_len,
	const char* src,    size_t  src_len,
	UErrorCode* status )
{
	UChar*      dst_buf = NULL;
	int32_t     dst_len = 0;

	/* If *target is NULL determine required destination buffer size (pre-flighting).
	 * Otherwise, attempt to convert source string; if *target buffer is not large enough
	 * it will be resized appropriately.
	 */
	*status = U_ZERO_ERROR;

	if(src_len > INT32_MAX) {
		/* we can not fit this string */
		*status = U_BUFFER_OVERFLOW_ERROR;
		return;
	}

	u_strFromUTF8( *target, *target_len, &dst_len, src, (int32_t)src_len, status );

	if( *status == U_ZERO_ERROR )
	{
		/* String is converted successfully */
		(*target)[dst_len] = 0;
		*target_len = dst_len;
		return;
	}

	/* Bail out if an unexpected error occurred.
	 * (U_BUFFER_OVERFLOW_ERROR means that *target buffer is not large enough).
	 * (U_STRING_NOT_TERMINATED_WARNING usually means that the input string is empty).
	 */
	if( *status != U_BUFFER_OVERFLOW_ERROR && *status != U_STRING_NOT_TERMINATED_WARNING )
		return;

	/* Allocate memory for the destination buffer (it will be zero-terminated). */
	dst_buf = eumalloc( dst_len + 1 );

	/* Convert source string from UTF-8 to UTF-16. */
	*status = U_ZERO_ERROR;
	u_strFromUTF8( dst_buf, dst_len+1, NULL, src, src_len, status );
	if( U_FAILURE( *status ) )
	{
		efree( dst_buf );
		return;
	}

	dst_buf[dst_len] = 0;

	if( *target )
		efree( *target );

	*target     = dst_buf;
	*target_len = dst_len;
}

zend_string* intl_convert_utf16_to_utf8(
	const UChar* src,    int32_t  src_len,
	UErrorCode*  status )
{
	zend_string* dst;
	int32_t      dst_len;

	/* Determine required destination buffer size (pre-flighting). */
	*status = U_ZERO_ERROR;
	u_strToUTF8( NULL, 0, &dst_len, src, src_len, status );

	/* Bail out if an unexpected error occurred.
	 * (U_BUFFER_OVERFLOW_ERROR means that *target buffer is not large enough).
	 * (U_STRING_NOT_TERMINATED_WARNING usually means that the input string is empty).
	 */
	if( *status != U_BUFFER_OVERFLOW_ERROR && *status != U_STRING_NOT_TERMINATED_WARNING )
		return NULL;

	/* Allocate memory for the destination buffer (it will be zero-terminated). */
	dst = zend_string_alloc(dst_len, 0);

	/* Convert source string from UTF-8 to UTF-16. */
	*status = U_ZERO_ERROR;
	u_strToUTF8( ZSTR_VAL(dst), dst_len, NULL, src, src_len, status );
	if( U_FAILURE( *status ) )
	{
		zend_string_efree(dst);
		return NULL;
	}

	/* U_STRING_NOT_TERMINATED_WARNING is OK for us => reset 'status'. */
	*status = U_ZERO_ERROR;

	ZSTR_VAL(dst)[dst_len] = 0;
	return dst;
}

