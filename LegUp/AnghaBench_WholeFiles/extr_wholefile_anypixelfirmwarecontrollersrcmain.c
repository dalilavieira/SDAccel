#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_5__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int uint32_t ;
typedef  int uint16_t ;
typedef  int /*<<< orphan*/  u16_t ;
struct udp_pcb {int dummy; } ;
struct pbuf {int* payload; } ;
struct ip_addr {int dummy; } ;
struct TYPE_6__ {int type; int* payload; int param1; } ;
struct TYPE_8__ {char* a; TYPE_1__ s; } ;
typedef  TYPE_3__ ledPacket_type ;
struct TYPE_7__ {int* payload; int type; int param1; } ;
struct TYPE_9__ {char* a; TYPE_2__ s; int /*<<< orphan*/  ua; } ;

/* Variables and functions */
 scalar_t__ BL_MODE_ACTIVE ; 
 scalar_t__ BL_MODE_INACTIVE ; 
 scalar_t__ BL_MODE_WAITING ; 
 int /*<<< orphan*/  BUTTONS_Config () ; 
 int BUTTONS_Read_All () ; 
 int /*<<< orphan*/  CONFIG_pins (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DEBUGPIN_CLR (int) ; 
 int /*<<< orphan*/  DEBUGPIN_NUM ; 
 int /*<<< orphan*/  DEBUGPIN_SET (int) ; 
 int /*<<< orphan*/  DEBUGPIN_TGL (int) ; 
 void Delay (int) ; 
 scalar_t__ ERR_OK ; 
 int /*<<< orphan*/  ETH_BSP_Config () ; 
 scalar_t__ ETH_CheckFrameReceived () ; 
 int /*<<< orphan*/  IP4_ADDR (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  IP_ADDR0 ; 
 int /*<<< orphan*/  IP_ADDR1 ; 
 int /*<<< orphan*/  IP_ADDR2 ; 
 int /*<<< orphan*/  IP_ADDR_ANY ; 
 int IP_lastOctet ; 
 int LED_PACKET_LEN ; 
 int /*<<< orphan*/  LWIP_DEBUGF (int /*<<< orphan*/ ,char*) ; 
 scalar_t__ LocalTime ; 
 int /*<<< orphan*/  LwIP_Init () ; 
 int /*<<< orphan*/  LwIP_Periodic_Handle (scalar_t__) ; 
 int /*<<< orphan*/  LwIP_Pkt_Handle () ; 
 int /*<<< orphan*/  NVIC_PriorityGroupConfig (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NVIC_PriorityGroup_4 ; 
 int /*<<< orphan*/  NVIC_SystemReset () ; 
#define  PANEL_NE 143 
#define  PANEL_NW 142 
#define  PANEL_SE 141 
#define  PANEL_SW 140 
 int /*<<< orphan*/  PBUF_RAM ; 
 int /*<<< orphan*/  PBUF_TRANSPORT ; 
 int /*<<< orphan*/  PIN_Config () ; 
 int /*<<< orphan*/  PIN_High (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PIN_Low (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PIN_Num (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int PIN_State (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
#define  PKT_TYPE_8BIT_CAL 139 
#define  PKT_TYPE_8BIT_RAW 138 
 int PKT_TYPE_BL_ERASE_FLASH ; 
#define  PKT_TYPE_BL_INIT 137 
 int PKT_TYPE_BL_READ_BLOCK ; 
 int PKT_TYPE_BL_UNLOCK_FLASH ; 
 int PKT_TYPE_BL_WRITE_BLOCK ; 
#define  PKT_TYPE_DOTCORRECT_PACK12 136 
#define  PKT_TYPE_DOTCORRECT_PACK6 135 
#define  PKT_TYPE_DOTCORRECT_PACK8 134 
#define  PKT_TYPE_FAN_CONFIG 133 
#define  PKT_TYPE_GET_LOOKUP 132 
#define  PKT_TYPE_GSVALS 131 
#define  PKT_TYPE_REBOOT 130 
#define  PKT_TYPE_RELAY_CTRL 129 
#define  PKT_TYPE_SET_LOOKUP 128 
 int POWER_ROW ; 
 int /*<<< orphan*/  PWRCTRL_NUM_PINS ; 
 int /*<<< orphan*/  PWR_CTRL_AC_0 ; 
 int /*<<< orphan*/  PWR_CTRL_AC_1 ; 
 int /*<<< orphan*/  PWR_MON_0_0 ; 
 int /*<<< orphan*/  PWR_MON_0_1 ; 
 int /*<<< orphan*/  PWR_MON_0_2 ; 
 int /*<<< orphan*/  PWR_MON_1_0 ; 
 int /*<<< orphan*/  PWR_MON_1_1 ; 
 int /*<<< orphan*/  PWR_MON_1_2 ; 
 int /*<<< orphan*/  PWR_MON_AC_0 ; 
 int /*<<< orphan*/  PWR_MON_AC_1 ; 
 scalar_t__ SYSTEMTICK_PERIOD_MS ; 
 int /*<<< orphan*/  UART_Config (int /*<<< orphan*/ *) ; 
 int UART_RX_frame_available (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  UART_RX_read (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  UART_SendBytes (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  UDP_DEBUG ; 
 int USART_NE ; 
 int USART_NW ; 
 int USART_SE ; 
 int USART_SW ; 
 scalar_t__ bootloaderMode ; 
 int* buttonpacket ; 
 scalar_t__* fan_duty ; 
 scalar_t__* fan_intercept ; 
 scalar_t__* fan_min ; 
 int* fan_mode ; 
 scalar_t__* fan_setpoint ; 
 int* fan_slope ; 
 int** fan_tach ; 
 int global_column ; 
 int /*<<< orphan*/ * global_pcb ; 
 int global_row ; 
 scalar_t__ lastButtonPacketTime ; 
 scalar_t__ lastPacketTime ; 
 scalar_t__ lastStatusPacketTime ; 
 scalar_t__ lastUDPReceivePacketTime ; 
 TYPE_5__* ledpackets ; 
 int mac_last_octet ; 
 scalar_t__ maxPacketDelay ; 
 int /*<<< orphan*/  memcpy (int*,...) ; 
 int /*<<< orphan*/  memset (char*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ minButtonPacketDelay ; 
 scalar_t__ minPacketDelay ; 
 scalar_t__ minStatusPacketDelay ; 
 int /*<<< orphan*/  pack12bit (int*,int,int) ; 
 size_t* panelButtonMap ; 
 int* panelLEDmap ; 
 int* panel_avg_temp ; 
 struct pbuf* pbuf_alloc (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pbuf_free (struct pbuf*) ; 
 int /*<<< orphan*/  pins_debug ; 
 int /*<<< orphan*/  pins_powerctrl ; 
 int pow (float,double) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int** serialNum ; 
 int* temperatures ; 
 int* test_intensities ; 
 scalar_t__ timingdelay ; 
 scalar_t__ udp_bind (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  udp_dest ; 
 int /*<<< orphan*/ * udp_new () ; 
 int /*<<< orphan*/  udp_recv (int /*<<< orphan*/ *,void (*) (void*,struct udp_pcb*,struct pbuf*,struct ip_addr*,int /*<<< orphan*/ ),int /*<<< orphan*/ *) ; 
 scalar_t__ udp_sendto (int /*<<< orphan*/ *,struct pbuf*,int /*<<< orphan*/ *,int) ; 
 int unpack12bit (int*,int) ; 
 int unpack6bit (int*,int) ; 
 int* uptimes ; 
 int /*<<< orphan*/ * usarts ; 

void globalSet(int index, int value) {
    int global_row = index / 3 / 14;
    int global_column = (index / 3) % 14;
    int channel = index % 3;
    int panel_row = global_row % 7;
    int panel_column = global_column % 7;
    int panel_index = (global_row / 7)*2+(global_column / 7);
    pack12bit(ledpackets[panel_index].s.payload, panelLEDmap[(panel_row*7+panel_column)*3+channel], value);
}

void globalSet8bit(int index, uint8_t value) {
    int global_row = index / 3 / 14;
    int global_column = (index / 3) % 14;
    int channel = index % 3;
    int panel_row = global_row % 7;
    int panel_column = global_column % 7;
    int panel_index = (global_row / 7)*2+(global_column / 7);
    int addr = panelLEDmap[(panel_row*7+panel_column)*3+channel];
    addr += (addr>>5)*16;   // make sure things are in the correct places for the 5 LED board CPUs to find them
    ledpackets[panel_index].s.payload[addr] = value;
}

void globalButtonSet(int boardButtonIndex, int value, int panel) {
    int col = boardButtonIndex % 7;
    int row = boardButtonIndex / 7;
    int bitAddr;

    switch(panel) {
        case PANEL_NW:
            bitAddr = row * 14 + col;
            break;
        case PANEL_NE:
            bitAddr = row * 14 + col + 7;
            break;
        case PANEL_SW:
            bitAddr = (row + 7) * 14 + col;
            break;
        case PANEL_SE:
            bitAddr = (row + 7) * 14 + col + 7;
            break;
    }
    int byteAddr = bitAddr / 8;
    int bitOffset = 7-(bitAddr - (byteAddr*8));

    if(value)
        buttonpacket[4+byteAddr] |= (1 << bitOffset);
    else
        buttonpacket[4+byteAddr] &= ~(1 << bitOffset);
}

bool globalGetButtonState(int boardButtonIndex, int panel) {
    int col = boardButtonIndex % 7;
    int row = boardButtonIndex / 7;
    int bitAddr;

    switch(panel) {
        case PANEL_NW:
            bitAddr = row * 14 + col;
            break;
        case PANEL_NE:
            bitAddr = row * 14 + col + 7;
            break;
        case PANEL_SW:
            bitAddr = (row + 7) * 14 + col;
            break;
        case PANEL_SE:
            bitAddr = (row + 7) * 14 + col + 7;
            break;
    }
    int byteAddr = bitAddr / 8;
    int bitOffset = 7-(bitAddr - (byteAddr*8));
    if( buttonpacket[4+byteAddr] & (1 << bitOffset) )
        return true;
    return false;
}

void handle_feedback(int usart_idx, int panel_idx) {
    int i, r, c;
    int row_offset, col_offset;
    int workTemp, avgTemp;
    ledPacket_type inPkt;
    DEBUGPIN_SET(1);
    i = UART_RX_frame_available(&usarts[usart_idx]);
    //printf("avail=%d ",i);
    switch(panel_idx) {
        case PANEL_NW:
            row_offset = 0; col_offset = 0; break;
        case PANEL_NE:
            row_offset = 0; col_offset = 7; break;
        case PANEL_SW:
            row_offset = 7; col_offset = 0; break;
        case PANEL_SE:
            row_offset = 7; col_offset = 7; break;
    }

    if(i == LED_PACKET_LEN) { // got valid packet length so process
        UART_RX_read(&usarts[usart_idx], inPkt.a, i);
        avgTemp = 0;

        if(inPkt.s.type >= 0x20)
            return;

        for(r = 0; r < 7; r++) {
            for(c = 0; c < 7; c++) {
                // update button state in global map
                globalButtonSet(7*r+c, inPkt.s.payload[ panelButtonMap[7*r+c] ], panel_idx);
                // update temperatures
                workTemp = inPkt.s.payload[ panelButtonMap[7*r+c] + 10 ];
                temperatures[14*(r+row_offset)+c+col_offset] = workTemp;
                avgTemp += workTemp;
            }
        }
        avgTemp /= 49;
        panel_avg_temp[panel_idx] = avgTemp;

        // calculate new fan speed if in auto mode
        if(fan_mode[panel_idx] == 1)
            fan_duty[panel_idx] = ((fan_slope[panel_idx]*(avgTemp-80)) >> 8) + fan_intercept[panel_idx];
            if(fan_duty[panel_idx] < fan_min[panel_idx])
                fan_duty[panel_idx] = fan_min[panel_idx];

        // update fan status
        uint32_t workVal = 0;
        for(i = 0; i < 4; i++) {
            workVal <<= 8;
            workVal |= inPkt.s.payload[48*3+20+i];
        }
        if(workVal == 65535)
            workVal = 0;
        else
            workVal = 360000/workVal;

        if(workVal == 0 || (workVal > 7 && workVal < 250)) {
            fan_tach[panel_idx][fan_tach[panel_idx][8]&0x07] = (uint8_t)workVal;
            fan_tach[panel_idx][8]++;
        }

        // update serial number
        for(i = 0; i < 6; i++)
            serialNum[panel_idx][i] = inPkt.s.payload[20+i];

        // update uptimes (5 per panel)
        uptimes[panel_idx] = 0;
        for(i = 0; i < 4; i++) {
            uptimes[panel_idx] <<= 8;
            uptimes[panel_idx] |= inPkt.s.payload[48*3+32+i];
        }
    } else {
        if(i > 0) { // got unexpected length packet so flush buffer
            char buf[512];
            if(i > 512)
                i = 512;
            UART_RX_read(&usarts[usart_idx], buf, i);
        }
    }
    DEBUGPIN_CLR(1);
}

void sendLEDpackets(void) {
    // read before writing so there was enough time to get things back
    handle_feedback(USART_NW, PANEL_NW);
    handle_feedback(USART_SW, PANEL_SW);
    handle_feedback(USART_SE, PANEL_SE);
    handle_feedback(USART_NE, PANEL_NE);

    UART_SendBytes(&usarts[3], ledpackets[PANEL_NW].a, sizeof(ledPacket_type));
    UART_SendBytes(&usarts[2], ledpackets[PANEL_SW].a, sizeof(ledPacket_type));
    UART_SendBytes(&usarts[1], ledpackets[PANEL_SE].a, sizeof(ledPacket_type));
    UART_SendBytes(&usarts[0], ledpackets[PANEL_NE].a, sizeof(ledPacket_type));
    lastPacketTime = LocalTime;
}

__attribute__((used)) static bool lookupTableReadbackHelper(ledPacket_type *outpkt, uint8_t *udpPayload, int index, int usart, int panel) {
    int fail_count = 0;
    int row_offset, col_offset;
    int r,c, len;
    ledPacket_type inpkt;

    outpkt->s.type = PKT_TYPE_GET_LOOKUP;
    outpkt->s.param1 = index;

    switch(panel) {
        case PANEL_NW:
            row_offset = 0; col_offset = 0; break;
        case PANEL_NE:
            row_offset = 0; col_offset = 7; break;
        case PANEL_SW:
            row_offset = 7; col_offset = 0; break;
        case PANEL_SE:
            row_offset = 7; col_offset = 7; break;
    }

    while(1) {
        UART_SendBytes(&usarts[usart], outpkt->a, sizeof(ledPacket_type));
        Delay(20);
        len = UART_RX_frame_available(&usarts[usart]);
        if(len == LED_PACKET_LEN) { // got valid packet length so process
            UART_RX_read(&usarts[usart], inpkt.a, len);
            break;
        } else {
            if(len > 0) { // got unexpected length packet so flush buffer
                char buf[512];
                if(len > 512)
                    len = 512;
                UART_RX_read(&usarts[usart], buf, len);
            }
            if(fail_count++ > 3)
                return false;
        }
    }
    // get inpkt contents moved to udpPayload
    for(r = 0; r < 7; r++) {
        for(c = 0; c < 7; c++) {
            pack12bit(udpPayload, ((r+row_offset)*14+(c+col_offset))*3, unpack12bit(inpkt.s.payload, panelLEDmap[(r*7+c)*3]) );
            pack12bit(udpPayload, ((r+row_offset)*14+(c+col_offset))*3+1, unpack12bit(inpkt.s.payload, panelLEDmap[(r*7+c)*3+1]) );
            pack12bit(udpPayload, ((r+row_offset)*14+(c+col_offset))*3+2, unpack12bit(inpkt.s.payload, panelLEDmap[(r*7+c)*3+2]) );
        }
    }
    return true;
}

__attribute__((used)) static void doLookupTableReadback() {
    int i, failcount;
    ledPacket_type pkt;
    struct pbuf *p;
    bool result = false;

    if(global_row == POWER_ROW)
        return;

    p = pbuf_alloc(PBUF_TRANSPORT, 196*3*3/2+4, PBUF_RAM);

    failcount = 0;
    i = 0;
    do {
        result = false;
        result |= lookupTableReadbackHelper(&pkt, p->payload+4, i, USART_NW, PANEL_NW);
        result |= lookupTableReadbackHelper(&pkt, p->payload+4, i, USART_NE, PANEL_NE);
        result |= lookupTableReadbackHelper(&pkt, p->payload+4, i, USART_SW, PANEL_SW);
        result |= lookupTableReadbackHelper(&pkt, p->payload+4, i, USART_SE, PANEL_SE);
        if(result != false) { // only continue if at least one succeeded
            ((uint8_t*)p->payload)[0] = 0x23;
            ((uint8_t*)p->payload)[1] = i;
            if( udp_sendto(global_pcb, p, &udp_dest, 27482) != ERR_OK ) {
                Delay(100);
                LwIP_Periodic_Handle(LocalTime);
                continue;
            }
            Delay(20);
            LwIP_Periodic_Handle(LocalTime);
            i++;
            failcount = 0;
        } else {
            if(failcount++ > 4)
                break;
        }
    } while(i < 65);

    /* free the pbuf */
    pbuf_free(p);
}

void udp_process_recv_packet(void *arg, struct udp_pcb *pcb, struct pbuf *p, struct ip_addr *addr, u16_t port)
{
    int i, pixValue;
    static int pktCount = 0;
    uint8_t workType;
    uint8_t workParam;

    DEBUGPIN_SET(0);

    pktCount++;

    if (p != NULL) {
        lastUDPReceivePacketTime = LocalTime;
        workType = ((uint8_t*)p->payload)[0];
        switch( workType ) {
            case PKT_TYPE_8BIT_CAL:
                for(i = 0; i < 196*3; i++) {
                    pixValue = ((uint8_t*)p->payload)[16+i];
                    globalSet8bit(i, pixValue);
                }
                break;
            case PKT_TYPE_GSVALS:
                for(i = 0; i < 196*3; i++) {
                    pixValue = unpack12bit(p->payload+16, i);
                    globalSet(i, pixValue);
                }
                break;
            case PKT_TYPE_DOTCORRECT_PACK12:
                for(i = 0; i < 196*3; i++) {
                    pixValue = unpack12bit(p->payload+16, i);
                    globalSet(i, pixValue);
                }
                break;
            case PKT_TYPE_8BIT_RAW:
                for(i = 0; i < 196*3; i++) {
                    pixValue = ((uint8_t*)p->payload)[16+i];
                    globalSet8bit(i, pixValue);
                }
                break;
            case PKT_TYPE_SET_LOOKUP:
                for(i = 0; i < 196*3; i++) {
                    pixValue = unpack12bit(p->payload+16, i);
                    globalSet(i, pixValue);
                }
                workParam = ((uint8_t*)p->payload)[6];
                break;
            case PKT_TYPE_DOTCORRECT_PACK8:
                for(i = 0; i < 196*3; i++) {
                    pixValue = ((uint8_t*)p->payload)[16+i];
                    globalSet(i, pixValue);
                }
                workType = PKT_TYPE_DOTCORRECT_PACK12;
                break;
            case PKT_TYPE_DOTCORRECT_PACK6:
                for(i = 0; i < 196*3; i++) {
                    pixValue = unpack6bit(p->payload+16, i);
                    globalSet(i, pixValue);
                }
                workType = PKT_TYPE_DOTCORRECT_PACK12;
                break;
            case PKT_TYPE_GET_LOOKUP:
                doLookupTableReadback();
                pbuf_free(p);
                DEBUGPIN_CLR(0);
                return;
            case PKT_TYPE_FAN_CONFIG:
                {
                    uint8_t *pl = p->payload+16;
                    for(i = 0; i < 4; i++) {
                        fan_setpoint[i]  = (pl[   i*2] << 8) | pl[   i*2+1];
                        fan_mode[i]      =  pl[ 8+i  ];
                        fan_slope[i]     = (pl[12+i*2] << 8) | pl[12+i*2+1];
                        fan_intercept[i] = (pl[20+i*2] << 8) | pl[20+i*2+1];
                        fan_min[i]       = (pl[28+i*2] << 8) | pl[28+i*2+1];
                        if(fan_mode[i] == 0)
                            fan_duty[i] = fan_setpoint[i];
                    }
                }
                break;
            case PKT_TYPE_RELAY_CTRL:
                if(((uint8_t*)(p->payload+16))[0] != 0)
                    PIN_High(pins_powerctrl, PWR_CTRL_AC_0);
                else
                    PIN_Low(pins_powerctrl, PWR_CTRL_AC_0);

                if(((uint8_t*)(p->payload+16))[1] != 0)
                    PIN_High(pins_powerctrl, PWR_CTRL_AC_1);
                else
                    PIN_Low(pins_powerctrl, PWR_CTRL_AC_1);
                break;
            case PKT_TYPE_REBOOT: // 0xF0
                if( ((uint32_t*)(p->payload+16))[0] == 0x816A4EB2) {
                    if( ((uint8_t*)(p->payload+16))[4] & 0x0F) {
                        ledPacket_type outpkt;
                        outpkt.s.type = PKT_TYPE_REBOOT;
                        ((uint32_t*)outpkt.s.payload)[0] = 0x816A4EB2;
                        ((uint32_t*)outpkt.s.payload)[12] = 0x816A4EB2;
                        ((uint32_t*)outpkt.s.payload)[24] = 0x816A4EB2;
                        ((uint32_t*)outpkt.s.payload)[36] = 0x816A4EB2;
                        ((uint32_t*)outpkt.s.payload)[48] = 0x816A4EB2;
                        for(i = 0; i < 4; i++) {
                            if( ((uint8_t*)(p->payload+16))[4] & (0x01 << i)) {
                                UART_SendBytes(&usarts[i], outpkt.a, sizeof(ledPacket_type));
                            }
                        }
                    }
                    if( ((uint8_t*)(p->payload+16))[4] & 0x10) {
                        Delay(100);  // delay 100ms before rebooting to make sure outgoing packet gets sent completely
                        NVIC_SystemReset();
                    }
                }
                break;
            case PKT_TYPE_BL_INIT:
                if(bootloaderMode == BL_MODE_WAITING) {
                    // need to change bootloader mode and init LED board
                    bootloaderMode = BL_MODE_ACTIVE;
                }

            default:
                workType = 0;
                break;
        }

        // copy the packet type into the packets being sent to each endpoint
        for(i = 0; i < 4; i++) {
            ledpackets[i].s.type = workType;
            ledpackets[i].s.param1 = workParam;
        }

        // limit the rate of communications to the LED board
        if( (global_row != POWER_ROW) && (LocalTime - lastPacketTime >= minPacketDelay) )
            sendLEDpackets();

        /* free the pbuf */
        pbuf_free(p);
    }
    DEBUGPIN_CLR(0);
}

void udp_recv_init(void)
{
    /* get new pcb */
    global_pcb = udp_new();
    if (global_pcb == NULL) {
        LWIP_DEBUGF(UDP_DEBUG, ("udp_new failed!\n"));
        return;
    }

    /* bind to any IP address on port 7 */
    if (udp_bind(global_pcb, IP_ADDR_ANY, 7) != ERR_OK) {
        LWIP_DEBUGF(UDP_DEBUG, ("udp_bind failed!\n"));
        return;
    }

    /* set udp_echo_recv() as callback function
       for received packets */
    udp_recv(global_pcb, udp_process_recv_packet, NULL);
}

void buttonTest(int intensity) {
    int i;

    handle_feedback(USART_NW, PANEL_NW);
    handle_feedback(USART_SW, PANEL_SW);
    handle_feedback(USART_SE, PANEL_SE);
    handle_feedback(USART_NE, PANEL_NE);
    for(i = 0; i < 49; i++) {
        if( globalGetButtonState(i, PANEL_NE) ) {
            pack12bit(ledpackets[PANEL_NW].s.payload, panelLEDmap[i*3], intensity);
            pack12bit(ledpackets[PANEL_NW].s.payload, panelLEDmap[i*3+1], intensity);
            pack12bit(ledpackets[PANEL_NW].s.payload, panelLEDmap[i*3+2], 0);
        } else {
            //pack12bit(ledpackets[PANEL_NW].s.payload, panelLEDmap[i*3], intensity);
            pack12bit(ledpackets[PANEL_NW].s.payload, panelLEDmap[i*3+1], 0);
            pack12bit(ledpackets[PANEL_NW].s.payload, panelLEDmap[i*3+2], 0);
        }
    }
    UART_SendBytes(&usarts[3], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
    UART_SendBytes(&usarts[2], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
    UART_SendBytes(&usarts[1], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
    UART_SendBytes(&usarts[0], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
    Delay(10);
}

void test_modes() {
    int i, row, col;

    int rampStep = 10;
    int rampValue = 0;
    int rampMin, rampMax;

    while(1) {
        i = BUTTONS_Read_All();
        row = (i >> 4) & 0xF;
        col = i & 0xF;
        switch(row) {
            case 0: // cycle through RGBW illumination
            case 1: // red
                for(i = 0; i < 49*3; i++)
                    pack12bit(ledpackets[PANEL_NW].s.payload, panelLEDmap[i], 0);
                for(i = 0; i < 49; i++)
                    pack12bit(ledpackets[PANEL_NW].s.payload, panelLEDmap[i*3], test_intensities[col]);
                UART_SendBytes(&usarts[3], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                UART_SendBytes(&usarts[2], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                UART_SendBytes(&usarts[1], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                UART_SendBytes(&usarts[0], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                Delay(2000);
                if(row != 0) break;
            case 2: // green
                for(i = 0; i < 49*3; i++)
                    pack12bit(ledpackets[PANEL_NW].s.payload, panelLEDmap[i], 0);
                for(i = 0; i < 49; i++)
                    pack12bit(ledpackets[PANEL_NW].s.payload, panelLEDmap[i*3+1], test_intensities[col]);
                UART_SendBytes(&usarts[3], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                UART_SendBytes(&usarts[2], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                UART_SendBytes(&usarts[1], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                UART_SendBytes(&usarts[0], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                Delay(2000);
                if(row != 0) break;
            case 3: // blue
                for(i = 0; i < 49*3; i++)
                    pack12bit(ledpackets[PANEL_NW].s.payload, panelLEDmap[i], 0);
                for(i = 0; i < 49; i++)
                    pack12bit(ledpackets[PANEL_NW].s.payload, panelLEDmap[i*3+2], test_intensities[col]);
                UART_SendBytes(&usarts[3], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                UART_SendBytes(&usarts[2], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                UART_SendBytes(&usarts[1], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                UART_SendBytes(&usarts[0], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                Delay(2000);
                if(row != 0) break;
            case 4: // white
                for(i = 0; i < 49*3; i++)
                    pack12bit(ledpackets[PANEL_NW].s.payload, panelLEDmap[i], test_intensities[col]);
                UART_SendBytes(&usarts[3], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                UART_SendBytes(&usarts[2], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                UART_SendBytes(&usarts[1], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                UART_SendBytes(&usarts[0], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                Delay(2000);
                break;
            case 5: // gamma correction test
                for(i = 0; i < 196; i++) {
                    globalSet8bit(i*3, i);
                    globalSet8bit(i*3+1, 0);
                    globalSet8bit(i*3+2, 0);
                }
                ledpackets[PANEL_NW].s.type = PKT_TYPE_8BIT_CAL;
                UART_SendBytes(&usarts[3], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                UART_SendBytes(&usarts[2], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                UART_SendBytes(&usarts[1], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                UART_SendBytes(&usarts[0], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                Delay(1000);
                ledpackets[PANEL_NW].s.type = PKT_TYPE_8BIT_RAW;
                UART_SendBytes(&usarts[3], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                UART_SendBytes(&usarts[2], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                UART_SendBytes(&usarts[1], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                UART_SendBytes(&usarts[0], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                Delay(1000);
                break;
            case 6: // one LED element at a time
                // Startup sequence the lights all the LEDs one at a time
                ledpackets[PANEL_NW].s.type = PKT_TYPE_GSVALS;
                for(i = 0; i < 49*3+1; i++) {
                    if(i < 49*3)
                        pack12bit(ledpackets[PANEL_NW].s.payload, panelLEDmap[i], test_intensities[col]);
                    if(i > 0)
                        pack12bit(ledpackets[PANEL_NW].s.payload, panelLEDmap[i-1], 0);
                    UART_SendBytes(&usarts[3], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                    UART_SendBytes(&usarts[2], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                    UART_SendBytes(&usarts[1], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                    UART_SendBytes(&usarts[0], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));

                    Delay(10);
                }
                break;
            case 7: // Test ramp for burnin testing of LED boards
                rampMax = test_intensities[col];
                rampMin = test_intensities[col]/5;
                for(rampValue = rampMin; rampValue < rampMax; rampValue += rampStep) {
                    for(i = 0; i <192*3; i++) {
                        globalSet(i,rampValue);
                    }
                    for(i = 0; i < 4; i++) {
                        ledpackets[i].s.type = PKT_TYPE_GSVALS;
                        pack12bit(ledpackets[i].ua+1, 0, rampValue/2);
                    }
                    sendLEDpackets();
                    Delay(10);
                }
                Delay(1000);
                for(rampValue = rampMax; rampValue > rampMin; rampValue -= rampStep) {
                    for(i = 0; i <192*3; i++) {
                        globalSet(i,rampValue);
                    }
                    for(i = 0; i < 4; i++) {
                        ledpackets[i].s.type = PKT_TYPE_GSVALS;
                        pack12bit(ledpackets[i].ua+1, 0, rampValue/2);
                    }
                    sendLEDpackets();
                    Delay(10);
                }
                break;
            case 8: // button test
                buttonTest(test_intensities[col]);
                break;
            case 9: // clear
                for(i = 0; i <49*3; i++)
                    pack12bit(ledpackets[PANEL_NW].s.payload, panelLEDmap[i], 0);
                UART_SendBytes(&usarts[3], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                UART_SendBytes(&usarts[2], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                UART_SendBytes(&usarts[1], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                UART_SendBytes(&usarts[0], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                Delay(1000);
                break;
            case 10: // thermal cycle
                if( (rampMin > 600) || (rampMin < -600))  rampMin = 600;
                if(rampMin <= 0) {
                    for(i = 0; i < 49*3; i++)
                        pack12bit(ledpackets[PANEL_NW].s.payload, panelLEDmap[i], 4000);
                } else {
                    for(i = 0; i < 49*3; i++)
                        pack12bit(ledpackets[PANEL_NW].s.payload, panelLEDmap[i], 0);
                }
                UART_SendBytes(&usarts[3], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                UART_SendBytes(&usarts[2], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                UART_SendBytes(&usarts[1], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                UART_SendBytes(&usarts[0], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                Delay(1000);
                rampMin--;
                break;
            default:
                break;
        }
    }
}

__attribute__((used)) static void BLhelper_send() {
    UART_SendBytes(&usarts[3], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
    UART_SendBytes(&usarts[2], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
    UART_SendBytes(&usarts[1], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
    UART_SendBytes(&usarts[0], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
    Delay(1000);
    handle_feedback(USART_NW, PANEL_NW);
    handle_feedback(USART_SW, PANEL_SW);
    handle_feedback(USART_SE, PANEL_SE);
    handle_feedback(USART_NE, PANEL_NE);
}

__attribute__((used)) static void BLhelper_dup() {
    int i;
    for(i = 0; i < 48; i++) {
        uint8_t val = ledpackets[PANEL_NW].s.payload[i];
        ledpackets[PANEL_NW].s.payload[i+48]   = val;
        ledpackets[PANEL_NW].s.payload[i+48*2] = val;
        ledpackets[PANEL_NW].s.payload[i+48*3] = val;
        ledpackets[PANEL_NW].s.payload[i+48*4] = val;
    }
}

void startBootloader() {
    int i;
    uint32_t * payload32 = (uint32_t*)ledpackets[PANEL_NW].s.payload;

    // send reboot a bunch of times to make sure we get it to work
    for(i = 0; i < 10; i++) {
        ledpackets[PANEL_NW].s.type = PKT_TYPE_REBOOT;
        payload32[0] = 0x816A4EB2;
        BLhelper_dup();
        BLhelper_send();
        Delay(100);
    }
    for(i = 0; i < 10; i++) {
        ledpackets[PANEL_NW].s.type = PKT_TYPE_BL_INIT;
        BLhelper_send();
        Delay(500);
    }
}

void doBootloaderTest() {
    int i, j;
    uint32_t * payload32 = (uint32_t*)ledpackets[PANEL_NW].s.payload;

    /*for(i = 0; i < 10; i++) {
        ledpackets[PANEL_NW].s.type = PKT_TYPE_BL_READ_BLOCK;
        payload32[0] = 0x08002000+32*i;
        payload32[1] = 0x8;
        BLhelper_dup();
        BLhelper_send();
    }*/

    ledpackets[PANEL_NW].s.type = PKT_TYPE_BL_UNLOCK_FLASH;
    payload32[0] = 0x45670123;
    payload32[1] = 0xCDEF89AB;
    BLhelper_dup();
    BLhelper_send();

    ledpackets[PANEL_NW].s.type = PKT_TYPE_BL_ERASE_FLASH;
    payload32[0] = 0xACEA1623;
    BLhelper_dup();
    BLhelper_send();

    Delay(5000);

    for(i = 0; i < 10; i++) {
        ledpackets[PANEL_NW].s.type = PKT_TYPE_BL_WRITE_BLOCK;
        payload32[0] = 0x08002000+32*i;
        payload32[1] = 0x8;
        for(j = 0; j < 8; j++)
            payload32[2+j] = 8*i+j;
        BLhelper_dup();
        BLhelper_send();
    }

    for(i = 0; i < 10; i++) {
        ledpackets[PANEL_NW].s.type = PKT_TYPE_BL_READ_BLOCK;
        payload32[0] = 0x08002000+32*i;
        payload32[1] = 0x8;
        BLhelper_dup();
        BLhelper_send();
    }

    while(1);

}

__attribute__((used)) static uint8_t calcMedian(uint8_t *list) {
    uint8_t workList[8], temp;
    int i, j;
    memcpy(workList, list, 8);
    for(i = 0; i < 7; i++) {
        for(j = i+1; j < 8; j++) {
            if(workList[j] < workList[i]) {
                temp = workList[i];
                workList[i] = workList[j];
                workList[j] = temp;
            }
        }
    }
    return workList[3];
}

int main(void)
{
  /*!< At this stage the microcontroller clock setting is already configured to
       168 MHz, this is done through SystemInit() function which is called from
       startup file (startup_stm32f4xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
       system_stm32f4xx.c file
     */
    int i;

    struct pbuf *p;

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);

    /* configure ethernet (GPIOs, clocks, MAC, DMA) */
    printf("about to start ethernet config\n");
    ETH_BSP_Config();

    // Determine the IP address based on dip switch position
    BUTTONS_Config();
    PIN_Config();
    CONFIG_pins(pins_powerctrl, PWRCTRL_NUM_PINS);
    PIN_Num(pins_debug, 0, DEBUGPIN_NUM);

    PIN_Low(pins_powerctrl, PWR_CTRL_AC_0);
    PIN_Low(pins_powerctrl, PWR_CTRL_AC_1);

    Delay(10);
    i = BUTTONS_Read_All();
    #ifdef TEST_MODES
        i = 2;
    #endif
    global_row = (i >> 4) & 0xF;
    global_column = i & 0xF;
    IP_lastOctet = 20+global_row*10+global_column;
    mac_last_octet = 20+global_row*10+global_column;
    printf("IP: 192.168.0.%d", IP_lastOctet);

    IP4_ADDR(&udp_dest, IP_ADDR0, IP_ADDR1, IP_ADDR2, 10);

    /* Initilaize the LwIP stack */
    LwIP_Init();

    // Initialize, bind, and setup callback for UDP
    udp_recv_init();

    if(global_row != POWER_ROW) {
        // this is a normal panel (not a power box)
        UART_Config(&usarts[0]);
        UART_Config(&usarts[1]);
        UART_Config(&usarts[2]);
        UART_Config(&usarts[3]);

        Delay(10);

        //startBootloader();
        //doBootloaderTest();

        // Wait for initialization of LED board firmware and debug display
        Delay(7000);

        // run through sequence of setting dot correction
        int dotval = 58;
        while(dotval <= 63) {
            Delay(50);
            // set dot correction
            ledPacket_type pkt;
            memset(pkt.a, 0, sizeof(ledPacket_type));
            pkt.s.type = PKT_TYPE_DOTCORRECT_PACK12;
            for(i = 0; i < 49; i++) {
                pack12bit(pkt.s.payload, panelLEDmap[i*3+1], dotval);
                #ifdef TEST_MODES
                    pack12bit(pkt.s.payload, panelLEDmap[i*3], dotval*12/16);
                    pack12bit(pkt.s.payload, panelLEDmap[i*3+2], dotval*12/16);
                #else
                    pack12bit(pkt.s.payload, panelLEDmap[i*3  ], dotval/2);
                    pack12bit(pkt.s.payload, panelLEDmap[i*3+2], dotval/2);
                #endif
            }
            UART_SendBytes(&usarts[0], pkt.a, sizeof(ledPacket_type));
            UART_SendBytes(&usarts[1], pkt.a, sizeof(ledPacket_type));
            UART_SendBytes(&usarts[2], pkt.a, sizeof(ledPacket_type));
            UART_SendBytes(&usarts[3], pkt.a, sizeof(ledPacket_type));
            Delay(50);
            ledpackets[PANEL_NW].s.type = PKT_TYPE_GSVALS;
            for(i = 0; i <7*3; i++)
                pack12bit(ledpackets[PANEL_NW].s.payload, panelLEDmap[i], 800);
            for(; i <49*3; i++)
                pack12bit(ledpackets[PANEL_NW].s.payload, panelLEDmap[i], 0);
            UART_SendBytes(&usarts[3], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
            UART_SendBytes(&usarts[2], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
            UART_SendBytes(&usarts[1], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
            UART_SendBytes(&usarts[0], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
            dotval++;
            Delay(30);
        }
        // set calibration to a 2.2 gamma curve
        {
            int j;
            float value;
            uint16_t iValue;
            ledpackets[PANEL_NW].s.type = PKT_TYPE_SET_LOOKUP;
            for(i = 0; i < 65; i++) {
                value = 4000*pow( (float)i/65.0, 2.2);
                iValue = ((uint16_t)value) & 0xFFF;
                for(j = 0; j < 49*3; j++) {
                    pack12bit(ledpackets[PANEL_NW].s.payload, panelLEDmap[j], iValue);
                }
                ledpackets[PANEL_NW].s.param1 = i;
                UART_SendBytes(&usarts[3], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                UART_SendBytes(&usarts[2], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                UART_SendBytes(&usarts[1], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                UART_SendBytes(&usarts[0], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                Delay(30);
            }
        }
        // turn off all channels
        ledpackets[PANEL_NW].s.type = PKT_TYPE_GSVALS;
        for(i = 0; i <49*3; i++) {
            pack12bit(ledpackets[PANEL_NW].s.payload, panelLEDmap[i], 0);
        }
        UART_SendBytes(&usarts[3], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
        UART_SendBytes(&usarts[2], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
        UART_SendBytes(&usarts[1], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
        UART_SendBytes(&usarts[0], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));

        // Startup sequence that lights all the LEDs one at a time
        ledpackets[PANEL_NW].s.type = PKT_TYPE_GSVALS;
        for(i = 0; i <49*3+1; i++) {
            if(i < 49*3)
                pack12bit(ledpackets[PANEL_NW].s.payload, panelLEDmap[i], 800);
            if(i > 0)
                pack12bit(ledpackets[PANEL_NW].s.payload, panelLEDmap[i-1], 0);
            UART_SendBytes(&usarts[3], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
            UART_SendBytes(&usarts[2], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
            UART_SendBytes(&usarts[1], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
            UART_SendBytes(&usarts[0], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));

            Delay(10);
        }

        #ifdef TEST_MODES
            test_modes();
        #endif

        //buttonTest();
    }

    // Normal execution infinite while loop
    while(1) {
        if (ETH_CheckFrameReceived()) {
            /* process received ethernet packet*/
            LwIP_Pkt_Handle();
        }

        // for normal panels send packet to LED boards if overdue and not in bootloader mode
        if(global_row != POWER_ROW && LocalTime - lastPacketTime >= maxPacketDelay && bootloaderMode == BL_MODE_INACTIVE) {
            sendLEDpackets();
            DEBUGPIN_TGL(8);
        }

        if(global_row == POWER_ROW) {
            // This is a power box controller
            if(LocalTime-lastStatusPacketTime >= minStatusPacketDelay) {
                lastStatusPacketTime = LocalTime;
                p = pbuf_alloc(PBUF_TRANSPORT, 4+6+2+2, PBUF_RAM);
                i = 0;
                ((uint8_t*)p->payload)[i++] = 0x22;
                ((uint8_t*)p->payload)[i++] = 0x0;
                ((uint8_t*)p->payload)[i++] = 0x0;
                ((uint8_t*)p->payload)[i++] = 0x0;
                ((uint8_t*)p->payload)[i++] = PIN_State(pins_powerctrl, PWR_MON_0_0);
                ((uint8_t*)p->payload)[i++] = PIN_State(pins_powerctrl, PWR_MON_0_1);
                ((uint8_t*)p->payload)[i++] = PIN_State(pins_powerctrl, PWR_MON_0_2);
                ((uint8_t*)p->payload)[i++] = PIN_State(pins_powerctrl, PWR_MON_1_0);
                ((uint8_t*)p->payload)[i++] = PIN_State(pins_powerctrl, PWR_MON_1_1);
                ((uint8_t*)p->payload)[i++] = PIN_State(pins_powerctrl, PWR_MON_1_2);
                ((uint8_t*)p->payload)[i++] = !PIN_State(pins_powerctrl, PWR_MON_AC_0);
                ((uint8_t*)p->payload)[i++] = !PIN_State(pins_powerctrl, PWR_MON_AC_1);
                ((uint8_t*)p->payload)[i++] = PIN_State(pins_powerctrl, PWR_CTRL_AC_0);
                ((uint8_t*)p->payload)[i++] = PIN_State(pins_powerctrl, PWR_CTRL_AC_1);
                udp_sendto(global_pcb, p, &udp_dest, 27482);
                /* free the pbuf */
                pbuf_free(p);
            }
        } else {
            // This is an LED panel controller

            // build and send button data packet at a fixed rate
            if(LocalTime-lastButtonPacketTime >= minButtonPacketDelay && bootloaderMode == BL_MODE_INACTIVE) {
                lastButtonPacketTime = LocalTime;
                DEBUGPIN_TGL(7);
                p = pbuf_alloc(PBUF_TRANSPORT, 29, PBUF_RAM);
                memcpy(p->payload, buttonpacket, 29);
                udp_sendto(global_pcb, p, &udp_dest, 27482);
                /* free the pbuf */
                pbuf_free(p);
            }
            // build and send button data packet at a fixed rate
            if(LocalTime-lastStatusPacketTime >= minStatusPacketDelay && bootloaderMode == BL_MODE_INACTIVE) {
                lastStatusPacketTime = LocalTime;
                p = pbuf_alloc(PBUF_TRANSPORT, 4+196+4+4*6+4*4+4, PBUF_RAM);
                ((uint8_t*)p->payload)[0] = 0x21;
                memcpy(p->payload+4, temperatures, 196);
                ((uint8_t*)(p->payload))[4+196+0] = calcMedian(fan_tach[0]);
                ((uint8_t*)(p->payload))[4+196+1] = calcMedian(fan_tach[1]);
                ((uint8_t*)(p->payload))[4+196+2] = calcMedian(fan_tach[2]);
                ((uint8_t*)(p->payload))[4+196+3] = calcMedian(fan_tach[3]);
                memcpy(p->payload+4+196+4, serialNum, 4*6);
                memcpy(p->payload+4+196+4+4*6, uptimes, 4*4);
                memcpy(p->payload+4+196+4+4*6+4*4, panel_avg_temp, 4);
                udp_sendto(global_pcb, p, &udp_dest, 27482);
                /* free the pbuf */
                pbuf_free(p);
            }
        }

        LwIP_Periodic_Handle(LocalTime);

        // Turn off the display if we don't receive anything for more than 5 seconds
        if( (LocalTime - lastUDPReceivePacketTime) > 5000 ) {
            // turn off all channels
            ledpackets[PANEL_NW].s.type = PKT_TYPE_GSVALS;
            for(i = 0; i <49*3; i++) {
                pack12bit(ledpackets[PANEL_NW].s.payload, panelLEDmap[i], 0);
            }
            if( (global_row != POWER_ROW) && (LocalTime - lastPacketTime >= minPacketDelay) ) {
                handle_feedback(USART_NW, PANEL_NW);
                handle_feedback(USART_SW, PANEL_SW);
                handle_feedback(USART_SE, PANEL_SE);
                handle_feedback(USART_NE, PANEL_NE);
                UART_SendBytes(&usarts[3], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                UART_SendBytes(&usarts[2], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                UART_SendBytes(&usarts[1], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                UART_SendBytes(&usarts[0], ledpackets[PANEL_NW].a, sizeof(ledpackets[PANEL_NW].a));
                lastPacketTime = LocalTime;
            }
        }
    }
}

void Delay(uint32_t nCount) {
  /* Capture the current local time */
  timingdelay = LocalTime;

  /* wait until the desired delay is finished */
  while( (LocalTime - timingdelay) < nCount ) {
  }
}

void Time_Update(void) {
    LocalTime += SYSTEMTICK_PERIOD_MS;
}

