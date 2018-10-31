/****************************************************************************
 * \file        : input.c													*
 * \brief       : User input middle layer									*
 * \author		: MLN														*
 * \date		: 31.10.18													*
 ***************************************************************************/


/****************************************************************************
 * INCLUDES																	*
 ***************************************************************************/

/* USER CODE BEGIN Includes */
#include "../../Inc/Middleware/input.h"

/* USER CODE END Includes */



/****************************************************************************
 * VARIABLES																*
 ***************************************************************************/

/* USER CODE BEGIN Variables */
uint16_t analogValue [ANALOG_NUMBER] = {0};

uint8_t keypadValue [KEYPAD_NUMBER] = {0};
const uint8_t keypadAddress [KEYPAD_NUMBER] = {
		UP_PIN,
		DOWN_PIN,
		LEFT_PIN,
		RIGHT_PIN,
		OK_PIN};

uint16_t light1;
uint16_t light2;
uint16_t light3;

uint16_t temperature;

/* USER CODE END Variables */



/****************************************************************************
 * FUNCTION PROTOTYPES														*
 ***************************************************************************/



/****************************************************************************
 * FUNCTIONS																*
 ***************************************************************************/

void input_initAnalog(ADC_HandleTypeDef *hadcLocal)
{
	HAL_ADC_Start_DMA(hadcLocal, analogValue, ANALOG_NUMBER);
}


void input_getInputs ()
{
	light1 = analogValue [0];
	light2 = analogValue [1];
	light3 = analogValue [2];

	temperature = analogValue [3];

	// Saving previous pin state and fetching current one
	for (uint8_t i = 0; i < KEYPAD_NUMBER; i++){
		keypadValue [i] <<= 1;
		keypadValue [i] |= HAL_GPIO_ReadPin(INPUT_PORT, keypadAddress[i]);
	}
}
