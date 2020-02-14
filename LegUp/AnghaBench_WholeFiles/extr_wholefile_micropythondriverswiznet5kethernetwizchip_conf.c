#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_7__ ;
typedef  struct TYPE_19__   TYPE_6__ ;
typedef  struct TYPE_18__   TYPE_5__ ;
typedef  struct TYPE_17__   TYPE_4__ ;
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;
typedef  struct TYPE_13__   TYPE_12__ ;

/* Type definitions */
struct TYPE_19__ {int /*<<< orphan*/  time_100us; int /*<<< orphan*/  retry_cnt; } ;
typedef  TYPE_6__ wiz_NetTimeout ;
struct TYPE_20__ {int volatile* mac; int volatile* gw; int volatile* sn; int volatile* ip; int /*<<< orphan*/  dhcp; void** dns; } ;
typedef  TYPE_7__ wiz_NetInfo ;
typedef  int volatile uint8_t ;
typedef  scalar_t__ uint32_t ;
typedef  int uint16_t ;
typedef  scalar_t__ ptrdiff_t ;
typedef  int netmode_type ;
typedef  scalar_t__ intr_kind ;
typedef  int int8_t ;
typedef  int ctlwizchip_type ;
typedef  int ctlnetwork_type ;
typedef  int /*<<< orphan*/  WIZCHIP_EXPORT ;
struct TYPE_18__ {int volatile (* _read_byte ) (scalar_t__) ;void (* _write_byte ) (scalar_t__,int volatile) ;} ;
struct TYPE_14__ {void (* _read_bytes ) (int volatile*,scalar_t__) ;void (* _write_bytes ) (int volatile const*,scalar_t__) ;} ;
struct TYPE_17__ {TYPE_1__ SPI; TYPE_5__ BUS; } ;
struct TYPE_16__ {void (* _select ) () ;void (* _deselect ) () ;} ;
struct TYPE_15__ {void (* _enter ) () ;void (* _exit ) () ;} ;
struct TYPE_13__ {int if_mode; int* id; TYPE_4__ IF; TYPE_3__ CS; TYPE_2__ CRIS; } ;

/* Variables and functions */
#define  CN_GET_NETINFO 142 
#define  CN_GET_NETMODE 141 
#define  CN_GET_TIMEOUT 140 
#define  CN_SET_NETINFO 139 
#define  CN_SET_NETMODE 138 
#define  CN_SET_TIMEOUT 137 
#define  CW_CLR_INTERRUPT 136 
#define  CW_GET_ID 135 
#define  CW_GET_INTERRUPT 134 
#define  CW_GET_INTRMASK 133 
#define  CW_GET_PHYLINK 132 
#define  CW_GET_PHYPOWMODE 131 
#define  CW_INIT_WIZCHIP 130 
#define  CW_RESET_WIZCHIP 129 
#define  CW_SET_INTRMASK 128 
 int volatile MR_RST ; 
 int NM_PINGBLOCK ; 
 int NM_PPPOE ; 
 int NM_WAKEONLAN ; 
 TYPE_12__ WIZCHIP ; 
 int /*<<< orphan*/  _DHCP_ ; 
 void** _DNS_ ; 
 int volatile* _SUBN_ ; 
 int _WIZCHIP_IO_MODE_BUS_ ; 
 int _WIZCHIP_IO_MODE_SPI_ ; 
 int _WIZCHIP_SOCK_NUM_ ; 
 int /*<<< orphan*/  getGAR (int volatile*) ; 
 int getIMR () ; 
 int getIR () ; 
 int getMR () ; 
 int /*<<< orphan*/  getRCR () ; 
 int /*<<< orphan*/  getRTR () ; 
 int /*<<< orphan*/  getSHAR (int volatile*) ; 
 int getSIMR () ; 
 int /*<<< orphan*/  getSIPR (int volatile*) ; 
 int getSIR () ; 
 int /*<<< orphan*/  getSUBR (int volatile*) ; 
 int /*<<< orphan*/  setGAR (int volatile*) ; 
 int /*<<< orphan*/  setIMR (int volatile) ; 
 int /*<<< orphan*/  setIR (int volatile) ; 
 int /*<<< orphan*/  setMR (int volatile) ; 
 int /*<<< orphan*/  setRCR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  setRTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  setSHAR (int volatile*) ; 
 int /*<<< orphan*/  setSIMR (int volatile) ; 
 int /*<<< orphan*/  setSIPR (int volatile*) ; 
 int /*<<< orphan*/  setSIR (int volatile) ; 
 int /*<<< orphan*/  setSUBR (int volatile*) ; 
 int /*<<< orphan*/  setSn_RXBUF_SIZE (int,int volatile) ; 
 int /*<<< orphan*/  setSn_TXBUF_SIZE (int,int volatile) ; 
 void wizchip_clrinterrupt (scalar_t__) ; 
 scalar_t__ wizchip_getinterrupt () ; 
 scalar_t__ wizchip_getinterruptmask () ; 
 void wizchip_getnetinfo (TYPE_7__*) ; 
 int wizchip_getnetmode () ; 
 void wizchip_gettimeout (TYPE_6__*) ; 
 int wizchip_init (int volatile*,int volatile*) ; 
 void wizchip_setinterruptmask (scalar_t__) ; 
 void wizchip_setnetinfo (TYPE_7__*) ; 
 int wizchip_setnetmode (int) ; 
 void wizchip_settimeout (TYPE_6__*) ; 
 void wizchip_sw_reset () ; 
 int wizphy_getphylink () ; 
 int wizphy_getphypmode () ; 

