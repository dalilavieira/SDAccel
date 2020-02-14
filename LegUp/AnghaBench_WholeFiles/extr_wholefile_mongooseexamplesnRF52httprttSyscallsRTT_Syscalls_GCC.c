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
struct _reent {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  SEGGER_RTT_Write (int /*<<< orphan*/ ,char*,int) ; 

int _write(int file, char *ptr, int len) {
  (void) file;  /* Not used, avoid warning */
  SEGGER_RTT_Write(0, ptr, len);
  return len;
}

int _write_r(struct _reent *r, int file, char *ptr, int len) {
  (void) file;  /* Not used, avoid warning */
  (void) r;  /* Not used, avoid warning */
  SEGGER_RTT_Write(0, ptr, len);
  return len;
}

