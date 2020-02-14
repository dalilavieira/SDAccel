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
typedef  int u8 ;
typedef  int u16 ;
struct spi_device {int bits_per_word; int /*<<< orphan*/  chip_select; } ;

/* Variables and functions */
 int DS26522_BERT_ADDR_END ; 
 int DS26522_BERT_ADDR_START ; 
 int DS26522_E1TAF_ADDR ; 
 int DS26522_E1TAF_DEFAULT ; 
 int DS26522_E1TNAF_ADDR ; 
 int DS26522_E1TNAF_DEFAULT ; 
 int DS26522_GFCR_ADDR ; 
 int DS26522_GFCR_BPCLK_2048KHZ ; 
 int DS26522_GFSRR_ADDR ; 
 int DS26522_GFSRR_NORMAL ; 
 int DS26522_GFSRR_RESET ; 
 int DS26522_GLSRR_ADDR ; 
 int DS26522_GLSRR_NORMAL ; 
 int DS26522_GLSRR_RESET ; 
 int DS26522_GTCCR_ADDR ; 
 int DS26522_GTCCR_BFREQSEL_2048KHZ ; 
 int DS26522_GTCCR_BPREFSEL_REFCLKIN ; 
 int DS26522_GTCCR_FREQSEL_2048KHZ ; 
 int DS26522_GTCR1 ; 
 int DS26522_GTCR1_ADDR ; 
 int DS26522_GTCR2_ADDR ; 
 int DS26522_GTCR2_TSSYNCOUT ; 
 int DS26522_IDR_ADDR ; 
 int DS26522_LIU_ADDR_END ; 
 int DS26522_LIU_ADDR_START ; 
 int DS26522_LMCR_ADDR ; 
 int DS26522_LMCR_TE ; 
 int DS26522_LRISMR_75OHM ; 
 int DS26522_LRISMR_ADDR ; 
 int DS26522_LRISMR_MAX ; 
 int DS26522_LTITSR_ADDR ; 
 int DS26522_LTITSR_LBOS_75OHM ; 
 int DS26522_LTITSR_TLIS_75OHM ; 
 int DS26522_LTRCR_ADDR ; 
 int DS26522_LTRCR_E1 ; 
 int DS26522_RCR1_ADDR ; 
 int DS26522_RCR1_E1_CCS ; 
 int DS26522_RCR1_E1_HDB3 ; 
 int DS26522_RF_ADDR_END ; 
 int DS26522_RF_ADDR_START ; 
 int DS26522_RIOCR_2048KHZ ; 
 int DS26522_RIOCR_ADDR ; 
 int DS26522_RIOCR_RSIO_OUT ; 
 int DS26522_RMMR_ADDR ; 
 int DS26522_RMMR_E1 ; 
 int DS26522_RMMR_FRM_EN ; 
 int DS26522_RMMR_INIT_DONE ; 
 int DS26522_RMMR_SFTRST ; 
 int DS26522_TCR1_ADDR ; 
 int DS26522_TCR1_TB8ZS ; 
 int DS26522_TF_ADDR_END ; 
 int DS26522_TF_ADDR_START ; 
 int DS26522_TIOCR_2048KHZ ; 
 int DS26522_TIOCR_ADDR ; 
 int DS26522_TIOCR_TSIO_OUT ; 
 int DS26522_TMMR_ADDR ; 
 int DS26522_TMMR_E1 ; 
 int DS26522_TMMR_FRM_EN ; 
 int DS26522_TMMR_INIT_DONE ; 
 int DS26522_TMMR_SFTRST ; 
 int /*<<< orphan*/  SLIC_THREE_LEN ; 
 int /*<<< orphan*/  SLIC_TRANS_LEN ; 
 int /*<<< orphan*/  SLIC_TWO_LEN ; 
 int bitrev16 (int) ; 
 int bitrev8 (int) ; 
 struct spi_device* g_spi ; 
 int /*<<< orphan*/  pr_info (char*,...) ; 
 int /*<<< orphan*/  spi_write (struct spi_device*,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spi_write_then_read (struct spi_device*,int*,int /*<<< orphan*/ ,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static void slic_write(struct spi_device *spi, u16 addr,
		       u8 data)
{
	u8 temp[3];

	addr = bitrev16(addr) >> 1;
	data = bitrev8(data);
	temp[0] = (u8)((addr >> 8) & 0x7f);
	temp[1] = (u8)(addr & 0xfe);
	temp[2] = data;

	/* write spi addr and value */
	spi_write(spi, &temp[0], SLIC_THREE_LEN);
}

__attribute__((used)) static u8 slic_read(struct spi_device *spi, u16 addr)
{
	u8 temp[2];
	u8 data;

	addr = bitrev16(addr) >> 1;
	temp[0] = (u8)(((addr >> 8) & 0x7f) | 0x80);
	temp[1] = (u8)(addr & 0xfe);

	spi_write_then_read(spi, &temp[0], SLIC_TWO_LEN, &data,
			    SLIC_TRANS_LEN);

	data = bitrev8(data);
	return data;
}

__attribute__((used)) static bool get_slic_product_code(struct spi_device *spi)
{
	u8 device_id;

	device_id = slic_read(spi, DS26522_IDR_ADDR);
	if ((device_id & 0xf8) == 0x68)
		return true;
	else
		return false;
}

__attribute__((used)) static void ds26522_e1_spec_config(struct spi_device *spi)
{
	/* Receive E1 Mode, Framer Disabled */
	slic_write(spi, DS26522_RMMR_ADDR, DS26522_RMMR_E1);

	/* Transmit E1 Mode, Framer Disable */
	slic_write(spi, DS26522_TMMR_ADDR, DS26522_TMMR_E1);

	/* Receive E1 Mode Framer Enable */
	slic_write(spi, DS26522_RMMR_ADDR,
		   slic_read(spi, DS26522_RMMR_ADDR) | DS26522_RMMR_FRM_EN);

	/* Transmit E1 Mode Framer Enable */
	slic_write(spi, DS26522_TMMR_ADDR,
		   slic_read(spi, DS26522_TMMR_ADDR) | DS26522_TMMR_FRM_EN);

	/* RCR1, receive E1 B8zs & ESF */
	slic_write(spi, DS26522_RCR1_ADDR,
		   DS26522_RCR1_E1_HDB3 | DS26522_RCR1_E1_CCS);

	/* RSYSCLK=2.048MHz, RSYNC-Output */
	slic_write(spi, DS26522_RIOCR_ADDR,
		   DS26522_RIOCR_2048KHZ | DS26522_RIOCR_RSIO_OUT);

	/* TCR1 Transmit E1 b8zs */
	slic_write(spi, DS26522_TCR1_ADDR, DS26522_TCR1_TB8ZS);

	/* TSYSCLK=2.048MHz, TSYNC-Output */
	slic_write(spi, DS26522_TIOCR_ADDR,
		   DS26522_TIOCR_2048KHZ | DS26522_TIOCR_TSIO_OUT);

	/* Set E1TAF */
	slic_write(spi, DS26522_E1TAF_ADDR, DS26522_E1TAF_DEFAULT);

	/* Set E1TNAF register */
	slic_write(spi, DS26522_E1TNAF_ADDR, DS26522_E1TNAF_DEFAULT);

	/* Receive E1 Mode Framer Enable & init Done */
	slic_write(spi, DS26522_RMMR_ADDR, slic_read(spi, DS26522_RMMR_ADDR) |
		   DS26522_RMMR_INIT_DONE);

	/* Transmit E1 Mode Framer Enable & init Done */
	slic_write(spi, DS26522_TMMR_ADDR, slic_read(spi, DS26522_TMMR_ADDR) |
		   DS26522_TMMR_INIT_DONE);

	/* Configure LIU E1 mode */
	slic_write(spi, DS26522_LTRCR_ADDR, DS26522_LTRCR_E1);

	/* E1 Mode default 75 ohm w/Transmit Impedance Matlinking */
	slic_write(spi, DS26522_LTITSR_ADDR,
		   DS26522_LTITSR_TLIS_75OHM | DS26522_LTITSR_LBOS_75OHM);

	/* E1 Mode default 75 ohm Long Haul w/Receive Impedance Matlinking */
	slic_write(spi, DS26522_LRISMR_ADDR,
		   DS26522_LRISMR_75OHM | DS26522_LRISMR_MAX);

	/* Enable Transmit output */
	slic_write(spi, DS26522_LMCR_ADDR, DS26522_LMCR_TE);
}

__attribute__((used)) static int slic_ds26522_init_configure(struct spi_device *spi)
{
	u16 addr;

	/* set clock */
	slic_write(spi, DS26522_GTCCR_ADDR, DS26522_GTCCR_BPREFSEL_REFCLKIN |
			DS26522_GTCCR_BFREQSEL_2048KHZ |
			DS26522_GTCCR_FREQSEL_2048KHZ);
	slic_write(spi, DS26522_GTCR2_ADDR, DS26522_GTCR2_TSSYNCOUT);
	slic_write(spi, DS26522_GFCR_ADDR, DS26522_GFCR_BPCLK_2048KHZ);

	/* set gtcr */
	slic_write(spi, DS26522_GTCR1_ADDR, DS26522_GTCR1);

	/* Global LIU Software Reset Register */
	slic_write(spi, DS26522_GLSRR_ADDR, DS26522_GLSRR_RESET);

	/* Global Framer and BERT Software Reset Register */
	slic_write(spi, DS26522_GFSRR_ADDR, DS26522_GFSRR_RESET);

	usleep_range(100, 120);

	slic_write(spi, DS26522_GLSRR_ADDR, DS26522_GLSRR_NORMAL);
	slic_write(spi, DS26522_GFSRR_ADDR, DS26522_GFSRR_NORMAL);

	/* Perform RX/TX SRESET,Reset receiver */
	slic_write(spi, DS26522_RMMR_ADDR, DS26522_RMMR_SFTRST);

	/* Reset tranceiver */
	slic_write(spi, DS26522_TMMR_ADDR, DS26522_TMMR_SFTRST);

	usleep_range(100, 120);

	/* Zero all Framer Registers */
	for (addr = DS26522_RF_ADDR_START; addr <= DS26522_RF_ADDR_END;
	     addr++)
		slic_write(spi, addr, 0);

	for (addr = DS26522_TF_ADDR_START; addr <= DS26522_TF_ADDR_END;
	     addr++)
		slic_write(spi, addr, 0);

	for (addr = DS26522_LIU_ADDR_START; addr <= DS26522_LIU_ADDR_END;
	     addr++)
		slic_write(spi, addr, 0);

	for (addr = DS26522_BERT_ADDR_START; addr <= DS26522_BERT_ADDR_END;
	     addr++)
		slic_write(spi, addr, 0);

	/* setup ds26522 for E1 specification */
	ds26522_e1_spec_config(spi);

	slic_write(spi, DS26522_GTCR1_ADDR, 0x00);

	return 0;
}

__attribute__((used)) static int slic_ds26522_remove(struct spi_device *spi)
{
	pr_info("DS26522 module uninstalled\n");
	return 0;
}

__attribute__((used)) static int slic_ds26522_probe(struct spi_device *spi)
{
	int ret = 0;

	g_spi = spi;
	spi->bits_per_word = 8;

	if (!get_slic_product_code(spi))
		return ret;

	ret = slic_ds26522_init_configure(spi);
	if (ret == 0)
		pr_info("DS26522 cs%d configured\n", spi->chip_select);

	return ret;
}

