/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : EXTI_program.c                   */
/*   DATE        : 17 JAN 2024                      */
/*   VERSION     : V01                              */
/****************************************************/

/****************************************************/
/* Library Directives                               */
/****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/****************************************************/
/* EXTI Directives                                  */
/****************************************************/
#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"
#include "EXTI_register.h"

/****************************************************/
/* GLOBAL VARIABLES                                 */
/****************************************************/
static void (*Global_EXTIPtr[16])(void); // Array to store callback functions for EXTI lines 0-15

/****************************************************/
/* FUNCTION DEFINITIONS                             */
/****************************************************/

/**
 * @brief Configure the GPIO port for a specific EXTI line.
 * @param Copy_port: GPIO port (e.g., PORTA, PORTB) from PORT_e enum.
 * @param Copy_line: EXTI line number (0-15) from Line_e enum.
 */
void MEXTI_voidSetPort(PORT_e Copy_port, Line_e Copy_line) {
    // Calculate the index in the EXTICR array (4 lines per register)
    u8 reg_idx = Copy_line / 4;
    // Calculate the bit position within the register (4 bits per line)
    u8 bit_shift = 4 * (Copy_line % 4);
    
    // Clear the existing port configuration for the line
    SYS_CFG->EXTICR[reg_idx] &= ~(0xF << bit_shift);
    // Set the new port configuration
    SYS_CFG->EXTICR[reg_idx] |= (Copy_port << bit_shift);
}

/**
 * @brief Enable/Disable an EXTI line interrupt.
 * @param Copy_line: EXTI line number (0-15).
 * @param Copy_mode: Enable/Disable mode from Mode_t enum.
 */
void MEXTI_voidEnableAndDisableInterrupt(Line_e Copy_line, Mode_t Copy_mode) {
    switch (Copy_mode) {
    case ENABLED:
        SET_BIT(EXTI->IMR, Copy_line); // Enable interrupt via IMR (Interrupt Mask Register)
        break;
    case DISABLED:
        CLR_BIT(EXTI->IMR, Copy_line); // Disable interrupt
        break;
    }
}

/**
 * @brief Set the trigger edge for an EXTI line.
 * @param Copy_line: EXTI line number (0-15).
 * @param Copy_edge: Trigger edge (RISING, FALLING, ON_CHANGE) from Trigger_t enum.
 */
void MEXTI_voidSetEdge(Line_e Copy_line, Trigger_t Copy_edge) {
    switch (Copy_edge) {
    case RISING:
        SET_BIT(EXTI->RTSR, Copy_line);   // Enable rising edge trigger
        CLR_BIT(EXTI->FTSR, Copy_line);     // Disable falling edge trigger
        break;
    case FALLING:
        SET_BIT(EXTI->FTSR, Copy_line);     // Enable falling edge trigger
        CLR_BIT(EXTI->RTSR, Copy_line);       // Disable rising edge trigger
        break;
    case ON_CHANGE:
        SET_BIT(EXTI->RTSR, Copy_line);     // Enable both edges
        SET_BIT(EXTI->FTSR, Copy_line);
        break;
    }
}

/**
 * @brief Register a callback function for EXTI line 0.
 * @param ptr: Pointer to the callback function.
 */
void EXTI0_voidCallBack(void (*ptr)(void)) {
    Global_EXTIPtr[0] = ptr;
}

/**
 * @brief Register a callback function for EXTI line 1.
 * @param ptr: Pointer to the callback function.
 */
void EXTI1_voidCallBack(void (*ptr)(void)) {
    Global_EXTIPtr[1] = ptr;
}

/**
 * @brief EXTI line 0 interrupt handler.
 *        Invokes the registered callback and clears the pending flag.
 */
void EXTI0_IRQHandler(void) {
    if (Global_EXTIPtr[0] != NULL) {
        Global_EXTIPtr[0](); // Execute callback
    }
    SET_BIT(EXTI->PR, 0);    // Clear pending flag for line 0
}

/**
 * @brief EXTI line 1 interrupt handler.
 *        Invokes the registered callback and clears the pending flag.
 */
void EXTI1_IRQHandler(void) {
    if (Global_EXTIPtr[1] != NULL) {
        Global_EXTIPtr[1](); // Execute callback
    }
    SET_BIT(EXTI->PR, 1);    // Clear pending flag for line 1
}


/**
 * @brief Register a callback function for a specific EXTI line.
 * @param INT_NUM: EXTI line number (0-15) from Line_e enum.
 * @param ptr: Pointer to the callback function to be invoked when the EXTI line triggers.
 */
void EXTI_voidCallBack(Line_e INT_NUM, void (*ptr)(void)) {
    // Validate that the EXTI line number is within range
    if (INT_NUM < 16) {
        // Store the callback function in the global array for the given EXTI line
        Global_EXTIPtr[INT_NUM] = ptr;
    }
}
