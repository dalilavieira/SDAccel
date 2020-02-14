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
typedef  int USHORT ;
typedef  int ULONG ;
typedef  int UCHAR ;
typedef  int* PUSHORT ;
typedef  int /*<<< orphan*/  PUCHAR ;
typedef  char* PCSTR ;
typedef  int /*<<< orphan*/  BOOLEAN ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 scalar_t__ I2C_IO_BASE ; 
 int READ_PORT_UCHAR (int /*<<< orphan*/ ) ; 
 int READ_PORT_USHORT (int*) ; 
 int /*<<< orphan*/  StallExecutionProcessor (int) ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  WRITE_PORT_UCHAR (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  WRITE_PORT_USHORT (int*,int) ; 
 int strlen (char*) ; 

__attribute__((used)) static BOOLEAN
WriteToSMBus(UCHAR Address, UCHAR bRegister, UCHAR Size, ULONG Data_to_smbus)
{
  int nRetriesToLive=50;

  while(READ_PORT_USHORT((PUSHORT) (I2C_IO_BASE+0)) & 0x0800)
  {
    ;  // Franz's spin while bus busy with any master traffic
  }

  while(nRetriesToLive--)
  {
    UCHAR b;
    unsigned int temp;

    WRITE_PORT_UCHAR((PUCHAR)(I2C_IO_BASE + 4), (Address << 1) | 0);
    WRITE_PORT_UCHAR((PUCHAR)(I2C_IO_BASE + 8), bRegister);

    switch (Size)
    {
      case 4:
        WRITE_PORT_UCHAR((PUCHAR) (I2C_IO_BASE + 9), Data_to_smbus & 0xff);
        WRITE_PORT_UCHAR((PUCHAR) (I2C_IO_BASE + 9), (Data_to_smbus >> 8) & 0xff );
        WRITE_PORT_UCHAR((PUCHAR) (I2C_IO_BASE + 9), (Data_to_smbus >> 16) & 0xff );
        WRITE_PORT_UCHAR((PUCHAR) (I2C_IO_BASE + 9), (Data_to_smbus >> 24) & 0xff );
        WRITE_PORT_USHORT((PUSHORT) (I2C_IO_BASE + 6), 4);
        break;
      case 2:
        WRITE_PORT_USHORT((PUSHORT) (I2C_IO_BASE + 6), Data_to_smbus&0xffff);
        break;
      default:    // 1
        WRITE_PORT_USHORT((PUSHORT) (I2C_IO_BASE + 6), Data_to_smbus&0xff);
        break;
    }


    temp = READ_PORT_USHORT((PUSHORT) (I2C_IO_BASE + 0));
    WRITE_PORT_USHORT((PUSHORT) (I2C_IO_BASE + 0), temp);  // clear down all preexisting errors

    switch (Size)
    {
      case 4:
        WRITE_PORT_UCHAR((PUCHAR) (I2C_IO_BASE + 2), 0x1d);    // DWORD modus
        break;
      case 2:
        WRITE_PORT_UCHAR((PUCHAR) (I2C_IO_BASE + 2), 0x1b);    // WORD modus
        break;
      default:    // 1
        WRITE_PORT_UCHAR((PUCHAR) (I2C_IO_BASE + 2), 0x1a);    // BYTE modus
        break;
    }

    b = 0;

    while( (b&0x36)==0 )
    {
      b=READ_PORT_UCHAR((PUCHAR) (I2C_IO_BASE + 0));
    }

    if ((b&0x10) != 0)
    {
      return TRUE;
    }

    StallExecutionProcessor(1);
  }

  return FALSE;
}

__attribute__((used)) static BOOLEAN
ReadfromSMBus(UCHAR Address, UCHAR bRegister, UCHAR Size, ULONG *Data_to_smbus)
{
  int nRetriesToLive=50;

  while (0 != (READ_PORT_USHORT((PUSHORT) (I2C_IO_BASE + 0)) & 0x0800))
    {
      ;  /* Franz's spin while bus busy with any master traffic */
    }

  while (0 != nRetriesToLive--)
    {
      UCHAR b;
      int temp;

      WRITE_PORT_UCHAR((PUCHAR) (I2C_IO_BASE + 4), (Address << 1) | 1);
      WRITE_PORT_UCHAR((PUCHAR) (I2C_IO_BASE + 8), bRegister);

      temp = READ_PORT_USHORT((USHORT *) (I2C_IO_BASE + 0));
      WRITE_PORT_USHORT((PUSHORT) (I2C_IO_BASE + 0), temp);  /* clear down all preexisting errors */

      switch (Size)
        {
          case 4:
            WRITE_PORT_UCHAR((PUCHAR) (I2C_IO_BASE + 2), 0x0d);      /* DWORD modus ? */
            break;
          case 2:
            WRITE_PORT_UCHAR((PUCHAR) (I2C_IO_BASE + 2), 0x0b);      /* WORD modus */
            break;
          default:
            WRITE_PORT_UCHAR((PUCHAR) (I2C_IO_BASE + 2), 0x0a);      // BYTE
            break;
        }

      b = 0;

      while (0 == (b & 0x36))
        {
          b = READ_PORT_UCHAR((PUCHAR) (I2C_IO_BASE + 0));
        }

      if (0 != (b & 0x24))
        {
          /* printf("I2CTransmitByteGetReturn error %x\n", b); */
        }

      if(0 == (b & 0x10))
        {
          /* printf("I2CTransmitByteGetReturn no complete, retry\n"); */
        }
      else
        {
          switch (Size)
            {
              case 4:
                READ_PORT_UCHAR((PUCHAR) (I2C_IO_BASE + 6));
                READ_PORT_UCHAR((PUCHAR) (I2C_IO_BASE + 9));
                READ_PORT_UCHAR((PUCHAR) (I2C_IO_BASE + 9));
                READ_PORT_UCHAR((PUCHAR) (I2C_IO_BASE + 9));
                READ_PORT_UCHAR((PUCHAR) (I2C_IO_BASE + 9));
                break;
              case 2:
                *Data_to_smbus = READ_PORT_USHORT((USHORT *) (I2C_IO_BASE + 6));
                break;
              default:
                *Data_to_smbus = READ_PORT_UCHAR((PUCHAR) (I2C_IO_BASE + 6));
                break;
            }


          return TRUE;
        }
    }

  return FALSE;
}

BOOLEAN
I2CTransmitByteGetReturn(UCHAR bPicAddressI2cFormat, UCHAR bDataToWrite, ULONG *Return)
{
  return ReadfromSMBus(bPicAddressI2cFormat, bDataToWrite, 1, Return);
}

__attribute__((used)) static BOOLEAN
I2CTransmitWord(UCHAR bPicAddressI2cFormat, USHORT wDataToWrite)
{
  return WriteToSMBus(bPicAddressI2cFormat,(wDataToWrite>>8)&0xff,1,(wDataToWrite&0xff));
}

__attribute__((used)) static void
I2cSetFrontpanelLed(UCHAR b)
{
  I2CTransmitWord( 0x10, 0x800 | b);  // sequencing thanks to Jarin the Penguin!
  I2CTransmitWord( 0x10, 0x701);
}

void
XboxSetLED(PCSTR pattern) {
    const char *x = pattern;
    int r, g;

    if(strlen(pattern) == 4) {
        r = g = 0;
        while (*x) {
            r *= 2;
            g *= 2;
            switch (*x) {
                case 'r':
                    r++;
                    break;
                case 'g':
                    g++;
                    break;
                case 'o':
                    r++;
                    g++;
                    break;
            }
            x++;
        }
        I2cSetFrontpanelLed(((r<<4) & 0xF0) + (g & 0xF));
    }
}

