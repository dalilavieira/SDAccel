
//=======================================================
//  This code is generated by Terasic System Builder
//=======================================================

module HELLO_FPGA2(

	//////////// CLOCK //////////
	CLOCK_50,
	CLOCK2_50,
	CLOCK3_50,

	//////////// Sma //////////
	SMA_CLKIN,
	SMA_CLKOUT,

	//////////// LED //////////
	LEDG,
	LEDR,

	//////////// KEY //////////
	KEY,

	//////////// EX_IO //////////
	EX_IO,

	//////////// SW //////////
	SW,

	//////////// SEG7 //////////
	HEX0,
	HEX1,
	HEX2,
	HEX3,
	HEX4,
	HEX5,
	HEX6,
	HEX7,

	//////////// LCD //////////
	LCD_BLON,
	LCD_DATA,
	LCD_EN,
	LCD_ON,
	LCD_RS,
	LCD_RW,

	//////////// RS232 //////////
	UART_CTS,
	UART_RTS,
	UART_RXD,
	UART_TXD,

	//////////// PS2 for Keyboard and Mouse //////////
	PS2_CLK,
	PS2_CLK2,
	PS2_DAT,
	PS2_DAT2,

	//////////// SDCARD //////////
	SD_CLK,
	SD_CMD,
	SD_DAT,
	SD_WP_N,

	//////////// VGA //////////
	VGA_B,
	VGA_BLANK_N,
	VGA_CLK,
	VGA_G,
	VGA_HS,
	VGA_R,
	VGA_SYNC_N,
	VGA_VS,

	//////////// Audio //////////
	AUD_ADCDAT,
	AUD_ADCLRCK,
	AUD_BCLK,
	AUD_DACDAT,
	AUD_DACLRCK,
	AUD_XCK,

	//////////// I2C for EEPROM //////////
	EEP_I2C_SCLK,
	EEP_I2C_SDAT,

	//////////// I2C for Audio Tv-Decoder HSMC  //////////
	I2C_SCLK,
	I2C_SDAT,

	//////////// Ethernet 0 //////////
	ENET0_GTX_CLK,
	ENET0_INT_N,
	ENET0_LINK100,
	ENET0_MDC,
	ENET0_MDIO,
	ENET0_RST_N,
	ENET0_RX_CLK,
	ENET0_RX_COL,
	ENET0_RX_CRS,
	ENET0_RX_DATA,
	ENET0_RX_DV,
	ENET0_RX_ER,
	ENET0_TX_CLK,
	ENET0_TX_DATA,
	ENET0_TX_EN,
	ENET0_TX_ER,
	ENETCLK_25,

	//////////// Ethernet 1 //////////
	ENET1_GTX_CLK,
	ENET1_INT_N,
	ENET1_LINK100,
	ENET1_MDC,
	ENET1_MDIO,
	ENET1_RST_N,
	ENET1_RX_CLK,
	ENET1_RX_COL,
	ENET1_RX_CRS,
	ENET1_RX_DATA,
	ENET1_RX_DV,
	ENET1_RX_ER,
	ENET1_TX_CLK,
	ENET1_TX_DATA,
	ENET1_TX_EN,
	ENET1_TX_ER,

	//////////// TV Decoder //////////
	TD_CLK27,
	TD_DATA,
	TD_HS,
	TD_RESET_N,
	TD_VS,

	//////////// USB 2.0 OTG //////////
	OTG_ADDR,
	OTG_CS_N,
	OTG_DACK_N,
	OTG_DATA,
	OTG_DREQ,
	OTG_FSPEED,
	OTG_INT,
	OTG_LSPEED,
	OTG_RD_N,
	OTG_RST_N,
	OTG_WE_N,

	//////////// IR Receiver //////////
	IRDA_RXD,

	//////////// SDRAM //////////
	DRAM_ADDR,
	DRAM_BA,
	DRAM_CAS_N,
	DRAM_CKE,
	DRAM_CLK,
	DRAM_CS_N,
	DRAM_DQ,
	DRAM_DQM,
	DRAM_RAS_N,
	DRAM_WE_N,

	//////////// SRAM //////////
	SRAM_ADDR,
	SRAM_CE_N,
	SRAM_DQ,
	SRAM_LB_N,
	SRAM_OE_N,
	SRAM_UB_N,
	SRAM_WE_N,

	//////////// Flash //////////
	FL_ADDR,
	FL_CE_N,
	FL_DQ,
	FL_OE_N,
	FL_RST_N,
	FL_RY,
	FL_WE_N,
	FL_WP_N,

	//////////// GPIO, GPIO connect to GPIO Default //////////
	gpioGPIO,

	//////////// HSMC, HSMC connect to HSMC Default //////////
	hsmcCLKIN_N1,
	hsmcCLKIN_N2,
	hsmcCLKIN_P1,
	hsmcCLKIN_P2,
	hsmcCLKIN0,
	hsmcCLKOUT_N1,
	hsmcCLKOUT_N2,
	hsmcCLKOUT_P1,
	hsmcCLKOUT_P2,
	hsmcCLKOUT0,
	hsmcD,
	hsmcRX_D_N,
	hsmcRX_D_P,
	hsmcTX_D_N,
	hsmcTX_D_P
);