void 	  wizchip_cris_enter(void)           {}

void 	  wizchip_cris_exit(void)          {}

void 	wizchip_cs_select(void)            {}

void 	wizchip_cs_deselect(void)          {}

uint8_t wizchip_bus_readbyte(uint32_t AddrSel) { return * ((volatile uint8_t *)((ptrdiff_t) AddrSel)); }

void 	wizchip_bus_writebyte(uint32_t AddrSel, uint8_t wb)  { *((volatile uint8_t*)((ptrdiff_t)AddrSel)) = wb; }

void wizchip_spi_readbytes(uint8_t *buf, uint32_t len) {}

void wizchip_spi_writebytes(const uint8_t *buf, uint32_t len) {}

void reg_wizchip_cris_cbfunc(void(*cris_en)(void), void(*cris_ex)(void))
{
   if(!cris_en || !cris_ex)
   {
      WIZCHIP.CRIS._enter = wizchip_cris_enter;
      WIZCHIP.CRIS._exit  = wizchip_cris_exit;
   }
   else
   {
      WIZCHIP.CRIS._enter = cris_en;
      WIZCHIP.CRIS._exit  = cris_ex;
   }
}

void reg_wizchip_cs_cbfunc(void(*cs_sel)(void), void(*cs_desel)(void))
{
   if(!cs_sel || !cs_desel)
   {
      WIZCHIP.CS._select   = wizchip_cs_select;
      WIZCHIP.CS._deselect = wizchip_cs_deselect;
   }
   else
   {
      WIZCHIP.CS._select   = cs_sel;
      WIZCHIP.CS._deselect = cs_desel;
   }
}

void reg_wizchip_bus_cbfunc(uint8_t(*bus_rb)(uint32_t addr), void (*bus_wb)(uint32_t addr, uint8_t wb))
{
   while(!(WIZCHIP.if_mode & _WIZCHIP_IO_MODE_BUS_));
   
   if(!bus_rb || !bus_wb)
   {
      WIZCHIP.IF.BUS._read_byte   = wizchip_bus_readbyte;
      WIZCHIP.IF.BUS._write_byte  = wizchip_bus_writebyte;
   }
   else
   {
      WIZCHIP.IF.BUS._read_byte   = bus_rb;
      WIZCHIP.IF.BUS._write_byte  = bus_wb;
   }
}

