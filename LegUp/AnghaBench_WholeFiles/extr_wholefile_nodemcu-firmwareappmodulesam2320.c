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
typedef  int uint8_t ;
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int uint16_t ;
typedef  int /*<<< orphan*/  nfo ;
typedef  int /*<<< orphan*/  lua_State ;

/* Variables and functions */
 int EIO ; 
 int /*<<< orphan*/  PLATFORM_I2C_DIRECTION_RECEIVER ; 
 int /*<<< orphan*/  PLATFORM_I2C_DIRECTION_TRANSMITTER ; 
 int /*<<< orphan*/  am2320_i2c_addr ; 
 int /*<<< orphan*/  am2320_i2c_id ; 
 int luaL_error (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  lua_pushinteger (int /*<<< orphan*/ *,int) ; 
 int ntohl (int /*<<< orphan*/ ) ; 
 int ntohs (int) ; 
 int /*<<< orphan*/  os_delay_us (int) ; 
 int platform_i2c_recv_byte (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  platform_i2c_send_address (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_i2c_send_byte (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  platform_i2c_send_start (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_i2c_send_stop (int /*<<< orphan*/ ) ; 

__attribute__((used)) static uint16_t crc16(uint8_t *ptr, unsigned int len)
{
    uint16_t	crc =0xFFFF;
    uint8_t	i;

    while(len--) {
	crc ^= *ptr++;
	for(i=0;i<8;i++) {
	    if(crc & 0x01) {
		crc >>= 1;
		crc ^= 0xA001;
	    } else {
		crc >>= 1;
	    }
	}
    }
    return crc;
}

__attribute__((used)) static int _read(uint32_t id, void *buf, uint8_t len, uint8_t off)
{
    int i;
    uint8_t *b = (uint8_t *)buf;
    uint16_t crc;

    // step 1: Wake sensor
    platform_i2c_send_start(id);
    platform_i2c_send_address(id, am2320_i2c_addr, PLATFORM_I2C_DIRECTION_TRANSMITTER);
    os_delay_us(800);
    platform_i2c_send_stop(id);

    // step 2: Send read command
    platform_i2c_send_start(id);
    platform_i2c_send_address(id, am2320_i2c_addr, PLATFORM_I2C_DIRECTION_TRANSMITTER);
    platform_i2c_send_byte(id, 0x03);
    platform_i2c_send_byte(id, off);
    platform_i2c_send_byte(id, len);
    platform_i2c_send_stop(id);

    // step 3: Read the data
    os_delay_us(1500);
    platform_i2c_send_start(id);
    platform_i2c_send_address(id, am2320_i2c_addr, PLATFORM_I2C_DIRECTION_RECEIVER);
    os_delay_us(30);
    for(i=0; i<len+2; i++)
	b[i] = platform_i2c_recv_byte(id,1);
    crc  = platform_i2c_recv_byte(id,1);
    crc |= platform_i2c_recv_byte(id,0) << 8;
    platform_i2c_send_stop(id);

    if(b[0] != 0x3 || b[1] != len)
	return -EIO;
    if(crc != crc16(b,len+2))
	return -EIO;
    return 0;
}

__attribute__((used)) static int am2320_setup(lua_State* L)
{
    int ret;
    struct {
    	uint8_t  cmd;
    	uint8_t  len;
	uint16_t model;
	uint8_t	 version;
	uint32_t id;
    } nfo;

    os_delay_us(1500); // give some time to settle things down
    ret = _read(am2320_i2c_id, &nfo, sizeof(nfo)-2, 0x08);
    if(ret)
        return luaL_error(L, "transmission error");

    lua_pushinteger(L, ntohs(nfo.model));
    lua_pushinteger(L, nfo.version);
    lua_pushinteger(L, ntohl(nfo.id));
    return 3;
}

__attribute__((used)) static int am2320_read(lua_State* L)
{
    int ret;
    struct {
    	uint8_t  cmd;
    	uint8_t  len;
	uint16_t rh;
	uint16_t temp;
    } nfo;

    ret = _read(am2320_i2c_id, &nfo, sizeof(nfo)-2, 0x00);
    if(ret)
        return luaL_error(L, "transmission error");

    ret = ntohs(nfo.temp);
    if(ret & 0x8000)
    	ret = -(ret & 0x7fff);

    lua_pushinteger(L, ntohs(nfo.rh));
    lua_pushinteger(L, ret);
    return 2;
}

