//////////////////////////////////////////////////////////////////////////
//			SAM D - Cortex M0+ SERCOM Source Code
//	Author: Andres Vasquez
//	Purpose: THis code is in charge of the necessary transactions that
//				are to take place between any main code and the code 
//				necessary to send data through the SERCOM peripherals
//////////////////////////////////////////////////////////////////////////
#include "main.h"
#include "bastian_sercom.h"

#define LED_DEBUG	PIN_PA24

void fcnSPIconfiguration (void);
static void spi_slave_callback_transmitted(const struct spi_module *const module);
static void spi_slave_callback_received(const struct spi_module *const module);
static void spi_slave_callback_transceived(const struct spi_module *const module);

////////////////////  BASTIAN SERCOM  ////////////////////////////////////
//		MODULE: Slave Module -> spi_slave
//		module handler for the SPI interaction with RED
struct spi_module spi_slave;

////////////////////  BASTIAN SERCOM  ////////////////////////////////////
//		Perform complete SERCOM module setup for the application
//		Takes no arguments
void bastian_complete_sercom_setup(void) {
	// Configure the SPI
	fcnSPIconfiguration();
	
}

void fcnSPIconfiguration (void) {
	//////////////////////////////////////////////////////////////////////////
	// "SHIELD" communication module Setup for Red
	// Declare our configuration parameters
	struct spi_config spi_conf;

	// Initialize them to default values
	spi_get_config_defaults(&spi_conf);
	
	spi_conf.mode = SPI_MODE_SLAVE;
	spi_conf.mode_specific.slave.preload_enable = true;
	//spi_conf.
	spi_conf.mode_specific.slave.frame_format = SPI_FRAME_FORMAT_SPI_FRAME;
	spi_conf.mux_setting = SPI_SIGNAL_MUX_SETTING_I;
	// Pad Configuration
	spi_conf.pinmux_pad0 = PINMUX_PA14D_SERCOM2_PAD0;
	spi_conf.pinmux_pad1 = PINMUX_PA15D_SERCOM2_PAD1;
	spi_conf.pinmux_pad2 = PINMUX_PA16D_SERCOM2_PAD2;
	spi_conf.pinmux_pad3 = PINMUX_PA25D_SERCOM2_PAD3;
	

	// Initialize the previous settings
	spi_init(&spi_slave, SERCOM2, &spi_conf);

	// Enable the module
	spi_enable(&spi_slave);

	// ******** Callback setup
	spi_register_callback(&spi_slave, spi_slave_callback_received, SPI_CALLBACK_BUFFER_RECEIVED);
	spi_enable_callback(&spi_slave, SPI_CALLBACK_BUFFER_RECEIVED);

	spi_register_callback(&spi_slave, spi_slave_callback_transmitted, SPI_CALLBACK_BUFFER_TRANSMITTED);
	spi_enable_callback(&spi_slave, SPI_CALLBACK_BUFFER_TRANSMITTED);
	
	spi_register_callback(&spi_slave, spi_slave_callback_transceived, SPI_CALLBACK_BUFFER_TRANSCEIVED);
	spi_enable_callback(&spi_slave, SPI_CALLBACK_BUFFER_TRANSCEIVED);
}




//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
////////////////////// SPI CALLBACK FUNCTIONS ////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// SPI RX Callback Function
static void spi_slave_callback_received(const struct spi_module *const module) {
	
}
// SPI RX Callback Function
static void spi_slave_callback_transmitted(const struct spi_module *const module) {
	
}


// SPI RX Callback Function
static void spi_slave_callback_transceived(const struct spi_module *const module) {
	
	
}