/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : RCC_configration.h               */
/*   DATE        : 14 JAN 2024                      */
/*   VERSION     : V01                              */
/****************************************************/


#ifndef MRCC_CONFIG_H
#define MRCC_CONFIG_H

/* Three main clock sources:-
 * Options:-
 * 1- HSI_CLOCK_SOURCE
 * 2- HSE_CLOCK_SOURCE
 * 3- PLL_HSI_CLOCK_SOURCE
 * 4- PLL_HSE_CLOCK_SOURCE
 * */
#define RCC_CLOCK_SOURCE_TYPE	HSI_CLOCK_SOURCE

/* Two Clock Signals Generators for HSE clock source
 * Options:-
 * 1- HSE_CRYSTAL_CERAMIC_RESNATOR_CLOCK_SIGNAL
 * 2- HSE_EXTERNAL_USER_CLOCK_SIGNAL
 * */
#define HSE_CLOCK_SIGNAL_GENERATOR	HSE_CRYSTAL_CERAMIC_RESNATOR_CLOCK_SIGNAL


/* PLL Configratutions Parameters
 * M Division Factor
 * N Multiplication Factor
 * P Division Factor */

/* value must be 2, 4, 6, or 8 */
#define PLL_P_DIVISION_FACTOR				(2)

/* N Multiplication Factor
 * Values must be in the range 192 <= N <= 432  */
#define PLL_N_MULTIPLICATION_FACTOR			(192)

/* M_DIVISION_FACTOR
 * Values must be in range 2 <= M <= 63 */
#define PLL_M_DIVISION_FACTOR				(2)


/* AHB Prescaler
 * 1- SYSTEM_CLOCK_NOT_DIVIDED
 * 2- SYSTEM_CLOCK_DIVIDED_BY_002
 * 3- SYSTEM_CLOCK_DIVIDED_BY_004
 * 4- SYSTEM_CLOCK_DIVIDED_BY_008
 * 5- SYSTEM_CLOCK_DIVIDED_BY_016
 * 6- SYSTEM_CLOCK_DIVIDED_BY_064
 * 7- SYSTEM_CLOCK_DIVIDED_BY_128
 * 8- SYSTEM_CLOCK_DIVIDED_BY_256
 * 9- SYSTEM_CLOCK_DIVIDED_BY_512
 * */
#define AHB_PRESCALER	SYSTEM_CLOCK_DIVIDED_BY_002


/* APB  Prescalers
 * Options:-
 * 1- AHB_CLOCK_NOT_DIVIDED
 * 2- AHB_CLOCK_DIVIED_BY_02
 * 3- AHB_CLOCK_DIVIED_BY_04
 * 4- AHB_CLOCK_DIVIED_BY_08
 * 5- AHB_CLOCK_DIVIED_BY_16
 * */
#define APB1_PRESCALER		AHB_CLOCK_DIVIED_BY_02

/* APB2 Prescaler */
#define APB2_PRESCALER 		AHB_CLOCK_DIVIED_BY_02

#endif // MRCC_CONFIG_H