//=======================================================
//  PARAMETER declarations
//=======================================================


//=======================================================
//  PORT declarations
//=======================================================

//////////// CLOCK //////////
input 		          		CLOCK_50;
input 		          		CLOCK2_50;
input 		          		CLOCK3_50;

//////////// Sma //////////
input 		          		SMA_CLKIN;
output		          		SMA_CLKOUT;

//////////// LED //////////
output		     [8:0]		LEDG;
output		    [17:0]		LEDR;

//////////// KEY //////////
input 		     [3:0]		KEY;

//////////// EX_IO //////////
inout 		     [6:0]		EX_IO;

//////////// SW //////////
input 		    [17:0]		SW;

//////////// SEG7 //////////
output		     [6:0]		HEX0;
output		     [6:0]		HEX1;
output		     [6:0]		HEX2;
output		     [6:0]		HEX3;
output		     [6:0]		HEX4;
output		     [6:0]		HEX5;
output		     [6:0]		HEX6;
output		     [6:0]		HEX7;

//////////// LCD //////////
output		          		LCD_BLON;
inout 		     [7:0]		LCD_DATA;
output		          		LCD_EN;
output		          		LCD_ON;
output		          		LCD_RS;
output		          		LCD_RW;

//////////// RS232 //////////
output		          		UART_CTS;
input 		          		UART_RTS;
input 		          		UART_RXD;
output		          		UART_TXD;

//////////// PS2 for Keyboard and Mouse //////////
inout 		          		PS2_CLK;
inout 		          		PS2_CLK2;
inout 		          		PS2_DAT;
inout 		          		PS2_DAT2;

//////////// SDCARD //////////
output		          		SD_CLK;
inout 		          		SD_CMD;
inout 		     [3:0]		SD_DAT;
input 		          		SD_WP_N;

//////////// VGA //////////
output		     [7:0]		VGA_B;
output		          		VGA_BLANK_N;
output		          		VGA_CLK;
output		     [7:0]		VGA_G;
output		          		VGA_HS;
output		     [7:0]		VGA_R;
output		          		VGA_SYNC_N;
output		          		VGA_VS;

//////////// Audio //////////
input 		          		AUD_ADCDAT;
inout 		          		AUD_ADCLRCK;
inout 		          		AUD_BCLK;
output		          		AUD_DACDAT;
inout 		          		AUD_DACLRCK;
output		          		AUD_XCK;

//////////// I2C for EEPROM //////////
output		          		EEP_I2C_SCLK;
inout 		          		EEP_I2C_SDAT;

//////////// I2C for Audio Tv-Decoder HSMC  //////////
output		          		I2C_SCLK;
inout 		          		I2C_SDAT;

//////////// Ethernet 0 //////////
output		          		ENET0_GTX_CLK;
input 		          		ENET0_INT_N;
input 		          		ENET0_LINK100;
output		          		ENET0_MDC;
inout 		          		ENET0_MDIO;
output		          		ENET0_RST_N;
input 		          		ENET0_RX_CLK;
input 		          		ENET0_RX_COL;
input 		          		ENET0_RX_CRS;
input 		     [3:0]		ENET0_RX_DATA;
input 		          		ENET0_RX_DV;
input 		          		ENET0_RX_ER;
input 		          		ENET0_TX_CLK;
output		     [3:0]		ENET0_TX_DATA;
output		          		ENET0_TX_EN;
output		          		ENET0_TX_ER;
input 		          		ENETCLK_25;

//////////// Ethernet 1 //////////
output		          		ENET1_GTX_CLK;
input 		          		ENET1_INT_N;
input 		          		ENET1_LINK100;
output		          		ENET1_MDC;
inout 		          		ENET1_MDIO;
output		          		ENET1_RST_N;
input 		          		ENET1_RX_CLK;
input 		          		ENET1_RX_COL;
input 		          		ENET1_RX_CRS;
input 		     [3:0]		ENET1_RX_DATA;
input 		          		ENET1_RX_DV;
input 		          		ENET1_RX_ER;
input 		          		ENET1_TX_CLK;
output		     [3:0]		ENET1_TX_DATA;
output		          		ENET1_TX_EN;
output		          		ENET1_TX_ER;

//////////// TV Decoder //////////
input 		          		TD_CLK27;
input 		     [7:0]		TD_DATA;
input 		          		TD_HS;
output		          		TD_RESET_N;
input 		          		TD_VS;

