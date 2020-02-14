#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
struct mantis_pci {int* mac_address; int subsystem_device; int gpio_status; int /*<<< orphan*/  mantis_mmio; int /*<<< orphan*/  mantis_addr; int /*<<< orphan*/  latency; TYPE_2__* pdev; int /*<<< orphan*/  subsystem_vendor; int /*<<< orphan*/  revision; TYPE_3__* hwconfig; int /*<<< orphan*/  adapter; int /*<<< orphan*/  intmask_lock; } ;
struct i2c_msg {int addr; int* buf; int len; int /*<<< orphan*/  flags; } ;
struct TYPE_12__ {int /*<<< orphan*/  dev_type; int /*<<< orphan*/  model_name; } ;
struct TYPE_11__ {int /*<<< orphan*/  irq; int /*<<< orphan*/  devfn; TYPE_1__* bus; } ;
struct TYPE_10__ {int /*<<< orphan*/  number; } ;

/* Variables and functions */
#define  CINERGY_C 136 
 int /*<<< orphan*/  I2C_M_RD ; 
 int /*<<< orphan*/  MANTIS_DEBUG ; 
 int /*<<< orphan*/  MANTIS_ERROR ; 
 int MANTIS_GPIF_ADDR ; 
 int MANTIS_GPIF_DOUT ; 
 int MANTIS_INT_MASK ; 