void reg_wizchip_spi_cbfunc(void (*spi_rb)(uint8_t *, uint32_t), void (*spi_wb)(const uint8_t *, uint32_t))
{
   while(!(WIZCHIP.if_mode & _WIZCHIP_IO_MODE_SPI_));
   
   if(!spi_rb || !spi_wb)
   {
      WIZCHIP.IF.SPI._read_bytes   = wizchip_spi_readbytes;
      WIZCHIP.IF.SPI._write_bytes  = wizchip_spi_writebytes;
   }
   else
   {
      WIZCHIP.IF.SPI._read_bytes   = spi_rb;
      WIZCHIP.IF.SPI._write_bytes  = spi_wb;
   }
}

int8_t ctlwizchip(ctlwizchip_type cwtype, void* arg)
{
   uint8_t tmp = 0;
   uint8_t* ptmp[2] = {0,0};
   switch(cwtype)
   {
      case CW_RESET_WIZCHIP:
         wizchip_sw_reset();
         break;
      case CW_INIT_WIZCHIP:
         if(arg != 0) 
         {
            ptmp[0] = (uint8_t*)arg;
            ptmp[1] = ptmp[0] + _WIZCHIP_SOCK_NUM_;
         }
         return wizchip_init(ptmp[0], ptmp[1]);
      case CW_CLR_INTERRUPT:
         wizchip_clrinterrupt(*((intr_kind*)arg));
         break;
      case CW_GET_INTERRUPT:
        *((intr_kind*)arg) = wizchip_getinterrupt();
         break;
      case CW_SET_INTRMASK:
         wizchip_setinterruptmask(*((intr_kind*)arg));
         break;         
      case CW_GET_INTRMASK:
         *((intr_kind*)arg) = wizchip_getinterruptmask();
         break;
   #if _WIZCHIP_ > 5100
      case CW_SET_INTRTIME:
         setINTLEVEL(*(uint16_t*)arg);
         break;
      case CW_GET_INTRTIME:
         *(uint16_t*)arg = getINTLEVEL();
         break;
   #endif
      case CW_GET_ID:
         ((uint8_t*)arg)[0] = WIZCHIP.id[0];
         ((uint8_t*)arg)[1] = WIZCHIP.id[1];
         ((uint8_t*)arg)[2] = WIZCHIP.id[2];
         ((uint8_t*)arg)[3] = WIZCHIP.id[3];
         ((uint8_t*)arg)[4] = WIZCHIP.id[4];
         ((uint8_t*)arg)[5] = 0;
         break;
   #if _WIZCHIP_ ==  5500
      case CW_RESET_PHY:
         wizphy_reset();
         break;
      case CW_SET_PHYCONF:
         wizphy_setphyconf((wiz_PhyConf*)arg);
         break;
      case CW_GET_PHYCONF:
         wizphy_getphyconf((wiz_PhyConf*)arg);
         break;
      case CW_GET_PHYSTATUS:
         break;
      case CW_SET_PHYPOWMODE:
         return wizphy_setphypmode(*(uint8_t*)arg);
   #endif
      case CW_GET_PHYPOWMODE:
         tmp = wizphy_getphypmode();
         if((int8_t)tmp == -1) return -1;
         *(uint8_t*)arg = tmp;
         break;
      case CW_GET_PHYLINK:
         tmp = wizphy_getphylink();
         if((int8_t)tmp == -1) return -1;
         *(uint8_t*)arg = tmp;
         break;
      default:
         return -1;
   }
   return 0;
}

int8_t ctlnetwork(ctlnetwork_type cntype, void* arg)
{
   
   switch(cntype)
   {
      case CN_SET_NETINFO:
         wizchip_setnetinfo((wiz_NetInfo*)arg);
         break;
      case CN_GET_NETINFO:
         wizchip_getnetinfo((wiz_NetInfo*)arg);
         break;
      case CN_SET_NETMODE:
         return wizchip_setnetmode(*(netmode_type*)arg);
      case CN_GET_NETMODE:
         *(netmode_type*)arg = wizchip_getnetmode();
         break;
      case CN_SET_TIMEOUT:
         wizchip_settimeout((wiz_NetTimeout*)arg);
         break;
      case CN_GET_TIMEOUT:
         wizchip_gettimeout((wiz_NetTimeout*)arg);
         break;
      default:
         return -1;
   }
   return 0;
}