//////////// USB 2.0 OTG //////////
output		     [1:0]		OTG_ADDR;
output		          		OTG_CS_N;
output		     [1:0]		OTG_DACK_N;
inout 		    [15:0]		OTG_DATA;
input 		     [1:0]		OTG_DREQ;
inout 		          		OTG_FSPEED;
input 		     [1:0]		OTG_INT;
inout 		          		OTG_LSPEED;
output		          		OTG_RD_N;
output		          		OTG_RST_N;
output		          		OTG_WE_N;

//////////// IR Receiver //////////
input 		          		IRDA_RXD;

//////////// SDRAM //////////
output		    [12:0]		DRAM_ADDR;
output		     [1:0]		DRAM_BA;
output		          		DRAM_CAS_N;
output		          		DRAM_CKE;
output		          		DRAM_CLK;
output		          		DRAM_CS_N;
inout 		    [31:0]		DRAM_DQ;
output		     [3:0]		DRAM_DQM;
output		          		DRAM_RAS_N;
output		          		DRAM_WE_N;

//////////// SRAM //////////
output		    [19:0]		SRAM_ADDR;
output		          		SRAM_CE_N;
inout 		    [15:0]		SRAM_DQ;
output		          		SRAM_LB_N;
output		          		SRAM_OE_N;
output		          		SRAM_UB_N;
output		          		SRAM_WE_N;

//////////// Flash //////////
output		    [22:0]		FL_ADDR;
output		          		FL_CE_N;
inout 		     [7:0]		FL_DQ;
output		          		FL_OE_N;
output		          		FL_RST_N;
input 		          		FL_RY;
output		          		FL_WE_N;
output		          		FL_WP_N;

//////////// GPIO, GPIO connect to GPIO Default //////////
inout 		    [35:0]		gpioGPIO;

//////////// HSMC, HSMC connect to HSMC Default //////////
input 		          		hsmcCLKIN_N1;
input 		          		hsmcCLKIN_N2;
input 		          		hsmcCLKIN_P1;
input 		          		hsmcCLKIN_P2;
input 		          		hsmcCLKIN0;
output		          		hsmcCLKOUT_N1;
output		          		hsmcCLKOUT_N2;
output		          		hsmcCLKOUT_P1;
output		          		hsmcCLKOUT_P2;
output		          		hsmcCLKOUT0;
inout 		     [3:0]		hsmcD;
inout 		    [16:0]		hsmcRX_D_N;
inout 		    [16:0]		hsmcRX_D_P;
inout 		    [16:0]		hsmcTX_D_N;
inout 		    [16:0]		hsmcTX_D_P;

reg clock;
reg [31:0] clock_divisor;
reg reset;
reg [8:0] ledr;
reg ledg;
reg start;
reg [3:0] displays_in[7:0];
integer i;

assign LEDR[8:0] = ledr[8:0];
assign LEDG[8] = ledg;

wire out;
wire [32-1:0] evalResult;

initial begin
	clock_divisor = 0;
	clock = 0;
	ledr = 0;
	displays_in[0] <= 1;
	displays_in[1] <= 0;
	displays_in[2] <= 0;
	displays_in[3] <= 0;
	displays_in[4] <= 0;
	displays_in[5] <= 0;
	displays_in[6] <= 0;
	displays_in[7] <= 0;
end
	
always @(posedge CLOCK_50) begin

	if(clock_divisor == 50000) begin
		clock_divisor = 0;
		clock =~ clock;
	end
	
	clock_divisor = clock_divisor + 1;
		
end

always@(clock)begin
	//if(SW[0] == 1)	begin//start
		ledr[8] <= 1;
		if(SW[0] == 1) begin
			displays_in[0] <= clock;
		end
		else if(SW[1] == 1) begin
			displays_in[0] <= evalResult[3:0];
			displays_in[1] <= evalResult[7:4];
			displays_in[2] <= evalResult[11:8];
			displays_in[3] <= evalResult[15:12];
			displays_in[4] <= evalResult[19:16];
			displays_in[5] <= evalResult[23:20];
			displays_in[6] <= evalResult[27:24];
			displays_in[7] <= evalResult[31:28];
		end
end

mDecoder display0(
 .in(displays_in[0]),
 .out(HEX0)
);

mDecoder display1(
 .in(displays_in[1]),
 .out(HEX1)
);

mDecoder display2(
 .in(displays_in[2]),
 .out(HEX2)
);

mDecoder display3(
 .in(displays_in[3]),
 .out(HEX3)
);


mDecoder display4(
 .in(displays_in[4]),
 .out(HEX4)
);


mDecoder display5(
 .in(displays_in[5]),
 .out(HEX5)
);

mDecoder display6(
 .in(displays_in[6]),
 .out(HEX6)
);

mDecoder display7(
 .in(displays_in[7]),
 .out(HEX7)
);

placement p1 (out, clock, reset, evalResult);

endmodule
