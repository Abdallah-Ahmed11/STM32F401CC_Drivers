/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : MSYSTICK_private.h              */
/*   DATE        : 18 JAN 2024                      */
/*   VERSION     : V01                              */
/****************************************************/

/*
 * MSYSTICK_private.h
 *
 * @brief Private definitions for the SysTick driver.
 *        Defines macros for enabling/disabling and clock source settings,
 *        as well as bit positions in the SysTick control register.
 */

 #ifndef MSYSTICK_PRIVATE_H_
 #define MSYSTICK_PRIVATE_H_
 
 /* Generic Enable/Disable macros */
 #define ENABLE              1
 #define DISABLE             2
 
 /* Clock Source Options */
 #define AHB_DIV_8           1
 #define AHB                 2
 
 /* SysTick Control Register (CSR) Bit Definitions */
 #define CSR_ENABLE          0   // SysTick counter enable bit
 #define CSR_TICKINT         1   // SysTick interrupt enable bit
 #define CSR_CLOCKSOURCE     2   // Clock source selection bit
 #define CSR_COUNT_FLAG      16  // Count flag (read-only) indicating timer has reached zero
 
 #endif /* MSYSTICK_PRIVATE_H_ */
 