/****************************************************************************
 * \file        : triac.c													*
 * \brief       : Triac control middle layer								*
 * \author		: MLN														*
 * \date		: 31.10.18													*
 ***************************************************************************/


/****************************************************************************
 * INCLUDES																	*
 ***************************************************************************/

/* USER CODE BEGIN Includes */
#include "../../Inc/Middleware/triac.h"

/* USER CODE END Includes */



/****************************************************************************
 * VARIABLES																*
 ***************************************************************************/

/* USER CODE BEGIN Variables */


/* USER CODE END Variables */



/****************************************************************************
 * FUNCTION PROTOTYPES														*
 ***************************************************************************/



/****************************************************************************
 * FUNCTIONS																*
 ***************************************************************************/

void triac_openAll(void){
	HAL_GPIO_WritePin (TRIAC_PORT, M1_CLOSE_PIN, TRIAC_OFF);
	HAL_GPIO_WritePin (TRIAC_PORT, M2_CLOSE_PIN, TRIAC_OFF);

	HAL_GPIO_WritePin (TRIAC_PORT, M1_OPEN_PIN, TRIAC_ON);
	HAL_GPIO_WritePin (TRIAC_PORT, M2_OPEN_PIN, TRIAC_ON);
}



void triac_closeAll(void){
	HAL_GPIO_WritePin (TRIAC_PORT, M1_OPEN_PIN, TRIAC_OFF);
	HAL_GPIO_WritePin (TRIAC_PORT, M2_OPEN_PIN, TRIAC_OFF);

	HAL_GPIO_WritePin (TRIAC_PORT, M1_CLOSE_PIN, TRIAC_ON);
	HAL_GPIO_WritePin (TRIAC_PORT, M2_CLOSE_PIN, TRIAC_ON);

}



void triac_stopAll(void){
	HAL_GPIO_WritePin (TRIAC_PORT, M1_CLOSE_PIN, TRIAC_OFF);
	HAL_GPIO_WritePin (TRIAC_PORT, M2_CLOSE_PIN, TRIAC_OFF);

	HAL_GPIO_WritePin (TRIAC_PORT, M1_OPEN_PIN, TRIAC_OFF);
	HAL_GPIO_WritePin (TRIAC_PORT, M2_OPEN_PIN, TRIAC_OFF);
}
