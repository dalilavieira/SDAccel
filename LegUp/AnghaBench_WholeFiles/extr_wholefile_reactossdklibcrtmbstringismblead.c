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
struct TYPE_2__ {int* mbctype; } ;

/* Variables and functions */
 int _M1 ; 
 TYPE_1__* get_mbcinfo () ; 

int _ismbblead(unsigned int c)
{
  return (get_mbcinfo()->mbctype[(c&0xff) + 1] & _M1) != 0;
}

int _ismbslead( const unsigned char *start, const unsigned char *str)
{
  int lead = 0;

  /* Lead bytes can also be trail bytes so we need to analyse the string
   */
  while (start <= str)
  {
    if (!*start)
      return 0;
    lead = !lead && _ismbblead(*start);
    start++;
  }

  return lead ? -1 : 0;
}

unsigned char *__p__mbctype(void)
{
  return get_mbcinfo()->mbctype;
}