#define  MANTIS_VP_1033_DVB_S 135 
#define  MANTIS_VP_1034_DVB_S 134 
#define  MANTIS_VP_1041_DVB_S2 133 
#define  MANTIS_VP_2033_DVB_C 132 
#define  MANTIS_VP_2040_DVB_C 131 
#define  MANTIS_VP_3030_DVB_T 130 
 int /*<<< orphan*/  PCI_FUNC (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PCI_SLOT (int /*<<< orphan*/ ) ; 
#define  TECHNISAT_CABLESTAR_HD2 129 
#define  TECHNISAT_SKYSTAR_HD2 128 
 int /*<<< orphan*/  dprintk (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,char*,...) ; 
 int i2c_transfer (int /*<<< orphan*/ *,struct i2c_msg*,int) ; 
 scalar_t__ mantis_dma_exit (struct mantis_pci*) ; 
 int mantis_dma_init (struct mantis_pci*) ; 
 int /*<<< orphan*/  mantis_dma_stop (struct mantis_pci*) ; 
 scalar_t__ mantis_dvb_exit (struct mantis_pci*) ; 
 int mantis_dvb_init (struct mantis_pci*) ; 
 scalar_t__ mantis_i2c_exit (struct mantis_pci*) ; 
 int mantis_i2c_init (struct mantis_pci*) ; 
 int /*<<< orphan*/  mantis_uart_exit (struct mantis_pci*) ; 
 int mantis_uart_init (struct mantis_pci*) ; 
 int mmread (int) ; 
 int /*<<< orphan*/  mmwrite (int,int) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  udelay (int) ; 
 TYPE_3__ unknown_device ; 
 int /*<<< orphan*/  verbose ; 
 TYPE_3__ vp1033_mantis_config ; 
 TYPE_3__ vp1034_mantis_config ; 
 TYPE_3__ vp1041_mantis_config ; 
 TYPE_3__ vp2033_mantis_config ; 
 TYPE_3__ vp2040_mantis_config ; 
 TYPE_3__ vp3030_mantis_config ; 

__attribute__((used)) static inline void mantis_mask_ints(struct mantis_pci *mantis, u32 mask)
{
	unsigned long flags;

	spin_lock_irqsave(&mantis->intmask_lock, flags);
	mmwrite(mmread(MANTIS_INT_MASK) & ~mask, MANTIS_INT_MASK);
	spin_unlock_irqrestore(&mantis->intmask_lock, flags);
}

__attribute__((used)) static inline void mantis_unmask_ints(struct mantis_pci *mantis, u32 mask)
{
	unsigned long flags;

	spin_lock_irqsave(&mantis->intmask_lock, flags);
	mmwrite(mmread(MANTIS_INT_MASK) | mask, MANTIS_INT_MASK);
	spin_unlock_irqrestore(&mantis->intmask_lock, flags);
}

__attribute__((used)) static int read_eeprom_byte(struct mantis_pci *mantis, u8 *data, u8 length)
{
	int err;
	struct i2c_msg msg[] = {
		{
			.addr = 0x50,
			.flags = 0,
			.buf = data,
			.len = 1
		}, {
			.addr = 0x50,
			.flags = I2C_M_RD,
			.buf = data,
			.len = length
		},
	};

	err = i2c_transfer(&mantis->adapter, msg, 2);
	if (err < 0) {
		dprintk(verbose, MANTIS_ERROR, 1,
			"ERROR: i2c read: < err=%i d0=0x%02x d1=0x%02x >",
			err, data[0], data[1]);

		return err;
	}

	return 0;
}

__attribute__((used)) static int get_mac_address(struct mantis_pci *mantis)
{
	int err;

	mantis->mac_address[0] = 0x08;
	err = read_eeprom_byte(mantis, &mantis->mac_address[0], 6);
	if (err < 0) {
		dprintk(verbose, MANTIS_ERROR, 1, "Mantis EEPROM read error");

		return err;
	}
	dprintk(verbose, MANTIS_ERROR, 0,
		"    MAC Address=[%pM]\n", mantis->mac_address);

	return 0;
}

__attribute__((used)) static void mantis_load_config(struct mantis_pci *mantis)
{
	switch (mantis->subsystem_device) {
	case MANTIS_VP_1033_DVB_S:	/* VP-1033 */
		mantis->hwconfig = &vp1033_mantis_config;
		break;
	case MANTIS_VP_1034_DVB_S:	/* VP-1034 */
		mantis->hwconfig = &vp1034_mantis_config;
		break;
	case MANTIS_VP_1041_DVB_S2:	/* VP-1041 */
	case TECHNISAT_SKYSTAR_HD2:
		mantis->hwconfig = &vp1041_mantis_config;
		break;
	case MANTIS_VP_2033_DVB_C:	/* VP-2033 */
		mantis->hwconfig = &vp2033_mantis_config;
		break;
	case MANTIS_VP_2040_DVB_C:	/* VP-2040 */
	case CINERGY_C:	/* VP-2040 clone */
	case TECHNISAT_CABLESTAR_HD2:
		mantis->hwconfig = &vp2040_mantis_config;
		break;
	case MANTIS_VP_3030_DVB_T:	/* VP-3030 */
		mantis->hwconfig = &vp3030_mantis_config;
		break;
	default:
		mantis->hwconfig = &unknown_device;
		break;
	}
}

int mantis_core_init(struct mantis_pci *mantis)
{
	int err = 0;

	mantis_load_config(mantis);
	dprintk(verbose, MANTIS_ERROR, 0, "found a %s PCI %s device on (%02x:%02x.%x),\n",
		mantis->hwconfig->model_name, mantis->hwconfig->dev_type,
		mantis->pdev->bus->number, PCI_SLOT(mantis->pdev->devfn), PCI_FUNC(mantis->pdev->devfn));
	dprintk(verbose, MANTIS_ERROR, 0, "    Mantis Rev %d [%04x:%04x], ",
		mantis->revision,
		mantis->subsystem_vendor, mantis->subsystem_device);
	dprintk(verbose, MANTIS_ERROR, 0,
		"irq: %d, latency: %d\n    memory: 0x%lx, mmio: 0x%p\n",
		mantis->pdev->irq, mantis->latency,
		mantis->mantis_addr, mantis->mantis_mmio);

	err = mantis_i2c_init(mantis);
	if (err < 0) {
		dprintk(verbose, MANTIS_ERROR, 1, "Mantis I2C init failed");
		return err;
	}
	err = get_mac_address(mantis);
	if (err < 0) {
		dprintk(verbose, MANTIS_ERROR, 1, "get MAC address failed");
		return err;
	}
	err = mantis_dma_init(mantis);
	if (err < 0) {
		dprintk(verbose, MANTIS_ERROR, 1, "Mantis DMA init failed");
		return err;
	}
	err = mantis_dvb_init(mantis);
	if (err < 0) {
		dprintk(verbose, MANTIS_DEBUG, 1, "Mantis DVB init failed");
		return err;
	}
	err = mantis_uart_init(mantis);
	if (err < 0) {
		dprintk(verbose, MANTIS_DEBUG, 1, "Mantis UART init failed");
		return err;
	}

	return 0;
}

int mantis_core_exit(struct mantis_pci *mantis)
{
	mantis_dma_stop(mantis);
	dprintk(verbose, MANTIS_ERROR, 1, "DMA engine stopping");

	mantis_uart_exit(mantis);
	dprintk(verbose, MANTIS_ERROR, 1, "UART exit failed");

	if (mantis_dma_exit(mantis) < 0)
		dprintk(verbose, MANTIS_ERROR, 1, "DMA exit failed");
	if (mantis_dvb_exit(mantis) < 0)
		dprintk(verbose, MANTIS_ERROR, 1, "DVB exit failed");
	if (mantis_i2c_exit(mantis) < 0)
		dprintk(verbose, MANTIS_ERROR, 1, "I2C adapter delete.. failed");

	return 0;
}

void gpio_set_bits(struct mantis_pci *mantis, u32 bitpos, u8 value)
{
	u32 cur;

	cur = mmread(MANTIS_GPIF_ADDR);
	if (value)
		mantis->gpio_status = cur | (1 << bitpos);
	else
		mantis->gpio_status = cur & (~(1 << bitpos));

	mmwrite(mantis->gpio_status, MANTIS_GPIF_ADDR);
	mmwrite(0x00, MANTIS_GPIF_DOUT);
	udelay(100);
}

void mantis_set_direction(struct mantis_pci *mantis, int direction)
{
	u32 reg;

	reg = mmread(0x28);
	dprintk(verbose, MANTIS_DEBUG, 1, "TS direction setup");
	if (direction == 0x01) {
		/* to CI */
		reg |= 0x04;
		mmwrite(reg, 0x28);
		reg &= 0xff - 0x04;
		mmwrite(reg, 0x28);
	} else {
		reg &= 0xff - 0x04;
		mmwrite(reg, 0x28);
		reg |= 0x04;
		mmwrite(reg, 0x28);
	}
}

