/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : MSYSTICK_program.c               */
/*   DATE        : 18 JAN 2024                      */
/*   VERSION     : V01                              */
/****************************************************/

/****************************************************/
/* Library Directives                               */
/****************************************************/
#include "STD_TYPES.h"         // Standard data types definitions
#include "BIT_MATH.h"          // Bit manipulation macros

/****************************************************/
/* SysTick Directives                               */
/****************************************************/
#include "MSYSTICK_interface.h"  // SysTick driver interface prototypes
#include "MSYSTICK_registers.h"  // Register definitions for SysTick
#include "MSYSTICK_private.h"    // Private macros for SysTick
#include "MSYSTICK_config.h"     // Configuration settings for SysTick

/****************************************************/
/* GLOBAL VARIABLES                                 */
/****************************************************/
void (*Globalpf)(void) = NULL; // Global pointer to store the callback function
u8 Flag = 0;                   // Mode flag: 1 for single-shot, 2 for periodic

/****************************************************/
/* FUNCTION DEFINITIONS                             */
/****************************************************/

/**
 * @brief Initialize the SysTick timer.
 *
 * Configures the SysTick control register based on the defined configuration.
 * Enables or disables the SysTick interrupt and sets the clock source.
 */
void SysTick_voidInit(void)
{
    /* Configure SysTick interrupt */
    #if SYSTICK_INTERRUPT == ENABLE
        SET_BIT(SYSTICK->SYST_CSR, CSR_TICKINT);
    #elif SYSTICK_INTERRUPT == DISABLE
        CLR_BIT(SYSTICK->SYST_CSR, CSR_TICKINT);
    #endif

    /* Configure SysTick clock source */
    #if SYSTICK_CLOCKSOURCE == AHB_DIV_8
        CLR_BIT(SYSTICK->SYST_CSR, CSR_CLOCKSOURCE);
    #elif SYSTICK_CLOCKSOURCE == AHB
        SET_BIT(SYSTICK->SYST_CSR, CSR_CLOCKSOURCE);
    #endif
}

/**
 * @brief Create a busy-wait delay.
 *
 * Loads the delay time into the reload register, clears the current value,
 * and starts the timer. Waits until the COUNT FLAG is set, then stops the timer.
 *
 * @param Copy_u32DelayTime: The delay time (tick count).
 */
void SysTick_voidBusyWait(u32 Copy_u32DelayTime)
{
    SYSTICK->SYST_RVR = Copy_u32DelayTime; // Load delay time
    SYSTICK->SYST_CVR = 0;                 // Reset current value
    SET_BIT(SYSTICK->SYST_CSR, CSR_ENABLE); // Start the timer
    while (GET_BIT(SYSTICK->SYST_CSR, CSR_COUNT_FLAG) == 0); // Wait for flag
    SYSTICK->SYST_RVR = 0;                 // Reset reload register
    SYSTICK->SYST_CVR = 0;                 // Reset current value
    CLR_BIT(SYSTICK->SYST_CSR, CSR_ENABLE); // Stop the timer
}

/**
 * @brief Get the elapsed time since the timer started.
 *
 * @return u32: The elapsed tick count.
 */
u32 SysTick_u32ElapsedTime(void)
{
    return SYSTICK->SYST_RVR - SYSTICK->SYST_CVR;
}

/**
 * @brief Get the remaining time before the timer expires.
 *
 * @return u32: The current value of the timer (remaining tick count).
 */
u32 SysTick_u32RemainingTime(void)
{
    return SYSTICK->SYST_CVR;
}

/**
 * @brief Set a single-shot time interval.
 *
 * Loads the delay time, resets the timer, stores the callback function,
 * sets the mode flag to single interval, and starts the timer.
 *
 * @param Copy_u32DelayTime: The tick count for the interval.
 * @param pf: Callback function to execute when the interval expires.
 */
void SysTick_voidSetTimeIntervalSingle(u32 Copy_u32DelayTime, void (*pf)(void))
{
    SYSTICK->SYST_RVR = Copy_u32DelayTime;
    SYSTICK->SYST_CVR = 0;
    Globalpf = pf;
    Flag = 1; // Single interval mode
    SET_BIT(SYSTICK->SYST_CSR, CSR_ENABLE);
}

/**
 * @brief Set a periodic time interval.
 *
 * Loads the delay time, resets the timer, stores the callback function,
 * sets the mode flag to periodic, and starts the timer.
 *
 * @param Copy_u32DelayTime: The tick count for the interval.
 * @param pf: Callback function to execute at each interval.
 */
void SysTick_voidSetTimeIntervalPeriodic(u32 Copy_u32DelayTime, void (*pf)(void))
{
    SYSTICK->SYST_RVR = Copy_u32DelayTime;
    SYSTICK->SYST_CVR = 0;
    Globalpf = pf;
    Flag = 2; // Periodic interval mode
    SET_BIT(SYSTICK->SYST_CSR, CSR_ENABLE);
}

/**
 * @brief Stop the SysTick timer.
 *
 * Stops the timer by clearing the enable bit in the control register.
 */
void SysTick_voidStopTimer(void)
{
    CLR_BIT(SYSTICK->SYST_CSR, CSR_ENABLE);
}

/**
 * @brief SysTick interrupt handler.
 *
 * Executes the registered callback function. In single interval mode,
 * it stops the timer after executing the callback; in periodic mode, it continues.
 */
void SysTick_Handler(void)
{
    if (Globalpf != NULL)
    {
        switch (Flag)
        {
            case 1: 
                Globalpf();             // Execute callback for single interval
                SysTick_voidStopTimer(); // Stop timer after single interval
                break;
            case 2:
                Globalpf();             // Execute callback for periodic interval
                break;
        }
    }
}
