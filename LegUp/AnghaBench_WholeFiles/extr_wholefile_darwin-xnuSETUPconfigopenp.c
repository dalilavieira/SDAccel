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
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int flgs ; 
 scalar_t__ fopen (char*,char const*) ; 
 char const* ftyp ; 
 scalar_t__ fvalue ; 
 int mod ; 
 scalar_t__ open (char*,int,int) ; 
 scalar_t__ searchp (char const*,char*,char*,int (*) (char*)) ; 
 scalar_t__ value ; 

__attribute__((used)) static int
func(char *fnam)
{
	value = open (fnam,flgs,mod);
	return (value < 0);
}

__attribute__((used)) static int
ffunc(char *fnam)
{
	fvalue = fopen (fnam,ftyp);
	return (fvalue == 0);
}

int
openp(const char *fpath, char *file, char *complete, int flags, int mode)
{
	flgs = flags;
	mod = mode;
	if (searchp(fpath,file,complete,func) < 0)  return (-1);
	return (value);
}

FILE *
fopenp(const char *fpath, char *file, char *complete, const char *ftype)
{
	ftyp = ftype;
	if (searchp(fpath,file,complete,ffunc) < 0)  return (0);
	return (fvalue);
}

