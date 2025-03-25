/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : NVIC_register.h                  */
/*   DATE        : 16 JAN 2024                      */
/*   VERSION     : V01                              */
/****************************************************/


#ifndef NVIC_REGISTER_H_
#define NVIC_REGISTER_H_



#define NVIC_BASE_ADDRESS 0xE000E100 // Base address of NVIC registers



// NVIC register structure mapping
typedef struct {
    u32 ISER[8];   // Interrupt Set Enable Registers (enable interrupts)
    u32 Reserved1[24];
    u32 ICER[8];   // Interrupt Clear Enable Registers (disable interrupts)
    u32 Reserved2[24];
    u32 ISPR[8];   // Interrupt Set Pending Registers (set pending interrupts)
    u32 Reserved3[24];
    u32 ICPR[8];   // Interrupt Clear Pending Registers (clear pending interrupts)
    u32 Reserved4[24];
    u32 IABR[8];   // Interrupt Active Bit Registers (read active interrupts)
    u32 Reserved5[56];
    u8 IPR[240];   // Interrupt Priority Registers (set interrupt priorities)
} NVIC_t;



#define NVIC ((volatile NVIC_t*)NVIC_BASE_ADDRESS) // NVIC register access pointer
#define SCB_AIRCR *((volatile u32*)(0xE000ED0C))  // System Control Block register for priority grouping



#endif /* NVIC_REGISTER_H_ */
