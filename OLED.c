#include "OLED.h"


#define SIZE 4
/// SPI MOSI pin definition.
#define PIN_SPI_MOSI   {1 << 13, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
/// SPI SPCK pin definition.
#define PIN_SPI_SPCK   {1 << 14, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
/// List of SPI pin definitions (MISO, MOSI & SPCK).
#define PINS_NEW_SPI       PIN_SPI_NPCS2, PIN_SPI_MOSI, PIN_SPI_SPCK
/// SPI chip select 2 pin definition - mjc
#define PIN_SPI_NPCS2  {1 << 10, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}

       static const Pin at91board_OLED[] ={PINS_NEW_SPI};    
    
    
    /*typedef struct _AT91S_SPI {
	AT91_REG	 SPI_CR; 	// Control Register
	AT91_REG	 SPI_MR; 	// Mode Register
	AT91_REG	 SPI_RDR; 	// Receive Data Register
	AT91_REG	 SPI_TDR; 	// Transmit Data Register
	AT91_REG	 SPI_SR; 	// Status Register
	AT91_REG	 SPI_IER; 	// Interrupt Enable Register
	AT91_REG	 SPI_IDR; 	// Interrupt Disable Register
	AT91_REG	 SPI_IMR; 	// Interrupt Mask Register
	AT91_REG	 Reserved0[4]; 	// 
	AT91_REG	 SPI_CSR[4]; 	// Chip Select Register
	AT91_REG	 Reserved1[48]; 	// 
	AT91_REG	 SPI_RPR; 	// Receive Pointer Register
	AT91_REG	 SPI_RCR; 	// Receive Counter Register
	AT91_REG	 SPI_TPR; 	// Transmit Pointer Register
	AT91_REG	 SPI_TCR; 	// Transmit Counter Register
	AT91_REG	 SPI_RNPR; 	// Receive Next Pointer Register
	AT91_REG	 SPI_RNCR; 	// Receive Next Counter Register
	AT91_REG	 SPI_TNPR; 	// Transmit Next Pointer Register
	AT91_REG	 SPI_TNCR; 	// Transmit Next Counter Register
	AT91_REG	 SPI_PTCR; 	// PDC Transfer Control Register
	AT91_REG	 SPI_PTSR; 	// PDC Transfer Status Register
} AT91S_SPI, *AT91PS_SPI;
*/
    static  AT91S_SPI spi ;
unsigned char OLED_Init(void)
{

unsigned char Error_status = PIO_Configure(at91board_OLED,SIZE);

SPI_Configure (&spi, AT91C_ID_SPI,
SPI_PCS(2)|SPI_SCBR(500000, BOARD_MCK)|SPI_DLYBS(3, BOARD_MCK)| SPI_DLYBCT(4, BOARD_MCK));

SPI_ConfigureNPCS(&spi,2,SPI_SCBR(500000, BOARD_MCK));
/*Enable SPI*/
OLED_Enable();
return Error_status;
}


void OLED_Disable(void){

    SPI_Disable(&spi);
}



void OLED_Enable(void){

   /*Enable SPI*/
SPI_Enable(&spi);

}