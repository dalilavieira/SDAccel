#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int wchar_t ;
struct TYPE_2__ {int (* uni2char ) (int const,unsigned char*,int) ;scalar_t__ (* char2uni ) (int /*<<< orphan*/  const,int,int*) ;} ;
typedef  int /*<<< orphan*/  PUCHAR ;

/* Variables and functions */
 int ENAMETOOLONG ; 
 TYPE_1__* p_nls ; 
 int stub1 (int const,unsigned char*,int) ; 
 int stub2 (int const,unsigned char*,int) ; 
 scalar_t__ stub3 (int /*<<< orphan*/  const,int,int*) ; 

__attribute__((used)) static int uni2char(const wchar_t uni,
		    unsigned char *out, int boundlen)
{
	if (boundlen <= 0)
		return -ENAMETOOLONG;

	if ((uni & 0xffaf) == 0x040e || (uni & 0xffce) == 0x254c) {
		/* koi8-ru and koi8-u differ only on two characters */
		if (uni == 0x040e)
			return 0xbe;
		else if (uni == 0x045e)
			return 0xae;
		else if (uni == 0x255d || uni == 0x256c)
			return 0;
		else
			return p_nls->uni2char(uni, out, boundlen);
	}
	else
		/* fast path */
		return p_nls->uni2char(uni, out, boundlen);
}

__attribute__((used)) static int char2uni(const unsigned char *rawstring, int boundlen,
		    wchar_t *uni)
{
	int n;

	if ((*rawstring & 0xef) != 0xae) {
		/* koi8-ru and koi8-u differ only on two characters */
		*uni = (*rawstring & 0x10) ? 0x040e : 0x045e;
		return 1;
	}

	n = (int)(p_nls->char2uni((const PUCHAR)rawstring, boundlen,uni));
	return n;
}

