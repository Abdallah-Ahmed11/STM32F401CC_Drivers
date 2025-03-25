/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : NVIC_interface.h                 */
/*   DATE        : 16 JAN 2024                      */
/*   VERSION     : V01                              */
/****************************************************/

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

/**
 * @brief Priority grouping configurations for NVIC.
 *        Defines how priority bits are split between Group and Subgroup.
 */
typedef enum {
    GROUP16_SUB0 = 3,  // 4 bits for Group (16 levels), 0 bits for Subgroup
    GROUP8_SUB2,       // 3 bits for Group (8 levels), 1 bit for Subgroup (2 levels)
    GROUP4_SUB4,       // 2 bits for Group (4 levels), 2 bits for Subgroup (4 levels)
    GROUP2_SUB8,       // 1 bit for Group (2 levels), 3 bits for Subgroup (8 levels)
    GROUP0_SUB16       // 0 bits for Group, 4 bits for Subgroup (16 levels)
} MNVIC_GROUP_MODE_e;

/* Function Prototypes */

/**
 * @brief Enable a specific peripheral interrupt.
 * @param Copy_u8IDX: Interrupt number (0 to 239).
 */
void MNVIC_voidSetEnablePeripheralInterrupt(u8 Copy_u8IDX);



/**
 * @brief Disable a specific peripheral interrupt.
 * @param Copy_u8IDX: Interrupt number (0 to 239).
 */
void MNVIC_voidSetDisablePeripheralInterrupt(u8 Copy_u8IDX);



/**
 * @brief Manually set an interrupt as pending.
 * @param Copy_u8IDX: Interrupt number (0 to 239).
 */
void MNVIC_voidSetPendingFlag(u8 Copy_u8IDX);



/**
 * @brief Clear the pending status of an interrupt.
 * @param Copy_u8IDX: Interrupt number (0 to 239).
 */
void MNVIC_voidClearPendingFlag(u8 Copy_u8IDX);



/**
 * @brief Check if an interrupt is currently active.
 * @param Copy_u8IDX: Interrupt number (0 to 239).
 * @return 1 if active, 0 otherwise.
 */
u8 MNVIC_u8GetActiveState(u8 Copy_u8IDX);



/**
 * @brief Configure the priority grouping mode (Group/Subgroup).
 * @param Copy_Mode: Priority grouping configuration from MNVIC_GROUP_MODE_e.
 */
void MNVIC_voidSetGroupMode(MNVIC_GROUP_MODE_e Copy_Mode);



/**
 * @brief Set the priority for a specific interrupt.
 * @param Copy_IDX: Interrupt number (0 to 239).
 * @param GroupNum: Group priority value (depends on grouping mode).
 * @param SubGroup: Subgroup priority value (depends on grouping mode).
 */
void MNVIC_voidSetInterruptPriority(u8 Copy_IDX, u8 GroupNum, u8 SubGroup);

#endif /* NVIC_INTERFACE_H_ */