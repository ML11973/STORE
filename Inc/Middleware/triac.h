/****************************************************************************
 * \file        : triac.h													*
 * \brief       : User triac middle layer header file						*
 * \author		: MLN														*
 * \date		: 31.10.18													*
 ***************************************************************************/

#ifndef TRIAC_H_
#define TRIAC_H_

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
#define M1_OPEN_PIN		GPIO_PIN_12
#define M1_CLOSE_PIN	GPIO_PIN_13
#define M2_OPEN_PIN		GPIO_PIN_14
#define M2_CLOSE_PIN	GPIO_PIN_15

#define SWCONTROL_PIN	GPIO_PIN_11

#define TRIAC_PORT 		GPIOC

#define TRIAC_OFF		GPIO_PIN_RESET
#define TRIAC_ON		GPIO_PIN_SET
/* USER CODE END Definitions */



/****************************************************************************
 * PUBLIC VARIABLES															*
 ***************************************************************************/

/* USER CODE BEGIN Public variables */


/* USER CODE END Public variables */



/****************************************************************************
 * FUNCTION PROTOTYPES														*
 ***************************************************************************/

/**
 * \fn 		triac_openAll(void)
 *
 * \brief 	Opens all blinds. Must be stopped with triac_stopAll().
 */
void triac_openAll();



/**
 * \fn 		triac_closeAll(void)
 *
 * \brief 	Closes all blinds. Must be stopped with triac_stopAll().
 */
void triac_closeAll(void);



/**
 * \fn 		triac_stopAll(void)
 *
 * \brief 	Stops closing/opening of all blinds.
 */
void triac_stopAll(void);

#endif /* TRIAC_H_ */
