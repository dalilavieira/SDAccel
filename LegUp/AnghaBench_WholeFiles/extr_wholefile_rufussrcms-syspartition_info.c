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
 int write_data (int /*<<< orphan*/ *,int,unsigned char*,int) ; 

int write_partition_number_of_heads(FILE *fp, int iHeads)
{
   unsigned char aucBuf[2];
   unsigned short s = (unsigned short) iHeads;

   if(!s)
      return 0;
   /* Converting a number like this is not necessary as long as we are on
      i386 compatible CPUs, however, the following code might make the program
      more portable... */
   aucBuf[0] = (unsigned char)(s & 0xff);
   aucBuf[1] = (unsigned char)((s & 0xff00) >> 8);
   return write_data(fp, 0x1a, aucBuf, 2);
}

int write_partition_start_sector_number(FILE *fp, int iStartSector)
{
   unsigned char aucBuf[4];
   unsigned long l = (unsigned long)iStartSector;

   if(!l)
      return 0;
   /* Converting a number like this is not necessary as long as we are on
      i386 compatible CPUs, however, the following code might make the program
      more portable... */
   aucBuf[0] = (unsigned char)(l & 0xff);
   aucBuf[1] = (unsigned char)((l & 0xff00) >> 8);
   aucBuf[2] = (unsigned char)((l & 0xff0000) >> 16);
   aucBuf[3] = (unsigned char)((l & 0xff000000) >> 24);
   return write_data(fp, 0x1c, aucBuf, 4);
}

int write_partition_physical_disk_drive_id_fat32(FILE *fp)
{
   unsigned char ucId = 0x80; /* C: */

   return write_data(fp, 0x40, &ucId, 1);
}

int write_partition_physical_disk_drive_id_fat16(FILE *fp)
{
   unsigned char ucId = 0x80; /* C: */

   return write_data(fp, 0x24, &ucId, 1);
}