void wizchip_sw_reset(void)
{
   uint8_t gw[4], sn[4], sip[4];
   uint8_t mac[6];
   getSHAR(mac);
   getGAR(gw);  getSUBR(sn);  getSIPR(sip);
   setMR(MR_RST);
   getMR(); // for delay
   setSHAR(mac);
   setGAR(gw);
   setSUBR(sn);
   setSIPR(sip);
}

int8_t wizchip_init(uint8_t* txsize, uint8_t* rxsize)
{
   int8_t i;
   int8_t tmp = 0;
   wizchip_sw_reset();
   if(txsize)
   {
      tmp = 0;
      for(i = 0 ; i < _WIZCHIP_SOCK_NUM_; i++)
         tmp += txsize[i];
      if(tmp > 16) return -1;
      for(i = 0 ; i < _WIZCHIP_SOCK_NUM_; i++)
         setSn_TXBUF_SIZE(i, txsize[i]);
   }
   if(rxsize)
   {
      tmp = 0;
      for(i = 0 ; i < _WIZCHIP_SOCK_NUM_; i++)
         tmp += rxsize[i];
      if(tmp > 16) return -1;
      for(i = 0 ; i < _WIZCHIP_SOCK_NUM_; i++)
         setSn_RXBUF_SIZE(i, rxsize[i]);
   }

   WIZCHIP_EXPORT(socket_reset)();

   return 0;
}

void wizchip_clrinterrupt(intr_kind intr)
{
   uint8_t ir  = (uint8_t)intr;
   uint8_t sir = (uint8_t)((uint16_t)intr >> 8);
#if _WIZCHIP_ < 5500
   ir |= (1<<4); // IK_WOL
#endif
#if _WIZCHIP_ == 5200
   ir |= (1 << 6);
#endif
   
#if _WIZCHIP_ < 5200
   sir &= 0x0F;
#endif

#if _WIZCHIP_ == 5100
   ir |= sir;
   setIR(ir);
#else
   setIR(ir);
   setSIR(sir);
#endif   
}

intr_kind wizchip_getinterrupt(void)
{
   uint8_t ir  = 0;
   uint8_t sir = 0;
   uint16_t ret = 0;
#if _WIZCHIP_ == 5100
   ir = getIR();
   sir = ir 0x0F;
#else
   ir  = getIR();
   sir = getSIR();
#endif         

#if _WIZCHIP_ < 5500
   ir &= ~(1<<4); // IK_WOL
#endif
#if _WIZCHIP_ == 5200
   ir &= ~(1 << 6);
#endif
  ret = sir;
  ret = (ret << 8) + ir;
  return (intr_kind)ret;
}

void wizchip_setinterruptmask(intr_kind intr)
{
   uint8_t imr  = (uint8_t)intr;
   uint8_t simr = (uint8_t)((uint16_t)intr >> 8);
#if _WIZCHIP_ < 5500
   imr &= ~(1<<4); // IK_WOL
#endif
#if _WIZCHIP_ == 5200
   imr &= ~(1 << 6);
#endif
   
#if _WIZCHIP_ < 5200
   simr &= 0x0F;
#endif

#if _WIZCHIP_ == 5100
   imr |= simr;
   setIMR(imr);
#else
   setIMR(imr);
   setSIMR(simr);
#endif   
}

intr_kind wizchip_getinterruptmask(void)
{
   uint8_t imr  = 0;
   uint8_t simr = 0;
   uint16_t ret = 0;
#if _WIZCHIP_ == 5100
   imr  = getIMR();
   simr = imr 0x0F;
#else
   imr  = getIMR();
   simr = getSIMR();
#endif         

#if _WIZCHIP_ < 5500
   imr &= ~(1<<4); // IK_WOL
#endif
#if _WIZCHIP_ == 5200
   imr &= ~(1 << 6);  // IK_DEST_UNREACH
#endif
  ret = simr;
  ret = (ret << 8) + imr;
  return (intr_kind)ret;
}

