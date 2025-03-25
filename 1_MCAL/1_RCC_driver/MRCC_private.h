/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : RCC_private.h                    */
/*   DATE        : 14 JAN 2024                      */
/*   VERSION     : V01                              */
/****************************************************/


#ifndef MRCC_PRIVATE_H
#define MRCC_PRIVATE_H


/* Clock Source Types */
#define HSI_CLOCK_SOURCE		(1)
#define HSE_CLOCK_SOURCE		(2)
#define PLL_HSI_CLOCK_SOURCE	(3)
#define PLL_HSE_CLOCK_SOURCE	(4)


/* HSE Clock Generation Selection */
#define HSE_CRYSTAL_CERAMIC_RESNATOR_CLOCK_SIGNAL	(1)
#define HSE_EXTERNAL_USER_CLOCK_SIGNAL				(2)


/* AHB Prescalers */
#define SYSTEM_CLOCK_NOT_DIVIDED					(0b0000)
#define SYSTEM_CLOCK_DIVIDED_BY_002					(0b1000)
#define SYSTEM_CLOCK_DIVIDED_BY_004                 (0b1001)
#define SYSTEM_CLOCK_DIVIDED_BY_008                 (0b1010)
#define SYSTEM_CLOCK_DIVIDED_BY_016                 (0b1011)
#define SYSTEM_CLOCK_DIVIDED_BY_064                 (0b1100)
#define SYSTEM_CLOCK_DIVIDED_BY_128                 (0b1101)
#define SYSTEM_CLOCK_DIVIDED_BY_256                 (0b1110)
#define SYSTEM_CLOCK_DIVIDED_BY_512                 (0b1111)

/* APB Prescalers */
#define AHB_CLOCK_NOT_DIVIDED                       (0b000)
#define AHB_CLOCK_DIVIED_BY_02                      (0b100)
#define AHB_CLOCK_DIVIED_BY_04                      (0b101)
#define AHB_CLOCK_DIVIED_BY_08                      (0b110)
#define AHB_CLOCK_DIVIED_BY_16                      (0b111)


/* Implementation Specific */

/* NOT_READY is used when polling on the ready flags of the clock sources */
#define NOT_READY 	0

/* macros for masking the P division factor */
#define PLL_P_DIVISION_FACTOR_START_BIT			(16)
#define MASKING_TWO_BITS						(0b11)

/* macros for masking the N multiplication factor */
#define PLL_N_MULTIPLICATION_FACTOR_START_BIT	(6)
#define MASKING_NINE_BITS						(0b111111111)

/* macros for masking the M division factor */
#define PLL_M_DIVISION_FACTOR_START_BIT			(0)
#define MASKING_SIX_BITS						(0b111111)

/* macros for masking the AHB prescaler */
#define AHB_PRESCALER_START_BIT	(4)
#define MASKING_FOUR_BITS		(0b1111)

/* macros for masking the APB1 & APB2 prescalers */
#define APB1_PRESCALER_START_BIT	(10)
#define APB2_PRESCALER_START_BIT	(13)
#define MASKING_THREE_BITS			(0b111)





#endif // MRCC_PRIVATE_H
