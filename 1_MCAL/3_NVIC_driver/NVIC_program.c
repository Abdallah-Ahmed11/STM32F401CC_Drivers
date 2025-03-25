/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : NVIC_program.c                   */
/*   DATE        : 16 JAN 2024                      */
/*   VERSION     : V01                              */
/****************************************************/

/****************************************************/
/* Library Directives                               */
/****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/****************************************************/
/* NVIC Directives                                  */
/****************************************************/
#include "NVIC_interface.h"
#include "NVIC_config.h"
#include "NVIC_private.h"
#include "NVIC_register.h"

/****************************************************/
/* GLOBAL VARIABLES                                 */
/****************************************************/
static u8 Glopal_u8IPR = 0; // Stores the current priority grouping mode (Group/Subgroup)

/****************************************************/
/* FUNCTION DEFINITIONS                             */
/****************************************************/

// Enable a specific interrupt by setting the corresponding bit in the ISER register
void MNVIC_voidSetEnablePeripheralInterrupt(u8 Copy_u8IDX)
{
    // Calculate register index (each ISER register handles 32 interrupts)
    // Bit position = Copy_u8IDX % 32
    SET_BIT(NVIC->ISER[Copy_u8IDX / MAX_LENGTH], (Copy_u8IDX % MAX_LENGTH));
}

// Disable a specific interrupt by setting the corresponding bit in the ICER register
void MNVIC_voidSetDisablePeripheralInterrupt(u8 Copy_u8IDX)
{
    SET_BIT(NVIC->ICER[Copy_u8IDX / MAX_LENGTH], (Copy_u8IDX % MAX_LENGTH));
}

// Set a pending flag for an interrupt using the ISPR register
void MNVIC_voidSetPendingFlag(u8 Copy_u8IDX)
{
    SET_BIT(NVIC->ISPR[Copy_u8IDX / MAX_LENGTH], (Copy_u8IDX % MAX_LENGTH));
}

// Clear a pending flag for an interrupt using the ICPR register
void MNVIC_voidClearPendingFlag(u8 Copy_u8IDX)
{
    SET_BIT(NVIC->ICPR[Copy_u8IDX / MAX_LENGTH], (Copy_u8IDX % MAX_LENGTH));
}

// Check if an interrupt is active by reading the IABR register
u8 MNVIC_u8GetActiveState(u8 Copy_u8IDX)
{
    u8 Local_u8ReturnValue = GET_BIT(NVIC->IABR[Copy_u8IDX / MAX_LENGTH], (Copy_u8IDX % MAX_LENGTH));
    return Local_u8ReturnValue;
}

// Set interrupt priority based on the configured grouping mode (Group/Subgroup)
void MNVIC_voidSetInterruptPriority(u8 Copy_IDX, u8 GroupNum, u8 SubGroup)
{
    switch (Glopal_u8IPR) // Use the stored grouping mode
    {
    case GROUP16_SUB0: // 16 priority groups, 0 subgroups
        NVIC->IPR[Copy_IDX] = GroupNum << 4; // Priority bits [7:4]
        break;
    case GROUP8_SUB2: // 8 groups, 2 subgroups
        NVIC->IPR[Copy_IDX] = GroupNum << 5 | SubGroup << 4; // Group[7:5], Sub[4]
        break;
    case GROUP4_SUB4: // 4 groups, 4 subgroups
        NVIC->IPR[Copy_IDX] = GroupNum << 6 | SubGroup << 4; // Group[7:6], Sub[5:4]
        break;
    case GROUP2_SUB8: // 2 groups, 8 subgroups
        NVIC->IPR[Copy_IDX] = GroupNum << 7 | SubGroup << 4; // Group[7], Sub[6:4]
        break;
    case GROUP0_SUB16: // 0 groups, 16 subgroups
        NVIC->IPR[Copy_IDX] = SubGroup << 4; // Priority bits [7:4]
        break;
    }
}

// Configure priority grouping mode via SCB_AIRCR register
void MNVIC_voidSetGroupMode(MNVIC_GROUP_MODE_e Copy_Mode)
{
    Glopal_u8IPR = Copy_Mode; // Save grouping mode globally
    // VECT_KEY (0x5FA) must be written to modify SCB_AIRCR
    SCB_AIRCR = VECT_KEY | (Copy_Mode << 8); // Combine key and mode
}