/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : RCC_program.c                    */
/*   DATE        : 14 JAN 2024                      */
/*   VERSION     : V01                              */
/****************************************************/



/****************************************************/
/* Library Directives							    */
/****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/****************************************************/
/* RCC Directives								    */
/****************************************************/
#include "MRCC_interface.h"
#include "MRCC_private.h"
#include "MRCC_config.h"
#include "MRCC_register.h"

/* Define Functionality */
void MRCC_voidInitSystemClock(void) {
/*** Configure the selected clock source ***/
/*** Enable Selected clock source ***/

#if RCC_CLOCK_SOURCE_TYPE == HSI_CLOCK_SOURCE
	/* Based on the functionality of HSI, we don't need any configurations for it */

	/* Enable HSI clock source */
	SET_BIT(RCC_CR, HSION);

	/* Polling on the ready flag of HSI due to the settling time */
	while(GET_BIT(RCC_CR, HSIRDY) == NOT_READY) {
		/* Wait until the HSI clock is ready */
	}

	/* Switch to HSI */
	WRT_GROUP_OF_BITS(RCC_CFGR, 0, 0b00, 0b11);

#elif RCC_CLOCK_SOURCE_TYPE == HSE_CLOCK_SOURCE
	/* Configure the HSE clock signal generation */
	switch(HSE_CLOCK_SIGNAL_GENERATOR) {
	case HSE_CRYSTAL_CERAMIC_RESNATOR_CLOCK_SIGNAL:
		/* Writing zero to the HSE bypass bit */
		CLR_BIT(RCC_CR, HSEBYP);
		break;

	case HSE_EXTERNAL_USER_CLOCK_SIGNAL:
		/* Writing one to the HSE bypass bit */
		SET_BIT(RCC_CR, HSEBYP);
		break;
	}

	/* Enable HSE clock source */
	SET_BIT(RCC_CR, HSEON);

	/* Polling on the ready flag of HSE due to the settling time */
	while(GET_BIT(RCC_CR, HSERDY) == NOT_READY) {
		/* Wait until the HSE clock is ready */
	}

	/* Switch to HSE */
	WRT_GROUP_OF_BITS(RCC_CFGR, 0, 0b01, 0b11);
#elif RCC_CLOCK_SOURCE_TYPE == PLL_HSI_CLOCK_SOURCE

	/*** HSI Considerations ***/

	/* Enable HSI because it will be the input source of the PLL */
	SET_BIT(RCC_CR, HSION);

	while(GET_BIT(RCC_CR, HSIRDY) == NOT_READY) {
		/* Wait until the HSI clock is ready */
	}

	/*** PLL Considerations ***/

	/* P Division Factor */
	/* Masking the value of P division factor to the PLLCFGR register
	 * note that we divide 2 from (P_DIVISION_FACTOR - 1) to write the correct values
	 * go to data sheet, PLLP bits in the RCC_PLLCFGR to the the options' value */
	WRT_GROUP_OF_BITS(RCC_PLLCFGR, PLL_P_DIVISION_FACTOR_START_BIT, (PLL_P_DIVISION_FACTOR - 1 ) / 2, MASKING_TWO_BITS);


	/*** N Multiplication factor ***/
	WRT_GROUP_OF_BITS(RCC_PLLCFGR, PLL_N_MULTIPLICATION_FACTOR_START_BIT, PLL_N_MULTIPLICATION_FACTOR, MASKING_NINE_BITS);

	/*** M division factor ***/
	WRT_GROUP_OF_BITS(RCC_PLLCFGR, PLL_M_DIVISION_FACTOR_START_BIT, PLL_M_DIVISION_FACTOR, MASKING_SIX_BITS);


	/* Select input clock source PLL--> HSI */
	CLR_BIT(RCC_PLLCFGR, PLLSRC);

	/* Enable PLL */
	SET_BIT(RCC_CR, PLLON);

	/* Wait */
	while(GET_BIT(RCC_CR, PLLRDY) == NOT_READY) {
		/* Wait until the PLL clock is ready */
	}

	/* Switch to PLL */
	WRT_GROUP_OF_BITS(RCC_CFGR, 0, 0b10, 0b11);
#elif RCC_CLOCK_SOURCE_TYPE == PLL_HSE_CLOCK_SOURCE

	/*** HSE Considerations ***/

	/* Configure the HSE clock signal generation */
	switch(HSE_CLOCK_SIGNAL_GENERATOR) {
	case HSE_CRYSTAL_CERAMIC_RESNATOR_CLOCK_SIGNAL:
		/* Writing zero to the HSE bypass bit */
		CLR_BIT(RCC_CR, HSEBYP);
		break;

	case HSE_EXTERNAL_USER_CLOCK_SIGNAL:
		/* Writing one to the HSE bypass bit */
		SET_BIT(RCC_CR, HSEBYP);
		break;
	}

	/* Enable HSE clock source */
	SET_BIT(RCC_CR, HSEON);

	/* Polling on the ready flag of HSE due to the settling time */
	while(GET_BIT(RCC_CR, HSERDY) == NOT_READY) {
		/* Wait until the HSI clock is ready */
	}

	/*** Considerations PLL ***/
	/* P Division Factor */
	/* Masking the value of P division factor to the PLLCFGR register
	 * note that we divide 2 from (P_DIVISION_FACTOR - 1) to write the correct values
	 * go to data sheet, PLLP bits in the RCC_PLLCFGR to the the options' value */
	WRT_GROUP_OF_BITS(RCC_PLLCFGR, PLL_P_DIVISION_FACTOR_START_BIT, (PLL_P_DIVISION_FACTOR - 1 ) / 2, MASKING_TWO_BITS);


	/*** N Multiplication factor ***/
	WRT_GROUP_OF_BITS(RCC_PLLCFGR, PLL_N_MULTIPLICATION_FACTOR_START_BIT, PLL_N_MULTIPLICATION_FACTOR, MASKING_NINE_BITS);

	/*** M division factor ***/
	WRT_GROUP_OF_BITS(RCC_PLLCFGR, PLL_M_DIVISION_FACTOR_START_BIT, PLL_M_DIVISION_FACTOR, MASKING_SIX_BITS);


	/* Select input clock source PLL--> HSE */
	SET_BIT(RCC_PLLCFGR, PLLSRC);

	/* Enable PLL */
	SET_BIT(RCC_CR, PLLON);

	/* Wait */
	while(GET_BIT(RCC_CR, PLLRDY) == NOT_READY) {
		/* Wait until the PLL clock is ready */
	}

	/* Switch to PLL */
	WRT_GROUP_OF_BITS(RCC_CFGR, 0, 0b10, 0b11);
#endif // RCC_CLOCK_SOURCE_TYPE == HSI_CLOCK_SOURCE


	/*** Prescalers ***/

	/* AHB Prescaler */
	WRT_GROUP_OF_BITS(RCC_CFGR, AHB_PRESCALER_START_BIT, AHB_PRESCALER, MASKING_FOUR_BITS);

	/* APB2 Prescaler */
	WRT_GROUP_OF_BITS(RCC_CFGR, APB1_PRESCALER_START_BIT, APB1_PRESCALER, MASKING_THREE_BITS);

	/* APB1 Prescaler */
	WRT_GROUP_OF_BITS(RCC_CFGR, APB2_PRESCALER_START_BIT, APB2_PRESCALER, MASKING_THREE_BITS);
}


void MRCC_voidEnableVendorPerphiral(EN_AMBABus_t Copy_enuBus, EN_PeriphralID_t Copy_enuPerphiralID) {
	switch(Copy_enuBus) {
	case AHB1: SET_BIT(RCC_AHB1ENR, Copy_enuPerphiralID);	break;
	case AHB2: SET_BIT(RCC_AHB2ENR, Copy_enuPerphiralID);	break;
	case APB1: SET_BIT(RCC_APB1ENR, Copy_enuPerphiralID);	break;
	case APB2: SET_BIT(RCC_APB2ENR, Copy_enuPerphiralID);	break;
	}
}

void MRCC_voidDisableVendorPerphiral(EN_AMBABus_t Copy_enuBus, EN_PeriphralID_t Copy_enuPerphiralID) {
	switch(Copy_enuBus) {
	case AHB1: CLR_BIT(RCC_AHB1ENR, Copy_enuPerphiralID);	break;
	case AHB2: CLR_BIT(RCC_AHB2ENR, Copy_enuPerphiralID);	break;
	case APB1: CLR_BIT(RCC_APB1ENR, Copy_enuPerphiralID);	break;
	case APB2: CLR_BIT(RCC_APB2ENR, Copy_enuPerphiralID);	break;
	}
}
