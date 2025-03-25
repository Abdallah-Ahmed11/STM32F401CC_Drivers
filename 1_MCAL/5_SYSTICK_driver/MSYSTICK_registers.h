/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : MSYSTICK_registers.h             */
/*   DATE        : 18 JAN 2024                      */
/*   VERSION     : V01                              */
/****************************************************/

/*
 * MSYSTICK_registers.h
 *
 * @brief Register definitions for the SysTick timer.
 *        Provides a structure mapping for SysTick registers.
 */

 #ifndef MSYSTICK_REGISTERS_H_
 #define MSYSTICK_REGISTERS_H_
 
 /* Base address for SysTick registers */
 #define SYSTICK_BASE_ADDRESS    0xE000E010
 
 /**
  * @brief Structure representing the SysTick registers.
  */
 typedef struct {
	 u32 SYST_CSR;    /**< Control and Status Register */
	 u32 SYST_RVR;    /**< Reload Value Register */
	 u32 SYST_CVR;    /**< Current Value Register */
	 u32 SYST_CALIB;  /**< Calibration Register */
 } SysTic_t;
 
 /* Define a pointer for register access */
 #define SYSTICK    ((volatile SysTic_t*)SYSTICK_BASE_ADDRESS)
 
 #endif /* MSYSTICK_REGISTERS_H_ */
 