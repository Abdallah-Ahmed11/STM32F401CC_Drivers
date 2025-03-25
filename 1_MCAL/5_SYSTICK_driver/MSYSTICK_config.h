/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : MSYSTICK_config.h                */
/*   DATE        : 18 JAN 2024                      */
/*   VERSION     : V01                              */
/****************************************************/

/*
 * MSYSTICK_config.h
 *
 * @brief Configuration file for the SysTick driver.
 *        Define the interrupt state and clock source.
 */

 #ifndef MSYSTICK_CONFIG_H_
 #define MSYSTICK_CONFIG_H_
 
 /* SysTick Interrupt Enable/Disable Configuration */
 /* Options: ENABLE or DISABLE */
 #define SYSTICK_INTERRUPT      ENABLE
 
 /* SysTick Clock Source Configuration */
 /* Options: AHB_DIV_8 or AHB */
 #define SYSTICK_CLOCKSOURCE    AHB_DIV_8
 
 #endif /* MSYSTICK_CONFIG_H_ */
 