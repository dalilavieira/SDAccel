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
typedef  int UINT ;
typedef  int /*<<< orphan*/  DWORD ;
typedef  int /*<<< orphan*/  DSTATUS ;
typedef  int /*<<< orphan*/  DRESULT ;
typedef  int BYTE ;

/* Variables and functions */
#define  CTRL_SYNC 129 
#define  CTRL_TRIM 128 
 int /*<<< orphan*/  RES_ERROR ; 
 int /*<<< orphan*/  RES_OK ; 
 int /*<<< orphan*/  RES_PARERR ; 
 int /*<<< orphan*/  STA_NOINIT ; 
 int /*<<< orphan*/  m_status ; 
 scalar_t__ platform_sdcard_init (int,int) ; 
 int /*<<< orphan*/  platform_sdcard_read_block (int,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  platform_sdcard_read_blocks (int,int /*<<< orphan*/ ,int,int*) ; 
 int /*<<< orphan*/  platform_sdcard_write_block (int,int /*<<< orphan*/ ,int const*) ; 
 int /*<<< orphan*/  platform_sdcard_write_blocks (int,int /*<<< orphan*/ ,int,int const*) ; 

DSTATUS disk_status (
	BYTE pdrv		/* Physical drive nmuber to identify the drive */
)
{
  return m_status;
}

DSTATUS disk_initialize (
	BYTE pdrv				/* Physical drive nmuber to identify the drive */
)
{
  int result;

  if (platform_sdcard_init( 1, pdrv )) {
    m_status &= ~STA_NOINIT;
  }

  return m_status;
}

DRESULT disk_read (
	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
	BYTE *buff,		/* Data buffer to store read data */
	DWORD sector,	/* Sector address in LBA */
	UINT count		/* Number of sectors to read */
)
{
  if (count == 1) {
    if (! platform_sdcard_read_block( pdrv, sector, buff )) {
      return RES_ERROR;
    }
  } else {
    if (! platform_sdcard_read_blocks( pdrv, sector, count, buff )) {
      return RES_ERROR;
    }
  }

  return RES_OK;
}

DRESULT disk_write (
	BYTE pdrv,			/* Physical drive nmuber to identify the drive */
	const BYTE *buff,	/* Data to be written */
	DWORD sector,		/* Sector address in LBA */
	UINT count			/* Number of sectors to write */
)
{
  if (count == 1) {
    if (! platform_sdcard_write_block( pdrv, sector, buff )) {
      return RES_ERROR;
    }
  } else {
    if (! platform_sdcard_write_blocks( pdrv, sector, count, buff )) {
      return RES_ERROR;
    }
  }

  return RES_OK;
}

DRESULT disk_ioctl (
	BYTE pdrv,		/* Physical drive nmuber (0..) */
	BYTE cmd,		/* Control code */
	void *buff		/* Buffer to send/receive control data */
)
{
  switch (cmd) {
  case CTRL_TRIM:    /* no-op */
  case CTRL_SYNC:    /* no-op */
    return RES_OK;

  default:           /* anything else throws parameter error */
    return RES_PARERR;
  }
}

