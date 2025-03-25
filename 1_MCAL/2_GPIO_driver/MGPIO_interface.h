/****************************************************/
/*   AUTHOR      : Abdullah Ahmed                   */
/*   Description : GPIO_interface.h                 */
/*   DATE        : 14 JAN 2024                      */
/*   VERSION     : V01                              */
/****************************************************/

#ifndef MGPIO_INTERFACE_H
#define MGPIO_INTERFACE_H

/* Mapping Controller Ports into numeric values to implement the functionality of the driver */
typedef enum {
	GPIO_PORTA = 1,
	GPIO_PORTB,
	GPIO_PORTC,
} EN_GpioPortNo_t;

/* Mapping Controller pins into numeric values to implement the functionality of the driver */
typedef enum {
	GPIO_PIN00 = 0,
	GPIO_PIN01,
	GPIO_PIN02,
	GPIO_PIN03,
	GPIO_PIN04,
	GPIO_PIN05,
	GPIO_PIN06,
	GPIO_PIN07,
	GPIO_PIN08,
	GPIO_PIN09,
	GPIO_PIN10,
	GPIO_PIN11,
	GPIO_PIN12,
	GPIO_PIN13,
	GPIO_PIN14,
	GPIO_PIN15,
} EN_GpioPinNo_t;

/* Mapping Gpio Modes into numeric values to implement the functionality of the driver */
typedef enum {
	GPIO_MODE_INPUT = 0,
	GPIO_MODE_OUTPUT,
	GPIO_MODE_ALTERNATE_FUNCTION,
	GPIO_MODE_ANALOG,
} EN_GpioMode_t;

/* Mapping Gpio Output Types into numeric values to implement the functionality of the driver */
typedef enum {
	GPIO_OTYPE_PUSH_PULL = 0,
	GPIO_OTYPE_OPEN_DRAIN,
} EN_GpioOtype_t;

/* Mapping Gpio Output Speeds into numeric values to implement the functionality of the driver */
typedef enum {
	GPIO_OSPEED_LOW = 0,
	GPIO_OSPEED_MEDIUM,
	GPIO_OSPEED_HIGH,
	GPIO_OSPEED_VERY_HIGH,
} EN_GpioOSpeed_t;

/* Mapping Gpio internal pull resistors into numeric values to implement the functionality of the driver */
typedef enum {
	GPIO_PUPD_NOT_PULLED = 0,
	GPIO_PUPD_PULL_UP,
	GPIO_PUPD_PULL_DOWN,
} EN_GpioPUPD_t;

/* Mapping Gpio voltage levels into numeric values to implement the functionality of the driver */
typedef enum {
	GPIO_VOLT_LEVEL_LOW = 0,
	GPIO_VOLT_LEVEL_HIGH,
} EN_GpioVoltLevel_t;


/* @brief configure the pin as general purpose output
 *
 * This function configure the pin as general purpose output (means it can be push pull, or open drain)
 *   and takes the output type as push pull or open drain pin and also takes the output speed
 *
 * @param EN_GpioPortNo_t	the port number for the specified pin.
 * 		  EN_GpioPinNo_t	the specified pin number.
 * 		  EN_GpioOtype_t	the output type  (GPIO_OTYPE_PUSH_PULL or GPIO_OTYPE_OPEN_DRAIN).
 * 		  EN_GpioOSpeed_t	the output speed
 *
 * @return void
 **/
void MGPIO_voidSetPinOutput(EN_GpioPortNo_t PortNo, EN_GpioPinNo_t PinNo, EN_GpioOtype_t OType, EN_GpioOSpeed_t OSpeed);


/* @brief configure the pin as input
 *
 * This function configure the pin as input, it takes the port number and the pin number to
 * reach to the specified Gpio pin, and it also takes the internal pull resistor type
 *
 * @param EN_GpioPortNo_t	the port number for the specified pin.
 * 		  EN_GpioPinNo_t	the specified pin number.
 *		  EN_GpioPUPD_t		the internal pull resistor type
 *
 * @return void
 **/
void MGPIO_voidSetPinInput(EN_GpioPortNo_t PortNo, EN_GpioPinNo_t PinNo, EN_GpioPUPD_t PUPD);


/* @brief configure the pin direction.
 *
 * This function configure the direction of a specified pin as (input, general purpose output, alternat function or analog).
 * It takes the port number and the pin number for the specified pin, it also takes the mode to configure
 *
 * @param EN_GpioPortNo_t	the port number for the specified pin.
 * 		  EN_GpioPinNo_t	the specified pin number.
 *		  EN_GpioMode_t     the direction of the specified pin
 *
 * @return void
 **/
