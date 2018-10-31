/****************************************************************************
 * \file        : input.h													*
 * \brief       : User input middle layer header file						*
 * \author		: MLN														*
 * \date		: 31.10.18													*
 ***************************************************************************/

#ifndef INPUT_H_
#define INPUT_H_

/****************************************************************************
 * INCLUDES																	*
 ***************************************************************************/

/* USER CODE BEGIN Includes */
#include "../main.h"

/* USER CODE END Includes */



/****************************************************************************
 * DEFINITIONS																*
 ***************************************************************************/

/* USER CODE BEGIN Definitions */
#define ANALOG_NUMBER 4

#define MAXINPUT 4095

#define KEYPAD_NUMBER 5

#define UP_PIN		GPIO_PIN_0
#define DOWN_PIN	GPIO_PIN_1
#define LEFT_PIN	GPIO_PIN_2
#define RIGHT_PIN	GPIO_PIN_3
#define OK_PIN		GPIO_PIN_4

#define INPUT_PORT 	GPIOC
/* USER CODE END Definitions */



/****************************************************************************
 * PUBLIC VARIABLES															*
 ***************************************************************************/

/* USER CODE BEGIN Public variables */
extern uint8_t keypadValues [];

extern uint16_t light1;
extern uint16_t light2;
extern uint16_t light3;

extern uint16_t temperature;

/* USER CODE END Public variables */



/****************************************************************************
 * FUNCTION PROTOTYPES														*
 ***************************************************************************/

/**
 * \fn 		input_initAnalog(ADC_HandleTypeDef*)
 *
 * \brief 	Initializes sensor live update service: the ADC scans our sensors
 * 			continuously, passes each value to the DMA controller who stores our
 * 			values in analogValues table.
 *
 * 			The process runs solely on peripherals, saving us CPU power.
 */
void input_initAnalog(ADC_HandleTypeDef*);



/**
 * \fn 		input_getInputs(void)
 *
 * \brief 	Copies ADC live-read values to local light and temperature variables.
 * 			Saves the last 8 states of each keypad key in keypadValues array.
 */
void input_getInputs(void);

#endif /* INPUT_H_ */
