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
typedef  int /*<<< orphan*/  VOID ;
typedef  int UINT ;
typedef  int DWORD ;
typedef  int /*<<< orphan*/  DSTATUS ;
typedef  int /*<<< orphan*/  DRESULT ;
typedef  scalar_t__ BYTE ;

/* Variables and functions */
#define  CTRL_SYNC 132 
#define  GET_BLOCK_SIZE 131 
#define  GET_SECTOR_COUNT 130 
#define  GET_SECTOR_SIZE 129 
 int /*<<< orphan*/  RES_ERROR ; 
 int /*<<< orphan*/  RES_OK ; 
 int /*<<< orphan*/  RES_PARERR ; 
 int /*<<< orphan*/  SEEK_END ; 
 int /*<<< orphan*/  SEEK_SET ; 
#define  SET_SECTOR_COUNT 128 
 int /*<<< orphan*/  STA_NOINIT ; 
 int /*<<< orphan*/ ** driveHandle ; 
 scalar_t__ driveHandleCount ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fflush (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (char const*,char*) ; 
 int fread (scalar_t__*,int,int,int /*<<< orphan*/ *) ; 
 scalar_t__ fseek (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int ftell (int /*<<< orphan*/ *) ; 
 int fwrite (void*,int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  printf (char*) ; 
 int* sectorCount ; 

DSTATUS disk_openimage(BYTE pdrv, const char* imageFileName)
{
    if (pdrv < driveHandleCount)
    {
        if (driveHandle[0] != NULL)
            return 0;

        driveHandle[0] = fopen(imageFileName, "r+b");
        if (!driveHandle[0])
        {
            driveHandle[0] = fopen(imageFileName, "w+b");
        }

        if (driveHandle[0] != NULL)
            return 0;
    }
    return STA_NOINIT;
}

VOID disk_cleanup(
    BYTE pdrv		/* Physical drive nmuber (0..) */
    )
{
    if (pdrv < driveHandleCount)
    {
        if (driveHandle[pdrv] != NULL)
        {
            fclose(driveHandle[pdrv]);
            driveHandle[pdrv] = NULL;
        }
    }
}

DSTATUS disk_initialize(
    BYTE pdrv        /* Physical drive nmuber (0..) */
    )
{
    if (pdrv == 0) /* only one drive (image file) supported atm. */
    {
        return 0;
    }
    return STA_NOINIT;
}

DSTATUS disk_status(
    BYTE pdrv		/* Physical drive nmuber (0..) */
    )
{
    if (pdrv < driveHandleCount)
    {
        if (driveHandle[pdrv] != NULL)
            return 0;
    }
    return STA_NOINIT;
}

DRESULT disk_read(
    BYTE pdrv,		/* Physical drive nmuber (0..) */
    BYTE *buff,		/* Data buffer to store read data */
    DWORD sector,	/* Sector address (LBA) */
    UINT count		/* Number of sectors to read (1..128) */
    )
{
    DWORD result;

    if (pdrv < driveHandleCount)
    {
        if (driveHandle[pdrv] != NULL)
        {
            if (fseek(driveHandle[pdrv], sector * 512, SEEK_SET))
                return RES_ERROR;

            result = fread(buff, 512, count, driveHandle[pdrv]);

            if (result != count)
                return RES_ERROR;

            return RES_OK;
        }
    }

    return RES_PARERR;
}

DRESULT disk_write(
    BYTE pdrv,			/* Physical drive nmuber (0..) */
    const BYTE *buff,	/* Data to be written */
    DWORD sector,		/* Sector address (LBA) */
    UINT count			/* Number of sectors to write (1..128) */
    )
{
    DWORD result;

    if (pdrv < driveHandleCount)
    {
        if (driveHandle[pdrv] != NULL)
        {
            if (fseek(driveHandle[pdrv], sector * 512, SEEK_SET))
                return RES_ERROR;

            result = fwrite(buff, 512, count, driveHandle[pdrv]);

            if (result != count)
                return RES_ERROR;

            return RES_OK;
        }
    }

    return RES_PARERR;
}

DRESULT disk_ioctl(
    BYTE pdrv,		/* Physical drive nmuber (0..) */
    BYTE cmd,		/* Control code */
    void *buff		/* Buffer to send/receive control data */
    )
{
    if (pdrv < driveHandleCount)
    {
        if (driveHandle[pdrv] != NULL)
        {
            switch (cmd)
            {
            case CTRL_SYNC:
                fflush(driveHandle[pdrv]);
                return RES_OK;
            case GET_SECTOR_SIZE:
                *(DWORD*)buff = 512;
                return RES_OK;
            case GET_BLOCK_SIZE:
                *(DWORD*)buff = 512;
                return RES_OK;
            case GET_SECTOR_COUNT:
            {
                if (sectorCount[pdrv] <= 0)
                {
                    if (fseek(driveHandle[pdrv], 0, SEEK_END))
                        printf("fseek failed!\n");
                    else
                        sectorCount[pdrv] = ftell(driveHandle[pdrv]) / 512;
                }

                *(DWORD*)buff = sectorCount[pdrv];
                return RES_OK;
            }
            case SET_SECTOR_COUNT:
            {
                int count = *(DWORD*)buff;
                long size;

                sectorCount[pdrv] = count;

                fseek(driveHandle[pdrv], 0, SEEK_END);
                size = ftell(driveHandle[pdrv]) / 512;

                if (size < count)
                {
                    if (fseek(driveHandle[pdrv], count * 512 - 1, SEEK_SET))
                        return RES_ERROR;

                    fwrite(buff, 1, 1, driveHandle[pdrv]);

                    return RES_OK;
                }
                else
                {
                    // SHRINKING NOT IMPLEMENTED
                    return RES_OK;
                }
            }
            }
        }
    }

    return RES_PARERR;
}