void MGPIO_voidSetPinMode(EN_GpioPortNo_t PortNo, EN_GpioPinNo_t PinNo, EN_GpioMode_t Mode);


/* @brief configure the pin output type.
 *
 * This function configure the output type of a specified pin as (push pull, or open drain)
 * if the mode of this pin was configured as output.
 * It takes the port number and the pin number for the specified pin, it also takes the Output type to configure
 *
 * @param EN_GpioPortNo_t	the port number for the specified pin.
 * 		  EN_GpioPinNo_t	the specified pin number.
 *		  EN_GpioOtype_t    the output type of the specified pin
 *
 * @return void
 **/
void MGPIO_voidSetPinOType(EN_GpioPortNo_t PortNo, EN_GpioPinNo_t PinNo, EN_GpioOtype_t OType);


/* @brief configure the pin output speed.
 *
 * This function configure the output speed of a specified pin as (low, medium, high or very high)
 * if the mode of this pin was configured as output.
 * It takes the port number and the pin number for the specified pin, it also takes the Output speed to configure
 *
 * @param EN_GpioPortNo_t	the port number for the specified pin.
 * 		  EN_GpioPinNo_t	the specified pin number.
 *		  EN_GpioOSpeed_t   the output speed of the specified pin
 *
 * @return void
 **/
void MGPIO_voidSetPinOSpeed(EN_GpioPortNo_t PortNo, EN_GpioPinNo_t PinNo, EN_GpioOSpeed_t OSpeed);


/* @brief configure the pin internal pull up or pull down resistor.
 *
 * This function configure the internal pull up or pull down resistor (not pulled, pull up, or pull down)
 * It takes the port number and the pin number for the specified pin, it also takes the PUPD mode to configure
 *
 * @param EN_GpioPortNo_t	the port number for the specified pin.
 * 		  EN_GpioPinNo_t	the specified pin number.
 *		  EN_GpioPUPD_t     the PUPD mode of the specified pin
 *
 * @return void
 **/
void MGPIO_voidSetPinPUPD(EN_GpioPortNo_t PortNo, EN_GpioPinNo_t PinNo, EN_GpioPUPD_t PUPD);


/* @brief sets the output pin to voltage level
 *
 * This function is used to output level low or level high to an general purpose output pin (push pull, or open drain)
 * It takes the port number and the pin number for the specified pin, it also takes the voltage level to set.
 *
 * @param EN_GpioPortNo_t		 the port number for the specified pin.
 * 		  EN_GpioPinNo_t		 the specified pin number.
 *		  EN_GpioVoltLevel_t     the voltage level for the specified pin
 *
 * @return void
 **/
void MGPIO_voidSetPinValue(EN_GpioPortNo_t PortNo, EN_GpioPinNo_t PinNo, EN_GpioVoltLevel_t VoltLevel);


/* @brief gets the captured voltage level state of an input pin.
 *
 * This function is used to get the captured voltage level state of an input pin as it sense low level or high level.
 * It takes the port number and the pin number for the specified pin, it also takes a pointer to voltage level to read the data.
 *
 * @param EN_GpioPortNo_t		 the port number for the specified pin.
 * 		  EN_GpioPinNo_t		 the specified pin number.
 *		  EN_GpioVoltLevel_t*    the location that will hold the read state.
 *
 * @return void
 **/
void MGPIO_voidGetPinValue(EN_GpioPortNo_t PortNo, EN_GpioPinNo_t PinNo, EN_GpioVoltLevel_t * P_enuVoltLevel);


/* @brief toggling the voltage level of a pin.
 *
 * This function is used to toggle the voltage level of a pin.
 * It takes the port number and the pin number for the specified pin.
 *
 * @param EN_GpioPortNo_t		 the port number for the specified pin.
 * 		  EN_GpioPinNo_t		 the specified pin number.
 *
 * @return void
 **/
void MGPIO_voidTogglePinValue(EN_GpioPortNo_t PortNo, EN_GpioPinNo_t PinNo);

/*********************************************************************/
/******************* Extend The Functionality ************************/
/*********************************************************************/

typedef enum {
	GPIO_PORT_LOW_LEVEL_PINS,
	GPIO_PORT_HIGH_LEVEL_PINS,
} EN_GpioPortLevelPins_t;

void MGPIO_voidSet8PinsValue(EN_GpioPortNo_t PortNo, EN_GpioPortLevelPins_t PortLevelPins, u8 Value);


#endif
