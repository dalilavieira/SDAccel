#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  zend_bool ;
struct TYPE_8__ {int l; char* member_0; int /*<<< orphan*/  member_1; int /*<<< orphan*/  s; } ;
struct TYPE_7__ {char* member_0; int member_1; char* s; int /*<<< orphan*/  l; } ;
typedef  TYPE_1__ const MYSQLND_STRING ;
typedef  TYPE_2__ const MYSQLND_CSTRING ;

/* Variables and functions */
 int /*<<< orphan*/  memcpy (char*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ mnd_pemalloc (int,int /*<<< orphan*/  const) ; 

__attribute__((used)) static inline MYSQLND_STRING mnd_dup_cstring(const MYSQLND_CSTRING str, const zend_bool persistent)
{
	const MYSQLND_STRING ret = {(char*) mnd_pemalloc(str.l + 1, persistent), str.l};
	if (ret.s) {
		memcpy(ret.s, str.s, str.l);
		ret.s[str.l] = '\0';
	}
	return ret;
}

__attribute__((used)) static inline MYSQLND_CSTRING mnd_str2c(const MYSQLND_STRING str)
{
	const MYSQLND_CSTRING ret = {str.s, str.l};
	return ret;
}

__attribute__((used)) static inline void DBG_INF(const char * const msg) {}

__attribute__((used)) static inline void DBG_ERR(const char * const msg) {}

__attribute__((used)) static inline void DBG_INF_FMT(const char * const format, ...) {}

__attribute__((used)) static inline void DBG_ERR_FMT(const char * const format, ...) {}

__attribute__((used)) static inline void DBG_ENTER(const char * const func_name) {}

__attribute__((used)) static inline void TRACE_ALLOC_INF(const char * const msg) {}

__attribute__((used)) static inline void TRACE_ALLOC_ERR(const char * const msg) {}

__attribute__((used)) static inline void TRACE_ALLOC_INF_FMT(const char * const format, ...) {}

__attribute__((used)) static inline void TRACE_ALLOC_ERR_FMT(const char * const format, ...) {}

__attribute__((used)) static inline void TRACE_ALLOC_ENTER(const char * const func_name) {}

