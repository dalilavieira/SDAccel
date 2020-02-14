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

/* Variables and functions */
 size_t ZSTR_LEN (int /*<<< orphan*/  const*) ; 
 scalar_t__ ZSTR_VAL (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/ * php_base64_decode_ex (unsigned char const*,size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * php_base64_encode (unsigned char const*,size_t) ; 

__attribute__((used)) static inline zend_string *php_base64_encode_str(const zend_string *str) {
	return php_base64_encode((const unsigned char*)(ZSTR_VAL(str)), ZSTR_LEN(str));
}

__attribute__((used)) static inline zend_string *php_base64_decode(const unsigned char *str, size_t len) {
	return php_base64_decode_ex(str, len, 0);
}

__attribute__((used)) static inline zend_string *php_base64_decode_str(const zend_string *str) {
	return php_base64_decode_ex((const unsigned char*)(ZSTR_VAL(str)), ZSTR_LEN(str), 0);
}

