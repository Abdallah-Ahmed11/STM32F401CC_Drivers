/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : EXTI_register.h                  */
/*   DATE        : 17 JAN 2024                      */
/*   VERSION     : V01                              */
/****************************************************/

#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

/* Base addresses for the EXTI and SYSCFG peripherals */
#define EXTI_BASE_ADRESS      0x40013C00  /**< Base address of EXTI registers */
#define SYSCFG_BASE_ADRESS    0x40013800  /**< Base address of SYSCFG registers */



/**
 * @brief Structure representing the EXTI registers.
 */
typedef struct
{
    u32 IMR;      /**< Interrupt Mask Register: enables/disables interrupts */
    u32 EMR;      /**< Event Mask Register: configures events (not used here) */
    u32 RTSR;     /**< Rising Trigger Selection Register: configures rising edge trigger */
    u32 FTSR;     /**< Falling Trigger Selection Register: configures falling edge trigger */
    u32 SWEIR;    /**< Software Interrupt Event Register (not used here) */
    u32 PR;       /**< Pending Register: indicates pending interrupts */
} EXTI_t;



/**
 * @brief Structure representing the SYSCFG registers.
 */
typedef struct
{
    u32 MEMRMP;      /**< Memory Remap Register */
    u32 PMC;         /**< Peripheral Mode Configuration Register */
    u32 EXTICR[4];   /**< External Interrupt Configuration Registers: map EXTI lines to ports */
    u32 Reserved[2]; /**< Reserved for alignment */
    u32 CMPCR;       /**< Compensation Cell Control Register */
} SYSCFG_t;



/* Define pointers for register access */
#define EXTI     ((volatile EXTI_t*)(EXTI_BASE_ADRESS))   /**< Pointer to EXTI registers */
#define SYS_CFG  ((volatile SYSCFG_t*)(SYSCFG_BASE_ADRESS)) /**< Pointer to SYSCFG registers */



#endif /* EXTI_REGISTER_H_ */