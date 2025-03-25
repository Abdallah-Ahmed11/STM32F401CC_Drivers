/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : GPIO_register.h                  */
/*   DATE        : 14 JAN 2024                      */
/*   VERSION     : V01                              */
/****************************************************/

#ifndef MGPIO_REGISTER_H
#define MGPIO_REGISTER_H

/* Get the base address */
#define MGPIOA_BASE_ADDRESS		(0x40020000)
#define MGPIOB_BASE_ADDRESS     (0x40020400)
#define MGPIOC_BASE_ADDRESS     (0x40020800)


/* Define each register */
#define GPIOA_MODER			*( (volatile u32*)(MGPIOA_BASE_ADDRESS + 0x00))
#define GPIOA_OTYPER       *( (volatile u32*)(MGPIOA_BASE_ADDRESS + 0x04))
#define GPIOA_OSPEEDR      *( (volatile u32*)(MGPIOA_BASE_ADDRESS + 0x08))
#define GPIOA_PUPDR        *( (volatile u32*)(MGPIOA_BASE_ADDRESS + 0x0C))
#define GPIOA_IDR          *( (volatile u32*)(MGPIOA_BASE_ADDRESS + 0x10))
#define GPIOA_ODR          *( (volatile u32*)(MGPIOA_BASE_ADDRESS + 0x14))
#define GPIOA_BSRR         *( (volatile u32*)(MGPIOA_BASE_ADDRESS + 0x18))
#define GPIOA_LCKR         *( (volatile u32*)(MGPIOA_BASE_ADDRESS + 0x1C))
#define GPIOA_AFRL         *( (volatile u32*)(MGPIOA_BASE_ADDRESS + 0x20))
#define GPIOA_AFRH         *( (volatile u32*)(MGPIOA_BASE_ADDRESS + 0x24))

#define GPIOB_MODER		*( (volatile u32*)(MGPIOB_BASE_ADDRESS + 0x00))
#define GPIOB_OTYPER       *( (volatile u32*)(MGPIOB_BASE_ADDRESS + 0x04))
#define GPIOB_OSPEEDR      *( (volatile u32*)(MGPIOB_BASE_ADDRESS + 0x08))
#define GPIOB_PUPDR        *( (volatile u32*)(MGPIOB_BASE_ADDRESS + 0x0C))
#define GPIOB_IDR          *( (volatile u32*)(MGPIOB_BASE_ADDRESS + 0x10))
#define GPIOB_ODR          *( (volatile u32*)(MGPIOB_BASE_ADDRESS + 0x14))
#define GPIOB_BSRR         *( (volatile u32*)(MGPIOB_BASE_ADDRESS + 0x18))
#define GPIOB_LCKR         *( (volatile u32*)(MGPIOB_BASE_ADDRESS + 0x1C))
#define GPIOB_AFRL         *( (volatile u32*)(MGPIOB_BASE_ADDRESS + 0x20))
#define GPIOB_AFRH         *( (volatile u32*)(MGPIOB_BASE_ADDRESS + 0x24))

#define GPIOC_MODER		*( (volatile u32*)(MGPIOC_BASE_ADDRESS + 0x00))
#define GPIOC_OTYPER       *( (volatile u32*)(MGPIOC_BASE_ADDRESS + 0x04))
#define GPIOC_OSPEEDR      *( (volatile u32*)(MGPIOC_BASE_ADDRESS + 0x08))
#define GPIOC_PUPDR        *( (volatile u32*)(MGPIOC_BASE_ADDRESS + 0x0C))
#define GPIOC_IDR          *( (volatile u32*)(MGPIOC_BASE_ADDRESS + 0x10))
#define GPIOC_ODR          *( (volatile u32*)(MGPIOC_BASE_ADDRESS + 0x14))
#define GPIOC_BSRR         *( (volatile u32*)(MGPIOC_BASE_ADDRESS + 0x18))
#define GPIOC_LCKR         *( (volatile u32*)(MGPIOC_BASE_ADDRESS + 0x1C))
#define GPIOC_AFRL         *( (volatile u32*)(MGPIOC_BASE_ADDRESS + 0x20))
#define GPIOC_AFRH         *( (volatile u32*)(MGPIOC_BASE_ADDRESS + 0x24))


#endif
