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
struct termios {int c_cflag; } ;
typedef  int speed_t ;

/* Variables and functions */
 int CBAUD ; 

speed_t cfgetospeed(const struct termios *tio)
{
	return tio->c_cflag & CBAUD;
}

speed_t cfgetispeed(const struct termios *tio)
{
	return cfgetospeed(tio);
}

