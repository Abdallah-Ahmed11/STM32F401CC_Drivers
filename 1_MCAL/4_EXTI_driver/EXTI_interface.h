/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : EXTI_interface.h                 */
/*   DATE        : 17 JAN 2024                      */
/*   VERSION     : V01                              */
/****************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/**
 * @brief Enumeration for available GPIO ports.
 */
typedef enum
{
    PORTA, /**< Port A */
    PORTB, /**< Port B */
    PORTC  /**< Port C */
} PORT_e;

/**
 * @brief Enumeration for EXTI lines.
 *        EXTI lines are numbered from 0 to 15.
 */
typedef enum
{
    line0,  /**< EXTI Line 0 */
    line1,  /**< EXTI Line 1 */
    line2,  /**< EXTI Line 2 */
    line3,  /**< EXTI Line 3 */
    line4,  /**< EXTI Line 4 */
    line5,  /**< EXTI Line 5 */
    line6,  /**< EXTI Line 6 */
    line7,  /**< EXTI Line 7 */
    line8,  /**< EXTI Line 8 */
    line9,  /**< EXTI Line 9 */
    line10, /**< EXTI Line 10 */
    line11, /**< EXTI Line 11 */
    line12, /**< EXTI Line 12 */
    line13, /**< EXTI Line 13 */
    line14, /**< EXTI Line 14 */
    line15  /**< EXTI Line 15 */
} Line_e;

/**
 * @brief Enumeration for interrupt mode.
 */
typedef enum
{
    ENABLED,  /**< Interrupt is enabled */
    DISABLED  /**< Interrupt is disabled */
} Mode_t;

/**
 * @brief Enumeration for trigger edge type.
 */
typedef enum
{
    RISING,   /**< Rising edge trigger */
    FALLING,  /**< Falling edge trigger */
    ON_CHANGE /**< Both rising and falling edges trigger */
} Trigger_t;

/* Function Prototypes */

/**
 * @brief Maps a specific EXTI line to a GPIO port.
 * @param Copy_port GPIO port selection from PORT_e enum.
 * @param Copy_line EXTI line number from Line_e enum.
 */
void MEXTI_voidSetPort(PORT_e Copy_port, Line_e Copy_line);

/**
 * @brief Enables or disables an EXTI line interrupt.
 * @param Copy_line EXTI line number from Line_e enum.
 * @param Copy_mode Mode (ENABLED or DISABLED) from Mode_t enum.
 */
void MEXTI_voidEnableAndDisableInterrupt(Line_e Copy_line, Mode_t Copy_mode);

/**
 * @brief Sets the trigger edge for a specific EXTI line.
 * @param Copy_line EXTI line number from Line_e enum.
 * @param Copy_edge Trigger edge type from Trigger_t enum.
 */
void MEXTI_voidSetEdge(Line_e Copy_line, Trigger_t Copy_edge);

/**
 * @brief Registers a callback function for a specific EXTI line.
 * @param INT_NUM EXTI line number from Line_e enum.
 * @param ptr Pointer to the callback function.
 */
void EXTI_voidCallBack(Line_e INT_NUM, void (*ptr)(void));

#endif /* EXTI_INTERFACE_H_ */
