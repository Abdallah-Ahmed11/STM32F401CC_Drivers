/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : RCC_interface.h                  */
/*   DATE        : 14 JAN 2024                      */
/*   VERSION     : V01                              */
/****************************************************/


#ifndef MRCC_INTERFACE_H
#define MRCC_INTERFACE_H


/*** Interface.h contains functions prototypes & new data types used by the functions ***/

/* new type for Enable & Disable vendor peripheral functions */
typedef enum {
	AHB1,
	AHB2,
	APB1,
	APB2
} EN_AMBABus_t;

/* new type for Enable & Disable vendor peripheral functions */
/* The enumeration values of the enums are from the data sheet:-
 * RCC_AHB1ENR for the AHB1 bus
 * RCC_AHB2ENR for the AHB2 bus
 * RCC_APB1ENR for the APB1 bus
 * RCC_APB2ENR for the APB2 bus
 *  */
typedef enum {
	AHB1_DMA2EN	 	= 22,
	AHB1_DMA1EN 	= 21,
	AHB1_CRCEN 		= 12,
	AHB1_GPIOHEN	= 7,
	AHB1_GPIOEEN 	= 4,
	AHB1_GPIODEN 	= 3,
	AHB1_GPIOCEN 	= 2,
	AHB1_GPIOBEN 	= 1,
	AHB1_GPIOAEN 	= 0,

	AHB2_OTGFSEN 	= 7,

	APB1_PWREN 		= 28,
	APB1_I2C3EN 	= 23,
	APB1_I2C2EN 	= 22,
	APB1_I2C1EN 	= 21,
	APB1_USART2EN 	= 17,
	APB1_SPI3EN 	= 15,
	APB1_SPI2EN 	= 14,
	APB1_WWDGEN 	= 11,
	APB1_TIM5EN 	= 3,
	APB1_TIM4EN 	= 2,
	APB1_TIM3EN 	= 1,
	APB1_TIM2EN 	= 0,

	APB2_TIM11EN 	= 18,
	APB2_TIM10EN 	= 17,
	APB2_TIM9EN 	= 16,
	APB2_SYSCFGEN 	= 14,
	APB2_SPI4EN 	= 13,
	APB2_SPI1EN 	= 12,
	APB2_SDIOEN 	= 11,
	APB2_ADC1EN 	= 8,
	APB2_USART6EN 	= 5,
	APB2_USART1EN 	= 4,
	APB2_TIM1EN 	= 0,
} EN_PeriphralID_t;


/* @brief Configure the system clock & set the prescalers
 *
 * This function configure the system clock based on the configuration parameters
 * in the MRCC_config.h file and also set the prescalers for the AMBA buses
 *
 * @param void
 *
 * @return void
 **/
void MRCC_voidInitSystemClock(void);


/* @brief Enable the clock for a vendor peripheral
 *
 * This function Enable the clock for a specific vendor peripheral
 * based on the peripheral id and the AMBA bus that the peripheral is connected to
 *
 * @param EN_AMBABus_t		the AMBA bus that the peripheral is connected to.
 *		  EN_PeriphralID_t	the id of the peripheral
 *
 * @return void
 **/
void MRCC_voidEnableVendorPerphiral(EN_AMBABus_t Copy_enuBus, EN_PeriphralID_t Copy_enuPerphiralID);


/* @brief Disable the clock for a vendor peripheral
 *
 * This function Disable the clock for a specific vendor peripheral
 * based on the peripheral id and the AMBA bus that the peripheral is connected to
 *
 * @param EN_AMBABus_t		the AMBA bus that the peripheral is connected to.
 *		  EN_PeriphralID_t	the id of the peripheral
 *
 * @return void
 **/
void MRCC_voidDisableVendorPerphiral(EN_AMBABus_t Copy_enuBus, EN_PeriphralID_t Copy_enuPerphiralID);

#endif // MRCC_INTERFACE_H
