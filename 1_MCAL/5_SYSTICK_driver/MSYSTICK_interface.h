/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : MSYSTICK_interface.h             */
/*   DATE        : 18 JAN 2024                      */
/*   VERSION     : V01                              */
/****************************************************/

/*
 * MSYSTICK_interface.h
 *
 * @brief Interface file for the SysTick driver.
 *        Contains function prototypes for initializing the timer, 
 *        busy-wait delays, and setting time intervals.
 */

 #ifndef MSYSTICK_INTERFACE_H_
 #define MSYSTICK_INTERFACE_H_
 
 /**
  * @brief Initialize the SysTick timer.
  */
 void SysTick_voidInit(void);
 
 /**
  * @brief Create a busy-wait delay using SysTick.
  * @param Copy_u32DelayTime: The delay time (tick count) to wait.
  */
 void SysTick_voidBusyWait(u32 Copy_u32DelayTime);
 
 /**
  * @brief Get the elapsed time since the timer started.
  * @return u32: The elapsed tick count.
  */
 u32 SysTick_u32ElapsedTime(void);
 
 /**
  * @brief Get the remaining time before the timer expires.
  * @return u32: The remaining tick count.
  */
 u32 SysTick_u32RemainingTime(void);
 
 /**
  * @brief Set a single-shot time interval for SysTick.
  * @param Copy_u32DelayTime: The tick count for the interval.
  * @param pf: Callback function to execute when the interval expires.
  */
 void SysTick_voidSetTimeIntervalSingle(u32 Copy_u32DelayTime, void (*pf)(void));
 
 /**
  * @brief Set a periodic time interval for SysTick.
  * @param Copy_u32DelayTime: The tick count for the interval.
  * @param pf: Callback function to execute at each interval.
  */
 void SysTick_voidSetTimeIntervalPeriodic(u32 Copy_u32DelayTime, void (*pf)(void));
 
 /**
  * @brief Stop the SysTick timer.
  */
 void SysTick_voidStopTimer(void);
 
 #endif /* MSYSTICK_INTERFACE_H_ */
 