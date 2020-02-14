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
typedef  int UCHAR ;
typedef  int /*<<< orphan*/  PVOID ;
typedef  int /*<<< orphan*/  PI2C_CALLBACKS ;
typedef  int INT ;
typedef  int BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  DELAY_HALF () ; 
 int FALSE ; 
 scalar_t__ HIGH ; 
 int /*<<< orphan*/  INFO_ (int /*<<< orphan*/ ,char*,...) ; 
 scalar_t__ LOW ; 
 scalar_t__ READ_SCL () ; 
 scalar_t__ READ_SDA () ; 
 int TRUE ; 
 int /*<<< orphan*/  VIDEOPRT ; 
 int /*<<< orphan*/  WARN_ (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  WRITE_SCL (scalar_t__) ; 
 int /*<<< orphan*/  WRITE_SDA (scalar_t__) ; 

__attribute__((used)) static BOOL
I2CWrite(PVOID HwDeviceExtension, PI2C_CALLBACKS i2c, UCHAR Data)
{
   UCHAR Bit;
   BOOL Ack;

   /* transmit data */
   for (Bit = (1 << 7); Bit != 0; Bit >>= 1)
     {
        WRITE_SCL(LOW);
        WRITE_SDA((Data & Bit) ? HIGH : LOW);
        DELAY_HALF();
        WRITE_SCL(HIGH);
        DELAY_HALF();
     }

   /* get ack */
   WRITE_SCL(LOW);
   WRITE_SDA(HIGH);
   DELAY_HALF();
   WRITE_SCL(HIGH);
   do
     {
        DELAY_HALF();
     }
   while (READ_SCL() != HIGH);
   Ack = (READ_SDA() == LOW);
   DELAY_HALF();

   INFO_(VIDEOPRT, "I2CWrite: %s\n", Ack ? "Ack" : "Nak");
   return Ack;
}

__attribute__((used)) static UCHAR
I2CRead(PVOID HwDeviceExtension, PI2C_CALLBACKS i2c, BOOL Ack)
{
   INT Bit = 0x80;
   UCHAR Data = 0;

   /* pull down SCL and release SDA */
   WRITE_SCL(LOW);
   WRITE_SDA(HIGH);

   /* read byte */
   for (Bit = (1 << 7); Bit != 0; Bit >>= 1)
     {
        WRITE_SCL(LOW);
        DELAY_HALF();
        WRITE_SCL(HIGH);
        DELAY_HALF();
        if (READ_SDA() == HIGH)
          Data |= Bit;
     }

   /* send ack/nak */
   WRITE_SCL(LOW);
   WRITE_SDA(Ack ? LOW : HIGH);
   DELAY_HALF();
   WRITE_SCL(HIGH);
   do
     {
        DELAY_HALF();
     }
   while (READ_SCL() != HIGH);

   return Data;
}

__attribute__((used)) static VOID
I2CStop(PVOID HwDeviceExtension, PI2C_CALLBACKS i2c)
{
   WRITE_SCL(LOW);
   WRITE_SDA(LOW);
   DELAY_HALF();
   WRITE_SCL(HIGH);
   DELAY_HALF();
   WRITE_SDA(HIGH);
}

__attribute__((used)) static BOOL
I2CStart(PVOID HwDeviceExtension, PI2C_CALLBACKS i2c, UCHAR Address)
{
   /* make sure the bus is free */
   if (READ_SDA() == LOW || READ_SCL() == LOW)
     {
        WARN_(VIDEOPRT, "I2CStart: Bus is not free!\n");
        return FALSE;
     }

   /* send address */
   WRITE_SDA(LOW);
   DELAY_HALF();
   if (!I2CWrite(HwDeviceExtension, i2c, Address))
     {
        /* ??release the bus?? */
        I2CStop(HwDeviceExtension, i2c);
        WARN_(VIDEOPRT, "I2CStart: Device not found (Address = 0x%x)\n", Address);
        return FALSE;
     }

   INFO_(VIDEOPRT, "I2CStart: SUCCESS!\n");
   return TRUE;
}

__attribute__((used)) static BOOL
I2CRepStart(PVOID HwDeviceExtension, PI2C_CALLBACKS i2c, UCHAR Address)
{
   /* setup lines for repeated start condition */
   WRITE_SCL(LOW);
   DELAY_HALF();
   WRITE_SDA(HIGH);
   DELAY_HALF();
   WRITE_SCL(HIGH);
   DELAY_HALF();

   return I2CStart(HwDeviceExtension, i2c, Address);
}