int8_t wizphy_getphylink(void)
{
   int8_t tmp;
#if   _WIZCHIP_ == 5200
   if(getPHYSTATUS() & PHYSTATUS_LINK)
      tmp = PHY_LINK_ON;
   else
      tmp = PHY_LINK_OFF;
#elif _WIZCHIP_ == 5500
   if(getPHYCFGR() & PHYCFGR_LNK_ON)
      tmp = PHY_LINK_ON;
   else
      tmp = PHY_LINK_OFF;
#else
   tmp = -1;
#endif
   return tmp;
}

int8_t wizphy_getphypmode(void)
{
   int8_t tmp = 0;
   #if   _WIZCHIP_ == 5200
      if(getPHYSTATUS() & PHYSTATUS_POWERDOWN)
         tmp = PHY_POWER_DOWN;
      else          
         tmp = PHY_POWER_NORM;
   #elif _WIZCHIP_ == 5500
      if(getPHYCFGR() & PHYCFGR_OPMDC_PDOWN)
         tmp = PHY_POWER_DOWN;
      else 
         tmp = PHY_POWER_NORM;
   #else
      tmp = -1;
   #endif
   return tmp;
}

void wizchip_setnetinfo(wiz_NetInfo* pnetinfo)
{
   setSHAR(pnetinfo->mac);
   setGAR(pnetinfo->gw);
   setSUBR(pnetinfo->sn);
   setSIPR(pnetinfo->ip);
#if _WIZCHIP_ == 5200   // for W5200 ARP errata
   _SUBN_[0] = pnetinfo->sn[0];
   _SUBN_[1] = pnetinfo->sn[1];
   _SUBN_[2] = pnetinfo->sn[2];
   _SUBN_[3] = pnetinfo->sn[3];
#endif
   _DNS_[0] = pnetinfo->dns[0];
   _DNS_[1] = pnetinfo->dns[1];
   _DNS_[2] = pnetinfo->dns[2];
   _DNS_[3] = pnetinfo->dns[3];
   _DHCP_   = pnetinfo->dhcp;
}

void wizchip_getnetinfo(wiz_NetInfo* pnetinfo)
{
   getSHAR(pnetinfo->mac);
   getGAR(pnetinfo->gw);
   getSUBR(pnetinfo->sn);
   getSIPR(pnetinfo->ip);
#if _WIZCHIP_ == 5200   // for W5200 ARP errata
   pnetinfo->sn[0] = _SUBN_[0];
   pnetinfo->sn[1] = _SUBN_[1];
   pnetinfo->sn[2] = _SUBN_[2];
   pnetinfo->sn[3] = _SUBN_[3];
#endif
   pnetinfo->dns[0]= _DNS_[0];
   pnetinfo->dns[1]= _DNS_[1];
   pnetinfo->dns[2]= _DNS_[2];
   pnetinfo->dns[3]= _DNS_[3];
   pnetinfo->dhcp  = _DHCP_;
}

uint8_t *wizchip_getsubn(void) {
    return _SUBN_;
}

int8_t wizchip_setnetmode(netmode_type netmode)
{
   uint8_t tmp = 0;
#if _WIZCHIP_ != 5500   
   if(netmode & ~(NM_WAKEONLAN | NM_PPPOE | NM_PINGBLOCK)) return -1;
#else
   if(netmode & ~(NM_WAKEONLAN | NM_PPPOE | NM_PINGBLOCK | NM_FORCEARP)) return -1;
#endif      
   tmp = getMR();
   tmp |= (uint8_t)netmode;
   setMR(tmp);
   return 0;
}

netmode_type wizchip_getnetmode(void)
{
   return (netmode_type) getMR();
}

void wizchip_settimeout(wiz_NetTimeout* nettime)
{
   setRCR(nettime->retry_cnt);
   setRTR(nettime->time_100us);
}

void wizchip_gettimeout(wiz_NetTimeout* nettime)
{
   nettime->retry_cnt = getRCR();
   nettime->time_100us = getRTR();
}

